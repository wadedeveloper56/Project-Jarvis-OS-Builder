#include "pch.h"
#include "globals.h"
#include "Initialize.h"
#include "orl.h"
#include "debug.h"
#include "carve.h"
#include "stringtable.h"
#include "ring.h"
#include "hash.h"
#include "CmdLine.h"

#define SEG_CARVE_SIZE          (2*1024)
#define MOD_CARVE_SIZE          (5*1024)
#define SDATA_CARVE_SIZE        (16*1024)
#define SYM_CARVE_SIZE          (32*1024)

int ARCompName(const void* key, const void* vbase);
int ARCompIName(const void* key, const void* vbase);
int (*CmpARRtn)(const void*, const void*) = ARCompName;
int (*CmpOMFRtn)(const void*, const void*, size_t) = memcmp;
int (*CmpRtn)(const void*, const void*, size_t);

#ifdef _INT_DEBUG
int           Chunks;
#endif
int           OpenFiles;      // the number of open files
unsigned      LastResult;
bool          CaughtBreak;    // set to TRUE if break hit.
char* TFileName;
unsigned long TmpFSize;
bool          BannerPrinted;
nodearray* ExtNodes;           // ptr to obj file import list
nodearray* SegNodes;           // ptr to obj file segment list
nodearray* GrpNodes;           // ptr to obj file group list
nodearray* NameNodes;          // ptr to obj file lname list
symbol** GlobalSymPtrs;
symbol** StaticSymPtrs;
orl_handle    ORLHandle;
long          ORLFilePos;
orl_funcs     ORLFuncs;
readcache* ReadCacheList;
sysblock* PrevCommand;
stringtable   PermStrings;
stringtable   PrefixStrings;  /* these are NetWare prefix strings of which there could possibly be several */
stringtable   StoredRelocs;
carve_t       CarveLeader;
carve_t       CarveModEntry;
carve_t       CarveSymbol;
carve_t       CarveSegData;
carve_t       CarveClass;
carve_t       CarveGroup;
carve_t       CarveDLLInfo;
carve_t       CarveExportInfo;
char* IncFileName;
incgroupdef* IncGroupDefs;
group_entry** IncGroups;
libnamelist* SavedUserLibs;
libnamelist* SavedDefLibs;
char* ReadRelocs;
unsigned      SizeRelocs;
char* OldExe;
char* OldSymFile;
void* AltDefData;
char* IncStrTab;
unsigned        NameLen;
symbol* LastSym;
symbol* SymList = NULL;
block_data Pass1Blocks;
block_data PermBlocks;
char* SymFileName;
group_entry* DBIGroups;
symrecinfo* UndefList;
symrecinfo* SymTraceList;
int             MapCol;
time_t          StartT;
clock_t         ClockTicks;
bool            Absolute_Seg;
bool             Buffering;  // buffering on/off.
int              BufferSize;          // # of chars in buffer.
void* LastFile;
file_list** LastLibFile;
unsigned_16         AreaSize;
comdat_info* CDatList;
comdat_info* FreedInfos;
comdat_piece* FreedPieces;
unsigned_16  CurrModThere;
arcdata* ArcBuffer;
unsigned_32  ArcBufLen;
mod_entry** ModTable;
unsigned_16  CurrModHandle;
section** SectOvlTab;
sysblock* SysBlocks;
sysblock* LinkCommands;
unsigned_32  DbgInfoCount;
unsigned_32  DbgInfoLen;
virt_mem     NovDbgInfo;
virt_mem     CurrDbgLoc;
module_import* PEImpList;  /* list of imported modules */
unsigned         NumMods;
segdata* XFerSegData; /* linker-generated thunk data */
local_import* PELocalImpList;
unsigned         NumLocalImports;

static struct {
	offset      ilt_off;
	offset      eof_ilt_off;
	offset      iat_off;
	offset      mod_name_off;
	offset      hint_off;
	offset      total_size;
	segdata* sdata;
} IData;
offset           LastOptimized;  // offset last optimized.
fix_type         LastOptType;
segdata* LastSegData;
offset           FixupOverflow;

#if 1 /* JWLink */
static struct {
	segdata* sdata;
} EData;
#endif
infilelist* CachedLibFiles;
infilelist* CachedFiles;
edgelist* FreedEdges;
bakpat_list* BakPats;
unsigned        FmtRelocSize;
reloc_info* FloatFixups;
trace_info* CurrTrace;
trace_info* TraceList;
startinfo       StartInfo;
pHTable  Toc;
char* TocName;
symbol* TocSym;
offset TocSize;
offset TocShift;
char* Name;
vmemblock* VMemBlocks;

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

unsigned NumCacheBlocks(unsigned long len)
{
	unsigned    numblocks;

	numblocks = len / CACHE_PAGE_SIZE;
	if (len % CACHE_PAGE_SIZE != 0) {
		numblocks++;
	}
	return numblocks;
}

