#include "pch.h"
#include "linkstd.h"
#include "alloc.h"
#include "msg.h"
#include "wlnkmsg.h"
#include "linkutil.h"
#include "distrib.h"
#include "wcomdef.h"
#include "strtab.h"
#include "carve.h"
#include "permdata.h"
#include "objnode.h"

#define NODE_ARRAY_SIZE 256
#define MAX_NUM_NODES   128
#define NEED_NEW_ARRAY( x ) (!((x) & 0xFF))
#define ARRAY_NUM( x )      ((x) >> 8 )
#define ELEMENT_NUM( x )    ((x) & 0xFF)

typedef struct nodearray {
	unsigned    num;            // number of nodes inserted
	unsigned    elsize;         // size of individual element in array.
	unsigned    arraymax;       // the number of node arrays allocated - 1
	char* array[MAX_NUM_NODES];   // the array.
} nodearray;

nodearray* ExtNodes;           // ptr to obj file import list
nodearray* SegNodes;           // ptr to obj file segment list
nodearray* GrpNodes;           // ptr to obj file group list
nodearray* NameNodes;          // ptr to obj file lname list

static void BurnNodeArray(nodearray* list)
{
	int index;

	for (index = 0; index <= list->arraymax; index++) {
		_LnkFree(list->array[index]);
	}
	_LnkFree(list);
}

void BurnNodes(void)
{
	BurnNodeArray(GrpNodes);
	BurnNodeArray(SegNodes);
	BurnNodeArray(ExtNodes);
	BurnNodeArray(NameNodes);
}

static void* MakeArray(unsigned size)
{
	nodearray* nodes;

	_ChkAlloc(nodearray*, nodes, sizeof(nodearray));
	nodes->num = 0;
	nodes->elsize = size;
	nodes->arraymax = 0;
	size *= NODE_ARRAY_SIZE;
	_ChkAlloc(char*, nodes->array[0], size);
	memset(nodes->array[0], 0, size);
	return(nodes);
}

void InitNodes(void)
{
	GrpNodes = (nodearray*)MakeArray(sizeof(grpnode));
	SegNodes = (nodearray*)MakeArray(sizeof(segnode));
	ExtNodes = (nodearray*)MakeArray(sizeof(extnode));
	NameNodes = (nodearray*)MakeArray(sizeof(list_of_names*));
}