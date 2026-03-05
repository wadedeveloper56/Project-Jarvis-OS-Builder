#include "pch.h"
#include "SpecifierQualifierList.h"

using namespace WadeSpace;

SpecifierQualifierList::SpecifierQualifierList(SpecifierQualifierList* specifierQualifierList, TypeSpecifier* typeSpecifier) : specifierQualifierList(specifierQualifierList), typeSpecifier(typeSpecifier), typeQualifier(nullptr)
{
}

SpecifierQualifierList::SpecifierQualifierList(TypeSpecifier* typeSpecifier) : specifierQualifierList(nullptr), typeSpecifier(typeSpecifier), typeQualifier(nullptr)
{
}

SpecifierQualifierList::SpecifierQualifierList(SpecifierQualifierList* specifierQualifierList, TypeQualifier* typeQualifier) : specifierQualifierList(specifierQualifierList), typeSpecifier(nullptr), typeQualifier(typeQualifier)
{
}

SpecifierQualifierList::SpecifierQualifierList(TypeQualifier* typeQualifier) : specifierQualifierList(nullptr), typeSpecifier(nullptr), typeQualifier(typeQualifier)
{
}

SpecifierQualifierList::SpecifierQualifierList() : specifierQualifierList(nullptr), typeSpecifier(nullptr), typeQualifier(nullptr)
{
}

SpecifierQualifierList::~SpecifierQualifierList()
{
	delete specifierQualifierList;
	delete typeSpecifier;
	delete typeQualifier;
}

SpecifierQualifierList* SpecifierQualifierList::getSpecifierQualifierList() const
{
	return specifierQualifierList;
}

TypeSpecifier* SpecifierQualifierList::getTypeSpecifier() const
{
	return typeSpecifier;
}

TypeQualifier* SpecifierQualifierList::getTypeQualifier() const
{
	return typeQualifier;
}

SpecifierQualifierList::SpecifierQualifierList(const SpecifierQualifierList& other)
{
	specifierQualifierList = other.specifierQualifierList ? new SpecifierQualifierList(*other.specifierQualifierList) : nullptr;
	typeSpecifier = other.typeSpecifier ? new TypeSpecifier(*other.typeSpecifier) : nullptr;
	typeQualifier = other.typeQualifier ? new TypeQualifier(*other.typeQualifier) : nullptr;;
}

SpecifierQualifierList::SpecifierQualifierList(SpecifierQualifierList&& other) noexcept
{
	specifierQualifierList = other.specifierQualifierList ? new SpecifierQualifierList(*other.specifierQualifierList) : nullptr;
	typeSpecifier = other.typeSpecifier ? new TypeSpecifier(*other.typeSpecifier) : nullptr;
	typeQualifier = other.typeQualifier ? new TypeQualifier(*other.typeQualifier) : nullptr;;
}

SpecifierQualifierList& SpecifierQualifierList::operator=(const SpecifierQualifierList& other)
{
	if (this == &other)
		return *this;
	specifierQualifierList = other.specifierQualifierList ? new SpecifierQualifierList(*other.specifierQualifierList) : nullptr;
	typeSpecifier = other.typeSpecifier ? new TypeSpecifier(*other.typeSpecifier) : nullptr;
	typeQualifier = other.typeQualifier ? new TypeQualifier(*other.typeQualifier) : nullptr;
	return *this;
}

SpecifierQualifierList& SpecifierQualifierList::operator=(SpecifierQualifierList&& other) noexcept
{
	if (this == &other)
		return *this;
	specifierQualifierList = other.specifierQualifierList ? new SpecifierQualifierList(*other.specifierQualifierList) : nullptr;
	typeSpecifier = other.typeSpecifier ? new TypeSpecifier(*other.typeSpecifier) : nullptr;
	typeQualifier = other.typeQualifier ? new TypeQualifier(*other.typeQualifier) : nullptr;;
	return *this;
}

bool SpecifierQualifierList::hasSpecifierQualifierList() const
{
	return specifierQualifierList != nullptr;
}

bool SpecifierQualifierList::hasTypeSpecifier() const
{
	return typeSpecifier != nullptr;
}

bool SpecifierQualifierList::hasTypeQualifier() const
{
	return typeQualifier != nullptr;
}