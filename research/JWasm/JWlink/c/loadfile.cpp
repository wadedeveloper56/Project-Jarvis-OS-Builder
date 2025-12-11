#include "pch.h"
#include "globals.h"
#include "loadfile.h"
#include "ntio.h"
#include "mem.h"
#include "msg.h"
#include "wlmsgs.h"
#include "debug.h"

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

#define BUFF_BLOCK_SIZE (16*1024)

void InitBuffFile(outfilelist* outfile, char* filename, bool executable)
{
    outfile->fname = filename;
    outfile->handle = NIL_HANDLE;
    outfile->file_loc = 0;
    outfile->bufpos = 0;
    outfile->buffer = NULL;
    outfile->ovlfnoff = 0;
    outfile->is_exe = executable;
    outfile->origin = 0;
}

static void FlushBuffFile(outfilelist* outfile)
{
    unsigned    modpos;

    modpos = outfile->bufpos % BUFF_BLOCK_SIZE;
    if (modpos != 0) {
        QWrite(outfile->handle, outfile->buffer, modpos, outfile->fname);
    }
    _LnkFree(outfile->buffer);
    outfile->buffer = NULL;
}

void CloseBuffFile(outfilelist* outfile)
{
    if (outfile->buffer != NULL) {
        FlushBuffFile(outfile);
    }
    QClose(outfile->handle, outfile->fname);
    outfile->handle = NIL_HANDLE;
}

static void CloseOutFiles(void)
{
    outfilelist* fnode;

    for (fnode = OutFiles; fnode != NULL; fnode = fnode->next) {
        if (fnode->handle != NIL_HANDLE) {
            CloseBuffFile(fnode);
        }
    }
}

void FreeOutFiles(void)
{
    outfilelist* fnode;

    CloseOutFiles();
    for (fnode = OutFiles; fnode != NULL; fnode = OutFiles) {
        if (LinkState & LINK_ERROR) {
            QDelete(fnode->fname);
        }
        _LnkFree(fnode->fname);
        OutFiles = fnode->next;
        _LnkFree(fnode);
    }
}

void CleanLoadFile(void)
{
}

void InitLoadFile(void)
{
    DEBUG((DBG_OLD, "InitLoadFile()"));
    LnkMsg(INF + MSG_CREATE_EXE, "f");
}

