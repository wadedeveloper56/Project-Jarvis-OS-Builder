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
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "c11ansi.y"

#include <stdlib.h>
#include <stdio.h>
#include "jcc.h"

int yyerror(const char *s);
int yylex();

#line 80 "c11ansi.tab.c"

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
#define YYLAST   2695

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
       0,   192,   192,   193,   194,   195,   196,   200,   201,   202,
     206,   210,   211,   215,   219,   220,   224,   225,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   242,   243,
     247,   248,   249,   250,   251,   252,   253,   257,   258,   259,
     260,   261,   262,   266,   267,   271,   272,   273,   274,   278,
     279,   280,   284,   285,   286,   290,   291,   292,   293,   294,
     298,   299,   300,   304,   305,   309,   310,   314,   315,   319,
     320,   324,   325,   329,   330,   334,   335,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   353,   354,
     358,   362,   363,   364,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   381,   382,   386,   387,   391,   392,
     393,   394,   395,   396,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   421,   422,   423,   427,   428,   432,   433,   437,
     438,   439,   443,   444,   445,   446,   450,   451,   455,   456,
     457,   461,   462,   463,   464,   465,   469,   470,   474,   475,
     479,   483,   484,   485,   486,   490,   491,   495,   496,   500,
     501,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   522,   523,   524,   525,   529,
     530,   535,   536,   540,   541,   545,   546,   547,   551,   552,
     556,   557,   561,   562,   563,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   591,   592,   593,   597,
     598,   599,   600,   604,   608,   609,   613,   614,   618,   622,
     623,   624,   625,   626,   627,   631,   632,   633,   637,   638,
     642,   643,   647,   648,   652,   653,   657,   658,   659,   663,
     664,   665,   666,   667,   668,   672,   673,   674,   675,   676,
     680,   681,   685,   686,   690,   691,   695,   696
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
    2279,  -363,  -363,  -363,  -363,  -363,    13,  -363,  -363,  -363,
    -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,
    -363,  -363,  -363,  -363,  -363,  -363,    20,  -363,  -363,  -363,
      23,    69,  -363,  -363,   145,  2334,  2334,  -363,    29,  -363,
    -363,  2334,  2334,  2334,  -363,   413,  -363,  -363,   -12,    87,
    2567,   957,  1965,  -363,    47,    64,  -363,    50,  -363,  2169,
      58,   103,  -363,  -363,     9,  2475,  -363,  -363,  -363,  -363,
    -363,    87,  -363,   108,    32,  -363,  2567,   140,  2567,    89,
    -363,  -363,  -363,  -363,  -363,  -363,   957,  -363,  -363,  2045,
    -363,  2045,  2125,  -363,  -363,  -363,   143,   159,  -363,  -363,
    -363,  -363,   280,  -363,  1965,  -363,    31,   216,    17,   256,
      67,   190,   158,   129,   217,   -16,  -363,   226,   245,   210,
     248,  -363,  -363,  -363,    64,    47,  -363,   983,   587,  -363,
     145,  -363,  2224,  1112,  1405,    58,  2475,  2383,  -363,   305,
    -363,    43,  1965,    16,  -363,  -363,  1222,  1433,   141,  -363,
     155,  -363,  -363,   195,  -363,  -363,   161,   252,   957,  -363,
    -363,   957,  -363,  1965,  2567,  1789,  -363,  -363,   276,   288,
    1965,  -363,  1965,  1965,  1965,  1965,  1965,  1965,  1965,  1965,
    1965,  1965,  1965,  1965,  1965,  1965,  1965,  1965,  1965,  1965,
    1965,  -363,  -363,   266,  -363,  -363,  -363,  -363,   291,  1757,
    -363,  -363,   299,  -363,  -363,   317,   302,  1965,   319,   325,
    1153,   333,   310,   320,   321,  1837,   173,  -363,  -363,  -363,
    -363,   713,  -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,
    -363,   136,   334,   330,  -363,   171,   309,  -363,   451,   311,
    1461,  2429,  -363,  -363,  1965,  -363,   174,  -363,   327,    22,
    -363,  -363,  -363,  -363,  -363,   340,   346,   318,  -363,   451,
     324,  1574,   155,  1289,   531,  -363,  -363,  -363,  -363,  -363,
    -363,  -363,  -363,  -363,  -363,  -363,  1965,  -363,  1965,  1869,
     347,   349,   344,   351,  -363,   207,  -363,  -363,  -363,    28,
    -363,  -363,  -363,    31,    31,   216,   216,    17,    17,    17,
      17,   256,   256,    67,   190,   158,   129,    35,   217,   355,
     369,  1965,  -363,    46,   983,   181,  -363,  1153,  1965,  1153,
     343,  1965,  1965,   254,   839,   342,  -363,  -363,  -363,   189,
    -363,  -363,  -363,  1033,  -363,    54,  -363,  -363,  2087,  -363,
     373,  -363,   332,   451,  -363,   335,  -363,  1965,   336,  -363,
    -363,   167,  -363,  1965,  -363,  -363,  -363,  -363,   339,   451,
    -363,  -363,  1965,   350,  -363,   363,  -363,   451,   353,   354,
    1602,  -363,  -363,  1757,  -363,   289,   289,  2521,  -363,  -363,
    1965,  -363,  1965,   356,  -363,   357,  1632,  -363,  -363,  -363,
    -363,  -363,   212,  -363,  1153,   253,   265,   371,  1898,  1898,
    -363,  -363,  -363,  -363,  -363,  -363,   358,  -363,   361,  -363,
    -363,  -363,  -363,   362,   364,  -363,  -363,   366,   451,  -363,
    -363,  -363,  1965,   370,    48,   359,   269,  -363,   378,  -363,
    -363,  -363,  -363,  -363,  -363,   983,  1153,  -363,  1153,  1153,
    1965,  1994,  2015,  -363,  -363,  -363,  -363,  -363,   372,   374,
    -363,  1728,  -363,  1965,  -363,  2521,  1965,  -363,   314,  -363,
    -363,   283,  1153,   286,  1153,   295,  -363,  -363,  -363,  -363,
    -363,  -363,  1153,   368,  -363,  1153,  -363,  1153,  -363,  -363,
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
    -363,  -363,  -363,  -363,  -363,  -363,  -363,   -54,  -363,  -363,
      71,  -363,   -44,   106,   148,   163,   139,   211,   228,   233,
     234,   231,  -363,   -42,    24,  -363,   -82,   -41,   -47,     3,
    -363,   298,  -363,   -43,  -363,  -363,   292,  -114,   -24,  -363,
      74,  -363,   365,  -125,  -363,   -50,  -363,  -363,    -5,   -59,
     -15,   -92,  -116,  -363,    92,  -363,   -20,   -63,  -135,  -121,
      59,  -362,  -363,   112,   -45,   -46,  -363,    11,  -363,   213,
    -303,  -363,  -363,  -363,  -363,   388,  -363,  -363
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
     116,   119,   129,   262,   149,    78,    48,   232,   253,    72,
     140,   399,    76,   243,   435,    72,    78,   189,    78,    59,
      79,   118,    64,    76,    50,    76,    78,    51,    62,    63,
     123,   139,   240,    76,    66,    67,    68,   172,    34,   278,
      53,   177,   145,   143,   151,   261,   278,    53,   178,   173,
     171,    54,   148,    55,   249,   382,   157,   386,   333,   451,
     131,   125,   133,   381,   195,   183,   156,   190,    71,   156,
      55,   217,   126,    52,   122,   227,    78,    78,   289,   435,
      72,   140,   140,    76,    76,   441,   442,   122,   147,   136,
     116,   251,   134,    49,   152,   184,    53,   307,    78,   196,
     252,    78,   139,   139,    78,    76,   354,    54,    76,    65,
     198,    76,   103,   103,   253,   198,   144,   243,   290,   291,
     292,   148,   174,   329,   248,     4,   231,   250,   280,    53,
     387,   281,   452,   228,   283,   142,   343,   365,    53,   231,
     333,   200,    55,    20,   146,   146,    55,   163,   239,    54,
     159,    55,   160,   162,   323,   116,   320,   359,   336,   263,
      53,   260,   370,   164,   217,   103,   277,    56,   121,    27,
     147,    54,   278,    55,   147,   147,   339,   282,   122,   286,
     195,    78,   340,   388,   278,   351,   140,   244,    76,   264,
     262,   185,   116,   350,   186,   330,   352,   310,   265,   122,
     278,   195,   266,   103,   122,   267,   335,   139,   389,   268,
     187,   401,   379,   200,   269,   311,   334,   436,   380,   188,
     270,   193,   271,   278,   175,   374,   392,   272,   176,   395,
     396,   191,   273,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     192,   103,   342,   194,   348,   434,   231,   279,   438,   116,
     385,   391,   309,   393,   278,   418,   135,   398,   103,   287,
     439,   293,   294,   358,   454,   363,   278,   274,   369,   179,
     455,   288,   180,   195,   165,   181,   182,   275,   473,   166,
     371,   475,   372,   167,   278,   168,   169,   278,    53,   195,
     477,   116,   411,   325,   457,   103,   278,   122,   335,    54,
     195,    55,   301,   302,   170,   295,   296,    78,   127,   317,
     434,   318,   319,   321,    76,   244,   231,   245,   200,   322,
     430,   231,   297,   298,   299,   300,   248,   324,   437,   337,
     103,   338,   326,   327,   341,   355,   344,   353,   461,   463,
     465,   356,   375,   357,   376,   377,   378,   406,   195,   360,
     383,   408,   384,   394,   400,   397,   404,   405,   416,   373,
     407,   409,   103,   413,   412,   440,   414,   472,   431,   453,
     458,   417,   459,   460,   423,   415,   303,   200,   419,   420,
     479,   470,   432,   443,   429,    78,   444,   445,   456,   446,
     200,   447,    76,    69,   304,   450,   474,   466,   476,   467,
     305,   308,   306,   197,   103,   410,   478,   390,   241,   480,
     403,   481,   424,    70,   332,     0,   141,     0,     0,     0,
       0,     0,   448,     0,     0,     0,   449,     0,     0,     0,
       0,     0,     0,   103,    80,    81,    82,    83,    84,   200,
       0,     0,    85,     0,     0,    86,     0,    87,     0,    88,
      89,     0,     0,    90,    91,   200,     0,   469,     0,     0,
     471,     1,     2,     3,     4,     5,     0,     6,     7,     8,
       9,    10,    11,    12,    13,     0,    14,    15,    16,    17,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    92,    80,    81,    82,    83,    84,     0,
      20,    32,    85,     0,     0,    86,    93,    87,     0,    88,
      89,     0,     0,    90,    91,    94,    95,    96,     0,     0,
      97,     0,     0,     0,     0,   121,    27,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   366,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     202,    81,    82,    83,    84,     0,     0,     0,    85,     0,
       0,    86,     4,    87,     0,    88,    89,     0,     0,    90,
      91,     0,     0,    92,   367,     0,     0,     0,     0,   203,
      20,     0,     0,     0,     0,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,     0,     0,
      97,     0,     0,     0,     0,   121,    27,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     5,
     368,     6,     7,     8,     9,    10,    11,    12,    13,    92,
      14,    15,    16,    17,    18,    19,    20,   128,     0,     0,
       0,   204,    93,   205,     0,     0,    21,     0,     0,     0,
       0,    94,    95,    96,   206,   207,    97,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,   208,   209,   210,
     211,   212,   213,   214,   215,    32,   202,    81,    82,    83,
      84,     0,     0,     0,    85,     0,     0,    86,     0,    87,
       0,    88,    89,     0,     0,    90,    91,     0,     0,     0,
       0,     0,     0,     0,     0,   203,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     3,     4,     5,     0,     6,     7,     8,
       9,    10,    11,    12,    13,    92,    14,    15,    16,    17,
      18,    19,    20,   128,     0,     0,     0,   331,    93,   205,
       0,     0,    21,     0,     0,     0,     0,    94,    95,    96,
     206,   207,    97,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,   208,   209,   210,   211,   212,   213,   214,
     215,    32,    80,    81,    82,    83,    84,     0,     0,     0,
      85,     0,     0,    86,     0,    87,     0,    88,    89,     0,
       0,    90,    91,     0,     0,     0,     0,     0,     0,     0,
       0,   203,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       4,     5,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    92,    14,    15,    16,    17,    18,    19,    20,     0,
       0,     0,     0,     0,    93,     0,     0,     0,    21,     0,
       0,     0,     0,    94,    95,    96,     0,     0,    97,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     0,
      80,    81,    82,    83,    84,     0,     0,    32,    85,     0,
       0,    86,     0,    87,     0,    88,    89,     0,     0,    90,
      91,     0,     0,     0,     0,     0,    80,    81,    82,    83,
      84,     0,     0,     0,    85,     0,     0,    86,     0,    87,
       0,    88,    89,     0,     0,    90,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       0,     6,     0,     8,     9,    10,    53,    12,    13,    92,
       0,    15,     0,    17,    18,    19,    20,   333,   254,    55,
       0,     0,    93,     0,     0,     0,    21,     0,     0,     0,
       0,    94,    95,    96,     0,    92,    97,    22,    23,    24,
      25,    26,    27,   199,     0,     0,     0,   147,    93,     0,
       0,     0,     0,     0,     0,    32,     0,    94,    95,    96,
       0,     0,    97,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     3,     4,     5,     0,     6,     7,     8,
       9,    10,    11,    12,    13,   229,    14,    15,    16,    17,
      18,    19,    20,     0,     0,     0,     0,   230,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,     0,     0,     0,   202,    81,    82,    83,
      84,    32,     0,     0,    85,     0,     0,    86,     0,    87,
       0,    88,    89,     0,     0,    90,    91,     0,     0,     0,
       1,     2,     3,     4,     5,   203,     6,     7,     8,     9,
      10,    11,    12,    13,     0,    14,    15,    16,    17,    18,
      19,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,    23,    24,    25,    26,    27,    28,    29,
      30,     0,     0,     0,     0,    92,   146,   254,    55,     0,
      32,     0,     0,   128,     0,     0,     0,     0,    93,   205,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
     206,   207,    97,     0,     0,     0,   147,     0,     0,     0,
       0,     0,     0,   208,   209,   210,   211,   212,   213,   214,
     215,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     2,     3,     4,     5,     0,     6,     7,     8,     9,
      10,    11,    12,    13,   364,    14,    15,    16,    17,    18,
      19,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,    23,    24,    25,    26,    27,    28,    29,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       4,     5,     0,     6,     7,     8,     9,    10,    11,    12,
      13,     0,    14,    15,    16,    17,    18,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    80,    81,
      82,    83,    84,     0,     0,     0,    85,    32,     0,    86,
       0,   236,     0,    88,    89,     0,     0,    90,    91,     0,
       0,     0,     0,     0,     0,     0,    80,    81,    82,    83,
      84,     0,     0,     0,    85,     0,     0,    86,     0,   257,
     237,    88,    89,     0,     0,    90,    91,     0,     0,     0,
       0,     0,     0,     0,    80,    81,    82,    83,    84,     0,
       0,     0,    85,     0,     0,    86,     4,   345,   258,    88,
      89,     0,     0,    90,    91,     0,     0,    92,   238,     0,
       0,     0,     0,     0,    20,     0,     0,     0,     0,     0,
      93,     0,     0,     0,     4,     0,   346,     0,     0,    94,
      95,    96,     0,     0,    97,    92,   259,     0,     0,   121,
      27,     0,    20,     0,     0,     0,     0,     0,    93,     0,
       0,     0,     4,     0,     0,     0,     0,    94,    95,    96,
       0,     0,    97,    92,   347,     0,     0,   121,    27,     0,
      20,     0,     0,     0,     0,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,     0,     0,
      97,     0,     0,     0,     0,   121,    27,    80,    81,    82,
      83,    84,     0,     0,     0,    85,     0,     0,    86,     0,
      87,     0,    88,    89,     0,     0,    90,    91,     0,     0,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    84,
       0,     0,     0,    85,     0,     0,    86,     0,    87,   361,
      88,    89,     0,     0,    90,    91,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    84,
       0,     0,     0,    85,     0,     4,    86,   421,    87,     0,
      88,    89,     0,     0,    90,    91,    92,   362,   310,     0,
       0,     0,     0,    20,     0,     0,     0,     0,     0,    93,
       0,     0,     0,     4,     0,     0,   311,     0,    94,    95,
      96,     0,     0,    97,    92,   422,     0,     0,   121,    27,
       0,    20,     0,     0,     0,     0,     0,    93,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,     0,
       0,    97,     0,     0,    92,     0,   121,    27,     0,     0,
       0,     0,   199,     0,     0,     0,   433,    93,     0,     0,
       0,    80,    81,    82,    83,    84,    94,    95,    96,    85,
       0,    97,    86,     0,    87,     0,    88,    89,     0,     0,
      90,    91,     0,     0,   310,     0,     0,     0,     0,     0,
      80,    81,    82,    83,    84,     0,     0,     0,    85,     0,
       0,    86,   311,    87,     0,    88,    89,     0,     0,    90,
      91,     0,     0,   310,     0,     0,     0,     0,     0,     0,
       0,     0,    80,    81,    82,    83,    84,     0,     0,     0,
      85,   311,     0,    86,   284,    87,     0,    88,    89,     0,
      92,    90,    91,     0,     0,     0,     0,     0,   199,     0,
       0,     0,   468,    93,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,     0,     0,    97,     0,    92,
      80,    81,    82,    83,    84,     0,     0,   199,    85,     0,
       0,    86,    93,    87,     0,    88,    89,     0,     0,    90,
      91,    94,    95,    96,     0,     0,    97,     0,     0,   328,
       0,    92,    80,    81,    82,    83,    84,     0,     0,     0,
      85,     0,     0,    86,    93,    87,     0,    88,    89,     0,
       0,    90,    91,    94,    95,    96,     0,     0,    97,     0,
       0,    80,    81,    82,    83,    84,     0,     0,     0,    85,
       0,     0,    86,     0,    87,     0,    88,    89,     0,    92,
      90,    91,     0,     0,     0,     0,     0,     0,     0,     0,
     203,     0,    93,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,     0,     0,    97,     0,     0,     0,
       0,    92,     0,     0,     0,     0,     0,     0,     0,   373,
       0,     0,     0,     0,    93,     0,     0,     0,    80,    81,
      82,    83,    84,    94,    95,    96,    85,     0,    97,    86,
      92,    87,     0,    88,    89,     0,     0,    90,    91,     0,
       0,     0,     0,    93,     0,     0,     0,    80,    81,    82,
      83,    84,    94,    95,    96,    85,     0,    97,    86,   462,
      87,     0,    88,    89,     0,     0,    90,    91,    80,    81,
      82,    83,    84,     0,     0,     0,    85,     0,     0,    86,
     464,    87,     0,    88,    89,     0,     0,    90,    91,     0,
       0,     0,     0,     0,     0,     0,     0,    92,    80,    81,
      82,    83,    84,     0,     0,     0,    85,     0,     0,   158,
      93,    87,     0,    88,    89,     0,     0,    90,    91,    94,
      95,    96,     0,     0,    97,     0,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    93,
       0,     0,     0,     0,     0,     0,     0,    92,    94,    95,
      96,     0,     0,    97,     0,     0,     0,     0,     0,     0,
      93,     0,     0,     0,   402,     0,     0,     0,     0,    94,
      95,    96,     0,     0,    97,     0,     0,    92,    80,    81,
      82,    83,    84,     0,     0,     0,    85,     0,     0,   161,
      93,    87,     0,    88,    89,     0,     0,    90,    91,    94,
      95,    96,     0,     0,    97,     1,     2,     3,     4,     5,
       0,     6,     7,     8,     9,    10,    11,    12,    13,     0,
      14,    15,    16,    17,    18,    19,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,    23,    24,
      25,    26,    27,    28,    29,    30,   127,    92,     0,     0,
       0,     0,     0,     0,     0,    32,     0,     0,     0,     0,
      93,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,     0,     0,    97,     0,     0,     1,     2,     3,
       4,     5,     0,     6,     7,     8,     9,    10,    11,    12,
      13,     0,    14,    15,    16,    17,    18,    19,    20,   128,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     0,
       0,     0,     1,     2,     3,     4,     5,    32,     6,     7,
       8,     9,    10,    11,    12,    13,     0,    14,    15,    16,
      17,    18,    19,    20,   128,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,     0,     0,     1,     2,     3,
       4,     5,    32,     6,     7,     8,     9,    10,    11,    12,
      13,     0,    14,    15,    16,    17,    18,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     0,
       0,     0,     1,     2,     3,     4,     5,    32,     6,     7,
       8,     9,    10,    11,    12,    13,     0,    14,    15,    16,
      17,    18,    19,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     3,     4,     5,     0,     6,     0,     8,
       9,    10,    32,    12,    13,     0,     0,    15,     0,    17,
      18,    19,    20,     0,     0,     0,     0,   242,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    23,    24,    25,    26,    27,     3,
       4,     5,    31,     6,     0,     8,     9,    10,     0,    12,
      13,    32,     0,    15,     0,    17,    18,    19,    20,     0,
       0,     0,     0,   349,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
      23,    24,    25,    26,    27,     3,     4,     5,    31,     6,
       0,     8,     9,    10,     0,    12,    13,    32,     0,    15,
       0,    17,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    23,    24,    25,    26,
      27,     3,     4,     5,    31,     6,     0,     8,     9,    10,
       0,    12,    13,    32,     0,    15,     0,    17,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,     0,     0,   425,     0,
       0,    22,    23,    24,    25,    26,    27,     3,     4,     5,
       0,     6,     0,     8,     9,    10,     0,    12,    13,    32,
       0,    15,     0,    17,    18,    19,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,    23,    24,
      25,    26,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32
};

