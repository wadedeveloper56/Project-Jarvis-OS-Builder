#include "pch.h"
#include "TypeName.h"

using namespace WadeSpace;

TypeName::TypeName(SpecifierQualifierList* specifierQualifierList) : specifierQualifierList(specifierQualifierList), abstractDeclarator(nullptr)
{
}

TypeName::TypeName(SpecifierQualifierList* specifierQualifierList, AbstractDeclarator* abstractDeclarator) : specifierQualifierList(specifierQualifierList), abstractDeclarator(abstractDeclarator)
{
}

TypeName::TypeName() : specifierQualifierList(nullptr), abstractDeclarator(nullptr)
{
}

TypeName::~TypeName()
{
	delete specifierQualifierList;
	delete abstractDeclarator;
}

SpecifierQualifierList* TypeName::getSpecifierQualifierList() const
{
	return specifierQualifierList;
}

AbstractDeclarator* TypeName::getAbstractDeclarator() const
{
	return abstractDeclarator;
}

TypeName::TypeName(const TypeName& other)
{
	specifierQualifierList = other.specifierQualifierList ? new SpecifierQualifierList(*other.specifierQualifierList) : nullptr;
	abstractDeclarator = other.abstractDeclarator ? new AbstractDeclarator(*other.abstractDeclarator) : nullptr;
}

TypeName::TypeName(TypeName&& other) noexcept
{
	specifierQualifierList = other.specifierQualifierList ? new SpecifierQualifierList(*other.specifierQualifierList) : nullptr;
	abstractDeclarator = other.abstractDeclarator ? new AbstractDeclarator(*other.abstractDeclarator) : nullptr;
}

TypeName& TypeName::operator=(const TypeName& other)
{
	if (this == &other)
		return *this;
	specifierQualifierList = other.specifierQualifierList ? new SpecifierQualifierList(*other.specifierQualifierList) : nullptr;
	abstractDeclarator = other.abstractDeclarator ? new AbstractDeclarator(*other.abstractDeclarator) : nullptr;
	return *this;
}

TypeName& TypeName::operator=(TypeName&& other) noexcept
{
	if (this == &other)
		return *this;
	specifierQualifierList = other.specifierQualifierList ? new SpecifierQualifierList(*other.specifierQualifierList) : nullptr;
	abstractDeclarator = other.abstractDeclarator ? new AbstractDeclarator(*other.abstractDeclarator) : nullptr;
	return *this;
}
