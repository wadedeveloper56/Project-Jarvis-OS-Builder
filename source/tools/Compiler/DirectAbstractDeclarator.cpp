#include "DirectAbstractDeclarator.h"

using namespace WadeSpace;

DirectAbstractDeclarator::DirectAbstractDeclarator(DirectAbstractDeclarator* dad, ParameterTypeList* ptl,
                                                   TokenType type) : ad(nullptr), ce(nullptr), type(type), dad(dad),
                                                                     ptl(ptl)
{
}

DirectAbstractDeclarator::DirectAbstractDeclarator(ParameterTypeList* ptl, TokenType type) : ad(nullptr), ce(nullptr),
	type(type), dad(nullptr), ptl(ptl)
{
}

DirectAbstractDeclarator::DirectAbstractDeclarator(DirectAbstractDeclarator* dad, ConstantExpression* ce,
                                                   TokenType type) : ad(nullptr), ce(ce), type(type), dad(dad),
                                                                     ptl(nullptr)
{
}

DirectAbstractDeclarator::DirectAbstractDeclarator(DirectAbstractDeclarator* dad, TokenType type) : ad(nullptr),
	ce(nullptr), type(type), dad(dad), ptl(nullptr)
{
}

DirectAbstractDeclarator::DirectAbstractDeclarator(TokenType type) : ad(nullptr), ce(nullptr), type(type), dad(nullptr),
                                                                     ptl(nullptr)
{
}

DirectAbstractDeclarator::DirectAbstractDeclarator(ConstantExpression* ce) : ad(nullptr), ce(ce), type(NONE),
                                                                             dad(nullptr), ptl(nullptr)
{
}

DirectAbstractDeclarator::DirectAbstractDeclarator(AbstractDeclarator* ad) : ad(ad), ce(nullptr), type(NONE),
                                                                             dad(nullptr), ptl(nullptr)
{
}

DirectAbstractDeclarator::DirectAbstractDeclarator() : ad(nullptr), ce(nullptr), type(NONE), dad(nullptr), ptl(nullptr)
{
}

DirectAbstractDeclarator::~DirectAbstractDeclarator()
{
}
