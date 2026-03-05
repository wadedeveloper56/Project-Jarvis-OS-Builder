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

bool BaseCodeGenerator::hasVariableTable() const
{
	return variableTable != nullptr;
}

bool BaseCodeGenerator::hasFunctionTable() const
{
	return functionTable != nullptr;
}

BaseCodeGenerator::BaseCodeGenerator(const BaseCodeGenerator& other)
{
	variableTable = other.variableTable ? new vector<VariableData*>(*other.variableTable) : nullptr;
	functionTable = other.functionTable ? new vector<FunctionData*>(*other.functionTable) : nullptr;
}

BaseCodeGenerator::BaseCodeGenerator(BaseCodeGenerator&& other) noexcept
{
	variableTable = other.variableTable ? new vector<VariableData*>(*other.variableTable) : nullptr;
	functionTable = other.functionTable ? new vector<FunctionData*>(*other.functionTable) : nullptr;
}

BaseCodeGenerator& BaseCodeGenerator::operator=(const BaseCodeGenerator& other)
{
	if (this == &other)
		return *this;
	variableTable = other.variableTable ? new vector<VariableData*>(*other.variableTable) : nullptr;
	functionTable = other.functionTable ? new vector<FunctionData*>(*other.functionTable) : nullptr;
	return *this;
}

BaseCodeGenerator& BaseCodeGenerator::operator=(BaseCodeGenerator&& other) noexcept
{
	if (this == &other)
		return *this;
	variableTable = other.variableTable ? new vector<VariableData*>(*other.variableTable) : nullptr;
	functionTable = other.functionTable ? new vector<FunctionData*>(*other.functionTable) : nullptr;
	return *this;
}

