#include "pch.h"
#include "LabeledStatement.h"

using namespace WadeSpace;
using namespace std;

LabeledStatement::LabeledStatement(TokenPtr identifier, BaseStatement* statement) : BaseStatement(identifier, statement)
{
}

LabeledStatement::LabeledStatement(TokenType op, ExpressionTree* exp, BaseStatement* statement) : BaseStatement(op, exp, statement)
{
}

LabeledStatement::LabeledStatement(TokenType op, BaseStatement* statement) : BaseStatement(op, statement)
{
}

LabeledStatement::LabeledStatement() : BaseStatement()
{
}

LabeledStatement::~LabeledStatement()
{
}

LabeledStatement::LabeledStatement(const LabeledStatement& other) : BaseStatement(other)
{
}

LabeledStatement::LabeledStatement(LabeledStatement&& other) noexcept : BaseStatement(std::move(other))
{
}

LabeledStatement& LabeledStatement::operator=(const LabeledStatement& other)
{
	if (this == &other)
		return *this;
	BaseStatement::operator =(other);
	return *this;
}

LabeledStatement& LabeledStatement::operator=(LabeledStatement&& other) noexcept
{
	if (this == &other)
		return *this;
	BaseStatement::operator =(std::move(other));
	return *this;
}

