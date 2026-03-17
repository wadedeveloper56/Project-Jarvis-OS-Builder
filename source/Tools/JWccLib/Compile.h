#pragma once

#include <map>
#include <vector>
#include <string>
#include "Compile.h"
#include "ArgumentTable.h"
#include "ProgramData.h"
#include "ExternalDeclaration.h"
#include "StructOrUnionSpecifier.h"

using namespace std;

namespace WadeSpace
{
	class Compile
	{
		ProgramData programData;
		map<string, ExternalDeclaration*> typedefList;
		map<string, StructOrUnionSpecifier*> structList;
		vector<string> functionList;
	public:
		Compile();
		~Compile();
		void compileFile(istringstream& inStr, ostream& out, int& exitcode);
		void compile(istream& in, ArgFilePtr infiles, ostream& out, int& exitcode);
		
		ProgramData getProgramData() { return programData; }
		map<string, ExternalDeclaration*> getTypedefList() { return typedefList; }
		map<string, StructOrUnionSpecifier*> getStructList() { return structList; }
		vector<string> getFunctionList() { return functionList; }
	};
}
