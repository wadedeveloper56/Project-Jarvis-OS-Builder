#pragma once

#include "StorageClassSpecifier.h"
#include "TypeSpecifier.h"
#include "TypeQualifier.h"

namespace WadeSpace
{
	class DeclarationSpecifiers
	{
	public:
		DeclarationSpecifiers() = default;
		DeclarationSpecifiers(StorageClassSpecifier* const storageClassSpecifier, TypeSpecifier* const typeSpecifier, TypeQualifier* const typeQualifier, DeclarationSpecifiers* const declarationSpecifiers);
		virtual ~DeclarationSpecifiers();

		DeclarationSpecifiers(const DeclarationSpecifiers& other)
			: storageClassSpecifier(new StorageClassSpecifier(*other.storageClassSpecifier)),
			  typeSpecifier(new TypeSpecifier(*other.typeSpecifier)),
			  typeQualifier(new TypeQualifier(*other.typeQualifier)),
			  declarationSpecifiers(new DeclarationSpecifiers(*other.declarationSpecifiers))
		{
		}

		DeclarationSpecifiers(DeclarationSpecifiers&& other) noexcept
			: storageClassSpecifier(new StorageClassSpecifier(*other.storageClassSpecifier)),
			  typeSpecifier(new TypeSpecifier(*other.typeSpecifier)),
			  typeQualifier(new TypeQualifier(*other.typeQualifier)),
			  declarationSpecifiers(new DeclarationSpecifiers(*other.declarationSpecifiers))
		{
		}

		DeclarationSpecifiers& operator=(const DeclarationSpecifiers& other)
		{
			if (this == &other)
				return *this;
			storageClassSpecifier = new StorageClassSpecifier(*other.storageClassSpecifier);
			typeSpecifier = new TypeSpecifier(*other.typeSpecifier);
			typeQualifier = new TypeQualifier(*other.typeQualifier);
			declarationSpecifiers = new DeclarationSpecifiers(*other.declarationSpecifiers);
			return *this;
		}

		DeclarationSpecifiers& operator=(DeclarationSpecifiers&& other) noexcept
		{
			if (this == &other)
				return *this;
			storageClassSpecifier = new StorageClassSpecifier(*other.storageClassSpecifier);
			typeSpecifier = new TypeSpecifier(*other.typeSpecifier);
			typeQualifier = new TypeQualifier(*other.typeQualifier);
			declarationSpecifiers = new DeclarationSpecifiers(*other.declarationSpecifiers);
			return *this;
		}

		[[nodiscard]] StorageClassSpecifier* getStorageClassSpecifier() const;
		[[nodiscard]] TypeSpecifier* getTypeSpecifier() const;
		[[nodiscard]] TypeQualifier* getTypeQualifier() const;
		[[nodiscard]] DeclarationSpecifiers* getDeclarationSpecifiers() const;

		[[nodiscard]] bool isStorageClassSpecifier() const;
		[[nodiscard]] bool isTypeSpecifier() const;
		[[nodiscard]] bool isTypeQualifier() const;
		[[nodiscard]] bool isDeclarationSpecifiers() const;

	private:
		StorageClassSpecifier* storageClassSpecifier;
		TypeSpecifier* typeSpecifier;
		TypeQualifier* typeQualifier;
		DeclarationSpecifiers* declarationSpecifiers;
	};
}
