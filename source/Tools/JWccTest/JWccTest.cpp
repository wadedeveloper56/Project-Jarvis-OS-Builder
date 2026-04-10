#include "pch.h"
#include "CppUnitTest.h"
#include "..\JWccLib\Compiler.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace WadeSpace;

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

		TEST_METHOD(Compiler_Basic_Function)
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
		}
	};
}
