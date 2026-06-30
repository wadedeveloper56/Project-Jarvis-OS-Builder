#include "pch.h"
#include "MemorySubsystem.h"
//#include "linkstd.h"
//#include "objnode.h"
#include "ObjectNode.h"
#include "Structs.h"

using namespace std;

nodearray* ExtNodes;           // ptr to obj file import list
nodearray* SegNodes;           // ptr to obj file segment list
nodearray* GrpNodes;           // ptr to obj file group list
nodearray* NameNodes;          // ptr to obj file lname list

void* MakeArray(MemorySubsystem *memorySubsystem, unsigned size)
{
	nodearray* nodes = (nodearray*)memorySubsystem->AllocateMemory(sizeof(nodearray));
	nodes->num = 0;
	nodes->elsize = size;
	nodes->arraymax = 0;
	size *= NODE_ARRAY_SIZE;
	nodes->array[0] = (char*)memorySubsystem->AllocateMemory(size);
	memset(nodes->array[0], 0, size);
	return(nodes);
}

void InitNodes(MemorySubsystem *memorySubsystem)
{
	GrpNodes = (nodearray*)MakeArray(memorySubsystem, sizeof(grpnode));
	SegNodes = (nodearray*)MakeArray(memorySubsystem, sizeof(segnode));
	ExtNodes = (nodearray*)MakeArray(memorySubsystem, sizeof(extnode));
	NameNodes = (nodearray*)MakeArray(memorySubsystem, sizeof(list_of_names*));
}

void BurnNodeArray(MemorySubsystem *memorySubsystem, nodearray* list)
{
	for (int index = 0; index <= list->arraymax; index++)
	{
		memorySubsystem->FreeMemory(list->array[index]);
	}
	memorySubsystem->FreeMemory(list);
}

void BurnNodes(MemorySubsystem *memorySubsystem)
{
	BurnNodeArray(memorySubsystem, GrpNodes);
	BurnNodeArray(memorySubsystem, SegNodes);
	BurnNodeArray(memorySubsystem, ExtNodes);
	BurnNodeArray(memorySubsystem, NameNodes);
}
