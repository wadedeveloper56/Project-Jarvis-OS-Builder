#include "LogicalAndExpression.h"

using namespace WadeSpace;

LogicalAndExpression::LogicalAndExpression(InclusiveOrExpression* ioe) : ioe(ioe), lae(nullptr)
{
}

LogicalAndExpression::LogicalAndExpression(LogicalAndExpression* lae, InclusiveOrExpression* ioe) : ioe(ioe), lae(lae)
{
}

LogicalAndExpression::LogicalAndExpression() : ioe(nullptr), lae(nullptr)
{
}

LogicalAndExpression::~LogicalAndExpression()
{
}
