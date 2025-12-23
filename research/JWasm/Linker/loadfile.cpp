#include "pch.h"
#include "globals.h"
#include "loadfile.h"
#include "debug.h"
#include "FileSubsystem.h"

seg_leader* StackSegPtr;
startinfo       StartInfo;

#define IMPLIB_BUFSIZE 4096

typedef struct {
    FileHandle    handle;
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

static void CloseOutFiles(void)
{
    outfilelist* fnode;

    for (fnode = OutFiles; fnode != NULL; fnode = fnode->next) {
        if (fnode->handle != NIL_HANDLE) {
            CloseFile(fnode->handle);
        }
    }
}

void FreeOutFiles(MemorySubsystem* memory)
{
    outfilelist* fnode;

    CloseOutFiles();
    for (fnode = OutFiles; fnode != NULL; fnode = OutFiles) {
        if (LinkState & LINK_ERROR) {
            FileSubsystem::Delete(fnode->fname);
        }
        memory->FreeMemory(fnode->fname);
        OutFiles = fnode->next;
        memory->FreeMemory(fnode);
    }
}
