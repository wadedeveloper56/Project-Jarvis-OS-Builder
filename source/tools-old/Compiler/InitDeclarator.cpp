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
	optional<string> name = getDeclarator()->getDirectDeclarator()->getIdentifier();
	if (!name.has_value()) name = getDeclarator()->getDirectDeclarator()->getDirectDeclarator()->getIdentifier();
	return (name.has_value()) ? name.value() : "";
}
