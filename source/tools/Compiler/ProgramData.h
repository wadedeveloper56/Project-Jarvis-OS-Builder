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
		int size;
	} VariableData;

	typedef struct
	{
		string name;
		TokenType type;
		int size;
		vector<VariableData*>* parameters;
	} FunctionData;

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
		vector<ExternalDeclaration*> *programData;
		vector<VariableData*> *variableTable;
		vector<FunctionData*>* functionTable;
	};
}
