#include "pch.h"
#include "globals.h"
#include "procfile.h"
#include "loadpe.h"

void FreeLocalImports(void)
{
#ifdef _OS2
    FreePELocalImports();
#endif
}
