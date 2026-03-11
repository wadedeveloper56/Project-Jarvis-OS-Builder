#pragma once

#include "Token.h"
#include "Constant.h"

using namespace std;

namespace WadeSpace
{
	typedef enum _NodeType
	{
		NT_NONE, NT_ARRAY, NT_FUNCTION_CALL, NT_VAR_ACCESS, NT_INC, NT_DEC, NT_TYPECAST, NT_SIZEOF, NT_UNARY, NT_OP, NT_QUESTION
	} NodeType;

	class ExpressionTree;
	class AssignmentExpression;
	class Initializer;
	class TypeName;

	class TreeNodeData
	{
	public:
		NodeType type;
		TokenPtr token1;
		TokenPtr token2;
		ExpressionTree* lexp;
		ExpressionTree* exp1;
		ExpressionTree* exp2;
		vector<ExpressionTree*>* argumentList;
		TokenPtr identifier;
		vector<Initializer*>* initializerList;
		TypeName* typeName;
		TokenPtr token3;
		Constant* constant;
		TreeNodeData();
		TreeNodeData(
			const NodeType type,
			const TokenPtr token1,
			const TokenPtr token2,
			ExpressionTree* const lexp,
			ExpressionTree* const exp1,
			ExpressionTree* const exp2,
			vector<ExpressionTree*>* argumentList,
			TokenPtr identifier,
			vector<Initializer*>* initializerList,
			TypeName* typeName,
			TokenPtr token3,
			Constant* constant
		);
		~TreeNodeData();
	};

	class TreeNode
	{
	public:
		TreeNodeData* data;
		TreeNode* left;
		TreeNode* right;
		TreeNode();
		TreeNode(TreeNodeData* data, TreeNode* left = nullptr, TreeNode* right = nullptr);
		~TreeNode();
	};

	class ExpressionTree
	{
		stack<TreeNode*>* stak;
		TreeNode* tree;
	public:
		ExpressionTree();
		~ExpressionTree();
	};
}
