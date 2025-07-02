#include "Constant.h"

using namespace WadeSpace;

Constant::Constant(std::uint64_t value):iConst(value), fConst(0.0),strConst("") {
}

Constant::Constant(long double value) :iConst(0), fConst(value), strConst("") {
}

Constant::Constant(std::string value) :iConst(0), fConst(0.0), strConst(value) {
}

Constant::Constant():iConst(0),fConst(0.0), strConst("") {

}

Constant::~Constant() {

}

std::uint64_t Constant::integerConstant() const {
	return iConst;
}

long double Constant::floatConstant() const {
	return fConst;
}

std::string Constant::stringConstant() const {
	return strConst;
}