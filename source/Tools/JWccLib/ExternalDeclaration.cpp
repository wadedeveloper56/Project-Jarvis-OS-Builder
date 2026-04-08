#include "pch.h"
#include "ExternalDeclaration.h"
#include "GlobalVars.h"
#include "Compiler.h"

using namespace WadeSpace;
using namespace std;
 
ExternalDeclaration::ExternalDeclaration(shared_ptr<FunctionDefinition> functionDefinition) : functionDefinition(functionDefinition), declaration(nullptr)
{
}

ExternalDeclaration::ExternalDeclaration(shared_ptr<Declaration> declaration) : functionDefinition(nullptr), declaration(declaration)
{
	if (isTypedef())
	{
		shared_ptr<DeclarationSpecifiers> declSpecifiers = declaration->getDeclarationSpecifiers();
		shared_ptr<vector<shared_ptr<InitDeclarator>>> initDeclaratorsList = declaration->getVectorInitDeclarator();

		shared_ptr<vector<shared_ptr<DeclarationSpecifiersNode>>> list = declSpecifiers->getDeclarationSpecifiersNodeList();
		string name = initDeclaratorsList->at(0)->getDeclarator()->getDirectDeclarator()->getIdentifier()->getSymbolName();
		compiler->addTypedef(name, make_shared<DeclarationSpecifiersNode>(*list->at(0)));
	}
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
