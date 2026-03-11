#include "pch.h"
#include "CppUnitTest.h"
#include "../File/File.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FileTest
{
	TEST_CLASS(FileTest)
	{
	public:
		
		TEST_METHOD(OpenFile_NotNull)
		{
			f_handle fh;
			errno_t err = OpenFile2(&fh, "test.txt", _O_RDWR | _O_CREAT, _SH_DENYNO, _S_IREAD | _S_IWRITE);
			Assert::AreEqual(0, err, L"File open failure");
			Assert::AreNotEqual(NIL_HANDLE, fh, L"File handle is invalid");
			CloseFile2(fh);
			DeleteFileA("test.txt");
		}
	};
}
