#include "TypeQualifier.h"

using namespace WadeSpace;
using namespace std;

TypeQualifier::TypeQualifier(const string& value, TokenType type) : operatorStr(value), type(type)
{
}

TypeQualifier::TypeQualifier() : operatorStr(nullopt), type(NONE)
{
}

TypeQualifier::~TypeQualifier()
{
}

optional<string> TypeQualifier::getOperatorStr() const
{
	return operatorStr;
}

TokenType TypeQualifier::getType() const
{
	return type;
}