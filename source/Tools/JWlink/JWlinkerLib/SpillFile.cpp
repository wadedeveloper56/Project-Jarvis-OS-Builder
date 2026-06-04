#include "pch.h"
#include "SpillFile.h"


SpillFile::SpillFile() : TempFile(NIL_HANDLE), TFileName(nullptr), TmpFSize(0)
{
}

SpillFile::~SpillFile()
{
}
