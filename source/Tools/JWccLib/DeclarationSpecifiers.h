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
		DeclarationSpecifiers(const DeclarationSpecifiers& other);
		DeclarationSpecifiers(DeclarationSpecifiers&& other) noexcept;
		DeclarationSpecifiers& operator=(const DeclarationSpecifiers& other);  
		DeclarationSpecifiers& operator=(DeclarationSpecifiers&& other) noexcept;
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
