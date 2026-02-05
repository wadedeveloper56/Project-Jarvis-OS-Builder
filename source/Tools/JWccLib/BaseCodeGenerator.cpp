#include "pch.h"
#include "BaseCodeGenerator.h"

using namespace WadeSpace;

BaseCodeGenerator::BaseCodeGenerator(vector<VariableData*>* const variable_table,
                                     vector<FunctionData*>* const function_table)
	: variableTable(variable_table),
	  functionTable(function_table)
{
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

BaseCodeGenerator::BaseCodeGenerator(BaseCodeGenerator&& other) noexcept
	: variableTable(other.variableTable),
	  functionTable(other.functionTable)
{
}

BaseCodeGenerator& BaseCodeGenerator::operator=(const BaseCodeGenerator& other)
{
	if (this == &other)
		return *this;
	variableTable = other.variableTable;
	functionTable = other.functionTable;
	return *this;
}

BaseCodeGenerator& BaseCodeGenerator::operator=(BaseCodeGenerator&& other) noexcept
{
	if (this == &other)
		return *this;
	variableTable = other.variableTable;
	functionTable = other.functionTable;
	return *this;
}
