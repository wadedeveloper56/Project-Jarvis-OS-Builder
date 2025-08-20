#include "pch.h"
#include "Linker.h"
#include "ArgumentTable.h"

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

	printf("LINKER (x86/x64) v1.0 (C) Copyright 2025 Christopher D. Wade.\n");
	printf("All Rights Reserved\n");

	if (argNullCheck(argtable) != 0)
	{
		printf("%s: insufficient memory\n", progname);
		exitcode = 1;
	}
	else
	{
		if (argc == 1)
		{
			printf("Try '%s --help' for more information.\n", progname);
			exitcode = 0;
		}
		else
		{
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
				exitcode = 0;
			}
			else {
				if (version->count > 0)
				{
					printf("LINKER (x86/x64) v1.0 (C) Copyright 2025 Christopher D. Wade.\n");
					printf("All Rights Reserved\n");
					exitcode = 0;
				}
				else
				{
					if (nerrors > 0)
					{
						argPrintErrors(stdout, end, progname);
						printf("Try '%s --help' for more information.\n", progname);
						exitcode = 1;
					}
				}
			}
		}
	}

	return 0;
}
