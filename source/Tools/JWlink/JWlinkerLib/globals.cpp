#include "pch.h"
#include "globals.h"

#define SECTOR_SIZE     512
#define MAX_HEADROOM    (4*1024)

outfilelist* OutFiles;
char* MapFName;
f_handle       MapFile;
targ_addr      StackAddr;
linkflag       LinkFlags;
stateflag      LinkState;
mapflag        MapFlags;
file_list* ObjLibFiles;
mod_entry* LibModules;
group_entry* Groups;
group_entry* AbsGroups;
group_entry* OvlGroup;
group_entry* DataGroup;
group_entry* IDataGroup;
seg_leader* OvlSeg;
mod_entry* CurrMod;
targ_addr      CurrLoc;
int            RecNum;
seg_leader* CurrentSeg;
section* Root;
section* CurrSect;
offset         StackSize;
list_of_names* OvlClasses;
int            OvlNum;
vecnode* OvlVectors;
targ_addr      OvltabAddr;
unsigned int   OvltabSize;
int            VecNum;
section* NonSect;
char* OvlFName;
path_entry* Path;
path_entry* LibPath;
char* TokBuff;
unsigned       TokSize;
offset         PackCodeLimit;
offset         PackDataLimit;
symbol* HeadSym;
::byte           DBIFlag;
struct fmt_data FmtData;
obj_format     ObjFormat;
f_handle       TempFile;
mod_entry* FakeModule;
uint32_t    NumImports;
uint32_t    NumExports;

