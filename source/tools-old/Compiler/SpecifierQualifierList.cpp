#include "SpecifierQualifierList.h"

using namespace WadeSpace;

SpecifierQualifierList::SpecifierQualifierList(SpecifierQualifierList* specifierQualifierList, TypeSpecifier* typeSpecifier) : specifierQualifierList(specifierQualifierList), typeSpecifier(typeSpecifier),
typeQualifier(nullptr)
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
