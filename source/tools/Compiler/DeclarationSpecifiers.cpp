#include "DeclarationSpecifiers.h"

using namespace WadeSpace;

DeclarationSpecifiers::DeclarationSpecifiers(TypeQualifier& tq, DeclarationSpecifiers& ds) :scs(std::nullopt), ts(std::nullopt), ds(ds), tq(tq) {}
DeclarationSpecifiers::DeclarationSpecifiers(TypeQualifier& tq) :scs(std::nullopt), ts(std::nullopt), ds(std::nullopt), tq(tq) {}
DeclarationSpecifiers::DeclarationSpecifiers(TypeSpecifier& ts, DeclarationSpecifiers& ds) :scs(std::nullopt), ts(ts), ds(ds), tq(std::nullopt) {}
DeclarationSpecifiers::DeclarationSpecifiers(TypeSpecifier& ts) :scs(std::nullopt), ts(ts), ds(std::nullopt), tq(std::nullopt) {}
DeclarationSpecifiers::DeclarationSpecifiers(StorageClassSpecifier& scs, DeclarationSpecifiers& ds) :scs(scs), ts(std::nullopt), ds(ds), tq(std::nullopt) {}
DeclarationSpecifiers::DeclarationSpecifiers(StorageClassSpecifier& scs) :scs(scs), ts(std::nullopt), ds(std::nullopt), tq(std::nullopt) {}
DeclarationSpecifiers::DeclarationSpecifiers() :scs(std::nullopt), ts(std::nullopt), ds(std::nullopt), tq(std::nullopt) {}
DeclarationSpecifiers::~DeclarationSpecifiers() {}
StorageClassSpecifier& DeclarationSpecifiers::getScs() const { return scs->get(); }
TypeSpecifier& DeclarationSpecifiers::getTs() const { return ts->get(); }
DeclarationSpecifiers& DeclarationSpecifiers::getDs() const { return ds->get(); }
TypeQualifier& DeclarationSpecifiers::getTq() const { return tq->get(); }
