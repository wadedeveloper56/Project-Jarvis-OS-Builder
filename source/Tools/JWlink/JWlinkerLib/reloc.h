#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "Structs.h"
#include "SpillFile.h"

using namespace std;

void ResetReloc();
reloc_info* AllocRelocInfo(MemorySubsystem *memorySubsystem, SpillFile * spillFile);
void* OS2PagedRelocInit(MemorySubsystem *memorySubsystem, offset size, int unitsize);
void* OS2FlatRelocInit(MemorySubsystem *memorySubsystem, offset size);
void* PERelocInit(MemorySubsystem *memorySubsystem, offset size);
void DoWriteReloc(MemorySubsystem *memorySubsystem, SpillFile * spillFile, void* lst, void* reloc, unsigned size);
void WriteReloc(MemorySubsystem *memorySubsystem, SpillFile * spillFile, group_entry* group, offset off, void* reloc, unsigned size);
#ifdef _QNXLOAD
void FloatReloc(MemorySubsystem *memorySubsystem, SpillFile * spillFile, reloc_item* item);
void QNXLinearReloc(MemorySubsystem *memorySubsystem, SpillFile * spillFile, group_entry* group, reloc_item* item);
#endif
bool FreeRelocList(MemorySubsystem *memorySubsystem, SpillFile * spillFile, reloc_info* list);
void FreeRelocSect(MemorySubsystem *memorySubsystem, SpillFile * spillFile, section* sect);
bool TraverseRelocBlock(MemorySubsystem *memorySubsystem, SpillFile * spillFile, reloc_info** reloclist, unsigned num, bool (*fn)(MemorySubsystem *, SpillFile *, reloc_info*));
bool TraverseOS2RelocList(MemorySubsystem *memorySubsystem, SpillFile * spillFile, group_entry* group, bool (*fn)(MemorySubsystem *, SpillFile *, reloc_info*));
void FreeGroupRelocs(MemorySubsystem *memorySubsystem, SpillFile * spillFile, group_entry* group);
void WalkAllSects(MemorySubsystem *memorySubsystem, SpillFile * spillFile, void (*rtn)(MemorySubsystem *, SpillFile *, section*));
void FreeRelocInfo(MemorySubsystem *memorySubsystem, SpillFile * spillFile);
uint32_t RelocSize(reloc_info* list);
uint32_t DumpMaxRelocList(SpillFile * spillFile, reloc_info** head, uint32_t max);
bool DumpRelocList(SpillFile * spillFile, reloc_info* list);
uint32_t WalkRelocList(SpillFile * spillFile, reloc_info** head, bool (*fn)(void* data, uint32_t size, void* ctx), void* ctx);
void SetRelocSize();
bool SpillRelocList(MemorySubsystem *memorySubsystem, SpillFile * spillFile, reloc_info* list);
bool SpillSections(MemorySubsystem *memorySubsystem, SpillFile * spillFile, section* sect);
bool SpillAreas(MemorySubsystem *memorySubsystem, SpillFile * spillFile, OVL_AREA* ovl);
bool SwapOutRelocs(MemorySubsystem *memorySubsystem, SpillFile * spillFile);