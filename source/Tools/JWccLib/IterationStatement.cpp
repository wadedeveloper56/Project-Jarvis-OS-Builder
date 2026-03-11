#include "pch.h"
#include "IterationStatement.h"
#include "Expression.h"

using namespace WadeSpace;
using namespace std;

IterationStatement::IterationStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, ExpressionTree* exp, BaseStatement* statement) 
	: BaseStatement(op, es1, es2, exp, statement)
{
}

IterationStatement::IterationStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, BaseStatement* statement) 
	: BaseStatement(op, es1, es2, statement)
{
}

IterationStatement::IterationStatement(TokenType op, ExpressionTree* identifier, BaseStatement* statement)
	: BaseStatement(op, identifier, statement)
{
}

IterationStatement::IterationStatement() : BaseStatement()
{
}

IterationStatement::~IterationStatement()
{
}

IterationStatement::IterationStatement(const IterationStatement& other)
	: BaseStatement(other)
{
}

IterationStatement::IterationStatement(IterationStatement&& other) noexcept
	: BaseStatement(std::move(other))
{
}

IterationStatement& IterationStatement::operator=(const IterationStatement& other)
{
	if (this == &other)
		return *this;
	BaseStatement::operator =(other);
	return *this;
}

IterationStatement& IterationStatement::operator=(IterationStatement&& other) noexcept
{
	if (this == &other)
		return *this;
	BaseStatement::operator =(std::move(other));
	return *this;
}
