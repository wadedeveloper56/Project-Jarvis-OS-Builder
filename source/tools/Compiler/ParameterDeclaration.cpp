#include "ParameterDeclaration.h"

using namespace WadeSpace;

ParameterDeclaration::ParameterDeclaration(DeclarationSpecifiers* pdl) : pdl(pdl), ad(nullptr), dec(nullptr)
{
}

ParameterDeclaration::ParameterDeclaration(DeclarationSpecifiers* pdl, AbstractDeclarator* ad) : pdl(pdl), ad(ad), dec(nullptr)
{
}

ParameterDeclaration::ParameterDeclaration(DeclarationSpecifiers* pdl, Declarator* dec) : pdl(pdl), ad(nullptr), dec(dec)
{
}

ParameterDeclaration::ParameterDeclaration(): pdl(nullptr), ad(nullptr), dec(nullptr)
{
}

ParameterDeclaration::~ParameterDeclaration()
{
	delete pdl;
	delete ad;
	delete dec;
}
