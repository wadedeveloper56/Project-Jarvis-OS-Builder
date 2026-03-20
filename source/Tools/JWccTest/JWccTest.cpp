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
			Compiler* compiler = new Compiler();
		}
	};
}
