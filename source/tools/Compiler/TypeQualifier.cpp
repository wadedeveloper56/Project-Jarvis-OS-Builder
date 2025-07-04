#include "TypeQualifier.h"

using namespace WadeSpace;

TypeQualifier::TypeQualifier(std::string value, TypeQualifierType type) :operatorStr(value), type(type) {}
TypeQualifier::TypeQualifier() :operatorStr(""), type(NONE4) {}
TypeQualifier::~TypeQualifier() {}
std::string TypeQualifier::getoperator() const { return operatorStr; }
TypeQualifierType TypeQualifier::getType() const { return type; }