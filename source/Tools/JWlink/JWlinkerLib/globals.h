#pragma once

#include "File.h"
#include "link.h"
#include "syms.h"
#include "ovlstruc.h"
#include "standard.h"
#include "objstruc.h"
#include "formats.h"

#define SECTOR_SIZE     512
#define MAX_HEADROOM    (4*1024)

extern outfilelist* OutFiles;
extern char* MapFName;
extern f_handle       MapFile;
extern targ_addr      StackAddr;
extern linkflag       LinkFlags;
extern stateflag      LinkState;
extern mapflag        MapFlags;
extern file_list* ObjLibFiles;
extern mod_entry* LibModules;
extern group_entry* Groups;
extern group_entry* AbsGroups;
extern group_entry* OvlGroup;
extern group_entry* DataGroup;
extern group_entry* IDataGroup;
extern seg_leader* OvlSeg;
extern mod_entry* CurrMod;
extern targ_addr      CurrLoc;
extern int            RecNum;
extern seg_leader* CurrentSeg;
extern section* Root;
extern section* CurrSect;
extern offset         StackSize;
extern list_of_names* OvlClasses;
extern int            OvlNum;
extern vecnode* OvlVectors;
extern targ_addr      OvltabAddr;
extern unsigned int   OvltabSize;
extern int            VecNum;
extern section* NonSect;
extern char* OvlFName;
extern path_entry* Path;
extern path_entry* LibPath;
extern char* TokBuff;
extern unsigned       TokSize;
extern offset         PackCodeLimit;
extern offset         PackDataLimit;
extern symbol* HeadSym;
extern byte           DBIFlag;
extern struct fmt_data FmtData;
extern obj_format     ObjFormat;
extern f_handle       TempFile;
extern mod_entry* FakeModule;
extern unsigned_32    NumImports;
extern unsigned_32    NumExports;
