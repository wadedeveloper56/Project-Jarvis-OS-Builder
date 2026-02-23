#pragma once

#include <string>
#include <vector>
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
		JumpStatement(TokenType op, TokenPtr identifier);
		JumpStatement(TokenType op, Expression* identifier);
		JumpStatement();
		virtual ~JumpStatement();

		JumpStatement(const JumpStatement& other): BaseStatement(other)
		{
		}

		JumpStatement(JumpStatement&& other) noexcept : BaseStatement(std::move(other))
		{
		}

		JumpStatement& operator=(const JumpStatement& other)
		{
			if (this == &other)
				return *this;
			BaseStatement::operator =(other);
			return *this;
		}

		JumpStatement& operator=(JumpStatement&& other) noexcept
		{
			if (this == &other)
				return *this;
			BaseStatement::operator =(std::move(other));
			return *this;
		}
	};
}
