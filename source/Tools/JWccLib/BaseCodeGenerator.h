#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <optional>
#include "GlobalVars.h"
#include "TokenType.h"

using namespace std;

namespace WadeSpace
{
	typedef struct _VariableData
	{
		string name;
		TokenType type;
		int size;
		bool pointer;
		unsigned long long arraySize;
	} VariableData;

	typedef struct _FunctionData
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
		BaseCodeGenerator(vector<VariableData*>* const variable_table, vector<FunctionData*>* const function_table);
		virtual ~BaseCodeGenerator();
		BaseCodeGenerator(const BaseCodeGenerator& other) = default;
		BaseCodeGenerator(BaseCodeGenerator&& other) noexcept = default;
		BaseCodeGenerator& operator=(const BaseCodeGenerator& other) = default;
		BaseCodeGenerator& operator=(BaseCodeGenerator&& other) noexcept = default;
		vector<VariableData*>* getVariableTable() const;
		vector<FunctionData*>* getFunctionTable() const;
		bool isVariableTable() const;
		bool isFunctionTable() const;
		virtual void generateCode(ofstream& out) = 0;

	protected:
		vector<VariableData*>* variableTable;
		vector<FunctionData*>* functionTable;
	};
}
