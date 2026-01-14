#include "Initializer.h"
#include "ExpressionNode.h"

using namespace WadeSpace;

Initializer::Initializer(ExpressionNode* assignmentExpression) : assignmentExpression(assignmentExpression), initializerList(nullptr)
{
}

Initializer::Initializer(vector<Initializer*>* initializerList) : assignmentExpression(nullptr), initializerList(initializerList)
{
}

Initializer::Initializer() : assignmentExpression(nullptr), initializerList(nullptr)
{
}

Initializer::~Initializer()
{
	delete assignmentExpression;
	for (Initializer* ptr : *initializerList)
	{
		delete ptr;
	}
	delete initializerList;
}

ExpressionNode* Initializer::getAssignmentExpression() const
{
	return assignmentExpression;
}

vector<Initializer*>* Initializer::getInitializerList() const
{
	return initializerList;
}
