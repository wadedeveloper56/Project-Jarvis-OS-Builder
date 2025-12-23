#pragma once

#define _ChkAlloc( cast, dest, size ) dest = (cast)memory->AllocateMemory( size )
#define _LnkAlloc( cast, dest, size ) dest = (cast)memory->AllocateMemory( size )
#define _LnkReAlloc( cast, dest, src, size ) dest = (cast)memory->ReallocateMemory( src, size );
#define _LnkFree( ptr )         memory->FreeMemory( ptr )
#define _PermFree( ptr )        /* nothing to do */
#define _LnkExpand( cast, dest, src, size ) dest = (cast)memory->ExpandMemory( src, size );

class MemorySubsystem
{
public:
	MemorySubsystem();
	~MemorySubsystem();
	static void* AllocateMemory(size_t size);
	static void FreeMemory(void* memoryBlock);
	void* ReallocateMemory(void* memblock, size_t size);
	void* ExpandMemory(void* memblock, size_t size);
	void DbgZapAlloc(void* tgt, size_t size);
	void DbgZapFreed(void* tgt, size_t size);
	void* LAlloc(size_t size);
	void* ChkLAlloc(size_t size);
};

