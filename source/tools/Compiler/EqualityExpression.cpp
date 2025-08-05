#include "EqualityExpression.h"

using namespace WadeSpace;
using namespace std;

EqualityExpression::EqualityExpression(RelationalExpression* relationalExpression) : relationalExpression(nullptr), op(nullopt), equalityExpression(nullptr)
{
}

EqualityExpression::EqualityExpression(EqualityExpression* equalityExpression, int& op, RelationalExpression* relationalExpression) : relationalExpression(relationalExpression), op(op), equalityExpression(equalityExpression)
{
}

EqualityExpression::EqualityExpression() : relationalExpression(nullptr), op(nullopt), equalityExpression(nullptr)
{
}

EqualityExpression::~EqualityExpression()
{
	delete relationalExpression;
	delete equalityExpression;
}

RelationalExpression* EqualityExpression::getRelationalExpression() const
{
	return relationalExpression;
}

optional<int> EqualityExpression::getOp() const
{
	return op;
}

EqualityExpression* EqualityExpression::getEqualityExpression() const
{
	return equalityExpression;
}
