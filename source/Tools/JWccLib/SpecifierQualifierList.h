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
		SpecifierQualifierList();
		SpecifierQualifierList(SpecifierQualifierList* specifierQualifierList, TypeSpecifier* typeSpecifier);
		SpecifierQualifierList(TypeSpecifier* typeSpecifier);
		SpecifierQualifierList(SpecifierQualifierList* specifierQualifierList, TypeQualifier* typeQualifier);
		SpecifierQualifierList(TypeQualifier* typeQualifier);
		virtual ~SpecifierQualifierList();

		SpecifierQualifierList(const SpecifierQualifierList& other);
		SpecifierQualifierList(SpecifierQualifierList&& other) noexcept;
		SpecifierQualifierList& operator=(const SpecifierQualifierList& other);
		SpecifierQualifierList& operator=(SpecifierQualifierList&& other) noexcept;

		[[nodiscard]] SpecifierQualifierList* getSpecifierQualifierList() const;
		[[nodiscard]] TypeSpecifier* getTypeSpecifier() const;
		[[nodiscard]] TypeQualifier* getTypeQualifier() const;

		[[nodiscard]] bool hasSpecifierQualifierList() const;
		[[nodiscard]] bool hasTypeSpecifier() const;
		[[nodiscard]] bool hasTypeQualifier() const;

	private:
		SpecifierQualifierList* specifierQualifierList;
		TypeSpecifier* typeSpecifier;
		TypeQualifier* typeQualifier;
	};
}
