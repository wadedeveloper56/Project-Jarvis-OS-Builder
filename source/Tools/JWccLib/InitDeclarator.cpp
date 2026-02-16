#include "pch.h"
#include "InitDeclarator.h"

using namespace WadeSpace;

InitDeclarator::InitDeclarator(Declarator* declarator) : declarator(declarator), initializer(nullptr)
{
}

InitDeclarator::InitDeclarator(Declarator* declarator, Initializer* initializer) : declarator(declarator), initializer(initializer)
{
}

InitDeclarator::InitDeclarator() : declarator(nullptr), initializer(nullptr)
{
}

InitDeclarator::~InitDeclarator()
{
	delete declarator;
	delete initializer;
}

Declarator* InitDeclarator::getDeclarator() const { return declarator; }
Initializer* InitDeclarator::getInitializer() const { return initializer; }

string InitDeclarator::getVariableName() const
{
	TokenPtr identifier = getDeclarator()->getDirectDeclarator()->getIdentifier();
	if (!identifier) identifier = getDeclarator()->getDirectDeclarator()->getDirectDeclarator()->getIdentifier();
	return (identifier) ? identifier->data->repr.symbol.string : "";
}
