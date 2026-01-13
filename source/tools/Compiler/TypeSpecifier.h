#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "EnumSpecifier.h"

namespace WadeSpace
{
	class StructOrUnionSpecifier;

	class TypeSpecifier
	{
	public:
		TypeSpecifier(TokenType type);
		TypeSpecifier(EnumSpecifier* type);
		TypeSpecifier(StructOrUnionSpecifier* type);
		TypeSpecifier();
		virtual ~TypeSpecifier();
		EnumSpecifier* getEnumSpec() const;
		TokenType getType() const;
		StructOrUnionSpecifier* getSuSpec() const;

	private:
		EnumSpecifier* enumSpec;
		TokenType type;
		StructOrUnionSpecifier* suSpec;
	};
}
