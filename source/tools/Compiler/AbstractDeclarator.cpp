#include "AbstractDeclarator.h"

using namespace WadeSpace;

AbstractDeclarator::AbstractDeclarator(Pointer& ptr) :ptr(ptr), dad(std::nullopt) {}
AbstractDeclarator::AbstractDeclarator(DirectAbstractDeclarator& dad) :ptr(std::nullopt), dad(dad) {}
AbstractDeclarator::AbstractDeclarator(Pointer& ptr, DirectAbstractDeclarator& dad) :ptr(ptr), dad(dad) {}
AbstractDeclarator::AbstractDeclarator() :ptr(std::nullopt), dad(std::nullopt) {}
AbstractDeclarator::~AbstractDeclarator() {}
Pointer& AbstractDeclarator::getPointer() const { return ptr->get(); }
DirectAbstractDeclarator& AbstractDeclarator::getDad() const { return dad->get(); }