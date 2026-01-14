#include "StructOrUnion.h"

using namespace WadeSpace;

StructOrUnion::StructOrUnion(TokenType type): type(type)
{
}

StructOrUnion::StructOrUnion(): type(NONE)
{
}

StructOrUnion::~StructOrUnion()
{
}

TokenType StructOrUnion::getType() const
{
	return type;
}