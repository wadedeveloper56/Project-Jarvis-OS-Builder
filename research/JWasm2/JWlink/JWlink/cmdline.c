#include "pch.h"
#include "linkstd.h"
#include "exeos2.h"
#include "msg.h"
#include "alloc.h"
#include "command.h"
#include "wlnkmsg.h"
#include "cmdall.h"
#include "cmdos2.h"
#include "cmdqnx.h"
#include "cmd16m.h"
#include "cmdnov.h"
#include "cmdelf.h"
#include "cmdphar.h"
#include "cmddos.h"
#include "cmdline.h"
#include "overlays.h"
#include "fileio.h"
#include "symtrace.h"
#include "reloc.h"
// #include "strtab.h"
// #include "carve.h"
// #include "permdata.h"
#include "dbgall.h"
#include "loadfile.h"

static sysblock* PrevCommand;

//#define INIT_FILE_NAME  "wlink.lnk"
//#define INIT_FILE_ENV   "WLINK_LNK"
#define INIT_FILE_NAME  "jwlink.lnk"
#define INIT_FILE_ENV   "JWLINK_LNK"

void InitCmdFile(void)
{
    PrevCommand = NULL;
}
