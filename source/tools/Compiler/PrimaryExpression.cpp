#include "PrimaryExpression.h"

using namespace WadeSpace;
using namespace std;

PrimaryExpression::PrimaryExpression(string identifier) : identifier(identifier), c(nullptr), exp(nullptr)
{
}

PrimaryExpression::PrimaryExpression(Constant* c) : identifier(identifier), c(c), exp(nullptr)
{
}

PrimaryExpression::PrimaryExpression(Expression* exp) : identifier(identifier), c(c), exp(exp)
{
}

PrimaryExpression::PrimaryExpression() : identifier(identifier), c(nullptr), exp(nullptr)
{
}

PrimaryExpression::~PrimaryExpression()
{
}
