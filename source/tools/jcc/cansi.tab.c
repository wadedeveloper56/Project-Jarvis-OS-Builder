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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "cansi.y"

#include <stdlib.h>
#include <stdio.h>
#include "wic.h"

int yyerror(const char *s);
int yylex();

#line 80 "cansi.tab.c"

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

#include "cansi.tab.h"
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
#define YYLAST   2753

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  130
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  78
/* YYNRULES -- Number of rules.  */
#define YYNRULES  277
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  482

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
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   145,   145,   146,   147,   148,   149,   153,   154,   155,
     159,   163,   164,   168,   172,   173,   177,   178,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   195,   196,
     200,   201,   202,   203,   204,   205,   206,   210,   211,   212,
     213,   214,   215,   219,   220,   224,   225,   226,   227,   231,
     232,   233,   237,   238,   239,   243,   244,   245,   246,   247,
     251,   252,   253,   257,   258,   262,   263,   267,   268,   272,
     273,   277,   278,   282,   283,   287,   288,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   306,   307,
     311,   315,   316,   317,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   334,   335,   339,   340,   344,   345,
     346,   347,   348,   349,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   374,   375,   376,   380,   381,   385,   386,   390,
     391,   392,   396,   397,   398,   399,   403,   404,   408,   409,
     410,   414,   415,   416,   417,   418,   422,   423,   427,   428,
     432,   436,   437,   438,   439,   443,   444,   448,   449,   453,
     454,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   475,   476,   477,   478,   482,
     483,   488,   489,   493,   494,   498,   499,   500,   504,   505,
     509,   510,   514,   515,   516,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   544,   545,   546,   550,
     551,   552,   553,   557,   561,   562,   566,   567,   571,   575,
     576,   577,   578,   579,   580,   584,   585,   586,   590,   591,
     595,   596,   600,   601,   605,   606,   610,   611,   612,   616,
     617,   618,   619,   620,   621,   625,   626,   627,   628,   629,
     633,   634,   638,   639,   643,   644,   648,   649
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
  "Y_LONG_LONG", "'*'", "$accept", "primary_expression", "constant",
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
    2337,  -363,  -363,  -363,  -363,  -363,    14,  -363,  -363,  -363,
    -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,
    -363,  -363,  -363,  -363,  -363,  -363,    27,  -363,  -363,  -363,
      41,    48,  -363,  -363,   259,  2392,  2392,  -363,    49,  -363,
    -363,  2392,  2392,  2392,  -363,   423,  -363,  -363,    -9,   102,
    2625,  1053,  2034,  -363,    53,    69,  -363,    26,  -363,  2227,
     142,    47,  -363,  -363,    42,  2533,  -363,  -363,  -363,  -363,
    -363,   102,  -363,   110,    16,  -363,  2625,   162,  2625,   154,
    -363,  -363,  -363,  -363,  -363,  -363,  1053,  -363,  -363,  2101,
    -363,  2101,  2130,  -363,  -363,  -363,   158,   175,  -363,  -363,
    -363,  -363,   198,  -363,  2034,  -363,    37,   219,     8,   286,
     165,   183,   133,    91,   208,   -23,  -363,   192,   210,   189,
     213,  -363,  -363,  -363,    69,    53,  -363,  1079,   683,  -363,
     259,  -363,  2282,  1208,  1501,   142,  2533,  2441,  -363,   267,
    -363,    51,  2034,    22,  -363,  -363,  1318,   541,   178,  -363,
     187,  -363,  -363,   117,  -363,  -363,    88,   215,  1053,  -363,
    -363,  1053,  -363,  2034,  2625,   461,  -363,  -363,   264,   274,
    2034,  -363,  2034,  2034,  2034,  2034,  2034,  2034,  2034,  2034,
    2034,  2034,  2034,  2034,  2034,  2034,  2034,  2034,  2034,  2034,
    2034,  -363,  -363,   276,  -363,  -363,  -363,  -363,   243,  1842,
    -363,  -363,   255,  -363,  -363,   287,   291,  2034,   290,   292,
    1249,   310,   325,   301,   303,  1874,    74,  -363,  -363,  -363,
    -363,   809,  -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,
    -363,    57,   324,   328,  -363,    98,   309,  -363,  1691,   311,
    1529,  2487,  -363,  -363,  2034,  -363,   194,  -363,   323,    31,
    -363,  -363,  -363,  -363,  -363,   340,   342,  -363,  1691,   317,
     318,  1557,   187,  1385,   569,  -363,  -363,  -363,  -363,  -363,
    -363,  -363,  -363,  -363,  -363,  -363,  2034,  -363,  2034,  1922,
     346,   350,   345,   352,  -363,   214,  -363,  -363,  -363,    33,
    -363,  -363,  -363,    37,    37,   219,   219,     8,     8,     8,
       8,   286,   286,   165,   183,   133,    91,    36,   208,   354,
     367,  2034,  -363,    54,  1079,   242,  -363,  1249,  2034,  1249,
     341,  2034,  2034,   251,   935,   343,  -363,  -363,  -363,   195,
    -363,  -363,  -363,  1129,  -363,   152,  -363,  -363,  2172,  -363,
     370,  -363,   329,  1691,  -363,   331,  -363,  2034,   333,  -363,
    -363,   302,  -363,  2034,  -363,  -363,  -363,   334,  1691,  -363,
    -363,  -363,  2034,   335,  -363,   368,  -363,  1691,   339,   344,
    1670,  -363,  -363,  1842,  -363,   295,   295,  2579,  -363,  -363,
    2034,  -363,  2034,   355,  -363,   348,  1717,  -363,  -363,  -363,
    -363,  -363,   217,  -363,  1249,   269,   279,   372,  1954,  1954,
    -363,  -363,  -363,  -363,  -363,  -363,   349,  -363,   353,  -363,
    -363,  -363,  -363,   357,   358,  -363,  -363,   365,  1691,  -363,
    -363,  -363,  2034,   366,    56,   360,   281,  -363,   361,  -363,
    -363,  -363,  -363,  -363,  -363,  1079,  1249,  -363,  1249,  1249,
    2034,  1984,  2080,  -363,  -363,  -363,  -363,  -363,   371,   373,
    -363,  1813,  -363,  2034,  -363,  2579,  2034,  -363,   315,  -363,
    -363,   288,  1249,   308,  1249,   316,  -363,  -363,  -363,  -363,
    -363,  -363,  1249,   363,  -363,  1249,  -363,  1249,  -363,  -363,
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
     153,   158,   152,   157,   222,     0,     0,   206,     0,     0,
       0,     0,   202,     0,     0,    85,    78,    81,    82,    79,
      83,    77,    84,    86,    87,    80,     0,     5,     0,     0,
       0,     0,     0,     0,    20,     0,    28,    23,    22,     0,
      46,    47,    48,    50,    51,    54,    53,    56,    58,    57,
      59,    62,    61,    64,    66,    68,    70,     0,    72,     0,
       0,     0,   230,     0,     0,     0,   234,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   266,   267,   268,     0,
     255,   249,   251,     0,   195,   203,   196,   182,     0,   184,
       0,   174,     0,     0,   181,    38,   180,     0,     0,   133,
     148,     0,   140,     0,   154,   223,   205,     0,     0,   207,
     213,   212,     0,     0,   224,     0,   214,     0,     0,     0,
       0,    76,    89,     0,    44,     0,    35,     0,    36,    21,
       0,    19,     0,     0,   237,     0,     0,   226,   229,   233,
     235,   245,     0,   247,     0,     0,     0,     0,     0,     0,
     265,   269,   191,   194,   199,   176,     0,   177,     0,   179,
     147,   149,   209,     0,     0,   211,   225,     0,     0,   215,
     221,   220,     0,     0,     0,     0,     0,    14,     0,    29,
      74,   238,   236,   227,   232,     0,     0,   246,     0,     0,
       0,     0,     0,   175,   178,   208,   210,   217,     0,     0,
     218,     0,    26,     0,    13,     0,     0,   231,   257,   258,
     259,     0,     0,     0,     0,     0,   216,   219,    27,    17,
      15,    16,     0,     0,   263,     0,   261,     0,   256,   260,
     264,   262
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -363,  -363,  -363,  -363,  -363,  -363,  -363,   -58,  -363,  -363,
      71,  -363,   -45,   171,    86,   163,   168,   228,   229,   212,
     231,   227,  -363,   -42,    34,  -363,   -82,   -40,   -36,     3,
    -363,   275,  -363,   -43,  -363,  -363,   285,  -106,   -46,  -363,
      75,  -363,   351,  -125,  -363,   -50,  -363,  -363,   -13,   -59,
     -26,  -107,  -119,  -363,    87,  -363,    13,   -61,  -135,  -121,
      55,  -362,  -363,   112,   -54,   -30,  -363,    21,  -363,   209,
    -256,  -363,  -363,  -363,  -363,   384,  -363,  -363
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
     116,   140,   119,   262,   232,    78,   149,    48,   253,   139,
     189,    59,    76,   129,   435,    72,    78,   240,    78,   123,
     145,   243,   151,    76,    72,    76,    78,   143,    62,    63,
     261,    50,   177,    76,    66,    67,    68,   125,    34,   178,
      53,   148,    64,   172,   278,    51,    53,   278,   126,   171,
      53,    54,    52,    79,   118,   173,   382,    54,   399,    55,
     190,   333,   249,    55,   195,   386,   156,   451,   381,   156,
     131,    71,   140,   140,   122,    55,    78,    78,   289,   435,
     139,   139,   217,    76,    76,   278,   227,   122,   196,   157,
     116,   147,   251,   277,    49,    72,   330,   307,    78,   278,
     144,    78,   198,   339,    78,    76,   252,   198,    76,   340,
     148,    76,   103,   103,   253,   354,   248,   290,   291,   292,
     265,   343,   136,   329,   266,   243,   231,   267,   174,    65,
       4,   268,   441,   442,   365,   250,   269,   142,   387,   231,
     452,   358,   270,   228,   271,    53,   133,   370,    20,   272,
     159,   200,   160,   162,   273,   116,   333,   320,   239,   152,
     336,   280,   163,   183,   281,   103,   146,   283,    55,   186,
     323,   260,   187,   121,    27,   217,   134,   140,   122,   164,
     195,    78,   146,   388,   185,   139,   147,   282,    76,   286,
     262,   263,   116,   184,   350,   335,   147,   191,   122,   274,
     193,   195,   165,   103,   122,   351,   278,   166,   334,   275,
     188,   167,   147,   168,   169,   192,   352,   401,   194,   379,
     279,   264,   436,   200,   374,   380,   392,   175,   278,   395,
     396,   176,   170,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     418,   103,    53,   295,   296,   434,   231,   287,   310,   116,
      53,   385,   342,    54,   348,    55,   135,   288,   103,   389,
     127,    54,   309,    55,   438,   317,   311,   391,   398,   393,
     278,    56,   357,   195,   439,   363,   454,   244,   369,   245,
     278,   318,   455,   473,   321,    53,   322,   335,   195,   278,
     371,   116,   372,   411,   457,   103,    54,   122,    55,   179,
     195,   319,   180,   475,   324,   181,   182,    78,   325,   278,
     434,   477,   244,   326,    76,   327,   231,   278,   248,   337,
     430,   231,   297,   298,   299,   300,   293,   294,   200,   338,
     103,   301,   302,   353,   341,   355,   344,   356,   461,   463,
     465,   375,   359,   360,   437,   376,   377,   378,   195,   383,
     384,   394,   397,   404,   405,   400,   407,   406,   409,   412,
     415,   408,   103,   416,   419,   373,   440,   431,   472,   420,
     453,   456,   413,   432,   443,   479,   414,   470,   444,   305,
     197,   417,   445,   446,   423,    78,   458,   200,   459,   460,
     447,   450,    76,   303,   429,   304,   466,   308,   467,   306,
     200,   241,   141,    69,   103,   403,   410,   390,   424,    70,
     332,     0,   474,     0,   476,     0,     0,     0,     0,     0,
       0,     0,   478,     0,     0,   480,     0,   481,     0,     0,
       0,     0,   448,   103,     0,     0,   449,     0,     0,     0,
       0,     0,     0,     0,    80,    81,    82,    83,    84,   200,
       0,     0,    85,     0,     0,    86,   284,    87,     0,    88,
      89,     0,     0,    90,    91,   200,     0,   469,     0,     0,
     471,     1,     2,     3,     4,     5,     0,     6,     7,     8,
       9,    10,    11,    12,    13,     0,    14,    15,    16,    17,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    92,    80,    81,    82,    83,    84,     0,
       0,    32,    85,     0,     0,    86,    93,    87,     0,    88,
      89,     0,     0,    90,    91,    94,    95,    96,     0,     0,
      97,     0,    80,    81,    82,    83,    84,     0,     0,     0,
      85,     0,     0,    86,     0,    87,   257,    88,    89,     0,
       0,    90,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     0,   366,     0,     0,     0,     0,     0,
       0,     0,     0,    92,   258,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,    93,     0,     0,     0,
       4,     0,     0,     0,     0,    94,    95,    96,     0,     0,
      97,    92,   367,     0,     0,   121,    27,     0,    20,     0,
       0,     0,     0,     0,    93,     0,     0,     0,     0,     0,
     259,     0,     0,    94,    95,    96,     0,     0,    97,     0,
       0,     0,     0,   121,    27,     0,   202,    81,    82,    83,
      84,     0,     0,     0,    85,     0,     0,    86,   368,    87,
       0,    88,    89,     0,     0,    90,    91,     0,     0,     0,
       0,     0,     0,     0,     0,   203,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     3,     4,     5,     0,     6,     7,     8,
       9,    10,    11,    12,    13,    92,    14,    15,    16,    17,
      18,    19,    20,   128,     0,     0,     0,   204,    93,   205,
       0,     0,    21,     0,     0,     0,     0,    94,    95,    96,
     206,   207,    97,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,   208,   209,   210,   211,   212,   213,   214,
     215,    32,   202,    81,    82,    83,    84,     0,     0,     0,
      85,     0,     0,    86,     0,    87,     0,    88,    89,     0,
       0,    90,    91,     0,     0,     0,     0,     0,     0,     0,
       0,   203,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       4,     5,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    92,    14,    15,    16,    17,    18,    19,    20,   128,
       0,     0,     0,   331,    93,   205,     0,     0,    21,     0,
       0,     0,     0,    94,    95,    96,   206,   207,    97,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,   208,
     209,   210,   211,   212,   213,   214,   215,    32,    80,    81,
      82,    83,    84,     0,     0,     0,    85,     0,     0,    86,
       0,    87,     0,    88,    89,     0,     0,    90,    91,     0,
       0,     0,     0,     0,     0,     0,     0,   203,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     0,     6,
       7,     8,     9,    10,    11,    12,    13,    92,    14,    15,
      16,    17,    18,    19,    20,     0,     0,     0,     0,     0,
      93,     0,     0,     0,    21,     0,     0,     0,     0,    94,
      95,    96,     0,     0,    97,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     0,    80,    81,    82,    83,
      84,     0,     0,    32,    85,     0,     0,    86,     0,    87,
       0,    88,    89,     0,     0,    90,    91,     0,     0,     0,
       0,     0,    80,    81,    82,    83,    84,     0,     0,     0,
      85,     0,     0,    86,     0,    87,     0,    88,    89,     0,
       0,    90,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     0,     6,     0,     8,
       9,    10,    53,    12,    13,    92,     0,    15,     0,    17,
      18,    19,    20,   333,   254,    55,     0,     0,    93,     0,
       0,     0,    21,     0,     0,     0,     0,    94,    95,    96,
       0,    92,    97,    22,    23,    24,    25,    26,    27,   199,
       0,     0,     0,   147,    93,     0,     0,     0,     0,     0,
       0,    32,     0,    94,    95,    96,     0,     0,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       4,     5,     0,     6,     7,     8,     9,    10,    11,    12,
      13,   229,    14,    15,    16,    17,    18,    19,    20,     0,
       0,     0,     0,   230,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
      23,    24,    25,    26,    27,    28,    29,    30,     0,     0,
       0,     0,   202,    81,    82,    83,    84,    32,     0,     0,
      85,     0,     0,    86,     0,    87,     0,    88,    89,     0,
       0,    90,    91,     0,     0,     0,     1,     2,     3,     4,
       5,   203,     6,     7,     8,     9,    10,    11,    12,    13,
       0,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     0,     0,     0,
       0,    92,   146,   254,    55,     0,    32,     0,     0,   128,
       0,     0,     0,     0,    93,   205,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,   206,   207,    97,     0,
       0,     0,   147,     0,     0,     0,     0,     0,     0,   208,
     209,   210,   211,   212,   213,   214,   215,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     2,     3,     4,
       5,     0,     6,     7,     8,     9,    10,    11,    12,    13,
     364,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     0,     6,
       7,     8,     9,    10,    11,    12,    13,     0,    14,    15,
      16,    17,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    80,    81,    82,    83,    84,     0,
       0,     0,    85,    32,     0,    86,     0,   236,     0,    88,
      89,     0,     0,    90,    91,     0,     0,     0,     0,     0,
       0,     0,    80,    81,    82,    83,    84,     0,     0,     0,
      85,     0,     0,    86,     0,   345,   237,    88,    89,     0,
       0,    90,    91,     0,     0,     0,     0,     0,     0,     0,
      80,    81,    82,    83,    84,     0,     0,     0,    85,     0,
       0,    86,     4,    87,   346,    88,    89,     0,     0,    90,
      91,     0,     0,    92,   238,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,    93,     0,     0,     0,
       4,     0,   361,     0,     0,    94,    95,    96,     0,     0,
      97,    92,   347,     0,     0,   121,    27,     0,    20,     0,
       0,     0,     0,     0,    93,     0,     0,     0,     4,     0,
       0,     0,     0,    94,    95,    96,     0,     0,    97,    92,
     362,     0,     0,   121,    27,     0,    20,     0,     0,     0,
       0,     0,    93,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,     0,     0,    97,     0,     0,     0,
       0,   121,    27,    80,    81,    82,    83,    84,     0,     0,
       0,    85,     0,     0,    86,     0,    87,     0,    88,    89,
       0,     0,    90,    91,    80,    81,    82,    83,    84,     0,
       0,     0,    85,     0,     0,    86,     0,    87,     0,    88,
      89,     0,     0,    90,    91,   421,     0,     0,     0,     0,
      80,    81,    82,    83,    84,     0,     0,     0,    85,     0,
       0,    86,     0,    87,     0,    88,    89,     0,     0,    90,
      91,     4,     0,   310,     0,     0,     0,     0,     0,     0,
       0,     0,    92,   422,     0,     0,     0,     0,     0,    20,
       0,   311,     4,     0,     0,    93,     0,     0,     0,     0,
       0,     0,     0,    92,    94,    95,    96,     0,     0,    97,
      20,     0,     0,     0,   121,    27,    93,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,     0,    92,
      97,     0,     0,     0,     0,   121,    27,   199,     0,     0,
       0,   433,    93,     0,     0,     0,    80,    81,    82,    83,
      84,    94,    95,    96,    85,     0,    97,    86,     0,    87,
       0,    88,    89,     0,     0,    90,    91,     0,     0,   310,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    84,
       0,     0,     0,    85,     0,     0,    86,   311,    87,     0,
      88,    89,     0,     0,    90,    91,     0,     0,   310,     0,
       0,     0,     0,     0,     0,     0,     0,    80,    81,    82,
      83,    84,     0,     0,     0,    85,   311,     0,    86,     0,
      87,     0,    88,    89,     0,    92,    90,    91,     0,     0,
       0,     0,     0,   199,     0,     0,   328,   468,    93,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
       0,     0,    97,     0,    92,    80,    81,    82,    83,    84,
       0,     0,   199,    85,     0,     0,    86,    93,    87,     0,
      88,    89,     0,     0,    90,    91,    94,    95,    96,     0,
       0,    97,     0,     0,     0,     0,    92,    80,    81,    82,
      83,    84,     0,     0,     0,    85,     0,     0,    86,    93,
      87,     0,    88,    89,     0,     0,    90,    91,    94,    95,
      96,     0,     0,    97,     0,     0,   203,    80,    81,    82,
      83,    84,     0,     0,     0,    85,     0,     0,    86,   462,
      87,     0,    88,    89,    92,     0,    90,    91,     0,     0,
       0,     0,   373,     0,     0,     0,     0,    93,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,     0,
       0,    97,     0,     0,     0,     0,    92,    80,    81,    82,
      83,    84,     0,     0,     0,    85,     0,     0,    86,    93,
      87,     0,    88,    89,     0,     0,    90,    91,    94,    95,
      96,     0,     0,    97,     0,     0,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    93,
       0,     0,     0,    80,    81,    82,    83,    84,    94,    95,
      96,    85,     0,    97,    86,   464,    87,     0,    88,    89,
       0,     0,    90,    91,    80,    81,    82,    83,    84,     0,
       0,     0,    85,     0,     0,   158,    92,    87,     0,    88,
      89,     0,     0,    90,    91,     0,     0,     0,     0,    93,
       0,     0,     0,    80,    81,    82,    83,    84,    94,    95,
      96,    85,     0,    97,   161,     0,    87,     0,    88,    89,
       0,     0,    90,    91,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,     0,     0,     0,     0,
       0,     0,     0,    92,    94,    95,    96,     0,     0,    97,
       0,     0,     0,     0,     0,     0,    93,     0,     0,   402,
       0,     0,     0,     0,     0,    94,    95,    96,     0,     0,
      97,     0,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,     0,     0,    97,
       1,     2,     3,     4,     5,     0,     6,     7,     8,     9,
      10,    11,    12,    13,     0,    14,    15,    16,    17,    18,
      19,    20,     0,     0,   127,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,    23,    24,    25,    26,    27,    28,    29,
      30,     0,     0,     0,     0,     1,     2,     3,     4,     5,
      32,     6,     7,     8,     9,    10,    11,    12,    13,     0,
      14,    15,    16,    17,    18,    19,    20,   128,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     0,     0,     0,
       1,     2,     3,     4,     5,    32,     6,     7,     8,     9,
      10,    11,    12,    13,     0,    14,    15,    16,    17,    18,
      19,    20,   128,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,     0,     0,     1,     2,     3,     4,     5,
      32,     6,     7,     8,     9,    10,    11,    12,    13,     0,
      14,    15,    16,    17,    18,    19,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     0,     0,     0,
       1,     2,     3,     4,     5,    32,     6,     7,     8,     9,
      10,    11,    12,    13,     0,    14,    15,    16,    17,    18,
      19,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,    23,    24,    25,    26,    27,    28,    29,
      30,     3,     4,     5,     0,     6,     0,     8,     9,    10,
      32,    12,    13,     0,     0,    15,     0,    17,    18,    19,
      20,     0,     0,     0,     0,   242,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,    23,    24,    25,    26,    27,     3,     4,     5,
      31,     6,     0,     8,     9,    10,     0,    12,    13,    32,
       0,    15,     0,    17,    18,    19,    20,     0,     0,     0,
       0,   349,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,    23,    24,
      25,    26,    27,     3,     4,     5,    31,     6,     0,     8,
       9,    10,     0,    12,    13,    32,     0,    15,     0,    17,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    23,    24,    25,    26,    27,     3,
       4,     5,    31,     6,     0,     8,     9,    10,     0,    12,
      13,    32,     0,    15,     0,    17,    18,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,     0,     0,   425,     0,     0,    22,
      23,    24,    25,    26,    27,     3,     4,     5,     0,     6,
       0,     8,     9,    10,     0,    12,    13,    32,     0,    15,
       0,    17,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    23,    24,    25,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32
};

