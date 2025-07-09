#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "StructOrUnion.h"
#include "StructDeclaration.h"

namespace WadeSpace {
	class StructOrUnionSpecifier
	{
	public:
		StructOrUnionSpecifier(StructOrUnion& su, std::string name, std::vector<StructDeclaration>& list);
		StructOrUnionSpecifier(StructOrUnion& su, std::vector<StructDeclaration>& list);
		StructOrUnionSpecifier(StructOrUnion& su, std::string name);
		StructOrUnionSpecifier();
		~StructOrUnionSpecifier();
		std::string getName() const;
		StructOrUnion& getSu() const;
		std::vector<StructDeclaration>& getList() const;
	private:
		std::string name;
		std::optional < std::reference_wrapper < StructOrUnion>> su;
		std::optional < std::reference_wrapper < std::vector<StructDeclaration>>> list;
	};
}
