#include "pch.h"
#include "DeclarationSpecifiers.h"

using namespace WadeSpace;

DeclarationSpecifiersNode::DeclarationSpecifiersNode(StorageClassSpecifier* const storageClassSpecifier, TypeSpecifier* const typeSpecifier, TypeQualifier* const typeQualifier)
	: storageClassSpecifier(storageClassSpecifier), typeSpecifier(typeSpecifier), typeQualifier(typeQualifier) 
{
}

DeclarationSpecifiersNode::~DeclarationSpecifiersNode()
{
	delete storageClassSpecifier;
	delete typeSpecifier;
	delete typeQualifier;
}

DeclarationSpecifiers::DeclarationSpecifiers()
{
	declarationSpecifiers = nullptr;
}

DeclarationSpecifiers::~DeclarationSpecifiers()
{
	if (declarationSpecifiers != nullptr)
	{
		for (DeclarationSpecifiersNode* node : *declarationSpecifiers)
		{
			delete node;
		}
		delete declarationSpecifiers;
	}
}

void DeclarationSpecifiers::addDeclarationSpecifiersNode(StorageClassSpecifier* const storageClassSpecifier, TypeSpecifier* const typeSpecifier, TypeQualifier* const typeQualifier)
{
	if (declarationSpecifiers == nullptr)
	{
		declarationSpecifiers = new vector<DeclarationSpecifiersNode*>();
	}
	declarationSpecifiers->push_back(new DeclarationSpecifiersNode(storageClassSpecifier, typeSpecifier, typeQualifier));
}

vector<DeclarationSpecifiersNode*>* DeclarationSpecifiers::getDeclarationSpecifiers() const
{
	return declarationSpecifiers;
}

bool DeclarationSpecifiers::isDeclarationSpecifiers() const
{
	return declarationSpecifiers != nullptr;
}

DeclarationSpecifiers::DeclarationSpecifiers(const DeclarationSpecifiers& other)
{
	declarationSpecifiers = other.declarationSpecifiers ? new vector<DeclarationSpecifiersNode*>(*other.declarationSpecifiers) : nullptr;
}

DeclarationSpecifiers::DeclarationSpecifiers(DeclarationSpecifiers&& other) noexcept
{
	declarationSpecifiers = other.declarationSpecifiers ? new vector<DeclarationSpecifiersNode*>(*other.declarationSpecifiers) : nullptr;
}

DeclarationSpecifiers& DeclarationSpecifiers::operator=(const DeclarationSpecifiers& other)
{
	if (this == &other)
		return *this;
	declarationSpecifiers = other.declarationSpecifiers ? new vector<DeclarationSpecifiersNode*>(*other.declarationSpecifiers) : nullptr;
	return *this;
}

DeclarationSpecifiers& DeclarationSpecifiers::operator=(DeclarationSpecifiers&& other) noexcept
{
	if (this == &other)
		return *this;
	declarationSpecifiers = other.declarationSpecifiers ? new vector<DeclarationSpecifiersNode*>(*other.declarationSpecifiers) : nullptr;
	return *this;
}

