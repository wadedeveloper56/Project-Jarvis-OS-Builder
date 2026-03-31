#include "pch.h"
#include "EnumSpecifier.h"

#include "Token.h"

using namespace WadeSpace;

EnumSpecifier::EnumSpecifier(CTokenPtr nameStr, vector<Enumerator*>* vectorEnumerator) : nameStr(nameStr),vectorEnumerator(vectorEnumerator)
{
}
