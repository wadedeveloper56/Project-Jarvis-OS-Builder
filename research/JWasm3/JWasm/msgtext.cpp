#include "pch.h"
#include "globals.h"
#include "errmsg.h"
#include "msgtext.h"

#define USERESOURCES 0 /* 1=use Win string resources, won't work for Linux! */

#define FPTR( x ) x
#undef pick
#define pick( code, string )  string,
static const char* const msgtexts[] = {
#include "msgdef.h"
};

static const char* MsgGet(int msgid, char* buffer)
{
#if USERESOURCES
    HRSRC hRsrc;
    HGLOBAL hRes;
    WORD* pId;
    int i;

    hRsrc = FindResource(NULL, MAKEINTRESOURCE(1 + (msgid >> 4)), RT_STRING);
    if (hRsrc) {
        hRes = LoadResource(NULL, hRsrc);
        if (hRes) {
            pId = LockResource(hRes);
            for (i = msgid % 16; i; i--)
                pId += *pId + 1;
            i = *pId++;
            if (buffer == NULL)
                buffer = StringBufferEnd;
            WideCharToMultiByte(CP_ACP, 0, pId, i, buffer, -1, 0, 0);
            buffer[i] = NULLC;
            return(buffer);
        }
    }
#else
    if (msgid < MSG_LAST) {
        if (buffer) {
            strcpy(buffer, FPTR(msgtexts[msgid]));
            return(buffer);
        }
        else
            return((char*)FPTR(msgtexts[msgid]));
    }
#endif
    DebugMsg(("MsgGet(%u): Msg not found!!!\n", msgid));
    if (buffer == NULL)
        buffer = StringBufferEnd;
    sprintf(buffer, "Msg %u", msgid);
    return(buffer);
}

const char* MsgGetEx(int msgid)
{
	return(MsgGet(msgid, NULL));
}
