/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Skeleton implementation for Bison GLR parsers in C

   Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

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

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 1






/* First part of user prologue.  */
#line 1 "c11ansi.y"

#include <stdlib.h>
#include <stdio.h>
#include "jcc.h"

int yyerror(const char *s);
int yylex();

#line 67 "c11ansi.tab.c"

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

#include "c11ansi.tab.h"

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
  YYSYMBOL_129_ = 129,                     /* '*'  */
  YYSYMBOL_YYACCEPT = 130,                 /* $accept  */
  YYSYMBOL_primary_expression = 131,       /* primary_expression  */
  YYSYMBOL_constant = 132,                 /* constant  */
  YYSYMBOL_enumeration_constant = 133,     /* enumeration_constant  */
  YYSYMBOL_string = 134,                   /* string  */
  YYSYMBOL_postfix_expression = 135,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 136, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 137,         /* unary_expression  */
  YYSYMBOL_unary_operator = 138,           /* unary_operator  */
  YYSYMBOL_cast_expression = 139,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 140, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 141,      /* additive_expression  */
  YYSYMBOL_shift_expression = 142,         /* shift_expression  */
  YYSYMBOL_relational_expression = 143,    /* relational_expression  */
  YYSYMBOL_equality_expression = 144,      /* equality_expression  */
  YYSYMBOL_and_expression = 145,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 146,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 147,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 148,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 149,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 150,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 151,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 152,      /* assignment_operator  */
  YYSYMBOL_expression = 153,               /* expression  */
  YYSYMBOL_constant_expression = 154,      /* constant_expression  */
  YYSYMBOL_declaration = 155,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 156,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 157,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 158,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 159,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 160,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 161, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 162,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 163,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 164,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 165, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 166,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 167,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 168,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 169,          /* enumerator_list  */
  YYSYMBOL_enumerator = 170,               /* enumerator  */
  YYSYMBOL_atomic_type_specifier = 171,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 172,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 173,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 174,      /* alignment_specifier  */
  YYSYMBOL_declarator = 175,               /* declarator  */
  YYSYMBOL_direct_declarator = 176,        /* direct_declarator  */
  YYSYMBOL_pointer = 177,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 178,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 179,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 180,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 181,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 182,          /* identifier_list  */
  YYSYMBOL_type_name = 183,                /* type_name  */
  YYSYMBOL_abstract_declarator = 184,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 185, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 186,              /* initializer  */
  YYSYMBOL_initializer_list = 187,         /* initializer_list  */
  YYSYMBOL_designation = 188,              /* designation  */
  YYSYMBOL_designator_list = 189,          /* designator_list  */
  YYSYMBOL_designator = 190,               /* designator  */
  YYSYMBOL_static_assert_declaration = 191, /* static_assert_declaration  */
  YYSYMBOL_statement = 192,                /* statement  */
  YYSYMBOL_labeled_statement = 193,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 194,       /* compound_statement  */
  YYSYMBOL_block_item_list = 195,          /* block_item_list  */
  YYSYMBOL_block_item = 196,               /* block_item  */
  YYSYMBOL_expression_statement = 197,     /* expression_statement  */
  YYSYMBOL_selection_statement = 198,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 199,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 200,           /* jump_statement  */
  YYSYMBOL_translation_unit = 201,         /* translation_unit  */
  YYSYMBOL_external_declaration = 202,     /* external_declaration  */
  YYSYMBOL_function_definition = 203,      /* function_definition  */
  YYSYMBOL_declaration_list = 204          /* declaration_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;



#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#ifdef __cplusplus
  typedef bool yybool;
# define yytrue true
# define yyfalse false
#else
  /* When we move to stdbool, get rid of the various casts to yybool.  */
  typedef signed char yybool;
# define yytrue 1
# define yyfalse 0
#endif

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify Clang and ICC.  */
# define YYLONGJMP(Env, Val)                    \
 do {                                           \
   longjmp (Env, Val);                          \
   YY_ASSERT (0);                               \
 } while (yyfalse)
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

/* The _Noreturn keyword of C11.  */
#ifndef _Noreturn
# if (defined __cplusplus \
      && ((201103 <= __cplusplus && !(__GNUC__ == 4 && __GNUC_MINOR__ == 7)) \
          || (defined _MSC_VER && 1900 <= _MSC_VER)))
#  define _Noreturn [[noreturn]]
# elif ((!defined __cplusplus || defined __clang__) \
        && (201112 <= (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0) \
            || (!defined __STRICT_ANSI__ \
                && (4 < __GNUC__ + (7 <= __GNUC_MINOR__) \
                    || (defined __apple_build_version__ \
                        ? 6000000 <= __apple_build_version__ \
                        : 3 < __clang_major__ + (5 <= __clang_minor__))))))
   /* _Noreturn works as-is.  */
# elif (2 < __GNUC__ + (8 <= __GNUC_MINOR__) || defined __clang__ \
        || 0x5110 <= __SUNPRO_C)
#  define _Noreturn __attribute__ ((__noreturn__))
# elif 1200 <= (defined _MSC_VER ? _MSC_VER : 0)
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn
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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  69
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2678

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  130
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
/* YYNRULES -- Number of rules.  */
#define YYNRULES  271
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  466
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 7
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   383

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
       2,     2,   129,     2,     2,     2,     2,     2,     2,     2,
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
     125,   126,   127,   128
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   180,   180,   181,   182,   183,   188,   189,   190,   194,
     198,   199,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   230,   231,   235,   236,   237,   238,   239,   240,
     241,   245,   246,   247,   248,   249,   250,   254,   255,   259,
     260,   261,   262,   266,   267,   268,   272,   273,   274,   278,
     279,   280,   281,   282,   286,   287,   288,   292,   293,   297,
     298,   302,   303,   307,   308,   312,   313,   317,   318,   322,
     323,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   341,   342,   346,   350,   351,   352,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   369,   370,
     374,   375,   379,   380,   381,   382,   383,   384,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   409,   410,   411,   415,
     416,   420,   421,   425,   426,   427,   431,   432,   433,   434,
     438,   439,   443,   444,   445,   449,   450,   451,   452,   453,
     457,   458,   462,   463,   467,   471,   472,   473,   474,   478,
     479,   483,   484,   488,   489,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   510,
     511,   512,   513,   517,   518,   523,   524,   528,   529,   533,
     534,   535,   539,   540,   544,   545,   549,   550,   551,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     579,   580,   581,   585,   586,   587,   588,   592,   596,   597,
     601,   602,   606,   610,   611,   612,   613,   614,   615,   619,
     620,   621,   625,   626,   630,   631,   635,   636,   640,   641,
     645,   646,   647,   651,   652,   653,   654,   655,   656,   660,
     661,   662,   663,   664,   668,   669,   673,   674,   678,   679,
     683,   684
};
#endif

