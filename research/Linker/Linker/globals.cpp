#include "pch.h"
#include "linkstd.h"
#include "msg.h"
#include "alloc.h"
#include "wlnkmsg.h"
#include "command.h"
#include "fileio.h"
#include "objpass2.h"
#include "cmdline.h"
#include "loadfile.h"
#include "objfree.h"
#include "mapio.h"
#include "objcalc.h"
#include "procfile.h"
#include "spillio.h"
#include "virtmem.h"
#include "loados2.h"
#include "loadpe.h"
#include "loadqnx.h"
#include "loadnov.h"
#include "loadelf.h"
#include "symtrace.h"
#include "objnode.h"
#include "objio.h"
#include "distrib.h"
#include "objorl.h"
#include "strtab.h"
#include "carve.h"
#include "permdata.h"
#include "toc.h"
#include "dbgall.h"
#include "objpass1.h"
#include "obj2supp.h"
#include "cmdall.h"
#include "reloc.h"
#include "salloc.h"
#include "objstrip.h"
#include "symtab.h"
#include "omfreloc.h"
#include "overlays.h"
#include "wcomdef.h"
#include "objomf.h"
#include "wlink.h"
#include "library.h"
#include "globals.h"
#include "watcom.h"

stateflag LinkState;      /* flags to indicate linker state */
linkflag LinkFlags;    /* flags to indicate presence of parms  */
group_entry* Groups;         /* pointer to defined groups            */
group_entry* AbsGroups;      /* pointer to defined absolute groups   */
group_entry* OvlGroup;       /* pointer to group for overlay table   */
group_entry* DataGroup;      /* pointer to DGROUP */
group_entry* IDataGroup;     /* pointer to .idata */
char* MapFName;              /* name of map file                     */
f_handle       MapFile;      /* handle of map file                   */
outfilelist* OutFiles;       // list of files which will be written to
file_list* ObjLibFiles;      /* list of library files (for searching)*/
mod_entry* LibModules;       /* library modules (for processing)     */
targ_addr      CurrLoc;      /* current location pointer             */
list_of_names* OvlClasses;    /* list of classes to be overlayed       */
int            OvlNum;         /* current overlay number               */
vecnode* OvlVectors;    /* point to overlay vector notes         */
targ_addr      OvltabAddr;     /* address of overlay tables */
int            VecNum;         /* number of vectors so far             */
char* OvlFName;       /* points to file name for overlays     */
mod_entry* CurrMod;        /* pointer to current mod_entry struct  */
offset         StackSize;      /* size of stack                        */
symbol* HeadSym;        /* head of symbol table list */
section* Root;           /* pointer to root information          */
mapflag        MapFlags;       /* flags dealing with the map file */
path_entry* LibPath;        /* path for library files               */
unsigned_32    NumImports;
unsigned_32    NumExports;
char* TokBuff;        // Multi-purpose large buffer
unsigned       TokSize;        // size of above buffer
obj_format     ObjFormat;
int            RecNum;         /* record number of the obj file        */
seg_leader* CurrentSeg;    /* current segment being allocated       */
