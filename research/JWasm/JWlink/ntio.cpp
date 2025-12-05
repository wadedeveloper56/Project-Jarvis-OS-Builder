#include "pch.h"
#include "ntio.h"
#include "File.h"
#include "msg.h"
#include "wlnkmsg.h"

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

