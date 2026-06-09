
#ifndef ORL_GLOBAL_INCLUDED
#define ORL_GLOBAL_INCLUDED

#include <watcom.h>

#define ORLENTRY

typedef uint_32                         orl_file_offset;
typedef uint_32                         orl_file_size;

typedef uint_32                         orl_sec_size;
typedef uint_32                         orl_sec_offset;
typedef uint_32                         orl_sec_alignment;
typedef long                            orl_sec_frame;

typedef uint_32                         orl_reloc_addend;
typedef int_32                          orl_reloc_addend_signed;

typedef uint_32                         orl_symbol_value;

typedef uint_32                         orl_table_index;

#define ORL_SEC_NO_ABS_FRAME            -1

typedef enum {
    ORL_OUT_OF_MEMORY,
    ORL_ERROR,
    ORL_OKAY,
    ORL_TRUE = ORL_OKAY,
    ORL_FALSE
} orl_return;

typedef enum {
    ORL_ELF,
    ORL_COFF,
    ORL_OMF,
    ORL_UNRECOGNIZED_FORMAT
} orl_file_format;

#include <pushpck1.h>
typedef struct {
    unsigned_16 linnum;
    unsigned_32 off;
} orl_linnum;
#include <poppck.h>

typedef struct {
    void *      (*read)( void *, size_t );
    long int    (*seek)( void *, long int, int );
    void *      (*alloc)( size_t );
    void        (*free)( void * );
} orl_funcs;

typedef enum {
    ORL_MACHINE_TYPE_NONE,         
    ORL_MACHINE_TYPE_WE_2100,
    ORL_MACHINE_TYPE_SPARC,
    ORL_MACHINE_TYPE_I386,
    ORL_MACHINE_TYPE_I860,
    ORL_MACHINE_TYPE_M68000,
    ORL_MACHINE_TYPE_M88000,
    ORL_MACHINE_TYPE_ALPHA,
    ORL_MACHINE_TYPE_R3000,
    ORL_MACHINE_TYPE_R4000,
    ORL_MACHINE_TYPE_PPC601,
    ORL_MACHINE_TYPE_I8086,
    ORL_MACHINE_TYPE_AMD64,
    ORL_MACHINE_TYPE_SPARCPLUS,
    ORL_MACHINE_TYPE_UNKNOWN
} orl_machine_type;

typedef enum {
    ORL_FILE_TYPE_NONE = 0,
    ORL_FILE_TYPE_OBJECT,
    ORL_FILE_TYPE_EXECUTABLE,
    ORL_FILE_TYPE_SHARED_OBJECT,
    ORL_FILE_TYPE_DLL,
    ORL_FILE_TYPE_IMPORT,
    ORL_FILE_TYPE_CORE
} orl_file_type;

typedef enum {
    ORL_FILE_FLAG_NONE                  = 0x0000,
    ORL_FILE_FLAG_LINE_NUMS_STRIPPED    = 0x0001,     
    ORL_FILE_FLAG_RELOCS_STRIPPED       = 0x0002,    
    ORL_FILE_FLAG_LOCAL_SYMS_STRIPPED   = 0x0004,   
    ORL_FILE_FLAG_DEBUG_STRIPPED        = 0x0008,   
    ORL_FILE_FLAG_16BIT_MACHINE         = 0x0010,   
    ORL_FILE_FLAG_32BIT_MACHINE         = 0x0020,   
    ORL_FILE_FLAG_64BIT_MACHINE         = 0x0040,   
    ORL_FILE_FLAG_LITTLE_ENDIAN         = 0x0100,     
    ORL_FILE_FLAG_BIG_ENDIAN            = 0x0200,     
    ORL_FILE_FLAG_SYSTEM                = 0x1000,  
} orl_file_flags;

typedef enum {
    ORL_SEC_TYPE_NONE = 0,
    ORL_SEC_TYPE_NO_BITS,                      
    ORL_SEC_TYPE_PROG_BITS,
    ORL_SEC_TYPE_SYM_TABLE,                  
    ORL_SEC_TYPE_DYN_SYM_TABLE,             
    ORL_SEC_TYPE_STR_TABLE,                  
    ORL_SEC_TYPE_RELOCS,                   
    ORL_SEC_TYPE_RELOCS_EXPADD,              
    ORL_SEC_TYPE_HASH,                        
    ORL_SEC_TYPE_DYNAMIC,                    
    ORL_SEC_TYPE_NOTE,                      
    ORL_SEC_TYPE_IMPORT,                    
    ORL_SEC_TYPE_EXPORT,                    
} orl_sec_type;

