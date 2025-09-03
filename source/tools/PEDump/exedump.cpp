#include "pch.h"
#include "common.h"
#include "symboltablesupport.h"
#include "coffsymboltable.h"
#include "resdump.h"
#include "extrnvar.h"

int Is32 = 0;
PIMAGE_OPTIONAL_HEADER64 opt64 = 0;
PIMAGE_OPTIONAL_HEADER32 opt32 = 0;

void DumpExeDebugDirectory(BYTE *base, PIMAGE_NT_HEADERS pNTHeader)
{
    PIMAGE_DEBUG_DIRECTORY debugDir;
    PIMAGE_SECTION_HEADER header;
    DWORD va_debug_dir;
    DWORD size;
    
    va_debug_dir = GetImgDirEntryRVA(pNTHeader, IMAGE_DIRECTORY_ENTRY_DEBUG);

    if ( va_debug_dir == 0 )
        return;

    header = GetSectionHeader((PSTR)".debug", pNTHeader);
    if ( header && (header->VirtualAddress == va_debug_dir) )
    {
        debugDir = (PIMAGE_DEBUG_DIRECTORY)(header->PointerToRawData+base);
        size = GetImgDirEntrySize(pNTHeader, IMAGE_DIRECTORY_ENTRY_DEBUG)
                * sizeof(IMAGE_DEBUG_DIRECTORY);
    }
    else         
    {
        header = GetEnclosingSectionHeader( va_debug_dir, pNTHeader );
        if ( !header )
            return;

        size = GetImgDirEntrySize( pNTHeader, IMAGE_DIRECTORY_ENTRY_DEBUG );
    
        debugDir = MakePtr(PIMAGE_DEBUG_DIRECTORY, base,
                            header->PointerToRawData
							+ (va_debug_dir - header->VirtualAddress) );
    }

    DumpDebugDirectory( debugDir, size, base );
}


