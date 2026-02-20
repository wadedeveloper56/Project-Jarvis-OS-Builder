#include "pch.h"
#include "ExpressionStatement.h"
#include "Expression.h"

using namespace WadeSpace;
using namespace std;

ExpressionStatement::ExpressionStatement(Expression* exp) : BaseStatement(NONE, exp)
{
}

ExpressionStatement::ExpressionStatement():BaseStatement(NONE, (Expression*)nullptr)
{
}

ExpressionStatement::ExpressionStatement(const ExpressionStatement& other)
	: BaseStatement(other)
{
}

ExpressionStatement::ExpressionStatement(ExpressionStatement&& other) noexcept
	: BaseStatement(std::move(other))
{
}

ExpressionStatement& ExpressionStatement::operator=(const ExpressionStatement& other)
{
	if (this == &other)
		return *this;
	BaseStatement::operator =(other);
	return *this;
}

ExpressionStatement& ExpressionStatement::operator=(ExpressionStatement&& other) noexcept
{
	if (this == &other)
		return *this;
	BaseStatement::operator =(std::move(other));
	return *this;
}

