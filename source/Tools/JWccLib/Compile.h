#pragma once

#include <map>
#include <vector>
#include <string>

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
	};
}
