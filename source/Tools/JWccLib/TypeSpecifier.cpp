#include "pch.h"
#include "TypeSpecifier.h"
#include "GlobalVars.h"
#include "StructOrUnionSpecifier.h"
#include "ExternalDeclaration.h"

using namespace WadeSpace;

TypeSpecifier::TypeSpecifier(TokenPtr type) : type(nullopt), enumSpec(nullptr), suSpec(nullptr), typePtr(type)
{
	string keyword = type->getSymbolName();
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

TypeSpecifier::TypeSpecifier(TokenType type) : type(type), enumSpec(nullptr), suSpec(nullptr), typePtr(nullptr), typedefInfo(nullptr)
{
}

TypeSpecifier::TypeSpecifier(EnumSpecifier* type) : type(nullopt), enumSpec(type), suSpec(nullptr), typePtr(nullptr), typedefInfo(nullptr)
{
}

TypeSpecifier::TypeSpecifier(StructOrUnionSpecifier* type) : type(nullopt), enumSpec(nullptr), suSpec(type), typePtr(nullptr), typedefInfo(nullptr)
{
}

TypeSpecifier::TypeSpecifier() : type(nullopt), enumSpec(nullptr), suSpec(nullptr), typePtr(nullptr), typedefInfo(nullptr)
{
}

TypeSpecifier::~TypeSpecifier()
{
	delete enumSpec;
	delete suSpec;
	delete typedefInfo;
	delete typePtr;
}

EnumSpecifier* TypeSpecifier::getEnumSpec() const { return enumSpec; }
optional<TokenType> TypeSpecifier::getType() const { return type; }
StructOrUnionSpecifier* TypeSpecifier::getSuSpec() const { return suSpec; }
TokenPtr TypeSpecifier::getTypePtr() const { return typePtr; }
ExternalDeclaration* TypeSpecifier::getTypedefInfo() const { return typedefInfo; }

TypeSpecifier::TypeSpecifier(const TypeSpecifier& other)
{
	delete enumSpec;
	delete suSpec;
	delete typedefInfo;
	delete typePtr;
	enumSpec = other.enumSpec ? new EnumSpecifier(*other.enumSpec) : nullptr;
	type = std::move(other.type);
	typePtr = other.typePtr ? new Token(*other.typePtr) : nullptr;
	suSpec = other.suSpec ? new StructOrUnionSpecifier(*other.suSpec) : nullptr;
	typedefInfo = other.typedefInfo ? new ExternalDeclaration(*other.typedefInfo) : nullptr;
}

TypeSpecifier::TypeSpecifier(TypeSpecifier&& other) noexcept
{
	delete enumSpec;
	delete suSpec;
	delete typedefInfo;
	delete typePtr;
	enumSpec = other.enumSpec ? new EnumSpecifier(*other.enumSpec) : nullptr;
	type = std::move(other.type);
	typePtr = other.typePtr ? new Token(*other.typePtr) : nullptr;
	suSpec = other.suSpec ? new StructOrUnionSpecifier(*other.suSpec) : nullptr;
	typedefInfo = other.typedefInfo ? new ExternalDeclaration(*other.typedefInfo) : nullptr;
}

TypeSpecifier& TypeSpecifier::operator=(const TypeSpecifier& other)
{
	if (this == &other)
		return *this;
	delete enumSpec;
	delete suSpec;
	delete typedefInfo;
	delete typePtr;
	enumSpec = other.enumSpec ? new EnumSpecifier(*other.enumSpec) : nullptr;
	type = std::move(other.type);
	typePtr = other.typePtr ? new Token(*other.typePtr) : nullptr;
	suSpec = other.suSpec ? new StructOrUnionSpecifier(*other.suSpec) : nullptr;
	typedefInfo = other.typedefInfo ? new ExternalDeclaration(*other.typedefInfo) : nullptr;
	return *this;
}

TypeSpecifier& TypeSpecifier::operator=(TypeSpecifier&& other) noexcept
{
	if (this == &other)
		return *this;
	delete enumSpec;
	delete suSpec;
	delete typedefInfo;
	delete typePtr;
	enumSpec = other.enumSpec ? new EnumSpecifier(*other.enumSpec) : nullptr;
	type = std::move(other.type);
	typePtr = other.typePtr ? new Token(*other.typePtr) : nullptr;
	suSpec = other.suSpec ? new StructOrUnionSpecifier(*other.suSpec) : nullptr;
	typedefInfo = other.typedefInfo ? new ExternalDeclaration(*other.typedefInfo) : nullptr;
	return *this;
}