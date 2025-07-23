#include "Enumerator.h"

using namespace WadeSpace;

Enumerator::Enumerator(const string&  value, ConstantExpression* type) : operatorStr(value), expression(type)
{
}

Enumerator::Enumerator(const string&  value) : operatorStr(value), expression(nullptr)
{
}

Enumerator::Enumerator() : operatorStr(""), expression(nullptr)
{
}

Enumerator::~Enumerator()
{
	delete expression;
}
