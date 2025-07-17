#include "Constant.h"

using namespace WadeSpace;

Constant::Constant(std::uint64_t value) :iConst(value), fConst(0.0), strConst(""), type(INTEGER_CONSTANT) {}
Constant::Constant(long double value) :iConst(0), fConst(value), strConst(""), type(FLOAT_CONSTANT) {}
Constant::Constant(string value) :iConst(0), fConst(0.0), strConst(value), type(STRING_CONSTANT) {}
Constant::Constant() :iConst(0), fConst(0.0), strConst(""), type(NONE) {}
Constant::~Constant() {}