#define YYPACT_NINF (-341)
#define YYTABLE_NINF (-1)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2308,  -341,  -341,  -341,  -341,  -341,    20,  -341,  -341,  -341,
    -341,  -341,  -341,  -341,  -341,  -341,  -341,  -341,  -341,  -341,
    -341,  -341,  -341,  -341,  -341,  -341,    18,  -341,  -341,  -341,
      21,    43,  -341,  -341,   201,  2363,  2363,  -341,    24,  -341,
    -341,  2363,  2363,  2363,  -341,   339,  -341,  -341,   -43,    37,
    2550,   969,  2059,  -341,   231,    26,  -341,    28,  -341,  2198,
       6,   238,  -341,  -341,   -15,  2504,  -341,  -341,  -341,  -341,
    -341,    37,  -341,    41,    33,  -341,  2550,    60,  2550,   103,
    -341,  -341,  -341,  -341,  -341,  -341,   969,  -341,  -341,  2080,
    -341,  2080,  2101,  -341,  -341,  -341,   165,  -341,  -341,  -341,
     217,  -341,  2059,  -341,    27,   162,   136,   239,    29,   185,
     160,   122,   210,   -10,  -341,   236,   241,   204,   256,  -341,
    -341,  -341,    26,   231,  -341,   995,   599,  -341,   201,  -341,
    2253,  1124,  1417,     6,  2504,  2412,  -341,   198,  -341,    44,
    2059,    11,  -341,  -341,  1234,   457,   130,  -341,   154,  -341,
    -341,   496,  -341,  -341,   161,   267,   969,  -341,  -341,   969,
    -341,  2550,  1777,  -341,  -341,   229,   250,  2059,  -341,  2059,
    2059,  2059,  2059,  2059,  2059,  2059,  2059,  2059,  2059,  2059,
    2059,  2059,  2059,  2059,  2059,  2059,  2059,  2059,  -341,  -341,
     277,  -341,  -341,  -341,  -341,   261,  1753,  -341,  -341,   271,
    -341,  -341,   288,   290,  2059,   300,   310,  1165,   311,   324,
     298,   299,  1798,   225,  -341,  -341,  -341,  -341,   725,  -341,
    -341,  -341,  -341,  -341,  -341,  -341,  -341,  -341,   129,   319,
     323,  -341,   179,   301,  -341,  1607,   303,  1445,  2458,  -341,
    -341,  2059,  -341,   228,  -341,   315,    14,  -341,  -341,  -341,
    -341,  -341,   334,   335,  -341,  1607,   313,   314,  1473,   154,
    1301,   485,  -341,  -341,  -341,  -341,  -341,  -341,  -341,  -341,
    -341,  -341,  -341,  2059,  -341,  2059,  1894,   346,   349,   351,
    -341,   208,  -341,  -341,  -341,    13,  -341,  -341,  -341,    27,
      27,   162,   162,   136,   136,   136,   136,   239,   239,    29,
     185,   160,   122,    31,   210,   353,   366,  2059,  -341,    52,
     995,    98,  -341,  1165,  2059,  1165,   340,  2059,  2059,   251,
     851,   341,  -341,  -341,  -341,   233,  -341,  -341,  -341,  1045,
    -341,   183,  -341,  -341,  2143,  -341,   368,  -341,   329,  1607,
    -341,   330,  -341,  2059,   336,  -341,  -341,   234,  -341,  2059,
    -341,  -341,  -341,   337,  1607,  -341,  -341,  -341,  2059,   338,
    -341,   364,  -341,  1607,   342,   343,  1586,  -341,  -341,  1753,
    -341,   294,   294,  -341,  -341,  2059,  -341,  2059,   348,  -341,
     344,  1633,  -341,  -341,  -341,  -341,  -341,   266,  -341,  1165,
     270,   275,   371,  1915,  1915,  -341,  -341,  -341,  -341,  -341,
    -341,   345,  -341,   347,  -341,  -341,  -341,  -341,   350,   352,
    -341,  -341,   355,  1607,  -341,  -341,  -341,  2059,   356,    78,
    -341,  -341,  -341,  -341,  -341,  -341,   995,  1165,  -341,  1165,
    1165,  2059,  1939,  1963,  -341,  -341,  -341,  -341,  -341,   358,
     360,  -341,  1729,  -341,  -341,   318,  -341,  -341,   284,  1165,
     291,  1165,   296,  -341,  -341,  -341,  1165,   354,  -341,  1165,
    -341,  1165,  -341,  -341,  -341,  -341
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   105,   106,   109,   155,   115,     0,   103,   114,   111,
     112,   107,   110,   117,   104,   129,   102,   130,   118,   108,
     157,   125,   121,   120,   116,   119,   158,   156,   159,   160,
       0,     0,   113,   267,     0,    89,    91,   123,     0,   124,
     122,    93,    95,    97,    87,     0,   264,   266,   149,     0,
       0,     0,     0,   165,     0,   182,    85,     0,    98,   101,
     164,     0,    88,    90,   128,     0,    92,    94,    96,     1,
     265,     0,     9,   153,     0,   150,   137,   195,   139,     0,
       2,     6,     7,    10,    36,    31,     0,    32,    33,     0,
      34,     0,     0,    35,     8,    11,     0,    12,     3,     4,
      24,    37,     0,    39,    43,    46,    49,    54,    57,    59,
      61,    63,    65,    67,    84,     0,     0,     0,     0,   158,
     183,   181,   180,     0,    86,     0,     0,   270,     0,   269,
       0,     0,     0,   163,     0,     0,   131,     0,   135,     0,
       0,     0,   145,   136,     0,     0,   197,   194,   198,   138,
     154,    37,    69,    82,     0,     0,     0,    25,    26,     0,
      28,     0,     0,    18,    19,     0,     0,     0,    27,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   162,   161,
       0,   166,   184,   179,    99,   101,     0,   222,   100,     2,
     248,   242,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   246,   247,   233,   234,     0,   244,
     235,   236,   237,   238,   271,   268,   192,   177,   191,     0,
     186,   187,     0,    32,   167,     0,     0,     0,     0,   126,
     132,     0,   133,     0,   140,   144,     0,   147,   152,   146,
     151,   216,     0,     0,   200,     0,     0,     0,     0,   196,
       0,     0,    79,    72,    75,    76,    73,    77,    71,    78,
      80,    81,    74,     0,     5,     0,     0,     0,     0,     0,
      14,     0,    22,    17,    16,     0,    40,    41,    42,    44,
      45,    48,    47,    50,    52,    51,    53,    56,    55,    58,
      60,    62,    64,     0,    66,     0,     0,     0,   224,     0,
       0,     0,   228,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   260,   261,   262,     0,   249,   243,   245,     0,
     189,   197,   190,   176,     0,   178,     0,   168,     0,     0,
     175,    32,   174,     0,     0,   127,   142,     0,   134,     0,
     148,   217,   199,     0,     0,   201,   207,   206,     0,     0,
     218,     0,   208,     0,     0,     0,     0,    70,    83,     0,
      38,     0,    29,    30,    15,     0,    13,     0,     0,   231,
       0,     0,   220,   223,   227,   229,   239,     0,   241,     0,
       0,     0,     0,     0,     0,   259,   263,   185,   188,   193,
     170,     0,   171,     0,   173,   141,   143,   203,     0,     0,
     205,   219,     0,     0,   209,   215,   214,     0,     0,     0,
      23,    68,   232,   230,   221,   226,     0,     0,   240,     0,
       0,     0,     0,     0,   169,   172,   202,   204,   211,     0,
       0,   212,     0,    20,   225,   251,   252,   253,     0,     0,
       0,     0,     0,   210,   213,    21,     0,     0,   257,     0,
     255,     0,   250,   254,   258,   256
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -341,  -341,  -341,  -341,  -341,  -341,  -341,   -21,  -341,   -77,
      86,    92,   164,    89,   211,   213,   214,   209,   219,  -341,
     -39,   -66,  -341,   -79,   -23,   -40,     3,  -341,   289,  -341,
     243,  -341,  -341,   287,  -113,   -14,  -341,    82,  -341,   359,
    -130,  -341,   -50,  -341,  -341,   -25,   -57,   -53,   -45,  -121,
    -341,    97,  -341,   -30,   -61,  -138,  -119,    63,  -340,  -341,
     123,   -12,   -94,  -341,   -41,  -341,   215,  -257,  -341,  -341,
    -341,  -341,   390,  -341,  -341
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    97,    98,    73,    99,   100,   281,   151,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     152,   153,   273,   213,   115,    33,   128,    57,    58,    35,
      36,    37,    38,   135,   136,    77,   243,   244,    39,    74,
      75,    40,    41,    42,    43,   118,    60,    61,   122,   252,
     230,   231,   232,    79,   253,   148,   308,   309,   310,   311,
     312,    44,   215,   216,   217,   218,   219,   220,   221,   222,
     223,    45,    46,    47,   130
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      78,    78,   121,    34,   133,   120,   198,   154,   259,    59,
     229,   250,   114,   114,    72,    78,   147,    72,   129,   127,
     131,   116,   240,    48,   146,   168,    78,    64,    78,   117,
     101,   101,    50,   186,   275,    51,    78,   180,    62,    63,
      72,   426,    55,   169,    66,    67,    68,    71,    34,   123,
     132,   137,   275,   138,   141,   170,   155,    52,   376,   197,
     124,   377,   143,   394,   149,   246,   236,   181,   157,   193,
     158,   160,   192,   381,   144,   134,    55,   154,   140,   257,
     154,   101,   120,   187,    78,    78,   214,   237,   285,   225,
     224,   146,   286,   287,   288,   120,   282,     4,   195,   442,
     258,   114,   426,   195,   145,   249,    78,   303,   350,    78,
      49,    78,   245,   319,    65,    20,   250,   248,   150,   101,
     137,   137,   138,   138,   306,   240,   277,   142,   171,   278,
     197,   279,    53,   325,   228,   384,   432,   433,   247,   361,
     119,    27,   307,   329,   144,    55,   382,   228,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   114,   101,   332,   260,   338,
     174,   344,   443,   145,   145,   331,   274,   175,   214,   161,
     172,   316,   275,   101,   173,   120,    53,   192,    78,   353,
     339,   383,   359,   259,   335,   365,   182,   329,   261,   370,
     336,    53,   114,   330,    53,   120,   183,   367,   192,   368,
     354,   120,    54,   184,    55,    54,   366,    55,   346,   386,
     101,   388,   185,   374,   137,   190,   138,   145,   241,   375,
     242,   162,   283,    56,    53,   387,   163,    53,   390,   391,
     164,    53,   165,   166,   197,    54,   275,    55,    54,   347,
      55,   188,    54,   284,   275,   101,   189,   326,   289,   290,
     348,   167,   425,   228,   241,   396,   291,   292,   114,   297,
     298,   191,   176,   401,   133,   177,   331,   403,   178,   179,
     393,   427,   276,   305,   380,   429,   101,   275,   408,   192,
     430,   275,   409,    76,    76,   428,   275,   412,   125,   457,
     418,   313,   314,   197,   192,   275,   459,   444,    76,   420,
     114,   461,   275,   120,   317,   197,   192,   275,   413,    76,
     315,    76,   245,   425,   318,   320,   406,   321,   101,    76,
     322,   323,   228,   445,   333,   446,   447,   228,   421,    69,
     293,   294,   295,   296,   334,   349,   337,   439,   340,   351,
     352,   440,   448,   450,   452,   458,   101,   460,   355,   356,
     197,   371,   462,   192,   372,   464,   373,   465,   378,   379,
     389,   399,   392,   395,   400,   402,   197,    76,    76,   411,
     422,   404,   407,   410,   369,   431,   463,   414,   415,   423,
     434,   456,   435,   299,   302,   436,   300,   437,   301,    76,
     438,   441,    76,   453,    76,   454,   304,     1,     2,     3,
       4,     5,   194,     6,     7,     8,     9,    10,    11,    12,
      13,   238,    14,    15,    16,    17,    18,    19,    20,   405,
     139,   398,   419,   328,   385,    70,     0,     0,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     0,
      80,    81,    82,    83,    84,     0,     0,    32,    85,     0,
       0,    86,     0,    87,     0,    88,    89,     0,     0,    90,
      91,    76,     0,     0,     0,     0,     0,     0,    80,    81,
      82,    83,    84,     0,     0,     0,    85,     0,     0,    86,
       0,    87,   254,    88,    89,     0,     0,    90,    91,   262,
       0,     0,     0,   263,     0,     0,   264,     0,     0,     0,
     265,     0,     0,     0,     0,   266,     0,     0,     4,     0,
     362,   267,     0,   268,     0,     0,     0,     0,   269,    92,
     255,     0,     0,   270,     0,     0,    20,     0,     0,     0,
       0,     0,    93,     0,     0,     0,     4,     0,     0,     0,
       0,    94,    95,     0,     0,     0,    96,    92,   363,     0,
       0,   119,    27,     0,    20,     0,     0,     0,     0,     0,
      93,     0,     0,     0,     0,     0,   256,     0,   271,    94,
      95,     0,     0,     0,    96,     0,     0,     0,   272,   119,
      27,     0,   199,    81,    82,    83,    84,     0,     0,     0,
      85,     0,     0,    86,   364,    87,     0,    88,    89,     0,
       0,    90,    91,     0,     0,     0,     0,     0,     0,     0,
       0,   200,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       4,     5,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    92,    14,    15,    16,    17,    18,    19,    20,   126,
       0,     0,     0,   201,    93,   202,     0,     0,    21,     0,
       0,     0,     0,    94,    95,     0,   203,   204,    96,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,   205,
     206,   207,   208,   209,   210,   211,   212,    32,   199,    81,
      82,    83,    84,     0,     0,     0,    85,     0,     0,    86,
       0,    87,     0,    88,    89,     0,     0,    90,    91,     0,
       0,     0,     0,     0,     0,     0,     0,   200,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     0,     6,
       7,     8,     9,    10,    11,    12,    13,    92,    14,    15,
      16,    17,    18,    19,    20,   126,     0,     0,     0,   327,
      93,   202,     0,     0,    21,     0,     0,     0,     0,    94,
      95,     0,   203,   204,    96,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,   205,   206,   207,   208,   209,
     210,   211,   212,    32,    80,    81,    82,    83,    84,     0,
       0,     0,    85,     0,     0,    86,     0,    87,     0,    88,
      89,     0,     0,    90,    91,     0,     0,     0,     0,     0,
       0,     0,     0,   200,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     4,     5,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    92,    14,    15,    16,    17,    18,    19,
      20,     0,     0,     0,     0,     0,    93,     0,     0,     0,
      21,     0,     0,     0,     0,    94,    95,     0,     0,     0,
      96,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     0,    80,    81,    82,    83,    84,     0,     0,    32,
      85,     0,     0,    86,     0,    87,     0,    88,    89,     0,
       0,    90,    91,     0,     0,     0,     0,     0,    80,    81,
      82,    83,    84,     0,     0,     0,    85,     0,     0,    86,
       0,    87,     0,    88,    89,     0,     0,    90,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     0,     6,     0,     8,     9,    10,    53,    12,
      13,    92,     0,    15,     0,    17,    18,    19,    20,   329,
     251,    55,     0,     0,    93,     0,     0,     0,    21,     0,
       0,     0,     0,    94,    95,     0,     0,    92,    96,    22,
      23,    24,    25,    26,    27,   196,     0,     0,     0,   145,
      93,     0,     0,     0,     0,     0,     0,    32,     0,    94,
      95,     0,     0,     0,    96,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     0,     6,
       7,     8,     9,    10,    11,    12,    13,   226,    14,    15,
      16,    17,    18,    19,    20,     0,     0,     0,     0,   227,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    23,    24,    25,    26,
      27,    28,    29,    30,     0,     0,     0,     0,   199,    81,
      82,    83,    84,    32,     0,     0,    85,     0,     0,    86,
       0,    87,     0,    88,    89,     0,     0,    90,    91,     0,
       0,     0,     1,     2,     3,     4,     5,   200,     6,     7,
       8,     9,    10,    11,    12,    13,     0,    14,    15,    16,
      17,    18,    19,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     0,     0,     0,     0,    92,   144,   251,
      55,     0,    32,     0,     0,   126,     0,     0,     0,     0,
      93,   202,     0,     0,     0,     0,     0,     0,     0,    94,
      95,     0,   203,   204,    96,     0,     0,     0,   145,     0,
       0,     0,     0,     0,     0,   205,   206,   207,   208,   209,
     210,   211,   212,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     4,     5,     0,     6,     7,
       8,     9,    10,    11,    12,    13,   360,    14,    15,    16,
      17,    18,    19,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    32,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     4,     5,     0,     6,     7,     8,     9,    10,
      11,    12,    13,     0,    14,    15,    16,    17,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      80,    81,    82,    83,    84,     0,     0,     0,    85,    32,
       0,    86,     0,   233,     0,    88,    89,     0,     0,    90,
      91,     0,     0,     0,     0,     0,     0,     0,    80,    81,
      82,    83,    84,     0,     0,     0,    85,     0,     0,    86,
       0,   341,   234,    88,    89,     0,     0,    90,    91,     0,
       0,     0,     0,     0,     0,     0,    80,    81,    82,    83,
      84,     0,     0,     0,    85,     0,     0,    86,     4,    87,
     342,    88,    89,     0,     0,    90,    91,     0,     0,    92,
     235,     0,     0,     0,     0,     0,    20,     0,     0,     0,
       0,     0,    93,     0,     0,     0,     4,     0,   357,     0,
       0,    94,    95,     0,     0,     0,    96,    92,   343,     0,
       0,   119,    27,     0,    20,     0,     0,     0,     0,     0,
      93,     0,     0,     0,     4,     0,     0,     0,     0,    94,
      95,     0,     0,     0,    96,    92,   358,     0,     0,   119,
      27,     0,    20,     0,     0,     0,     0,     0,    93,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,     0,
       0,     0,    96,     0,     0,     0,     0,   119,    27,    80,
      81,    82,    83,    84,     0,     0,     0,    85,     0,     0,
      86,     0,    87,     0,    88,    89,     0,     0,    90,    91,
      80,    81,    82,    83,    84,     0,     0,     0,    85,     0,
       0,    86,     0,    87,     0,    88,    89,     0,     0,    90,
      91,   416,     0,     0,     0,     0,    80,    81,    82,    83,
      84,     0,     0,     0,    85,     0,     0,    86,     0,    87,
       0,    88,    89,     0,     0,    90,    91,     4,     0,   306,
       0,     0,     0,     0,     0,     0,     0,     0,    92,   417,
       0,     0,     0,     0,     0,    20,     0,   307,     4,     0,
       0,    93,     0,     0,     0,     0,     0,     0,     0,    92,
      94,    95,     0,     0,     0,    96,    20,     0,     0,     0,
     119,    27,    93,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,     0,     0,    92,    96,     0,     0,     0,
       0,   119,    27,   196,     0,     0,     0,   424,    93,     0,
       0,     0,    80,    81,    82,    83,    84,    94,    95,     0,
      85,     0,    96,    86,     0,    87,     0,    88,    89,     0,
       0,    90,    91,     0,     0,   306,    80,    81,    82,    83,
      84,     0,     0,     0,    85,     0,     0,    86,     0,    87,
       0,    88,    89,   307,     0,    90,    91,     0,     0,   306,
      80,    81,    82,    83,    84,     0,     0,     0,    85,     0,
       0,    86,   280,    87,     0,    88,    89,   307,     0,    90,
      91,    80,    81,    82,    83,    84,     0,     0,     0,    85,
       0,    92,    86,     0,    87,     0,    88,    89,     0,   196,
      90,    91,     0,   455,    93,     0,     0,     0,     0,     0,
     324,     0,     0,    94,    95,    92,     0,     0,    96,     0,
       0,     0,     0,   196,     0,     0,     0,     0,    93,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    92,
       0,     0,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,     0,     0,     0,     0,     0,     0,     0,
      92,    94,    95,     0,     0,     0,    96,     0,     0,     0,
       0,     0,     0,    93,     0,     0,     0,    80,    81,    82,
      83,    84,    94,    95,     0,    85,     0,    96,    86,     0,
      87,     0,    88,    89,     0,     0,    90,    91,    80,    81,
      82,    83,    84,     0,     0,     0,    85,     0,     0,    86,
       0,    87,     0,    88,    89,     0,     0,    90,    91,     0,
       0,     0,    80,    81,    82,    83,    84,   200,     0,     0,
      85,     0,     0,    86,   449,    87,     0,    88,    89,     0,
       0,    90,    91,     0,     0,     0,    80,    81,    82,    83,
      84,     0,     0,     0,    85,     0,    92,    86,   451,    87,
       0,    88,    89,     0,   369,    90,    91,     0,     0,    93,
       0,     0,     0,     0,     0,     0,     0,    92,    94,    95,
       0,     0,     0,    96,     0,     0,     0,     0,     0,     0,
      93,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    92,     0,     0,    96,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    93,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    92,     0,     0,    96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    93,     0,
       0,     0,    80,    81,    82,    83,    84,    94,    95,     0,
      85,     0,    96,    86,     0,    87,     0,    88,    89,     0,
       0,    90,    91,    80,    81,    82,    83,    84,     0,     0,
       0,    85,     0,     0,   156,     0,    87,     0,    88,    89,
       0,     0,    90,    91,    80,    81,    82,    83,    84,     0,
       0,     0,    85,     0,     0,   159,     0,    87,     0,    88,
      89,     0,     0,    90,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    93,     0,     0,     0,     0,     0,
       0,     0,    92,    94,    95,     0,     0,     0,    96,     0,
     397,     0,     0,     0,     0,    93,     0,     0,     0,     0,
       0,     0,     0,    92,    94,    95,     0,     0,     0,    96,
       0,     0,     0,     0,     0,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,     0,     0,     0,
      96,     1,     2,     3,     4,     5,     0,     6,     7,     8,
       9,    10,    11,    12,    13,     0,    14,    15,    16,    17,
      18,    19,    20,     0,     0,   125,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,     0,     0,     0,     1,     2,     3,     4,
       5,    32,     6,     7,     8,     9,    10,    11,    12,    13,
       0,    14,    15,    16,    17,    18,    19,    20,   126,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     0,     0,
       0,     1,     2,     3,     4,     5,    32,     6,     7,     8,
       9,    10,    11,    12,    13,     0,    14,    15,    16,    17,
      18,    19,    20,   126,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     0,     0,     0,     1,     2,     3,     4,
       5,    32,     6,     7,     8,     9,    10,    11,    12,    13,
       0,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     0,     0,
       0,     1,     2,     3,     4,     5,    32,     6,     7,     8,
       9,    10,    11,    12,    13,     0,    14,    15,    16,    17,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     3,     4,     5,     0,     6,     0,     8,     9,
      10,    32,    12,    13,     0,     0,    15,     0,    17,    18,
      19,    20,     0,     0,     0,     0,   239,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,    23,    24,    25,    26,    27,     3,     4,
       5,    31,     6,     0,     8,     9,    10,     0,    12,    13,
      32,     0,    15,     0,    17,    18,    19,    20,     0,     0,
       0,     0,   345,     0,     0,     0,     0,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,    23,
      24,    25,    26,    27,     3,     4,     5,    31,     6,     0,
       8,     9,    10,     0,    12,    13,    32,     0,    15,     0,
      17,    18,    19,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,    23,    24,    25,    26,    27,
       3,     4,     5,    31,     6,     0,     8,     9,    10,     0,
      12,    13,    32,     0,    15,     0,    17,    18,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,    23,    24,    25,    26,    27,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    32
};

