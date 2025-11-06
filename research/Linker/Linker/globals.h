#pragma once

#include <fstream>
using namespace std;

#define LINK_ERROR              0x00000008

#define NODE_ARRAY_SIZE 256
#define MAX_HEADROOM    (4*1024)

#include "types.h"
#include "nodes.h"
#include "objstruc.h"

#define STATIC_TABALLOC (256 * sizeof(symbol *))  // 1st power of 128 > TABSIZE
#define GLOBAL_TABALLOC (1792 * sizeof(symbol *)) // 1st power of 128 > TABSIZE

typedef unsigned long stateflag;

extern stateflag LinkState;
extern nodearray* ExtNodes;           // ptr to obj file import list
extern nodearray* SegNodes;           // ptr to obj file segment list
extern nodearray* GrpNodes;           // ptr to obj file group list
extern nodearray* NameNodes;;         // ptr to obj file lname list
extern char* TokBuff;                 // Multi-purpose large buffer
extern unsigned TokSize;
extern char* TFileName;
extern unsigned long    TmpFSize;
extern fstream* TempFile;
extern symbol** GlobalSymPtrs;
extern symbol** StaticSymPtrs;
extern readcache* ReadCacheList;
