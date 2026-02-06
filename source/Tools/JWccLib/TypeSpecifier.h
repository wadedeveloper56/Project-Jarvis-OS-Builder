#pragma once

#include <string>
#include <vector>
#include <optional>
#include "TokenType.h"
#include "EnumSpecifier.h"

namespace WadeSpace
{
	class StructOrUnionSpecifier;

	class TypeSpecifier
	{
	public:
		explicit TypeSpecifier(TokenType type);
		explicit TypeSpecifier(EnumSpecifier* type);
		explicit TypeSpecifier(StructOrUnionSpecifier* type);
		TypeSpecifier();
		virtual ~TypeSpecifier();
		[[nodiscard]] EnumSpecifier* getEnumSpec() const;
		[[nodiscard]] optional<TokenType> getType() const;
		[[nodiscard]] StructOrUnionSpecifier* getSuSpec() const;

	private:
		EnumSpecifier* enumSpec;
		optional<TokenType> type;
		StructOrUnionSpecifier* suSpec;
	};
}
