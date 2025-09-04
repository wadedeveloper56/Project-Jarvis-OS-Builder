#include "pch.h"
#include "common.h"
#include "extrnvar.h"
#include "resdump.h"

void
DumpResourceDirectory(
    PIMAGE_RESOURCE_DIRECTORY resDir,
    BYTE* resourceBase,
    DWORD level,
    DWORD resourceType
    );

const char* SzResourceTypes[] =
{
    "???_0",
    "CURSOR",
    "BITMAP",
    "ICON",
    "MENU",
    "DIALOG",
    "STRING",
    "FONTDIR",
    "FONT",
    "ACCELERATORS",
    "RCDATA",
    "MESSAGETABLE",
    "GROUP_CURSOR",
    "???_13",
    "GROUP_ICON",
    "???_15",
    "VERSION",
    "DLGINCLUDE",
    "???_18",
    "PLUGPLAY",
    "VXD",
    "ANICURSOR",
    "ANIICON"
};

PIMAGE_RESOURCE_DIRECTORY_ENTRY pStrResEntries = 0;
PIMAGE_RESOURCE_DIRECTORY_ENTRY pDlgResEntries = 0;
DWORD cStrResEntries                           = 0;
DWORD cDlgResEntries                           = 0;

DWORD
GetOffsetToDataFromResEntry(
    BYTE* base,
    BYTE* resourceBase,
    PIMAGE_RESOURCE_DIRECTORY_ENTRY pResEntry
    )
{
    PIMAGE_RESOURCE_DIRECTORY pStupidResDir;
    pStupidResDir = (PIMAGE_RESOURCE_DIRECTORY) (resourceBase + pResEntry->OffsetToDirectory);

    PIMAGE_RESOURCE_DIRECTORY_ENTRY pResDirEntry =
    (PIMAGE_RESOURCE_DIRECTORY_ENTRY) (pStupidResDir + 1);

    PIMAGE_RESOURCE_DATA_ENTRY pResDataEntry =
    (PIMAGE_RESOURCE_DATA_ENTRY) (resourceBase
            + pResDirEntry->OffsetToData);

    return pResDataEntry->OffsetToData;
}

void
DumpStringTable(
    BYTE* base,
    PIMAGE_NT_HEADERS pNTHeader,
    BYTE* resourceBase,
    PIMAGE_RESOURCE_DIRECTORY_ENTRY pStrResEntry,
    DWORD cStrResEntries
    )
{
    for (unsigned i = 0; i < cStrResEntries; i++, pStrResEntry++)
    {
        DWORD offsetToData = GetOffsetToDataFromResEntry(
            base,
            resourceBase,
            pStrResEntry
            );

        PWORD pStrEntry = (PWORD) GetPtrFromRVA(
            offsetToData,
            pNTHeader,
            base
            );

        if (!pStrEntry)
        {
            printf(
                "TODO: (PWORD)GetPtrFromRVA failed RVA %08X\n",
                offsetToData
                );
            break;
        }

        unsigned id = (pStrResEntry->Name - 1) << 4;

        for (unsigned j = 0; j < 16; j++)
        {
            WORD len = *pStrEntry++;

            if (len)
            {
                printf(
                    "%-5u: ",
                    id + j
                    );

                for (
                    unsigned k = 0; k < min(
                        len,
                        (WORD) 64
                        ); k++
                    )
                {
                    const char* s;
                    char szBuff[20];
                    char c = (char) pStrEntry[k];

                    switch (c)
                    {
                        case '\t': s = "\\t"; break;
                        case '\r': s = "\\r"; break;
                        case '\n': s = "\\n"; break;
                        default:
                        wsprintfA(
                                szBuff,
                                "%c",
                                isprint(c) ? c : '.'
                                );
                            s = szBuff;
                            break;
                    }

                    printf(
                        "%s",
                        s
                        );
                }

                printf("\n");
            }

            pStrEntry += len;
        }
    }
}

#define ADD_DUMP_DIALOGS

