#include "pch.h"
#include "ExpressionTree.h"
#include "TypeName.h"

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

TreeNodeData::TreeNodeData(const TreeNodeData& other)
{
	token1 = other.token1 ? new Token(*other.token1) : nullptr;
	token2 = other.token2 ? new Token(*other.token2) : nullptr;
	lexp = other.lexp ? new ExpressionTree(*other.lexp) : nullptr;
	exp1 = other.exp1 ? new ExpressionTree(*other.exp1) : nullptr;
   	exp2 = other.exp2 ? new ExpressionTree(*other.exp2) : nullptr;
   	argumentList = other.argumentList ? new vector<ExpressionTree*>(*other.argumentList) : nullptr;
   	identifier = other.identifier ? new Token(*other.identifier) : nullptr;
   	initializerList = other.initializerList ? new vector<Initializer*>(*other.initializerList) : nullptr;
   	typeName = other.typeName ? new TypeName(*other.typeName) : nullptr;
   	token3 = other.token3 ? new Token(*other.token3) : nullptr;
   	constant = other.constant ? new Constant(*other.constant) : nullptr;
   	op = other.op ? new Token(*other.op) : nullptr;
}

TreeNodeData::TreeNodeData(TreeNodeData&& other) noexcept
{
    token1 = other.token1 ? new Token(*other.token1) : nullptr;
    token2 = other.token2 ? new Token(*other.token2) : nullptr;
    lexp = other.lexp ? new ExpressionTree(*other.lexp) : nullptr;
    exp1 = other.exp1 ? new ExpressionTree(*other.exp1) : nullptr;
    exp2 = other.exp2 ? new ExpressionTree(*other.exp2) : nullptr;
    argumentList = other.argumentList ? new vector<ExpressionTree*>(*other.argumentList) : nullptr;
    identifier = other.identifier ? new Token(*other.identifier) : nullptr;
    initializerList = other.initializerList ? new vector<Initializer*>(*other.initializerList) : nullptr;
    typeName = other.typeName ? new TypeName(*other.typeName) : nullptr;
    token3 = other.token3 ? new Token(*other.token3) : nullptr;
    constant = other.constant ? new Constant(*other.constant) : nullptr;
    op = other.op ? new Token(*other.op) : nullptr;
}

TreeNodeData& TreeNodeData::operator=(const TreeNodeData& other)
{
    if (this != &other)
		return *this;
    token1 = other.token1 ? new Token(*other.token1) : nullptr;
    token2 = other.token2 ? new Token(*other.token2) : nullptr;
    lexp = other.lexp ? new ExpressionTree(*other.lexp) : nullptr;
    exp1 = other.exp1 ? new ExpressionTree(*other.exp1) : nullptr;
    exp2 = other.exp2 ? new ExpressionTree(*other.exp2) : nullptr;
    argumentList = other.argumentList ? new vector<ExpressionTree*>(*other.argumentList) : nullptr;
    identifier = other.identifier ? new Token(*other.identifier) : nullptr;
    initializerList = other.initializerList ? new vector<Initializer*>(*other.initializerList) : nullptr;
    typeName = other.typeName ? new TypeName(*other.typeName) : nullptr;
    token3 = other.token3 ? new Token(*other.token3) : nullptr;
    constant = other.constant ? new Constant(*other.constant) : nullptr;
    op = other.op ? new Token(*other.op) : nullptr;
    return *this;
}

TreeNodeData& TreeNodeData::operator=(TreeNodeData&& other) noexcept
{
    if (this != &other)
        return *this;
    token1 = other.token1 ? new Token(*other.token1) : nullptr;
    token2 = other.token2 ? new Token(*other.token2) : nullptr;
    lexp = other.lexp ? new ExpressionTree(*other.lexp) : nullptr;
    exp1 = other.exp1 ? new ExpressionTree(*other.exp1) : nullptr;
    exp2 = other.exp2 ? new ExpressionTree(*other.exp2) : nullptr;
    argumentList = other.argumentList ? new vector<ExpressionTree*>(*other.argumentList) : nullptr;
    identifier = other.identifier ? new Token(*other.identifier) : nullptr;
    initializerList = other.initializerList ? new vector<Initializer*>(*other.initializerList) : nullptr;
    typeName = other.typeName ? new TypeName(*other.typeName) : nullptr;
    token3 = other.token3 ? new Token(*other.token3) : nullptr;
    constant = other.constant ? new Constant(*other.constant) : nullptr;
    op = other.op ? new Token(*other.op) : nullptr;
    return *this;
}

