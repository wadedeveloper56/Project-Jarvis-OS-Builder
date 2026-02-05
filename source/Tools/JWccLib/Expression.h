#pragma once

#include <string>
#include "Constant.h"
using namespace std;

namespace WadeSpace
{

	typedef enum _NodeType { NT_NONE, SIZEOF_TYPE, INITIALZER_LIST, ARGUMENT_LIST, IDENTIFIER_TYPE, CONDITIONAL, CAST, STRING, CONSTANT } NodeType;

	class Expression;
	class AssignmentExpression;
	class Initializer;
	class TypeName;

	typedef struct NodeData
	{
		NodeType type;
		optional<string> str;
		Constant* const1;
		int op;
		Expression* exp;
		Expression* exp2;
		Expression* exp3;
		vector<Expression*>* vectorAssignmentExpression;
		vector<Initializer*>* vectorInitializer;
		TypeName* typeName;
		NodeData();
		~NodeData() = default;
	} * NodeDataPtr;

	class Expression
	{
	public:
		Expression(const optional<string>& identifier, Constant* constant);
		Expression(TypeName* typeName, Expression* exp);
		Expression(TypeName* typeName, int op);
		Expression(Expression* left, int op, Expression* right);
		Expression(Expression* exp, int op, const string& identifier);
		Expression(Expression* exp, Expression* exp2, Expression* exp3);
		Expression(Expression* exp, vector<Expression*>* vectorAssignmentExpression);
		Expression(TypeName* typeName, vector<Initializer*>* vectorInitializer);
		Expression();
		~Expression();
	private:
		NodeDataPtr data;
		Expression* left;
		int op;
		Expression* right;
	};
}
