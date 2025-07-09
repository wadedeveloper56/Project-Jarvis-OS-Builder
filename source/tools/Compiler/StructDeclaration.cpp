#include "StructDeclaration.h"

using namespace WadeSpace;

StructDeclaration::StructDeclaration(SpecifierQualifierList& sql, std::vector<StructDeclarator>& list):sql(sql),list(list) {}
StructDeclaration::StructDeclaration() :sql(std::nullopt), list(std::nullopt) {}
StructDeclaration::~StructDeclaration() {}
SpecifierQualifierList& StructDeclaration::getSql() const { return sql->get(); }
std::vector<StructDeclarator>& StructDeclaration::getList() const { return list->get(); }
