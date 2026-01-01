#pragma once

#define _ChkAlloc( cast, dest, size ) dest = (cast)memory->ChkLAlloc( size )
#define _ChkAlloc2( cast, dest, size ) cast dest = (cast)memory->ChkLAlloc( size )
#define _LnkAlloc( cast, dest, size ) dest = (cast)memory->LAlloc( size )
#define _LnkReAlloc( cast, dest, src, size ) dest = (cast)memory->ReallocateMemory( src, size );
#define _LnkFree( ptr )         memory->FreeMemory( ptr )
#define _LnkExpand( cast, dest, src, size ) dest = (cast)memory->ExpandMemory( src, size );

class MemorySubsystem
{
public:
	MemorySubsystem();
	~MemorySubsystem();
	void* AllocateMemory(size_t size);
	void* ReallocateMemory(void* memblock, size_t size);
	void FreeMemory(void* memoryBlock);
	void* ExpandMemory(void* memblock, size_t size);
	void DbgZapAlloc(void* tgt, size_t size);
	void DbgZapFreed(void* tgt, size_t size);
	void* LAlloc(size_t size);
	void* ChkLAlloc(size_t size);
private:
};

