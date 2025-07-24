#include "ExclusiveOrExpression.h"

using namespace WadeSpace;
using namespace std;

ExclusiveOrExpression::ExclusiveOrExpression(AndExpression* andExpression) : andExpression(andExpression), exclusiveOrExpression(nullptr)
{
}

ExclusiveOrExpression::ExclusiveOrExpression(ExclusiveOrExpression* exclusiveOrExpression, AndExpression* andExpression) : andExpression(andExpression), exclusiveOrExpression(exclusiveOrExpression)
{
}

ExclusiveOrExpression::ExclusiveOrExpression() : andExpression(nullptr), exclusiveOrExpression(nullptr)
{
}

ExclusiveOrExpression::~ExclusiveOrExpression()
{
	delete andExpression;
	delete exclusiveOrExpression;
}

AndExpression* ExclusiveOrExpression::getAndExpression() const
{
	return andExpression;
}

ExclusiveOrExpression* ExclusiveOrExpression::getExclusiveOrExpression() const
{
	return exclusiveOrExpression;
}
