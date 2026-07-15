#pragma once

#include "MemorySubsystem.h"
#include "Structs.h"
#include "Carve.h"
#include "StringTable.h"

#define INC_FILE_SIG_SIZE        36
#ifdef __QNX__
#define INC_FILE_SIG  "WLINK Incremental Link File V1.03\n\x0c\x04"
#else
#define INC_FILE_SIG  "WLINK Incremental Link File V1.03\r\n\x1a"
#endif

typedef struct {
    uint32_t num;
} carve_info;

typedef struct {
     char               signature[INC_FILE_SIG_SIZE];
     uint32_t        hdrsize;              
     uint32_t        strtabsize;         
     uint32_t        relocsize;          
     uint32_t        numgroups;          
     carve_info         mods;             
     carve_info         segdatas;         
     carve_info         symbols;          
     uint32_t        altdefsize;         
     union {
         uint32_t    rootmodidx;        
         void          *pv_rootmodidx;
     };
     union {
         uint32_t    headsymidx;        
         void          *pv_headsymidx;
     };
     union {
         uint32_t    libmodidx;         
         void          *pv_libmodidx;
     };
     uint32_t        linkstate;         
     union {
         uint32_t    exename;            
         void          *pv_exename;
     };
     union {
         uint32_t    symname;             
         void          *pv_symname;
     };
     uint32_t        numdllsyms;           
     uint32_t        numexports;          
     union {
         uint32_t    startmodidx;        
         void          *pv_startmodidx;
     };
     union {
         uint32_t    startidx;            
         void          *pv_startidx;
     };
     uint32_t        startoff;             
     uint32_t        flags;            
     uint32_t        numuserlibs;         
     uint32_t        numdeflibs;         
     time_t             exemodtime;         
     time_t             symmodtime;        
} inc_file_header;

#define INC_FLAG_START_SEG      0x0001      

struct perm_read_info_struct {
    f_handle    incfhdl;
    unsigned    currpos;
    char        *buffer;
    unsigned    num;
    void        (*cbfn)(void *, struct perm_read_info_struct *);
    carve_t     cv;
};

typedef struct perm_read_info_struct perm_read_info;

typedef struct {
    stringtable strtab;
    unsigned    currpos;
    f_handle    incfhdl;
    void        (*prepfn)( void *, void * );
} perm_write_info;

extern Carve*          CarveLeader;
extern Carve*          CarveModEntry;
extern Carve*          CarveDLLInfo;
extern Carve*          CarveExportInfo;
extern Carve*          CarveSymbol;
extern Carve*          CarveSegData;
extern Carve*          CarveClass;
extern Carve*          CarveGroup;
extern char             *IncFileName;
extern incgroupdef      *IncGroupDefs;
extern group_entry      **IncGroups;
extern libnamelist      *SavedUserLibs;
extern libnamelist      *SavedDefLibs;

void     ResetPermData( MemorySubsystem* memorySubsystem );
