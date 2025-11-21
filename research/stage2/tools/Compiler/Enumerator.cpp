#include "Enumerator.h"
#include "ExpressionNode.h"

using namespace WadeSpace;

Enumerator::Enumerator(string&  operatorStr, ExpressionNode* constantExpression) : operatorStr(operatorStr), constantExpression(constantExpression)
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

ExpressionNode* Enumerator::getConstantExpression() const
{
	return constantExpression;
}

optional<string> Enumerator::getOperatorStr() const
{
	return operatorStr;
}