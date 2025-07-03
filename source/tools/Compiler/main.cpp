#include <fstream>
#include "scanner.h"
#include "parser.hpp"
#include "interpreter.h"
#include "ArgumentTable.h"
using namespace WadeSpace;
using namespace std;

int main(int argc, char* argv[]) {
	ifstream rfile;
	ArgIntPtr bitsize = arg_int0("b", "bitsize", NULL, "define bit size to be 16, 32 or 64 bits (default is 32)");
	ArgFilePtr outfile = arg_file0("o", NULL, "<output>", "output file (default is \"-\")");
	ArgLitPtr verbose = arg_lit0("v", "verbose,debug", "verbose messages");
	ArgLitPtr help = arg_lit0(NULL, "help", "print this help and exit");
	ArgLitPtr version = arg_lit0(NULL, "version", "print version information and exit");
	ArgFilePtr infiles = arg_filen(NULL, NULL, NULL, 1, argc + 2, "input file(s)");
	ArgEndPtr end = arg_end(20);
	void* argtable[] = { bitsize,outfile,verbose,help,version,infiles,end };
	const char* progname = "Compiler";
	int exitcode = 0, nerrors = 0;

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

	rfile.open(argv[1], ifstream::in);

	if (rfile.is_open()) {
		Interpreter i;
		i.switchInputStream(&rfile);
		exitcode = i.parse();
		cout << "Parse complete. Result = " << exitcode << endl;
	}
	else {
		cerr << "Error opening file " << argv[1] << endl;
		exitcode = -1;
	}
exit:
	arg_freetable(argtable, sizeof(argtable) / sizeof(argtable[0]));
	rfile.close();
	return exitcode;
}
