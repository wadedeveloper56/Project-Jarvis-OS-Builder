#include "AssignmentExpression.h"

using namespace WadeSpace;
using namespace std;

AssignmentExpression::AssignmentExpression(ConditionalExpression* ce) : ce(ce), ue(nullptr), oper(nullptr), ae(nullptr)
{
}

AssignmentExpression::AssignmentExpression(UnaryExpression* ue, AssignmentOperator* oper,
                                           AssignmentExpression* ae) : ce(nullptr), ue(ue), oper(oper), ae(ae)
{
}

AssignmentExpression::AssignmentExpression() : ce(nullptr), ue(nullptr), oper(nullptr), ae(nullptr)
{
}

AssignmentExpression::~AssignmentExpression()
{
	if (ce != nullptr) delete ce;
	if (ue != nullptr) delete ue;
	if (oper != nullptr) delete oper;
	if (ae != nullptr) delete ae;
}

ConditionalExpression* AssignmentExpression::getConditionalExpression() const
{
	return ce;
}

UnaryExpression* AssignmentExpression::getUnaryExpression() const
{
	return ue;
}

AssignmentOperator* AssignmentExpression::getAssignmentOperator() const
{
	return oper;
}

AssignmentExpression* AssignmentExpression::getAssignmentExpression() const
{
	return ae;
}
