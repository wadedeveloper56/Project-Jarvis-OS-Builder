#include "Expression.h"

using namespace WadeSpace;
using namespace std;

Expression::Expression(AssignmentExpression* assignmentExpression) : assignmentExpression(assignmentExpression), oper(nullopt), expression(nullptr)
{
}

Expression::Expression(Expression* expression, const string& oper, AssignmentExpression* assignmentExpression) : assignmentExpression(assignmentExpression), oper(oper), expression(expression)
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