static const yytype_int16 yycheck[] =
{
      50,    51,    55,     0,    61,    55,   125,    86,   146,    34,
     131,   141,    51,    52,     3,    65,    77,     3,    59,    59,
      14,    51,   135,     3,    77,   102,    76,     3,    78,    52,
      51,    52,    14,    43,    21,    14,    86,     8,    35,    36,
       3,   381,    16,    16,    41,    42,    43,    90,    45,    21,
      44,    65,    21,    65,    21,    28,    86,    14,    45,   125,
      32,    30,    76,   320,    78,    21,   132,    38,    89,   122,
      91,    92,   122,    21,    14,    90,    16,   156,    37,   145,
     159,   102,   132,    93,   134,   135,   126,   132,   167,   130,
     130,   144,   169,   170,   171,   145,   162,    71,   123,    21,
     145,   140,   442,   128,    44,    94,   156,   186,    94,   159,
      90,   161,   137,   207,    90,    89,   246,   140,    15,   140,
     134,   135,   134,   135,    26,   238,   156,    94,   101,   159,
     196,   161,     3,   212,   131,    37,   393,   394,    94,   260,
     114,   115,    44,    14,    14,    16,    94,   144,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   204,   187,   228,    14,   235,
      34,   237,    94,    44,    44,   228,    15,    41,   218,    14,
      18,   204,    21,   204,    22,   235,     3,   237,   238,   255,
     235,   310,   258,   331,    15,   261,    11,    14,    44,   276,
      21,     3,   241,   228,     3,   255,    46,   273,   258,   275,
     255,   261,    14,    91,    16,    14,   261,    16,   241,   313,
     241,   315,    12,    15,   238,    21,   238,    44,    30,    21,
      32,    14,     3,    32,     3,   314,    19,     3,   317,   318,
      23,     3,    25,    26,   310,    14,    21,    16,    14,    21,
      16,    15,    14,     3,    21,   276,    15,    32,   172,   173,
      32,    44,   381,   260,    30,    32,   174,   175,   307,   180,
     181,    15,    33,   339,   331,    36,   329,   343,    39,    40,
     320,    15,    15,     6,   307,    15,   307,    21,   354,   339,
      15,    21,   358,    50,    51,   389,    21,   363,    37,    15,
     366,    30,    14,   369,   354,    21,    15,   426,    65,   375,
     349,    15,    21,   363,    14,   381,   366,    21,   363,    76,
      30,    78,   347,   442,    14,    14,   349,     3,   349,    86,
      32,    32,   329,   427,    15,   429,   430,   334,   377,     0,
     176,   177,   178,   179,    21,    30,    45,   413,    45,    15,
      15,   417,   431,   432,   433,   449,   377,   451,    45,    45,
     426,    15,   456,   413,    15,   459,    15,   461,    15,     3,
      30,     3,   121,    32,    45,    45,   442,   134,   135,    15,
      32,    45,    45,    45,    90,    14,    32,    45,    45,    45,
      45,    73,    45,   182,   185,    45,   183,    45,   184,   156,
      45,    45,   159,    45,   161,    45,   187,    68,    69,    70,
      71,    72,   123,    74,    75,    76,    77,    78,    79,    80,
      81,   134,    83,    84,    85,    86,    87,    88,    89,   347,
      71,   334,   369,   218,   311,    45,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,    -1,
       3,     4,     5,     6,     7,    -1,    -1,   128,    11,    -1,
      -1,    14,    -1,    16,    -1,    18,    19,    -1,    -1,    22,
      23,   238,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    11,    -1,    -1,    14,
      -1,    16,    45,    18,    19,    -1,    -1,    22,    23,    13,
      -1,    -1,    -1,    17,    -1,    -1,    20,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    29,    -1,    -1,    71,    -1,
      45,    35,    -1,    37,    -1,    -1,    -1,    -1,    42,    82,
      83,    -1,    -1,    47,    -1,    -1,    89,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      -1,   104,   105,    -1,    -1,    -1,   109,    82,    83,    -1,
      -1,   114,   115,    -1,    89,    -1,    -1,    -1,    -1,    -1,
      95,    -1,    -1,    -1,    -1,    -1,   129,    -1,    92,   104,
     105,    -1,    -1,    -1,   109,    -1,    -1,    -1,   102,   114,
     115,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      11,    -1,    -1,    14,   129,    16,    -1,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,
      71,    72,    -1,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    -1,    -1,    94,    95,    96,    -1,    -1,    99,    -1,
      -1,    -1,    -1,   104,   105,    -1,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    11,    -1,    -1,    14,
      -1,    16,    -1,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    71,    72,    -1,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    -1,    -1,    94,
      95,    96,    -1,    -1,    99,    -1,    -1,    -1,    -1,   104,
     105,    -1,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    11,    -1,    -1,    14,    -1,    16,    -1,    18,
      19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    -1,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,   104,   105,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    -1,     3,     4,     5,     6,     7,    -1,    -1,   128,
      11,    -1,    -1,    14,    -1,    16,    -1,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    11,    -1,    -1,    14,
      -1,    16,    -1,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    -1,    74,    -1,    76,    77,    78,     3,    80,
      81,    82,    -1,    84,    -1,    86,    87,    88,    89,    14,
      15,    16,    -1,    -1,    95,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,   104,   105,    -1,    -1,    82,   109,   110,
     111,   112,   113,   114,   115,    90,    -1,    -1,    -1,    44,
      95,    -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,   104,
     105,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    71,    72,    -1,    74,
      75,    76,    77,    78,    79,    80,    81,     3,    83,    84,
      85,    86,    87,    88,    89,    -1,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,   128,    -1,    -1,    11,    -1,    -1,    14,
      -1,    16,    -1,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    68,    69,    70,    71,    72,    32,    74,    75,
      76,    77,    78,    79,    80,    81,    -1,    83,    84,    85,
      86,    87,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,    -1,    82,    14,    15,
      16,    -1,   128,    -1,    -1,    90,    -1,    -1,    -1,    -1,
      95,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
     105,    -1,   107,   108,   109,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    -1,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    71,    72,    -1,    74,    75,
      76,    77,    78,    79,    80,    81,    15,    83,    84,    85,
      86,    87,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    -1,    74,    75,    76,    77,    78,
      79,    80,    81,    -1,    83,    84,    85,    86,    87,    88,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    11,   128,
      -1,    14,    -1,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    11,    -1,    -1,    14,
      -1,    16,    45,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    11,    -1,    -1,    14,    71,    16,
      45,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    82,
      83,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    -1,    -1,    71,    -1,    45,    -1,
      -1,   104,   105,    -1,    -1,    -1,   109,    82,    83,    -1,
      -1,   114,   115,    -1,    89,    -1,    -1,    -1,    -1,    -1,
      95,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,   104,
     105,    -1,    -1,    -1,   109,    82,    83,    -1,    -1,   114,
     115,    -1,    89,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,    -1,
      -1,    -1,   109,    -1,    -1,    -1,    -1,   114,   115,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    11,    -1,    -1,
      14,    -1,    16,    -1,    18,    19,    -1,    -1,    22,    23,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    11,    -1,
      -1,    14,    -1,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    45,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    11,    -1,    -1,    14,    -1,    16,
      -1,    18,    19,    -1,    -1,    22,    23,    71,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,
      -1,    -1,    -1,    -1,    -1,    89,    -1,    44,    71,    -1,
      -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
     104,   105,    -1,    -1,    -1,   109,    89,    -1,    -1,    -1,
     114,   115,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   104,   105,    -1,    -1,    82,   109,    -1,    -1,    -1,
      -1,   114,   115,    90,    -1,    -1,    -1,    94,    95,    -1,
      -1,    -1,     3,     4,     5,     6,     7,   104,   105,    -1,
      11,    -1,   109,    14,    -1,    16,    -1,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    26,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    11,    -1,    -1,    14,    -1,    16,
      -1,    18,    19,    44,    -1,    22,    23,    -1,    -1,    26,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    11,    -1,
      -1,    14,    15,    16,    -1,    18,    19,    44,    -1,    22,
      23,     3,     4,     5,     6,     7,    -1,    -1,    -1,    11,
      -1,    82,    14,    -1,    16,    -1,    18,    19,    -1,    90,
      22,    23,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    -1,   104,   105,    82,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    90,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,    82,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      82,   104,   105,    -1,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    -1,    -1,    -1,     3,     4,     5,
       6,     7,   104,   105,    -1,    11,    -1,   109,    14,    -1,
      16,    -1,    18,    19,    -1,    -1,    22,    23,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    11,    -1,    -1,    14,
      -1,    16,    -1,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,     3,     4,     5,     6,     7,    32,    -1,    -1,
      11,    -1,    -1,    14,    15,    16,    -1,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    11,    -1,    82,    14,    15,    16,
      -1,    18,    19,    -1,    90,    22,    23,    -1,    -1,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,   104,   105,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
     105,    82,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,   105,    82,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,     3,     4,     5,     6,     7,   104,   105,    -1,
      11,    -1,   109,    14,    -1,    16,    -1,    18,    19,    -1,
      -1,    22,    23,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    11,    -1,    -1,    14,    -1,    16,    -1,    18,    19,
      -1,    -1,    22,    23,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    11,    -1,    -1,    14,    -1,    16,    -1,    18,
      19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,   104,   105,    -1,    -1,    -1,   109,    -1,
      27,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,   104,   105,    -1,    -1,    -1,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,   105,    -1,    -1,    -1,
     109,    68,    69,    70,    71,    72,    -1,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    83,    84,    85,    86,
      87,    88,    89,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    -1,    -1,    -1,    -1,    68,    69,    70,    71,
      72,   128,    74,    75,    76,    77,    78,    79,    80,    81,
      -1,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,    68,    69,    70,    71,    72,   128,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,    -1,    -1,    -1,    68,    69,    70,    71,
      72,   128,    74,    75,    76,    77,    78,    79,    80,    81,
      -1,    83,    84,    85,    86,    87,    88,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,    68,    69,    70,    71,    72,   128,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    83,    84,    85,    86,
      87,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    70,    71,    72,    -1,    74,    -1,    76,    77,
      78,   128,    80,    81,    -1,    -1,    84,    -1,    86,    87,
      88,    89,    -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,    70,    71,
      72,   119,    74,    -1,    76,    77,    78,    -1,    80,    81,
     128,    -1,    84,    -1,    86,    87,    88,    89,    -1,    -1,
      -1,    -1,    94,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,    70,    71,    72,   119,    74,    -1,
      76,    77,    78,    -1,    80,    81,   128,    -1,    84,    -1,
      86,    87,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
      70,    71,    72,   119,    74,    -1,    76,    77,    78,    -1,
      80,    81,   128,    -1,    84,    -1,    86,    87,    88,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    68,    69,    70,    71,    72,    74,    75,    76,    77,
      78,    79,    80,    81,    83,    84,    85,    86,    87,    88,
      89,    99,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   128,   155,   156,   159,   160,   161,   162,   168,
     171,   172,   173,   174,   191,   201,   202,   203,     3,    90,
      14,    14,    14,     3,    14,    16,    32,   157,   158,   175,
     176,   177,   156,   156,     3,    90,   156,   156,   156,     0,
     202,    90,     3,   133,   169,   170,   160,   165,   172,   183,
       3,     4,     5,     6,     7,    11,    14,    16,    18,    19,
      22,    23,    82,    95,   104,   105,   109,   131,   132,   134,
     135,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   154,   183,   154,   175,   114,
     172,   177,   178,    21,    32,    37,    90,   155,   156,   194,
     204,    14,    44,   176,    90,   163,   164,   165,   191,   169,
      37,    21,    94,   165,    14,    44,   177,   184,   185,   165,
      15,   137,   150,   151,   153,   183,    14,   137,   137,    14,
     137,    14,    14,    19,    23,    25,    26,    44,   139,    16,
      28,   101,    18,    22,    34,    41,    33,    36,    39,    40,
       8,    38,    11,    46,    91,    12,    43,    93,    15,    15,
      21,    15,   172,   177,   158,   175,    90,   151,   186,     3,
      32,    94,    96,   107,   108,   120,   121,   122,   123,   124,
     125,   126,   127,   153,   155,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   155,   194,     3,    15,   156,   179,
     180,   181,   182,    16,    45,    83,   151,   178,   163,    94,
     164,    30,    32,   166,   167,   175,    21,    94,   154,    94,
     170,    15,   179,   184,    45,    83,   129,   151,   178,   185,
      14,    44,    13,    17,    20,    24,    29,    35,    37,    42,
      47,    92,   102,   152,    15,    21,    15,   183,   183,   183,
      15,   136,   151,     3,     3,   153,   139,   139,   139,   140,
     140,   141,   141,   142,   142,   142,   142,   143,   143,   144,
     145,   146,   147,   153,   148,     6,    26,    44,   186,   187,
     188,   189,   190,    30,    14,    30,   154,    14,    14,   192,
      14,     3,    32,    32,    32,   153,    32,    94,   196,    14,
     175,   177,   184,    15,    21,    15,    21,    45,   151,   178,
      45,    16,    45,    83,   151,    94,   154,    21,    32,    30,
      94,    15,    15,   151,   178,    45,    45,    45,    83,   151,
      15,   179,    45,    83,   129,   151,   178,   151,   151,    90,
     139,    15,    15,    15,    15,    21,    45,    30,    15,     3,
     154,    21,    94,   186,    37,   190,   192,   153,   192,    30,
     153,   153,   121,   155,   197,    32,    32,    27,   181,     3,
      45,   151,    45,   151,    45,   167,   154,    45,   151,   151,
      45,    15,   151,   178,    45,    45,    45,    83,   151,   187,
     151,   150,    32,    45,    94,   186,   188,    15,   192,    15,
      15,    14,   197,   197,    45,    45,    45,    45,    45,   151,
     151,    45,    21,    94,   186,   192,   192,   192,   153,    15,
     153,    15,   153,    45,    45,    94,    73,    15,   192,    15,
     192,    15,   192,    32,   192,   192
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   130,   131,   131,   131,   131,   132,   132,   132,   133,
     134,   134,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   136,   136,   137,   137,   137,   137,   137,   137,
     137,   138,   138,   138,   138,   138,   138,   139,   139,   140,
     140,   140,   140,   141,   141,   141,   142,   142,   142,   143,
     143,   143,   143,   143,   144,   144,   144,   145,   145,   146,
     146,   147,   147,   148,   148,   149,   149,   150,   150,   151,
     151,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   153,   153,   154,   155,   155,   155,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   157,   157,
     158,   158,   159,   159,   159,   159,   159,   159,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   161,   161,   161,   162,
     162,   163,   163,   164,   164,   164,   165,   165,   165,   165,
     166,   166,   167,   167,   167,   168,   168,   168,   168,   168,
     169,   169,   170,   170,   171,   172,   172,   172,   172,   173,
     173,   174,   174,   175,   175,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   177,
     177,   177,   177,   178,   178,   179,   179,   180,   180,   181,
     181,   181,   182,   182,   183,   183,   184,   184,   184,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     186,   186,   186,   187,   187,   187,   187,   188,   189,   189,
     190,   190,   191,   192,   192,   192,   192,   192,   192,   193,
     193,   193,   194,   194,   195,   195,   196,   196,   197,   197,
     198,   198,   198,   199,   199,   199,   199,   199,   199,   200,
     200,   200,   200,   200,   201,   201,   202,   202,   203,   203,
     204,   204
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     4,     3,     4,     3,     3,     2,     2,
       6,     7,     1,     3,     1,     2,     2,     2,     2,     4,
       4,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     5,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     3,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     5,     2,     1,
       1,     1,     2,     2,     3,     1,     2,     1,     2,     1,
       1,     3,     2,     3,     1,     4,     5,     5,     6,     2,
       1,     3,     3,     1,     4,     1,     1,     1,     1,     1,
       1,     4,     4,     2,     1,     1,     3,     3,     4,     6,
       5,     5,     6,     5,     4,     4,     4,     3,     4,     3,
       2,     2,     1,     1,     2,     3,     1,     1,     3,     2,
       2,     1,     1,     3,     2,     1,     2,     1,     1,     3,
       2,     3,     5,     4,     5,     4,     3,     3,     3,     4,
       6,     5,     5,     6,     4,     4,     2,     3,     3,     4,
       3,     4,     1,     2,     1,     4,     3,     2,     1,     2,
       3,     2,     7,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     2,     3,     1,     2,     1,     1,     1,     2,
       7,     5,     5,     5,     7,     6,     7,     6,     7,     3,
       2,     2,     2,     3,     1,     2,     1,     1,     4,     3,
       1,     2
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const yytype_int8 yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const yytype_int8 yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
};

