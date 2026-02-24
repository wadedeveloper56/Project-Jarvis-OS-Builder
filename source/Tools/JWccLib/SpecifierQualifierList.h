#pragma once

#include <string>
#include <vector>
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
		SpecifierQualifierList(const SpecifierQualifierList& other);
		SpecifierQualifierList(SpecifierQualifierList&& other) noexcept;
		SpecifierQualifierList& operator=(const SpecifierQualifierList& other);
		SpecifierQualifierList& operator=(SpecifierQualifierList&& other) noexcept;
		SpecifierQualifierList* getSpecifierQualifierList() const;
		TypeSpecifier* getTypeSpecifier() const;
		TypeQualifier* getTypeQualifier() const;

	private:
		SpecifierQualifierList* specifierQualifierList;
		TypeSpecifier* typeSpecifier;
		TypeQualifier* typeQualifier;
	};
}
