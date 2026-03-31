#include "pch.h"
#include "TypeName.h"

using namespace WadeSpace;

TypeName::TypeName(SpecifierQualifierList* specifierQualifierList) : specifierQualifierList(specifierQualifierList), abstractDeclarator(nullptr)
{
}

TypeName::TypeName(SpecifierQualifierList* specifierQualifierList, AbstractDeclarator* abstractDeclarator) : specifierQualifierList(specifierQualifierList), abstractDeclarator(abstractDeclarator)
{
}