typedef enum {
    ORL_SEC_FLAG_NONE                   = 0x0000,
    ORL_SEC_FLAG_EXEC                   = 0x0001,     
    ORL_SEC_FLAG_INITIALIZED_DATA       = 0x0002,     
    ORL_SEC_FLAG_UNINITIALIZED_DATA     = 0x0004,      
    ORL_SEC_FLAG_GROUPED                = 0x0008,         
    ORL_SEC_FLAG_NO_PADDING             = 0x0010,      
    ORL_SEC_FLAG_OVERLAY                = 0x0020,     
    ORL_SEC_FLAG_REMOVE                 = 0x0040,        
    ORL_SEC_FLAG_COMDAT                 = 0x0080,     
    ORL_SEC_FLAG_DISCARDABLE            = 0x0100,       
    ORL_SEC_FLAG_NOT_CACHED             = 0x0200,     
    ORL_SEC_FLAG_NOT_PAGEABLE           = 0x0400,     
    ORL_SEC_FLAG_SHARED                 = 0x0800,       
    ORL_SEC_FLAG_EXECUTE_PERMISSION     = 0x1000,       
    ORL_SEC_FLAG_READ_PERMISSION        = 0x2000,     
    ORL_SEC_FLAG_WRITE_PERMISSION       = 0x4000,      
    ORL_SEC_FLAG_USE_32                 = 0x8000      
} orl_sec_flags;

typedef enum {
    ORL_SEC_COMBINE_MASK                = 0x000f,     
    ORL_SEC_COMBINE_NONE                = 0x0000,     
    ORL_SEC_COMBINE_PRIVATE             = 0x0001,    
    ORL_SEC_COMBINE_PUBLIC              = 0x0002,      
    ORL_SEC_COMBINE_STACK               = 0x0003,        
    ORL_SEC_COMBINE_COMMON              = 0x0004,     
    ORL_SEC_COMBINE_COMDAT              = 0x0004,      
    ORL_SEC_COMBINE_COMDAT_ALLOC_MASK   = 0x00f0,    
    ORL_SEC_COMBINE_COMDAT_ALLOC_EXPLIC = 0x0000,    
    ORL_SEC_COMBINE_COMDAT_ALLOC_CODE16 = 0x0010,     
    ORL_SEC_COMBINE_COMDAT_ALLOC_DATA16 = 0x0020,    
    ORL_SEC_COMBINE_COMDAT_ALLOC_CODE32 = 0x0030,     
    ORL_SEC_COMBINE_COMDAT_ALLOC_DATA32 = 0x0040,     
    ORL_SEC_COMBINE_COMDAT_PICK_MASK    = 0x0f00,    
    ORL_SEC_COMBINE_COMDAT_PICK_NONE    = 0x0000,     
    ORL_SEC_COMBINE_COMDAT_PICK_ANY     = 0x0100,    
    ORL_SEC_COMBINE_COMDAT_PICK_SAME    = 0x0200,     
    ORL_SEC_COMBINE_COMDAT_PICK_EXACT   = 0x0300,     
} orl_sec_combine;

typedef enum {
    ORL_SYM_BINDING_NONE,
    ORL_SYM_BINDING_LOCAL,        
    ORL_SYM_BINDING_WEAK,            
    ORL_SYM_BINDING_GLOBAL,       
    ORL_SYM_BINDING_LAZY,             
    ORL_SYM_BINDING_ALIAS
} orl_symbol_binding;

