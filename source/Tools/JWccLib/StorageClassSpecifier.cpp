#include "pch.h"
#include "StorageClassSpecifier.h"

using namespace WadeSpace;

StorageClassSpecifier::StorageClassSpecifier(TokenPtr type) : type(type)
{
}

StorageClassSpecifier::StorageClassSpecifier() : type(nullptr)
{
}

TokenPtr StorageClassSpecifier::getType() const
{
	return type;
}

bool StorageClassSpecifier::isType() const
{
	return type!=nullptr;
}

StorageClassSpecifier::StorageClassSpecifier(const StorageClassSpecifier& other)
{
	delete type;
	type = other.type ? new Token(*other.type) : nullptr;
}

StorageClassSpecifier::StorageClassSpecifier(StorageClassSpecifier&& other) noexcept
{
	delete type;
	type = other.type ? new Token(*other.type) : nullptr;
}

StorageClassSpecifier& StorageClassSpecifier::operator=(const StorageClassSpecifier& other)
{
	if (this == &other)
		return *this;
	delete type;
	type = other.type ? new Token(*other.type) : nullptr;
	return *this;
}

StorageClassSpecifier& StorageClassSpecifier::operator=(StorageClassSpecifier&& other) noexcept
{
	if (this == &other)
		return *this;
	delete type;
	type = other.type ? new Token(*other.type) : nullptr;
	return *this;
}


