#include "pch.h"
#include "globals.h"
#include "objfree.h"
#include "LinkerUtils.h"
#include "dbgall.h"
#include "reloc.h"
#include "Carve.h"
#include "MixCache.h"
#include "ovlsupp.h"
#include "libr.h"

void BurnLibs(MemorySubsystem* memory, MixCache* cache)
{
	file_list* temp;
	dict_entry* dict;

	for (temp = ObjLibFiles; temp != NULL; temp = temp->next_file) {
		if (temp->status & STAT_AR_LIB) {
			cache->CacheFree(temp, temp->strtab);
			temp->strtab = NULL;
		}
		dict = temp->u.dict;
		if (dict == NULL) continue;
		if (temp->status & STAT_AR_LIB) {
			cache->CacheFree(temp, dict->a.filepostab - 1);
			_LnkFree(dict->a.fnametab);
		}
		else {
			if (dict->o.cache != NULL) {
				FreeDictCache(memory, dict->o.cache, (dict->o.pages / PAGES_IN_CACHE) + 1);
			}
		}
		_LnkFree(dict);
		temp->u.dict = NULL;
		cache->FreeObjCache(temp);
	}
}

void FreeSections(MemorySubsystem* memory, PermData* permData, HashTable* hashTable, MixCache* cache, section* sec)
{
	section* next;
	ORDER_CLASS* Class, * NextClass;
	ORDER_SEGMENT* Seg, * NextSeg;

	while (sec != NULL) {
		FreeFiles(memory, cache, sec->files);
		if (!(LinkFlags & INC_LINK_FLAG)) {
			FreeMods(permData, cache, sec->mods);
			permData->FreeClasses(sec->classlist);
		}
	    DBISectCleanup(sec);
		FreeAreas(memory, permData, hashTable, cache, sec->areas);
		hashTable->ZapHTable(sec->modFilesHashed);
		Class = sec->orderlist;
		while (Class != NULL) {   // Free up any Order Class entries
			if (Class->Name != NULL) {   // Including members and sucessors
				_LnkFree(Class->Name);
			}
			if (Class->Copy) {
				_LnkFree(Class->SrcName);
			}
			Seg = Class->SegList;
			while (Seg != NULL) {  // Order Seg emtries can also have members and sucessors
				if (Seg->Name != NULL) {
					_LnkFree(Seg->Name);
				}
				NextSeg = Seg->NextSeg;
				_LnkFree(Seg);
				Seg = NextSeg;
			}
			NextClass = Class->NextClass;
			_LnkFree(Class);
			Class = NextClass;
		}
		next = sec->next_sect;
		_LnkFree(sec);
		sec = next;
	}
}

void FreeAreas(MemorySubsystem* memory, PermData* permData, HashTable* hashTable, MixCache* cache, OVL_AREA* area)
{
	OVL_AREA* next;

	while (area != NULL) {
		next = area->next_area;
		FreeSections(memory, permData, hashTable, cache, area->sections);
		area = next;
	}
}

void FreeAMod(PermData* permData, MixCache* cache, mod_entry* mod)
{
	cache->FreeObjCache(mod->f.source);
	permData->FreeModEntry(mod);
}

void FreeMods(PermData* permData, MixCache* cache, mod_entry* head)
{
	void* temp;

	while (head != NULL) {
		temp = head->n.next_mod;
		FreeAMod(permData, cache, head);
		head = (mod_entry*)temp;
	}
}

void FreeFiles(MemorySubsystem* memory, MixCache* cache, file_list* list)
{
	void* temp;

	while (list != NULL) {
		temp = list->next_file;
		cache->CacheClose(list, 3);
		if (list->status & STAT_HAS_MEMBER && list->u.member != NULL) {
			FreeList(memory, list->u.member);
		}
		//_PermFree(list);
		list = (file_list*)temp;
	}
}


void CleanLinkStruct(MemorySubsystem* memory, PermData* permData, HashTable* hashTable, MixCache* cache, SymbolTableMemory* symMem)
{
	if (Root == NULL) return;  /* haven't finished initializing */
	BurnLibs(memory, cache);
	FreeFiles(memory, cache, ObjLibFiles);
	FreeFiles(memory, cache, Root->files);
	ObjLibFiles = NULL;
	Root->files = NULL;
	if (!(LinkFlags & INC_LINK_FLAG)) {
		FreeMods(permData, cache, LibModules);
	}
	if (SymFileName != NULL) {
		_LnkFree(SymFileName);
	}
	if (FmtData.osname != NULL) {
		_LnkFree(FmtData.osname);
	}
	if (FmtData.resource != NULL) {
		_LnkFree(FmtData.resource);
	}
	FreeRelocInfo(memory);
	FreeGroups(permData, Groups);
	FreeGroups(permData, AbsGroups);
	Groups = NULL;
	AbsGroups = NULL;
	FreeSections(memory, permData, hashTable, cache, Root);
	DBICleanup(permData);
	Root = NULL;
	if (FmtData.type & MK_REAL_MODE) {
		FreeOvlStruct(memory, permData, cache, symMem);
	}
}

#if defined(_OS2) || defined( _QNXLOAD )
void FreeSegFlags(MemorySubsystem* memory, seg_flags* curr)
{
	seg_flags* next;

	while (curr != NULL) {
		next = curr->next;
		_LnkFree(curr->name);
		_LnkFree(curr);
		curr = next;
	}
}
#endif

void FreeGroups(PermData* permData, group_entry* head)
{
	group_entry* next;

	while (head != NULL) {
		next = head->next_group;
		permData->FreeAGroup(head);
		head = next;
	}
}
