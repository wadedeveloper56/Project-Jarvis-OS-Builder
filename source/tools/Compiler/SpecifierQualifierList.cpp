#include "SpecifierQualifierList.h"

using namespace WadeSpace;

SpecifierQualifierList::SpecifierQualifierList(SpecifierQualifierList& sql, TypeSpecifier& ts) :sql(sql), ts(ts), tq(std::nullopt) {}
SpecifierQualifierList::SpecifierQualifierList(TypeSpecifier& ts) :sql(std::nullopt), ts(ts), tq(std::nullopt) {}
SpecifierQualifierList::SpecifierQualifierList(SpecifierQualifierList& sql, TypeQualifier& tq) :sql(sql), ts(std::nullopt), tq(tq) {}
SpecifierQualifierList::SpecifierQualifierList(TypeQualifier& ts) :sql(std::nullopt), ts(std::nullopt), tq(tq) {}
SpecifierQualifierList::SpecifierQualifierList() :sql(std::nullopt), ts(std::nullopt), tq(std::nullopt) {}
SpecifierQualifierList::~SpecifierQualifierList() {}
