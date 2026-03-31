#include "pch.h"
#include "DeclarationSpecifiers.h"

using namespace WadeSpace;

DeclarationSpecifiersNode::DeclarationSpecifiersNode(StorageClassSpecifier* const storageClassSpecifier, TypeSpecifier* const typeSpecifier, TypeQualifier* const typeQualifier)
	: storageClassSpecifier(storageClassSpecifier), typeSpecifier(typeSpecifier), typeQualifier(typeQualifier) 
{
}

void DeclarationSpecifiers::addDeclarationSpecifiersNode(StorageClassSpecifier* const storageClassSpecifier, TypeSpecifier* const typeSpecifier, TypeQualifier* const typeQualifier)
{
	if (declarationSpecifiersNodeList == nullptr)
	{
		declarationSpecifiersNodeList = new vector<DeclarationSpecifiersNode*>();
	}
	declarationSpecifiersNodeList->push_back(new DeclarationSpecifiersNode(storageClassSpecifier, typeSpecifier, typeQualifier));
}
