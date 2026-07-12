#include "pch.h"
#include "cmdutils.h"
#include "MemorySubsystem.h"
#include "MessagingSubsystem.h"
#include "FileSubsystem.h"
#include "hash.h"
#include "Structs.h"
#include "globals.h"
#include "linkutil.h"
#include "cmdline.h"
#include "ntio.h"
#include "debug.h"
#include "linkutil.h"

using namespace std;

cmdfilelist* CmdFile = NULL;

char* DefExt[] = {
#undef pick1
#define pick1(enum1,text) text,
#include "ldefext.h"
};

int stricmp_wrapper(const void* s1, const void* s2)
{
	return(_stricmp((const char*)s1, (const char*)s2));
}

section* NewSection(MemorySubsystem* memorySubsystem)
{
	section* sect = nullptr;

	OvlNum++;
	sect = (section*)memorySubsystem->AllocateMemory(sizeof(section));
	sect->next_sect = NULL;
	sect->classlist = NULL;
	sect->orderlist = NULL;
	sect->areas = NULL;
	sect->files = NULL;
	sect->modFilesHashed = CreateHTable(256, StringiHashFunc, stricmp_wrapper, memorySubsystem);
	sect->mods = NULL;
	sect->reloclist = NULL;
	sect->sect_addr.off = 0;
	sect->sect_addr.seg = UNDEFINED;
	sect->ovl_num = 0;
	sect->parent = NULL;
	sect->relocs = 0;
	sect->size = 0;
	sect->outfile = NULL;
	sect->u.dist_mods = NULL;
	sect->dbg_info = NULL;
	return(sect);
}

char* FileName(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, char* buff, unsigned len, file_defext etype, bool force)
{
	char* namptr;
	char* namstart;
	char* ptr;
	unsigned    cnt;
	unsigned    namelen;

	namptr = buff + len;
	cnt = 0;
	while (cnt != len)
	{
		cnt++;
		--namptr;
		if (IS_PATH_SEP(*namptr))
		{
			break;
		}
	}
	if (IS_PATH_SEP(*namptr))
	{
		namptr++;
	}
	namstart = namptr;
	cnt = len - (namptr - buff);
	if (cnt == 0)
	{
		_LnkAlloc(char*, ptr, len + 1);
		memcpy(ptr, buff, len);
		ptr[len] = '\0';
		messagingSubsystem->LnkMsg(LOC + LINE + FTL + MSG_INV_FILENAME, "s", ptr);
	}
	namelen = cnt;
	namptr = buff + len - 1;
	while (--cnt != 0 && *namptr != '.')
	{
		namptr--;
	}
	if (force || *namptr != '.')
	{
		if (force && etype == E_MAP)
		{
			buff = namstart;
			len = namelen;
		}
		if (cnt != 0)
		{
			len = namptr - buff;
		}
		_LnkAlloc(char*, ptr, len + strlen(DefExt[etype]) + 1);
		memcpy(ptr, buff, len);
		strcpy(ptr + len, DefExt[etype]);
	}
	else
	{
		ptr = ChkToString(memorySubsystem, buff, len);
	}
	return(ptr);
}

void NewCommandSource(MemorySubsystem* memorySubsystem, char* name, char* buff, method how)
{
	cmdfilelist* newfile;

	_LnkAlloc(cmdfilelist*, newfile, sizeof(cmdfilelist));
	newfile->file = STDIN_HANDLE;
	if (CmdFile != NULL)
	{
		memcpy(&CmdFile->token, &Token, sizeof(tok));
		newfile->next = CmdFile->next;
		if (newfile->next != NULL)
		{
			newfile->next->prev = newfile;
		}
	}
	else
	{
		newfile->next = NULL;
	}
	newfile->prev = CmdFile;
	if (newfile->prev != NULL)
	{
		newfile->prev->next = newfile;
	}
	CmdFile = newfile;
	CmdFile->name = name;
	CmdFile->token.buff = buff;
	CmdFile->token.how = how;
	Token.buff = buff;
	Token.next = Token.buff;
	Token.where = MIDST;
	Token.line = 1;
	Token.how = how;
	Token.thumb = OK;
	Token.locked = FALSE;
	Token.quoted = 0;
}

