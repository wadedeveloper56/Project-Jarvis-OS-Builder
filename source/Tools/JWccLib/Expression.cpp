#include "pch.h"
#include "Expression.h"

using namespace WadeSpace;

_Nodedata::_Nodedata() :type(NT_NONE), str(""), const1(nullptr), op(0), exp(nullptr), exp2(nullptr), exp3(nullptr), vectorAssignmentExpression(nullptr), vectorInitializer(nullptr), typeName(nullptr)
{
}

_Nodedata::~_Nodedata() {}


Expression::Expression(string identifier, Constant* constant) :left(nullptr), op(0), right(nullptr)
{
	data = new NodeData;
	if (identifier != "")
	{
		data->type = STRING;
		data->str = identifier;
	}
	else
	{
		data->type = CONSTANT;
		data->const1 = constant;
	}
}

Expression::Expression(TypeName* typeName, Expression* exp) :left(nullptr), op(0), right(nullptr)
{
	data = new NodeData;
	data->type = CAST;
	data->typeName = typeName;
	data->exp = exp;
}

Expression::Expression(Expression* exp, Expression* exp2, Expression* exp3) :left(nullptr), op(0), right(nullptr)
{
	data = new NodeData;
	data->type = CONDITIONAL;
	data->exp = exp;
	data->exp2 = exp2;
	data->exp3 = exp3;
}

Expression::Expression(Expression* exp, int op, const string& identifier) :left(nullptr), op(0), right(nullptr)
{
	data = new NodeData;
	data->type = IDENTIFIER_TYPE;
	data->exp = exp;
	data->op = op;
	data->str = identifier;
}

Expression::Expression(Expression* exp, vector<Expression*>* vectorAssignmentExpression) :left(nullptr), op(0), right(nullptr)
{
	data = new NodeData;
	data->type = ARGUMENT_LIST;
	data->exp = exp;
	data->op = op;
	data->vectorAssignmentExpression = vectorAssignmentExpression;
}

Expression::Expression(TypeName* typeName, int op) :left(nullptr), op(0), right(nullptr)
{
	data = new NodeData;
	data->type = SIZEOF_TYPE;
	data->typeName = typeName;
	data->op = op;
}

Expression::Expression(TypeName* typeName, vector<Initializer*>* vectorInitializer) :data(nullptr), left(nullptr), op(0), right(nullptr)
{
	data = new NodeData;
	data->type = ARGUMENT_LIST;
	data->typeName = typeName;
	data->vectorInitializer = vectorInitializer;
}

Expression::Expression(Expression* left, int op, Expression* right) :data(nullptr), left(left), op(op), right(right)
{

}

Expression::Expression() :data(nullptr), left(nullptr), op(0), right(nullptr)
{

}

Expression::~Expression()
{
	delete data;
}
