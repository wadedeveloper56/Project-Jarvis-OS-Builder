#pragma once

#include "SpecifierQualifierList.h"
#include "AbstractDeclarator.h"

namespace WadeSpace
{
	class TypeName
	{
	public:
		TypeName();
		TypeName(SpecifierQualifierList* specifierQualifierList);
		TypeName(SpecifierQualifierList* specifierQualifierList, AbstractDeclarator* abstractDeclarator);
		virtual ~TypeName();

		TypeName(const TypeName& other);
		TypeName(TypeName&& other) noexcept;
		TypeName& operator=(const TypeName& other);
		TypeName& operator=(TypeName&& other) noexcept;

		[[nodiscard]] SpecifierQualifierList* getSpecifierQualifierList() const;
		[[nodiscard]] AbstractDeclarator* getAbstractDeclarator() const;

		[[nodiscard]] bool hasSpecifierQualifierList() const;
		[[nodiscard]] bool hasAbstractDeclarator() const;

	private:
		SpecifierQualifierList* specifierQualifierList;
		AbstractDeclarator* abstractDeclarator;
	};
}
