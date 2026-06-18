#include "pch.h"
#include "loadpe.h"
#include "globals.h"
#include "Structs.h"

i386_transfer    I386Jump = { I386_TRANSFER_OP1, I386_TRANSFER_OP2, 0 };
alpha_transfer   AlphaJump = { 0, ALPHA_TRANSFER_OP1,	0, ALPHA_TRANSFER_OP2,					0, ALPHA_TRANSFER_OP3 };
uint32_t PPCJump[] = {
	0x81620000,         //   lwz        r11,[tocv]__imp_RtlMoveMemory(rtoc)
	0x818B0000,         //   lwz        r12,(r11)
	0x90410004,         //   stw        rtoc,0x4(sp)
	0x7D8903A6,         //   mtctr      r12
	0x804B0004,         //   lwz        rtoc,0x4(r11)
	0x4E800420          //   bctr
};
module_import* PEImpList;  /* list of imported modules */
unsigned         NumMods;
segdata* XFerSegData; /* linker-generated thunk data */
local_import* PELocalImpList;
unsigned         NumLocalImports;
struct IData IData;
#if 1 /* JWLink */
struct EData EData;
#endif

void ResetLoadPE()
{
	PEImpList = NULL;
	XFerSegData = NULL;
	NumMods = 0;
	NumImports = 0;
	memset(&IData, 0, sizeof(IData));
#if 1 /* JWLink: exports */
	memset(&EData, 0, sizeof(EData));
#endif
}
