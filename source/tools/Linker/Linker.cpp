#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ArgumentTable.h"

#define OUTPUT_COM 1
#define OUTPUT_EXE 2
#define OUTPUT_PE32  3
#define OUTPUT_PE64  4

#define PE_SUBSYS_NATIVE  1
#define PE_SUBSYS_WINDOWS 2
#define PE_SUBSYS_CONSOLE 3
#define PE_SUBSYS_POSIX   7

#define WIN32_DEFAULT_BASE              0x00400000
#define WIN32_DEFAULT_FILEALIGN         0x00000200
#define WIN32_DEFAULT_OBJECTALIGN       0x00001000
#define WIN32_DEFAULT_STACKSIZE         0x00100000
#define WIN32_DEFAULT_STACKCOMMITSIZE   0x00001000
#define WIN32_DEFAULT_HEAPSIZE          0x00100000
#define WIN32_DEFAULT_HEAPCOMMITSIZE    0x00001000
#define WIN32_DEFAULT_SUBSYS            PE_SUBSYS_WINDOWS
#define WIN32_DEFAULT_SUBSYSMAJOR       4
#define WIN32_DEFAULT_SUBSYSMINOR       0
#define WIN32_DEFAULT_OSMAJOR           1
#define WIN32_DEFAULT_OSMINOR           0

char case_sensitive = 1;
char padsegments = 0;
char mapfile = 0; 
char* outname = 0;
int output_type = OUTPUT_EXE;
unsigned int  imageBase = 0;
unsigned int  fileAlign = 1;
unsigned int  objectAlign = 1;
unsigned int  stackSize;
unsigned int  stackCommitSize;
unsigned int  heapSize;
unsigned int  heapCommitSize;
unsigned char osMajor, osMinor;
unsigned char subsysMajor, subsysMinor;
unsigned int subSystem;
bool buildDll = false;
unsigned char* stubName = NULL;

void ProcessEnvironmentVariable()
{
	char* libList = getenv("LIB");
}

