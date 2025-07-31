#include "AdditiveExpression.h"

using namespace WadeSpace;
using namespace std;

AdditiveExpression::AdditiveExpression(MultiplicativeExpression* multiplicativeExpression) : additiveExpression(nullptr), oper(""), multiplicativeExpression(multiplicativeExpression)
{
}

AdditiveExpression::AdditiveExpression(AdditiveExpression* additiveExpression, const string& op, MultiplicativeExpression* multiplicativeExpression) : additiveExpression(additiveExpression), oper(op), multiplicativeExpression(multiplicativeExpression)
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
