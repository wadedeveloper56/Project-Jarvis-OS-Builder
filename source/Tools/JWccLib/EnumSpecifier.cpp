#include "pch.h"
#include "EnumSpecifier.h"

#include "Token.h"

using namespace WadeSpace;

EnumSpecifier::EnumSpecifier(TokenPtr nameStr, vector<Enumerator*>* vectorEnumerator) : nameStr(nameStr),vectorEnumerator(vectorEnumerator)
{
}

EnumSpecifier::EnumSpecifier() : nameStr(nullptr), vectorEnumerator(nullptr)
{
}

EnumSpecifier::~EnumSpecifier()
{
	delete nameStr;
	if (vectorEnumerator != nullptr)
	{
		for (auto ptr : *vectorEnumerator)
		{
			delete ptr;
		}
		delete vectorEnumerator;
	}
}

TokenPtr EnumSpecifier::getNameStr() const
{
	return nameStr;
}

vector<Enumerator*>* EnumSpecifier::getVectorEnumerator() const
{
	return vectorEnumerator;
}

bool EnumSpecifier::hasNameStr() const
{
	return nameStr != nullptr;
}

bool EnumSpecifier::hasVectorEnumerator() const
{
	return vectorEnumerator != nullptr;
}

EnumSpecifier::EnumSpecifier(const EnumSpecifier& other)
{
	delete nameStr;
	if (vectorEnumerator != nullptr)
	{
		for (auto ptr : *vectorEnumerator)
		{
			delete ptr;
		}
		delete vectorEnumerator;
	}
	nameStr = other.nameStr ? new Token(*other.nameStr) : nullptr;
	vectorEnumerator = other.vectorEnumerator ? new vector<Enumerator*>(*other.vectorEnumerator) : nullptr;
}

EnumSpecifier::EnumSpecifier(EnumSpecifier&& other) noexcept
{
	delete nameStr;
	if (vectorEnumerator != nullptr)
	{
		for (auto ptr : *vectorEnumerator)
		{
			delete ptr;
		}
		delete vectorEnumerator;
	}
	nameStr = other.nameStr ? new Token(*other.nameStr) : nullptr;
	vectorEnumerator = other.vectorEnumerator ? new vector<Enumerator*>(*other.vectorEnumerator) : nullptr;
}

EnumSpecifier& EnumSpecifier::operator=(const EnumSpecifier& other)
{
	if (this == &other)
		return *this;
	delete nameStr;
	if (vectorEnumerator != nullptr)
	{
		for (auto ptr : *vectorEnumerator)
		{
			delete ptr;
		}
		delete vectorEnumerator;
	}
	nameStr = other.nameStr ? new Token(*other.nameStr) : nullptr;
	vectorEnumerator = other.vectorEnumerator ? new vector<Enumerator*>(*other.vectorEnumerator) : nullptr;
	return *this;
}

EnumSpecifier& EnumSpecifier::operator=(EnumSpecifier&& other) noexcept
{
	if (this == &other)
		return *this;
	delete nameStr;
	if (vectorEnumerator != nullptr)
	{
		for (auto ptr : *vectorEnumerator)
		{
			delete ptr;
		}
		delete vectorEnumerator;
	}	nameStr = other.nameStr ? new Token(*other.nameStr) : nullptr;
	vectorEnumerator = other.vectorEnumerator ? new vector<Enumerator*>(*other.vectorEnumerator) : nullptr;
	return *this;
}
