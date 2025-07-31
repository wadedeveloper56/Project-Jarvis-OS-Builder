#include "InclusiveOrExpression.h"

using namespace WadeSpace;
using namespace std;

InclusiveOrExpression::InclusiveOrExpression(ExclusiveOrExpression* exclusiveOrExpression) : exclusiveOrExpression(nullptr), inclusiveOrExpression(nullptr)
{
}

InclusiveOrExpression::InclusiveOrExpression(InclusiveOrExpression* inclusiveOrExpression, ExclusiveOrExpression* exclusiveOrExpression) : exclusiveOrExpression(nullptr), inclusiveOrExpression(nullptr)
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
