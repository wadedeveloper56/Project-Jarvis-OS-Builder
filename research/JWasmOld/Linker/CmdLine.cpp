#include "pch.h"
#include "CmdLine.h"
#include "LinkerUtils.h"
#include "CmdPlatform.h"
#include "CmdQnx.h"
#include "CmdElf.h"
#include "CmdWinOS2.h"
#include "CmdPharlap.h"
#include "CmdNovell.h"

CmdLine::CmdLine(MemorySubsystem* memory, MessagingSubsystem* msg, PermData* permData)
{
	this->memory = memory;
	this->msg = msg;
	this->permData = permData;
	PrevCommand = nullptr;
	SysBlocks = nullptr;
	Name = nullptr;
	PossibleFmt[0] = { (exe_format)MK_DOS,         "LIBDOS",       nullptr };
	PossibleFmt[1] = { (exe_format)MK_QNX,         "LIBQNX",       new CmdQnx(memory, msg) };
	PossibleFmt[2] = { (exe_format)MK_ELF,         "LIBELF",       new CmdElf(memory, msg) };
	PossibleFmt[3] = { (exe_format)MK_WIN_NE,      "LIBWIN",       new CmdWinOS2(memory, msg, permData) };
	PossibleFmt[4] = { (exe_format)MK_OS2_NE,      "LIBOS2",       new CmdWinOS2(memory, msg, permData) };
	PossibleFmt[5] = { (exe_format)MK_OS2_LE,      "LIBOS2FLAT",   new CmdWinOS2(memory, msg, permData) };
	PossibleFmt[6] = { (exe_format)MK_OS2_LX,      "LIBOS2FLAT",   new CmdWinOS2(memory, msg, permData) };
	PossibleFmt[7] = { (exe_format)MK_PE,          "LIBPE",        new CmdWinOS2(memory, msg, permData) };
	PossibleFmt[8] = { (exe_format)MK_WIN_VXD,     "LIBVXD",       new CmdWinOS2(memory, msg, permData) };
	PossibleFmt[9] = { (exe_format)MK_PHAR_LAP,    "LIBPHAR",      new CmdPharlap(memory, msg) };
	PossibleFmt[10] = { (exe_format)MK_NOVELL,      "LIBNOV",       new CmdNovell(memory, msg) };
}

CmdLine::~CmdLine()
{
}

void CmdLine::CleanSystemList(bool check)
{
	sysblock** sys;
	sysblock* next;
	char* name;

	sys = &SysBlocks;
	while (*sys != NULL) {
		name = (*sys)->name;
		if (!check || (memcmp("286", name, 4) != 0 && memcmp("386", name, 4) != 0)) {
			next = (*sys)->next;
			memory->FreeMemory(name);
			memory->FreeMemory(*sys);
			*sys = next;
		}
		else {
			sys = &(*sys)->next;
		}
	}
}

void CmdLine::BurnSystemList(void)
{
	CleanSystemList(false);
}

void CmdLine::FreePaths(void)
{
	FreeList(memory, Path);
	Path = nullptr;
	if (Name != nullptr) {
		memory->FreeMemory(Name);
		Name = nullptr;
	}
}


void CmdLine::FreeFormatStuff(void)
{
	exe_format possible;

	if (!(LinkState & FMT_DECIDED)) return;
	for (int i = 0; i <= 10; i++) {
		possible = PossibleFmt[i].bits;
		if ((~possible & FmtData.type) == 0) {
			if (PossibleFmt[i].platform != NULL)
				PossibleFmt[i].platform->freeFormat();
			break;
		}
	}
}

void CmdLine::SetSegMask(void)
{
	FmtData.SegShift = 16 - FmtData.Hshift;
	FmtData.SegMask = (1 << FmtData.SegShift) - 1;
}

void CmdLine::ResetCmdFile(void)
{
	SysBlocks = NULL;
	Extension = E_LOAD;
	Name = NULL;
	CmdFlags = CF_UNNAMED;
	Path = NULL;
	memset(&FmtData, 0, sizeof(FmtData));
	FmtData.base = -1;// NO_BASE_SPEC;
	FmtData.objalign = -1;// NO_BASE_SPEC;
	FmtData.type = (exe_format)MK_ALL;
	FmtData.def_seg_flags = SEG_LEVEL_3;
	FmtData.output_raw = false;
	FmtData.output_hex = false;
	FmtData.Hshift = 12;   // May want different value for some 32 bit segmented modes
	FmtData.FillChar = 0;  // Default fillchar for segment alignment
	SetSegMask();
	CurrSect = Root;
	CurrFList = &Root->files;
	DBIFlag = 0;        /*  default is only global information */
}

