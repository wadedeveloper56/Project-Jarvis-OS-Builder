#include "pch.h"
#include "Statement.h"

using namespace WadeSpace;
using namespace std;

Statement::Statement(TokenType op, BaseStatement* statement) : BaseStatement(op, statement)
{
}

Statement::Statement() : BaseStatement()
{
}

Statement::~Statement()
{
}

Statement::Statement(const Statement& other): BaseStatement(other)
{
}

Statement::Statement(Statement&& other) noexcept: BaseStatement(std::move(other))
{
}

Statement& Statement::operator=(const Statement& other)
{
	if (this == &other)
		return *this;
	BaseStatement::operator =(other);
	return *this;
}

Statement& Statement::operator=(Statement&& other) noexcept
{
	if (this == &other)
		return *this;
	BaseStatement::operator =(std::move(other));
	return *this;
}
