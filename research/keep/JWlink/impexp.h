#pragma once

#define NOT_IMP_BY_ORDINAL 0xFFFFFFFF

typedef struct entry_export {
    struct entry_export* next;
    char* name;
    unsigned_32             ordinal;
    unsigned_16             iopl_words;
    unsigned_16             isresident : 1;
    unsigned_16             isexported : 1;
    unsigned_16             ismovable : 1;
    unsigned_16             isanonymous : 1;
    unsigned_16             isfree : 1;
    unsigned_16             isprivate : 1;
    symbol* sym;
    char* impname;
    targ_addr               addr;
} entry_export;

extern unsigned_16      FindEntryOrdinal(targ_addr, group_entry*);
extern void             FreeExportList(void);
extern void             AddToExportList(entry_export*);
extern void             MSExportKeyword(length_name*, length_name*,
    unsigned, unsigned);
extern void             MSImportKeyword(symbol*, length_name*,
    length_name*, unsigned long);
extern dll_sym_info* AllocDLLInfo(void);
extern void             FreeImport(dll_sym_info*);
extern entry_export* AllocExport(char*, unsigned);
extern void             AssignOrdinals(void);
extern char* ImpModuleName(dll_sym_info*);
extern bool             IsSymElfImported(symbol*);
extern bool             IsSymElfExported(symbol*);
extern bool             IsSymElfImpExp(symbol*);
extern void             KillDependantSyms(symbol*);