int CmdLine::_bgetcmd(char* buffer, int len)
{
	int     total;
	int     i;
	char* word;
	char* p = NULL;
	char** argv = &_argv[1];

	--len; // reserve space for NULL byte

	if (buffer && (len > 0)) {
		p = buffer;
		*p = '\0';
	}

	/* create approximation of original command line */
	for (word = *argv++, i = 0, total = 0; word; word = *argv++) {
		i = strlen(word);
		total += i;

		if (p) {
			if (i >= len) {
				strncpy(p, word, len);
				p[len] = '\0';
				p = NULL;
				len = 0;
			}
			else {
				strcpy(p, word);
				p += i;
				len -= i;
			}
		}

		/* account for at least one space separating arguments */
		if (*argv) {
			if (p) {
				*p++ = ' ';
				--len;
			}
			++total;
		}
	}

	return(total);
}

char* CmdLine::getcmd(char* buffer)
{
	_bgetcmd(buffer, INT_MAX);
	return(buffer);
}

void CmdLine::GetCmdLine(char* buff)
{
	getcmd(buff);
}

void CmdLine::NewCommandSource(char* name, char* buff, method how)
{
	cmdfilelist* newfile;

	_ChkAlloc(cmdfilelist*, newfile, sizeof(cmdfilelist));
	newfile->file = stdin;
	if (CmdFile != NULL) {     /* save current state */
		memcpy(&CmdFile->token, &Token, sizeof(tok));
		newfile->next = CmdFile->next;
		if (newfile->next != NULL) {
			newfile->next->prev = newfile;
		}
	}
	else {
		newfile->next = NULL;
	}
	newfile->prev = CmdFile;
	if (newfile->prev != NULL) {
		newfile->prev->next = newfile;
	}
	CmdFile = newfile;
	CmdFile->name = name;
	CmdFile->token.buff = buff;     /* make sure token is freed */
	CmdFile->token.how = how;       /* but only if it needs to be */
	Token.buff = buff;
	Token.next = Token.buff;
	Token.where = MIDST;
	Token.line = 1;
	Token.how = how;
	Token.thumb = OK;
	Token.locked = false;
	Token.quoted = 0;
}

bool CmdLine::IsStdOutConsole(void)
{
	return(_isatty(_fileno(stdout)));
}

void CmdLine::EatWhite(void)
{
	while (IS_WHITESPACE(Token.next)) {
		Token.next++;
	}
}

void CmdLine::Crash(bool check_file)
{
}

void CmdLine::Ignite()
{
}

void CmdLine::Suicide(void)
{
}

bool CmdLine::GetToken(sep_type req, tokcontrol ctrl)
{
	return(GetTokenEx(req, ctrl, NULL, NULL));
}

