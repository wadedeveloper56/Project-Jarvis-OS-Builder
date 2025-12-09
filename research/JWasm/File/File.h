#pragma once

enum perms {// names for permissions
    none = 0,
    owner_read = 0400,  // S_IRUSR
    owner_write = 0200, // S_IWUSR
    owner_exec = 0100,  // S_IXUSR
    owner_all = 0700,   // S_IRWXU
    group_read = 040,   // S_IRGRP
    group_write = 020,  // S_IWGRP
    group_exec = 010,   // S_IXGRP
    group_all = 070,    // S_IRWXG
    others_read = 04,   // S_IROTH
    others_write = 02,  // S_IWOTH
    others_exec = 01,   // S_IXOTH
    others_all = 07,    // S_IRWXO
    all = 0777,
    set_uid = 04000,    // S_ISUID
    set_gid = 02000,    // S_ISGID
    sticky_bit = 01000, // S_ISVTX
    mask = 07777,
    unknown = 0xFFFF,
    add_perms = 0x10000,
    remove_perms = 0x20000,
    resolve_symlinks = 0x40000
};

typedef int FileHandle;
#define NIL_HANDLE      ((FileHandle)-1)

FileHandle OpenFile(const char* filename, int oflag, int pmode);
int CloseFile(FileHandle handle);
int ReadFile(FileHandle handle, void* const buffer, unsigned const buffer_size);
int WriteFile(FileHandle handle, void* const buffer, unsigned int count);
int setFileMode(FileHandle handle, int mode);
int FileAccess(const char* path, int mode);
__int64 FileTell(FileHandle handle);
__int64 FileSeek(FileHandle handle, __int64 offset, int origin);
int FileRemove(const char* path);
int FileStat(FileHandle handle, struct _stati64* buffer);