void EatWhite(void)
{
	while (IS_WHITESPACE(Token.next))
	{
		Token.next++;
	}
}

void BurnUtils(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem)
{
	void* temp;

	if (CmdFile->next != NULL)
	{
		messagingSubsystem->LnkMsg(LOC + LINE + ERR + MSG_NO_INPUT_LEFT, NULL);
	}
	while (CmdFile != NULL)
	{
		if (CmdFile->file > STDIN_HANDLE)
		{
			QClose(CmdFile->file, CmdFile->name);
		}
		if (CmdFile->symprefix)
			_LnkFree(CmdFile->symprefix);
		CmdFile->symprefix = NULL;
		_LnkFree(CmdFile->name);
		switch (CmdFile->token.how)
		{
			case ENVIRONMENT:
			case SYSTEM:
				break;
			default:
				_LnkFree(CmdFile->token.buff);
				break;
		}
		temp = CmdFile;
		CmdFile = CmdFile->prev;
		_LnkFree(temp);
	}
	Token.how = BUFFERED;
}

bool GetToken(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem, sep_type req, tokcontrol ctrl)
{
	return(GetTokenEx(memorySubsystem, messagingSubsystem, fileSubsystem, req, ctrl, NULL, NULL));
}

char* tostring(MemorySubsystem* memorySubsystem)
{
	return(ChkToString(memorySubsystem, Token.this1, Token.len));
}

void StartNewFile(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem)
{
	char* fname;
	char* envstring;
	char* buff;
	f_handle    file;

	fname = FileName(memorySubsystem, messagingSubsystem, Token.this1, Token.len, E_COMMAND, FALSE);
	file = QObjOpen(fileSubsystem, fname);
	if (file == NIL_HANDLE)
	{
		_LnkFree(fname);
		fname = tostring(memorySubsystem);
		envstring = GetEnvString(fname);
		if (envstring != NULL)
		{
			buff = ChkStrDup(memorySubsystem, envstring);
			NewCommandSource(memorySubsystem, fname, buff, ENVIRONMENT);
		}
		else
		{
			messagingSubsystem->LnkMsg(LOC + LINE + ERR + MSG_CANT_OPEN_NO_REASON, "s", fname);
			_LnkFree(fname);
			Suicide();
		}
		return;
	}
	else
	{
		SetCommandFile(memorySubsystem, file, fname);
	}
	DEBUG((DBG_OLD, "processing command file %s", CmdFile->name));
}

unsigned MapDoubleByteChar(unsigned char c)
{
	switch (CmdFlags & CF_LANGUAGE_MASK)
	{
		case CF_LANGUAGE_JAPANESE:
			if ((c >= 0x81 && c <= 0x9F) || (c >= 0xE0 && c <= 0xFC))
			{
				Token.next++;
				return(1);
			}
			break;
		case CF_LANGUAGE_CHINESE:
			if (c > 0xFC) break;
		case CF_LANGUAGE_KOREAN:
			if (c > 0xFD) break;
			if (c < 0x81) break;
			Token.next++;
			return(1);
	}
	return(0);
}

int ParseNumber(char* str, int radix)
{
	bool        isdig;
	bool        isvalid;
	char        ch;
	int         size;
	unsigned    value;

	size = 0;
	value = 0;
	for (;;)
	{
		ch = tolower(*str);
		isdig = isdigit(ch);
		if (radix == 8)
		{
			isvalid = isdig && !(ch == '8' && ch == '9');
		}
		else
		{
			isvalid = isxdigit(ch);
		}
		if (!isvalid) break;
		value *= radix;
		if (isdig)
		{
			value += ch - '0';
		}
		else
		{
			value += ch - 'a' + 10;
		}
		size++;
		str++;
	}
	*Token.next = value;
	return(size);
}

