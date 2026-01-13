#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "ProgramData.h"
#include "BaseCodeGenerator.h"

using namespace std;

namespace WadeSpace
{
	class NasmCodeGenerator : public BaseCodeGenerator
	{
	public:
		NasmCodeGenerator();
		NasmCodeGenerator(vector<VariableData*>* variableTable, vector<FunctionData*>* functionTable, vector<FunctionData*>* functionPrototypeTable);
		~NasmCodeGenerator();
		virtual void generateCode(ofstream& out);
	};
}

