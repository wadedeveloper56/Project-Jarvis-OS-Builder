#include "pch.h"
#include "InitDeclarator.h"

using namespace WadeSpace;

InitDeclarator::InitDeclarator(Declarator* declarator) : declarator(declarator), initializer(nullptr)
{
}

InitDeclarator::InitDeclarator(Declarator* declarator, Initializer* initializer) : declarator(declarator), initializer(initializer)
{
}

string InitDeclarator::getVariableName() const
{
	CTokenPtr identifier = getDeclarator()->getDirectDeclarator()->getIdentifier();
	if (!identifier) identifier = getDeclarator()->getDirectDeclarator()->getDirectDeclarator()->getIdentifier();
	return (identifier) ? identifier->getSymbolName() : "";
}
