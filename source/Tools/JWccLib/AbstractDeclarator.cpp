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

AbstractDeclarator::AbstractDeclarator(const AbstractDeclarator& other)
{
	pointer = other.pointer ? new Pointer(*other.pointer) : nullptr;
	directAbstractDeclarator = other.directAbstractDeclarator ? new DirectAbstractDeclarator(*other.directAbstractDeclarator) : nullptr;
}

AbstractDeclarator::AbstractDeclarator(AbstractDeclarator&& other) noexcept
{
	pointer = other.pointer ? new Pointer(*other.pointer) : nullptr;
	directAbstractDeclarator = other.directAbstractDeclarator ? new DirectAbstractDeclarator(*other.directAbstractDeclarator) : nullptr;
}

AbstractDeclarator& AbstractDeclarator::operator=(const AbstractDeclarator& other)
{
	if (this == &other)
		return *this;
	pointer = other.pointer ? new Pointer(*other.pointer) : nullptr;
	directAbstractDeclarator = other.directAbstractDeclarator ? new DirectAbstractDeclarator(*other.directAbstractDeclarator) : nullptr;
	return *this;
}

AbstractDeclarator& AbstractDeclarator::operator=(AbstractDeclarator&& other) noexcept
{
	if (this == &other)
		return *this;
	pointer = other.pointer ? new Pointer(*other.pointer) : nullptr;
	directAbstractDeclarator = other.directAbstractDeclarator ? new DirectAbstractDeclarator(*other.directAbstractDeclarator) : nullptr;
	return *this;
}

Pointer* AbstractDeclarator::getPointer() const { return pointer; }
DirectAbstractDeclarator* AbstractDeclarator::getDirectAbstractDeclarator() const { return directAbstractDeclarator; }
bool AbstractDeclarator::isPointer() const { return pointer != nullptr; }
bool AbstractDeclarator::isDirectAbstractDeclarator() const { return directAbstractDeclarator != nullptr; }
