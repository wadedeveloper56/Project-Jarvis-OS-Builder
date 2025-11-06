#pragma once

#define MAX_NUM_NODES   128

typedef struct readcache {
	readcache* next;
	void* data;
} readcache;

typedef struct nodearray {
	unsigned    num;            // number of nodes inserted
	unsigned    elsize;         // size of individual element in array.
	unsigned    arraymax;       // the number of node arrays allocated - 1
	char* array[MAX_NUM_NODES];   // the array.
} nodearray;