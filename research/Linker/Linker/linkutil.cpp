#include "pch.h"
#include "linkstd.h"
#include "pcobj.h"
#include "newmem.h"
#include "alloc.h"
#include "msg.h"
#include "wlnkmsg.h"
#include "linkutil.h"
#include "fileio.h"
#include "ring.h"
#include "overlays.h"
#include "strtab.h"
#include "loadfile.h"
#include "permdata.h"
#include "mapio.h"
#include "wressetr.h"

static void* SpawnStack;

int Spawn(void (*fn)(void))
{
    jmp_buf env;

    void *save_env = SpawnStack;
    SpawnStack = env;
    int status = setjmp(env);
    if (status == 0) {
        (*fn)();
    }
    SpawnStack = save_env;  /* unwind */
    return(status);
}

char* GetEnvString(char* envname)
{
    return(getenv(envname));
}