void MapEscapeChar(void)
{
	char* str;
	int         shift;

	shift = 2;
	str = Token.next + 1;
	switch (*str)
	{
		case 'a':
			*Token.next = '\a';
			break;
		case 'b':
			*Token.next = '\b';
			break;
		case 'f':
			*Token.next = '\f';
			break;
		case 'n':
			*Token.next = '\n';
			break;
		case 'r':
			*Token.next = '\r';
			break;
		case 't':
			*Token.next = '\t';
			break;
		case 'v':
			*Token.next = '\v';
			break;
		case 'x':
			shift += ParseNumber(++str, 16);
			break;
		case '0': case '1': case '2': case '3': case '4': case'5': case '6':
		case '7': case '8': case '9':
			shift += ParseNumber(str, 8) - 1;
			break;
		default:
			*Token.next = *str;
			break;
	}
	str = Token.next + shift;
	memmove(Token.next + 1, str, strlen(str) + 1);
}

void OutPutPrompt(char* str)
{
	if (QIsDevice(CmdFile->file))
	{
		WriteStdOut(str);
	}
}

void GetNewLine(void)
{
	if (Token.how == BUFFERED
		|| Token.how == ENVIRONMENT
		|| Token.how == SYSTEM)
	{
		Token.where = MIDST;
		while (*Token.next != '\n')
		{           
			if (*Token.next == '\0' || *Token.next == CTRLZ)
			{
				Token.where = ENDOFFILE;
				break;
			}
			Token.next++;
		}
		Token.next++;
	}
	else if (Token.how == NONBUFFERED)
	{
		if (QReadStr(CmdFile->file, Token.buff, MAX_REC, CmdFile->name))
		{
			Token.where = ENDOFFILE;
		}
		else
		{
			Token.where = MIDST;
		}
		Token.next = Token.buff;
	}
	else
	{                
		OutPutPrompt(_LinkerPrompt);
		Token.how = INTERACTIVE;
		if (QReadStr(STDIN_HANDLE, Token.buff, MAX_REC, "console"))
		{
			Token.where = ENDOFCMD;
		}
		else
		{
			Token.where = MIDST;
		}
		Token.next = Token.buff;
	}
}


bool MakeToken(tokcontrol ctrl, sep_type separator)
{
	bool        quit;
	char        hmm;
	unsigned    len;
	bool        forcematch;
	bool        hitmatch;
	bool        keepspecial;

	Token.this1 = Token.next;
	len = 0;
	quit = FALSE;
	forcematch = (separator == SEP_QUOTE) || (separator == SEP_PAREN)
		|| (separator == SEP_PERCENT);
	keepspecial = (separator == SEP_SPACE) || (separator == SEP_DOT_EXT);
	if (separator == SEP_DOT_EXT)
	{
		len--;
		Token.next--;
	}
	if (*Token.next == '\\' && separator == SEP_QUOTE
		&& !(ctrl & TOK_IS_FILENAME))
	{
		MapEscapeChar();
	}
	hmm = *Token.next;
	len += MapDoubleByteChar((unsigned char)hmm);
	hitmatch = FALSE;
	for (;;)
	{
		len++;
		hmm = *++Token.next;
		switch (hmm)
		{
			case '\'':
			case '"':
				if (separator == SEP_QUOTE && Token.quoted == hmm)
				{
					++Token.next;
					hitmatch = TRUE;
					quit = TRUE;
				}
				break;
			case ')':
				if (separator == SEP_PAREN)
				{
					++Token.next;
					hitmatch = TRUE;
					quit = TRUE;
				}
				break;
			case '%':
				if (separator == SEP_PERCENT)
				{
					++Token.next;
					hitmatch = TRUE;
					quit = TRUE;
				}
				break;
			case '.':
				if (!(ctrl & TOK_INCLUDE_DOT) && !forcematch)
				{
					quit = TRUE;
				}
				break;
			case '{':
			case '}':
			case '(':
			case ',':
			case '=':
			case '#':
			case '@':
				if (keepspecial)
				{
					break;
				}
			case '\t':
			case ' ':
				if (!forcematch)
				{
					quit = TRUE;
				}
				break;
			case '\\':
				if (separator == SEP_QUOTE && !(ctrl & TOK_IS_FILENAME))
				{
					MapEscapeChar();
				}
				break;
			case '\0':
			case '\r':
			case '\n':
			case CTRLZ:
				quit = TRUE;
				break;
			default:
				len += MapDoubleByteChar((unsigned char)hmm);
		}
		if (quit)
		{
			break;
		}
	}
	Token.len = len;
	if (forcematch && !hitmatch)
	{
		return(FALSE);
	}
	return(TRUE);
}

