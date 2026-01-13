#include "ParameterDeclaration.h"

using namespace WadeSpace;

ParameterDeclaration::ParameterDeclaration(DeclarationSpecifiers* declarationSpecifiers) : declarationSpecifiers(declarationSpecifiers), abstractDeclarator(nullptr), declarator(nullptr)
{
}

ParameterDeclaration::ParameterDeclaration(DeclarationSpecifiers* declarationSpecifiers, AbstractDeclarator* abstractDeclarator) : declarationSpecifiers(declarationSpecifiers), abstractDeclarator(abstractDeclarator), declarator(nullptr)
{
}

ParameterDeclaration::ParameterDeclaration(DeclarationSpecifiers* declarationSpecifiers, Declarator* declarator) : declarationSpecifiers(declarationSpecifiers), abstractDeclarator(nullptr), declarator(declarator)
{
}

ParameterDeclaration::ParameterDeclaration(): declarationSpecifiers(nullptr), abstractDeclarator(nullptr), declarator(nullptr)
{
}

ParameterDeclaration::~ParameterDeclaration()
{
	delete declarationSpecifiers;
	delete abstractDeclarator;
	delete declarator;
}

DeclarationSpecifiers* ParameterDeclaration::getDeclarationSpecifiers() const
{
	return declarationSpecifiers;
}

Declarator* ParameterDeclaration::getDeclarator() const
{
	return declarator;
}

AbstractDeclarator* ParameterDeclaration::getAbstractDeclarator() const
{
	return abstractDeclarator;
}
