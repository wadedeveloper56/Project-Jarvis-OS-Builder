#include "pch.h"
#include "globals.h"
#include "alloc.h"
#include "ntio.h"

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

static void WriteBuffer(char* info, unsigned long len, outfilelist* outfile, void* (*rtn)(void*, const void*, size_t))
{
    unsigned modpos;
    unsigned adjust;

    modpos = outfile->bufpos % BUFF_BLOCK_SIZE;
    outfile->bufpos += len;
    while (modpos + len >= BUFF_BLOCK_SIZE) {
        adjust = BUFF_BLOCK_SIZE - modpos;
        rtn(outfile->buffer + modpos, info, adjust);
        QWrite(outfile->handle, outfile->buffer, BUFF_BLOCK_SIZE,
            outfile->fname);
        info += adjust;
        len -= adjust;
        modpos = 0;
    }
    if (len > 0) {
        rtn(outfile->buffer + modpos, info, len);
    }
}

void WriteLoad(void* buff, unsigned long size)
{
    outfilelist* outfile;

    outfile = CurrSect->outfile;
    if (outfile->buffer != NULL) {
        WriteBuffer((char *)buff, size, outfile, memcpy);
    }
    else {
        QWrite(outfile->handle, buff, size, outfile->fname);
    }
}
