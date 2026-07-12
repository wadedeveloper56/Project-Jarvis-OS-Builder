#include "pch.h"
#include "MemorySubsystem.h"
#include "MessagingSubsystem.h"
#include "cmdline.h"
#include "Structs.h"
#include "globals.h"
#include "Linkutil.h"
#include "cmd16m.h"
#include "cmdqnx.h"
#include "cmdelf.h"
#include "cmdos2.h"
#include "cmddos.h"
#include "cmdphar.h"
#include "cmdnov.h"
#include "ntio.h"
#include "cmdutils.h"
#include "loadfile.h"
#include "debug.h"
#include "dbgall.h"
#include "cmdall.h"
#include "symtrace.h"
#include "overlays.h"

using namespace std;

const int htopics[] = {
#if defined( _QNXLOAD ) && defined( __QNX__ )
    MSG_QNX_HELP_0, MSG_QNX_HELP_LAST,
#endif
#ifdef _EXE
    MSG_DOS_HELP_0, MSG_DOS_HELP_LAST,
#endif
#ifdef _OS2
    MSG_OS2_HELP_0, MSG_OS2_HELP_LAST,
    MSG_WINDOWS_HELP_0, MSG_WINDOWS_HELP_LAST,
    MSG_WIN_VXD_HELP_0, MSG_WIN_VXD_HELP_LAST,
    MSG_NT_HELP_0, MSG_NT_HELP_LAST,
#endif
#ifdef _PHARLAP
    MSG_PHAR_HELP_0, MSG_PHAR_HELP_LAST,
#endif
#ifdef _NOVELL
    MSG_NOVELL_HELP_0, MSG_NOVELL_HELP_LAST,
#endif
#ifdef _DOS16M
    MSG_DOS16_HELP_0, MSG_DOS16_HELP_LAST,
#endif
#if defined( _QNXLOAD ) && !defined( __QNX__ )
    MSG_QNX_HELP_0, MSG_QNX_HELP_LAST,
#endif
#ifdef _ELF
    MSG_ELF_HELP_0, MSG_ELF_HELP_LAST,
#endif
#ifdef _RAW
    MSG_RAW_HELP_0, MSG_RAW_HELP_LAST,
#endif
};

#define NUMHTOPICS ( sizeof( htopics ) / ( sizeof( htopics[0] * 2 ) ) )

bool             ProcDosHelp(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem);
bool             ProcOS2Help(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem);
bool             ProcPharHelp(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem);
bool             ProcNovellHelp(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem);
bool             Proc16MHelp(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem);
bool             ProcQNXHelp(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem);
bool             ProcELFHelp(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem);
bool             ProcWindowsHelp(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem);
bool             ProcWinVxdHelp(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem);
bool             ProcNTHelp(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem);
bool             ProcRawHelp(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem);
void             WriteHelp(unsigned first_ln, unsigned last_ln, bool prompt);
void             GetExtraCommands(void);

 parse_entry   FormatHelp[] = {
    "Dos",          ProcDosHelp,            MK_ALL,     (commandflag)0,
#ifdef _OS2
    "OS2",          ProcOS2Help,            MK_ALL,     (commandflag)0,
    "WINdows",      ProcWindowsHelp,        MK_ALL,     (commandflag)0,
    "VXD",          ProcWinVxdHelp,         MK_ALL,     (commandflag)0,
    "PE",           ProcNTHelp,             MK_ALL,     (commandflag)0,
#endif
#ifdef _PHARLAP
    "PHARlap",      ProcPharHelp,           MK_ALL,     (commandflag)0,
#endif
#ifdef _NOVELL
    "NOVell",       ProcNovellHelp,         MK_ALL,     (commandflag)0,
#endif
#ifdef _DOS16M
    "DOS16M",       Proc16MHelp,            MK_ALL,     (commandflag)0,
#endif
#ifdef _QNXLOAD
    "QNX",          ProcQNXHelp,            MK_ALL,     (commandflag)0,
#endif
#ifdef _ELF
    "ELF",          ProcELFHelp,            MK_ALL,     (commandflag)0,
#endif
#ifdef _RAW
    "Raw",          ProcRawHelp,            MK_ALL,     (commandflag)0,
#endif
    NULL
};

