#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
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

	private:
		SpecifierQualifierList* specifierQualifierList;
		AbstractDeclarator* abstractDeclarator;
	};
}
