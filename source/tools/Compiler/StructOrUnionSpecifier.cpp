#include "StructOrUnionSpecifier.h"

using namespace WadeSpace;

StructOrUnionSpecifier::StructOrUnionSpecifier(StructOrUnion* su, string name, vector<StructDeclaration *>* list) :su(su), name(name), list(list) {}
StructOrUnionSpecifier::StructOrUnionSpecifier(StructOrUnion* su, vector<StructDeclaration *>* list) :su(su), name(""), list(list) {}
StructOrUnionSpecifier::StructOrUnionSpecifier(StructOrUnion* su, string name) :su(su), name(name), list(NULL) {}
StructOrUnionSpecifier::StructOrUnionSpecifier() :su(NULL), name(""), list(NULL) {}
StructOrUnionSpecifier::~StructOrUnionSpecifier() {}
