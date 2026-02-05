#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
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
	};
}
