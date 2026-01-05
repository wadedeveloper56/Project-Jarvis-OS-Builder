#include "pch.h"
#include "MessagingSubsystem.h"

static char* MsgStrings[] = {
"JWlink Version 1.9beta 13",
"Portions Copyright (c) 1985-2002 Sybase, Inc. All Rights Reserved.",
"Source code is available under the Sybase Open Watcom Public License."
};

static const char* const msgtexts[] = {
	"",
	"",
#undef pick
#define pick( code, string )  string,
#include "lnkerror.msg"
#include "wlink.msg"
#include "rc.msg"
#undef pick
	 
};

MessagingSubsystem::MessagingSubsystem(FileSubsystem* file)
{
	this->file = file;
	BannerPrinted = false;
}

MessagingSubsystem::~MessagingSubsystem()
{
}

unsigned MessagingSubsystem::CalcMsgNum(unsigned msg)
{
	return msg % MSG_LANG_SPACING;
}

unsigned MessagingSubsystem::FmtStr(char* buffer, unsigned bufsize, char* fmt, ...)
{
	va_list args;
	unsigned len;
	va_start(args, fmt);
	len = DoFmtStr(buffer, bufsize, fmt, &args);
	va_end(args);
	return len;
}

unsigned MessagingSubsystem::DoFmtStr(char* buffer, unsigned bufsize, char* fmt, va_list* args)
{
	unsigned index = 0;
	char ch;
	while ((ch = *fmt++) != '\0' && index < bufsize - 1) {
		if (ch != '%') {
			buffer[index++] = ch;
		}
		else {
			ch = *fmt++;
			switch (ch) {
				case 's': {
					char* str = va_arg(*args, char*);
					while (*str != '\0' && index < bufsize - 1) {
						buffer[index++] = *str++;
					}
					break;
				}
				case 'c': {
					char c = (char)va_arg(*args, int);
					buffer[index++] = c;
					break;
				}
				case 'd': {
					int num = va_arg(*args, int);
					char numbuf[20];
					int numindex = 0;
					if (num < 0) {
						buffer[index++] = '-';
						num = -num;
					}
					do {
						numbuf[numindex++] = (num % 10) + '0';
						num /= 10;
					} while (num > 0);
					while (numindex > 0 && index < bufsize - 1) {
						buffer[index++] = numbuf[--numindex];
					}
					break;
				}
				default:
					buffer[index++] = ch;
					break;
			}
		}
	}
	buffer[index] = '\0';
	return index;
}

bool TestBit(int_8* array, unsigned num)
{
	int_8 mask = 1 << (num % 8);
	num /= 8;
	return(*(array + num) & mask);
}

