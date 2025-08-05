#include "PostfixExpression.h"

using namespace WadeSpace;
using namespace std;

PostfixExpression::PostfixExpression(PrimaryExpression* primaryExpression) : primaryExpression(primaryExpression),
                                                                             vectorInitializer(nullptr),
                                                                             vectorPostfixExpressionNode(nullptr),
                                                                             typeName(nullptr)
{
}

PostfixExpression::PostfixExpression(TypeName* typeName, vector<Initializer*>* vectorInitializer) :
	primaryExpression(nullptr), vectorInitializer(vectorInitializer), vectorPostfixExpressionNode(nullptr),
	typeName(typeName)
{
}

PostfixExpression::PostfixExpression() : primaryExpression(nullptr), vectorInitializer(nullptr),
                                         vectorPostfixExpressionNode(nullptr), typeName(nullptr)
{
}

PostfixExpression::~PostfixExpression()
{

	delete primaryExpression;
	if (vectorInitializer != nullptr) {
		for (Initializer* ptr : *vectorInitializer)
		{
			delete ptr;
		}
	}
	delete vectorInitializer;
	if (vectorPostfixExpressionNode != nullptr) {
		for (PostfixExpressionNode* ptr : *vectorPostfixExpressionNode)
		{
			delete ptr;
		}
	}
	delete vectorPostfixExpressionNode;
	delete typeName;
}

void PostfixExpression::add(const string& str, const string& str2)
{
	PostfixExpressionNodePtr temp = new PostfixExpressionNode;
	temp->expression = nullptr;
	temp->str1 = str;
	temp->str2 = str2;
	temp->vectorAssignmentExpression = nullptr;
	if (vectorPostfixExpressionNode == nullptr)  vectorPostfixExpressionNode = new vector<PostfixExpressionNode*>();
	vectorPostfixExpressionNode->push_back(temp);
}

void PostfixExpression::add(Expression* expression)
{
	PostfixExpressionNodePtr temp = new PostfixExpressionNode;
	temp->expression = nullptr;
	temp->str1 = nullopt;
	temp->str2 = nullopt;
	temp->vectorAssignmentExpression = nullptr;
	if (vectorPostfixExpressionNode == nullptr)  vectorPostfixExpressionNode = new vector<PostfixExpressionNode*>();
	vectorPostfixExpressionNode->push_back(temp);
}

void PostfixExpression::add(vector<AssignmentExpression*>* vectorAssignmentExpression)
{
	PostfixExpressionNodePtr temp = new PostfixExpressionNode;
	temp->expression = nullptr;
	temp->str1 = nullopt;
	temp->str2 = nullopt;
	temp->vectorAssignmentExpression = vectorAssignmentExpression;
	if (vectorPostfixExpressionNode == nullptr)  vectorPostfixExpressionNode = new vector<PostfixExpressionNode*>();
	vectorPostfixExpressionNode->push_back(temp);
}

PrimaryExpression* PostfixExpression::getPrimaryExpression() const { return primaryExpression; }
vector<Initializer*>* PostfixExpression::getVectorInitializer() const { return vectorInitializer; }

vector<PostfixExpressionNode*>* PostfixExpression::getVectorPostfixExpressionNode() const
{
	return vectorPostfixExpressionNode;
}

TypeName* PostfixExpression::getTypeName() const { return typeName; }
