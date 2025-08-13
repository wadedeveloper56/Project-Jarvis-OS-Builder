#pragma once

#include <string>
#include "Constant.h"
using namespace std;

namespace WadeSpace {

	typedef enum _NodeType { NONE2, SIZEOF_TYPE, INITIALZER_LIST, ARGUMENT_LIST, IDENTIFIER_TYPE, CONDITIONAL, CAST, STRING, CONSTANT } NodeType;
	
	class ExpressionNode;
	class AssignmentExpression;
	class Initializer;
	class TypeName;

	typedef struct _Nodedata {
		NodeType type;
		string str;
		Constant* const1;
		int op;
		ExpressionNode* exp;
		ExpressionNode* exp2;
		ExpressionNode* exp3;
		vector<ExpressionNode*>* vectorAssignmentExpression;
		vector<Initializer*>* vectorInitializer;
		TypeName* typeName;
		_Nodedata();
		~_Nodedata();
	}NodeData, * NodeDataPtr;

	class ExpressionNode
	{
	public:
		ExpressionNode(const string& identifier);
		ExpressionNode(Constant* constant);
		ExpressionNode(TypeName* typeName, ExpressionNode* exp);
		ExpressionNode(TypeName* typeName, int op);
		ExpressionNode(ExpressionNode* left, int op, ExpressionNode* right);
		ExpressionNode(ExpressionNode* exp, int op, const string& identifier);
		ExpressionNode(ExpressionNode* exp, ExpressionNode* exp2, ExpressionNode* exp3);
		ExpressionNode(ExpressionNode* exp, vector<ExpressionNode*>* vectorAssignmentExpression);
		ExpressionNode(TypeName* typeName, vector<Initializer*>* vectorInitializer);
		ExpressionNode();
		~ExpressionNode();
	private:
		NodeDataPtr data;
		ExpressionNode* left;
		int op;
		ExpressionNode* right;
	};
}
