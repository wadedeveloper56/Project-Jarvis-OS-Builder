#include "pch.h"
#include "cmdall.h"

static void* LastFile;
static file_list** LastLibFile;

void ResetCmdAll(void)
{
    LastFile = nullptr;
    LastLibFile = nullptr;
    LibPath = nullptr;
}