#include "ALink.h"

char case_sensitive = 1;
char padsegments = 0;
char mapfile = 0;
PCHAR mapname = 0;
unsigned short maxalloc = 0xffff;
int output_type = OUTPUT_EXE;
PCHAR outname = 0;

FILE* afile = 0;
UINT filepos = 0;
long reclength = 0;
unsigned char rectype = 0;
char li_le = 0;
UINT prevofs = 0;
long prevseg = 0;
long gotstart = 0;
RELOC startaddr;
UINT imageBase = 0;
UINT fileAlign = 1;
UINT objectAlign = 1;
UINT stackSize;
UINT stackCommitSize;
UINT heapSize;
UINT heapCommitSize;
unsigned char osMajor, osMinor;
unsigned char subsysMajor, subsysMinor;
unsigned int subSystem;
bool buildDll = false;
PUCHAR stubName = NULL;

long errcount = 0;

unsigned char buf[65536];
PDATABLOCK lidata;

PPCHAR namelist = NULL;
PPSEG seglist = NULL;
PPSEG outlist = NULL;
PPGRP grplist = NULL;
PSORTENTRY publics = NULL;
PEXTREC externs = NULL;
PPCOMREC comdefs = NULL;
PPRELOC relocs = NULL;
PIMPREC impdefs = NULL;
PEXPREC expdefs = NULL;
PLIBFILE libfiles = NULL;
PRESOURCE resource = NULL;
PSORTENTRY comdats = NULL;
PPCHAR modname;
PPCHAR filename;
UINT namecount = 0, namemin = 0,
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
UINT libPathCount = 0;
PCHAR* libPath = NULL;
char* entryPoint = NULL;
char t_thred[4];
char f_thred[4];
int t_thredindex[4];
int f_thredindex[4];