#include "EnumSpecifier.h"

using namespace WadeSpace;

EnumSpecifier::EnumSpecifier(vector<Enumerator*>* vectorEnumerator) : nameStr(nullopt), vectorEnumerator(vectorEnumerator)
{
}

EnumSpecifier::EnumSpecifier(string&  nameStr, vector<Enumerator*>* vectorEnumerator) : nameStr(nameStr), vectorEnumerator(vectorEnumerator)
{
}

EnumSpecifier::EnumSpecifier(string&  nameStr) : nameStr(nameStr), vectorEnumerator(nullptr)
{
}

EnumSpecifier::EnumSpecifier() : nameStr(nullopt), vectorEnumerator(nullptr)
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

bool EnumSpecifier::hasNameStr() const
{
	return nameStr.has_value();
}

string EnumSpecifier::getNameStr() const
{
	return nameStr.value();
}

vector<Enumerator*>* EnumSpecifier::getVectorEnumerator() const
{
	return vectorEnumerator;
}
