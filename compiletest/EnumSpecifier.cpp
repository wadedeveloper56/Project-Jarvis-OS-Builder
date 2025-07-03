#include "EnumSpecifier.h"

using namespace WadeSpace;

EnumSpecifier::EnumSpecifier(std::string value, std::vector<Enumerator>& list) :nameStr(value), list(list) {}
EnumSpecifier::EnumSpecifier() :nameStr(""), list(std::vector<Enumerator>()) {}
EnumSpecifier::~EnumSpecifier() {}
std::string EnumSpecifier::getNameStr() const { return nameStr; }
std::vector<Enumerator> EnumSpecifier::getList() const { return list; }