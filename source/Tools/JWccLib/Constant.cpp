#include "pch.h"
#include "Constant.h"

using namespace WadeSpace;
using namespace std;

Constant::Constant(const optional<uint64_t>& iConst, const optional<long double>& fConst,
	const optional<string>& strConst, const optional<TokenType>& type)
	: iConst(iConst),
	fConst(fConst),
	strConst(strConst),
	type(type)
{
}

Constant::Constant() : iConst(nullopt), fConst(nullopt), strConst(nullopt), type(nullopt)
{
}

optional<uint64_t> Constant::getIConst() const
{
	return iConst;
}

optional<long double> Constant::getFConst() const
{
	return fConst;
}

optional<string> Constant::getStrConst() const
{
	return strConst;
}

optional<TokenType> Constant::getType() const
{
	return type;
}
