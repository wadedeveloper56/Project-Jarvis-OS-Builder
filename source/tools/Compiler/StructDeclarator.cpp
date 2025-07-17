#include "StructDeclarator.h"

using namespace WadeSpace;

StructDeclarator::StructDeclarator(Declarator* dec) :dec(dec), exp(NULL) {}
StructDeclarator::StructDeclarator(ConstantExpression* exp) :dec(NULL), exp(exp) {}
StructDeclarator::StructDeclarator(Declarator* dec, ConstantExpression* exp) :dec(dec), exp(exp) {}
StructDeclarator::StructDeclarator() :dec(NULL), exp(NULL) {}
StructDeclarator::~StructDeclarator() {}
