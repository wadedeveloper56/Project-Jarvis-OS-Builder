#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TypeSpecifier.h"
#include "TypeQualifier.h"

namespace WadeSpace {
	class SpecifierQualifierList
	{
	public:
		SpecifierQualifierList(SpecifierQualifierList* sql, TypeSpecifier* ts);
		SpecifierQualifierList(TypeSpecifier* ts);
		SpecifierQualifierList(SpecifierQualifierList* sql, TypeQualifier* ts);
		SpecifierQualifierList(TypeQualifier* ts);
		SpecifierQualifierList();
		~SpecifierQualifierList();
	private:
		SpecifierQualifierList* sql;
		TypeSpecifier* ts;
		TypeQualifier* tq;
	};
}