static const yytype_int16 yycheck[] =
{
      50,    51,    61,     0,    86,    55,   127,    50,    51,    51,
      52,    52,    59,   148,    77,    65,     3,   133,   143,     3,
      65,   324,    65,   137,   386,     3,    76,    43,    78,    34,
      50,    51,     3,    76,    14,    78,    86,    14,    35,    36,
      55,    65,   134,    86,    41,    42,    43,    16,    45,    21,
       3,    34,    76,    21,    78,   147,    21,     3,    41,    28,
     104,    14,    77,    16,    21,    30,    86,    21,    14,    21,
      59,    21,    14,    45,   124,     8,   158,    93,    90,   161,
      16,   128,    32,    14,   134,   132,   136,   137,   170,   451,
       3,   136,   137,   136,   137,   398,   399,   147,    44,    90,
     142,   142,    44,    90,    15,    38,     3,   189,   158,   124,
      94,   161,   136,   137,   164,   158,    94,    14,   161,    90,
     125,   164,    51,    52,   249,   130,    94,   241,   172,   173,
     174,   146,   101,   215,   139,    71,   133,    94,   158,     3,
      94,   161,    94,   132,   164,    37,   238,   263,     3,   146,
      14,   127,    16,    89,    14,    14,    16,    14,   134,    14,
      89,    16,    91,    92,   210,   207,   207,   259,   231,    14,
       3,   147,   264,    14,   221,   104,    15,    32,   114,   115,
      44,    14,    21,    16,    44,    44,    15,   163,   238,   165,
     240,   241,    21,   314,    21,    21,   241,    30,   241,    44,
     335,    11,   244,   244,    46,    32,    32,    26,    13,   259,
      21,   261,    17,   142,   264,    20,   231,   241,    37,    24,
      91,    32,    15,   199,    29,    44,   231,    15,    21,    12,
      35,    21,    37,    21,    18,   279,   318,    42,    22,   321,
     322,    15,    47,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      15,   190,   238,    15,   240,   386,   263,    15,    15,   311,
     311,   317,     6,   319,    21,   367,   335,   324,   207,     3,
      15,   175,   176,   259,    15,   261,    21,    92,   264,    33,
      21,     3,    36,   343,    14,    39,    40,   102,    15,    19,
     276,    15,   278,    23,    21,    25,    26,    21,     3,   359,
      15,   353,   353,     3,   435,   244,    21,   367,   333,    14,
     370,    16,   183,   184,    44,   177,   178,   377,    37,    30,
     451,    14,    30,    14,   377,    30,   333,    32,   314,    14,
     382,   338,   179,   180,   181,   182,   351,    14,   394,    15,
     279,    21,    32,    32,    45,    15,    45,    30,   440,   441,
     442,    15,    15,    45,    15,    21,    15,   343,   418,    45,
      15,   347,     3,    30,    32,   121,     3,    45,    15,    90,
      45,    45,   311,   359,    45,    14,   362,    73,    32,    30,
     436,   367,   438,   439,   370,    45,   185,   373,    45,    45,
      32,   455,    45,    45,   380,   455,    45,    45,    30,    45,
     386,    45,   455,     0,   186,    45,   462,    45,   464,    45,
     187,   190,   188,   125,   353,   351,   472,   315,   136,   475,
     338,   477,   373,    45,   221,    -1,    71,    -1,    -1,    -1,
      -1,    -1,   418,    -1,    -1,    -1,   422,    -1,    -1,    -1,
      -1,    -1,    -1,   382,     3,     4,     5,     6,     7,   435,
      -1,    -1,    11,    -1,    -1,    14,    -1,    16,    -1,    18,
      19,    -1,    -1,    22,    23,   451,    -1,   453,    -1,    -1,
     456,    68,    69,    70,    71,    72,    -1,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    83,    84,    85,    86,
      87,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,    82,     3,     4,     5,     6,     7,    -1,
      89,   128,    11,    -1,    -1,    14,    95,    16,    -1,    18,
      19,    -1,    -1,    22,    23,   104,   105,   106,    -1,    -1,
     109,    -1,    -1,    -1,    -1,   114,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    11,    -1,
      -1,    14,    71,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    82,    83,    -1,    -1,    -1,    -1,    32,
      89,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,   105,   106,    -1,    -1,
     109,    -1,    -1,    -1,    -1,   114,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,
     129,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    -1,
      -1,    94,    95,    96,    -1,    -1,    99,    -1,    -1,    -1,
      -1,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    11,    -1,    -1,    14,    -1,    16,
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
      81,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,   104,   105,   106,    -1,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,    -1,
       3,     4,     5,     6,     7,    -1,    -1,   128,    11,    -1,
      -1,    14,    -1,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    11,    -1,    -1,    14,    -1,    16,
      -1,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      -1,    74,    -1,    76,    77,    78,     3,    80,    81,    82,
      -1,    84,    -1,    86,    87,    88,    89,    14,    15,    16,
      -1,    -1,    95,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,   104,   105,   106,    -1,    82,   109,   110,   111,   112,
     113,   114,   115,    90,    -1,    -1,    -1,    44,    95,    -1,
      -1,    -1,    -1,    -1,    -1,   128,    -1,   104,   105,   106,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    69,    70,    71,    72,    -1,    74,    75,    76,
      77,    78,    79,    80,    81,     3,    83,    84,    85,    86,
      87,    88,    89,    -1,    -1,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,   128,    -1,    -1,    11,    -1,    -1,    14,    -1,    16,
      -1,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,
      68,    69,    70,    71,    72,    32,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    83,    84,    85,    86,    87,
      88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    -1,    -1,    -1,    -1,    82,    14,    15,    16,    -1,
     128,    -1,    -1,    90,    -1,    -1,    -1,    -1,    95,    96,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,
     107,   108,   109,    -1,    -1,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    -1,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    71,    72,    -1,    74,    75,    76,    77,
      78,    79,    80,    81,    15,    83,    84,    85,    86,    87,
      88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,
      71,    72,    -1,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,    83,    84,    85,    86,    87,    88,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    11,   128,    -1,    14,
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
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    11,    -1,    -1,    14,    -1,    16,    45,
      18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    11,    -1,    71,    14,    45,    16,    -1,
      18,    19,    -1,    -1,    22,    23,    82,    83,    26,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    95,
      -1,    -1,    -1,    71,    -1,    -1,    44,    -1,   104,   105,
     106,    -1,    -1,   109,    82,    83,    -1,    -1,   114,   115,
      -1,    89,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,    -1,
      -1,   109,    -1,    -1,    82,    -1,   114,   115,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    -1,    94,    95,    -1,    -1,
      -1,     3,     4,     5,     6,     7,   104,   105,   106,    11,
      -1,   109,    14,    -1,    16,    -1,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    11,    -1,
      -1,    14,    44,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      11,    44,    -1,    14,    15,    16,    -1,    18,    19,    -1,
      82,    22,    23,    -1,    -1,    -1,    -1,    -1,    90,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   104,   105,   106,    -1,    -1,   109,    -1,    82,
       3,     4,     5,     6,     7,    -1,    -1,    90,    11,    -1,
      -1,    14,    95,    16,    -1,    18,    19,    -1,    -1,    22,
      23,   104,   105,   106,    -1,    -1,   109,    -1,    -1,    32,
      -1,    82,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      11,    -1,    -1,    14,    95,    16,    -1,    18,    19,    -1,
      -1,    22,    23,   104,   105,   106,    -1,    -1,   109,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    11,
      -1,    -1,    14,    -1,    16,    -1,    18,    19,    -1,    82,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   104,   105,   106,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,     3,     4,
       5,     6,     7,   104,   105,   106,    11,    -1,   109,    14,
      82,    16,    -1,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    95,    -1,    -1,    -1,     3,     4,     5,
       6,     7,   104,   105,   106,    11,    -1,   109,    14,    15,
      16,    -1,    18,    19,    -1,    -1,    22,    23,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    11,    -1,    -1,    14,
      15,    16,    -1,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    11,    -1,    -1,    14,
      95,    16,    -1,    18,    19,    -1,    -1,    22,    23,   104,
     105,   106,    -1,    -1,   109,    -1,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,   104,   105,
     106,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,   104,
     105,   106,    -1,    -1,   109,    -1,    -1,    82,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    11,    -1,    -1,    14,
      95,    16,    -1,    18,    19,    -1,    -1,    22,    23,   104,
     105,   106,    -1,    -1,   109,    68,    69,    70,    71,    72,
      -1,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    37,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
     105,   106,    -1,    -1,   109,    -1,    -1,    68,    69,    70,
      71,    72,    -1,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,    -1,    68,    69,    70,    71,    72,   128,    74,    75,
      76,    77,    78,    79,    80,    81,    -1,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,    68,    69,    70,
      71,    72,   128,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,    83,    84,    85,    86,    87,    88,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,    -1,    68,    69,    70,    71,    72,   128,    74,    75,
      76,    77,    78,    79,    80,    81,    -1,    83,    84,    85,
      86,    87,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    70,    71,    72,    -1,    74,    -1,    76,
      77,    78,   128,    80,    81,    -1,    -1,    84,    -1,    86,
      87,    88,    89,    -1,    -1,    -1,    -1,    94,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,    70,
      71,    72,   119,    74,    -1,    76,    77,    78,    -1,    80,
      81,   128,    -1,    84,    -1,    86,    87,    88,    89,    -1,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,    70,    71,    72,   119,    74,
      -1,    76,    77,    78,    -1,    80,    81,   128,    -1,    84,
      -1,    86,    87,    88,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,    70,    71,    72,   119,    74,    -1,    76,    77,    78,
      -1,    80,    81,   128,    -1,    84,    -1,    86,    87,    88,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,
      -1,   110,   111,   112,   113,   114,   115,    70,    71,    72,
      -1,    74,    -1,    76,    77,    78,    -1,    80,    81,   128,
      -1,    84,    -1,    86,    87,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   128
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
#line 192 "c11ansi.y"
                                                { (yyval.expression) = createCTreeRoot(createTokenLabel((yyvsp[0].token))); }
#line 2105 "c11ansi.tab.c"
    break;

  case 3: /* primary_expression: constant  */
#line 193 "c11ansi.y"
                                                { (yyval.expression) = createCTreeRoot(createTokenLabel((yyvsp[0].token))); }
#line 2111 "c11ansi.tab.c"
    break;

  case 4: /* primary_expression: string  */
#line 194 "c11ansi.y"
                                                { (yyval.expression) = createCTreeRoot(createTokenLabel((yyvsp[0].token))); }
#line 2117 "c11ansi.tab.c"
    break;

  case 5: /* primary_expression: Y_LEFT_PAREN expression Y_RIGHT_PAREN  */
#line 195 "c11ansi.y"
                                                { (yyval.expression) = createCTree1(createConstr2Label(LABCT_PAREN_EXPR, (yyvsp[-2].token), (yyvsp[0].token)), (yyvsp[-1].expression)); }
#line 2123 "c11ansi.tab.c"
    break;

  case 6: /* primary_expression: generic_selection  */
#line 196 "c11ansi.y"
                                                { (yyval.expression) = NULL; }
#line 2129 "c11ansi.tab.c"
    break;

  case 7: /* constant: "i_const"  */
#line 200 "c11ansi.y"
                                 {(yyval.token) = (yyvsp[0].token);}
#line 2135 "c11ansi.tab.c"
    break;

  case 8: /* constant: "f_const"  */
#line 201 "c11ansi.y"
                                 {(yyval.token) = (yyvsp[0].token);}
#line 2141 "c11ansi.tab.c"
    break;

  case 9: /* constant: Y_ENUMERATION_CONSTANT  */
#line 202 "c11ansi.y"
                                 {(yyval.token) = (yyvsp[0].token);}
#line 2147 "c11ansi.tab.c"
    break;

  case 10: /* enumeration_constant: "identifier"  */
#line 206 "c11ansi.y"
                     {(yyval.token) = (yyvsp[0].token);}
#line 2153 "c11ansi.tab.c"
    break;

  case 11: /* string: "sting_literal"  */
#line 210 "c11ansi.y"
                         {(yyval.token) = (yyvsp[0].token);}
#line 2159 "c11ansi.tab.c"
    break;

  case 12: /* string: Y_FUNC_NAME  */
#line 211 "c11ansi.y"
                         {(yyval.token) = (yyvsp[0].token);}
#line 2165 "c11ansi.tab.c"
    break;

  case 18: /* postfix_expression: primary_expression  */
#line 229 "c11ansi.y"
                                                                                   { (yyval.expression) = (yyvsp[0].expression); }
#line 2171 "c11ansi.tab.c"
    break;

  case 19: /* postfix_expression: postfix_expression Y_LEFT_BRACKET expression Y_RIGHT_BRACKET  */
#line 230 "c11ansi.y"
                                                                                   { (yyval.expression) = createCTree2(createConstr2Label(LABCT_INDEX, (yyvsp[-2].token), (yyvsp[0].token)), (yyvsp[-3].expression),  (yyvsp[-1].expression)); }
#line 2177 "c11ansi.tab.c"
    break;

  case 20: /* postfix_expression: postfix_expression Y_LEFT_PAREN Y_RIGHT_PAREN  */
#line 231 "c11ansi.y"
                                                                                   { (yyval.expression) = createCTree1(createConstr2Label(LABCT_CALL, (yyvsp[-1].token), (yyvsp[0].token)), (yyvsp[-2].expression)); }
#line 2183 "c11ansi.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression Y_LEFT_PAREN argument_expression_list Y_RIGHT_PAREN  */
#line 232 "c11ansi.y"
                                                                                   { (yyval.expression) = createCTree2(createConstr2Label(LABCT_CALL, (yyvsp[-2].token), (yyvsp[0].token)), (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 2189 "c11ansi.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression Y_DOT "identifier"  */
#line 233 "c11ansi.y"
                                                                                   { (yyval.expression) = createCTree2(createConstr1Label(LABCT_DOT, (yyvsp[-1].token)), (yyvsp[-2].expression), createCTreeRoot(createTokenLabel((yyvsp[0].token)))); }
#line 2195 "c11ansi.tab.c"
    break;

  case 23: /* postfix_expression: postfix_expression Y_ARROW "identifier"  */
#line 234 "c11ansi.y"
                                                                                   { (yyval.expression) = createCTree2(createConstr1Label(LABCT_ARROW, (yyvsp[-1].token)), (yyvsp[-2].expression), createCTreeRoot(createTokenLabel((yyvsp[0].token)))); }
#line 2201 "c11ansi.tab.c"
    break;

  case 24: /* postfix_expression: postfix_expression Y_PLUS_PLUS  */
#line 235 "c11ansi.y"
                                                                                   { (yyval.expression) = createCTree1(createConstr1Label(LABCT_PLUS_PLUS, (yyvsp[0].token)), (yyvsp[-1].expression)); }
#line 2207 "c11ansi.tab.c"
    break;

  case 25: /* postfix_expression: postfix_expression Y_MINUS_MINUS  */
#line 236 "c11ansi.y"
                                                                                   { (yyval.expression) = createCTree1(createConstr1Label(LABCT_MINUS_MINUS, (yyvsp[0].token)), (yyvsp[-1].expression)); }
#line 2213 "c11ansi.tab.c"
    break;

  case 26: /* postfix_expression: Y_LEFT_PAREN type_name Y_RIGHT_PAREN Y_LEFT_BRACE initializer_list Y_RIGHT_BRACE  */
#line 237 "c11ansi.y"
                                                                                             { (yyval.expression) = createCTree1(createConstr5Label(LABCT_INIT, (yyvsp[-5].token),(yyvsp[-4].token),(yyvsp[-3].token),(yyvsp[-2].token),(yyvsp[0].token)), (yyvsp[-1].expression)); }
#line 2219 "c11ansi.tab.c"
    break;

  case 27: /* postfix_expression: Y_LEFT_PAREN type_name Y_RIGHT_PAREN Y_LEFT_BRACE initializer_list Y_COMMA Y_RIGHT_BRACE  */
#line 238 "c11ansi.y"
                                                                                                    { (yyval.expression) = createCTree1(createConstr5Label(LABCT_INIT, (yyvsp[-6].token),(yyvsp[-5].token),(yyvsp[-4].token),(yyvsp[-3].token),(yyvsp[-1].token)), (yyvsp[-2].expression)); }
#line 2225 "c11ansi.tab.c"
    break;

  case 28: /* argument_expression_list: assignment_expression  */
#line 242 "c11ansi.y"
                                                                 { (yyval.expression) = (yyvsp[0].expression); }
#line 2231 "c11ansi.tab.c"
    break;

  case 29: /* argument_expression_list: argument_expression_list Y_COMMA assignment_expression  */
#line 243 "c11ansi.y"
                                                                 { (yyval.expression) = createCTree2(createConstr1Label(LABCT_EXPR_SEPARATOR, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2237 "c11ansi.tab.c"
    break;

  case 30: /* unary_expression: postfix_expression  */
#line 247 "c11ansi.y"
                                                          { (yyval.expression) = (yyvsp[0].expression); }
#line 2243 "c11ansi.tab.c"
    break;

  case 31: /* unary_expression: Y_PLUS_PLUS unary_expression  */
#line 248 "c11ansi.y"
                                                          { (yyval.expression) = createCTree1(createConstr1Label(LABCT_PLUS_PLUS, (yyvsp[-1].token)), (yyvsp[0].expression)); }
#line 2249 "c11ansi.tab.c"
    break;

  case 32: /* unary_expression: Y_MINUS_MINUS unary_expression  */
#line 249 "c11ansi.y"
                                                          { (yyval.expression) = createCTree1(createConstr1Label(LABCT_MINUS_MINUS, (yyvsp[-1].token)), (yyvsp[0].expression)); }
#line 2255 "c11ansi.tab.c"
    break;

  case 33: /* unary_expression: unary_operator cast_expression  */
#line 250 "c11ansi.y"
                                                          { (yyval.expression) = createCTree1((yyvsp[-1].label), (yyvsp[0].expression)); }
#line 2261 "c11ansi.tab.c"
    break;

  case 34: /* unary_expression: Y_SIZEOF unary_expression  */
#line 251 "c11ansi.y"
                                                          { (yyval.expression) = createCTree1(createConstr1Label(LABCT_SIZEOF_EXPR, (yyvsp[-1].token)), (yyvsp[0].expression)); }
#line 2267 "c11ansi.tab.c"
    break;

  case 35: /* unary_expression: Y_SIZEOF Y_LEFT_PAREN type_name Y_RIGHT_PAREN  */
#line 252 "c11ansi.y"
                                                          { (yyval.expression) = createCTreeRoot(createConstr3Label(LABCT_SIZEOF_TYPE, (yyvsp[-3].token), (yyvsp[-2].token), (yyvsp[0].token))); }
#line 2273 "c11ansi.tab.c"
    break;

  case 36: /* unary_expression: Y_ALIGNOF Y_LEFT_PAREN type_name Y_RIGHT_PAREN  */
#line 253 "c11ansi.y"
                                                          { (yyval.expression) = createCTreeRoot(createConstr3Label(LABCT_ALIGNOF_TYPE, (yyvsp[-3].token), (yyvsp[-2].token), (yyvsp[0].token))); }
#line 2279 "c11ansi.tab.c"
    break;

  case 37: /* unary_operator: Y_AND  */
#line 257 "c11ansi.y"
                        { (yyval.label) = createConstr1Label(LABCT_ADDR_OF_VALUE, (yyvsp[0].token)); }
#line 2285 "c11ansi.tab.c"
    break;

  case 38: /* unary_operator: Y_TIMES  */
#line 258 "c11ansi.y"
                        { (yyval.label) = createConstr1Label(LABCT_VALUE_AT_ADDR, (yyvsp[0].token)); }
#line 2291 "c11ansi.tab.c"
    break;

  case 39: /* unary_operator: Y_PLUS  */
#line 259 "c11ansi.y"
                        { (yyval.label) = createConstr1Label(LABCT_UNARY_PLUS, (yyvsp[0].token)); }
#line 2297 "c11ansi.tab.c"
    break;

  case 40: /* unary_operator: Y_MINUS  */
#line 260 "c11ansi.y"
                        { (yyval.label) = createConstr1Label(LABCT_UNARY_MINUS, (yyvsp[0].token)); }
#line 2303 "c11ansi.tab.c"
    break;

  case 41: /* unary_operator: Y_TILDE  */
#line 261 "c11ansi.y"
                        { (yyval.label) = createConstr1Label(LABCT_TILDE, (yyvsp[0].token)); }
#line 2309 "c11ansi.tab.c"
    break;

  case 42: /* unary_operator: Y_EXCLAMATION  */
#line 262 "c11ansi.y"
                        { (yyval.label) = createConstr1Label(LABCT_EXCLAMATION, (yyvsp[0].token)); }
#line 2315 "c11ansi.tab.c"
    break;

  case 43: /* cast_expression: unary_expression  */
#line 266 "c11ansi.y"
                                                               { (yyval.expression) = (yyvsp[0].expression); }
#line 2321 "c11ansi.tab.c"
    break;

  case 44: /* cast_expression: Y_LEFT_PAREN type_name Y_RIGHT_PAREN cast_expression  */
#line 267 "c11ansi.y"
                                                               { (yyval.expression) = NULL; }
#line 2327 "c11ansi.tab.c"
    break;

  case 45: /* multiplicative_expression: cast_expression  */
#line 271 "c11ansi.y"
                          { (yyval.expression) = (yyvsp[0].expression); }
#line 2333 "c11ansi.tab.c"
    break;

  case 46: /* multiplicative_expression: multiplicative_expression Y_TIMES cast_expression  */
#line 272 "c11ansi.y"
                                                              { (yyval.expression) = createCTree2(createConstr1Label(LABCT_TIMES, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2339 "c11ansi.tab.c"
    break;

  case 47: /* multiplicative_expression: multiplicative_expression Y_DIVIDE cast_expression  */
#line 273 "c11ansi.y"
                                                              { (yyval.expression) = createCTree2(createConstr1Label(LABCT_DIVIDE, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2345 "c11ansi.tab.c"
    break;

  case 48: /* multiplicative_expression: multiplicative_expression Y_PERCENT cast_expression  */
#line 274 "c11ansi.y"
                                                              { (yyval.expression) = createCTree2(createConstr1Label(LABCT_PERCENT, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2351 "c11ansi.tab.c"
    break;

  case 49: /* additive_expression: multiplicative_expression  */
#line 278 "c11ansi.y"
                                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2357 "c11ansi.tab.c"
    break;

  case 50: /* additive_expression: additive_expression Y_PLUS multiplicative_expression  */
#line 279 "c11ansi.y"
                                                                { (yyval.expression) = createCTree2(createConstr1Label(LABCT_PLUS, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2363 "c11ansi.tab.c"
    break;

  case 51: /* additive_expression: additive_expression Y_MINUS multiplicative_expression  */
#line 280 "c11ansi.y"
                                                                { (yyval.expression) = createCTree2(createConstr1Label(LABCT_MINUS, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2369 "c11ansi.tab.c"
    break;

  case 52: /* shift_expression: additive_expression  */
#line 284 "c11ansi.y"
                                                         { (yyval.expression) = (yyvsp[0].expression); }
#line 2375 "c11ansi.tab.c"
    break;

  case 53: /* shift_expression: shift_expression Y_RSHIFT additive_expression  */
#line 285 "c11ansi.y"
                                                         { (yyval.expression) = createCTree2(createConstr1Label(LABCT_TIMES, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2381 "c11ansi.tab.c"
    break;

  case 54: /* shift_expression: shift_expression Y_LSHIFT additive_expression  */
#line 286 "c11ansi.y"
                                                         { (yyval.expression) = createCTree2(createConstr1Label(LABCT_TIMES, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2387 "c11ansi.tab.c"
    break;

  case 55: /* relational_expression: shift_expression  */
#line 290 "c11ansi.y"
                                                      { (yyval.expression) = (yyvsp[0].expression); }
#line 2393 "c11ansi.tab.c"
    break;

  case 56: /* relational_expression: relational_expression Y_LT shift_expression  */
#line 291 "c11ansi.y"
                                                      { (yyval.expression) = createCTree2(createConstr1Label(LABCT_LT, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2399 "c11ansi.tab.c"
    break;

  case 57: /* relational_expression: relational_expression Y_GT shift_expression  */
#line 292 "c11ansi.y"
                                                      { (yyval.expression) = createCTree2(createConstr1Label(LABCT_GT, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2405 "c11ansi.tab.c"
    break;

  case 58: /* relational_expression: relational_expression Y_LE shift_expression  */
#line 293 "c11ansi.y"
                                                      { (yyval.expression) = createCTree2(createConstr1Label(LABCT_LE, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2411 "c11ansi.tab.c"
    break;

  case 59: /* relational_expression: relational_expression Y_GE shift_expression  */
#line 294 "c11ansi.y"
                                                      { (yyval.expression) = createCTree2(createConstr1Label(LABCT_GE, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2417 "c11ansi.tab.c"
    break;

  case 60: /* equality_expression: relational_expression  */
#line 298 "c11ansi.y"
                                                         { (yyval.expression) = (yyvsp[0].expression); }
#line 2423 "c11ansi.tab.c"
    break;

  case 61: /* equality_expression: equality_expression Y_EQ relational_expression  */
#line 299 "c11ansi.y"
                                                         { (yyval.expression) = createCTree2(createConstr1Label(LABCT_EQ, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2429 "c11ansi.tab.c"
    break;

  case 62: /* equality_expression: equality_expression Y_NE relational_expression  */
#line 300 "c11ansi.y"
                                                         { (yyval.expression) = createCTree2(createConstr1Label(LABCT_NE, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2435 "c11ansi.tab.c"
    break;

  case 63: /* and_expression: equality_expression  */
#line 304 "c11ansi.y"
                                                   { (yyval.expression) = (yyvsp[0].expression); }
#line 2441 "c11ansi.tab.c"
    break;

  case 64: /* and_expression: and_expression Y_AND equality_expression  */
#line 305 "c11ansi.y"
                                                   { (yyval.expression) = createCTree2(createConstr1Label(LABCT_AND, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2447 "c11ansi.tab.c"
    break;

  case 65: /* exclusive_or_expression: and_expression  */
#line 309 "c11ansi.y"
                                                       { (yyval.expression) = (yyvsp[0].expression); }
#line 2453 "c11ansi.tab.c"
    break;

  case 66: /* exclusive_or_expression: exclusive_or_expression Y_XOR and_expression  */
#line 310 "c11ansi.y"
                                                       { (yyval.expression) = createCTree2(createConstr1Label(LABCT_XOR, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2459 "c11ansi.tab.c"
    break;

  case 67: /* inclusive_or_expression: exclusive_or_expression  */
#line 314 "c11ansi.y"
                                                               { (yyval.expression) = (yyvsp[0].expression); }
#line 2465 "c11ansi.tab.c"
    break;

  case 68: /* inclusive_or_expression: inclusive_or_expression Y_OR exclusive_or_expression  */
#line 315 "c11ansi.y"
                                                               { (yyval.expression) = createCTree2(createConstr1Label(LABCT_OR, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2471 "c11ansi.tab.c"
    break;

  case 69: /* logical_and_expression: inclusive_or_expression  */
#line 319 "c11ansi.y"
                                                                    { (yyval.expression) = (yyvsp[0].expression); }
#line 2477 "c11ansi.tab.c"
    break;

  case 70: /* logical_and_expression: logical_and_expression Y_AND_AND inclusive_or_expression  */
#line 320 "c11ansi.y"
                                                                    { (yyval.expression) = createCTree2(createConstr1Label(LABCT_AND_AND, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2483 "c11ansi.tab.c"
    break;

  case 71: /* logical_or_expression: logical_and_expression  */
#line 324 "c11ansi.y"
                                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2489 "c11ansi.tab.c"
    break;

  case 72: /* logical_or_expression: logical_or_expression Y_OR_OR logical_and_expression  */
#line 325 "c11ansi.y"
                                                                { (yyval.expression) = createCTree2(createConstr1Label(LABCT_OR_OR, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2495 "c11ansi.tab.c"
    break;

  case 73: /* conditional_expression: logical_or_expression  */
#line 329 "c11ansi.y"
                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2501 "c11ansi.tab.c"
    break;

  case 74: /* conditional_expression: logical_or_expression Y_QUESTION expression Y_COLON conditional_expression  */
#line 330 "c11ansi.y"
                                                                                     { (yyval.expression) = createCTree2(createConstr1Label(LABCT_QUESTION, (yyvsp[-3].token)), (yyvsp[-4].expression), createCTree2(createConstr1Label(LABCT_COLON, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression))); }
#line 2507 "c11ansi.tab.c"
    break;

  case 75: /* assignment_expression: conditional_expression  */
#line 334 "c11ansi.y"
                                                                      { (yyval.expression) = (yyvsp[0].expression); }
#line 2513 "c11ansi.tab.c"
    break;

  case 76: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 335 "c11ansi.y"
                                                                      { (yyval.expression) = createCTree2((yyvsp[-1].label), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2519 "c11ansi.tab.c"
    break;

  case 77: /* assignment_operator: Y_EQUAL  */
#line 339 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_EQ, (yyvsp[0].token)); }
#line 2525 "c11ansi.tab.c"
    break;

  case 78: /* assignment_operator: Y_TIMES_EQUAL  */
#line 340 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_TIMES_EQUAL, (yyvsp[0].token)); }
#line 2531 "c11ansi.tab.c"
    break;

  case 79: /* assignment_operator: Y_DIVIDE_EQUAL  */
#line 341 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_DIVIDE_EQUAL, (yyvsp[0].token)); }
#line 2537 "c11ansi.tab.c"
    break;

  case 80: /* assignment_operator: Y_PERCENT_EQUAL  */
#line 342 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_PERCENT_EQUAL, (yyvsp[0].token)); }
#line 2543 "c11ansi.tab.c"
    break;

  case 81: /* assignment_operator: Y_PLUS_EQUAL  */
#line 343 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_PLUS_EQUAL, (yyvsp[0].token)); }
#line 2549 "c11ansi.tab.c"
    break;

  case 82: /* assignment_operator: Y_MINUS_EQUAL  */
#line 344 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_MINUS_EQUAL, (yyvsp[0].token)); }
#line 2555 "c11ansi.tab.c"
    break;

  case 83: /* assignment_operator: Y_LSHIFT_EQUAL  */
#line 345 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_LSHIFT_EQUAL, (yyvsp[0].token)); }
#line 2561 "c11ansi.tab.c"
    break;

  case 84: /* assignment_operator: Y_RSHIFT_EQUAL  */
#line 346 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_RSHIFT_EQUAL, (yyvsp[0].token)); }
#line 2567 "c11ansi.tab.c"
    break;

  case 85: /* assignment_operator: Y_AND_EQUAL  */
#line 347 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_AND_EQUAL, (yyvsp[0].token)); }
#line 2573 "c11ansi.tab.c"
    break;

  case 86: /* assignment_operator: Y_XOR_EQUAL  */
#line 348 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_XOR_EQUAL, (yyvsp[0].token)); }
#line 2579 "c11ansi.tab.c"
    break;

  case 87: /* assignment_operator: Y_OR_EQUAL  */
#line 349 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_OR_EQUAL, (yyvsp[0].token)); }
#line 2585 "c11ansi.tab.c"
    break;

  case 88: /* expression: assignment_expression  */
#line 353 "c11ansi.y"
                                                   { (yyval.expression) = (yyvsp[0].expression); }
#line 2591 "c11ansi.tab.c"
    break;

  case 89: /* expression: expression Y_COMMA assignment_expression  */
#line 354 "c11ansi.y"
                                                   { (yyval.expression) = createCTree2(createConstr1Label(LABCT_EXPR_SEPARATOR, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2597 "c11ansi.tab.c"
    break;

  case 90: /* constant_expression: conditional_expression  */
#line 358 "c11ansi.y"
                                  { (yyval.expression) = (yyvsp[0].expression); }
#line 2603 "c11ansi.tab.c"
    break;

  case 91: /* declaration: declaration_specifiers Y_SEMICOLON  */
#line 362 "c11ansi.y"
                                                                  { (yyval.declaration) = createDeclaration((yyvsp[-1].declSpecifiers),NULL,NULL); }
#line 2609 "c11ansi.tab.c"
    break;

  case 92: /* declaration: declaration_specifiers init_declarator_list Y_SEMICOLON  */
#line 363 "c11ansi.y"
                                                                  { (yyval.declaration) = createDeclaration((yyvsp[-2].declSpecifiers),(yyvsp[-1].initDeclaratorList),NULL); }
#line 2615 "c11ansi.tab.c"
    break;

  case 93: /* declaration: static_assert_declaration  */
#line 364 "c11ansi.y"
                                                                  { (yyval.declaration) = createDeclaration(NULL,NULL,(yyvsp[0].staticAssertDecl)); }
#line 2621 "c11ansi.tab.c"
    break;

  case 94: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 368 "c11ansi.y"
                                                         { (yyval.declSpecifiers) = createDeclarationSpecifiers1((yyvsp[-1].token),(yyvsp[0].declSpecifiers)); }
#line 2627 "c11ansi.tab.c"
    break;

  case 95: /* declaration_specifiers: storage_class_specifier  */
#line 369 "c11ansi.y"
                                                         { (yyval.declSpecifiers) = createDeclarationSpecifiers1((yyvsp[0].token),NULL); }
#line 2633 "c11ansi.tab.c"
    break;

  case 96: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 370 "c11ansi.y"
                                                         { (yyval.declSpecifiers) = createDeclarationSpecifiers2((yyvsp[-1].typeSpecifier),(yyvsp[0].declSpecifiers)); }
#line 2639 "c11ansi.tab.c"
    break;

  case 97: /* declaration_specifiers: type_specifier  */
#line 371 "c11ansi.y"
                                                         { (yyval.declSpecifiers) = createDeclarationSpecifiers2((yyvsp[0].typeSpecifier),NULL); }
#line 2645 "c11ansi.tab.c"
    break;

  case 98: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 372 "c11ansi.y"
                                                         { (yyval.declSpecifiers) = createDeclarationSpecifiers1((yyvsp[-1].token),(yyvsp[0].declSpecifiers)); }
#line 2651 "c11ansi.tab.c"
    break;

  case 99: /* declaration_specifiers: type_qualifier  */
#line 373 "c11ansi.y"
                                                         { (yyval.declSpecifiers) = createDeclarationSpecifiers1((yyvsp[0].token),NULL); }
#line 2657 "c11ansi.tab.c"
    break;

  case 100: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 374 "c11ansi.y"
                                                         { (yyval.declSpecifiers) = createDeclarationSpecifiers1((yyvsp[-1].token),(yyvsp[0].declSpecifiers)); }
#line 2663 "c11ansi.tab.c"
    break;

  case 101: /* declaration_specifiers: function_specifier  */
#line 375 "c11ansi.y"
                                                         { (yyval.declSpecifiers) = createDeclarationSpecifiers1((yyvsp[0].token),NULL); }
#line 2669 "c11ansi.tab.c"
    break;

  case 102: /* declaration_specifiers: alignment_specifier declaration_specifiers  */
#line 376 "c11ansi.y"
                                                         { (yyval.declSpecifiers) = createDeclarationSpecifiers1((yyvsp[-1].token),(yyvsp[0].declSpecifiers)); }
#line 2675 "c11ansi.tab.c"
    break;

  case 103: /* declaration_specifiers: alignment_specifier  */
#line 377 "c11ansi.y"
                                                         { (yyval.declSpecifiers) = createDeclarationSpecifiers1((yyvsp[0].token),NULL); }
#line 2681 "c11ansi.tab.c"
    break;

  case 104: /* init_declarator_list: init_declarator  */
#line 381 "c11ansi.y"
                                                        { (yyval.initDeclaratorList) = NULL; }
#line 2687 "c11ansi.tab.c"
    break;

  case 105: /* init_declarator_list: init_declarator_list Y_COMMA init_declarator  */
#line 382 "c11ansi.y"
                                                        { (yyval.initDeclaratorList) = NULL; }
#line 2693 "c11ansi.tab.c"
    break;

  case 108: /* storage_class_specifier: Y_TYPEDEF  */
#line 391 "c11ansi.y"
                              { (yyval.token) = (yyvsp[0].token); }
#line 2699 "c11ansi.tab.c"
    break;

  case 109: /* storage_class_specifier: Y_EXTERN  */
#line 392 "c11ansi.y"
                          { (yyval.token) = (yyvsp[0].token); }
#line 2705 "c11ansi.tab.c"
    break;

  case 110: /* storage_class_specifier: Y_STATIC  */
#line 393 "c11ansi.y"
                          { (yyval.token) = (yyvsp[0].token); }
#line 2711 "c11ansi.tab.c"
    break;

  case 111: /* storage_class_specifier: Y_THREAD_LOCAL  */
#line 394 "c11ansi.y"
                          { (yyval.token) = (yyvsp[0].token); }
#line 2717 "c11ansi.tab.c"
    break;

  case 112: /* storage_class_specifier: Y_AUTO  */
#line 395 "c11ansi.y"
                          { (yyval.token) = (yyvsp[0].token); }
#line 2723 "c11ansi.tab.c"
    break;

  case 113: /* storage_class_specifier: Y_REGISTER  */
#line 396 "c11ansi.y"
                          { (yyval.token) = (yyvsp[0].token); }
#line 2729 "c11ansi.tab.c"
    break;

  case 114: /* type_specifier: Y_VOID  */
#line 400 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2735 "c11ansi.tab.c"
    break;

  case 115: /* type_specifier: Y_CHAR  */
#line 401 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2741 "c11ansi.tab.c"
    break;

  case 116: /* type_specifier: Y_SHORT  */
#line 402 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2747 "c11ansi.tab.c"
    break;

  case 117: /* type_specifier: Y_INT  */
#line 403 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2753 "c11ansi.tab.c"
    break;

  case 118: /* type_specifier: Y_LONG  */
#line 404 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2759 "c11ansi.tab.c"
    break;

  case 119: /* type_specifier: Y_LONG_LONG  */
#line 405 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2765 "c11ansi.tab.c"
    break;

  case 120: /* type_specifier: Y_FLOAT  */
#line 406 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2771 "c11ansi.tab.c"
    break;

  case 121: /* type_specifier: Y_DOUBLE  */
#line 407 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2777 "c11ansi.tab.c"
    break;

  case 122: /* type_specifier: Y_LONG_DOUBLE  */
#line 408 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2783 "c11ansi.tab.c"
    break;

  case 123: /* type_specifier: Y_SIGNED  */
#line 409 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2789 "c11ansi.tab.c"
    break;

  case 124: /* type_specifier: Y_UNSIGNED  */
#line 410 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2795 "c11ansi.tab.c"
    break;

  case 125: /* type_specifier: Y_BOOL  */
#line 411 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2801 "c11ansi.tab.c"
    break;

  case 126: /* type_specifier: Y_COMPLEX  */
#line 412 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2807 "c11ansi.tab.c"
    break;

  case 127: /* type_specifier: Y_IMAGINARY  */
#line 413 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2813 "c11ansi.tab.c"
    break;

  case 128: /* type_specifier: atomic_type_specifier  */
#line 414 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier2((yyvsp[0].atomicTypeSpecifier)); }
#line 2819 "c11ansi.tab.c"
    break;

  case 129: /* type_specifier: struct_or_union_specifier  */
#line 415 "c11ansi.y"
                                    { (yyval.typeSpecifier) = NULL; }
#line 2825 "c11ansi.tab.c"
    break;

  case 130: /* type_specifier: enum_specifier  */
#line 416 "c11ansi.y"
                                    { (yyval.typeSpecifier) = NULL; }
#line 2831 "c11ansi.tab.c"
    break;

  case 131: /* type_specifier: Y_TYPEDEF_NAME  */
#line 417 "c11ansi.y"
                                    { (yyval.typeSpecifier) = createTypeSpecifier((yyvsp[0].token)); }
#line 2837 "c11ansi.tab.c"
    break;

  case 135: /* struct_or_union: Y_STRUCT  */
#line 427 "c11ansi.y"
                    { (yyval.token) = (yyvsp[0].token); }
#line 2843 "c11ansi.tab.c"
    break;

  case 136: /* struct_or_union: Y_UNION  */
#line 428 "c11ansi.y"
                    { (yyval.token) = (yyvsp[0].token); }
#line 2849 "c11ansi.tab.c"
    break;

  case 137: /* struct_declaration_list: struct_declaration  */
#line 432 "c11ansi.y"
                                                     { (yyval.list) = createStructDeclarationList((yyvsp[0].structDeclaration),NULL); }
#line 2855 "c11ansi.tab.c"
    break;

  case 138: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 433 "c11ansi.y"
                                                     { (yyval.list) = createStructDeclarationList((yyvsp[0].structDeclaration),(yyvsp[-1].list)); }
#line 2861 "c11ansi.tab.c"
    break;

  case 139: /* struct_declaration: specifier_qualifier_list Y_SEMICOLON  */
#line 437 "c11ansi.y"
                                                                       { (yyval.structDeclaration) = createStructDeclaration((yyvsp[-1].list),NULL,NULL); }
#line 2867 "c11ansi.tab.c"
    break;

  case 140: /* struct_declaration: specifier_qualifier_list struct_declarator_list Y_SEMICOLON  */
#line 438 "c11ansi.y"
                                                                       { (yyval.structDeclaration) = createStructDeclaration((yyvsp[-2].list),(yyvsp[-1].list),NULL); }
#line 2873 "c11ansi.tab.c"
    break;

  case 141: /* struct_declaration: static_assert_declaration  */
#line 439 "c11ansi.y"
                                                                       { (yyval.structDeclaration) = createStructDeclaration(NULL,NULL,(yyvsp[0].staticAssertDecl)); }
#line 2879 "c11ansi.tab.c"
    break;

  case 142: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 443 "c11ansi.y"
                                                   { (yyval.list) = createSecifierQualifierList((yyvsp[-1].typeSpecifier),NULL,(yyvsp[0].list)); }
#line 2885 "c11ansi.tab.c"
    break;

  case 143: /* specifier_qualifier_list: type_specifier  */
#line 444 "c11ansi.y"
                                                   { (yyval.list) = createSecifierQualifierList((yyvsp[0].typeSpecifier),NULL,NULL); }
#line 2891 "c11ansi.tab.c"
    break;

  case 144: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 445 "c11ansi.y"
                                                   { (yyval.list) = createSecifierQualifierList(NULL,(yyvsp[-1].token),(yyvsp[0].list)); }
#line 2897 "c11ansi.tab.c"
    break;

  case 145: /* specifier_qualifier_list: type_qualifier  */
#line 446 "c11ansi.y"
                                                   { (yyval.list) = createSecifierQualifierList(NULL,(yyvsp[0].token),NULL); }
#line 2903 "c11ansi.tab.c"
    break;

  case 146: /* struct_declarator_list: struct_declarator  */
#line 450 "c11ansi.y"
                                                           { (yyval.list) = createStructDeclaratorList((yyvsp[0].structDeclarator),NULL); }
#line 2909 "c11ansi.tab.c"
    break;

  case 147: /* struct_declarator_list: struct_declarator_list Y_COMMA struct_declarator  */
#line 451 "c11ansi.y"
                                                           { (yyval.list) = createStructDeclaratorList((yyvsp[0].structDeclarator),(yyvsp[-2].list)); }
#line 2915 "c11ansi.tab.c"
    break;

  case 160: /* atomic_type_specifier: Y_ATOMIC Y_LEFT_PAREN type_name Y_RIGHT_PAREN  */
#line 479 "c11ansi.y"
                                                        { (yyval.atomicTypeSpecifier) = createAtomicTypeSpecifier((yyvsp[-3].token),(yyvsp[-1].token)); }
#line 2921 "c11ansi.tab.c"
    break;

  case 161: /* type_qualifier: Y_CONST  */
#line 483 "c11ansi.y"
                       { (yyval.token) = (yyvsp[0].token); }
#line 2927 "c11ansi.tab.c"
    break;

  case 162: /* type_qualifier: Y_RESTRICT  */
#line 484 "c11ansi.y"
                       { (yyval.token) = (yyvsp[0].token); }
#line 2933 "c11ansi.tab.c"
    break;

  case 163: /* type_qualifier: Y_VOLATILE  */
#line 485 "c11ansi.y"
                       { (yyval.token) = (yyvsp[0].token); }
#line 2939 "c11ansi.tab.c"
    break;

  case 164: /* type_qualifier: Y_ATOMIC  */
#line 486 "c11ansi.y"
                       { (yyval.token) = (yyvsp[0].token); }
#line 2945 "c11ansi.tab.c"
    break;

  case 165: /* function_specifier: Y_INLINE  */
#line 490 "c11ansi.y"
                      { (yyval.token) = (yyvsp[0].token);  }
#line 2951 "c11ansi.tab.c"
    break;

  case 166: /* function_specifier: Y_NORETURN  */
#line 491 "c11ansi.y"
                      { (yyval.token) = (yyvsp[0].token); }
#line 2957 "c11ansi.tab.c"
    break;

  case 167: /* alignment_specifier: Y_ALIGNAS Y_LEFT_PAREN type_name Y_RIGHT_PAREN  */
#line 495 "c11ansi.y"
                                                                    { (yyval.token) = (yyvsp[-3].token); }
#line 2963 "c11ansi.tab.c"
    break;

  case 168: /* alignment_specifier: Y_ALIGNAS Y_LEFT_PAREN constant_expression Y_RIGHT_PAREN  */
#line 496 "c11ansi.y"
                                                                    { (yyval.token) = (yyvsp[-3].token); }
#line 2969 "c11ansi.tab.c"
    break;

  case 200: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 556 "c11ansi.y"
                                                       { (yyval.token) = NULL; }
#line 2975 "c11ansi.tab.c"
    break;

  case 201: /* type_name: specifier_qualifier_list  */
#line 557 "c11ansi.y"
                                                       { (yyval.token) = NULL; }
#line 2981 "c11ansi.tab.c"
    break;

  case 226: /* initializer: Y_LEFT_BRACE initializer_list Y_RIGHT_BRACE  */
#line 591 "c11ansi.y"
                                                              { (yyval.expression) = createCTree1(createConstr2Label(LABCT_EXPR_LIST, (yyvsp[-2].token), (yyvsp[0].token)), (yyvsp[-1].expression)); }
#line 2987 "c11ansi.tab.c"
    break;

  case 227: /* initializer: Y_LEFT_BRACE initializer_list Y_COMMA Y_RIGHT_BRACE  */
#line 592 "c11ansi.y"
                                                              { (yyval.expression) = createCTree1(createConstr3Label(LABCT_EXPR_LIST, (yyvsp[-3].token), (yyvsp[-1].token), (yyvsp[0].token)), (yyvsp[-2].expression)); }
#line 2993 "c11ansi.tab.c"
    break;

  case 228: /* initializer: assignment_expression  */
#line 593 "c11ansi.y"
                                                              { (yyval.expression) = (yyvsp[0].expression); }
#line 2999 "c11ansi.tab.c"
    break;

  case 229: /* initializer_list: designation initializer  */
#line 597 "c11ansi.y"
                                                            { (yyval.expression) = NULL; }
#line 3005 "c11ansi.tab.c"
    break;

  case 230: /* initializer_list: initializer  */
#line 598 "c11ansi.y"
                                                            { (yyval.expression) = createCTree1(createConstr0Label(LABCT_EXPR_LIST), (yyvsp[0].expression)); }
#line 3011 "c11ansi.tab.c"
    break;

  case 231: /* initializer_list: initializer_list Y_COMMA designation initializer  */
#line 599 "c11ansi.y"
                                                            { (yyval.expression) = NULL; }
#line 3017 "c11ansi.tab.c"
    break;

  case 232: /* initializer_list: initializer_list Y_COMMA initializer  */
#line 600 "c11ansi.y"
                                                            { (yyval.expression) = createCTree2(createConstr1Label(LABCT_EXPR_LIST, (yyvsp[-1].token)), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 3023 "c11ansi.tab.c"
    break;

  case 238: /* static_assert_declaration: Y_STATIC_ASSERT Y_LEFT_PAREN constant_expression Y_COMMA "sting_literal" Y_RIGHT_PAREN Y_SEMICOLON  */
#line 618 "c11ansi.y"
                                                                                                            { (yyval.staticAssertDecl) = NULL; }
#line 3029 "c11ansi.tab.c"
    break;

  case 265: /* jump_statement: Y_GOTO "identifier" Y_SEMICOLON  */
#line 672 "c11ansi.y"
                                           { printf("jump_statement -> Y_GOTO IDENTIFIER Y_SEMICOLON\n"); }
#line 3035 "c11ansi.tab.c"
    break;

  case 266: /* jump_statement: Y_CONTINUE Y_SEMICOLON  */
#line 673 "c11ansi.y"
                                           { printf("jump_statement -> Y_CONTINUE Y_SEMICOLON\n"); }
#line 3041 "c11ansi.tab.c"
    break;

  case 267: /* jump_statement: Y_BREAK Y_SEMICOLON  */
#line 674 "c11ansi.y"
                                           { printf("jump_statement -> Y_BREAK Y_SEMICOLON\n"); }
#line 3047 "c11ansi.tab.c"
    break;

  case 268: /* jump_statement: Y_RETURN Y_SEMICOLON  */
#line 675 "c11ansi.y"
                                           { printf("jump_statement -> Y_RETURN Y_SEMICOLON\n"); }
#line 3053 "c11ansi.tab.c"
    break;

  case 269: /* jump_statement: Y_RETURN expression Y_SEMICOLON  */
#line 676 "c11ansi.y"
                                           { printf("jump_statement -> Y_RETURN expression Y_SEMICOLON\n"); }
#line 3059 "c11ansi.tab.c"
    break;

  case 270: /* translation_unit: external_declaration  */
#line 680 "c11ansi.y"
                                                 { printf("translation_unit -> external_declaration\n\n"); }
#line 3065 "c11ansi.tab.c"
    break;

  case 271: /* translation_unit: translation_unit external_declaration  */
#line 681 "c11ansi.y"
                                                 { printf("translation_unit -> translation_unit external_declaration\n\n"); }
#line 3071 "c11ansi.tab.c"
    break;

  case 272: /* external_declaration: function_definition  */
#line 685 "c11ansi.y"
                                { printf("external_declaration -> function_definition\n"); }
#line 3077 "c11ansi.tab.c"
    break;

  case 273: /* external_declaration: declaration  */
#line 686 "c11ansi.y"
                                { printf("external_declaration -> declaration\n"); }
#line 3083 "c11ansi.tab.c"
    break;

  case 274: /* function_definition: declaration_specifiers declarator declaration_list compound_statement  */
#line 690 "c11ansi.y"
                                                                                   { printf("function_definition -> declaration_specifiers declarator declaration_list compound_statement\n"); }
#line 3089 "c11ansi.tab.c"
    break;

  case 275: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 691 "c11ansi.y"
                                                                                   { printf("function_definition -> declaration_specifiers declarator compound_statement\n"); }
#line 3095 "c11ansi.tab.c"
    break;


#line 3099 "c11ansi.tab.c"

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

#line 700 "c11ansi.y"

#include <stdio.h>

extern char * yytext;
extern int yylineno;

int yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** Line %d %s %s\n", yylineno, s, yytext);
	return 0;
}
