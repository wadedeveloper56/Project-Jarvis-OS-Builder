#include "pch.h"
#include "StructDeclaration.h"

using namespace WadeSpace;

StructDeclaration::StructDeclaration(SpecifierQualifierList* specifierQualifierList, vector<StructDeclarator*>* vectorStructDeclarator) : specifierQualifierList(specifierQualifierList), vectorStructDeclarator(vectorStructDeclarator)
{
}
