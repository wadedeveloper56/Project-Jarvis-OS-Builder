#include "pch.h"
#include "MessagingSubsystem.h"
#include "MemorySubsystem.h"
#include "Memory.h"

MemorySubsystem::MemorySubsystem(MessagingSubsystem* msg)
{
    this->msg = msg;
}

MemorySubsystem::~MemorySubsystem()
{
}

void* MemorySubsystem::AllocateMemory(size_t size)
{
	return ::AllocateMemory(size);
}

void MemorySubsystem::FreeMemory(void* memoryBlock)
{
	::FreeMemory(memoryBlock);
}

void* MemorySubsystem::ReallocateMemory(void* memblock, size_t size)
{
	return ::ReallocateMemory(memblock, size);
}	

void* MemorySubsystem::ExpandMemory(void* memblock, size_t size)
{
	return ::ExpandMemory(memblock, size);
}

void MemorySubsystem::DbgZapAlloc(void* tgt, size_t size)
{
	memset(tgt, 0xA5, size);
}

void MemorySubsystem::DbgZapFreed(void* tgt, size_t size)
{
	memset(tgt, 0xBD, size);
}

void* MemorySubsystem::LAlloc(size_t size)
{
    void* p;

    for (;; ) {
        p = AllocateMemory(size);
        if (p != NULL) {
            break;
        }
    }
    return(p);
}

void* MemorySubsystem::ChkLAlloc(size_t size)
{
    void* ptr;
    ptr = LAlloc(size);
    if (ptr == NULL) {
        msg->LnkMsg(FTL + MSG_NO_DYN_MEM, NULL);
    }
    return(ptr);
}

