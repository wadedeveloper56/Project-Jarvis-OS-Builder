#include "PostfixExpression.h"

using namespace WadeSpace;
using namespace std;

PostfixExpression::PostfixExpression(PrimaryExpression* primaryExpression) : primaryExpression(primaryExpression), postfixExpression(nullptr), expression(nullptr), vectorAssignmentExpression(nullptr),
vectorInitializer(nullptr), typeName(nullptr), str1(nullopt), str2(nullopt)
{
}

PostfixExpression::PostfixExpression(PostfixExpression* postfixExpression, const string& str, const string& str2) : primaryExpression(nullptr), postfixExpression(postfixExpression),
vectorAssignmentExpression(nullptr), expression(nullptr), vectorInitializer(nullptr), typeName(nullptr), str1(str1), str2(str2)
{
}

PostfixExpression::PostfixExpression(PostfixExpression* postfixExpression, Expression* expression) : primaryExpression(nullptr), postfixExpression(postfixExpression), expression(expression),
vectorAssignmentExpression(nullptr), vectorInitializer(nullptr), typeName(nullptr), str1(nullopt), str2(nullopt)
{
}

PostfixExpression::PostfixExpression(PostfixExpression* postfixExpression, vector<AssignmentExpression*>* vectorAssignmentExpression) : primaryExpression(nullptr),
postfixExpression(postfixExpression), expression(nullptr), vectorAssignmentExpression(vectorAssignmentExpression), vectorInitializer(nullptr), typeName(nullptr), str1(nullopt), str2(nullopt)
{
}

PostfixExpression::PostfixExpression(TypeName* typeName, vector<Initializer*>* vectorInitializer) : primaryExpression(nullptr), postfixExpression(nullptr), expression(nullptr),
vectorAssignmentExpression(nullptr), vectorInitializer(vectorInitializer), typeName(typeName), str1(nullopt),
str2(nullopt)
{
}

PostfixExpression::PostfixExpression() : primaryExpression(nullptr), postfixExpression(nullptr), expression(nullptr), vectorAssignmentExpression(nullptr), vectorInitializer(nullptr),
typeName(nullptr), str1(nullopt), str2(nullopt)
{
}

PostfixExpression::~PostfixExpression()
{
	delete primaryExpression;
	delete postfixExpression;
	delete expression;
	delete vectorAssignmentExpression;
	delete vectorInitializer;
	delete typeName;
}

PrimaryExpression* PostfixExpression::getPrimaryExpression() const
{
	return primaryExpression;
}

PostfixExpression* PostfixExpression::getPostfixExpression() const
{
	return postfixExpression;
}

Expression* PostfixExpression::getExpression() const
{
	return expression;
}

vector<AssignmentExpression*>* PostfixExpression::getVectorAssignmentExpression() const
{
	return vectorAssignmentExpression;
}

vector<Initializer*>* PostfixExpression::getVectorInitializer() const
{
	return vectorInitializer;
}

TypeName* PostfixExpression::getTypeName() const
{
	return typeName;
}

optional<string> PostfixExpression::getStr1() const
{
	return str1;
}

optional<string> PostfixExpression::getStr2() const
{
	return str2;
}
