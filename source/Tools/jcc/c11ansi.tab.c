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
#define YYLAST   2678

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  130
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
/* YYNRULES -- Number of rules.  */
#define YYNRULES  271
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  466

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
       0,   198,   198,   199,   200,   201,   206,   207,   208,   212,
     216,   217,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   248,   249,   253,   254,   255,   256,   257,   258,
     259,   263,   264,   265,   266,   267,   268,   272,   273,   277,
     278,   279,   280,   284,   285,   286,   290,   291,   292,   296,
     297,   298,   299,   300,   304,   305,   306,   310,   311,   315,
     316,   320,   321,   325,   326,   330,   331,   335,   336,   340,
     341,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   359,   360,   364,   368,   369,   370,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   387,   388,
     392,   393,   397,   398,   399,   400,   401,   402,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   427,   428,   429,   433,
     434,   438,   439,   443,   444,   445,   449,   450,   451,   452,
     456,   457,   461,   462,   463,   467,   468,   469,   470,   471,
     475,   476,   480,   481,   485,   489,   490,   491,   492,   496,
     497,   501,   502,   506,   507,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   528,
     529,   530,   531,   535,   536,   541,   542,   546,   547,   551,
     552,   553,   557,   558,   562,   563,   567,   568,   569,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     597,   598,   599,   603,   604,   605,   606,   610,   614,   615,
     619,   620,   624,   628,   629,   630,   631,   632,   633,   637,
     638,   639,   643,   644,   648,   649,   653,   654,   658,   659,
     663,   664,   665,   669,   670,   671,   672,   673,   674,   678,
     679,   680,   681,   682,   686,   687,   691,   692,   696,   697,
     701,   702
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

#define YYPACT_NINF (-341)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

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
#line 198 "c11ansi.y"
                                                { (yyval.tree) = createCTreeRoot(createTokenLabel((yyvsp[0].token))); }
#line 2091 "c11ansi.tab.c"
    break;

  case 3: /* primary_expression: constant  */
#line 199 "c11ansi.y"
                                                { (yyval.tree) = createCTreeRoot(createTokenLabel((yyvsp[0].token))); }
#line 2097 "c11ansi.tab.c"
    break;

  case 4: /* primary_expression: string  */
#line 200 "c11ansi.y"
                                                { (yyval.tree) = createCTreeRoot(createTokenLabel((yyvsp[0].token))); }
#line 2103 "c11ansi.tab.c"
    break;

  case 5: /* primary_expression: Y_LEFT_PAREN expression Y_RIGHT_PAREN  */
#line 201 "c11ansi.y"
                                                { (yyval.tree) = createCTree1(createConstr2Label(LABCT_PAREN_EXPR, (yyvsp[-2].token), (yyvsp[0].token)), (yyvsp[-1].tree)); }
#line 2109 "c11ansi.tab.c"
    break;

  case 6: /* constant: "i_const"  */
#line 206 "c11ansi.y"
                                 {(yyval.token) = (yyvsp[0].token);}
#line 2115 "c11ansi.tab.c"
    break;

  case 7: /* constant: "f_const"  */
#line 207 "c11ansi.y"
                                 {(yyval.token) = (yyvsp[0].token);}
#line 2121 "c11ansi.tab.c"
    break;

  case 8: /* constant: Y_ENUMERATION_CONSTANT  */
#line 208 "c11ansi.y"
                                 {(yyval.token) = (yyvsp[0].token);}
#line 2127 "c11ansi.tab.c"
    break;

  case 9: /* enumeration_constant: "identifier"  */
#line 212 "c11ansi.y"
                     {(yyval.token) = (yyvsp[0].token);}
#line 2133 "c11ansi.tab.c"
    break;

  case 10: /* string: "sting_literal"  */
#line 216 "c11ansi.y"
                         {(yyval.token) = (yyvsp[0].token);}
#line 2139 "c11ansi.tab.c"
    break;

  case 11: /* string: Y_FUNC_NAME  */
#line 217 "c11ansi.y"
                         {(yyval.token) = (yyvsp[0].token);}
#line 2145 "c11ansi.tab.c"
    break;

  case 12: /* postfix_expression: primary_expression  */
#line 235 "c11ansi.y"
                                                                                   { (yyval.tree) = (yyvsp[0].tree); }
#line 2151 "c11ansi.tab.c"
    break;

  case 13: /* postfix_expression: postfix_expression Y_LEFT_BRACKET expression Y_RIGHT_BRACKET  */
#line 236 "c11ansi.y"
                                                                                   { (yyval.tree) = createCTree2(createConstr2Label(LABCT_INDEX, (yyvsp[-2].token), (yyvsp[0].token)), (yyvsp[-3].tree),  (yyvsp[-1].tree)); }
#line 2157 "c11ansi.tab.c"
    break;

  case 14: /* postfix_expression: postfix_expression Y_LEFT_PAREN Y_RIGHT_PAREN  */
#line 237 "c11ansi.y"
                                                                                   { (yyval.tree) = createCTree1(createConstr2Label(LABCT_CALL, (yyvsp[-1].token), (yyvsp[0].token)), (yyvsp[-2].tree)); }
#line 2163 "c11ansi.tab.c"
    break;

  case 15: /* postfix_expression: postfix_expression Y_LEFT_PAREN argument_expression_list Y_RIGHT_PAREN  */
#line 238 "c11ansi.y"
                                                                                   { (yyval.tree) = createCTree2(createConstr2Label(LABCT_CALL, (yyvsp[-2].token), (yyvsp[0].token)), (yyvsp[-3].tree), (yyvsp[-1].tree)); }
#line 2169 "c11ansi.tab.c"
    break;

  case 16: /* postfix_expression: postfix_expression Y_DOT "identifier"  */
#line 239 "c11ansi.y"
                                                                                   { (yyval.tree) = createCTree2(createConstr1Label(LABCT_DOT, (yyvsp[-1].token)), (yyvsp[-2].tree), createCTreeRoot(createTokenLabel((yyvsp[0].token)))); }
#line 2175 "c11ansi.tab.c"
    break;

  case 17: /* postfix_expression: postfix_expression Y_ARROW "identifier"  */
#line 240 "c11ansi.y"
                                                                                   { (yyval.tree) = createCTree2(createConstr1Label(LABCT_ARROW, (yyvsp[-1].token)), (yyvsp[-2].tree), createCTreeRoot(createTokenLabel((yyvsp[0].token)))); }
#line 2181 "c11ansi.tab.c"
    break;

  case 18: /* postfix_expression: postfix_expression Y_PLUS_PLUS  */
