#include "pch.h"
#include "Pointer.h"

using namespace WadeSpace;

Pointer::Pointer(const TokenPtr name, vector<TypeQualifier*>* typeQualifierList) : name(name), typeQualifierList(typeQualifierList), level(1), pointer(nullptr)
{
}

Pointer::Pointer(const TokenPtr name, vector<TypeQualifier*>* typeQualifierList, Pointer* pointer) : name(name), typeQualifierList(typeQualifierList), level(1), pointer(pointer)
{
}

Pointer::Pointer(const TokenPtr name, Pointer* pointer) : name(name), typeQualifierList(nullptr), level(1), pointer(pointer)
{
}

Pointer::Pointer(const TokenPtr name) : name(name), typeQualifierList(nullptr), level(1), pointer(nullptr)
{
}

Pointer::Pointer() : name(nullptr), typeQualifierList(nullptr), level(0), pointer(nullptr)
{
}

Pointer::~Pointer()
{
	if (typeQualifierList != NULL)
	{
		for (TypeQualifier* ptr : *typeQualifierList)
		{
			delete ptr;
		}
	}
	delete typeQualifierList;
	delete pointer;
}

void Pointer::inc() { level++; }
