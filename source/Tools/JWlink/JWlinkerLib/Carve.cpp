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
