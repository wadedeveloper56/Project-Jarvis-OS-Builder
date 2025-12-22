#include "pch.h"
#include "globals.h"
#include "objfree.h"
#include "LinkerUtils.h"
#include "dbgall.h"
#include "reloc.h"
#include "Carve.h"

void BurnLibs(MemorySubsystem* memory)
{
	file_list* temp;
	dict_entry* dict;

	for (temp = ObjLibFiles; temp != NULL; temp = temp->next_file) {
		if (temp->status & STAT_AR_LIB) {
			//FIX ME CacheFree(temp, temp->strtab);
			temp->strtab = NULL;
		}
		dict = temp->u.dict;
		if (dict == NULL) continue;
		if (temp->status & STAT_AR_LIB) {
			//FIX ME CacheFree(temp, dict->a.filepostab - 1);
			_LnkFree(dict->a.fnametab);
		}
		else {
			if (dict->o.cache != NULL) {
				//FIX ME FreeDictCache(dict->o.cache, (dict->o.pages / PAGES_IN_CACHE) + 1);
			}
		}
		_LnkFree(dict);
		temp->u.dict = NULL;
		//FIX ME FreeObjCache(temp);
	}
}

void FreeFiles(MemorySubsystem* memory, file_list* list)
{
	void* temp;

	while (list != NULL) {
		temp = list->next_file;
		//FIX ME CacheClose(list, 3);
		if (list->status & STAT_HAS_MEMBER && list->u.member != NULL) {
			FreeList(memory, list->u.member);
		}
		_PermFree(list);
		list = (file_list*)temp;
	}
}

void FreeAMod(mod_entry* mod)
{
	//FIX ME FreeObjCache(mod->f.source);
	//FIX ME FreeModEntry(mod);
}

static void FreeMods(mod_entry* head)
{
	void* temp;

	while (head != NULL) {
		temp = head->n.next_mod;
		FreeAMod(head);
		head = (mod_entry*)temp;
	}
}

void FreeGroups(PermData* permData, group_entry* head)
{
	group_entry* next;

	while (head != NULL) {
		next = head->next_group;
		permData->FreeAGroup(head);
		head = next;
	}
}

static void FreeSections(MemorySubsystem* memory, section* sec)
{
	section* next;
	ORDER_CLASS* Class, * NextClass;
	ORDER_SEGMENT* Seg, * NextSeg;

	while (sec != NULL) {
		FreeFiles(memory, sec->files);
		if (!(LinkFlags & INC_LINK_FLAG)) {
			FreeMods(sec->mods);
			//FIX ME FreeClasses(sec->classlist);
		}
		//FIX ME DBISectCleanup(sec);
		//FIX ME FreeAreas(sec->areas);
		//FIX ME ZapHTable(sec->modFilesHashed, LFree);
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

void CleanLinkStruct(MemorySubsystem* memory, PermData* permData)
{
	if (Root == NULL) return;  /* haven't finished initializing */
	BurnLibs(memory);
	FreeFiles(memory, ObjLibFiles);
	FreeFiles(memory, Root->files);
	ObjLibFiles = NULL;
	Root->files = NULL;
	if (!(LinkFlags & INC_LINK_FLAG)) {
		FreeMods(LibModules);
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
	FreeSections(memory, Root);
	//FIX ME DBICleanup();
	Root = NULL;
	if (FmtData.type & MK_REAL_MODE) {
		//FIX ME FreeOvlStruct();
	}
}

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
