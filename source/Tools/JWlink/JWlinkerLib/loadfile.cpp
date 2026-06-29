#include "pch.h"
#include "loadfile.h"
#include "globals.h"
#include "Structs.h"
#include "MemorySubsystem.h"
#include "FileSubsystem.h"
#include "ntio.h"

seg_leader* StackSegPtr;
startinfo       StartInfo;
implibinfo       ImpLib;

#define BUFF_BLOCK_SIZE (16*1024)

void FlushBuffFile(shared_ptr<MemorySubsystem> memorySubsystem,outfilelist* outfile)
{
    unsigned    modpos;

    modpos = outfile->bufpos % BUFF_BLOCK_SIZE;
    if (modpos != 0)
    {
        QWrite(outfile->handle, outfile->buffer, modpos, outfile->fname);
    }
    memorySubsystem->FreeMemory(outfile->buffer);
    outfile->buffer = NULL;
}

void CloseBuffFile(shared_ptr<MemorySubsystem> memorySubsystem, outfilelist* outfile)
{
    if (outfile->buffer != NULL)
    {
        FlushBuffFile(memorySubsystem, outfile);
    }
    QClose(outfile->handle, outfile->fname);
    outfile->handle = NIL_HANDLE;
}

void CloseOutFiles(shared_ptr<MemorySubsystem> memorySubsystem)
{
    outfilelist* fnode;

    for (fnode = OutFiles; fnode != NULL; fnode = fnode->next)
    {
        if (fnode->handle != NIL_HANDLE)
        {
            CloseBuffFile(memorySubsystem, fnode);
        }
    }
}

void FreeOutFiles(shared_ptr<FileSubsystem> fileSubsystem, shared_ptr<MemorySubsystem> memorySubsystem)
{
    outfilelist* fnode;

    CloseOutFiles(memorySubsystem);
    for (fnode = OutFiles; fnode != NULL; fnode = OutFiles)
    {
        if (LinkState & LINK_ERROR)
        {
            QDelete(fnode->fname);
        }
        memorySubsystem->FreeMemory(fnode->fname);
        OutFiles = fnode->next;
        memorySubsystem->FreeMemory(fnode);
    }
}

void ClearStartAddr()
{
    memset(&StartInfo, 0, sizeof(startinfo));
}

void ResetLoadFile()
{
    ClearStartAddr();
}

void CleanLoadFile()
{
}

void WriteBuffer(char* info, unsigned long len, outfilelist* outfile,  void* (*rtn)(void*, const void*, size_t))
{
    unsigned modpos;
    unsigned adjust;

    modpos = outfile->bufpos % BUFF_BLOCK_SIZE;
    outfile->bufpos += len;
    while (modpos + len >= BUFF_BLOCK_SIZE)
    {
        adjust = BUFF_BLOCK_SIZE - modpos;
        rtn(outfile->buffer + modpos, info, adjust);
        QWrite(outfile->handle, outfile->buffer, BUFF_BLOCK_SIZE,
            outfile->fname);
        info += adjust;
        len -= adjust;
        modpos = 0;
    }
    if (len > 0)
    {
        rtn(outfile->buffer + modpos, info, len);
    }
}

void WriteLoad(void* buff, unsigned long size)
{
    outfilelist* outfile;

    outfile = CurrSect->outfile;
    if (outfile->buffer != NULL)
    {
        WriteBuffer((char*)buff, size, outfile, memcpy);
    }
    else
    {
        QWrite(outfile->handle, buff, size, outfile->fname);
    }
}