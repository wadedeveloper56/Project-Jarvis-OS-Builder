#include "pch.h"
#include "Exception.h"
#include "Public.h"

PCSTR GetUnwFlag(BYTE Flags)
{
    PCSTR FlagsString = NULL;

    switch (Flags) {
        case 0:
            FlagsString = "None";//微软的dumpbin显示的是这个。
            break;
        case UNW_FLAG_EHANDLER:
            FlagsString = "EHANDLER";
            break;
        case UNW_FLAG_UHANDLER:
            FlagsString = "UHANDLER";
            break;
        case UNW_FLAG_CHAININFO:
            FlagsString = "CHAININFO";
            break;
        default:
            FlagsString = "未知";
            break;
    }

    return FlagsString;
}


PCSTR GetUnwOpCodes(BYTE UnwindOp)
{
    PCSTR UnwOpCodes = NULL;

    switch (UnwindOp) {
        case UWOP_PUSH_NONVOL:
            UnwOpCodes = "PUSH_NONVOL";
            break;
        case UWOP_ALLOC_LARGE:
            UnwOpCodes = "ALLOC_LARGE";
            break;
        case UWOP_ALLOC_SMALL:
            UnwOpCodes = "ALLOC_SMALL";
            break;
        case UWOP_SET_FPREG:
            UnwOpCodes = "SET_FPREG";
            break;
        case UWOP_SAVE_NONVOL:
            UnwOpCodes = "SAVE_NONVOL";
            break;
        case UWOP_SAVE_NONVOL_FAR:
            UnwOpCodes = "SAVE_NONVOL_FAR";
            break;
        case UWOP_SPARE_CODE1:
            UnwOpCodes = "EPILOG";//微软的dumpbin显示的是这个。
            break;
        case UWOP_SPARE_CODE2:
            UnwOpCodes = "SPARE_CODE2";
            break;
        case UWOP_SAVE_XMM128:
            UnwOpCodes = "SAVE_XMM128";
            break;
        case UWOP_SAVE_XMM128_FAR:
            UnwOpCodes = "SAVE_XMM128_FAR";
            break;
        case UWOP_PUSH_MACHFRAME:
            UnwOpCodes = "PUSH_MACHFRAME";
            break;
        default:
            UnwOpCodes = "未知";
            break;
    }

    return UnwOpCodes;
}


const char* GetRegister(unsigned char FrameRegister)
{
    const char* c = "";

    switch (FrameRegister)
    {
        case 0:
            c = "RAX";
            break;
        case 1:
            c = "RCX";
            break;
        case 2:
            c = "RDX";
            break;
        case 3:
            c = "RBX";
            break;
        case 4:
            c = "RSP";
            break;
        case 5:
            c = "RBP";
            break;
        case 6:
            c = "RSI";
            break;
        case 7:
            c = "RDI";
            break;
        case 8:
            c = "R8";
            break;
        case 9:
            c = "R9";
            break;
        case 10:
            c = "R10";
            break;
        case 11:
            c = "R11";
            break;
        case 12:
            c = "R12";
            break;
        case 13:
            c = "R13";
            break;
        case 14:
            c = "R14";
            break;
        case 15:
            c = "R15";
            break;
        default:
            break;
    }

    return c;
}

DWORD Exception(PBYTE Data, DWORD Size)
{
    DWORD ret = ERROR_SUCCESS;

    if (!IsValidPE(Data, Size)) {
        return ret;
    }

    IMAGE_DATA_DIRECTORY DataDirectory = { 0 };
    GetDataDirectory(Data, Size, IMAGE_DIRECTORY_ENTRY_EXCEPTION, &DataDirectory);

    if (0 == DataDirectory.VirtualAddress) {
        printf("碋xception empty.\n");
        return ret;
    }

    ULONG size = 0;
    PIMAGE_SECTION_HEADER FoundHeader = NULL;
    //PRUNTIME_FUNCTION
    PIMAGE_RUNTIME_FUNCTION_ENTRY ExceptionDirectory = (PIMAGE_RUNTIME_FUNCTION_ENTRY)
        ImageDirectoryEntryToDataEx(Data,
            FALSE,
            IMAGE_DIRECTORY_ENTRY_EXCEPTION,
            &size,
            &FoundHeader);

    PIMAGE_NT_HEADERS NtHeaders = ImageNtHeader(Data);
    _ASSERTE(NtHeaders);

    printf("Exception Directory Information:\n");

    printf("Exception Function Numbers:%zd.\n", DataDirectory.Size / sizeof(_IMAGE_RUNTIME_FUNCTION_ENTRY));

    printf("\n");

    for (DWORD i = 0; i * sizeof(_IMAGE_RUNTIME_FUNCTION_ENTRY) < DataDirectory.Size; i++) {
        printf("index:%06d.\n", i);

        printf("BeginAddress:%#010X.\n", ExceptionDirectory->BeginAddress);
        printf("EndAddress:%#010X.\n", ExceptionDirectory->EndAddress);
        printf("UnwindInfoAddress:%#010X.\n", ExceptionDirectory->UnwindInfoAddress);

        PUNWIND_INFO UnwindInfoAddress = (PUNWIND_INFO)ImageRvaToVa(NtHeaders,
            Data,
            ExceptionDirectory->UnwindInfoAddress,
            NULL);
        if (UnwindInfoAddress != NULL) {
            printf("\tVersion:%d.\n", UnwindInfoAddress->Version);
            printf("\tFlags:%d, %s.\n", UnwindInfoAddress->Flags, GetUnwFlag(UnwindInfoAddress->Flags));
            printf("\tSizeOfProlog:%d.\n", UnwindInfoAddress->SizeOfProlog);
            printf("\tCountOfCodes:%d.\n", UnwindInfoAddress->CountOfCodes);
            printf("\tFrameRegister:%d, %s.\n", UnwindInfoAddress->FrameRegister, GetRegister(UnwindInfoAddress->FrameRegister));
            printf("\tFrameOffset:%d.\n", UnwindInfoAddress->FrameOffset);

            PUNWIND_CODE temp = UnwindInfoAddress->UnwindCode;

            for (char i = 0; i < UnwindInfoAddress->CountOfCodes; i++) {
                printf("\t\tindex:%d, CodeOffset:%d, UnwindOp:%d(%s), OpInfo:%d, FrameOffset:%d.\n",
                    i + 1,
                    temp->CodeOffset,
                    temp->UnwindOp,
                    GetUnwOpCodes(temp->UnwindOp),
                    temp->OpInfo,
                    temp->FrameOffset);

                temp++;
            }

            printf("\n");
        }
        ExceptionDirectory++;
    }

    return ret;
}
