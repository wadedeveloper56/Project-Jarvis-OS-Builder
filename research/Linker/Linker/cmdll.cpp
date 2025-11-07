#include "pch.h"
#include "walloca.h"
#include "linkstd.h"
#include "msg.h"
#include "alloc.h"
#include "command.h"
#include "wlnkmsg.h"
#include "strtab.h"
#include "dbgall.h"
#include "cmddos.h"
#include "cmdline.h"
#include "symtrace.h"
#include "objio.h"
#include "loadfile.h"
#include "carve.h"
#include "permdata.h"
#include "cmdall.h"
#include "library.h"

static void* LastFile;
static file_list** LastLibFile;

void ResetCmdAll(void)
{
    LastFile = NULL;
    LastLibFile = NULL;
    LibPath = NULL;
}
