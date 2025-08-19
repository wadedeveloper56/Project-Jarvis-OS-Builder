#include "pch.h"
#include "LoadConfig.h"
#include "Public.h"

void PrintLoadConfig64(PIMAGE_LOAD_CONFIG_DIRECTORY64 LoadConfigDirectory64)
{
    printf("Size:%#010X.\n", LoadConfigDirectory64->Size);
    CHAR TimeDateStamp[MAX_PATH] = { 0 };
    GetTimeDateStamp(LoadConfigDirectory64->TimeDateStamp, TimeDateStamp);
    printf("TimeDateStamp:%d(%#010X), 时间戳：%s.\n",
        LoadConfigDirectory64->TimeDateStamp,
        LoadConfigDirectory64->TimeDateStamp,
        TimeDateStamp);

    printf("Version:%d.%d.\n", LoadConfigDirectory64->MajorVersion, LoadConfigDirectory64->MinorVersion);

    printf("GlobalFlagsClear:%#010X.\n", LoadConfigDirectory64->GlobalFlagsClear);
    printf("GlobalFlagsSet:%#010X.\n", LoadConfigDirectory64->GlobalFlagsSet);
    printf("CriticalSectionDefaultTimeout:%#010X.\n", LoadConfigDirectory64->CriticalSectionDefaultTimeout);

    printf("DeCommitFreeBlockThreshold:%#016llX.\n", LoadConfigDirectory64->DeCommitFreeBlockThreshold);
    printf("DeCommitTotalFreeThreshold:%#016llX.\n", LoadConfigDirectory64->DeCommitTotalFreeThreshold);
    printf("LockPrefixTable:%#016llX.\n", LoadConfigDirectory64->LockPrefixTable);
    printf("MaximumAllocationSize:%#016llX.\n", LoadConfigDirectory64->MaximumAllocationSize);
    printf("VirtualMemoryThreshold:%#016llX.\n", LoadConfigDirectory64->VirtualMemoryThreshold);
    printf("ProcessAffinityMask:%#016llX.\n", LoadConfigDirectory64->ProcessAffinityMask);

    printf("ProcessHeapFlags:%#010X.\n", LoadConfigDirectory64->ProcessHeapFlags);

    printf("CSDVersion:%#06X.\n", LoadConfigDirectory64->CSDVersion);
    printf("DependentLoadFlags:%#06X.\n", LoadConfigDirectory64->DependentLoadFlags);

    printf("EditList:%#016llX.\n", LoadConfigDirectory64->EditList);
    printf("SecurityCookie:%#016llX.\n", LoadConfigDirectory64->SecurityCookie);
    printf("SEHandlerTable:%#016llX.\n", LoadConfigDirectory64->SEHandlerTable);
    printf("SEHandlerCount:%#016llX.\n", LoadConfigDirectory64->SEHandlerCount);
    printf("GuardCFCheckFunctionPointer:%#016llX.\n", LoadConfigDirectory64->GuardCFCheckFunctionPointer);
    printf("GuardCFDispatchFunctionPointer:%#016llX.\n", LoadConfigDirectory64->GuardCFDispatchFunctionPointer);
    printf("GuardCFFunctionTable:%#016llX.\n", LoadConfigDirectory64->GuardCFFunctionTable);
    printf("GuardCFFunctionCount:%#016llX.\n", LoadConfigDirectory64->GuardCFFunctionCount);

    printf("GuardFlags:%#010X.\n", LoadConfigDirectory64->GuardFlags);

    printf("CodeIntegrity.Flags:%#06X.\n", LoadConfigDirectory64->CodeIntegrity.Flags);
    printf("CodeIntegrity.Catalog:%#06X.\n", LoadConfigDirectory64->CodeIntegrity.Catalog);
    printf("CodeIntegrity.CatalogOffset:%#010X.\n", LoadConfigDirectory64->CodeIntegrity.CatalogOffset);
    printf("CodeIntegrity.Reserved:%#010X.\n", LoadConfigDirectory64->CodeIntegrity.Reserved);

    printf("GuardAddressTakenIatEntryTable:%#016llX.\n", LoadConfigDirectory64->GuardAddressTakenIatEntryTable);
    printf("GuardAddressTakenIatEntryCount:%#016llX.\n", LoadConfigDirectory64->GuardAddressTakenIatEntryCount);
    printf("GuardLongJumpTargetTable:%#016llX.\n", LoadConfigDirectory64->GuardLongJumpTargetTable);
    printf("GuardLongJumpTargetCount:%#016llX.\n", LoadConfigDirectory64->GuardLongJumpTargetCount);
    printf("DynamicValueRelocTable:%#016llX.\n", LoadConfigDirectory64->DynamicValueRelocTable);
    printf("CHPEMetadataPointer:%#016llX.\n", LoadConfigDirectory64->CHPEMetadataPointer);
    printf("GuardRFFailureRoutine:%#016llX.\n", LoadConfigDirectory64->GuardRFFailureRoutine);
    printf("GuardRFFailureRoutineFunctionPointer:%#016llX.\n", LoadConfigDirectory64->GuardRFFailureRoutineFunctionPointer);

    printf("DynamicValueRelocTableOffset:%#010X.\n", LoadConfigDirectory64->DynamicValueRelocTableOffset);

    printf("DynamicValueRelocTableSection:%#06X.\n", LoadConfigDirectory64->DynamicValueRelocTableSection);
    printf("Reserved2:%#06X.\n", LoadConfigDirectory64->Reserved2);

    printf("GuardRFVerifyStackPointerFunctionPointer:%#016llX.\n", LoadConfigDirectory64->GuardRFVerifyStackPointerFunctionPointer);

    printf("HotPatchTableOffset:%#010X.\n", LoadConfigDirectory64->HotPatchTableOffset);
    printf("Reserved3:%#010X.\n", LoadConfigDirectory64->Reserved3);

    printf("EnclaveConfigurationPointer:%#016llX.\n", LoadConfigDirectory64->EnclaveConfigurationPointer);
    printf("VolatileMetadataPointer:%#016llX.\n", LoadConfigDirectory64->VolatileMetadataPointer);
    printf("GuardEHContinuationTable:%#016llX.\n", LoadConfigDirectory64->GuardEHContinuationTable);
    printf("GuardEHContinuationCount:%#016llX.\n", LoadConfigDirectory64->GuardEHContinuationCount);
}

