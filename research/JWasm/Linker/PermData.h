#pragma once

#include "globals.h"
#include "MemorySubsystem.h"
#include "Ring.h"
#include "Carve.h"
#include "StringTable.h"

#define INC_FILE_SIG_SIZE        36
#define SEG_CARVE_SIZE          (2*1024)
#define MOD_CARVE_SIZE          (5*1024)
#define SDATA_CARVE_SIZE        (16*1024)
#define SYM_CARVE_SIZE          (32*1024)

typedef struct {
    unsigned_32 num;
    //    unsigned_32       fileoff;         not currently used
} carve_info;

typedef struct {
    char               signature[INC_FILE_SIG_SIZE];
    unsigned_32        hdrsize;        // size of hdr + small structs
    unsigned_32        strtabsize;     // size of string table
    unsigned_32        relocsize;      // size of all relocs
    unsigned_32        numgroups;      // number of group_entry structures
    carve_info         mods;           // mod_entry info
    carve_info         segdatas;       // segdata info
    carve_info         symbols;        // symbol info
    unsigned_32        altdefsize;     // size of altdef data
    unsigned_32        rootmodidx;     // Root->mods swizzled pointer
    unsigned_32        headsymidx;     // HeadSym swizzled pointer
    unsigned_32        libmodidx;      // LibModules swizzled pointer
    unsigned_32        linkstate;      // value of LinkState
    unsigned_32        exename;        // name of the .exe
    unsigned_32        symname;        // name of the sym file
    unsigned_32        numdllsyms;     // OS/2&PE only: number of dll symbols
    unsigned_32        numexports;     // OS/2&PE only: number of exports
    unsigned_32        startmodidx;    // start module swizzled pointer
    unsigned_32        startidx;       // swizzled pointer to start object
    unsigned_32        startoff;       // delta from object of start addr.
    unsigned_32        flags;          // miscellaneous flags
    unsigned_32        numuserlibs;    // number of user specified libs
    unsigned_32        numdeflibs;     // number of default libs
    time_t             exemodtime;     // time exe was written.
    time_t             symmodtime;     // sym file time
} inc_file_header;

#define INC_FLAG_START_SEG      0x0001  // startidx is a segname

typedef struct groupdef {
    struct groupdef* next;
    unsigned            numsegs;
    char* grpname;
    char* names[1];
} incgroupdef;

typedef struct liblist {
    struct liblist* next;
    unsigned            namelen;
    char                name[1];
} libnamelist;

struct perm_read_info_struct {
    FileHandle    incfhdl;
    unsigned    currpos;
    char* buffer;
    unsigned    num;
    void        (*cbfn)(void*, struct perm_read_info_struct*);
    carve_t     cv;
};

typedef struct perm_read_info_struct perm_read_info;

typedef struct {
    stringtable strtab;
    unsigned    currpos;
    FileHandle    incfhdl;
    void        (*prepfn)(void*, void*);
} perm_write_info;

class PermData
{
    MemorySubsystem* memory;
    Ring* ring;
	Carve* carve;
	StringTable* strtab;
	stringtable             PermStrings;
	stringtable             PrefixStrings;  /* these are NetWare prefix strings of which there could possibly be several */
	carve_t                 CarveLeader;
	carve_t                 CarveModEntry;
	carve_t                 CarveSymbol;
	carve_t                 CarveSegData;
	carve_t                 CarveClass;
    carve_t                 CarveGroup;
	carve_t                 CarveDLLInfo;
	carve_t                 CarveExportInfo;
	char* IncFileName;
	incgroupdef* IncGroupDefs;
	group_entry** IncGroups;
	libnamelist* SavedUserLibs;
	libnamelist* SavedDefLibs;
	stringtable      StoredRelocs;
	char* ReadRelocs;
	unsigned         SizeRelocs;
	char* OldExe;
	char* OldSymFile;
	void* AltDefData;
	char* IncStrTab;
public:
	PermData(MemorySubsystem* memory, Ring* ring, Carve* carve, StringTable* strtab);
	~PermData();
	void Reset(void);
    void CleanPermData(void);
    void FreeAGroup(group_entry* group);
    entry_export* FreeAnExport(entry_export* exp);
    void FreeSymbol(symbol* sym);
    void FreeImport(dll_sym_info* dll);
    void FreeClasses(class_entry* list);
    void FreeModEntry(mod_entry* mod);
    void FreeLeader(void* seg);
};
