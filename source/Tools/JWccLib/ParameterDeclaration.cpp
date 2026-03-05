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
	declarationSpecifiers = other.declarationSpecifiers ? new DeclarationSpecifiers(*other.declarationSpecifiers) : nullptr;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	abstractDeclarator = other.abstractDeclarator ? new AbstractDeclarator(*other.abstractDeclarator) : nullptr;
}

ParameterDeclaration::ParameterDeclaration(ParameterDeclaration&& other) noexcept
{
	declarationSpecifiers = other.declarationSpecifiers ? new DeclarationSpecifiers(*other.declarationSpecifiers) : nullptr;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	abstractDeclarator = other.abstractDeclarator ? new AbstractDeclarator(*other.abstractDeclarator) : nullptr;
}

ParameterDeclaration& ParameterDeclaration::operator=(const ParameterDeclaration& other)
{
	if (this == &other)
		return *this;
	declarationSpecifiers = other.declarationSpecifiers ? new DeclarationSpecifiers(*other.declarationSpecifiers) : nullptr;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	abstractDeclarator = other.abstractDeclarator ? new AbstractDeclarator(*other.abstractDeclarator) : nullptr;
	return *this;
}

ParameterDeclaration& ParameterDeclaration::operator=(ParameterDeclaration&& other) noexcept
{
	if (this == &other)
		return *this;
	declarationSpecifiers = other.declarationSpecifiers ? new DeclarationSpecifiers(*other.declarationSpecifiers) : nullptr;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	abstractDeclarator = other.abstractDeclarator ? new AbstractDeclarator(*other.abstractDeclarator) : nullptr;
	return *this;
}

bool ParameterDeclaration::hasDeclarationSpecifiers() const
{
	return declarationSpecifiers != nullptr;
}

bool ParameterDeclaration::hasDeclarator() const
{
	return declarator != nullptr;
}

bool ParameterDeclaration::hasAbstractDeclarator() const
{
	return abstractDeclarator != nullptr;
}