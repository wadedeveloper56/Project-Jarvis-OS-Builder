#include "pch.h"
#include "ProgramData.h"
#include "ExternalDeclaration.h"
#include "GlobalVars.h"
#include "ParameterTypeList.h"
#include "MasmCodeGenerator.h"

using namespace WadeSpace;
using namespace std;

ProgramData::ProgramData()
{
	this->programData = new vector<ExternalDeclaration*>();
	this->generator = nullptr;
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

void ProgramData::handleDeclaration(Declaration* declaration, vector<VariableData*>* variableTable)
{
	TokenType type = declaration->getDeclarationSpecifiers()->getTypeSpecifier()->getType().value();
	for (InitDeclarator* initDecl : *declaration->getVectorInitDeclarator())
	{
		VariableData* data = new VariableData();
		DirectDeclarator* dd = initDecl->getDeclarator()->getDirectDeclarator();
		/*
		if (!((dd->getToken1() != nullptr && dd->getToken1()->data->repr.symbol.string == "(" && dd->getToken2() != nullptr && dd->getToken2()->data->repr.symbol.string == ")") || (dd->getParameterTypeList() != nullptr)))
		{
			data->name = initDecl->getVariableName();
			data->type = type;
			data->size = getSize(type);
			variableTable->push_back(data);
		}
		*/
	}
}

void ProgramData::handleFunction(FunctionDefinition* declaration, vector<FunctionData*>* functionTable)
{
	FunctionData* data = new FunctionData();
	data->type = declaration->getDeclarationSpecifiers()->getTypeSpecifier()->getType().value();
	data->name = declaration->getDeclarator()->getDirectDeclarator()->getDirectDeclarator()->getIdentifier()->data->repr.symbol.string;
	ParameterTypeList* parameters = declaration->getDeclarator()->getDirectDeclarator()->getParameterTypeList();
	if (parameters != nullptr && !parameters->getVectorParameterDeclaration()->empty())
	{
		data->parameters = new vector<VariableData*>();
		for (ParameterDeclaration* parameterDeclaration : *parameters->getVectorParameterDeclaration())
		{
			VariableData* functionData = new VariableData();
			functionData->name = parameterDeclaration->getDeclarator()->getDirectDeclarator()->getIdentifier()->data->repr.symbol.string;
			TokenType type = parameterDeclaration->getDeclarationSpecifiers()->getTypeSpecifier()->getType().value();
			functionData->type = type;
			functionData->size = getSize(type);
			data->parameters->push_back(functionData);
		}
	}
	functionTable->push_back(data);
}

BaseCodeGenerator* ProgramData::processGlobalVariables()
{
	vector<VariableData*>* variableTable = new vector<VariableData*>();
	vector<FunctionData*>* functionTable = new vector<FunctionData*>();

	if (programData != NULL)
	{
		for (ExternalDeclaration* ptr : *programData)
		{
			if (ptr->isDeclaration())
			{
				handleDeclaration(ptr->getDeclaration(), variableTable);
			}
			else if (ptr->isFunction())
			{
				handleFunction(ptr->getFunction(), functionTable);
			}
		}
	}
	generator = new MasmCodeGenerator(variableTable, functionTable);
	return generator;
}
