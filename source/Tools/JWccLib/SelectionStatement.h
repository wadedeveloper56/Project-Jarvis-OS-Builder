#pragma once

#include <string>
#include <vector>
#include "TokenType.h"
#include "BaseStatement.h"

using namespace std;

namespace WadeSpace
{
	class SelectionStatement : public BaseStatement
	{
	public:
		SelectionStatement(TokenType op, Expression* exp, BaseStatement* statement);
		SelectionStatement(TokenType op, Expression* exp, BaseStatement* ifStatement, BaseStatement* elseStatement);
		SelectionStatement();
		virtual ~SelectionStatement();

		SelectionStatement(const SelectionStatement& other)
			: BaseStatement(other)
		{
		}

		SelectionStatement(SelectionStatement&& other) noexcept
			: BaseStatement(std::move(other))
		{
		}

		SelectionStatement& operator=(const SelectionStatement& other)
		{
			if (this == &other)
				return *this;
			BaseStatement::operator =(other);
			return *this;
		}

		SelectionStatement& operator=(SelectionStatement&& other) noexcept
		{
			if (this == &other)
				return *this;
			BaseStatement::operator =(std::move(other));
			return *this;
		}
	};
}
