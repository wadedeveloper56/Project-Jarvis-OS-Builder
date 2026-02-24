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

Pointer::Pointer(const Pointer& other)
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
	delete name;
	name = other.name ? new Token(*other.name) : nullptr;
	typeQualifierList = other.typeQualifierList ? new vector<TypeQualifier*>(*other.typeQualifierList) : nullptr;
	level = other.level;
	pointer = other.pointer ? new Pointer(*other.pointer) : nullptr;
}

Pointer::Pointer(Pointer&& other) noexcept
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
	delete name;
	name = other.name ? new Token(*other.name) : nullptr;
	typeQualifierList = other.typeQualifierList ? new vector<TypeQualifier*>(*other.typeQualifierList) : nullptr;
	level = other.level;
	pointer = other.pointer ? new Pointer(*other.pointer) : nullptr;
}

Pointer& Pointer::operator=(const Pointer& other)
{
	if (this == &other)
		return *this;
	if (typeQualifierList != NULL)
	{
		for (TypeQualifier* ptr : *typeQualifierList)
		{
			delete ptr;
		}
	}
	delete typeQualifierList;
	delete pointer;
	delete name;
	name = other.name ? new Token(*other.name) : nullptr;
	typeQualifierList = other.typeQualifierList ? new vector<TypeQualifier*>(*other.typeQualifierList) : nullptr;
	level = other.level;
	pointer = other.pointer ? new Pointer(*other.pointer) : nullptr;
	return *this;
}

Pointer& Pointer::operator=(Pointer&& other) noexcept
{
	if (this == &other)
		return *this;
	if (typeQualifierList != NULL)
	{
		for (TypeQualifier* ptr : *typeQualifierList)
		{
			delete ptr;
		}
	}
	delete typeQualifierList;
	delete pointer;
	delete name;
	name = other.name ? new Token(*other.name) : nullptr;
	typeQualifierList = other.typeQualifierList ? new vector<TypeQualifier*>(*other.typeQualifierList) : nullptr;
	level = other.level;
	pointer = other.pointer ? new Pointer(*other.pointer) : nullptr;
	return *this;
}
