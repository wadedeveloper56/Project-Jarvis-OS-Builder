#include "pch.h"
#include "CppUnitTest.h"
#include "../Memory/Memory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MemoryTest
{
	TEST_CLASS(MemoryTest)
	{
	public:
		
		TEST_METHOD(AllocateMemory_NotNull)
		{
			void* buffer = AllocateMemory(1024);
			Assert::IsNotNull(buffer, L"Memory allocation failure");
		}
	};
}
