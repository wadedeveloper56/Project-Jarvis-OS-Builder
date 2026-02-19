#include "pch.h"
#include "StructOrUnionSpecifier.h"

using namespace WadeSpace;

StructOrUnionSpecifier::StructOrUnionSpecifier(TokenPtr structOrUnion, TokenPtr name, vector<StructDeclaration*>* vectorStructDeclaration) : structOrUnion(structOrUnion), name(name), vectorStructDeclaration(vectorStructDeclaration)
{
}

StructOrUnionSpecifier::StructOrUnionSpecifier(TokenPtr structOrUnion, vector<StructDeclaration*>* vectorStructDeclaration) : structOrUnion(structOrUnion), name(nullptr),	vectorStructDeclaration(vectorStructDeclaration)
{
}

StructOrUnionSpecifier::StructOrUnionSpecifier(TokenPtr structOrUnion, TokenPtr name) : structOrUnion(structOrUnion), name(name), vectorStructDeclaration(nullptr)
{
}

StructOrUnionSpecifier::StructOrUnionSpecifier() : structOrUnion(nullptr), name(nullptr), vectorStructDeclaration(nullptr)
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

TokenPtr StructOrUnionSpecifier::getName() const
{
	return name;
}

TokenPtr StructOrUnionSpecifier::getStructOrUnion() const
{
	return structOrUnion;
}

vector<StructDeclaration*>* StructOrUnionSpecifier::getVectorStructDeclaration() const
{
	return vectorStructDeclaration;
}
