#include "pch.h"
#include "framework.h"
#include "BinaryFormat.h"

using namespace std;

PSTR PszLongnames = 0;

DWORD ConvertBigEndian(DWORD bigEndian)
{
	DWORD temp = 0;
	temp |= bigEndian >> 24;
	temp |= ((bigEndian & 0x00FF0000) >> 8);
	temp |= ((bigEndian & 0x0000FF00) << 8);
	temp |= ((bigEndian & 0x000000FF) << 24);
	return temp;
}

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

void DumpFirstLinkerMember(PVOID p)
{
	DWORD cSymbols = *(PDWORD)p;
	PDWORD pMemberOffsets = MakePtr(PDWORD, p, 4);
	PSTR pSymbolName;
	unsigned i;

	cSymbols = ConvertBigEndian(cSymbols);
	pSymbolName = MakePtr(PSTR, pMemberOffsets, 4 * cSymbols);
	printf("First Linker Member:\n");
	printf("  Symbols:         %08X\n", cSymbols);
	printf("  MbrOffs   Name\n  --------  ----\n");
	for (i = 0; i < cSymbols; i++)
	{
		DWORD offset = ConvertBigEndian(*pMemberOffsets);
		printf("  %08X  %s\n", offset, pSymbolName);
		pMemberOffsets++;
		pSymbolName += strlen(pSymbolName) + 1;
	}
}

void DumpSecondLinkerMember(PVOID p)
{
	DWORD cArchiveMembers = *(PDWORD)p;
	PDWORD pMemberOffsets = MakePtr(PDWORD, p, 4);
	DWORD cSymbols;
	PSTR pSymbolName;
	PWORD pIndices;
	unsigned i;

	cArchiveMembers = cArchiveMembers;
	cSymbols = pMemberOffsets[cArchiveMembers];
	pIndices = MakePtr(PWORD, p, 4 + cArchiveMembers * sizeof(DWORD) + 4);
	pSymbolName = MakePtr(PSTR, pIndices, cSymbols * sizeof(WORD));
	printf("Second Linker Member:\n");
	printf("  Archive Members: %08X\n", cArchiveMembers);
	printf("  Symbols:         %08X\n", cSymbols);
	printf("  MbrOffs   Name\n  --------  ----\n");
	for (i = 0; i < cSymbols; i++)
	{
		printf("  %08X  %s\n", pMemberOffsets[pIndices[i] - 1], pSymbolName);
		pSymbolName += strlen(pSymbolName) + 1;
	}
}

void DumpLongnamesMember(PVOID p, DWORD len)
{
	PSTR pszName = (PSTR)p;
	DWORD offset = 0;
	PszLongnames = (PSTR)p;
	printf("Longnames:\n");
	while (offset < len)
	{
		unsigned cbString = lstrlenA(pszName) + 1;
		printf("  %05u: %s\n", offset, pszName);
		offset += cbString;
		pszName += cbString;
	}
}

void DumpObjFile(PIMAGE_FILE_HEADER pImageFileHeader)
{
}

LIBFilePtr loadLibFile(FileType fileType, char* lpFileBase, LONGLONG fileSize)
{
	LIBFilePtr ptr = new LIBFile;
	PIMAGE_ARCHIVE_MEMBER_HEADER pArchHeader;
	BOOL fSawFirstLinkerMember = FALSE;
	BOOL fSawSecondLinkerMember = FALSE;
	BOOL fBreak = FALSE;

	if (strncmp(lpFileBase, IMAGE_ARCHIVE_START, IMAGE_ARCHIVE_START_SIZE))
	{
		printf("Not a valid .LIB file - signature not found\n");
		return NULL;
	}
	pArchHeader = MakePtr(PIMAGE_ARCHIVE_MEMBER_HEADER, lpFileBase, IMAGE_ARCHIVE_START_SIZE);
	while (pArchHeader)
	{
		LIBFileEntryPtr entry = new LIBFileEntry;
		for (int i = 0; i < 16; i++) entry->header.Name[i] = pArchHeader->Name[i];
		for (int i = 0; i < 12; i++) entry->header.Date[i] = pArchHeader->Date[i];
		for (int i = 0; i < 6; i++) entry->header.UserID[i] = pArchHeader->UserID[i];
		for (int i = 0; i < 6; i++) entry->header.GroupID[i] = pArchHeader->GroupID[i];
		for (int i = 0; i < 8; i++) entry->header.Mode[i] = pArchHeader->Mode[i];
		for (int i = 0; i < 10; i++) entry->header.Size[i] = pArchHeader->Size[i];
		for (int i = 0; i < 2; i++) entry->header.EndHeader[i] = pArchHeader->EndHeader[i];

		DWORD thisMemberSize;
		DWORD fileOffset = (DWORD)((PBYTE)pArchHeader - (PBYTE)lpFileBase);
		DisplayArchiveMemberHeader(pArchHeader, fileOffset);
		printf("\n");
		if (!strncmp((char*)pArchHeader->Name, IMAGE_ARCHIVE_LINKER_MEMBER, 16))
		{
			if (!fSawFirstLinkerMember)
			{
				DumpFirstLinkerMember((PVOID)(pArchHeader + 1));
				printf("\n");
				fSawFirstLinkerMember = TRUE;
			}
			else if (!fSawSecondLinkerMember)
			{
				DumpSecondLinkerMember((PVOID)(pArchHeader + 1));
				printf("\n");
				fSawSecondLinkerMember = TRUE;
			}
		}
		else if (!strncmp((char*)pArchHeader->Name, IMAGE_ARCHIVE_LONGNAMES_MEMBER, 16))
		{
			DumpLongnamesMember((PVOID)(pArchHeader + 1), atoi((char*)pArchHeader->Size));
			printf("\n");
		}
		else
		{
			PIMAGE_FILE_HEADER pifh = (PIMAGE_FILE_HEADER)(pArchHeader + 1);
			WORD nSects = pifh->NumberOfSections;
			WORD nSzOpt = pifh->SizeOfOptionalHeader;
			PIMAGE_SECTION_HEADER pSections = MakePtr(PIMAGE_SECTION_HEADER, (pifh + 1), nSzOpt);
			PIMAGE_SECTION_HEADER last = pSections;
			if (nSects) {
				last = pSections + (nSects - 1);
			}
			DumpObjFile(pifh);
		}
		thisMemberSize = atoi((char*)pArchHeader->Size) + IMAGE_SIZEOF_ARCHIVE_MEMBER_HDR;
		thisMemberSize = (thisMemberSize + 1) & ~1;
		ptr->entrys.push_back(entry);
		pArchHeader = MakePtr(PIMAGE_ARCHIVE_MEMBER_HEADER, pArchHeader, thisMemberSize);
		if (strncmp((char*)pArchHeader->EndHeader, IMAGE_ARCHIVE_END, 2))
			break;
	}
	return ptr;
}