#include <iostream>
#include "ProgramData.h"
#include "ExternalDeclaration.h"
#include "GlobalVars.h"
#include "ParameterTypeList.h"
#include "NasmCodeGenerator.h"

using namespace WadeSpace;
using namespace std;

ProgramData::ProgramData()
{
	programData = new vector<ExternalDeclaration*>();
}

ProgramData::~ProgramData()
{
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

BaseCodeGenerator* ProgramData::processGlobalVariables()
{
	vector<VariableData*>* variableTable = new vector<VariableData*>();
	vector<FunctionData*>* functionTable = new vector<FunctionData*>();
	vector<FunctionData*>* functionPrototypeTable = new vector<FunctionData*>();

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
				if ((dd->getStr1() == OPAREN && dd->getStr2() == CPAREN) || (dd->getParameterTypeList() != nullptr))
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
	generator = new NasmCodeGenerator(variableTable, functionTable, functionPrototypeTable);
	return generator;
}
