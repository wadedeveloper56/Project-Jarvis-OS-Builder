#pragma once

#pragma warning(push)
#pragma warning(disable : 4200)
struct CV_INFO_PDB70
{
    DWORD  CvSignature;
    GUID Signature;
    DWORD Age;
    BYTE PdbFileName[];
};
#pragma warning(pop)  

PCSTR GetDebugType(DWORD Type);
void PrintDebug(PBYTE Data, PIMAGE_DEBUG_DIRECTORY DebugDirectory);
DWORD Debug(PBYTE Data, LONGLONG Size);
