#include "InitDeclarator.h"

using namespace WadeSpace;

InitDeclarator::InitDeclarator(Declarator& dec):dec(dec),init(std::nullopt) {}
InitDeclarator::InitDeclarator(Declarator& dec, Initializer& init):dec(dec), init(init) {}
InitDeclarator::InitDeclarator():dec(std::nullopt), init(std::nullopt) {}
InitDeclarator::~InitDeclarator() {}
