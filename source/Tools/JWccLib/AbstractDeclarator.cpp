#include "pch.h"
#include "AbstractDeclarator.h"

using namespace WadeSpace;

AbstractDeclarator::AbstractDeclarator(shared_ptr<Pointer> pointer, shared_ptr<DirectAbstractDeclarator> directAbstractDeclarator)
{
	this->pointer = pointer;
	this->directAbstractDeclarator = directAbstractDeclarator;
}

