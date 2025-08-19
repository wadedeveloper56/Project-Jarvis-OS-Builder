#include "pch.h"
#include "Security.h"
#include "Public.h"

DWORD Security(PBYTE Data, DWORD Size)
{
    DWORD ret = ERROR_SUCCESS;

    if (!IsValidPE(Data, Size)) {
        return ret;
    }

    printf("Security Info\n");
    //ParseCertificateInfo1();

    IMAGE_DATA_DIRECTORY DataDirectory = { 0 };
    GetDataDirectory(Data, Size, IMAGE_DIRECTORY_ENTRY_SECURITY, &DataDirectory);

    if (0 == DataDirectory.VirtualAddress) {
        printf("Security empty.\n");
        return ret;
    }

    printf("Security Directory Information:\n");
    printf("VirtualAddress:%#010X.\n", DataDirectory.VirtualAddress);
    printf("Size:%#010X.\n", DataDirectory.Size);
    printf("\n");

    //ULONG size = 0;
    //PIMAGE_SECTION_HEADER FoundHeader = NULL;
    //LPWIN_CERTIFICATE SecurityDirectory = (LPWIN_CERTIFICATE)
    //    ImageDirectoryEntryToDataEx(Data,
    //                                FALSE,//自己映射的用FALSE，操作系统加载的用TRUE。 
    //                                IMAGE_DIRECTORY_ENTRY_SECURITY,
    //                                &size,
    //                                &FoundHeader);

    //LPWIN_CERTIFICATE SecurityDirectory = (LPWIN_CERTIFICATE)(Data + DataDirectory.VirtualAddress);

    PIMAGE_NT_HEADERS NtHeaders = ImageNtHeader(Data);
    _ASSERTE(NtHeaders);

    //////////////////////////////////////////////////////////////////////////////////////////////
    /*
    printf("----------------------------------------------------------------------------------\n");
    printf("解析方式二：\n");
    ParseCertificateInfo2();

    printf("----------------------------------------------------------------------------------\n");
    printf("解析方式三：\n");
    ParseCertificateInfo3(&DataDirectory, SecurityDirectory);

    printf("----------------------------------------------------------------------------------\n");
    printf("解析方式四：\n");
    ParseCertificateInfo4(&DataDirectory, SecurityDirectory);

    printf("----------------------------------------------------------------------------------\n");
    printf("解析方式五：\n");
    ParseCertificateInfo5(&DataDirectory, SecurityDirectory);
    */
    //////////////////////////////////////////////////////////////////////////////////////////////

    return ret;
}
