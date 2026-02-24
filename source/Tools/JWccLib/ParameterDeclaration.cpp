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


ParameterDeclaration::ParameterDeclaration(const ParameterDeclaration& other)
{
	delete declarationSpecifiers;
	delete declarator;
	delete abstractDeclarator;
	declarationSpecifiers = other.declarationSpecifiers ? new DeclarationSpecifiers(*other.declarationSpecifiers) : nullptr;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	abstractDeclarator = other.abstractDeclarator ? new AbstractDeclarator(*other.abstractDeclarator) : nullptr;
}

ParameterDeclaration::ParameterDeclaration(ParameterDeclaration&& other) noexcept
{
	delete declarationSpecifiers;
	delete declarator;
	delete abstractDeclarator;
	declarationSpecifiers = other.declarationSpecifiers ? new DeclarationSpecifiers(*other.declarationSpecifiers) : nullptr;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	abstractDeclarator = other.abstractDeclarator ? new AbstractDeclarator(*other.abstractDeclarator) : nullptr;
}

ParameterDeclaration& ParameterDeclaration::operator=(const ParameterDeclaration& other)
{
	if (this == &other)
		return *this;
	delete declarationSpecifiers;
	delete declarator;
	delete abstractDeclarator;
	declarationSpecifiers = other.declarationSpecifiers ? new DeclarationSpecifiers(*other.declarationSpecifiers) : nullptr;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	abstractDeclarator = other.abstractDeclarator ? new AbstractDeclarator(*other.abstractDeclarator) : nullptr;
	return *this;
}

ParameterDeclaration& ParameterDeclaration::operator=(ParameterDeclaration&& other) noexcept
{
	if (this == &other)
		return *this;
	delete declarationSpecifiers;
	delete declarator;
	delete abstractDeclarator;
	declarationSpecifiers = other.declarationSpecifiers ? new DeclarationSpecifiers(*other.declarationSpecifiers) : nullptr;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	abstractDeclarator = other.abstractDeclarator ? new AbstractDeclarator(*other.abstractDeclarator) : nullptr;
	return *this;
}
