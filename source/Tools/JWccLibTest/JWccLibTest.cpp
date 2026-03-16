#include "pch.h"
#include <iostream>
#include "CppUnitTest.h"
#include "../JWccLib/pch.h"
#include "../JWccLib/ExpressionTree.h"
#include "../JWccLib/Constant.h"
#include "../JWccLib/debug.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace WadeSpace;

namespace JWccLibTest
{
	void testprocess(ostream& out, TreeNodeData* left, TreeNodeData* right, TreeNodeData* current)
	{
		Assert::IsNotNull(current);
		Assert::IsNotNull(left);
		Assert::IsNotNull(right);
	}

	TEST_CLASS(JWccLibTest)
	{
	public:

		TEST_METHOD(ExpressionTree_ConstructionTest1)
		{
			const auto token1 = createConstantULLToken(5LL);
			Constant* constant1 = new Constant(token1, nullptr, nullptr, TokenType::INTEGER_CONSTANT);
			ExpressionTree* exp1 = createExpression(NodeType::NT_OP, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, constant1, nullptr, nullptr, nullptr);

			const auto token2 = createConstantULLToken(6LL);
			Constant* constant2 = new Constant(token2, nullptr, nullptr, TokenType::INTEGER_CONSTANT);
			ExpressionTree* exp2 = createExpression(NodeType::NT_OP, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, constant2, nullptr, nullptr, nullptr);

			ExpressionTree* root = createExpression(NodeType::NT_OP, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, exp1, createKeywordToken("+", PLUS_OP), exp2);

			Assert::IsNotNull(root);
			Assert::IsNotNull(root->getData()); 
			Assert::IsNotNull(root->getLeft()); 
			Assert::IsNotNull(root->getRight());
			Assert::IsNotNull(root->getLeft()->getData());
			Assert::IsNotNull(root->getRight()->getData());
			Assert::IsNull(root->getLeft()->getLeft());
			Assert::IsNull(root->getLeft()->getRight());
			Assert::IsNull(root->getRight()->getLeft());
			Assert::IsNull(root->getRight()->getRight());

			delete root;
		}

		TEST_METHOD(ExpressionTree_SingleNode_TraversalTest1)
		{
			const auto token1 = createConstantULLToken(5LL);
			Constant* constant1 = new Constant(token1, nullptr, nullptr, TokenType::INTEGER_CONSTANT);
			ExpressionTree* root = createExpression(NodeType::NT_OP, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, constant1, nullptr, nullptr, nullptr);

			Assert::IsNotNull(root);
			Assert::IsNotNull(root->getData());
			Assert::IsNull(root->getLeft());
			Assert::IsNull(root->getRight());

			ostringstream oss;
			TreeNode* result = root->postOrderTraversal(oss, root->getTree(), testprocess);

			Assert::IsNotNull(result);
			Assert::IsNotNull(result->getData());
			Assert::IsNull(result->getLeft());
			Assert::IsNull(result->getRight());

			delete root;
		}

		TEST_METHOD(ExpressionTree_MultiNode_TraversalTest1)
		{
			const auto token1 = createConstantULLToken(5LL);
			Constant* constant1 = new Constant(token1, nullptr, nullptr, TokenType::INTEGER_CONSTANT);
			ExpressionTree* exp1 = createExpression(NodeType::NT_OP, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, constant1, nullptr, nullptr, nullptr);

			const auto token2 = createConstantULLToken(6LL);
			Constant* constant2 = new Constant(token2, nullptr, nullptr, TokenType::INTEGER_CONSTANT);
			ExpressionTree* exp2 = createExpression(NodeType::NT_OP, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, constant2, nullptr, nullptr, nullptr);

			ExpressionTree* root = createExpression(NodeType::NT_OP, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, exp1, createKeywordToken("+", PLUS_OP), exp2);

			Assert::IsNotNull(root);
			Assert::IsNotNull(root->getData());
			Assert::IsNotNull(root->getLeft());
			Assert::IsNotNull(root->getRight());
			Assert::IsNotNull(root->getLeft()->getData());
			Assert::IsNotNull(root->getRight()->getData());
			Assert::IsNull(root->getLeft()->getLeft());
			Assert::IsNull(root->getLeft()->getRight());
			Assert::IsNull(root->getRight()->getLeft());
			Assert::IsNull(root->getRight()->getRight());

			ostringstream oss;
			root->postOrderTraversal(oss, root->getTree(), testprocess);
			
			delete root;
		}
	};
}
