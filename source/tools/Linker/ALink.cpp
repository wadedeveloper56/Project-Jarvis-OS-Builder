#include "alink.h"
#include "ArgumentTable.h"

void processEnvironmentVariable()
{
	int isend;

	char* libList = getenv("LIB");
	if (libList)
	{
		for (int i = 0, j = 0;; i++)
		{
			isend = (!libList[i]);
			if (libList[i] == ';' || !libList[i])
			{
				if (i - j)
				{
					libPath = (char**)checkRealloc(libPath, (libPathCount + 1) * sizeof(char*));
					libList[i] = 0;
					if (libList[i - 1] == PATH_CHAR)
					{
						libPath[libPathCount] = checkStrdup(libList + j);
					}
					else
					{
						libPath[libPathCount] = (char*)checkMalloc(i - j + 2);
						strcpy(libPath[libPathCount], libList + j);
						libPath[libPathCount][i - j] = PATH_CHAR;
						libPath[libPathCount][i - j + 1] = 0;
					}
					libPathCount++;
				}
				j = i + 1;
			}
			if (isend) break;
		}
	}

}

void processArgs(int argc, char* argv[])
{
	ArgLitPtr caseSensitive = argLit0("c", NULL, "Enable case sensitivity (default is off)");
	ArgLitPtr segmentPadding = argLit0("p", NULL, "Enable segment padding  (default is off)");
	ArgLitPtr map = argLit0("mM", "map", "Enable map file  (default is off)");
	ArgFilePtr outfile = argFile1("o", "output", NULL, "output file name");
	ArgStrPtr format = argStr1("fF", "format", "<format type>", "output format  (COM,EXE,PE32,PE64)");
	ArgStrPtr entry = argStr1("e", "entry", "<name>", "Use public symbol name as the entry point");
	ArgIntPtr base = argInt0("bB", "base", "<addr>", "Set base address of image");
	ArgIntPtr filealign = argInt0("aA", "filealign", "<addr>", "Set section alignment in file");
	ArgIntPtr objectalign = argInt0("O", "objectalign", "<addr>", "Set section alignment in memory");
	ArgStrPtr subsys = argStrN("s", "subsys", "<subsys type>", 0, 1, "susbsystem (gui,console,native,posix)");
	ArgStrPtr subsysVersion = argStrN("D", "subsysver", "<x.y>", 0, 1, "Select subsystem version x.y");
	ArgStrPtr osVersion = argStrN("E", "osver", "<x.y>", 0, 1, "Select OS version x.y");
	ArgFilePtr stubfile = argFileN(NULL, "stub", "xxx", 0, 1, "Use xxx as the MSDOS stub");
	ArgLitPtr dll = argLit0("d", "dll", "Build DLL instead of EXE");
	ArgIntPtr stacksize = argIntN("S", "stacksize", "xxx", 0, 1, "Set stack size to xxx");
	ArgIntPtr stackcommitsize = argIntN("C", "stackcommitsize", "xxx", 0, 1, "Set stack commit size to xxx");
	ArgIntPtr heapsize = argIntN("h", "heapsize", "xxx", 0, 1, "Set heap size to xxx");
	ArgIntPtr heapcommitsize = argIntN("H", "heapcommitsize", "xxx", 0, 1, "Set heap commit size to xxx");
	ArgLitPtr help = argLit0("hH?", "help", "print this help and exit");
	ArgLitPtr version = argLit0("vV", "version", "print version information and exit");
	ArgFilePtr infiles = argFileN(NULL, NULL, NULL, 1, argc + 2, "input file(s)");
	ArgEndPtr end = argEnd(20);
	void* argtable[] = { caseSensitive, segmentPadding, map, outfile, format, entry, base, filealign, objectalign, subsys, subsysVersion, osVersion, stubfile, dll, stacksize, stackcommitsize, heapsize, heapcommitsize, help, version, infiles, end };
	const char* progname = "Linker";
	int exitcode = 0, nerrors = 0;
	unsigned char setsubsys;
	bool gotsubsys = false, gotbase = false, gotfalign = false, gotoalign = false, gotsubsysver = false, gotosversion = false, gotstack = false, gotstackcommit = false, gotheap = false, gotheapcommit = false;
	int setbase, setfalign, setoalign, setstack, setstackcommit, setheap, setheapcommit;
	int setsubsysmajor, setsubsysminor, setosmajor, setosminor;

	printf("Linker (x86/x64) v1.0 (C) Copyright 2025 Christopher D. Wade.\n");
	printf("All Rights Reserved\n");

	if (argNullCheck(argtable) != 0)
	{
		printf("%s: insufficient memory\n", progname);
		exit(1);
	}
	caseSensitive->count = 0;
	segmentPadding->count = 0;
	map->count = 0;
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
	filecount = infiles->count;
	filename = (char**)infiles->filename;
	case_sensitive = caseSensitive->count;
	padsegments = segmentPadding->count;
	mapfile = map->count > 0;
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
	else
	{
		printf("Unknown type %s\n", format->sval[0]);
		exit(1);
	}
	entryPoint = (char*)entry->sval[0];
	setbase = base->ival[0];
	gotbase = base->count > 0;
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
	else
	{
		printf("Unknown subsystem %s\n", format->sval[0]);
		exit(1);
	}
	setfalign = filealign->ival[0];
	gotfalign = filealign->count > 0;
	setoalign = objectalign->ival[0];
	gotoalign = objectalign->count > 0;
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
	buildDll = dll->count > 0;
	setstack = stacksize->ival[0];
	gotstack = stacksize->count > 0;
	setstackcommit = stackcommitsize->ival[0];
	gotstackcommit = stackcommitsize->count > 0;
	setheap = heapsize->ival[0];
	gotheap = heapsize->count > 0;
	setheapcommit = heapcommitsize->ival[0];
	gotheapcommit = heapcommitsize->count > 0;
	if ((output_type != OUTPUT_PE32 && output_type != OUTPUT_PE64) &&
		(gotoalign || gotfalign || gotbase || gotsubsys || gotstack || gotstackcommit || gotheap || gotheapcommit || buildDll || stubName || gotsubsysver || gotosversion))
	{
		printf("Option not supported for non-PE output formats\n");
		exit(1);
	}
	if (gotstack) stackSize = setstack;
	if (gotstackcommit) stackCommitSize = setstackcommit;
	if (stackCommitSize > stackSize)
	{
		printf("Stack commit size is greater than stack size, committing whole stack\n");
		stackCommitSize = stackSize;
	}
	if (gotheap) heapSize = setheap;
	if (gotheapcommit) heapCommitSize = setheapcommit;
	if (heapCommitSize > heapSize)
	{
		printf("Heap commit size is greater than heap size, committing whole heap\n");
		heapCommitSize = heapSize;
	}
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
	processEnvironmentVariable();
	processArgs(argc, argv);
	if (!filecount)
	{
		printf("No files specified\n");
		exit(1);
	}
	if (mapfile)
	{
		if (!mapname)
		{
			mapname = new char[strlen(outname) + 1 + 4];
			strcpy(mapname, outname);
			int i = strlen(mapname);
			while ((i >= 0) && (mapname[i] != '.') && (mapname[i] != PATH_CHAR) && (mapname[i] != ':'))
			{
				i--;
			}
			if (mapname[i] != '.')
			{
				i = strlen(mapname);
			}
			strcpy(mapname + i, ".map");
		}
	}

	return 0;
}