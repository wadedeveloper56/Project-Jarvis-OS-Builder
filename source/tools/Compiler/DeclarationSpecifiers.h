#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "StorageClassSpecifier.h"
#include "TypeSpecifier.h"
#include "TypeQualifier.h"

namespace WadeSpace {
	class DeclarationSpecifiers
	{
	public:
		DeclarationSpecifiers(TypeQualifier* tq, DeclarationSpecifiers* ds);
		DeclarationSpecifiers(TypeQualifier* tq);
		DeclarationSpecifiers(TypeSpecifier* ts, DeclarationSpecifiers* ds);
		DeclarationSpecifiers(TypeSpecifier* ts);
		DeclarationSpecifiers(StorageClassSpecifier* scs);
		DeclarationSpecifiers(StorageClassSpecifier* scs, DeclarationSpecifiers* ds);
		DeclarationSpecifiers();
		virtual ~DeclarationSpecifiers();
		StorageClassSpecifier* getStorageClassSpecifier() const;
		TypeSpecifier* getTypeSpecifier() const;
		TypeQualifier* getTypeQualifier() const;
		DeclarationSpecifiers* getDeclarationSpecifiers() const;
	private:
		StorageClassSpecifier* scs;
		TypeSpecifier* ts;
		TypeQualifier* tq;
		DeclarationSpecifiers* ds;
	};
}
