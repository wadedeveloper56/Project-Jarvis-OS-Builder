#include "pch.h"
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