void
DumpDialogs(
    BYTE* base,
    PIMAGE_NT_HEADERS pNTHeader,
    BYTE* resourceBase,
    PIMAGE_RESOURCE_DIRECTORY_ENTRY pDlgResEntry,
    DWORD cDlgResEntries
    )
{
#ifdef ADD_DUMP_DIALOGS
    for (unsigned i = 0; i < cDlgResEntries; i++, pDlgResEntry++)
    {
        DWORD offsetToData = GetOffsetToDataFromResEntry(
            base,
            resourceBase,
            pDlgResEntry
            );

        PDWORD pDlgStyle = (PDWORD) GetPtrFromRVA(
            offsetToData,
            pNTHeader,
            base
            );

        if (!pDlgStyle)
        {
            printf(
                "TODO: (PDWORD)GetPtrFromRVA failed RVA %08X\n",
                offsetToData
                );
            break;
        }

        printf(" ====================\n");

        if (HIWORD(*pDlgStyle) != 0xFFFF)
        {
            DLGTEMPLATE* pDlgTemplate = (DLGTEMPLATE*) pDlgStyle;

            printf(
                "  style: %08X\n",
                pDlgTemplate->style
                );
            printf(
                "  extended style: %08X\n",
                pDlgTemplate->dwExtendedStyle
                );

            printf(
                "  controls: %u\n",
                pDlgTemplate->cdit
                );
            printf(
                "  (%u,%u) - (%u,%u)\n",
                pDlgTemplate->x,
                pDlgTemplate->y,
                pDlgTemplate->x + pDlgTemplate->cx,
                pDlgTemplate->y + pDlgTemplate->cy
                );
            PWORD pMenu = (PWORD) (pDlgTemplate + 1);

            if (*pMenu)
            {
                if (0xFFFF == *pMenu)
                {
                    pMenu++;
                    printf(
                        "  ordinal menu: %u\n",
                        *pMenu
                        );
                }
                else
                {
                    printf(" menu: ");

                    while (*pMenu)
                    {
                        printf(
                            "%c",
                            LOBYTE(*pMenu++)
                            );
                    }

                    pMenu++;
                    printf("\n");
                }
            }
            else
            {
                pMenu++;
            }

            PWORD pClass = pMenu;

            if (*pClass)
            {
                if (0xFFFF == *pClass)
                {
                    pClass++;
                    printf(
                        "  ordinal class: %u\n",
                        *pClass
                        );
                }
                else
                {
                    printf(" class: ");

                    while (*pClass)
                    {
                        printf(
                            "%c",
                            LOBYTE(*pClass++)
                            );
                    }

                    pClass++;
                    printf("\n");
                }
            }
            else
            {
                pClass++;
            }

            PWORD pTitle = pClass;

            if (*pTitle)
            {
                printf(" title: ");

                while (*pTitle)
                {
                    printf(
                        "%c",
                        LOBYTE(*pTitle++)
                        );
                }

                pTitle++;
            }
            else
            {
                pTitle++;
            }

            printf("\n");

            PWORD pFont = pTitle;

            if (pDlgTemplate->style & DS_SETFONT)
            {
                printf(
                    "  Font: %u point ",
                    *pFont++
                    );

                while (*pFont)
                {
                    printf(
                        "%c",
                        LOBYTE(*pFont++)
                        );
                }

                pFont++;
                printf("\n");
            }
            else
            {
                pFont = pTitle;
            }

            LPDLGITEMTEMPLATE pDlgItemTemplate = (LPDLGITEMTEMPLATE) pFont;

            for (unsigned i = 0; i < pDlgTemplate->cdit; i++)
            {
                printf(
                    "    style: %08X\n",
                    pDlgItemTemplate->style
                    );
                printf(
                    "    extended style: %08X\n",
                    pDlgItemTemplate->dwExtendedStyle
                    );

                printf(
                    "    (%u,%u) - (%u,%u)\n",
                    pDlgItemTemplate->x,
                    pDlgItemTemplate->y,
                    pDlgItemTemplate->x + pDlgItemTemplate->cx,
                    pDlgItemTemplate->y + pDlgItemTemplate->cy
                    );
                printf(
                    "    id: %u\n",
                    pDlgItemTemplate->id
                    );

                PWORD pClass = (PWORD) (pDlgItemTemplate + 1);

                if (*pClass)
                {
                    if (0xFFFF == *pClass)
                    {
                        pClass++;
                        printf(
                            "    ordinal class: %u",
                            *pClass++
                            );
                    }
                    else
                    {
                        printf(" class: ");

                        while (*pClass)
                        {
                            printf(
                                "%c",
                                LOBYTE(*pClass++)
                                );
                        }

                        pClass++;
                        printf("\n");
                    }
                }
                else
                {
                    pClass++;
                }

                printf("\n");

                PWORD pTitle = pClass;

                if (*pTitle)
                {
                    printf(" title: ");

                    if (0xFFFF == *pTitle)
                    {
                        pTitle++;
                        printf(
                            "%u\n",
                            *pTitle++
                            );
                    }
                    else
                    {
                        while (*pTitle)
                        {
                            printf(
                                "%c",
                                LOBYTE(*pTitle++)
                                );
                        }

                        pTitle++;
                        printf("\n");
                    }
                }
                else
                {
                    pTitle++;
                }

                printf("\n");

                PBYTE pCreationData = (PBYTE) (pTitle + 1);

                if (*pCreationData)
                {
                    pCreationData += *pCreationData;
                }
                else
                {
                    pCreationData++;
                }

                pDlgItemTemplate = (DLGITEMTEMPLATE*) pCreationData;

                printf("\n");
            }

            printf("\n");
        }
        else
        {
        }

        printf("\n");
    }
#else // ifdef ADD_DUMP_DIALOGS
    printf("TODO: Port DumpDialogs!\n");
#endif
}

