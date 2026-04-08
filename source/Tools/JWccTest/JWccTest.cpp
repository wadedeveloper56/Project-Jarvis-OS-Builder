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
		
		TEST_METHOD(TestMethod1)
		{
			shared_ptr<Compiler> compiler = make_shared<Compiler>();
			Assert::IsNotNull(compiler.get());
		}
	};
}
