#pragma once

class LinkerMemory
{
public:
	LinkerMemory();
	~LinkerMemory();
	void* alloc(uint64_t size);
	void free(void* mem);
};

