#include "Enumerator.h"

using namespace WadeSpace;

Enumerator::Enumerator(string value, ConstantExpression* type) :operatorStr(value), expression(type) {}
Enumerator::Enumerator(string value) :operatorStr(value), expression(NULL) {}
Enumerator::Enumerator() :operatorStr(""), expression(NULL) {}
Enumerator::~Enumerator() {}
