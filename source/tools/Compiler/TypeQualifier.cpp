#include "TypeQualifier.h"

using namespace WadeSpace;
using namespace std;

TypeQualifier::TypeQualifier(const string&  value, TokenType type) : operatorStr(value), type(type)
{
}

TypeQualifier::TypeQualifier() : operatorStr(""), type(NONE)
{
}

TypeQualifier::~TypeQualifier()
{
}
