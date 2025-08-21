#pragma once

typedef unsigned char unsigned_8;
typedef unsigned short unsigned_16;
typedef unsigned int unsigned_32;

#define INDENT          "    "
#define INDWIDTH        (sizeof( INDENT ) - 1)
#define BAILOUT         "\n" INDENT "!! "

typedef unsigned_8      byte;

enum {
    LIB_NOT_FOUND = 0,
    LIB_HEADER_REC = 0xf0,
    LIB_TRAILER_REC = 0xf1,
    LIB_FULL_PAGE = 0xff
};

/*
 *  INTEL Object Record Types
 */

typedef enum omf_cmd {
    CMD_MIN_CMD = 0x6e,     /* minimum cmd enum                 */
    CMD_RHEADR = 0x6e,
    CMD_REGINT = 0x70,
    CMD_REDATA = 0x72,
    CMD_RIDATA = 0x74,
    CMD_OVLDEF = 0x76,
    CMD_ENDREC = 0x78,
    CMD_BLKDEF = 0x7a,     /* block definition record          */
    CMD_BLKDEF32 = 0x7b,     /* weird extension for QNX MAX assembler */
    CMD_BLKD32 = 0x7b,     /* weird extension for QNX MAX assembler */
    CMD_BLKEND = 0x7c,     /* block end record                 */
    CMD_BLKEND32 = 0x7d,     /* _might_ be used by QNX MAX assembler */
    CMD_BLKE32 = 0x7d,     /* _might_ be used by QNX MAX assembler */
    CMD_DEBSYM = 0x7e,
    CMD_THEADR = 0x80,     /* header record                    */
    CMD_LHEADR = 0x82,
    CMD_PEDATA = 0x84,
    CMD_PIDATA = 0x86,
    CMD_COMENT = 0x88,     /* comment record                   */
    CMD_MODEND = 0x8a,     /* end of module record             */
    CMD_MODEND32 = 0x8b,     /* 32-bit end of module record      */
    CMD_MODE32 = 0x8b,     /* 32-bit end of module record      */
    CMD_EXTDEF = 0x8c,     /* import names record              */
    CMD_TYPDEF = 0x8e,     /* type definition record           */
    CMD_PUBDEF = 0x90,     /* export names record              */
    CMD_PUBDEF32 = 0x91,     /* 32-bit export names record       */
    CMD_PUBD32 = 0x91,     /* 32-bit export names record       */
    CMD_LOCSYM = 0x92,
    CMD_LINNUM = 0x94,     /* line number record               */
    CMD_LINNUM32 = 0x95,     /* 32-bit line number record.       */
    CMD_LINN32 = 0x95,     /* 32-bit line number record.       */
    CMD_LNAMES = 0x96,     /* list of names record             */
    CMD_SEGDEF = 0x98,     /* segment definition record        */
    CMD_SEGDEF32 = 0x99,     /* 32-bit segment definition        */
    CMD_SEGD32 = 0x99,     /* 32-bit segment definition        */
    CMD_GRPDEF = 0x9a,     /* group definition record          */
    CMD_FIXUPP = 0x9c,     /* relocation record                */
    CMD_FIXUPP32 = 0x9d,     /* 32-bit relocation record         */
    CMD_FIXU32 = 0x9d,     /* 32-bit relocation record         */
    CMD_LEDATA = 0xa0,     /* object record                    */
    CMD_LEDATA32 = 0xa1,     /* 32-bit object record             */
    CMD_LEDA32 = 0xa1,     /* 32-bit object record             */
    CMD_LIDATA = 0xa2,     /* repeated data record             */
    CMD_LIDATA32 = 0xa3,     /* 32-bit repeated data record      */
    CMD_LIDA32 = 0xa3,     /* 32-bit repeated data record      */
    CMD_LIBHED = 0xa4,
    CMD_LIBNAM = 0xa6,
    CMD_LIBLOC = 0xa8,
    CMD_LIBDIC = 0xaa,
    CMD_COMDEF = 0xb0,     /* communal definition              */
    CMD_BAKPAT = 0xb2,     /* backpatch record (for Quick C) */
    CMD_BAKPAT32 = 0xb3,
    CMD_BAKP32 = 0xb3,
    CMD_LEXTDEF = 0xb4,     /*  local import names record */
    CMD_STATIC_EXTDEF = 0xb4,
    CMD_LEXTDEF32 = 0xb5,     /*  32-bit local import names record */
    CMD_STATIC_EXTD32 = 0xb5,
    CMD_LPUBDEF = 0xb6,     /* static export names record */
    CMD_STATIC_PUBDEF = 0xb6,
    CMD_LPUBDEF32 = 0xb7,     /* static export names record */
    CMD_STATIC_PUBD32 = 0xb7,
    CMD_LCOMDEF = 0xb8,     /* local comdev */
    CMD_STATIC_COMDEF = 0xb8,
    CMD_CEXTDEF = 0xbc,     /* external reference to a COMDAT */
    CMD_COMDAT = 0xc2,     /* initialized communal data record */
    CMD_COMDAT32 = 0xc3,     /* initialized 32-bit communal data record */
    CMD_COMD32 = 0xc3,     /* initialized 32-bit communal data record */
    CMD_LINSYM = 0xc4,     /* LINNUM for a COMDAT */
    CMD_LINSYM32 = 0xc5,     /* 32-bit LINNUM for a COMDAT */
    CMD_LINS32 = 0xc5,     /* 32-bit LINNUM for a COMDAT */
    CMD_ALIAS = 0xc6,     /* alias definition record          */
    CMD_NBKPAT = 0xc8,     /* named backpatch record (quick c?) */
    CMD_NBKPAT32 = 0xc9,     /* 32-bit named backpatch record */
    CMD_NBKP32 = 0xc9,     /* 32-bit named backpatch record */
    CMD_LLNAMES = 0xca,     /* a "local" lnames */
    CMD_VERNUM = 0xcc,     /* TIS version number record        */
    CMD_VENDEXT = 0xce,     /* TIS vendor extension record      */
    CMD_MAX_CMD = 0xce      /* maximum cmd enum                 */
} omf_cmd;

