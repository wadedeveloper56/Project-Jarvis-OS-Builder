#include "pch.h"
#include "TypeQualifier.h"

#include "Token.h"

using namespace WadeSpace;
using namespace std;

TypeQualifier::TypeQualifier(CTokenPtr type) :type(type)
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

CTokenPtr TypeQualifier::getType() const
{
	return type;
}

bool TypeQualifier::hasType() const
{
	return type != nullptr;
}

TypeQualifier::TypeQualifier(const TypeQualifier& other)
{
	type = other.type ? new CToken(*other.type) : nullptr;
}

TypeQualifier::TypeQualifier(TypeQualifier&& other) noexcept
{
	type = other.type ? new CToken(*other.type) : nullptr;
}

TypeQualifier& TypeQualifier::operator=(const TypeQualifier& other)
{
	if (this == &other)
		return *this;
	type = other.type ? new CToken(*other.type) : nullptr;
	return *this;
}

TypeQualifier& TypeQualifier::operator=(TypeQualifier&& other) noexcept
{
	if (this == &other)
		return *this;
	type = other.type ? new CToken(*other.type) : nullptr;
	return *this;
}