#line 241 "c11ansi.y"
                                                                                   { (yyval.tree) = createCTree1(createConstr1Label(LABCT_PLUS_PLUS, (yyvsp[0].token)), (yyvsp[-1].tree)); }
#line 2187 "c11ansi.tab.c"
    break;

  case 19: /* postfix_expression: postfix_expression Y_MINUS_MINUS  */
#line 242 "c11ansi.y"
                                                                                   { (yyval.tree) = createCTree1(createConstr1Label(LABCT_MINUS_MINUS, (yyvsp[0].token)), (yyvsp[-1].tree)); }
#line 2193 "c11ansi.tab.c"
    break;

  case 20: /* postfix_expression: Y_LEFT_PAREN type_name Y_RIGHT_PAREN Y_LEFT_BRACE initializer_list Y_RIGHT_BRACE  */
#line 243 "c11ansi.y"
                                                                                             { (yyval.tree) = createCTree2(createConstr4Label(LABCT_CAST_EXPR, (yyvsp[-5].token), (yyvsp[-3].token), (yyvsp[-2].token), (yyvsp[0].token)), (yyvsp[-4].tree), (yyvsp[-1].tree)); }
#line 2199 "c11ansi.tab.c"
    break;

  case 21: /* postfix_expression: Y_LEFT_PAREN type_name Y_RIGHT_PAREN Y_LEFT_BRACE initializer_list Y_COMMA Y_RIGHT_BRACE  */
#line 244 "c11ansi.y"
                                                                                                     { (yyval.tree) = createCTree2(createConstr5Label(LABCT_CAST_EXPR, (yyvsp[-6].token), (yyvsp[-4].token), (yyvsp[-3].token), (yyvsp[-1].token), (yyvsp[0].token)), (yyvsp[-5].tree), (yyvsp[-2].tree)); }
#line 2205 "c11ansi.tab.c"
    break;

  case 22: /* argument_expression_list: assignment_expression  */
#line 248 "c11ansi.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 2211 "c11ansi.tab.c"
    break;

  case 23: /* argument_expression_list: argument_expression_list Y_COMMA assignment_expression  */
