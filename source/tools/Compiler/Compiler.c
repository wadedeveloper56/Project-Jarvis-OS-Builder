/*******************************************************************************
 * compiler: Provides the sub-command mechanism
 *
 * This file is part of the ArgumentsTable library.
 *
 * Copyright (C) 2025 Christopher D. Wade
 * <wade4615@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of STEWART HEITMANN nor the  names of its contributors
 *       may be used to endorse or promote products derived from this software
 *       without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL STEWART HEITMANN BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/
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
	struct arg_file* outfile = arg_file0("o", NULL, "<output>", "output file (default is \"-\")");
	ArgLitPtr verbose = arg_lit0("v", "verbose,debug", "verbose messages");
	ArgLitPtr help = arg_lit0(NULL, "help", "print this help and exit");
	ArgLitPtr version = arg_lit0(NULL, "version", "print version information and exit");
	struct arg_file* infiles = arg_filen(NULL, NULL, NULL, 1, argc + 2, "input file(s)");
	struct arg_end* end = arg_end(20);
	void* argtable[] = { bitsize,outfile,verbose,help,version,infiles,end };
	const char* progname = "Compiler";
	int nerrors;
	int exitcode = 0;

	/* verify the argtable[] entries were allocated sucessfully */
	if (arg_nullcheck(argtable) != 0)
	{
		/* NULL entries were detected, some allocations must have failed */
		printf("%s: insufficient memory\n", progname);
		exitcode = 1;
		goto exit;
	}

	/* set any command line default values prior to parsing */
	bitsize->ival[0] = 32;
	outfile->filename[0] = "-";

	/* Parse the command line as defined by argtable[] */
	nerrors = argParse(argc, argv, argtable);

	/* special case: '--help' takes precedence over error reporting */
	if (help->count > 0)
	{
		printf("Usage: %s", progname);
		arg_print_syntax(stdout, argtable, "\n");
		printf("Compiler that coverts c code to 16,32 or 64 bit assembler\n");
		arg_print_glossary(stdout, argtable, "  %-25s %s\n");
		exitcode = 0;
		goto exit;
	}

	/* special case: '--version' takes precedence error reporting */
	if (version->count > 0)
	{
		printf("'%s' c code to assember compiler.\n", progname);
		printf("June 2025, (c) Christopher D. Wade\n");
		exitcode = 0;
		goto exit;
	}

	/* If the parser returned any errors then display them and exit */
	if (nerrors > 0)
	{
		/* Display the error details contained in the arg_end struct.*/
		arg_print_errors(stdout, end, progname);
		printf("Try '%s --help' for more information.\n", progname);
		exitcode = 1;
		goto exit;
	}

	/* special case: uname with no command line options induces brief help */
	if (argc == 1)
	{
		printf("Try '%s --help' for more information.\n", progname);
		exitcode = 0;
		goto exit;
	}

	/* normal case: take the command line options at face value */
	exitcode = setArguments(bitsize->ival[0], outfile->filename[0], verbose->count, infiles->filename, infiles->count);

exit:
	/* deallocate each non-null entry in argtable[] */
	arg_freetable(argtable, sizeof(argtable) / sizeof(argtable[0]));

	return exitcode;
}