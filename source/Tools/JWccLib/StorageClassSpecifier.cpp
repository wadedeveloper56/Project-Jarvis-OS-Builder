#include "pch.h"
#include "StorageClassSpecifier.h"

using namespace WadeSpace;

StorageClassSpecifier::StorageClassSpecifier(const int& value, TokenType type) : operatorStr(value), type(type)
{
}

StorageClassSpecifier::StorageClassSpecifier() : operatorStr(nullopt), type(NONE)
{
}

optional<int> StorageClassSpecifier::getOperatorStr() const
{
	return operatorStr;
}

optional<TokenType> StorageClassSpecifier::getType() const
{
	return type;
}

bool StorageClassSpecifier::isOperatorStr() const
{
	return operatorStr.has_value();
}

bool StorageClassSpecifier::isType() const
{
	return type.has_value();
}


