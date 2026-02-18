#include "pch.h"
#include "Declaration.h"

using namespace WadeSpace;
using namespace std;

Declaration::Declaration(DeclarationSpecifiers* declarationSpecifiers) : declarationSpecifiers(declarationSpecifiers), vectorInitDeclarator(nullptr)
{
}

Declaration::Declaration(DeclarationSpecifiers* declarationSpecifiers, vector<InitDeclarator*>* vectorInitDeclarator) : declarationSpecifiers(declarationSpecifiers), vectorInitDeclarator(vectorInitDeclarator)
{
}

Declaration::Declaration() : declarationSpecifiers(nullptr), vectorInitDeclarator(nullptr)
{
}

Declaration::~Declaration()
{
	delete declarationSpecifiers;
	if (vectorInitDeclarator != nullptr)
	{
		for (InitDeclarator* ptr : *vectorInitDeclarator)
		{
			delete ptr;
		}
	}
	delete vectorInitDeclarator;
}

DeclarationSpecifiers* Declaration::getDeclarationSpecifiers() const { return declarationSpecifiers; }
vector<InitDeclarator*>* Declaration::getVectorInitDeclarator() const { return vectorInitDeclarator; }
bool Declaration::isDeclarationSpecifiers() const { return declarationSpecifiers != nullptr;  }
bool Declaration::isVectorInitDeclarator() const { return vectorInitDeclarator != nullptr; }
bool Declaration::isStorageClassSpecifier() const
{
	if (declarationSpecifiers != nullptr)
	{
		return declarationSpecifiers->isStorageClassSpecifier();
	}
	return false;
}

StorageClassSpecifier* Declaration::getStorageClassSpecifier() const
{
	if (declarationSpecifiers != nullptr)
	{
		return declarationSpecifiers->getStorageClassSpecifier();
	}
	return nullptr;
}