void
GetResourceTypeName(
    LONGLONG type,
    PSTR buffer,
    UINT cBytes
    )
{
    if (type <= (LONGLONG) RT_ANIICON)
    {
        strncpy(
            buffer,
            SzResourceTypes[type],
            cBytes
            );
    }
    else
    {
        sprintf(
            buffer,
            "%llX",
            type
            );
    }
}

void
GetResourceNameFromId(
    DWORD id,
    BYTE* resourceBase,
    PSTR buffer,
    UINT cBytes
    )
{
    PIMAGE_RESOURCE_DIR_STRING_U prdsu;

    if (!(id & IMAGE_RESOURCE_NAME_IS_STRING))
    {
        sprintf(
            buffer,
            "%X",
            id
            );

        return;
    }

    id   &= 0x7FFFFFFF;
    prdsu = (PIMAGE_RESOURCE_DIR_STRING_U) (resourceBase + id);

    if (
        IsAddressInRange(
            (BYTE*) prdsu,
            (int) sizeof(IMAGE_RESOURCE_DIR_STRING_U)
            )
        )
    {
        WideCharToMultiByte(
            CP_ACP,
            0,
            prdsu->NameString,
            prdsu->Length,
            buffer,
            cBytes,
            0,
            0
            );
        buffer[min(
            cBytes - 1,
            prdsu->Length
            )] = 0;
    }
    else
    {
        sprintf(
            buffer,
            "PIMAGE_RESOURCE_DIR_STRING_U out of range - %p",
            prdsu
            );
        printf(
            "TODO: GetResourceNameFromId - PIMAGE_RESOURCE_DIR_STRING_U out of range - %p\n",
            prdsu
            );
    }
}

void
DumpResourceEntry(
    PIMAGE_RESOURCE_DIRECTORY_ENTRY resDirEntry,
    BYTE* resourceBase,
    DWORD level
    )
{
    UINT i;
    char nameBuffer[264];
    PIMAGE_RESOURCE_DATA_ENTRY pResDataEntry;

    if (
        IsAddressInRange(
            (BYTE*) resDirEntry,
            (int) sizeof(IMAGE_RESOURCE_DIRECTORY_ENTRY)
            )
        )
    {
        if (resDirEntry->OffsetToData & IMAGE_RESOURCE_DATA_IS_DIRECTORY)
        {
            DumpResourceDirectory(
                (PIMAGE_RESOURCE_DIRECTORY) ((resDirEntry->OffsetToData & 0x7FFFFFFF) + resourceBase),
                resourceBase,
                level,
                resDirEntry->Name
                );

            return;
        }

        for (i = 0; i < level; i++)
        {
            printf(" ");
        }

        if (resDirEntry->Name & IMAGE_RESOURCE_NAME_IS_STRING)
        {
            GetResourceNameFromId(
                resDirEntry->Name,
                resourceBase,
                nameBuffer,
                sizeof(nameBuffer)
                );
            printf(
                "Name: %s  DataEntryOffs: %08X\n",
                nameBuffer,
                resDirEntry->OffsetToData
                );
        }
        else
        {
            printf(
                "ID: %08X  DataEntryOffs: %08X\n",
                resDirEntry->Name,
                resDirEntry->OffsetToData
                );
        }

        for (i = 0; i < level; i++)
        {
            printf(" ");
        }

        pResDataEntry = (PIMAGE_RESOURCE_DATA_ENTRY) (resourceBase + resDirEntry->OffsetToData);

        if (
            IsAddressInRange(
                (BYTE*) pResDataEntry,
                (int) sizeof(IMAGE_RESOURCE_DATA_ENTRY)
                )
            )
        {
            printf(
                "DataRVA: %05X  DataSize: %05X  CodePage: %X\n",
                pResDataEntry->OffsetToData,
                pResDataEntry->Size,
                pResDataEntry->CodePage
                );
        }
        else
        {
            printf(
                "TODO: DumpResourceEntry - PIMAGE_RESOURCE_DATA_ENTRY out of range - %p\n",
                pResDataEntry
                );
        }
    }
    else
    {
        printf(
            "TODO: DumpResourceEntry - PIMAGE_RESOURCE_DIRECTORY_ENTRY out of range - %p\n",
            resDirEntry
            );
    }
}

