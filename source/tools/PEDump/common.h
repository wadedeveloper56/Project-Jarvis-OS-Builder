//==================================
// PEDUMP - Matt Pietrek 1997
// FILE: common.h
//==================================
#ifndef _COMMON_H_
#define _COMMON_H_
#include <algorithm> // for std::sort
#include <vector>
#include <string>
#include <set>

#include "sprtf.hxx"
#include "utils.hxx"

typedef std::vector<std::string> vSTR;

// MakePtr is a macro that allows you to easily add to values (including
// pointers) together without dealing with C's pointer arithmetic.  It
// essentially treats the last two parameters as DWORDs.  The first
// parameter is used to typecast the result to the appropriate pointer type.
// #define MakePtr( cast, ptr, addValue ) (cast)( (DWORD)(ptr) + (DWORD)(addValue))
#define MakePtr( cast, ptr, addValue ) (cast)( (BYTE *)(ptr) + (DWORD)(addValue))

void DumpHeader(PIMAGE_FILE_HEADER pImageFileHeader);
void DumpOptionalHeader32(PIMAGE_OPTIONAL_HEADER32 pImageOptionalHeader);
void DumpOptionalHeader64(PIMAGE_OPTIONAL_HEADER64 pImageOptionalHeader);
void DumpSectionTable(PIMAGE_SECTION_HEADER section, unsigned cSections, BOOL IsEXE, const char *caller);
LPVOID GetSectionPtr(PSTR name, PIMAGE_NT_HEADERS pNTHeader, BYTE *imageBase);
LPVOID GetPtrFromRVA( DWORD rva, PIMAGE_NT_HEADERS pNTHeader, BYTE *imageBase );
PIMAGE_SECTION_HEADER GetSectionHeader(PSTR name, PIMAGE_NT_HEADERS pNTHeader);
PIMAGE_SECTION_HEADER GetEnclosingSectionHeader(DWORD rva,
                                                PIMAGE_NT_HEADERS pNTHeader);
void DumpRawSectionData(PIMAGE_SECTION_HEADER section,
                        PVOID base,
                        unsigned cSections);
void DumpDebugDirectory(PIMAGE_DEBUG_DIRECTORY debugDir, DWORD size, BYTE *base);
void DumpCOFFHeader(PIMAGE_COFF_SYMBOLS_HEADER pDbgInfo);
extern void HexDump(PBYTE ptr, DWORD length, PBYTE pb = 0);

PSTR GetMachineTypeName( WORD wMachineType );

#if 0 // 000000000000000000000000000000000000000000000000000000000000000000
#define GetImgDirEntryRVA( pNTHdr, IDE ) \
	(pNTHdr->OptionalHeader.DataDirectory[IDE].VirtualAddress)

#define GetImgDirEntrySize( pNTHdr, IDE ) \
	(pNTHdr->OptionalHeader.DataDirectory[IDE].Size)
#endif // 000000000000000000000000000000000000000000000000000000000000000000

extern DWORD GetImgDirEntryRVA(PVOID pNTHdr, DWORD);
//    (Is32) ? ((PIMAGE_OPTIONAL_HEADER32)pNTHdr->OptionalHeader.DataDirectory[IDE].VirtualAddress) : \
//  	((PIMAGE_OPTIONAL_HEADER64)pNTHdr->OptionalHeader.DataDirectory[IDE].VirtualAddress)

extern DWORD GetImgDirEntrySize(PVOID pNTHdr, DWORD IDE);
//    (Is32) ? ((PIMAGE_OPTIONAL_HEADER32)pNTHdr->OptionalHeader.DataDirectory[IDE].VirtualAddress) : \
//  	((PIMAGE_OPTIONAL_HEADER64)pNTHdr->OptionalHeader.DataDirectory[IDE].VirtualAddress)

extern BOOL DoesSectionExist(const char *sect);

extern void add_2_dll_list(char * pDLL);  // FIX20171017
extern void kill_dll_list();  // FIX20171017
extern void show_dll_list();  // FIX20171017

extern int IsAddressInRange(BYTE *bgn, int len);
extern int is_listed_machine_type(WORD wMachineType);

