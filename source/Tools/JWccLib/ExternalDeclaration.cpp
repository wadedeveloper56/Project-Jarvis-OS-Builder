#include "pch.h"
#include "ExternalDeclaration.h"
#include <iostream>

using namespace WadeSpace;
using namespace std;
 
ExternalDeclaration::ExternalDeclaration(shared_ptr<FunctionDefinition> functionDefinition) : functionDefinition(functionDefinition), declaration(nullptr)
{
}

ExternalDeclaration::ExternalDeclaration(shared_ptr<Declaration> declaration) : functionDefinition(nullptr), declaration(declaration)
{
}

bool ExternalDeclaration::isTypedef() const
{
	if (declaration != nullptr)
	{
		shared_ptr<vector<shared_ptr<DeclarationSpecifiersNode>>> temp = declaration->getDeclarationSpecifiers()->getDeclarationSpecifiersNodeList();
		for (auto node : *temp)
		{
			if (node->getStorageClassSpecifier() != nullptr && node->getStorageClassSpecifier()->getType()->getKeywordName() == "typedef")
			{
				return true;
			}
		}
	}
	return false;
}
