#include "AbstractDeclarator.h"

using namespace WadeSpace;

AbstractDeclarator::AbstractDeclarator(Pointer* ptr) :ptr(ptr), dad(NULL) {}
AbstractDeclarator::AbstractDeclarator(DirectAbstractDeclarator* dad) :ptr(NULL), dad(dad) {}
AbstractDeclarator::AbstractDeclarator(Pointer* ptr, DirectAbstractDeclarator* dad) :ptr(ptr), dad(dad) {}
AbstractDeclarator::AbstractDeclarator() :ptr(NULL), dad(NULL) {}
AbstractDeclarator::~AbstractDeclarator() {
	if (ptr) delete ptr;
	if (dad) delete dad;
}
bool AbstractDeclarator::hasPointer() const { return ptr != NULL; }
bool AbstractDeclarator::hasDirectAbstractDeclarator() const { return dad != NULL; }
Pointer* AbstractDeclarator::getPointer() const {return ptr;}
DirectAbstractDeclarator* AbstractDeclarator::getDirectAbstractDeclarator() const { return dad; }