void PrintLoadConfig32(PIMAGE_LOAD_CONFIG_DIRECTORY32 LoadConfigDirectory32)
{
    printf("Size:%#010X.\n", LoadConfigDirectory32->Size);
    CHAR TimeDateStamp[MAX_PATH] = { 0 };
    GetTimeDateStamp(LoadConfigDirectory32->TimeDateStamp, TimeDateStamp);
    printf("TimeDateStamp:%d(%#010X), 时间戳：%s.\n",
        LoadConfigDirectory32->TimeDateStamp,
        LoadConfigDirectory32->TimeDateStamp,
        TimeDateStamp);

    printf("Version:%d.%d.\n", LoadConfigDirectory32->MajorVersion, LoadConfigDirectory32->MinorVersion);

    printf("GlobalFlagsClear:%#010X.\n", LoadConfigDirectory32->GlobalFlagsClear);
    printf("GlobalFlagsSet:%#010X.\n", LoadConfigDirectory32->GlobalFlagsSet);
    printf("CriticalSectionDefaultTimeout:%#010X.\n", LoadConfigDirectory32->CriticalSectionDefaultTimeout);
    printf("DeCommitFreeBlockThreshold:%#010X.\n", LoadConfigDirectory32->DeCommitFreeBlockThreshold);
    printf("DeCommitTotalFreeThreshold:%#010X.\n", LoadConfigDirectory32->DeCommitTotalFreeThreshold);
    printf("LockPrefixTable:%#010X.\n", LoadConfigDirectory32->LockPrefixTable);
    printf("MaximumAllocationSize:%#010X.\n", LoadConfigDirectory32->MaximumAllocationSize);
    printf("VirtualMemoryThreshold:%#010X.\n", LoadConfigDirectory32->VirtualMemoryThreshold);
    printf("ProcessHeapFlags:%#010X.\n", LoadConfigDirectory32->ProcessHeapFlags);
    printf("ProcessAffinityMask:%#010X.\n", LoadConfigDirectory32->ProcessAffinityMask);

    printf("CSDVersion:%#06X.\n", LoadConfigDirectory32->CSDVersion);
    printf("DependentLoadFlags:%#06X.\n", LoadConfigDirectory32->DependentLoadFlags);

    printf("EditList:%#010X.\n", LoadConfigDirectory32->EditList);
    printf("SecurityCookie:%#010X.\n", LoadConfigDirectory32->SecurityCookie);
    printf("SEHandlerTable:%#010X.\n", LoadConfigDirectory32->SEHandlerTable);
    printf("SEHandlerCount:%#010X.\n", LoadConfigDirectory32->SEHandlerCount);
    printf("GuardCFCheckFunctionPointer:%#010X.\n", LoadConfigDirectory32->GuardCFCheckFunctionPointer);
    printf("GuardCFDispatchFunctionPointer:%#010X.\n", LoadConfigDirectory32->GuardCFDispatchFunctionPointer);
    printf("GuardCFFunctionTable:%#010X.\n", LoadConfigDirectory32->GuardCFFunctionTable);
    printf("GuardCFFunctionCount:%#010X.\n", LoadConfigDirectory32->GuardCFFunctionCount);
    printf("GuardFlags:%#010X.\n", LoadConfigDirectory32->GuardFlags);

    printf("CodeIntegrity.Flags:%#06X.\n", LoadConfigDirectory32->CodeIntegrity.Flags);
    printf("CodeIntegrity.Catalog:%#06X.\n", LoadConfigDirectory32->CodeIntegrity.Catalog);
    printf("CodeIntegrity.CatalogOffset:%#010X.\n", LoadConfigDirectory32->CodeIntegrity.CatalogOffset);
    printf("CodeIntegrity.Reserved:%#010X.\n", LoadConfigDirectory32->CodeIntegrity.Reserved);

    printf("GuardAddressTakenIatEntryTable:%#010X.\n", LoadConfigDirectory32->GuardAddressTakenIatEntryTable);
    printf("GuardAddressTakenIatEntryCount:%#010X.\n", LoadConfigDirectory32->GuardAddressTakenIatEntryCount);
    printf("GuardLongJumpTargetTable:%#010X.\n", LoadConfigDirectory32->GuardLongJumpTargetTable);
    printf("GuardLongJumpTargetCount:%#010X.\n", LoadConfigDirectory32->GuardLongJumpTargetCount);
    printf("DynamicValueRelocTable:%#010X.\n", LoadConfigDirectory32->DynamicValueRelocTable);
    printf("CHPEMetadataPointer:%#010X.\n", LoadConfigDirectory32->CHPEMetadataPointer);
    printf("GuardRFFailureRoutine:%#010X.\n", LoadConfigDirectory32->GuardRFFailureRoutine);
    printf("GuardRFFailureRoutineFunctionPointer:%#010X.\n", LoadConfigDirectory32->GuardRFFailureRoutineFunctionPointer);
    printf("DynamicValueRelocTableOffset:%#010X.\n", LoadConfigDirectory32->DynamicValueRelocTableOffset);

    printf("DynamicValueRelocTableSection:%#06X.\n", LoadConfigDirectory32->DynamicValueRelocTableSection);
    printf("Reserved2:%#06X.\n", LoadConfigDirectory32->Reserved2);

    printf("GuardRFVerifyStackPointerFunctionPointer:%#010X.\n", LoadConfigDirectory32->GuardRFVerifyStackPointerFunctionPointer);
    printf("HotPatchTableOffset:%#010X.\n", LoadConfigDirectory32->HotPatchTableOffset);
    printf("Reserved3:%#010X.\n", LoadConfigDirectory32->Reserved3);
    printf("EnclaveConfigurationPointer:%#010X.\n", LoadConfigDirectory32->EnclaveConfigurationPointer);
    printf("VolatileMetadataPointer:%#010X.\n", LoadConfigDirectory32->VolatileMetadataPointer);
    printf("GuardEHContinuationTable:%#010X.\n", LoadConfigDirectory32->GuardEHContinuationTable);
    printf("GuardEHContinuationCount:%#010X.\n", LoadConfigDirectory32->GuardEHContinuationCount);
}

