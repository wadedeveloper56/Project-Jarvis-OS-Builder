#include "PrimaryExpression.h"
#include "Expression.h"

using namespace WadeSpace;
using namespace std;

PrimaryExpression::PrimaryExpression(const string& identifier) : identifier(identifier), constant(nullptr), expression(nullptr)
{
}

PrimaryExpression::PrimaryExpression(Constant* constant) : identifier(nullopt), constant(constant), expression(nullptr)
{
}

PrimaryExpression::PrimaryExpression(Expression* expression) : identifier(nullopt), constant(nullptr), expression(expression)
{
}

PrimaryExpression::PrimaryExpression() : identifier(nullopt), constant(nullptr), expression(nullptr)
{
}

PrimaryExpression::~PrimaryExpression()
{
	delete constant;
	delete expression;
}

optional<string> PrimaryExpression::getIdentifier() const
{
	return identifier;
}

Constant* PrimaryExpression::getConstant() const
{
	return constant;
}

Expression* PrimaryExpression::getExpression() const
{
	return expression;
}
