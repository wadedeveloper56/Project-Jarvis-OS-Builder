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
    PossibleFmt[10]= { (exe_format)MK_NOVELL,      "LIBNOV",       new CmdNovell(memory, msg) };
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

void CmdLine::DoCmdFile(char* fname)
{
    exe_format  possible;
    FileHandle  file;
    size_t      namelen;
    file_defext extension;
    char* namelnk;

    ResetCmdFile();
    if (fname == NULL || *fname == '\0') {
        _ChkAlloc(char *, fname, (10 * 1024));  // arbitrarily large buffer that won't
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
}
