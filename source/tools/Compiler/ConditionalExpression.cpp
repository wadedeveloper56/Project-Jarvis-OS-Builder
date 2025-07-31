#include "ConditionalExpression.h"
#include "Expression.h"

using namespace WadeSpace;
using namespace std;

ConditionalExpression::ConditionalExpression(LogicalOrExpression* logicalOrExpression) : logicalOrExpression(logicalOrExpression), expression(nullptr), conditionalExpression(nullptr)
{
}

ConditionalExpression::ConditionalExpression(LogicalOrExpression* logicalOrExpression, Expression* expression, ConditionalExpression* conditionalExpression) : logicalOrExpression(logicalOrExpression), expression(expression), conditionalExpression(conditionalExpression)
{
}

ConditionalExpression::ConditionalExpression() : logicalOrExpression(nullptr), expression(nullptr), conditionalExpression(nullptr)
{
}

ConditionalExpression::~ConditionalExpression()
{
	delete logicalOrExpression;
	delete expression;
	delete conditionalExpression;
}
