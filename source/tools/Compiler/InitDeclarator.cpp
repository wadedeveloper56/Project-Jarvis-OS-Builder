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

string InitDeclarator::getVariableName()
{
	string name = getDeclarator()->getDirectDeclarator()->getId();
	if (name=="") name = getDeclarator()->getDirectDeclarator()->getDirectDeclarator()->getId();
	return name;
}