file_defext     Extension;
file_list** CurrFList;
tok             Token;
commandflag     CmdFlags;
char* Name;
sysblock* SysBlocks;
sysblock* LinkCommands;
sysblock* PrevCommand;

struct select_format
{
	exe_format bits;
	char* lib_var_name;
	void (*set_func)(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem);
	void (*free_func)(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem);
};

struct select_format PossibleFmt[] =
{
	(exe_format)MK_DOS,         "LIBDOS",       NULL,           NULL,
#ifdef _DOS16M
				MK_DOS16M,      "LIBDOS16M",    SetD16MFmt,     FreeD16MFmt,
#endif
#ifdef _QNXLOAD
	(exe_format)MK_QNX,         "LIBQNX",       SetQNXFmt,      FreeQNXFmt,
#endif
#ifdef _ELF
				MK_ELF,         "LIBELF",       SetELFFmt,      FreeELFFmt,
#endif
#ifdef _OS2
				MK_WIN_NE,      "LIBWIN",       SetOS2Fmt,      FreeOS2Fmt,
				MK_OS2_NE,      "LIBOS2",       SetOS2Fmt,      FreeOS2Fmt,
				MK_OS2_LE,      "LIBOS2FLAT",   SetOS2Fmt,      FreeOS2Fmt,
				MK_OS2_LX,      "LIBOS2FLAT",   SetOS2Fmt,      FreeOS2Fmt,
				MK_PE,          "LIBPE",        SetOS2Fmt,      FreeOS2Fmt,
				MK_WIN_VXD,     "LIBVXD",       SetOS2Fmt,      FreeOS2Fmt,
#endif
#ifdef _PHARLAP
	(exe_format)MK_PHAR_LAP,    "LIBPHAR",      SetPharFmt,     FreePharFmt,
#endif
#ifdef _NOVELL
				MK_NOVELL,      "LIBNOV",       SetNovFmt,      FreeNovFmt,
#endif
};

#define NUMPOSSIBLEFMT ( sizeof( PossibleFmt ) / sizeof ( PossibleFmt[0] ) )

#define INIT_FILE_NAME  "jwlink.lnk"
#define INIT_FILE_ENV   "JWLINK_LNK"

void FreeFormatStuff(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem)
{
	int i;
	exe_format                  possible;

	if (!(LinkState & FMT_DECIDED)) return;
	for (i = 0; i < NUMPOSSIBLEFMT; i++)
	{
		possible = PossibleFmt[i].bits;
		if ((~possible & FmtData.type) == 0)
		{
			if (PossibleFmt[i].free_func != NULL)
				PossibleFmt[i].free_func(memorySubsystem, messagingSubsystem);
			break;
		}
	}
}

void InitCmdFile()
{
	PrevCommand = NULL;
}

char* GetNextLink()
{
	return(NULL);
}

void CleanSystemList(MemorySubsystem* memory, bool check)
{
	sysblock** sys;
	sysblock* next;
	char* name;

	sys = &SysBlocks;
	while (*sys != NULL)
	{
		name = (*sys)->name;
		if (!check
			|| (memcmp("286", name, 4) != 0 && memcmp("386", name, 4) != 0))
		{
			next = (*sys)->next;
			memory->FreeMemory(name);
			memory->FreeMemory(*sys);
			*sys = next;
		}
		else
		{
			sys = &(*sys)->next;
		}
	}
}

void PruneSystemList(MemorySubsystem* memory)
{
	CleanSystemList(memory, true);
}

void BurnSystemList(MemorySubsystem* memory)
{
	CleanSystemList(memory, false);
}

void FreePaths(MemorySubsystem* memory)
{
	FreeList(memory, Path);
	Path = NULL;
	if (Name != NULL)
	{
		memory->FreeMemory(Name);
		Name = NULL;
	}
}

