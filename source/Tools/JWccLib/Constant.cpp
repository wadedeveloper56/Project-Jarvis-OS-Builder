#include "pch.h"
#include "Constant.h"

using namespace WadeSpace;
using namespace std;

Constant::Constant(const CTokenPtr iConst, const CTokenPtr fConst, const CTokenPtr strConst, const optional<TokenType>& type) 
	: iConst(iConst),
	fConst(fConst),
	strConst(strConst),
	type(type)
{
}
