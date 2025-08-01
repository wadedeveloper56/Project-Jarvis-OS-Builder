#include "StructDeclarator.h"

using namespace WadeSpace;

StructDeclarator::StructDeclarator(Declarator* declarator) : declarator(declarator), constantExpression(nullptr)
{
}

StructDeclarator::StructDeclarator(ConstantExpression* constantExpression) : declarator(nullptr), constantExpression(constantExpression)
{
}

StructDeclarator::StructDeclarator(Declarator* declarator, ConstantExpression* constantExpression) : declarator(declarator), constantExpression(constantExpression)
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

ConstantExpression* StructDeclarator::getConstantExpression() const
{
	return constantExpression;
}
