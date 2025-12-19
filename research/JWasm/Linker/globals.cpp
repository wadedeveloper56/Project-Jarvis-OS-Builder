#include "pch.h"
#include "globals.h"

stateflag LinkState;        /* flags to indicate linker state */
int RecNum;                 /* record number of the obj file        */
tok Token;
mod_entry* CurrMod;         /* pointer to current mod_entry struct  */
cmdfilelist* CmdFile;
linkflag LinkFlags;         /* flags to indicate presence of parms  */
group_entry* Groups;        /* pointer to defined groups            */
group_entry* AbsGroups;     /* pointer to defined absolute groups   */
group_entry* OvlGroup;      /* pointer to group for overlay table   */
group_entry* DataGroup;     /* pointer to DGROUP */
group_entry* IDataGroup;    /* pointer to .idata */
FileHandle  MapFile;        /* handle to map file                   */
char* MapFName;             /* name of map file                     */
outfilelist* OutFiles;      // list of files which will be written to
file_list* ObjLibFiles;     /* list of library files (for searching)*/
mod_entry* LibModules;      /* library modules (for processing)     */
targ_addr CurrLoc;          /* current location pointer             */
list_of_names* OvlClasses;  /* list of classes to be overlayed       */
int OvlNum;                 /* current overlay number               */
vecnode* OvlVectors;        /* point to overlay vector notes         */
targ_addr OvltabAddr;       /* address of overlay tables */
unsigned int OvltabSize;    /* size of overlay tables */
int VecNum;                 /* number of vectors so far             */
char* OvlFName;             /* points to file name for overlays     */
offset StackSize;           /* size of stack                        */
symbol* HeadSym;            /* head of symbol table list */
section* Root;              /* pointer to root information          */
mapflag MapFlags;           /* flags dealing with the map file */
path_entry* LibPath;        /* path for library files               */
unsigned_32 NumImports;
unsigned_32 NumExports;
obj_format ObjFormat;
seg_leader* CurrentSeg;     /* current segment being allocated       */
FileHandle TempFile;
path_entry* Path;           /* path for object files                */
struct fmt_data FmtData;    /* format specific data */
