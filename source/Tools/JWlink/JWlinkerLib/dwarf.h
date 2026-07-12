
#ifndef _DWARF_H_INCLUDED_
#define _DWARF_H_INCLUDED_

#include "pushpck1.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DWARF_IMPL_VERSION  2     

typedef enum {
#define DWTAGI( __n, __v  )   DW_TAG_##__n = __v,
#include "dwtagi.h"
#undef  DWTAGI
}dw_tagnum;

typedef enum {
#define DWFORMI( __n, __v  )   DW_FORM_##__n = __v,
#include "dwformi.h"
#undef  DWFORMI
}dw_formnum;

typedef enum {
#define DWATI( __n, __v  )   DW_AT_##__n = __v,
#include "dwati.h"
#undef  DWATI
}dw_atnum;

#define DW_OP_lit( __x )        ( (__x) + 0x30 )            
#define DW_OP_reg( __x )        ( (__x) + 0x50 )            
#define DW_OP_breg( __x )       ( (__x) + 0x70 )            
#include "dwloccl.h"
typedef enum {
    DW_OP_regx          = 0x90,
    DW_OP_addr          = 0x03,
    DW_OP_const1u       = 0x08,
    DW_OP_const1s,
    DW_OP_const2u,
    DW_OP_const2s,
    DW_OP_const4u,
    DW_OP_const4s,
    DW_OP_const8u,
    DW_OP_const8s,
    DW_OP_constu,
    DW_OP_consts,
    DW_OP_lit0          = 0x30,
    DW_OP_lit31         = 0x4f,
    DW_OP_reg0          = 0x50,
    DW_OP_reg31         = 0x6f,
    DW_OP_breg0         = 0x70,
    DW_OP_breg31        = 0x8f,
#define DW_LOC_OP( __n, __v )   DW_OP_##__n = __v,
#include "dwlocop.h"
#undef DW_LOC_OP
    DW_OP_lo_user       = 0xe0,
    DW_OP_hi_user       = 0xff
}dw_op;

typedef enum {
    DW_ATE_address          =0x01,
    DW_ATE_boolean          =0x02,
    DW_ATE_complex_float    =0x03,
    DW_ATE_float            =0x04,
    DW_ATE_signed           =0x05,
    DW_ATE_signed_char      =0x06,
    DW_ATE_unsigned         =0x07,
    DW_ATE_unsigned_char    =0x08,
    DW_ATE_lo_user          =0x80,
    DW_ATE_hi_user          =0xff,
}dw_ate;
typedef enum {
    DW_ACCESS_public      = 1,
    DW_ACCESS_protected   = 2,
    DW_ACCESS_private     = 3,
}dw_access;
typedef enum {
    DW_VIRTUALITY_none           =  0,
    DW_VIRTUALITY_virtual        =  1,
    DW_VIRTUALITY_pure_virtual   =  2,
}dw_virtuality;
typedef enum {
    DW_LANG_C89             = 0x0001,
    DW_LANG_C               = 0x0002,
    DW_LANG_Ada83           = 0x0003,
    DW_LANG_C_plus_plus     = 0x0004,
    DW_LANG_Cobol74         = 0x0005,
    DW_LANG_Cobol85         = 0x0006,
    DW_LANG_Fortran77       = 0x0007,
    DW_LANG_Fortran90       = 0x0008,
    DW_LANG_Pascal83        = 0x0009,
    DW_LANG_Modula2         = 0x000a,
    DW_LANG_lo_user         = 0x8000,
    DW_LANG_hi_user         = 0xffff,
}dw_langnum;
typedef enum {
    DW_ID_case_sensitive   =0,
    DW_ID_up_case          =1,
    DW_ID_down_case        =2,
    DW_ID_case_insensitive =3,
}dw_id;
typedef enum {
    DW_CC_normal           =0x01,
    DW_CC_program          =0x02,
    DW_CC_nocall           =0x03,
    DW_CC_lo_user          =0x40,
    DW_CC_hi_user          =0xff,
}dw_cc;
typedef enum {
    DW_INL_not_inlined             =0,
    DW_INL_inlined                 =1,
    DW_INL_declared_not_inlined    =2,
    DW_INL_declared_inlined        =3,
}dw_inl;
typedef enum {
  DW_ORD_row_major =  0,
  DW_ORD_col_major =  1,
}dw_ord;

