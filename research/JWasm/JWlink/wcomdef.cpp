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
    CDatSegments[0] = NULL;
    CDatSegments[1] = NULL;
    CDatSegments[2] = NULL;
    CDatSegments[3] = NULL;
    CDatSegNum = 0;
#endif
    CDatList = NULL;
    FreedInfos = NULL;
    FreedPieces = NULL;
}
