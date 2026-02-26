#include "pch.h"
#include "DeclarationSpecifiers.h"

using namespace WadeSpace;

DeclarationSpecifiers::DeclarationSpecifiers(StorageClassSpecifier* const storageClassSpecifier,
                                             TypeSpecifier* const typeSpecifier,
                                             TypeQualifier* const typeQualifier,
                                             DeclarationSpecifiers* const declarationSpecifiers)
	: storageClassSpecifier(storageClassSpecifier),
	  typeSpecifier(typeSpecifier),
	  typeQualifier(typeQualifier),
	  declarationSpecifiers(declarationSpecifiers)
{
}

DeclarationSpecifiers::~DeclarationSpecifiers()
{
	delete storageClassSpecifier;
	delete typeSpecifier;
	delete typeQualifier;
	delete declarationSpecifiers;
}

DeclarationSpecifiers::DeclarationSpecifiers(const DeclarationSpecifiers& other)
{
	storageClassSpecifier = other.storageClassSpecifier ? new StorageClassSpecifier(*other.storageClassSpecifier) : nullptr;
	typeSpecifier = other.typeSpecifier ? new TypeSpecifier(*other.typeSpecifier) : nullptr;
	typeQualifier = other.typeQualifier ? new TypeQualifier(*other.typeQualifier) : nullptr;
	declarationSpecifiers = other.declarationSpecifiers ? new DeclarationSpecifiers(*other.declarationSpecifiers) : nullptr;
}

DeclarationSpecifiers::DeclarationSpecifiers(DeclarationSpecifiers&& other) noexcept
{
	storageClassSpecifier = other.storageClassSpecifier ? new StorageClassSpecifier(*other.storageClassSpecifier) : nullptr;
	typeSpecifier = other.typeSpecifier ? new TypeSpecifier(*other.typeSpecifier) : nullptr;
	typeQualifier = other.typeQualifier ? new TypeQualifier(*other.typeQualifier) : nullptr;
	declarationSpecifiers = other.declarationSpecifiers ? new DeclarationSpecifiers(*other.declarationSpecifiers) : nullptr;

}

DeclarationSpecifiers& DeclarationSpecifiers::operator=(const DeclarationSpecifiers& other)
{
	if (this == &other)
		return *this;
	storageClassSpecifier = other.storageClassSpecifier ? new StorageClassSpecifier(*other.storageClassSpecifier) : nullptr;
	typeSpecifier = other.typeSpecifier ? new TypeSpecifier(*other.typeSpecifier) : nullptr;
	typeQualifier = other.typeQualifier ? new TypeQualifier(*other.typeQualifier) : nullptr;
	declarationSpecifiers = other.declarationSpecifiers ? new DeclarationSpecifiers(*other.declarationSpecifiers) : nullptr;
	return *this;
}

DeclarationSpecifiers& DeclarationSpecifiers::operator=(DeclarationSpecifiers&& other) noexcept
{
	if (this == &other)
		return *this;
	storageClassSpecifier = other.storageClassSpecifier ? new StorageClassSpecifier(*other.storageClassSpecifier) : nullptr;
	typeSpecifier = other.typeSpecifier ? new TypeSpecifier(*other.typeSpecifier) : nullptr;
	typeQualifier = other.typeQualifier ? new TypeQualifier(*other.typeQualifier) : nullptr;
	declarationSpecifiers = other.declarationSpecifiers ? new DeclarationSpecifiers(*other.declarationSpecifiers) : nullptr;
	return *this;
}

StorageClassSpecifier* DeclarationSpecifiers::getStorageClassSpecifier() const
{
	return storageClassSpecifier;
}

TypeSpecifier* DeclarationSpecifiers::getTypeSpecifier() const
{
	return typeSpecifier;
}

TypeQualifier* DeclarationSpecifiers::getTypeQualifier() const
{
	return typeQualifier;
}

DeclarationSpecifiers* DeclarationSpecifiers::getDeclarationSpecifiers() const
{
	return declarationSpecifiers;
}

bool DeclarationSpecifiers::isStorageClassSpecifier() const
{
	return storageClassSpecifier != nullptr;
}

bool DeclarationSpecifiers::isTypeSpecifier() const
{
	return typeSpecifier != nullptr;
}

bool DeclarationSpecifiers::isTypeQualifier() const
{
	return typeQualifier != nullptr;
}

bool DeclarationSpecifiers::isDeclarationSpecifiers() const
{
	return declarationSpecifiers != nullptr;
}
