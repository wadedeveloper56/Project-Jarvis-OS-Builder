#include "Constant.h"

using namespace WadeSpace;
using namespace std;

Constant::Constant(uint64_t value) : iConst(value), fConst(0.0), strConst(""), type(INTEGER_CONSTANT)
{
}

Constant::Constant(long double value) : iConst(0), fConst(value), strConst(""), type(FLOAT_CONSTANT)
{
}

Constant::Constant(const string&  value) : iConst(0), fConst(0.0), strConst(value), type(STRING_CONSTANT)
{
}

Constant::Constant() : iConst(0), fConst(0.0), strConst(""), type(NONE)
{
}

Constant::~Constant()
{
}
