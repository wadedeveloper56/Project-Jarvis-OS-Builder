#include "pch.h"
#include "cmdall.h"
#include "globals.h"

void* LastFile;
file_list** LastLibFile;

void ResetCmdAll()
{
    LastFile = NULL;
    LastLibFile = NULL;
    LibPath = NULL;
}