#include "pch.h"
#include "structures.h"
#include "globals.h"

#ifdef _INT_DEBUG
char* _edata;
char* _end;
#endif
int             _argc;
char**          _argv;
MessagingSubsystem* msg;
MemorySubsystem* memory;
FileSubsystem* files;

Token           token;
outfilelist*    OutFiles;       // list of files which will be written to
char*           MapFName;       /* name of map file                     */
f_handle        MapFile;        /* handle of map file                   */
targ_addr       StackAddr;      /* initial stack address                */
linkflag        LinkFlags;      /* flags to indicate presence of parms  */
stateflag       LinkState;      /* flags to indicate linker state */
mapflag         MapFlags;       /* flags dealing with the map file */
file_list*      ObjLibFiles;    /* list of library files (for searching)*/
mod_entry*      LibModules;     /* library modules (for processing)     */
group_entry*    Groups;         /* pointer to defined groups            */
group_entry*    AbsGroups;      /* pointer to defined absolute groups   */
group_entry*    OvlGroup;       /* pointer to group for overlay table   */
group_entry*    DataGroup;      /* pointer to DGROUP */
group_entry*    IDataGroup;     /* pointer to .idata */
seg_leader*     OvlSeg;         /* pointer to seg_leader for overlaytab */
// byte *         ObjBuff;      /* offset into object buffer            */
mod_entry*      CurrMod;        /* pointer to current mod_entry struct  */
// byte *         EOObjRec;     /* end of object buffer                 */
targ_addr       CurrLoc;        /* current location pointer             */
int             RecNum;         /* record number of the obj file        */
seg_leader*     CurrentSeg;     /* current segment being allocated       */
section*        Root;           /* pointer to root information          */
section*        CurrSect;       /* current section for file processing  */
offset          StackSize;      /* size of stack                        */
list_of_names*  OvlClasses;     /* list of classes to be overlayed       */
int             OvlNum;         /* current overlay number               */
vecnode*        OvlVectors;     /* point to overlay vector notes         */
targ_addr       OvltabAddr;     /* address of overlay tables */
unsigned int    OvltabSize;     /* size of overlay tables */
int             VecNum;         /* number of vectors so far             */
section*        NonSect;        /* non-overlay-class section            */
char*           OvlFName;       /* points to file name for overlays     */
path_entry*     Path;           /* path for object files                */
path_entry*     LibPath;        /* path for library files               */
char*           TokBuff;        // Multi-purpose large buffer
unsigned        TokSize;        // size of above buffer
offset          PackCodeLimit;  // Maximum size of a packed code seg
offset          PackDataLimit;  // Maximum size of a packed data seg
symbol*         HeadSym;        /* head of symbol table list */
byte            DBIFlag;
struct fmt_data FmtData;        /* format specific data */
obj_format      ObjFormat;
f_handle        TempFile;
mod_entry*      FakeModule;     // Module containing all the extra sections
unsigned_32     NumImports;
unsigned_32     NumExports;


//*****************************************

#ifdef _INT_DEBUG
int           Chunks;
#endif
int           OpenFiles;      // the number of open files
unsigned      LastResult;
bool          CaughtBreak;    // set to TRUE if break hit.
char* TFileName;
unsigned long TmpFSize;
bool          BannerPrinted;
nodearray* ExtNodes;           // ptr to obj file import list
nodearray* SegNodes;           // ptr to obj file segment list
nodearray* GrpNodes;           // ptr to obj file group list
nodearray* NameNodes;          // ptr to obj file lname list
symbol** GlobalSymPtrs;
symbol** StaticSymPtrs;
orl_handle    ORLHandle;
long          ORLFilePos;
orl_funcs     ORLFuncs;
readcache* ReadCacheList;
sysblock* PrevCommand;
stringtable   PermStrings;
stringtable   PrefixStrings;  /* these are NetWare prefix strings of which there could possibly be several */
stringtable   StoredRelocs;
carve_t       CarveLeader;
carve_t       CarveModEntry;
carve_t       CarveSymbol;
carve_t       CarveSegData;
carve_t       CarveClass;
carve_t       CarveGroup;
carve_t       CarveDLLInfo;
carve_t       CarveExportInfo;
char* IncFileName;
incgroupdef* IncGroupDefs;
group_entry** IncGroups;
libnamelist* SavedUserLibs;
libnamelist* SavedDefLibs;
char* ReadRelocs;
unsigned      SizeRelocs;
char* OldExe;
char* OldSymFile;
void* AltDefData;
char* IncStrTab;
unsigned        NameLen;
symbol* LastSym;
symbol* SymList = NULL;
block_data Pass1Blocks;
block_data PermBlocks;
char* SymFileName;
group_entry* DBIGroups;
symrecinfo* UndefList;
symrecinfo* SymTraceList;
int             MapCol;
time_t          StartT;
clock_t         ClockTicks;
bool            Absolute_Seg;
bool             Buffering;  // buffering on/off.
int              BufferSize;          // # of chars in buffer.
void* LastFile;
file_list** LastLibFile;
unsigned_16         AreaSize;
comdat_info* CDatList;
comdat_info* FreedInfos;
comdat_piece* FreedPieces;
unsigned_16  CurrModThere;
arcdata* ArcBuffer;
unsigned_32  ArcBufLen;
mod_entry** ModTable;
unsigned_16  CurrModHandle;
section** SectOvlTab;
sysblock* SysBlocks;
sysblock* LinkCommands;
unsigned_32  DbgInfoCount;
unsigned_32  DbgInfoLen;
virt_mem     NovDbgInfo;
virt_mem     CurrDbgLoc;
module_import* PEImpList;  /* list of imported modules */
unsigned         NumMods;
segdata* XFerSegData; /* linker-generated thunk data */
local_import* PELocalImpList;
unsigned         NumLocalImports;
struct _IData  IData;
offset           LastOptimized;  // offset last optimized.
fix_type         LastOptType;
segdata* LastSegData;
offset           FixupOverflow;
struct _EData EData;
infilelist* CachedLibFiles;
infilelist* CachedFiles;
edgelist* FreedEdges;
bakpat_list* BakPats;
unsigned        FmtRelocSize;
reloc_info* FloatFixups;
trace_info* CurrTrace;
trace_info* TraceList;
startinfo       StartInfo;
pHTable  Toc;
char* TocName;
symbol* TocSym;
offset TocSize;
offset TocShift;
char* Name;
vmemblock* VMemBlocks;