DWORD LoadConfig(PBYTE Data, LONGLONG Size)
{
    DWORD ret = ERROR_SUCCESS;

    if (!IsValidPE(Data, Size)) {
        return ret;
    }

    IMAGE_DATA_DIRECTORY DataDirectory = { 0 };
    GetDataDirectory(Data, Size, IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG, &DataDirectory);

    if (0 == DataDirectory.VirtualAddress) {
        printf("LoadConfig empty.\n");
        return ret;
    }

    ULONG size = 0;
    PIMAGE_SECTION_HEADER FoundHeader = NULL;
    PIMAGE_LOAD_CONFIG_DIRECTORY LoadConfigDirectory = (PIMAGE_LOAD_CONFIG_DIRECTORY)
        ImageDirectoryEntryToDataEx(Data,
            FALSE,
            IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG,
            &size, &FoundHeader);

    PIMAGE_NT_HEADERS NtHeaders = ImageNtHeader(Data);
    _ASSERTE(NtHeaders);

    printf("Load Config Directory Information:\n");
    printf("VirtualAddress:%#010X.\n", DataDirectory.VirtualAddress);
    printf("Size:%#010X.\n", DataDirectory.Size);
    printf("\n");

    if (IsPE32Ex(Data, Size)) {
        PIMAGE_LOAD_CONFIG_DIRECTORY64 LoadConfigDirectory64 = (PIMAGE_LOAD_CONFIG_DIRECTORY64)LoadConfigDirectory;

        _ASSERTE(sizeof(IMAGE_LOAD_CONFIG_DIRECTORY64) == DataDirectory.Size);
        _ASSERTE(LoadConfigDirectory64->Size == DataDirectory.Size);

        PrintLoadConfig64(LoadConfigDirectory64);
    }
    else {
        PIMAGE_LOAD_CONFIG_DIRECTORY32 LoadConfigDirectory32 = (PIMAGE_LOAD_CONFIG_DIRECTORY32)LoadConfigDirectory;

        _ASSERTE(sizeof(IMAGE_LOAD_CONFIG_DIRECTORY32) == DataDirectory.Size);
        _ASSERTE(LoadConfigDirectory32->Size == DataDirectory.Size);

        PrintLoadConfig32(LoadConfigDirectory32);
    }

    return ret;
}

