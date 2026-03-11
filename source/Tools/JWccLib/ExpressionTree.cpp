#include "pch.h"
#include "ExpressionTree.h"

using namespace WadeSpace;

TreeNodeData::TreeNodeData()
{
    type = NT_NONE;
    token1 = nullptr;
    token2 = nullptr;
    lexp = nullptr;
    exp1 = nullptr;
    exp2 = nullptr;
    argumentList = nullptr;
    identifier = nullptr;
    initializerList = nullptr;
    typeName = nullptr;
    token3 = nullptr;
    constant = nullptr;
}

TreeNodeData::TreeNodeData(
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

TreeNodeData::~TreeNodeData()
{
    delete token1;
    delete token2;
    delete lexp;
    delete exp1;
    delete exp2;
    delete argumentList;
    delete identifier;
    delete initializerList;
    delete typeName;
    delete token3;
    delete constant;
}

TreeNode::TreeNode()
{
    data = nullptr;
    left = nullptr;
    right = nullptr;
}

TreeNode::TreeNode(TreeNodeData* data, TreeNode* left, TreeNode* right)
{
    this->data = data;
    this->left = left;
    this->right = right;
}

TreeNode::~TreeNode()
{
    delete data;
    delete left;
    delete right;
}

ExpressionTree::ExpressionTree()
{
    stak = new stack<TreeNode*>();
	tree = nullptr;
}

ExpressionTree::ExpressionTree(TreeNode* data)
{
    stak = new stack<TreeNode*>();
    tree = data;
}

ExpressionTree::~ExpressionTree()
{
    delete stak;
    delete tree;
}