bool DumpFileCache(MemorySubsystem* memory, infilelist* file, bool nuke)
{
	unsigned    num;
	unsigned    savenum;
	unsigned    index;
	char** blocklist;
	bool        blockfreed;

	blockfreed = false;
	if (nuke) {
		savenum = UINT_MAX;
	}
	else {
		savenum = file->currpos / CACHE_PAGE_SIZE;
	}
	if (file->cache != NULL) {
		num = NumCacheBlocks(file->len);
		blocklist = (char**)file->cache;
		for (index = 0; index < num; index++) {
			if (index != savenum && *blocklist != NULL) {
				_LnkFree(*blocklist);
				*blocklist = NULL;
				blockfreed = true;
			}
			blocklist++;
		}
	}
	return blockfreed;
}

void FreeObjCache(MemorySubsystem* memory, file_list* list)
{
	if (list == NULL) return;
	if (list->file->flags & INSTAT_FULL_CACHE) {
		_LnkFree(list->file->cache);
	}
	else {
		DumpFileCache(memory, list->file, true);
	}
	list->file->cache = NULL;
}

void CacheClose(FileSubsystem* files, MemorySubsystem* memory, file_list* list, unsigned pass)
{
	infilelist* file;
	bool        nukecache;

	if (list == NULL) return;
	file = list->file;
	//    if( file->handle == NIL_HANDLE ) return;
	file->flags = (infile_flags)(file->flags & ~INSTAT_IN_USE);
	switch (pass) {
		case 1: /* first pass */
			nukecache = !(file->flags & INSTAT_LIBRARY);
			if (file->flags & INSTAT_FULL_CACHE) {
				if (nukecache) {
					FreeObjCache(memory, list);
				}
			}
			else {
				DumpFileCache(memory, file, nukecache);   // don't cache .obj's
			}
			break;
		case 3: /* freeing structure */
			FreeObjCache(memory, list);
			if (file->handle != NIL_HANDLE) {
				files->Close(file->handle);
				file->handle = NIL_HANDLE;
			}
			break;
	}
}

void CacheFree(MemorySubsystem* memory, file_list* list, void* mem)
{
	if (list->file->flags & INSTAT_PAGE_CACHE) {
		_LnkFree(mem);
	}
}

void FreeDictCache(MemorySubsystem* memory, void** cache, unsigned_16 buckets)
{
	while (buckets != 0) {
		_LnkFree(cache[--buckets]);
	}
	_LnkFree(cache);
}

void BurnLibs(MemorySubsystem* memory)
{
	file_list* temp;
	dict_entry* dict;

	for (temp = ObjLibFiles; temp != NULL; temp = temp->next_file) {
		if (temp->status & STAT_AR_LIB) {
			CacheFree(memory, temp, temp->strtab);
			temp->strtab = NULL;
		}
		dict = temp->u.dict;
		if (dict == NULL) continue;
		if (temp->status & STAT_AR_LIB) {
			CacheFree(memory, temp, dict->a.filepostab - 1);
			_LnkFree(dict->a.fnametab);
		}
		else {
			if (dict->o.cache != NULL) {
				FreeDictCache(memory, dict->o.cache, (dict->o.pages / PAGES_IN_CACHE) + 1);
			}
		}
		_LnkFree(dict);
		temp->u.dict = NULL;
		FreeObjCache(memory, temp);
	}
}

void FreeFiles(FileSubsystem* file, MemorySubsystem* memory, file_list* list)
{
	void* temp;

	while (list != NULL) {
		temp = list->next_file;
		CacheClose(file, memory, list, 3);
		if (list->status & STAT_HAS_MEMBER && list->u.member != NULL) {
			FreeList(memory, list->u.member);
		}
		//_PermFree(list);
		list = (file_list*)temp;
	}
}

void FreeModEntry(MessagingSubsystem* msg, mod_entry* mod)
{
	CarveFree(msg, CarveModEntry, mod);
}

void FreeAMod(MessagingSubsystem* msg, MemorySubsystem* memory, mod_entry* mod)
{
	FreeObjCache(memory, mod->f.source);
	FreeModEntry(msg, mod);
}

void FreeMods(MessagingSubsystem* msg, MemorySubsystem* memory, mod_entry* head)
{
	void* temp;

	while (head != NULL) {
		temp = head->n.next_mod;
		FreeAMod(msg, memory, head);
		head = (mod_entry*)temp;
	}
}

bool TraverseRelocBlock(MemorySubsystem* memory, reloc_info** reloclist, unsigned num, bool (*fn)(MemorySubsystem*, reloc_info*))
{
	while (num > 0) {
		if (fn(memory, *reloclist++))
			return(true);
		if (FmtData.type & MK_OS2_FLAT) {
			if (fn(memory, *reloclist++)) {
				return(true);
			}
		}
		num--;
	}
	return(false);
}

