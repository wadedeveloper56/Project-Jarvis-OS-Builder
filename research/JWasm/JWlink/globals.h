#pragma once

#include "link.h"
#include "File.h"
#include "formats.h"

#define SECTOR_SIZE     512
#define MAX_HEADROOM    (4*1024)

extern int _argc;
extern char** _argv;
extern stateflag      LinkState;      /* flags to indicate linker state */
extern char* TokBuff;        // Multi-purpose large buffer
extern unsigned       TokSize;        // size of above buffer
extern FileHandle       TempFile;
extern struct fmt_data FmtData;
extern group_entry* Groups;         /* pointer to defined groups            */
extern group_entry* AbsGroups;     /* pointer to defined absolute groups   */
extern group_entry* OvlGroup;       /* pointer to group for overlay table   */
extern group_entry* DataGroup;      /* pointer to DGROUP */
extern group_entry* IDataGroup;     /* pointer to .idata */
extern int            RecNum;         /* record number of the obj file        */
extern mod_entry* CurrMod;
extern linkflag       LinkFlags;
extern FileHandle       MapFile;        /* handle of map file                   */
extern char* MapFName;       /* name of map file                     */
extern mapflag        MapFlags;       /* flags dealing with the map file */
extern outfilelist* OutFiles;       // list of files which will be written to
extern path_entry* LibPath;        /* path for library files               */
