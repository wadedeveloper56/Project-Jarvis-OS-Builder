#include "TypeSpecifier.h"

using namespace WadeSpace;

TypeSpecifier::TypeSpecifier(TokenType type) :type(type), enumSpec(NULL), suSpec(NULL) {}
TypeSpecifier::TypeSpecifier(EnumSpecifier* type) :type(NONE), enumSpec(type), suSpec(NULL) {}
TypeSpecifier::TypeSpecifier(StructOrUnionSpecifier* type) :type(NONE), suSpec(type) {}
TypeSpecifier::TypeSpecifier() :type(NONE), enumSpec(NULL), suSpec(NULL) {}
TypeSpecifier::~TypeSpecifier() {}
