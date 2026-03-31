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
		SelectionStatement() = default;
		SelectionStatement(TokenType op, ExpressionTree* exp, BaseStatement* statement);
		SelectionStatement(TokenType op, ExpressionTree* exp, BaseStatement* ifStatement, BaseStatement* elseStatement);
		virtual ~SelectionStatement() = default;
		SelectionStatement(const SelectionStatement& other) = default;
		SelectionStatement(SelectionStatement&& other) noexcept = default;
		SelectionStatement& operator=(const SelectionStatement& other) = default;
		SelectionStatement& operator=(SelectionStatement&& other) noexcept = default;
	};
}
