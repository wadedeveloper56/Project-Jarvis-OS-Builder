#include "pch.h"
#include "globals.h"

int _argc;
char** _argv;
stateflag LinkState;        /* flags to indicate linker state */
int RecNum;                 /* record number of the obj file        */
tok Token;
linkflag LinkFlags;         /* flags to indicate presence of parms  */
