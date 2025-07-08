#include "Declarator.h"

using namespace WadeSpace;

Declarator::Declarator(Pointer& ptr, DirectDeclarator& dd) :dd(dd), ptr(ptr) {}
Declarator::Declarator(DirectDeclarator& dd) :dd(dd), ptr(std::nullopt) {}
Declarator::Declarator() :dd(std::nullopt), ptr(std::nullopt) {}
Declarator::~Declarator() {}
DirectDeclarator& Declarator::getDirectDeclarator() const { return dd->get(); };
Pointer& Declarator::getPointer() const { return ptr->get(); }