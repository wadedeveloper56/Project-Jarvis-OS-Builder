#include "pch.h"
#include "AbstractDeclarator.h"

using namespace WadeSpace;

AbstractDeclarator::AbstractDeclarator(Pointer* pointer, DirectAbstractDeclarator* directAbstractDeclarator)
{
	this->pointer = pointer;
	this->directAbstractDeclarator = directAbstractDeclarator;
}


AbstractDeclarator::AbstractDeclarator()
{
	this->pointer = nullptr;
	this->directAbstractDeclarator = nullptr;
}

AbstractDeclarator::~AbstractDeclarator()
{
	delete pointer;
	delete directAbstractDeclarator;
}

Pointer* AbstractDeclarator::getPointer() const { return pointer; }
DirectAbstractDeclarator* AbstractDeclarator::getDirectAbstractDeclarator() const { return directAbstractDeclarator; }
bool AbstractDeclarator::isPointer() const { return pointer != nullptr; }
bool AbstractDeclarator::isDirectAbstractDeclarator() const { return directAbstractDeclarator != nullptr; }