void processArgs(int argc, char* argv[])
{
	ArgLitPtr caseSensitive = argLit0("c", NULL, "Enable case sensitivity (default is off)");
	ArgLitPtr segmentPadding = argLit0("p", NULL, "Enable segment padding  (default is off)");
	ArgLitPtr map = argLit0("mM", "map", "Enable map file  (default is off)");
	ArgFilePtr outfile = argFile1("o", "output", NULL, "output file name");
	ArgStrPtr format = argStr1("fF", "format", "<format type>", "output format  (COM,EXE,PE32,PE64)");
	ArgIntPtr base = argInt0("bB", "base", "<addr>", "Set base address of image");
	ArgIntPtr filealign = argInt0("aA", "filealign", "<addr>", "Set section alignment in file");
	ArgIntPtr objectalign = argInt0("O", "objectalign", "<addr>", "Set section alignment in memory");
	ArgStrPtr subsys = argStrN("sS", "subsys", "<subsys type>", 0, 1, "susbsystem (gui,console,native,posix)");
	ArgStrPtr subsysVersion = argStrN("dD", "subsysver", "<x.y>", 0, 1, "Select subsystem version x.y");
	ArgStrPtr osVersion = argStrN("eE", "osver", "<x.y>", 0, 1, "Select OS version x.y");
	ArgFilePtr stubfile = argFileN(NULL, "stub", "xxx", 0, 1, "Use xxx as the MSDOS stub");

	ArgLitPtr help = argLit0("hH?", "help", "print this help and exit");
	ArgLitPtr version = argLit0("vV", "version", "print version information and exit");
	ArgFilePtr infiles = argFileN(NULL, NULL, NULL, 1, argc + 2, "input file(s)");
	ArgEndPtr end = argEnd(20);
	void* argtable[] = { caseSensitive, segmentPadding, map, outfile, format, base, filealign, objectalign, subsys, subsysVersion, osVersion, stubfile, help, version, infiles, end };
	const char* progname = "Linker";
	int exitcode = 0, nerrors = 0;
	unsigned char setsubsys;
	bool gotsubsys = false, gotbase = false, gotfalign = false, gotoalign = false, gotsubsysver = false, gotosversion = false;
	int setbase, setfalign, setoalign;
	int setsubsysmajor, setsubsysminor, setosmajor, setosminor;

	printf("Linker (x86/x64) v1.0 (C) Copyright 2025 Christopher D. Wade.\n");
	printf("All Rights Reserved\n");

	if (argNullCheck(argtable) != 0)
	{
		printf("%s: insufficient memory\n", progname);
		exit(1);
	}
	nerrors = argParse(argc, argv, argtable);
	if (help->count > 0 || argc == 1)
	{
		printf("\nUsage: %s", progname);
		argPrintSyntax(stdout, argtable, "\n\n");
		printf("Each file may be an object file, a library, or a Win32 resource\n");
		printf("file.If no extension is specified, .obj is assumed.Modules are\n");
		printf("only loaded from library files if they are required to match an\n");
		printf("external reference.\n");
		printf("Options and files may be listed in any order, all mixed together.\n");
		argPrintGlossary(stdout, argtable, "  %-35s %s\n");
		exit(1);
	}

	if (version->count > 0)
	{
		printf("'%s' x86/x64 linker.\n", progname);
		printf("June 2025, (c) Christopher D. Wade\n");
		exit(1);
	}

	if (nerrors > 0)
	{
		argPrintErrors(stdout, end, progname);
		printf("Try '%s --help' for more information.\n", progname);
		exit(1);
	}
	case_sensitive = caseSensitive->count;
	padsegments = segmentPadding->count;
	mapfile = map->count;
	outname = (char*)outfile->filename[0];
	if (strcmp(format->sval[0], "COM"))
	{
		output_type = OUTPUT_COM;
		imageBase = 0;
		fileAlign = 1;
		objectAlign = 1;
		stackSize = 0;
		stackCommitSize = 0;
		heapSize = 0;
		heapCommitSize = 0;
	}
	else if (strcmp(format->sval[0], "EXE"))
	{
		output_type = OUTPUT_EXE;
		imageBase = 0;
		fileAlign = 1;
		objectAlign = 1;
		stackSize = 0;
		stackCommitSize = 0;
		heapSize = 0;
		heapCommitSize = 0;
	}
	else if (strcmp(format->sval[0], "PE32"))
	{
		output_type = OUTPUT_PE32;
		imageBase = WIN32_DEFAULT_BASE;
		fileAlign = WIN32_DEFAULT_FILEALIGN;
		objectAlign = WIN32_DEFAULT_OBJECTALIGN;
		stackSize = WIN32_DEFAULT_STACKSIZE;
		stackCommitSize = WIN32_DEFAULT_STACKCOMMITSIZE;
		heapSize = WIN32_DEFAULT_HEAPSIZE;
		heapCommitSize = WIN32_DEFAULT_HEAPCOMMITSIZE;
		subSystem = WIN32_DEFAULT_SUBSYS;
		subsysMajor = WIN32_DEFAULT_SUBSYSMAJOR;
		subsysMinor = WIN32_DEFAULT_SUBSYSMINOR;
		osMajor = WIN32_DEFAULT_OSMAJOR;
		osMinor = WIN32_DEFAULT_OSMINOR;
	}
	else if (strcmp(format->sval[0], "PE64"))
	{
		output_type = OUTPUT_PE64;
		imageBase = WIN32_DEFAULT_BASE;
		fileAlign = WIN32_DEFAULT_FILEALIGN;
		objectAlign = WIN32_DEFAULT_OBJECTALIGN;
		stackSize = WIN32_DEFAULT_STACKSIZE;
		stackCommitSize = WIN32_DEFAULT_STACKCOMMITSIZE;
		heapSize = WIN32_DEFAULT_HEAPSIZE;
		heapCommitSize = WIN32_DEFAULT_HEAPCOMMITSIZE;
		subSystem = WIN32_DEFAULT_SUBSYS;
		subsysMajor = WIN32_DEFAULT_SUBSYSMAJOR;
		subsysMinor = WIN32_DEFAULT_SUBSYSMINOR;
		osMajor = WIN32_DEFAULT_OSMAJOR;
		osMinor = WIN32_DEFAULT_OSMINOR;
	}
	setbase = base->ival[0];
	if (base->count > 0) gotbase = true;
	if (strcmp(subsys->sval[0], "gui"))
	{
		setsubsys = PE_SUBSYS_WINDOWS;
		gotsubsys = true;
	}
	else if (strcmp(subsys->sval[0], "console"))
	{
		setsubsys = PE_SUBSYS_CONSOLE;
		gotsubsys = true;
	}
	else if (strcmp(subsys->sval[0], "native"))
	{
		setsubsys = PE_SUBSYS_NATIVE;
		gotsubsys = true;
	}
	else if (strcmp(subsys->sval[0], "posix"))
	{
		setsubsys = PE_SUBSYS_POSIX;
		gotsubsys = true;
	}
	setfalign = filealign->ival[0];
	if (filealign->count > 0) gotfalign = true;
	setoalign = objectalign->ival[0];
	if (objectalign->count > 0) gotoalign = true;
	long j;
	if (sscanf(subsysVersion->sval[0], "%d.%d%n", &setsubsysmajor, &setsubsysminor, &j) != 2)
		exit(1);
	else
		gotsubsysver = true;
	if (sscanf(osVersion->sval[0], "%d.%d%n", &setosmajor, &setosminor, &j) != 2)
		exit(1);
	else
		gotosversion = true;
	stubName = (unsigned char*)stubfile->filename[0];

	if (gotoalign) objectAlign = setoalign;
	if (gotfalign) fileAlign = setfalign;
	if (gotbase) imageBase = setbase;
	if (gotsubsys) subSystem = setsubsys;
	if (gotsubsysver)
	{
		subsysMajor = setsubsysmajor;
		subsysMinor = setsubsysminor;
	}
	if (gotosversion)
	{
		osMajor = setosmajor;
		osMinor = setosminor;
	}
}

int main(int argc, char* argv[])
{
	ProcessEnvironmentVariable();
	processArgs(argc, argv);
	return 0;
}
