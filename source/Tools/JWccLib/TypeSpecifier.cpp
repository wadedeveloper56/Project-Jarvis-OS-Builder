#include "pch.h"
#include "TypeSpecifier.h"
#include "StructOrUnionSpecifier.h"

using namespace WadeSpace;

TypeSpecifier::TypeSpecifier(TokenType type) : type(type), enumSpec(nullptr), suSpec(nullptr)
{
}

TypeSpecifier::TypeSpecifier(EnumSpecifier* type) : type(nullopt), enumSpec(type), suSpec(nullptr)
{
}

TypeSpecifier::TypeSpecifier(StructOrUnionSpecifier* type) : type(nullopt), enumSpec(nullptr), suSpec(type)
{
}

TypeSpecifier::TypeSpecifier() : type(nullopt), enumSpec(nullptr), suSpec(nullptr)
{
}

TypeSpecifier::~TypeSpecifier()
{
	delete enumSpec;
	delete suSpec;
}

EnumSpecifier* TypeSpecifier::getEnumSpec() const { return enumSpec; }
optional<TokenType> TypeSpecifier::getType() const { return type; }
StructOrUnionSpecifier* TypeSpecifier::getSuSpec() const { return suSpec; }
