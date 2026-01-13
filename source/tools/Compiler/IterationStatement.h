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
	class IterationStatement : public BaseStatement
	{
	public:
		IterationStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, ExpressionNode* exp, BaseStatement* statement);
		IterationStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, BaseStatement* statement);
		IterationStatement(TokenType op, ExpressionNode* identifier, BaseStatement* statement);
		IterationStatement();
		virtual ~IterationStatement();
	};
}