void SetSegMask()
{
    FmtData.SegShift = 16 - FmtData.Hshift;
    FmtData.SegMask = (1 << FmtData.SegShift) - 1;
}

void ResetCmdFile(void)
{
    SysBlocks = NULL;
    Extension = E_LOAD;
    Name = NULL;
    CmdFlags = CF_UNNAMED;
    Path = NULL;
    memset(&FmtData, 0, sizeof(FmtData));
    FmtData.base = NO_BASE_SPEC;
    FmtData.objalign = NO_BASE_SPEC;
    FmtData.type = (exe_format)0;
    FmtData.def_seg_flags = SEG_LEVEL_3;
    FmtData.output_raw = FALSE;
    FmtData.output_hex = FALSE;
    FmtData.Hshift = 12;             
    FmtData.FillChar = 0;       
    SetSegMask();
    CurrSect = Root;
    CurrFList = (file_list**) & Root->files;
    DBIFlag = 0;               
}

bool IsStdOutConsole()
{
    return(QIsDevice(STDOUT_HANDLE));
}

void Burn(MemorySubsystem* memorySubsystem,FileSubsystem* fileSubsystem,MessagingSubsystem* messagingSubsystem)
{
    FreePaths(memorySubsystem);
    if (MapFName != NULL)
    {
        _LnkFree(MapFName);
        MapFName = NULL;
    }
    FreeOutFiles(fileSubsystem, memorySubsystem);
    BurnUtils(memorySubsystem, messagingSubsystem);
}

void Ignite(MemorySubsystem* memorySubsystem, FileSubsystem* fileSubsystem, MessagingSubsystem* messagingSubsystem)
{
    BurnSystemList(memorySubsystem);
    Burn(memorySubsystem, fileSubsystem, messagingSubsystem);
}

void WriteMsg(char msg_buffer[])
{
    WriteStdOut(msg_buffer);
    WriteNLStdOut();
}

void PressKey(MemorySubsystem *memorySubsystem, MessagingSubsystem *messagingSubsystem, FileSubsystem *fileSubsystem)
{
    char        msg_buffer[RESOURCE_MAX_SIZE];
    char        result;

    messagingSubsystem->Msg_Get(MSG_PRESS_KEY, msg_buffer);
    WriteStdOut(msg_buffer);
    result = WaitForKey();
    WriteNLStdOut();
    if (tolower(result) == 'q')
    {
        Ignite(memorySubsystem, fileSubsystem, messagingSubsystem);
        Suicide();
    }
}

void WriteHelp(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem, unsigned first_ln, unsigned last_ln, bool prompt)
{
    char        msg_buffer[RESOURCE_MAX_SIZE];
    int         previous_null = 0;

    for (; first_ln <= last_ln; first_ln++)
    {
        messagingSubsystem->Msg_Get((int)first_ln, msg_buffer);
        if (previous_null)
        {
            if (msg_buffer[0] != '\0')
            {
#ifndef __UNIX__
                PressKey(memorySubsystem, messagingSubsystem, fileSubsystem );
#endif
                WriteMsg(msg_buffer);
                previous_null = 0;
            }
            else break;
        }
        else if (msg_buffer[0] == '\0')
        {
            if (prompt)
                previous_null = 1;
        }
        else
        {
            WriteMsg(msg_buffer);
        }
    }
}

void WriteGenHelp(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem)
{
    messagingSubsystem->WLPrtBanner();
    WriteHelp(memorySubsystem, messagingSubsystem, fileSubsystem, MSG_GENERAL_HELP_0, MSG_GENERAL_HELP_LAST, CmdFlags & CF_TO_STDOUT);
}

void DisplayOptions(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem)
{
    int i;

    WriteGenHelp(memorySubsystem, messagingSubsystem, fileSubsystem);
    for (i = 0; i < NUMHTOPICS; i += 2)
    {
#ifndef __UNIX__
        if (i && (CmdFlags & CF_TO_STDOUT))
            PressKey(memorySubsystem, messagingSubsystem, fileSubsystem);
#endif
        WriteHelp(memorySubsystem, messagingSubsystem, fileSubsystem, htopics[i], htopics[i + 1], CmdFlags & CF_TO_STDOUT);
    }
}

