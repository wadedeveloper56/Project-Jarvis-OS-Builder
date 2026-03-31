#pragma once

#include <vector>
#include <stack>
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
		CTokenPtr token1;
		CTokenPtr token2;
		ExpressionTree* lexp;
		ExpressionTree* exp1;
		ExpressionTree* exp2;
		vector<ExpressionTree*>* argumentList;
		CTokenPtr identifier;
		vector<Initializer*>* initializerList;
		TypeName* typeName;
		CTokenPtr token3;
		Constant* constant;
		CTokenPtr op;
	public:
		TreeNodeData() = default;
		TreeNodeData(
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
		);
		virtual ~TreeNodeData() = default;
		TreeNodeData(const TreeNodeData& other) = default;
		TreeNodeData(TreeNodeData&& other) noexcept = default;
		TreeNodeData& operator=(const TreeNodeData& other) = default;
		TreeNodeData& operator=(TreeNodeData&& other) noexcept;
		[[nodiscard]] NodeType getType() const { return type; }
		[[nodiscard]] CTokenPtr getToken1() const { return token1; }
		[[nodiscard]] CTokenPtr getToken2() const { return token2; }
		[[nodiscard]] ExpressionTree* getLExp() const { return lexp; }
		[[nodiscard]] ExpressionTree* getExp1() const { return exp1; }
		[[nodiscard]] ExpressionTree* getExp2() const { return exp2; }
		[[nodiscard]] vector<ExpressionTree*>* getArgumentList() const { return argumentList; }
		[[nodiscard]] CTokenPtr getIdentifier() const { return identifier; }
		[[nodiscard]] vector<Initializer*>* getInitializerList() const { return initializerList; }
		[[nodiscard]] TypeName* getTypeName() const { return typeName; }
		[[nodiscard]] CTokenPtr getToken3() const { return token3; }
		[[nodiscard]] Constant* getConstant() const { return constant; }
		[[nodiscard]] CTokenPtr getOp() const { return op; }
		void setType(const NodeType type) { this->type = type; }
		void setToken1(const CTokenPtr token1) { this->token1 = token1; }
		void setToken2(const CTokenPtr token2) { this->token2 = token2; }
		void setLExp(ExpressionTree* lexp) { this->lexp = lexp; }
		void setExp1(ExpressionTree* exp1) { this->exp1 = exp1; }
		void setExp2(ExpressionTree* exp2) { this->exp2 = exp2; }
		void setArgumentList(vector<ExpressionTree*>* argumentList) { this->argumentList = argumentList; }
		void setIdentifier(CTokenPtr identifier) { this->identifier = identifier; }
		void setInitializerList(vector<Initializer*>* initializerList) { this->initializerList = initializerList; }
		void setTypeName(TypeName* typeName) { this->typeName = typeName; }
		void setToken3(CTokenPtr token3) { this->token3 = token3; }
		void setConstant(Constant* constant) { this->constant = constant; }
		void setOp(CTokenPtr op) { this->op = op; }
		bool hasToken1() const { return token1 != nullptr; }
		bool hasToken2() const { return token2 != nullptr; }
		bool hasLExp() const { return lexp != nullptr; }
		bool hasExp1() const { return exp1 != nullptr; }
		bool hasExp2() const { return exp2 != nullptr; }
		bool hasArgumentList() const { return argumentList != nullptr; }
		bool hasIdentifier() const { return identifier != nullptr; }
		bool hasInitializerList() const { return initializerList != nullptr; }
		bool hasTypeName() const { return typeName != nullptr; }
		bool hasToken3() const { return token3 != nullptr; }
		bool hasConstant() const { return constant != nullptr; }
		bool hasOp() const { return op != nullptr; }
		[[nodiscard]] CTokenPtr getIConst() const { return constant ? constant->getIConst() : nullptr; }
		[[nodiscard]] CTokenPtr getFConst() const { return constant ? constant->getFConst() : nullptr; }
		[[nodiscard]] CTokenPtr getStrConst() const { return constant ? constant->getStrConst() : nullptr; }
		[[nodiscard]] optional<TokenType> getTokenType() const { return constant ? constant->getType() : nullopt; }
	};

	class TreeNode
	{
		TreeNodeData* data;
		TreeNode* left;
		TreeNode* right;
	public:
		TreeNode() = default;
		TreeNode(TreeNodeData* data, TreeNode* left = nullptr, TreeNode* right = nullptr);
		virtual ~TreeNode() = default;
		TreeNode(const TreeNode& other) = default;
		TreeNode(TreeNode&& other) noexcept = default;
		TreeNode& operator=(const TreeNode& other) = default;
		TreeNode& operator=(TreeNode&& other) noexcept = default;
		[[nodiscard]] TreeNodeData* getData() const { return data; }
		[[nodiscard]] TreeNode* getLeft() const { return left; }
		[[nodiscard]] TreeNode* getRight() const { return right; }
		void setData(TreeNodeData* data) { this->data = data; }
		void setLeft(TreeNode* left) { this->left = left; }
		void setRight(TreeNode* right) { this->right = right; }
		bool hasData() const { return data != nullptr; }
		bool hasLeft() const { return left != nullptr; }
		bool hasRight() const { return right != nullptr; }
	};

	class ExpressionTree
	{
		stack<TreeNode*>* stak;
		TreeNode* tree;
	public:
		ExpressionTree() = default;
		ExpressionTree(TreeNode* data);
		~ExpressionTree() = default;
		ExpressionTree(const ExpressionTree& other) = default;
		ExpressionTree(ExpressionTree&& other) noexcept = default;
		ExpressionTree& operator=(const ExpressionTree& other) = default;
		ExpressionTree& operator=(ExpressionTree&& other) noexcept = default;
		TreeNode* evaluate(ostream& out, void (*process)(ostream& out, TreeNodeData* left, TreeNodeData* right, TreeNodeData* current));
		TreeNode* postOrderTraversal(ostream& out, TreeNode* node, void (*process)(ostream& out, TreeNodeData* left, TreeNodeData* right, TreeNodeData* current));
		[[nodiscard]] TreeNode* getTree() const { return tree; }
		[[nodiscard]] stack<TreeNode*>* getStak() const { return stak; }
		void setTree(TreeNode* tree) { this->tree = tree; }
		void setStak(stack<TreeNode*>* stak) { this->stak = stak; }
		bool hasTree() const { return tree != nullptr; }
		bool hasStak() const { return stak != nullptr; }
		[[nodiscard]] TreeNode* getLeft() const { return tree ? tree->getLeft() : nullptr; }
		[[nodiscard]] TreeNode* getRight() const { return tree ? tree->getRight() : nullptr; }
		[[nodiscard]] TreeNodeData* getData() const { return tree ? tree->getData() : nullptr; }
	};
}
