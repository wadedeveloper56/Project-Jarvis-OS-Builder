#include "pch.h"
#include "BaseCodeGenerator.h"

using namespace WadeSpace;

BaseCodeGenerator::BaseCodeGenerator() : variableTable(nullptr), functionTable(nullptr)
{
}

BaseCodeGenerator::BaseCodeGenerator(vector<VariableData*>* const variable_table, vector<FunctionData*>* const function_table) : variableTable(variable_table),	functionTable(function_table)
{
}

BaseCodeGenerator::~BaseCodeGenerator()
{
	if (variableTable != nullptr)
	{
		for (auto ptr : *variableTable)
		{
			delete ptr;
		}
		delete variableTable;
	}
	if (functionTable != nullptr)
	{
		for (auto ptr : *functionTable)
		{
			delete ptr;
		}
		delete functionTable;
	}
}

vector<VariableData*>* BaseCodeGenerator::getVariableTable() const
{
	return variableTable;
}

vector<FunctionData*>* BaseCodeGenerator::getFunctionTable() const
{
	return functionTable;
}

bool BaseCodeGenerator::isVariableTable() const
{
	return variableTable != nullptr;
}

bool BaseCodeGenerator::isFunctionTable() const
{
	return functionTable != nullptr;
}
