#include "DeclarationSpecifiers.h"

using namespace WadeSpace;

DeclarationSpecifiers::DeclarationSpecifiers(TypeQualifier* typeQualifier, DeclarationSpecifiers* declarationSpecifiers) : storageClassSpecifier(nullptr), typeSpecifier(nullptr), declarationSpecifiers(declarationSpecifiers), typeQualifier(typeQualifier)
{
}

DeclarationSpecifiers::DeclarationSpecifiers(TypeQualifier* typeQualifier) : storageClassSpecifier(nullptr), typeSpecifier(nullptr), declarationSpecifiers(nullptr), typeQualifier(typeQualifier)
{
}

DeclarationSpecifiers::DeclarationSpecifiers(TypeSpecifier* typeSpecifier, DeclarationSpecifiers* declarationSpecifiers) : storageClassSpecifier(nullptr), typeSpecifier(typeSpecifier), declarationSpecifiers(declarationSpecifiers), typeQualifier(nullptr)
{
}

DeclarationSpecifiers::DeclarationSpecifiers(TypeSpecifier* typeSpecifier) : storageClassSpecifier(nullptr), typeSpecifier(typeSpecifier), declarationSpecifiers(nullptr), typeQualifier(nullptr)
{
}

DeclarationSpecifiers::DeclarationSpecifiers(StorageClassSpecifier* storageClassSpecifier, DeclarationSpecifiers* declarationSpecifiers) : storageClassSpecifier(storageClassSpecifier), typeSpecifier(nullptr), declarationSpecifiers(declarationSpecifiers), typeQualifier(nullptr)
{
}

DeclarationSpecifiers::DeclarationSpecifiers(StorageClassSpecifier* storageClassSpecifier) : storageClassSpecifier(storageClassSpecifier), typeSpecifier(nullptr), declarationSpecifiers(nullptr), typeQualifier(nullptr)
{
}

DeclarationSpecifiers::DeclarationSpecifiers() : storageClassSpecifier(nullptr), typeSpecifier(nullptr), declarationSpecifiers(nullptr), typeQualifier(nullptr)
{
}

DeclarationSpecifiers::~DeclarationSpecifiers()
{
	delete storageClassSpecifier;
	delete typeSpecifier;
	delete typeQualifier;
	delete declarationSpecifiers;
}

StorageClassSpecifier* DeclarationSpecifiers::getStorageClassSpecifier() const { return storageClassSpecifier; }
TypeSpecifier* DeclarationSpecifiers::getTypeSpecifier() const { return typeSpecifier; }
TypeQualifier* DeclarationSpecifiers::getTypeQualifier() const { return typeQualifier; }
DeclarationSpecifiers* DeclarationSpecifiers::getDeclarationSpecifiers() const { return declarationSpecifiers; }
