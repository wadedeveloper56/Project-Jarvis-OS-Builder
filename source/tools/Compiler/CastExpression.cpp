#include "CastExpression.h"
#include "TypeName.h"

using namespace WadeSpace;
using namespace std;

CastExpression::CastExpression(UnaryExpression* ue) : unaryExpression(ue), type(nullptr), castExpression(nullptr)
{
}

CastExpression::CastExpression(TypeName* type, CastExpression* ce) : unaryExpression(nullptr), type(type), castExpression(ce)
{
}

CastExpression::CastExpression() : unaryExpression(nullptr), type(nullptr), castExpression(nullptr)
{
}

CastExpression::~CastExpression()
{
	delete unaryExpression;
	delete castExpression;
	delete type;
}

UnaryExpression* CastExpression::getUnaryExpression() const
{
	return unaryExpression;
}

TypeName* CastExpression::getType() const
{
	return type;
}

CastExpression* CastExpression::getCastExpression() const
{
	return castExpression;
}
