#include "pch.h"
#include "Compiler.h"

using namespace std;
using namespace WadeSpace;

Compiler::Compiler()
{
	programData = new ProgramData();
	typedefList = new map<string, ExternalDeclaration*>();
	structList = new map<string, StructOrUnionSpecifier*>();
	functionList = new vector<string>();
}

Compiler::~Compiler()
{
	delete programData;
	if (typedefList != nullptr)
	{
		for (const auto& obj : *typedefList)
		{
			delete obj.second;
		}
		typedefList->clear();
		delete typedefList;
	}
	if (structList != nullptr)
	{
		for (const auto& obj : *structList)
		{
			delete obj.second;
		}
		structList->clear();
		delete structList;
	}
	functionList->clear();
	delete functionList;
}

