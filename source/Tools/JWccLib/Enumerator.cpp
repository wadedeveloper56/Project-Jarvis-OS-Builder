#include "pch.h"
#include "Enumerator.h"
#include "Expression.h"

using namespace WadeSpace;

Enumerator::Enumerator(TokenPtr identifier, Expression* constantExpression) : identifier(identifier), constantExpression(constantExpression)
{
}

Enumerator::Enumerator() : identifier(nullptr), constantExpression(nullptr)
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

TokenPtr Enumerator::getIdentifier() const
{
	return identifier;
}