void DumpImportsSection32(BYTE *base, PIMAGE_NT_HEADERS pNTHeader)
{
    PIMAGE_IMPORT_DESCRIPTOR importDesc;
    PIMAGE_SECTION_HEADER pSection;
    PIMAGE_THUNK_DATA32 thunk, thunkIAT=0;
    PIMAGE_IMPORT_BY_NAME pOrdinalName;
    DWORD importsStartRVA;
	PSTR pszTimeDate;
    DWORD count = 0;
    DWORD totentries = 0;
    DWORD hdrcnt = 0;

    importsStartRVA = GetImgDirEntryRVA(pNTHeader,IMAGE_DIRECTORY_ENTRY_IMPORT);
    if ( !importsStartRVA )
        return;

    pSection = GetEnclosingSectionHeader( importsStartRVA, pNTHeader );
    if ( !pSection )
        return;

    importDesc = (PIMAGE_IMPORT_DESCRIPTOR)GetPtrFromRVA(importsStartRVA,pNTHeader,base);
    if (!importDesc) {
        printf("TODO: (PIMAGE_IMPORT_DESCRIPTOR)GetPtrFromRVA failed RVA %08X\n", importsStartRVA);
        return;
    }
            
    printf("Imports Table: thunk32\n");
    
    while ( 1 )
    {
        if ( (importDesc->TimeDateStamp==0 ) && (importDesc->Name==0) )
            break;
        
        char *pimp = (char *)GetPtrFromRVA(importDesc->Name, pNTHeader, base);
        if (!pimp) {
            printf("TODO: (char *)GetPtrFromRVA failed RVA %08X\n", importDesc->Name);
            break;
        }
        add_2_dll_list(pimp);

        count++;

        printf("  %s\n", pimp );


        printf("  OrigFirstThunk:  %08X (Unbound IAT)\n",
      			importDesc->Characteristics);

        if (importDesc->TimeDateStamp) {
            pszTimeDate = get_ctime_stg((time_t *)&importDesc->TimeDateStamp);
            printf("  TimeDateStamp:   %08X", importDesc->TimeDateStamp);
            printf(pszTimeDate ? " -> %s\n" : "\n", pszTimeDate);
        }

        printf("  ForwarderChain:  %08X\n", importDesc->ForwarderChain);
        printf("  First thunk RVA: %08X\n", importDesc->FirstThunk);
    
        DWORD dwthunk = importDesc->Characteristics;
        DWORD dwthunkIAT = importDesc->FirstThunk;

        if ( dwthunk == 0 )      
        {
            dwthunk = dwthunkIAT;
            
            if ( dwthunk == 0 )        
                return;
        }
        
        thunk = (PIMAGE_THUNK_DATA32)GetPtrFromRVA(dwthunk, pNTHeader, base);
        if (!thunk) {
            printf("TODO: (PIMAGE_THUNK_DATA32)GetPtrFromRVA failed RVA %08X\n", dwthunk);
            return;
        }

        thunkIAT = (PIMAGE_THUNK_DATA32)GetPtrFromRVA(dwthunkIAT, pNTHeader, base);
        if (!thunkIAT) {
            printf("TODO: (PIMAGE_THUNK_DATA32)GetPtrFromRVA failed RVA %08X\n", dwthunkIAT);
            return;
        }
    
        printf("  Ordn  Name\n");
        hdrcnt = 0;
        while ( 1 )        
        {
            if ( thunk->u1.AddressOfData == 0 )
                break;

            hdrcnt++;
            totentries++;
            if ( thunk->u1.Ordinal & IMAGE_ORDINAL_FLAG32 )
            {
                printf( "  %4u", IMAGE_ORDINAL32(thunk->u1.Ordinal) );
            }
            else
            {
                DWORD dwOff = (DWORD)thunk->u1.AddressOfData;
                pOrdinalName = (PIMAGE_IMPORT_BY_NAME)GetPtrFromRVA(dwOff, pNTHeader, base);
                if (!pOrdinalName) {
                    printf("TODO: (PIMAGE_IMPORT_BY_NAME)GetPtrFromRVA failed RVA %08X\n", dwOff);
                    break;
                }
                printf("  %4u  %s", pOrdinalName->Hint, pOrdinalName->Name);
            }
            
            if ( fShowIATentries || importDesc->TimeDateStamp )
                printf( " (Bound to: %08X)", thunkIAT->u1.Function );

            printf( "\n" );

            thunk++;                
            thunkIAT++;             
        }
        printf("Done %u entries.\n", hdrcnt);
        importDesc++;       
        printf("\n");
    }
    printf("Done %u imports... total %u entries...\n", count, totentries);
}

