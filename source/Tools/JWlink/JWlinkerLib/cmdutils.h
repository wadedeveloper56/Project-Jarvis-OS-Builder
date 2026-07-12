#pragma once

#include "MemorySubsystem.h"
#include "Structs.h"
#include "MessagingSubsystem.h"
#include "FileSubsystem.h"
#include "cmdline.h"

#define IS_WHITESPACE(ptr) (*(ptr) == ' ' || *(ptr) =='\t' || *(ptr) == '\r')
#define _LinkerPrompt "JWLINK>"

using namespace std;

extern cmdfilelist* CmdFile;

int stricmp_wrapper(const void* s1, const void* s2);
section* NewSection(MemorySubsystem* memorySubsystem);
char* FileName(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, char* buff, unsigned len, file_defext etype, bool force);
void NewCommandSource(MemorySubsystem* memorySubsystem, char* name, char* buff, method how);
void EatWhite(void);
void BurnUtils(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem);
bool GetToken(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem, sep_type req, tokcontrol ctrl);
char* tostring(MemorySubsystem* memorySubsystem);
void StartNewFile(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem);
unsigned MapDoubleByteChar(unsigned char c);
int ParseNumber(char* str, int radix);
void MapEscapeChar(void);
bool MakeToken(tokcontrol ctrl, sep_type separator);
void BackupParser(MessagingSubsystem* messagingSubsystem);
bool GetTokenEx(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem, sep_type req, tokcontrol ctrl, cmdfilelist* resetpoint, bool* pbreset);
void ExpandEnvVariable(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem);
bool ProcOne(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem, parse_entry* entry, sep_type req, bool suicide);
void SetCommandFile(MemorySubsystem* memorySubsystem, f_handle file, char* fname);