void BackupParser(MessagingSubsystem* messagingSubsystem)
{
	if (CmdFile->prev == NULL)
	{
		messagingSubsystem->LnkMsg(LOC + LINE + WRN + MSG_NO_PREVIOUS_INPUT, NULL);
		return;
	}
	memcpy(&CmdFile->token, &Token, sizeof(tok));
	CmdFile = CmdFile->prev;
	memcpy(&Token, &CmdFile->token, sizeof(tok));
}

void ExpandEnvVariable(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem)
{
	char* envname;
	char* env;
	char* buff;
	size_t  envlen;

	Token.next++;
	if (!MakeToken(TOK_INCLUDE_DOT, SEP_PERCENT))
	{
		messagingSubsystem->LnkMsg(LOC + LINE + FTL + MSG_ENV_NAME_INCORRECT, NULL);
	}
	envname = tostring(memorySubsystem);
	env = GetEnvString(envname);
	if (env == NULL)
	{
		messagingSubsystem->LnkMsg(LOC + LINE + WRN + MSG_ENV_NOT_FOUND, "s", envname);
		_LnkFree(envname);
	}
	else
	{
		envlen = strlen(env);
		if (!IS_WHITESPACE(Token.next))
		{
			MakeToken(TOK_INCLUDE_DOT, SEP_SPACE);
			_LnkAlloc(char*, buff, envlen + Token.len + 1);
			memcpy(buff, env, envlen);
			memcpy(buff + envlen, Token.this1, Token.len);
			buff[Token.len + envlen] = '\0';
		}
		else
		{
			buff = ChkToString(memorySubsystem, env, envlen);
		}
		NewCommandSource(memorySubsystem, envname, buff, ENVIRONMENT);
	}
}

void RestoreCmdLine(MemorySubsystem* memorySubsystem)
{
	cmdfilelist* temp;

	if (CmdFile->prev == NULL)
	{          
		Token.where = ENDOFCMD;
		return;
	}
	switch (Token.how)
	{
		case SYSTEM:
			break;
		default:
			_LnkFree(Token.buff);
			if (CmdFile->file > STDIN_HANDLE)
			{
				QClose(CmdFile->file, CmdFile->name);
			}
			break;
	}
	if (CmdFile->symprefix)
		_LnkFree(CmdFile->symprefix);
	CmdFile->symprefix = NULL;
	_LnkFree(CmdFile->name);
	temp = CmdFile->prev;
	temp->next = CmdFile->next;
	if (temp->next != NULL)
	{
		temp->next->prev = temp;
	}
	_LnkFree(CmdFile);
	CmdFile = temp;
	memcpy(&Token, &CmdFile->token, sizeof(tok));    
}

