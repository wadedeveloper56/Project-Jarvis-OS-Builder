#include "pch.h"
#include "objnode.h"
#include "alloc.h"
#include "objstruct.h"

nodearray* ExtNodes;           // ptr to obj file import list
nodearray* SegNodes;           // ptr to obj file segment list
nodearray* GrpNodes;           // ptr to obj file group list
nodearray* NameNodes;          // ptr to obj file lname list

static nodearray* MakeArray(unsigned size)
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
	GrpNodes = MakeArray(sizeof(grpnode));
	SegNodes = MakeArray(sizeof(segnode));
	ExtNodes = MakeArray(sizeof(extnode));
	NameNodes = MakeArray(sizeof(list_of_names*));
}

static void BurnNodeArray(nodearray* list)
{
	for (int index = 0; index <= list->arraymax; index++) {
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