bool TraverseOS2RelocList(MemorySubsystem* memory, group_entry* group, bool (*fn)(MemorySubsystem*, reloc_info*))
{
	unsigned_32         index;
	unsigned_32         highidx;
	unsigned            lowidx;
	reloc_info*** reloclist;

	reloclist = (reloc_info***)group->g.grp_relocs;
	if (reloclist != NULL) {
		index = OSF_PAGE_COUNT(group->totalsize);
		highidx = OSF_RLIDX_HIGH(index);
		while (highidx > 0) {
			if (TraverseRelocBlock(memory, *reloclist, OSF_RLIDX_MAX, fn))
				return(true);
			reloclist++;
			highidx--;
		}
		lowidx = OSF_RLIDX_LOW(index);
		if (lowidx > 0) {
			return(TraverseRelocBlock(memory, *reloclist, OSF_RLIDX_LOW(index), fn));
		}
	}
	return(false);
}

bool FreeRelocList(MemorySubsystem* memory, reloc_info* list)
{
	while (list != NULL) {
		if (!(list->sizeleft & RELOC_SPILLED)) {
			_LnkFree(list->loc.addr);
		}
		list = list->next;
	}
	return(false);  /* needed for OS2 generic traversal routines */
}

void FreeRelocSect(MemorySubsystem* memory, section* sect)
{
	FreeRelocList(memory, (reloc_info*)sect->reloclist);
}

void FreeGroupRelocs(MemorySubsystem* memory, group_entry* group)
{
	unsigned_32         highidx;
	unsigned_32         index;
	reloc_info*** reloclist;

	if (!(LinkState & MAKE_RELOCS))
		return;
	if (FmtData.type & (MK_OS2_FLAT | MK_PE)) {
		TraverseOS2RelocList(memory, group, FreeRelocList);
		reloclist = (reloc_info***)group->g.grp_relocs;
		if (reloclist != NULL) {
			index = OSF_PAGE_COUNT(group->totalsize);
			highidx = OSF_RLIDX_HIGH(index);
			if (OSF_RLIDX_LOW(index) != 0) {
				highidx++;
			}
			while (highidx > 0) {
				_LnkFree(*reloclist);
				reloclist++;
				highidx--;
			}
		}
	}
	else if (FmtData.type & (MK_ELF | MK_OS2_16BIT | MK_QNX)) {
		FreeRelocList(memory, (reloc_info*)group->g.grp_relocs);
	}
}

void WalkAreas(MemorySubsystem* memory, OVL_AREA* ovl, void (*rtn)(MemorySubsystem*, section*));

void WalkSections(MemorySubsystem* memory, section* sect, void (*rtn)(MemorySubsystem*, section*))
{
	for (; sect != NULL; sect = sect->next_sect) {
		rtn(memory, sect);
		WalkAreas(memory, sect->areas, rtn);
	}
}

void WalkAreas(MemorySubsystem* memory, OVL_AREA* ovl, void (*rtn)(MemorySubsystem*, section*))
{
	for (; ovl != NULL; ovl = ovl->next_area) {
		WalkSections(memory, ovl->sections, rtn);
	}
}

void WalkAllSects(MemorySubsystem* memory, void (*rtn)(MemorySubsystem*,section*))
{
	rtn(memory, Root);
	if (FmtData.type & MK_OVERLAYS) {
		WalkAreas(memory, Root->areas, rtn);
	}
}

void FreeRelocInfo(MemorySubsystem* memory)
{
	group_entry* group;

	if (!(LinkState & MAKE_RELOCS))
		return;
	if (FmtData.type & (MK_ELF | MK_OS2_FLAT | MK_PE | MK_OS2_16BIT | MK_QNX)) {
		for (group = Groups; group != NULL; group = group->next_group) {
			FreeGroupRelocs(memory, group);
		}
	}
	else if (Root != NULL) {
		WalkAllSects(memory, FreeRelocSect);
	}
	if (FmtData.type & MK_QNX) {
		FreeRelocList(memory, FloatFixups);
		FreeRelocSect(memory, Root);
	}
}

void FreeAGroup(MessagingSubsystem* msg, group_entry* group)
{
	CarveFree(msg, CarveGroup, group);
}

void FreeGroups(MessagingSubsystem* msg, group_entry* head)
{
	group_entry* next;

	while (head != NULL) {
		next = head->next_group;
		FreeAGroup(msg, head);
		head = next;
	}
}

void FreeSegData(MessagingSubsystem* msg, void* sdata)
{
	CarveFree(msg, CarveSegData, sdata);
}

void FreeLeader(MessagingSubsystem* msg, void* seg)
{
	RingWalk(msg, ((seg_leader*)seg)->pieces, FreeSegData);
	CarveFree(msg, CarveLeader, seg);
}

