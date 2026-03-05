#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <optional>
#include "TokenType.h"
#include "ExternalDeclaration.h"
#include "BaseCodeGenerator.h"

using namespace std;

namespace WadeSpace
{
	class BaseCodeGenerator;

	class ProgramData
	{
	public:
		ProgramData();
		virtual ~ProgramData();
		void add(ExternalDeclaration* data);
		BaseCodeGenerator* processGlobalVariables();

	private:
		void handleDeclaration(Declaration* declaration, vector<struct _VariableData*>* variableTable);
		void handleFunction(FunctionDefinition* declaration, vector<struct _FunctionData*>* functionTable);
		void handleInitDeclaratorForDeclaratation(Declaration* declaration, vector<VariableData*>* variableTable, TokenType type);

	public:
		[[nodiscard]] vector<ExternalDeclaration*>* getProgram() const;
		[[nodiscard]] BaseCodeGenerator* getGenerator() const;

		[[nodiscard]] bool hasProgram() const;
		[[nodiscard]] bool hasGenerator() const;

	private:
		vector<ExternalDeclaration*> *program;
		BaseCodeGenerator* generator;
	};
}
