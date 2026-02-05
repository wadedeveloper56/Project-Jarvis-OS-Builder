#include "pch.h"
#include "BaseCodeGenerator.h"

using namespace WadeSpace;

BaseCodeGenerator::BaseCodeGenerator() :variableTable(nullptr), functionTable(nullptr) {

}

BaseCodeGenerator::BaseCodeGenerator(vector<VariableData*>* variableTable, vector<FunctionData*>* functionTable)
    : variableTable(variableTable), functionTable(functionTable)
{
}

BaseCodeGenerator::~BaseCodeGenerator() {

}
