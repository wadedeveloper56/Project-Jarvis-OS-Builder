#include "pch.h"
#include "TypeSpecifier.h"
#include "GlobalVars.h"
#include "StructOrUnionSpecifier.h"
#include "ExternalDeclaration.h"
#include "Compiler.h"

using namespace WadeSpace;

TypeSpecifier::TypeSpecifier(TokenType type, CTokenPtr token, StructOrUnionSpecifier* structOrUnion, EnumSpecifier* enumSpec) 
                                 : type(type), enumSpec(enumSpec), structOrUnionSpecifier(structOrUnion), typePtr(token)
{
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

CTokenPtr TypeSpecifier::getTypePtr() const
{
	return typePtr;
}

ExternalDeclaration* TypeSpecifier::getTypedefInfo() const
{
	return typedefInfo;
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

