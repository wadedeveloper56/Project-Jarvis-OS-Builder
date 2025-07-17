#include "Declarator.h"

using namespace WadeSpace;
using namespace std;

Declarator::Declarator(Pointer* ptr, DirectDeclarator* directDeclarator) :directDeclarator(directDeclarator), pointer(ptr) {}
Declarator::Declarator(DirectDeclarator* directDeclarator) :directDeclarator(directDeclarator), pointer(NULL) {}
Declarator::Declarator() :directDeclarator(NULL), pointer(NULL) {}
Declarator::~Declarator() {}
