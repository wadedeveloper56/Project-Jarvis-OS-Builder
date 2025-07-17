#include "ParameterDeclaration.h"

using namespace WadeSpace;

ParameterDeclaration::ParameterDeclaration(DeclarationSpecifiers* pdl) :pdl(pdl), ad(NULL), dec(NULL) {}
ParameterDeclaration::ParameterDeclaration(DeclarationSpecifiers* pdl, AbstractDeclarator* ad) :pdl(pdl), ad(ad), dec(NULL) {}
ParameterDeclaration::ParameterDeclaration(DeclarationSpecifiers* pdl, Declarator* dec) :pdl(pdl), ad(NULL), dec(dec) {}
ParameterDeclaration::ParameterDeclaration():pdl(NULL),ad(NULL),dec(NULL) {}
ParameterDeclaration::~ParameterDeclaration() {}
