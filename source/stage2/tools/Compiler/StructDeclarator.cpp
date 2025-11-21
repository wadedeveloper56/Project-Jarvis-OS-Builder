#include "StructDeclarator.h"
#include "ExpressionNode.h"

using namespace WadeSpace;

StructDeclarator::StructDeclarator(Declarator* declarator) : declarator(declarator), constantExpression(nullptr)
{
}

StructDeclarator::StructDeclarator(ExpressionNode* constantExpression) : declarator(nullptr), constantExpression(constantExpression)
{
}

StructDeclarator::StructDeclarator(Declarator* declarator, ExpressionNode* constantExpression) : declarator(declarator), constantExpression(constantExpression)
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

ExpressionNode* StructDeclarator::getConstantExpression() const
{
	return constantExpression;
}
