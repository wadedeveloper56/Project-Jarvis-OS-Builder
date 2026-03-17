#pragma once

#include <map>
#include <vector>
#include <string>
#include "Compile.h"
#include "ArgumentTable.h"

using namespace std;

namespace WadeSpace
{
	class ProgramData;
	class ExternalDeclaration;
	class StructOrUnionSpecifier;

	class Compile
	{
		ProgramData* programData;
		map<string, ExternalDeclaration*>* typedefList;
		map<string, StructOrUnionSpecifier*>* structList;
		vector<string>* functionList;
	public:
		Compile();
		~Compile();
		void compileFile(istringstream& inStr, ostream& out, int& exitcode);
		void compile(istream& in, ArgFilePtr infiles, ostream& out, int& exitcode);
		
		ProgramData* getProgramData() { return programData; }
		map<string, ExternalDeclaration*>* getTypedefList() { return typedefList; }
		map<string, StructOrUnionSpecifier*>* getStructList() { return structList; }
		vector<string>* getFunctionList() { return functionList; }
	};
}
