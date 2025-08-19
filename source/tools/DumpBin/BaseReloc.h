#pragma once

typedef struct _BaseRelocBit {
    WORD Offset : 12;
    WORD Type : 4;
} BaseRelocBit, * PBaseRelocBit;

PCSTR GetBaseRelocType(WORD Type);
DWORD BaseReloc(PBYTE Data, LONGLONG Size);