typedef enum omf_cmd {
	CMD_MIN_CMD = 0x6e,     /* minimum cmd enum                 */
	CMD_RHEADR = 0x6e,
	CMD_REGINT = 0x70,
	CMD_REDATA = 0x72,
	CMD_RIDATA = 0x74,
	CMD_OVLDEF = 0x76,
	CMD_ENDREC = 0x78,
	CMD_BLKDEF = 0x7a,     /* block definition record          */
	CMD_BLKDEF32 = 0x7b,     /* weird extension for QNX MAX assembler */
	CMD_BLKD32 = 0x7b,     /* weird extension for QNX MAX assembler */
	CMD_BLKEND = 0x7c,     /* block end record                 */
	CMD_BLKEND32 = 0x7d,     /* _might_ be used by QNX MAX assembler */
	CMD_BLKE32 = 0x7d,     /* _might_ be used by QNX MAX assembler */
	CMD_DEBSYM = 0x7e,
	CMD_THEADR = 0x80,     /* header record                    */
	CMD_LHEADR = 0x82,
	CMD_PEDATA = 0x84,
	CMD_PIDATA = 0x86,
	CMD_COMENT = 0x88,     /* comment record                   */
	CMD_MODEND = 0x8a,     /* end of module record             */
	CMD_MODEND32 = 0x8b,     /* 32-bit end of module record      */
	CMD_MODE32 = 0x8b,     /* 32-bit end of module record      */
	CMD_EXTDEF = 0x8c,     /* import names record              */
	CMD_TYPDEF = 0x8e,     /* type definition record           */
	CMD_PUBDEF = 0x90,     /* export names record              */
	CMD_PUBDEF32 = 0x91,     /* 32-bit export names record       */
	CMD_PUBD32 = 0x91,     /* 32-bit export names record       */
	CMD_LOCSYM = 0x92,
	CMD_LINNUM = 0x94,     /* line number record               */
	CMD_LINNUM32 = 0x95,     /* 32-bit line number record.       */
	CMD_LINN32 = 0x95,     /* 32-bit line number record.       */
	CMD_LNAMES = 0x96,     /* list of names record             */
	CMD_SEGDEF = 0x98,     /* segment definition record        */
	CMD_SEGDEF32 = 0x99,     /* 32-bit segment definition        */
	CMD_SEGD32 = 0x99,     /* 32-bit segment definition        */
	CMD_GRPDEF = 0x9a,     /* group definition record          */
	CMD_FIXUPP = 0x9c,     /* relocation record                */
	CMD_FIXUPP32 = 0x9d,     /* 32-bit relocation record         */
	CMD_FIXU32 = 0x9d,     /* 32-bit relocation record         */
	CMD_LEDATA = 0xa0,     /* object record                    */
	CMD_LEDATA32 = 0xa1,     /* 32-bit object record             */
	CMD_LEDA32 = 0xa1,     /* 32-bit object record             */
	CMD_LIDATA = 0xa2,     /* repeated data record             */
	CMD_LIDATA32 = 0xa3,     /* 32-bit repeated data record      */
	CMD_LIDA32 = 0xa3,     /* 32-bit repeated data record      */
	CMD_LIBHED = 0xa4,
	CMD_LIBNAM = 0xa6,
	CMD_LIBLOC = 0xa8,
	CMD_LIBDIC = 0xaa,
	CMD_COMDEF = 0xb0,     /* communal definition              */
	CMD_BAKPAT = 0xb2,     /* backpatch record (for Quick C) */
	CMD_BAKPAT32 = 0xb3,
	CMD_BAKP32 = 0xb3,
	CMD_LEXTDEF = 0xb4,     /*  local import names record */
	CMD_STATIC_EXTDEF = 0xb4,
	CMD_LEXTDEF32 = 0xb5,     /*  32-bit local import names record */
	CMD_STATIC_EXTD32 = 0xb5,
	CMD_LPUBDEF = 0xb6,     /* static export names record */
	CMD_STATIC_PUBDEF = 0xb6,
	CMD_LPUBDEF32 = 0xb7,     /* static export names record */
	CMD_STATIC_PUBD32 = 0xb7,
	CMD_LCOMDEF = 0xb8,     /* local comdev */
	CMD_STATIC_COMDEF = 0xb8,
	CMD_CEXTDEF = 0xbc,     /* external reference to a COMDAT */
	CMD_COMDAT = 0xc2,     /* initialized communal data record */
	CMD_COMDAT32 = 0xc3,     /* initialized 32-bit communal data record */
	CMD_COMD32 = 0xc3,     /* initialized 32-bit communal data record */
	CMD_LINSYM = 0xc4,     /* LINNUM for a COMDAT */
	CMD_LINSYM32 = 0xc5,     /* 32-bit LINNUM for a COMDAT */
	CMD_LINS32 = 0xc5,     /* 32-bit LINNUM for a COMDAT */
	CMD_ALIAS = 0xc6,     /* alias definition record          */
	CMD_NBKPAT = 0xc8,     /* named backpatch record (quick c?) */
	CMD_NBKPAT32 = 0xc9,     /* 32-bit named backpatch record */
	CMD_NBKP32 = 0xc9,     /* 32-bit named backpatch record */
	CMD_LLNAMES = 0xca,     /* a "local" lnames */
	CMD_VERNUM = 0xcc,     /* TIS version number record        */
	CMD_VENDEXT = 0xce,     /* TIS vendor extension record      */
	CMD_MAX_CMD = 0xce      /* maximum cmd enum                 */
} omf_cmd;

#endif // #ifndef _COMMON_H_
// eof
