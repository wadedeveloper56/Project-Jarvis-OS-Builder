#include "StructDeclarator.h"

using namespace WadeSpace;

StructDeclarator::StructDeclarator(Declarator* dec) : dec(dec), exp(nullptr)
{
}

StructDeclarator::StructDeclarator(ConstantExpression* exp) : dec(nullptr), exp(exp)
{
}

StructDeclarator::StructDeclarator(Declarator* dec, ConstantExpression* exp) : dec(dec), exp(exp)
{
}

StructDeclarator::StructDeclarator() : dec(nullptr), exp(nullptr)
{
}

StructDeclarator::~StructDeclarator()
{
	delete dec;
	delete exp;
}
