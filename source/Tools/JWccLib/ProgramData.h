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
		int getSize(TokenType type, bool isPointer);

	private:
		void handleDeclaration(Declaration* declaration, vector<struct _VariableData*>* variableTable);
		void handleFunction(FunctionDefinition* declaration, vector<struct _FunctionData*>* functionTable);
		void handleInitDeclaratorForDeclaratation(Declaration* declaration, vector<VariableData*>* variableTable, TokenType type);

		vector<ExternalDeclaration*> *program;
		BaseCodeGenerator* generator;
	};
}
