#include "EqualityExpression.h"

using namespace WadeSpace;
using namespace std;

EqualityExpression::EqualityExpression(RelationalExpression* re) : re(nullptr), op(""), ee(nullptr)
{
}

EqualityExpression::EqualityExpression(EqualityExpression* eq, string op, RelationalExpression* re) : re(re), op(op), ee(ee)
{
}

EqualityExpression::EqualityExpression() : re(nullptr), op(""), ee(nullptr)
{
}

EqualityExpression::~EqualityExpression()
{
	delete re;
	delete ee;
}
