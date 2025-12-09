#pragma once

#include "objstruct.h"

void FiniLinkStruct(void);
void FreeModEntry(mod_entry* mod);
void CleanLinkStruct(void);
void FreeGroups(group_entry* head);
void FreeAMod(mod_entry* mod);
void FreeSegFlags(seg_flags* curr);
