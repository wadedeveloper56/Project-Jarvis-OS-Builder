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
	class LabeledStatement : public BaseStatement
	{
	public:
		LabeledStatement(string&  identifier, BaseStatement* statement);
		LabeledStatement(TokenType op, ConstantExpression* exp, BaseStatement* statement);
		LabeledStatement(TokenType op, BaseStatement* statement);
		LabeledStatement();
		virtual ~LabeledStatement();
	};
}