NodeType TreeNodeData::getType() const { return type; }
TokenPtr TreeNodeData::getToken1() const { return token1; }
TokenPtr TreeNodeData::getToken2() const { return token2; }
TokenPtr TreeNodeData::getToken3() const { return token3; }
vector<ExpressionTree*>* TreeNodeData::getArgumentList() const { return argumentList; }
Constant* TreeNodeData::getConstant() const { return constant; }


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

TreeNode::TreeNode(const TreeNode& other)
{
    data = other.data ? new TreeNodeData(*other.data) : nullptr;
    left = other.left ? new TreeNode(*other.left) : nullptr;
    right = other.right ? new TreeNode(*other.right) : nullptr;
}

TreeNode::TreeNode(TreeNode&& other) noexcept
{
    data = other.data ? new TreeNodeData(*other.data) : nullptr;
    left = other.left ? new TreeNode(*other.left) : nullptr;
    right = other.right ? new TreeNode(*other.right) : nullptr;
}

TreeNode& TreeNode::operator=(const TreeNode& other)
{
    if (this != &other)
		return *this;
    data = other.data ? new TreeNodeData(*other.data) : nullptr;
    left = other.left ? new TreeNode(*other.left) : nullptr;
    right = other.right ? new TreeNode(*other.right) : nullptr;
    return *this;
}

TreeNode& TreeNode::operator=(TreeNode&& other) noexcept
{
    if (this != &other)
        return *this;
    data = other.data ? new TreeNodeData(*other.data) : nullptr;
    left = other.left ? new TreeNode(*other.left) : nullptr;
    right = other.right ? new TreeNode(*other.right) : nullptr;
    return *this;
}

TreeNodeData* TreeNode::getData() const { return data; }
TreeNode* TreeNode::getLeft() const { return left; }
TreeNode* TreeNode::getRight() const { return right; }

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
    if (stak) {
        while (!stak->empty()) {
            TreeNode* node = stak->top();
            stak->pop();
            delete node;
        }
	}
    delete stak;
    delete tree;
}


ExpressionTree::ExpressionTree(const ExpressionTree& other)
{
    stak = other.stak ? new stack<TreeNode*>(*other.stak) : nullptr;
    tree = other.tree ? new TreeNode(*other.tree) : nullptr;
}

ExpressionTree::ExpressionTree(ExpressionTree&& other) noexcept
{
    stak = other.stak ? new stack<TreeNode*>(*other.stak) : nullptr;
    tree = other.tree ? new TreeNode(*other.tree) : nullptr;
}

ExpressionTree& ExpressionTree::operator=(const ExpressionTree& other)
{
    if (this != &other)
		return *this;
    stak = other.stak ? new stack<TreeNode*>(*other.stak) : nullptr;
    tree = other.tree ? new TreeNode(*other.tree) : nullptr;
    return *this;
}

ExpressionTree& ExpressionTree::operator=(ExpressionTree&& other) noexcept
{
    if (this != &other)
        return *this;
    stak = other.stak ? new stack<TreeNode*>(*other.stak) : nullptr;
    tree = other.tree ? new TreeNode(*other.tree) : nullptr;
    return *this;
}

TreeNode* ExpressionTree::getTree() const { return tree; }
void ExpressionTree::setTree(TreeNode* tree) { this->tree = tree; }
TreeNodeData* ExpressionTree::getData() const { return tree ? tree->getData() : nullptr; }
TreeNode* ExpressionTree::getLeft() const { return tree ? tree->getLeft() : nullptr; }
TreeNode* ExpressionTree::getRight() const { return tree ? tree->getRight() : nullptr; }
