#include "pch.h"
#include "StructOrUnionSpecifier.h"

using namespace WadeSpace;

StructOrUnionSpecifier::StructOrUnionSpecifier(TokenPtr structOrUnion, TokenPtr name, vector<StructDeclaration*>* vectorStructDeclaration) : structOrUnion(structOrUnion), name(name), vectorStructDeclaration(vectorStructDeclaration)
{
}

StructOrUnionSpecifier::StructOrUnionSpecifier() : structOrUnion(nullptr), name(nullptr), vectorStructDeclaration(nullptr)
{
}

StructOrUnionSpecifier::~StructOrUnionSpecifier()
{
	delete structOrUnion;
	delete name;
	if (vectorStructDeclaration != nullptr)
	{
		for (StructDeclaration* ptr : *vectorStructDeclaration)
		{
			delete ptr;
		}
		delete vectorStructDeclaration;
	}
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

StructOrUnionSpecifier::StructOrUnionSpecifier(const StructOrUnionSpecifier& other)
{
	name = other.name;
	structOrUnion = other.structOrUnion ? new Token(*other.structOrUnion) : nullptr;
	vectorStructDeclaration = other.vectorStructDeclaration ? new vector<StructDeclaration*>(*other.vectorStructDeclaration) : nullptr;
}

StructOrUnionSpecifier::StructOrUnionSpecifier(StructOrUnionSpecifier&& other) noexcept
{
	name = other.name;
	structOrUnion = other.structOrUnion ? new Token(*other.structOrUnion) : nullptr;
	vectorStructDeclaration = other.vectorStructDeclaration ? new vector<StructDeclaration*>(*other.vectorStructDeclaration) : nullptr;
}

StructOrUnionSpecifier& StructOrUnionSpecifier::operator=(const StructOrUnionSpecifier& other)
{
	if (this == &other)
		return *this;
	name = other.name;
	structOrUnion = other.structOrUnion ? new Token(*other.structOrUnion) : nullptr;
	vectorStructDeclaration = other.vectorStructDeclaration ? new vector<StructDeclaration*>(*other.vectorStructDeclaration) : nullptr;
	return *this;
}

StructOrUnionSpecifier& StructOrUnionSpecifier::operator=(StructOrUnionSpecifier&& other) noexcept
{
	if (this == &other)
		return *this;
	name = other.name;
	structOrUnion = other.structOrUnion ? new Token(*other.structOrUnion) : nullptr;
	vectorStructDeclaration = other.vectorStructDeclaration ? new vector<StructDeclaration*>(*other.vectorStructDeclaration) : nullptr;
	return *this;
}
