/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "c11ansi.y"

#include "pch.h"
#include "jcc.h"

int yyerror(const char *s);
int yylex();

#line 79 "c11ansi.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "c11ansi.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* "identifier"  */
  YYSYMBOL_I_CONSTANT = 4,                 /* "i_const"  */
  YYSYMBOL_F_CONSTANT = 5,                 /* "f_const"  */
  YYSYMBOL_STRING_LITERAL = 6,             /* "sting_literal"  */
  YYSYMBOL_Y_EXCLAMATION = 7,              /* Y_EXCLAMATION  */
  YYSYMBOL_Y_NE = 8,                       /* Y_NE  */
  YYSYMBOL_Y_POUND = 9,                    /* Y_POUND  */
  YYSYMBOL_Y_POUND_POUND = 10,             /* Y_POUND_POUND  */
  YYSYMBOL_Y_AND = 11,                     /* Y_AND  */
  YYSYMBOL_Y_AND_AND = 12,                 /* Y_AND_AND  */
  YYSYMBOL_Y_AND_EQUAL = 13,               /* Y_AND_EQUAL  */
  YYSYMBOL_Y_LEFT_PAREN = 14,              /* Y_LEFT_PAREN  */
  YYSYMBOL_Y_RIGHT_PAREN = 15,             /* Y_RIGHT_PAREN  */
  YYSYMBOL_Y_TIMES = 16,                   /* Y_TIMES  */
  YYSYMBOL_Y_TIMES_EQUAL = 17,             /* Y_TIMES_EQUAL  */
  YYSYMBOL_Y_PLUS = 18,                    /* Y_PLUS  */
  YYSYMBOL_Y_PLUS_PLUS = 19,               /* Y_PLUS_PLUS  */
  YYSYMBOL_Y_PLUS_EQUAL = 20,              /* Y_PLUS_EQUAL  */
  YYSYMBOL_Y_COMMA = 21,                   /* Y_COMMA  */
  YYSYMBOL_Y_MINUS = 22,                   /* Y_MINUS  */
  YYSYMBOL_Y_MINUS_MINUS = 23,             /* Y_MINUS_MINUS  */
  YYSYMBOL_Y_MINUS_EQUAL = 24,             /* Y_MINUS_EQUAL  */
  YYSYMBOL_Y_ARROW = 25,                   /* Y_ARROW  */
  YYSYMBOL_Y_DOT = 26,                     /* Y_DOT  */
  YYSYMBOL_Y_DOT_DOT_DOT = 27,             /* Y_DOT_DOT_DOT  */
  YYSYMBOL_Y_DIVIDE = 28,                  /* Y_DIVIDE  */
  YYSYMBOL_Y_DIVIDE_EQUAL = 29,            /* Y_DIVIDE_EQUAL  */
  YYSYMBOL_Y_COLON = 30,                   /* Y_COLON  */
  YYSYMBOL_Y_SEG_OP = 31,                  /* Y_SEG_OP  */
  YYSYMBOL_Y_SEMICOLON = 32,               /* Y_SEMICOLON  */
  YYSYMBOL_Y_LT = 33,                      /* Y_LT  */
  YYSYMBOL_Y_LSHIFT = 34,                  /* Y_LSHIFT  */
  YYSYMBOL_Y_LSHIFT_EQUAL = 35,            /* Y_LSHIFT_EQUAL  */
  YYSYMBOL_Y_LE = 36,                      /* Y_LE  */
  YYSYMBOL_Y_EQUAL = 37,                   /* Y_EQUAL  */
  YYSYMBOL_Y_EQ = 38,                      /* Y_EQ  */
  YYSYMBOL_Y_GT = 39,                      /* Y_GT  */
  YYSYMBOL_Y_GE = 40,                      /* Y_GE  */
  YYSYMBOL_Y_RSHIFT = 41,                  /* Y_RSHIFT  */
  YYSYMBOL_Y_RSHIFT_EQUAL = 42,            /* Y_RSHIFT_EQUAL  */
  YYSYMBOL_Y_QUESTION = 43,                /* Y_QUESTION  */
  YYSYMBOL_Y_LEFT_BRACKET = 44,            /* Y_LEFT_BRACKET  */
  YYSYMBOL_Y_RIGHT_BRACKET = 45,           /* Y_RIGHT_BRACKET  */
  YYSYMBOL_Y_XOR = 46,                     /* Y_XOR  */
  YYSYMBOL_Y_XOR_EQUAL = 47,               /* Y_XOR_EQUAL  */
  YYSYMBOL_Y___BASED = 48,                 /* Y___BASED  */
  YYSYMBOL_Y___CDECL = 49,                 /* Y___CDECL  */
  YYSYMBOL_Y___EXPORT = 50,                /* Y___EXPORT  */
  YYSYMBOL_Y___FAR = 51,                   /* Y___FAR  */
  YYSYMBOL_Y___FAR16 = 52,                 /* Y___FAR16  */
  YYSYMBOL_Y___FORTRAN = 53,               /* Y___FORTRAN  */
  YYSYMBOL_Y___HUGE = 54,                  /* Y___HUGE  */
  YYSYMBOL_Y___INTERRUPT = 55,             /* Y___INTERRUPT  */
  YYSYMBOL_Y___LOADDS = 56,                /* Y___LOADDS  */
  YYSYMBOL_Y___NEAR = 57,                  /* Y___NEAR  */
  YYSYMBOL_Y___PASCAL = 58,                /* Y___PASCAL  */
  YYSYMBOL_Y___PRAGMA = 59,                /* Y___PRAGMA  */
  YYSYMBOL_Y___SAVEREGS = 60,              /* Y___SAVEREGS  */
  YYSYMBOL_Y___SEGMENT = 61,               /* Y___SEGMENT  */
  YYSYMBOL_Y___SEGNAME = 62,               /* Y___SEGNAME  */
  YYSYMBOL_Y___SELF = 63,                  /* Y___SELF  */
  YYSYMBOL_Y___STDCALL = 64,               /* Y___STDCALL  */
  YYSYMBOL_Y__PACKED = 65,                 /* Y__PACKED  */
  YYSYMBOL_Y__SEG16 = 66,                  /* Y__SEG16  */
  YYSYMBOL_Y__SYSCALL = 67,                /* Y__SYSCALL  */
  YYSYMBOL_Y_THREAD_LOCAL = 68,            /* Y_THREAD_LOCAL  */
  YYSYMBOL_Y_AUTO = 69,                    /* Y_AUTO  */
  YYSYMBOL_Y_CHAR = 70,                    /* Y_CHAR  */
  YYSYMBOL_Y_CONST = 71,                   /* Y_CONST  */
  YYSYMBOL_Y_DOUBLE = 72,                  /* Y_DOUBLE  */
  YYSYMBOL_Y_ELSE = 73,                    /* Y_ELSE  */
  YYSYMBOL_Y_ENUM = 74,                    /* Y_ENUM  */
  YYSYMBOL_Y_EXTERN = 75,                  /* Y_EXTERN  */
  YYSYMBOL_Y_FLOAT = 76,                   /* Y_FLOAT  */
  YYSYMBOL_Y_INT = 77,                     /* Y_INT  */
  YYSYMBOL_Y_LONG = 78,                    /* Y_LONG  */
  YYSYMBOL_Y_REGISTER = 79,                /* Y_REGISTER  */
  YYSYMBOL_Y_SHORT = 80,                   /* Y_SHORT  */
  YYSYMBOL_Y_SIGNED = 81,                  /* Y_SIGNED  */
  YYSYMBOL_Y_SIZEOF = 82,                  /* Y_SIZEOF  */
  YYSYMBOL_Y_STATIC = 83,                  /* Y_STATIC  */
  YYSYMBOL_Y_STRUCT = 84,                  /* Y_STRUCT  */
  YYSYMBOL_Y_TYPEDEF = 85,                 /* Y_TYPEDEF  */
  YYSYMBOL_Y_UNION = 86,                   /* Y_UNION  */
  YYSYMBOL_Y_UNSIGNED = 87,                /* Y_UNSIGNED  */
  YYSYMBOL_Y_VOID = 88,                    /* Y_VOID  */
  YYSYMBOL_Y_VOLATILE = 89,                /* Y_VOLATILE  */
  YYSYMBOL_Y_LEFT_BRACE = 90,              /* Y_LEFT_BRACE  */
  YYSYMBOL_Y_OR = 91,                      /* Y_OR  */
  YYSYMBOL_Y_OR_EQUAL = 92,                /* Y_OR_EQUAL  */
  YYSYMBOL_Y_OR_OR = 93,                   /* Y_OR_OR  */
  YYSYMBOL_Y_RIGHT_BRACE = 94,             /* Y_RIGHT_BRACE  */
  YYSYMBOL_Y_TILDE = 95,                   /* Y_TILDE  */
  YYSYMBOL_Y_IF = 96,                      /* Y_IF  */
  YYSYMBOL_Y_STRING = 97,                  /* Y_STRING  */
  YYSYMBOL_Y_INCLUDE_FILE_NAME = 98,       /* Y_INCLUDE_FILE_NAME  */
  YYSYMBOL_Y_TYPEDEF_NAME = 99,            /* Y_TYPEDEF_NAME  */
  YYSYMBOL_Y_NUMBER = 100,                 /* Y_NUMBER  */
  YYSYMBOL_Y_PERCENT = 101,                /* Y_PERCENT  */
  YYSYMBOL_Y_PERCENT_EQUAL = 102,          /* Y_PERCENT_EQUAL  */
  YYSYMBOL_Y_DEFINED = 103,                /* Y_DEFINED  */
  YYSYMBOL_Y_ENUMERATION_CONSTANT = 104,   /* Y_ENUMERATION_CONSTANT  */
  YYSYMBOL_Y_FUNC_NAME = 105,              /* Y_FUNC_NAME  */
  YYSYMBOL_Y_GENERIC = 106,                /* Y_GENERIC  */
  YYSYMBOL_Y_DEFAULT = 107,                /* Y_DEFAULT  */
  YYSYMBOL_Y_CASE = 108,                   /* Y_CASE  */
  YYSYMBOL_Y_ALIGNOF = 109,                /* Y_ALIGNOF  */
  YYSYMBOL_Y_IMAGINARY = 110,              /* Y_IMAGINARY  */
  YYSYMBOL_Y_COMPLEX = 111,                /* Y_COMPLEX  */
  YYSYMBOL_Y_LONG_DOUBLE = 112,            /* Y_LONG_DOUBLE  */
  YYSYMBOL_Y_BOOL = 113,                   /* Y_BOOL  */
  YYSYMBOL_Y_ATOMIC = 114,                 /* Y_ATOMIC  */
  YYSYMBOL_Y_RESTRICT = 115,               /* Y_RESTRICT  */
  YYSYMBOL_Y_INLINE = 116,                 /* Y_INLINE  */
  YYSYMBOL_Y_NORETURN = 117,               /* Y_NORETURN  */
  YYSYMBOL_Y_ALIGNAS = 118,                /* Y_ALIGNAS  */
  YYSYMBOL_Y_STATIC_ASSERT = 119,          /* Y_STATIC_ASSERT  */
  YYSYMBOL_Y_SWITCH = 120,                 /* Y_SWITCH  */
  YYSYMBOL_Y_WHILE = 121,                  /* Y_WHILE  */
  YYSYMBOL_Y_DO = 122,                     /* Y_DO  */
  YYSYMBOL_Y_FOR = 123,                    /* Y_FOR  */
  YYSYMBOL_Y_GOTO = 124,                   /* Y_GOTO  */
  YYSYMBOL_Y_CONTINUE = 125,               /* Y_CONTINUE  */
  YYSYMBOL_Y_BREAK = 126,                  /* Y_BREAK  */
  YYSYMBOL_Y_RETURN = 127,                 /* Y_RETURN  */
  YYSYMBOL_Y_LONG_LONG = 128,              /* Y_LONG_LONG  */
  YYSYMBOL_129_then_ = 129,                /* "then"  */
  YYSYMBOL_YYACCEPT = 130,                 /* $accept  */
  YYSYMBOL_primary_expression = 131,       /* primary_expression  */
  YYSYMBOL_constant = 132,                 /* constant  */
  YYSYMBOL_enumeration_constant = 133,     /* enumeration_constant  */
  YYSYMBOL_string = 134,                   /* string  */
  YYSYMBOL_generic_selection = 135,        /* generic_selection  */
  YYSYMBOL_generic_assoc_list = 136,       /* generic_assoc_list  */
  YYSYMBOL_generic_association = 137,      /* generic_association  */
  YYSYMBOL_postfix_expression = 138,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 139, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 140,         /* unary_expression  */
  YYSYMBOL_unary_operator = 141,           /* unary_operator  */
  YYSYMBOL_cast_expression = 142,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 143, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 144,      /* additive_expression  */
  YYSYMBOL_shift_expression = 145,         /* shift_expression  */
  YYSYMBOL_relational_expression = 146,    /* relational_expression  */
  YYSYMBOL_equality_expression = 147,      /* equality_expression  */
  YYSYMBOL_and_expression = 148,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 149,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 150,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 151,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 152,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 153,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 154,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 155,      /* assignment_operator  */
  YYSYMBOL_expression = 156,               /* expression  */
  YYSYMBOL_constant_expression = 157,      /* constant_expression  */
  YYSYMBOL_declaration = 158,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 159,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 160,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 161,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 162,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 163,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 164, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 165,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 166,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 167,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 168, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 169,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 170,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 171,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 172,          /* enumerator_list  */
  YYSYMBOL_enumerator = 173,               /* enumerator  */
  YYSYMBOL_atomic_type_specifier = 174,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 175,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 176,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 177,      /* alignment_specifier  */
  YYSYMBOL_declarator = 178,               /* declarator  */
  YYSYMBOL_direct_declarator = 179,        /* direct_declarator  */
  YYSYMBOL_pointer = 180,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 181,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 182,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 183,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 184,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 185,          /* identifier_list  */
  YYSYMBOL_type_name = 186,                /* type_name  */
  YYSYMBOL_abstract_declarator = 187,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 188, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 189,              /* initializer  */
  YYSYMBOL_initializer_list = 190,         /* initializer_list  */
  YYSYMBOL_designation = 191,              /* designation  */
  YYSYMBOL_designator_list = 192,          /* designator_list  */
  YYSYMBOL_designator = 193,               /* designator  */
  YYSYMBOL_static_assert_declaration = 194, /* static_assert_declaration  */
  YYSYMBOL_statement = 195,                /* statement  */
  YYSYMBOL_labeled_statement = 196,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 197,       /* compound_statement  */
  YYSYMBOL_block_item_list = 198,          /* block_item_list  */
  YYSYMBOL_block_item = 199,               /* block_item  */
  YYSYMBOL_expression_statement = 200,     /* expression_statement  */
  YYSYMBOL_selection_statement = 201,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 202,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 203,           /* jump_statement  */
  YYSYMBOL_translation_unit = 204,         /* translation_unit  */
  YYSYMBOL_external_declaration = 205,     /* external_declaration  */
  YYSYMBOL_function_definition = 206,      /* function_definition  */
  YYSYMBOL_declaration_list = 207          /* declaration_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  69
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2797

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  130
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  78
/* YYNRULES -- Number of rules.  */
#define YYNRULES  277
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  482

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   384


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   223,   223,   224,   225,   226,   227,   231,   232,   233,
     237,   241,   242,   246,   250,   251,   255,   256,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   273,   274,
     278,   279,   280,   281,   282,   283,   284,   288,   289,   290,
     291,   292,   293,   297,   298,   302,   303,   304,   305,   309,
     310,   311,   315,   316,   317,   321,   322,   323,   324,   325,
     329,   330,   331,   335,   336,   340,   341,   345,   346,   350,
     351,   355,   356,   360,   361,   365,   366,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   384,   385,
     389,   393,   394,   395,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   412,   413,   417,   418,   422,   423,
     424,   425,   426,   427,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   452,   453,   454,   458,   459,   463,   464,   468,
     469,   470,   474,   475,   476,   477,   481,   482,   486,   487,
     488,   492,   493,   494,   495,   496,   500,   501,   505,   506,
     510,   514,   515,   516,   517,   521,   522,   526,   527,   531,
     532,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   553,   554,   555,   556,   560,
     561,   566,   567,   571,   572,   576,   577,   578,   582,   583,
     587,   588,   592,   593,   594,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   622,   623,   624,   628,
     629,   630,   631,   635,   639,   640,   644,   645,   649,   653,
     654,   655,   656,   657,   658,   662,   663,   664,   668,   669,
     673,   674,   678,   679,   683,   684,   688,   689,   690,   694,
     695,   696,   697,   698,   699,   703,   704,   705,   706,   707,
     711,   712,   716,   717,   721,   722,   726,   727
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "\"identifier\"",
  "\"i_const\"", "\"f_const\"", "\"sting_literal\"", "Y_EXCLAMATION",
  "Y_NE", "Y_POUND", "Y_POUND_POUND", "Y_AND", "Y_AND_AND", "Y_AND_EQUAL",
  "Y_LEFT_PAREN", "Y_RIGHT_PAREN", "Y_TIMES", "Y_TIMES_EQUAL", "Y_PLUS",
  "Y_PLUS_PLUS", "Y_PLUS_EQUAL", "Y_COMMA", "Y_MINUS", "Y_MINUS_MINUS",
  "Y_MINUS_EQUAL", "Y_ARROW", "Y_DOT", "Y_DOT_DOT_DOT", "Y_DIVIDE",
  "Y_DIVIDE_EQUAL", "Y_COLON", "Y_SEG_OP", "Y_SEMICOLON", "Y_LT",
  "Y_LSHIFT", "Y_LSHIFT_EQUAL", "Y_LE", "Y_EQUAL", "Y_EQ", "Y_GT", "Y_GE",
  "Y_RSHIFT", "Y_RSHIFT_EQUAL", "Y_QUESTION", "Y_LEFT_BRACKET",
  "Y_RIGHT_BRACKET", "Y_XOR", "Y_XOR_EQUAL", "Y___BASED", "Y___CDECL",
  "Y___EXPORT", "Y___FAR", "Y___FAR16", "Y___FORTRAN", "Y___HUGE",
  "Y___INTERRUPT", "Y___LOADDS", "Y___NEAR", "Y___PASCAL", "Y___PRAGMA",
  "Y___SAVEREGS", "Y___SEGMENT", "Y___SEGNAME", "Y___SELF", "Y___STDCALL",
  "Y__PACKED", "Y__SEG16", "Y__SYSCALL", "Y_THREAD_LOCAL", "Y_AUTO",
  "Y_CHAR", "Y_CONST", "Y_DOUBLE", "Y_ELSE", "Y_ENUM", "Y_EXTERN",
  "Y_FLOAT", "Y_INT", "Y_LONG", "Y_REGISTER", "Y_SHORT", "Y_SIGNED",
  "Y_SIZEOF", "Y_STATIC", "Y_STRUCT", "Y_TYPEDEF", "Y_UNION", "Y_UNSIGNED",
  "Y_VOID", "Y_VOLATILE", "Y_LEFT_BRACE", "Y_OR", "Y_OR_EQUAL", "Y_OR_OR",
  "Y_RIGHT_BRACE", "Y_TILDE", "Y_IF", "Y_STRING", "Y_INCLUDE_FILE_NAME",
  "Y_TYPEDEF_NAME", "Y_NUMBER", "Y_PERCENT", "Y_PERCENT_EQUAL",
  "Y_DEFINED", "Y_ENUMERATION_CONSTANT", "Y_FUNC_NAME", "Y_GENERIC",
  "Y_DEFAULT", "Y_CASE", "Y_ALIGNOF", "Y_IMAGINARY", "Y_COMPLEX",
  "Y_LONG_DOUBLE", "Y_BOOL", "Y_ATOMIC", "Y_RESTRICT", "Y_INLINE",
  "Y_NORETURN", "Y_ALIGNAS", "Y_STATIC_ASSERT", "Y_SWITCH", "Y_WHILE",
  "Y_DO", "Y_FOR", "Y_GOTO", "Y_CONTINUE", "Y_BREAK", "Y_RETURN",
  "Y_LONG_LONG", "\"then\"", "$accept", "primary_expression", "constant",
  "enumeration_constant", "string", "generic_selection",
  "generic_assoc_list", "generic_association", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "atomic_type_specifier", "type_qualifier", "function_specifier",
  "alignment_specifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "static_assert_declaration", "statement", "labeled_statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "declaration_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-363)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2381,  -363,  -363,  -363,  -363,  -363,    49,  -363,  -363,  -363,
    -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,
    -363,  -363,  -363,  -363,  -363,  -363,    37,  -363,  -363,  -363,
      59,    69,  -363,  -363,   183,  2436,  2436,  -363,    51,  -363,
    -363,  2436,  2436,  2436,  -363,   351,  -363,  -363,   -53,    75,
    2669,   848,  2032,  -363,   205,    66,  -363,    77,  -363,  2225,
       9,   158,  -363,  -363,     2,  2577,  -363,  -363,  -363,  -363,
    -363,    75,  -363,    43,    19,  -363,  2669,   140,  2669,   130,
    -363,  -363,  -363,  -363,  -363,  -363,   848,  -363,  -363,  2097,
    -363,  2097,  2128,  -363,  -363,  -363,   138,   143,  -363,  -363,
    -363,  -363,   272,  -363,  2032,  -363,    34,   151,    23,   268,
      64,   159,   131,   101,   189,   -26,  -363,   179,   191,   199,
     210,  -363,  -363,  -363,    66,   205,  -363,   874,   478,  -363,
     183,  -363,  2326,  1003,  1296,     9,  2577,  2485,  -363,   202,
    -363,    50,  2032,    22,  -363,  -363,  1113,  1324,    98,  -363,
     139,  -363,  -363,  2332,  -363,  -363,    84,   222,   848,  -363,
    -363,   848,  -363,  2032,  2669,  1819,  -363,  -363,   257,   269,
    2032,  -363,  2032,  2032,  2032,  2032,  2032,  2032,  2032,  2032,
    2032,  2032,  2032,  2032,  2032,  2032,  2032,  2032,  2032,  2032,
    2032,  -363,  -363,   198,  -363,  -363,  -363,  -363,   226,  1788,
    -363,  -363,   241,  -363,  -363,   270,   264,  2032,   275,   282,
    1044,   289,   279,   278,   281,  1840,   175,  -363,  -363,  -363,
    -363,   604,  -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,
    -363,   103,   306,   303,  -363,   209,   280,  -363,  1634,   290,
    1352,  2531,  -363,  -363,  2032,  -363,   201,  -363,   296,    46,
    -363,  -363,  -363,  -363,  -363,   327,   329,   300,  -363,  1634,
     304,  1465,   139,  1180,  1493,  -363,  -363,  -363,  -363,  -363,
    -363,  -363,  -363,  -363,  -363,  -363,  2032,  -363,  2032,  1884,
     332,   333,   331,   338,  -363,   252,  -363,  -363,  -363,    21,
    -363,  -363,  -363,    34,    34,   151,   151,    23,    23,    23,
      23,   268,   268,    64,   159,   131,   101,    35,   189,   339,
     353,  2032,  -363,    54,   874,   141,  -363,  1044,  2032,  1044,
     336,  2032,  2032,   251,   730,   341,  -363,  -363,  -363,   206,
    -363,  -363,  -363,   924,  -363,    17,  -363,  -363,  2170,  -363,
     371,  -363,   330,  1634,  -363,   334,  -363,  2032,   335,  -363,
    -363,   276,  -363,  2032,  -363,  -363,  -363,  -363,   340,  1634,
    -363,  -363,  2032,   342,  -363,   361,   343,  -363,  1634,   344,
    1521,  -363,  -363,  1788,  -363,   287,   287,  2623,  -363,  -363,
    2032,  -363,  2032,   346,  -363,   345,  1660,  -363,  -363,  -363,
    -363,  -363,   259,  -363,  1044,   260,   284,   367,  1936,  1936,
    -363,  -363,  -363,  -363,  -363,  -363,   348,  -363,   350,  -363,
    -363,  -363,  -363,   354,   355,  -363,  -363,  -363,   356,  1634,
    -363,  -363,  2032,   357,    56,   366,   302,  -363,   368,  -363,
    -363,  -363,  -363,  -363,  -363,   874,  1044,  -363,  1044,  1044,
    2032,  1980,  2001,  -363,  -363,  -363,  -363,  -363,   358,   362,
    -363,  1692,  -363,  2032,  -363,  2623,  2032,  -363,   311,  -363,
    -363,   307,  1044,   318,  1044,   322,  -363,  -363,  -363,  -363,
    -363,  -363,  1044,   359,  -363,  1044,  -363,  1044,  -363,  -363,
    -363,  -363
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   111,   112,   115,   161,   121,     0,   109,   120,   117,
     118,   113,   116,   123,   110,   135,   108,   136,   124,   114,
     163,   131,   127,   126,   122,   125,   164,   162,   165,   166,
       0,     0,   119,   273,     0,    95,    97,   129,     0,   130,
     128,    99,   101,   103,    93,     0,   270,   272,   155,     0,
       0,     0,     0,   171,     0,   188,    91,     0,   104,   107,
     170,     0,    94,    96,   134,     0,    98,   100,   102,     1,
     271,     0,    10,   159,     0,   156,   143,   201,   145,     0,
       2,     7,     8,    11,    42,    37,     0,    38,    39,     0,
      40,     0,     0,    41,     9,    12,     0,     0,    18,     3,
       4,     6,    30,    43,     0,    45,    49,    52,    55,    60,
      63,    65,    67,    69,    71,    73,    90,     0,     0,     0,
       0,   164,   189,   187,   186,     0,    92,     0,     0,   276,
       0,   275,     0,     0,     0,   169,     0,     0,   137,     0,
     141,     0,     0,     0,   151,   142,     0,     0,   203,   200,
     204,   144,   160,    43,    75,    88,     0,     0,     0,    31,
      32,     0,    34,     0,     0,     0,    24,    25,     0,     0,
       0,    33,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   168,   167,     0,   172,   190,   185,   105,   107,     0,
     228,   106,     2,   254,   248,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   252,   253,   239,
     240,     0,   250,   241,   242,   243,   244,   277,   274,   198,
     183,   197,     0,   192,   193,     0,    38,   173,     0,     0,
       0,     0,   132,   138,     0,   139,     0,   146,   150,     0,
     153,   158,   152,   157,   222,     0,     0,    38,   206,     0,
       0,     0,   202,     0,     0,    85,    78,    81,    82,    79,
      83,    77,    84,    86,    87,    80,     0,     5,     0,     0,
       0,     0,     0,     0,    20,     0,    28,    23,    22,     0,
      46,    47,    48,    50,    51,    54,    53,    56,    58,    57,
      59,    62,    61,    64,    66,    68,    70,     0,    72,     0,
       0,     0,   230,     0,     0,     0,   234,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   266,   267,   268,     0,
     255,   249,   251,     0,   195,   203,   196,   182,     0,   184,
       0,   174,     0,     0,   181,    38,   180,     0,     0,   133,
     148,     0,   140,     0,   154,   223,   205,   207,     0,     0,
     213,   212,     0,     0,   224,     0,    38,   214,     0,     0,
       0,    76,    89,     0,    44,     0,    35,     0,    36,    21,
       0,    19,     0,     0,   237,     0,     0,   226,   229,   233,
     235,   245,     0,   247,     0,     0,     0,     0,     0,     0,
     265,   269,   191,   194,   199,   176,     0,   177,     0,   179,
     147,   149,   209,     0,     0,   211,   225,   215,     0,     0,
     221,   220,     0,     0,     0,     0,     0,    14,     0,    29,
      74,   238,   236,   227,   232,     0,     0,   246,     0,     0,
       0,     0,     0,   175,   178,   208,   210,   217,     0,     0,
     218,     0,    26,     0,    13,     0,     0,   231,   256,   258,
     259,     0,     0,     0,     0,     0,   216,   219,    27,    17,
      15,    16,     0,     0,   263,     0,   261,     0,   257,   260,
     264,   262
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -363,  -363,  -363,  -363,  -363,  -363,  -363,   -49,  -363,  -363,
      71,  -363,   -44,    53,  -119,   182,    58,   223,   225,   227,
     221,   228,  -363,   -42,    24,  -363,   -82,   -41,   -47,     3,
    -363,   288,  -363,   -43,  -363,  -363,   297,  -110,   -46,  -363,
      65,  -363,   370,  -125,  -363,   -50,  -363,  -363,    -5,   -59,
     -14,  -100,  -117,  -363,    79,  -363,    18,   -63,  -135,  -121,
      42,  -362,  -363,   127,   -10,  -107,  -363,    11,  -363,   224,
    -303,  -363,  -363,  -363,  -363,   399,  -363,  -363
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    98,    99,    73,   100,   101,   426,   427,   102,   285,
     153,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   154,   155,   276,   216,   117,    33,   130,
      57,    58,    35,    36,    37,    38,   137,   138,    77,   246,
     247,    39,    74,    75,    40,    41,    42,    43,   120,    60,
      61,   124,   255,   233,   234,   235,   428,   256,   150,   312,
     313,   314,   315,   316,    44,   218,   219,   220,   221,   222,
     223,   224,   225,   226,    45,    46,    47,   132
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      78,    78,   135,    34,   156,   122,   201,    76,    76,   116,
     116,   119,   129,   262,   149,    78,   232,   189,   253,   139,
      53,   399,    76,   133,   435,    72,    78,   243,    78,    59,
     145,   333,   151,    76,   240,    76,    78,    71,    62,    63,
     143,   123,   278,    76,    66,    67,    68,   261,    34,    72,
     172,    50,    48,   134,    64,   140,   278,   177,   295,   296,
     171,   147,   173,   148,   178,   382,   381,   190,    79,   118,
     131,   249,   183,    51,   195,   386,   156,   451,    72,   156,
     142,   217,    55,    52,   122,   227,    78,    78,   289,   435,
     139,   139,   136,    76,    76,   441,   442,   122,   125,   277,
     116,   251,   184,   323,   157,   278,    53,   307,    78,   126,
     196,    78,   146,   144,    78,    76,   252,   333,    76,    55,
     198,    76,   103,   103,   253,   198,   140,   140,   290,   291,
     292,   243,   148,   329,   248,   174,   231,     4,   343,    49,
     354,    65,   147,   228,   250,   152,   365,   147,   387,   231,
     452,   200,   163,   263,   146,    20,    55,   164,   239,   359,
     159,    53,   160,   162,   370,   116,   320,   310,   336,   175,
     185,   260,    54,   176,   217,   103,   280,   186,   389,   281,
     121,    27,   283,   264,   147,   311,    53,   282,   122,   286,
     195,    78,   187,   388,   191,   139,   278,    54,    76,    55,
     262,   188,   116,   350,   309,    53,   192,   330,    53,   122,
     391,   195,   393,   103,   122,    56,    54,   335,    55,    54,
     193,    55,   351,   200,   339,   194,   334,   278,   293,   294,
     340,   140,   244,   352,   245,   374,   392,   279,   401,   395,
     396,   301,   302,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     287,   103,   342,   127,   348,   434,   231,   379,   419,   116,
     385,   317,   288,   380,   436,   438,   135,   398,   103,    53,
     278,   278,   325,   358,   318,   363,   165,   437,   369,   321,
      54,   166,    55,   195,   319,   167,   322,   168,   169,   439,
     371,   179,   372,   324,   180,   278,   244,   181,   182,   195,
     326,   116,   411,   327,   457,   103,   170,   454,   122,   335,
     195,   337,   473,   455,   338,   341,   353,    78,   278,   458,
     434,   459,   460,   475,    76,   344,   231,   477,   200,   278,
     430,   231,   355,   278,   356,   357,   248,   375,   376,   360,
     103,    69,   377,   378,   383,   474,   384,   476,   461,   463,
     465,   297,   298,   299,   300,   478,   394,   406,   480,   195,
     481,   408,   397,   400,   404,   405,   416,   373,   431,   407,
     409,   440,   103,   413,   472,   412,   414,   415,   417,   420,
     432,   479,   418,   443,   423,   444,   453,   200,   456,   445,
     446,   447,   450,   466,   429,    78,   470,   467,   303,   306,
     200,   304,    76,   197,   305,   424,   410,   403,   308,     1,
       2,     3,     4,     5,   103,     6,     7,     8,     9,    10,
      11,    12,    13,   241,    14,    15,    16,    17,    18,    19,
      20,   141,   390,   448,    70,   332,   449,     0,     0,     0,
      21,     0,     0,   103,     0,     0,     0,     0,     0,   200,
       0,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     0,     0,     0,     0,   200,     0,   469,     0,    32,
     471,   202,    81,    82,    83,    84,     0,     0,     0,    85,
       0,     0,    86,     0,    87,     0,    88,    89,     0,     0,
      90,    91,     0,     0,     0,     0,     0,     0,     0,     0,
     203,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     2,     3,     4,
       5,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      92,    14,    15,    16,    17,    18,    19,    20,   128,     0,
       0,     0,   204,    93,   205,     0,     0,    21,     0,     0,
       0,     0,    94,    95,    96,   206,   207,    97,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,   208,   209,
     210,   211,   212,   213,   214,   215,    32,   202,    81,    82,
      83,    84,     0,     0,     0,    85,     0,     0,    86,     0,
      87,     0,    88,    89,     0,     0,    90,    91,     0,     0,
       0,     0,     0,     0,     0,     0,   203,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     4,     5,     0,     6,     7,
       8,     9,    10,    11,    12,    13,    92,    14,    15,    16,
      17,    18,    19,    20,   128,     0,     0,     0,   331,    93,
     205,     0,     0,    21,     0,     0,     0,     0,    94,    95,
      96,   206,   207,    97,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,   208,   209,   210,   211,   212,   213,
     214,   215,    32,    80,    81,    82,    83,    84,     0,     0,
       0,    85,     0,     0,    86,     0,    87,     0,    88,    89,
       0,     0,    90,    91,     0,     0,     0,     0,     0,     0,
       0,     0,   203,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       3,     4,     5,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    92,    14,    15,    16,    17,    18,    19,    20,
       0,     0,     0,     0,     0,    93,     0,     0,     0,    21,
       0,     0,     0,     0,    94,    95,    96,     0,     0,    97,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       0,    80,    81,    82,    83,    84,     0,     0,    32,    85,
       0,     0,    86,     0,    87,     0,    88,    89,     0,     0,
      90,    91,     0,     0,     0,     0,     0,    80,    81,    82,
      83,    84,     0,     0,     0,    85,     0,     0,    86,     0,
      87,     0,    88,    89,     0,     0,    90,    91,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     0,     6,     0,     8,     9,    10,    53,    12,    13,
      92,     0,    15,     0,    17,    18,    19,    20,   333,   254,
      55,     0,     0,    93,     0,     0,     0,    21,     0,     0,
       0,     0,    94,    95,    96,     0,    92,    97,    22,    23,
      24,    25,    26,    27,   199,     0,     0,     0,   147,    93,
       0,     0,     0,     0,     0,     0,    32,     0,    94,    95,
      96,     0,     0,    97,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     4,     5,     0,     6,     7,
       8,     9,    10,    11,    12,    13,   229,    14,    15,    16,
      17,    18,    19,    20,     0,     0,     0,     0,   230,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     0,     0,     0,     0,   202,    81,    82,
      83,    84,    32,     0,     0,    85,     0,     0,    86,     0,
      87,     0,    88,    89,     0,     0,    90,    91,     0,     0,
       0,     1,     2,     3,     4,     5,   203,     6,     7,     8,
       9,    10,    11,    12,    13,     0,    14,    15,    16,    17,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,     0,     0,     0,    92,   146,   254,    55,
       0,    32,     0,     0,   128,     0,     0,     0,     0,    93,
     205,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,   206,   207,    97,     0,     0,     0,   147,     0,     0,
       0,     0,     0,     0,   208,   209,   210,   211,   212,   213,
     214,   215,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     3,     4,     5,     0,     6,     7,     8,
       9,    10,    11,    12,    13,   364,    14,    15,    16,    17,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,     0,     0,     0,     0,     0,     0,     1,     2,
       3,     4,     5,     0,     6,     7,     8,     9,    10,    11,
      12,    13,     0,    14,    15,    16,    17,    18,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    80,
      81,    82,    83,    84,     0,     0,     0,    85,    32,     0,
      86,     0,   236,     0,    88,    89,     0,     0,    90,    91,
       0,     0,     0,     0,     0,     0,     0,    80,    81,    82,
      83,    84,     0,     0,     0,    85,     0,     0,    86,     0,
     257,   237,    88,    89,     0,     0,    90,    91,     0,     0,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    84,
       0,     0,     0,    85,     0,     0,    86,     4,   345,   258,
      88,    89,     0,     0,    90,    91,     0,     0,    92,   238,
       0,     0,     0,     0,     0,    20,     0,     0,     0,     0,
       0,    93,     0,     0,     0,     4,     0,   346,     0,     0,
      94,    95,    96,     0,     0,    97,    92,   259,     0,     0,
     121,    27,     0,    20,     0,     0,     0,     0,     0,    93,
       0,     0,     0,     4,     0,     0,     0,     0,    94,    95,
      96,     0,     0,    97,    92,   347,     0,     0,   121,    27,
       0,    20,     0,     0,     0,     0,     0,    93,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,     0,
       0,    97,     0,     0,     0,     0,   121,    27,    80,    81,
      82,    83,    84,     0,     0,     0,    85,     0,     0,    86,
       0,    87,     0,    88,    89,     0,     0,    90,    91,     0,
       0,     0,     0,     0,     0,     0,    80,    81,    82,    83,
      84,     0,     0,     0,    85,     0,     0,    86,     0,   366,
     361,    88,    89,     0,     0,    90,    91,     0,     0,     0,
       0,     0,     0,     0,    80,    81,    82,    83,    84,     0,
       0,     0,    85,     0,     0,    86,     4,    87,   367,    88,
      89,     0,     0,    90,    91,     0,     0,    92,   362,     0,
       0,     0,     0,     0,    20,     0,     0,     0,     0,     0,
      93,     0,     0,     0,     4,     0,   421,     0,     0,    94,
      95,    96,     0,     0,    97,    92,   368,     0,     0,   121,
      27,     0,    20,     0,     0,     0,     0,     0,    93,     0,
       0,     0,     4,     0,     0,     0,     0,    94,    95,    96,
       0,     0,    97,    92,   422,     0,     0,   121,    27,     0,
      20,     0,     0,     0,     0,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,     0,     0,
      97,     0,     0,     0,     0,   121,    27,    80,    81,    82,
      83,    84,     0,     0,     0,    85,     0,     0,    86,     0,
      87,     0,    88,    89,     0,     0,    90,    91,     0,     0,
       0,     0,     0,    80,    81,    82,    83,    84,     0,     0,
       0,    85,     0,     0,    86,     0,    87,     0,    88,    89,
       0,     0,    90,    91,     0,     0,   310,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    84,
       0,     0,     0,    85,   311,     4,    86,     0,    87,     0,
      88,    89,     0,     0,    90,    91,    92,     0,   310,     0,
       0,     0,     0,    20,     0,     0,     0,     0,     0,    93,
       0,     0,     0,     0,     0,     0,   311,     0,    94,    95,
      96,     0,    92,    97,     0,     0,     0,     0,   121,    27,
     199,     0,     0,     0,   433,    93,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,     0,     0,    97,
       0,     0,     0,     0,    92,     0,     0,     0,     0,     0,
       0,     0,   199,     0,     0,     0,   468,    93,     0,     0,
       0,    80,    81,    82,    83,    84,    94,    95,    96,    85,
       0,    97,    86,     0,    87,     0,    88,    89,     0,     0,
      90,    91,     0,     0,   310,     0,     0,     0,     0,     0,
       0,     0,    80,    81,    82,    83,    84,     0,     0,     0,
      85,     0,   311,    86,   284,    87,     0,    88,    89,     0,
       0,    90,    91,    80,    81,    82,    83,    84,     0,     0,
       0,    85,     0,     0,    86,     0,    87,     0,    88,    89,
       0,     0,    90,    91,     0,     0,     0,     0,     0,     0,
      92,     0,   328,     0,     0,     0,     0,     0,   199,     0,
       0,     0,     0,    93,     0,     0,     0,    80,    81,    82,
      83,    84,    94,    95,    96,    85,     0,    97,    86,     0,
      87,    92,    88,    89,     0,     0,    90,    91,     0,     0,
       0,     0,     0,     0,    93,     0,     0,     0,     0,     0,
       0,     0,    92,    94,    95,    96,     0,     0,    97,     0,
       0,     0,     0,     0,     0,    93,     0,     0,     0,    80,
      81,    82,    83,    84,    94,    95,    96,    85,     0,    97,
      86,     0,    87,     0,    88,    89,     0,     0,    90,    91,
       0,     0,     0,     0,     0,     0,    92,     0,   203,     0,
       0,     0,     0,     0,   373,     0,     0,     0,     0,    93,
       0,     0,     0,    80,    81,    82,    83,    84,    94,    95,
      96,    85,     0,    97,    86,   462,    87,     0,    88,    89,
       0,     0,    90,    91,    80,    81,    82,    83,    84,     0,
       0,     0,    85,     0,     0,    86,   464,    87,    92,    88,
      89,     0,     0,    90,    91,     0,     0,     0,     0,     0,
       0,    93,     0,     0,     0,    80,    81,    82,    83,    84,
      94,    95,    96,    85,     0,    97,    86,     0,    87,     0,
      88,    89,     0,     0,    90,    91,     0,     0,     0,     0,
       0,     0,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,     0,     0,     0,     0,
       0,     0,     0,    92,    94,    95,    96,     0,     0,    97,
       0,     0,     0,     0,     0,     0,    93,     0,     0,     0,
      80,    81,    82,    83,    84,    94,    95,    96,    85,     0,
      97,   158,     0,    87,    92,    88,    89,     0,     0,    90,
      91,     0,     0,     0,     0,     0,     0,    93,     0,     0,
       0,    80,    81,    82,    83,    84,    94,    95,    96,    85,
       0,    97,   161,     0,    87,     0,    88,    89,     0,     0,
      90,    91,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,     0,     0,     0,     0,   402,     0,     0,
       0,    94,    95,    96,     0,     0,    97,     0,     0,     0,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    93,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,     0,     0,    97,     1,     2,
       3,     4,     5,     0,     6,     7,     8,     9,    10,    11,
      12,    13,     0,    14,    15,    16,    17,    18,    19,    20,
       0,     0,   127,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,    23,    24,    25,    26,    27,    28,    29,    30,     0,
       0,     0,     0,     1,     2,     3,     4,     5,    32,     6,
       7,     8,     9,    10,    11,    12,    13,     0,    14,    15,
      16,    17,    18,    19,    20,   128,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,   265,     0,     0,     0,   266,
       0,     0,   267,    32,     0,     0,   268,     0,     0,     0,
       0,   269,     0,     0,     0,     0,     0,   270,     0,   271,
       0,     0,     0,     0,   272,     0,     0,     0,     0,   273,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     3,     4,     5,     0,
       6,     7,     8,     9,    10,    11,    12,    13,     0,    14,
      15,    16,    17,    18,    19,    20,   128,     0,     0,     0,
       0,     0,     0,     0,   274,    21,     0,     0,     0,     0,
       0,     0,     0,     0,   275,     0,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,     0,     0,     0,     1,
       2,     3,     4,     5,    32,     6,     7,     8,     9,    10,
      11,    12,    13,     0,    14,    15,    16,    17,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     0,     0,     0,     1,     2,     3,     4,     5,    32,
       6,     7,     8,     9,    10,    11,    12,    13,     0,    14,
      15,    16,    17,    18,    19,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,    23,    24,    25,
      26,    27,    28,    29,    30,     3,     4,     5,     0,     6,
       0,     8,     9,    10,    32,    12,    13,     0,     0,    15,
       0,    17,    18,    19,    20,     0,     0,     0,     0,   242,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    23,    24,    25,    26,
      27,     3,     4,     5,    31,     6,     0,     8,     9,    10,
       0,    12,    13,    32,     0,    15,     0,    17,    18,    19,
      20,     0,     0,     0,     0,   349,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,    23,    24,    25,    26,    27,     3,     4,     5,
      31,     6,     0,     8,     9,    10,     0,    12,    13,    32,
       0,    15,     0,    17,    18,    19,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,    23,    24,
      25,    26,    27,     3,     4,     5,    31,     6,     0,     8,
       9,    10,     0,    12,    13,    32,     0,    15,     0,    17,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,     0,
     425,     0,     0,    22,    23,    24,    25,    26,    27,     3,
       4,     5,     0,     6,     0,     8,     9,    10,     0,    12,
      13,    32,     0,    15,     0,    17,    18,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
      23,    24,    25,    26,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32
};

