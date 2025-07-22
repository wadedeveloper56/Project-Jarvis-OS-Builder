#include "Pointer.h"

using namespace WadeSpace;

Pointer::Pointer(string value, vector<TypeQualifier*>* list) : nameStr(value), list(list), level(1), ptr(nullptr)
{
}

Pointer::Pointer(string value, vector<TypeQualifier*>* list, Pointer* ptr) : nameStr(value), list(list), level(1),
                                                                             ptr(ptr)
{
}

Pointer::Pointer(string value, Pointer* ptr) : nameStr(value), list(nullptr), level(1), ptr(ptr)
{
}

Pointer::Pointer(string value) : nameStr(value), list(nullptr), level(1), ptr(nullptr)
{
}

Pointer::Pointer() : nameStr(""), list(nullptr), level(1), ptr(nullptr)
{
}

Pointer::~Pointer()
{
}

void Pointer::inc() { level++; }
