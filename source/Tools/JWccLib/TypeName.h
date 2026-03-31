#pragma once

#include "SpecifierQualifierList.h"
#include "AbstractDeclarator.h"

namespace WadeSpace
{
	class TypeName
	{
		SpecifierQualifierList* specifierQualifierList;
		AbstractDeclarator* abstractDeclarator;
	public:
		TypeName() = default;
		TypeName(SpecifierQualifierList* specifierQualifierList);
		TypeName(SpecifierQualifierList* specifierQualifierList, AbstractDeclarator* abstractDeclarator);
		virtual ~TypeName() = default;
		TypeName(const TypeName& other) = default;
		TypeName(TypeName&& other) noexcept = default;
		TypeName& operator=(const TypeName& other) = default;
		TypeName& operator=(TypeName&& other) noexcept = default;
		[[nodiscard]] SpecifierQualifierList* getSpecifierQualifierList() const { return specifierQualifierList; }
		[[nodiscard]] AbstractDeclarator* getAbstractDeclarator() const { return abstractDeclarator; }
		[[nodiscard]] bool hasSpecifierQualifierList() const { return specifierQualifierList != nullptr; }
		[[nodiscard]] bool hasAbstractDeclarator() const { return abstractDeclarator != nullptr; }
		void setSpecifierQualifierList(SpecifierQualifierList* specifierQualifierList) { this->specifierQualifierList = specifierQualifierList; }
		void setAbstractDeclarator(AbstractDeclarator* abstractDeclarator) { this->abstractDeclarator = abstractDeclarator; }

	};
}