void FreeClasses(MessagingSubsystem* msg, class_entry* list)
{
	class_entry* next;

	while (list != NULL) {
		next = list->next_class;
		RingWalk(msg, list->segs, FreeLeader);
		CarveFree(msg, CarveClass, list);
		list = next;
	}
}

void FreeAreas(MessagingSubsystem* msg, FileSubsystem* file, MemorySubsystem* memory, OVL_AREA* area)
{
	OVL_AREA* next;

	while (area != NULL) {
		next = area->next_area;
		FreeSections(msg, file, memory, area->sections);
		area = next;
	}
}

void ODBISectCleanup(section* sect)
{
	sect = sect;
	//_PermFree(sect->dbg_info);
}

void DBISectCleanup(section* sect)
{
	if (LinkFlags & OLD_DBI_FLAG) {
		ODBISectCleanup(sect);
	}
}

void ZapHTable(MemorySubsystem* memory, pHTable table) {
	int i;
	pHTElem* tblPtr;
	pHTElem tblElem, temp;

	if (table == NULL) {
		return;
	}

	tblPtr = table->tbl;

	for (i = 0; i < table->size; i++) {
		for (tblElem = tblPtr[i]; tblElem != NULL; tblElem = temp) {
			memory->FreeMemory(tblElem->userData);
			temp = tblElem->next;
			free(tblElem);
		}
	}

	memory->FreeMemory(table->tbl);
	memory->FreeMemory(table);
}