void DumpImportsSection64(BYTE *base, PIMAGE_NT_HEADERS pNTHeader)
{
    PIMAGE_IMPORT_DESCRIPTOR importDesc;
    PIMAGE_SECTION_HEADER pSection;
    PIMAGE_THUNK_DATA64 thunk, thunkIAT = 0;
    PIMAGE_IMPORT_BY_NAME pOrdinalName;
    DWORD importsStartRVA;
    PSTR pszTimeDate;
    DWORD count = 0;
    DWORD totentries = 0;
    DWORD hdrcnt = 0;

    importsStartRVA = GetImgDirEntryRVA(pNTHeader, IMAGE_DIRECTORY_ENTRY_IMPORT);
    if (!importsStartRVA)
        return;

    pSection = GetEnclosingSectionHeader(importsStartRVA, pNTHeader);
    if (!pSection)
        return;

    importDesc = (PIMAGE_IMPORT_DESCRIPTOR) GetPtrFromRVA(importsStartRVA, pNTHeader, base);
    if (!importDesc) {
        printf("TODO: (PIMAGE_IMPORT_DESCRIPTOR) GetPtrFromRVA failed with RVA %08X\n", importsStartRVA);
        return;
    }

    printf("Imports Table: thunk64\n");

    while (1)
    {
        if ((importDesc->TimeDateStamp == 0) && (importDesc->Name == 0))
            break;

        char *pimp = (char *)GetPtrFromRVA(importDesc->Name, pNTHeader, base);
        if (!pimp) {
            printf("TODO: (char *)GetPtrFromRVA from RVA %08X\n", importDesc->Name);
            break;
        }

        add_2_dll_list(pimp);

        count++;
        printf("  %s\n", pimp);


        printf("  OrigFirstThunk:  %08X (Unbound IAT)\n",
            importDesc->Characteristics);

        if (importDesc->TimeDateStamp) {
            pszTimeDate = get_ctime_stg((time_t *)&importDesc->TimeDateStamp);
            printf("  TimeDateStamp:   %08X", importDesc->TimeDateStamp);
            printf(pszTimeDate ? " -> %s\n" : "\n", pszTimeDate);
        }

        printf("  ForwarderChain:  %08X\n", importDesc->ForwarderChain);
        printf("  First thunk RVA: %08X\n", importDesc->FirstThunk);

        DWORD dwthunk = importDesc->Characteristics;
        DWORD dwthunkIAT = importDesc->FirstThunk;

        if (dwthunk == 0)      
        {
            dwthunk = dwthunkIAT;

            if (dwthunk == 0)        
                return;
        }

        thunk = (PIMAGE_THUNK_DATA64)GetPtrFromRVA(dwthunk, pNTHeader, base);
        if (!thunk) {
            printf("TODO: (PIMAGE_THUNK_DATA64)GetPtrFromRVA from RVA %08X\n", dwthunk);
            return;
        }

        thunkIAT = (PIMAGE_THUNK_DATA64)GetPtrFromRVA(dwthunkIAT, pNTHeader, base);
        if (!thunkIAT) {
            printf("TODO: (PIMAGE_THUNK_DATA64)GetPtrFromRVA failed with RVA %08X\n", dwthunkIAT);
            return;
        }

        printf("  Ordn  Name\n");
        hdrcnt = 0;
        while (1)        
        {
            if (thunk->u1.AddressOfData == 0)
                break;

            hdrcnt++;
            totentries++;
            if (thunk->u1.Ordinal & IMAGE_ORDINAL_FLAG64)
            {
                printf("  %4llu", IMAGE_ORDINAL64(thunk->u1.Ordinal));
            }
            else
            {
                DWORD dwOff = (DWORD)thunk->u1.AddressOfData;
                pOrdinalName = (PIMAGE_IMPORT_BY_NAME)GetPtrFromRVA(dwOff, pNTHeader, base);
                if (!pOrdinalName) {
                    printf("TODO: (PIMAGE_IMPORT_BY_NAME)GetPtrFromRVA failed RVA %08X\n", dwOff);
                    break;
                }

                printf("  %4u  %s", pOrdinalName->Hint, pOrdinalName->Name);
            }

            if (fShowIATentries || importDesc->TimeDateStamp)
                printf(" (Bound to: %08llX)", (unsigned long long)thunkIAT->u1.Function);

            printf("\n");

            thunk++;                
            thunkIAT++;             
        }
        printf("Done %u entries\n", hdrcnt);
        importDesc++;       
        printf("\n");
    }
    printf("Done %u imports... total %u entries...\n", count, totentries);
}

void DumpImportsSection(BYTE *base, PIMAGE_NT_HEADERS pNTHeader)
{
    if (Is32)
        DumpImportsSection32(base, pNTHeader);
    else
        DumpImportsSection64(base, pNTHeader);
}




PSTR GetSafeFileName(PSTR fn1, PSTR filename)
{
    PSTR cp = GetNxtBuf();
    int i, c, len, max = 256;
    int got0 = 0;
    *cp = 0;
    len = 0;
    if (IsAddressInRange((BYTE *)fn1, max)) {
        for (i = 0; i < max; i++) {
            c = fn1[i] & 0xff;
            if (c == 0) {
                got0 = 1;
                break;
            }
            else if ((c >= 0x20) && (c < 128)) {
                cp[len++] = c;
                cp[len] = 0;
            }
            else
                break;
        }
    }
    if (got0 && len)
        return cp;
    *cp = 0;
    len = 0;
    if (IsAddressInRange((BYTE *)fn1, max)) {
        for (i = 0; i < max; i++) {
            c = fn1[i] & 0xff;
            if (c == 0) {
                got0 = 1;
                break;
            }
            else if ((c >= 0x20) && (c < 128)) {
                cp[len++] = c;
                cp[len] = 0;
            }
            else
                break;
        }
    }
    if (got0 && len)
        return cp;
    cp = (PSTR)"N/A";
    return cp;
}