typedef enum {
    DW_LNS_copy = 1,
    DW_LNS_advance_pc,
    DW_LNS_advance_line,
    DW_LNS_set_file,
    DW_LNS_set_column,
    DW_LNS_negate_stmt,
    DW_LNS_set_basic_block,
    DW_LNS_const_add_pc,
    DW_LNS_fixed_advance_pc
}dw_lns;

typedef enum {
    DW_LNE_end_sequence = 1,
    DW_LNE_set_address,
    DW_LNE_define_file,
#if 1
    DW_LNE_set_segment
#endif
}dw_lne;

#define DW_MACINFO_define       1
#define DW_MACINFO_undef        2
#define DW_MACINFO_start_file   3
#define DW_MACINFO_end_file     4
#define DW_MACINFO_vendor_ext   255

#define REF_BEGIN_SCOPE         0x01
#define REF_END_SCOPE           0x02
#define REF_SET_FILE            0x03
#define REF_SET_LINE            0x04
#define REF_SET_COLUMN          0x05
#define REF_ADD_LINE            0x06
#define REF_ADD_COLUMN          0x07
#define REF_COPY                0x08
#define REF_CODE_BASE           0x10
#define REF_COLUMN_RANGE        80

typedef enum {
    DW_MEM_MODEL_none    = 0,
    DW_MEM_MODEL_flat    = 1,
    DW_MEM_MODEL_small   = 2,
    DW_MEM_MODEL_medium  = 3,
    DW_MEM_MODEL_compact = 4,
    DW_MEM_MODEL_large   = 5,
    DW_MEM_MODEL_huge    = 6,
}dw_mem_model;

typedef enum {
    DW_ADDR_none,
    DW_ADDR_near16,
    DW_ADDR_far16,
    DW_ADDR_huge16,
    DW_ADDR_near32,
    DW_ADDR_far32
}dw_addr;

typedef enum {
    DW_CHILDREN_no,
    DW_CHILDREN_yes
}dw_children;

#define COMPILE_UNIT_HDR_SIZE   11           
#define DWLINE_OPCODE_BASE      10

#define DW_MIN_INSTR_LENGTH     1
#define DWLINE_BASE             (-1)
#define DWLINE_RANGE            4

#define LAST_LINKER_ABBREV 4

#ifdef __UNIX__
//#define 
#else
//#define  
//
#endif

typedef struct {
    uint32_t total_length;
    uint16_t version;
    uint32_t prologue_length;
    uint8_t  minimum_instruction_length;
    uint8_t  default_is_stmt;
    int8_t    line_base;
    uint8_t  line_range;
    uint8_t  opcode_base;
    uint8_t  standard_opcode_lengths[DWLINE_OPCODE_BASE - 1];
}  stmt_prologue;


typedef struct {
    uint32_t offset;
    uint16_t segment;
    uint32_t length;
}  segmented_arange_tuple;

typedef struct {
    uint32_t offset;
    uint32_t length;
} flat_arange_tuple;

typedef union {
    segmented_arange_tuple      s;
    flat_arange_tuple           f;
} arange_tuple;

typedef struct {
    uint32_t length;
    uint16_t version;
    uint32_t debug_offset;
    uint8_t  offset_size;
    uint8_t  segment_size;
}  arange_prologue;

typedef struct {
    uint32_t length;
    uint16_t version;
    uint32_t abbrev_offset;
    uint8_t  addr_size;
}  compuhdr_prologue;

typedef struct {
    uint32_t length;
    uint16_t version;
    uint32_t debug_offset;
    uint32_t debug_size;
}  pubnames_prologue;

#ifdef __cplusplus
};
#endif
#include "poppck.h"
#endif
