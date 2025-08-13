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
	class Expression;

	class JumpStatement : public BaseStatement
	{
	public:
		JumpStatement(TokenType op);
		JumpStatement(TokenType op, string& identifier);
		JumpStatement(TokenType op, ExpressionNode* identifier);
		JumpStatement();
		virtual ~JumpStatement();
	};
}
