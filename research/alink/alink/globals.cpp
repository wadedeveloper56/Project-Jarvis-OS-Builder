#include "pch.h"
#include "alink.h"

char case_sensitive = 1;
char padSegments = 0;
char mapfile = 0;
CharPtr mapname = 0;
unsigned short maxalloc = 0xffff;
int output_type = OUTPUT_EXE;
CharPtr outname = 0;

FILE* afile = 0;
UInt filepos = 0;
long reclength = 0;
unsigned char rectype = 0;
char li_le = 0;
UInt prevofs = 0;
long prevSeg = 0;
long gotstart = 0;
Reloc startaddr;
UInt imageBase = 0;
UInt fileAlign = 1;
UInt objectAlign = 1;
UInt stackSize;
UInt stackCommitSize;
UInt heapSize;
UInt heapCommitSize;
unsigned char osMajor, osMinor;
unsigned char subsysMajor, subsysMinor;
unsigned int subSystem;
int buildDll = FALSE;
UCharPtr stubName = NULL;

long errcount = 0;

unsigned char buf[65536];
DataBlockPtr lidata;

CharPtrPtr namelist = NULL;
SegPtrPtr Seglist = NULL;
SegPtrPtr outlist = NULL;
GroupPtrPtr grplist = NULL;
SortEntryPtr publics = NULL;
ExtRecPtr externs = NULL;
ComRecPtrPtr comdefs = NULL;
RelocPtrPtr relocs = NULL;
ImpRecPtr impdefs = NULL;
ExpRecPtr expdefs = NULL;
LibraryFilePtr libfiles = NULL;
ResourcePtr resource = NULL;
SortEntryPtr comdats = NULL;
CharPtrPtr modname;
CharPtrPtr filename;
UInt namecount = 0, namemin = 0,
pubcount = 0, pubmin = 0,
Segcount = 0, Segmin = 0, outcount = 0,
grpcount = 0, grpmin = 0,
extcount = 0, extmin = 0,
comcount = 0, commin = 0,
fixcount = 0, fixmin = 0,
impcount = 0, impmin = 0, impsreq = 0,
expcount = 0, expmin = 0,
nummods = 0,
filecount = 0,
libcount = 0,
rescount = 0;
UInt libPathCount = 0;
CharPtr* libPath = NULL;
char* entryPoint = NULL;

