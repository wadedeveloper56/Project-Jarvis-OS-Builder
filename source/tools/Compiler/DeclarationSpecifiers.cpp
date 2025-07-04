#include "DeclarationSpecifiers.h"

using namespace WadeSpace;

DeclarationSpecifiers::DeclarationSpecifiers(std::string name, StorageClassSpecifier* scs, TypeSpecifier* ts, DeclarationSpecifiers* ds, TypeQualifier* tq) :name(name), scs(scs), ts(ts), ds(ds), tq(tq) {}
DeclarationSpecifiers::DeclarationSpecifiers() :name(""), scs(NULL), ts(NULL), ds(NULL), tq(NULL) {}
DeclarationSpecifiers::~DeclarationSpecifiers() {}
std::string DeclarationSpecifiers::getName() const { return name; }
StorageClassSpecifier* DeclarationSpecifiers::getScs() const { return scs; }
TypeSpecifier* DeclarationSpecifiers::getTs() const { return ts; }
DeclarationSpecifiers* DeclarationSpecifiers::getDs() const { return ds; }
TypeQualifier* DeclarationSpecifiers::getTq() const { return tq; }
