#include "pch.h"
#include "Declaration.h"
#include "ExternalDeclaration.h"

using namespace WadeSpace;
using namespace std;

Declaration::Declaration() : declarationSpecifiers(nullptr), vectorInitDeclarator(nullptr)
{
}

Declaration::Declaration(DeclarationSpecifiers* declarationSpecifiers) : declarationSpecifiers(declarationSpecifiers), vectorInitDeclarator(nullptr)
{
}

Declaration::Declaration(DeclarationSpecifiers* declarationSpecifiers, vector<InitDeclarator*>* vectorInitDeclarator) : declarationSpecifiers(declarationSpecifiers), vectorInitDeclarator(vectorInitDeclarator)
{
}

Declaration::~Declaration()
{
	delete declarationSpecifiers;
	if (vectorInitDeclarator != nullptr)
	{
		for (auto ptr : *vectorInitDeclarator)
		{
			delete ptr;
		}
	}
	delete vectorInitDeclarator;
}

Declaration::Declaration(const Declaration& other)
{
	declarationSpecifiers = other.declarationSpecifiers ? new DeclarationSpecifiers(*other.declarationSpecifiers) : nullptr;
	vectorInitDeclarator = other.vectorInitDeclarator ? new vector<InitDeclarator*>(*other.vectorInitDeclarator) : nullptr;
}

Declaration::Declaration(Declaration&& other) noexcept
{
	declarationSpecifiers = other.declarationSpecifiers ? new DeclarationSpecifiers(*other.declarationSpecifiers) : nullptr;
	vectorInitDeclarator = other.vectorInitDeclarator ? new vector<InitDeclarator*>(*other.vectorInitDeclarator) : nullptr;
}

Declaration& Declaration::operator=(const Declaration& other)
{
	if (this == &other)
		return *this;
	declarationSpecifiers = other.declarationSpecifiers ? new DeclarationSpecifiers(*other.declarationSpecifiers) : nullptr;
	vectorInitDeclarator = other.vectorInitDeclarator ? new vector<InitDeclarator*>(*other.vectorInitDeclarator) : nullptr;
	return *this;
}

Declaration& Declaration::operator=(Declaration&& other) noexcept
{
	if (this == &other)
		return *this;
	declarationSpecifiers = other.declarationSpecifiers ? new DeclarationSpecifiers(*other.declarationSpecifiers) : nullptr;
	vectorInitDeclarator = other.vectorInitDeclarator ? new vector<InitDeclarator*>(*other.vectorInitDeclarator) : nullptr;
	return *this;
}

DeclarationSpecifiers* Declaration::getDeclarationSpecifiers() const { return declarationSpecifiers; }
vector<InitDeclarator*>* Declaration::getVectorInitDeclarator() const { return vectorInitDeclarator; }
bool Declaration::isDeclarationSpecifiers() const { return declarationSpecifiers != nullptr;  }
bool Declaration::isVectorInitDeclarator() const { return vectorInitDeclarator != nullptr; }
bool Declaration::isStorageClassSpecifier() const { return isDeclarationSpecifiers() && getDeclarationSpecifiers()->getStorageClassSpecifier() != nullptr; }
StorageClassSpecifier* Declaration::getStorageClassSpecifier() const { return getDeclarationSpecifiers()->getStorageClassSpecifier(); }

bool Declaration::isTypedef() const
{
		if (isStorageClassSpecifier())
		{
			string keyword = getStorageClassSpecifier()->getType()->getKeywordName();
			return keyword == "typedef";
		}
	return false;
}

TokenType Declaration::getType() const
{
	auto declaration_specifiers = getDeclarationSpecifiers();
	if (declaration_specifiers != nullptr)
	{
		if (declaration_specifiers->getTypeSpecifier()->getType().has_value())
		{
			return declaration_specifiers->getTypeSpecifier()->getType().value();
		}
		else
		{
			if (declaration_specifiers->getTypeSpecifier()->getTypedefInfo() != nullptr)
			{
				auto temp = declaration_specifiers->getTypeSpecifier()->getTypedefInfo()->getDeclaration();
				return temp->getDeclarationSpecifiers()->getDeclarationSpecifiers()->getTypeSpecifier()->getType().value();
			}
		}
	}	return UNKNOWN;
}