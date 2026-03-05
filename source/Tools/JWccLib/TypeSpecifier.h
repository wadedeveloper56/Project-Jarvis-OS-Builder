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
		TypeSpecifier();
		explicit TypeSpecifier(TokenType type, TokenPtr token, StructOrUnionSpecifier* structOrUnion, EnumSpecifier* enumSpec);
		virtual ~TypeSpecifier();

		TypeSpecifier(const TypeSpecifier& other);
		TypeSpecifier(TypeSpecifier&& other) noexcept;
		TypeSpecifier& operator=(const TypeSpecifier& other);
		TypeSpecifier& operator=(TypeSpecifier&& other) noexcept;

		[[nodiscard]] EnumSpecifier* getEnumSpec() const;
		[[nodiscard]] optional<TokenType> getType() const;
		[[nodiscard]] StructOrUnionSpecifier* getStructOrUnionSpecifier() const;
		[[nodiscard]] TokenPtr getTypePtr() const;
		[[nodiscard]] ExternalDeclaration* getTypedefInfo() const;

		[[nodiscard]] bool hasEnumSpec() const;
		[[nodiscard]] bool hasType() const;
		[[nodiscard]] bool hasStructOrUnionSpecifier() const;
		[[nodiscard]] bool hasTypePtr() const;
		[[nodiscard]] bool hasTypedefInfo() const;

	private:
		EnumSpecifier* enumSpec;
		optional<TokenType> type;
		TokenPtr typePtr;
		StructOrUnionSpecifier* structOrUnionSpecifier;
		ExternalDeclaration* typedefInfo;
	};
}
