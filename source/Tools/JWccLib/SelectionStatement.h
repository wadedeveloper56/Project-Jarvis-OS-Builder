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
		SelectionStatement();
		SelectionStatement(TokenType op, Expression* exp, BaseStatement* statement);
		SelectionStatement(TokenType op, Expression* exp, BaseStatement* ifStatement, BaseStatement* elseStatement);
		virtual ~SelectionStatement();

		SelectionStatement(const SelectionStatement& other);
		SelectionStatement(SelectionStatement&& other) noexcept;
		SelectionStatement& operator=(const SelectionStatement& other);
		SelectionStatement& operator=(SelectionStatement&& other) noexcept;
	};
}
