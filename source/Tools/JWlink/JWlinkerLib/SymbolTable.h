#pragma once

#include "MemorySubsystem.h"
//#include "walloca.h"
//#include "linkstd.h"
//#include "pcobj.h"
//#include "objio.h"
//#include "alloc.h"
//#include "newmem.h"
//#include "msg.h"
//#include "wlnkmsg.h"
//#include "objnode.h"
//#include "wcomdef.h"
//#include "mapio.h"
//#include "impexp.h"
//#include "objstrip.h"
//#include "objpass1.h"
//#include "ring.h"
//#include "strtab.h"
//#include "carve.h"
//#include "permdata.h"
//#include "nwpfx.h"
//#include "command.h"
#include "taddr.h"
#include "watcom.h"
#include "symtab.h"
#include "syms.h"

using namespace std;

#define STATIC_TABSIZE  241  /* should be prime */
#define GLOBAL_TABSIZE  1789  /* should be prime */
#define STATIC_TABALLOC (256 * sizeof(symbol *))  // 1st power of 128 > TABSIZE
#define GLOBAL_TABALLOC (1792 * sizeof(symbol *)) // 1st power of 128 > TABSIZE

class SymbolTable
{
	shared_ptr<MemorySubsystem> memorySubsystem;
	symbol* SymList;
	symbol** GlobalSymPtrs;
	symbol** StaticSymPtrs;
public:
	SymbolTable(shared_ptr<MemorySubsystem> memorySubsystem);
	~SymbolTable();
};