void FreeSections(MessagingSubsystem* msg, FileSubsystem* file, MemorySubsystem* memory, section* sec)
{
	section* next;
	ORDER_CLASS* Class, * NextClass;
	ORDER_SEGMENT* Seg, * NextSeg;

	while (sec != NULL) {
		FreeFiles(file, memory, sec->files);
		if (!(LinkFlags & INC_LINK_FLAG)) {
			FreeMods(msg, memory, sec->mods);
			FreeClasses(msg, sec->classlist);
		}
		DBISectCleanup(sec);
		FreeAreas(msg, file, memory, sec->areas);
		ZapHTable(memory, sec->modFilesHashed);
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

void DBICleanup(MessagingSubsystem* msg)
{
	FreeGroups(msg, DBIGroups);
}

void ReleasePass1(MemorySubsystem* memory)
{
	FreeList(memory, Pass1Blocks.list);
	Pass1Blocks.list = NULL;
}

void FreeDistStuff(MessagingSubsystem* msg, MemorySubsystem* memory)
{
	unsigned    index;

	for (index = 1; index <= CurrModHandle; index++) {
		FreeAMod(msg, memory, ModTable[index]);
	}
	_LnkFree(ModTable);
	_LnkFree(ArcBuffer);
	_LnkFree(SectOvlTab);
	ReleasePass1(memory);
}

void FreeOvlStruct(MessagingSubsystem* msg, MemorySubsystem* memory)
{
	OvlClasses = NULL;
	OvlVectors = NULL;
	if (OvlSeg != NULL) {
		FreeLeader(msg, OvlSeg);
	}
	FreeDistStuff(msg, memory);
}

void CleanLinkStruct(MessagingSubsystem* msg, FileSubsystem* file, MemorySubsystem* memory)
{
	if (Root == NULL) return;  /* haven't finished initializing */
	BurnLibs(memory);
	FreeFiles(file, memory, ObjLibFiles);
	FreeFiles(file, memory, Root->files);
	ObjLibFiles = NULL;
	Root->files = NULL;
	if (!(LinkFlags & INC_LINK_FLAG)) {
		FreeMods(msg, memory, LibModules);
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
	FreeGroups(msg, Groups);
	FreeGroups(msg, AbsGroups);
	Groups = NULL;
	AbsGroups = NULL;
	FreeSections(msg, file, memory, Root);
	DBICleanup(msg);
	Root = NULL;
	if (FmtData.type & MK_REAL_MODE) {
		FreeOvlStruct(msg, memory);
	}
}

void CleanLoadFile(void)
{
}

void FreeLocalImports(void)
{
#ifdef _OS2
	FreePELocalImports();
#endif
}

void FreeUndefs(MemorySubsystem* memory)
{
	RingFree(memory, &SymTraceList);
	RingFree(memory, &UndefList);
}

void FreePaths(MemorySubsystem* memory)
{
	FreeList(memory, Path);
	Path = NULL;
	if (Name != NULL) {
		_LnkFree(Name);
		Name = NULL;
	}
}

void CleanTraces(MemorySubsystem* memory)
{
	trace_info* next;

	while (TraceList != NULL) {
		next = TraceList->next;
		if (!TraceList->found) {
			_LnkFree(TraceList->u.name);
		}
		_LnkFree(TraceList->member);
		_LnkFree(TraceList);
		TraceList = next;
	}
	TraceList = NULL;
}

void CloseSpillFile(FileSubsystem* file, MemorySubsystem* memory)
{
	if (TempFile != NIL_HANDLE) {
		//RestoreBreak();
		file->Close(TempFile);
		file->Delete(TFileName);
		_LnkFree(TFileName);
		TFileName = NULL;
		TempFile = NIL_HANDLE;
	}
}
void ResetToc(void)
{
	Toc = NULL;
	TocSize = 0;
	TocName = NULL;
	TocSym = NULL;
}

void ResetAddr(void)
{
	CurrLoc.seg = 0;
	CurrLoc.off = 0;
	CurrentSeg = NULL;
}

void ClearStartAddr(void)
{
	memset(&StartInfo, 0, sizeof(startinfo));
}

void ResetLoadFile(void)
{
	ClearStartAddr();
}

void ResetSymTrace(void)
{
	TraceList = NULL;
}

void ResetReloc(void)
{
	FloatFixups = NULL;
}

void ResetOMFReloc(void)
{
	BakPats = NULL;
}

void ResetObjStrip(void)
{
	FreedEdges = NULL;
}

void ResetObjPass1(void)
{
	ObjFormat = (obj_format)0;
}

void ResetObjOMF(void)
{
	//    ObjBuff = NULL;
	//    EOObjRec = NULL;
}

void ResetObjIO(void)
{
	CachedFiles = NULL;
	CachedLibFiles = NULL;
}

void ResetObj2Supp(void)
{
	FixupOverflow = 0;
	LastOptType = (fix_type)0;
	LastOptimized = 0xFFFFFFFF;
}

void ResetLoadPE(void)
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

void ResetLoadNov(void)
{
	DbgInfoCount = 0;
	DbgInfoLen = 0;
}

void ResetDistrib(void)
{
	ArcBuffer = NULL;
	ModTable = NULL;
	SectOvlTab = NULL;
}

void ResetComdef(void)
{
#if 0
	memcpy(CDatSegName, CDAT_SEG_NAME, CDAT_SEG_NAME_LEN);
	CDatSegments[0] = NULL;
	CDatSegments[1] = NULL;
	CDatSegments[2] = NULL;
	CDatSegments[3] = NULL;
	CDatSegNum = 0;
#endif
	CDatList = NULL;
	FreedInfos = NULL;
	FreedPieces = NULL;
}
void ResetOvlSupp(void)
{
	AreaSize = 0xFFFF;
}
void ResetCmdAll(void)
{
	LastFile = NULL;
	LastLibFile = NULL;
	LibPath = NULL;
}
void ResetMapIO(void)
{
	MapFlags = (mapflag)0;
	UndefList = NULL;
	SymTraceList = NULL;
}

void ResetDBI(void)
{
	SymFileName = NULL;
	DBIGroups = NULL;
}
void ResetPermData(MemorySubsystem* memory)
{
	DEBUG(("ResetPermData() enter\n"));
	IncFileName = NULL;
	IncStrTab = NULL;
	ReadRelocs = NULL;
	OldExe = NULL;
	AltDefData = NULL;
	OldSymFile = NULL;
	IncGroupDefs = NULL;
	IncGroups = NULL;
	SavedUserLibs = NULL;
	SavedDefLibs = NULL;
	CarveClass = CarveCreate(memory, sizeof(class_entry), 20 * sizeof(class_entry));
	CarveGroup = CarveCreate(memory, sizeof(group_entry), 20 * sizeof(group_entry));
	CarveDLLInfo = CarveCreate(memory, sizeof(dll_sym_info), 100 * sizeof(dll_sym_info));
	CarveExportInfo = CarveCreate(memory, sizeof(entry_export), 20 * sizeof(entry_export));
	CarveLeader = CarveCreate(memory, sizeof(seg_leader), SEG_CARVE_SIZE);
	CarveModEntry = CarveCreate(memory, sizeof(mod_entry), MOD_CARVE_SIZE);
	CarveSegData = CarveCreate(memory, sizeof(segdata), SDATA_CARVE_SIZE);
	CarveSymbol = CarveCreate(memory, sizeof(symbol), SYM_CARVE_SIZE);
	InitStringTable(memory, &PermStrings, true);
	InitStringTable(memory, &PrefixStrings, true);
	InitStringTable(memory, &StoredRelocs, false);
}

void FlushBuffFile(FileSubsystem* file, MemorySubsystem* memory, outfilelist* outfile)
{
	unsigned    modpos;

	modpos = outfile->bufpos % BUFF_BLOCK_SIZE;
	if (modpos != 0) {
		file->FlushFile(outfile->handle);
	}
	_LnkFree(outfile->buffer);
	outfile->buffer = NULL;
}

void CloseBuffFile(FileSubsystem* file, MemorySubsystem* memory, outfilelist* outfile)
{
	if (outfile->buffer != NULL) {
		FlushBuffFile(file, memory, outfile);
	}
	file->Close(outfile->handle);
	outfile->handle = NIL_HANDLE;
}

void CloseOutFiles(FileSubsystem* file, MemorySubsystem* memory)
{
	outfilelist* fnode;

	for (fnode = OutFiles; fnode != NULL; fnode = fnode->next) {
		if (fnode->handle != NIL_HANDLE) {
			CloseBuffFile(file, memory, fnode);
		}
	}
}

void FreeOutFiles(FileSubsystem* file, MemorySubsystem* memory)
{
	outfilelist* fnode;

	CloseOutFiles(file, memory);
	for (fnode = OutFiles; fnode != NULL; fnode = OutFiles) {
		if (LinkState & LINK_ERROR) {
			file->Delete(fnode->fname);
		}
		_LnkFree(fnode->fname);
		OutFiles = fnode->next;
		_LnkFree(fnode);
	}
}

void FreeList(MemorySubsystem* memory, void* _curr)
{
	node* curr = (node*)_curr;
	node* next_node;

	while (curr) {
		next_node = (node*)curr->next;
		_LnkFree(curr);
		curr = next_node;
	}
}

void CleanPermData(MessagingSubsystem* msg, MemorySubsystem* memory, FileSubsystem* file)
{
#ifndef _DEBUG
	if (!(LinkFlags & INC_LINK_FLAG)) {
		CarveVerifyAllGone(msg, file, CarveLeader, "seg_leader");
		CarveVerifyAllGone(msg, file, CarveModEntry, "mod_entry");
		CarveVerifyAllGone(msg, file, CarveDLLInfo, "dll_sym_info");
		CarveVerifyAllGone(msg, file, CarveExportInfo, "entry_export");
		CarveVerifyAllGone(msg, file, CarveSymbol, "symbol");
		CarveVerifyAllGone(msg, file, CarveSegData, "segdata");
		CarveVerifyAllGone(msg, file, CarveClass, "class_entry");
		CarveVerifyAllGone(msg, file, CarveGroup, "group_entry");
	}
#endif
	if (LinkState & LINK_ERROR) {
		file->Delete(IncFileName);
	}
	CarveDestroy(memory, CarveLeader);
	CarveDestroy(memory, CarveModEntry);
	CarveDestroy(memory, CarveDLLInfo);
	CarveDestroy(memory, CarveExportInfo);
	CarveDestroy(memory, CarveSymbol);
	CarveDestroy(memory, CarveSegData);
	CarveDestroy(memory, CarveClass);
	CarveDestroy(memory, CarveGroup);
	FiniStringTable(memory, &PrefixStrings);
	FiniStringTable(memory, &PermStrings);
	FiniStringTable(memory, &StoredRelocs);
	_LnkFree(IncFileName);
	_LnkFree(IncStrTab);
	_LnkFree(ReadRelocs);
	_LnkFree(OldExe);
	_LnkFree(OldSymFile);
	_LnkFree(AltDefData);
	RingFree(memory, &IncGroupDefs);
	_LnkFree(IncGroups);
	FreeList(memory, SavedUserLibs);
	FreeList(memory, SavedDefLibs);
}

void LnkMemInit(void)
{
#ifdef _INT_DEBUG
	Chunks = 0;
#endif
}

void LnkMemFini(void)
{
}

void InitCmdFile(void)
{
	PrevCommand = NULL;
}

void LnkFilesInit(void)
{
	OpenFiles = 0;
	CaughtBreak = false;
	_setmode(_fileno(stdin), O_BINARY);
	_setmode(_fileno(stdout), O_BINARY);
}

int InitMsg(void)
{
	BannerPrinted = false;
	return(EXIT_SUCCESS);
}

static nodearray* MakeArray(MemorySubsystem* memory, unsigned size)
{
	_ChkAlloc2(nodearray*, nodes, sizeof(nodearray));
	nodes->num = 0;
	nodes->elsize = size;
	nodes->arraymax = 0;
	size *= NODE_ARRAY_SIZE;
	_ChkAlloc(char*, nodes->array[0], size);
	memset(nodes->array[0], 0, size);
	return(nodes);
}

void InitNodes(MemorySubsystem* memory)
{
	GrpNodes = MakeArray(memory, sizeof(grpnode));
	SegNodes = MakeArray(memory, sizeof(segnode));
	ExtNodes = MakeArray(memory, sizeof(extnode));
	NameNodes = MakeArray(memory, sizeof(list_of_names*));
}

static void BurnNodeArray(MemorySubsystem* memory, nodearray* list)
{
	for (int index = 0; index <= list->arraymax; index++) {
		_LnkFree(list->array[index]);
	}
	_LnkFree(list);
}

void BurnNodes(MemorySubsystem* memory)
{
	BurnNodeArray(memory, GrpNodes);
	BurnNodeArray(memory, SegNodes);
	BurnNodeArray(memory, ExtNodes);
	BurnNodeArray(memory, NameNodes);
}

void InitTokBuff(MemorySubsystem* memory)
{
	TokSize = MAX_HEADROOM;
	_ChkAlloc(char*, TokBuff, MAX_HEADROOM);
}

void FreeTokBuffs(MemorySubsystem* memory)
{
	if (TokBuff != NULL) {
		_LnkFree(TokBuff);
		TokBuff = NULL;
	}
}

void InitSpillFile(void)
{
	TempFile = NIL_HANDLE;
	TFileName = NULL;
	TmpFSize = 0;
	//SetBreak();
}

void InitSym(MemorySubsystem* memory)
{
	_ChkAlloc(symbol**, GlobalSymPtrs, GLOBAL_TABALLOC);
	_ChkAlloc(symbol**, StaticSymPtrs, STATIC_TABALLOC);
}

void FiniSym(MemorySubsystem* memory)
{
	_LnkFree(GlobalSymPtrs);
	_LnkFree(StaticSymPtrs);
}

void CacheFini(void)
{
}

long ORLSeek(void* _list, long pos, int where)
{
	file_list* list = (file_list*)_list;

	if (where == SEEK_SET) {
		ORLFilePos = pos;
	}
	else if (where == SEEK_CUR) {
		ORLFilePos += pos;
	}
	else {
		ORLFilePos = list->file->len - pos;
	}
	return(ORLFilePos);
}

void* CachePermRead(file_list* list, unsigned long pos, unsigned len)
{
	return CacheRead(list, pos, len);
}

void* CacheRead(file_list* list, unsigned long pos, unsigned len)
{
	if (pos + len > list->file->len) return NULL;
	return (char*)list->file->cache + pos;
}

void* ORLRead(MemorySubsystem* memory, void* _list, size_t len)
{
	file_list* list = (file_list*)_list;
	void* result;
	readcache* cache;

	result = CachePermRead(list, ORLFilePos, len);
	ORLFilePos += len;
	_ChkAlloc(readcache*, cache, sizeof(readcache));
	cache->next = ReadCacheList;
	ReadCacheList = cache;
	cache->data = result;
	return(result);
}

void InitObjORL(MemorySubsystem* mem)
{
	ORLFuncs = { ORLRead, ORLSeek, mem };
	ORLHandle = ORLInit(&ORLFuncs);
	ReadCacheList = NULL;
}

void ObjORLFini(void)
{
	ORLFini(ORLHandle);
}

void FiniLinkStruct(MemorySubsystem* memory)
{
	BurnNodes(memory);
	FreeTokBuffs(memory);
	CacheFini();
	ObjORLFini();
}

int FiniMsg(void)
{
	return(EXIT_SUCCESS);
}

void GetSymBlock(void)
{
	PermBlocks.list = NULL;
}

int ARCompName(const void* key, const void* vbase)
{
	char** base;

	base = (char**)vbase;
	return strcmp((char*)key, *base);
}

int ARCompIName(const void* key, const void* vbase)
{
	char** base;

	base = (char**)vbase;
	return _stricmp((char*)key, *base);
}

void SetLibCase(void)
{
	if (LinkFlags & CASE_FLAG) {
		CmpOMFRtn = memcmp;
		CmpARRtn = ARCompName;
	}
	else {
		CmpOMFRtn = _memicmp;
		CmpARRtn = ARCompIName;
	}
}

void ClearHashPointers(void)
{
	memset(GlobalSymPtrs, 0, GLOBAL_TABSIZE * sizeof(symbol*));
	memset(StaticSymPtrs, 0, STATIC_TABSIZE * sizeof(symbol*));
}

void SetSymCase(void)
{
	if (LinkFlags & CASE_FLAG) {
		CmpRtn = memcmp;
	}
	else {
		CmpRtn = _memicmp;
	}
}

void ResetSym(void)
{
	NameLen = 0;
	SymList = NULL;
	HeadSym = NULL;
	LastSym = NULL;
	CmpRtn = _memicmp;
	GetSymBlock();
	ClearHashPointers();
}

void ResetMisc(void)
{
	/* jwlink: default is: multiple defines are NOT ok */
	//LinkFlags = REDEFS_OK | CASE_FLAG | FAR_CALLS_FLAG;
	LinkFlags = CASE_FLAG | FAR_CALLS_FLAG;
	LinkState = MAKE_RELOCS;
	AbsGroups = NULL;
	DataGroup = NULL;
	IDataGroup = NULL;
	MapFile = NIL_HANDLE;
	MapFName = NULL;
	OutFiles = NULL;
	ObjLibFiles = NULL;
	LibModules = NULL;
	Groups = NULL;
	CurrLoc.seg = UNDEFINED;
	CurrLoc.off = 0;
	OvlClasses = NULL;
	OvlVectors = NULL;
	VecNum = 0;
	OvlNum = 0;
	OvlFName = NULL;
	CurrMod = NULL;
	StackSize = 0x1000;
	// set case sensitivity for symbols
	ResetSym();
	SetSymCase();
	SetLibCase();
}

int stricmp_wrapper(const void* s1, const void* s2)
{
	return(_stricmp((char*)s1, (char*)s2));
}

section* NewSection(MemorySubsystem* memory)
{
	section* sect;

	OvlNum++;
	_ChkAlloc(section*, sect, sizeof(section));
	sect->next_sect = NULL;
	sect->classlist = NULL;
	sect->orderlist = NULL;
	sect->areas = NULL;
	sect->files = NULL;
	sect->modFilesHashed = CreateHTable(memory, 256, StringiHashFunc, stricmp_wrapper);
	sect->mods = NULL;
	sect->reloclist = NULL;
	sect->sect_addr.off = 0;
	sect->sect_addr.seg = UNDEFINED;
	sect->ovl_num = 0;
	sect->parent = NULL;
	sect->relocs = 0;
	sect->size = 0;
	sect->outfile = NULL;
	sect->u.dist_mods = NULL;
	sect->dbg_info = NULL;
	return(sect);
}

void CleanSystemList(MemorySubsystem* memory, bool check)
{
	sysblock** sys;
	sysblock* next;
	char* name;

	sys = &SysBlocks;
	while (*sys != NULL) {
		name = (*sys)->name;
		if (!check
			|| (memcmp("286", name, 4) != 0 && memcmp("386", name, 4) != 0)) {
			next = (*sys)->next;
			_LnkFree(name);
			_LnkFree(*sys);
			*sys = next;
		}
		else {
			sys = &(*sys)->next;
		}
	}
}

void BurnSystemList(MemorySubsystem* memory)
{
	CleanSystemList(memory, false);
}

void FreeFormatStuff(MemorySubsystem* memory, MessagingSubsystem* msg)
{
	int i;
	exe_format                  possible;

	CmdLine* cmdLine = new CmdLine(memory, msg);
	if (!(LinkState & FMT_DECIDED)) return;
	for (i = 0; i < 11; i++) {
		select_format* sf = cmdLine->getPossibleFormat(i);
		possible = sf->bits;
		if ((~possible & FmtData.type) == 0) {
			if (sf->platform != NULL)
				sf->platform->freeFormat();
			break;
		}
	}
}

void FreeNodes(nodearray* nodes)
{
	unsigned    index;

	for (index = 0; index <= nodes->arraymax; index++) {
		memset(nodes->array[index], 0, nodes->elsize * NODE_ARRAY_SIZE);
	}
	nodes->num = 0;
}

void FreeObjInfo(void)
{
	FreeNodes(ExtNodes);
	FreeNodes(SegNodes);
	FreeNodes(GrpNodes);
}

void FreeVirtMem(MemorySubsystem* memory)
{
	FreeList(memory, VMemBlocks);
	VMemBlocks = NULL;
}

void CleanToc(MemorySubsystem* memory)
{
	ZapHTable(memory, Toc);
}

void FreeImport(MessagingSubsystem* msg,dll_sym_info* dll)
{
	CarveFree(msg, CarveDLLInfo, dll);
}

void WipeSym(MessagingSubsystem* msg, MemorySubsystem* memory, symbol* sym)
{
	if (IS_SYM_IMPORTED(sym) && !(FmtData.type & MK_ELF)) {
		if (FmtData.type & MK_NOVELL) {
			if (sym->p.import != DUMMY_IMPORT_PTR) {
				_LnkFree(sym->p.import);
			}
		}
		else {
			FreeImport(msg, (dll_sym_info*)sym->p.import);
		}
		sym->p.import = NULL;
	}
	else if (IS_SYM_ALIAS(sym)) {
		if (sym->info & SYM_FREE_ALIAS) {
			_LnkFree(sym->p.alias);
		}
		sym->u.aliaslen = 0;    // make sure this is nulled again
	}
}

void FreeSymbol(MessagingSubsystem* msg, MemorySubsystem* memory, symbol* sym)
{
	WipeSym(msg, memory, sym);
	CarveFree(msg, CarveSymbol, sym);
}

void RelSymBlock(MemorySubsystem* memory)
{
	FreeList(memory, PermBlocks.list);
	PermBlocks.list = NULL;
}

void CleanSym(MessagingSubsystem* msg, MemorySubsystem* memory)
{
	symbol* sym;
	symbol* next;

#ifdef _INT_DEBUG
	DumpHashTable();
#endif
	if (!(LinkFlags & INC_LINK_FLAG)) {
		for (sym = HeadSym; sym != NULL; sym = next) {
			next = sym->link;
			FreeSymbol(msg, memory, sym);
		}
	}
	RelSymBlock(memory);
	ReleasePass1(memory);
}

