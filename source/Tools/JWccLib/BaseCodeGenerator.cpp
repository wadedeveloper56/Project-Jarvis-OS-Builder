#include "pch.h"
#include "BaseCodeGenerator.h"

using namespace WadeSpace;

BaseCodeGenerator::BaseCodeGenerator(vector<VariableData*>* const variable_table, vector<FunctionData*>* const function_table) : variableTable(variable_table),	functionTable(function_table)
{
}
