#include "pch.h"
#include <iostream>
#include "CppUnitTest.h"
#include "../JWccLib/pch.h"
#include "../JWccLib/ExpressionTree.h"
#include "../JWccLib/Constant.h"
#include "../JWccLib/debug.h"
#include "../JWccLib/main.h"
#include "../JWccLib/GlobalVars.h"
#include "../JWccLib/ProgramData.h"
#include "../JWccLib/JumpStatement.h"
#include "../JWccLib/Compile.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace WadeSpace;

namespace JWccLibTest
{
	void testprocess(ostream& out, TreeNodeData* left, TreeNodeData* right, TreeNodeData* current)
	{
		Assert::IsNotNull(current);
		//Assert::IsNotNull(left);
		//Assert::IsNotNull(right);
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

		TEST_METHOD(Compile_Function_Test1)
		{
			istringstream inStr("int main() { return 5; }");
			ostringstream outStr;
			int exitcode = 0;
			WadeSpace::compile.compileFile(inStr, outStr, exitcode);
			Assert::AreEqual(0, exitcode);	
			Assert::IsNotNull(WadeSpace::compile.getProgramData());
			Assert::IsNotNull(WadeSpace::compile.getProgramData()->getGenerator());

			auto generator = WadeSpace::compile.getProgramData()->getGenerator();
			Assert::AreEqual(1, (int)generator->getFunctionTable().size());
			Assert::AreEqual(0, (int)generator->getVariableTable().size());

			FunctionData* function = generator->getFunctionTable().at(0);
			Assert::IsNotNull(function);
			Assert::AreEqual("main", function->name.c_str());
			Assert::IsTrue(TokenType::INT == function->type);
			Assert::IsNotNull(function->statements);
			Assert::IsNotNull(function->statements->getStatementList());
			Assert::IsTrue(function->statements->getStatementList()->size() == 1);

			BaseStatement* statement = function->statements->getStatementList()->at(0);
			Assert::IsTrue(statement->getOp() == jump_statement);
			Assert::IsNotNull(dynamic_cast<JumpStatement*>(statement->getStatement()));

			WadeSpace::compile.~Compile();
		}

		TEST_METHOD(Compile_Variable_Test1)
		{
			istringstream inStr("char var1;");
			ostringstream outStr;
			int exitcode = 0;
			WadeSpace::compile.compileFile(inStr, outStr, exitcode);
			Assert::AreEqual(0, exitcode);
			Assert::IsNotNull(WadeSpace::compile.getProgramData());
			Assert::IsNotNull(WadeSpace::compile.getProgramData()->getGenerator());

			auto generator = WadeSpace::compile.getProgramData()->getGenerator();
			auto variableTable = generator->getVariableTable();
			auto functionTable = generator->getFunctionTable();
			auto varSize = variableTable.size();
			auto funcSize = functionTable.size();
			bool ve = varSize == 1;
			bool fe = funcSize == 0;
			Assert::IsTrue(fe,L"function table size");
			Assert::IsTrue(ve,L"variable table size");

			WadeSpace::compile.~Compile();
		}
	};
}