void Crash(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem, bool check_file)
{
    char        buff[81];
    unsigned    len;
    f_handle    fp;

    if (check_file)
    {
        fp = SearchPath(fileSubsystem, "wlink.hlp");
        if (fp != NIL_HANDLE)
        {
            messagingSubsystem->WLPrtBanner();
            for (;; )
            {
                len = QRead(fp, buff, 80, "wlink.hlp");
                if (len == 0) break;
                buff[len] = '\0';
                WriteStdOut(buff);
            }
            QClose(fp, "wlink.hlp");
            Ignite(memorySubsystem, fileSubsystem, messagingSubsystem);
            Suicide();
        }
    }
    DisplayOptions(memorySubsystem, messagingSubsystem, fileSubsystem);
    Ignite(memorySubsystem, fileSubsystem, messagingSubsystem);
    Suicide();
}

void Help(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem)
{
    EatWhite();
    if (*Token.next == '?')
    {
        Crash(memorySubsystem, messagingSubsystem, fileSubsystem, FALSE);
    }
    else if (*Token.next == '\0' || !ProcOne(memorySubsystem, messagingSubsystem, fileSubsystem, FormatHelp, SEP_NO, FALSE))
    {
        Crash(memorySubsystem, messagingSubsystem, fileSubsystem, TRUE);
    }
    else
    {
        Ignite(memorySubsystem, fileSubsystem, messagingSubsystem);
        Suicide();
    }
}

void InitFmt(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem,void (*set)(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem))
{
    if (LinkState & FMT_INITIALIZED) return;
    if (set != NULL) set(memorySubsystem, messagingSubsystem);
    LinkState |= FMT_INITIALIZED;
}

void AddLibPaths(MemorySubsystem* memorySubsystem, char* name, unsigned len, bool add_to_front)
{
    path_entry* newpath;
    file_list const* libfiles;

    _LnkAlloc(path_entry*, newpath, sizeof(path_entry) + len);
    memcpy(newpath->name, name, len);
    newpath->name[len] = '\0';
    if (add_to_front)
    {
        newpath->next = LibPath;
        LibPath = newpath;
    }
    else
    {
        LinkList(&LibPath, newpath);
    }
    if (LibPath == newpath)
    {
        libfiles = ObjLibFiles;
        while (libfiles != NULL)
        {
            libfiles->file->path_list = LibPath;
            libfiles = (file_list*) libfiles->next_file;
        }
        libfiles = (file_list*) Root->files;
        while (libfiles != NULL && libfiles->file->flags & INSTAT_USE_LIBPATH)
        {
            libfiles->file->path_list = LibPath;
            libfiles = (file_list*) libfiles->next_file;
        }
    }
}

void AddEnvPaths(MemorySubsystem* memorySubsystem, char* envname)
{
    char* const        val = GetEnvString(envname);
    unsigned            len;

    if (val == NULL)
        return;
    len = strlen(val);
    AddLibPaths(memorySubsystem, val, len, FALSE);
}

void AddFmtLibPaths(MemorySubsystem* memorySubsystem)
{
    int i;
    exe_format                  possible;

    if (!(LinkState & FMT_DECIDED)) return;
    for (i = 0; i < NUMPOSSIBLEFMT; i++)
    {
        possible = PossibleFmt[i].bits;
        if ((~possible & FmtData.type) == 0)
        {
            AddEnvPaths(memorySubsystem, PossibleFmt[i].lib_var_name);
            break;
        }
    }
}

