#include "pch.h"
#include "ExpressionTree.h"
#include "TypeName.h"

using namespace WadeSpace;

TreeNode* ExpressionTree::evaluate(ostream& out, void (*process)(ostream& out, TreeNodeData* left, TreeNodeData* right, TreeNodeData* current))
{
	return postOrderTraversal(out, tree, process);
}

TreeNode* ExpressionTree::postOrderTraversal(ostream& out, TreeNode* node, void (*process)(ostream& out, TreeNodeData* left, TreeNodeData* right, TreeNodeData* current))
{
	if (node == nullptr)
		return nullptr;
	if (node->getLeft() == nullptr && node->getRight() == nullptr)
	{
		if (process)
		{
			(*process)(out, nullptr, nullptr, node->getData());
		}
		return node;
	}
	TreeNode* left = postOrderTraversal(out, node->getLeft(), process);
	TreeNode* right = postOrderTraversal(out, node->getRight(), process);
	TreeNodeData* data = node->getData();
	if (data && process)
	{
		(*process)(out, left ? left->getData() : nullptr, right ? right->getData() : nullptr, data);
	}
	return node;
}

TreeNodeData::TreeNodeData(
	const NodeType type,
	const CTokenPtr token1,
	const CTokenPtr token2,
	ExpressionTree* const lexp,
	ExpressionTree* const exp1,
	ExpressionTree* const exp2,
	vector<ExpressionTree*>* argumentList,
	CTokenPtr identifier,
	vector<Initializer*>* initializerList,
	TypeName* typeName,
	CTokenPtr token3,
	Constant* constant,
	CTokenPtr op
)
{
	this->type = type;
	this->token1 = token1;
	this->token2 = token2;
	this->lexp = lexp;
	this->exp1 = exp1;
	this->exp2 = exp2;
	this->argumentList = argumentList;
	this->identifier = identifier;
	this->initializerList = initializerList;
	this->typeName = typeName;
	this->token3 = token3;
	this->constant = constant;
	this->op = op;
}

TreeNode::TreeNode(TreeNodeData* data, TreeNode* left, TreeNode* right)
{
	this->data = data;
	this->left = left;
	this->right = right;
}

ExpressionTree::ExpressionTree(TreeNode* data)
{
	stak = new stack<TreeNode*>();
	tree = data;
}
