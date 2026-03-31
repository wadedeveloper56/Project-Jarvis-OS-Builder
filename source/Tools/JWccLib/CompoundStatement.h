#pragma once

#include <string>
#include <vector>
#include <optional>
#include "TokenType.h"
#include "BaseStatement.h"

using namespace std;

namespace WadeSpace
{
	class CompoundStatement : public BaseStatement
	{
	public:
		CompoundStatement() = default;
		CompoundStatement(vector<BaseStatement*>* const list);
		CompoundStatement(vector<Declaration*>* list);
		CompoundStatement(vector<BaseStatement*>* sList, vector<Declaration*>* dList);
		~CompoundStatement() override = default;

		CompoundStatement(const CompoundStatement& other) = default;
		CompoundStatement(CompoundStatement&& other) noexcept = default;
		CompoundStatement& operator=(const CompoundStatement& other) = default;
		CompoundStatement& operator=(CompoundStatement&& other) noexcept = default;
	};
}
