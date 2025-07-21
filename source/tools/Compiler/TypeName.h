#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "SpecifierQualifierList.h"
#include "AbstractDeclarator.h"

namespace WadeSpace {
	class TypeName
	{
	public:
		TypeName(SpecifierQualifierList* sql);
		TypeName(SpecifierQualifierList* sql, AbstractDeclarator* ad);
		TypeName();
		virtual ~TypeName();
	private:
		SpecifierQualifierList* sql;
		AbstractDeclarator* ad;
	};
}
