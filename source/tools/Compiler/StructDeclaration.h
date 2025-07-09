#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "SpecifierQualifierList.h"
#include "StructDeclarator.h"

namespace WadeSpace {
	class StructDeclaration
	{
	public:
		StructDeclaration(SpecifierQualifierList& sql, std::vector<StructDeclarator>& list);
		StructDeclaration();
		~StructDeclaration();
		SpecifierQualifierList& getSql() const;
		std::vector<StructDeclarator>& getList() const;
	private:
		std::optional < std::reference_wrapper < SpecifierQualifierList>> sql;
		std::optional < std::reference_wrapper < std::vector<StructDeclarator>>> list;
	};
}
