#pragma once

#include "MemoryMappedFile.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    WORD flag;
    const char* name;
} WORD_FLAG_DESCRIPTIONS;

typedef struct
{
    DWORD flag;
    const char* name;
} DWORD_FLAG_DESCRIPTIONS;

typedef struct _OBJFile
{
	IMAGE_FILE_HEADER header;
}OBJFile, *OBJFilePtr, **OBJFilePtrPtr;

#define MakePtr( cast, ptr, addValue ) (cast)( (BYTE *)(ptr) + (DWORD)(addValue))

typedef enum _FileType { UNKNOWN, EXE, DEBUG, OBJ, ANONYMOUS, LIB }FileType;
WORD getFileMagic(char* buffer);
FileType getFileType(char* buffer);
PSTR GetMachineTypeName(WORD wMachineType);
int islistedMachineType(WORD wMachineType);
OBJFilePtr loadObjFile(char* buffer, LONGLONG fileSize);
