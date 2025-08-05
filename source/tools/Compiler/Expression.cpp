#include "Expression.h"

using namespace WadeSpace;
using namespace std;

Expression::Expression(AssignmentExpression* assignmentExpression) : assignmentExpression(assignmentExpression), oper(nullopt), expression(nullptr)
{
}

Expression::Expression(Expression* expression, const int& oper, AssignmentExpression* assignmentExpression) : assignmentExpression(assignmentExpression), oper(oper), expression(expression)
{
}

Expression::Expression() : assignmentExpression(nullptr), oper(nullopt), expression(nullptr)
{
}

Expression::~Expression()
{
	delete assignmentExpression;
	delete expression;
}

Expression* Expression::getExpression() const
{
	return expression;
}

optional<int> Expression::getOper() const
{
	return oper;
}

AssignmentExpression* Expression::getAssignmentExpression() const
{
	return assignmentExpression;
}
