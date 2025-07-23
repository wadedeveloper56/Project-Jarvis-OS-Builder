#include "AssignmentExpression.h"

using namespace WadeSpace;
using namespace std;

AssignmentExpression::AssignmentExpression(ConditionalExpression* conditionalExpression) : conditionalExpression(conditionalExpression), unaryExpression(nullptr), oper(nullptr), assignmentExpression(nullptr)
{
}

AssignmentExpression::AssignmentExpression(UnaryExpression* unaryExpression, AssignmentOperator* oper,
                                           AssignmentExpression* assignmentExpression) : conditionalExpression(nullptr), unaryExpression(unaryExpression), oper(oper), assignmentExpression(assignmentExpression)
{
}

AssignmentExpression::AssignmentExpression() : conditionalExpression(nullptr), unaryExpression(nullptr), oper(nullptr), assignmentExpression(nullptr)
{
}

AssignmentExpression::~AssignmentExpression()
{
	if (conditionalExpression != nullptr) delete conditionalExpression;
	if (unaryExpression != nullptr) delete unaryExpression;
	if (oper != nullptr) delete oper;
	if (assignmentExpression != nullptr) delete assignmentExpression;
}

ConditionalExpression* AssignmentExpression::getConditionalExpression() const
{
	return conditionalExpression;
}

UnaryExpression* AssignmentExpression::getUnaryExpression() const
{
	return unaryExpression;
}

AssignmentOperator* AssignmentExpression::getAssignmentOperator() const
{
	return oper;
}

AssignmentExpression* AssignmentExpression::getAssignmentExpression() const
{
	return assignmentExpression;
}