bool CmdLine::GetTokenEx(sep_type req, tokcontrol ctrl, cmdfilelist* resetpoint, bool* pbreset)
{
	char    hmm;
	bool    ret;
	bool    need_sep;

	if (Token.thumb == REJECT) {
		Token.thumb = OK;
		if (Token.quoted) return(true);
		Token.next = Token.this1;        /* re-process last token */
	}
	need_sep = true;
	for (;;) {                           /* finite state machine */
		if ((Token.skipToNext) && (req == SEP_COMMA)) {
			Token.skipToNext = 0;
			need_sep = false;
		}

		switch (Token.where) {
			case MIDST:
				EatWhite();
				hmm = *Token.next;
				switch (hmm) {
					case CTRLZ:
						Token.where = ENDOFFILE;
						break;
					case '\0':
						if (Token.how == BUFFERED || Token.how == ENVIRONMENT	|| Token.how == SYSTEM) {
							Token.where = ENDOFFILE;
							break;
						}                // NOTE the fall through.
					case '\n':
						if (Token.how == BUFFERED || Token.how == ENVIRONMENT || Token.how == SYSTEM) {
							Token.next++;               // just skip this.
						}
						else if (Token.how == COMMANDLINE) {
							Token.where = ENDOFCMD;
						}
						else {
							Token.where = ENDOFLINE;
						}
						Token.line++;
						break;
					case '@':
						if (req != SEP_SPACE) {
							Token.next++;
							GetToken(SEP_NO, (tokcontrol)(TOK_INCLUDE_DOT | TOK_IS_FILENAME));
							StartNewFile();
							break;
						}
						Token.next--;   /* make a token out of this */
						ret = MakeToken(ctrl, req);
						Token.quoted = 0;
						return(ret);
					case '#':
						Token.where = ENDOFLINE;            /* begin comment */
						Token.line++;
						break;
					case '^':
						if (req != SEP_SPACE) {    /* if not storing system blocks */
							Token.next++;
							BackupParser();
							break;
						}
						Token.next--;   /* make a token out of this */
						ret = MakeToken(ctrl, req);
						Token.quoted = 0;
						return(ret);
					case '%':
						if (req != SEP_SPACE) {
							ExpandEnvVariable();
							break;
						}
					default:
						if (need_sep) {
							if (need_sep != SEP_QUOTE)
								Token.quoted = 0;
							switch (req) {
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
									//if( hmm != '\'' ) return( FALSE );
									if (hmm != Token.quoted) return(FALSE);
									Token.next++;
									//Token.quoted = hmm;
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
						else {                /*  must have good separator here */
							//if( hmm == '\'' && req != SEP_PAREN && req != SEP_SPACE ) {
							if ((hmm == '\'' || hmm == '"') && req != SEP_PAREN && req != SEP_SPACE) {
								req = SEP_QUOTE;   /* token has been quoted */
								Token.next++;      /* don't include the quote */
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
				RestoreCmdLine();
				if (Token.thumb == REJECT) {
					Token.thumb = OK;
					Token.next = Token.this;        /* re-process last token */
				}
				Token.quoted = 0;
				if (resetpoint && (CmdFile == resetpoint)) {
					if (*Token.next == ',')
						break;
					if (pbreset)
						*pbreset = TRUE;            /* Show we have hit a file end-point for a directive */
					return(FALSE);
				}
				break;
			case ENDOFCMD:
				if (CmdFile->next != NULL) {
					RestoreParser();
					break;
				}
				Token.quoted = 0;
				ret = (req == SEP_END) ? TRUE : FALSE;
				return(ret);
		}
	}
}

bool CmdLine::ProcOne(parse_entry* entry, sep_type req, bool suicide)
{
	char* key;
	char* ptr;
	unsigned            plen;
	bool                ret;
	char                keybuff[20];

	ret = GetToken(req, TOK_INCLUDE_DOT);
	if (ret == false) {
		return(ret);
	}
	while (entry->keyword != NULL) {
		key = entry->keyword;
		ptr = Token.this1;
		plen = Token.len;
		for (;;) {
			if (plen == 0 && !isupper(*key)) {
				if (HintFormat(entry->format)) {
					ret = (*entry->rtn)();
					CmdFlags |= entry->flags;
				}
				else {
					strcpy(keybuff, entry->keyword);
					strupr(keybuff); /* jwlink: was strlwr() */
					LnkMsg(LOC + LINE + WRN + MSG_FORMAT_BAD_OPTION, "s", keybuff);
					ret = TRUE;
				}
				return(ret);
			}
			if (*key == '\0' || tolower(*ptr) != tolower(*key)) break;
			ptr++;
			key++;
			plen--;
		}
		/* here if this is no match */
		entry++;
	}
	/* here if no match in table */
	if (suicide) {
		Syntax();
	}
	else {
		Token.thumb = REJECT;       /*  try again later */
		ret = FALSE;
	}
	return(ret);
}

void CmdLine::Help(void)
{
	EatWhite();
	if (*Token.next == '?') {
		Crash(false);
	}
	else if (*Token.next == '\0' || !ProcOne(FormatHelp, SEP_NO, false)) {
		Crash(true);
	}
	else {
		Ignite();
		Suicide();
	}
}

void CmdLine::DoCmdFile(char* fname)
{
	exe_format  possible;
	FileHandle  file;
	size_t      namelen;
	file_defext extension;
	char* namelnk;

	ResetCmdFile();
	if (fname == NULL || *fname == '\0') {
		_ChkAlloc(char*, fname, (10 * 1024));  // arbitrarily large buffer that won't
		GetCmdLine(fname);            // be overflowed
		NewCommandSource(NULL, fname, COMMANDLINE);
	}
	else {
		NewCommandSource(NULL, fname, ENVIRONMENT);
	}
	if (IsStdOutConsole()) {
		CmdFlags = (commandflag)(CmdFlags | CF_TO_STDOUT);
	}
	while (*fname == ' ') {
		fname++;
	}
	if (*fname == '?') {
		Token.next = fname + 1;       // skip question mark.
		Help();
#if defined( __UNIX__ )
	}
	else if (*fname == '-') {
#else
	}
	else if (*fname == '-' || *fname == '/') {
#endif
		if (*(fname + 1) == '?') {
			Token.next = fname + 2;     // skip /?
			Help();
		}
	}
}
