#include "pch.h"
#include "linkstd.h"
#include "msg.h"
#include "alloc.h"
#include "wlnkmsg.h"
#include "fileio.h"
#include "spillio.h"

static char* TFileName;
static unsigned long  TmpFSize;
f_handle TempFile;
#define TEMPFNAME "WLK02112.xx`"        // "'" will be an "a" when processed.
#define TEMPFNAME_SIZE 13

void InitSpillFile(void)
{
	TempFile = NIL_HANDLE;
	TFileName = NULL;
	TmpFSize = 0;
	SetBreak();
}

static char* MakeTempName(char* name)
{
	memcpy(name, TEMPFNAME, sizeof(TEMPFNAME));   // includes nullchar
	return(name + sizeof(TEMPFNAME) - 2);         // pointer to "a"
}

f_handle OpenTempFile(char** fname)
{
	char* ptr;
	unsigned    tlen;
	char* tptr;
	f_handle    fhdl;

	ptr = GetEnvString("WLINKTMP");
	if (ptr == NULL) ptr = GetEnvString("TMP");
	if (ptr == NULL) ptr = GetEnvString("TMPDIR");
	if (ptr == NULL) {
		_ChkAlloc(char*, *fname, TEMPFNAME_SIZE);
		tptr = *fname;
	}
	else {
		tlen = strlen(ptr);
		_ChkAlloc(char*, *fname, tlen + 1 + TEMPFNAME_SIZE);
		memcpy(*fname, ptr, tlen);
		switch ((*fname)[tlen - 1])
		{
		CASE_PATH_SEP:
			break;
			default:
				(*fname)[tlen++] = PATH_SEP;
				break;
		}
		tptr = *fname + tlen;
	}
	ptr = MakeTempName(tptr);
	tlen = 0;
	for (;; ) {
		if (tlen >= 26) {
			//FIX ME LnkMsg(FTL + MSG_CANT_OPEN_SPILL, NULL);
		}
		*ptr += 1;                          // change temp file extension
		fhdl = TempFileOpen(*fname);
		if (fhdl == NIL_HANDLE) break;
		//FIX ME QClose(fhdl, *fname);
		++tlen;
	}
	return fhdl; //FIX ME  QOpenRW(*fname);
}

unsigned long SpillAlloc(unsigned amt)
{
	unsigned long           stg;

	if (TempFile == NIL_HANDLE) {
		TempFile = OpenTempFile(&TFileName);
		//FIX ME LnkMsg(INF + MSG_USING_SPILL, NULL);
	}
	/* round up storage start to a disk sector boundry -- assumed power of 2 */
	TmpFSize += SECTOR_SIZE - 1;
	TmpFSize &= ~(SECTOR_SIZE - 1);
	stg = TmpFSize;
	TmpFSize += amt;
	return(stg + 1);  /* add 1 to prevent a NULL handle */
}

void SpillWrite(unsigned long base, unsigned off, void* mem, unsigned size)
{
	//FIX ME QSeek(TempFile, base + off - 1, TFileName);
	//FIX ME QWrite(TempFile, mem, size, TFileName);
}