void DumpExportsSection(BYTE *base, PIMAGE_NT_HEADERS pNTHeader)
{
    PIMAGE_EXPORT_DIRECTORY exportDir;
    PIMAGE_SECTION_HEADER header;
    INT delta; 
    PSTR filename;
    DWORD i;
    PDWORD functions;
    PWORD ordinals;
    DWORD exportsStartRVA, exportsEndRVA;
    
    exportsStartRVA = GetImgDirEntryRVA(pNTHeader,IMAGE_DIRECTORY_ENTRY_EXPORT);
    exportsEndRVA = exportsStartRVA +
	   				GetImgDirEntrySize(pNTHeader, IMAGE_DIRECTORY_ENTRY_EXPORT);

    header = GetEnclosingSectionHeader( exportsStartRVA, pNTHeader );
    if ( !header )
        return;

    delta = (INT)(header->VirtualAddress - header->PointerToRawData);
    
    exportDir = MakePtr(PIMAGE_EXPORT_DIRECTORY, base,
                         exportsStartRVA - delta);

    DWORD Rva = exportDir->Name;
    PSTR fn1 = (PSTR)(base + (Rva - delta));
    filename = (PSTR)(base + Rva);   
    filename = GetSafeFileName(fn1, filename);

    printf("exports table:\n\n");
    printf("  Name:            %s\n", filename);
    printf("  Characteristics: %08X\n", exportDir->Characteristics);
    printf("  TimeDateStamp:   %08X -> %s\n",
    			exportDir->TimeDateStamp,
    			get_ctime_stg((time_t *)&exportDir->TimeDateStamp) );
    printf("  Version:         %u.%02u\n", exportDir->MajorVersion,
            exportDir->MinorVersion);
    printf("  Ordinal base:    %08X\n", exportDir->Base);
    printf("  # of functions:  %08X\n", exportDir->NumberOfFunctions);
    printf("  # of Names:      %08X\n", exportDir->NumberOfNames);
    
    functions = (PDWORD)(base + (exportDir->AddressOfFunctions - delta));
    ordinals = (PWORD)(base + (exportDir->AddressOfNameOrdinals - delta));
    DWORD *dwpname = (DWORD *)(base + (exportDir->AddressOfNames - delta));

    printf("\n  Entry Pt  Ordn  Name\n");
    for ( i=0; i < exportDir->NumberOfFunctions; i++ )
    {
        DWORD entryPointRVA = functions[i];
        DWORD j;

        if ( entryPointRVA == 0 )         
            continue;                     
        printf("  %08X  %4u", entryPointRVA, i + exportDir->Base );

        for ( j=0; j < exportDir->NumberOfNames; j++ )
            if (ordinals[j] == i) {
                INT off = dwpname[j];
                if (off > delta) {
                    BYTE *pn = base + (off - delta);
                    printf("  %s", pn);
                }
            }
        if ( (entryPointRVA >= exportsStartRVA)
             && (entryPointRVA <= exportsEndRVA) )
        {
            printf(" (forwarder -> %s)", entryPointRVA - delta + base );
        }
        
        printf("\n");
    }
}

