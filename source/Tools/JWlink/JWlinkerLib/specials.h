#pragma once

#ifdef export
#define SPECIAL( sym, val ) char sym[] = val
#else
#define SPECIAL( sym, val ) extern char sym[sizeof( val )]
#endif

SPECIAL(AutoGrpName, "AUTO");
SPECIAL(DataGrpName, "DGROUP");
#if 0   
SPECIAL(IDataGrpName, ".idata");
#else
SPECIAL(IDataGrpName, ".rdata");
#endif
SPECIAL(TLSGrpName, "tls");

SPECIAL(BSSClassName, "BSS");
SPECIAL(CodeClassName, "CODE");
SPECIAL(FarDataClassName, "FAR_DATA");
SPECIAL(DataClassName, "DATA");
SPECIAL(BegCodeClassName, "BEGCODE");
SPECIAL(BegDataClassName, "BEGDATA");
SPECIAL(StackClassName, "STACK");
SPECIAL(ConstClassName, "CONST");
SPECIAL(TLSClassName, "TLS");
SPECIAL(_MSTypeClass, "DEBTYP");
SPECIAL(_MSLocalClass, "DEBSYM");
SPECIAL(_DwarfClass, "DWARF");

SPECIAL(BSSStartSym, "_edata");
SPECIAL(BSSEndSym, "_end");
SPECIAL(BSS_StartSym, "__edata");
SPECIAL(BSS_EndSym, "__end");
SPECIAL(ImportSymPrefix, "__imp_");
SPECIAL(TLSSym, "__tls_used");
SPECIAL(TocSymName, ".toc");

SPECIAL(BegTextSegName, "BEGTEXT");
SPECIAL(CommunalSegName, "c_common");
SPECIAL(CoffTextSegName, ".text");
SPECIAL(CoffDebugSymName, ".debug$S");
SPECIAL(CoffDebugTypeName, ".debug$T");
SPECIAL(CoffDebugPrefix, ".debug");
SPECIAL(CoffIDataSegName, ".idata");
SPECIAL(CoffRelocSegName, ".reloc");
SPECIAL(CoffTocSegName, ".idata$4toc");
SPECIAL(CoffPDataSegName, ".pdata");
SPECIAL(CoffReldataSegName, ".reldata");
SPECIAL(CoffImportRefName, "_IMPORT_DESCRIPTOR");
SPECIAL(TLSSegPrefix, ".tls");

SPECIAL(LinkerModule, "LINKER MODULE");

SPECIAL(GotSymName, "_GLOBAL_OFFSET_TABLE_");
SPECIAL(DynSymName, "_DYNAMIC");
SPECIAL(GotSecName, ".got");
SPECIAL(ElfIDataSecName, ".imports");

SPECIAL(RelASecName, ".rela");
