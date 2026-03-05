#pragma once

#include "TokenType.h"
#include "BaseStatement.h"

using namespace std;

namespace WadeSpace
{
	class Expression;

	class JumpStatement : public BaseStatement
	{
	public:
		JumpStatement();       
		JumpStatement(TokenType op);
		JumpStatement(TokenType op, TokenPtr identifier);
		JumpStatement(TokenType op, Expression* identifier);
		virtual ~JumpStatement();

		JumpStatement(const JumpStatement& other);
		JumpStatement(JumpStatement&& other) noexcept;
		JumpStatement& operator=(const JumpStatement& other);
		JumpStatement& operator=(JumpStatement&& other) noexcept;
	};
}
