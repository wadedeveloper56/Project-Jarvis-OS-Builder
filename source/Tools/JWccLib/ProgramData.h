#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <stdint.h>
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
		int getSize(TokenType type);
		void test();

	private:
		void handleDeclaration(Declaration* declaration, vector<struct _VariableData*>* variableTable);
		void handleFunction(FunctionDefinition* declaration, vector<struct _FunctionData*>* functionTable);
		vector<ExternalDeclaration*> *programData;
		BaseCodeGenerator* generator;
	};
}
