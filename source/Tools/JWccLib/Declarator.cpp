#include "pch.h"
#include "Declarator.h"
#include "GlobalVars.h"

using namespace WadeSpace;
using namespace std;

Declarator::Declarator(Pointer* pointer, DirectDeclarator* directDeclarator) : directDeclarator(directDeclarator), pointer(pointer)
{
}
