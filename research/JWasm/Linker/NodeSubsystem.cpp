#include "NodeSubsystem.h"

NodeSubsystem::NodeSubsystem(MemorySubsystem* memory)
{
	this->memory = memory;
	GrpNodes = MakeArray(sizeof(grpnode));
	SegNodes = MakeArray(sizeof(segnode));
	ExtNodes = MakeArray(sizeof(extnode));
	NameNodes = MakeArray(sizeof(list_of_names*));
}

NodeSubsystem::~NodeSubsystem()
{
	BurnNodeArray(GrpNodes);
	BurnNodeArray(SegNodes);
	BurnNodeArray(ExtNodes);
	BurnNodeArray(NameNodes);
}

NodeArrayPtr NodeSubsystem::MakeArray(unsigned size)
{
	NodeArrayPtr nodes = (NodeArrayPtr)memory->AllocateMemory(sizeof(NodeArray));
	nodes->num = 0;
	nodes->elsize = size;
	nodes->arraymax = 0;
	size *= NODE_ARRAY_SIZE;
	nodes->array[0] = (char*)memory->AllocateMemory(size);
	memset(nodes->array[0], 0, size);
	return(nodes);
}

void NodeSubsystem::BurnNodeArray(NodeArrayPtr list)
{
	for (int index = 0; index <= list->arraymax; index++) {
		memory->FreeMemory(list->array[index]);
	}
	memory->FreeMemory(list);
}
