#include "pch.h"
#include "TypeQualifier.h"

#include "Token.h"

using namespace WadeSpace;
using namespace std;

TypeQualifier::TypeQualifier(TokenPtr type) :type(type)
{
}

TokenPtr TypeQualifier::getType() const
{
	return type;
}