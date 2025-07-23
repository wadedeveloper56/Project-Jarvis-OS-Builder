#include <iostream>
#include "ProgramData.h"
#include "ExternalDeclaration.h"
#include "GlobalVars.h"

using namespace WadeSpace;
using namespace std;

ProgramData::ProgramData()
{
	programData = make_unique<vector<ExternalDeclaration*>>();
	variableTable = make_unique<vector<VariableData*>>();
}

ProgramData::~ProgramData()
{
	for (VariableData* ptr : *variableTable)
	{
		delete ptr;
	}
	for (ExternalDeclaration* ptr : *programData)
	{
		delete ptr;
	}
}

void ProgramData::add(ExternalDeclaration* data)
{
	programData->push_back(data);
}

void ProgramData::generateCode(ofstream& out)
{
	if (bit16)
		out << "BITS 16" << endl;
	else if (bit32)
		out << "BITS 32" << endl;
	else
		out << "BITS 64" << endl;
	out << "SECTION .data" << endl;
	out << "SECTION .bss" << endl;
	out << "SECTION .text" << endl;
}

void ProgramData::processGlobalVariables()
{
	for (ExternalDeclaration* ptr : *programData)
	{
		if (ptr->isDeclaration())
		{
			Declaration* declaration = ptr->getDeclaration();
			TokenType type = declaration->getDeclarationSpecifiers()->getTypeSpecifier()->getType();
			for (InitDeclarator* initDecl : *declaration->getVectorInitDeclarator())
			{
				VariableData* data = new VariableData();
				data->name = initDecl->getVariableName();
				data->type = type;
				variableTable->push_back(data);
			}
		}
		else if (ptr->isFunction())
		{
		}
	}
}

void ProgramData::test()
{
	cout << "Number of entries in programData table: " << programData->size() << endl;
	for (VariableData* ptr : *variableTable)
	{
		cout << "  variable = " << ptr->name << " " << ptr->type << endl;
	}
}
