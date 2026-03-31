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
