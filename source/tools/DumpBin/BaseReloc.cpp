#include "pch.h"
#include "BaseReloc.h"
#include "Public.h"

PCSTR GetBaseRelocType(WORD Type)
{
	PCSTR TypeString = NULL;

	switch (Type) {
		case IMAGE_REL_BASED_ABSOLUTE:
			TypeString = "ABSOLUTE";
			break;
		case IMAGE_REL_BASED_HIGH:
			TypeString = "HIGH";
			break;
		case IMAGE_REL_BASED_LOW:
			TypeString = "LOW";
			break;
		case IMAGE_REL_BASED_HIGHLOW:
			TypeString = "HIGHLOW";
			break;
		case IMAGE_REL_BASED_HIGHADJ:
			TypeString = "HIGHADJ";
			break;
		case IMAGE_REL_BASED_MACHINE_SPECIFIC_5:
			TypeString = "MACHINE_SPECIFIC_5";
			break;
		case IMAGE_REL_BASED_RESERVED:
			TypeString = "RESERVED";
			break;
		case IMAGE_REL_BASED_MACHINE_SPECIFIC_7:
			TypeString = "MACHINE_SPECIFIC_7";
			break;
		case IMAGE_REL_BASED_MACHINE_SPECIFIC_8:
			TypeString = "MACHINE_SPECIFIC_8";
			break;
		case IMAGE_REL_BASED_MACHINE_SPECIFIC_9:
			TypeString = "MACHINE_SPECIFIC_9";
			break;
		case IMAGE_REL_BASED_DIR64:
			TypeString = "DIR64";
			break;
		default:
			//LOGA(ERROR_LEVEL, "Type:%#X", Type);
			TypeString = "unknown";
			break;
	}

	return TypeString;
}

DWORD BaseReloc(PBYTE Data, DWORD Size)
{
	DWORD ret = ERROR_SUCCESS;

	if (!IsValidPE(Data, Size)) {
		return ret;
	}

	IMAGE_DATA_DIRECTORY DataDirectory = { 0 };
	GetDataDirectory(Data, Size, IMAGE_DIRECTORY_ENTRY_BASERELOC, &DataDirectory);

	if (0 == DataDirectory.VirtualAddress) {
		printf("���ļ�û��BaseReloc.\n");
		return ret;
	}

	ULONG size = 0;
	PIMAGE_SECTION_HEADER FoundHeader = NULL;
	PIMAGE_BASE_RELOCATION BaseRelocDirectory = (PIMAGE_BASE_RELOCATION)
		ImageDirectoryEntryToDataEx(Data,
			FALSE,//ӳ�䣨MapViewOfFile������FALSE��ԭʼ��ȡ(�磺ReadFile)����TRUE�� 
			IMAGE_DIRECTORY_ENTRY_BASERELOC,
			&size, &FoundHeader);

	PIMAGE_NT_HEADERS NtHeaders = ImageNtHeader(Data);
	_ASSERTE(NtHeaders);

	printf("BaseReloc Directory Information:\n");

	PIMAGE_BASE_RELOCATION temp = (PIMAGE_BASE_RELOCATION)BaseRelocDirectory;

	//���Ը��������Ϣ����������š�

	for (DWORD Len = 0; Len < DataDirectory.Size; Len += temp->SizeOfBlock) {

		printf("VirtualAddress:%#010X, SizeOfBlock:%#010X.\n", temp->VirtualAddress, temp->SizeOfBlock);

		DWORD SizeOfBlock = temp->SizeOfBlock - sizeof(temp->SizeOfBlock) - sizeof(temp->SizeOfBlock);
		SizeOfBlock /= sizeof(DWORD);

		PBaseRelocBit BaseRelocBit = (PBaseRelocBit)((PBYTE)temp + sizeof(IMAGE_BASE_RELOCATION));

		for (DWORD i = 0; i < SizeOfBlock; i++) {
			printf("\tType:%#06X, %s, Offset:%#06X.\n",
				BaseRelocBit->Type,
				GetBaseRelocType(BaseRelocBit->Type), //�����ԣ����ֵ���ں���ķ�Χ�ڣ�˵�������������
				BaseRelocBit->Offset);

			BaseRelocBit++;
		}
	}

	return ret;
}
