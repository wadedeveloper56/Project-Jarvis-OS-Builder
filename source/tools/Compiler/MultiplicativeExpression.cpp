#include "MultiplicativeExpression.h"

using namespace WadeSpace;
using namespace std;

MultiplicativeExpression::MultiplicativeExpression(CastExpression* ce) : ce(nullptr), op(""), me(nullptr)
{
}

MultiplicativeExpression::MultiplicativeExpression(MultiplicativeExpression* me, string op, CastExpression* ce): me(me), op(op), ce(ce)
{
}

MultiplicativeExpression::MultiplicativeExpression() : me(nullptr), op(""), ce(nullptr)
{
}

MultiplicativeExpression::~MultiplicativeExpression()
{
    delete me;
    delete ce;
}
