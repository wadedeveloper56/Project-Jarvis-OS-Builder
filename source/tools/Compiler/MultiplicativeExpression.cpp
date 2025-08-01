#include "MultiplicativeExpression.h"

using namespace WadeSpace;
using namespace std;

MultiplicativeExpression::MultiplicativeExpression(CastExpression* castExpression) : castExpression(castExpression), op(nullopt), multiplicativeExpression(nullptr)
{
}

MultiplicativeExpression::MultiplicativeExpression(MultiplicativeExpression* multiplicativeExpression, const string& op, CastExpression* castExpression): multiplicativeExpression(multiplicativeExpression), op(op), castExpression(castExpression)
{
}

MultiplicativeExpression::MultiplicativeExpression() : multiplicativeExpression(nullptr), op(nullopt), castExpression(nullptr)
{
}

MultiplicativeExpression::~MultiplicativeExpression()
{
    delete multiplicativeExpression;
    delete castExpression;
}

MultiplicativeExpression* MultiplicativeExpression::getMultiplicativeExpression() const
{
	return multiplicativeExpression;
}

optional<string> MultiplicativeExpression::getOp() const
{
	return op;
}

CastExpression* MultiplicativeExpression::getCastExpression() const
{
	return castExpression;
}
