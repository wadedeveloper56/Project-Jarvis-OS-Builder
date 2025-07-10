#include "ParameterDeclaration.h"

using namespace WadeSpace;

ParameterDeclaration::ParameterDeclaration(DeclarationSpecifiers& pdl) :pdl(pdl), ad(std::nullopt), dec(std::nullopt) {}
ParameterDeclaration::ParameterDeclaration(DeclarationSpecifiers& pdl, AbstractDeclarator& ad) :pdl(pdl), ad(ad), dec(std::nullopt) {}
ParameterDeclaration::ParameterDeclaration(DeclarationSpecifiers& pdl, Declarator& dec) :pdl(pdl), ad(std::nullopt), dec(dec) {}
ParameterDeclaration::ParameterDeclaration():pdl(std::nullopt),ad(std::nullopt),dec(std::nullopt) {}
ParameterDeclaration::~ParameterDeclaration() {}
