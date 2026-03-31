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
		virtual ~MasmCodeGenerator() = default;

		virtual void generateCode(ostream& out);

		MasmCodeGenerator(const MasmCodeGenerator& other);
		MasmCodeGenerator(MasmCodeGenerator&& other) noexcept;
		MasmCodeGenerator& operator=(const MasmCodeGenerator& other);
		MasmCodeGenerator& operator=(MasmCodeGenerator&& other) noexcept;

	private:
		void handleIndividualFunction(ostream& out, FunctionData* ptr);
		void handleInitializedVariable(ostream& out, VariableData* ptr);
		void handleUUninitializedVariable(ostream& out, VariableData* ptr);
		void handleVariableTable(ostream& out);
		void handleFunctionTable(ostream& out);
		//void handleStructs(ostream& out);
		void outputVariable(ostream& out, VariableData* ptr);
		void handleFunctionWithParameters(ostream& out, string name, vector<VariableData*>* list);
		void handleIndividualFunctionStatements(ostream& out, TokenType returnType, BaseStatement const * statements);
		string vectorToCommaSeparatedList(const vector<string>& vec);
		string getAsmType(TokenType type, bool isPointer, bool isUnsigned);
		void handlePrototype(ostream& out);
		string convertToAsmType(bool isUnsigned, bool isPointer, TokenType type);
		void handleFunctionTablePrototypes(ostream& out);
	};
}

