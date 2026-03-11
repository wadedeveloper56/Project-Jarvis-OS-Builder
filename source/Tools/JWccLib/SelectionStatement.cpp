#include "pch.h"
#include "SelectionStatement.h"

using namespace WadeSpace;
using namespace std;

SelectionStatement::SelectionStatement(TokenType op, ExpressionTree* exp, BaseStatement* ifStatement, BaseStatement* elseStatement) 
	: BaseStatement(op, exp, ifStatement, elseStatement)
{
}

SelectionStatement::SelectionStatement(TokenType op, ExpressionTree* exp, BaseStatement* statement) : BaseStatement(op, exp, statement)
{
}

SelectionStatement::SelectionStatement() : BaseStatement()
{
}

SelectionStatement::~SelectionStatement()
{
}

SelectionStatement::SelectionStatement(const SelectionStatement& other): BaseStatement(other)
{
}

SelectionStatement::SelectionStatement(SelectionStatement&& other) noexcept: BaseStatement(std::move(other))
{
}

SelectionStatement& SelectionStatement::operator=(const SelectionStatement& other)
{
	if (this == &other)
		return *this;
	BaseStatement::operator =(other);
	return *this;
}

SelectionStatement& SelectionStatement::operator=(SelectionStatement&& other) noexcept
{
	if (this == &other)
		return *this;
	BaseStatement::operator =(std::move(other));
	return *this;
}

