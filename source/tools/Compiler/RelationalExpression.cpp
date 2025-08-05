#include "RelationalExpression.h"

using namespace WadeSpace;
using namespace std;

RelationalExpression::RelationalExpression(ShiftExpression* shiftExpression) : relationalExpression(nullptr), op(nullopt),
shiftExpression(shiftExpression)
{
}

RelationalExpression::RelationalExpression(RelationalExpression* relationalExpression, const int& op,
	ShiftExpression* shiftExpression) :
	relationalExpression(relationalExpression), op(op), shiftExpression(shiftExpression)
{
}

RelationalExpression::RelationalExpression() : relationalExpression(nullptr), op(nullopt), shiftExpression(nullptr)
{
}

RelationalExpression::~RelationalExpression()
{
	delete shiftExpression;
	delete relationalExpression;
}

RelationalExpression* RelationalExpression::getRelationalExpression() const
{
	return relationalExpression;
}

optional<int> RelationalExpression::getOp() const
{
	return op;
}

ShiftExpression* RelationalExpression::getShiftExpression() const
{
	return shiftExpression;
}
