#include "pch.h"
#include "Debug.h"
#include "Public.h"

PCSTR GetDebugType(DWORD Type)
{
	PCSTR TypeString = NULL;

	switch (Type) {
		case IMAGE_DEBUG_TYPE_UNKNOWN:
			TypeString = "UNKNOWN";
			break;
		case IMAGE_DEBUG_TYPE_COFF:
			TypeString = "COFF";
			break;
		case IMAGE_DEBUG_TYPE_CODEVIEW:
			TypeString = "CODEVIEW";
			break;
		case IMAGE_DEBUG_TYPE_FPO:
			TypeString = "FPO";
			break;
		case IMAGE_DEBUG_TYPE_MISC:
			TypeString = "MISC";
			break;
		case IMAGE_DEBUG_TYPE_EXCEPTION:
			TypeString = "EXCEPTION";
			break;
		case IMAGE_DEBUG_TYPE_FIXUP:
			TypeString = "FIXUP";
			break;
		case IMAGE_DEBUG_TYPE_OMAP_TO_SRC:
			TypeString = "OMAP_TO_SRC";
			break;
		case IMAGE_DEBUG_TYPE_OMAP_FROM_SRC:
			TypeString = "OMAP_FROM_SRC";
			break;
		case IMAGE_DEBUG_TYPE_BORLAND:
			TypeString = "BORLAND";
			break;
		case IMAGE_DEBUG_TYPE_RESERVED10:
			TypeString = "RESERVED10";
			break;
		case IMAGE_DEBUG_TYPE_CLSID:
			TypeString = "CLSID";
			break;
		case IMAGE_DEBUG_TYPE_VC_FEATURE:
			TypeString = "VC_FEATURE";
			break;
		case IMAGE_DEBUG_TYPE_POGO:
			TypeString = "POGO";
			break;
		case IMAGE_DEBUG_TYPE_ILTCG:
			TypeString = "ILTCG";
			break;
		case IMAGE_DEBUG_TYPE_MPX:
			TypeString = "MPX";
			break;
		case IMAGE_DEBUG_TYPE_REPRO:
			TypeString = "REPRO";
			break;
		case IMAGE_DEBUG_TYPE_EX_DLLCHARACTERISTICS:
			TypeString = "EX_DLLCHARACTERISTICS";
			break;
		default:
			//LOGA(ERROR_LEVEL, "Type:%#X", Type);
			TypeString = "未定义";
			break;
	}

	return TypeString;
}


