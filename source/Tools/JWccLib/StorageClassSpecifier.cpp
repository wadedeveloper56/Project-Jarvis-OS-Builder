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


