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
		explicit CompoundStatement(vector<BaseStatement*>* const list);
		explicit CompoundStatement(vector<Declaration*>* list);
		explicit CompoundStatement(vector<BaseStatement*>* sList, vector<Declaration*>* dList);
		~CompoundStatement() override = default;
		CompoundStatement(const CompoundStatement& other);
		CompoundStatement(CompoundStatement&& other) noexcept;
		CompoundStatement& operator=(const CompoundStatement& other);
		CompoundStatement& operator=(CompoundStatement&& other) noexcept;
	};
}
