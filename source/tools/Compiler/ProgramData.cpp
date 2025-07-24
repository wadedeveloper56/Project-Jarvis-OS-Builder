#include <iostream>
#include "ProgramData.h"
#include "ExternalDeclaration.h"
#include "GlobalVars.h"

using namespace WadeSpace;
using namespace std;

ProgramData::ProgramData()
{
	programData = new vector<ExternalDeclaration*>();
	variableTable = new vector<VariableData*>();
}

ProgramData::~ProgramData()
{
	for (VariableData* ptr : *variableTable)
	{
		delete ptr;
	}
	delete variableTable;
	for (ExternalDeclaration* ptr : *programData)
	{
		delete ptr;
	}
	delete programData;
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
	for (VariableData* ptr : *variableTable)
	{
		if (ptr->size == 1) out << ptr->name << ":  resb 1" << endl;
		if (ptr->size == 2) out << ptr->name << ":  resw 1" << endl;
		if (ptr->size == 4) out << ptr->name << ":  resd 1" << endl;
		if (ptr->size == 8) out << ptr->name << ":  resq 1" << endl;
		if (ptr->size == 10) out << ptr->name << ":  rest 1" << endl;
		if (ptr->size == 16) out << ptr->name << ":  resb 16" << endl;
	}
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
				if (type == CHAR || type==BOOL) data->size = 1;
				if (type == SHORT) data->size = 2;
				if (type == INT) data->size = 4;
				if (type == LONG) data->size = 4;
				if (type == LONG_LONG) data->size = 8;
				if (type == FLOAT) data->size = 4;
				if (type == DOUBLE) data->size = 8;
				if (type == LONG_DOUBLE) data->size = 10;
				if (type == IMAGINARY) data->size = 8;
				if (type == COMPLEX) data->size = 16;
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
