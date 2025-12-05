#include "pch.h"
#include "globals.h"
#include "File.h"

int _argc;
char** _argv;
stateflag      LinkState;      /* flags to indicate linker state */
char* TokBuff;        // Multi-purpose large buffer
unsigned       TokSize;        // size of above buffer
FileHandle       TempFile;
struct fmt_data FmtData;
group_entry* Groups;         /* pointer to defined groups            */
group_entry* AbsGroups;     /* pointer to defined absolute groups   */
group_entry* OvlGroup;       /* pointer to group for overlay table   */
group_entry* DataGroup;      /* pointer to DGROUP */
group_entry* IDataGroup;     /* pointer to .idata */