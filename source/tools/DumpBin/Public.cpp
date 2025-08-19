#include "pch.h"
#include "Public.h"

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