void
DumpResourceDirectory(
    PIMAGE_RESOURCE_DIRECTORY resDir,
    BYTE* resourceBase,
    DWORD level,
    DWORD resourceType
    )
{
    PIMAGE_RESOURCE_DIRECTORY_ENTRY resDirEntry;
    char szType[64];
    UINT i;

    if (level == 1)
    {
        printf(" ---------------------------------------------------" "-----------\n");

        if (resourceType & IMAGE_RESOURCE_NAME_IS_STRING)
        {
            GetResourceNameFromId(
                resourceType,
                resourceBase,
                szType,
                sizeof(szType)
                );
        }
        else
        {
            GetResourceTypeName(
                resourceType,
                szType,
                sizeof(szType)
                );
        }
    }
    else
    {
        GetResourceNameFromId(
            resourceType,
            resourceBase,
            szType,
            sizeof(szType)
            );
    }

    for (i = 0; i < level; i++)
    {
        printf(" ");
    }

    if (
        IsAddressInRange(
            (BYTE*) resDir,
            (int) sizeof(IMAGE_RESOURCE_DIRECTORY)
            )
        )
    {
        printf(
            "ResDir (%s) Entries:%02X (Named:%02X, ID:%02X) TimeDate:%08X",
            szType,
            resDir->NumberOfNamedEntries + resDir->NumberOfIdEntries,
            resDir->NumberOfNamedEntries,
            resDir->NumberOfIdEntries,
            resDir->TimeDateStamp
            );

        if (resDir->MajorVersion || resDir->MinorVersion)
        {
            printf(
                " Vers:%u.%02u",
                resDir->MajorVersion,
                resDir->MinorVersion
                );
        }

        if (resDir->Characteristics)
        {
            printf(
                " Char:%08X",
                resDir->Characteristics
                );
        }

        printf("\n");
        resDirEntry = (PIMAGE_RESOURCE_DIRECTORY_ENTRY) (resDir + 1);

        if ((level == 1) && (resourceType == (LONGLONG) RT_STRING))
        {
            pStrResEntries = resDirEntry;
            cStrResEntries = resDir->NumberOfIdEntries;
        }

        if ((level == 1) && (resourceType == (LONGLONG) RT_DIALOG))
        {
            pDlgResEntries = resDirEntry;
            cDlgResEntries = resDir->NumberOfIdEntries;
        }

        for (i = 0; i < resDir->NumberOfNamedEntries; i++, resDirEntry++)
        {
            DumpResourceEntry(
                resDirEntry,
                resourceBase,
                level + 1
                );
        }

        for (i = 0; i < resDir->NumberOfIdEntries; i++, resDirEntry++)
        {
            DumpResourceEntry(
                resDirEntry,
                resourceBase,
                level + 1
                );
        }
    }
    else
    {
        printf(
            "TODO: DumpResourceDirectory - IMAGE_RESOURCE_DIRECTORY out of range - %p\n",
            resDir
            );
    }
}

