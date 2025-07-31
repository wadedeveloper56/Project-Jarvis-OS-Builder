#include "ConstantExpression.h"

using namespace WadeSpace;

ConstantExpression::ConstantExpression(ConditionalExpression* conditionalExpression): conditionalExpression(conditionalExpression)
{
}

ConstantExpression::ConstantExpression(): conditionalExpression(nullptr)
{
}

ConstantExpression::~ConstantExpression()
{
	delete conditionalExpression;
}
