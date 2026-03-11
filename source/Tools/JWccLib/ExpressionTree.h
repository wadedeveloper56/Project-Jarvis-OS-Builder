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

		TreeNodeData(const TreeNodeData& other) = default;
		TreeNodeData(TreeNodeData&& other) noexcept = default;
		TreeNodeData& operator=(const TreeNodeData& other) = default;
		TreeNodeData& operator=(TreeNodeData&& other) noexcept = default;

		NodeType getType() const { return type; }
		TokenPtr getToken1() const { return token1; }
		TokenPtr getToken2() const { return token2; }
		TokenPtr getToken3() const { return token3; }
		vector<ExpressionTree*>* getArgumentList() const { return argumentList; }
		Constant* getConstant() const { return constant; }
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

		TreeNode(const TreeNode& other) = default;
		TreeNode(TreeNode&& other) noexcept = default;
		TreeNode& operator=(const TreeNode& other) = default;
		TreeNode& operator=(TreeNode&& other) noexcept = default;

		TreeNodeData* getData() const { return data; }
		TreeNode* getLeft() const { return left; }
		TreeNode* getRight() const { return right; }
	};

	class ExpressionTree
	{
		stack<TreeNode*>* stak;
		TreeNode* tree;
	public:
		ExpressionTree();
		ExpressionTree(TreeNode* data);
		~ExpressionTree();

		ExpressionTree(const ExpressionTree& other) = default;
		ExpressionTree(ExpressionTree&& other) noexcept = default;
		ExpressionTree& operator=(const ExpressionTree& other) = default;
		ExpressionTree& operator=(ExpressionTree&& other) noexcept = default;

		TreeNode* getTree() const { return tree; }
		void setTree(TreeNode* tree) { this->tree = tree; }
		TreeNodeData* getData() const { return tree ? tree->getData() : nullptr; }
		TreeNode* getLeft() const { return tree ? tree->getLeft() : nullptr; }
		TreeNode* getRight() const { return tree ? tree->getRight() : nullptr; }
	};
}
