#include "pch.h"
#include "Compile.h"
#include "ProgramData.h"
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

Compile::Compile()
{
}

Compile::~Compile()
{
}

void Compile::compileFile(istringstream& inStr, ostream& out, int& exitcode)
{
	Interpreter i;
	i.setStreams(&inStr, &out);
	exitcode = i.parse();
	BaseCodeGenerator* generator = programData.processGlobalVariables();
	generator->generateCode(out);
}

void Compile::compile(istream& in, ArgFilePtr infiles, ostream& out, int& exitcode)
{
	string name = infiles->filename[0];
	DUI dui;
	OutputList outputList;
	vector<string> files;
	TokenList* rawtokens;
	FileDataCache filedata;

	rawtokens = new TokenList(in, files, name, &outputList);
	rawtokens->removeComments();
	TokenList outputTokens(files);
	preprocess(outputTokens, *rawtokens, files, filedata, dui, &outputList);
	cleanup(filedata);
	delete rawtokens;
	rawtokens = nullptr;
	cout << outputTokens.stringify() << endl << endl;;
	istringstream inStr(outputTokens.stringify());

	compileFile(inStr, out, exitcode);

	cout << "Parse complete. Result = " << exitcode << endl;
}