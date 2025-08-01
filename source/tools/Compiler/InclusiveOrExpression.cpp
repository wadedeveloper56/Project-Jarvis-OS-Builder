#include "InclusiveOrExpression.h"

using namespace WadeSpace;
using namespace std;

InclusiveOrExpression::InclusiveOrExpression(ExclusiveOrExpression* exclusiveOrExpression) : exclusiveOrExpression(exclusiveOrExpression), inclusiveOrExpression(nullptr)
{
}

InclusiveOrExpression::InclusiveOrExpression(InclusiveOrExpression* inclusiveOrExpression, ExclusiveOrExpression* exclusiveOrExpression) : exclusiveOrExpression(exclusiveOrExpression), inclusiveOrExpression(inclusiveOrExpression)
{
}

InclusiveOrExpression::InclusiveOrExpression() : exclusiveOrExpression(nullptr), inclusiveOrExpression(nullptr)
{
}

InclusiveOrExpression::~InclusiveOrExpression()
{
	delete exclusiveOrExpression;
	delete inclusiveOrExpression;
}

InclusiveOrExpression* InclusiveOrExpression::getInclusiveOrExpression() const
{
	return inclusiveOrExpression;
}

ExclusiveOrExpression* InclusiveOrExpression::getExclusiveOrExpression() const
{
	return exclusiveOrExpression;
}
