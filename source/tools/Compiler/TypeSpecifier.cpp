#include "TypeSpecifier.h"

using namespace WadeSpace;

TypeSpecifier::TypeSpecifier(TokenType type) : type(type), enumSpec(nullptr), suSpec(nullptr)
{
}

TypeSpecifier::TypeSpecifier(EnumSpecifier* type) : type(NONE), enumSpec(type), suSpec(nullptr)
{
}

TypeSpecifier::TypeSpecifier(StructOrUnionSpecifier* type) : type(NONE), enumSpec(nullptr), suSpec(type)
{
}

TypeSpecifier::TypeSpecifier() : type(NONE), enumSpec(nullptr), suSpec(nullptr)
{
}

TypeSpecifier::~TypeSpecifier()
{
}

EnumSpecifier* TypeSpecifier::getEnumSpec() const { return enumSpec; }
TokenType TypeSpecifier::getType() const { return type; }
StructOrUnionSpecifier* TypeSpecifier::getSuSpec() const { return suSpec; }
