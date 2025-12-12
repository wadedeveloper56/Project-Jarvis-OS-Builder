#include "pch.h"
#include "globals.h"
#include "wcomdef.h"
#include "objpass1.h"

static comdat_info* CDatList;
static comdat_info* FreedInfos;
static comdat_piece* FreedPieces;

void ResetComdef(void)
{
#if 0
    memcpy(CDatSegName, CDAT_SEG_NAME, CDAT_SEG_NAME_LEN);
    CDatSegments[0] = nullptr;
    CDatSegments[1] = nullptr;
    CDatSegments[2] = nullptr;
    CDatSegments[3] = nullptr;
    CDatSegNum = 0;
#endif
    CDatList = nullptr;
    FreedInfos = nullptr;
    FreedPieces = nullptr;
}
