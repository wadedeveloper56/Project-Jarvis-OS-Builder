#include "pch.h"
#include "Carve.h"
#include "MemorySubsystem.h"
#include "Structs.h"

Carve::Carve(MemorySubsystem* memorySubsystem) : memorySubsystem(memorySubsystem), cv(nullptr)
{
}

Carve::~Carve()
{
	if (cv != nullptr)
	{
		CarveDestroy();
	}
}

void MakeFreeList(cv_t* cv, blk_t* newblk, unsigned offset)
{
	size_t      elm_size;
	char* top_elm;
	char* bottom_elm;
	char* free_elm;
	free_t* free_list;

	elm_size = cv->elm_size;
	bottom_elm = newblk->data + offset;
	top_elm = newblk->data + cv->blk_top;
	free_list = cv->free_list;
	free_elm = top_elm;
	do
	{                                
		free_elm -= elm_size;
		DbgZapFreed(free_elm, elm_size);
		_ADD_TO_FREE(free_list, free_elm);
	} while (free_elm != bottom_elm);
	cv->free_list = free_list;
}

blk_t* newBlk(MemorySubsystem* memorySubsystem, cv_t* cv)
{
	blk_t* newblk;
	blk_t** blklist;

	_ChkAlloc(blk_t*, newblk, sizeof(blk_t) - 1 + cv->blk_size);
	blklist = &cv->blk_list;
	while (*blklist > newblk)
	{              
		blklist = &(*blklist)->next;      
	}
	newblk->next = *blklist;
	*blklist = newblk;
	cv->blk_count++;
	cv->size_chg = TRUE;
	return newblk;
}

void Carve::CarveFree(void* elm)
{
	if (elm == NULL)
	{
		return;
	}
	CarveDebugFree(cv, elm);
	_ADD_TO_FREE(cv->free_list, elm);
}

void* Carve::CarveAlloc()
{
	void* p;

	if (cv->free_list == NULL)
	{
		MakeFreeList(cv, newBlk(memorySubsystem, cv), 0);
	}
	_REMOVE_FROM_FREE(cv, p);
	DbgZapAlloc(p, cv->elm_size);
	return p;
}

void Carve::CarveCreate(size_t elm_size, size_t blk_size)
{
	elm_size = (elm_size + (sizeof(int) - 1)) & ~(sizeof(int) - 1);
	if (elm_size < sizeof(free_t))
	{
		elm_size = sizeof(free_t);
	}
	_ChkAlloc(cv_t*, cv, sizeof(*cv));
	cv->elm_size = elm_size;
	cv->blk_size = blk_size;
	cv->elm_count = cv->blk_size / cv->elm_size;
	cv->blk_top = cv->elm_count * elm_size;
	cv->blk_count = 0;
	cv->blk_list = NULL;
	cv->free_list = NULL;
	cv->blk_map = NULL;
	cv->size_chg = FALSE;
}

void Carve::CarveDestroy()
{
	blk_t* cur;
	blk_t* next;

	if (cv != NULL)
	{
		if (cv->blk_map != NULL)
		{
			_LnkFree(cv->blk_map);
		}
		cur = cv->blk_list;
		while (cur != NULL)
		{
			next = cur->next;
			_LnkFree(cur);
			cur = next;
		}
		_LnkFree(cv);
	}
}