void MessagingSubsystem::LnkMsg(unsigned num, char* types, ...)
{
	va_list     args;
	int         which_file = 0;
	unsigned    len;
	unsigned    prefixlen;
	unsigned    class1;
	bool        waserror;
	char        rc_buff[RESOURCE_MAX_SIZE];
	char        buff[MAX_MSG_SIZE];
	char        prefix[MAX_MSG_SIZE];

	if (!TestBit(MsgFlags, num & NUM_MSK))
		return;
	CurrSymName = NULL;
	LocateFile(num);
	len = 0;
	prefixlen = 0;
	waserror = false;
	class1 = num & CLASS_MSK;
	if (class1 == (YELL & CLASS_MSK)) {
		waserror = true;        /* yells are counted as errors for limits */
	}
	else if (class1 >= (MILD_ERR & CLASS_MSK)) {
		waserror = true;
		if (class1 >= (ERR & CLASS_MSK)) {
			LinkState |= LINK_ERROR;
		}
	}
	if (class1 >= (WRN & CLASS_MSK)) {
		if (class1 == (WRN & CLASS_MSK)) {
			Msg_Get(MSG_WARNING, rc_buff);
		}
		else {
			Msg_Get(MSG_ERROR, rc_buff);
		}
#if !defined( _DLLHOST )
		len = FmtStr(buff, MAX_MSG_SIZE - len, rc_buff, CalcMsgNum(num));
#else
		prefixlen = FmtStr(prefix, MAX_MSG_SIZE, rc_buff, CalcMsgNum(num));
#endif
	}
	if (LocFile != NULL) {
		which_file += 1;
	}
	if (LocMem != NULL) {
		which_file += 2;
	}
	if (LocRec != 0) {
		which_file += 4;
	}
	if (which_file != 0) {
		if (token.how == SYSTEM) {
			Msg_Get(MSG_SYS_BLK, rc_buff);
			which_file = 1;
		}
		else if (token.how == ENVIRONMENT) {
			Msg_Get(MSG_ENVIRON, rc_buff);
			which_file = 1;
		}
		else {
			Msg_Get(MSG_FILE_REC_NAME_0 + which_file - 1, rc_buff);
		}
		FileOrder(rc_buff, which_file);
		len += FmtStr(&buff[len], MAX_MSG_SIZE - len, rc_buff);
		if (num & LINE) {
			if (token.how != SYSTEM && token.how != ENVIRONMENT) {
				Msg_Get(MSG_LINE, rc_buff);
				Msg_Do_Put_Args(rc_buff, &MsgArgInfo, "d", token.line);
				len += FmtStr(&buff[len], MAX_MSG_SIZE - len, rc_buff);
			}
		}
		LocFile = NULL;
		LocMem = NULL;
		LocRec = 0;
	}

	va_start(args, types);
	Msg_Get(num & NUM_MSK, rc_buff);
	Msg_Put_Args(rc_buff, &MsgArgInfo, types, &args);
	va_end(args);
	len += FmtStr(&buff[len], MAX_MSG_SIZE - len, rc_buff);
	MessageFini(num, buff, len, prefix, prefixlen, waserror);
}

void MessagingSubsystem::WLPrtBanner(void)
{
	char* msg;

	if (!BannerPrinted) {
		msg = MsgStrings[PRODUCT];
		file->WriteStdOut(msg, sizeof(msg));
		msg = MsgStrings[COPYRIGHT];
		file->WriteStdOut(msg, sizeof(msg));
		msg = MsgStrings[TRADEMARK];
		file->WriteStdOut(msg, sizeof(msg));
		BannerPrinted = true;
	}
}


//bool MessagingSubsystem::SkipSymbol(symbol* sym)
//{
//	return false;
//}

int MessagingSubsystem::SymAlphaCompare(const void*, const void*)
{
	// Placeholder implementation
	return 0;
}

void MessagingSubsystem::ResetMsg(void)
{
	LocFile = NULL;
	LocMem = NULL;
	LocRec = 0;
	MsgArgInfo.index = -1;
	memset(MsgFlags, 0xFF, MSG_ARRAY_SIZE);
}

int MessagingSubsystem::Msg_Get(int resourceid, char buffer[])
{
	if (resourceid < 0 || resourceid >= static_cast<int>(sizeof(msgtexts) / sizeof(msgtexts[0]))) {
		return 0;
	}
	strcpy(buffer, msgtexts[resourceid]);
	return static_cast<int>(strlen(buffer));
}

void MessagingSubsystem::Msg_Do_Put_Args(char rc_buff[], MSG_ARG_LIST* arg_info, char* types, ...)
{
	va_list     args;

	va_start(args, types);
	Msg_Put_Args(rc_buff, arg_info, types, &args);
	va_end(args);
}

