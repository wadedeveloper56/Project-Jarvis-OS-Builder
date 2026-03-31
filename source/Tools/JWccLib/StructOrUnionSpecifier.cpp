#include "pch.h"
#include "StructOrUnionSpecifier.h"

using namespace WadeSpace;

StructOrUnionSpecifier::StructOrUnionSpecifier(CTokenPtr structOrUnion, CTokenPtr name, vector<StructDeclaration*>* vectorStructDeclaration) : 
structOrUnion(structOrUnion), name(name), vectorStructDeclaration(vectorStructDeclaration)
{
}
