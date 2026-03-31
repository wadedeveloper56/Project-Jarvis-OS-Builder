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
		SpecifierQualifierList* specifierQualifierList;
		TypeSpecifier* typeSpecifier;
		TypeQualifier* typeQualifier;
	public:
		SpecifierQualifierList() = default;
		SpecifierQualifierList(SpecifierQualifierList* specifierQualifierList, TypeSpecifier* typeSpecifier);
		SpecifierQualifierList(TypeSpecifier* typeSpecifier);
		SpecifierQualifierList(SpecifierQualifierList* specifierQualifierList, TypeQualifier* typeQualifier);
		SpecifierQualifierList(TypeQualifier* typeQualifier);
		virtual ~SpecifierQualifierList() = default;
		SpecifierQualifierList(const SpecifierQualifierList& other) = default;
		SpecifierQualifierList(SpecifierQualifierList&& other) noexcept = default;
		SpecifierQualifierList& operator=(const SpecifierQualifierList& other) = default;
		SpecifierQualifierList& operator=(SpecifierQualifierList&& other) noexcept = default;
		[[nodiscard]] SpecifierQualifierList* getSpecifierQualifierList() const { return specifierQualifierList; }
		[[nodiscard]] TypeSpecifier* getTypeSpecifier() const { return typeSpecifier; }
		[[nodiscard]] TypeQualifier* getTypeQualifier() const { return typeQualifier; }
		void setSpecifierQualifierList(SpecifierQualifierList* specifierQualifierList) { this->specifierQualifierList = specifierQualifierList; }
		void setTypeSpecifier(TypeSpecifier* typeSpecifier) { this->typeSpecifier = typeSpecifier; }
		void setTypeQualifier(TypeQualifier* typeQualifier) { this->typeQualifier = typeQualifier; }
		bool hasSpecifierQualifierList() const { return specifierQualifierList != nullptr; }
		bool hasTypeSpecifier() const { return typeSpecifier != nullptr; }
		bool hasTypeQualifier() const { return typeQualifier != nullptr; }
	};
}
