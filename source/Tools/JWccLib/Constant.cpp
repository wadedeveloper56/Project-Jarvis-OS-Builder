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

Constant::~Constant()
{
	delete iConst;
	delete fConst;
	delete strConst;
}

Constant::Constant(const Constant& other)
	: iConst(other.iConst),
	fConst(other.fConst),
	strConst(other.strConst),
	type(other.type)
{
}

Constant::Constant(Constant&& other) noexcept
	: iConst(other.iConst),
	fConst(other.fConst),
	strConst(other.strConst),
	type(std::move(other.type))
{
}

Constant& Constant::operator=(const Constant& other)
{
	if (this == &other)
		return *this;
	iConst = other.iConst;
	fConst = other.fConst;
	strConst = other.strConst;
	type = other.type;
	return *this;
}

Constant& Constant::operator=(Constant&& other) noexcept
{
	if (this == &other)
		return *this;
	iConst = other.iConst;
	fConst = other.fConst;
	strConst = other.strConst;
	type = other.type;
	return *this;
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
