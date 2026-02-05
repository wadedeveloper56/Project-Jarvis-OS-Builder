#include "pch.h"
#include "Enumerator.h"
#include "Expression.h"

using namespace WadeSpace;

Enumerator::Enumerator(string&  operatorStr, Expression* constantExpression) : operatorStr(operatorStr), constantExpression(constantExpression)
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

Expression* Enumerator::getConstantExpression() const
{
	return constantExpression;
}

optional<string> Enumerator::getOperatorStr() const
{
	return operatorStr;
}