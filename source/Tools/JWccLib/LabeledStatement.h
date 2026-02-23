#pragma once

#include <string>
#include <vector>
#include <optional>
#include "TokenType.h"
#include "BaseStatement.h"

using namespace std;

namespace WadeSpace
{
	class LabeledStatement : public BaseStatement
	{
	public:
		LabeledStatement(TokenPtr identifier, BaseStatement* statement);
		LabeledStatement(TokenType op, Expression* exp, BaseStatement* statement);
		LabeledStatement(TokenType op, BaseStatement* statement);
		LabeledStatement();
		virtual ~LabeledStatement();

		LabeledStatement(const LabeledStatement& other): BaseStatement(other)
		{
		}

		LabeledStatement(LabeledStatement&& other) noexcept: BaseStatement(std::move(other))
		{
		}

		LabeledStatement& operator=(const LabeledStatement& other)
		{
			if (this == &other)
				return *this;
			BaseStatement::operator =(other);
			return *this;
		}

		LabeledStatement& operator=(LabeledStatement&& other) noexcept
		{
			if (this == &other)
				return *this;
			BaseStatement::operator =(std::move(other));
			return *this;
		}
	};
}
