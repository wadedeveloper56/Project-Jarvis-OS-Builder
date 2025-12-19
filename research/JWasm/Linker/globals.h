#pragma once

#include "types.h"
#include "structures.h"

enum {
    MAX_REC = 1024,
    UNDEFINED = 0xffff,   /* undefined segment */
};

extern stateflag LinkState;        /* flags to indicate linker state */
extern int RecNum;                 /* record number of the obj file        */
extern tok Token;
extern mod_entry* CurrMod;         /* pointer to current mod_entry struct  */
extern cmdfilelist* CmdFile;
extern linkflag LinkFlags;         /* flags to indicate presence of parms  */
extern group_entry* Groups;        /* pointer to defined groups            */
extern group_entry* AbsGroups;     /* pointer to defined absolute groups   */
extern group_entry* OvlGroup;      /* pointer to group for overlay table   */
extern group_entry* DataGroup;     /* pointer to DGROUP */
extern group_entry* IDataGroup;    /* pointer to .idata */
extern FileHandle  MapFile;        /* handle to map file                   */
extern char* MapFName;             /* name of map file                     */
extern outfilelist* OutFiles;      // list of files which will be written to
extern file_list* ObjLibFiles;     /* list of library files (for searching)*/
extern mod_entry* LibModules;      /* library modules (for processing)     */
extern targ_addr CurrLoc;          /* current location pointer             */
extern list_of_names* OvlClasses;  /* list of classes to be overlayed       */
extern int OvlNum;                 /* current overlay number               */
extern vecnode* OvlVectors;        /* point to overlay vector notes         */
extern targ_addr OvltabAddr;       /* address of overlay tables */
extern unsigned int OvltabSize;    /* size of overlay tables */
extern int VecNum;                 /* number of vectors so far             */
extern char* OvlFName;             /* points to file name for overlays     */
extern offset StackSize;           /* size of stack                        */
extern symbol* HeadSym;            /* head of symbol table list */
extern section* Root;              /* pointer to root information          */
extern mapflag MapFlags;           /* flags dealing with the map file */
extern path_entry* LibPath;        /* path for library files               */
extern unsigned_32    NumImports;
extern unsigned_32    NumExports;
extern obj_format     ObjFormat;
extern seg_leader* CurrentSeg;     /* current segment being allocated       */
extern FileHandle TempFile;
extern path_entry* Path;           /* path for object files                */
