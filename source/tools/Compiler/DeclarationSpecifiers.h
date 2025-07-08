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
		DeclarationSpecifiers(TypeQualifier& tq, DeclarationSpecifiers& ds);
		DeclarationSpecifiers(TypeQualifier& tq);
		DeclarationSpecifiers(TypeSpecifier& ts, DeclarationSpecifiers& ds);
		DeclarationSpecifiers(TypeSpecifier& ts);
		DeclarationSpecifiers(StorageClassSpecifier& scs);
		DeclarationSpecifiers(StorageClassSpecifier& scs, DeclarationSpecifiers& ds);
		DeclarationSpecifiers();
		~DeclarationSpecifiers();

		StorageClassSpecifier& getScs() const;
		TypeSpecifier& getTs() const;
		DeclarationSpecifiers& getDs() const;
		TypeQualifier& getTq() const;
	private:
		std::optional < std::reference_wrapper < StorageClassSpecifier>> scs;
		std::optional < std::reference_wrapper < TypeSpecifier>> ts;
		std::optional < std::reference_wrapper < TypeQualifier>> tq;
		std::optional < std::reference_wrapper < DeclarationSpecifiers>> ds;
	};
}
