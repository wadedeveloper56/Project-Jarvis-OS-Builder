#include "pch.h"
#include "Public.h"

void GetSectionCharacteristics(DWORD Characteristics,PCHAR String,size_t cchDest)
{
	if (Characteristics & IMAGE_SCN_SCALE_INDEX) {
		StringCchCatA(String, cchDest, "SCALE_INDEX ");
	}

	if (Characteristics & IMAGE_SCN_TYPE_NO_PAD) {
		StringCchCatA(String, cchDest, "TYPE_NO_PAD ");
	}

	if (Characteristics & IMAGE_SCN_CNT_CODE) {
		StringCchCatA(String, cchDest, "CNT_CODE ");
	}

	if (Characteristics & IMAGE_SCN_CNT_INITIALIZED_DATA) {
		StringCchCatA(String, cchDest, "INITIALIZED_DATA ");
	}

	if (Characteristics & IMAGE_SCN_CNT_UNINITIALIZED_DATA) {
		StringCchCatA(String, cchDest, "CNT_UNINITIALIZED_DATA ");
	}

	if (Characteristics & IMAGE_SCN_LNK_OTHER) {
		StringCchCatA(String, cchDest, "LNK_OTHER ");
	}

	if (Characteristics & IMAGE_SCN_LNK_INFO) {
		StringCchCatA(String, cchDest, "LNK_INFO ");
	}

	if (Characteristics & IMAGE_SCN_LNK_REMOVE) {
		StringCchCatA(String, cchDest, "LNK_REMOVE ");
	}

	if (Characteristics & IMAGE_SCN_LNK_COMDAT) {
		StringCchCatA(String, cchDest, "LNK_COMDAT ");
	}

	if (Characteristics & IMAGE_SCN_NO_DEFER_SPEC_EXC) {
		StringCchCatA(String, cchDest, "NO_DEFER_SPEC_EXC ");
	}

	if (Characteristics & IMAGE_SCN_GPREL) {
		StringCchCatA(String, cchDest, "GPREL ");
	}

	if (Characteristics & IMAGE_SCN_MEM_FARDATA) {
		StringCchCatA(String, cchDest, "MEM_FARDATA ");
	}

	if (Characteristics & IMAGE_SCN_MEM_PURGEABLE) {
		StringCchCatA(String, cchDest, "MEM_PURGEABLE ");
	}

	if (Characteristics & IMAGE_SCN_MEM_16BIT) {
		StringCchCatA(String, cchDest, "MEM_16BIT ");
	}

	if (Characteristics & IMAGE_SCN_MEM_LOCKED) {
		StringCchCatA(String, cchDest, "MEM_LOCKED ");
	}

	if (Characteristics & IMAGE_SCN_MEM_PRELOAD) {
		StringCchCatA(String, cchDest, "MEM_PRELOAD ");
	}

	if (Characteristics & IMAGE_SCN_ALIGN_1BYTES) {
		StringCchCatA(String, cchDest, "ALIGN_1BYTES ");
	}

	if (Characteristics & IMAGE_SCN_ALIGN_2BYTES) {
		StringCchCatA(String, cchDest, "ALIGN_2BYTES ");
	}

	if (Characteristics & IMAGE_SCN_ALIGN_4BYTES) {
		StringCchCatA(String, cchDest, "ALIGN_4BYTES ");
	}

	if (Characteristics & IMAGE_SCN_ALIGN_8BYTES) {
		StringCchCatA(String, cchDest, "ALIGN_8BYTES ");
	}

	if (Characteristics & IMAGE_SCN_ALIGN_16BYTES) {
		StringCchCatA(String, cchDest, "ALIGN_16BYTES ");
	}

	if (Characteristics & IMAGE_SCN_ALIGN_32BYTES) {
		StringCchCatA(String, cchDest, "ALIGN_32BYTES ");
	}

	if (Characteristics & IMAGE_SCN_ALIGN_64BYTES) {
		StringCchCatA(String, cchDest, "ALIGN_64BYTES ");
	}

	if (Characteristics & IMAGE_SCN_ALIGN_128BYTES) {
		StringCchCatA(String, cchDest, "ALIGN_128BYTES ");
	}

	if (Characteristics & IMAGE_SCN_ALIGN_256BYTES) {
		StringCchCatA(String, cchDest, "ALIGN_256BYTES ");
	}

	if (Characteristics & IMAGE_SCN_ALIGN_512BYTES) {
		StringCchCatA(String, cchDest, "ALIGN_512BYTES ");
	}

	if (Characteristics & IMAGE_SCN_ALIGN_1024BYTES) {
		StringCchCatA(String, cchDest, "ALIGN_1024BYTES ");
	}

	if (Characteristics & IMAGE_SCN_ALIGN_2048BYTES) {
		StringCchCatA(String, cchDest, "ALIGN_2048BYTES ");
	}

	if (Characteristics & IMAGE_SCN_ALIGN_4096BYTES) {
		StringCchCatA(String, cchDest, "ALIGN_4096BYTES ");
	}

	if (Characteristics & IMAGE_SCN_ALIGN_8192BYTES) {
		StringCchCatA(String, cchDest, "ALIGN_8192BYTES ");
	}

	if (Characteristics & IMAGE_SCN_ALIGN_MASK) {
		StringCchCatA(String, cchDest, "ALIGN_MASK ");
	}

	if (Characteristics & IMAGE_SCN_LNK_NRELOC_OVFL) {
		StringCchCatA(String, cchDest, "LNK_NRELOC_OVFL ");
	}

	if (Characteristics & IMAGE_SCN_MEM_DISCARDABLE) {
		StringCchCatA(String, cchDest, "MEM_DISCARDABLE ");
	}

	if (Characteristics & IMAGE_SCN_MEM_NOT_CACHED) {
		StringCchCatA(String, cchDest, "MEM_NOT_CACHED ");
	}

	if (Characteristics & IMAGE_SCN_MEM_NOT_PAGED) {
		StringCchCatA(String, cchDest, "MEM_NOT_PAGED ");
	}

	if (Characteristics & IMAGE_SCN_MEM_SHARED) {
		StringCchCatA(String, cchDest, "MEM_SHARED ");
	}

	if (Characteristics & IMAGE_SCN_MEM_EXECUTE) {
		StringCchCatA(String, cchDest, "MEM_EXECUTE ");
	}

	if (Characteristics & IMAGE_SCN_MEM_READ) {
		StringCchCatA(String, cchDest, "MEM_READ ");
	}

	if (Characteristics & IMAGE_SCN_MEM_WRITE) {
		StringCchCatA(String, cchDest, "MEM_WRITE ");
	}
}

