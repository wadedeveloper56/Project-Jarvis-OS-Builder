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
			f_handle fh = OpenFile2("test.txt", _O_RDWR | _O_CREAT, _S_IREAD | _S_IWRITE);
			Assert::AreNotEqual(NIL_HANDLE, fh, L"File handle is invalid");
			CloseFile2(fh);
			DeleteFileA("test.txt");
		}
	};
}
