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
