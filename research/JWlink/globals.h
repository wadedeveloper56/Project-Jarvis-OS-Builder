#pragma once

#include "watcom.h"
#include "types.h"
#include "structures.h"
#include "orl.h"
#include "debug.h"
#include "carve.h"
#include "stringtable.h"
#include "ring.h"
#include "hash.h"
#include "CmdLine.h"

#define SECTOR_SIZE     512
#define MAX_HEADROOM    (4*1024)

class MessagingSubsystem;
class MemorySubSystem;
class FileSubsystem;

#ifdef _INT_DEBUG
extern char* _edata;
extern char* _end;
#endif
extern int             _argc;
extern char**          _argv;
extern MessagingSubsystem* msg;
extern MemorySubsystem* memory;
extern FileSubsystem* files;
extern Token           token;
extern linkflag        LinkFlags;      /* flags to indicate presence of parms  */
extern outfilelist*    OutFiles;       // list of files which will be written to
extern char*           MapFName;       /* name of map file                     */
extern f_handle        MapFile;        /* handle of map file                   */
extern targ_addr       StackAddr;      /* initial stack address                */
extern linkflag        LinkFlags;      /* flags to indicate presence of parms  */
extern stateflag       LinkState;      /* flags to indicate linker state */
extern mapflag         MapFlags;       /* flags dealing with the map file */
extern file_list*      ObjLibFiles;    /* list of library files (for searching)*/
extern mod_entry*      LibModules;     /* library modules (for processing)     */
extern group_entry*    Groups;         /* pointer to defined groups            */
extern group_entry*    AbsGroups;      /* pointer to defined absolute groups   */
extern group_entry*    OvlGroup;       /* pointer to group for overlay table   */
extern group_entry*    DataGroup;      /* pointer to DGROUP */
extern group_entry*    IDataGroup;     /* pointer to .idata */
extern seg_leader*     OvlSeg;         /* pointer to seg_leader for overlaytab */
// byte *         ObjBuff;             /* offset into object buffer            */
extern mod_entry*      CurrMod;        /* pointer to current mod_entry struct  */
// byte *         EOObjRec;            /* end of object buffer                 */
extern targ_addr       CurrLoc;        /* current location pointer             */
extern int             RecNum;         /* record number of the obj file        */
extern seg_leader*     CurrentSeg;     /* current segment being allocated       */
extern section*        Root;           /* pointer to root information          */
extern section*        CurrSect;       /* current section for file processing  */
extern offset          StackSize;      /* size of stack                        */
extern list_of_names*  OvlClasses;     /* list of classes to be overlayed       */
extern int             OvlNum;         /* current overlay number               */
extern vecnode*        OvlVectors;     /* point to overlay vector notes         */
extern targ_addr       OvltabAddr;     /* address of overlay tables */
extern unsigned int    OvltabSize;     /* size of overlay tables */
extern int             VecNum;         /* number of vectors so far             */
extern section*        NonSect;        /* non-overlay-class section            */
extern char*           OvlFName;       /* points to file name for overlays     */
extern path_entry*     Path;           /* path for object files                */
extern path_entry*     LibPath;        /* path for library files               */
extern char*           TokBuff;        // Multi-purpose large buffer
extern unsigned        TokSize;        // size of above buffer
extern offset          PackCodeLimit;  // Maximum size of a packed code seg
extern offset          PackDataLimit;  // Maximum size of a packed data seg
extern symbol*         HeadSym;        /* head of symbol table list */
extern byte            DBIFlag;
extern struct fmt_data FmtData;        /* format specific data */
extern obj_format      ObjFormat;
extern f_handle        TempFile;
extern mod_entry*      FakeModule;     // Module containing all the extra sections
extern unsigned_32     NumImports;
extern unsigned_32     NumExports;


//*****************************************

