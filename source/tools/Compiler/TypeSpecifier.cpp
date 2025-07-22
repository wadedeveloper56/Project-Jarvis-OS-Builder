#include "TypeSpecifier.h"

using namespace WadeSpace;

TypeSpecifier::TypeSpecifier(TokenType type) :type(type), enumSpec(NULL), suSpec(NULL) {}
TypeSpecifier::TypeSpecifier(EnumSpecifier* type) :type(NONE), enumSpec(type), suSpec(NULL) {}
TypeSpecifier::TypeSpecifier(StructOrUnionSpecifier* type) :type(NONE), enumSpec(NULL), suSpec(type) {}
TypeSpecifier::TypeSpecifier() :type(NONE), enumSpec(NULL), suSpec(NULL) {}
TypeSpecifier::~TypeSpecifier() {}
EnumSpecifier* TypeSpecifier::getEnumSpec() const { return enumSpec; }
TokenType TypeSpecifier::getType() const { return type; }
StructOrUnionSpecifier* TypeSpecifier::getSuSpec() const { return suSpec; }
