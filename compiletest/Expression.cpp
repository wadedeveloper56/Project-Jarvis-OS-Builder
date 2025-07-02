#include "Expression.h"

using namespace WadeSpace;

Expression::Expression() :cValue(NULL), sValue(""), exp(NULL) {
}

Expression::Expression(Constant *value) :cValue(value), sValue(""), exp(NULL) {
}

Expression::Expression(std::string& value) :cValue(NULL),sValue(value), exp(NULL) {
}

Expression::Expression(std::string& value, Expression* expValue) :cValue(NULL), sValue(value), exp(expValue) {
}

Expression::~Expression() {
}