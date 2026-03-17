#pragma once

#include "BaseStatement.h"
#include "GlobalVars.h"
#include "Initializer.h"
#include "TokenType.h"
#include "StructOrUnionSpecifier.h"
#include "ParameterTypeList.h"

using namespace std;

namespace WadeSpace
{
	typedef struct _VariableData
	{
		string name;
		TokenType type;
		bool pointer;
		unsigned long long arraySize;
		Initializer* initializer;
		string structName;
		StructOrUnionSpecifier* suSpec;
		bool unsign;
		ParameterTypeList* plist;

		_VariableData() = default;
		~_VariableData() = default;

		_VariableData(const _VariableData& other)
		{
			name = other.name;
			pointer = other.pointer;
			arraySize = other.arraySize;
			type = other.type;
			initializer = other.initializer ? new Initializer(*other.initializer) : nullptr;
			structName = other.structName;
			suSpec = other.suSpec ? new StructOrUnionSpecifier(*other.suSpec) : nullptr;
			unsign = other.unsign;
			plist = other.plist ? new ParameterTypeList(*other.plist) : nullptr;
		}

		_VariableData(_VariableData&& other) noexcept
		{
			name = other.name;
			pointer = other.pointer;
			arraySize = other.arraySize;
			type = other.type;
			initializer = other.initializer ? new Initializer(*other.initializer) : nullptr;
			structName = other.structName;
			suSpec = other.suSpec ? new StructOrUnionSpecifier(*other.suSpec) : nullptr;
			unsign = other.unsign;
			plist = other.plist ? new ParameterTypeList(*other.plist) : nullptr;
		}

		_VariableData& operator=(const _VariableData& other)
		{
			if (this == &other)
				return *this;
			name = other.name;
			pointer = other.pointer;
			arraySize = other.arraySize;
			type = other.type;
			initializer = other.initializer ? new Initializer(*other.initializer) : nullptr;
			structName = other.structName;
			suSpec = other.suSpec ? new StructOrUnionSpecifier(*other.suSpec) : nullptr;
			unsign = other.unsign;
			plist = other.plist ? new ParameterTypeList(*other.plist) : nullptr;
			return *this;
		}

		_VariableData& operator=(_VariableData&& other) noexcept
		{
			if (this == &other)
				return *this;
			name = std::move(other.name);
			pointer = other.pointer;
			arraySize = other.arraySize;
			type = other.type;
			initializer = other.initializer ? new Initializer(*other.initializer) : nullptr;
			structName = other.structName;
			suSpec = other.suSpec ? new StructOrUnionSpecifier(*other.suSpec) : nullptr;	
			unsign = other.unsign;
			plist = other.plist ? new ParameterTypeList(*other.plist) : nullptr;
			return *this;
		}
	} VariableData;

	typedef struct _FunctionData
	{
		string name;
		TokenType type;
		vector<VariableData*>* parameters;
		BaseStatement* statements;

		_FunctionData() = default;
		~_FunctionData() = default;

		_FunctionData(const _FunctionData& other)
		{
			name = other.name;
			type = other.type;
			parameters = other.parameters ? new vector<VariableData*>(*other.parameters) : nullptr;
			statements = other.statements ? new BaseStatement(*other.statements) : nullptr;
		}

		_FunctionData(_FunctionData&& other) noexcept
		{
			name = other.name;
			type = other.type;
			parameters = other.parameters ? new vector<VariableData*>(*other.parameters) : nullptr;
			statements = other.statements ? new BaseStatement(*other.statements) : nullptr;
		}

		_FunctionData& operator=(const _FunctionData& other)
		{
			if (this == &other)
				return *this;
			name = other.name;
			type = other.type;
			parameters = other.parameters ? new vector<VariableData*>(*other.parameters) : nullptr;
			statements = other.statements ? new BaseStatement(*other.statements) : nullptr;
			return *this;
		}

		_FunctionData& operator=(_FunctionData&& other) noexcept
		{
			if (this == &other)
				return *this;
			name = std::move(other.name);
			type = other.type;		
			parameters = other.parameters ? new vector<VariableData*>(*other.parameters) : nullptr;
			statements = other.statements ? new BaseStatement(*other.statements) : nullptr;
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

		bool hasVariableTable() const;
		bool hasFunctionTable() const;
		virtual void generateCode(ostream& out) = 0;

	protected:
		vector<VariableData*>* variableTable;
		vector<FunctionData*>* functionTable;
	};
}
