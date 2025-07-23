#include "RelationalExpression.h"

using namespace WadeSpace;
using namespace std;

RelationalExpression::RelationalExpression(ShiftExpression* se) : re(nullptr), op(""), se(se)
{
}

RelationalExpression::RelationalExpression(RelationalExpression* re, const string& op, ShiftExpression* se) : re(re), op(op), se(se)
{
}

RelationalExpression::RelationalExpression() : re(nullptr), op(""), se(nullptr)
{
}

RelationalExpression::~RelationalExpression()
{
	delete se;
	delete re;
}
