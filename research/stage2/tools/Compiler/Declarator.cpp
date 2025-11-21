#include "Declarator.h"

#include <iostream>

#include "GlobalVars.h"

using namespace WadeSpace;
using namespace std;

Declarator::Declarator(Pointer* ptr, DirectDeclarator* directDeclarator) : directDeclarator(directDeclarator), pointer(ptr)
{
}

Declarator::Declarator(DirectDeclarator* directDeclarator) : directDeclarator(directDeclarator), pointer(nullptr)
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

DirectDeclarator* Declarator::getDirectDeclarator() const { return directDeclarator; }
Pointer* Declarator::getPointer() const { return pointer; }
