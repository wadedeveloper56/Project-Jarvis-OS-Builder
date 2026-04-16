#include "pch.h"
#include "CppUnitTest.h"
#include "..\JWccLib\Compiler.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace WadeSpace;
using namespace std;

namespace JWccTest
{
	TEST_CLASS(JWccTest)
	{
	public:
		
		TEST_METHOD(Compiler_Basic_Structures)
		{
			compiler = make_shared<Compiler>();
			Assert::IsNotNull(compiler.get(), L"Pointer should not be null after allocation");
			Assert::IsTrue(compiler->hasProgramData(), L"Program data should not be null after allocation");
			Assert::IsTrue(compiler->hasTypedefList(), L"Typedef list should not be null after allocation");
			Assert::IsTrue(compiler->hasFunctionList(), L"Function list should not be null after allocation");
			Assert::IsTrue(compiler->hasStructList(), L"Struct list should not be null after allocation");
			Assert::AreEqual(1L, (long)compiler.use_count(), L"Use count should be 1 after allocation");
			compiler.reset();
			Assert::IsNull(compiler.get(), L"Pointer should be null after reset");
			Assert::AreEqual(0L, (long)compiler.use_count(), L"Use count should be 0 after reset");
		}

		void AssertVariable(shared_ptr<ExternalDeclaration>& func1)
		{
			Assert::IsTrue(func1 != nullptr, L"ExternalDeclarationshould not be null after allocation");
			Assert::AreEqual(1L, (long)compiler.use_count(), L"Use count should be 1 after allocation");
			auto funcDef = func1->getFunctionDefinition();
			auto variables = func1->getDeclaration();
			Assert::IsTrue(funcDef == nullptr, L"Function definition should not be non-null");
			Assert::IsTrue(variables != nullptr, L"declaration should not be null");
		}

		void AssertFunction(shared_ptr<ExternalDeclaration>& func2)
		{
			Assert::IsTrue(func2 != nullptr, L"ExternalDeclarationshould not be null after allocation");
			Assert::AreEqual(1L, (long)compiler.use_count(), L"Use count should be 1 after allocation");
			auto funcDef2 = func2->getFunctionDefinition();
			auto variables2 = func2->getDeclaration();
			Assert::IsTrue(funcDef2 != nullptr, L"Function definition should not be null");
			Assert::IsTrue(variables2 == nullptr, L"declaration should not be non-null");
		}

		void AssertVariableNameAndType(shared_ptr<ExternalDeclaration>& func1, TokenType expectedType, string expectedName)
		{
			shared_ptr<Declaration> declaration = func1->getDeclaration();
			auto var1 = func1->findType(declaration);
			Assert::IsTrue(var1 != nullptr, L"Variable should not be null");
			Assert::IsTrue(var1->hasType(), L"Variable should have type");
			Assert::IsTrue(var1->getType().value() == expectedType, L"Variable type should be INT");
			shared_ptr<vector<shared_ptr<InitDeclarator>>> initDeclaratorsList = declaration->getVectorInitDeclarator();
			shared_ptr<InitDeclarator> initDecl = initDeclaratorsList->at(0);
			Assert::IsTrue(initDecl != nullptr, L"InitDeclarator should not be null");
			Assert::IsTrue(initDecl->getVariableName() == expectedName, L"Variable name should be var1");
		}

		TEST_METHOD(Compiler_Basic_Function1)
		{
			compiler = make_shared<Compiler>();
			Assert::IsNotNull(compiler.get(), L"Pointer should not be null after allocation");
			Assert::IsTrue(compiler->hasProgramData(), L"Program data should not be null after allocation");
			Assert::IsTrue(compiler->hasTypedefList(), L"Typedef list should not be null after allocation");
			Assert::IsTrue(compiler->hasFunctionList(), L"Function list should not be null after allocation");
			Assert::IsTrue(compiler->hasStructList(), L"Struct list should not be null after allocation");
			Assert::AreEqual(1L, (long)compiler.use_count(), L"Use count should be 1 after allocation");

			istringstream input("int main() { return 0; }");
			ostringstream output;
			int exitCode = -1;
			compiler->compileFile(input, output, exitCode);
			
			Assert::IsNotNull(output.str().c_str(), L"There should be output");
			Assert::IsTrue(compiler->hasProgramData(), L"Program data should not be null after allocation");
			auto data = compiler->getProgramData();
			Assert::IsTrue(data != nullptr, L"Program data should not be null after allocation");
			Assert::IsTrue(data->getProgram() != nullptr, L"Program data should not be null after allocation");
			Assert::IsTrue(data->getGenerator() != nullptr, L"Program data should not be null after allocation");
			Assert::IsTrue(data->getProgram()->size() == 1, L"Program data should not be null after allocation");
			
			auto func = data->getProgram()->at(0);
			AssertFunction(func);
			
			compiler.reset();
			Assert::IsNull(compiler.get(), L"Pointer should be null after reset");
			Assert::AreEqual(0L, (long)compiler.use_count(), L"Use count should be 0 after reset");
		}

		TEST_METHOD(Compiler_Basic_Function2)
		{
			compiler = make_shared<Compiler>();
			Assert::IsNotNull(compiler.get(), L"Pointer should not be null after allocation");
			Assert::IsTrue(compiler->hasProgramData(), L"Program data should not be null after allocation");
			Assert::IsTrue(compiler->hasTypedefList(), L"Typedef list should not be null after allocation");
			Assert::IsTrue(compiler->hasFunctionList(), L"Function list should not be null after allocation");
			Assert::IsTrue(compiler->hasStructList(), L"Struct list should not be null after allocation");
			Assert::AreEqual(1L, (long)compiler.use_count(), L"Use count should be 1 after allocation");

			istringstream input("int var1; int main() { return 0; }");
			ostringstream output;
			int exitCode = -1;
			compiler->compileFile(input, output, exitCode);

			Assert::IsNotNull(output.str().c_str(), L"There should be output");
			Assert::IsTrue(compiler->hasProgramData(), L"Program data should not be null after allocation");
			auto data = compiler->getProgramData();
			Assert::IsTrue(data != nullptr, L"Program data should not be null after allocation");
			Assert::IsTrue(data->getProgram() != nullptr, L"Program data should not be null after allocation");
			Assert::IsTrue(data->getGenerator() != nullptr, L"Program data should not be null after allocation");
			Assert::IsTrue(data->getProgram()->size() == 2, L"Program data should not be null after allocation");

			shared_ptr<ExternalDeclaration>	func1 = data->getProgram()->at(0);
			AssertVariable(func1);
			AssertVariableNameAndType(func1, INT, "var1");

			shared_ptr<ExternalDeclaration>	func2 = data->getProgram()->at(1);
			AssertFunction(func2);

			compiler.reset();
			Assert::IsNull(compiler.get(), L"Pointer should be null after reset");
			Assert::AreEqual(0L, (long)compiler.use_count(), L"Use count should be 0 after reset");
		}
	};
}
