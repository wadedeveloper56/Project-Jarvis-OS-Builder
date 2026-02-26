#include "pch.h"
#include "TypeQualifier.h"

#include "Token.h"

using namespace WadeSpace;
using namespace std;

TypeQualifier::TypeQualifier(TokenPtr type) :type(type)
{
}

TypeQualifier::TypeQualifier()
{
	type = nullptr;	
}

TypeQualifier::~TypeQualifier()
{
	delete type;
}

TokenPtr TypeQualifier::getType() const
{
	return type;
}

TypeQualifier::TypeQualifier(const TypeQualifier& other)
{
	type = other.type ? new Token(*other.type) : nullptr;
}

TypeQualifier::TypeQualifier(TypeQualifier&& other) noexcept
{
	type = other.type ? new Token(*other.type) : nullptr;
}

TypeQualifier& TypeQualifier::operator=(const TypeQualifier& other)
{
	if (this == &other)
		return *this;
	type = other.type ? new Token(*other.type) : nullptr;
	return *this;
}

TypeQualifier& TypeQualifier::operator=(TypeQualifier&& other) noexcept
{
	if (this == &other)
		return *this;
	type = other.type ? new Token(*other.type) : nullptr;
	return *this;
}

