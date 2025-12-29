#include "pch.h"
#include "comdef.h"

static comdat_info* CDatList;
static comdat_info* FreedInfos;
static comdat_piece* FreedPieces;

void ResetComdef(void)
{
    CDatList = nullptr;
    FreedInfos = nullptr;
    FreedPieces = nullptr;
}
