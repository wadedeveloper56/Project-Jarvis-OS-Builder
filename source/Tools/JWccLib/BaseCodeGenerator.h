#pragma once

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
		_VariableData() = default;
		~_VariableData() = default;
	} VariableData;

	typedef struct _FunctionData
	{
		string name;
		TokenType type;
		int size;
		vector<VariableData*>* parameters;
		_FunctionData() = default;
		~_FunctionData() = default;
	} FunctionData;

	class BaseCodeGenerator
	{
	public:
		BaseCodeGenerator();
		BaseCodeGenerator(vector<VariableData*>* const variable_table, vector<FunctionData*>* const function_table);
		BaseCodeGenerator(const BaseCodeGenerator& other) = default;
		BaseCodeGenerator(BaseCodeGenerator&& other) noexcept = default;
		virtual ~BaseCodeGenerator();

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