void PrintDebug(PBYTE Data, PIMAGE_DEBUG_DIRECTORY DebugDirectory)
{
	PIMAGE_NT_HEADERS NtHeaders = ImageNtHeader(Data);
	_ASSERTE(NtHeaders);

	printf("Characteristics:%#010X.\n", DebugDirectory->Characteristics);//保留，必须为 0。

	CHAR TimeDateStamp[MAX_PATH] = { 0 };
	GetTimeDateStamp(DebugDirectory->TimeDateStamp, TimeDateStamp);
	printf("TimeDateStamp:%d (%#010X), %s.\n",
		DebugDirectory->TimeDateStamp,
		DebugDirectory->TimeDateStamp,
		TimeDateStamp);

	printf("Version:%d.%d.\n", DebugDirectory->MajorVersion, DebugDirectory->MinorVersion);

	printf("Type:%#010X, %s.\n", DebugDirectory->Type, GetDebugType(DebugDirectory->Type));

	printf("SizeOfData:%#010X.\n", DebugDirectory->SizeOfData);
	printf("AddressOfRawData:%#010X.\n", DebugDirectory->AddressOfRawData);//需进一步的解析。
	printf("PointerToRawData:%#010X.\n", DebugDirectory->PointerToRawData);//需进一步的解析。

	switch (DebugDirectory->Type) {
		case IMAGE_DEBUG_TYPE_UNKNOWN:

			break;
		case IMAGE_DEBUG_TYPE_COFF:
		{
			PIMAGE_COFF_SYMBOLS_HEADER CoffSymbolsHeader = (PIMAGE_COFF_SYMBOLS_HEADER)(Data + DebugDirectory->PointerToRawData);

			printf("NumberOfSymbols:%#010X.\n", CoffSymbolsHeader->NumberOfSymbols);
			printf("LvaToFirstSymbol:%#010X.\n", CoffSymbolsHeader->LvaToFirstSymbol);
			printf("NumberOfLinenumbers:%#010X.\n", CoffSymbolsHeader->NumberOfLinenumbers);
			printf("LvaToFirstLinenumber:%#010X.\n", CoffSymbolsHeader->LvaToFirstLinenumber);
			printf("RvaToFirstByteOfCode:%#010X.\n", CoffSymbolsHeader->RvaToFirstByteOfCode);
			printf("RvaToLastByteOfCode:%#010X.\n", CoffSymbolsHeader->RvaToLastByteOfCode);
			printf("RvaToFirstByteOfData:%#010X.\n", CoffSymbolsHeader->RvaToFirstByteOfData);
			printf("RvaToLastByteOfData:%#010X.\n", CoffSymbolsHeader->RvaToLastByteOfData);

			break;
		}
		case IMAGE_DEBUG_TYPE_CODEVIEW:
		{
			CV_INFO_PDB70* temp = (CV_INFO_PDB70*)(Data + DebugDirectory->AddressOfRawData);//不可访问。
			CV_INFO_PDB70* temp2 = (CV_INFO_PDB70*)(Data + DebugDirectory->PointerToRawData);

			BYTE* PdbFileName = temp2->PdbFileName;
			if (PdbFileName != NULL) {
				printf("PdbFileName:%s.\n", PdbFileName);
				//HeapFree(GetProcessHeap(), 0, PdbFileName);
			}
			break;
		}
		case IMAGE_DEBUG_TYPE_FPO:
		{
			PFPO_DATA fpo = (PFPO_DATA)(Data + DebugDirectory->PointerToRawData);

			printf("ulOffStart:%#010X.\n", fpo->ulOffStart);
			printf("cbProcSize:%#010X.\n", fpo->cbProcSize);
			printf("cdwLocals:%#010X.\n", fpo->cdwLocals);

			printf("cdwParams:%#06X.\n", fpo->cdwParams);

			printf("cbProlog:%#06X.\n", fpo->cbProlog);
			printf("cbRegs:%#06X.\n", fpo->cbRegs);
			printf("fHasSEH:%#06X.\n", fpo->fHasSEH);
			printf("fUseBP:%#06X.\n", fpo->fUseBP);
			printf("reserved:%#06X.\n", fpo->reserved);
			printf("cbFrame:%#06X.\n", fpo->cbFrame);

			break;
		}
		case IMAGE_DEBUG_TYPE_MISC:
		{
			PIMAGE_DEBUG_MISC misc = (PIMAGE_DEBUG_MISC)(Data + DebugDirectory->PointerToRawData);

			printf("DataType:%#010X.\n", misc->DataType);
			printf("Length:%#010X.\n", misc->Length);

			printf("Length:%d.\n", misc->Unicode);

			printf("Reserved[3]:%#04X%#04X%#04X.\n",
				misc->Reserved[0],
				misc->Reserved[1],
				misc->Reserved[2]);

			printf("Data[1]:%#04X.\n", misc->Data[0]);//这个的数据应该有个长度指示。

			break;
		}
		case IMAGE_DEBUG_TYPE_EXCEPTION:

			break;
		case IMAGE_DEBUG_TYPE_FIXUP:

			break;
		case IMAGE_DEBUG_TYPE_OMAP_TO_SRC:

			break;
		case IMAGE_DEBUG_TYPE_OMAP_FROM_SRC:

			break;
		case IMAGE_DEBUG_TYPE_BORLAND:

			break;
		case IMAGE_DEBUG_TYPE_RESERVED10:

			break;
		case IMAGE_DEBUG_TYPE_CLSID:

			break;
		case IMAGE_DEBUG_TYPE_VC_FEATURE:
		{
			PVOID temp = (PVOID)(Data + DebugDirectory->AddressOfRawData);//不可访问。
			PVOID temp2 = (PVOID)(Data + DebugDirectory->PointerToRawData);

			PVOID temp3 = ImageRvaToVa(NtHeaders,
				Data,
				DebugDirectory->AddressOfRawData,
				NULL);
			_ASSERTE(temp3 == temp2);//竟然发现这个。

			PVOID temp4 = ImageRvaToVa(NtHeaders,
				Data,
				DebugDirectory->PointerToRawData,
				NULL);//可访问，但不知数据格式。


			break;
		}
		case IMAGE_DEBUG_TYPE_POGO:
		{
			PVOID temp = (PVOID)(Data + DebugDirectory->AddressOfRawData);//可访问。
			PVOID temp2 = (PVOID)(Data + DebugDirectory->PointerToRawData);

			PVOID temp3 = ImageRvaToVa(NtHeaders,
				Data,
				DebugDirectory->AddressOfRawData,
				NULL);
			_ASSERTE(temp3 == temp2);//竟然发现这个。

			PVOID temp4 = ImageRvaToVa(NtHeaders,
				Data,
				DebugDirectory->PointerToRawData,
				NULL);//可访问，但不知数据格式。




			break;
		}
		case IMAGE_DEBUG_TYPE_ILTCG:

			break;
		case IMAGE_DEBUG_TYPE_MPX:

			break;
		case IMAGE_DEBUG_TYPE_REPRO:
		{
			PVOID temp = (PVOID)(Data + DebugDirectory->AddressOfRawData);//可访问。
			PVOID temp2 = (PVOID)(Data + DebugDirectory->PointerToRawData);

			PVOID temp3 = ImageRvaToVa(NtHeaders,
				Data,
				DebugDirectory->AddressOfRawData,
				NULL);
			_ASSERTE(temp3 == temp2);//竟然发现这个。

			PVOID temp4 = ImageRvaToVa(NtHeaders,
				Data,
				DebugDirectory->PointerToRawData,
				NULL);//可访问，但不知数据格式。

			break;
		}
		case IMAGE_DEBUG_TYPE_EX_DLLCHARACTERISTICS:

			break;
		default:
			_ASSERTE(FALSE);
			break;
	}

	printf("\n");
}


DWORD Debug(PBYTE Data, LONGLONG Size)
{
	DWORD ret = ERROR_SUCCESS;

	if (!IsValidPE(Data, Size)) {
		return ret;
	}

	IMAGE_DATA_DIRECTORY DataDirectory = { 0 };
	GetDataDirectory(Data, Size, IMAGE_DIRECTORY_ENTRY_DEBUG, &DataDirectory);

	if (0 == DataDirectory.VirtualAddress) {
		printf("Debug empty.\n");
		return ret;
	}

	ULONG size = 0;
	PIMAGE_SECTION_HEADER FoundHeader = NULL;
	PIMAGE_DEBUG_DIRECTORY DebugDirectory = (PIMAGE_DEBUG_DIRECTORY)
		ImageDirectoryEntryToDataEx(Data,
			FALSE,
			IMAGE_DIRECTORY_ENTRY_DEBUG,
			&size, &FoundHeader);

	printf("Debug Directory Information:\n");

	for (DWORD i = 0; i * sizeof(IMAGE_DEBUG_DIRECTORY) < DataDirectory.Size; i++) {
		PrintDebug(Data, DebugDirectory);

		DebugDirectory++;
	}

	return ret;
}
