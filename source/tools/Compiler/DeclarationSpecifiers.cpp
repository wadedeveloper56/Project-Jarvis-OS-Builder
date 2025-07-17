#include "DeclarationSpecifiers.h"

using namespace WadeSpace;

DeclarationSpecifiers::DeclarationSpecifiers(TypeQualifier* tq, DeclarationSpecifiers* ds) :scs(NULL), ts(NULL), ds(ds), tq(tq) {}
DeclarationSpecifiers::DeclarationSpecifiers(TypeQualifier* tq) :scs(NULL), ts(NULL), ds(NULL), tq(tq) {}
DeclarationSpecifiers::DeclarationSpecifiers(TypeSpecifier* ts, DeclarationSpecifiers* ds) :scs(NULL), ts(ts), ds(ds), tq(NULL) {}
DeclarationSpecifiers::DeclarationSpecifiers(TypeSpecifier* ts) :scs(NULL), ts(ts), ds(NULL), tq(NULL) {}
DeclarationSpecifiers::DeclarationSpecifiers(StorageClassSpecifier* scs, DeclarationSpecifiers* ds) :scs(scs), ts(NULL), ds(ds), tq(NULL) {}
DeclarationSpecifiers::DeclarationSpecifiers(StorageClassSpecifier* scs) :scs(scs), ts(NULL), ds(NULL), tq(NULL) {}
DeclarationSpecifiers::DeclarationSpecifiers() :scs(NULL), ts(NULL), ds(NULL), tq(NULL) {}
DeclarationSpecifiers::~DeclarationSpecifiers() {}
