#include "pch.h"
#include "Constant.h"

using namespace WadeSpace;
using namespace std;

Constant::Constant(const TokenPtr iConst, const TokenPtr fConst, const TokenPtr strConst, const optional<TokenType>& type)
	: iConst(iConst),
	fConst(fConst),
	strConst(strConst),
	type(type)
{
}

Constant::Constant() : iConst(nullptr), fConst(nullptr), strConst(nullptr), type(nullopt)
{
}

TokenPtr Constant::getIConst() const
{
	return iConst;
}

TokenPtr Constant::getFConst() const
{
	return fConst;
}

TokenPtr Constant::getStrConst() const
{
	return strConst;
}

optional<TokenType> Constant::getType() const
{
	return type;
}
