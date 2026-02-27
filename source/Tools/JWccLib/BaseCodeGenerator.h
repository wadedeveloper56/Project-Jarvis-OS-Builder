#pragma once

#include "GlobalVars.h"
#include "Initializer.h"
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
		Initializer* initializer;

		_VariableData() = default;
		~_VariableData() = default;

		_VariableData(const _VariableData& other)
		{
			name = other.name;
			size = other.size;
			pointer = other.pointer;
			arraySize = other.arraySize;
			type = other.type;
			initializer = other.initializer ? new Initializer(*other.initializer) : nullptr;
		}

		_VariableData(_VariableData&& other) noexcept
		{
			name = other.name;
			size = other.size;
			pointer = other.pointer;
			arraySize = other.arraySize;
			type = other.type;
			initializer = other.initializer ? new Initializer(*other.initializer) : nullptr;
		}

		_VariableData& operator=(const _VariableData& other)
		{
			if (this == &other)
				return *this;
			name = other.name;
			size = other.size;
			pointer = other.pointer;
			arraySize = other.arraySize;
			type = other.type;
			initializer = other.initializer ? new Initializer(*other.initializer) : nullptr;
			return *this;
		}

		_VariableData& operator=(_VariableData&& other) noexcept
		{
			if (this == &other)
				return *this;
			name = std::move(other.name);
			size = other.size;
			pointer = other.pointer;
			arraySize = other.arraySize;
			type = other.type;
			initializer = other.initializer ? new Initializer(*other.initializer) : nullptr;
			return *this;
		}
	} VariableData;

	typedef struct _FunctionData
	{
		string name;
		TokenType type;
		int size;
		vector<VariableData*>* parameters;
		_FunctionData() = default;
		~_FunctionData() = default;

		_FunctionData(const _FunctionData& other)
		{
			name = other.name;
			size = other.size;
			type = other.type;
			parameters = other.parameters ? new vector<VariableData*>(*other.parameters) : nullptr;
		}

		_FunctionData(_FunctionData&& other) noexcept
		{
			name = other.name;
			size = other.size;
			type = other.type;
			parameters = other.parameters ? new vector<VariableData*>(*other.parameters) : nullptr;
		}

		_FunctionData& operator=(const _FunctionData& other)
		{
			if (this == &other)
				return *this;
			name = other.name;
			size = other.size;
			type = other.type;
			parameters = other.parameters ? new vector<VariableData*>(*other.parameters) : nullptr;
			return *this;
		}

		_FunctionData& operator=(_FunctionData&& other) noexcept
		{
			if (this == &other)
				return *this;
			name = std::move(other.name);
			size = other.size;
			type = other.type;		
			parameters = other.parameters ? new vector<VariableData*>(*other.parameters) : nullptr;
			return *this;
		}
	} FunctionData;

	class BaseCodeGenerator
	{
	public:
		BaseCodeGenerator();
		BaseCodeGenerator(vector<VariableData*>* const variable_table, vector<FunctionData*>* const function_table);
		virtual ~BaseCodeGenerator();
		BaseCodeGenerator(const BaseCodeGenerator& other);
		BaseCodeGenerator(BaseCodeGenerator&& other) noexcept;
		BaseCodeGenerator& operator=(const BaseCodeGenerator& other);
		BaseCodeGenerator& operator=(BaseCodeGenerator&& other) noexcept;
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
