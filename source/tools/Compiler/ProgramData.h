#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "ExternalDeclaration.h"

using namespace std;

namespace WadeSpace
{
	typedef struct
	{
		string name;
		TokenType type;
	} VariableData;

	class ProgramData
	{
	public:
		ProgramData();
		virtual ~ProgramData();
		void add(ExternalDeclaration* data);
		void processGlobalVariables();
		void test();

	private:
		vector<ExternalDeclaration*>* programData;
		vector<VariableData*>* variableTable;
	};
}