/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
   in the case of predicates.  */
static const yybool yyimmediate[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const yytype_int8 yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,   158,     0,   251,     0
};




#undef yynerrs
#define yynerrs (yystackp->yyerrcnt)
#undef yychar
#define yychar (yystackp->yyrawchar)
#undef yylval
#define yylval (yystackp->yyval)
#undef yylloc
#define yylloc (yystackp->yyloc)


enum { YYENOMEM = -2 };

typedef enum { yyok, yyaccept, yyabort, yyerr, yynomem } YYRESULTTAG;

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (0)

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#  define YYSTACKEXPANDABLE 1
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (0)
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (0)
#endif

/** State numbers. */
typedef int yy_state_t;

/** Rule numbers. */
typedef int yyRuleNum;

/** Item references. */
typedef short yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState
{
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yyval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yy_state_t yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the last token produced by my symbol */
  YYPTRDIFF_T yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  nonterminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yyval;
  } yysemantics;
};

struct yyGLRStateSet
{
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  YYPTRDIFF_T yysize;
  YYPTRDIFF_T yycapacity;
};

struct yySemanticOption
{
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;


  int yyerrcnt;
  int yyrawchar;
  YYSTYPE yyval;

  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  YYPTRDIFF_T yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

_Noreturn static void
yyFail (yyGLRStack* yystackp, const char* yymsg)
{
  if (yymsg != YY_NULLPTR)
    yyerror (yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

_Noreturn static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

/** Accessing symbol of state YYSTATE.  */
static inline yysymbol_kind_t
yy_accessing_symbol (yy_state_t yystate)
{
  return YY_CAST (yysymbol_kind_t, yystos[yystate]);
}

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
  "Y_LONG_LONG", "'*'", "$accept", "primary_expression", "constant",
  "enumeration_constant", "string", "postfix_expression",
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

/** Left-hand-side symbol for rule #YYRULE.  */
static inline yysymbol_kind_t
yylhsNonterm (yyRuleNum yyrule)
{
  return YY_CAST (yysymbol_kind_t, yyr1[yyrule]);
}

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YY_FPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_FPRINTF_

# define YY_FPRINTF_(Args)                      \
  do {                                          \
    YYFPRINTF Args;                             \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)

# define YY_DPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_DPRINTF_

# define YY_DPRINTF_(Args)                      \
  do {                                          \
    if (yydebug)                                \
      YYFPRINTF Args;                           \
    YY_IGNORE_USELESS_CAST_END                  \
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

# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YY_FPRINTF ((stderr, "%s ", Title));                            \
        yy_symbol_print (stderr, Kind, Value);        \
        YY_FPRINTF ((stderr, "\n"));                                    \
      }                                                                 \
  } while (0)

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule);

# define YY_REDUCE_PRINT(Args)          \
  do {                                  \
    if (yydebug)                        \
      yy_reduce_print Args;             \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

static void yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
  YY_ATTRIBUTE_UNUSED;
static void yypdumpstack (yyGLRStack* yystackp)
  YY_ATTRIBUTE_UNUSED;

#else /* !YYDEBUG */

# define YY_DPRINTF(Args) do {} while (yyfalse)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_REDUCE_PRINT(Args)

#endif /* !YYDEBUG */



/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) YY_ATTRIBUTE_UNUSED;
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
#if YYDEBUG
      yyvsp[i].yystate.yylrState = s->yylrState;
#endif
      yyvsp[i].yystate.yyresolved = s->yyresolved;
      if (s->yyresolved)
        yyvsp[i].yystate.yysemantics.yyval = s->yysemantics.yyval;
      else
        /* The effect of using yyval or yyloc (in an immediate rule) is
         * undefined.  */
        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}


