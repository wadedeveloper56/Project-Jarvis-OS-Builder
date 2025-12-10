#include "pch.h"
#include "globals.h"

/* linker global variables */
 outfilelist* OutFiles;       // list of files which will be written to
 char* MapFName;       /* name of map file                     */
 FileHandle       MapFile;        /* handle of map file                   */
 targ_addr      StackAddr;      /* initial stack address                */
 linkflag       LinkFlags;      /* flags to indicate presence of parms  */
 stateflag      LinkState;      /* flags to indicate linker state */
 mapflag        MapFlags;       /* flags dealing with the map file */
 file_list* ObjLibFiles;   /* list of library files (for searching)*/
 mod_entry* LibModules;    /* library modules (for processing)     */
 group_entry* Groups;         /* pointer to defined groups            */
 group_entry* AbsGroups;     /* pointer to defined absolute groups   */
 group_entry* OvlGroup;       /* pointer to group for overlay table   */
 group_entry* DataGroup;      /* pointer to DGROUP */
 group_entry* IDataGroup;     /* pointer to .idata */
 seg_leader* OvlSeg;         /* pointer to seg_leader for overlaytab */
// byte *         ObjBuff;        /* offset into object buffer            */
 mod_entry* CurrMod;        /* pointer to current mod_entry struct  */
// byte *         EOObjRec;       /* end of object buffer                 */
 targ_addr      CurrLoc;        /* current location pointer             */
 int            RecNum;         /* record number of the obj file        */
 seg_leader* CurrentSeg;    /* current segment being allocated       */
 section* Root;           /* pointer to root information          */
 section* CurrSect;       /* current section for file processing  */
 offset         StackSize;      /* size of stack                        */
 list_of_names* OvlClasses;    /* list of classes to be overlayed       */
 int            OvlNum;         /* current overlay number               */
 vecnode* OvlVectors;    /* point to overlay vector notes         */
 targ_addr      OvltabAddr;     /* address of overlay tables */
 unsigned int   OvltabSize;     /* size of overlay tables */
 int            VecNum;         /* number of vectors so far             */
 section* NonSect;        /* non-overlay-class section            */
 char* OvlFName;       /* points to file name for overlays     */
 path_entry* Path;           /* path for object files                */
 path_entry* LibPath;        /* path for library files               */
 char* TokBuff;        // Multi-purpose large buffer
 unsigned       TokSize;        // size of above buffer
 offset         PackCodeLimit;  // Maximum size of a packed code seg
 offset         PackDataLimit;  // Maximum size of a packed data seg
 symbol* HeadSym;        /* head of symbol table list */
 byte           DBIFlag;
 struct fmt_data FmtData;       /* format specific data */
 obj_format     ObjFormat;
 FileHandle       TempFile;
 mod_entry* FakeModule;     // Module containing all the extra sections
 unsigned_32    NumImports;
 unsigned_32    NumExports;
