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
