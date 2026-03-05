#include "pch.h"
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
	if (vectorStructDeclarator != nullptr)
	{
		for (StructDeclarator* ptr : *vectorStructDeclarator)
		{
			delete ptr;
		}
		delete vectorStructDeclarator;
	}
}

SpecifierQualifierList* StructDeclaration::getSpecifierQualifierList() const
{
	return specifierQualifierList;
}

vector<StructDeclarator*>* StructDeclaration::getVectorStructDeclarator() const
{
	return vectorStructDeclarator;
}

StructDeclaration::StructDeclaration(const StructDeclaration& other)
{
	specifierQualifierList = other.specifierQualifierList ? new SpecifierQualifierList(*other.specifierQualifierList) : nullptr;
	vectorStructDeclarator = other.vectorStructDeclarator ? new vector<StructDeclarator*>(*other.vectorStructDeclarator) : nullptr;
}

StructDeclaration::StructDeclaration(StructDeclaration&& other) noexcept
{
	specifierQualifierList = other.specifierQualifierList ? new SpecifierQualifierList(*other.specifierQualifierList) : nullptr;
	vectorStructDeclarator = other.vectorStructDeclarator ? new vector<StructDeclarator*>(*other.vectorStructDeclarator) : nullptr;
}

StructDeclaration& StructDeclaration::operator=(const StructDeclaration& other)
{
	if (this == &other)
		return *this;
	specifierQualifierList = other.specifierQualifierList ? new SpecifierQualifierList(*other.specifierQualifierList) : nullptr;
	vectorStructDeclarator = other.vectorStructDeclarator ? new vector<StructDeclarator*>(*other.vectorStructDeclarator) : nullptr;
	return *this;
}

StructDeclaration& StructDeclaration::operator=(StructDeclaration&& other) noexcept
{
	if (this == &other)
		return *this;
	specifierQualifierList = other.specifierQualifierList ? new SpecifierQualifierList(*other.specifierQualifierList) : nullptr;
	vectorStructDeclarator = other.vectorStructDeclarator ? new vector<StructDeclarator*>(*other.vectorStructDeclarator) : nullptr		;
	return *this;
}

bool StructDeclaration::hasSpecifierQualifierList() const
{
	return specifierQualifierList != nullptr;
}

bool StructDeclaration::hasVectorStructDeclarator() const
{
	return vectorStructDeclarator != nullptr;
}	
