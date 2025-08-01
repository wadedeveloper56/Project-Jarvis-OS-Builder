#include "LogicalAndExpression.h"

using namespace WadeSpace;

LogicalAndExpression::LogicalAndExpression(InclusiveOrExpression* inclusiveOrExpression) : inclusiveOrExpression(inclusiveOrExpression), logicalAndExpression(nullptr)
{
}

LogicalAndExpression::LogicalAndExpression(LogicalAndExpression* logicalAndExpression, InclusiveOrExpression* inclusiveOrExpression) : inclusiveOrExpression(inclusiveOrExpression), logicalAndExpression(logicalAndExpression)
{
}

LogicalAndExpression::LogicalAndExpression() : inclusiveOrExpression(nullptr), logicalAndExpression(nullptr)
{
}

LogicalAndExpression::~LogicalAndExpression()
{
	delete inclusiveOrExpression;
	delete logicalAndExpression;
}

InclusiveOrExpression* LogicalAndExpression::getInclusiveOrExpression() const
{
	return inclusiveOrExpression;
}

LogicalAndExpression* LogicalAndExpression::getLogicalAndExpression() const
{
	return logicalAndExpression;
}
