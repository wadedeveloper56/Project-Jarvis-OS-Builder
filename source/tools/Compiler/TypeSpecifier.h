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
		TypeSpecifier(EnumSpecifier* type);
		TypeSpecifier(StructOrUnionSpecifier* type);
		TypeSpecifier();
		virtual ~TypeSpecifier();
	private:
		EnumSpecifier* enumSpec;
		TokenType type;
		StructOrUnionSpecifier* suSpec;
	};
}
