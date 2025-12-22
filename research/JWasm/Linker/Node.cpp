#include "pch.h"
#include "Node.h"

Node::Node(MemorySubsystem* memory)
{
	this->memory = memory;
	GrpNodes = MakeArray(sizeof(GroupNode));
	SegNodes = MakeArray(sizeof(SegmentNode));
	ExtNodes = MakeArray(sizeof(ExtNode));
	NameNodes = MakeArray(sizeof(ListOfNamesPtr));
}

Node::~Node()
{
	BurnNodeArray(GrpNodes);
	BurnNodeArray(SegNodes);
	BurnNodeArray(ExtNodes);
	BurnNodeArray(NameNodes);
}

NodeArrayPtr Node::MakeArray(unsigned size)
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

void Node::BurnNodeArray(NodeArrayPtr list)
{
	for (unsigned int index = 0; index <= list->arraymax; index++) {
		memory->FreeMemory(list->array[index]);
	}
	memory->FreeMemory(list);
}

void Node::FreeNodes(NodeArrayPtr nodes)
{
	for (unsigned index = 0; index <= nodes->arraymax; index++) {
		memset(nodes->array[index], 0, nodes->elsize * NODE_ARRAY_SIZE);
	}
	nodes->num = 0;
}

void Node::FreeObjInfo(void)
{
	FreeNodes(ExtNodes);
	FreeNodes(SegNodes);
	FreeNodes(GrpNodes);
}