bool HintFormat(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem,exe_format hint)
{
    int i;
    exe_format                  possible;

    DEBUG((DBG_BASE, "HintFormat(%h): enter FmtData.type=%h", hint, FmtData.type));
    if (!(hint & FmtData.type))
        return(FALSE);
    DO_AND_EQUAL(exe_format, FmtData.type, &=, hint);
    if (LinkState & FMT_DECIDED)
        return(TRUE);
    for (i = 0; i < NUMPOSSIBLEFMT; i++)
    {
        possible = PossibleFmt[i].bits;
        if ((~possible & FmtData.type) == 0)
        {
            DEBUG((DBG_BASE, "HintFormat(%h): format %h found", hint, possible));
            InitFmt(memorySubsystem, messagingSubsystem, PossibleFmt[i].set_func);
            LinkState |= FMT_DECIDED;
            if (LinkState & SEARCHING_LIBRARIES)
                AddFmtLibPaths(memorySubsystem);
            return(TRUE);
        }
    }
#ifdef _OS2
    if ((~(MK_OS2 | MK_PE | MK_WIN_VXD) & FmtData.type) == 0)
    {
        DEBUG((DBG_BASE, "HintFormat(%h): calling InitFmt()", hint));
        InitFmt(memorySubsystem, messagingSubsystem, SetOS2Fmt);
    }
#endif
    return(TRUE);
}

void GetExtraCommands(void)
{
    struct extra_cmd_info const* cmd;
    //char                                buff[_MAX_PATH + PREFIX_SIZE];

    //cmd = ExtraCmds;
    //while (cmd->prefix[0] != '\0')
    //{
    //    for (;;)
    //    {
    //        memcpy(buff, cmd->prefix, PREFIX_SIZE);
    //        if (!GetAddtlCommand(cmd->type, buff + PREFIX_SIZE)) break;
    //        NewCommandSource(NULL, buff, COMMANDLINE);
    //        if (Spawn(DoCmdParse)) break;
    //        if (!cmd->retry) break;
    //    }
    //    cmd++;
    //}

}


