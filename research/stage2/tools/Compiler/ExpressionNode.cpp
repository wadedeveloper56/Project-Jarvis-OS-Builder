#include "ExpressionNode.h"

using namespace WadeSpace;

_Nodedata::_Nodedata() :type(NONE2), str(""), const1(nullptr), op(0), exp(nullptr), exp2(nullptr), exp3(nullptr), vectorAssignmentExpression(nullptr), vectorInitializer(nullptr), typeName(nullptr)
{
}

_Nodedata::~_Nodedata() {}


ExpressionNode::ExpressionNode(const string& identifier) :left(nullptr), op(0), right(nullptr)
{
	data = new NodeData;
	data->type = STRING;
	data->str = identifier;
}

ExpressionNode::ExpressionNode(Constant* constant) :left(nullptr), op(0), right(nullptr)
{
	data = new NodeData;
	data->type = CONSTANT;
	data->const1 = constant;
}

ExpressionNode::ExpressionNode(TypeName* typeName, ExpressionNode* exp) :left(nullptr), op(0), right(nullptr)
{
	data = new NodeData;
	data->type = CAST;
	data->typeName = typeName;
	data->exp = exp;
}

ExpressionNode::ExpressionNode(ExpressionNode* exp, ExpressionNode* exp2, ExpressionNode* exp3) :left(nullptr), op(0), right(nullptr)
{
	data = new NodeData;
	data->type = CONDITIONAL;
	data->exp = exp;
	data->exp2 = exp2;
	data->exp3 = exp3;
}

ExpressionNode::ExpressionNode(ExpressionNode* exp, int op, const string& identifier) :left(nullptr), op(0), right(nullptr)
{
	data = new NodeData;
	data->type = IDENTIFIER_TYPE;
	data->exp = exp;
	data->op = op;
	data->str = identifier;
}

ExpressionNode::ExpressionNode(ExpressionNode* exp, vector<ExpressionNode*>* vectorAssignmentExpression) :left(nullptr), op(0), right(nullptr)
{
	data = new NodeData;
	data->type = ARGUMENT_LIST;
	data->exp = exp;
	data->op = op;
	data->vectorAssignmentExpression = vectorAssignmentExpression;
}

ExpressionNode::ExpressionNode(TypeName* typeName, int op) :left(nullptr), op(0), right(nullptr)
{
	data = new NodeData;
	data->type = SIZEOF_TYPE;
	data->typeName = typeName;
	data->op = op;
}

ExpressionNode::ExpressionNode(TypeName* typeName, vector<Initializer*>* vectorInitializer) :data(nullptr), left(nullptr), op(0), right(nullptr)
{
	data = new NodeData;
	data->type = ARGUMENT_LIST;
	data->typeName = typeName;
	data->vectorInitializer = vectorInitializer;
}

ExpressionNode::ExpressionNode(ExpressionNode* left, int op, ExpressionNode* right) :data(nullptr), left(left), op(op), right(right)
{

}

ExpressionNode::ExpressionNode() :data(nullptr), left(nullptr), op(0), right(nullptr)
{

}

ExpressionNode::~ExpressionNode()
{
	delete data;
}
