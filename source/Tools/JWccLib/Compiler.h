#pragma once

#include <string>
#include <map>
#include <vector>
#include "ProgramData.h"
#include "ExternalDeclaration.h"
#include "StructOrUnionSpecifier.h"

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
	};
}
