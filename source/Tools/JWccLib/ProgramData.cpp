#include "pch.h"
#include "ProgramData.h"

#include "Expression.h"
#include "ExternalDeclaration.h"
#include "GlobalVars.h"
#include "ParameterTypeList.h"
#include "MasmCodeGenerator.h"
#include "StructOrUnionSpecifier.h"

using namespace WadeSpace;
using namespace std;

ProgramData::ProgramData()
{
	this->program = new vector<ExternalDeclaration*>();
	this->generator = nullptr;
}

ProgramData::~ProgramData()
{
	if (program != nullptr)
	{
		for (auto ptr : *program)
		{
			delete ptr;
		}
		delete program;
	}
}

void ProgramData::add(ExternalDeclaration* data)
{
	program->push_back(data);
}

int ProgramData::getSize(TokenType type, bool isPointer)
{
	if (isPointer)
	{
		if (bit64) return 8;
		else if (bit32) return 4;
		else return 2;
	}
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

void ProgramData::handleFunction(FunctionDefinition* declaration, vector<FunctionData*>* functionTable)
{
	FunctionData* data = new FunctionData();
	data->type = declaration->getDeclarationSpecifiers()->getTypeSpecifier()->getType().value();
	data->name = declaration->getDeclarator()->getDirectDeclarator()->getDirectDeclarator()->getIdentifier()->
	                          getSymbolName();
	ParameterTypeList* parameters = declaration->getDeclarator()->getDirectDeclarator()->getParameterTypeList();
	if (parameters != nullptr && !parameters->getVectorParameterDeclaration()->empty())
	{
		data->parameters = new vector<VariableData*>();
		for (ParameterDeclaration* parameterDeclaration : *parameters->getVectorParameterDeclaration())
		{
			VariableData* functionData = new VariableData();
			if (parameterDeclaration->getDeclarator()->getDirectDeclarator()->getIdentifier() != nullptr)
			{
				functionData->name = parameterDeclaration->getDeclarator()->getDirectDeclarator()->getIdentifier()->
				                                           getSymbolName();
			}
			else
			{
				functionData->name = parameterDeclaration->getDeclarator()->getDirectDeclarator()->getDirectDeclarator()
				                                         ->getIdentifier()->getSymbolName();
			}
			TokenType type = parameterDeclaration->getDeclarationSpecifiers()->getTypeSpecifier()->getType().value();
			functionData->pointer = parameterDeclaration->getDeclarator()->isPointer();
			functionData->type = type;
			functionData->size = getSize(type, functionData->pointer);
			data->parameters->push_back(functionData);
		}
	}
	functionTable->push_back(data);
}

void ProgramData::handleInitDeclaratorForDeclaratation(Declaration* declaration, vector<VariableData*>* variableTable,
                                                       TokenType type)
{
	for (InitDeclarator* initDecl : *declaration->getVectorInitDeclarator())
	{
		VariableData* data = new VariableData();
		auto declarator = initDecl->getDeclarator();
		DirectDeclarator* dd = declarator->getDirectDeclarator();
		if (dd->getIdentifier() != nullptr)
		{
			data->name = dd->getIdentifier()->getSymbolName();
		}
		else
		{
			data->name = dd->getDirectDeclarator()->getIdentifier()->getSymbolName();
		}
		data->initializer = nullptr;
		if (initDecl->isInitializer()) data->initializer = new Initializer(*initDecl->getInitializer());
		data->arraySize = 1;
		if (dd->isConstantExpression()) data->arraySize = dd->getConstantExpression()->getData()->getConstant()->getIConst()->data->repr.numericConstant.repr.lIntConst;
		data->type = type;
		data->pointer = declarator->isPointer();
		data->size = getSize(type, data->pointer);
		variableTable->push_back(data);
	}
}

void ProgramData::handleDeclaration(Declaration* declaration, vector<VariableData*>* variableTable)
{
	TokenType type = declaration->getType();
	if (declaration != nullptr)
	{
		if (declaration->getVectorInitDeclarator() != nullptr)
		{
			handleInitDeclaratorForDeclaratation(declaration, variableTable, type);
		}
	}
}

BaseCodeGenerator* ProgramData::processGlobalVariables()
{
	vector<VariableData*>* variableTable = new vector<VariableData*>();
	vector<FunctionData*>* functionTable = new vector<FunctionData*>();

	if (program != nullptr)
	{
		for (ExternalDeclaration* ptr : *program)
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
