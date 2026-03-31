#include "pch.h"
#include "JumpStatement.h"
#include "Expression.h"

using namespace WadeSpace;
using namespace std;

JumpStatement::JumpStatement(TokenType op, ExpressionTree* exp) : BaseStatement(op, exp)
{
}

JumpStatement::JumpStatement(TokenType op) : BaseStatement(op)
{
}

JumpStatement::JumpStatement(TokenType op, CTokenPtr identifier) : BaseStatement(op, identifier)
{
}

JumpStatement::JumpStatement() : BaseStatement()
{
}

JumpStatement::~JumpStatement()
{
}

JumpStatement::JumpStatement(const JumpStatement& other) : BaseStatement(other)
{
}

JumpStatement::JumpStatement(JumpStatement&& other) noexcept : BaseStatement(std::move(other))
{
}

JumpStatement& JumpStatement::operator=(const JumpStatement& other)
{
	if (this == &other)
		return *this;
	BaseStatement::operator =(other);
	return *this;
}

JumpStatement& JumpStatement::operator=(JumpStatement&& other) noexcept
{
	if (this == &other)
		return *this;
	BaseStatement::operator =(std::move(other));
	return *this;
}

