#include "TypeSpecifier.h"

using namespace WadeSpace;

TypeSpecifier::TypeSpecifier(std::string value, TypeSpecifierType type) :operatorStr(value), type(type), enumSpec(NULL) {}
TypeSpecifier::TypeSpecifier(std::string value, EnumSpecifier* spec) :operatorStr(value), type(enum_specifier), enumSpec(spec) {}
TypeSpecifier::TypeSpecifier() :operatorStr(""), type(NONE3), enumSpec(NULL) {}
TypeSpecifier::~TypeSpecifier() {}
std::string TypeSpecifier::getoperator() const { return operatorStr; }
TypeSpecifierType TypeSpecifier::getType() const { return type; }
EnumSpecifier* TypeSpecifier::getEnumSpecifier() const { return enumSpec; }
