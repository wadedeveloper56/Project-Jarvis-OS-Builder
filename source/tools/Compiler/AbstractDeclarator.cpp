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