typedef enum {
    ORL_SYM_TYPE_NONE                   = 0x0000,
    ORL_SYM_TYPE_OBJECT                 = 0x0001,       
    ORL_SYM_TYPE_FUNCTION               = 0x0002,      
    ORL_SYM_TYPE_SECTION                = 0x0004,      
    ORL_SYM_TYPE_FILE                   = 0x0008,        
    ORL_SYM_TYPE_FUNC_INFO              = 0x0010,        
    ORL_SYM_TYPE_GROUP                  = 0x0020,       
    ORL_SYM_TYPE_NOTYPE                 = 0x0040,     
    ORL_SYM_TYPE_ABSOLUTE               = 0x0100,      
    ORL_SYM_TYPE_COMMON                 = 0x0200,        
    ORL_SYM_TYPE_UNDEFINED              = 0x0400,      
    ORL_SYM_TYPE_DEFINED                = 0x0800,      
    ORL_SYM_TYPE_DEBUG                  = 0x1000,      
    ORL_SYM_CDAT_NODUPLICATES           = 0x2000,
    ORL_SYM_CDAT_ANY                    = 0x4000,
    ORL_SYM_CDAT_SAME_SIZE              = 0x6000,
    ORL_SYM_CDAT_EXACT                  = 0x8000,
    ORL_SYM_CDAT_ASSOCIATIVE            = 0xA000,
    ORL_SYM_CDAT_MASK                   = 0xE000,
    ORL_SYM_CDAT_SHIFT                  = 13
} orl_symbol_type;

typedef enum {
    ORL_RELOC_TYPE_NONE,           
    ORL_RELOC_TYPE_ABSOLUTE,           
    ORL_RELOC_TYPE_WORD_16,             
    ORL_RELOC_TYPE_WORD_32,             
    ORL_RELOC_TYPE_WORD_32_NB,             
    ORL_RELOC_TYPE_HALF_HI,             
    ORL_RELOC_TYPE_HALF_HA,            
    ORL_RELOC_TYPE_HALF_LO,             
    ORL_RELOC_TYPE_PAIR,               
    ORL_RELOC_TYPE_JUMP,                    
    ORL_RELOC_TYPE_SECTION,              
    ORL_RELOC_TYPE_SEC_REL,                 
    ORL_RELOC_TYPE_REL_16,            
    ORL_RELOC_TYPE_REL_21_SH,            
    ORL_RELOC_TYPE_WORD_64,             
    ORL_RELOC_TYPE_SEGMENT,         
    ORL_RELOC_TYPE_WORD_14,               
    ORL_RELOC_TYPE_WORD_24,               
    ORL_RELOC_TYPE_WORD_26,               
    ORL_RELOC_TYPE_REL_14,               
    ORL_RELOC_TYPE_REL_24,               
    ORL_RELOC_TYPE_REL_32,             
    ORL_RELOC_TYPE_REL_32_NOADJ,        

    ORL_RELOC_TYPE_TOCREL_16,            
    ORL_RELOC_TYPE_TOCREL_14,              
    ORL_RELOC_TYPE_TOCVREL_16,         
    ORL_RELOC_TYPE_TOCVREL_14,    
    ORL_RELOC_TYPE_GOT_32,               
    ORL_RELOC_TYPE_GOT_16,               
    ORL_RELOC_TYPE_GOT_16_HI,              
    ORL_RELOC_TYPE_GOT_16_HA,          
    ORL_RELOC_TYPE_GOT_16_LO,              
    ORL_RELOC_TYPE_PLTREL_24,            
    ORL_RELOC_TYPE_PLTREL_32,            
    ORL_RELOC_TYPE_PLT_32,               
    ORL_RELOC_TYPE_PLT_16_HI,              
    ORL_RELOC_TYPE_PLT_16_HA,          
    ORL_RELOC_TYPE_PLT_16_LO,              
    ORL_RELOC_TYPE_IFGLUE,                
    ORL_RELOC_TYPE_IMGLUE,                 

    ORL_RELOC_TYPE_WORD_8,           
    ORL_RELOC_TYPE_REL_8,              
    ORL_RELOC_TYPE_WORD_16_SEG,       
    ORL_RELOC_TYPE_REL_16_SEG,          
    ORL_RELOC_TYPE_WORD_HI_8,           
    ORL_RELOC_TYPE_REL_HI_8,             
    ORL_RELOC_TYPE_WORD_32_SEG,      
    ORL_RELOC_TYPE_REL_32_SEG,          

    ORL_RELOC_TYPE_REL_32_ADJ1,           
    ORL_RELOC_TYPE_REL_32_ADJ2,           
    ORL_RELOC_TYPE_REL_32_ADJ3,           
    ORL_RELOC_TYPE_REL_32_ADJ4,           
    ORL_RELOC_TYPE_REL_32_ADJ5,           

    ORL_RELOC_TYPE_MAX                 
} orl_reloc_type;

#endif
