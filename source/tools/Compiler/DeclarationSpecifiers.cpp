#include "DeclarationSpecifiers.h"

using namespace WadeSpace;

DeclarationSpecifiers::DeclarationSpecifiers(TypeQualifier* tq, DeclarationSpecifiers* ds) : scs(nullptr), ts(nullptr),
	ds(ds), tq(tq)
{
}

DeclarationSpecifiers::DeclarationSpecifiers(TypeQualifier* tq) : scs(nullptr), ts(nullptr), ds(nullptr), tq(tq)
{
}

DeclarationSpecifiers::DeclarationSpecifiers(TypeSpecifier* ts, DeclarationSpecifiers* ds) : scs(nullptr), ts(ts),
	ds(ds), tq(nullptr)
{
}

DeclarationSpecifiers::DeclarationSpecifiers(TypeSpecifier* ts) : scs(nullptr), ts(ts), ds(nullptr), tq(nullptr)
{
}

DeclarationSpecifiers::DeclarationSpecifiers(StorageClassSpecifier* scs,
                                             DeclarationSpecifiers* ds) : scs(scs), ts(nullptr), ds(ds), tq(nullptr)
{
}

DeclarationSpecifiers::DeclarationSpecifiers(StorageClassSpecifier* scs) : scs(scs), ts(nullptr), ds(nullptr),
                                                                           tq(nullptr)
{
}

DeclarationSpecifiers::DeclarationSpecifiers() : scs(nullptr), ts(nullptr), ds(nullptr), tq(nullptr)
{
}

DeclarationSpecifiers::~DeclarationSpecifiers()
{
}

StorageClassSpecifier* DeclarationSpecifiers::getStorageClassSpecifier() const { return scs; }
TypeSpecifier* DeclarationSpecifiers::getTypeSpecifier() const { return ts; }
TypeQualifier* DeclarationSpecifiers::getTypeQualifier() const { return tq; }
DeclarationSpecifiers* DeclarationSpecifiers::getDeclarationSpecifiers() const { return ds; }
