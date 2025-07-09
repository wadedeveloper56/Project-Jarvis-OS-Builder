#include "TypeSpecifier.h"

using namespace WadeSpace;

TypeSpecifier::TypeSpecifier(std::string value, TokenType type) :operatorStr(value), type(type), enumSpec(std::nullopt) {}
TypeSpecifier::TypeSpecifier(std::string value, EnumSpecifier& spec) :operatorStr(value), type(NONE), enumSpec(spec) {}
TypeSpecifier::TypeSpecifier() :operatorStr(""), type(NONE), enumSpec(std::nullopt) {}
TypeSpecifier::~TypeSpecifier() {}
