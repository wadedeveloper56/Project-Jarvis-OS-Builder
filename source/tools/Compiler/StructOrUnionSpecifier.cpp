#include "StructOrUnionSpecifier.h"

using namespace WadeSpace;

StructOrUnionSpecifier::StructOrUnionSpecifier(StructOrUnion& su, std::string name, std::vector<StructDeclaration>& list) :su(su), name(name), list(list) {}
StructOrUnionSpecifier::StructOrUnionSpecifier(StructOrUnion& su, std::vector<StructDeclaration>& list) :su(su), name(""), list(list) {}
StructOrUnionSpecifier::StructOrUnionSpecifier(StructOrUnion& su, std::string name) :su(su), name(name), list(std::nullopt) {}
StructOrUnionSpecifier::StructOrUnionSpecifier() :su(std::nullopt), name(""), list(std::nullopt) {}
StructOrUnionSpecifier::~StructOrUnionSpecifier() {}
std::string StructOrUnionSpecifier::getName() const { return name; }
StructOrUnion& StructOrUnionSpecifier::getSu() const { return su->get(); }
std::vector<StructDeclaration>& StructOrUnionSpecifier::getList() const { return list->get(); }
