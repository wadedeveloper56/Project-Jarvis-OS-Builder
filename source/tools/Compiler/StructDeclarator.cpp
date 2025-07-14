#include "StructDeclarator.h"

using namespace WadeSpace;

StructDeclarator::StructDeclarator(Declarator& dec) :dec(dec), exp(std::nullopt) {}
StructDeclarator::StructDeclarator(ConstantExpression& exp) :dec(std::nullopt), exp(exp) {}
StructDeclarator::StructDeclarator(Declarator& dec, ConstantExpression& exp) :dec(dec), exp(exp) {}
StructDeclarator::StructDeclarator() :dec(std::nullopt), exp(std::nullopt) {}
StructDeclarator::~StructDeclarator() {}
