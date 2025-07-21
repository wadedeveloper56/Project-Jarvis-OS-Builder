#include "InitDeclarator.h"

using namespace WadeSpace;

InitDeclarator::InitDeclarator(Declarator* dec) :dec(dec), init(NULL) {}
InitDeclarator::InitDeclarator(Declarator* dec, Initializer* init) :dec(dec), init(init) {}
InitDeclarator::InitDeclarator() :dec(NULL), init(NULL) {}
InitDeclarator::~InitDeclarator() {}
bool InitDeclarator::hasDeclarator() const { return dec != NULL; }
bool InitDeclarator::hasInitializer() const { return init != NULL; }
Declarator* InitDeclarator::getDeclarator() const { return dec; }
Initializer* InitDeclarator::getInitializer() const { return init; }
