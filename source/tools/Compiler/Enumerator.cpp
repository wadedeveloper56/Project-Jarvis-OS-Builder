#include "Enumerator.h"

using namespace WadeSpace;

Enumerator::Enumerator(string&  operatorStr, ConstantExpression* constantExpression) : operatorStr(operatorStr), constantExpression(constantExpression)
{
}

Enumerator::Enumerator(string&  operatorStr) : operatorStr(operatorStr), constantExpression(nullptr)
{
}

Enumerator::Enumerator() : operatorStr(nullopt), constantExpression(nullptr)
{
}

Enumerator::~Enumerator()
{
	delete constantExpression;
}

bool Enumerator::hasOperatorStr() const
{
	return operatorStr.has_value();
}

string Enumerator::getOperatorStr() const
{
	return operatorStr.value();
}

ConstantExpression* Enumerator::getConstantExpression() const
{
	return constantExpression;
}