static const yytype_int16 yycheck[] =
{
      50,    51,    61,     0,    86,    55,   127,    50,    51,    51,
      52,    52,    59,   148,    77,    65,   133,    43,   143,    65,
       3,   324,    65,    14,   386,     3,    76,   137,    78,    34,
      76,    14,    78,    76,   134,    78,    86,    90,    35,    36,
      21,    55,    21,    86,    41,    42,    43,   147,    45,     3,
      16,    14,     3,    44,     3,    65,    21,    34,   177,   178,
     104,    44,    28,    77,    41,    30,    45,    93,    50,    51,
      59,    21,     8,    14,   124,    21,   158,    21,     3,   161,
      37,   128,    16,    14,   134,   132,   136,   137,   170,   451,
     136,   137,    90,   136,   137,   398,   399,   147,    21,    15,
     142,   142,    38,   210,    86,    21,     3,   189,   158,    32,
     124,   161,    14,    94,   164,   158,    94,    14,   161,    16,
     125,   164,    51,    52,   249,   130,   136,   137,   172,   173,
     174,   241,   146,   215,   139,   101,   133,    71,   238,    90,
      94,    90,    44,   132,    94,    15,   263,    44,    94,   146,
      94,   127,    14,    14,    14,    89,    16,    14,   134,   259,
      89,     3,    91,    92,   264,   207,   207,    26,   231,    18,
      11,   147,    14,    22,   221,   104,   158,    46,    37,   161,
     114,   115,   164,    44,    44,    44,     3,   163,   238,   165,
     240,   241,    91,   314,    15,   241,    21,    14,   241,    16,
     335,    12,   244,   244,     6,     3,    15,    32,     3,   259,
     317,   261,   319,   142,   264,    32,    14,   231,    16,    14,
      21,    16,    21,   199,    15,    15,   231,    21,   175,   176,
      21,   241,    30,    32,    32,   279,   318,    15,    32,   321,
     322,   183,   184,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       3,   190,   238,    37,   240,   386,   263,    15,   368,   311,
     311,    30,     3,    21,    15,    15,   335,   324,   207,     3,
      21,    21,     3,   259,    14,   261,    14,   394,   264,    14,
      14,    19,    16,   343,    30,    23,    14,    25,    26,    15,
     276,    33,   278,    14,    36,    21,    30,    39,    40,   359,
      32,   353,   353,    32,   435,   244,    44,    15,   368,   333,
     370,    15,    15,    21,    21,    45,    30,   377,    21,   436,
     451,   438,   439,    15,   377,    45,   333,    15,   314,    21,
     382,   338,    15,    21,    15,    45,   351,    15,    15,    45,
     279,     0,    21,    15,    15,   462,     3,   464,   440,   441,
     442,   179,   180,   181,   182,   472,    30,   343,   475,   419,
     477,   347,   121,    32,     3,    45,    15,    90,    32,    45,
      45,    14,   311,   359,    73,    45,   362,    45,    45,    45,
      45,    32,   368,    45,   370,    45,    30,   373,    30,    45,
      45,    45,    45,    45,   380,   455,   455,    45,   185,   188,
     386,   186,   455,   125,   187,   373,   351,   338,   190,    68,
      69,    70,    71,    72,   353,    74,    75,    76,    77,    78,
      79,    80,    81,   136,    83,    84,    85,    86,    87,    88,
      89,    71,   315,   419,    45,   221,   422,    -1,    -1,    -1,
      99,    -1,    -1,   382,    -1,    -1,    -1,    -1,    -1,   435,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    -1,    -1,    -1,    -1,   451,    -1,   453,    -1,   128,
     456,     3,     4,     5,     6,     7,    -1,    -1,    -1,    11,
      -1,    -1,    14,    -1,    16,    -1,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,
      72,    -1,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      -1,    -1,    94,    95,    96,    -1,    -1,    99,    -1,    -1,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    11,    -1,    -1,    14,    -1,
      16,    -1,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    71,    72,    -1,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,    -1,    -1,    94,    95,
      96,    -1,    -1,    99,    -1,    -1,    -1,    -1,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    11,    -1,    -1,    14,    -1,    16,    -1,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    -1,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,   104,   105,   106,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,     3,     4,     5,     6,     7,    -1,    -1,   128,    11,
      -1,    -1,    14,    -1,    16,    -1,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    11,    -1,    -1,    14,    -1,
      16,    -1,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    -1,    74,    -1,    76,    77,    78,     3,    80,    81,
      82,    -1,    84,    -1,    86,    87,    88,    89,    14,    15,
      16,    -1,    -1,    95,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,   104,   105,   106,    -1,    82,   109,   110,   111,
     112,   113,   114,   115,    90,    -1,    -1,    -1,    44,    95,
      -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,   104,   105,
     106,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    71,    72,    -1,    74,    75,
      76,    77,    78,    79,    80,    81,     3,    83,    84,    85,
      86,    87,    88,    89,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,   128,    -1,    -1,    11,    -1,    -1,    14,    -1,
      16,    -1,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    68,    69,    70,    71,    72,    32,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    83,    84,    85,    86,
      87,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    -1,    -1,    -1,    -1,    82,    14,    15,    16,
      -1,   128,    -1,    -1,    90,    -1,    -1,    -1,    -1,    95,
      96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,
     106,   107,   108,   109,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    -1,   120,   121,   122,   123,   124,   125,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    69,    70,    71,    72,    -1,    74,    75,    76,
      77,    78,    79,    80,    81,    15,    83,    84,    85,    86,
      87,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    -1,    74,    75,    76,    77,    78,    79,
      80,    81,    -1,    83,    84,    85,    86,    87,    88,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    11,   128,    -1,
      14,    -1,    16,    -1,    18,    19,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    11,    -1,    -1,    14,    -1,
      16,    45,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    11,    -1,    -1,    14,    71,    16,    45,
      18,    19,    -1,    -1,    22,    23,    -1,    -1,    82,    83,
      -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,
      -1,    95,    -1,    -1,    -1,    71,    -1,    45,    -1,    -1,
     104,   105,   106,    -1,    -1,   109,    82,    83,    -1,    -1,
     114,   115,    -1,    89,    -1,    -1,    -1,    -1,    -1,    95,
      -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,   104,   105,
     106,    -1,    -1,   109,    82,    83,    -1,    -1,   114,   115,
      -1,    89,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,    -1,
      -1,   109,    -1,    -1,    -1,    -1,   114,   115,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    11,    -1,    -1,    14,
      -1,    16,    -1,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    11,    -1,    -1,    14,    -1,    16,
      45,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    11,    -1,    -1,    14,    71,    16,    45,    18,
      19,    -1,    -1,    22,    23,    -1,    -1,    82,    83,    -1,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,
      95,    -1,    -1,    -1,    71,    -1,    45,    -1,    -1,   104,
     105,   106,    -1,    -1,   109,    82,    83,    -1,    -1,   114,
     115,    -1,    89,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    -1,   104,   105,   106,
      -1,    -1,   109,    82,    83,    -1,    -1,   114,   115,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,   105,   106,    -1,    -1,
     109,    -1,    -1,    -1,    -1,   114,   115,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    11,    -1,    -1,    14,    -1,
      16,    -1,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    11,    -1,    -1,    14,    -1,    16,    -1,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    11,    44,    71,    14,    -1,    16,    -1,
      18,    19,    -1,    -1,    22,    23,    82,    -1,    26,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,   104,   105,
     106,    -1,    82,   109,    -1,    -1,    -1,    -1,   114,   115,
      90,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   104,   105,   106,    -1,    -1,   109,
      -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    -1,    94,    95,    -1,    -1,
      -1,     3,     4,     5,     6,     7,   104,   105,   106,    11,
      -1,   109,    14,    -1,    16,    -1,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      11,    -1,    44,    14,    15,    16,    -1,    18,    19,    -1,
      -1,    22,    23,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    11,    -1,    -1,    14,    -1,    16,    -1,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      82,    -1,    32,    -1,    -1,    -1,    -1,    -1,    90,    -1,
      -1,    -1,    -1,    95,    -1,    -1,    -1,     3,     4,     5,
       6,     7,   104,   105,   106,    11,    -1,   109,    14,    -1,
      16,    82,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,   104,   105,   106,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,     3,
       4,     5,     6,     7,   104,   105,   106,    11,    -1,   109,
      14,    -1,    16,    -1,    18,    19,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    -1,    -1,    95,
      -1,    -1,    -1,     3,     4,     5,     6,     7,   104,   105,
     106,    11,    -1,   109,    14,    15,    16,    -1,    18,    19,
      -1,    -1,    22,    23,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    11,    -1,    -1,    14,    15,    16,    82,    18,
      19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    -1,    -1,    -1,     3,     4,     5,     6,     7,
     104,   105,   106,    11,    -1,   109,    14,    -1,    16,    -1,
      18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,   104,   105,   106,    -1,    -1,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
       3,     4,     5,     6,     7,   104,   105,   106,    11,    -1,
     109,    14,    -1,    16,    82,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,
      -1,     3,     4,     5,     6,     7,   104,   105,   106,    11,
      -1,   109,    14,    -1,    16,    -1,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,   104,   105,   106,    -1,    -1,   109,    -1,    -1,    -1,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   104,   105,   106,    -1,    -1,   109,    68,    69,
      70,    71,    72,    -1,    74,    75,    76,    77,    78,    79,
      80,    81,    -1,    83,    84,    85,    86,    87,    88,    89,
      -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,    -1,    68,    69,    70,    71,    72,   128,    74,
      75,    76,    77,    78,    79,    80,    81,    -1,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,    13,    -1,    -1,    -1,    17,
      -1,    -1,    20,   128,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    35,    -1,    37,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,    -1,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   102,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,    68,
      69,    70,    71,    72,   128,    74,    75,    76,    77,    78,
      79,    80,    81,    -1,    83,    84,    85,    86,    87,    88,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    -1,    -1,    -1,    68,    69,    70,    71,    72,   128,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    83,
      84,    85,    86,    87,    88,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    70,    71,    72,    -1,    74,
      -1,    76,    77,    78,   128,    80,    81,    -1,    -1,    84,
      -1,    86,    87,    88,    89,    -1,    -1,    -1,    -1,    94,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,    70,    71,    72,   119,    74,    -1,    76,    77,    78,
      -1,    80,    81,   128,    -1,    84,    -1,    86,    87,    88,
      89,    -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,    70,    71,    72,
     119,    74,    -1,    76,    77,    78,    -1,    80,    81,   128,
      -1,    84,    -1,    86,    87,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,    70,    71,    72,   119,    74,    -1,    76,
      77,    78,    -1,    80,    81,   128,    -1,    84,    -1,    86,
      87,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,    -1,   110,   111,   112,   113,   114,   115,    70,
      71,    72,    -1,    74,    -1,    76,    77,    78,    -1,    80,
      81,   128,    -1,    84,    -1,    86,    87,    88,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    68,    69,    70,    71,    72,    74,    75,    76,    77,
      78,    79,    80,    81,    83,    84,    85,    86,    87,    88,
      89,    99,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   128,   158,   159,   162,   163,   164,   165,   171,
     174,   175,   176,   177,   194,   204,   205,   206,     3,    90,
      14,    14,    14,     3,    14,    16,    32,   160,   161,   178,
     179,   180,   159,   159,     3,    90,   159,   159,   159,     0,
     205,    90,     3,   133,   172,   173,   163,   168,   175,   186,
       3,     4,     5,     6,     7,    11,    14,    16,    18,    19,
      22,    23,    82,    95,   104,   105,   106,   109,   131,   132,
     134,   135,   138,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   157,   186,   157,
     178,   114,   175,   180,   181,    21,    32,    37,    90,   158,
     159,   197,   207,    14,    44,   179,    90,   166,   167,   168,
     194,   172,    37,    21,    94,   168,    14,    44,   180,   187,
     188,   168,    15,   140,   153,   154,   156,   186,    14,   140,
     140,    14,   140,    14,    14,    14,    19,    23,    25,    26,
      44,   142,    16,    28,   101,    18,    22,    34,    41,    33,
      36,    39,    40,     8,    38,    11,    46,    91,    12,    43,
      93,    15,    15,    21,    15,   175,   180,   161,   178,    90,
     154,   189,     3,    32,    94,    96,   107,   108,   120,   121,
     122,   123,   124,   125,   126,   127,   156,   158,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   158,   197,     3,
      15,   159,   182,   183,   184,   185,    16,    45,    83,   154,
     181,   166,    94,   167,    30,    32,   169,   170,   178,    21,
      94,   157,    94,   173,    15,   182,   187,    16,    45,    83,
     154,   181,   188,    14,    44,    13,    17,    20,    24,    29,
      35,    37,    42,    47,    92,   102,   155,    15,    21,    15,
     186,   186,   154,   186,    15,   139,   154,     3,     3,   156,
     142,   142,   142,   143,   143,   144,   144,   145,   145,   145,
     145,   146,   146,   147,   148,   149,   150,   156,   151,     6,
      26,    44,   189,   190,   191,   192,   193,    30,    14,    30,
     157,    14,    14,   195,    14,     3,    32,    32,    32,   156,
      32,    94,   199,    14,   178,   180,   187,    15,    21,    15,
      21,    45,   154,   181,    45,    16,    45,    83,   154,    94,
     157,    21,    32,    30,    94,    15,    15,    45,   154,   181,
      45,    45,    83,   154,    15,   182,    16,    45,    83,   154,
     181,   154,   154,    90,   142,    15,    15,    21,    15,    15,
      21,    45,    30,    15,     3,   157,    21,    94,   189,    37,
     193,   195,   156,   195,    30,   156,   156,   121,   158,   200,
      32,    32,    27,   184,     3,    45,   154,    45,   154,    45,
     170,   157,    45,   154,   154,    45,    15,    45,   154,   181,
      45,    45,    83,   154,   190,   107,   136,   137,   186,   154,
     153,    32,    45,    94,   189,   191,    15,   195,    15,    15,
      14,   200,   200,    45,    45,    45,    45,    45,   154,   154,
      45,    21,    94,    30,    15,    21,    30,   189,   195,   195,
     195,   156,    15,   156,    15,   156,    45,    45,    94,   154,
     137,   154,    73,    15,   195,    15,   195,    15,   195,    32,
     195,   195
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   130,   131,   131,   131,   131,   131,   132,   132,   132,
     133,   134,   134,   135,   136,   136,   137,   137,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   139,   139,
     140,   140,   140,   140,   140,   140,   140,   141,   141,   141,
     141,   141,   141,   142,   142,   143,   143,   143,   143,   144,
     144,   144,   145,   145,   145,   146,   146,   146,   146,   146,
     147,   147,   147,   148,   148,   149,   149,   150,   150,   151,
     151,   152,   152,   153,   153,   154,   154,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   156,   156,
     157,   158,   158,   158,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   160,   160,   161,   161,   162,   162,
     162,   162,   162,   162,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   164,   164,   164,   165,   165,   166,   166,   167,
     167,   167,   168,   168,   168,   168,   169,   169,   170,   170,
     170,   171,   171,   171,   171,   171,   172,   172,   173,   173,
     174,   175,   175,   175,   175,   176,   176,   177,   177,   178,
     178,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   180,   180,   180,   180,   181,
     181,   182,   182,   183,   183,   184,   184,   184,   185,   185,
     186,   186,   187,   187,   187,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   189,   189,   189,   190,
     190,   190,   190,   191,   192,   192,   193,   193,   194,   195,
     195,   195,   195,   195,   195,   196,   196,   196,   197,   197,
     198,   198,   199,   199,   200,   200,   201,   201,   201,   202,
     202,   202,   202,   202,   202,   203,   203,   203,   203,   203,
     204,   204,   205,   205,   206,   206,   207,   207
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     6,     1,     3,     3,     3,     1,     4,
       3,     4,     3,     3,     2,     2,     6,     7,     1,     3,
       1,     2,     2,     2,     2,     4,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     3,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     5,     2,     1,     1,     1,     2,     2,
       3,     1,     2,     1,     2,     1,     1,     3,     2,     3,
       1,     4,     5,     5,     6,     2,     1,     3,     3,     1,
       4,     1,     1,     1,     1,     1,     1,     4,     4,     2,
       1,     1,     3,     3,     4,     6,     5,     5,     6,     5,
       4,     4,     4,     3,     4,     3,     2,     2,     1,     1,
       2,     3,     1,     1,     3,     2,     2,     1,     1,     3,
       2,     1,     2,     1,     1,     3,     2,     3,     5,     4,
       5,     4,     3,     3,     3,     4,     6,     5,     5,     6,
       4,     4,     2,     3,     3,     4,     3,     4,     1,     2,
       1,     4,     3,     2,     1,     2,     3,     2,     7,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     2,     3,
       1,     2,     1,     1,     1,     2,     5,     7,     5,     5,
       7,     6,     7,     6,     7,     3,     2,     2,     2,     3,
       1,     2,     1,     1,     4,     3,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval);
    }

  if (yychar <= END)
    {
      yychar = END;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* primary_expression: "identifier"  */
#line 223 "c11ansi.y"
                                                { (yyval.expression) = createCTreeRoot(createTokenLabel((yyvsp[0].token))); }
#line 2124 "c11ansi.c"
    break;

  case 3: /* primary_expression: constant  */
#line 224 "c11ansi.y"
                                                { (yyval.expression) = createCTreeRoot(createTokenLabel((yyvsp[0].token))); }
#line 2130 "c11ansi.c"
    break;

  case 4: /* primary_expression: string  */
#line 225 "c11ansi.y"
                                                { (yyval.expression) = createCTreeRoot(createTokenLabel((yyvsp[0].token))); }
#line 2136 "c11ansi.c"
    break;

  case 5: /* primary_expression: Y_LEFT_PAREN expression Y_RIGHT_PAREN  */
#line 226 "c11ansi.y"
                                                { (yyval.expression) = createCTree1(createConstr2Label(LABCT_PAREN_EXPR, (yyvsp[-2].token), (yyvsp[0].token)), (yyvsp[-1].expression)); }
#line 2142 "c11ansi.c"
    break;

  case 6: /* primary_expression: generic_selection  */
#line 227 "c11ansi.y"
                                                { (yyval.expression) = createCTreeRoot(createGenericSelectionLabel((yyvsp[0].genericSelection))); }
#line 2148 "c11ansi.c"
    break;

  case 7: /* constant: "i_const"  */
#line 231 "c11ansi.y"
                                 { (yyval.token) = (yyvsp[0].token); }
#line 2154 "c11ansi.c"
    break;

  case 8: /* constant: "f_const"  */
#line 232 "c11ansi.y"
                                 { (yyval.token) = (yyvsp[0].token); }
#line 2160 "c11ansi.c"
    break;

  case 9: /* constant: Y_ENUMERATION_CONSTANT  */
#line 233 "c11ansi.y"
                                 { (yyval.token) = (yyvsp[0].token); }
#line 2166 "c11ansi.c"
    break;

  case 10: /* enumeration_constant: "identifier"  */
#line 237 "c11ansi.y"
                     { (yyval.token) = (yyvsp[0].token); }
#line 2172 "c11ansi.c"
    break;

  case 11: /* string: "sting_literal"  */
#line 241 "c11ansi.y"
                         { (yyval.token) = (yyvsp[0].token); }
#line 2178 "c11ansi.c"
    break;

  case 12: /* string: Y_FUNC_NAME  */
#line 242 "c11ansi.y"
                         { (yyval.token) = (yyvsp[0].token); }
#line 2184 "c11ansi.c"
    break;

  case 13: /* generic_selection: Y_GENERIC Y_LEFT_PAREN assignment_expression Y_COMMA generic_assoc_list Y_RIGHT_PAREN  */
#line 246 "c11ansi.y"
                                                                                                { (yyval.genericSelection) = createGenericSelection((yyvsp[-3].expression),(yyvsp[-1].list)); }
#line 2190 "c11ansi.c"
    break;

  case 14: /* generic_assoc_list: generic_association  */
#line 250 "c11ansi.y"
                                                         { (yyval.list) = createGenericAssocList((yyvsp[0].genericAssoc),NULL); }
#line 2196 "c11ansi.c"
    break;

  case 15: /* generic_assoc_list: generic_assoc_list Y_COMMA generic_association  */
#line 251 "c11ansi.y"
                                                         { (yyval.list) = createGenericAssocList((yyvsp[0].genericAssoc),(yyvsp[-2].list)); }
#line 2202 "c11ansi.c"
    break;

  case 16: /* generic_association: type_name Y_COLON assignment_expression  */
#line 255 "c11ansi.y"
                                                  { (yyval.genericAssoc) = createGenericAssoc((yyvsp[-2].typeName),(yyvsp[0].expression),NULL); }
#line 2208 "c11ansi.c"
    break;

  case 17: /* generic_association: Y_DEFAULT Y_COLON assignment_expression  */
#line 256 "c11ansi.y"
                                                  { (yyval.genericAssoc) = createGenericAssoc(NULL,(yyvsp[0].expression),(yyvsp[-2].token)); }
#line 2214 "c11ansi.c"
    break;

  case 18: /* postfix_expression: primary_expression  */
#line 260 "c11ansi.y"
                                                                                                    { (yyval.expression) = (yyvsp[0].expression); }
#line 2220 "c11ansi.c"
    break;

  case 19: /* postfix_expression: postfix_expression Y_LEFT_BRACKET expression Y_RIGHT_BRACKET  */
#line 261 "c11ansi.y"
                                                                                                    { (yyval.expression) = createCTree2(createConstr2Label(LABCT_INDEX, (yyvsp[-2].token), (yyvsp[0].token)), (yyvsp[-3].expression),  (yyvsp[-1].expression)); }
#line 2226 "c11ansi.c"
    break;

  case 20: /* postfix_expression: postfix_expression Y_LEFT_PAREN Y_RIGHT_PAREN  */
#line 262 "c11ansi.y"
                                                                                                    { (yyval.expression) = createCTree1(createConstr2Label(LABCT_CALL, (yyvsp[-1].token), (yyvsp[0].token)), (yyvsp[-2].expression)); }
#line 2232 "c11ansi.c"
    break;

  case 21: /* postfix_expression: postfix_expression Y_LEFT_PAREN argument_expression_list Y_RIGHT_PAREN  */
#line 263 "c11ansi.y"
                                                                                                    { (yyval.expression) = createCTree2(createConstr2Label(LABCT_CALL, (yyvsp[-2].token), (yyvsp[0].token)), (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 2238 "c11ansi.c"
    break;

  case 22: /* postfix_expression: postfix_expression Y_DOT "identifier"  */
#line 264 "c11ansi.y"
                                                                                                    { (yyval.expression) = createCTree2(createConstr1Label(LABCT_DOT, (yyvsp[-1].token)), (yyvsp[-2].expression), createCTreeRoot(createTokenLabel((yyvsp[0].token)))); }
#line 2244 "c11ansi.c"
    break;

  case 23: /* postfix_expression: postfix_expression Y_ARROW "identifier"  */
#line 265 "c11ansi.y"
                                                                                                    { (yyval.expression) = createCTree2(createConstr1Label(LABCT_ARROW, (yyvsp[-1].token)), (yyvsp[-2].expression), createCTreeRoot(createTokenLabel((yyvsp[0].token)))); }
#line 2250 "c11ansi.c"
    break;

  case 24: /* postfix_expression: postfix_expression Y_PLUS_PLUS  */
#line 266 "c11ansi.y"
                                                                                                    { (yyval.expression) = createCTree1(createConstr1Label(LABCT_PLUS_PLUS, (yyvsp[0].token)), (yyvsp[-1].expression)); }
#line 2256 "c11ansi.c"
    break;

  case 25: /* postfix_expression: postfix_expression Y_MINUS_MINUS  */
#line 267 "c11ansi.y"
                                                                                                    { (yyval.expression) = createCTree1(createConstr1Label(LABCT_MINUS_MINUS, (yyvsp[0].token)), (yyvsp[-1].expression)); }
#line 2262 "c11ansi.c"
    break;

  case 26: /* postfix_expression: Y_LEFT_PAREN type_name Y_RIGHT_PAREN Y_LEFT_BRACE initializer_list Y_RIGHT_BRACE  */
#line 268 "c11ansi.y"
                                                                                                    { (yyval.expression) = createCTreeRoot(createConstr7Label(LABCT_INIT, (yyvsp[-5].token),(yyvsp[-3].token),(yyvsp[-2].token),(yyvsp[0].token),(yyvsp[-4].typeName), (yyvsp[-1].list))); }
#line 2268 "c11ansi.c"
    break;

  case 27: /* postfix_expression: Y_LEFT_PAREN type_name Y_RIGHT_PAREN Y_LEFT_BRACE initializer_list Y_COMMA Y_RIGHT_BRACE  */
#line 269 "c11ansi.y"
                                                                                                    { (yyval.expression) = createCTreeRoot(createConstr7Label(LABCT_INIT, (yyvsp[-6].token),(yyvsp[-4].token),(yyvsp[-3].token),(yyvsp[-1].token),(yyvsp[-5].typeName), (yyvsp[-2].list))); }
#line 2274 "c11ansi.c"
    break;

  case 28: /* argument_expression_list: assignment_expression  */
#line 273 "c11ansi.y"
                                                                 { (yyval.expression) = (yyvsp[0].expression); }
#line 2280 "c11ansi.c"
    break;

  case 29: /* argument_expression_list: argument_expression_list Y_COMMA assignment_expression  */
#line 274 "c11ansi.y"
                                                                 { (yyval.expression) = createCTree2(createConstr1Label(LABCT_EXPR_SEPARATOR, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2286 "c11ansi.c"
    break;

  case 30: /* unary_expression: postfix_expression  */
#line 278 "c11ansi.y"
                                                          { (yyval.expression) = (yyvsp[0].expression); }
#line 2292 "c11ansi.c"
    break;

  case 31: /* unary_expression: Y_PLUS_PLUS unary_expression  */
#line 279 "c11ansi.y"
                                                          { (yyval.expression) = createCTree1(createConstr1Label(LABCT_PLUS_PLUS, (yyvsp[-1].token)), (yyvsp[0].expression)); }
#line 2298 "c11ansi.c"
    break;

  case 32: /* unary_expression: Y_MINUS_MINUS unary_expression  */
#line 280 "c11ansi.y"
                                                          { (yyval.expression) = createCTree1(createConstr1Label(LABCT_MINUS_MINUS, (yyvsp[-1].token)), (yyvsp[0].expression)); }
#line 2304 "c11ansi.c"
    break;

  case 33: /* unary_expression: unary_operator cast_expression  */
#line 281 "c11ansi.y"
                                                          { (yyval.expression) = createCTree1((yyvsp[-1].label), (yyvsp[0].expression)); }
#line 2310 "c11ansi.c"
    break;

  case 34: /* unary_expression: Y_SIZEOF unary_expression  */
#line 282 "c11ansi.y"
                                                          { (yyval.expression) = createCTree1(createConstr1Label(LABCT_SIZEOF_EXPR, (yyvsp[-1].token)), (yyvsp[0].expression)); }
#line 2316 "c11ansi.c"
    break;

  case 35: /* unary_expression: Y_SIZEOF Y_LEFT_PAREN type_name Y_RIGHT_PAREN  */
#line 283 "c11ansi.y"
                                                          { (yyval.expression) = createCTreeRoot(createConstr3Label(LABCT_SIZEOF_TYPE, (yyvsp[-3].token), (yyvsp[-2].token), (yyvsp[0].token))); }
#line 2322 "c11ansi.c"
    break;

  case 36: /* unary_expression: Y_ALIGNOF Y_LEFT_PAREN type_name Y_RIGHT_PAREN  */
#line 284 "c11ansi.y"
                                                          { (yyval.expression) = createCTreeRoot(createConstr3Label(LABCT_ALIGNOF_TYPE, (yyvsp[-3].token), (yyvsp[-2].token), (yyvsp[0].token))); }
#line 2328 "c11ansi.c"
    break;

  case 37: /* unary_operator: Y_AND  */
#line 288 "c11ansi.y"
                        { (yyval.label) = createConstr1Label(LABCT_ADDR_OF_VALUE, (yyvsp[0].token)); }
#line 2334 "c11ansi.c"
    break;

  case 38: /* unary_operator: Y_TIMES  */
#line 289 "c11ansi.y"
                        { (yyval.label) = createConstr1Label(LABCT_VALUE_AT_ADDR, (yyvsp[0].token)); }
#line 2340 "c11ansi.c"
    break;

  case 39: /* unary_operator: Y_PLUS  */
#line 290 "c11ansi.y"
                        { (yyval.label) = createConstr1Label(LABCT_UNARY_PLUS, (yyvsp[0].token)); }
#line 2346 "c11ansi.c"
    break;

  case 40: /* unary_operator: Y_MINUS  */
#line 291 "c11ansi.y"
                        { (yyval.label) = createConstr1Label(LABCT_UNARY_MINUS, (yyvsp[0].token)); }
#line 2352 "c11ansi.c"
    break;

  case 41: /* unary_operator: Y_TILDE  */
#line 292 "c11ansi.y"
                        { (yyval.label) = createConstr1Label(LABCT_TILDE, (yyvsp[0].token)); }
#line 2358 "c11ansi.c"
    break;

  case 42: /* unary_operator: Y_EXCLAMATION  */
#line 293 "c11ansi.y"
                        { (yyval.label) = createConstr1Label(LABCT_EXCLAMATION, (yyvsp[0].token)); }
#line 2364 "c11ansi.c"
    break;

  case 43: /* cast_expression: unary_expression  */
#line 297 "c11ansi.y"
                                                               { (yyval.expression) = (yyvsp[0].expression); }
#line 2370 "c11ansi.c"
    break;

  case 44: /* cast_expression: Y_LEFT_PAREN type_name Y_RIGHT_PAREN cast_expression  */
#line 298 "c11ansi.y"
                                                               { (yyval.expression) = NULL; }
#line 2376 "c11ansi.c"
    break;

  case 45: /* multiplicative_expression: cast_expression  */
#line 302 "c11ansi.y"
                                                              { (yyval.expression) = (yyvsp[0].expression); }
#line 2382 "c11ansi.c"
    break;

  case 46: /* multiplicative_expression: multiplicative_expression Y_TIMES cast_expression  */
#line 303 "c11ansi.y"
                                                              { (yyval.expression) = createCTree2(createConstr1Label(LABCT_TIMES, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2388 "c11ansi.c"
    break;

  case 47: /* multiplicative_expression: multiplicative_expression Y_DIVIDE cast_expression  */
#line 304 "c11ansi.y"
                                                              { (yyval.expression) = createCTree2(createConstr1Label(LABCT_DIVIDE, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2394 "c11ansi.c"
    break;

  case 48: /* multiplicative_expression: multiplicative_expression Y_PERCENT cast_expression  */
#line 305 "c11ansi.y"
                                                              { (yyval.expression) = createCTree2(createConstr1Label(LABCT_PERCENT, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2400 "c11ansi.c"
    break;

  case 49: /* additive_expression: multiplicative_expression  */
#line 309 "c11ansi.y"
                                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2406 "c11ansi.c"
    break;

  case 50: /* additive_expression: additive_expression Y_PLUS multiplicative_expression  */
#line 310 "c11ansi.y"
                                                                { (yyval.expression) = createCTree2(createConstr1Label(LABCT_PLUS, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2412 "c11ansi.c"
    break;

  case 51: /* additive_expression: additive_expression Y_MINUS multiplicative_expression  */
#line 311 "c11ansi.y"
                                                                { (yyval.expression) = createCTree2(createConstr1Label(LABCT_MINUS, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2418 "c11ansi.c"
    break;

  case 52: /* shift_expression: additive_expression  */
#line 315 "c11ansi.y"
                                                         { (yyval.expression) = (yyvsp[0].expression); }
#line 2424 "c11ansi.c"
    break;

  case 53: /* shift_expression: shift_expression Y_RSHIFT additive_expression  */
#line 316 "c11ansi.y"
                                                         { (yyval.expression) = createCTree2(createConstr1Label(LABCT_TIMES, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2430 "c11ansi.c"
    break;

  case 54: /* shift_expression: shift_expression Y_LSHIFT additive_expression  */
#line 317 "c11ansi.y"
                                                         { (yyval.expression) = createCTree2(createConstr1Label(LABCT_TIMES, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2436 "c11ansi.c"
    break;

  case 55: /* relational_expression: shift_expression  */
#line 321 "c11ansi.y"
                                                      { (yyval.expression) = (yyvsp[0].expression); }
#line 2442 "c11ansi.c"
    break;

  case 56: /* relational_expression: relational_expression Y_LT shift_expression  */
#line 322 "c11ansi.y"
                                                      { (yyval.expression) = createCTree2(createConstr1Label(LABCT_LT, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2448 "c11ansi.c"
    break;

  case 57: /* relational_expression: relational_expression Y_GT shift_expression  */
#line 323 "c11ansi.y"
                                                      { (yyval.expression) = createCTree2(createConstr1Label(LABCT_GT, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2454 "c11ansi.c"
    break;

  case 58: /* relational_expression: relational_expression Y_LE shift_expression  */
#line 324 "c11ansi.y"
                                                      { (yyval.expression) = createCTree2(createConstr1Label(LABCT_LE, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2460 "c11ansi.c"
    break;

  case 59: /* relational_expression: relational_expression Y_GE shift_expression  */
#line 325 "c11ansi.y"
                                                      { (yyval.expression) = createCTree2(createConstr1Label(LABCT_GE, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2466 "c11ansi.c"
    break;

  case 60: /* equality_expression: relational_expression  */
#line 329 "c11ansi.y"
                                                         { (yyval.expression) = (yyvsp[0].expression); }
#line 2472 "c11ansi.c"
    break;

  case 61: /* equality_expression: equality_expression Y_EQ relational_expression  */
#line 330 "c11ansi.y"
                                                         { (yyval.expression) = createCTree2(createConstr1Label(LABCT_EQ, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2478 "c11ansi.c"
    break;

  case 62: /* equality_expression: equality_expression Y_NE relational_expression  */
#line 331 "c11ansi.y"
                                                         { (yyval.expression) = createCTree2(createConstr1Label(LABCT_NE, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2484 "c11ansi.c"
    break;

  case 63: /* and_expression: equality_expression  */
#line 335 "c11ansi.y"
                                                   { (yyval.expression) = (yyvsp[0].expression); }
#line 2490 "c11ansi.c"
    break;

  case 64: /* and_expression: and_expression Y_AND equality_expression  */
#line 336 "c11ansi.y"
                                                   { (yyval.expression) = createCTree2(createConstr1Label(LABCT_AND, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2496 "c11ansi.c"
    break;

  case 65: /* exclusive_or_expression: and_expression  */
#line 340 "c11ansi.y"
                                                       { (yyval.expression) = (yyvsp[0].expression); }
#line 2502 "c11ansi.c"
    break;

  case 66: /* exclusive_or_expression: exclusive_or_expression Y_XOR and_expression  */
#line 341 "c11ansi.y"
                                                       { (yyval.expression) = createCTree2(createConstr1Label(LABCT_XOR, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2508 "c11ansi.c"
    break;

  case 67: /* inclusive_or_expression: exclusive_or_expression  */
#line 345 "c11ansi.y"
                                                               { (yyval.expression) = (yyvsp[0].expression); }
#line 2514 "c11ansi.c"
    break;

  case 68: /* inclusive_or_expression: inclusive_or_expression Y_OR exclusive_or_expression  */
#line 346 "c11ansi.y"
                                                               { (yyval.expression) = createCTree2(createConstr1Label(LABCT_OR, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2520 "c11ansi.c"
    break;

  case 69: /* logical_and_expression: inclusive_or_expression  */
#line 350 "c11ansi.y"
                                                                    { (yyval.expression) = (yyvsp[0].expression); }
#line 2526 "c11ansi.c"
    break;

  case 70: /* logical_and_expression: logical_and_expression Y_AND_AND inclusive_or_expression  */
#line 351 "c11ansi.y"
                                                                    { (yyval.expression) = createCTree2(createConstr1Label(LABCT_AND_AND, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2532 "c11ansi.c"
    break;

  case 71: /* logical_or_expression: logical_and_expression  */
#line 355 "c11ansi.y"
                                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2538 "c11ansi.c"
    break;

  case 72: /* logical_or_expression: logical_or_expression Y_OR_OR logical_and_expression  */
#line 356 "c11ansi.y"
                                                                { (yyval.expression) = createCTree2(createConstr1Label(LABCT_OR_OR, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2544 "c11ansi.c"
    break;

  case 73: /* conditional_expression: logical_or_expression  */
#line 360 "c11ansi.y"
                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2550 "c11ansi.c"
    break;

  case 74: /* conditional_expression: logical_or_expression Y_QUESTION expression Y_COLON conditional_expression  */
#line 361 "c11ansi.y"
                                                                                     { (yyval.expression) = createCTree2(createConstr1Label(LABCT_QUESTION, (yyvsp[-3].token)), (yyvsp[-4].expression), createCTree2(createConstr1Label(LABCT_COLON, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression))); }
#line 2556 "c11ansi.c"
    break;

  case 75: /* assignment_expression: conditional_expression  */
#line 365 "c11ansi.y"
                                                                      { (yyval.expression) = (yyvsp[0].expression); }
#line 2562 "c11ansi.c"
    break;

  case 76: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 366 "c11ansi.y"
                                                                      { (yyval.expression) = createCTree2((yyvsp[-1].label), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2568 "c11ansi.c"
    break;

  case 77: /* assignment_operator: Y_EQUAL  */
#line 370 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_EQ, (yyvsp[0].token)); }
#line 2574 "c11ansi.c"
    break;

  case 78: /* assignment_operator: Y_TIMES_EQUAL  */
#line 371 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_TIMES_EQUAL, (yyvsp[0].token)); }
#line 2580 "c11ansi.c"
    break;

  case 79: /* assignment_operator: Y_DIVIDE_EQUAL  */
#line 372 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_DIVIDE_EQUAL, (yyvsp[0].token)); }
#line 2586 "c11ansi.c"
    break;

  case 80: /* assignment_operator: Y_PERCENT_EQUAL  */
#line 373 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_PERCENT_EQUAL, (yyvsp[0].token)); }
#line 2592 "c11ansi.c"
    break;

  case 81: /* assignment_operator: Y_PLUS_EQUAL  */
#line 374 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_PLUS_EQUAL, (yyvsp[0].token)); }
#line 2598 "c11ansi.c"
    break;

  case 82: /* assignment_operator: Y_MINUS_EQUAL  */
#line 375 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_MINUS_EQUAL, (yyvsp[0].token)); }
#line 2604 "c11ansi.c"
    break;

  case 83: /* assignment_operator: Y_LSHIFT_EQUAL  */
#line 376 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_LSHIFT_EQUAL, (yyvsp[0].token)); }
#line 2610 "c11ansi.c"
    break;

  case 84: /* assignment_operator: Y_RSHIFT_EQUAL  */
#line 377 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_RSHIFT_EQUAL, (yyvsp[0].token)); }
#line 2616 "c11ansi.c"
    break;

  case 85: /* assignment_operator: Y_AND_EQUAL  */
#line 378 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_AND_EQUAL, (yyvsp[0].token)); }
#line 2622 "c11ansi.c"
    break;

  case 86: /* assignment_operator: Y_XOR_EQUAL  */
#line 379 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_XOR_EQUAL, (yyvsp[0].token)); }
#line 2628 "c11ansi.c"
    break;

  case 87: /* assignment_operator: Y_OR_EQUAL  */
#line 380 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_OR_EQUAL, (yyvsp[0].token)); }
#line 2634 "c11ansi.c"
    break;

  case 88: /* expression: assignment_expression  */
#line 384 "c11ansi.y"
                                                   { (yyval.expression) = (yyvsp[0].expression); }
#line 2640 "c11ansi.c"
    break;

  case 89: /* expression: expression Y_COMMA assignment_expression  */
#line 385 "c11ansi.y"
                                                   { (yyval.expression) = createCTree2(createConstr1Label(LABCT_EXPR_SEPARATOR, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2646 "c11ansi.c"
    break;

  case 90: /* constant_expression: conditional_expression  */
#line 389 "c11ansi.y"
                                  { (yyval.expression) = (yyvsp[0].expression); }
#line 2652 "c11ansi.c"
    break;

  case 91: /* declaration: declaration_specifiers Y_SEMICOLON  */
#line 393 "c11ansi.y"
                                                                  { (yyval.declaration) = createDeclaration((yyvsp[-1].declSpecifiers),NULL,NULL); }
#line 2658 "c11ansi.c"
    break;

  case 92: /* declaration: declaration_specifiers init_declarator_list Y_SEMICOLON  */
#line 394 "c11ansi.y"
                                                                  { (yyval.declaration) = createDeclaration((yyvsp[-2].declSpecifiers),(yyvsp[-1].initDeclaratorList),NULL); }
#line 2664 "c11ansi.c"
    break;

  case 93: /* declaration: static_assert_declaration  */
#line 395 "c11ansi.y"
                                                                  { (yyval.declaration) = createDeclaration(NULL,NULL,(yyvsp[0].staticAssertDecl)); }
#line 2670 "c11ansi.c"
    break;

  case 94: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 399 "c11ansi.y"
                                                         { (yyval.declSpecifiers) = createDeclarationSpecifiers1((yyvsp[-1].token),(yyvsp[0].declSpecifiers)); }
#line 2676 "c11ansi.c"
    break;

  case 95: /* declaration_specifiers: storage_class_specifier  */
#line 400 "c11ansi.y"
                                                         { (yyval.declSpecifiers) = createDeclarationSpecifiers1((yyvsp[0].token),NULL); }
#line 2682 "c11ansi.c"
    break;

  case 96: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 401 "c11ansi.y"
                                                         { (yyval.declSpecifiers) = createDeclarationSpecifiers2((yyvsp[-1].typeSpecifier),(yyvsp[0].declSpecifiers)); }
#line 2688 "c11ansi.c"
    break;

  case 97: /* declaration_specifiers: type_specifier  */
#line 402 "c11ansi.y"
                                                         { (yyval.declSpecifiers) = createDeclarationSpecifiers2((yyvsp[0].typeSpecifier),NULL); }
#line 2694 "c11ansi.c"
    break;

  case 98: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 403 "c11ansi.y"
                                                         { (yyval.declSpecifiers) = createDeclarationSpecifiers1((yyvsp[-1].token),(yyvsp[0].declSpecifiers)); }
#line 2700 "c11ansi.c"
    break;

  case 99: /* declaration_specifiers: type_qualifier  */
#line 404 "c11ansi.y"
                                                         { (yyval.declSpecifiers) = createDeclarationSpecifiers1((yyvsp[0].token),NULL); }
#line 2706 "c11ansi.c"
    break;

  case 100: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 405 "c11ansi.y"
                                                         { (yyval.declSpecifiers) = createDeclarationSpecifiers1((yyvsp[-1].token),(yyvsp[0].declSpecifiers)); }
#line 2712 "c11ansi.c"
    break;

  case 101: /* declaration_specifiers: function_specifier  */
#line 406 "c11ansi.y"
                                                         { (yyval.declSpecifiers) = createDeclarationSpecifiers1((yyvsp[0].token),NULL); }
#line 2718 "c11ansi.c"
    break;

  case 102: /* declaration_specifiers: alignment_specifier declaration_specifiers  */
#line 407 "c11ansi.y"
                                                         { (yyval.declSpecifiers) = createDeclarationSpecifiers3((yyvsp[-1].alignmentSpecifier),(yyvsp[0].declSpecifiers)); }
#line 2724 "c11ansi.c"
    break;

  case 103: /* declaration_specifiers: alignment_specifier  */
#line 408 "c11ansi.y"
                                                         { (yyval.declSpecifiers) = createDeclarationSpecifiers3((yyvsp[0].alignmentSpecifier),NULL); }
#line 2730 "c11ansi.c"
    break;

  case 104: /* init_declarator_list: init_declarator  */
#line 412 "c11ansi.y"
                                                        { (yyval.initDeclaratorList) = createInitDeclaratorList((yyvsp[0].initDeclarator),NULL); }
#line 2736 "c11ansi.c"
    break;

  case 105: /* init_declarator_list: init_declarator_list Y_COMMA init_declarator  */
#line 413 "c11ansi.y"
                                                        { (yyval.initDeclaratorList) = createInitDeclaratorList((yyvsp[0].initDeclarator),(yyvsp[-2].initDeclaratorList));  zapToken((yyvsp[-1].token)); }
#line 2742 "c11ansi.c"
    break;

  case 106: /* init_declarator: declarator Y_EQUAL initializer  */
#line 417 "c11ansi.y"
                                         { (yyval.initDeclarator) = createInitDeclarator((yyvsp[-2].declarator),(yyvsp[0].expression)); }
#line 2748 "c11ansi.c"
    break;

  case 107: /* init_declarator: declarator  */
#line 418 "c11ansi.y"
                                                     { (yyval.initDeclarator) = createInitDeclarator((yyvsp[0].declarator),NULL); }
#line 2754 "c11ansi.c"
    break;

  case 108: /* storage_class_specifier: Y_TYPEDEF  */
#line 422 "c11ansi.y"
                              { (yyval.token) = (yyvsp[0].token); }
#line 2760 "c11ansi.c"
    break;

  case 109: /* storage_class_specifier: Y_EXTERN  */
#line 423 "c11ansi.y"
                          { (yyval.token) = (yyvsp[0].token); }
#line 2766 "c11ansi.c"
    break;

  case 110: /* storage_class_specifier: Y_STATIC  */
#line 424 "c11ansi.y"
                          { (yyval.token) = (yyvsp[0].token); }
#line 2772 "c11ansi.c"
    break;

  case 111: /* storage_class_specifier: Y_THREAD_LOCAL  */
#line 425 "c11ansi.y"
                          { (yyval.token) = (yyvsp[0].token); }
#line 2778 "c11ansi.c"
    break;

  case 112: /* storage_class_specifier: Y_AUTO  */
#line 426 "c11ansi.y"
                          { (yyval.token) = (yyvsp[0].token); }
#line 2784 "c11ansi.c"
    break;

  case 113: /* storage_class_specifier: Y_REGISTER  */
#line 427 "c11ansi.y"
                          { (yyval.token) = (yyvsp[0].token); }
#line 2790 "c11ansi.c"
    break;

  case 114: /* type_specifier: Y_VOID  */
#line 431 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2796 "c11ansi.c"
    break;

  case 115: /* type_specifier: Y_CHAR  */
#line 432 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2802 "c11ansi.c"
    break;

  case 116: /* type_specifier: Y_SHORT  */
#line 433 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2808 "c11ansi.c"
    break;

  case 117: /* type_specifier: Y_INT  */
#line 434 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2814 "c11ansi.c"
    break;

  case 118: /* type_specifier: Y_LONG  */
#line 435 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2820 "c11ansi.c"
    break;

  case 119: /* type_specifier: Y_LONG_LONG  */
#line 436 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2826 "c11ansi.c"
    break;

  case 120: /* type_specifier: Y_FLOAT  */
#line 437 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2832 "c11ansi.c"
    break;

  case 121: /* type_specifier: Y_DOUBLE  */
#line 438 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2838 "c11ansi.c"
    break;

  case 122: /* type_specifier: Y_LONG_DOUBLE  */
#line 439 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2844 "c11ansi.c"
    break;

  case 123: /* type_specifier: Y_SIGNED  */
#line 440 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2850 "c11ansi.c"
    break;

  case 124: /* type_specifier: Y_UNSIGNED  */
#line 441 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2856 "c11ansi.c"
    break;

  case 125: /* type_specifier: Y_BOOL  */
#line 442 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2862 "c11ansi.c"
    break;

  case 126: /* type_specifier: Y_COMPLEX  */
#line 443 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2868 "c11ansi.c"
    break;

  case 127: /* type_specifier: Y_IMAGINARY  */
#line 444 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2874 "c11ansi.c"
    break;

  case 128: /* type_specifier: atomic_type_specifier  */
#line 445 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier2((yyvsp[0].atomicTypeSpecifier)); }
#line 2880 "c11ansi.c"
    break;

  case 129: /* type_specifier: struct_or_union_specifier  */
#line 446 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier3((yyvsp[0].structOrUnionSpecifier)); }
#line 2886 "c11ansi.c"
    break;

  case 130: /* type_specifier: enum_specifier  */
#line 447 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier4((yyvsp[0].enumSpecifier)); }
#line 2892 "c11ansi.c"
    break;

  case 131: /* type_specifier: Y_TYPEDEF_NAME  */
#line 448 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2898 "c11ansi.c"
    break;

  case 132: /* struct_or_union_specifier: struct_or_union Y_LEFT_BRACE struct_declaration_list Y_RIGHT_BRACE  */
#line 452 "c11ansi.y"
                                                                                        { (yyval.structOrUnionSpecifier) = createStructOrUnionSpecifier((yyvsp[-3].token),NULL,(yyvsp[-1].list)); }
#line 2904 "c11ansi.c"
    break;

  case 133: /* struct_or_union_specifier: struct_or_union "identifier" Y_LEFT_BRACE struct_declaration_list Y_RIGHT_BRACE  */
#line 453 "c11ansi.y"
                                                                                        { (yyval.structOrUnionSpecifier) = createStructOrUnionSpecifier((yyvsp[-4].token),(yyvsp[-3].token),(yyvsp[-1].list)); }
#line 2910 "c11ansi.c"
    break;

  case 134: /* struct_or_union_specifier: struct_or_union "identifier"  */
#line 454 "c11ansi.y"
                                                                                        { (yyval.structOrUnionSpecifier) = createStructOrUnionSpecifier((yyvsp[-1].token),(yyvsp[0].token),NULL); }
#line 2916 "c11ansi.c"
    break;

  case 135: /* struct_or_union: Y_STRUCT  */
#line 458 "c11ansi.y"
                    { (yyval.token) = (yyvsp[0].token); }
#line 2922 "c11ansi.c"
    break;

  case 136: /* struct_or_union: Y_UNION  */
#line 459 "c11ansi.y"
                    { (yyval.token) = (yyvsp[0].token); }
#line 2928 "c11ansi.c"
    break;

  case 137: /* struct_declaration_list: struct_declaration  */
#line 463 "c11ansi.y"
                                                     { (yyval.list) = createStructDeclarationList((yyvsp[0].structDeclaration),NULL); }
#line 2934 "c11ansi.c"
    break;

  case 138: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 464 "c11ansi.y"
                                                     { (yyval.list) = createStructDeclarationList((yyvsp[0].structDeclaration),(yyvsp[-1].list)); }
#line 2940 "c11ansi.c"
    break;

  case 139: /* struct_declaration: specifier_qualifier_list Y_SEMICOLON  */
#line 468 "c11ansi.y"
                                                                       { (yyval.structDeclaration) = createStructDeclaration((yyvsp[-1].list),NULL,NULL); }
#line 2946 "c11ansi.c"
    break;

  case 140: /* struct_declaration: specifier_qualifier_list struct_declarator_list Y_SEMICOLON  */
#line 469 "c11ansi.y"
                                                                       { (yyval.structDeclaration) = createStructDeclaration((yyvsp[-2].list),(yyvsp[-1].list),NULL); }
#line 2952 "c11ansi.c"
    break;

  case 141: /* struct_declaration: static_assert_declaration  */
#line 470 "c11ansi.y"
                                                                       { (yyval.structDeclaration) = createStructDeclaration(NULL,NULL,(yyvsp[0].staticAssertDecl)); }
#line 2958 "c11ansi.c"
    break;

  case 142: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 474 "c11ansi.y"
                                                   { (yyval.list) = createSecifierQualifierList((yyvsp[-1].typeSpecifier),NULL,(yyvsp[0].list)); }
#line 2964 "c11ansi.c"
    break;

  case 143: /* specifier_qualifier_list: type_specifier  */
#line 475 "c11ansi.y"
                                                   { (yyval.list) = createSecifierQualifierList((yyvsp[0].typeSpecifier),NULL,NULL); }
#line 2970 "c11ansi.c"
    break;

  case 144: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 476 "c11ansi.y"
                                                   { (yyval.list) = createSecifierQualifierList(NULL,(yyvsp[-1].token),(yyvsp[0].list)); }
#line 2976 "c11ansi.c"
    break;

  case 145: /* specifier_qualifier_list: type_qualifier  */
#line 477 "c11ansi.y"
                                                   { (yyval.list) = createSecifierQualifierList(NULL,(yyvsp[0].token),NULL); }
#line 2982 "c11ansi.c"
    break;

  case 146: /* struct_declarator_list: struct_declarator  */
#line 481 "c11ansi.y"
                                                           { (yyval.list) = createStructDeclaratorList((yyvsp[0].structDeclarator),NULL); }
#line 2988 "c11ansi.c"
    break;

  case 147: /* struct_declarator_list: struct_declarator_list Y_COMMA struct_declarator  */
#line 482 "c11ansi.y"
                                                           { (yyval.list) = createStructDeclaratorList((yyvsp[0].structDeclarator),(yyvsp[-2].list)); }
#line 2994 "c11ansi.c"
    break;

  case 148: /* struct_declarator: Y_COLON constant_expression  */
#line 486 "c11ansi.y"
                                                 { (yyval.structDeclarator) = createStructDeclarator(NULL,(yyvsp[0].expression)); }
#line 3000 "c11ansi.c"
    break;

  case 149: /* struct_declarator: declarator Y_COLON constant_expression  */
#line 487 "c11ansi.y"
                                                 { (yyval.structDeclarator) = createStructDeclarator((yyvsp[-2].declarator),(yyvsp[0].expression)); }
#line 3006 "c11ansi.c"
    break;

  case 150: /* struct_declarator: declarator  */
#line 488 "c11ansi.y"
                                                 { (yyval.structDeclarator) = createStructDeclarator((yyvsp[0].declarator),NULL); }
#line 3012 "c11ansi.c"
    break;

  case 151: /* enum_specifier: Y_ENUM Y_LEFT_BRACE enumerator_list Y_RIGHT_BRACE  */
#line 492 "c11ansi.y"
                                                                                { (yyval.enumSpecifier) = createEnumSpecifier(NULL,(yyvsp[-1].list)); }
#line 3018 "c11ansi.c"
    break;

  case 152: /* enum_specifier: Y_ENUM Y_LEFT_BRACE enumerator_list Y_COMMA Y_RIGHT_BRACE  */
#line 493 "c11ansi.y"
                                                                                { (yyval.enumSpecifier) = createEnumSpecifier(NULL,(yyvsp[-2].list)); }
#line 3024 "c11ansi.c"
    break;

  case 153: /* enum_specifier: Y_ENUM "identifier" Y_LEFT_BRACE enumerator_list Y_RIGHT_BRACE  */
#line 494 "c11ansi.y"
                                                                                { (yyval.enumSpecifier) = createEnumSpecifier((yyvsp[-3].token),(yyvsp[-1].list)); }
#line 3030 "c11ansi.c"
    break;

  case 154: /* enum_specifier: Y_ENUM "identifier" Y_LEFT_BRACE enumerator_list Y_COMMA Y_RIGHT_BRACE  */
#line 495 "c11ansi.y"
                                                                                { (yyval.enumSpecifier) = createEnumSpecifier((yyvsp[-4].token),(yyvsp[-2].list)); }
#line 3036 "c11ansi.c"
    break;

  case 155: /* enum_specifier: Y_ENUM "identifier"  */
#line 496 "c11ansi.y"
                                                                                { (yyval.enumSpecifier) = createEnumSpecifier((yyvsp[0].token),NULL); }
#line 3042 "c11ansi.c"
    break;

  case 156: /* enumerator_list: enumerator  */
#line 500 "c11ansi.y"
                                              { (yyval.list) = createEnumeratorList((yyvsp[0].enumerator), NULL); }
#line 3048 "c11ansi.c"
    break;

  case 157: /* enumerator_list: enumerator_list Y_COMMA enumerator  */
#line 501 "c11ansi.y"
                                              { (yyval.list) = createEnumeratorList((yyvsp[0].enumerator), (yyvsp[-2].list)); }
#line 3054 "c11ansi.c"
    break;

  case 158: /* enumerator: enumeration_constant Y_EQUAL constant_expression  */
#line 505 "c11ansi.y"
                                                           { (yyval.enumerator) = createEnumerator((yyvsp[-2].token), (yyvsp[0].expression)); }
#line 3060 "c11ansi.c"
    break;

  case 159: /* enumerator: enumeration_constant  */
#line 506 "c11ansi.y"
                                                           { (yyval.enumerator) = createEnumerator((yyvsp[0].token), NULL); }
#line 3066 "c11ansi.c"
    break;

  case 160: /* atomic_type_specifier: Y_ATOMIC Y_LEFT_PAREN type_name Y_RIGHT_PAREN  */
#line 510 "c11ansi.y"
                                                        { (yyval.atomicTypeSpecifier) = createAtomicTypeSpecifier((yyvsp[-3].token),(yyvsp[-1].typeName)); }
#line 3072 "c11ansi.c"
    break;

  case 161: /* type_qualifier: Y_CONST  */
#line 514 "c11ansi.y"
                       { (yyval.token) = (yyvsp[0].token); }
#line 3078 "c11ansi.c"
    break;

  case 162: /* type_qualifier: Y_RESTRICT  */
#line 515 "c11ansi.y"
                       { (yyval.token) = (yyvsp[0].token); }
#line 3084 "c11ansi.c"
    break;

  case 163: /* type_qualifier: Y_VOLATILE  */
#line 516 "c11ansi.y"
                       { (yyval.token) = (yyvsp[0].token); }
#line 3090 "c11ansi.c"
    break;

  case 164: /* type_qualifier: Y_ATOMIC  */
#line 517 "c11ansi.y"
                       { (yyval.token) = (yyvsp[0].token); }
#line 3096 "c11ansi.c"
    break;

  case 165: /* function_specifier: Y_INLINE  */
#line 521 "c11ansi.y"
                      { (yyval.token) = (yyvsp[0].token);  }
#line 3102 "c11ansi.c"
    break;

  case 166: /* function_specifier: Y_NORETURN  */
#line 522 "c11ansi.y"
                      { (yyval.token) = (yyvsp[0].token); }
#line 3108 "c11ansi.c"
    break;

  case 167: /* alignment_specifier: Y_ALIGNAS Y_LEFT_PAREN type_name Y_RIGHT_PAREN  */
#line 526 "c11ansi.y"
                                                                    { (yyval.alignmentSpecifier) = createAlignmentSpecifiers((yyvsp[-1].typeName),NULL); }
#line 3114 "c11ansi.c"
    break;

  case 168: /* alignment_specifier: Y_ALIGNAS Y_LEFT_PAREN constant_expression Y_RIGHT_PAREN  */
#line 527 "c11ansi.y"
                                                                    { (yyval.alignmentSpecifier) = createAlignmentSpecifiers(NULL,(yyvsp[-1].expression)); }
#line 3120 "c11ansi.c"
    break;

  case 169: /* declarator: pointer direct_declarator  */
#line 531 "c11ansi.y"
                                    { (yyval.declarator) = NULL; }
#line 3126 "c11ansi.c"
    break;

  case 170: /* declarator: direct_declarator  */
#line 532 "c11ansi.y"
                                    { (yyval.declarator) = NULL; }
#line 3132 "c11ansi.c"
    break;

  case 171: /* direct_declarator: "identifier"  */
#line 536 "c11ansi.y"
                                                                                                              { (yyval.directDeclarator) = createDirectDeclarator1((yyvsp[0].token)); }
#line 3138 "c11ansi.c"
    break;

  case 172: /* direct_declarator: Y_LEFT_PAREN declarator Y_RIGHT_PAREN  */
#line 537 "c11ansi.y"
                                                                                                              { (yyval.directDeclarator) = createDirectDeclarator2((yyvsp[-1].declarator)); }
#line 3144 "c11ansi.c"
    break;

  case 173: /* direct_declarator: direct_declarator Y_LEFT_BRACKET Y_RIGHT_BRACKET  */
#line 538 "c11ansi.y"
                                                                                                              { (yyval.directDeclarator) = createDirectDeclarator3((yyvsp[-2].directDeclarator),(yyvsp[-1].token),NULL,(yyvsp[0].token)); }
#line 3150 "c11ansi.c"
    break;

  case 174: /* direct_declarator: direct_declarator Y_LEFT_BRACKET Y_TIMES Y_RIGHT_BRACKET  */
#line 539 "c11ansi.y"
                                                                                                              { (yyval.directDeclarator) = createDirectDeclarator3((yyvsp[-3].directDeclarator),(yyvsp[-2].token),(yyvsp[-1].token),(yyvsp[0].token)); }
#line 3156 "c11ansi.c"
    break;

  case 175: /* direct_declarator: direct_declarator Y_LEFT_BRACKET Y_STATIC type_qualifier_list assignment_expression Y_RIGHT_BRACKET  */
#line 540 "c11ansi.y"
                                                                                                              { (yyval.directDeclarator) = createDirectDeclarator5((yyvsp[-5].directDeclarator),(yyvsp[-4].token),(yyvsp[-2].list),(yyvsp[-1].expression),(yyvsp[0].token),NULL,(yyvsp[-3].token)); }
#line 3162 "c11ansi.c"
    break;

  case 176: /* direct_declarator: direct_declarator Y_LEFT_BRACKET Y_STATIC assignment_expression Y_RIGHT_BRACKET  */
#line 541 "c11ansi.y"
                                                                                                              { (yyval.directDeclarator) = createDirectDeclarator5((yyvsp[-4].directDeclarator),(yyvsp[-3].token),NULL,(yyvsp[-1].expression),(yyvsp[0].token),NULL,(yyvsp[-2].token)); }
#line 3168 "c11ansi.c"
    break;

  case 177: /* direct_declarator: direct_declarator Y_LEFT_BRACKET type_qualifier_list Y_TIMES Y_RIGHT_BRACKET  */
#line 542 "c11ansi.y"
                                                                                                              { (yyval.directDeclarator) = createDirectDeclarator5((yyvsp[-4].directDeclarator),(yyvsp[-3].token),(yyvsp[-2].list),NULL,NULL,(yyvsp[-1].token),NULL); }
#line 3174 "c11ansi.c"
    break;

  case 178: /* direct_declarator: direct_declarator Y_LEFT_BRACKET type_qualifier_list Y_STATIC assignment_expression Y_RIGHT_BRACKET  */
#line 543 "c11ansi.y"
                                                                                                              { (yyval.directDeclarator) = createDirectDeclarator5((yyvsp[-5].directDeclarator),(yyvsp[-4].token),(yyvsp[-3].list),(yyvsp[-1].expression),(yyvsp[0].token),NULL,(yyvsp[-2].token)); }
#line 3180 "c11ansi.c"
    break;

  case 179: /* direct_declarator: direct_declarator Y_LEFT_BRACKET type_qualifier_list assignment_expression Y_RIGHT_BRACKET  */
#line 544 "c11ansi.y"
                                                                                                              { (yyval.directDeclarator) = createDirectDeclarator5((yyvsp[-4].directDeclarator),(yyvsp[-3].token),(yyvsp[-2].list),(yyvsp[-1].expression),(yyvsp[0].token),NULL,NULL); }
#line 3186 "c11ansi.c"
    break;

  case 180: /* direct_declarator: direct_declarator Y_LEFT_BRACKET type_qualifier_list Y_RIGHT_BRACKET  */
#line 545 "c11ansi.y"
                                                                                                              { (yyval.directDeclarator) = createDirectDeclarator5((yyvsp[-3].directDeclarator),(yyvsp[-2].token),(yyvsp[-1].list),NULL,(yyvsp[0].token),NULL,NULL); }
#line 3192 "c11ansi.c"
    break;

  case 181: /* direct_declarator: direct_declarator Y_LEFT_BRACKET assignment_expression Y_RIGHT_BRACKET  */
#line 546 "c11ansi.y"
                                                                                                              { (yyval.directDeclarator) = createDirectDeclarator5((yyvsp[-3].directDeclarator),(yyvsp[-2].token),NULL,(yyvsp[-1].expression),(yyvsp[0].token),NULL,NULL); }
#line 3198 "c11ansi.c"
    break;

  case 182: /* direct_declarator: direct_declarator Y_LEFT_PAREN parameter_type_list Y_RIGHT_PAREN  */
#line 547 "c11ansi.y"
                                                                                                              { (yyval.directDeclarator) = createDirectDeclarator4((yyvsp[-3].directDeclarator),(yyvsp[-2].token),(yyvsp[-1].parameterTypeList),(yyvsp[0].token)); }
#line 3204 "c11ansi.c"
    break;

  case 183: /* direct_declarator: direct_declarator Y_LEFT_PAREN Y_RIGHT_PAREN  */
#line 548 "c11ansi.y"
                                                                                                              { (yyval.directDeclarator) = createDirectDeclarator3((yyvsp[-2].directDeclarator),(yyvsp[-1].token),NULL,(yyvsp[0].token)); }
#line 3210 "c11ansi.c"
    break;

  case 184: /* direct_declarator: direct_declarator Y_LEFT_PAREN identifier_list Y_RIGHT_PAREN  */
#line 549 "c11ansi.y"
                                                                                                              { (yyval.directDeclarator) = createDirectDeclarator6((yyvsp[-3].directDeclarator),(yyvsp[-1].list)); }
#line 3216 "c11ansi.c"
    break;

  case 185: /* pointer: Y_TIMES type_qualifier_list pointer  */
#line 553 "c11ansi.y"
                                              { (yyval.pointer) = createPointer((yyvsp[0].pointer),(yyvsp[-1].list)); }
#line 3222 "c11ansi.c"
    break;

  case 186: /* pointer: Y_TIMES type_qualifier_list  */
#line 554 "c11ansi.y"
                                              { (yyval.pointer) = createPointer(NULL,(yyvsp[0].list)); }
#line 3228 "c11ansi.c"
    break;

  case 187: /* pointer: Y_TIMES pointer  */
#line 555 "c11ansi.y"
                                              { (yyval.pointer) = createPointer((yyvsp[0].pointer),NULL); }
#line 3234 "c11ansi.c"
    break;

  case 188: /* pointer: Y_TIMES  */
#line 556 "c11ansi.y"
                                              { (yyval.pointer) = createPointer(NULL,NULL); }
#line 3240 "c11ansi.c"
    break;

  case 189: /* type_qualifier_list: type_qualifier  */
#line 560 "c11ansi.y"
                                             { (yyval.list) = createTypeQualifierList((yyvsp[0].token),NULL); }
#line 3246 "c11ansi.c"
    break;

  case 190: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 561 "c11ansi.y"
                                             { (yyval.list) = createTypeQualifierList((yyvsp[0].token),(yyvsp[-1].list)); }
#line 3252 "c11ansi.c"
    break;

  case 191: /* parameter_type_list: parameter_list Y_COMMA Y_DOT_DOT_DOT  */
#line 566 "c11ansi.y"
                                               { (yyval.parameterTypeList) = createParameterTypeList((yyvsp[-2].list),true); }
#line 3258 "c11ansi.c"
    break;

  case 192: /* parameter_type_list: parameter_list  */
#line 567 "c11ansi.y"
                                               { (yyval.parameterTypeList) = createParameterTypeList((yyvsp[0].list),false); }
#line 3264 "c11ansi.c"
    break;

  case 193: /* parameter_list: parameter_declaration  */
#line 571 "c11ansi.y"
                                                       { (yyval.list) = createParameterList((yyvsp[0].parameterDeclaration),NULL); }
#line 3270 "c11ansi.c"
    break;

  case 194: /* parameter_list: parameter_list Y_COMMA parameter_declaration  */
#line 572 "c11ansi.y"
                                                       { (yyval.list) = createParameterList((yyvsp[0].parameterDeclaration),(yyvsp[-2].list)); }
#line 3276 "c11ansi.c"
    break;

  case 195: /* parameter_declaration: declaration_specifiers declarator  */
#line 576 "c11ansi.y"
                                                     { (yyval.parameterDeclaration) = createParameterDeclaration((yyvsp[-1].declSpecifiers),(yyvsp[0].declarator),NULL); }
#line 3282 "c11ansi.c"
    break;

  case 196: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 577 "c11ansi.y"
                                                     { (yyval.parameterDeclaration) = createParameterDeclaration((yyvsp[-1].declSpecifiers),NULL,(yyvsp[0].abstractDeclarator)); }
#line 3288 "c11ansi.c"
    break;

  case 197: /* parameter_declaration: declaration_specifiers  */
#line 578 "c11ansi.y"
                                                     { (yyval.parameterDeclaration) = createParameterDeclaration((yyvsp[0].declSpecifiers),NULL,NULL); }
#line 3294 "c11ansi.c"
    break;

  case 198: /* identifier_list: "identifier"  */
#line 582 "c11ansi.y"
                                             { (yyval.list) = createIdentifierList((yyvsp[0].token),NULL); }
#line 3300 "c11ansi.c"
    break;

  case 199: /* identifier_list: identifier_list Y_COMMA "identifier"  */
#line 583 "c11ansi.y"
                                             { (yyval.list) = createIdentifierList((yyvsp[0].token),(yyvsp[-2].list)); zapToken((yyvsp[-1].token)); }
#line 3306 "c11ansi.c"
    break;

  case 200: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 587 "c11ansi.y"
                                                       { (yyval.typeName) = createTypeName((yyvsp[-1].list),(yyvsp[0].abstractDeclarator)); }
#line 3312 "c11ansi.c"
    break;

  case 201: /* type_name: specifier_qualifier_list  */
#line 588 "c11ansi.y"
                                                       { (yyval.typeName) = createTypeName((yyvsp[0].list),NULL); }
#line 3318 "c11ansi.c"
    break;

  case 202: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 592 "c11ansi.y"
                                              { (yyval.abstractDeclarator) = creatorAbstractDeclarator((yyvsp[-1].pointer),(yyvsp[0].directAbstractDeclarator)); }
#line 3324 "c11ansi.c"
    break;

  case 203: /* abstract_declarator: pointer  */
#line 593 "c11ansi.y"
                                              { (yyval.abstractDeclarator) = creatorAbstractDeclarator((yyvsp[0].pointer),NULL); }
#line 3330 "c11ansi.c"
    break;

  case 204: /* abstract_declarator: direct_abstract_declarator  */
#line 594 "c11ansi.y"
                                              { (yyval.abstractDeclarator) = creatorAbstractDeclarator(NULL,(yyvsp[0].directAbstractDeclarator)); }
#line 3336 "c11ansi.c"
    break;

  case 205: /* direct_abstract_declarator: Y_LEFT_PAREN abstract_declarator Y_RIGHT_PAREN  */
#line 598 "c11ansi.y"
                                                                                                                       { (yyval.directAbstractDeclarator) = createDirectAbstractDeclarator(NULL,(yyvsp[-2].token),(yyvsp[-1].abstractDeclarator),(yyvsp[0].token),NULL,NULL,NULL,NULL,NULL); }
#line 3342 "c11ansi.c"
    break;

  case 206: /* direct_abstract_declarator: Y_LEFT_BRACKET Y_RIGHT_BRACKET  */
#line 599 "c11ansi.y"
                                                                                                                       { (yyval.directAbstractDeclarator) = createDirectAbstractDeclarator(NULL,(yyvsp[-1].token),NULL,(yyvsp[0].token),NULL,NULL,NULL,NULL,NULL); }
#line 3348 "c11ansi.c"
    break;

  case 207: /* direct_abstract_declarator: Y_LEFT_BRACKET Y_TIMES Y_RIGHT_BRACKET  */
#line 600 "c11ansi.y"
                                                                                                                       { (yyval.directAbstractDeclarator) = createDirectAbstractDeclarator(NULL,(yyvsp[-2].token),NULL,(yyvsp[0].token),(yyvsp[-1].token),NULL,NULL,NULL,NULL); }
#line 3354 "c11ansi.c"
    break;

  case 208: /* direct_abstract_declarator: Y_LEFT_BRACKET Y_STATIC type_qualifier_list assignment_expression Y_RIGHT_BRACKET  */
#line 601 "c11ansi.y"
                                                                                                                       { (yyval.directAbstractDeclarator) = createDirectAbstractDeclarator(NULL,(yyvsp[-4].token),NULL,(yyvsp[0].token),NULL,(yyvsp[-2].list),(yyvsp[-1].expression),(yyvsp[-3].token),NULL); }
#line 3360 "c11ansi.c"
    break;

  case 209: /* direct_abstract_declarator: Y_LEFT_BRACKET Y_STATIC assignment_expression Y_RIGHT_BRACKET  */
#line 602 "c11ansi.y"
                                                                                                                       { (yyval.directAbstractDeclarator) = createDirectAbstractDeclarator(NULL,(yyvsp[-3].token),NULL,(yyvsp[0].token),NULL,NULL,(yyvsp[-1].expression),(yyvsp[-2].token),NULL); }
#line 3366 "c11ansi.c"
    break;

  case 210: /* direct_abstract_declarator: Y_LEFT_BRACKET type_qualifier_list Y_STATIC assignment_expression Y_RIGHT_BRACKET  */
#line 603 "c11ansi.y"
                                                                                                                       { (yyval.directAbstractDeclarator) = createDirectAbstractDeclarator(NULL,(yyvsp[-4].token),NULL,(yyvsp[0].token),NULL,(yyvsp[-3].list),(yyvsp[-1].expression),(yyvsp[-2].token),NULL); }
#line 3372 "c11ansi.c"
    break;

  case 211: /* direct_abstract_declarator: Y_LEFT_BRACKET type_qualifier_list assignment_expression Y_RIGHT_BRACKET  */
#line 604 "c11ansi.y"
                                                                                                                       { (yyval.directAbstractDeclarator) = createDirectAbstractDeclarator(NULL,(yyvsp[-3].token),NULL,(yyvsp[0].token),NULL,(yyvsp[-2].list),(yyvsp[-1].expression),NULL,NULL); }
#line 3378 "c11ansi.c"
    break;

  case 212: /* direct_abstract_declarator: Y_LEFT_BRACKET type_qualifier_list Y_RIGHT_BRACKET  */
#line 605 "c11ansi.y"
                                                                                                                       { (yyval.directAbstractDeclarator) = createDirectAbstractDeclarator(NULL,(yyvsp[-2].token),NULL,(yyvsp[0].token),NULL,(yyvsp[-1].list),NULL,NULL,NULL); }
#line 3384 "c11ansi.c"
    break;

  case 213: /* direct_abstract_declarator: Y_LEFT_BRACKET assignment_expression Y_RIGHT_BRACKET  */
#line 606 "c11ansi.y"
                                                                                                                       { (yyval.directAbstractDeclarator) = createDirectAbstractDeclarator(NULL,(yyvsp[-2].token),NULL,(yyvsp[0].token),NULL,NULL,(yyvsp[-1].expression),NULL,NULL); }
#line 3390 "c11ansi.c"
    break;

  case 214: /* direct_abstract_declarator: direct_abstract_declarator Y_LEFT_BRACKET Y_RIGHT_BRACKET  */
#line 607 "c11ansi.y"
                                                                                                                       { (yyval.directAbstractDeclarator) = createDirectAbstractDeclarator((yyvsp[-2].directAbstractDeclarator),(yyvsp[-1].token),NULL,(yyvsp[0].token),NULL,NULL,NULL,NULL,NULL); }
#line 3396 "c11ansi.c"
    break;

  case 215: /* direct_abstract_declarator: direct_abstract_declarator Y_LEFT_BRACKET Y_TIMES Y_RIGHT_BRACKET  */
#line 608 "c11ansi.y"
                                                                                                                       { (yyval.directAbstractDeclarator) = createDirectAbstractDeclarator((yyvsp[-3].directAbstractDeclarator),(yyvsp[-2].token),NULL,(yyvsp[0].token),(yyvsp[-1].token),NULL,NULL,NULL,NULL); }
#line 3402 "c11ansi.c"
    break;

  case 216: /* direct_abstract_declarator: direct_abstract_declarator Y_LEFT_BRACKET Y_STATIC type_qualifier_list assignment_expression Y_RIGHT_BRACKET  */
#line 609 "c11ansi.y"
                                                                                                                       { (yyval.directAbstractDeclarator) = createDirectAbstractDeclarator((yyvsp[-5].directAbstractDeclarator),(yyvsp[-4].token),NULL,(yyvsp[0].token),NULL,(yyvsp[-2].list),(yyvsp[-1].expression),(yyvsp[-3].token),NULL); }
#line 3408 "c11ansi.c"
    break;

  case 217: /* direct_abstract_declarator: direct_abstract_declarator Y_LEFT_BRACKET Y_STATIC assignment_expression Y_RIGHT_BRACKET  */
#line 610 "c11ansi.y"
                                                                                                                       { (yyval.directAbstractDeclarator) = createDirectAbstractDeclarator((yyvsp[-4].directAbstractDeclarator),(yyvsp[-3].token),NULL,(yyvsp[0].token),NULL,NULL,(yyvsp[-1].expression),(yyvsp[-2].token),NULL); }
#line 3414 "c11ansi.c"
    break;

  case 218: /* direct_abstract_declarator: direct_abstract_declarator Y_LEFT_BRACKET type_qualifier_list assignment_expression Y_RIGHT_BRACKET  */
#line 611 "c11ansi.y"
                                                                                                                       { (yyval.directAbstractDeclarator) = createDirectAbstractDeclarator((yyvsp[-4].directAbstractDeclarator),(yyvsp[-3].token),NULL,(yyvsp[0].token),NULL,(yyvsp[-2].list),(yyvsp[-1].expression),NULL,NULL); }
#line 3420 "c11ansi.c"
    break;

  case 219: /* direct_abstract_declarator: direct_abstract_declarator Y_LEFT_BRACKET type_qualifier_list Y_STATIC assignment_expression Y_RIGHT_BRACKET  */
#line 612 "c11ansi.y"
                                                                                                                       { (yyval.directAbstractDeclarator) = createDirectAbstractDeclarator((yyvsp[-5].directAbstractDeclarator),(yyvsp[-4].token),NULL,(yyvsp[0].token),NULL,(yyvsp[-3].list),(yyvsp[-1].expression),(yyvsp[-2].token),NULL); }
#line 3426 "c11ansi.c"
    break;

  case 220: /* direct_abstract_declarator: direct_abstract_declarator Y_LEFT_BRACKET type_qualifier_list Y_RIGHT_BRACKET  */
#line 613 "c11ansi.y"
                                                                                                                       { (yyval.directAbstractDeclarator) = createDirectAbstractDeclarator((yyvsp[-3].directAbstractDeclarator),(yyvsp[-2].token),NULL,(yyvsp[0].token),NULL,(yyvsp[-1].list),NULL,NULL,NULL); }
#line 3432 "c11ansi.c"
    break;

  case 221: /* direct_abstract_declarator: direct_abstract_declarator Y_LEFT_BRACKET assignment_expression Y_RIGHT_BRACKET  */
#line 614 "c11ansi.y"
                                                                                                                       { (yyval.directAbstractDeclarator) = createDirectAbstractDeclarator((yyvsp[-3].directAbstractDeclarator),(yyvsp[-2].token),NULL,(yyvsp[0].token),NULL,NULL,(yyvsp[-1].expression),NULL,NULL); }
#line 3438 "c11ansi.c"
    break;

  case 222: /* direct_abstract_declarator: Y_LEFT_PAREN Y_RIGHT_PAREN  */
#line 615 "c11ansi.y"
                                                                                                                       { (yyval.directAbstractDeclarator) = createDirectAbstractDeclarator(NULL,(yyvsp[-1].token),NULL,(yyvsp[0].token),NULL,NULL,NULL,NULL,NULL); }
#line 3444 "c11ansi.c"
    break;

  case 223: /* direct_abstract_declarator: Y_LEFT_PAREN parameter_type_list Y_RIGHT_PAREN  */
#line 616 "c11ansi.y"
                                                                                                                       { (yyval.directAbstractDeclarator) = createDirectAbstractDeclarator(NULL,(yyvsp[-2].token),NULL,(yyvsp[0].token),NULL,NULL,NULL,NULL,(yyvsp[-1].parameterTypeList)); }
#line 3450 "c11ansi.c"
    break;

  case 224: /* direct_abstract_declarator: direct_abstract_declarator Y_LEFT_PAREN Y_RIGHT_PAREN  */
#line 617 "c11ansi.y"
                                                                                                                       { (yyval.directAbstractDeclarator) = createDirectAbstractDeclarator((yyvsp[-2].directAbstractDeclarator),(yyvsp[-1].token),NULL,(yyvsp[0].token),NULL,NULL,NULL,NULL,NULL); }
#line 3456 "c11ansi.c"
    break;

  case 225: /* direct_abstract_declarator: direct_abstract_declarator Y_LEFT_PAREN parameter_type_list Y_RIGHT_PAREN  */
#line 618 "c11ansi.y"
                                                                                                                       { (yyval.directAbstractDeclarator) = createDirectAbstractDeclarator((yyvsp[-3].directAbstractDeclarator),(yyvsp[-2].token),NULL,(yyvsp[0].token),NULL,NULL,NULL,NULL,(yyvsp[-1].parameterTypeList)); }
#line 3462 "c11ansi.c"
    break;

  case 226: /* initializer: Y_LEFT_BRACE initializer_list Y_RIGHT_BRACE  */
#line 622 "c11ansi.y"
                                                              { (yyval.expression) = createCTreeRoot(createConstr6Label(LABCT_EXPR_LIST, (yyvsp[-2].token), (yyvsp[0].token), (yyvsp[-1].list))); }
#line 3468 "c11ansi.c"
    break;

  case 227: /* initializer: Y_LEFT_BRACE initializer_list Y_COMMA Y_RIGHT_BRACE  */
#line 623 "c11ansi.y"
                                                              { (yyval.expression) = createCTreeRoot(createConstr6Label(LABCT_EXPR_LIST, (yyvsp[-3].token), (yyvsp[-1].token), (yyvsp[-2].list))); }
#line 3474 "c11ansi.c"
    break;

  case 228: /* initializer: assignment_expression  */
#line 624 "c11ansi.y"
                                                              { (yyval.expression) = (yyvsp[0].expression); }
#line 3480 "c11ansi.c"
    break;

  case 229: /* initializer_list: designation initializer  */
#line 628 "c11ansi.y"
                                                            { (yyval.list) = createInitializerList((yyvsp[-1].designation),(yyvsp[0].expression),NULL); }
#line 3486 "c11ansi.c"
    break;

  case 230: /* initializer_list: initializer  */
#line 629 "c11ansi.y"
                                                            { (yyval.list) = createInitializerList(NULL,(yyvsp[0].expression),NULL); }
#line 3492 "c11ansi.c"
    break;

  case 231: /* initializer_list: initializer_list Y_COMMA designation initializer  */
#line 630 "c11ansi.y"
                                                            { (yyval.list) = createInitializerList((yyvsp[-1].designation),(yyvsp[0].expression),(yyvsp[-3].list)); }
#line 3498 "c11ansi.c"
    break;

  case 232: /* initializer_list: initializer_list Y_COMMA initializer  */
#line 631 "c11ansi.y"
                                                            { (yyval.list) = createInitializerList(NULL,(yyvsp[0].expression),(yyvsp[-2].list)); }
#line 3504 "c11ansi.c"
    break;

  case 233: /* designation: designator_list Y_EQUAL  */
#line 635 "c11ansi.y"
                                   { (yyval.designation) = createDesignation((yyvsp[-1].list),(yyvsp[0].token)); }
#line 3510 "c11ansi.c"
    break;

  case 234: /* designator_list: designator  */
#line 639 "c11ansi.y"
                                     { (yyval.list) = createDesignatorList((yyvsp[0].designator),NULL); }
#line 3516 "c11ansi.c"
    break;

  case 235: /* designator_list: designator_list designator  */
#line 640 "c11ansi.y"
                                     { (yyval.list) = createDesignatorList((yyvsp[0].designator),(yyvsp[-1].list)); }
#line 3522 "c11ansi.c"
    break;

  case 236: /* designator: Y_LEFT_BRACKET constant_expression Y_RIGHT_BRACKET  */
#line 644 "c11ansi.y"
                                                             { (yyval.designator) = createDesignator((yyvsp[-2].token),(yyvsp[-1].expression),(yyvsp[0].token),NULL,NULL); }
#line 3528 "c11ansi.c"
    break;

  case 237: /* designator: Y_DOT "identifier"  */
#line 645 "c11ansi.y"
                                                             { (yyval.designator) = createDesignator(NULL,NULL,NULL,(yyvsp[-1].token),(yyvsp[0].token)); }
#line 3534 "c11ansi.c"
    break;

  case 238: /* static_assert_declaration: Y_STATIC_ASSERT Y_LEFT_PAREN constant_expression Y_COMMA "sting_literal" Y_RIGHT_PAREN Y_SEMICOLON  */
#line 649 "c11ansi.y"
                                                                                                            { (yyval.staticAssertDecl) = NULL; }
#line 3540 "c11ansi.c"
    break;

  case 239: /* statement: labeled_statement  */
#line 653 "c11ansi.y"
                                { (yyval.statement) = createStatement(LABELED_STATEMENT,(yyvsp[0].labeledStatement),NULL,NULL,NULL,NULL,NULL); }
#line 3546 "c11ansi.c"
    break;

  case 240: /* statement: compound_statement  */
#line 654 "c11ansi.y"
                                { (yyval.statement) = createStatement(COMPOUND_STATEMENT,NULL,(yyvsp[0].list),NULL,NULL,NULL,NULL); }
#line 3552 "c11ansi.c"
    break;

  case 241: /* statement: expression_statement  */
#line 655 "c11ansi.y"
                                { (yyval.statement) = createStatement(EXPRESSION_STATEMENT,NULL,NULL,(yyvsp[0].expressionStatement),NULL,NULL,NULL); }
#line 3558 "c11ansi.c"
    break;

  case 242: /* statement: selection_statement  */
#line 656 "c11ansi.y"
                                { (yyval.statement) = createStatement(SELECTION_STATEMENT,NULL,NULL,NULL,(yyvsp[0].selectionStatement),NULL,NULL); }
#line 3564 "c11ansi.c"
    break;

  case 243: /* statement: iteration_statement  */
#line 657 "c11ansi.y"
                                { (yyval.statement) = createStatement(ITERATION_STATEMENT,NULL,NULL,NULL,NULL,(yyvsp[0].iterationStatement),NULL); }
#line 3570 "c11ansi.c"
    break;

  case 244: /* statement: jump_statement  */
#line 658 "c11ansi.y"
                                { (yyval.statement) = createStatement(JUMP_STATEMENT,NULL,NULL,NULL,NULL,NULL,(yyvsp[0].jumpStatement)); }
#line 3576 "c11ansi.c"
    break;

  case 245: /* labeled_statement: "identifier" Y_COLON statement  */
#line 662 "c11ansi.y"
                                                        { (yyval.labeledStatement) = createLabeledStatement((yyvsp[-2].token),(yyvsp[0].statement),NULL,NULL); }
#line 3582 "c11ansi.c"
    break;

  case 246: /* labeled_statement: Y_CASE constant_expression Y_COLON statement  */
#line 663 "c11ansi.y"
                                                        { (yyval.labeledStatement) = createLabeledStatement(NULL,(yyvsp[0].statement),(yyvsp[-2].expression),NULL); }
#line 3588 "c11ansi.c"
    break;

  case 247: /* labeled_statement: Y_DEFAULT Y_COLON statement  */
#line 664 "c11ansi.y"
                                                        { (yyval.labeledStatement) = createLabeledStatement(NULL,(yyvsp[0].statement),NULL,(yyvsp[-2].token)); }
#line 3594 "c11ansi.c"
    break;

  case 248: /* compound_statement: Y_LEFT_BRACE Y_RIGHT_BRACE  */
#line 668 "c11ansi.y"
                                                      { (yyval.list) = NULL; }
#line 3600 "c11ansi.c"
    break;

  case 249: /* compound_statement: Y_LEFT_BRACE block_item_list Y_RIGHT_BRACE  */
#line 669 "c11ansi.y"
                                                      { (yyval.list) = (yyvsp[-1].list); }
#line 3606 "c11ansi.c"
    break;

  case 250: /* block_item_list: block_item  */
#line 673 "c11ansi.y"
                                     { (yyval.list) = createBlockItemList((yyvsp[0].blockItem),NULL); }
#line 3612 "c11ansi.c"
    break;

  case 251: /* block_item_list: block_item_list block_item  */
#line 674 "c11ansi.y"
                                     { (yyval.list) = createBlockItemList((yyvsp[0].blockItem),(yyvsp[-1].list)); }
#line 3618 "c11ansi.c"
    break;

  case 252: /* block_item: declaration  */
#line 678 "c11ansi.y"
                      { (yyval.blockItem) = createBlockItem((yyvsp[0].declaration),NULL); }
#line 3624 "c11ansi.c"
    break;

  case 253: /* block_item: statement  */
#line 679 "c11ansi.y"
                      { (yyval.blockItem) = createBlockItem(NULL,(yyvsp[0].statement)); }
#line 3630 "c11ansi.c"
    break;

  case 254: /* expression_statement: Y_SEMICOLON  */
#line 683 "c11ansi.y"
                                 { (yyval.expressionStatement) = createExpressionStatement(NULL); }
#line 3636 "c11ansi.c"
    break;

  case 255: /* expression_statement: expression Y_SEMICOLON  */
#line 684 "c11ansi.y"
                                 { (yyval.expressionStatement) = createExpressionStatement((yyvsp[-1].expression)); }
#line 3642 "c11ansi.c"
    break;

  case 256: /* selection_statement: Y_IF Y_LEFT_PAREN expression Y_RIGHT_PAREN statement  */
#line 688 "c11ansi.y"
                                                                                { (yyval.selectionStatement) = createSelectionStatement((yyvsp[-2].expression),(yyvsp[0].statement),NULL); }
#line 3648 "c11ansi.c"
    break;

  case 257: /* selection_statement: Y_IF Y_LEFT_PAREN expression Y_RIGHT_PAREN statement Y_ELSE statement  */
#line 689 "c11ansi.y"
                                                                                { (yyval.selectionStatement) = createSelectionStatement((yyvsp[-4].expression),(yyvsp[-2].statement),(yyvsp[0].statement)); }
#line 3654 "c11ansi.c"
    break;

  case 258: /* selection_statement: Y_SWITCH Y_LEFT_PAREN expression Y_RIGHT_PAREN statement  */
#line 690 "c11ansi.y"
                                                                                { (yyval.selectionStatement) = createSelectionStatement((yyvsp[-2].expression),(yyvsp[0].statement),NULL); }
#line 3660 "c11ansi.c"
    break;

  case 259: /* iteration_statement: Y_WHILE Y_LEFT_PAREN expression Y_RIGHT_PAREN statement  */
#line 694 "c11ansi.y"
                                                                                                          { (yyval.iterationStatement) = createIterationStatement((yyvsp[-4].token), (yyvsp[-2].expression), (yyvsp[0].statement), NULL, NULL, NULL); }
#line 3666 "c11ansi.c"
    break;

  case 260: /* iteration_statement: Y_DO statement Y_WHILE Y_LEFT_PAREN expression Y_RIGHT_PAREN Y_SEMICOLON  */
#line 695 "c11ansi.y"
                                                                                                          { (yyval.iterationStatement) = createIterationStatement((yyvsp[-6].token), (yyvsp[-2].expression), (yyvsp[-5].statement), NULL, NULL, NULL); }
#line 3672 "c11ansi.c"
    break;

  case 261: /* iteration_statement: Y_FOR Y_LEFT_PAREN expression_statement expression_statement Y_RIGHT_PAREN statement  */
#line 696 "c11ansi.y"
                                                                                                          { (yyval.iterationStatement) = createIterationStatement((yyvsp[-5].token), NULL, (yyvsp[0].statement), (yyvsp[-3].expressionStatement), (yyvsp[-2].expressionStatement), NULL); }
#line 3678 "c11ansi.c"
    break;

  case 262: /* iteration_statement: Y_FOR Y_LEFT_PAREN expression_statement expression_statement expression Y_RIGHT_PAREN statement  */
#line 697 "c11ansi.y"
                                                                                                          { (yyval.iterationStatement) = createIterationStatement((yyvsp[-6].token), (yyvsp[-2].expression), (yyvsp[0].statement), (yyvsp[-4].expressionStatement), (yyvsp[-3].expressionStatement), NULL); }
#line 3684 "c11ansi.c"
    break;

  case 263: /* iteration_statement: Y_FOR Y_LEFT_PAREN declaration expression_statement Y_RIGHT_PAREN statement  */
#line 698 "c11ansi.y"
                                                                                                          { (yyval.iterationStatement) = createIterationStatement((yyvsp[-5].token), NULL, (yyvsp[0].statement), (yyvsp[-2].expressionStatement), NULL, (yyvsp[-3].declaration)); }
#line 3690 "c11ansi.c"
    break;

  case 264: /* iteration_statement: Y_FOR Y_LEFT_PAREN declaration expression_statement expression Y_RIGHT_PAREN statement  */
#line 699 "c11ansi.y"
                                                                                                          { (yyval.iterationStatement) = createIterationStatement((yyvsp[-6].token), (yyvsp[-2].expression), (yyvsp[0].statement), (yyvsp[-3].expressionStatement), NULL, (yyvsp[-4].declaration)); }
#line 3696 "c11ansi.c"
    break;

  case 265: /* jump_statement: Y_GOTO "identifier" Y_SEMICOLON  */
#line 703 "c11ansi.y"
                                           { printf("jump_statement -> Y_GOTO IDENTIFIER Y_SEMICOLON\n");   (yyval.jumpStatement) = createJumpStatement((yyvsp[-2].token),(yyvsp[-1].token),NULL); }
#line 3702 "c11ansi.c"
    break;

  case 266: /* jump_statement: Y_CONTINUE Y_SEMICOLON  */
#line 704 "c11ansi.y"
                                           { printf("jump_statement -> Y_CONTINUE Y_SEMICOLON\n");          (yyval.jumpStatement) = createJumpStatement((yyvsp[-1].token),NULL,NULL); }
#line 3708 "c11ansi.c"
    break;

  case 267: /* jump_statement: Y_BREAK Y_SEMICOLON  */
#line 705 "c11ansi.y"
                                           { printf("jump_statement -> Y_BREAK Y_SEMICOLON\n");             (yyval.jumpStatement) = createJumpStatement((yyvsp[-1].token),NULL,NULL); }
#line 3714 "c11ansi.c"
    break;

  case 268: /* jump_statement: Y_RETURN Y_SEMICOLON  */
#line 706 "c11ansi.y"
                                           { printf("jump_statement -> Y_RETURN Y_SEMICOLON\n");            (yyval.jumpStatement) = createJumpStatement((yyvsp[-1].token),NULL,NULL); }
#line 3720 "c11ansi.c"
    break;

  case 269: /* jump_statement: Y_RETURN expression Y_SEMICOLON  */
#line 707 "c11ansi.y"
                                           { printf("jump_statement -> Y_RETURN expression Y_SEMICOLON\n"); (yyval.jumpStatement) = createJumpStatement((yyvsp[-2].token),NULL,(yyvsp[-1].expression)); }
#line 3726 "c11ansi.c"
    break;

  case 270: /* translation_unit: external_declaration  */
#line 711 "c11ansi.y"
                                                 { printf("translation_unit -> external_declaration\n\n"); createProgramData((yyvsp[0].externalDeclaration)); }
#line 3732 "c11ansi.c"
    break;

  case 271: /* translation_unit: translation_unit external_declaration  */
#line 712 "c11ansi.y"
                                                 { printf("translation_unit -> translation_unit external_declaration\n\n"); createProgramData((yyvsp[0].externalDeclaration)); }
#line 3738 "c11ansi.c"
    break;

  case 272: /* external_declaration: function_definition  */
#line 716 "c11ansi.y"
                                { printf("external_declaration -> function_definition\n"); (yyval.externalDeclaration) = createExternalDeclaration(NULL, (yyvsp[0].functionDefinition)); }
#line 3744 "c11ansi.c"
    break;

  case 273: /* external_declaration: declaration  */
#line 717 "c11ansi.y"
                                { printf("external_declaration -> declaration\n"); (yyval.externalDeclaration) = createExternalDeclaration((yyvsp[0].declaration),NULL); }
#line 3750 "c11ansi.c"
    break;

  case 274: /* function_definition: declaration_specifiers declarator declaration_list compound_statement  */
#line 721 "c11ansi.y"
                                                                                { printf("function_definition -> declaration_specifiers declarator declaration_list compound_statement\n"); (yyval.functionDefinition) = createFunctionDefinition((yyvsp[-3].declSpecifiers),(yyvsp[-2].declarator),(yyvsp[-1].list),(yyvsp[0].list)); }
#line 3756 "c11ansi.c"
    break;

  case 275: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 722 "c11ansi.y"
                                                                                { printf("function_definition -> declaration_specifiers declarator compound_statement\n"); (yyval.functionDefinition) = createFunctionDefinition((yyvsp[-2].declSpecifiers),(yyvsp[-1].declarator),NULL,(yyvsp[0].list)); }
#line 3762 "c11ansi.c"
    break;

  case 276: /* declaration_list: declaration  */
#line 726 "c11ansi.y"
                                       { (yyval.list) = createDeclarationList((yyvsp[0].declaration),NULL); }
#line 3768 "c11ansi.c"
    break;

  case 277: /* declaration_list: declaration_list declaration  */
#line 727 "c11ansi.y"
                                       { (yyval.list) = createDeclarationList((yyvsp[0].declaration),(yyvsp[-1].list)); }
#line 3774 "c11ansi.c"
    break;


#line 3778 "c11ansi.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= END)
        {
          /* Return failure if at end of input.  */
          if (yychar == END)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 731 "c11ansi.y"

#include <stdio.h>

extern char * yytext;
extern int yylineno;

int yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** Line %d %s %s\n", yylineno, s, yytext);
	return 0;
}
