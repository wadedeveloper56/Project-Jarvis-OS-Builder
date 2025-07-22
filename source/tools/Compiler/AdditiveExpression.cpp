#include "AdditiveExpression.h"

using namespace WadeSpace;
using namespace std;

AdditiveExpression::AdditiveExpression(MultiplicativeExpression* me) : ae(nullptr), op(""), me(nullptr)
{
}

AdditiveExpression::AdditiveExpression(AdditiveExpression* ae, string op,
                                       MultiplicativeExpression* me) : ae(ae), op(op), me(me)
{
}

AdditiveExpression::AdditiveExpression() : ae(nullptr), op(""), me(nullptr)
{
}

AdditiveExpression::~AdditiveExpression()
{
	if (ae) delete ae;
	if (me) delete me;
}

MultiplicativeExpression* AdditiveExpression::getMultiplicativeExpression() const { return me; }
AdditiveExpression* AdditiveExpression::getAdditiveExpression() const { return ae; }
string AdditiveExpression::getOperation() const { return op; }
