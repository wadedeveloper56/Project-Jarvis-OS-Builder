#include "UnaryExpression.h"
#include "PostfixExpression.h"
#include "CastExpression.h"

using namespace WadeSpace;
using namespace std;

UnaryExpression::UnaryExpression(PostfixExpression* postfixExpression) : postfixExpression(postfixExpression), castExpression(nullptr), unaryExpression(nullptr), typeName(nullptr), op(nullopt)
{
}

UnaryExpression::UnaryExpression(const string& op, UnaryExpression* unaryExpression) : postfixExpression(nullptr), castExpression(nullptr), unaryExpression(unaryExpression), typeName(nullptr), op(op)
{
}

UnaryExpression::UnaryExpression(const string& op, CastExpression* castExpression) : postfixExpression(nullptr), castExpression(castExpression), unaryExpression(nullptr), typeName(nullptr), op(op)
{
}

UnaryExpression::UnaryExpression(const string& op, TypeName* typeName) : postfixExpression(nullptr), castExpression(nullptr), unaryExpression(nullptr), typeName(typeName), op(op)
{
}

UnaryExpression::UnaryExpression() : postfixExpression(nullptr), castExpression(nullptr), unaryExpression(nullptr), typeName(nullptr), op(nullopt)
{
}

UnaryExpression::~UnaryExpression()
{
	delete postfixExpression;
	delete castExpression;
	delete unaryExpression;
	delete typeName;
}

PostfixExpression* UnaryExpression::getPostfixExpression() const
{
	return postfixExpression;
}

TypeName* UnaryExpression::getTypeName() const
{
	return typeName;
}

UnaryExpression* UnaryExpression::getUnaryExpression() const
{
	return unaryExpression;
}

CastExpression* UnaryExpression::getCastExpression() const
{
	return castExpression;
}

optional<string> UnaryExpression::getOp() const
{
	return op;
}