void RestoreParser(void)
{
	if (CmdFile->next == NULL) return;
	memcpy(&CmdFile->token, &Token, sizeof(tok));      
	CmdFile = CmdFile->next;
	memcpy(&Token, &CmdFile->token, sizeof(tok));    
}

bool GetTokenEx(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem, sep_type req, tokcontrol ctrl, cmdfilelist* resetpoint, bool* pbreset)
{
	char    hmm;
	bool    ret;
	bool    need_sep;

	if (Token.thumb == REJECT)
	{
		Token.thumb = OK;
		if (Token.quoted) return(TRUE);
		Token.next = Token.this1;
	}
	need_sep = TRUE;
	for (;;)
	{

		if ((Token.skipToNext) && (req == SEP_COMMA))
		{
			Token.skipToNext = 0;
			need_sep = FALSE;
		}

		switch (Token.where)
		{
			case MIDST:
				EatWhite();
				hmm = *Token.next;
				switch (hmm)
				{
					case CTRLZ:
						Token.where = ENDOFFILE;
						break;
					case '\0':
						if (Token.how == BUFFERED
							|| Token.how == ENVIRONMENT
							|| Token.how == SYSTEM)
						{
							Token.where = ENDOFFILE;
							break;
						}
					case '\n':
						if (Token.how == BUFFERED
							|| Token.how == ENVIRONMENT
							|| Token.how == SYSTEM)
						{
							Token.next++;
						}
						else if (Token.how == COMMANDLINE)
						{
							Token.where = ENDOFCMD;
						}
						else
						{
							Token.where = ENDOFLINE;
						}
						Token.line++;
						break;
					case '@':
						if (req != SEP_SPACE)
						{
							Token.next++;
							GetToken(memorySubsystem, messagingSubsystem, fileSubsystem, SEP_NO, (tokcontrol)(TOK_INCLUDE_DOT | TOK_IS_FILENAME));
							StartNewFile(memorySubsystem, messagingSubsystem, fileSubsystem);
							break;
						}
						Token.next--;
						ret = MakeToken(ctrl, req);
						Token.quoted = 0;
						return(ret);
					case '#':
						Token.where = ENDOFLINE;
						Token.line++;
						break;
					case '^':
						if (req != SEP_SPACE)
						{
							Token.next++;
							BackupParser(messagingSubsystem);
							break;
						}
						Token.next--;
						ret = MakeToken(ctrl, req);
						Token.quoted = 0;
						return(ret);
					case '%':
						if (req != SEP_SPACE)
						{
							ExpandEnvVariable(memorySubsystem, messagingSubsystem, fileSubsystem);
							break;
						}
					default:
						if (need_sep)
						{
							if ((sep_type)need_sep != SEP_QUOTE)
								Token.quoted = 0;
							switch (req)
							{
								case SEP_NO:
									if (hmm == ',' || hmm == '=') return(FALSE);
									break;
								case SEP_COMMA:
									if (hmm != ',') return(FALSE);
									Token.next++;
									break;
								case SEP_EQUALS:
									if (hmm != '=') return(FALSE);
									Token.next++;
									break;
								case SEP_PERIOD:
								case SEP_DOT_EXT:
									if (hmm != '.') return(FALSE);
									Token.next++;
									break;
								case SEP_PAREN:
									if (hmm != '(') return(FALSE);
									Token.next++;
									break;
								case SEP_LCURLY:
									if (hmm != '{') return(FALSE);
									Token.next++;
									break;
								case SEP_QUOTE:
									if (hmm != Token.quoted) return(FALSE);
									Token.next++;
									break;
								case SEP_RCURLY:
									if (hmm != '}') return(FALSE);
									Token.next++;
									return(TRUE);
								case SEP_END:
									return(FALSE);
							}
							need_sep = FALSE;
							EatWhite();
						}
						else
						{
							if ((hmm == '\'' || hmm == '"') && req != SEP_PAREN && req != SEP_SPACE)
							{
								req = SEP_QUOTE;
								Token.next++;
								Token.quoted = hmm;
							}
							ret = MakeToken(ctrl, req);
							return(ret);
						}
						break;
				}
				break;
			case ENDOFLINE:
				GetNewLine();
				break;
			case ENDOFFILE:
				if (Token.locked) return(FALSE);
				RestoreCmdLine(memorySubsystem);
				if (Token.thumb == REJECT)
				{
					Token.thumb = OK;
					Token.next = Token.this1;
				}
				Token.quoted = 0;
				if (resetpoint && (CmdFile == resetpoint))
				{
					if (*Token.next == ',')
						break;
					if (pbreset)
						*pbreset = TRUE;
					return(FALSE);
				}
				break;
			case ENDOFCMD:
				if (CmdFile->next != NULL)
				{
					RestoreParser();
					break;
				}
				Token.quoted = 0;
				ret = (req == SEP_END) ? TRUE : FALSE;
				return(ret);
		}
	}
}

