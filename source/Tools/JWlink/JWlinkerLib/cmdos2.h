#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "cmdline.h"
#include "Structs.h"
#include "globals.h"
#include "Linkutil.h"
#include "cmd16m.h"
#include "cmdqnx.h"
#include "cmdelf.h"
#include "MessagingSubsystem.h"

using namespace std;


// NOTE: in these flags, CLEAN_MEMORY and INIT_THREAD_FLAG have the same value,
// since CLEAN_MEMORY is windows 16-bit only, and INIT_THREAD_FLAG is windows pe
// only.  Same goes for PROPOTIONAL_FONT and TERM_THREAD_FLAG.

#define SINGLE_AUTO_DATA    0x0001
#define MULTIPLE_AUTO_DATA  0x0002
#define INIT_INSTANCE_FLAG  0x0004
#define PHONEY_STACK_FLAG   0x0008
#define PM_COMPATIBLE       0x0010
#define PM_APPLICATION      0x0020
#define LONG_FILENAMES      0x0040
#define CLEAN_MEMORY        0x0080 /* MEMORY attribute of FORMAT WINDOWS */
#define INIT_THREAD_FLAG    0x0080 /* (undocumented) INITTHREAD attribute of FORMAT WIN PE */
#define PROPORTIONAL_FONT   0x0100 /* FONT attribute of FORMAT WINDOWS */
#define TERM_THREAD_FLAG    0x0100 /* (undocumented) TERMTHREAD attribute of FORMAT WIN PE */
#define PROTMODE_ONLY       0x0200 /* OPTION PROTMODE */
#define PHYS_DEVICE         0x0400
#define VIRT_DEVICE         0x0800
#define SHARABLE_DGROUP     0x1000
#define PM_NOT_COMPATIBLE   0x4000
#define TERM_INSTANCE_FLAG  0x8000

void SetOS2Fmt(MemorySubsystem *memorySubsystem, MessagingSubsystem *messagingSubsystem);
void FreeOS2Fmt(MemorySubsystem *memorySubsystem, MessagingSubsystem *messagingSubsystem);
