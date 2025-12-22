#pragma once

#include "globals.h"
#include "MemorySubsystem.h"
#include "MessagingSubsystem.h"

typedef struct blk blk_t;
typedef struct free_t free_t;

typedef struct {
	free_t* free_list;
	free_t* insert;
	blk_t* blk_list;
	blk_t** blk_map;
	size_t      elm_size;
	size_t      elm_count;
	size_t      blk_top;
	size_t      blk_count;
	size_t      blk_size;
	unsigned    size_chg : 1;
} cv_t, * carve_t;

typedef struct {
	unsigned    bindex;
	blk_t* block;
	free_t** head;
	carve_t     cv;
} cvinit_t;

#define MK_INDEX( b, o )        (((b)<<16)|(o))
#define GET_BLOCK( i )          (((i)>>16)&0x0ffff)
#define GET_OFFSET( i )         ((i)&0x0ffff)

// block 0 is reserved for special indices

enum {
	CARVE_NULL_INDEX = MK_INDEX(0, 0),
	CARVE_INVALID_INDEX = MK_INDEX(0, 1),
};

class Carve
{
	MemorySubsystem* memory;
	MessagingSubsystem* msg;
	FileSubsystem* file;
public:
	Carve(MemorySubsystem* memory, MessagingSubsystem* msg, FileSubsystem* file);
	~Carve();
	blk_t* newBlk(cv_t* cv);
	static void MakeFreeList(cv_t* cv, blk_t* newblk, unsigned offset);
	static void CarveZapBlock(carve_t cv, void* blk, void* dummy);
	carve_t CarveCreate(size_t elm_size, size_t how_many);
	void CarveRestart(carve_t cv, unsigned);
	void CarvePurge(carve_t cv);
	void CarveVerifyAllGone(carve_t cv, char*);
	void CarveDestroy(carve_t cv);
	void* CarveAlloc(carve_t cv);
	void* CarveZeroAlloc(carve_t cv);
	void CarveFree(carve_t cv, void* elm);
	void* CarveGetIndex(carve_t, void*);
	void CarveWalkBlocks(carve_t, void (*)(carve_t, void*, void*), void*);
	bool CarveBlockModified(void*);
	void CarveBlockScan(carve_t, void*, void (*)(void*, void*), void*);
	unsigned CarveBlockSize(carve_t);
	unsigned CarveNumElements(carve_t);
	void* CarveBlockData(void*);
	void* CarveMapIndex(carve_t, void*);
	bool CarveSizeChanged(carve_t);
	void CarveInsertFree(carve_t, void*);
	void CarveWalkAllFree(carve_t gcv, void (*rtn)(void*));
	void CarveWalkAll(carve_t, void (*)(void*, void*), void*);
};

