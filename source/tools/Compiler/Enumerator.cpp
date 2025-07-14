#include "Enumerator.h"

using namespace WadeSpace;

Enumerator::Enumerator(std::string value, ConstantExpression&type) :operatorStr(value), expression(type) {}
Enumerator::Enumerator(std::string value) :operatorStr(value), expression(std::nullopt) {}
Enumerator::Enumerator() :operatorStr(""), expression(std::nullopt) {}
Enumerator::~Enumerator() {}
