#include "Enumerator.h"

using namespace WadeSpace;

Enumerator::Enumerator(string&  operatorStr, ConstantExpression* constantExpression) : operatorStr(operatorStr), constantExpression(constantExpression)
{
}

Enumerator::Enumerator(string&  operatorStr) : operatorStr(operatorStr), constantExpression(nullptr)
{
}

Enumerator::Enumerator() : operatorStr(""), constantExpression(nullptr)
{
}

Enumerator::~Enumerator()
{
	delete constantExpression;
}

ConstantExpression* Enumerator::getConstantExpression() const
{
	return constantExpression;
}
