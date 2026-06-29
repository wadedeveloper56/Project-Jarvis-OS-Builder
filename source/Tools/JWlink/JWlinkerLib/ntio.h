#pragma once

#include "File.h"

typedef enum
{
    TIO_READ = 0x00,
    TIO_WRITE = 0x01,
    TIO_READ_WRITE = 0x02,
    TIO_DENY_COMPATIBILITY = 0x00,
    TIO_DENY_READ_WRITE = 0x10,
    TIO_DENY_WRITE = 0x20,
    TIO_DENY_READ = 0x30,
    TIO_DENY_NONE = 0x40,
    TIO_INHERITANCE = 0x80,
    TIO_READ_DENY_WRITE = TIO_READ | TIO_DENY_WRITE,
    TIO_NULL_ATTR = 0x00
} open_attr;

typedef enum
{
    TIO_SEEK_START = 0,
    TIO_SEEK_SET = 0,
    TIO_SEEK_CURR = 1,
    TIO_SEEK_CUR = 1,
    TIO_SEEK_END = 2,
} seek_info;

typedef enum
{
    TIO_STDIN_FILENO = 0,
    TIO_STDOUT_FILENO = 1,
    TIO_STDERR_FILENO = 2,
    TIO_STDAUX_FILENO = 3,
    TIO_STDPRN_FILENO = 4
} tio_file_handles;

typedef enum
{
    TIO_NORMAL = 0x00,
    TIO_READ_ONLY = 0x01,
    TIO_HIDDEN = 0x02,
    TIO_SYSTEM = 0x04,
    TIO_VOLUME_LABEL = 0x08,
    TIO_SUBDIRECTORY = 0x10,
    TIO_ARCHIVE = 0x20,
} create_attr;

typedef enum
{
    TIO_CREATE = 0x01,        
    TIO_OPEN = 0x10,     
    TIO_TRUNCATE = 0x20,
} create_action;

#define TINY_IN     0
#define TINY_OUT    1
#define TINY_ERR    2

enum
{
    TIO_CTL_CONSOLE_IN = 0x0001,
    TIO_CTL_CONSOLE_OUT = 0x0002,
    TIO_CTL_NULL = 0x0004,
    TIO_CTL_CLOCK = 0x0008,
    TIO_CTL_SPECIAL = 0x0010,        
    TIO_CTL_RAW = 0x0020,
    TIO_CTL_EOF = 0x0040,
    TIO_CTL_DEVICE = 0x0080,

    TIO_CTL_DISK_DRIVE_MASK = 0x001f,        
};

enum
{
    TIO_INVALID_FUNCTION = 1,
    TIO_FILE_NOT_FOUND,
    TIO_PATH_NOT_FOUND,
    TIO_TOO_MANY_OPEN_FILES,
    TIO_ACCESS_DENIED,
    TIO_INVALID_HANDLE,
    TIO_ARENA_TRASHED,
    TIO_NOT_ENOUGH_MEMORY,
    TIO_INVALID_BLOCK,
    TIO_BAD_ENVIRONMENT,
    TIO_BAD_FORMAT,
    TIO_INVALID_ACCESS,
    TIO_INVALID_DATA,

    TIO_INVALID_DRIVE = 15,
    TIO_CURRENT_DIRECTORY,
    TIO_NOT_SAME_DEVICE,
    TIO_NO_MORE_FILES,
    TIO_WRITE_PROTECT,
    TIO_BAD_UNIT,
    TIO_NOT_READY,
    TIO_BAD_COMMAND,
    TIO_CRC,
    TIO_BAD_LENGTH,
    TIO_SEEK,
    TIO_NOT_DOS_DISK,
    TIO_SECTOR_NOT_FOUND,
    TIO_OUT_OF_PAPER,
    TIO_WRITE_FAULT,
    TIO_READ_FAULT,
    TIO_GEN_FAILURE,
    TIO_SHARING_VIOLATION,
    TIO_LOCK_VIOLATION,
    TIO_WRONG_DISK,
    TIO_FCB_UNAVAILABLE,

    TIO_FILE_EXISTS = 80,

    TIO_CANNOT_MAKE = 82,
    TIO_FAIL_I24,

    TIO_FIND_ERROR = TIO_FILE_NOT_FOUND,
    TIO_FIND_NO_MORE_FILES = TIO_NO_MORE_FILES,
};

void Locator(char* filename, char* mem, unsigned rec);
time_t QFModTime(int handle);
f_handle NSOpen(char* name, unsigned mode);
f_handle ExeOpen(char* name);
f_handle QObjOpen(char* name);
f_handle TempFileOpen(char* name);
int QMakeFileName(char** pos, char* name, char* fname);
bool QHavePath(char* name);
void QClose(f_handle file, char* name);
void QDelete(char* name);
unsigned QWrite(f_handle file, void* buffer, unsigned len, char* name);
unsigned QRead(f_handle file, void* buffer, unsigned len, char* name);
long QLSeek(f_handle file, long position, int start, char* name);
unsigned long QFileSize(f_handle file);
f_handle QOpenR(char* name);
f_handle QOpenRW(char* name);
void QSeek(f_handle file, long position, char* name);
