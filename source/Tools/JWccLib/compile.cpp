#include "pch.h"
#include "main.h"
#include "scanner.h"
#include "parser.hpp"
#include "interpreter.h"
#include "ArgumentTable.h"
#include "GlobalVars.h"
#include "simplecpp.h"
#include "BaseCodeGenerator.h"
#include "MasmCodeGenerator.h"

using namespace WadeSpace;
using namespace std;
using namespace simplecpp;

void compile(istream& in, ArgFilePtr infiles, ostream& out, int& exitcode)
{
	DUI dui;
	OutputList outputList;
	vector<string> files;
	TokenList* rawtokens;
	FileDataCache filedata;

	rawtokens = new TokenList(in, files, infiles->filename[0], &outputList);
	rawtokens->removeComments();
	TokenList outputTokens(files);
	preprocess(outputTokens, *rawtokens, files, filedata, dui, &outputList);
	cleanup(filedata);
	delete rawtokens;
	rawtokens = nullptr;
	cout << outputTokens.stringify() << endl << endl;;
	istringstream inStr(outputTokens.stringify());

	Interpreter i;
	i.setStreams(&inStr, &out);
	exitcode = i.parse();
	BaseCodeGenerator* generator = programData->processGlobalVariables();
	generator->generateCode(out);
	cout << "Parse complete. Result = " << exitcode << endl;
}