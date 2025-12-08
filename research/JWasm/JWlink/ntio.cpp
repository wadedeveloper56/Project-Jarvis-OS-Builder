#include "pch.h"
#include "ntio.h"
#include "File.h"
#include "msg.h"
#include "wlnkmsg.h"
#include "objio.h"
#define TOOMANY EMFILE

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

static int      OpenFiles;      // the number of open files
static unsigned LastResult;
static bool     CaughtBreak;

void LnkFilesInit(void)
{
	OpenFiles = 0;
	CaughtBreak = false;
	setFileMode(_fileno(stdin), _O_BINARY);
	setFileMode(_fileno(stdout), _O_BINARY);
}

void SetBreak(void)
{
}

void RestoreBreak(void)
{
}

FileHandle QOpenR(char* name)
{
	FileHandle fh = OpenFile(name, _O_RDONLY | _O_BINARY, _S_IREAD);
	if (fh != -1) return fh;
	LnkMsg(FTL + MSG_CANT_OPEN, (char*)"12", name, strerror(errno));
	return NIL_HANDLE;
}

FileHandle QOpenRW(char* name)
{
	FileHandle fh = OpenFile(name, _O_RDWR | _O_CREAT | _O_TRUNC | _O_BINARY, _S_IREAD | _S_IWRITE);
	if (fh != -1) return fh;
	LnkMsg(FTL + MSG_CANT_OPEN, (char*)"12", name, strerror(errno));
	return NIL_HANDLE;
}

unsigned QWrite(FileHandle file, void* buffer, unsigned len, char* name)
{
	char  rc_buff[RESOURCE_MAX_SIZE];
	int h = WriteFile(file, buffer, len);
	if (name != NULL) {
		if (h == -1) {
			LnkMsg(ERR + MSG_IO_PROBLEM, (char*)"12", name, strerror(errno));
		}
		else if (h != len) {
			Msg_Get(MSG_IOERRLIST_7, rc_buff);
			LnkMsg((FTL + MSG_IO_PROBLEM) & ~OUT_MAP, (char*)"12", name, rc_buff);
		}
	}
	return h;
}

char NLSeq[] = { "\r\n" };

void QWriteNL(FileHandle file, char* name)
{
	QWrite(file, NLSeq, sizeof(NLSeq) - 1, name);
}

unsigned QRead(FileHandle file, void* buffer, unsigned len, char* name)
{
	int h = ReadFile(file, buffer, len);
	if (h == -1) {
		LnkMsg(ERR + MSG_IO_PROBLEM, (char *)"12", name, strerror(errno));
	}
	return(h);
}

bool QReadStr(FileHandle file, char* dest, unsigned size, char* name)
{
	char ch;
	bool eof = false;
	while (--size > 0) {
		if (QRead(file, &ch, 1, name) == 0) {
			eof = true;
			break;
		}
		else if (ch != '\r') {
			*dest++ = ch;
		}
		if (ch == '\n') {
			break;
		}
	}
	*dest = '\0';
	return eof;
}

void QClose(FileHandle file, char* name)
{
	int h = CloseFile(file);
	OpenFiles--;
	if (h != -1) return;
	LnkMsg(ERR + MSG_IO_PROBLEM, (char*)"12", name, strerror(errno));

}

void QDelete(char* name)
{
	if (name == NULL) return;
	int h = remove(name);
	if (h == -1 && errno != ENOENT) { /* file not found is OK */
		LnkMsg(ERR + MSG_IO_PROBLEM, (char*)"12", name, strerror(errno));
	}
}

unsigned long QFileSize(FileHandle file)
{
	long result = _filelength(file);
	if (result == -1) result = 0;
	return result;
}

unsigned long QPos(FileHandle file)
{
	return (unsigned long)FileTell(file);
}

time_t QFModTime(int handle)
{
	struct stat buf;
	fstat(handle, &buf);
	return buf.st_mtime;
}

bool QHavePath(char* name)
{
	return(*name == '\\' || *name == '/' || *(name + 1) == ':');
}

long QLSeek(FileHandle file, long position, int start, char* name)
{
	long h = (long)FileSeek(file, position, start);
	if (h == -1 && name != NULL) {
		LnkMsg(ERR + MSG_IO_PROBLEM, (char*)"12", name, strerror(errno));
	}
	return h;
}

void QSeek(FileHandle file, long position, char* name)
{
	QLSeek(file, position, SEEK_SET, name);
}

bool QIsDevice(FileHandle file)
{
	return(_isatty(file));
}

static FileHandle DoOpen(char* name, unsigned mode, bool isexe)
{
	FileHandle h;

	mode |= _O_BINARY;
	for (;; ) {
		if (OpenFiles >= MAX_OPEN_FILES)
			CleanCachedHandles();
		h = OpenFile(name, mode, owner_read | owner_write);
		if (h != -1) {
			OpenFiles++;
			break;
		}
		if (errno != TOOMANY)
			break;
		if (!CleanCachedHandles()) {
			break;
		}
	}
	return(h);
}

static FileHandle NSOpen(char* name, unsigned mode)
{
	FileHandle h = DoOpen(name, mode, false);
	LastResult = h;
	if (h != -1) return(h);
	return(NIL_HANDLE);
}

FileHandle QObjOpen(char* name)
{
	return(NSOpen(name, _O_RDONLY));
}

FileHandle TempFileOpen(char* name)
{
	return(NSOpen(name, _O_RDWR));
}

