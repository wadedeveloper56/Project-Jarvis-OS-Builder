#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "EnumSpecifier.h"

namespace WadeSpace {
	class StructOrUnionSpecifier;

	class TypeSpecifier
	{
	public:
		TypeSpecifier(TokenType type);
		TypeSpecifier(EnumSpecifier& type);
		TypeSpecifier(StructOrUnionSpecifier& type);
		TypeSpecifier();
		~TypeSpecifier();
	private:
		std::optional < std::reference_wrapper < EnumSpecifier>> enumSpec;
		TokenType type;
		std::optional < std::reference_wrapper < StructOrUnionSpecifier>> suSpec;
	};
}
