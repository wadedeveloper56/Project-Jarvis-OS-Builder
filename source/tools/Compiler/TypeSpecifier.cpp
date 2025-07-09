#include "TypeSpecifier.h"

using namespace WadeSpace;

TypeSpecifier::TypeSpecifier(TokenType type) :type(type), enumSpec(std::nullopt), suSpec(std::nullopt) {}
TypeSpecifier::TypeSpecifier(EnumSpecifier& type) :type(NONE), enumSpec(type), suSpec(std::nullopt) {}
TypeSpecifier::TypeSpecifier(StructOrUnionSpecifier& type) :type(NONE), suSpec(type) {}
TypeSpecifier::TypeSpecifier() :type(NONE), enumSpec(std::nullopt), suSpec(std::nullopt) {}
TypeSpecifier::~TypeSpecifier() {}
