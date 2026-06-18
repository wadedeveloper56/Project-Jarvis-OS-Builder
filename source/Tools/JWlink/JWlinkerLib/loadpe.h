#pragma once

#include "Structs.h"

#define I386_TRANSFER_OP1       0xff    /* first byte of a "JMP [FOO]" */
#define I386_TRANSFER_OP2       0x25    /* second byte of a "JMP [FOO]" */
#define MINIMUM_SEG_SHIFT       2       /* Corresponds to 2^2 == 4 bytes */
#define DEFAULT_SEG_SHIFT       9       /* Corresponds to 2^9 == 512 bytes */
#define STUB_ALIGN 8    /* for PE format */
#define SYM_IS_REFERENCED (SYM_REFERENCED | SYM_LOCAL_REF)
#define I386_TRANSFER_SIZE (sizeof(i386_transfer))
#define ALPHA_TRANSFER_OP1      0x277F
#define ALPHA_TRANSFER_OP2      0xA37B
#define ALPHA_TRANSFER_OP3      0x6BFB
#define ALPHA_TRANSFER_SIZE (sizeof(alpha_transfer))
#define PPC_TRANSFER_SIZE (sizeof(PPCJump))
#define TRANSFER_SEGNAME "TRANSFER CODE"

#pragma pack(1)
typedef struct 
{
	uint8_t  op1;
	uint8_t  op2;
	uint32_t dest;
} i386_transfer;

typedef struct
{
	uint16_t high;
	uint16_t op1;
	uint16_t low;
	uint16_t op2;
	uint16_t zero;
	uint16_t op3;
} alpha_transfer;
#pragma pack()

typedef struct local_import
{
	struct local_import* next;
	symbol* iatsym;
	symbol* locsym;
} local_import;

typedef struct IData
{
	offset      ilt_off;
	offset      eof_ilt_off;
	offset      iat_off;
	offset      mod_name_off;
	offset      hint_off;
	offset      total_size;
	segdata* sdata;
} IData;

#if 1
typedef struct EData
{
	segdata* sdata;
} EData;
#endif


extern i386_transfer    I386Jump;
extern uint32_t PPCJump[];
extern alpha_transfer   AlphaJump;
extern module_import* PEImpList;  /* list of imported modules */
extern unsigned         NumMods;
extern segdata* XFerSegData; /* linker-generated thunk data */
extern local_import* PELocalImpList;
extern unsigned         NumLocalImports;

void ResetLoadPE();