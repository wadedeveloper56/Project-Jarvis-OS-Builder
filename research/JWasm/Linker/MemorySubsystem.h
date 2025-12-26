#pragma once

#define _ChkAlloc( cast, dest, size ) dest = (cast)memory->ChkLAlloc( size )
#define _LnkAlloc( cast, dest, size ) dest = (cast)memory->LAlloc( size )
#define _LnkReAlloc( cast, dest, src, size ) dest = (cast)memory->ReallocateMemory( src, size );
#define _LnkFree( ptr )         memory->FreeMemory( ptr )
#define _LnkExpand( cast, dest, src, size ) dest = (cast)memory->ExpandMemory( src, size );

class MessagingSubsystem;

class MemorySubsystem
{
	MessagingSubsystem* msg;
public:
	MemorySubsystem(MessagingSubsystem* msg);
	~MemorySubsystem();
	void* ReallocateMemory(void* memblock, size_t size);
	void FreeMemory(void* memoryBlock);
	void* ExpandMemory(void* memblock, size_t size);
	void DbgZapAlloc(void* tgt, size_t size);
	void DbgZapFreed(void* tgt, size_t size);
	void* LAlloc(size_t size);
	void* ChkLAlloc(size_t size);
private:
	void* AllocateMemory(size_t size);
};