bool IsValidPE(PBYTE Data, LARGE_INTEGER Size)
{
	bool ret = false;
	__try {
		PIMAGE_DOS_HEADER DosHeader = (PIMAGE_DOS_HEADER)Data;
		if (IMAGE_DOS_SIGNATURE != DosHeader->e_magic) {
			__leave;
		}

		PIMAGE_NT_HEADERS NtHeader = ImageNtHeader(Data);
		switch (NtHeader->Signature) {
			case IMAGE_OS2_SIGNATURE:
				break;
			case IMAGE_OS2_SIGNATURE_LE://IMAGE_VXD_SIGNATURE
				break;
			case IMAGE_NT_SIGNATURE:
				ret = true;
				break;
			default:
				break;
		}

	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		ret = GetExceptionCode();
	}

	return ret;
}


bool IsPE32Ex(PBYTE Data, LARGE_INTEGER Size)
{
	bool ret = false;

	if (!IsValidPE(Data, Size)) {
		return ret;
	}

	__try {
		PIMAGE_DOS_HEADER DosHeader = (PIMAGE_DOS_HEADER)Data;
		_ASSERTE(IMAGE_DOS_SIGNATURE == DosHeader->e_magic);

		PIMAGE_NT_HEADERS NtHeader = ImageNtHeader(Data);
		_ASSERTE(NtHeader);

		/*
		对于可选头的标准域(排除最后一个BaseOfData)来说，是32位的可选头和64位的可选头无所谓，因为偏移都是一样的。
		*/
		PIMAGE_OPTIONAL_HEADER OptionalHeader = (PIMAGE_OPTIONAL_HEADER)&NtHeader->OptionalHeader;
		switch (OptionalHeader->Magic) {
			case IMAGE_NT_OPTIONAL_HDR32_MAGIC:
				//这是一个普通的PE文件
				break;
			case IMAGE_NT_OPTIONAL_HDR64_MAGIC:
				ret = true;
				break;
			case IMAGE_ROM_OPTIONAL_HDR_MAGIC:
				break;
			default:
				break;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		ret = GetExceptionCode();
	}

	return ret;
}

void GetCharacteristics(WORD Characteristics, PCHAR String, size_t cchDest)
{
	_ASSERTE(String);
	//String[0] = 0;

	if (Characteristics & IMAGE_FILE_RELOCS_STRIPPED) {
		StringCchCatA(String, cchDest, "RELOCS_STRIPPED ");
	}

	if (Characteristics & IMAGE_FILE_EXECUTABLE_IMAGE) {
		StringCchCatA(String, cchDest, "EXECUTABLE_IMAGE ");
	}

	if (Characteristics & IMAGE_FILE_LINE_NUMS_STRIPPED) {
		StringCchCatA(String, cchDest, "LINE_NUMS_STRIPPED ");
	}

	if (Characteristics & IMAGE_FILE_LOCAL_SYMS_STRIPPED) {
		StringCchCatA(String, cchDest, "LOCAL_SYMS_STRIPPED ");
	}

	if (Characteristics & IMAGE_FILE_AGGRESIVE_WS_TRIM) {
		StringCchCatA(String, cchDest, "AGGRESIVE_WS_TRIM ");
	}

	if (Characteristics & IMAGE_FILE_LARGE_ADDRESS_AWARE) {
		StringCchCatA(String, cchDest, "LARGE_ADDRESS_AWARE ");
	}

	if (Characteristics & IMAGE_FILE_BYTES_REVERSED_LO) {
		StringCchCatA(String, cchDest, "BYTES_REVERSED_LO ");
	}

	if (Characteristics & IMAGE_FILE_32BIT_MACHINE) {
		StringCchCatA(String, cchDest, "32BIT_MACHINE ");
	}

	if (Characteristics & IMAGE_FILE_DEBUG_STRIPPED) {
		StringCchCatA(String, cchDest, "DEBUG_STRIPPED ");
	}

	if (Characteristics & IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP) {
		StringCchCatA(String, cchDest, "REMOVABLE_RUN_FROM_SWAP ");
	}

	if (Characteristics & IMAGE_FILE_NET_RUN_FROM_SWAP) {
		StringCchCatA(String, cchDest, "NET_RUN_FROM_SWAP ");
	}

	if (Characteristics & IMAGE_FILE_SYSTEM) {
		StringCchCatA(String, cchDest, "SYSTEM ");
	}

	if (Characteristics & IMAGE_FILE_DLL) {
		StringCchCatA(String, cchDest, "DLL ");
	}

	if (Characteristics & IMAGE_FILE_UP_SYSTEM_ONLY) {
		StringCchCatA(String, cchDest, "UP_SYSTEM_ONLY ");
	}

	if (Characteristics & IMAGE_FILE_BYTES_REVERSED_HI) {
		StringCchCatA(String, cchDest, "BYTES_REVERSED_HI ");
	}
}

void TimeStampToFileTime(INT64 timeStamp, FILETIME& fileTime)
{
	INT64 nll = timeStamp * 10000000 + 116444736000000000;
	fileTime.dwLowDateTime = (DWORD)nll;
	fileTime.dwHighDateTime = nll >> 32;
}

void FileTimeToLocalTimeA(PFILETIME ft, char* time)
{
	FILETIME lft;
	BOOL B = FileTimeToLocalFileTime(ft, &lft);
	_ASSERTE(B);

	SYSTEMTIME st;
	//GetLocalTime(&st);
	B = FileTimeToSystemTime(&lft, &st);
	_ASSERTE(B);

	//SystemTimeToTzSpecificLocalTime

	//格式：2016-07-11 17:35:54      
	wsprintfA(time,
		"%04d-%02d-%02d %02d:%02d:%02d",
		st.wYear,
		st.wMonth,
		st.wDay,
		st.wHour,
		st.wMinute,
		st.wSecond);

	//size_t cb = lstrlen(time) * sizeof(wchar_t);
}

void GetTimeDateStamp(DWORD TimeDateStamp, PCHAR String)
{
	FILETIME FileTime = { 0 };
	TimeStampToFileTime(TimeDateStamp, FileTime);
	FileTimeToLocalTimeA(&FileTime, String);
}

PCSTR GetMachine(WORD Machine)
{
	PCSTR MachineString = NULL;

	switch (Machine) {
		case IMAGE_FILE_MACHINE_UNKNOWN:
			MachineString = "Unknown";
			break;
		case IMAGE_FILE_MACHINE_TARGET_HOST:
			MachineString = "Useful for indicating we want to interact with the host and not a WoW guest";
			break;
		case IMAGE_FILE_MACHINE_I386:
			MachineString = "Intel 386";
			break;
		case IMAGE_FILE_MACHINE_R3000:
			MachineString = "MIPS little-endian, 0x160 big-endian";
			break;
		case IMAGE_FILE_MACHINE_R4000:
			MachineString = "MIPS little-endian";
			break;
		case IMAGE_FILE_MACHINE_R10000:
			MachineString = "MIPS little-endian";
			break;
		case IMAGE_FILE_MACHINE_WCEMIPSV2:
			MachineString = "MIPS little-endian WCE v2";
			break;
		case IMAGE_FILE_MACHINE_ALPHA:
			MachineString = "Alpha_AXP";
			break;
		case IMAGE_FILE_MACHINE_SH3:
			MachineString = "SH3 little-endian";
			break;
		case IMAGE_FILE_MACHINE_SH3DSP:
			MachineString = "IMAGE_FILE_MACHINE_SH3DSP";
			break;
		case IMAGE_FILE_MACHINE_SH3E:
			MachineString = "SH3E little-endian";
			break;
		case IMAGE_FILE_MACHINE_SH4:
			MachineString = "SH4 little-endian";
			break;
		case IMAGE_FILE_MACHINE_SH5:
			MachineString = "SH5";
			break;
		case IMAGE_FILE_MACHINE_ARM:
			MachineString = "ARM Little-Endian";
			break;
		case IMAGE_FILE_MACHINE_THUMB:
			MachineString = "ARM Thumb/Thumb-2 Little-Endian";
			break;
		case IMAGE_FILE_MACHINE_ARMNT:
			MachineString = "ARM Thumb-2 Little-Endian";
			break;
		case IMAGE_FILE_MACHINE_AM33:
			MachineString = "IMAGE_FILE_MACHINE_AM33";
			break;
		case IMAGE_FILE_MACHINE_POWERPC:
			MachineString = "IBM PowerPC Little-Endian";
			break;
		case IMAGE_FILE_MACHINE_POWERPCFP:
			MachineString = "IMAGE_FILE_MACHINE_POWERPCFP";
			break;
		case IMAGE_FILE_MACHINE_IA64:
			MachineString = "Intel 64";
			break;
		case IMAGE_FILE_MACHINE_MIPS16:
			MachineString = "MIPS";
			break;
		case IMAGE_FILE_MACHINE_ALPHA64:
			MachineString = "ALPHA64";
			break;
		case IMAGE_FILE_MACHINE_MIPSFPU:
			MachineString = "MIPS";
			break;
		case IMAGE_FILE_MACHINE_MIPSFPU16:
			MachineString = "MIPS";
			break;
		case IMAGE_FILE_MACHINE_TRICORE:
			MachineString = "Infineon";
			break;
		case IMAGE_FILE_MACHINE_CEF:
			MachineString = "IMAGE_FILE_MACHINE_CEF";
			break;
		case IMAGE_FILE_MACHINE_EBC:
			MachineString = "EFI Byte Code";
			break;
		case IMAGE_FILE_MACHINE_AMD64:
			MachineString = "AMD64 (K8)";
			break;
		case IMAGE_FILE_MACHINE_M32R:
			MachineString = "M32R little-endian";
			break;
		case IMAGE_FILE_MACHINE_ARM64:
			MachineString = "ARM64 Little-Endian";
			break;
		case IMAGE_FILE_MACHINE_CEE:
			MachineString = "IMAGE_FILE_MACHINE_CEE";
			break;
		default:
			MachineString = "未知";
			break;
	}

	return MachineString;
}
