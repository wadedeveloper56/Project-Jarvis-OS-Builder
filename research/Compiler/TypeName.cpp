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
