#include "pch.h"
#include "Pointer.h"

using namespace WadeSpace;

Pointer::Pointer(const CTokenPtr name, vector<TypeQualifier*>* typeQualifierList) : name(name), typeQualifierList(typeQualifierList), level(1), pointer(nullptr)
{
}

Pointer::Pointer(const CTokenPtr name, vector<TypeQualifier*>* typeQualifierList, Pointer* pointer) : name(name), typeQualifierList(typeQualifierList), level(1), pointer(pointer)
{
}

Pointer::Pointer(const CTokenPtr name, Pointer* pointer) : name(name), typeQualifierList(nullptr), level(1), pointer(pointer)
{
}

Pointer::Pointer(const CTokenPtr name) : name(name), typeQualifierList(nullptr), level(1), pointer(nullptr)
{
}

void Pointer::inc() { level++; }

