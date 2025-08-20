#include <fstream>
#include <sstream>
#include "scanner.h"
#include "parser.hpp"
#include "interpreter.h"
#include "ArgumentTable.h"
#include "GlobalVars.h"
#include "simplecpp.h"

using namespace WadeSpace;
using namespace std;
using namespace simplecpp;

int main(int argc, char* argv[])
{
	ifstream in;
	ofstream out;
	ArgIntPtr bitsize = argInt0("bB", "bitsize", NULL, "define bit size to be 16, 32 or 64 bits (default is 32)");
	ArgFilePtr outfile = argFile0("Oo", "output", "<file>", "output file (default is \"-\")");
	ArgLitPtr help = argLit0("hH", "help", "print this help and exit");
	ArgLitPtr version = argLit0("vV", "version", "print version information and exit");
	ArgFilePtr infiles = argFileN(NULL, NULL, NULL, 1, argc + 2, "input file(s)");
	ArgEndPtr end = argEnd(20);
	void* argtable[] = {bitsize, outfile, help, version, infiles, end};
	const char* progname = "Compiler";
	int exitcode = 0, nerrors = 0;

	printf("Compiler (x86/x64) v1.0 (C) Copyright 2025 Christopher D. Wade.\n");
	printf("All Rights Reserved\n"); 
	
	if (argNullCheck(argtable) != 0)
	{
		printf("%s: insufficient memory\n", progname);
		exitcode = 1;
		goto exit;
	}
	bitsize->ival[0] = 32;
	outfile->filename[0] = "-";

	nerrors = argParse(argc, argv, argtable);

	if (bitsize->ival[0] == 16)
		bit16 = true;
	else if (bitsize->ival[0] == 32)
		bit32 = true;
	else
		bit64 = true;

	if (help->count > 0)
	{
		printf("Usage: %s", progname);
		argPrintSyntax(stdout, argtable, "\n");
		printf("Compiler that coverts c code to 16,32 or 64 bit assembler\n");
		argPrintGlossary(stdout, argtable, "  %-25s %s\n");
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
		argPrintErrors(stdout, end, progname);
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

	_splitpath(infiles->filename[0], drive, dir, fname, ext);
	_makepath(logFileName, drive, dir, fname, "asm");

	in.open(infiles->filename[0], ifstream::in);
	out.open(logFileName, ofstream::out);

	if (in.is_open() && out.is_open())
	{
		DUI dui;
		OutputList outputList;
		vector<string> files;
		TokenList* rawtokens;

		rawtokens = new TokenList(in, files, infiles->filename[0], &outputList);
		rawtokens->removeComments();
		TokenList outputTokens(files);
		FileDataCache filedata;
		preprocess(outputTokens, *rawtokens, files, filedata, dui, &outputList);
		cleanup(filedata);
		delete rawtokens;
		rawtokens = nullptr;
		cout << outputTokens.stringify() << endl;
		istringstream inStr(outputTokens.stringify());

		Interpreter i;
		i.setStreams(&inStr, &out);
		exitcode = i.parse();
		program->processGlobalVariables();
		program->test();
		program->generateCode(out);
		cout << "Parse complete. Result = " << exitcode << endl;
	}
	else
	{
		cerr << "Error opening file " << infiles->filename[0] << endl;
		exitcode = -1;
	}
exit:
	arg_freetable(argtable, sizeof(argtable) / sizeof(argtable[0]));
	in.close();
	out.close();
	delete program;
	return exitcode;
}