void DoCmdFile(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem, SpillFile* spillFile, char*** _argv, char* fname)
{
    exe_format  possible;
    f_handle    file;
    size_t      namelen;
    file_defext extension;
    char* namelnk;

    ResetCmdFile();
    if (fname == NULL || *fname == '\0')
    {
        _LnkAlloc(char *, fname, (10 * 1024));
        GetCmdLine(_argv, fname);              
        NewCommandSource(memorySubsystem, NULL, fname, COMMANDLINE);
    }
    else
    {
        NewCommandSource(memorySubsystem, NULL, fname, ENVIRONMENT);
    }
    if (IsStdOutConsole())
    {
        DO_OR_EQUAL(commandflag, CmdFlags, |=, CF_TO_STDOUT);
    }
    while (*fname == ' ')
    {
        fname++;
    }
    if (QSysHelp(&Token.next))
    {
        Help(memorySubsystem, messagingSubsystem, fileSubsystem);
    }
    if (*fname == '?')
    {
        Token.next = fname + 1;          
        Help(memorySubsystem, messagingSubsystem, fileSubsystem);
#if defined( __UNIX__ )
    }
    else if (*fname == '-')
    {
#else
    }
    else if (*fname == '-' || *fname == '/')
    {
#endif
        if (*(fname + 1) == '?' || *(fname + 1) == 'h')
        {
            Token.next = fname + 2;       
            Help(memorySubsystem, messagingSubsystem, fileSubsystem );
        }
    }
    if (*fname == '\0')
    {           
        Token.how = INTERACTIVE;
        Token.where = ENDOFLINE;
        messagingSubsystem->LnkMsg(INF + MSG_PRESS_CTRL_Z, NULL);
    }
    namelnk = GetEnvString(INIT_FILE_ENV);
    file = (namelnk != NULL) ? SearchPath(fileSubsystem, namelnk) : NIL_HANDLE;
    if (file == NIL_HANDLE)
    {
        namelnk = INIT_FILE_NAME;
        file = SearchPath(fileSubsystem, namelnk);
    }
    if (file != NIL_HANDLE)
    {
        fname = ChkStrDup(memorySubsystem, namelnk);
        SetCommandFile(memorySubsystem, file, fname);
    }
    GetExtraCommands();
    if (!(LinkState & FMT_DECIDED))
    {
#if defined( __QNX__ )
#define LAST_CHANCE ( MK_OS2_LX | MK_OS2_LE | MK_OS2_NE | MK_QNX )
#elif defined( __LINUX__ )
#define LAST_CHANCE ( MK_OS2_LX | MK_OS2_LE | MK_OS2_NE | MK_ELF )
#elif defined( __NT__ )
#define LAST_CHANCE ( MK_OS2_LX             | MK_OS2_NE | MK_WIN_NE | MK_PE | MK_DOS_EXE | MK_WIN_VXD )
#else
#define LAST_CHANCE ( MK_OS2_LX | MK_OS2_LE | MK_OS2_NE | MK_DOS_EXE | MK_PHAR_SIMPLE )
#endif
        DEBUG((DBG_BASE, "DoCmdFile: calling HintFormat(LAST_CHANCE)"));
        HintFormat(memorySubsystem, messagingSubsystem, (exe_format)LAST_CHANCE);
    }
    else
    {
        for (possible = (exe_format)1; possible != 0; possible = (exe_format)(possible + 2))
        {
            if (FmtData.type & possible)
            {
                FmtData.type = possible;
                break;
            }
        }
    }
    if (FmtData.type & (MK_NOVELL | MK_DOS) && LinkFlags & INC_LINK_FLAG)
    {
        messagingSubsystem->LnkMsg(FTL + MSG_FORMAT_BAD_OPTION, "s", "incremental");
    }
#ifdef _NOVELL
    if (FmtData.type & MK_NOVELL)
    {
        CmdNovFini(memorySubsystem, messagingSubsystem);
    }
    else
#endif
        if (FmtData.type & MK_OVERLAYS)
        {
            CmdOvlFini(memorySubsystem, fileSubsystem, messagingSubsystem);
            AddObjLib(memorySubsystem, "wovl.lib", LIB_PRIORITY_MIN);          
        }
    if (Name == NULL || !(CmdFlags & CF_HAVE_FILES))
    {
        Ignite(memorySubsystem, fileSubsystem, messagingSubsystem);
        messagingSubsystem->LnkMsg(FTL + MSG_NO_FILES_FOUND, NULL);
    }
    namelen = strlen(Name);
    if (MapFlags & MAP_FLAG)
    {
        if (MapFName == NULL)
        {
            MapFName = FileName(memorySubsystem, messagingSubsystem, Name, namelen, E_MAP, TRUE);
        }
    }
    else
    {
        MapFlags = (mapflag)0;
    }
    if (SymFileName == NULL && (CmdFlags & CF_SEPARATE_SYM ||
        (LinkFlags & OLD_DBI_FLAG && FmtData.type & MK_COM)))
    {
        SymFileName = FileName(memorySubsystem, messagingSubsystem, Name, namelen, E_SYM, TRUE);
    }
    if (FmtData.make_implib && FmtData.implibname == NULL)
    {
        if (FmtData.make_impfile)
        {
            extension = E_LBC;
        }
        else
        {
            extension = E_LIBRARY;
        }
        FmtData.implibname = FileName(memorySubsystem, messagingSubsystem, Name, namelen, extension, TRUE);
    }
    CheckTraces(memorySubsystem, spillFile, messagingSubsystem);
    BurnUtils(memorySubsystem, messagingSubsystem);
    PruneSystemList(memorySubsystem);
    NumberSections(memorySubsystem, spillFile);
    DBIInit(memorySubsystem);
}

