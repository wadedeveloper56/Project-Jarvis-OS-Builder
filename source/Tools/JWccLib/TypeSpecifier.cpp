#include "pch.h"
#include "TypeSpecifier.h"
#include "GlobalVars.h"
#include "StructOrUnionSpecifier.h"
#include "ExternalDeclaration.h"

using namespace WadeSpace;

TypeSpecifier::TypeSpecifier(TokenType type, TokenPtr token, StructOrUnionSpecifier* structOrUnion, EnumSpecifier* enumSpec) 
                                 : type(type), enumSpec(enumSpec), structOrUnionSpecifier(structOrUnion), typePtr(token)
{
	if (token != nullptr)
	{
		string keyword = token->getSymbolName();
		typedefInfo = nullptr;
		if (typedefList != nullptr)
		{
			auto typedefEntry = typedefList->find(keyword);
			if (typedefEntry != typedefList->end())
			{
				typedefInfo = typedefEntry->second;
			}
		}
	}
	if (structOrUnion != nullptr)
	{
		auto struct_or_union = structOrUnion->getStructOrUnion();
		this->setType(struct_or_union->getKeywordName() == "struct" ? STRUCT : UNION);
	}
}

TypeSpecifier::TypeSpecifier() : type(nullopt), enumSpec(nullptr), structOrUnionSpecifier(nullptr), typePtr(nullptr),
                                 typedefInfo(nullptr)
{
}

TypeSpecifier::~TypeSpecifier()
{
	delete enumSpec;
	delete structOrUnionSpecifier;
	delete typedefInfo;
	delete typePtr;
}

EnumSpecifier* TypeSpecifier::getEnumSpec() const
{
	return enumSpec;
}

optional<TokenType> TypeSpecifier::getType() const
{
	return type;
}

StructOrUnionSpecifier* TypeSpecifier::getStructOrUnionSpecifier() const
{
	return structOrUnionSpecifier;
}

TokenPtr TypeSpecifier::getTypePtr() const
{
	return typePtr;
}

ExternalDeclaration* TypeSpecifier::getTypedefInfo() const
{
	return typedefInfo;
}

TypeSpecifier::TypeSpecifier(const TypeSpecifier& other)
{
	enumSpec = other.enumSpec ? new EnumSpecifier(*other.enumSpec) : nullptr;
	type = std::move(other.type);
	typePtr = other.typePtr ? new Token(*other.typePtr) : nullptr;
	structOrUnionSpecifier = other.structOrUnionSpecifier
		                         ? new StructOrUnionSpecifier(*other.structOrUnionSpecifier)
		                         : nullptr;
	typedefInfo = other.typedefInfo ? new ExternalDeclaration(*other.typedefInfo) : nullptr;
}

TypeSpecifier::TypeSpecifier(TypeSpecifier&& other) noexcept
{
	enumSpec = other.enumSpec ? new EnumSpecifier(*other.enumSpec) : nullptr;
	type = std::move(other.type);
	typePtr = other.typePtr ? new Token(*other.typePtr) : nullptr;
	structOrUnionSpecifier = other.structOrUnionSpecifier
		                         ? new StructOrUnionSpecifier(*other.structOrUnionSpecifier)
		                         : nullptr;
	typedefInfo = other.typedefInfo ? new ExternalDeclaration(*other.typedefInfo) : nullptr;
}

TypeSpecifier& TypeSpecifier::operator=(const TypeSpecifier& other)
{
	if (this == &other)
		return *this;
	enumSpec = other.enumSpec ? new EnumSpecifier(*other.enumSpec) : nullptr;
	type = std::move(other.type);
	typePtr = other.typePtr ? new Token(*other.typePtr) : nullptr;
	structOrUnionSpecifier = other.structOrUnionSpecifier
		                         ? new StructOrUnionSpecifier(*other.structOrUnionSpecifier)
		                         : nullptr;
	typedefInfo = other.typedefInfo ? new ExternalDeclaration(*other.typedefInfo) : nullptr;
	return *this;
}

TypeSpecifier& TypeSpecifier::operator=(TypeSpecifier&& other) noexcept
{
	if (this == &other)
		return *this;
	enumSpec = other.enumSpec ? new EnumSpecifier(*other.enumSpec) : nullptr;
	type = std::move(other.type);
	typePtr = other.typePtr ? new Token(*other.typePtr) : nullptr;
	structOrUnionSpecifier = other.structOrUnionSpecifier
		                         ? new StructOrUnionSpecifier(*other.structOrUnionSpecifier)
		                         : nullptr;
	typedefInfo = other.typedefInfo ? new ExternalDeclaration(*other.typedefInfo) : nullptr;
	return *this;
}

bool TypeSpecifier::hasEnumSpec() const
{
	return enumSpec != nullptr;
}

bool TypeSpecifier::hasType() const
{
	return type.has_value();
}

bool TypeSpecifier::hasStructOrUnionSpecifier() const
{
	return structOrUnionSpecifier != nullptr;
}

bool TypeSpecifier::hasTypePtr() const
{
	return typePtr != nullptr;
}

bool TypeSpecifier::hasTypedefInfo() const
{
	return typedefInfo != nullptr;
}

