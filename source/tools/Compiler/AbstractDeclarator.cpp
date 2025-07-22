#include "AbstractDeclarator.h"

using namespace WadeSpace;

AbstractDeclarator::AbstractDeclarator(Pointer* pointer) : pointer(pointer), directAbstractDeclarator(nullptr)
{
}

AbstractDeclarator::AbstractDeclarator(DirectAbstractDeclarator* directAbstractDeclarator) : pointer(nullptr),
	directAbstractDeclarator(directAbstractDeclarator)
{
}

AbstractDeclarator::AbstractDeclarator(Pointer* ptr, DirectAbstractDeclarator* directAbstractDeclarator) : pointer(ptr),
	directAbstractDeclarator(directAbstractDeclarator)
{
}

AbstractDeclarator::AbstractDeclarator() : pointer(nullptr), directAbstractDeclarator(nullptr)
{
}

AbstractDeclarator::~AbstractDeclarator()
{
	if (pointer != nullptr) delete pointer;
	if (directAbstractDeclarator != nullptr) delete directAbstractDeclarator;
}

Pointer* AbstractDeclarator::getPointer() const { return pointer; }
DirectAbstractDeclarator* AbstractDeclarator::getDirectAbstractDeclarator() const { return directAbstractDeclarator; }
