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

			istringstream input("char var1; short var2; int var3; long var4; long long var5;  enum type { first, second } var6;	struct type2 { int a; long b; } var7; union type3 { int a; long b; } var8; int main(int argc, char* argv[]) { return 5; }");
			ostringstream output;
			int exitCode = -1;
			compiler->compileFile(input, output, exitCode);

			Assert::IsNotNull(output.str().c_str(), L"There should be output");
			Assert::IsTrue(compiler->hasProgramData(), L"Program data should not be null after allocation");
			auto data = compiler->getProgramData();
			Assert::IsNotNull(data.get(), L"Program data should not be null after allocation");
			Assert::IsNotNull(data->getProgram().get(), L"Program data should not be null after allocation");
			Assert::IsNotNull(data->getGenerator().get(), L"Program data should not be null after allocation");
			Assert::AreEqual(9L, (long)data->getProgram()->size(), L"Program data should have 9 elements after allocation");

			shared_ptr<ExternalDeclaration>	func1 = data->getProgram()->at(0);
			AssertVariable(func1);
			AssertVariableNameAndType(func1, CHAR, "var1");

			shared_ptr<ExternalDeclaration>	func2 = data->getProgram()->at(1);
			AssertVariable(func2);
			AssertVariableNameAndType(func2, SHORT, "var2");

			shared_ptr<ExternalDeclaration>	func3 = data->getProgram()->at(2);
			AssertVariable(func3);
			AssertVariableNameAndType(func3, INT, "var3");

			shared_ptr<ExternalDeclaration>	func4 = data->getProgram()->at(3);
			AssertVariable(func4);
			AssertVariableNameAndType(func4, LONG, "var4");

			shared_ptr<ExternalDeclaration>	func5 = data->getProgram()->at(4);
			AssertVariable(func5);
			AssertVariableNameAndType(func5, LONG_LONG, "var5");

			shared_ptr<ExternalDeclaration>	func6 = data->getProgram()->at(5);
			AssertVariable(func6);
			AssertVariableNameAndType(func6, ENUM, "var6");

			shared_ptr<ExternalDeclaration>	func7 = data->getProgram()->at(6);
			AssertVariable(func7);
			AssertVariableNameAndType(func7, STRUCT, "var7");

			shared_ptr<ExternalDeclaration>	func8 = data->getProgram()->at(7);
			AssertVariable(func8);
			AssertVariableNameAndType(func8, UNION, "var8");

			shared_ptr<ExternalDeclaration>	func9 = data->getProgram()->at(8);
			AssertFunction(func9);

			compiler.reset();
			Assert::IsNull(compiler.get(), L"Pointer should be null after reset");
			Assert::AreEqual(0L, (long)compiler.use_count(), L"Use count should be 0 after reset");
		}
	};
}
