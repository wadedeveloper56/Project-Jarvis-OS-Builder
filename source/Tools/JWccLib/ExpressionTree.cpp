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
	token1 = other.token1 ? new CToken(*other.token1) : nullptr;
	token2 = other.token2 ? new CToken(*other.token2) : nullptr;
	lexp = other.lexp ? new ExpressionTree(*other.lexp) : nullptr;
	exp1 = other.exp1 ? new ExpressionTree(*other.exp1) : nullptr;
	exp2 = other.exp2 ? new ExpressionTree(*other.exp2) : nullptr;
	argumentList = other.argumentList ? new vector<ExpressionTree*>(*other.argumentList) : nullptr;
	identifier = other.identifier ? new CToken(*other.identifier) : nullptr;
	initializerList = other.initializerList ? new vector<Initializer*>(*other.initializerList) : nullptr;
	typeName = other.typeName ? new TypeName(*other.typeName) : nullptr;
	token3 = other.token3 ? new CToken(*other.token3) : nullptr;
	constant = other.constant ? new Constant(*other.constant) : nullptr;
	op = other.op ? new CToken(*other.op) : nullptr;
}

TreeNodeData::TreeNodeData(TreeNodeData&& other) noexcept
{
	token1 = other.token1 ? new CToken(*other.token1) : nullptr;
	token2 = other.token2 ? new CToken(*other.token2) : nullptr;
	lexp = other.lexp ? new ExpressionTree(*other.lexp) : nullptr;
	exp1 = other.exp1 ? new ExpressionTree(*other.exp1) : nullptr;
	exp2 = other.exp2 ? new ExpressionTree(*other.exp2) : nullptr;
	argumentList = other.argumentList ? new vector<ExpressionTree*>(*other.argumentList) : nullptr;
	identifier = other.identifier ? new CToken(*other.identifier) : nullptr;
	initializerList = other.initializerList ? new vector<Initializer*>(*other.initializerList) : nullptr;
	typeName = other.typeName ? new TypeName(*other.typeName) : nullptr;
	token3 = other.token3 ? new CToken(*other.token3) : nullptr;
	constant = other.constant ? new Constant(*other.constant) : nullptr;
	op = other.op ? new CToken(*other.op) : nullptr;
}

TreeNodeData& TreeNodeData::operator=(const TreeNodeData& other)
{
	if (this != &other)
		return *this;
	token1 = other.token1 ? new CToken(*other.token1) : nullptr;
	token2 = other.token2 ? new CToken(*other.token2) : nullptr;
	lexp = other.lexp ? new ExpressionTree(*other.lexp) : nullptr;
	exp1 = other.exp1 ? new ExpressionTree(*other.exp1) : nullptr;
	exp2 = other.exp2 ? new ExpressionTree(*other.exp2) : nullptr;
	argumentList = other.argumentList ? new vector<ExpressionTree*>(*other.argumentList) : nullptr;
	identifier = other.identifier ? new CToken(*other.identifier) : nullptr;
	initializerList = other.initializerList ? new vector<Initializer*>(*other.initializerList) : nullptr;
	typeName = other.typeName ? new TypeName(*other.typeName) : nullptr;
	token3 = other.token3 ? new CToken(*other.token3) : nullptr;
	constant = other.constant ? new Constant(*other.constant) : nullptr;
	op = other.op ? new CToken(*other.op) : nullptr;
	return *this;
}

TreeNodeData& TreeNodeData::operator=(TreeNodeData&& other) noexcept
{
	if (this != &other)
		return *this;
	token1 = other.token1 ? new CToken(*other.token1) : nullptr;
	token2 = other.token2 ? new CToken(*other.token2) : nullptr;
	lexp = other.lexp ? new ExpressionTree(*other.lexp) : nullptr;
	exp1 = other.exp1 ? new ExpressionTree(*other.exp1) : nullptr;
	exp2 = other.exp2 ? new ExpressionTree(*other.exp2) : nullptr;
	argumentList = other.argumentList ? new vector<ExpressionTree*>(*other.argumentList) : nullptr;
	identifier = other.identifier ? new CToken(*other.identifier) : nullptr;
	initializerList = other.initializerList ? new vector<Initializer*>(*other.initializerList) : nullptr;
	typeName = other.typeName ? new TypeName(*other.typeName) : nullptr;
	token3 = other.token3 ? new CToken(*other.token3) : nullptr;
	constant = other.constant ? new Constant(*other.constant) : nullptr;
	op = other.op ? new CToken(*other.op) : nullptr;
	return *this;
}

NodeType TreeNodeData::getType() const { return type; }
CTokenPtr TreeNodeData::getToken1() const { return token1; }
CTokenPtr TreeNodeData::getToken2() const { return token2; }
CTokenPtr TreeNodeData::getToken3() const { return token3; }
vector<ExpressionTree*>* TreeNodeData::getArgumentList() const { return argumentList; }
Constant* TreeNodeData::getConstant() const { return constant; }

[[nodiscard]] CTokenPtr TreeNodeData::getIConst() const { return constant ? constant->getIConst() : nullptr; }
[[nodiscard]] CTokenPtr TreeNodeData::getFConst() const { return constant ? constant->getFConst() : nullptr; }
[[nodiscard]] CTokenPtr TreeNodeData::getStrConst() const { return constant ? constant->getStrConst() : nullptr; }
[[nodiscard]] optional<TokenType> TreeNodeData::getTokenType() const { return constant ? constant->getType() : nullopt; }



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
	if (stak)
	{
		while (!stak->empty())
		{
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
