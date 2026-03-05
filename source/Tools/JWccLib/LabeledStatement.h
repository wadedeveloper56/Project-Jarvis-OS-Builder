#pragma once

#include "TokenType.h"
#include "BaseStatement.h"

using namespace std;

namespace WadeSpace
{
	class LabeledStatement : public BaseStatement
	{
	public:
		LabeledStatement();
		LabeledStatement(TokenPtr identifier, BaseStatement* statement);
		LabeledStatement(TokenType op, Expression* exp, BaseStatement* statement);
		LabeledStatement(TokenType op, BaseStatement* statement);
		virtual ~LabeledStatement();

		LabeledStatement(const LabeledStatement& other);
		LabeledStatement(LabeledStatement&& other) noexcept;
		LabeledStatement& operator=(const LabeledStatement& other);
		LabeledStatement& operator=(LabeledStatement&& other) noexcept;
	};
}
