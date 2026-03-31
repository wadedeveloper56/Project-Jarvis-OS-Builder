#include "pch.h"
#include "Enumerator.h"
#include "ExpressionTree.h"

using namespace WadeSpace;

Enumerator::Enumerator(CTokenPtr identifier, ExpressionTree* constantExpression) : identifier(identifier), constantExpression(constantExpression)
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

ExpressionTree* Enumerator::getConstantExpression() const
{
	return constantExpression;
}

CTokenPtr Enumerator::getIdentifier() const
{
	return identifier;
}

Enumerator::Enumerator(const Enumerator& other)
{
	identifier = other.identifier ? new CToken(*other.identifier) : nullptr;
	constantExpression = other.constantExpression ? new ExpressionTree(*other.constantExpression) : nullptr;
}

Enumerator::Enumerator(Enumerator&& other) noexcept
{
	identifier = other.identifier ? new CToken(*other.identifier) : nullptr;
	constantExpression = other.constantExpression ? new ExpressionTree(*other.constantExpression) : nullptr;
}

Enumerator& Enumerator::operator=(const Enumerator& other)
{
	if (this == &other)
		return *this;
	identifier = other.identifier ? new CToken(*other.identifier) : nullptr;
	constantExpression = other.constantExpression ? new ExpressionTree(*other.constantExpression) : nullptr;
	return *this;
}

Enumerator& Enumerator::operator=(Enumerator&& other) noexcept
{
	if (this == &other)
		return *this;
	identifier = other.identifier ? new CToken(*other.identifier) : nullptr;
	constantExpression = other.constantExpression ? new ExpressionTree(*other.constantExpression) : nullptr;
	return *this;
}

