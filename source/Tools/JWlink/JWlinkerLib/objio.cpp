#include "pch.h"
#include "objio.h"
#include "Structs.h"
#include "globals.h"

infilelist* CachedLibFiles;
infilelist* CachedFiles;

void ResetObjIO()
{
    CachedFiles = NULL;
    CachedLibFiles = NULL;
}
