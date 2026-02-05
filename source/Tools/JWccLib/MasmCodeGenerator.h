#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <optional>
#include "ProgramData.h"
#include "BaseCodeGenerator.h"

using namespace std;

namespace WadeSpace
{
	class MasmCodeGenerator : public BaseCodeGenerator
	{
	public:
		MasmCodeGenerator();
		MasmCodeGenerator(vector<VariableData*>* variableTable, vector<FunctionData*>* functionTable);
		~MasmCodeGenerator();
		virtual void generateCode(ofstream& out);
	};
}

