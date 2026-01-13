#include "Constant.h"

using namespace WadeSpace;
using namespace std;

Constant::Constant(uint64_t value) : iConst(value), fConst(0.0), strConst(nullopt), type(INTEGER_CONSTANT)
{
}

Constant::Constant(long double value) : iConst(0), fConst(value), strConst(nullopt), type(FLOAT_CONSTANT)
{
}

Constant::Constant(const string&  value) : iConst(0), fConst(0.0), strConst(value), type(STRING_CONSTANT)
{
}

Constant::Constant() : iConst(0), fConst(0.0), strConst(nullopt), type(NONE)
{
}

Constant::~Constant()
{
}

uint64_t Constant::getIConst() const
{
	return iConst;
}

long double Constant::getFConst() const
{
	return fConst;
}

optional<string> Constant::getStrConst() const
{
	return strConst;
}

TokenType Constant::getType() const
{
	return type;
}
