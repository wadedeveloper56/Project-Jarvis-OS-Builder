#include "pch.h"
#include "Linker.h"
#include "ArgumentTable.h"
#include "ObjLoad.h"
#include "Util.h"
#include "Coff.h"

void loadFiles(ArgFilePtr infiles)
{
	for (int index = 0; index < infiles->count; index++)
	{
		const char* filename = infiles->filename[index];
		printf("Loading file %s\n", filename);
		FILE* afile = fopen(filename, "rb");
		int j = fgetc(afile);
		fseek(afile, 0, SEEK_SET);
		switch (j)
		{
			case LIBHDR:
				loadlib(afile, filename);
				break;
			case THEADR:
			case LHEADR:
				loadmod(afile);
				break;
			case 0:
				loadres(afile);
				break;
			case 0x4c:
			case 0x4d:
			case 0x4e:
				loadcoff(afile);
				break;
			case 0x21:
				//loadCoffLib(afile, filename[i]);
				break;
			default:
				printf("Unknown file type\n");
				fclose(afile);
				exit(1);
		}
		fclose(afile);
	}
}

int main(int argc, char* argv[])
{
	ArgLitPtr help = argLit0("hH?", "help", "print this help and exit");
	ArgLitPtr version = argLit0("vV", "version", "print version information and exit");
	ArgFilePtr infiles = argFileN(NULL, NULL, NULL, 1, argc + 2, "input file(s)");
	ArgFilePtr outfile = argFile0("o", NULL, "<file>", "output file (default is \"-\")");
	ArgLitPtr caseSensitivity = argLit0("c", NULL, "Enable Case sensitivity (default is off)");
	ArgLitPtr segmentPadding = argLit0("p", NULL, "Enable segment padding (default is off)");
	ArgLitPtr map = argLit0("m", NULL, "Enable map (default is off)");
	ArgStrPtr format = argStr1("f", "format", "EXE,COM,PE32", "EXE,COM,PE32 are acceptble values");
	ArgEndPtr end = argEnd(20);
	void* argtable[] = { map, caseSensitivity, segmentPadding, format, outfile, help, version, infiles, end };
	const char* progname = "Linker";
	int exitcode = 0, nerrors = 0;
	long i, j;
	int isend;
	char* libList = NULL;
	unsigned int libPathCount = 0;

	printf("LINKER (x86/x64) v1.0 (C) Copyright 2025 Christopher D. Wade.\n");
	printf("All Rights Reserved\n");

	if (argNullCheck(argtable) != 0)
	{
		printf("%s: insufficient memory\n", progname);
		arg_freetable(argtable, sizeof(argtable) / sizeof(argtable[0]));
		exit(1);
	}
	if (argc == 1)
	{
		printf("Try '%s --help' for more information.\n", progname);
		arg_freetable(argtable, sizeof(argtable) / sizeof(argtable[0]));
		exit(0);
	}

	outfile->filename[0] = "-";
	caseSensitivity->count = 0;
	segmentPadding->count = 0;
	map->count = 0;
	nerrors = argParse(argc, argv, argtable);

	if (help->count > 0)
	{
		printf("Usage: %s", progname);
		argPrintSyntax(stdout, argtable, "\n");
		printf("    Each file may be an object file, a library, or a Win32 resource\n");
		printf("    file. If no extension is specified, .obj is assumed. Modules are\n");
		printf("    only loaded from library files if they are required to match an\n");
		printf("    external reference.\n");
		printf("    Options and files may be listed in any order, all mixed together.\n");
		printf("\n");
		argPrintGlossary(stdout, argtable, "  %-25s %s\n");
		arg_freetable(argtable, sizeof(argtable) / sizeof(argtable[0]));
		exit(0);
	}

	if (version->count > 0)
	{
		printf("LINKER (x86/x64) v1.0 (C) Copyright 2025 Christopher D. Wade.\n");
		printf("All Rights Reserved\n");
		arg_freetable(argtable, sizeof(argtable) / sizeof(argtable[0]));
		exit(0);
	}

	if (nerrors > 0)
	{
		argPrintErrors(stdout, end, progname);
		printf("Try '%s --help' for more information.\n", progname);
		arg_freetable(argtable, sizeof(argtable) / sizeof(argtable[0]));
		exit(1);
	}

	if (infiles->count == 0)
	{
		printf("No input files specified\n");
		arg_freetable(argtable, sizeof(argtable) / sizeof(argtable[0]));
		exit(1);
	}

	if (outfile->count == 0)
	{
		printf("No ouput file specified\n");
		arg_freetable(argtable, sizeof(argtable) / sizeof(argtable[0]));
		exit(1);
	}

	libList = getenv("LIB");
	if (libList)
	{
		for (i = 0, j = 0;; i++)
		{
			isend = (!libList[i]);
			if (libList[i] == ';' || !libList[i])
			{
				if (i - j)
				{
					unsigned long long temp = ((unsigned long long)libPathCount + 1) * sizeof(char*);
					libPath = (char **)checkRealloc(libPath, (size_t)temp);
					libList[i] = 0;
					if (libList[i - 1] == PATH_CHAR)
					{
						libPath[libPathCount] = checkStrdup(libList + j);
					}
					else
					{
						libPath[libPathCount] = (char *)checkMalloc(i - j + 2);
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
	loadFiles(infiles);
	arg_freetable(argtable, sizeof(argtable) / sizeof(argtable[0]));
	return 0;
}
