#include "StructDeclaration.h"

using namespace WadeSpace;

StructDeclaration::StructDeclaration(SpecifierQualifierList* specifierQualifierList, vector<StructDeclarator*>* vectorStructDeclarator) : specifierQualifierList(specifierQualifierList), vectorStructDeclarator(vectorStructDeclarator)
{
}

StructDeclaration::StructDeclaration() : specifierQualifierList(nullptr), vectorStructDeclarator(nullptr)
{
}

StructDeclaration::~StructDeclaration()
{
    delete specifierQualifierList;
    for (StructDeclarator* ptr : *vectorStructDeclarator)
    {
        delete ptr;
    }
    delete vectorStructDeclarator;
}

SpecifierQualifierList* StructDeclaration::getSpecifierQualifierList() const
{
	return specifierQualifierList;
}

vector<StructDeclarator*>* StructDeclaration::getVectorStructDeclarator() const
{
	return vectorStructDeclarator;
}
