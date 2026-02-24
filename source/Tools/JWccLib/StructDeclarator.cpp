#include "pch.h"
#include "StructDeclarator.h"
#include "Expression.h"

using namespace WadeSpace;

StructDeclarator::StructDeclarator(Declarator* declarator) : declarator(declarator), constantExpression(nullptr)
{
}

StructDeclarator::StructDeclarator(Expression* constantExpression) : declarator(nullptr), constantExpression(constantExpression)
{
}

StructDeclarator::StructDeclarator(Declarator* declarator, Expression* constantExpression) : declarator(declarator), constantExpression(constantExpression)
{
}

StructDeclarator::StructDeclarator() : declarator(nullptr), constantExpression(nullptr)
{
}

StructDeclarator::~StructDeclarator()
{
	delete declarator;
	delete constantExpression;
}

Declarator* StructDeclarator::getDeclarator() const
{
	return declarator;
}

Expression* StructDeclarator::getConstantExpression() const
{
	return constantExpression;
}

StructDeclarator::StructDeclarator(const StructDeclarator& other)
{
	delete declarator;
	delete constantExpression;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	constantExpression = other.constantExpression ? new Expression(*other.constantExpression) : nullptr;
}

StructDeclarator::StructDeclarator(StructDeclarator&& other) noexcept
{
	delete declarator;
	delete constantExpression;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	constantExpression = other.constantExpression ? new Expression(*other.constantExpression) : nullptr;
}

StructDeclarator& StructDeclarator::operator=(const StructDeclarator& other)
{
	if (this == &other)
		return *this;
	delete declarator;
	delete constantExpression;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	constantExpression = other.constantExpression ? new Expression(*other.constantExpression) : nullptr;
	return *this;
}

StructDeclarator& StructDeclarator::operator=(StructDeclarator&& other) noexcept
{
	if (this == &other)
		return *this;
	delete declarator;
	delete constantExpression;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	constantExpression = other.constantExpression ? new Expression(*other.constantExpression) : nullptr;
	return *this;
}
