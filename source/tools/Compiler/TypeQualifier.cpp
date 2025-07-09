#include "TypeQualifier.h"

using namespace WadeSpace;

TypeQualifier::TypeQualifier(std::string value, TokenType type) :operatorStr(value), type(type) {}
TypeQualifier::TypeQualifier() :operatorStr(""), type(NONE) {}
TypeQualifier::~TypeQualifier() {}
