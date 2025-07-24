#include "AdditiveExpression.h"

using namespace WadeSpace;
using namespace std;

AdditiveExpression::AdditiveExpression(MultiplicativeExpression* me) : additiveExpression(nullptr), oper(""), multiplicativeExpression(me)
{
}

AdditiveExpression::AdditiveExpression(AdditiveExpression* ae, const string& op, MultiplicativeExpression* me) : additiveExpression(ae), oper(op), multiplicativeExpression(me)
{
}

AdditiveExpression::AdditiveExpression() : additiveExpression(nullptr), oper(""), multiplicativeExpression(nullptr)
{
}

AdditiveExpression::~AdditiveExpression()
{
	delete additiveExpression;
	delete multiplicativeExpression;
}

MultiplicativeExpression* AdditiveExpression::getMultiplicativeExpression() const { return multiplicativeExpression; }
AdditiveExpression* AdditiveExpression::getAdditiveExpression() const { return additiveExpression; }
optional<string> AdditiveExpression::getOperation() const { return oper; }