void DumpRuntimeFunctions( BYTE *base, PIMAGE_NT_HEADERS pNTHeader )
{
	DWORD rtFnRVA;

	rtFnRVA = GetImgDirEntryRVA( pNTHeader, IMAGE_DIRECTORY_ENTRY_EXCEPTION );
	if ( !rtFnRVA )
		return;

	DWORD cEntries =
		GetImgDirEntrySize( pNTHeader, IMAGE_DIRECTORY_ENTRY_EXCEPTION )
		/ sizeof( IMAGE_RUNTIME_FUNCTION_ENTRY );
	if ( 0 == cEntries )
		return;

	PIMAGE_RUNTIME_FUNCTION_ENTRY pRTFn = (PIMAGE_RUNTIME_FUNCTION_ENTRY)GetPtrFromRVA( rtFnRVA, pNTHeader, base );
    if (!pRTFn) {
        printf("TODO: (PIMAGE_RUNTIME_FUNCTION_ENTRY)GetPtrFromRVA failed RVA %08X\n", rtFnRVA);
        return;
    }

    if (!DoesSectionExist("EXCEPTION")) {
        printf("Runtime Function Table (Exception handling) does NOT exist\n");//, cEntries);
        return;
    }

	printf( "Runtime Function Table (Exception handling) - count %lu\n", cEntries );
#ifdef	ADD_EXCEPTION_HANDLER
    printf( "  Begin     End       Handler   HndlData  PrologEnd\n" );
	printf( "  --------  --------  --------  --------  --------\n" );
#else
    printf("  Begin     End     \n");
    printf("  --------  --------\n");
#endif
	for ( unsigned i = 0; i < cEntries; i++, pRTFn++ )
	{
#ifdef	ADD_EXCEPTION_HANDLER
        printf("  %08X  %08X  %08X  %08X  %08X",
            pRTFn->BeginAddress, pRTFn->EndAddress, pRTFn->ExceptionHandler,
            pRTFn->HandlerData, pRTFn->PrologEndAddress);
#else
        printf("  %08X  %08X",
            pRTFn->BeginAddress, pRTFn->EndAddress);
#endif

		if ( g_pCOFFSymbolTable )
		{
#if 0  
			PCOFFSymbol pSymbol
				= g_pCOFFSymbolTable->GetNearestSymbolFromRVA(
										pRTFn->BeginAddress
										- pNTHeader->OptionalHeader.ImageBase,
										TRUE );
			if ( pSymbol )
				printf( "  %s", pSymbol->GetName() );

			delete pSymbol;
#endif  
		}

		printf( "\n" );
	}

    if (g_pCOFFSymbolTable)
        printf("TODO: Get symbol name 32/64 bits... using g_pCOFFSymbolTable - %p\n", g_pCOFFSymbolTable);
}

const char *SzRelocTypes[] = {
"ABSOLUTE","HIGH","LOW","HIGHLOW","HIGHADJ","MIPS/ARM",
"SECTION","REL32","MIPS16","DIR64", "TYPE10" };

#define RELOC_TYPE_COUNT (sizeof(SzRelocTypes) / sizeof(char *))
void DumpBaseRelocationsSection(BYTE *base, PIMAGE_NT_HEADERS pNTHeader)
{
	DWORD dwBaseRelocRVA;
    PIMAGE_BASE_RELOCATION baseReloc;

	dwBaseRelocRVA =
		GetImgDirEntryRVA( pNTHeader, IMAGE_DIRECTORY_ENTRY_BASERELOC );
    if ( !dwBaseRelocRVA )
        return;

    baseReloc = (PIMAGE_BASE_RELOCATION)GetPtrFromRVA( dwBaseRelocRVA, pNTHeader, base );
    if (!baseReloc) {
        printf("TODO: (PIMAGE_BASE_RELOCATION)GetPtrFromRVA failed RVA %08X\n", dwBaseRelocRVA);
        return;
    }

    printf("base relocations:\n\n");

    while ( baseReloc->SizeOfBlock != 0 )
    {
        unsigned i,cEntries;
        PWORD pEntry;
        const char *szRelocType;
        WORD relocType;

		if ( 0 == baseReloc->VirtualAddress )
			break;
		if ( baseReloc->SizeOfBlock < sizeof(*baseReloc) )
			break;
		
        cEntries = (baseReloc->SizeOfBlock-sizeof(*baseReloc))/sizeof(WORD);
        pEntry = MakePtr( PWORD, baseReloc, sizeof(*baseReloc) );
        
        printf("Virtual Address: %08X  size: %08X\n",
                baseReloc->VirtualAddress, baseReloc->SizeOfBlock);
            
        for ( i=0; i < cEntries; i++ )
        {
            relocType = (*pEntry & 0xF000) >> 12;
            szRelocType = (relocType < RELOC_TYPE_COUNT) ? SzRelocTypes[relocType] : (const char *)"unknown";
            
            printf("  %08X %s",
                    (*pEntry & 0x0FFF) + baseReloc->VirtualAddress,
                    szRelocType);

			if ( IMAGE_REL_BASED_HIGHADJ == relocType )
			{
				pEntry++;
				cEntries--;
				printf( " (%X)", *pEntry );
			}

			printf( "\n" );
            pEntry++;        
        }
        
        baseReloc = MakePtr( PIMAGE_BASE_RELOCATION, baseReloc,
                             baseReloc->SizeOfBlock);
    }
}

