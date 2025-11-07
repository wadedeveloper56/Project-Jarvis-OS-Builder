#include "pch.h"
#include "walloca.h"
#include "linkstd.h"
#include "ring.h"
#include "pcobj.h"
#include "newmem.h"
#include "msg.h"
#include "alloc.h"
#include "specials.h"
#include "wlnkmsg.h"
#include "virtmem.h"
#include "fileio.h"
#include "mapio.h"
#include "spillio.h"
#include "omfreloc.h"
#include "objcalc.h"
#include "dbgall.h"
#include "loadpe.h"
#include "loados2.h"
#include "loaddos.h"
#include "pharlap.h"
#include "loadnov.h"
#include "load16m.h"
#include "loadqnx.h"
#include "loadelf.h"
#include "loadraw.h"
#include "loadfile.h"
#include "objstrip.h"
#include "impexp.h"
#include "objnode.h"
#include "strtab.h"
#include "permdata.h"
#include "dllentry.h"
#include "overlays.h"

seg_leader* StackSegPtr;
startinfo       StartInfo;

#define IMPLIB_BUFSIZE 4096

typedef struct {
    f_handle    handle;
    char* fname;
    char* buffer;
    unsigned    bufsize;
    char* dllname;
    size_t      dlllen;
    unsigned    didone : 1;
} implibinfo;

typedef struct {
    unsigned_32 grp_start;
    unsigned_32 seg_start;
    group_entry* lastgrp;  // used only for copy classes
    bool        repos;
} grpwriteinfo;

static implibinfo       ImpLib;

void ClearStartAddr(void)
{
    memset(&StartInfo, 0, sizeof(startinfo));
}

void ResetLoadFile(void)
{
    ClearStartAddr();
}
