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
