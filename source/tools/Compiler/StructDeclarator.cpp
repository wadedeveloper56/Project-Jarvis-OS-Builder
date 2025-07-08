#include "StructDeclarator.h"

using namespace WadeSpace;

StructDeclarator::StructDeclarator(Declarator& dec) :dec(dec), exp(std::nullopt) {}
StructDeclarator::StructDeclarator(Expression& exp) :dec(std::nullopt), exp(exp) {}
StructDeclarator::StructDeclarator(Declarator& dec, Expression& exp) :dec(dec), exp(exp) {}
StructDeclarator::StructDeclarator() :dec(std::nullopt), exp(std::nullopt) {}
StructDeclarator::~StructDeclarator() {}
Declarator& StructDeclarator::getDec() const { return dec->get(); }
Expression& StructDeclarator::getExp() const { return exp->get(); }