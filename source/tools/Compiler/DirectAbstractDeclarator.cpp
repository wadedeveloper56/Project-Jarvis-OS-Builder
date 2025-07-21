#include "DirectAbstractDeclarator.h"

using namespace WadeSpace;

DirectAbstractDeclarator::DirectAbstractDeclarator(DirectAbstractDeclarator* dad, ParameterTypeList* ptl, TokenType type) :ad(NULL), ce(NULL), type(type), dad(dad), ptl(ptl) {}
DirectAbstractDeclarator::DirectAbstractDeclarator(ParameterTypeList* ptl, TokenType type) :ad(NULL), ce(NULL), type(type), dad(NULL), ptl(ptl) {}
DirectAbstractDeclarator::DirectAbstractDeclarator(DirectAbstractDeclarator* dad, ConstantExpression* ce, TokenType type) :ad(NULL), ce(ce), type(type), dad(dad), ptl(NULL) {}
DirectAbstractDeclarator::DirectAbstractDeclarator(DirectAbstractDeclarator* dad, TokenType type) :ad(NULL), ce(NULL), type(type), dad(dad), ptl(NULL) {}
DirectAbstractDeclarator::DirectAbstractDeclarator(TokenType type) :ad(NULL), ce(NULL), type(type), dad(NULL), ptl(NULL) {}
DirectAbstractDeclarator::DirectAbstractDeclarator(ConstantExpression* ce) :ad(NULL), ce(ce), type(NONE), dad(NULL), ptl(NULL) {}
DirectAbstractDeclarator::DirectAbstractDeclarator(AbstractDeclarator* ad) :ad(ad), ce(NULL), type(NONE), dad(NULL), ptl(NULL) {}
DirectAbstractDeclarator::DirectAbstractDeclarator() :ad(NULL), ce(NULL), type(NONE), dad(NULL), ptl(NULL) {}
DirectAbstractDeclarator::~DirectAbstractDeclarator() {}