/** If yychar is empty, fetch the next token.  */
static inline yysymbol_kind_t
yygetToken (int *yycharp, yyGLRStack* yystackp)
{
  yysymbol_kind_t yytoken;
  if (*yycharp == YYEMPTY)
    {
      YY_DPRINTF ((stderr, "Reading a token\n"));
      *yycharp = yylex (&yylval);
    }
  if (*yycharp <= END)
    {
      *yycharp = END;
      yytoken = YYSYMBOL_YYEOF;
      YY_DPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (*yycharp);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }
  return yytoken;
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     YY_ATTRIBUTE_UNUSED;
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT, yynomem for YYNOMEM.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyrule, int yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp, YYPTRDIFF_T yyk,
              YYSTYPE* yyvalp)
{
  const yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
  int yylow = 1;
  YY_USE (yyvalp);
  YY_USE (yyk);
  YY_USE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYNOMEM
# define YYNOMEM return yynomem
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, (N), yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yyval;
  /* If yyk == -1, we are running a deferred action on a temporary
     stack.  In that case, YY_REDUCE_PRINT must not play with YYFILL,
     so pretend the stack is "normal". */
  YY_REDUCE_PRINT ((yynormal || yyk == -1, yyvsp, yyk, yyrule));
  switch (yyrule)
    {
  case 2: /* primary_expression: "identifier"  */
#line 180 "c11ansi.y"
                                                { ((*yyvalp).tree) = createCTreeRoot(createTokenLabel((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token))); }
#line 2326 "c11ansi.tab.c"
    break;

  case 3: /* primary_expression: constant  */
#line 181 "c11ansi.y"
                                                { ((*yyvalp).tree) = createCTreeRoot(createTokenLabel((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token))); }
#line 2332 "c11ansi.tab.c"
    break;

  case 4: /* primary_expression: string  */
#line 182 "c11ansi.y"
                                                { ((*yyvalp).tree) = createCTreeRoot(createTokenLabel((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token))); }
#line 2338 "c11ansi.tab.c"
    break;

  case 5: /* primary_expression: Y_LEFT_PAREN expression Y_RIGHT_PAREN  */
#line 183 "c11ansi.y"
                                                { ((*yyvalp).tree) = createCTree1(createConstr2Label(LABCT_PAREN_EXPR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.token), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.tree)); }
#line 2344 "c11ansi.tab.c"
    break;

  case 6: /* constant: "i_const"  */
#line 188 "c11ansi.y"
                                 {((*yyvalp).token) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token);}
#line 2350 "c11ansi.tab.c"
    break;

  case 7: /* constant: "f_const"  */
#line 189 "c11ansi.y"
                                 {((*yyvalp).token) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token);}
#line 2356 "c11ansi.tab.c"
    break;

  case 8: /* constant: Y_ENUMERATION_CONSTANT  */
#line 190 "c11ansi.y"
                                 {((*yyvalp).token) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token);}
#line 2362 "c11ansi.tab.c"
    break;

  case 9: /* enumeration_constant: "identifier"  */
#line 194 "c11ansi.y"
                     {((*yyvalp).token) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token);}
#line 2368 "c11ansi.tab.c"
    break;

  case 10: /* string: "sting_literal"  */
#line 198 "c11ansi.y"
                         {((*yyvalp).token) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token);}
#line 2374 "c11ansi.tab.c"
    break;

  case 11: /* string: Y_FUNC_NAME  */
#line 199 "c11ansi.y"
                         {((*yyvalp).token) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token);}
#line 2380 "c11ansi.tab.c"
    break;

  case 12: /* postfix_expression: primary_expression  */
#line 217 "c11ansi.y"
                                                                                   { ((*yyvalp).tree) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree); }
#line 2386 "c11ansi.tab.c"
    break;

  case 13: /* postfix_expression: postfix_expression Y_LEFT_BRACKET expression Y_RIGHT_BRACKET  */
#line 218 "c11ansi.y"
                                                                                   { ((*yyvalp).tree) = createCTree2(createConstr2Label(LABCT_INDEX, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.token), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.tree),  (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.tree)); }
#line 2392 "c11ansi.tab.c"
    break;

  case 14: /* postfix_expression: postfix_expression Y_LEFT_PAREN Y_RIGHT_PAREN  */
#line 219 "c11ansi.y"
                                                                                   { ((*yyvalp).tree) = createCTree1(createConstr2Label(LABCT_CALL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree)); }
#line 2398 "c11ansi.tab.c"
    break;

  case 15: /* postfix_expression: postfix_expression Y_LEFT_PAREN argument_expression_list Y_RIGHT_PAREN  */
#line 220 "c11ansi.y"
                                                                                   { ((*yyvalp).tree) = createCTree2(createConstr2Label(LABCT_CALL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.token), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.tree)); }
#line 2404 "c11ansi.tab.c"
    break;

  case 16: /* postfix_expression: postfix_expression Y_DOT "identifier"  */
#line 221 "c11ansi.y"
                                                                                   { ((*yyvalp).tree) = createCTree2(createConstr1Label(LABCT_DOT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree), createCTreeRoot(createTokenLabel((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)))); }
#line 2410 "c11ansi.tab.c"
    break;

  case 17: /* postfix_expression: postfix_expression Y_ARROW "identifier"  */
#line 222 "c11ansi.y"
                                                                                   { ((*yyvalp).tree) = createCTree2(createConstr1Label(LABCT_ARROW, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree), createCTreeRoot(createTokenLabel((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)))); }
#line 2416 "c11ansi.tab.c"
    break;

  case 18: /* postfix_expression: postfix_expression Y_PLUS_PLUS  */
#line 223 "c11ansi.y"
                                                                                   { ((*yyvalp).tree) = createCTree1(createConstr1Label(LABCT_PLUS_PLUS, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.tree)); }
#line 2422 "c11ansi.tab.c"
    break;

  case 19: /* postfix_expression: postfix_expression Y_MINUS_MINUS  */
#line 224 "c11ansi.y"
                                                                                   { ((*yyvalp).tree) = createCTree1(createConstr1Label(LABCT_MINUS_MINUS, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.tree)); }
#line 2428 "c11ansi.tab.c"
    break;

  case 20: /* postfix_expression: Y_LEFT_PAREN type_name Y_RIGHT_PAREN Y_LEFT_BRACE initializer_list Y_RIGHT_BRACE  */
#line 225 "c11ansi.y"
                                                                                             { ((*yyvalp).tree) = createCTree2(createConstr4Label(LABCT_CAST_EXPR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.token), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.token), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.token), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.tree)); }
#line 2434 "c11ansi.tab.c"
    break;

  case 21: /* postfix_expression: Y_LEFT_PAREN type_name Y_RIGHT_PAREN Y_LEFT_BRACE initializer_list Y_COMMA Y_RIGHT_BRACE  */
#line 226 "c11ansi.y"
                                                                                                     { ((*yyvalp).tree) = createCTree2(createConstr5Label(LABCT_CAST_EXPR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.token), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.token), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.token), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree)); }
#line 2440 "c11ansi.tab.c"
    break;

  case 22: /* argument_expression_list: assignment_expression  */
#line 230 "c11ansi.y"
                                                                 { ((*yyvalp).tree) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree); }
#line 2446 "c11ansi.tab.c"
    break;

  case 23: /* argument_expression_list: argument_expression_list Y_COMMA assignment_expression  */
