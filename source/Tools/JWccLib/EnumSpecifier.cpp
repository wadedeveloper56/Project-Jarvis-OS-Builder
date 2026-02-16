#include "pch.h"
#include "EnumSpecifier.h"

#include "Token.h"

using namespace WadeSpace;

EnumSpecifier::EnumSpecifier(TokenPtr nameStr, vector<Enumerator*>* vectorEnumerator) : nameStr(nameStr), vectorEnumerator(vectorEnumerator)
{
}

EnumSpecifier::EnumSpecifier() : nameStr(nullptr), vectorEnumerator(nullptr)
{
}

EnumSpecifier::~EnumSpecifier()
{
	for (Enumerator* ptr : *vectorEnumerator)
	{
		delete ptr;
	}
	delete vectorEnumerator;
}

vector<Enumerator*>* EnumSpecifier::getVectorEnumerator() const
{
	return vectorEnumerator;
}
