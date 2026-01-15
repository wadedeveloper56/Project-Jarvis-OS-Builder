#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cansi.tab.h"
#include "wic.h"
#include "ArgumentTable.h"

extern FILE* yyin; 

void printHeader(void)
{
	printf("JWcc - Open Source C Compiler v0.0.1 (C) Copyright 2025 Christopher D. Wade.\n");
	printf("All Rights Reserved\n");
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
	g_opt.fileNameList = createSLList();
	for (int i = 0; i < infiles->count; i++)
	{
		addSLListElem(g_opt.fileNameList, _strdup(infiles->filename[i]));
	}
	argFreeTable(argtable, sizeof(argtable) / sizeof(argtable[0]));
}

static void initJccBasics(int argc, char* argv[]) {
    g_commentList = createSLList();
    g_dirList = createSLList();
    g_logList = createSLList();
    g_currPos = NULL;
    getCmdLineOptions(argc, argv);
}

void jccExit(int exitCode) {
    if (exitCode == 0) {
        zapSLList(g_logList, NULL);
        zapSLList(g_dirList, NULL);
        zapSLList(g_commentList, NULL);
    }
    else {
        printf("WIC: Terminating with error...\n");
        _fcloseall();
    }
    exit(exitCode);
}

static void doConversion(void** name) 
{
	char* newName = *name;
	printf("Processing file: %s\n", newName);
	yyin = fopen(newName, "r");
	if (yyin == NULL) {
		printf("Error: Could not open file %s for reading.\n", newName);
		jccExit(1);
	}
	yyparse();
	if (yyin!=NULL) fclose(yyin);
}

void main(int argc, char* argv[])
{
    initJccBasics(argc, argv);
	forAllInSLList(g_opt.fileNameList, doConversion);
	jccExit(0);
}
