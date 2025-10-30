#include "pch.h"
#include "mem.h"
#include "objnode.h"

nodearray* ExtNodes;           // ptr to obj file import list
nodearray* SegNodes;           // ptr to obj file segment list
nodearray* GrpNodes;           // ptr to obj file group list
nodearray* NameNodes;          // ptr to obj file lname list

void* MakeArray(unsigned size)
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