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
		CompoundStatement(const CompoundStatement& other) = default;
		CompoundStatement(CompoundStatement&& other) noexcept = default;
		CompoundStatement& operator=(const CompoundStatement& other)
		{
			if (this == &other)
				return *this;
			BaseStatement::operator =(other);
			return *this;
		}

		CompoundStatement& operator=(CompoundStatement&& other) noexcept
		{
			if (this == &other)
				return *this;
			BaseStatement::operator =(std::move(other));
			return *this;
		}
	};
}
