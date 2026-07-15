#include "pch.h"
#include "utils.h"
#include "FileSubsystem.h"

void WriteNulls(FileSubsystem *file, f_handle handle, uint32_t len, char* name)
{
    static unsigned NullArray[16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

    for (; len > sizeof(NullArray); len -= sizeof(NullArray))
    {
        file->WriteFile(handle, NullArray, sizeof(NullArray));
    }
    if (len > 0)
    {
        file->WriteFile(handle, NullArray, len);
    }
}