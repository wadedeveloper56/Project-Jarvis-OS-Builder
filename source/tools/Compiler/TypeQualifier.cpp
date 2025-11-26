#include "TypeQualifier.h"

using namespace WadeSpace;
using namespace std;

TypeQualifier::TypeQualifier(const int& value, TokenType type) : operatorStr(value), type(type)
{
}

TypeQualifier::TypeQualifier() : operatorStr(nullopt), type(NONE)
{
}

TypeQualifier::~TypeQualifier()
{
}

optional<int> TypeQualifier::getOperatorStr() const
{
	return operatorStr;
}

TokenType TypeQualifier::getType() const
{
	return type;
}