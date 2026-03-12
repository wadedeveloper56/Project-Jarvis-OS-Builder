#pragma once

#include "Token.h"
#include "Constant.h"
#include "NodeType.h"

using namespace std;

namespace WadeSpace
{
	class ExpressionTree;
	class AssignmentExpression;
	class Initializer;
	class TypeName;

	class TreeNodeData
	{
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
		TokenPtr op;
	public:
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
			Constant* constant,
			TokenPtr op
		);
		~TreeNodeData();

		TreeNodeData(const TreeNodeData& other);
		TreeNodeData(TreeNodeData&& other) noexcept;
		TreeNodeData& operator=(const TreeNodeData& other);
		TreeNodeData& operator=(TreeNodeData&& other) noexcept;

		NodeType getType() const;
		TokenPtr getToken1() const;
		TokenPtr getToken2() const;
		TokenPtr getToken3() const;
		vector<ExpressionTree*>* getArgumentList() const;
		Constant* getConstant() const;
	};

	class TreeNode
	{
		TreeNodeData* data;
		TreeNode* left;
		TreeNode* right;
	public:
		TreeNode();
		TreeNode(TreeNodeData* data, TreeNode* left = nullptr, TreeNode* right = nullptr);
		~TreeNode();

		TreeNode(const TreeNode& other);
		TreeNode(TreeNode&& other) noexcept;
		TreeNode& operator=(const TreeNode& other);
		TreeNode& operator=(TreeNode&& other) noexcept;

		TreeNodeData* getData() const;
		TreeNode* getLeft() const;
		TreeNode* getRight() const;
	};

	class ExpressionTree
	{
		stack<TreeNode*>* stak;
		TreeNode* tree;
	public:
		ExpressionTree();
		ExpressionTree(TreeNode* data);
		~ExpressionTree();

		ExpressionTree(const ExpressionTree& other);
		ExpressionTree(ExpressionTree&& other) noexcept;
		ExpressionTree& operator=(const ExpressionTree& other);
		ExpressionTree& operator=(ExpressionTree&& other) noexcept;

		TreeNode* getTree() const;
		void setTree(TreeNode* tree);
		TreeNodeData* getData() const;
		TreeNode* getLeft() const;
		TreeNode* getRight() const;
	};
}
