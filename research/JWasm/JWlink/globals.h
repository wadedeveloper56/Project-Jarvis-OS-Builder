#pragma once

#include "types.h"
#include "structures.h"

extern int _argc;
extern char** _argv;
extern stateflag LinkState;        /* flags to indicate linker state */
extern int RecNum;                 /* record number of the obj file        */
extern tok Token;
extern linkflag LinkFlags;         /* flags to indicate presence of parms  */