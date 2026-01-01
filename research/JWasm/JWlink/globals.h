#pragma once

#include "types.h"
#include "structures.h"

#define SECTOR_SIZE     512
#define MAX_HEADROOM    (4*1024)

extern int             _argc;
extern char**          _argv;
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
