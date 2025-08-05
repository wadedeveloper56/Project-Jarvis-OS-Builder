#include "UnaryExpression.h"
#include "PostfixExpression.h"
#include "CastExpression.h"

using namespace WadeSpace;
using namespace std;

UnaryExpression::UnaryExpression(PostfixExpression* postfixExpression) : postfixExpression(postfixExpression), castExpression(nullptr), vectorUnaryExpressionNode(nullptr), typeName(nullptr), op(nullopt)
{
}

void UnaryExpression::add(const string& str)
{
	UnaryExpressionNodePtr temp = new UnaryExpressionNode;
	temp->str = str;
	if (vectorUnaryExpressionNode == nullptr)  vectorUnaryExpressionNode = new vector<UnaryExpressionNode*>();
	vectorUnaryExpressionNode->push_back(temp);

}

UnaryExpression::UnaryExpression(const string& op, CastExpression* castExpression) : postfixExpression(nullptr), castExpression(castExpression), vectorUnaryExpressionNode(nullptr), typeName(nullptr), op(op)
{
}

UnaryExpression::UnaryExpression(const string& op, TypeName* typeName) : postfixExpression(nullptr), castExpression(nullptr), vectorUnaryExpressionNode(nullptr), typeName(typeName), op(op)
{
}

UnaryExpression::UnaryExpression() : postfixExpression(nullptr), castExpression(nullptr), vectorUnaryExpressionNode(nullptr), typeName(nullptr), op(nullopt)
{
}

UnaryExpression::~UnaryExpression()
{
	delete postfixExpression;
	delete castExpression;
	if (vectorUnaryExpressionNode!=nullptr)
	{
		for (UnaryExpressionNode* ptr :*vectorUnaryExpressionNode)
		{
			delete ptr;
		}
	}
	delete vectorUnaryExpressionNode;
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

vector<UnaryExpressionNode*>* UnaryExpression::getVectorUnaryExpressionNode() const
{
	return vectorUnaryExpressionNode;
}

CastExpression* UnaryExpression::getCastExpression() const
{
	return castExpression;
}

optional<string> UnaryExpression::getOp() const
{
	return op;
}
