#pragma once

#include <string>
#include <vector>
#include <optional>
#include "TokenType.h"
#include "EnumSpecifier.h"

namespace WadeSpace
{
	class ExternalDeclaration;
	class StructOrUnionSpecifier;

	class TypeSpecifier
	{
	public:
		explicit TypeSpecifier(TokenType type, TokenPtr token, StructOrUnionSpecifier* structOrUnion, EnumSpecifier* enumSpec);
		TypeSpecifier();
		virtual ~TypeSpecifier();
		[[nodiscard]] EnumSpecifier* getEnumSpec() const;
		[[nodiscard]] optional<TokenType> getType() const;
		[[nodiscard]] StructOrUnionSpecifier* getStructOrUnionSpecifier() const;
		[[nodiscard]] TokenPtr getTypePtr() const;
		[[nodiscard]] ExternalDeclaration* getTypedefInfo() const;

		TypeSpecifier(const TypeSpecifier& other);
		TypeSpecifier(TypeSpecifier&& other) noexcept;
		TypeSpecifier& operator=(const TypeSpecifier& other);
		TypeSpecifier& operator=(TypeSpecifier&& other) noexcept;

	private:
		EnumSpecifier* enumSpec;
		optional<TokenType> type;
		TokenPtr typePtr;
		StructOrUnionSpecifier* structOrUnionSpecifier;
		ExternalDeclaration* typedefInfo;
	};
}