#line 249 "c11ansi.y"
                                                                 { (yyval.tree) = createCTree2(createConstr1Label(LABCT_EXPR_SEPARATOR, (yyvsp[-1].token)), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 2217 "c11ansi.tab.c"
    break;

  case 24: /* unary_expression: postfix_expression  */
#line 253 "c11ansi.y"
                                                          { (yyval.tree) = (yyvsp[0].tree); }
#line 2223 "c11ansi.tab.c"
    break;

  case 25: /* unary_expression: Y_PLUS_PLUS unary_expression  */
#line 254 "c11ansi.y"
                                                          { (yyval.tree) = createCTree1(createConstr1Label(LABCT_PLUS_PLUS, (yyvsp[-1].token)), (yyvsp[0].tree)); }
#line 2229 "c11ansi.tab.c"
    break;

  case 26: /* unary_expression: Y_MINUS_MINUS unary_expression  */
#line 255 "c11ansi.y"
                                                          { (yyval.tree) = createCTree1(createConstr1Label(LABCT_MINUS_MINUS, (yyvsp[-1].token)), (yyvsp[0].tree)); }
#line 2235 "c11ansi.tab.c"
    break;

  case 27: /* unary_expression: unary_operator cast_expression  */
#line 256 "c11ansi.y"
                                                          { (yyval.tree) = createCTree1((yyvsp[-1].label), (yyvsp[0].tree)); }
#line 2241 "c11ansi.tab.c"
    break;

  case 28: /* unary_expression: Y_SIZEOF unary_expression  */
#line 257 "c11ansi.y"
                                                          { (yyval.tree) = createCTree1(createConstr1Label(LABCT_SIZEOF_EXPR, (yyvsp[-1].token)), (yyvsp[0].tree)); }
#line 2247 "c11ansi.tab.c"
    break;

  case 29: /* unary_expression: Y_SIZEOF Y_LEFT_PAREN type_name Y_RIGHT_PAREN  */
#line 258 "c11ansi.y"
                                                          { (yyval.tree) = createCTree1(createConstr3Label(LABCT_SIZEOF_TYPE, (yyvsp[-3].token), (yyvsp[-2].token), (yyvsp[0].token)), (yyvsp[-1].tree)); }
#line 2253 "c11ansi.tab.c"
    break;

  case 30: /* unary_expression: Y_ALIGNOF Y_LEFT_PAREN type_name Y_RIGHT_PAREN  */
#line 259 "c11ansi.y"
                                                          { (yyval.tree) = createCTree1(createConstr3Label(LABCT_ALIGNOF_TYPE, (yyvsp[-3].token), (yyvsp[-2].token), (yyvsp[0].token)), (yyvsp[-1].tree)); }
#line 2259 "c11ansi.tab.c"
    break;

  case 31: /* unary_operator: Y_AND  */
#line 263 "c11ansi.y"
                        { (yyval.label) = createConstr1Label(LABCT_ADDR_OF_VALUE, (yyvsp[0].token)); }
#line 2265 "c11ansi.tab.c"
    break;

  case 32: /* unary_operator: Y_TIMES  */
#line 264 "c11ansi.y"
                        { (yyval.label) = createConstr1Label(LABCT_VALUE_AT_ADDR, (yyvsp[0].token)); }
#line 2271 "c11ansi.tab.c"
    break;

  case 33: /* unary_operator: Y_PLUS  */
#line 265 "c11ansi.y"
                        { (yyval.label) = createConstr1Label(LABCT_UNARY_PLUS, (yyvsp[0].token)); }
#line 2277 "c11ansi.tab.c"
    break;

  case 34: /* unary_operator: Y_MINUS  */
#line 266 "c11ansi.y"
                        { (yyval.label) = createConstr1Label(LABCT_UNARY_MINUS, (yyvsp[0].token)); }
#line 2283 "c11ansi.tab.c"
    break;

  case 35: /* unary_operator: Y_TILDE  */
#line 267 "c11ansi.y"
                        { (yyval.label) = createConstr1Label(LABCT_TILDE, (yyvsp[0].token)); }
#line 2289 "c11ansi.tab.c"
    break;

  case 36: /* unary_operator: Y_EXCLAMATION  */
#line 268 "c11ansi.y"
                        { (yyval.label) = createConstr1Label(LABCT_EXCLAMATION, (yyvsp[0].token)); }
#line 2295 "c11ansi.tab.c"
    break;

  case 37: /* cast_expression: unary_expression  */
#line 272 "c11ansi.y"
                                                               { (yyval.tree) = (yyvsp[0].tree); }
#line 2301 "c11ansi.tab.c"
    break;

  case 38: /* cast_expression: Y_LEFT_PAREN type_name Y_RIGHT_PAREN cast_expression  */
#line 273 "c11ansi.y"
                                                               { (yyval.tree) = createCTree2(createConstr2Label(LABCT_CAST_EXPR, (yyvsp[-3].token), (yyvsp[-1].token)), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 2307 "c11ansi.tab.c"
    break;

  case 39: /* multiplicative_expression: cast_expression  */
#line 277 "c11ansi.y"
                          { (yyval.tree) = (yyvsp[0].tree); }
#line 2313 "c11ansi.tab.c"
    break;

  case 40: /* multiplicative_expression: multiplicative_expression Y_TIMES cast_expression  */
#line 278 "c11ansi.y"
                                                              { (yyval.tree) = createCTree2(createConstr1Label(LABCT_TIMES, (yyvsp[-1].token)), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 2319 "c11ansi.tab.c"
    break;

  case 41: /* multiplicative_expression: multiplicative_expression Y_DIVIDE cast_expression  */
#line 279 "c11ansi.y"
                                                              { (yyval.tree) = createCTree2(createConstr1Label(LABCT_DIVIDE, (yyvsp[-1].token)), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 2325 "c11ansi.tab.c"
    break;

  case 42: /* multiplicative_expression: multiplicative_expression Y_PERCENT cast_expression  */
#line 280 "c11ansi.y"
                                                              { (yyval.tree) = createCTree2(createConstr1Label(LABCT_PERCENT, (yyvsp[-1].token)), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 2331 "c11ansi.tab.c"
    break;

  case 43: /* additive_expression: multiplicative_expression  */
#line 284 "c11ansi.y"
                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2337 "c11ansi.tab.c"
    break;

  case 44: /* additive_expression: additive_expression Y_PLUS multiplicative_expression  */
#line 285 "c11ansi.y"
                                                                { (yyval.tree) = createCTree2(createConstr1Label(LABCT_PLUS, (yyvsp[-1].token)), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 2343 "c11ansi.tab.c"
    break;

  case 45: /* additive_expression: additive_expression Y_MINUS multiplicative_expression  */
#line 286 "c11ansi.y"
                                                                { (yyval.tree) = createCTree2(createConstr1Label(LABCT_MINUS, (yyvsp[-1].token)), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 2349 "c11ansi.tab.c"
    break;

  case 46: /* shift_expression: additive_expression  */
#line 290 "c11ansi.y"
                                                         { (yyval.tree) = (yyvsp[0].tree); }
#line 2355 "c11ansi.tab.c"
    break;

  case 47: /* shift_expression: shift_expression Y_RSHIFT additive_expression  */
#line 291 "c11ansi.y"
                                                         { (yyval.tree) = createCTree2(createConstr1Label(LABCT_TIMES, (yyvsp[-1].token)), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 2361 "c11ansi.tab.c"
    break;

  case 48: /* shift_expression: shift_expression Y_LSHIFT additive_expression  */
#line 292 "c11ansi.y"
                                                         { (yyval.tree) = createCTree2(createConstr1Label(LABCT_TIMES, (yyvsp[-1].token)), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 2367 "c11ansi.tab.c"
    break;

  case 49: /* relational_expression: shift_expression  */
#line 296 "c11ansi.y"
                                                      { (yyval.tree) = (yyvsp[0].tree); }
#line 2373 "c11ansi.tab.c"
    break;

  case 50: /* relational_expression: relational_expression Y_LT shift_expression  */
#line 297 "c11ansi.y"
                                                      { (yyval.tree) = createCTree2(createConstr1Label(LABCT_LT, (yyvsp[-1].token)), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 2379 "c11ansi.tab.c"
    break;

  case 51: /* relational_expression: relational_expression Y_GT shift_expression  */
#line 298 "c11ansi.y"
                                                      { (yyval.tree) = createCTree2(createConstr1Label(LABCT_GT, (yyvsp[-1].token)), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 2385 "c11ansi.tab.c"
    break;

  case 52: /* relational_expression: relational_expression Y_LE shift_expression  */
#line 299 "c11ansi.y"
                                                      { (yyval.tree) = createCTree2(createConstr1Label(LABCT_LE, (yyvsp[-1].token)), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 2391 "c11ansi.tab.c"
    break;

  case 53: /* relational_expression: relational_expression Y_GE shift_expression  */
#line 300 "c11ansi.y"
                                                      { (yyval.tree) = createCTree2(createConstr1Label(LABCT_GE, (yyvsp[-1].token)), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 2397 "c11ansi.tab.c"
    break;

  case 54: /* equality_expression: relational_expression  */
#line 304 "c11ansi.y"
                                                         { (yyval.tree) = (yyvsp[0].tree); }
#line 2403 "c11ansi.tab.c"
    break;

  case 55: /* equality_expression: equality_expression Y_EQ relational_expression  */
#line 305 "c11ansi.y"
                                                         { (yyval.tree) = createCTree2(createConstr1Label(LABCT_EQ, (yyvsp[-1].token)), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 2409 "c11ansi.tab.c"
    break;

  case 56: /* equality_expression: equality_expression Y_NE relational_expression  */
#line 306 "c11ansi.y"
                                                         { (yyval.tree) = createCTree2(createConstr1Label(LABCT_NE, (yyvsp[-1].token)), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 2415 "c11ansi.tab.c"
    break;

  case 57: /* and_expression: equality_expression  */
#line 310 "c11ansi.y"
                                                   { (yyval.tree) = (yyvsp[0].tree); }
#line 2421 "c11ansi.tab.c"
    break;

  case 58: /* and_expression: and_expression Y_AND equality_expression  */
#line 311 "c11ansi.y"
                                                   { (yyval.tree) = createCTree2(createConstr1Label(LABCT_AND, (yyvsp[-1].token)), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 2427 "c11ansi.tab.c"
    break;

  case 59: /* exclusive_or_expression: and_expression  */
#line 315 "c11ansi.y"
                                                       { (yyval.tree) = (yyvsp[0].tree); }
#line 2433 "c11ansi.tab.c"
    break;

  case 60: /* exclusive_or_expression: exclusive_or_expression Y_XOR and_expression  */
#line 316 "c11ansi.y"
                                                       { (yyval.tree) = createCTree2(createConstr1Label(LABCT_XOR, (yyvsp[-1].token)), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 2439 "c11ansi.tab.c"
    break;

  case 61: /* inclusive_or_expression: exclusive_or_expression  */
#line 320 "c11ansi.y"
                                                               { (yyval.tree) = (yyvsp[0].tree); }
#line 2445 "c11ansi.tab.c"
    break;

  case 62: /* inclusive_or_expression: inclusive_or_expression Y_OR exclusive_or_expression  */
#line 321 "c11ansi.y"
                                                               { (yyval.tree) = createCTree2(createConstr1Label(LABCT_OR, (yyvsp[-1].token)), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 2451 "c11ansi.tab.c"
    break;

  case 63: /* logical_and_expression: inclusive_or_expression  */
#line 325 "c11ansi.y"
                                                                    { (yyval.tree) = (yyvsp[0].tree); }
#line 2457 "c11ansi.tab.c"
    break;

  case 64: /* logical_and_expression: logical_and_expression Y_AND_AND inclusive_or_expression  */
#line 326 "c11ansi.y"
                                                                    { (yyval.tree) = createCTree2(createConstr1Label(LABCT_AND_AND, (yyvsp[-1].token)), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 2463 "c11ansi.tab.c"
    break;

  case 65: /* logical_or_expression: logical_and_expression  */
#line 330 "c11ansi.y"
                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2469 "c11ansi.tab.c"
    break;

  case 66: /* logical_or_expression: logical_or_expression Y_OR_OR logical_and_expression  */
#line 331 "c11ansi.y"
                                                                { (yyval.tree) = createCTree2(createConstr1Label(LABCT_OR_OR, (yyvsp[-1].token)), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 2475 "c11ansi.tab.c"
    break;

  case 67: /* conditional_expression: logical_or_expression  */
#line 335 "c11ansi.y"
                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2481 "c11ansi.tab.c"
    break;

  case 68: /* conditional_expression: logical_or_expression Y_QUESTION expression Y_COLON conditional_expression  */
#line 336 "c11ansi.y"
                                                                                     { (yyval.tree) = createCTree2(createConstr1Label(LABCT_QUESTION, (yyvsp[-3].token)), (yyvsp[-4].tree), createCTree2(createConstr1Label(LABCT_COLON, (yyvsp[-1].token)), (yyvsp[-2].tree), (yyvsp[0].tree))); }
#line 2487 "c11ansi.tab.c"
    break;

  case 69: /* assignment_expression: conditional_expression  */
#line 340 "c11ansi.y"
                                                                      { (yyval.tree) = (yyvsp[0].tree); }
#line 2493 "c11ansi.tab.c"
    break;

  case 70: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 341 "c11ansi.y"
                                                                      { (yyval.tree) = createCTree2((yyvsp[-1].label), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 2499 "c11ansi.tab.c"
    break;

  case 71: /* assignment_operator: Y_EQUAL  */
#line 345 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_EQ, (yyvsp[0].token)); }
#line 2505 "c11ansi.tab.c"
    break;

  case 72: /* assignment_operator: Y_TIMES_EQUAL  */
#line 346 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_TIMES_EQUAL, (yyvsp[0].token)); }
#line 2511 "c11ansi.tab.c"
    break;

  case 73: /* assignment_operator: Y_DIVIDE_EQUAL  */
#line 347 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_DIVIDE_EQUAL, (yyvsp[0].token)); }
#line 2517 "c11ansi.tab.c"
    break;

  case 74: /* assignment_operator: Y_PERCENT_EQUAL  */
#line 348 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_PERCENT_EQUAL, (yyvsp[0].token)); }
#line 2523 "c11ansi.tab.c"
    break;

  case 75: /* assignment_operator: Y_PLUS_EQUAL  */
#line 349 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_PLUS_EQUAL, (yyvsp[0].token)); }
#line 2529 "c11ansi.tab.c"
    break;

  case 76: /* assignment_operator: Y_MINUS_EQUAL  */
#line 350 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_MINUS_EQUAL, (yyvsp[0].token)); }
#line 2535 "c11ansi.tab.c"
    break;

  case 77: /* assignment_operator: Y_LSHIFT_EQUAL  */
#line 351 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_LSHIFT_EQUAL, (yyvsp[0].token)); }
#line 2541 "c11ansi.tab.c"
    break;

  case 78: /* assignment_operator: Y_RSHIFT_EQUAL  */
#line 352 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_RSHIFT_EQUAL, (yyvsp[0].token)); }
#line 2547 "c11ansi.tab.c"
    break;

  case 79: /* assignment_operator: Y_AND_EQUAL  */
#line 353 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_AND_EQUAL, (yyvsp[0].token)); }
#line 2553 "c11ansi.tab.c"
    break;

  case 80: /* assignment_operator: Y_XOR_EQUAL  */
#line 354 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_XOR_EQUAL, (yyvsp[0].token)); }
#line 2559 "c11ansi.tab.c"
    break;

  case 81: /* assignment_operator: Y_OR_EQUAL  */
#line 355 "c11ansi.y"
                           { (yyval.label) = createConstr1Label(LABCT_OR_EQUAL, (yyvsp[0].token)); }
#line 2565 "c11ansi.tab.c"
    break;

  case 82: /* expression: assignment_expression  */
#line 359 "c11ansi.y"
                                                   { (yyval.tree) = (yyvsp[0].tree); }
#line 2571 "c11ansi.tab.c"
    break;

  case 83: /* expression: expression Y_COMMA assignment_expression  */
#line 360 "c11ansi.y"
                                                   { (yyval.tree) = createCTree2(createConstr1Label(LABCT_EXPR_SEPARATOR, (yyvsp[-1].token)), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 2577 "c11ansi.tab.c"
    break;

  case 84: /* constant_expression: conditional_expression  */
#line 364 "c11ansi.y"
                                  { (yyval.tree) = (yyvsp[0].tree); }
#line 2583 "c11ansi.tab.c"
    break;

  case 85: /* declaration: declaration_specifiers Y_SEMICOLON  */
#line 368 "c11ansi.y"
                                                                   { (yyval.declList) = transformDecl((yyvsp[-1].dinfo)); zapToken((yyvsp[0].token)); }
#line 2589 "c11ansi.tab.c"
    break;

  case 86: /* declaration: declaration_specifiers init_declarator_list Y_SEMICOLON  */
#line 369 "c11ansi.y"
                                                                   { (yyval.declList) = transformDecl(addDeclInfoDclrList((yyvsp[-2].dinfo), (yyvsp[-1].dclrList))); zapToken((yyvsp[0].token)); }
#line 2595 "c11ansi.tab.c"
    break;

  case 87: /* declaration: static_assert_declaration  */
#line 370 "c11ansi.y"
                                                                   { (yyval.declList) = NULL; }
#line 2601 "c11ansi.tab.c"
    break;

  case 88: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 374 "c11ansi.y"
                                                         { (yyval.dinfo) = combine2DeclInfo((yyvsp[-1].dinfo), (yyvsp[0].dinfo)); }
#line 2607 "c11ansi.tab.c"
    break;

  case 89: /* declaration_specifiers: storage_class_specifier  */
#line 375 "c11ansi.y"
                                                         { (yyval.dinfo) = (yyvsp[0].dinfo); }
#line 2613 "c11ansi.tab.c"
    break;

  case 90: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 376 "c11ansi.y"
                                                         { (yyval.dinfo) = combine2DeclInfo((yyvsp[-1].dinfo), (yyvsp[0].dinfo)); }
#line 2619 "c11ansi.tab.c"
    break;

  case 91: /* declaration_specifiers: type_specifier  */
#line 377 "c11ansi.y"
                                                         { (yyval.dinfo) = (yyvsp[0].dinfo); }
#line 2625 "c11ansi.tab.c"
    break;

  case 92: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 378 "c11ansi.y"
                                                         { (yyval.dinfo) = combine2DeclInfo((yyvsp[-1].dinfo), (yyvsp[0].dinfo)); }
#line 2631 "c11ansi.tab.c"
    break;

  case 93: /* declaration_specifiers: type_qualifier  */
#line 379 "c11ansi.y"
                                                         { (yyval.dinfo) = (yyvsp[0].dinfo); }
#line 2637 "c11ansi.tab.c"
    break;

  case 94: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 380 "c11ansi.y"
                                                         { (yyval.dinfo) = combine2DeclInfo((yyvsp[-1].dinfo), (yyvsp[0].dinfo)); }
#line 2643 "c11ansi.tab.c"
    break;

  case 95: /* declaration_specifiers: function_specifier  */
#line 381 "c11ansi.y"
                                                         { (yyval.dinfo) = (yyvsp[0].dinfo); }
#line 2649 "c11ansi.tab.c"
    break;

  case 96: /* declaration_specifiers: alignment_specifier declaration_specifiers  */
#line 382 "c11ansi.y"
                                                         { (yyval.dinfo) = combine2DeclInfo((yyvsp[-1].dinfo), (yyvsp[0].dinfo)); }
#line 2655 "c11ansi.tab.c"
    break;

  case 97: /* declaration_specifiers: alignment_specifier  */
#line 383 "c11ansi.y"
                                                         { (yyval.dinfo) = (yyvsp[0].dinfo); }
#line 2661 "c11ansi.tab.c"
    break;

  case 98: /* init_declarator_list: init_declarator  */
#line 387 "c11ansi.y"
                                                       { (yyval.dclrList) = createDclrList((yyvsp[0].dclr)); }
#line 2667 "c11ansi.tab.c"
    break;

  case 99: /* init_declarator_list: init_declarator_list Y_COMMA init_declarator  */
#line 388 "c11ansi.y"
                                                       { (yyval.dclrList) = addDclrList((yyvsp[-2].dclrList),  (yyvsp[0].dclr)); zapToken((yyvsp[-1].token)); }
#line 2673 "c11ansi.tab.c"
    break;

  case 100: /* init_declarator: declarator Y_EQUAL initializer  */
#line 392 "c11ansi.y"
                                         { addDclrInitializer((yyvsp[-2].dclr), (yyvsp[-1].token), (yyvsp[0].tree));}
#line 2679 "c11ansi.tab.c"
    break;

  case 101: /* init_declarator: declarator  */
#line 393 "c11ansi.y"
                                                     { (yyval.dclr) = (yyvsp[0].dclr); }
#line 2685 "c11ansi.tab.c"
    break;

  case 102: /* storage_class_specifier: Y_TYPEDEF  */
#line 397 "c11ansi.y"
                              { (yyval.dinfo) = createStgClassDeclInfo(STG_TYPEDEF, (yyvsp[0].token)); }
#line 2691 "c11ansi.tab.c"
    break;

  case 103: /* storage_class_specifier: Y_EXTERN  */
#line 398 "c11ansi.y"
                          { (yyval.dinfo) = createStgClassDeclInfo(STG_EXTERN, (yyvsp[0].token)); }
#line 2697 "c11ansi.tab.c"
    break;

  case 104: /* storage_class_specifier: Y_STATIC  */
#line 399 "c11ansi.y"
                          { (yyval.dinfo) = createStgClassDeclInfo(STG_STATIC, (yyvsp[0].token)); }
#line 2703 "c11ansi.tab.c"
    break;

  case 105: /* storage_class_specifier: Y_THREAD_LOCAL  */
#line 400 "c11ansi.y"
                          { (yyval.dinfo) = createStgClassDeclInfo(STG_THREAD_LOCAL, (yyvsp[0].token)); }
#line 2709 "c11ansi.tab.c"
    break;

  case 106: /* storage_class_specifier: Y_AUTO  */
#line 401 "c11ansi.y"
                          { (yyval.dinfo) = createStgClassDeclInfo(STG_AUTO, (yyvsp[0].token)); }
#line 2715 "c11ansi.tab.c"
    break;

  case 107: /* storage_class_specifier: Y_REGISTER  */
#line 402 "c11ansi.y"
                          { (yyval.dinfo) = createStgClassDeclInfo(STG_REGISTER, (yyvsp[0].token)); }
#line 2721 "c11ansi.tab.c"
    break;

  case 108: /* type_specifier: Y_VOID  */
#line 406 "c11ansi.y"
                                    { (yyval.dinfo) = createDeclInfoSCALAR(STM_VOID); zapToken((yyvsp[0].token)); }
#line 2727 "c11ansi.tab.c"
    break;

  case 109: /* type_specifier: Y_CHAR  */
#line 407 "c11ansi.y"
                                    { (yyval.dinfo) = createDeclInfoSCALAR(STM_CHAR); zapToken((yyvsp[0].token)); }
#line 2733 "c11ansi.tab.c"
    break;

  case 110: /* type_specifier: Y_SHORT  */
#line 408 "c11ansi.y"
                                    { (yyval.dinfo) = createDeclInfoSCALAR(STM_SHORT); zapToken((yyvsp[0].token)); }
#line 2739 "c11ansi.tab.c"
    break;

  case 111: /* type_specifier: Y_INT  */
#line 409 "c11ansi.y"
                                    { (yyval.dinfo) = createDeclInfoSCALAR(STM_INT); zapToken((yyvsp[0].token)); }
#line 2745 "c11ansi.tab.c"
    break;

  case 112: /* type_specifier: Y_LONG  */
#line 410 "c11ansi.y"
                                    { (yyval.dinfo) = createDeclInfoSCALAR(STM_LONG); zapToken((yyvsp[0].token)); }
#line 2751 "c11ansi.tab.c"
    break;

  case 113: /* type_specifier: Y_LONG_LONG  */
#line 411 "c11ansi.y"
                                    { (yyval.dinfo) = createDeclInfoSCALAR(STM_LONG_LONG); zapToken((yyvsp[0].token)); }
#line 2757 "c11ansi.tab.c"
    break;

  case 114: /* type_specifier: Y_FLOAT  */
#line 412 "c11ansi.y"
                                    { (yyval.dinfo) = createDeclInfoSCALAR(STM_FLOAT); zapToken((yyvsp[0].token)); }
#line 2763 "c11ansi.tab.c"
    break;

  case 115: /* type_specifier: Y_DOUBLE  */
#line 413 "c11ansi.y"
                                    { (yyval.dinfo) = createDeclInfoSCALAR(STM_DOUBLE); zapToken((yyvsp[0].token)); }
#line 2769 "c11ansi.tab.c"
    break;

  case 116: /* type_specifier: Y_LONG_DOUBLE  */
#line 414 "c11ansi.y"
                                    { (yyval.dinfo) = createDeclInfoSCALAR(STM_LONG_DOUBLE); zapToken((yyvsp[0].token)); }
#line 2775 "c11ansi.tab.c"
    break;

  case 117: /* type_specifier: Y_SIGNED  */
#line 415 "c11ansi.y"
                                    { (yyval.dinfo) = createDeclInfoSCALAR(STM_SIGNED); zapToken((yyvsp[0].token)); }
#line 2781 "c11ansi.tab.c"
    break;

  case 118: /* type_specifier: Y_UNSIGNED  */
#line 416 "c11ansi.y"
                                    { (yyval.dinfo) = createDeclInfoSCALAR(STM_UNSIGNED); zapToken((yyvsp[0].token)); }
#line 2787 "c11ansi.tab.c"
    break;

  case 119: /* type_specifier: Y_BOOL  */
#line 417 "c11ansi.y"
                                    { (yyval.dinfo) = createDeclInfoSCALAR(STM_BOOL); zapToken((yyvsp[0].token)); }
#line 2793 "c11ansi.tab.c"
    break;

  case 120: /* type_specifier: Y_COMPLEX  */
#line 418 "c11ansi.y"
                                    { (yyval.dinfo) = createDeclInfoSCALAR(STM_COMPLEX); zapToken((yyvsp[0].token)); }
#line 2799 "c11ansi.tab.c"
    break;

  case 121: /* type_specifier: Y_IMAGINARY  */
#line 419 "c11ansi.y"
                                    { (yyval.dinfo) = createDeclInfoSCALAR(STM_IMAGINARY); zapToken((yyvsp[0].token)); }
#line 2805 "c11ansi.tab.c"
    break;

  case 122: /* type_specifier: atomic_type_specifier  */
#line 420 "c11ansi.y"
                                    { (yyval.dinfo) = createDeclInfoSCALAR(STM_ATOMIC); zapToken((yyvsp[0].token)); }
#line 2811 "c11ansi.tab.c"
    break;

  case 123: /* type_specifier: struct_or_union_specifier  */
#line 421 "c11ansi.y"
                                    { (yyval.dinfo) = createDeclInfoSCALAR(STM_STRUCT); zapToken((yyvsp[0].token)); }
#line 2817 "c11ansi.tab.c"
    break;

  case 124: /* type_specifier: enum_specifier  */
#line 422 "c11ansi.y"
                                    { (yyval.dinfo) = createDeclInfoSCALAR(STM_ENUM); zapToken((yyvsp[0].declEnum)); }
#line 2823 "c11ansi.tab.c"
    break;

  case 125: /* type_specifier: Y_TYPEDEF_NAME  */
#line 423 "c11ansi.y"
                                    { (yyval.dinfo) = createDeclInfoSCALAR(STM_TYPEDEF); zapToken((yyvsp[0].token)); }
#line 2829 "c11ansi.tab.c"
    break;

  case 129: /* struct_or_union: Y_STRUCT  */
#line 433 "c11ansi.y"
                   { (yyval.token) = (yyvsp[0].token); }
#line 2835 "c11ansi.tab.c"
    break;

  case 130: /* struct_or_union: Y_UNION  */
#line 434 "c11ansi.y"
                   { (yyval.token) = (yyvsp[0].token); }
#line 2841 "c11ansi.tab.c"
    break;

  case 131: /* struct_declaration_list: struct_declaration  */
#line 438 "c11ansi.y"
                                                     { (yyval.declList) = createDclrInfoList((yyvsp[0].dinfo)); }
#line 2847 "c11ansi.tab.c"
    break;

  case 132: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 439 "c11ansi.y"
                                                     { (yyval.declList) = addDclrInfoList((yyvsp[-1].declList), (yyvsp[0].dinfo)); }
#line 2853 "c11ansi.tab.c"
    break;

  case 133: /* struct_declaration: specifier_qualifier_list Y_SEMICOLON  */
#line 443 "c11ansi.y"
                                                                      { (yyval.dinfo) = (yyvsp[-1].dinfo); zapToken((yyvsp[0].token)); }
#line 2859 "c11ansi.tab.c"
    break;

  case 134: /* struct_declaration: specifier_qualifier_list struct_declarator_list Y_SEMICOLON  */
#line 444 "c11ansi.y"
                                                                      { (yyval.dinfo) = NULL; }
#line 2865 "c11ansi.tab.c"
    break;

  case 135: /* struct_declaration: static_assert_declaration  */
#line 445 "c11ansi.y"
                                                                      { (yyval.dinfo) = NULL; }
#line 2871 "c11ansi.tab.c"
    break;

  case 136: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 449 "c11ansi.y"
                                                  { (yyval.dinfo) = combine2DeclInfo((yyvsp[-1].dinfo), (yyvsp[0].dinfo)); }
#line 2877 "c11ansi.tab.c"
    break;

  case 137: /* specifier_qualifier_list: type_specifier  */
#line 450 "c11ansi.y"
                                                  { (yyval.dinfo) = (yyvsp[0].dinfo); }
#line 2883 "c11ansi.tab.c"
    break;

  case 138: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 451 "c11ansi.y"
                                                  { (yyval.dinfo) = combine2DeclInfo((yyvsp[-1].dinfo), (yyvsp[0].dinfo)); }
#line 2889 "c11ansi.tab.c"
    break;

  case 139: /* specifier_qualifier_list: type_qualifier  */
#line 452 "c11ansi.y"
                                                  { (yyval.dinfo) = (yyvsp[0].dinfo); }
#line 2895 "c11ansi.tab.c"
    break;

  case 140: /* struct_declarator_list: struct_declarator  */
#line 456 "c11ansi.y"
                                                            { (yyval.declList) = createDclrList((yyvsp[0].dclr)); }
#line 2901 "c11ansi.tab.c"
    break;

  case 141: /* struct_declarator_list: struct_declarator_list Y_COMMA struct_declarator  */
#line 457 "c11ansi.y"
                                                            { (yyval.declList) = addDclrList((yyvsp[-2].declList), (yyvsp[0].dclr)); zapToken((yyvsp[-1].token)); }
#line 2907 "c11ansi.tab.c"
    break;

  case 142: /* struct_declarator: Y_COLON constant_expression  */
#line 461 "c11ansi.y"
                                                 { (yyval.dclr) = createStructDeclarator(NULL,(yyvsp[0].tree)); }
#line 2913 "c11ansi.tab.c"
    break;

  case 143: /* struct_declarator: declarator Y_COLON constant_expression  */
#line 462 "c11ansi.y"
                                                 { (yyval.dclr) = createStructDeclarator((yyvsp[-2].dclr), (yyvsp[0].tree)); zapToken((yyvsp[-1].token)); }
#line 2919 "c11ansi.tab.c"
    break;

  case 144: /* struct_declarator: declarator  */
#line 463 "c11ansi.y"
                                                 { (yyval.dclr) = createStructDeclarator((yyvsp[0].dclr), NULL); }
#line 2925 "c11ansi.tab.c"
    break;

  case 145: /* enum_specifier: Y_ENUM Y_LEFT_BRACE enumerator_list Y_RIGHT_BRACE  */
#line 467 "c11ansi.y"
                                                                               { (yyval.declEnum) = createDeclEnum((yyvsp[-3].token), NULL, (yyvsp[-1].enumList)); zapToken((yyvsp[-2].token)); zapToken((yyvsp[0].token)); }
#line 2931 "c11ansi.tab.c"
    break;

  case 146: /* enum_specifier: Y_ENUM Y_LEFT_BRACE enumerator_list Y_COMMA Y_RIGHT_BRACE  */
#line 468 "c11ansi.y"
                                                                               { (yyval.declEnum) = createDeclEnum((yyvsp[-4].token), NULL, (yyvsp[-2].enumList)); zapToken((yyvsp[-3].token)); zapToken((yyvsp[-1].token)); zapToken((yyvsp[0].token)); }
#line 2937 "c11ansi.tab.c"
    break;

  case 147: /* enum_specifier: Y_ENUM "identifier" Y_LEFT_BRACE enumerator_list Y_RIGHT_BRACE  */
#line 469 "c11ansi.y"
                                                                               { (yyval.declEnum) = createDeclEnum((yyvsp[-4].token), (yyvsp[-3].token), (yyvsp[-1].enumList)); zapToken((yyvsp[-2].token)); zapToken((yyvsp[0].token));  }
#line 2943 "c11ansi.tab.c"
    break;

  case 148: /* enum_specifier: Y_ENUM "identifier" Y_LEFT_BRACE enumerator_list Y_COMMA Y_RIGHT_BRACE  */
#line 470 "c11ansi.y"
                                                                               { (yyval.declEnum) = createDeclEnum((yyvsp[-5].token), (yyvsp[-4].token), (yyvsp[-2].enumList)); zapToken((yyvsp[-3].token)); zapToken((yyvsp[-1].token)); zapToken((yyvsp[0].token)); }
#line 2949 "c11ansi.tab.c"
    break;

  case 149: /* enum_specifier: Y_ENUM "identifier"  */
#line 471 "c11ansi.y"
                                                                               { (yyval.declEnum) = createDeclEnum((yyvsp[-1].token), NULL, NULL); zapToken((yyvsp[0].token)); }
#line 2955 "c11ansi.tab.c"
    break;

  case 150: /* enumerator_list: enumerator  */
#line 475 "c11ansi.y"
                                              { (yyval.enumList) = createEnumElemList((yyvsp[0].enumElem)); }
#line 2961 "c11ansi.tab.c"
    break;

  case 151: /* enumerator_list: enumerator_list Y_COMMA enumerator  */
#line 476 "c11ansi.y"
                                              { (yyval.enumList) = addEnumElemList((yyvsp[-2].enumList), (yyvsp[0].enumElem)); zapToken((yyvsp[-1].token)); }
#line 2967 "c11ansi.tab.c"
    break;

  case 152: /* enumerator: enumeration_constant Y_EQUAL constant_expression  */
#line 480 "c11ansi.y"
                                                            { (yyval.enumElem) = createEnumElem((yyvsp[-2].token), (yyvsp[-1].token), (yyvsp[0].tree)); }
#line 2973 "c11ansi.tab.c"
    break;

  case 153: /* enumerator: enumeration_constant  */
#line 481 "c11ansi.y"
                                                            { (yyval.enumElem) = createEnumElem((yyvsp[0].token), NULL, NULL); }
#line 2979 "c11ansi.tab.c"
    break;

  case 155: /* type_qualifier: Y_CONST  */
#line 489 "c11ansi.y"
                      { (yyval.dinfo) = createQualifierDeclInfo(STY_CONST);  zapToken((yyvsp[0].token)); }
#line 2985 "c11ansi.tab.c"
    break;

  case 156: /* type_qualifier: Y_RESTRICT  */
#line 490 "c11ansi.y"
                      { (yyval.dinfo) = createQualifierDeclInfo(STY_RESTRICT);  zapToken((yyvsp[0].token)); }
#line 2991 "c11ansi.tab.c"
    break;

  case 157: /* type_qualifier: Y_VOLATILE  */
#line 491 "c11ansi.y"
                      { (yyval.dinfo) = createQualifierDeclInfo(STY_VOLATILE);  zapToken((yyvsp[0].token)); }
#line 2997 "c11ansi.tab.c"
    break;

  case 158: /* type_qualifier: Y_ATOMIC  */
#line 492 "c11ansi.y"
                      { (yyval.dinfo) = createQualifierDeclInfo(STY_ATOMIC);  zapToken((yyvsp[0].token)); }
#line 3003 "c11ansi.tab.c"
    break;

  case 159: /* function_specifier: Y_INLINE  */
#line 496 "c11ansi.y"
                       { (yyval.dinfo) = createFunctionSpecifirDeclInfo(STY_INLINE);  zapToken((yyvsp[0].token)); }
#line 3009 "c11ansi.tab.c"
    break;

  case 160: /* function_specifier: Y_NORETURN  */
#line 497 "c11ansi.y"
                       { (yyval.dinfo) = createFunctionSpecifirDeclInfo(STY_NORETURN);  zapToken((yyvsp[0].token)); }
#line 3015 "c11ansi.tab.c"
    break;

  case 161: /* alignment_specifier: Y_ALIGNAS Y_LEFT_PAREN type_name Y_RIGHT_PAREN  */
#line 501 "c11ansi.y"
                                                                   { (yyval.dinfo) = createAlignmentSpecifierDeclInfo(STY_ALIGNAS,(yyvsp[-3].token), (yyvsp[-2].token), (yyvsp[-1].tree), (yyvsp[0].token));  }
#line 3021 "c11ansi.tab.c"
    break;

  case 162: /* alignment_specifier: Y_ALIGNAS Y_LEFT_PAREN constant_expression Y_RIGHT_PAREN  */
#line 502 "c11ansi.y"
                                                                   { (yyval.dinfo) = createAlignmentSpecifierDeclInfo(STY_ALIGNAS,(yyvsp[-3].token), (yyvsp[-2].token), (yyvsp[-1].tree), (yyvsp[0].token));  }
#line 3027 "c11ansi.tab.c"
    break;

  case 220: /* initializer: Y_LEFT_BRACE initializer_list Y_RIGHT_BRACE  */
#line 597 "c11ansi.y"
                                                              { (yyval.tree) = createCTree1(createConstr2Label(LABCT_EXPR_LIST, (yyvsp[-2].token), (yyvsp[0].token)), (yyvsp[-1].tree)); }
#line 3033 "c11ansi.tab.c"
    break;

  case 221: /* initializer: Y_LEFT_BRACE initializer_list Y_COMMA Y_RIGHT_BRACE  */
#line 598 "c11ansi.y"
                                                              { (yyval.tree) = createCTree1(createConstr3Label(LABCT_EXPR_LIST, (yyvsp[-3].token), (yyvsp[-1].token), (yyvsp[0].token)), (yyvsp[-2].tree)); }
#line 3039 "c11ansi.tab.c"
    break;

  case 222: /* initializer: assignment_expression  */
#line 599 "c11ansi.y"
                                                              { (yyval.tree) = (yyvsp[0].tree); }
#line 3045 "c11ansi.tab.c"
    break;

  case 223: /* initializer_list: designation initializer  */
#line 603 "c11ansi.y"
                                                            { (yyval.tree) = createCTree2(createConstr0Label(LABCT_EXPR_LIST), (yyvsp[-1].tree), (yyvsp[0].tree)); }
#line 3051 "c11ansi.tab.c"
    break;

  case 224: /* initializer_list: initializer  */
#line 604 "c11ansi.y"
                                                            { (yyval.tree) = createCTree1(createConstr0Label(LABCT_EXPR_LIST), (yyvsp[0].tree)); }
#line 3057 "c11ansi.tab.c"
    break;

  case 225: /* initializer_list: initializer_list Y_COMMA designation initializer  */
#line 605 "c11ansi.y"
                                                            { (yyval.tree) = createCTree2(createConstr1Label(LABCT_EXPR_LIST, (yyvsp[-2].token)), (yyvsp[-3].tree), createCTree1(createConstr0Label(LABCT_EXPR_LIST), (yyvsp[-1].tree))); }
#line 3063 "c11ansi.tab.c"
    break;

  case 226: /* initializer_list: initializer_list Y_COMMA initializer  */
#line 606 "c11ansi.y"
                                                            { (yyval.tree) = createCTree2(createConstr1Label(LABCT_EXPR_LIST, (yyvsp[-1].token)), (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 3069 "c11ansi.tab.c"
    break;

  case 259: /* jump_statement: Y_GOTO "identifier" Y_SEMICOLON  */
#line 678 "c11ansi.y"
                                           { printf("jump_statement -> Y_GOTO IDENTIFIER Y_SEMICOLON\n"); }
#line 3075 "c11ansi.tab.c"
    break;

  case 260: /* jump_statement: Y_CONTINUE Y_SEMICOLON  */
#line 679 "c11ansi.y"
                                           { printf("jump_statement -> Y_CONTINUE Y_SEMICOLON\n"); }
#line 3081 "c11ansi.tab.c"
    break;

  case 261: /* jump_statement: Y_BREAK Y_SEMICOLON  */
#line 680 "c11ansi.y"
                                           { printf("jump_statement -> Y_BREAK Y_SEMICOLON\n"); }
#line 3087 "c11ansi.tab.c"
    break;

  case 262: /* jump_statement: Y_RETURN Y_SEMICOLON  */
#line 681 "c11ansi.y"
                                           { printf("jump_statement -> Y_RETURN Y_SEMICOLON\n"); }
#line 3093 "c11ansi.tab.c"
    break;

  case 263: /* jump_statement: Y_RETURN expression Y_SEMICOLON  */
#line 682 "c11ansi.y"
                                           { printf("jump_statement -> Y_RETURN expression Y_SEMICOLON\n"); }
#line 3099 "c11ansi.tab.c"
    break;

  case 264: /* translation_unit: external_declaration  */
#line 686 "c11ansi.y"
                                                 { printf("translation_unit -> external_declaration\n\n"); }
#line 3105 "c11ansi.tab.c"
    break;

  case 265: /* translation_unit: translation_unit external_declaration  */
#line 687 "c11ansi.y"
                                                 { printf("translation_unit -> translation_unit external_declaration\n\n"); }
#line 3111 "c11ansi.tab.c"
    break;

  case 266: /* external_declaration: function_definition  */
#line 691 "c11ansi.y"
                                { printf("external_declaration -> function_definition\n"); }
#line 3117 "c11ansi.tab.c"
    break;

  case 267: /* external_declaration: declaration  */
#line 692 "c11ansi.y"
                                { printf("external_declaration -> declaration\n"); }
#line 3123 "c11ansi.tab.c"
    break;

  case 268: /* function_definition: declaration_specifiers declarator declaration_list compound_statement  */
#line 696 "c11ansi.y"
                                                                                   { printf("function_definition -> declaration_specifiers declarator declaration_list compound_statement\n"); }
#line 3129 "c11ansi.tab.c"
    break;

  case 269: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 697 "c11ansi.y"
                                                                                   { printf("function_definition -> declaration_specifiers declarator compound_statement\n"); }
#line 3135 "c11ansi.tab.c"
    break;


#line 3139 "c11ansi.tab.c"

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

#line 706 "c11ansi.y"

#include <stdio.h>

extern char * yytext;
extern int yylineno;

int yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** Line %d %s %s\n", yylineno, s, yytext);
	return 0;
}
