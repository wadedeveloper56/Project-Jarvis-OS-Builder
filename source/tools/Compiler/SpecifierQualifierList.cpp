#include "SpecifierQualifierList.h"

using namespace WadeSpace;

SpecifierQualifierList::SpecifierQualifierList(SpecifierQualifierList* sql, TypeSpecifier* ts) :sql(sql), ts(ts), tq(NULL) {}
SpecifierQualifierList::SpecifierQualifierList(TypeSpecifier* ts) :sql(NULL), ts(ts), tq(NULL) {}
SpecifierQualifierList::SpecifierQualifierList(SpecifierQualifierList* sql, TypeQualifier* tq) :sql(sql), ts(NULL), tq(tq) {}
SpecifierQualifierList::SpecifierQualifierList(TypeQualifier* ts) :sql(NULL), ts(NULL), tq(tq) {}
SpecifierQualifierList::SpecifierQualifierList() :sql(NULL), ts(NULL), tq(NULL) {}
SpecifierQualifierList::~SpecifierQualifierList() {}
