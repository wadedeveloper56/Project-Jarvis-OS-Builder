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

bool StorageClassSpecifier::hasType() const
{
	return type!=nullptr;
}

StorageClassSpecifier::StorageClassSpecifier(const StorageClassSpecifier& other)
{
	type = other.type ? new Token(*other.type) : nullptr;
}

StorageClassSpecifier::StorageClassSpecifier(StorageClassSpecifier&& other) noexcept
{
	type = other.type ? new Token(*other.type) : nullptr;
}

StorageClassSpecifier& StorageClassSpecifier::operator=(const StorageClassSpecifier& other)
{
	if (this == &other)
		return *this;
	type = other.type ? new Token(*other.type) : nullptr;
	return *this;
}

StorageClassSpecifier& StorageClassSpecifier::operator=(StorageClassSpecifier&& other) noexcept
{
	if (this == &other)
		return *this;
	type = other.type ? new Token(*other.type) : nullptr;
	return *this;
}


