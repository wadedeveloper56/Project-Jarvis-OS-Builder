#include "StructOrUnionSpecifier.h"

using namespace WadeSpace;

StructOrUnionSpecifier::StructOrUnionSpecifier(StructOrUnion* structOrUnion, const string& name, vector<StructDeclaration*>* vectorStructDeclaration) : structOrUnion(structOrUnion), name(name), vectorStructDeclaration(vectorStructDeclaration)
{
}

StructOrUnionSpecifier::StructOrUnionSpecifier(StructOrUnion* structOrUnion, vector<StructDeclaration*>* vectorStructDeclaration) : structOrUnion(structOrUnion), name(nullopt),	vectorStructDeclaration(vectorStructDeclaration)
{
}

StructOrUnionSpecifier::StructOrUnionSpecifier(StructOrUnion* structOrUnion, const string& name) : structOrUnion(structOrUnion), name(name), vectorStructDeclaration(nullptr)
{
}

StructOrUnionSpecifier::StructOrUnionSpecifier() : structOrUnion(nullptr), name(nullopt), vectorStructDeclaration(nullptr)
{
}

StructOrUnionSpecifier::~StructOrUnionSpecifier()
{
	delete structOrUnion;
	for (StructDeclaration* ptr : *vectorStructDeclaration)
	{
		delete ptr;
	}
	delete vectorStructDeclaration;
}

optional<string> StructOrUnionSpecifier::getName() const
{
	return name;
}

StructOrUnion* StructOrUnionSpecifier::getStructOrUnion() const
{
	return structOrUnion;
}

vector<StructDeclaration*>* StructOrUnionSpecifier::getVectorStructDeclaration() const
{
	return vectorStructDeclaration;
}
