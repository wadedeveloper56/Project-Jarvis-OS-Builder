#include "alink.h"

char case_sensitive = 1;
char padsegments = 0;
char mapfile = 0;
char* mapname = 0;
unsigned short maxalloc = 0xffff;
int output_type = OUTPUT_EXE;
char* outname = 0;
FILE* afile = 0;
unsigned int  filepos = 0;
long reclength = 0;
unsigned char rectype = 0;
char li_le = 0;
unsigned int  prevofs = 0;
long prevseg = 0;
long gotstart = 0;
Reloc startaddr;
unsigned int  imageBase = 0;
unsigned int  fileAlign = 1;
unsigned int  objectAlign = 1;
unsigned int  stackSize;
unsigned int  stackCommitSize;
unsigned int  heapSize;
unsigned int  heapCommitSize;
unsigned char osMajor, osMinor;
unsigned char subsysMajor, subsysMinor;
unsigned int subSystem;
int buildDll = FALSE;
unsigned char* stubName = NULL;
long errcount = 0;
unsigned char buf[65536];
DataBlockPtr lidata;
char** namelist = NULL;
SegPtrPtr seglist = NULL;
SegPtrPtr outlist = NULL;
GrpPtrPtr grplist = NULL;
SortEntryPtr publics = NULL;
ExtRecPtr externs = NULL;
ComRecPtrPtr comdefs = NULL;
RelocPtrPtr relocs = NULL;
ImpRecPtr impdefs = NULL;
ExpRecPtr expdefs = NULL;
LibFilePtr libfiles = NULL;
ResourcePtr resource = NULL;
SortEntryPtr comdats = NULL;
char** modname;
char** filename;
unsigned int  namecount = 0, namemin = 0,
pubcount = 0, pubmin = 0,
segcount = 0, segmin = 0, outcount = 0,
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
unsigned int  libPathCount = 0;
char** libPath = NULL;
char* entryPoint = NULL;