#line 231 "c11ansi.y"
                                                                 { ((*yyvalp).tree) = createCTree2(createConstr1Label(LABCT_EXPR_SEPARATOR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2452 "c11ansi.tab.c"
    break;

  case 24: /* unary_expression: postfix_expression  */
#line 235 "c11ansi.y"
                                                          { ((*yyvalp).tree) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree); }
#line 2458 "c11ansi.tab.c"
    break;

  case 25: /* unary_expression: Y_PLUS_PLUS unary_expression  */
#line 236 "c11ansi.y"
                                                          { ((*yyvalp).tree) = createCTree1(createConstr1Label(LABCT_PLUS_PLUS, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2464 "c11ansi.tab.c"
    break;

  case 26: /* unary_expression: Y_MINUS_MINUS unary_expression  */
#line 237 "c11ansi.y"
                                                          { ((*yyvalp).tree) = createCTree1(createConstr1Label(LABCT_MINUS_MINUS, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2470 "c11ansi.tab.c"
    break;

  case 27: /* unary_expression: unary_operator cast_expression  */
#line 238 "c11ansi.y"
                                                          { ((*yyvalp).tree) = createCTree1((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.label), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2476 "c11ansi.tab.c"
    break;

  case 28: /* unary_expression: Y_SIZEOF unary_expression  */
#line 239 "c11ansi.y"
                                                          { ((*yyvalp).tree) = createCTree1(createConstr1Label(LABCT_SIZEOF_EXPR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2482 "c11ansi.tab.c"
    break;

  case 29: /* unary_expression: Y_SIZEOF Y_LEFT_PAREN type_name Y_RIGHT_PAREN  */
#line 240 "c11ansi.y"
                                                          { ((*yyvalp).tree) = createCTree1(createConstr3Label(LABCT_SIZEOF_TYPE, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.token), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.token), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.tree)); }
#line 2488 "c11ansi.tab.c"
    break;

  case 30: /* unary_expression: Y_ALIGNOF Y_LEFT_PAREN type_name Y_RIGHT_PAREN  */
#line 241 "c11ansi.y"
                                                          { ((*yyvalp).tree) = createCTree1(createConstr3Label(LABCT_ALIGNOF_TYPE, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.token), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.token), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.tree)); }
#line 2494 "c11ansi.tab.c"
    break;

  case 31: /* unary_operator: Y_AND  */
#line 245 "c11ansi.y"
                        { ((*yyvalp).label) = createConstr1Label(LABCT_ADDR_OF_VALUE, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)); }
#line 2500 "c11ansi.tab.c"
    break;

  case 32: /* unary_operator: Y_TIMES  */
#line 246 "c11ansi.y"
                        { ((*yyvalp).label) = createConstr1Label(LABCT_VALUE_AT_ADDR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)); }
#line 2506 "c11ansi.tab.c"
    break;

  case 33: /* unary_operator: Y_PLUS  */
#line 247 "c11ansi.y"
                        { ((*yyvalp).label) = createConstr1Label(LABCT_UNARY_PLUS, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)); }
#line 2512 "c11ansi.tab.c"
    break;

  case 34: /* unary_operator: Y_MINUS  */
#line 248 "c11ansi.y"
                        { ((*yyvalp).label) = createConstr1Label(LABCT_UNARY_MINUS, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)); }
#line 2518 "c11ansi.tab.c"
    break;

  case 35: /* unary_operator: Y_TILDE  */
#line 249 "c11ansi.y"
                        { ((*yyvalp).label) = createConstr1Label(LABCT_TILDE, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)); }
#line 2524 "c11ansi.tab.c"
    break;

  case 36: /* unary_operator: Y_EXCLAMATION  */
#line 250 "c11ansi.y"
                        { ((*yyvalp).label) = createConstr1Label(LABCT_EXCLAMATION, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)); }
#line 2530 "c11ansi.tab.c"
    break;

  case 37: /* cast_expression: unary_expression  */
#line 254 "c11ansi.y"
                                                               { ((*yyvalp).tree) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree); }
#line 2536 "c11ansi.tab.c"
    break;

  case 38: /* cast_expression: Y_LEFT_PAREN type_name Y_RIGHT_PAREN cast_expression  */
#line 255 "c11ansi.y"
                                                               { ((*yyvalp).tree) = createCTree2(createConstr2Label(LABCT_CAST_EXPR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.token), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2542 "c11ansi.tab.c"
    break;

  case 39: /* multiplicative_expression: cast_expression  */
#line 259 "c11ansi.y"
                          { ((*yyvalp).tree) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree); }
#line 2548 "c11ansi.tab.c"
    break;

  case 40: /* multiplicative_expression: multiplicative_expression Y_TIMES cast_expression  */
#line 260 "c11ansi.y"
                                                              { ((*yyvalp).tree) = createCTree2(createConstr1Label(LABCT_TIMES, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2554 "c11ansi.tab.c"
    break;

  case 41: /* multiplicative_expression: multiplicative_expression Y_DIVIDE cast_expression  */
#line 261 "c11ansi.y"
                                                              { ((*yyvalp).tree) = createCTree2(createConstr1Label(LABCT_DIVIDE, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2560 "c11ansi.tab.c"
    break;

  case 42: /* multiplicative_expression: multiplicative_expression Y_PERCENT cast_expression  */
#line 262 "c11ansi.y"
                                                              { ((*yyvalp).tree) = createCTree2(createConstr1Label(LABCT_PERCENT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2566 "c11ansi.tab.c"
    break;

  case 43: /* additive_expression: multiplicative_expression  */
#line 266 "c11ansi.y"
                                                                { ((*yyvalp).tree) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree); }
#line 2572 "c11ansi.tab.c"
    break;

  case 44: /* additive_expression: additive_expression Y_PLUS multiplicative_expression  */
#line 267 "c11ansi.y"
                                                                { ((*yyvalp).tree) = createCTree2(createConstr1Label(LABCT_PLUS, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2578 "c11ansi.tab.c"
    break;

  case 45: /* additive_expression: additive_expression Y_MINUS multiplicative_expression  */
#line 268 "c11ansi.y"
                                                                { ((*yyvalp).tree) = createCTree2(createConstr1Label(LABCT_MINUS, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2584 "c11ansi.tab.c"
    break;

  case 46: /* shift_expression: additive_expression  */
#line 272 "c11ansi.y"
                                                         { ((*yyvalp).tree) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree); }
#line 2590 "c11ansi.tab.c"
    break;

  case 47: /* shift_expression: shift_expression Y_RSHIFT additive_expression  */
#line 273 "c11ansi.y"
                                                         { ((*yyvalp).tree) = createCTree2(createConstr1Label(LABCT_TIMES, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2596 "c11ansi.tab.c"
    break;

  case 48: /* shift_expression: shift_expression Y_LSHIFT additive_expression  */
#line 274 "c11ansi.y"
                                                         { ((*yyvalp).tree) = createCTree2(createConstr1Label(LABCT_TIMES, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2602 "c11ansi.tab.c"
    break;

  case 49: /* relational_expression: shift_expression  */
#line 278 "c11ansi.y"
                                                      { ((*yyvalp).tree) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree); }
#line 2608 "c11ansi.tab.c"
    break;

  case 50: /* relational_expression: relational_expression Y_LT shift_expression  */
#line 279 "c11ansi.y"
                                                      { ((*yyvalp).tree) = createCTree2(createConstr1Label(LABCT_LT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2614 "c11ansi.tab.c"
    break;

  case 51: /* relational_expression: relational_expression Y_GT shift_expression  */
#line 280 "c11ansi.y"
                                                      { ((*yyvalp).tree) = createCTree2(createConstr1Label(LABCT_GT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2620 "c11ansi.tab.c"
    break;

  case 52: /* relational_expression: relational_expression Y_LE shift_expression  */
#line 281 "c11ansi.y"
                                                      { ((*yyvalp).tree) = createCTree2(createConstr1Label(LABCT_LE, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2626 "c11ansi.tab.c"
    break;

  case 53: /* relational_expression: relational_expression Y_GE shift_expression  */
#line 282 "c11ansi.y"
                                                      { ((*yyvalp).tree) = createCTree2(createConstr1Label(LABCT_GE, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2632 "c11ansi.tab.c"
    break;

  case 54: /* equality_expression: relational_expression  */
#line 286 "c11ansi.y"
                                                         { ((*yyvalp).tree) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree); }
#line 2638 "c11ansi.tab.c"
    break;

  case 55: /* equality_expression: equality_expression Y_EQ relational_expression  */
#line 287 "c11ansi.y"
                                                         { ((*yyvalp).tree) = createCTree2(createConstr1Label(LABCT_EQ, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2644 "c11ansi.tab.c"
    break;

  case 56: /* equality_expression: equality_expression Y_NE relational_expression  */
#line 288 "c11ansi.y"
                                                         { ((*yyvalp).tree) = createCTree2(createConstr1Label(LABCT_NE, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2650 "c11ansi.tab.c"
    break;

  case 57: /* and_expression: equality_expression  */
#line 292 "c11ansi.y"
                                                   { ((*yyvalp).tree) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree); }
#line 2656 "c11ansi.tab.c"
    break;

  case 58: /* and_expression: and_expression Y_AND equality_expression  */
#line 293 "c11ansi.y"
                                                   { ((*yyvalp).tree) = createCTree2(createConstr1Label(LABCT_AND, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2662 "c11ansi.tab.c"
    break;

  case 59: /* exclusive_or_expression: and_expression  */
#line 297 "c11ansi.y"
                                                       { ((*yyvalp).tree) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree); }
#line 2668 "c11ansi.tab.c"
    break;

  case 60: /* exclusive_or_expression: exclusive_or_expression Y_XOR and_expression  */
#line 298 "c11ansi.y"
                                                       { ((*yyvalp).tree) = createCTree2(createConstr1Label(LABCT_XOR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2674 "c11ansi.tab.c"
    break;

  case 61: /* inclusive_or_expression: exclusive_or_expression  */
#line 302 "c11ansi.y"
                                                               { ((*yyvalp).tree) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree); }
#line 2680 "c11ansi.tab.c"
    break;

  case 62: /* inclusive_or_expression: inclusive_or_expression Y_OR exclusive_or_expression  */
#line 303 "c11ansi.y"
                                                               { ((*yyvalp).tree) = createCTree2(createConstr1Label(LABCT_OR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2686 "c11ansi.tab.c"
    break;

  case 63: /* logical_and_expression: inclusive_or_expression  */
#line 307 "c11ansi.y"
                                                                    { ((*yyvalp).tree) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree); }
#line 2692 "c11ansi.tab.c"
    break;

  case 64: /* logical_and_expression: logical_and_expression Y_AND_AND inclusive_or_expression  */
#line 308 "c11ansi.y"
                                                                    { ((*yyvalp).tree) = createCTree2(createConstr1Label(LABCT_AND_AND, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2698 "c11ansi.tab.c"
    break;

  case 65: /* logical_or_expression: logical_and_expression  */
#line 312 "c11ansi.y"
                                                                { ((*yyvalp).tree) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree); }
#line 2704 "c11ansi.tab.c"
    break;

  case 66: /* logical_or_expression: logical_or_expression Y_OR_OR logical_and_expression  */
#line 313 "c11ansi.y"
                                                                { ((*yyvalp).tree) = createCTree2(createConstr1Label(LABCT_OR_OR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2710 "c11ansi.tab.c"
    break;

  case 67: /* conditional_expression: logical_or_expression  */
#line 317 "c11ansi.y"
                                { ((*yyvalp).tree) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree); }
#line 2716 "c11ansi.tab.c"
    break;

  case 68: /* conditional_expression: logical_or_expression Y_QUESTION expression Y_COLON conditional_expression  */
#line 318 "c11ansi.y"
                                                                                     { ((*yyvalp).tree) = createCTree2(createConstr1Label(LABCT_QUESTION, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.tree), createCTree2(createConstr1Label(LABCT_COLON, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree))); }
#line 2722 "c11ansi.tab.c"
    break;

  case 69: /* assignment_expression: conditional_expression  */
#line 322 "c11ansi.y"
                                                                      { ((*yyvalp).tree) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree); }
#line 2728 "c11ansi.tab.c"
    break;

  case 70: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 323 "c11ansi.y"
                                                                      { ((*yyvalp).tree) = createCTree2((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.label), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2734 "c11ansi.tab.c"
    break;

  case 71: /* assignment_operator: Y_EQUAL  */
#line 327 "c11ansi.y"
                           { ((*yyvalp).label) = createConstr1Label(LABCT_EQ, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)); }
#line 2740 "c11ansi.tab.c"
    break;

  case 72: /* assignment_operator: Y_TIMES_EQUAL  */
#line 328 "c11ansi.y"
                           { ((*yyvalp).label) = createConstr1Label(LABCT_TIMES_EQUAL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)); }
#line 2746 "c11ansi.tab.c"
    break;

  case 73: /* assignment_operator: Y_DIVIDE_EQUAL  */
#line 329 "c11ansi.y"
                           { ((*yyvalp).label) = createConstr1Label(LABCT_DIVIDE_EQUAL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)); }
#line 2752 "c11ansi.tab.c"
    break;

  case 74: /* assignment_operator: Y_PERCENT_EQUAL  */
#line 330 "c11ansi.y"
                           { ((*yyvalp).label) = createConstr1Label(LABCT_PERCENT_EQUAL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)); }
#line 2758 "c11ansi.tab.c"
    break;

  case 75: /* assignment_operator: Y_PLUS_EQUAL  */
#line 331 "c11ansi.y"
                           { ((*yyvalp).label) = createConstr1Label(LABCT_PLUS_EQUAL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)); }
#line 2764 "c11ansi.tab.c"
    break;

  case 76: /* assignment_operator: Y_MINUS_EQUAL  */
#line 332 "c11ansi.y"
                           { ((*yyvalp).label) = createConstr1Label(LABCT_MINUS_EQUAL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)); }
#line 2770 "c11ansi.tab.c"
    break;

  case 77: /* assignment_operator: Y_LSHIFT_EQUAL  */
#line 333 "c11ansi.y"
                           { ((*yyvalp).label) = createConstr1Label(LABCT_LSHIFT_EQUAL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)); }
#line 2776 "c11ansi.tab.c"
    break;

  case 78: /* assignment_operator: Y_RSHIFT_EQUAL  */
#line 334 "c11ansi.y"
                           { ((*yyvalp).label) = createConstr1Label(LABCT_RSHIFT_EQUAL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)); }
#line 2782 "c11ansi.tab.c"
    break;

  case 79: /* assignment_operator: Y_AND_EQUAL  */
#line 335 "c11ansi.y"
                           { ((*yyvalp).label) = createConstr1Label(LABCT_AND_EQUAL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)); }
#line 2788 "c11ansi.tab.c"
    break;

  case 80: /* assignment_operator: Y_XOR_EQUAL  */
#line 336 "c11ansi.y"
                           { ((*yyvalp).label) = createConstr1Label(LABCT_XOR_EQUAL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)); }
#line 2794 "c11ansi.tab.c"
    break;

  case 81: /* assignment_operator: Y_OR_EQUAL  */
#line 337 "c11ansi.y"
                           { ((*yyvalp).label) = createConstr1Label(LABCT_OR_EQUAL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)); }
#line 2800 "c11ansi.tab.c"
    break;

  case 82: /* expression: assignment_expression  */
#line 341 "c11ansi.y"
                                                   { ((*yyvalp).tree) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree); }
#line 2806 "c11ansi.tab.c"
    break;

  case 83: /* expression: expression Y_COMMA assignment_expression  */
#line 342 "c11ansi.y"
                                                   { ((*yyvalp).tree) = createCTree2(createConstr1Label(LABCT_EXPR_SEPARATOR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2812 "c11ansi.tab.c"
    break;

  case 84: /* constant_expression: conditional_expression  */
#line 346 "c11ansi.y"
                                  { ((*yyvalp).tree) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree); }
#line 2818 "c11ansi.tab.c"
    break;

  case 85: /* declaration: declaration_specifiers Y_SEMICOLON  */
#line 350 "c11ansi.y"
                                                                   { ((*yyvalp).declList) = transformDecl((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.dinfo)); zapToken((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)); }
#line 2824 "c11ansi.tab.c"
    break;

  case 86: /* declaration: declaration_specifiers init_declarator_list Y_SEMICOLON  */
#line 351 "c11ansi.y"
                                                                   { ((*yyvalp).declList) = transformDecl(addDeclInfoDclrList((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.dinfo), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.dclrList))); zapToken((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)); }
#line 2830 "c11ansi.tab.c"
    break;

  case 220: /* initializer: Y_LEFT_BRACE initializer_list Y_RIGHT_BRACE  */
#line 579 "c11ansi.y"
                                                              { ((*yyvalp).tree) = createCTree1(createConstr2Label(LABCT_EXPR_LIST, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.token), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.tree)); }
#line 2836 "c11ansi.tab.c"
    break;

  case 221: /* initializer: Y_LEFT_BRACE initializer_list Y_COMMA Y_RIGHT_BRACE  */
#line 580 "c11ansi.y"
                                                              { ((*yyvalp).tree) = createCTree1(createConstr3Label(LABCT_EXPR_LIST, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.token), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree)); }
#line 2842 "c11ansi.tab.c"
    break;

  case 222: /* initializer: assignment_expression  */
#line 581 "c11ansi.y"
                                                              { ((*yyvalp).tree) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree); }
#line 2848 "c11ansi.tab.c"
    break;

  case 223: /* initializer_list: designation initializer  */
#line 585 "c11ansi.y"
                                                            { ((*yyvalp).tree) = createCTree2(createConstr0Label(LABCT_EXPR_LIST), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2854 "c11ansi.tab.c"
    break;

  case 224: /* initializer_list: initializer  */
#line 586 "c11ansi.y"
                                                            { ((*yyvalp).tree) = createCTree1(createConstr0Label(LABCT_EXPR_LIST), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2860 "c11ansi.tab.c"
    break;

  case 225: /* initializer_list: initializer_list Y_COMMA designation initializer  */
#line 587 "c11ansi.y"
                                                            { ((*yyvalp).tree) = createCTree2(createConstr1Label(LABCT_EXPR_LIST, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.tree), createCTree1(createConstr0Label(LABCT_EXPR_LIST), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.tree))); }
#line 2866 "c11ansi.tab.c"
    break;

  case 226: /* initializer_list: initializer_list Y_COMMA initializer  */
#line 588 "c11ansi.y"
                                                            { ((*yyvalp).tree) = createCTree2(createConstr1Label(LABCT_EXPR_LIST, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.tree), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.tree)); }
#line 2872 "c11ansi.tab.c"
    break;

  case 259: /* jump_statement: Y_GOTO "identifier" Y_SEMICOLON  */
#line 660 "c11ansi.y"
                                           { printf("jump_statement -> Y_GOTO IDENTIFIER Y_SEMICOLON\n"); }
#line 2878 "c11ansi.tab.c"
    break;

  case 260: /* jump_statement: Y_CONTINUE Y_SEMICOLON  */
#line 661 "c11ansi.y"
                                           { printf("jump_statement -> Y_CONTINUE Y_SEMICOLON\n"); }
#line 2884 "c11ansi.tab.c"
    break;

  case 261: /* jump_statement: Y_BREAK Y_SEMICOLON  */
#line 662 "c11ansi.y"
                                           { printf("jump_statement -> Y_BREAK Y_SEMICOLON\n"); }
#line 2890 "c11ansi.tab.c"
    break;

  case 262: /* jump_statement: Y_RETURN Y_SEMICOLON  */
#line 663 "c11ansi.y"
                                           { printf("jump_statement -> Y_RETURN Y_SEMICOLON\n"); }
#line 2896 "c11ansi.tab.c"
    break;

  case 263: /* jump_statement: Y_RETURN expression Y_SEMICOLON  */
#line 664 "c11ansi.y"
                                           { printf("jump_statement -> Y_RETURN expression Y_SEMICOLON\n"); }
#line 2902 "c11ansi.tab.c"
    break;

  case 264: /* translation_unit: external_declaration  */
#line 668 "c11ansi.y"
                                                 { printf("translation_unit -> external_declaration\n\n"); }
#line 2908 "c11ansi.tab.c"
    break;

  case 265: /* translation_unit: translation_unit external_declaration  */
#line 669 "c11ansi.y"
                                                 { printf("translation_unit -> translation_unit external_declaration\n\n"); }
#line 2914 "c11ansi.tab.c"
    break;

  case 266: /* external_declaration: function_definition  */
#line 673 "c11ansi.y"
                                { printf("external_declaration -> function_definition\n"); }
#line 2920 "c11ansi.tab.c"
    break;

  case 267: /* external_declaration: declaration  */
#line 674 "c11ansi.y"
                                { printf("external_declaration -> declaration\n"); }
#line 2926 "c11ansi.tab.c"
    break;

  case 268: /* function_definition: declaration_specifiers declarator declaration_list compound_statement  */
#line 678 "c11ansi.y"
                                                                                   { printf("function_definition -> declaration_specifiers declarator declaration_list compound_statement\n"); }
#line 2932 "c11ansi.tab.c"
    break;

  case 269: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 679 "c11ansi.y"
                                                                                   { printf("function_definition -> declaration_specifiers declarator compound_statement\n"); }
#line 2938 "c11ansi.tab.c"
    break;


#line 2942 "c11ansi.tab.c"

      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yylhsNonterm (yyrule), yyvalp, yylocp);

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYNOMEM
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YY_USE (yy0);
  YY_USE (yy1);

  switch (yyn)
    {

      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

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

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yy_accessing_symbol (yys->yylrState),
                &yys->yysemantics.yyval);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YY_FPRINTF ((stderr, "%s unresolved", yymsg));
          else
            YY_FPRINTF ((stderr, "%s incomplete", yymsg));
          YY_SYMBOL_PRINT ("", yy_accessing_symbol (yys->yylrState), YY_NULLPTR, &yys->yyloc);
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh);
        }
    }
}

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

/** True iff LR state YYSTATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yy_state_t yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for YYSTATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yy_state_t yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yyn) \
  0

/** The action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
 *  of conflicting reductions.
 */
static inline int
yygetLRActions (yy_state_t yystate, yysymbol_kind_t yytoken, const short** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yytoken == YYSYMBOL_YYerror)
    {
      // This is the error token.
      *yyconflicts = yyconfl;
      return 0;
    }
  else if (yyisDefaultedState (yystate)
           || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyconflicts = yyconfl;
      return -yydefact[yystate];
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return yytable[yyindex];
    }
  else
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return 0;
    }
}

/** Compute post-reduction state.
 * \param yystate   the current state
 * \param yysym     the nonterminal to push on the stack
 */
static inline yy_state_t
yyLRgotoState (yy_state_t yystate, yysymbol_kind_t yysym)
{
  int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yysym - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
 *  if YYISSTATE, and otherwise a semantic option.  Callers should call
 *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 *  headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  YYRULE on the semantic values in YYRHS to the list of
 *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
 *  stack #YYK of *YYSTACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyGLRState* yystate,
                     yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  YY_ASSERT (!yynewOption->yyisState);
  yynewOption->yystate = yyrhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize YYSET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates
    = YY_CAST (yyGLRState**,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yystates[0]));
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULLPTR;
  yyset->yylookaheadNeeds
    = YY_CAST (yybool*,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yylookaheadNeeds[0]));
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  memset (yyset->yylookaheadNeeds,
          0,
          YY_CAST (YYSIZE_T, yyset->yycapacity) * sizeof yyset->yylookaheadNeeds[0]);
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize *YYSTACKP to a single empty stack, with total maximum
 *  capacity for all stacks of YYSIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, YYPTRDIFF_T yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yysize)
                         * sizeof yystackp->yynextFree[0]));
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS, YYTOITEMS, YYX, YYTYPE)                   \
  &((YYTOITEMS)                                                         \
    - ((YYFROMITEMS) - YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX))))->YYTYPE

/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  YYPTRDIFF_T yynewSize;
  YYPTRDIFF_T yyn;
  YYPTRDIFF_T yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yynewSize)
                         * sizeof yynewItems[0]));
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*YY_REINTERPRET_CAST (yybool *, yyp0))
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULLPTR)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULLPTR)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULLPTR)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULLPTR)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULLPTR)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                      yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULLPTR)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
 *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
 *  YYS.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULLPTR && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #YYK in *YYSTACKP.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULLPTR;
}

/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
    only be done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULLPTR || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YY_DPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULLPTR;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  YYPTRDIFF_T yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
        {
          if (yyi == yyj)
            YY_DPRINTF ((stderr, "Removing dead stacks.\n"));
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            YY_DPRINTF ((stderr, "Rename stack %ld -> %ld.\n",
                        YY_CAST (long, yyi), YY_CAST (long, yyj)));
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
 * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
 * value *YYVALP and source location *YYLOCP.  */
static inline void
yyglrShift (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
            YYPTRDIFF_T yyposn,
            YYSTYPE* yyvalp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyval = *yyvalp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
                 YYPTRDIFF_T yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
  YY_ASSERT (yynewState->yyisState);

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULLPTR;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
}

#if YYDEBUG

/*----------------------------------------------------------------------.
| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
`----------------------------------------------------------------------*/

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule)
{
  int yynrhs = yyrhsLength (yyrule);
  int yyi;
  YY_FPRINTF ((stderr, "Reducing stack %ld by rule %d (line %d):\n",
               YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
  if (! yynormal)
    yyfillin (yyvsp, 1, -yynrhs);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YY_FPRINTF ((stderr, "   $%d = ", yyi + 1));
      yy_symbol_print (stderr,
                       yy_accessing_symbol (yyvsp[yyi - yynrhs + 1].yystate.yylrState),
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yyval                       );
      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
        YY_FPRINTF ((stderr, " (unresolved)"));
      YY_FPRINTF ((stderr, "\n"));
    }
}
#endif

/** Pop the symbols consumed by reduction #YYRULE from the top of stack
 *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *YYVALP to the resulting value,
 *  and *YYLOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* yyrhs
        = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yytops.yystates[yyk]);
      YY_ASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp, yyk,
                           yyvalp);
    }
  else
    {
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yyGLRState* yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      int yyi;
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyk, yyvalp);
    }
}

/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with YYRULE and store its value with the
 *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #YYK from
 *  *YYSTACKP.  In this case, the semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
             yybool yyforceEval)
{
  YYPTRDIFF_T yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYSTYPE yyval;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yyval);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
        YY_DPRINTF ((stderr,
                     "Parse on stack %ld rejected by rule %d (line %d).\n",
                     YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
      if (yyflag != yyok)
        return yyflag;
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yyval);
    }
  else
    {
      YYPTRDIFF_T yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yy_state_t yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YY_DPRINTF ((stderr,
                   "Reduced stack %ld by rule %d (line %d); action deferred.  "
                   "Now in state %d.\n",
                   YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule],
                   yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YY_DPRINTF ((stderr, "Merging stack %ld into stack %ld.\n",
                                 YY_CAST (long, yyk), YY_CAST (long, yyi)));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static YYPTRDIFF_T
yysplitStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      YY_ASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yycapacity <= yystackp->yytops.yysize)
    {
      YYPTRDIFF_T state_size = YYSIZEOF (yystackp->yytops.yystates[0]);
      YYPTRDIFF_T half_max_capacity = YYSIZE_MAXIMUM / 2 / state_size;
      if (half_max_capacity < yystackp->yytops.yycapacity)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      {
        yyGLRState** yynewStates
          = YY_CAST (yyGLRState**,
                     YYREALLOC (yystackp->yytops.yystates,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewStates[0])));
        if (yynewStates == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yystates = yynewStates;
      }

      {
        yybool* yynewLookaheadNeeds
          = YY_CAST (yybool*,
                     YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewLookaheadNeeds[0])));
        if (yynewLookaheadNeeds == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
      }
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize - 1;
}

/** True iff YYY0 and YYY1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
 *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       0 < yyn;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yyval = yys0->yysemantics.yyval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yyval = yys1->yysemantics.yyval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (yytrue)
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULLPTR)
                break;
              else if (*yyz0p == YY_NULLPTR)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp)
{
  if (0 < yyn)
    {
      YY_ASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp));
    }
  return yyok;
}

/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
 *  user action, and return the semantic value and location in *YYVALP
 *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
 *  have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, -1, yyvalp);
    yychar = yychar_current;
    yylval = yylval_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULLPTR)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, empty>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1));
  else
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, tokens %ld .. %ld>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1, YY_CAST (long, yys->yyposn + 1),
                 YY_CAST (long, yyx->yystate->yyposn)));
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YY_FPRINTF ((stderr, "%*s%s <empty>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState))));
          else
            YY_FPRINTF ((stderr, "%*s%s <tokens %ld .. %ld>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState)),
                         YY_CAST (long, yystates[yyi-1]->yyposn + 1),
                         YY_CAST (long, yystates[yyi]->yyposn)));
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1)
{
  YY_USE (yyx0);
  YY_USE (yyx1);

#if YYDEBUG
  YY_FPRINTF ((stderr, "Ambiguity detected.\n"));
  YY_FPRINTF ((stderr, "Option 1,\n"));
  yyreportTree (yyx0, 2);
  YY_FPRINTF ((stderr, "\nOption 2,\n"));
  yyreportTree (yyx1, 2);
  YY_FPRINTF ((stderr, "\n"));
#endif

  yyerror (YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
 *  perform the indicated actions, and set the semantic value of YYS.
 *  If result != yyok, the chain of semantic options in YYS has been
 *  cleared instead or it has been left unmodified except that
 *  redundant options may have been removed.  Regardless of whether
 *  result = yyok, YYS has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yyval;
  YYRESULTTAG yyflag;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULLPTR; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              return yyreportAmbiguity (yybest, yyp);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YY_ASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yyval);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yyval_other;
                yyflag = yyresolveAction (yyp, yystackp, &yyval_other);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yy_accessing_symbol (yys->yylrState),
                                &yyval);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yyval, &yyval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yyval);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yyval = yyval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULLPTR;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp)
{
  if (yystackp->yysplitPoint != YY_NULLPTR)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             ));
    }
  return yyok;
}

/** Called when returning to deterministic operation to clean up the extra
 * stacks. */
static void
yycompressStack (yyGLRStack* yystackp)
{
  /* yyr is the state after the split point.  */
  yyGLRState *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
    return;

  {
    yyGLRState *yyp, *yyq;
    for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
         yyp != yystackp->yysplitPoint;
         yyr = yyp, yyp = yyq, yyq = yyp->yypred)
      yyp->yypred = yyr;
  }

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;

  while (yyr != YY_NULLPTR)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk,
                   YYPTRDIFF_T yyposn)
{
  while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    {
      yy_state_t yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YY_DPRINTF ((stderr, "Stack %ld Entering state %d\n",
                   YY_CAST (long, yyk), yystate));

      YY_ASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          YYRESULTTAG yyflag;
          yyRuleNum yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule]);
          if (yyflag == yyerr)
            {
              YY_DPRINTF ((stderr,
                           "Stack %ld dies "
                           "(predicate failure or explicit user error).\n",
                           YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          if (yyflag != yyok)
            return yyflag;
        }
      else
        {
          yysymbol_kind_t yytoken = yygetToken (&yychar, yystackp);
          const short* yyconflicts;
          const int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;

          for (/* nothing */; *yyconflicts; yyconflicts += 1)
            {
              YYRESULTTAG yyflag;
              YYPTRDIFF_T yynewStack = yysplitStack (yystackp, yyk);
              YY_DPRINTF ((stderr, "Splitting off stack %ld from %ld.\n",
                           YY_CAST (long, yynewStack), YY_CAST (long, yyk)));
              yyflag = yyglrReduce (yystackp, yynewStack,
                                    *yyconflicts,
                                    yyimmediate[*yyconflicts]);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn));
              else if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yynewStack)));
                  yymarkStackDeleted (yystackp, yynewStack);
                }
              else
                return yyflag;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            {
              YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
                                                yyimmediate[-yyaction]);
              if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr,
                               "Stack %ld dies "
                               "(predicate failure or explicit user error).\n",
                               YY_CAST (long, yyk)));
                  yymarkStackDeleted (yystackp, yyk);
                  break;
                }
              else if (yyflag != yyok)
                return yyflag;
            }
        }
    }
  return yyok;
}






static void
yyreportSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState != 0)
    return;
  yyerror (YY_("syntax error"));
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yysymbol_kind_t yytoken;
        int yyj;
        if (yychar == END)
          yyFail (yystackp, YY_NULLPTR);
        if (yychar != YYEMPTY)
          {
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval);
            yychar = YYEMPTY;
          }
        yytoken = yygetToken (&yychar, yystackp);
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  {
    YYPTRDIFF_T yyk;
    for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
      if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
        break;
    if (yyk >= yystackp->yytops.yysize)
      yyFail (yystackp, YY_NULLPTR);
    for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
      yymarkStackDeleted (yystackp, yyk);
    yyremoveDeletes (yystackp);
    yycompressStack (yystackp);
  }

  /* Pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULLPTR)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      int yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYSYMBOL_YYerror;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYSYMBOL_YYerror
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              int yyaction = yytable[yyj];
              YY_SYMBOL_PRINT ("Shifting", yy_accessing_symbol (yyaction),
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yyaction,
                          yys->yyposn, &yylval);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      if (yys->yypred != YY_NULLPTR)
        yydestroyGLRState ("Error: popping", yys);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
    yyFail (yystackp, YY_NULLPTR);
}

#define YYCHK1(YYE)                             \
  do {                                          \
    switch (YYE) {                              \
    case yyok:     break;                       \
    case yyabort:  goto yyabortlab;             \
    case yyaccept: goto yyacceptlab;            \
    case yyerr:    goto yyuser_error;           \
    case yynomem:  goto yyexhaustedlab;         \
    default:       goto yybuglab;               \
    }                                           \
  } while (0)

/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  YYPTRDIFF_T yyposn;

  YY_DPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;

  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode. */
      while (yytrue)
        {
          yy_state_t yystate = yystack.yytops.yystates[0]->yylrState;
          YY_DPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyRuleNum yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {
                  yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue));
            }
          else
            {
              yysymbol_kind_t yytoken = yygetToken (&yychar, yystackp);
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
              if (*yyconflicts)
                /* Enter nondeterministic mode.  */
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {
                  /* Issue an error message unless the scanner already
                     did. */
                  if (yychar != YYerror)
                    yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue));
            }
        }

      /* Nondeterministic mode. */
      while (yytrue)
        {
          yysymbol_kind_t yytoken_to_shift;
          YYPTRDIFF_T yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yyreportSyntaxError (&yystack);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              yy_state_t yystate = yystack.yytops.yystates[yys]->yylrState;
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken_to_shift,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YY_DPRINTF ((stderr, "On stack %ld, ", YY_CAST (long, yys)));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval);
              YY_DPRINTF ((stderr, "Stack %ld now in state %d\n",
                           YY_CAST (long, yys),
                           yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;

 yybuglab:
  YY_ASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturnlab;

 yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;

 yyreturnlab:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          YYPTRDIFF_T yysize = yystack.yytops.yysize;
          YYPTRDIFF_T yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                    if (yys->yypred != YY_NULLPTR)
                      yydestroyGLRState ("Cleanup: popping", yys);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#if YYDEBUG
/* Print *YYS and its predecessors. */
static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YY_FPRINTF ((stderr, " -> "));
    }
  YY_FPRINTF ((stderr, "%d@%ld", yys->yylrState, YY_CAST (long, yys->yyposn)));
}

