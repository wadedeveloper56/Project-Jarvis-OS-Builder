#pragma once

#include "TokenType.h"
#include "BaseStatement.h"

using namespace std;

namespace WadeSpace
{
	class LabeledStatement : public BaseStatement
	{
	public:
		LabeledStatement() = default;
		LabeledStatement(CTokenPtr identifier, BaseStatement* statement);
		LabeledStatement(TokenType op, ExpressionTree* exp, BaseStatement* statement);
		LabeledStatement(TokenType op, BaseStatement* statement);
		virtual ~LabeledStatement() = default;
		LabeledStatement(const LabeledStatement& other) = default;
		LabeledStatement(LabeledStatement&& other) noexcept = default;
		LabeledStatement& operator=(const LabeledStatement& other) = default;
		LabeledStatement& operator=(LabeledStatement&& other) noexcept = default;
	};
}
