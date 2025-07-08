#include "Enumerator.h"

using namespace WadeSpace;

Enumerator::Enumerator(std::string value, Expression &type) :operatorStr(value), expression(type) {}
Enumerator::Enumerator(std::string value) :operatorStr(value), expression(std::nullopt) {}
Enumerator::Enumerator() :operatorStr(""), expression(std::nullopt) {}
Enumerator::~Enumerator() {}
std::string Enumerator::getoperator() const { return operatorStr; }
Expression& Enumerator::getExpression() const { return expression->get();  }
