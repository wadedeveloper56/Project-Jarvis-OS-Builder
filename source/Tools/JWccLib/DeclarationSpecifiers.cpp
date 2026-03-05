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
	declarationSpecifiersNodeList = nullptr;
}

DeclarationSpecifiers::~DeclarationSpecifiers()
{
	if (declarationSpecifiersNodeList != nullptr)
	{
		for (DeclarationSpecifiersNode* node : *declarationSpecifiersNodeList)
		{
			delete node;
		}
		delete declarationSpecifiersNodeList;
	}
}

void DeclarationSpecifiers::addDeclarationSpecifiersNode(StorageClassSpecifier* const storageClassSpecifier, TypeSpecifier* const typeSpecifier, TypeQualifier* const typeQualifier)
{
	if (declarationSpecifiersNodeList == nullptr)
	{
		declarationSpecifiersNodeList = new vector<DeclarationSpecifiersNode*>();
	}
	declarationSpecifiersNodeList->push_back(new DeclarationSpecifiersNode(storageClassSpecifier, typeSpecifier, typeQualifier));
}

vector<DeclarationSpecifiersNode*>* DeclarationSpecifiers::getDeclarationSpecifiersNodeList() const
{
	return declarationSpecifiersNodeList;
}

bool DeclarationSpecifiers::hasDeclarationSpecifiersNodeList() const
{
	return declarationSpecifiersNodeList != nullptr;
}

DeclarationSpecifiers::DeclarationSpecifiers(const DeclarationSpecifiers& other)
{
	declarationSpecifiersNodeList = other.declarationSpecifiersNodeList ? new vector<DeclarationSpecifiersNode*>(*other.declarationSpecifiersNodeList) : nullptr;
}

DeclarationSpecifiers::DeclarationSpecifiers(DeclarationSpecifiers&& other) noexcept
{
	declarationSpecifiersNodeList = other.declarationSpecifiersNodeList ? new vector<DeclarationSpecifiersNode*>(*other.declarationSpecifiersNodeList) : nullptr;
}

DeclarationSpecifiers& DeclarationSpecifiers::operator=(const DeclarationSpecifiers& other)
{
	if (this == &other)
		return *this;
	declarationSpecifiersNodeList = other.declarationSpecifiersNodeList ? new vector<DeclarationSpecifiersNode*>(*other.declarationSpecifiersNodeList) : nullptr;
	return *this;
}

DeclarationSpecifiers& DeclarationSpecifiers::operator=(DeclarationSpecifiers&& other) noexcept
{
	if (this == &other)
		return *this;
	declarationSpecifiersNodeList = other.declarationSpecifiersNodeList ? new vector<DeclarationSpecifiersNode*>(*other.declarationSpecifiersNodeList) : nullptr;
	return *this;
}

