#include "pch.h"
#include "common.h"
#include "coffsymboltable.h"
#include "extrnvar.h"
#include "cv_dbg.h"

void
DumpCOFFHeader(PIMAGE_COFF_SYMBOLS_HEADER pDbgInfo)
{
    printf("COFF Debug Info Header\n");
    printf(
        "  NumberOfSymbols:      %08X\n",
        pDbgInfo->NumberOfSymbols
        );
    printf(
        "  LvaToFirstSymbol:     %08X\n",
        pDbgInfo->LvaToFirstSymbol
        );
    printf(
        "  NumberOfLinenumbers:  %08X\n",
        pDbgInfo->NumberOfLinenumbers
        );
    printf(
        "  LvaToFirstLinenumber: %08X\n",
        pDbgInfo->LvaToFirstLinenumber
        );
    printf(
        "  RvaToFirstByteOfCode: %08X\n",
        pDbgInfo->RvaToFirstByteOfCode
        );
    printf(
        "  RvaToLastByteOfCode:  %08X\n",
        pDbgInfo->RvaToLastByteOfCode
        );
    printf(
        "  RvaToFirstByteOfData: %08X\n",
        pDbgInfo->RvaToFirstByteOfData
        );
    printf(
        "  RvaToLastByteOfData:  %08X\n",
        pDbgInfo->RvaToLastByteOfData
        );
}

BOOL
LookupSymbolName(
    DWORD index,
    PSTR buffer,
    UINT length
    )
{
    if (!g_pCOFFSymbolTable)
    {
        return FALSE;
    }

    PCOFFSymbol pSymbol = g_pCOFFSymbolTable->GetSymbolFromIndex(index);

    if (!pSymbol)
    {
        return FALSE;
    }

    lstrcpynA(
        buffer,
        pSymbol->GetName(),
        length
        );

    delete pSymbol;

    return TRUE;
}

void
DumpLineNumbers(
    PIMAGE_LINENUMBER pln,
    DWORD count
    )
{
    char buffer[64];
    DWORD i;

    printf("Line Numbers\n");

    for (i = 0; i < count; i++)
    {
        if (pln->Linenumber == 0)
        {
            buffer[0] = 0;
            LookupSymbolName(
                pln->Type.SymbolTableIndex,
                buffer,
                sizeof(buffer)
                );
            printf(
                "SymIndex: %X (%s)\n",
                pln->Type.SymbolTableIndex,
                buffer
                );
        }
        else
        {
            printf(
                " Addr: %05X  Line: %04u\n",
                pln->Type.VirtualAddress,
                pln->Linenumber
                );
        }

        pln++;
    }
}

void
GetSectionName(
    WORD section,
    PSTR buffer,
    unsigned cbBuffer
    )
{
    char tempbuffer[10];

    switch ((SHORT) section)
    {
        case IMAGE_SYM_UNDEFINED: strcpy(
            tempbuffer,
            "UNDEF"
            ); break;
        case IMAGE_SYM_ABSOLUTE: strcpy(
            tempbuffer,
            "ABS"
            ); break;
        case IMAGE_SYM_DEBUG: strcpy(
            tempbuffer,
            "DEBUG"
            ); break;
        default: sprintf(
            tempbuffer,
            "%X",
            section
            );
    }

    strncpy(
        buffer,
        tempbuffer,
        cbBuffer - 1
        );
}

void
DumpSymbolTable(COFFSymbolTable* pSymTab)
{
    printf(
        "Symbol Table - %X entries  (* = auxillary symbol)\n",
        pSymTab->GetNumberOfSymbols()
        );

    printf("Indx Sectn Value Type Storage Name\n" "---- ----- -------- ----- ------- --------\n");

    PCOFFSymbol pSymbol = pSymTab->GetNextSymbol(0);

    while (pSymbol)
    {
        char szSection[10];
        GetSectionName(
            pSymbol->GetSectionNumber(),
            szSection,
            sizeof(szSection)
            );

        printf(
            "%04X %5s %08X  %s %-8s %s\n",
            pSymbol->GetIndex(),
            szSection,
            pSymbol->GetValue(),
            pSymbol->GetTypeName(),
            pSymbol->GetStorageClassName(),
            pSymbol->GetName()
            );

        if (pSymbol->GetNumberOfAuxSymbols())
        {
            char szAuxSymbol[1024];

            if (
                pSymbol->GetAuxSymbolAsString(
                    szAuxSymbol,
                    sizeof(szAuxSymbol)
                    )
                )
            {
                printf(
                    "     * %s\n",
                    szAuxSymbol
                    );
            }
        }

        pSymbol = pSymTab->GetNextSymbol(pSymbol);
    }
}

void
DumpMiscDebugInfo(PIMAGE_DEBUG_MISC pMiscDebugInfo)
{
    if (IMAGE_DEBUG_MISC_EXENAME != pMiscDebugInfo->DataType)
    {
        printf(
            "Unknown Miscellaneous Debug Information type: %u\n",
            pMiscDebugInfo->DataType
            );

        return;
    }

    printf("Miscellaneous Debug Information\n");
    printf(
        "  %s\n",
        pMiscDebugInfo->Data
        );
}

typedef struct tagmySDSR
{
    DWORD sig;
    BYTE guid[16];
    DWORD age;
    BYTE name[1];
} mySDSR, *pmySDSR;

void
DumpCVDebugInfo(PDWORD pCVHeader)
{
    PPDB_INFO pPDBInfo;
    int i;
    BYTE b;
    printf(
        "CodeView Signature: %08X\n",
        *pCVHeader
        );

    if ('01BN' == *pCVHeader)
    {
        pPDBInfo = (PPDB_INFO) pCVHeader;

        printf(
            "  Offset: %08X  Signature: %08X  Age: %08X\n",
            pPDBInfo->Offset,
            pPDBInfo->sig,
            pPDBInfo->age
            );
        printf(
            "  File: %s\n",
            pPDBInfo->PdbName
            );
    }
    else
    {
        if ('SDSR' == (UINT32) *pCVHeader)
        {
            pmySDSR pd = (pmySDSR) pCVHeader;
            // printf("Visual Studio .NET debug info %.4s\n", pCVHeader);
            printf(
                "Age: %u, GUID: ",
                pd->age
                );

            for (i = 0; i < 16; i++)
            {
                b = pd->guid[i];

                if (i && (i < 9))
                {
                    if (
                        ((i % 4) == 0) ||
                        ((i % 6) == 0) ||
                        ((i % 8) == 0)
                        )
                    {
                        printf("-");
                    }
                }

                printf(
                    "%02X",
                    b
                    );
            }

            printf("\n");
            printf(
                "File: %s\n",
                pd->name
                );
        }
        else
        {
            // printf("TODO: Unhandled CodeView Information format %.4s\n", pCVHeader);
        }
    }
}