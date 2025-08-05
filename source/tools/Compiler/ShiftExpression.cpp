#include "ShiftExpression.h"

using namespace WadeSpace;
using namespace std;

ShiftExpression::ShiftExpression(AdditiveExpression* additiveExpression) : additiveExpression(additiveExpression), op(nullopt), shiftExpression(nullptr)
{
}

ShiftExpression::ShiftExpression(ShiftExpression* shiftExpression, const int& op, AdditiveExpression* additiveExpression) : additiveExpression(additiveExpression), op(op), shiftExpression(shiftExpression)
{
}

ShiftExpression::ShiftExpression() : additiveExpression(nullptr), op(nullopt), shiftExpression(nullptr)
{
}

ShiftExpression::~ShiftExpression()
{
	delete additiveExpression;
	delete shiftExpression;
}
