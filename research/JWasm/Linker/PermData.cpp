#include "PermData.h"
#include "MemorySubsystem.h"

PermData::PermData(MemorySubsystem* memory)
{
	this->memory = memory;
	IncFileName = nullptr;
	IncStrTab = nullptr;
	ReadRelocs = nullptr;
	OldExe = nullptr;
	AltDefData = nullptr;
	OldSymFile = nullptr;
	IncGroupDefs = nullptr;
	IncGroups = nullptr;
	SavedUserLibs = nullptr;
	SavedDefLibs = nullptr;
	CarveClass = nullptr;
	CarveGroup = nullptr;
	CarveDLLInfo = nullptr;
	CarveExportInfo = nullptr;
	CarveLeader = nullptr;
	CarveModEntry = nullptr;
	CarveSegData = nullptr;
	CarveSymbol = nullptr;
}

PermData::~PermData()
{
	CleanPermData();
}

void PermData::Reset(void)
{
	IncFileName = nullptr;
	IncStrTab = nullptr;
	ReadRelocs = nullptr;
	OldExe = nullptr;
	AltDefData = nullptr;
	OldSymFile = nullptr;
	IncGroupDefs = nullptr;
	IncGroups = nullptr;
	SavedUserLibs = nullptr;
	SavedDefLibs = nullptr;
	CarveClass = CarveCreate(sizeof(class_entry), 20 * sizeof(class_entry));
	CarveGroup = CarveCreate(sizeof(group_entry), 20 * sizeof(group_entry));
	CarveDLLInfo = CarveCreate(sizeof(dll_sym_info), 100 * sizeof(dll_sym_info));
	CarveExportInfo = CarveCreate(sizeof(entry_export), 20 * sizeof(entry_export));
	CarveLeader = CarveCreate(sizeof(seg_leader), SEG_CARVE_SIZE);
	CarveModEntry = CarveCreate(sizeof(mod_entry), MOD_CARVE_SIZE);
	CarveSegData = CarveCreate(sizeof(segdata), SDATA_CARVE_SIZE);
	CarveSymbol = CarveCreate(sizeof(symbol), SYM_CARVE_SIZE);
	InitStringTable(&PermStrings, true);
	InitStringTable(&PrefixStrings, true);
	InitStringTable(&StoredRelocs, false);
}

carve_t PermData::CarveCreate(size_t elm_size, size_t blk_size)
{
	elm_size = (elm_size + (sizeof(int) - 1)) & ~(sizeof(int) - 1);
	if (elm_size < sizeof(free_t)) {
		elm_size = sizeof(free_t);
	}
	cv_t* cv = (cv_t*)memory->AllocateMemory(sizeof(*cv));
	cv->elm_size = elm_size;
	cv->blk_size = blk_size;
	cv->elm_count = cv->blk_size / cv->elm_size;
	cv->blk_top = cv->elm_count * elm_size;
	cv->blk_count = 0;
	cv->blk_list = NULL;
	cv->free_list = NULL;
	cv->blk_map = NULL;
	cv->size_chg = false;
	return (cv);
}

void PermData::CarveDestroy(carve_t cv)
{
	blk_t* cur;
	blk_t* next;

	if (cv != NULL) {
		if (cv->blk_map != NULL) {
			memory->FreeMemory(cv->blk_map);
		}
		cur = cv->blk_list;
		while (cur != NULL) {
			next = cur->next;
			memory->FreeMemory(cur);
			cur = next;
		}
		memory->FreeMemory(cv);
	}
}

stringblock* PermData::AllocNewBlock(stringtable* strtab)
{
	stringblock* blk = (stringblock*)memory->AllocateMemory(sizeof(stringblock));
	blk->next = nullptr;
	//FIX ME RingAppend(&strtab->data, blk);
	blk->size = 0;
	return blk;
}

void PermData::InitStringTable(stringtable* strtab, bool dontsplit)
{
	strtab->data = NULL;
	if (dontsplit) {
		strtab->currbase = 1;
	}
	else {
		strtab->currbase = 0;
	}
	AllocNewBlock(strtab);
}

void PermData::FiniStringTable(stringtable* strtab)
{
	//FIX ME RingFree(&strtab->data);
}

void PermData::CleanPermData(void)
{
	if (LinkState & LINK_ERROR) {
		//FIX ME QDelete(IncFileName);
	}
	CarveDestroy(CarveLeader);
	CarveDestroy(CarveModEntry);
	CarveDestroy(CarveDLLInfo);
	CarveDestroy(CarveExportInfo);
	CarveDestroy(CarveSymbol);
	CarveDestroy(CarveSegData);
	CarveDestroy(CarveClass);
	CarveDestroy(CarveGroup);
	FiniStringTable(&PrefixStrings);
	FiniStringTable(&PermStrings);
	FiniStringTable(&StoredRelocs);
	memory->FreeMemory(IncFileName);
	memory->FreeMemory(IncStrTab);
	memory->FreeMemory(ReadRelocs);
	memory->FreeMemory(OldExe);
	memory->FreeMemory(OldSymFile);
	memory->FreeMemory(AltDefData);
	//FIX ME RingFree(&IncGroupDefs);
	memory->FreeMemory(IncGroups);
	FreeList(SavedUserLibs);
	FreeList(SavedDefLibs);
}

void PermData::FreeList(libnamelist* list)
{
	libnamelist* curr;
	libnamelist* next;
	curr = list;
	while (curr != nullptr) {
		next = curr->next;
		memory->FreeMemory(curr);
		curr = next;
	}
}