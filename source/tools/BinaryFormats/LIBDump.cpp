#include "pch.h"
#include "framework.h"
#include "BinaryFormat.h"

using namespace std;

PSTR PszLongnames = 0;

void DisplayArchiveMemberHeader(PIMAGE_ARCHIVE_MEMBER_HEADER pArchHeader, DWORD fileOffset)
{
    printf("Archive Member Header (offset %08X):\n", fileOffset);

    printf("  Name:     %.16s", pArchHeader->Name);
    if (pArchHeader->Name[0] == '/' && isdigit(pArchHeader->Name[1]))
        printf("  (%s)\n", PszLongnames + atoi((char*)pArchHeader->Name + 1));
    printf("\n");

    char szDateAsLong[64];
    sprintf(szDateAsLong, "%.12s", pArchHeader->Date);
    time_t dateAsLong = atol(szDateAsLong);

    printf("  Date:     %.12s %s", pArchHeader->Date, get_ctime_stg(&dateAsLong));
    printf("  UserID:   %.6s\n", pArchHeader->UserID);
    printf("  GroupID:  %.6s\n", pArchHeader->GroupID);
    printf("  Mode:     %.8s\n", pArchHeader->Mode);
    printf("  Size:     %.10s\n", pArchHeader->Size);
}

LIBFilePtr loadLibFile(char* buffer, LONGLONG fileSize)
{
	LIBFilePtr ptr = new LIBFile;
	PIMAGE_ARCHIVE_MEMBER_HEADER pArchHeader = MakePtr(PIMAGE_ARCHIVE_MEMBER_HEADER, buffer, IMAGE_ARCHIVE_START_SIZE);
    DWORD fileOffset = (DWORD)((PBYTE)pArchHeader - (PBYTE)buffer);
    DisplayArchiveMemberHeader(pArchHeader, fileOffset);
	return ptr;
}