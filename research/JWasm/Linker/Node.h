#pragma once

#include <cstring>
#include "MemorySubsystem.h"
#include "structures.h"

#define NODE_ARRAY_SIZE 256
#define MAX_NUM_NODES   128
#define NEED_NEW_ARRAY( x ) (!((x) & 0xFF))
#define ARRAY_NUM( x )      ((x) >> 8 )
#define ELEMENT_NUM( x )    ((x) & 0xFF)

typedef struct _NodeArray {
	unsigned    num;            // number of nodes inserted
	unsigned    elsize;         // size of individual element in array.
	unsigned    arraymax;       // the number of node arrays allocated - 1
	char* array[MAX_NUM_NODES];   // the array.
} NodeArray, * NodeArrayPtr, ** NodeArrayPtrPtr;

class Node
{
	MemorySubsystem* memory;
	NodeArrayPtr ExtNodes;           // ptr to obj file import list
	NodeArrayPtr SegNodes;           // ptr to obj file segment list
	NodeArrayPtr GrpNodes;           // ptr to obj file group list
	NodeArrayPtr NameNodes;          // ptr to obj file lname list
public:
	Node(MemorySubsystem* memory);
	~Node();
private:
	NodeArrayPtr MakeArray(unsigned size);
	void BurnNodeArray(NodeArrayPtr list);
};

