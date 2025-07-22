#include "ConstantExpression.h"

using namespace WadeSpace;

ConstantExpression::ConstantExpression(ConditionalExpression* ce): ce(ce)
{
}

ConstantExpression::ConstantExpression(): ce(nullptr)
{
}

ConstantExpression::~ConstantExpression()
{
	if (ce) delete ce;
}
