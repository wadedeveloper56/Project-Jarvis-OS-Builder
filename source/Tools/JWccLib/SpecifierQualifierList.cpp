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

