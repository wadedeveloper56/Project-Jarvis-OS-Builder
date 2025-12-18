#include "pch.h"
#include "globals.h"
#include "objio.h"

typedef struct {
    void* buffer;
    unsigned long       pos;
    infilelist* currfile;
} bufferedfile;

infilelist* CachedLibFiles;
infilelist* CachedFiles;

void ResetObjIO(void)
{
    CachedFiles = nullptr;
    CachedLibFiles = nullptr;
}