void Syntax(MessagingSubsystem* messagingSubsystem)
{
	if (Token.this1 == NULL)
	{
		messagingSubsystem->LnkMsg(LOC + LINE + FTL + MSG_DIRECTIVE_ERR_BEGINNING, NULL);
	}
	else
	{
		Token.this1[Token.len] = '\0';
		messagingSubsystem->LnkMsg(LOC + LINE + FTL + MSG_DIRECTIVE_ERR, "s", Token.this1);
	}
}

bool ProcOne(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem, parse_entry* entry, sep_type req, bool suicide)
{
	char* key;
	char* ptr;
	unsigned            plen;
	bool                ret;
	char                keybuff[20];

	ret = GetToken(memorySubsystem, messagingSubsystem, fileSubsystem, req, (tokcontrol)(TOK_INCLUDE_DOT | TOK_IS_FILENAME));
	if (ret == FALSE)
	{
		return(ret);
	}
	while (entry->keyword != NULL)
	{
		key = entry->keyword;
		ptr = Token.this1;
		plen = Token.len;
		for (;;)
		{
			if (plen == 0 && !isupper(*key))
			{
				if (HintFormat(memorySubsystem, messagingSubsystem, entry->format))
				{
					ret = (*entry->rtn)(memorySubsystem, messagingSubsystem, fileSubsystem);
					DO_AND_EQUAL(commandflag, CmdFlags, |=, entry->flags);
				}
				else
				{
					strcpy(keybuff, entry->keyword);
					_strupr(keybuff);
					messagingSubsystem->LnkMsg(LOC + LINE + WRN + MSG_FORMAT_BAD_OPTION, "s", keybuff);
					ret = TRUE;
				}
				return(ret);
			}
			if (*key == '\0' || tolower(*ptr) != tolower(*key)) break;
			ptr++;
			key++;
			plen--;
		}
		entry++;
	}
	if (suicide)
	{
		Syntax(messagingSubsystem);
	}
	else
	{
		Token.thumb = REJECT;
		ret = FALSE;
	}
	return(ret);
}

void SetCommandFile(MemorySubsystem* memorySubsystem, f_handle file, char* fname)
{
	unsigned long   size;
	char* buff;

	if (QIsDevice(file))
	{
		size = 0x10000;
	}
	else
	{
		size = QFileSize(file);
	}
	buff = NULL;
	if (size < 65510)
	{
		_LnkAlloc(char*, buff, size + 1);
		if (buff != NULL)
		{
			size = QRead(file, buff, size, fname);
			*(buff + size) = '\0';
			NewCommandSource(memorySubsystem, fname, buff, BUFFERED);
		}
	}
	if (buff == NULL)
	{
		_LnkAlloc(char*, buff, MAX_REC + 1);
		NewCommandSource(memorySubsystem, fname, buff, NONBUFFERED);
		Token.where = ENDOFLINE;
		Token.line++;
	}
	CmdFile->file = file;
}


