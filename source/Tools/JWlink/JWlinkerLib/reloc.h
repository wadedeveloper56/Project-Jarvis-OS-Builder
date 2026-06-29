#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "Structs.h"
#include "SpillFile.h"

using namespace std;

void ResetReloc(void);
reloc_info* AllocRelocInfo(shared_ptr<MemorySubsystem> memorySubsystem, shared_ptr<SpillFile> spillFile);
void* OS2PagedRelocInit(shared_ptr<MemorySubsystem> memorySubsystem, offset size, int unitsize);
void* OS2FlatRelocInit(shared_ptr<MemorySubsystem> memorySubsystem, offset size);
void* PERelocInit(shared_ptr<MemorySubsystem> memorySubsystem, offset size);
void DoWriteReloc(shared_ptr<MemorySubsystem> memorySubsystem, shared_ptr<SpillFile> spillFile, void* lst, void* reloc, unsigned size);
void WriteReloc(shared_ptr<MemorySubsystem> memorySubsystem, shared_ptr<SpillFile> spillFile, group_entry* group, offset off, void* reloc, unsigned size);
#ifdef _QNXLOAD
void FloatReloc(reloc_item* item);
void QNXLinearReloc(group_entry* group, reloc_item* item);
#endif
bool FreeRelocList(shared_ptr<MemorySubsystem> memorySubsystem, shared_ptr<SpillFile> spillFile, reloc_info* list);
void FreeRelocSect(shared_ptr<MemorySubsystem> memorySubsystem, shared_ptr<SpillFile> spillFile, section* sect);
bool TraverseRelocBlock(shared_ptr<MemorySubsystem> memorySubsystem, shared_ptr<SpillFile> spillFile, reloc_info** reloclist, unsigned num, bool (*fn)(shared_ptr<MemorySubsystem>, shared_ptr<SpillFile>, reloc_info*));
bool TraverseOS2RelocList(shared_ptr<MemorySubsystem> memorySubsystem, shared_ptr<SpillFile> spillFile, group_entry* group, bool (*fn)(shared_ptr<MemorySubsystem>, shared_ptr<SpillFile>, reloc_info*));
void FreeGroupRelocs(shared_ptr<MemorySubsystem> memorySubsystem, shared_ptr<SpillFile> spillFile, group_entry* group);
void WalkAllSects(shared_ptr<MemorySubsystem> memorySubsystem, shared_ptr<SpillFile> spillFile, void (*rtn)(shared_ptr<MemorySubsystem>, shared_ptr<SpillFile>, section*));
void FreeRelocInfo(shared_ptr<MemorySubsystem> memorySubsystem, shared_ptr<SpillFile> spillFile);
uint32_t RelocSize(reloc_info* list);
uint32_t DumpMaxRelocList(shared_ptr<SpillFile> spillFile, reloc_info** head, uint32_t max);
bool DumpRelocList(shared_ptr<SpillFile> spillFile, reloc_info* list);
uint32_t WalkRelocList(shared_ptr<SpillFile> spillFile, reloc_info** head, bool (*fn)(void* data, uint32_t size, void* ctx), void* ctx);
void SetRelocSize(void);
bool SpillRelocList(shared_ptr<MemorySubsystem> memorySubsystem, shared_ptr<SpillFile> spillFile, reloc_info* list);
bool SpillSections(shared_ptr<MemorySubsystem> memorySubsystem, shared_ptr<SpillFile> spillFile, section* sect);
bool SpillAreas(shared_ptr<MemorySubsystem> memorySubsystem, shared_ptr<SpillFile> spillFile, OVL_AREA* ovl);
bool SwapOutRelocs(shared_ptr<MemorySubsystem> memorySubsystem, shared_ptr<SpillFile> spillFile);