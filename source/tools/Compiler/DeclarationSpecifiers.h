#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include "StorageClassSpecifier.h"
#include "TypeSpecifier.h"
#include "TypeQualifier.h"

namespace WadeSpace {
	class DeclarationSpecifiers
	{
	public:
		DeclarationSpecifiers(std::string name, StorageClassSpecifier* scs, TypeSpecifier* ts, DeclarationSpecifiers* ds, TypeQualifier* tq);
		DeclarationSpecifiers();
		~DeclarationSpecifiers();

		std::string getName() const;
		StorageClassSpecifier* getScs() const;
		TypeSpecifier* getTs() const;
		DeclarationSpecifiers* getDs() const;
		TypeQualifier* getTq() const;
	private:
		std::string name;
		StorageClassSpecifier* scs;
		TypeSpecifier* ts;
		TypeQualifier* tq;
		DeclarationSpecifiers* ds;
	};
}
