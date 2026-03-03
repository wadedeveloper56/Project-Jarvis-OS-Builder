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
		MasmCodeGenerator() = default;
		MasmCodeGenerator(vector<VariableData*>* variableTable, vector<FunctionData*>* functionTable);
		~MasmCodeGenerator();
		virtual void generateCode(ofstream& out);
		MasmCodeGenerator(const MasmCodeGenerator& other);
		MasmCodeGenerator(MasmCodeGenerator&& other) noexcept;
		MasmCodeGenerator& operator=(const MasmCodeGenerator& other);
		MasmCodeGenerator& operator=(MasmCodeGenerator&& other) noexcept;
	private:
		void handleIndividualFunction(ofstream& out, FunctionData* ptr);
		void handleInitializedVariable(ofstream& out, vector<_VariableData*>::value_type ptr);
		void handleUUninitializedVariable(ofstream& out, vector<_VariableData*>::value_type ptr);
		void handleVariableTable(ofstream& out);
		void handleFunctionTable(ofstream& out);
		void handleStructs(ofstream& out);
		void outputVariable(ofstream& out, _VariableData* ptr);
		void handleFunctionWithParameters(ofstream& out, string name, vector<VariableData*>* list);
		string vectorToCommaSeparatedList(const vector<string>& vec);
	};
}

