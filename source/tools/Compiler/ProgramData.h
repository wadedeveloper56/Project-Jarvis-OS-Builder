#pragma once

#include <fstream>
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
		void generateCode(ofstream& out);
		void test();

	private:
		unique_ptr < vector<ExternalDeclaration*>> programData;
		unique_ptr < vector<VariableData*>> variableTable;
	};
}
