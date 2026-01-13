#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TypeSpecifier.h"
#include "TypeQualifier.h"

namespace WadeSpace
{
	class SpecifierQualifierList
	{
	public:
		SpecifierQualifierList(SpecifierQualifierList* specifierQualifierList, TypeSpecifier* typeSpecifier);
		SpecifierQualifierList(TypeSpecifier* typeSpecifier);
		SpecifierQualifierList(SpecifierQualifierList* specifierQualifierList, TypeQualifier* typeQualifier);
		SpecifierQualifierList(TypeQualifier* typeQualifier);
		SpecifierQualifierList();
		virtual ~SpecifierQualifierList();
		SpecifierQualifierList* getSpecifierQualifierList() const;
		TypeSpecifier* getTypeSpecifier() const;
		TypeQualifier* getTypeQualifier() const;

	private:
		SpecifierQualifierList* specifierQualifierList;
		TypeSpecifier* typeSpecifier;
		TypeQualifier* typeQualifier;
	};
}
