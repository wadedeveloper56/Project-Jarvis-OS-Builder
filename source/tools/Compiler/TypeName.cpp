#include "TypeName.h"

using namespace WadeSpace;

TypeName::TypeName(SpecifierQualifierList* sql) :sql(sql), ad(NULL) {}
TypeName::TypeName(SpecifierQualifierList* sql, AbstractDeclarator* ad) :sql(sql), ad(ad) {}
TypeName::TypeName() :sql(NULL), ad(NULL) {}
TypeName::~TypeName() {}
