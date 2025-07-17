#include "InitDeclarator.h"

using namespace WadeSpace;

InitDeclarator::InitDeclarator(Declarator* dec) :dec(dec), init(NULL) {}
InitDeclarator::InitDeclarator(Declarator* dec, Initializer* init) :dec(dec), init(init) {}
InitDeclarator::InitDeclarator() :dec(NULL), init(NULL) {}
InitDeclarator::~InitDeclarator() {}
