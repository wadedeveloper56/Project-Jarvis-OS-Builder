#include "pch.h"
#include "StructDeclarator.h"
#include "ExpressionTree.h"

using namespace WadeSpace;

StructDeclarator::StructDeclarator(Declarator* declarator) : declarator(declarator), constantExpression(nullptr)
{
}

StructDeclarator::StructDeclarator(ExpressionTree* constantExpression) : declarator(nullptr), constantExpression(constantExpression)
{
}

StructDeclarator::StructDeclarator(Declarator* declarator, ExpressionTree* constantExpression) : declarator(declarator), constantExpression(constantExpression)
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

ExpressionTree* StructDeclarator::getConstantExpression() const
{
	return constantExpression;
}

StructDeclarator::StructDeclarator(const StructDeclarator& other)
{
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	constantExpression = other.constantExpression ? new ExpressionTree(*other.constantExpression) : nullptr;
}

StructDeclarator::StructDeclarator(StructDeclarator&& other) noexcept
{
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	constantExpression = other.constantExpression ? new ExpressionTree(*other.constantExpression) : nullptr;
}

StructDeclarator& StructDeclarator::operator=(const StructDeclarator& other)
{
	if (this == &other)
		return *this;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	constantExpression = other.constantExpression ? new ExpressionTree(*other.constantExpression) : nullptr;
	return *this;
}

StructDeclarator& StructDeclarator::operator=(StructDeclarator&& other) noexcept
{
	if (this == &other)
		return *this;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	constantExpression = other.constantExpression ? new ExpressionTree(*other.constantExpression) : nullptr;
	return *this;
}

bool StructDeclarator::hasDeclarator() const
{
	return declarator != nullptr;
}

bool StructDeclarator::hasConstantExpression() const
{
	return constantExpression != nullptr;
}
