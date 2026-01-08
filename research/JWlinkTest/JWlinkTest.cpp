#include "pch.h"
#include "CppUnitTest.h"
#include "Flag.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace JWlinkTest
{
	TEST_CLASS(JWlinkFlagTest)
	{
	public:
		TEST_METHOD(TestFlagOrEqual)
		{
			Flag flag;
			flag |= 0x004;
			Assert::AreEqual(flag.getFlag(), 0x004);
		}
		TEST_METHOD(TestFlagAndEqual)
		{
			Flag flag(0x004);
			flag &= ~0x004;
			Assert::AreEqual(flag.getFlag(), 0x0);
		}
		TEST_METHOD(TestFlagAndNotSet)
		{
			Flag flag;
			bool result = flag & 0x004;
			Assert::IsFalse(result, L"& failure");
		}
		TEST_METHOD(TestFlagAndSet)
		{
			Flag flag(0x004);
			bool result = flag & 0x004;
			Assert::IsTrue(result, L"& failure");
		}
	};
}