#ifdef _EXE
 bool ProcDosHelp(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem)
{
    WriteGenHelp(memorySubsystem, messagingSubsystem, fileSubsystem);
    WriteHelp(memorySubsystem, messagingSubsystem, fileSubsystem, MSG_DOS_HELP_0, MSG_DOS_HELP_LAST, CmdFlags & CF_TO_STDOUT);
    return(TRUE);
}
#endif
#ifdef _OS2
 bool ProcOS2Help(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem)
{
    WriteGenHelp(memorySubsystem, messagingSubsystem, fileSubsystem);
    WriteHelp(memorySubsystem, messagingSubsystem, fileSubsystem, MSG_OS2_HELP_0, MSG_OS2_HELP_LAST, CmdFlags & CF_TO_STDOUT);
    return(TRUE);
}

 bool ProcWindowsHelp(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem)
{
    WriteGenHelp(memorySubsystem, messagingSubsystem, fileSubsystem);
    WriteHelp(memorySubsystem, messagingSubsystem, fileSubsystem, MSG_WINDOWS_HELP_0, MSG_WINDOWS_HELP_LAST,
        CmdFlags & CF_TO_STDOUT);
    return(TRUE);
}

 bool ProcWinVxdHelp(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem)
{
    WriteGenHelp(memorySubsystem, messagingSubsystem, fileSubsystem);
    WriteHelp(memorySubsystem, messagingSubsystem, fileSubsystem, MSG_WIN_VXD_HELP_0, MSG_WIN_VXD_HELP_LAST,
        CmdFlags & CF_TO_STDOUT);
    return(TRUE);
}

bool ProcNTHelp(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem)
{
    WriteGenHelp(memorySubsystem, messagingSubsystem, fileSubsystem);
    WriteHelp(memorySubsystem, messagingSubsystem, fileSubsystem, MSG_NT_HELP_0, MSG_NT_HELP_LAST, CmdFlags & CF_TO_STDOUT);
    return(TRUE);
}
#endif
#ifdef _PHARLAP
 bool ProcPharHelp(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem)
{
    WriteGenHelp(memorySubsystem, messagingSubsystem, fileSubsystem);
    WriteHelp(memorySubsystem, messagingSubsystem, fileSubsystem, MSG_PHAR_HELP_0, MSG_PHAR_HELP_LAST, CmdFlags & CF_TO_STDOUT);
    return(TRUE);
}
#endif
#ifdef _NOVELL
 bool ProcNovellHelp(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem)
{
    WriteGenHelp(memorySubsystem, messagingSubsystem, fileSubsystem);
    WriteHelp(memorySubsystem, messagingSubsystem, fileSubsystem, MSG_NOVELL_HELP_0, MSG_NOVELL_HELP_LAST,
        CmdFlags & CF_TO_STDOUT);
    return(TRUE);
}
#endif
#ifdef _DOS16M
 bool Proc16MHelp(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem)
{
    WriteGenHelp(memorySubsystem, messagingSubsystem, fileSubsystem);
    WriteHelp(memorySubsystem, messagingSubsystem, fileSubsystem, MSG_DOS16_HELP_0, MSG_DOS16_HELP_LAST, CmdFlags & CF_TO_STDOUT);
    return(TRUE);
}
#endif
#ifdef _QNXLOAD
 bool ProcQNXHelp(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem)
{
    WriteGenHelp(memorySubsystem, messagingSubsystem, fileSubsystem);
    WriteHelp(memorySubsystem, messagingSubsystem, fileSubsystem, MSG_QNX_HELP_0, MSG_QNX_HELP_LAST, CmdFlags & CF_TO_STDOUT);
    return(TRUE);
}
#endif

#ifdef _ELF
 bool ProcELFHelp(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem)
{
    WriteGenHelp(memorySubsystem, messagingSubsystem, fileSubsystem);
    WriteHelp(memorySubsystem, messagingSubsystem, fileSubsystem,   MSG_ELF_HELP_0, MSG_ELF_HELP_LAST, CmdFlags & CF_TO_STDOUT);
    return(TRUE);
}
#endif

#ifdef _RAW
 bool ProcRawHelp(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem)
{
    WriteGenHelp(memorySubsystem, messagingSubsystem, fileSubsystem);
    WriteHelp(memorySubsystem, messagingSubsystem, fileSubsystem, MSG_RAW_HELP_0, MSG_RAW_HELP_LAST, CmdFlags & CF_TO_STDOUT);
    return(TRUE);
}
#endif

