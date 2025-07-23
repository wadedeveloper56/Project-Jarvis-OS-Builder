#include "PrimaryExpression.h"
#include "Expression.h"

using namespace WadeSpace;
using namespace std;

PrimaryExpression::PrimaryExpression(string identifier) : identifier(identifier), c(nullptr), exp(nullptr)
{
}

PrimaryExpression::PrimaryExpression(Constant* c) : identifier(""), c(c), exp(nullptr)
{
}

PrimaryExpression::PrimaryExpression(Expression* exp) : identifier(""), c(nullptr), exp(exp)
{
}

PrimaryExpression::PrimaryExpression() : identifier(""), c(nullptr), exp(nullptr)
{
}

PrimaryExpression::~PrimaryExpression()
{
	delete c;
	delete exp;
}
