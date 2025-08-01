#include "LogicalOrExpression.h"

using namespace WadeSpace;
using namespace std;

LogicalOrExpression::LogicalOrExpression(LogicalAndExpression* logicalAndExpression) : logicalOrExpression(nullptr), logicalAndExpression(logicalAndExpression)
{
}

LogicalOrExpression::LogicalOrExpression(LogicalOrExpression* logicalOrExpression, LogicalAndExpression* logicalAndExpression) : logicalOrExpression(logicalOrExpression), logicalAndExpression(logicalAndExpression)
{
}

LogicalOrExpression::LogicalOrExpression(): logicalOrExpression(nullptr), logicalAndExpression(nullptr)
{
}

LogicalOrExpression::~LogicalOrExpression()
{
	delete logicalOrExpression;
	delete logicalAndExpression;
}

LogicalOrExpression* LogicalOrExpression::getLogicalOrExpression() const
{
	return logicalOrExpression;
}

LogicalAndExpression* LogicalOrExpression::getLogicalAndExpression() const
{
	return logicalAndExpression;
}
