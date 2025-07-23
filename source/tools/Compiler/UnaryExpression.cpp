#include "UnaryExpression.h"
#include "PostfixExpression.h"
#include "CastExpression.h"

using namespace WadeSpace;
using namespace std;

UnaryExpression::UnaryExpression(PostfixExpression* pe) : pe(pe), ce(nullptr), ue(nullptr), tn(nullptr), op("")
{
}

UnaryExpression::UnaryExpression(const string&  op, UnaryExpression* ue) : pe(nullptr), ce(nullptr), ue(ue), tn(nullptr), op(op)
{
}

UnaryExpression::UnaryExpression(const string&  op, CastExpression* ce) : pe(nullptr), ce(ce), ue(nullptr), tn(nullptr), op(op)
{
}

UnaryExpression::UnaryExpression(const string&  op, TypeName* tn) : pe(nullptr), ce(nullptr), ue(nullptr), tn(tn), op(op)
{
}

UnaryExpression::UnaryExpression() : pe(nullptr), ce(nullptr), ue(nullptr), tn(nullptr), op("")
{
}

UnaryExpression::~UnaryExpression()
{
	delete pe;
	delete ce;
	delete ue;
	delete tn;
}