void MessagingSubsystem::Msg_Put_Args(char message[], MSG_ARG_LIST* arg_info, char* types, va_list* args)
{
	int         argnum = 0;             // Index of argument found
	int         j;                      // General purpose loop index
	int         order[3];               // Mapping of args to arg_info->arg
	char* percent;               // Position of '%' in message
	char        types_buff[1 + 3];      // readwrite copy of types
	char        specifier;              // Character following '%'

	if (types != NULL) {
		strcpy(types_buff, types);
		// conversions set order[]; digits->s
		percent = message - 2;          // So strchr below can work
		while ((percent = strchr(percent + 2, '%')) != NULL) {
			specifier = percent[1];
			for (j = 0; types_buff[j] != '\0'; j++) {  // Match with types
				if (types_buff[j] == specifier) {
					order[j] = argnum;
					argnum++;
					if (isdigit(specifier))          // Digit becomes s
						types_buff[j] = percent[1] = 's';
					break;
				}
			}
		}
		// Re-order sequential arguments
		for (j = 0; j < argnum; j++) {
			Msg_Add_Arg(arg_info->arg + order[j], types_buff[j], args);
		}
	}
	arg_info->index = 0;
}

void MessagingSubsystem::Msg_Add_Arg(MSG_ARG* arginfo, char typech, va_list* args)
{
	switch (typech) {
		case 's':
			arginfo->string = va_arg(*args, char*);
			break;
		case 'x':
		case 'd':
			arginfo->int_16 = va_arg(*args, unsigned int);
			break;
		case 'l':
			arginfo->int_32 = va_arg(*args, unsigned long);
			break;
		case 'A':
		case 'a':
			arginfo->address = va_arg(*args, targ_addr*);
			break;
		case 'S':
			//FIX ME arginfo->symb = va_arg(*args, symbol*);
			break;
	}
}

void MessagingSubsystem::Locator(char* filename, char* mem, unsigned rec)
{
	LocFile = filename;
	LocMem = mem;
	LocRec = rec;
}

void MessagingSubsystem::LocateFile(unsigned num)
{
	unsigned    rec;

	if (num & LOC) {
		if (num & (LOC_REC & ~LOC)) {
			rec = RecNum;
		}
		else {
			rec = 0;
		}
		//if (CurrMod == NULL) {
		//	if (CmdFile == NULL) {
		//		Locator(NULL, NULL, 0);
		//	}
		//	else {
		//		Locator(CmdFile->name, NULL, 0);
		//	}
		//}
		//else {
		//	Locator(CurrMod->f.source->file->name, CurrMod->name, rec);
		//}
	}
}

void MessagingSubsystem::FileOrder(char rc_buff[], int which_file)
{
	switch (which_file) {
		case 1:
			Msg_Do_Put_Args(rc_buff, &MsgArgInfo, "s", LocFile);
			break;
		case 2:
			Msg_Do_Put_Args(rc_buff, &MsgArgInfo, "s", LocMem);
			break;
		case 3:
			Msg_Do_Put_Args(rc_buff, &MsgArgInfo, "12", LocFile, LocMem);
			break;
		case 4:
			Msg_Do_Put_Args(rc_buff, &MsgArgInfo, "d", LocRec);
			break;
		case 5:
			Msg_Do_Put_Args(rc_buff, &MsgArgInfo, "sd", LocFile, LocRec);
			break;
		case 6:
			Msg_Do_Put_Args(rc_buff, &MsgArgInfo, "sd", LocMem, LocRec);
			break;
		case 7:
			Msg_Do_Put_Args(rc_buff, &MsgArgInfo, "12d", LocFile, LocMem,
				LocRec);
			break;
	}
}

void MessagingSubsystem::MessageFini(unsigned num, char* buff, unsigned len, char* prefix, unsigned prefixlen, bool waserror)
{
	if (num & OUT_TERM) {
		if (!(LinkFlags & QUIET_FLAG)) {
			WLPrtBanner();
			file->WriteStdOut(buff, strlen(buff));
		}
		else if ((num & CLASS_MSK) != (CLASS_MSK & INF)) {
			file->WriteStdOut(buff, strlen(buff));
		}
	}
	if (waserror && LinkFlags & MAX_ERRORS_FLAG) {
		MaxErrors--;
		if (MaxErrors == 0) {
			LnkMsg(FTL + MSG_TOO_MANY_ERRORS, NULL);
		}
	}
}

void MessagingSubsystem::LnkFatal(char* msg)
{
	LnkMsg(FTL + MSG_INTERNAL, "s", msg);
}
