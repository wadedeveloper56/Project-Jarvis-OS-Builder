#include "TypeName.h"

using namespace WadeSpace;

TypeName::TypeName(SpecifierQualifierList& sql) :sql(sql), ad(std::nullopt) {}
TypeName::TypeName(SpecifierQualifierList& sql, AbstractDeclarator& ad) :sql(sql), ad(ad) {}
TypeName::TypeName() :sql(std::nullopt), ad(std::nullopt) {}
TypeName::~TypeName() {}
SpecifierQualifierList& TypeName::getSql() const { return sql->get(); }
AbstractDeclarator& TypeName::getTs() const { return ad->get(); }
