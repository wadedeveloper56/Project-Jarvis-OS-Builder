#include "pch.h"
#include "BinaryFormat.h"

using namespace BinaryFormat;

MemoryMappedFile::MemoryMappedFile(char* filename) :buffer(nullptr), hFile(0), hMap(0), lpBasePtr(0)
{
	hFile = CreateFileA(filename, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		GetFileSizeEx(hFile, &fileSize);
		hMap = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 1024, L"MySharedMemory");
		if (hMap == NULL) {
			CloseHandle(hFile);
		}
		else {
			lpBasePtr = MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);
			if (lpBasePtr == NULL) {
				CloseHandle(hMap);
				CloseHandle(hFile);
			}
			else {
				buffer = static_cast<char*>(lpBasePtr);
			}
		}
	}
}

MemoryMappedFile::~MemoryMappedFile()
{
	UnmapViewOfFile(lpBasePtr);
	CloseHandle(hMap);
	CloseHandle(hFile);
}

char* MemoryMappedFile::getBuffer() const
{
	return buffer;
}

LONGLONG MemoryMappedFile::getFileSize() const
{
	return fileSize.QuadPart;
}