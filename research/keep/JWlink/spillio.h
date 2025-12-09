#pragma once

void InitSpillFile(void);
void CloseSpillFile(void);
unsigned long SpillAlloc(unsigned amt);
void SpillWrite(unsigned long base, unsigned off, void* mem, unsigned size);
void SpillRead(unsigned long base, unsigned off, void* mem, unsigned size);

