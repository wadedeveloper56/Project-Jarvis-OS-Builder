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
			FreeMemory(buffer);
		}
		TEST_METHOD(ReallocateMemory_NotNull)
		{
			void* buffer = AllocateMemory(1024);
			size_t size1 = _msize(buffer);
			Assert::IsNotNull(buffer, L"Memory allocation failure");
			buffer = ReallocateMemory(buffer, 2048);
			size_t size2 = _msize(buffer);
			Assert::IsNotNull(buffer, L"Memory reallocation failure");
			Assert::AreNotEqual(size1, size2, L"Memory reallocation size failure");
			FreeMemory(buffer);
		}
	};
}
