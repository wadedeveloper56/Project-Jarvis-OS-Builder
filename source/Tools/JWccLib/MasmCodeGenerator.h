#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <optional>
#include "ProgramData.h"
#include "BaseCodeGenerator.h"

using namespace std;

namespace WadeSpace
{
	class MasmCodeGenerator : public BaseCodeGenerator
	{
	public:
		MasmCodeGenerator();
		MasmCodeGenerator(vector<VariableData*>* variableTable, vector<FunctionData*>* functionTable);
		~MasmCodeGenerator();
		virtual void generateCode(ofstream& out);

		MasmCodeGenerator(const MasmCodeGenerator& other)
			: BaseCodeGenerator(other)
		{
		}

		MasmCodeGenerator(MasmCodeGenerator&& other) noexcept
			: BaseCodeGenerator(std::move(other))
		{
		}

		MasmCodeGenerator& operator=(const MasmCodeGenerator& other)
		{
			if (this == &other)
				return *this;
			BaseCodeGenerator::operator =(other);
			return *this;
		}

		MasmCodeGenerator& operator=(MasmCodeGenerator&& other) noexcept
		{
			if (this == &other)
				return *this;
			BaseCodeGenerator::operator =(std::move(other));
			return *this;
		}
	};
}