void
DumpResourceSection(
    BYTE* base,
    PIMAGE_NT_HEADERS pNTHeader
    )
{
    DWORD resourcesRVA;
    PIMAGE_RESOURCE_DIRECTORY resDir;

    resourcesRVA = GetImgDirEntryRVA(
        pNTHeader,
        IMAGE_DIRECTORY_ENTRY_RESOURCE
        );

    if (!resourcesRVA)
    {
        return;
    }

    resDir = (PIMAGE_RESOURCE_DIRECTORY) GetPtrFromRVA(
        resourcesRVA,
        pNTHeader,
        base
        );

    if (!resDir)
    {
        printf(
            "TODO: (PIMAGE_RESOURCE_DIRECTORY)GetPtrFromRVA failed RVA %08X\n",
            resourcesRVA
            );

        return;
    }

    if (!fShowResources)
    {
        return;
    }

    if (
        !IsAddressInRange(
            (BYTE*) resDir,
            (int) sizeof(IMAGE_RESOURCE_DIRECTORY)
            )
        )
    {
        printf(
            "TODO: DumpResourceSection Resources (RVA: %X), PIMAGE_RESOURCE_DIRECTORY out of range - %p\n",
            resourcesRVA,
            resDir
            );

        return;
    }

    WORD nNamed                                 = resDir->NumberOfNamedEntries;
    WORD nIds                                   = resDir->NumberOfIdEntries;
    PIMAGE_RESOURCE_DIRECTORY_ENTRY resDirEntry = (PIMAGE_RESOURCE_DIRECTORY_ENTRY) (resDir + 1);

    printf(
        "Resources (RVA: %X), named %u, ids %u\n",
        resourcesRVA,
        nNamed,
        nIds
        );
    UINT i;
    BOOL isValid = TRUE;
    DWORD disd, name, niss, niso, offd, offD, id;
    DWORD isDirectory = 0;
    DWORD isString    = 0;
    PIMAGE_RESOURCE_DATA_ENTRY pResDataEntry;

    for (i = 0; i < nNamed; i++, resDirEntry++)
    {
        if (
            !IsAddressInRange(
                (BYTE*) resDirEntry,
                (int) sizeof(IMAGE_RESOURCE_DIRECTORY_ENTRY)
                )
            )
        {
            isValid = FALSE;
            break;
        }

        disd = resDirEntry->DataIsDirectory;
        id   = resDirEntry->Id;
        name = resDirEntry->Name;
        niss = resDirEntry->NameIsString;
        niso = resDirEntry->NameOffset;
        offd = resDirEntry->OffsetToData;
        offD = resDirEntry->OffsetToDirectory;

        if (offd & IMAGE_RESOURCE_DATA_IS_DIRECTORY)
        {
            isDirectory++;
        }
        else
        {
            if (name & IMAGE_RESOURCE_NAME_IS_STRING)
            {
                isString++;
            }
            else
            {
                pResDataEntry = (PIMAGE_RESOURCE_DATA_ENTRY) ((BYTE*) resDir + offd);

                if (
                    !IsAddressInRange(
                        (BYTE*) pResDataEntry,
                        (int) sizeof(IMAGE_RESOURCE_DATA_ENTRY)
                        )
                    )
                {
                    isValid = FALSE;
                    break;
                }
            }
        }
    }

    if (isValid)
    {
        if (nNamed)
        {
            resDirEntry++;
        }

        for (i = 0; i < nIds; i++, resDirEntry++)
        {
            if (
                !IsAddressInRange(
                    (BYTE*) resDirEntry,
                    (int) sizeof(IMAGE_RESOURCE_DIRECTORY_ENTRY)
                    )
                )
            {
                isValid = FALSE;
                break;
            }

            disd = resDirEntry->DataIsDirectory;
            id   = resDirEntry->Id;
            name = resDirEntry->Name;
            niss = resDirEntry->NameIsString;
            niso = resDirEntry->NameOffset;
            offd = resDirEntry->OffsetToData;
            offD = resDirEntry->OffsetToDirectory;

            if (offd & IMAGE_RESOURCE_DATA_IS_DIRECTORY)
            {
                isDirectory++;
            }
            else
            {
                if (name & IMAGE_RESOURCE_NAME_IS_STRING)
                {
                    isString++;
                }
                else
                {
                    pResDataEntry = (PIMAGE_RESOURCE_DATA_ENTRY) ((BYTE*) resDir + offd);

                    if (
                        !IsAddressInRange(
                            (BYTE*) pResDataEntry,
                            (int) sizeof(IMAGE_RESOURCE_DATA_ENTRY)
                            )
                        )
                    {
                        isValid = FALSE;
                        break;
                    }
                }
            }
        }
    }

    if (isValid)
    {
        DumpResourceDirectory(
            resDir,
            (BYTE*) resDir,
            0,
            0
            );
    }
    else
    {
        printf("TODO: Walking PIMAGE_RESOURCE_DIRECTORY FAILED\n");
    }

    printf("\n");

    if (cStrResEntries)
    {
        printf("String Table\n");

        DumpStringTable(
            base,
            pNTHeader,
            (BYTE*) resDir,
            pStrResEntries,
            cStrResEntries
            );
        printf("\n");
    }

    if (cDlgResEntries)
    {
        printf("Dialogs\n");

        DumpDialogs(
            base,
            pNTHeader,
            (BYTE*) resDir,
            pDlgResEntries,
            cDlgResEntries
            );
        printf("\n");
    }
}