#include "linker.h"
#include "ArgumentTable.h"
#include "BinaryFormat.h"

using namespace std;
using namespace BinaryFormat;

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
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];

	parameters.case_sensitive = 1;
	parameters.padsegments = 0;
	parameters.output_type = 0;
	parameters.outname = nullptr;
	parameters.imageBase = 0;
	parameters.fileAlign = 1;
	parameters.objectAlign = 1;
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
	parameters.case_sensitive = caseSensitive->count;
	parameters.padsegments = segmentPadding->count;
	parameters.mapfile = map->count;
	parameters.outname = (char*)outfile->filename[0];
	_splitpath(parameters.outname, drive, dir, fname, ext);
	_makepath(parameters.mapFileName, drive, dir, fname, "map");
	for (int i = 0; i < infiles->count; i++)
	{
		inputFiles.push_back(infiles->filename[i]);
	}
	inputFilesCount = inputFiles.size();
	if (strcmp(format->sval[0], "COM"))
	{
		parameters.output_type = OUTPUT_COM;
		parameters.imageBase = 0;
		parameters.fileAlign = 1;
		parameters.objectAlign = 1;
		parameters.stackSize = 0;
		parameters.stackCommitSize = 0;
		parameters.heapSize = 0;
		parameters.heapCommitSize = 0;
	}
	else if (strcmp(format->sval[0], "EXE"))
	{
		parameters.output_type = OUTPUT_EXE;
		parameters.imageBase = 0;
		parameters.fileAlign = 1;
		parameters.objectAlign = 1;
		parameters.stackSize = 0;
		parameters.stackCommitSize = 0;
		parameters.heapSize = 0;
		parameters.heapCommitSize = 0;
	}
	else if (strcmp(format->sval[0], "PE32"))
	{
		parameters.output_type = OUTPUT_PE32;
		parameters.imageBase = WIN32_DEFAULT_BASE;
		parameters.fileAlign = WIN32_DEFAULT_FILEALIGN;
		parameters.objectAlign = WIN32_DEFAULT_OBJECTALIGN;
		parameters.stackSize = WIN32_DEFAULT_STACKSIZE;
		parameters.stackCommitSize = WIN32_DEFAULT_STACKCOMMITSIZE;
		parameters.heapSize = WIN32_DEFAULT_HEAPSIZE;
		parameters.heapCommitSize = WIN32_DEFAULT_HEAPCOMMITSIZE;
		parameters.subSystem = WIN32_DEFAULT_SUBSYS;
		parameters.subsysMajor = WIN32_DEFAULT_SUBSYSMAJOR;
		parameters.subsysMinor = WIN32_DEFAULT_SUBSYSMINOR;
		parameters.osMajor = WIN32_DEFAULT_OSMAJOR;
		parameters.osMinor = WIN32_DEFAULT_OSMINOR;
	}
	else if (strcmp(format->sval[0], "PE64"))
	{
		parameters.output_type = OUTPUT_PE64;
		parameters.imageBase = WIN32_DEFAULT_BASE;
		parameters.fileAlign = WIN32_DEFAULT_FILEALIGN;
		parameters.objectAlign = WIN32_DEFAULT_OBJECTALIGN;
		parameters.stackSize = WIN32_DEFAULT_STACKSIZE;
		parameters.stackCommitSize = WIN32_DEFAULT_STACKCOMMITSIZE;
		parameters.heapSize = WIN32_DEFAULT_HEAPSIZE;
		parameters.heapCommitSize = WIN32_DEFAULT_HEAPCOMMITSIZE;
		parameters.subSystem = WIN32_DEFAULT_SUBSYS;
		parameters.subsysMajor = WIN32_DEFAULT_SUBSYSMAJOR;
		parameters.subsysMinor = WIN32_DEFAULT_SUBSYSMINOR;
		parameters.osMajor = WIN32_DEFAULT_OSMAJOR;
		parameters.osMinor = WIN32_DEFAULT_OSMINOR;
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
		gotsubsysver = false;
	else
		gotsubsysver = true;
	if (sscanf(osVersion->sval[0], "%d.%d%n", &setosmajor, &setosminor, &j) != 2)
		gotosversion = false;
	else
		gotosversion = true;
	parameters.stubName = (char*)stubfile->filename[0];

	if (gotoalign) parameters.objectAlign = setoalign;
	if (gotfalign) parameters.fileAlign = setfalign;
	if (gotbase) parameters.imageBase = setbase;
	if (gotsubsys) parameters.subSystem = setsubsys;
	if (gotsubsysver)
	{
		parameters.subsysMajor = setsubsysmajor;
		parameters.subsysMinor = setsubsysminor;
	}
	if (gotosversion)
	{
		parameters.osMajor = setosmajor;
		parameters.osMinor = setosminor;
	}
}

void processEnvironmentVariable()
{
	string segment;

	char* libList = getenv("LIB");
	if (libList)
	{
		stringstream ss(libList);
		while (getline(ss, segment, ';')) {
			libraryPath.push_back(segment);
		}
		libPathCount = libraryPath.size();
	}

}

void checkForParameterErrors()
{
	if (parameters.outname == nullptr)
	{
		printf("No output name specified\n");
		exit(1);
	}
	if (inputFilesCount == 0)
	{
		printf("No input name(s) specified\n");
		exit(1);
	}
	if (parameters.output_type == 0)
	{
		printf("No output type specified\n");
		exit(1);
	}
}

void loadFiles()
{
	for (const string& file : inputFiles) {
		printf("Loading file %s\n", file.c_str());
		MemoryMappedFile* mmfile = new MemoryMappedFile((char*)file.c_str());
		char* buffer = mmfile->getBuffer();
		LONGLONG fileSize = mmfile->getFileSize();
		FileType fileType = getFileType(buffer, fileSize);
		switch (fileType)
		{
			case PE32EXE:
			case PE64EXE:
				cout << "cant link an exe to form exe" << endl;
				break;
			case DEBUG:
				break;
			case PE32OBJ:
			case PE64OBJ:
				cout << "its obj file type" << endl;
				loadObjFile(fileType, buffer, fileSize);
				break;
			case ANONYMOUS:
				break;
			case LIB:
				break;
			default:
				cout << "unknown file type" << endl;
				break;
		}
		delete mmfile;
	}
}

int main(int argc, char* argv[])
{
	processEnvironmentVariable();
	processArgs(argc, argv);
	checkForParameterErrors();
	loadFiles();
	return 0;
}