void DumpBoundImportDescriptors( BYTE *base, PIMAGE_NT_HEADERS pNTHeader )
{
    DWORD bidRVA;       
    PIMAGE_BOUND_IMPORT_DESCRIPTOR pibid;

    bidRVA = GetImgDirEntryRVA(pNTHeader, IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT);
    if ( !bidRVA )
        return;
    
    pibid = MakePtr( PIMAGE_BOUND_IMPORT_DESCRIPTOR, base, bidRVA );
    if (!IsAddressInRange((BYTE *)pibid, (int)sizeof(IMAGE_BOUND_IMPORT_DESCRIPTOR))) {
        printf("TODO: DumpBoundImportDescriptors PIMAGE_BOUND_IMPORT_DESCRIPTOR out of range - %p\n", pibid);
        return;
    }
    printf( "Bound import descriptors:\n\n" );
    printf( "  Module        TimeDate\n" );
    printf( "  ------------  --------\n" );
    
    while ( pibid->TimeDateStamp )
    {
        unsigned i;
        PIMAGE_BOUND_FORWARDER_REF pibfr;
        WORD off = pibid->OffsetModuleName;
        BYTE *pMod = base + bidRVA + off;
        if (!IsAddressInRange(pMod, 32)) {
            printf("TODO: DumpBoundImportDescriptors pMod out of range - %p\n", pMod);
            return;
        }
        printf( "  %-12s  %08X -> %s\n",
        		pMod,        
                pibid->TimeDateStamp,
                get_ctime_stg((time_t *)&pibid->TimeDateStamp) );
                            
        pibfr = MakePtr(PIMAGE_BOUND_FORWARDER_REF, pibid,
                            sizeof(IMAGE_BOUND_IMPORT_DESCRIPTOR));

        for ( i=0; i < pibid->NumberOfModuleForwarderRefs; i++ )
        {
            printf("    forwarder:  %-12s  %08X -> %s\n", 
                            base + bidRVA + pibfr->OffsetModuleName,
                            pibfr->TimeDateStamp,
                            get_ctime_stg((time_t *)&pibfr->TimeDateStamp) );
            pibfr++;         
                
            pibid = MakePtr( PIMAGE_BOUND_IMPORT_DESCRIPTOR, pibid,
                             sizeof( IMAGE_BOUND_FORWARDER_REF ) );
        }

        pibid++;        
    }
}

