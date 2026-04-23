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

		TokenType getDeclarationSpecifiersType(shared_ptr<DeclarationSpecifiers> declaration_specifiers)
		{
			TokenType type = UNKNOWN;
			auto type_specifierList = declaration_specifiers->getDeclarationSpecifiersNodeList();
			if (type_specifierList != nullptr)
			{
				for (shared_ptr<DeclarationSpecifiersNode> ptr : *type_specifierList)
				{
					if (ptr->getTypeSpecifier() != nullptr)
					{
						type = ptr->getTypeSpecifier()->getType().value();
					}
				}
			}
			return type;
		}

		void AssertFunction(shared_ptr<ExternalDeclaration>& func2, string expectedName, TokenType expectedType)
		{
			Assert::IsTrue(func2 != nullptr, L"ExternalDeclarationshould not be null after allocation");
			Assert::AreEqual(1L, (long)compiler.use_count(), L"Use count should be 1 after allocation");
			Assert::IsNotNull(func2->getFunctionDefinition().get(), L"Function definition should not be null");
			Assert::IsNull(func2->getDeclaration().get(), L"declaration should not be non-null");
			shared_ptr<DirectDeclarator> direct_declarator = func2->getFunctionDefinition()->getDeclarator()->getDirectDeclarator();
			string name = direct_declarator->getDirectDeclarator()->getIdentifier()->getSymbolName();
			Assert::AreEqual(expectedName, name, L"Function name should be main");
			Assert::IsTrue(func2->getFunctionDefinition()->hasDeclarationSpecifiers(), L"Function definition should have declaration specifiers");
			TokenType type = getDeclarationSpecifiersType(func2->getFunctionDefinition()->getDeclarationSpecifiers());
			Assert::AreEqual((int)expectedType, (int)type, L"Function type should be INT");
		}

		void AssertVariableNameAndType(shared_ptr<ExternalDeclaration>& func1, TokenType expectedType, string expectedName, int expectedArraySize)
		{
			shared_ptr<Declaration> declaration = func1->getDeclaration();
			auto var1 = func1->findType(declaration);
			Assert::IsTrue(var1 != nullptr, L"Variable should not be null");
			Assert::IsTrue(var1->hasType(), L"Variable should have type");
			Assert::IsTrue(var1->getType().value() == expectedType, L"Variable type should be INT");
			shared_ptr<vector<shared_ptr<InitDeclarator>>> initDeclaratorsList = declaration->getVectorInitDeclarator();
			shared_ptr<InitDeclarator> initDecl = initDeclaratorsList->at(0);
			shared_ptr<Declarator> declarator = initDecl->getDeclarator();
			Assert::IsTrue(declarator != nullptr, L"Declarator should not be null");
			shared_ptr<DirectDeclarator> dd = declarator->getDirectDeclarator();
			Assert::IsTrue(dd != nullptr, L"DirectDeclarator should not be null");
			Assert::IsTrue(initDecl != nullptr, L"InitDeclarator should not be null");
			Assert::IsTrue(initDecl->getVariableName() == expectedName, L"Variable name should be var1");
			unsigned long long arraySize = 1;
			if (dd->hasConstantExpression()) arraySize = dd->getConstantExpression()->getData()->getConstant()->getIConst()->getIntegerConst();
			Assert::AreEqual(expectedArraySize, (int)arraySize, L"Array size should be correct");
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
			AssertFunction(func, "main", INT);

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

			istringstream input("char var1; short var2; int var3; long var4; long long var5;	float var6;	double var7; long double var8; enum type { first, second } var9; struct type2 { int a; long b; } var10; union type3 { int a; long b; } var11; enum type4 { first, second }; struct type5 { int a; long b; }; union type6 { int a; long b; };	enum type4 var12; struct type5 var13;	union type6 var14;int main(int argc, char* argv[]){return 5;}");
			ostringstream output;
			int exitCode = -1;
			compiler->compileFile(input, output, exitCode);

			Assert::IsNotNull(output.str().c_str(), L"There should be output");
			Assert::IsTrue(compiler->hasProgramData(), L"Program data should not be null after allocation");
			auto data = compiler->getProgramData();
			Assert::IsNotNull(data.get(), L"Program data should not be null after allocation");
			Assert::IsNotNull(data->getProgram().get(), L"Program data should not be null after allocation");
			Assert::IsNotNull(data->getGenerator().get(), L"Program data should not be null after allocation");
			Assert::AreEqual(18L, (long)data->getProgram()->size(), L"Program data should have 18 elements after allocation");

			shared_ptr<ExternalDeclaration>	func1 = data->getProgram()->at(0);
			AssertVariable(func1);
			AssertVariableNameAndType(func1, CHAR, "var1", 1);

			shared_ptr<ExternalDeclaration>	func2 = data->getProgram()->at(1);
			AssertVariable(func2);
			AssertVariableNameAndType(func2, SHORTT, "var2", 1);

			shared_ptr<ExternalDeclaration>	func3 = data->getProgram()->at(2);
			AssertVariable(func3);
			AssertVariableNameAndType(func3, INT, "var3", 1);

			shared_ptr<ExternalDeclaration>	func4 = data->getProgram()->at(3);
			AssertVariable(func4);
			AssertVariableNameAndType(func4, LONG, "var4", 1);

			shared_ptr<ExternalDeclaration>	func5 = data->getProgram()->at(4);
			AssertVariable(func5);
			AssertVariableNameAndType(func5, LONG_LONG, "var5", 1);

			shared_ptr<ExternalDeclaration>	func6 = data->getProgram()->at(5);
			AssertVariable(func6);
			AssertVariableNameAndType(func6, FLOAT, "var6", 1);

			shared_ptr<ExternalDeclaration>	func7 = data->getProgram()->at(6);
			AssertVariable(func7);
			AssertVariableNameAndType(func7, DOUBLE, "var7", 1);

			shared_ptr<ExternalDeclaration>	func8 = data->getProgram()->at(7);
			AssertVariable(func8);
			AssertVariableNameAndType(func8, LONG_DOUBLE, "var8", 1);

			shared_ptr<ExternalDeclaration>	func9 = data->getProgram()->at(8);
			AssertVariable(func9);
			AssertVariableNameAndType(func9, ENUM, "var9", 1);

			shared_ptr<ExternalDeclaration>	func10 = data->getProgram()->at(9);
			AssertVariable(func10);
			AssertVariableNameAndType(func10, STRUCT, "var10", 1);

			shared_ptr<ExternalDeclaration>	func11 = data->getProgram()->at(10);
			AssertVariable(func11);
			AssertVariableNameAndType(func11, UNION, "var11", 1);

			shared_ptr<ExternalDeclaration>	func12 = data->getProgram()->at(11);
			AssertVariable(func12);

			shared_ptr<ExternalDeclaration>	func13 = data->getProgram()->at(12);
			AssertVariable(func13);

			shared_ptr<ExternalDeclaration>	func14 = data->getProgram()->at(13);
			AssertVariable(func14);

			shared_ptr<ExternalDeclaration>	func15 = data->getProgram()->at(14);
			AssertVariable(func15);
			AssertVariableNameAndType(func15, ENUM, "var12", 1);

			shared_ptr<ExternalDeclaration>	func16 = data->getProgram()->at(15);
			AssertVariable(func16);
			AssertVariableNameAndType(func16, STRUCT, "var13", 1);

			shared_ptr<ExternalDeclaration>	func17 = data->getProgram()->at(16);
			AssertVariable(func17);
			AssertVariableNameAndType(func17, UNION, "var14", 1);

			shared_ptr<ExternalDeclaration>	func18 = data->getProgram()->at(17);
			Assert::IsNotNull(func18.get(), L"Function should not be null");
			AssertFunction(func18, "main", INT);

			compiler.reset();
			Assert::IsNull(compiler.get(), L"Pointer should be null after reset");
			Assert::AreEqual(0L, (long)compiler.use_count(), L"Use count should be 0 after reset");
		}

		TEST_METHOD(Compiler_Basic_Function3)
		{
			compiler = make_shared<Compiler>();
			Assert::IsNotNull(compiler.get(), L"Pointer should not be null after allocation");
			Assert::IsTrue(compiler->hasProgramData(), L"Program data should not be null after allocation");
			Assert::IsTrue(compiler->hasTypedefList(), L"Typedef list should not be null after allocation");
			Assert::IsTrue(compiler->hasFunctionList(), L"Function list should not be null after allocation");
			Assert::IsTrue(compiler->hasStructList(), L"Struct list should not be null after allocation");
			Assert::AreEqual(1L, (long)compiler.use_count(), L"Use count should be 1 after allocation");

			istringstream input("char var1[5]; short var2[6]; int var3[7]; long var4[8]; long long var5[9]; float var6[10]; double var7[11]; long double var8[12]; enum type { first, second } var9[13]; struct type2 { int a; long b; } var10[14]; union type3 { int a; long b; } var11[15]; int main(int argc, char* argv[]) { return 5; }");
			ostringstream output;
			int exitCode = -1;
			compiler->compileFile(input, output, exitCode);

			Assert::IsNotNull(output.str().c_str(), L"There should be output");
			Assert::IsTrue(compiler->hasProgramData(), L"Program data should not be null after allocation");
			auto data = compiler->getProgramData();
			Assert::IsNotNull(data.get(), L"Program data should not be null after allocation");
			Assert::IsNotNull(data->getProgram().get(), L"Program data should not be null after allocation");
			Assert::IsNotNull(data->getGenerator().get(), L"Program data should not be null after allocation");
			Assert::AreEqual(12L, (long)data->getProgram()->size(), L"Program data should have 12 elements after allocation");

			shared_ptr<ExternalDeclaration>	func1 = data->getProgram()->at(0);
			AssertVariable(func1);
			AssertVariableNameAndType(func1, CHAR, "var1", 5);

			shared_ptr<ExternalDeclaration>	func2 = data->getProgram()->at(1);
			AssertVariable(func2);
			AssertVariableNameAndType(func2, SHORTT, "var2", 6);

			shared_ptr<ExternalDeclaration>	func3 = data->getProgram()->at(2);
			AssertVariable(func3);
			AssertVariableNameAndType(func3, INT, "var3", 7);

			shared_ptr<ExternalDeclaration>	func4 = data->getProgram()->at(3);
			AssertVariable(func4);
			AssertVariableNameAndType(func4, LONG, "var4", 8);

			shared_ptr<ExternalDeclaration>	func5 = data->getProgram()->at(4);
			AssertVariable(func5);
			AssertVariableNameAndType(func5, LONG_LONG, "var5", 9);

			shared_ptr<ExternalDeclaration>	func6 = data->getProgram()->at(5);
			AssertVariable(func6);
			AssertVariableNameAndType(func6, FLOAT, "var6", 10);

			shared_ptr<ExternalDeclaration>	func7 = data->getProgram()->at(6);
			AssertVariable(func7);
			AssertVariableNameAndType(func7, DOUBLE, "var7", 11);

			shared_ptr<ExternalDeclaration>	func8 = data->getProgram()->at(7);
			AssertVariable(func8);
			AssertVariableNameAndType(func8, LONG_DOUBLE, "var8", 12);

			shared_ptr<ExternalDeclaration>	func9 = data->getProgram()->at(8);
			AssertVariable(func9);
			AssertVariableNameAndType(func9, ENUM, "var9", 13);

			shared_ptr<ExternalDeclaration>	func10 = data->getProgram()->at(9);
			AssertVariable(func10);
			AssertVariableNameAndType(func10, STRUCT, "var10", 14);

			shared_ptr<ExternalDeclaration>	func11 = data->getProgram()->at(10);
			AssertVariable(func11);
			AssertVariableNameAndType(func11, UNION, "var11", 15);

			shared_ptr<ExternalDeclaration>	func12 = data->getProgram()->at(11);
			Assert::IsNotNull(func12.get(), L"Function should not be null");
			AssertFunction(func12, "main", INT);

			compiler.reset();
			Assert::IsNull(compiler.get(), L"Pointer should be null after reset");
			Assert::AreEqual(0L, (long)compiler.use_count(), L"Use count should be 0 after reset");
		}
	};
}
