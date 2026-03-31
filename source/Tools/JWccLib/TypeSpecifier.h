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
		explicit TypeSpecifier(TokenType type, CTokenPtr token, StructOrUnionSpecifier* structOrUnion, EnumSpecifier* enumSpec);
		virtual ~TypeSpecifier();

		TypeSpecifier(const TypeSpecifier& other) = default;
		TypeSpecifier(TypeSpecifier&& other) noexcept = default;
		TypeSpecifier& operator=(const TypeSpecifier& other)	= default;
		TypeSpecifier& operator=(TypeSpecifier&& other) noexcept = default;

		[[nodiscard]] EnumSpecifier* getEnumSpec() const;
		[[nodiscard]] optional<TokenType> getType() const;
		[[nodiscard]] StructOrUnionSpecifier* getStructOrUnionSpecifier() const;
		[[nodiscard]] CTokenPtr getTypePtr() const;
		[[nodiscard]] ExternalDeclaration* getTypedefInfo() const;

		void setType(const optional<TokenType>& type)
		{
			this->type = type;
		}

		[[nodiscard]] bool hasEnumSpec() const;
		[[nodiscard]] bool hasType() const;
		[[nodiscard]] bool hasStructOrUnionSpecifier() const;
		[[nodiscard]] bool hasTypePtr() const;
		[[nodiscard]] bool hasTypedefInfo() const;

	private:
		EnumSpecifier* enumSpec;
		optional<TokenType> type;
		CTokenPtr typePtr;
		StructOrUnionSpecifier* structOrUnionSpecifier;
		ExternalDeclaration* typedefInfo;
	};
}
