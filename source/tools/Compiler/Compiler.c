#include "global.h"
#include "ArgumentTable.h"

int initializeLexicalAnalysis(const char* fileInput) {
	int error;
	yyin = fopen(fileInput, "r");

	if (yyin == NULL)
		error = EXIT_FAILURE;
	else {
		error = EXIT_SUCCESS;
	}
	return error;
}

int endLexicalAnalysis() {
	int error;

	error = fclose(yyin);
	if (error == 0) {
		error = fclose(fileLexLog);
		if (error == 0)
			error = EXIT_SUCCESS;
		else
			error = EXIT_FAILURE;
	}
	else
		error = EXIT_FAILURE;
	return error;
}

int initializeSyntacticAnalysis(const char* fileOutput) {
	int error;

	yyout = fopen(fileOutput, "w");

	num_errors = 0;
	if (yyout == NULL) {
		error = EXIT_FAILURE;
	}
	else {
		error = EXIT_SUCCESS;
	}
	return error;
}

int symanticAnalysis() {
	int error;

	if (yyparse() == 0) {
		error = EXIT_SUCCESS;
	}
	else {
		error = EXIT_FAILURE;
	}
	return error;
}


int endSyntacticAnalysis() {
	int error;

	error = fclose(yyout);

	if (num_errors > 0) {
		fprintf(stdout, "\n\n\t-----------------------------------------------------");
		fprintf(stdout, "\n\t\t[ ERR ] Compiled with %d error/s\n", num_errors);
		fprintf(stdout, "\t-----------------------------------------------------\n\n");
	}
	else {
		fprintf(stdout, "\n\n\t-----------------------------------------------------");
		fprintf(stdout, "\n\t\t[ OK ] Compilation generated successfully\n");
		fprintf(stdout, "\t-----------------------------------------------------\n\n");
	}
	if (error == 0) {
		error = EXIT_SUCCESS;
	}
	else {
		error = EXIT_FAILURE;
	}
	return error;
}

int setArguments(int bitSize, const char* outfile, int v, const char** infiles, int ninfiles) {
	int i;

	if (bitSize == 16) bit16 = TRUE;
	if (bitSize == 32) bit32 = TRUE;
	if (bitSize == 64) bit64 = TRUE;

	_splitpath(infiles[0], drive, dir, fname, ext);
	_makepath(logFileName, drive, dir, fname, "log");

	fileLexLog = fopen(logFileName, "w");

	if (initializeLexicalAnalysis(infiles[0]) == EXIT_SUCCESS) {
		if (initializeSyntacticAnalysis(outfile) == EXIT_SUCCESS) {
			symanticAnalysis();
			if (v > 0) fprintf(fileLexLog, "verbose is enabled (-v)\n");
			fprintf(fileLexLog, "output is \"%s\"\n", outfile);
			fprintf(fileLexLog, "bit size=%d bits\n", bitSize);
			for (i = 0; i < ninfiles; i++) {
				fprintf(fileLexLog, "infile[%d]=\"%s\"\n", i, infiles[i]);
			}
			fprintf(fileLexLog, "log file =\"%s\"\n", logFileName);
			endLexicalAnalysis();
			endSyntacticAnalysis();
		}
	}


	return 0;
}

int main(int argc, char* argv[]) {
	ArgIntPtr bitsize = arg_int0("b", "bitsize", NULL, "define bit size to be 16, 32 or 64 bits (default is 32)");
	ArgFilePtr outfile = arg_file0("o", NULL, "<output>", "output file (default is \"-\")");
	ArgLitPtr verbose = arg_lit0("v", "verbose,debug", "verbose messages");
	ArgLitPtr help = arg_lit0(NULL, "help", "print this help and exit");
	ArgLitPtr version = arg_lit0(NULL, "version", "print version information and exit");
	ArgFilePtr infiles = arg_filen(NULL, NULL, NULL, 1, argc + 2, "input file(s)");
	struct arg_end* end = arg_end(20);
	void* argtable[] = { bitsize,outfile,verbose,help,version,infiles,end };
	const char* progname = "Compiler";
	int nerrors;
	int exitcode = 0;

	if (arg_nullcheck(argtable) != 0)
	{
		printf("%s: insufficient memory\n", progname);
		exitcode = 1;
		goto exit;
	}

	bitsize->ival[0] = 32;
	outfile->filename[0] = "-";

	nerrors = argParse(argc, argv, argtable);

	if (help->count > 0)
	{
		printf("Usage: %s", progname);
		arg_print_syntax(stdout, argtable, "\n");
		printf("Compiler that coverts c code to 16,32 or 64 bit assembler\n");
		arg_print_glossary(stdout, argtable, "  %-25s %s\n");
		exitcode = 0;
		goto exit;
	}

	if (version->count > 0)
	{
		printf("'%s' c code to assember compiler.\n", progname);
		printf("June 2025, (c) Christopher D. Wade\n");
		exitcode = 0;
		goto exit;
	}

	if (nerrors > 0)
	{
		arg_print_errors(stdout, end, progname);
		printf("Try '%s --help' for more information.\n", progname);
		exitcode = 1;
		goto exit;
	}

	if (argc == 1)
	{
		printf("Try '%s --help' for more information.\n", progname);
		exitcode = 0;
		goto exit;
	}

	exitcode = setArguments(bitsize->ival[0], outfile->filename[0], verbose->count, infiles->filename, infiles->count);

exit:
	arg_freetable(argtable, sizeof(argtable) / sizeof(argtable[0]));

	return exitcode;
}