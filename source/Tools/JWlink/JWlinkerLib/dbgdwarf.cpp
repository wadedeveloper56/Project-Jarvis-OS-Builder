#include "pch.h"
#include "dbgdwarf.h"
#include "globals.h"
#include "Structs.h"
#include "dwarf.h"

class_entry* DBIClass;            

//typedef struct
//{
//    virt_mem    addr;
//    uint32_t size;
//} dwarfsect;

//typedef struct dwarfmodinfo
//{
//    dwarfsect   pubsym;
//    dwarfsect   dasi;
//    dwarfsect   arange;
//} dwarfmodinfo;

typedef struct
{
    virt_mem    addr;         
    uint32_t size;        
    uint32_t start;           
    char* name;
} sectioninfo;

static sectioninfo SectionTable[] = {
    { 0, 0, 0, ".debug_info" },
    { 0, 0, 0, ".debug_abbrev" },
    { 0, 0, 0, ".debug_line" },
    { 0, 0, 0, ".debug_aranges" }
};

enum
{
    SECT_DEBUG_INFO,              
    SECT_DEBUG_ABBREV,
    SECT_DEBUG_LINE,
    SECT_DEBUG_ARANGE,
    SECT_NUM_SECTIONS
};

#pragma pack( 1 )

typedef struct
{
    uint8_t  abbrev_code;        
} compunit_die;

typedef struct
{
    uint8_t  abbrev_code;
    offset      off;
    uint8_t  isexternal;
} symbol_die;

typedef struct
{
    uint8_t  len;
    uint8_t  loc_op;
    uint16_t seg;
} symbol_seg;


#define NULL_ABBREV_CODE        0
#define COMPUNIT_ABBREV_CODE    1
#define CU_NOLINE_ABBREV_CODE   2
#define LABEL_ABBREV_CODE       3
#define VARIABLE_ABBREV_CODE    4
#define LAST_ABBREV_CODE        4

//#if LAST_ABBREV_CODE != LAST_LINKER_ABBREV
//#error "make sure dwarf.h is updated and dwarf writing library recompiled!"
//#endif

static char SegmentedStandardAbbrevs[] = {
    COMPUNIT_ABBREV_CODE,
    DW_TAG_compile_unit,
    DW_CHILDREN_yes,
    DW_AT_stmt_list,    DW_FORM_ref_addr,
    DW_AT_name,         DW_FORM_string,
    0,                  0,
    CU_NOLINE_ABBREV_CODE,
    DW_TAG_compile_unit,
    DW_CHILDREN_yes,
    DW_AT_name,         DW_FORM_string,
    0,                  0,
    LABEL_ABBREV_CODE,
    DW_TAG_label,
    DW_CHILDREN_no,
    DW_AT_low_pc,       DW_FORM_addr,
    DW_AT_external,     DW_FORM_flag,
    DW_AT_segment,      DW_FORM_block1,
    DW_AT_name,         DW_FORM_string,
    0,                  0,
    VARIABLE_ABBREV_CODE,
    DW_TAG_variable,
    DW_CHILDREN_no,
    DW_AT_low_pc,       DW_FORM_addr,
    DW_AT_external,     DW_FORM_flag,
    DW_AT_segment,      DW_FORM_block1,
    DW_AT_name,         DW_FORM_string,
    0,                  0
};

static char FlatStandardAbbrevs[] = {
    COMPUNIT_ABBREV_CODE,
    DW_TAG_compile_unit,
    DW_CHILDREN_yes,
    DW_AT_stmt_list,    DW_FORM_data4,
    DW_AT_name,         DW_FORM_string,
    0,                  0,
    CU_NOLINE_ABBREV_CODE,
    DW_TAG_compile_unit,
    DW_CHILDREN_yes,
    DW_AT_name,         DW_FORM_string,
    0,                  0,
    LABEL_ABBREV_CODE,
    DW_TAG_label,
    DW_CHILDREN_no,
    DW_AT_low_pc,       DW_FORM_addr,
    DW_AT_external,     DW_FORM_flag,
    DW_AT_name,         DW_FORM_string,
    0,                  0,
    VARIABLE_ABBREV_CODE,
    DW_TAG_variable,
    DW_CHILDREN_no,
    DW_AT_low_pc,       DW_FORM_addr,
    DW_AT_external,     DW_FORM_flag,
    DW_AT_name,         DW_FORM_string,
    0,                  0,
    0,                  0     
};
#pragma pack()

void DwarfInit(void)
{
    int index;

    DBIClass = NULL;
    for (index = 0; index < SECT_NUM_SECTIONS; index++)
    {
        SectionTable[index].addr = 0;
        SectionTable[index].size = 0;
        SectionTable[index].start = 0;
    }
}