void DumpExeFile( PIMAGE_DOS_HEADER dosHeader )
{
    PIMAGE_NT_HEADERS pNTHeader;
    BYTE *base = (BYTE *)dosHeader;
    
    pNTHeader = MakePtr( PIMAGE_NT_HEADERS, dosHeader,
                                dosHeader->e_lfanew );

        if ( pNTHeader->Signature != IMAGE_NT_SIGNATURE )
        {
            printf("Not a Portable Executable (PE) EXE\n");
            return;
        }
    PIMAGE_NT_HEADERS32 header32 = (PIMAGE_NT_HEADERS32)pNTHeader;
    PIMAGE_NT_HEADERS64 header64 = (PIMAGE_NT_HEADERS64)pNTHeader;
    PIMAGE_OPTIONAL_HEADER64 opt64 = 0;
    PIMAGE_OPTIONAL_HEADER32 opt32 = 0;
    
    DumpHeader((PIMAGE_FILE_HEADER)&pNTHeader->FileHeader);
    if (fShowMachineType)
        return;

    printf("\n");

    if (header32->OptionalHeader.Magic == IMAGE_NT_OPTIONAL_HDR32_MAGIC) {  
        Is32 = 1;
        opt32 = &header32->OptionalHeader;
    }
    else if (header32->OptionalHeader.Magic == IMAGE_NT_OPTIONAL_HDR64_MAGIC) {  
        opt64 = &header64->OptionalHeader;
        Is32 = 0;
    }
    else {
        printf("Is NOT a PE32 nor PE32+ magic value! Got %x\n", header32->OptionalHeader.Magic);
        return;
    }
    if (Is32) {
        DumpOptionalHeader32(opt32);
    }
    else {
        DumpOptionalHeader64(opt64);
    }
    printf("\n");

    DumpSectionTable( IMAGE_FIRST_SECTION(pNTHeader), pNTHeader->FileHeader.NumberOfSections, TRUE, "exedump");
    printf("\n");

    DumpExeDebugDirectory(base, pNTHeader);
    if ( pNTHeader->FileHeader.PointerToSymbolTable == 0 )
        g_pCOFFHeader = 0;    
    printf("\n");

    DumpResourceSection(base, pNTHeader);
    printf("\n");

    DumpImportsSection(base, pNTHeader);
    printf("\n");
    
    if ( GetImgDirEntryRVA( pNTHeader, IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT) )
    {
        DumpBoundImportDescriptors( base, pNTHeader );
        printf( "\n" );
    }
    
    if (DoesSectionExist("EXPORT") && GetImgDirEntryRVA(pNTHeader, IMAGE_DIRECTORY_ENTRY_EXPORT)) {
        DumpExportsSection(base, pNTHeader);
    }
    else {
        printf("No EXPORT section to dump\n");
    }

    printf("\n");
	if ( g_pCOFFHeader )	         
	{						    
		g_pCOFFSymbolTable = new COFFSymbolTable(
				(PVOID)(base+ pNTHeader->FileHeader.PointerToSymbolTable),
				pNTHeader->FileHeader.NumberOfSymbols );
	}

	if ( fShowPDATA )
	{
		DumpRuntimeFunctions( base, pNTHeader );
		printf( "\n" );
	}

    if ( fShowRelocations )
    {
        DumpBaseRelocationsSection(base, pNTHeader);
        printf("\n");
    } 

	if ( fShowSymbolTable && g_pMiscDebugInfo )
	{
		DumpMiscDebugInfo( g_pMiscDebugInfo );
		printf( "\n" );
	}

	if ( fShowSymbolTable && g_pCVHeader )
	{
		DumpCVDebugInfo( g_pCVHeader );
		printf( "\n" );
	}

    if ( fShowSymbolTable && g_pCOFFHeader )
    {
        DumpCOFFHeader( g_pCOFFHeader );
        printf("\n");
    }
    
    if ( fShowLineNumbers && g_pCOFFHeader )
    {
        DumpLineNumbers( MakePtr(PIMAGE_LINENUMBER, g_pCOFFHeader,
                            g_pCOFFHeader->LvaToFirstLinenumber),
                            g_pCOFFHeader->NumberOfLinenumbers);
        printf("\n");
    }

    if ( fShowSymbolTable )
    {
        if ( pNTHeader->FileHeader.NumberOfSymbols 
            && pNTHeader->FileHeader.PointerToSymbolTable
			&& g_pCOFFSymbolTable )
        {
            DumpSymbolTable( g_pCOFFSymbolTable );
            printf("\n");
        }
    }
    
    if ( fShowRawSectionData )
    {
        DumpRawSectionData(IMAGE_FIRST_SECTION(pNTHeader),
            dosHeader,
            pNTHeader->FileHeader.NumberOfSections);
    }

	if ( g_pCOFFSymbolTable )
		delete g_pCOFFSymbolTable;
    g_pCOFFSymbolTable = 0;
}
