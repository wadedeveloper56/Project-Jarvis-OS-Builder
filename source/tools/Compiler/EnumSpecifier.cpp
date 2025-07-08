#include "EnumSpecifier.h"

using namespace WadeSpace;

EnumSpecifier::EnumSpecifier(std::vector<Enumerator>& list) :nameStr(""), list(list) {}
EnumSpecifier::EnumSpecifier(std::string value, std::vector<Enumerator>& list) :nameStr(value), list(list) {}
EnumSpecifier::EnumSpecifier(std::string value) :nameStr(value), list(std::nullopt) {}
EnumSpecifier::EnumSpecifier() :nameStr(""), list(std::nullopt) {}
EnumSpecifier::~EnumSpecifier() {}
std::string EnumSpecifier::getNameStr() const { return nameStr; }
std::vector<Enumerator>&  EnumSpecifier::getList() const { return list->get(); }
