#include "BaseCodeGenerator.h"

using namespace WadeSpace;

BaseCodeGenerator::BaseCodeGenerator() :variableTable(nullptr), functionPrototypeTable(nullptr), functionTable(nullptr) {

}

BaseCodeGenerator::BaseCodeGenerator(vector<VariableData*>* variableTable, vector<FunctionData*>* functionTable, vector<FunctionData*>* functionPrototypeTable)
    : variableTable(variableTable), functionTable(functionTable), functionPrototypeTable(functionPrototypeTable)
{
}

BaseCodeGenerator::~BaseCodeGenerator() {

}
