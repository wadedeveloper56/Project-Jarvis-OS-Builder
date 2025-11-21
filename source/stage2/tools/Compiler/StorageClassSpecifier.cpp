#include "StorageClassSpecifier.h"

using namespace WadeSpace;

StorageClassSpecifier::StorageClassSpecifier(const int& value, TokenType type) : operatorStr(value), type(type)
{
}

StorageClassSpecifier::StorageClassSpecifier() : operatorStr(nullopt), type(NONE)
{
}

StorageClassSpecifier::~StorageClassSpecifier()
{
}

optional<int> StorageClassSpecifier::getOperatorStr() const
{
	return operatorStr;
}

TokenType StorageClassSpecifier::getType() const
{
	return type;
}