static const yytype_int16 yycheck[] =
{
      50,    51,    61,     0,    86,    55,   127,    50,    51,    51,
      52,    65,    52,   148,   133,    65,    77,     3,   143,    65,
      43,    34,    65,    59,   386,     3,    76,   134,    78,    55,
      76,   137,    78,    76,     3,    78,    86,    21,    35,    36,
     147,    14,    34,    86,    41,    42,    43,    21,    45,    41,
       3,    77,     3,    16,    21,    14,     3,    21,    32,   104,
       3,    14,    14,    50,    51,    28,    30,    14,   324,    16,
      93,    14,    21,    16,   124,    21,   158,    21,    45,   161,
      59,    90,   136,   137,   134,    16,   136,   137,   170,   451,
     136,   137,   128,   136,   137,    21,   132,   147,   124,    86,
     142,    44,   142,    15,    90,     3,    32,   189,   158,    21,
      94,   161,   125,    15,   164,   158,    94,   130,   161,    21,
     146,   164,    51,    52,   249,    94,   139,   172,   173,   174,
      13,   238,    90,   215,    17,   241,   133,    20,   101,    90,
      71,    24,   398,   399,   263,    94,    29,    37,    94,   146,
      94,   258,    35,   132,    37,     3,    14,   264,    89,    42,
      89,   127,    91,    92,    47,   207,    14,   207,   134,    15,
     231,   158,    14,     8,   161,   104,    14,   164,    16,    46,
     210,   147,    91,   114,   115,   221,    44,   241,   238,    14,
     240,   241,    14,   314,    11,   241,    44,   163,   241,   165,
     335,    14,   244,    38,   244,   231,    44,    15,   258,    92,
      21,   261,    14,   142,   264,    21,    21,    19,   231,   102,
      12,    23,    44,    25,    26,    15,    32,    32,    15,    15,
      15,    44,    15,   199,   279,    21,   318,    18,    21,   321,
     322,    22,    44,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     367,   190,     3,   177,   178,   386,   263,     3,    26,   311,
       3,   311,   238,    14,   240,    16,   335,     3,   207,    37,
      37,    14,     6,    16,    15,    30,    44,   317,   324,   319,
      21,    32,   258,   343,    15,   261,    15,    30,   264,    32,
      21,    14,    21,    15,    14,     3,    14,   333,   358,    21,
     276,   353,   278,   353,   435,   244,    14,   367,    16,    33,
     370,    30,    36,    15,    14,    39,    40,   377,     3,    21,
     451,    15,    30,    32,   377,    32,   333,    21,   351,    15,
     382,   338,   179,   180,   181,   182,   175,   176,   314,    21,
     279,   183,   184,    30,    45,    15,    45,    15,   440,   441,
     442,    15,    45,    45,   394,    15,    21,    15,   418,    15,
       3,    30,   121,     3,    45,    32,    45,   343,    45,    45,
      45,   347,   311,    15,    45,    90,    14,    32,    73,    45,
      30,    30,   358,    45,    45,    32,   362,   455,    45,   187,
     125,   367,    45,    45,   370,   455,   436,   373,   438,   439,
      45,    45,   455,   185,   380,   186,    45,   190,    45,   188,
     386,   136,    71,     0,   353,   338,   351,   315,   373,    45,
     221,    -1,   462,    -1,   464,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   472,    -1,    -1,   475,    -1,   477,    -1,    -1,
      -1,    -1,   418,   382,    -1,    -1,   422,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,   435,
      -1,    -1,    11,    -1,    -1,    14,    15,    16,    -1,    18,
      19,    -1,    -1,    22,    23,   451,    -1,   453,    -1,    -1,
     456,    68,    69,    70,    71,    72,    -1,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    83,    84,    85,    86,
      87,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,    82,     3,     4,     5,     6,     7,    -1,
      -1,   128,    11,    -1,    -1,    14,    95,    16,    -1,    18,
      19,    -1,    -1,    22,    23,   104,   105,   106,    -1,    -1,
     109,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      11,    -1,    -1,    14,    -1,    16,    45,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      71,    -1,    -1,    -1,    -1,   104,   105,   106,    -1,    -1,
     109,    82,    83,    -1,    -1,   114,   115,    -1,    89,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,
     129,    -1,    -1,   104,   105,   106,    -1,    -1,   109,    -1,
      -1,    -1,    -1,   114,   115,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    11,    -1,    -1,    14,   129,    16,
      -1,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    69,    70,    71,    72,    -1,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    -1,    -1,    94,    95,    96,
      -1,    -1,    99,    -1,    -1,    -1,    -1,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      11,    -1,    -1,    14,    -1,    16,    -1,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,
      71,    72,    -1,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    -1,    -1,    94,    95,    96,    -1,    -1,    99,    -1,
      -1,    -1,    -1,   104,   105,   106,   107,   108,   109,   110,
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
      85,    86,    87,    88,    89,    -1,    -1,    -1,    -1,    -1,
      95,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,   104,
     105,   106,    -1,    -1,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,    -1,     3,     4,     5,     6,
       7,    -1,    -1,   128,    11,    -1,    -1,    14,    -1,    16,
      -1,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      11,    -1,    -1,    14,    -1,    16,    -1,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    -1,    74,    -1,    76,
      77,    78,     3,    80,    81,    82,    -1,    84,    -1,    86,
      87,    88,    89,    14,    15,    16,    -1,    -1,    95,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,   104,   105,   106,
      -1,    82,   109,   110,   111,   112,   113,   114,   115,    90,
      -1,    -1,    -1,    44,    95,    -1,    -1,    -1,    -1,    -1,
      -1,   128,    -1,   104,   105,   106,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,
      71,    72,    -1,    74,    75,    76,    77,    78,    79,    80,
      81,     3,    83,    84,    85,    86,    87,    88,    89,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,   128,    -1,    -1,
      11,    -1,    -1,    14,    -1,    16,    -1,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    68,    69,    70,    71,
      72,    32,    74,    75,    76,    77,    78,    79,    80,    81,
      -1,    83,    84,    85,    86,    87,    88,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,    82,    14,    15,    16,    -1,   128,    -1,    -1,    90,
      -1,    -1,    -1,    -1,    95,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,   105,   106,   107,   108,   109,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,
      72,    -1,    74,    75,    76,    77,    78,    79,    80,    81,
      15,    83,    84,    85,    86,    87,    88,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    71,    72,    -1,    74,
      75,    76,    77,    78,    79,    80,    81,    -1,    83,    84,
      85,    86,    87,    88,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    11,   128,    -1,    14,    -1,    16,    -1,    18,
      19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      11,    -1,    -1,    14,    -1,    16,    45,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    11,    -1,
      -1,    14,    71,    16,    45,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      71,    -1,    45,    -1,    -1,   104,   105,   106,    -1,    -1,
     109,    82,    83,    -1,    -1,   114,   115,    -1,    89,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    -1,   104,   105,   106,    -1,    -1,   109,    82,
      83,    -1,    -1,   114,   115,    -1,    89,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   104,   105,   106,    -1,    -1,   109,    -1,    -1,    -1,
      -1,   114,   115,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    11,    -1,    -1,    14,    -1,    16,    -1,    18,    19,
      -1,    -1,    22,    23,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    11,    -1,    -1,    14,    -1,    16,    -1,    18,
      19,    -1,    -1,    22,    23,    45,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    11,    -1,
      -1,    14,    -1,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    71,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    89,
      -1,    44,    71,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,   104,   105,   106,    -1,    -1,   109,
      89,    -1,    -1,    -1,   114,   115,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,   105,   106,    -1,    82,
     109,    -1,    -1,    -1,    -1,   114,   115,    90,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,     3,     4,     5,     6,
       7,   104,   105,   106,    11,    -1,   109,    14,    -1,    16,
      -1,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    11,    -1,    -1,    14,    44,    16,    -1,
      18,    19,    -1,    -1,    22,    23,    -1,    -1,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    11,    44,    -1,    14,    -1,
      16,    -1,    18,    19,    -1,    82,    22,    23,    -1,    -1,
      -1,    -1,    -1,    90,    -1,    -1,    32,    94,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,
      -1,    -1,   109,    -1,    82,     3,     4,     5,     6,     7,
      -1,    -1,    90,    11,    -1,    -1,    14,    95,    16,    -1,
      18,    19,    -1,    -1,    22,    23,   104,   105,   106,    -1,
      -1,   109,    -1,    -1,    -1,    -1,    82,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    11,    -1,    -1,    14,    95,
      16,    -1,    18,    19,    -1,    -1,    22,    23,   104,   105,
     106,    -1,    -1,   109,    -1,    -1,    32,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    11,    -1,    -1,    14,    15,
      16,    -1,    18,    19,    82,    -1,    22,    23,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    -1,    -1,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,    -1,
      -1,   109,    -1,    -1,    -1,    -1,    82,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    11,    -1,    -1,    14,    95,
      16,    -1,    18,    19,    -1,    -1,    22,    23,   104,   105,
     106,    -1,    -1,   109,    -1,    -1,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      -1,    -1,    -1,     3,     4,     5,     6,     7,   104,   105,
     106,    11,    -1,   109,    14,    15,    16,    -1,    18,    19,
      -1,    -1,    22,    23,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    11,    -1,    -1,    14,    82,    16,    -1,    18,
      19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    95,
      -1,    -1,    -1,     3,     4,     5,     6,     7,   104,   105,
     106,    11,    -1,   109,    14,    -1,    16,    -1,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,   104,   105,   106,    -1,    -1,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    27,
      -1,    -1,    -1,    -1,    -1,   104,   105,   106,    -1,    -1,
     109,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   104,   105,   106,    -1,    -1,   109,
      68,    69,    70,    71,    72,    -1,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    83,    84,    85,    86,    87,
      88,    89,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,
     128,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,    -1,    -1,    -1,
      68,    69,    70,    71,    72,   128,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,    68,    69,    70,    71,    72,
     128,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,    -1,    -1,    -1,
      68,    69,    70,    71,    72,   128,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    83,    84,    85,    86,    87,
      88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    70,    71,    72,    -1,    74,    -1,    76,    77,    78,
     128,    80,    81,    -1,    -1,    84,    -1,    86,    87,    88,
      89,    -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,    70,    71,    72,
     119,    74,    -1,    76,    77,    78,    -1,    80,    81,   128,
      -1,    84,    -1,    86,    87,    88,    89,    -1,    -1,    -1,
      -1,    94,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,    70,    71,    72,   119,    74,    -1,    76,
      77,    78,    -1,    80,    81,   128,    -1,    84,    -1,    86,
      87,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,    70,
      71,    72,   119,    74,    -1,    76,    77,    78,    -1,    80,
      81,   128,    -1,    84,    -1,    86,    87,    88,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,    -1,   110,
     111,   112,   113,   114,   115,    70,    71,    72,    -1,    74,
      -1,    76,    77,    78,    -1,    80,    81,   128,    -1,    84,
      -1,    86,    87,    88,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128
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
      94,   157,    94,   173,    15,   182,   187,    45,    83,   129,
     154,   181,   188,    14,    44,    13,    17,    20,    24,    29,
      35,    37,    42,    47,    92,   102,   155,    15,    21,    15,
     186,   186,   154,   186,    15,   139,   154,     3,     3,   156,
     142,   142,   142,   143,   143,   144,   144,   145,   145,   145,
     145,   146,   146,   147,   148,   149,   150,   156,   151,     6,
      26,    44,   189,   190,   191,   192,   193,    30,    14,    30,
     157,    14,    14,   195,    14,     3,    32,    32,    32,   156,
      32,    94,   199,    14,   178,   180,   187,    15,    21,    15,
      21,    45,   154,   181,    45,    16,    45,    83,   154,    94,
     157,    21,    32,    30,    94,    15,    15,   154,   181,    45,
      45,    45,    83,   154,    15,   182,    45,    83,   129,   154,
     181,   154,   154,    90,   142,    15,    15,    21,    15,    15,
      21,    45,    30,    15,     3,   157,    21,    94,   189,    37,
     193,   195,   156,   195,    30,   156,   156,   121,   158,   200,
      32,    32,    27,   184,     3,    45,   154,    45,   154,    45,
     170,   157,    45,   154,   154,    45,    15,   154,   181,    45,
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
       1,     2,     1,     1,     1,     2,     7,     5,     5,     5,
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


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
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
      yychar = yylex ();
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
  case 270: /* translation_unit: external_declaration  */
#line 633 "cansi.y"
                                                 { printf("translation_unit -> external_declaration\n\n"); }
#line 2111 "cansi.tab.c"
    break;

  case 271: /* translation_unit: translation_unit external_declaration  */
#line 634 "cansi.y"
                                                 { printf("translation_unit -> translation_unit external_declaration\n\n"); }
#line 2117 "cansi.tab.c"
    break;

  case 272: /* external_declaration: function_definition  */
#line 638 "cansi.y"
                                { printf("external_declaration -> function_definition\n"); }
#line 2123 "cansi.tab.c"
    break;

  case 273: /* external_declaration: declaration  */
#line 639 "cansi.y"
                                { printf("external_declaration -> declaration\n"); }
#line 2129 "cansi.tab.c"
    break;


#line 2133 "cansi.tab.c"

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

#line 653 "cansi.y"

#include <stdio.h>

extern char * yytext;

int yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** %s %s\n", s, yytext);
	return 0;
}
