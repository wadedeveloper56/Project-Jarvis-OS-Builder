#include "AdditiveExpression.h"

using namespace WadeSpace;
using namespace std;

AdditiveExpression::AdditiveExpression(MultiplicativeExpression* multiplicativeExpression) : additiveExpression(nullptr), oper(nullopt), multiplicativeExpression(multiplicativeExpression)
{
}

AdditiveExpression::AdditiveExpression(AdditiveExpression* additiveExpression, const int& op, MultiplicativeExpression* multiplicativeExpression) : additiveExpression(additiveExpression), oper(op), multiplicativeExpression(multiplicativeExpression)
{
}

AdditiveExpression::AdditiveExpression() : additiveExpression(nullptr), oper(nullopt), multiplicativeExpression(nullptr)
{
}

AdditiveExpression::~AdditiveExpression()
{
	delete additiveExpression;
	delete multiplicativeExpression;
}

MultiplicativeExpression* AdditiveExpression::getMultiplicativeExpression() const { return multiplicativeExpression; }
AdditiveExpression* AdditiveExpression::getAdditiveExpression() const { return additiveExpression; }
optional<int> AdditiveExpression::getOperation() const { return oper; }
