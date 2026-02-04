#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "StorageClassSpecifier.h"
#include "TypeSpecifier.h"
#include "TypeQualifier.h"

namespace WadeSpace
{
	class DeclarationSpecifiers
	{
	public:
		DeclarationSpecifiers(TypeQualifier* typeQualifier, DeclarationSpecifiers* declarationSpecifiers);
		DeclarationSpecifiers(TypeQualifier* typeQualifier);
		DeclarationSpecifiers(TypeSpecifier* typeSpecifier, DeclarationSpecifiers* declarationSpecifiers);
		DeclarationSpecifiers(TypeSpecifier* typeSpecifier);
		DeclarationSpecifiers(StorageClassSpecifier* storageClassSpecifier);
		DeclarationSpecifiers(StorageClassSpecifier* storageClassSpecifier, DeclarationSpecifiers* declarationSpecifiers);
		DeclarationSpecifiers();
		virtual ~DeclarationSpecifiers();
		StorageClassSpecifier* getStorageClassSpecifier() const;
		TypeSpecifier* getTypeSpecifier() const;
		TypeQualifier* getTypeQualifier() const;
		DeclarationSpecifiers* getDeclarationSpecifiers() const;

	private:
		StorageClassSpecifier* storageClassSpecifier;
		TypeSpecifier* typeSpecifier;
		TypeQualifier* typeQualifier;
		DeclarationSpecifiers* declarationSpecifiers;
	};
}
