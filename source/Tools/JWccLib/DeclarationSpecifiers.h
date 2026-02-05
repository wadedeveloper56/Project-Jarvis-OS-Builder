#pragma once

#include <string>
#include <vector>
#include <optional>
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
		DeclarationSpecifiers(TypeQualifier* typeQualifier, DeclarationSpecifiers* declarationSpecifiers);
		explicit DeclarationSpecifiers(TypeQualifier* typeQualifier);
		DeclarationSpecifiers(TypeSpecifier* typeSpecifier, DeclarationSpecifiers* declarationSpecifiers);
		explicit DeclarationSpecifiers(TypeSpecifier* typeSpecifier);
		explicit DeclarationSpecifiers(StorageClassSpecifier* storageClassSpecifier);
		DeclarationSpecifiers(StorageClassSpecifier* storageClassSpecifier, DeclarationSpecifiers* declarationSpecifiers);
		virtual ~DeclarationSpecifiers();
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