/* Print YYS (possibly NULL) and its predecessors. */
static void
yypstates (yyGLRState* yys)
{
  if (yys == YY_NULLPTR)
    YY_FPRINTF ((stderr, "<null>"));
  else
    yy_yypstack (yys);
  YY_FPRINTF ((stderr, "\n"));
}

/* Print the stack #YYK.  */
static void
yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

/* Print all the stacks.  */
static void
yypdumpstack (yyGLRStack* yystackp)
{
#define YYINDEX(YYX)                                                    \
  YY_CAST (long,                                                        \
           ((YYX)                                                       \
            ? YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX)) - yystackp->yyitems \
            : -1))

  yyGLRStackItem* yyp;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YY_FPRINTF ((stderr, "%3ld. ",
                   YY_CAST (long, yyp - yystackp->yyitems)));
      if (*YY_REINTERPRET_CAST (yybool *, yyp))
        {
          YY_ASSERT (yyp->yystate.yyisState);
          YY_ASSERT (yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Res: %d, LR State: %d, posn: %ld, pred: %ld",
                       yyp->yystate.yyresolved, yyp->yystate.yylrState,
                       YY_CAST (long, yyp->yystate.yyposn),
                       YYINDEX (yyp->yystate.yypred)));
          if (! yyp->yystate.yyresolved)
            YY_FPRINTF ((stderr, ", firstVal: %ld",
                         YYINDEX (yyp->yystate.yysemantics.yyfirstVal)));
        }
      else
        {
          YY_ASSERT (!yyp->yystate.yyisState);
          YY_ASSERT (!yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Option. rule: %d, state: %ld, next: %ld",
                       yyp->yyoption.yyrule - 1,
                       YYINDEX (yyp->yyoption.yystate),
                       YYINDEX (yyp->yyoption.yynext)));
        }
      YY_FPRINTF ((stderr, "\n"));
    }

  YY_FPRINTF ((stderr, "Tops:"));
  {
    YYPTRDIFF_T yyi;
    for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
      YY_FPRINTF ((stderr, "%ld: %ld; ", YY_CAST (long, yyi),
                   YYINDEX (yystackp->yytops.yystates[yyi])));
    YY_FPRINTF ((stderr, "\n"));
  }
#undef YYINDEX
}
#endif

#undef yylval
#undef yychar
#undef yynerrs




#line 688 "c11ansi.y"

#include <stdio.h>

extern char * yytext;
extern int yylineno;

int yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** Line %d %s %s\n", yylineno, s, yytext);
	return 0;
}
