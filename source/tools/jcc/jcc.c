#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jcc.h"

extern FILE* yyin; 
LinkedListPtr files;

void printHeader(void)
{
	printf("JWcc - Open Source C Compiler v0.0.1 (C) Copyright 2025 Christopher D. Wade.\n");
	printf("All Rights Reserved\n");
}

void doConversion(void** name) 
{
	char* newName = *name;
	printf("Processing file: %s\n", newName);
	yyin = fopen(newName, "r");
	if (yyin == NULL) {
		printf("Error: Could not open file %s for reading.\n", newName);
		terminate(1);
	}
	yyparse();
	if (yyin!=NULL) fclose(yyin);
}

void getCmdLineOptions(int argc, char* argv[]) {
	ArgLitPtr help = argLit0("hH?", "help", "print this help and exit");
	ArgLitPtr version = argLit0("vV", "version", "print version information and exit");
	ArgFilePtr infiles = argFileN(NULL, NULL, NULL, 1, argc + 2, "input file(s)");
	ArgEndPtr end = argEnd(20);
	const char* progname = "PEDump";
	int exitcode = 0, nerrors = 0;
	void* argtable[] = {help, version, infiles, end };
	
	printHeader();
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
		argPrintGlossary(stdout, argtable, "  %-35s %s\n");
		exit(1);
	}
	if (version->count > 0)
	{
		printHeader();
		exit(1);
	}
	if (nerrors > 0)
	{
		argPrintErrors(stdout, end, progname);
		printf("Try '%s --help' for more information.\n", progname);
		exit(1);
	}
	files = createList();
	for (int i = 0; i < infiles->count; i++)
	{
		addListElem(files,(void *)infiles->filename[i]);
	}
	argFreeTable(argtable, sizeof(argtable) / sizeof(argtable[0]));
}

void initiate(int argc, char* argv[]) {
    getCmdLineOptions(argc, argv);
}

void terminate(int exitCode) {
    _fcloseall();
    exit(exitCode);
}

void main(int argc, char* argv[])
{
    initiate(argc, argv);
	LinkedListNodePtr ptr = files->list;
	while (ptr != NULL && ptr->userData != NULL)
	{
		doConversion(&ptr->userData);
		ptr = ptr->next;
	}	
	terminate(0);
}
