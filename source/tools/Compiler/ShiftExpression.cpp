#include "ShiftExpression.h"

using namespace WadeSpace;
using namespace std;

ShiftExpression::ShiftExpression(AdditiveExpression* ae) : ae(nullptr), op(""), se(nullptr)
{
}

ShiftExpression::ShiftExpression(ShiftExpression* se, string op, AdditiveExpression* ae) : ae(ae), op(op), se(se)
{
}

ShiftExpression::ShiftExpression() : ae(nullptr), op(""), se(nullptr)
{
}

ShiftExpression::~ShiftExpression()
{
	delete ae;
	delete se;
}
