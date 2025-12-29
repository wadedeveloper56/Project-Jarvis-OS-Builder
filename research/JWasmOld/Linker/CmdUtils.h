#pragma once

#include "globals.h"
#include "MemorySubsystem.h"
#include "HashTable.h"
#include "MessagingSubsystem.h"

#define PATH_SEP '\\'
#define IS_PATH_SEP( a ) ((a)=='\\' || (a)=='/' || (a)==':')
#define CASE_PATH_SEP   case '\\': case '/': case ':'
#define PATH_LIST_SEP ';'

section* NewSection(MemorySubsystem* memory, HashTable* hashTable);
char* FileName(MemorySubsystem* memory, MessagingSubsystem* msg, char* buff, unsigned len, file_defext etype, bool force);
