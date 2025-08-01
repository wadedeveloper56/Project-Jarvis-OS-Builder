#include "Pointer.h"

using namespace WadeSpace;

Pointer::Pointer(const string& name, vector<TypeQualifier*>* typeQualifierList) : name(name), typeQualifierList(typeQualifierList), level(1), pointer(nullptr)
{
}

Pointer::Pointer(const string& name, vector<TypeQualifier*>* typeQualifierList, Pointer* pointer) : name(name), typeQualifierList(typeQualifierList), level(1), pointer(pointer)
{
}

Pointer::Pointer(const string& name, Pointer* pointer) : name(name), typeQualifierList(nullptr), level(1), pointer(pointer)
{
}

Pointer::Pointer(const string& name) : name(name), typeQualifierList(nullptr), level(1), pointer(nullptr)
{
}

Pointer::Pointer() : name(nullopt), typeQualifierList(nullptr), level(0), pointer(nullptr)
{
}

Pointer::~Pointer()
{
	for (TypeQualifier* ptr : *typeQualifierList)
	{
		delete ptr;
	}
	delete typeQualifierList;
	delete pointer;
}

void Pointer::inc() { level++; }
