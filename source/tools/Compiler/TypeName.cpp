#include "TypeName.h"

using namespace WadeSpace;

TypeName::TypeName(SpecifierQualifierList* sql) : sql(sql), ad(nullptr)
{
}

TypeName::TypeName(SpecifierQualifierList* sql, AbstractDeclarator* ad) : sql(sql), ad(ad)
{
}

TypeName::TypeName() : sql(nullptr), ad(nullptr)
{
}

TypeName::~TypeName()
{
	delete sql;
	delete ad;
}
