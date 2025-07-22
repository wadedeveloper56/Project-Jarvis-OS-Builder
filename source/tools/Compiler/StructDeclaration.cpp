#include "StructDeclaration.h"

using namespace WadeSpace;

StructDeclaration::StructDeclaration(SpecifierQualifierList* sql,
                                     vector<StructDeclarator*>* list) : sql(sql), list(list)
{
}

StructDeclaration::StructDeclaration() : sql(nullptr), list(nullptr)
{
}

StructDeclaration::~StructDeclaration()
{
}
