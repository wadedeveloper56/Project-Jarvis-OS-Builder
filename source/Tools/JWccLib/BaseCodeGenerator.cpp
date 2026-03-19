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
	variableTable->clear();
	functionTable->clear();
}

vector<VariableData*>* BaseCodeGenerator::getVariableTable() const
{
	return variableTable;
}

vector<FunctionData*>* BaseCodeGenerator::getFunctionTable() const
{
	return functionTable;
}

BaseCodeGenerator::BaseCodeGenerator(const BaseCodeGenerator& other)
{
	variableTable = other.variableTable;
	functionTable = other.functionTable;
}

BaseCodeGenerator::BaseCodeGenerator(BaseCodeGenerator&& other) noexcept
{
	variableTable = std::move(other.variableTable);
	functionTable = std::move(other.functionTable);
	functionTable = other.functionTable;
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
	variableTable = std::move(other.variableTable);
	functionTable = std::move(other.functionTable);
	return *this;
}

