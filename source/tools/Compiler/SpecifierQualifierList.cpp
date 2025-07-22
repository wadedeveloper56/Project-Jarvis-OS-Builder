#include "SpecifierQualifierList.h"

using namespace WadeSpace;

SpecifierQualifierList::SpecifierQualifierList(SpecifierQualifierList* sql, TypeSpecifier* ts) : sql(sql), ts(ts),
	tq(nullptr)
{
}

SpecifierQualifierList::SpecifierQualifierList(TypeSpecifier* ts) : sql(nullptr), ts(ts), tq(nullptr)
{
}

SpecifierQualifierList::SpecifierQualifierList(SpecifierQualifierList* sql, TypeQualifier* tq) : sql(sql), ts(nullptr),
	tq(tq)
{
}

SpecifierQualifierList::SpecifierQualifierList(TypeQualifier* ts) : sql(nullptr), ts(nullptr), tq(tq)
{
}

SpecifierQualifierList::SpecifierQualifierList() : sql(nullptr), ts(nullptr), tq(nullptr)
{
}

SpecifierQualifierList::~SpecifierQualifierList()
{
}
