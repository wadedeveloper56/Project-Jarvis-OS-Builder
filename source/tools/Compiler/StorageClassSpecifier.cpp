#include "StorageClassSpecifier.h"

using namespace WadeSpace;

StorageClassSpecifier::StorageClassSpecifier(const string& value, TokenType type) : operatorStr(value), type(type)
{
}

StorageClassSpecifier::StorageClassSpecifier() : operatorStr(nullopt), type(NONE)
{
}

StorageClassSpecifier::~StorageClassSpecifier()
{
}

optional<string> StorageClassSpecifier::getOperatorStr() const
{
	return operatorStr;
}

TokenType StorageClassSpecifier::getType() const
{
	return type;
}