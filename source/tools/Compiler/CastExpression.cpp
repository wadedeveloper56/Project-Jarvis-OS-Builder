#include "CastExpression.h"

using namespace WadeSpace;
using namespace std;

CastExpression::CastExpression(UnaryExpression* ue) : ue(ue), type(nullptr), ce(nullptr)
{
}

CastExpression::CastExpression(TypeName* type, CastExpression* ce) : ue(nullptr), type(type), ce(ce)
{
}

CastExpression::CastExpression() : ue(nullptr), type(nullptr), ce(nullptr)
{
}

CastExpression::~CastExpression()
{
	if (ue) delete ue;
	if (ce) delete ce;
	if (type) delete type;
}
