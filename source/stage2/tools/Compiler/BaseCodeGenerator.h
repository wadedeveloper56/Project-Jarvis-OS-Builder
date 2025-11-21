#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "GlobalVars.h"

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

	class BaseCodeGenerator
	{
	public:
		BaseCodeGenerator();
		BaseCodeGenerator(vector<VariableData*>* variableTable, vector<FunctionData*>* functionTable, vector<FunctionData*>* functionPrototypeTable);
		~BaseCodeGenerator();
		virtual void generateCode(ofstream& out) = 0;
	protected:
		vector<VariableData*>* variableTable;
		vector<FunctionData*>* functionTable;
		vector<FunctionData*>* functionPrototypeTable;
	};
}
