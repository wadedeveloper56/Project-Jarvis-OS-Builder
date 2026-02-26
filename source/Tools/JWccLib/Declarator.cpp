#include "pch.h"
#include "Declarator.h"
#include "GlobalVars.h"

using namespace WadeSpace;
using namespace std;

Declarator::Declarator(Pointer* pointer, DirectDeclarator* directDeclarator) : directDeclarator(directDeclarator),
                                                                               pointer(pointer)
{
}

Declarator::Declarator() : directDeclarator(nullptr), pointer(nullptr)
{
}

Declarator::~Declarator()
{
	delete directDeclarator;
	delete pointer;
}

Declarator::Declarator(const Declarator& other)
{
	directDeclarator = other.directDeclarator ? new DirectDeclarator(*other.directDeclarator) : nullptr;
	pointer = other.pointer ? new Pointer(*other.pointer) : nullptr;
}

Declarator::Declarator(Declarator&& other) noexcept
{
	directDeclarator = other.directDeclarator ? new DirectDeclarator(*other.directDeclarator) : nullptr;
	pointer = other.pointer ? new Pointer(*other.pointer) : nullptr;
}

Declarator& Declarator::operator=(const Declarator& other)
{
	if (this == &other)
		return *this;
	directDeclarator = other.directDeclarator ? new DirectDeclarator(*other.directDeclarator) : nullptr;
	pointer = other.pointer ? new Pointer(*other.pointer) : nullptr;
	return *this;
}

Declarator& Declarator::operator=(Declarator&& other) noexcept
{
	if (this == &other)
		return *this;
	directDeclarator = other.directDeclarator ? new DirectDeclarator(*other.directDeclarator) : nullptr;
	pointer = other.pointer ? new Pointer(*other.pointer) : nullptr;
	return *this;
}

DirectDeclarator* Declarator::getDirectDeclarator() const
{
	return directDeclarator;
}

Pointer* Declarator::getPointer() const
{
	return pointer;
}

bool Declarator::isDirectDeclarator() const
{
	return directDeclarator != nullptr;
}

bool Declarator::isPointer() const
{
	return pointer != nullptr;
}
