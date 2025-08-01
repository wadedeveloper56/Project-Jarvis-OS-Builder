#include <iostream>
#include "ProgramData.h"
#include "ExternalDeclaration.h"
#include "GlobalVars.h"
#include "ParameterTypeList.h"

using namespace WadeSpace;
using namespace std;

ProgramData::ProgramData()
{
	programData = new vector<ExternalDeclaration*>();
	variableTable = new vector<VariableData*>();
	functionTable = new vector<FunctionData*>();
	functionPrototypeTable = new vector<FunctionData*>();
}

ProgramData::~ProgramData()
{
	for (FunctionData* ptr : *functionPrototypeTable)
	{
		for (VariableData* data : *ptr->parameters)
		{
			delete data;
		}
		delete ptr->parameters;
		delete ptr;
	}
	delete functionPrototypeTable;
	for (FunctionData* ptr : *functionTable)
	{
		for (VariableData* data : *ptr->parameters)
		{
			delete data;
		}
		delete ptr->parameters;
		delete ptr;
	}
	delete functionTable;
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
	out << "\t" << "SECTION .data" << endl;
	out << "\t" << "SECTION .bss" << endl;
	for (VariableData* ptr : *variableTable)
	{
		if (ptr->size == 1) out << ptr->name << ":  resb 1" << endl;
		if (ptr->size == 2) out << ptr->name << ":  resw 1" << endl;
		if (ptr->size == 4) out << ptr->name << ":  resd 1" << endl;
		if (ptr->size == 8) out << ptr->name << ":  resq 1" << endl;
		if (ptr->size == 10) out << ptr->name << ":  rest 1" << endl;
		if (ptr->size == 16) out << ptr->name << ":  resb 16" << endl;
	}
	out << "\t" << "SECTION .text" << endl;
	for (FunctionData* ptr : *functionTable)
	{
		out << "\t global _" << ptr->name << endl;
		out << "_" << ptr->name << ":" << endl;
		out << "\tret" << endl << endl;
	}
}

int ProgramData::getSize(TokenType type)
{
	if (type == CHAR || type == BOOL) return 1;
	if (type == SHORT) return 2;
	if (type == INT) return 4;
	if (type == LONG) return 4;
	if (type == LONG_LONG) return 8;
	if (type == FLOAT) return 4;
	if (type == DOUBLE) return 8;
	if (type == LONG_DOUBLE) return 10;
	if (type == IMAGINARY) return 8;
	if (type == COMPLEX) return 16;
	return 0;
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
				DirectDeclarator* dd = initDecl->getDeclarator()->getDirectDeclarator();
				if ((dd->getStr1() == "(" && dd->getStr2() == ")") || (dd->getParameterTypeList() != nullptr))
				{
					optional<string> name = dd->getDirectDeclarator()->getIdentifier();
					FunctionData* data = new FunctionData();
					data->type = type;
					data->name = name.value();
					data->size = getSize(type);
					functionPrototypeTable->push_back(data);
				}
				else {
					data->name = initDecl->getVariableName();
					data->type = type;
					data->size = getSize(type);
					variableTable->push_back(data);
				}
			}
		}
		else if (ptr->isFunction())
		{
			FunctionDefinition* declaration = ptr->getFunction();
			FunctionData* data = new FunctionData();
			data->type = declaration->getDeclarationSpecifiers()->getTypeSpecifier()->getType();
			data->name = declaration->getDeclarator()->getDirectDeclarator()->getDirectDeclarator()->getIdentifier().value();
			ParameterTypeList* parameters = declaration->getDeclarator()->getDirectDeclarator()->getParameterTypeList();
			if (parameters != nullptr && !parameters->getVectorParameterDeclaration()->empty())
			{
				data->parameters = new vector<VariableData*>();
				for (ParameterDeclaration* parameterDeclaration : *parameters->getVectorParameterDeclaration())
				{
					VariableData* functionData = new VariableData();
					functionData->name = parameterDeclaration->getDeclarator()->getDirectDeclarator()->getIdentifier().value();
					TokenType type = parameterDeclaration->getDeclarationSpecifiers()->getTypeSpecifier()->getType();
					functionData->type = type;
					functionData->size = getSize(type);
					data->parameters->push_back(functionData);
				}
			}
			functionTable->push_back(data);
		}
	}
}

void ProgramData::test()
{
	cout << "Number of entries in programData table: " << programData->size() << endl;
	cout << "Number of entries in variable table: " << variableTable->size() << endl;
	cout << "Number of entries in function table: " << functionTable->size() << endl;
	cout << "Number of entries in function prototype table: " << functionPrototypeTable->size() << endl;
}
