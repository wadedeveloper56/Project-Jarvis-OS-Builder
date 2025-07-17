#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "ExternalDeclaration.h"

using namespace std;

namespace WadeSpace {
	class ProgramData
	{
	public:
		ProgramData();
		~ProgramData();
		void add(ExternalDeclaration& data);
		void processGlobalVariables();
		void test();
	private:
		vector<ExternalDeclaration> programData;
		vector<FunctionDefinition> functionTable;
		vector<Declaration> variableTable;
	};
}
