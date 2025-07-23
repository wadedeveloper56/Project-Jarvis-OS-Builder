#include "LogicalOrExpression.h"

using namespace WadeSpace;
using namespace std;

LogicalOrExpression::LogicalOrExpression(LogicalAndExpression* lae) : loe(nullptr), lae(lae)
{
}

LogicalOrExpression::LogicalOrExpression(LogicalOrExpression* loe, LogicalAndExpression* lae) : loe(loe), lae(lae)
{
}

LogicalOrExpression::LogicalOrExpression(): loe(nullptr), lae(nullptr)
{
}

LogicalOrExpression::~LogicalOrExpression()
{
	delete loe;
	delete lae;
}
