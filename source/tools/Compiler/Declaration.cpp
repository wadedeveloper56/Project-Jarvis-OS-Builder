#include "Declaration.h"

using namespace WadeSpace;

Declaration::Declaration(DeclarationSpecifiers& ds) :ds(ds) {}
Declaration::Declaration(DeclarationSpecifiers& ds, std::vector<InitDeclarator> idl) :ds(ds), idl(idl) {}
Declaration::Declaration() {}
Declaration::~Declaration() {}