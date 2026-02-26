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
	delete identifier;
}

Expression* Enumerator::getConstantExpression() const
{
	return constantExpression;
}

TokenPtr Enumerator::getIdentifier() const
{
	return identifier;
}

Enumerator::Enumerator(const Enumerator& other)
{
	identifier = other.identifier ? new Token(*other.identifier) : nullptr;
	constantExpression = other.constantExpression ? new Expression(*other.constantExpression) : nullptr;
}

Enumerator::Enumerator(Enumerator&& other) noexcept
{
	identifier = other.identifier ? new Token(*other.identifier) : nullptr;
	constantExpression = other.constantExpression ? new Expression(*other.constantExpression) : nullptr;
}

Enumerator& Enumerator::operator=(const Enumerator& other)
{
	if (this == &other)
		return *this;
	identifier = other.identifier ? new Token(*other.identifier) : nullptr;
	constantExpression = other.constantExpression ? new Expression(*other.constantExpression) : nullptr;
	return *this;
}

Enumerator& Enumerator::operator=(Enumerator&& other) noexcept
{
	if (this == &other)
		return *this;
	identifier = other.identifier ? new Token(*other.identifier) : nullptr;
	constantExpression = other.constantExpression ? new Expression(*other.constantExpression) : nullptr;
	return *this;
}

