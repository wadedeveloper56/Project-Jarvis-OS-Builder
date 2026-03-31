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
		EnumSpecifier* enumSpec;
		optional<TokenType> type;
		CTokenPtr typePtr;
		StructOrUnionSpecifier* structOrUnionSpecifier;
		ExternalDeclaration* typedefInfo;
	public:
		TypeSpecifier() = default;
		TypeSpecifier(TokenType type, CTokenPtr token, StructOrUnionSpecifier* structOrUnion, EnumSpecifier* enumSpec, ExternalDeclaration* extDecl);
		virtual ~TypeSpecifier() = default;
		TypeSpecifier(const TypeSpecifier& other) = default;
		TypeSpecifier(TypeSpecifier&& other) noexcept = default;
		TypeSpecifier& operator=(const TypeSpecifier& other)	= default;
		TypeSpecifier& operator=(TypeSpecifier&& other) noexcept = default;
		[[nodiscard]] optional<TokenType> getType() const { return type; }
		[[nodiscard]] CTokenPtr getTypePtr() const { return typePtr; }
		[[nodiscard]] EnumSpecifier* getEnumSpec() const { return enumSpec; }
		[[nodiscard]] StructOrUnionSpecifier* getStructOrUnionSpecifier() const { return structOrUnionSpecifier; }
		[[nodiscard]] ExternalDeclaration* getTypedefInfo() const { return typedefInfo; }
		[[nodiscard]] bool hasType() const { return type.has_value(); }
		[[nodiscard]] bool hasTypePtr() const { return typePtr != nullptr; }
		[[nodiscard]] bool hasEnumSpec() const { return enumSpec != nullptr; }
		[[nodiscard]] bool hasStructOrUnionSpecifier() const { return structOrUnionSpecifier != nullptr; }
		[[nodiscard]] bool hasTypedefInfo() const { return typedefInfo != nullptr; }
		void setType(optional<TokenType> type) { this->type = type; }
		void setTypePtr(CTokenPtr typePtr) { this->typePtr = typePtr; }
		void setEnumSpec(EnumSpecifier* enumSpec) { this->enumSpec = enumSpec; }
		void setStructOrUnionSpecifier(StructOrUnionSpecifier* structOrUnionSpecifier) { this->structOrUnionSpecifier = structOrUnionSpecifier; }
		void setTypedefInfo(ExternalDeclaration* typedefInfo) { this->typedefInfo = typedefInfo; }
	};
}
