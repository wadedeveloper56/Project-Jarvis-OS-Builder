#include "pch.h"
#include "Initializer.h"
#include "ExpressionTree.h"

using namespace WadeSpace;

Initializer::Initializer(ExpressionTree* assignmentExpression) : assignmentExpression(assignmentExpression), initializerList(nullptr)
{
}

Initializer::Initializer(vector<Initializer*>* initializerList) : assignmentExpression(nullptr), initializerList(initializerList)
{
}