#ifdef _INT_DEBUG
extern int           Chunks;
#endif
extern int           OpenFiles;      // the number of open files
extern unsigned      LastResult;
extern bool          CaughtBreak;    // set to TRUE if break hit.
extern char* TFileName;
extern unsigned long TmpFSize;
extern bool          BannerPrinted;
extern nodearray* ExtNodes;           // ptr to obj file import list
extern nodearray* SegNodes;           // ptr to obj file segment list
extern nodearray* GrpNodes;           // ptr to obj file group list
extern nodearray* NameNodes;          // ptr to obj file lname list
extern symbol** GlobalSymPtrs;
extern symbol** StaticSymPtrs;
extern orl_handle    ORLHandle;
extern long          ORLFilePos;
extern orl_funcs     ORLFuncs;
extern readcache* ReadCacheList;
extern sysblock* PrevCommand;
extern stringtable   PermStrings;
extern stringtable   PrefixStrings;  /* these are NetWare prefix strings of which there could possibly be several */
extern stringtable   StoredRelocs;
extern carve_t       CarveLeader;
extern carve_t       CarveModEntry;
extern carve_t       CarveSymbol;
extern carve_t       CarveSegData;
extern carve_t       CarveClass;
extern carve_t       CarveGroup;
extern carve_t       CarveDLLInfo;
extern carve_t       CarveExportInfo;
extern char* IncFileName;
extern incgroupdef* IncGroupDefs;
extern group_entry** IncGroups;
extern libnamelist* SavedUserLibs;
extern libnamelist* SavedDefLibs;
extern char* ReadRelocs;
extern unsigned      SizeRelocs;
extern char* OldExe;
extern char* OldSymFile;
extern void* AltDefData;
extern char* IncStrTab;
extern unsigned        NameLen;
extern symbol* LastSym;
extern symbol* SymList = NULL;
extern block_data Pass1Blocks;
extern block_data PermBlocks;
extern char* SymFileName;
extern group_entry* DBIGroups;
extern symrecinfo* UndefList;
extern symrecinfo* SymTraceList;
extern int             MapCol;
extern time_t          StartT;
extern clock_t         ClockTicks;
extern bool            Absolute_Seg;
extern bool             Buffering;  // buffering on/off.
extern int              BufferSize;          // # of chars in buffer.
extern void* LastFile;
extern file_list** LastLibFile;
extern unsigned_16         AreaSize;
extern comdat_info* CDatList;
extern comdat_info* FreedInfos;
extern comdat_piece* FreedPieces;
extern unsigned_16  CurrModThere;
extern arcdata* ArcBuffer;
extern unsigned_32  ArcBufLen;
extern mod_entry** ModTable;
extern unsigned_16  CurrModHandle;
extern section** SectOvlTab;
extern sysblock* SysBlocks;
extern sysblock* LinkCommands;
extern unsigned_32  DbgInfoCount;
extern unsigned_32  DbgInfoLen;
extern virt_mem     NovDbgInfo;
extern virt_mem     CurrDbgLoc;
extern module_import* PEImpList;  /* list of imported modules */
extern unsigned         NumMods;
extern segdata* XFerSegData; /* linker-generated thunk data */
extern local_import* PELocalImpList;
extern unsigned         NumLocalImports;
extern struct _IData  IData;
extern offset           LastOptimized;  // offset last optimized.
extern fix_type         LastOptType;
extern segdata* LastSegData;
extern offset           FixupOverflow;
extern struct _EData EData;
extern infilelist* CachedLibFiles;
extern infilelist* CachedFiles;
extern edgelist* FreedEdges;
extern bakpat_list* BakPats;
extern unsigned        FmtRelocSize;
extern reloc_info* FloatFixups;
extern trace_info* CurrTrace;
extern trace_info* TraceList;
extern startinfo       StartInfo;
extern pHTable  Toc;
extern char* TocName;
extern symbol* TocSym;
extern offset TocSize;
extern offset TocShift;
extern char* Name;
extern vmemblock* VMemBlocks;
