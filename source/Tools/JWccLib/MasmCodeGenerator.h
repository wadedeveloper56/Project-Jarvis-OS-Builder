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
		MasmCodeGenerator(const MasmCodeGenerator& other);
		MasmCodeGenerator(MasmCodeGenerator&& other) noexcept;
		MasmCodeGenerator& operator=(const MasmCodeGenerator& other);
		MasmCodeGenerator& operator=(MasmCodeGenerator&& other) noexcept;
	private:
		void handleIndividualFunction(ofstream& out, FunctionData* ptr);
		void handleInitializedVarible(ofstream& out, vector<_VariableData*>::value_type ptr);
		void handleUUninitializedVariable(ofstream& out, vector<_VariableData*>::value_type ptr);
		void handleVaribleTable(ofstream& out);
		void handleFunctionTable(ofstream& out);
	};
}

