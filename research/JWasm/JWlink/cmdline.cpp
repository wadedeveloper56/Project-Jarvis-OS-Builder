#include "pch.h"
#include "globals.h"
#include "cmdline.h"

tok             Token;
static sysblock* PrevCommand;

//#define INIT_FILE_NAME  "wlink.lnk"
//#define INIT_FILE_ENV   "WLINK_LNK"
#define INIT_FILE_NAME  "jwlink.lnk"
#define INIT_FILE_ENV   "JWLINK_LNK"

void InitCmdFile(void)
{
    PrevCommand = NULL;
}