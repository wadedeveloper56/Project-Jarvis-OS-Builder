#include "pch.h"
#include "ExternalDeclaration.h"
#include <iostream>

using namespace WadeSpace;
using namespace std;
 
ExternalDeclaration::ExternalDeclaration(FunctionDefinition* functionDefinition) : functionDefinition(functionDefinition), declaration(nullptr)
{
}

ExternalDeclaration::ExternalDeclaration(Declaration* declaration) : functionDefinition(nullptr), declaration(declaration)
{
}

bool ExternalDeclaration::isTypedef() const
{
	if (declaration != nullptr)
	{
		vector<DeclarationSpecifiersNode*>* temp = declaration->getDeclarationSpecifiers()->getDeclarationSpecifiersNodeList();
		for (DeclarationSpecifiersNode* node : *temp)
		{
			if (node->storageClassSpecifier != nullptr && node->storageClassSpecifier->getType()->getKeywordName() == "typedef")
			{
				return true;
			}
		}
	}
	return false;
}
