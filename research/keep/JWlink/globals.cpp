#include "pch.h"
#include "globals.h"
#include "File.h"
#include "link.h"
#include "ovlstruct.h"

int _argc;
char** _argv;
stateflag      LinkState;      /* flags to indicate linker state */
char* TokBuff;        // Multi-purpose large buffer
unsigned       TokSize;        // size of above buffer
FileHandle       TempFile;
group_entry* Groups;         /* pointer to defined groups            */
group_entry* AbsGroups;     /* pointer to defined absolute groups   */
group_entry* OvlGroup;       /* pointer to group for overlay table   */
group_entry* DataGroup;      /* pointer to DGROUP */
group_entry* IDataGroup;     /* pointer to .idata */
int            RecNum;         /* record number of the obj file        */
mod_entry* CurrMod;        /* pointer to current mod_entry struct  */
linkflag       LinkFlags;      /* flags to indicate presence of parms  */
FileHandle       MapFile;
char* MapFName;       /* name of map file                     */
mapflag        MapFlags;       /* flags dealing with the map file */
outfilelist* OutFiles;       // list of files which will be written to
path_entry* LibPath;        /* path for library files               */
path_entry* Path;           /* path for object files                */
section* Root;           /* pointer to root information          */
file_list* ObjLibFiles;   /* list of library files (for searching)*/
mod_entry* LibModules;    /* library modules (for processing)     */
section* CurrSect;       /* current section for file processing  */
list_of_names* OvlClasses;    /* list of classes to be overlayed       */
vecnode* OvlVectors;    /* point to overlay vector notes         */
seg_leader* OvlSeg;         /* pointer to seg_leader for overlaytab */
struct fmt_data FmtData;       /* format specific data */