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
		TypeName(SpecifierQualifierList& sql);
		TypeName(SpecifierQualifierList& sql, AbstractDeclarator& ad);
		TypeName();
		~TypeName();
	private:
		std::optional < std::reference_wrapper < SpecifierQualifierList>> sql;
		std::optional < std::reference_wrapper < AbstractDeclarator>> ad;
	};
}
