#include "pch.h"
#include "globals.h"
#include "Initialize.h"
#include "orl.h"
#include "debug.h"
#include "carve.h"
#include "stringtable.h"
#include "ring.h"

#define SEG_CARVE_SIZE          (2*1024)
#define MOD_CARVE_SIZE          (5*1024)
#define SDATA_CARVE_SIZE        (16*1024)
#define SYM_CARVE_SIZE          (32*1024)

int ARCompName(const void* key, const void* vbase);
int ARCompIName(const void* key, const void* vbase);
int (*CmpARRtn)(const void*, const void*) = ARCompName;
int (*CmpOMFRtn)(const void*, const void*, unsigned) = memcmp; 
int             (*CmpRtn)(const void*, const void*, size_t);

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
		FlushBuffFile(file, memory,outfile);
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

void FreeList(MemorySubsystem* memory,void* _curr)
{
	node* curr = (node*)_curr;
	node* next_node;

	while (curr) {
		next_node = (node*)curr->next;
		_LnkFree(curr);
		curr = next_node;
	}
}

void CleanPermData(MemorySubsystem* memory)
{
#ifndef _DEBUG
	if (!(LinkFlags & INC_LINK_FLAG)) {
		CarveVerifyAllGone(CarveLeader, "seg_leader");
		CarveVerifyAllGone(CarveModEntry, "mod_entry");
		CarveVerifyAllGone(CarveDLLInfo, "dll_sym_info");
		CarveVerifyAllGone(CarveExportInfo, "entry_export");
		CarveVerifyAllGone(CarveSymbol, "symbol");
		CarveVerifyAllGone(CarveSegData, "segdata");
		CarveVerifyAllGone(CarveClass, "class_entry");
		CarveVerifyAllGone(CarveGroup, "group_entry");
	}
#endif
	if (LinkState & LINK_ERROR) {
		//FIX ME        QDelete(IncFileName);
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
	//FIX ME
	return 0;
}

int ARCompIName(const void* key, const void* vbase)
{
	//FIX ME
	return 0;
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
