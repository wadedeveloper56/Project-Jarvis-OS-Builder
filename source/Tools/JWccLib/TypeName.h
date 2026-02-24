#pragma once

#include "SpecifierQualifierList.h"
#include "AbstractDeclarator.h"

namespace WadeSpace
{
	class TypeName
	{
	public:
		TypeName(SpecifierQualifierList* specifierQualifierList);
		TypeName(SpecifierQualifierList* specifierQualifierList, AbstractDeclarator* abstractDeclarator);
		TypeName();
		virtual ~TypeName();
		SpecifierQualifierList* getSpecifierQualifierList() const;
		AbstractDeclarator* getAbstractDeclarator() const;
		TypeName(const TypeName& other);
		TypeName(TypeName&& other) noexcept;
		TypeName& operator=(const TypeName& other);
		TypeName& operator=(TypeName&& other) noexcept;

	private:
		SpecifierQualifierList* specifierQualifierList;
		AbstractDeclarator* abstractDeclarator;
	};
}