typedef enum omf_fix_loc {
    LOC_OFFSET_LO = 0,       /* relocate lo byte of offset             */
    LOC_OFFSET = 1,       /* relocate offset                        */
    LOC_BASE = 2,       /* relocate segment                       */
    LOC_BASE_OFFSET = 3,       /* relocate segment and offset            */
    LOC_OFFSET_HI = 4,       /* relocate hi byte of offset             */
    LOC_OFFSET_LOADER = 5,       /* like OFFSET but loader resolved        */
    LOC_OFFSET_32 = 9,       /* relocate 32-bit offset                 */
    LOC_BASE_OFFSET_32 = 11,      /* relocate 48-bit pointer                */
    LOC_OFFSET_LOADER_32 = 13       /* like 32-bit offset but loader resolved */
} omf_fix_loc;

/*
    Output routines (output.c)
*/
extern  void            OutputInit(void);
extern  void            OutputFini(void);
extern  void            OutputSetFH(FILE*);
extern  size_t          Output(const char* fmt, ...);
extern  size_t          OutputNL(void);
extern  void            OutputData(unsigned_32 off, unsigned_32 len);

extern  bool            no_disp;

/*
    Object reading (objread.c)
*/
typedef byte* data_ptr;

typedef struct Lnamelist {
    struct Lnamelist* next;
    byte                 LnameLen;
    byte                 Lname; // really LnameLen bytes ( can be ZERO )
} Lnamelist;

typedef struct Segdeflist {
    struct Segdeflist* next;
    unsigned             segidx;        /* into lnames                      */
} Segdeflist;

#define MAXGRPSEGS      64
typedef struct Grpdeflist {
    struct Grpdeflist* next;
    unsigned             grpidx;        /* into Lnames  for grpname         */
    unsigned             segidx[MAXGRPSEGS];  /* into segdefs for members */
} Grpdeflist;

extern  data_ptr        NamePtr;
extern  byte            NameLen;
extern  unsigned_16     RecLen;
extern  data_ptr        RecBuff;
extern  data_ptr        RecPtr;
extern  unsigned_16     RecMaxLen;
extern  unsigned        Grpindex;
extern  unsigned        Segindex;
extern  unsigned        Nameindex;
extern  unsigned        Importindex;
extern  unsigned        Libindex;
extern  bool            IsPharLap;
extern  bool            IsMS386;
extern  bool            IsIntel;
extern  bool            DumpRaw;
//extern  jmp_buf         BailOutJmp;
extern  char            ProvideRawTypes[];
extern  char            OmitTypes[];
extern  bool            IgnoreOutput;
extern  byte            rec_type[];
extern  int             rec_count;

extern  bool            EndRec(void);
extern  unsigned_16     RecOffset(void);
extern  byte            GetByte(void);
extern  void            BackupByte(void);
extern  unsigned_16     GetUInt(void);
extern  unsigned_32     GetLInt(void);
extern  unsigned_32     GetEither(void);
extern  byte            GetName(void);       /* length prefixed name     */
extern  unsigned        GetIndex(void);
extern  unsigned_32     GetVariable(void);
extern  void            ResizeBuff(unsigned_16 reqd_len);
extern  void            ProcFile(FILE* fp, bool);
extern  byte            RecNameToNumber(char* name);
extern  const char* RecNumberToName(byte code);

extern  void            AddLname(void);
extern  char* GetLname(unsigned idx);
extern  void            AddSegdef(unsigned idx);
extern  Segdeflist* GetSegdef(unsigned idx);
extern  void            AddGrpdef(unsigned grpidx, unsigned segidx);
extern  Grpdeflist* GetGrpdef(unsigned idx);
extern  unsigned        GetGrpseg(unsigned idx);
extern  void            AddXname(void);
extern  char* GetXname(unsigned idx);
/*
    Record processing routines
*/
extern  void            ProcEndRec(void);
extern  void            ProcTHeadr(int);
extern  void            ProcLHeadr(void);
extern  void            ProcRHeadr(void);
extern  void            ProcComent(void);
extern  void            ProcNames(unsigned*);
extern  void            ProcLNames(unsigned*);
extern  void            ProcExtNames(void);
extern  void            ProcModEnd(void);
extern  void            ProcSegDefs(void);
extern  void            ProcLocSyms(void);
extern  void            ProcPubDefs(void);
extern  void            ProcComDef(void);
extern  void            ProcLinNums(void);
extern  void            ProcLidata(void);
extern  void            ProcLedata(void);
extern  void            ProcFixup(void);
extern  void            ProcGrpDef(void);
extern  void            ProcLibHeader(void);
extern  void            ProcLibTrailer(FILE* fp);
extern  void            ProcBackPat(void);
extern  void            ProcNameBackPat(void);
extern  void            ProcComExtDef(void);
extern  void            ProcComDat(void);
extern  void            ProcLineSym(void);
extern  void            ProcAlias(void);
extern  void            ProcVerNum(void);
extern  void            ProcVendExt(void);

/*
    Misc routines (dmpobj.c)
*/
extern  bool            Descriptions;
extern  bool            InterpretComent;
extern  bool            TranslateIndex;
