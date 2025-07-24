#include "EnumSpecifier.h"

using namespace WadeSpace;

EnumSpecifier::EnumSpecifier(vector<Enumerator*>* vectorEnumerator) : nameStr(""), vectorEnumerator(vectorEnumerator)
{
}

EnumSpecifier::EnumSpecifier(string&  nameStr, vector<Enumerator*>* vectorEnumerator) : nameStr(nameStr), vectorEnumerator(vectorEnumerator)
{
}

EnumSpecifier::EnumSpecifier(string&  nameStr) : nameStr(nameStr), vectorEnumerator(nullptr)
{
}

EnumSpecifier::EnumSpecifier() : nameStr(""), vectorEnumerator(nullptr)
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
