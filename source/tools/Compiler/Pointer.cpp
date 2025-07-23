#include "Pointer.h"

using namespace WadeSpace;

Pointer::Pointer(const string&  value, vector<TypeQualifier*>* list) : nameStr(value), list(list), level(1), ptr(nullptr)
{
}

Pointer::Pointer(const string&  value, vector<TypeQualifier*>* list, Pointer* ptr) : nameStr(value), list(list), level(1), ptr(ptr)
{
}

Pointer::Pointer(const string&  value, Pointer* ptr) : nameStr(value), list(nullptr), level(1), ptr(ptr)
{
}

Pointer::Pointer(const string&  value) : nameStr(value), list(nullptr), level(1), ptr(nullptr)
{
}

Pointer::Pointer() : nameStr(""), list(nullptr), level(1), ptr(nullptr)
{
}

Pointer::~Pointer()
{
    for (TypeQualifier* ptr : *list)
    {
        delete ptr;
    }
    delete list;
    delete ptr;
}

void Pointer::inc() { level++; }
