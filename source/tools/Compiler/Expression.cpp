#include "Expression.h"

using namespace WadeSpace;
using namespace std;

Expression::Expression(AssignmentExpression* ae) : ae(ae), oper(""), exp(nullptr)
{
}

Expression::Expression(Expression* exp, const string& oper, AssignmentExpression* ae) : ae(ae), oper(oper), exp(exp)
{
}

Expression::Expression() : ae(nullptr), oper(""), exp(nullptr)
{
}

Expression::~Expression()
{
	delete ae;
	delete exp;
}
