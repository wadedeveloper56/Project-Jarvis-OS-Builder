#include "EnumSpecifier.h"

using namespace WadeSpace;

EnumSpecifier::EnumSpecifier(vector<Enumerator*>* list) : nameStr(""), list(list)
{
}

EnumSpecifier::EnumSpecifier(string value, vector<Enumerator*>* list) : nameStr(value), list(list)
{
}

EnumSpecifier::EnumSpecifier(string value) : nameStr(value), list(nullptr)
{
}

EnumSpecifier::EnumSpecifier() : nameStr(""), list(nullptr)
{
}

EnumSpecifier::~EnumSpecifier()
{
	for (Enumerator* ptr : *list)
	{
		delete ptr;
	}
	delete list;
}
