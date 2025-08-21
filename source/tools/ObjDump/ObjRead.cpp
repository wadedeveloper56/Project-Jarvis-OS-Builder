#include "pch.h"
#include "ObjDump.h"

data_ptr    NamePtr;
byte        NameLen;
unsigned_16 RecLen;
data_ptr    RecBuff;
data_ptr    RecPtr;
unsigned_16 RecMaxLen;
unsigned    RecNum;
unsigned    Grpindex;
unsigned    Segindex;
unsigned    Nameindex;
unsigned    Importindex;
unsigned    Libindex;
bool        IsPharLap;
bool        IsMS386;
bool        IsIntel;
bool        DumpRaw;
//jmp_buf     BailOutJmp;
byte        rec_type[10] = { 0 };
int         rec_count = 0;
Lnamelist* Lnames;
Lnamelist* lastLname;
Lnamelist* Xnames;
Lnamelist* lastXname;
Grpdeflist* Grpdefs;
Segdeflist* Segdefs;

unsigned_16 RecOffset(void)
{
    return((unsigned_16)(RecPtr - RecBuff));
}

byte RecNameToNumber(char* name)
{
    if (_strnicmp(name, "RHEADR", 6) == 0) {
        return(CMD_RHEADR);
    }
    else if (_strnicmp(name, "REGINT", 6) == 0) {
        return(CMD_REGINT);
    }
    else if (_strnicmp(name, "REDATA", 6) == 0) {
        return(CMD_REDATA);
    }
    else if (_strnicmp(name, "RIDATA", 6) == 0) {
        return(CMD_RIDATA);
    }
    else if (_strnicmp(name, "OVLDEF", 6) == 0) {
        return(CMD_OVLDEF);
    }
    else if (_strnicmp(name, "ENDREC", 6) == 0) {
        return(CMD_ENDREC);
    }
    else if (_strnicmp(name, "BLKDEF", 6) == 0) {
        return(CMD_BLKDEF);
    }
    else if (_strnicmp(name, "BLKEND", 6) == 0) {
        return(CMD_BLKEND);
    }
    else if (_strnicmp(name, "DEBSYM", 6) == 0) {
        return(CMD_DEBSYM);
    }
    else if (_strnicmp(name, "THEADR", 6) == 0) {
        return(CMD_THEADR);
    }
    else if (_strnicmp(name, "LHEADR", 6) == 0) {
        return(CMD_LHEADR);
    }
    else if (_strnicmp(name, "PEDATA", 6) == 0) {
        return(CMD_PEDATA);
    }
    else if (_strnicmp(name, "PIDATA", 6) == 0) {
        return(CMD_PIDATA);
    }
    else if (_strnicmp(name, "COMENT", 6) == 0) {
        return(CMD_COMENT);
    }
    else if (_strnicmp(name, "MODEND", 6) == 0) {
        return(CMD_MODEND);
    }
    else if (_strnicmp(name, "EXTDEF", 6) == 0) {
        return(CMD_EXTDEF);
    }
    else if (_strnicmp(name, "TYPDEF", 6) == 0) {
        return(CMD_TYPDEF);
    }
    else if (_strnicmp(name, "PUBDEF", 6) == 0) {
        return(CMD_PUBDEF);
    }
    else if (_strnicmp(name, "LOCSYM", 6) == 0) {
        return(CMD_LOCSYM);
    }
    else if (_strnicmp(name, "LINNUM", 6) == 0) {
        return(CMD_LINNUM);
    }
    else if (_strnicmp(name, "LNAMES", 6) == 0) {
        return(CMD_LNAMES);
    }
    else if (_strnicmp(name, "SEGDEF", 6) == 0) {
        return(CMD_SEGDEF);
    }
    else if (_strnicmp(name, "GRPDEF", 6) == 0) {
        return(CMD_GRPDEF);
    }
    else if (_strnicmp(name, "FIXUPP", 6) == 0) {
        return(CMD_FIXUPP);
    }
    else if (_strnicmp(name, "LEDATA", 6) == 0) {
        return(CMD_LEDATA);
    }
    else if (_strnicmp(name, "LIDATA", 6) == 0) {
        return(CMD_LIDATA);
    }
    else if (_strnicmp(name, "LIBHED", 6) == 0) {
        return(CMD_LIBHED);
    }
    else if (_strnicmp(name, "LIBNAM", 6) == 0) {
        return(CMD_LIBNAM);
    }
    else if (_strnicmp(name, "LIBLOC", 6) == 0) {
        return(CMD_LIBLOC);
    }
    else if (_strnicmp(name, "LIBDIC", 6) == 0) {
        return(CMD_LIBDIC);
    }
    else if (_strnicmp(name, "COMDEF", 6) == 0) {
        return(CMD_COMDEF);
    }
    else if (_strnicmp(name, "BAKPAT", 6) == 0) {
        return(CMD_BAKPAT);
    }
    else if (_strnicmp(name, "CEXTDEF", 7) == 0) {
        return(CMD_CEXTDEF);
    }
    else if (_strnicmp(name, "CEXTDF", 6) == 0) {
        return(CMD_CEXTDEF);
    }
    else if (_strnicmp(name, "COMDAT", 6) == 0) {
        return(CMD_COMDAT);
    }
    else if (_strnicmp(name, "LINSYM", 6) == 0) {
        return(CMD_LINSYM);
    }
    else if (_strnicmp(name, "ALIAS", 5) == 0) {
        return(CMD_ALIAS);
    }
    else if (_strnicmp(name, "NBKPAT", 6) == 0) {
        return(CMD_NBKPAT);
    }
    else if (_strnicmp(name, "LLNAMES", 7) == 0) {
        return(CMD_LLNAMES);
    }
    else if (_strnicmp(name, "LLNAME", 6) == 0) {
        return(CMD_LLNAMES);
    }
    else if (_strnicmp(name, "STATIC_EXTDEF", 13) == 0) {
        return(CMD_STATIC_EXTDEF);
    }
    else if (_strnicmp(name, "STATIC_PUBDEF", 13) == 0) {
        return(CMD_STATIC_PUBDEF);
    }
    else if (_strnicmp(name, "STATIC_COMDEF", 13) == 0) {
        return(CMD_STATIC_COMDEF);
    }
    else if (_strnicmp(name, "LIBTAIL", 7) == 0) {
        return(LIB_HEADER_REC);
    }
    else if (_strnicmp(name, "LIBHEAD", 7) == 0) {
        return(LIB_HEADER_REC);
    }
    else {
        return(0);
    }
}
