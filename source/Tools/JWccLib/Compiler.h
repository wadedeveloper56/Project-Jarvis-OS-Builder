#pragma once

#include <string>
#include <map>
#include <vector>
#include "ProgramData.h"
#include "ExternalDeclaration.h"
#include "StructOrUnionSpecifier.h"
#include "ArgumentTable.h"

namespace WadeSpace
{
	class Compiler
	{
		ProgramData* programData;
		map<string, ExternalDeclaration*>* typedefList;
		map<string, StructOrUnionSpecifier*>* structList;
		vector<string>* functionList;
	public:
		Compiler();
		~Compiler();
		void compileFile(istringstream& inStr, ostream& out, int& exitcode);
		void compile(istream& in, ArgFilePtr infiles, ostream& out, int& exitcode);
		[[nodiscard]] ProgramData* getProgramData() const { return programData; }
		[[nodiscard]] map<string, ExternalDeclaration*>* getTypedefList() const { return typedefList; }
		[[nodiscard]] map<string, StructOrUnionSpecifier*>* getStructList() const { return structList; }
		[[nodiscard]] vector<string>* getFunctionList() const { return functionList; }
	};
}
