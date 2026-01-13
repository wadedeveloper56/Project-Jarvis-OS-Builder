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
  YYSYMBOL_I_CONST = 4,                    /* "i_const"  */
  YYSYMBOL_F_CONST = 5,                    /* "f_const"  */
  YYSYMBOL_STRING_LITERAL = 6,             /* "sting_literal"  */
  YYSYMBOL_TYPE_NAME = 7,                  /* "type name"  */
  YYSYMBOL_AUTO = 8,                       /* "auto"  */
  YYSYMBOL_BREAK = 9,                      /* "break"  */
  YYSYMBOL_CASE = 10,                      /* "case"  */
  YYSYMBOL_CHAR = 11,                      /* "char"  */
  YYSYMBOL_CONST = 12,                     /* "const"  */
  YYSYMBOL_CONTINUE = 13,                  /* "continue"  */
  YYSYMBOL_DEFAULT = 14,                   /* "default"  */
  YYSYMBOL_DO = 15,                        /* "do"  */
  YYSYMBOL_DOUBLE = 16,                    /* "double"  */
  YYSYMBOL_LONG_DOUBLE = 17,               /* "long double"  */
  YYSYMBOL_ELSE = 18,                      /* "else"  */
  YYSYMBOL_ENUM = 19,                      /* "enum"  */
  YYSYMBOL_EXTERN = 20,                    /* "extern"  */
  YYSYMBOL_FLOAT = 21,                     /* "float"  */
  YYSYMBOL_FOR = 22,                       /* "for"  */
  YYSYMBOL_GOTO = 23,                      /* "goto"  */
  YYSYMBOL_IF = 24,                        /* "if"  */
  YYSYMBOL_INLINE = 25,                    /* "inline"  */
  YYSYMBOL_INT = 26,                       /* INT  */
  YYSYMBOL_LONG = 27,                      /* "long"  */
  YYSYMBOL_LONG_LONG = 28,                 /* "long long"  */
  YYSYMBOL_REGISTER = 29,                  /* "register"  */
  YYSYMBOL_RESTRICT = 30,                  /* "restrict"  */
  YYSYMBOL_RETURN = 31,                    /* "return"  */
  YYSYMBOL_SHORT = 32,                     /* "short"  */
  YYSYMBOL_SIGNED = 33,                    /* "signed"  */
  YYSYMBOL_SIZEOF = 34,                    /* "sizeof"  */
  YYSYMBOL_STATIC = 35,                    /* "static"  */
  YYSYMBOL_STRUCT = 36,                    /* "struct"  */
  YYSYMBOL_SWITCH = 37,                    /* "switch"  */
  YYSYMBOL_TYPEDEF = 38,                   /* "typedef"  */
  YYSYMBOL_UNION = 39,                     /* "union"  */
  YYSYMBOL_UNSIGNED = 40,                  /* "unsigned"  */
  YYSYMBOL_VOID = 41,                      /* "void"  */
  YYSYMBOL_VOLATILE = 42,                  /* "volatile"  */
  YYSYMBOL_WHILE = 43,                     /* "while"  */
  YYSYMBOL_BOOL = 44,                      /* "bool"  */
  YYSYMBOL_COMPLEX = 45,                   /* "complex"  */
  YYSYMBOL_IMAGINARY = 46,                 /* "imaginary"  */
  YYSYMBOL_ELLIPSIS = 47,                  /* "ellipsis"  */
  YYSYMBOL_QUESTION = 48,                  /* "question"  */
  YYSYMBOL_SEMICOLON = 49,                 /* ";"  */
  YYSYMBOL_OCURLY = 50,                    /* "{"  */
  YYSYMBOL_CCURLY = 51,                    /* "}"  */
  YYSYMBOL_COMMA = 52,                     /* ","  */
  YYSYMBOL_COLON = 53,                     /* ":"  */
  YYSYMBOL_OPAREN = 54,                    /* "("  */
  YYSYMBOL_CPAREN = 55,                    /* ")"  */
  YYSYMBOL_OBRACE = 56,                    /* "["  */
  YYSYMBOL_CBRACE = 57,                    /* "]"  */
  YYSYMBOL_PERIOD = 58,                    /* "."  */
  YYSYMBOL_TILDE = 59,                     /* "~"  */
  YYSYMBOL_EQUAL = 60,                     /* "="  */
  YYSYMBOL_RIGHT_ASSIGN = 61,              /* ">>="  */
  YYSYMBOL_LEFT_ASSIGN = 62,               /* "<<="  */
  YYSYMBOL_ADD_ASSIGN = 63,                /* "+="  */
  YYSYMBOL_SUB_ASSIGN = 64,                /* "-="  */
  YYSYMBOL_MUL_ASSIGN = 65,                /* "*="  */
  YYSYMBOL_DIV_ASSIGN = 66,                /* "/="  */
  YYSYMBOL_MOD_ASSIGN = 67,                /* "%="  */
  YYSYMBOL_AND_ASSIGN = 68,                /* "&="  */
  YYSYMBOL_XOR_ASSIGN = 69,                /* "^="  */
  YYSYMBOL_OR_ASSIGN = 70,                 /* "|="  */
  YYSYMBOL_RIGHT_OP = 71,                  /* ">>"  */
  YYSYMBOL_LEFT_OP = 72,                   /* "<<"  */
  YYSYMBOL_INC_OP = 73,                    /* "++"  */
  YYSYMBOL_DEC_OP = 74,                    /* "--"  */
  YYSYMBOL_PTR_OP = 75,                    /* "->"  */
  YYSYMBOL_AND_OP = 76,                    /* "&&"  */
  YYSYMBOL_OR_OP = 77,                     /* "||"  */
  YYSYMBOL_GREATER_EQUAL = 78,             /* ">="  */
  YYSYMBOL_LESS_EQUAL = 79,                /* "<="  */
  YYSYMBOL_GREATER = 80,                   /* ">"  */
  YYSYMBOL_LESS = 81,                      /* "<"  */
  YYSYMBOL_EQUAL_EQUAL = 82,               /* "=="  */
  YYSYMBOL_NOT_EQUAL = 83,                 /* "!="  */
  YYSYMBOL_NOT_OP = 84,                    /* "!"  */
  YYSYMBOL_XOR_OP = 85,                    /* "^"  */
  YYSYMBOL_BIT_AND = 86,                   /* "&"  */
  YYSYMBOL_BIT_OR = 87,                    /* "|"  */
  YYSYMBOL_MINUS_OP = 88,                  /* "-"  */
  YYSYMBOL_PLUS_OP = 89,                   /* "+"  */
  YYSYMBOL_TIMES_OP = 90,                  /* "*"  */
  YYSYMBOL_DIV_OP = 91,                    /* "/"  */
  YYSYMBOL_MOD_OP = 92,                    /* "%"  */
  YYSYMBOL_93_ = 93,                       /* '('  */
  YYSYMBOL_94_ = 94,                       /* ')'  */
  YYSYMBOL_95_ = 95,                       /* '['  */
  YYSYMBOL_96_ = 96,                       /* ']'  */
  YYSYMBOL_97_ = 97,                       /* '.'  */
  YYSYMBOL_98_ = 98,                       /* ','  */
  YYSYMBOL_99_ = 99,                       /* '&'  */
  YYSYMBOL_100_ = 100,                     /* '*'  */
  YYSYMBOL_101_ = 101,                     /* '+'  */
  YYSYMBOL_102_ = 102,                     /* '-'  */
  YYSYMBOL_103_ = 103,                     /* '~'  */
  YYSYMBOL_104_ = 104,                     /* '!'  */
  YYSYMBOL_105_ = 105,                     /* '/'  */
  YYSYMBOL_106_ = 106,                     /* '%'  */
  YYSYMBOL_107_ = 107,                     /* '^'  */
  YYSYMBOL_108_ = 108,                     /* '|'  */
  YYSYMBOL_109_ = 109,                     /* '?'  */
  YYSYMBOL_110_ = 110,                     /* ':'  */
  YYSYMBOL_111_ = 111,                     /* '='  */
  YYSYMBOL_112_ = 112,                     /* ';'  */
  YYSYMBOL_113_ = 113,                     /* '{'  */
  YYSYMBOL_114_ = 114,                     /* '}'  */
  YYSYMBOL_YYACCEPT = 115,                 /* $accept  */
  YYSYMBOL_primary_expression = 116,       /* primary_expression  */
  YYSYMBOL_constant = 117,                 /* constant  */
  YYSYMBOL_postfix_expression = 118,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 119, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 120,         /* unary_expression  */
  YYSYMBOL_unary_operator = 121,           /* unary_operator  */
  YYSYMBOL_cast_expression = 122,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 123, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 124,      /* additive_expression  */
  YYSYMBOL_shift_expression = 125,         /* shift_expression  */
  YYSYMBOL_relational_expression = 126,    /* relational_expression  */
  YYSYMBOL_equality_expression = 127,      /* equality_expression  */
  YYSYMBOL_and_expression = 128,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 129,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 130,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 131,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 132,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 133,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 134,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 135,      /* assignment_operator  */
  YYSYMBOL_expression = 136,               /* expression  */
  YYSYMBOL_constant_expression = 137,      /* constant_expression  */
  YYSYMBOL_declaration = 138,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 139,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 140,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 141,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 142,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 143,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 144, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 145,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 146,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 147,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 148, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 149,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 150,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 151,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 152,          /* enumerator_list  */
  YYSYMBOL_enumerator = 153,               /* enumerator  */
  YYSYMBOL_type_qualifier = 154,           /* type_qualifier  */
  YYSYMBOL_declarator = 155,               /* declarator  */
  YYSYMBOL_direct_declarator = 156,        /* direct_declarator  */
  YYSYMBOL_pointer = 157,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 158,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 159,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 160,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 161,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 162,          /* identifier_list  */
  YYSYMBOL_type_name = 163,                /* type_name  */
  YYSYMBOL_abstract_declarator = 164,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 165, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 166,              /* initializer  */
  YYSYMBOL_initializer_list = 167,         /* initializer_list  */
  YYSYMBOL_statement = 168,                /* statement  */
  YYSYMBOL_labeled_statement = 169,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 170,       /* compound_statement  */
  YYSYMBOL_declaration_list = 171,         /* declaration_list  */
  YYSYMBOL_statement_list = 172,           /* statement_list  */
  YYSYMBOL_expression_statement = 173,     /* expression_statement  */
  YYSYMBOL_selection_statement = 174,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 175,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 176,           /* jump_statement  */
  YYSYMBOL_translation_unit = 177,         /* translation_unit  */
  YYSYMBOL_external_declaration = 178,     /* external_declaration  */
  YYSYMBOL_function_definition = 179       /* function_definition  */
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
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1568

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  115
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  214
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  352

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   347


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   104,     2,     2,     2,   106,    99,     2,
      93,    94,   100,   101,    98,   102,    97,   105,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   110,   112,
       2,   111,     2,   109,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    95,     2,    96,   107,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   113,   108,   114,   103,     2,     2,     2,
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
      85,    86,    87,    88,    89,    90,    91,    92
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    97,    97,    98,    99,   103,   104,   105,   108,   109,
     110,   111,   112,   113,   114,   115,   119,   120,   124,   125,
     126,   127,   128,   129,   133,   134,   135,   136,   137,   138,
     142,   143,   147,   148,   149,   150,   154,   155,   156,   160,
     161,   162,   166,   167,   168,   169,   170,   174,   175,   176,
     180,   181,   185,   186,   190,   191,   195,   196,   200,   201,
     205,   206,   210,   211,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   229,   230,   234,   238,   239,
     243,   244,   245,   246,   247,   248,   252,   253,   257,   258,
     262,   263,   264,   265,   266,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   285,   286,   287,
     291,   292,   296,   297,   301,   305,   306,   307,   308,   312,
     313,   317,   318,   319,   323,   324,   325,   329,   330,   334,
     335,   339,   340,   344,   345,   349,   350,   351,   352,   353,
     354,   355,   359,   360,   361,   362,   366,   367,   372,   373,
     377,   378,   382,   383,   384,   388,   389,   393,   394,   398,
     399,   400,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   416,   417,   418,   422,   423,   427,   428,   429,   430,
     431,   432,   436,   437,   438,   442,   443,   444,   445,   449,
     450,   454,   455,   459,   460,   464,   465,   466,   470,   471,
     472,   473,   477,   478,   479,   480,   481,   485,   486,   490,
     491,   495,   496,   497,   498
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
  "\"i_const\"", "\"f_const\"", "\"sting_literal\"", "\"type name\"",
  "\"auto\"", "\"break\"", "\"case\"", "\"char\"", "\"const\"",
  "\"continue\"", "\"default\"", "\"do\"", "\"double\"", "\"long double\"",
  "\"else\"", "\"enum\"", "\"extern\"", "\"float\"", "\"for\"", "\"goto\"",
  "\"if\"", "\"inline\"", "INT", "\"long\"", "\"long long\"",
  "\"register\"", "\"restrict\"", "\"return\"", "\"short\"", "\"signed\"",
  "\"sizeof\"", "\"static\"", "\"struct\"", "\"switch\"", "\"typedef\"",
  "\"union\"", "\"unsigned\"", "\"void\"", "\"volatile\"", "\"while\"",
  "\"bool\"", "\"complex\"", "\"imaginary\"", "\"ellipsis\"",
  "\"question\"", "\";\"", "\"{\"", "\"}\"", "\",\"", "\":\"", "\"(\"",
  "\")\"", "\"[\"", "\"]\"", "\".\"", "\"~\"", "\"=\"", "\">>=\"",
  "\"<<=\"", "\"+=\"", "\"-=\"", "\"*=\"", "\"/=\"", "\"%=\"", "\"&=\"",
  "\"^=\"", "\"|=\"", "\">>\"", "\"<<\"", "\"++\"", "\"--\"", "\"->\"",
  "\"&&\"", "\"||\"", "\">=\"", "\"<=\"", "\">\"", "\"<\"", "\"==\"",
  "\"!=\"", "\"!\"", "\"^\"", "\"&\"", "\"|\"", "\"-\"", "\"+\"", "\"*\"",
  "\"/\"", "\"%\"", "'('", "')'", "'['", "']'", "'.'", "','", "'&'", "'*'",
  "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'^'", "'|'", "'?'", "':'",
  "'='", "';'", "'{'", "'}'", "$accept", "primary_expression", "constant",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "type_specifier", "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-210)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1310,  -210,  -210,  -210,  -210,  -210,  -210,     5,  -210,  -210,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,  -210,    42,    41,  -210,    31,  1490,  1490,  -210,     6,
    -210,  1490,   866,   -24,    33,  1227,  -210,  -210,   -96,    40,
     -22,  -210,  -210,    41,  -210,   -38,  -210,   830,  -210,  -210,
       4,  1526,  -210,   308,  -210,    31,  -210,   866,  1139,   953,
     -24,  -210,  -210,    40,   -20,   -60,  -210,  -210,  -210,  -210,
      42,  -210,   623,  -210,   866,  1526,  1526,   753,  -210,    36,
    1526,    18,  -210,  -210,  -210,   -37,  1089,    13,    72,   582,
     100,   197,   109,   640,  1110,   114,   116,  1122,  1122,   912,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
     113,   305,  1089,  -210,    -8,    49,   103,   166,   137,   112,
     110,   124,   146,   -52,  -210,  -210,   -35,  -210,  -210,  -210,
     420,   464,  -210,  -210,  -210,  -210,   117,  -210,  -210,  -210,
    -210,    45,   130,   141,  -210,   -74,  -210,  -210,  -210,  -210,
     144,   -46,  1089,    40,  -210,  -210,   623,  -210,  -210,  -210,
     789,  -210,  -210,  -210,  1089,   -25,  -210,   138,  -210,   582,
    -210,   147,  -210,   582,   222,   655,   154,  1089,  -210,   -18,
     912,  -210,  1089,  1089,  1089,  -210,  -210,    15,    96,   176,
    -210,  -210,   270,   965,  1089,   271,  -210,  -210,  -210,  -210,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,  1089,  -210,  1089,
    1089,  1089,  1089,  1089,  1089,  1089,  1089,  1089,  1089,  1089,
    1089,  1089,  1089,  1089,  1089,  1089,  1089,  1089,  1089,  -210,
    -210,   538,  -210,  -210,  1267,   987,  -210,     8,  -210,    90,
    -210,  1453,  -210,   272,  -210,  -210,  -210,  -210,  -210,   -36,
    -210,  -210,    36,  -210,  1089,  -210,   582,  -210,   183,   655,
    -210,    29,  -210,   184,    50,    82,  -210,  1357,    99,  -210,
    1089,  -210,  -210,   105,  -210,   -14,  -210,  -210,  -210,  -210,
    -210,    -8,    -8,    49,    49,   103,   103,   103,   103,   166,
     166,   137,   112,   110,   124,   146,   -31,  -210,  -210,  -210,
     185,   186,  -210,   187,    90,  1393,  1003,  -210,  -210,  -210,
     291,  -210,  -210,  -210,  -210,  1089,  1037,   582,  -210,   582,
     582,  -210,  -210,  1089,  -210,  1089,  -210,  -210,  -210,  -210,
     188,  -210,   189,  -210,  -210,   118,   582,   120,   263,  -210,
    -210,  -210,  -210,  -210,  -210,   172,  -210,   582,   582,  -210,
    -210,  -210
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   135,   106,    93,    96,   131,   101,     0,    91,   100,
      98,    99,    94,    97,   102,    92,   110,    90,   111,   103,
      95,   132,     0,   142,   210,     0,    80,    82,   104,     0,
     105,    84,     0,   134,     0,     0,   207,   209,   126,     0,
       0,   146,   144,   143,    78,     0,    86,    88,    81,    83,
     109,     0,    85,     0,   189,     0,   214,     0,     0,     0,
     133,     1,   208,     0,   129,     0,   127,   136,   147,   145,
       0,    79,     0,   212,     0,     0,   116,     0,   112,     0,
     118,     2,     6,     5,     7,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24,    25,    26,    27,    28,    29,   193,   185,     8,     3,
      18,    30,     0,    32,    36,    39,    42,    47,    50,    52,
      54,    56,    58,    60,    62,    75,     0,   191,   176,   177,
       0,     0,   178,   179,   180,   181,    88,   190,   213,   155,
     141,   154,     0,   148,   150,     0,     2,   138,    30,    77,
       0,     0,     0,     0,   124,    87,     0,   171,    89,   211,
       0,   115,   108,   113,     0,     0,   119,   121,   117,     0,
     204,     0,   203,     0,     0,     0,     0,     0,   205,     0,
       0,    22,     0,     0,     0,    19,    20,     0,   157,     0,
      14,    15,     0,     0,     0,     0,    71,    70,    68,    69,
      65,    66,    67,    72,    73,    74,    64,     0,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   194,
     187,     0,   186,   192,     0,     0,   152,   159,   153,   160,
     139,     0,   140,     0,   137,   125,   130,   128,   174,     0,
     107,   122,     0,   114,     0,   182,     0,   184,     0,     0,
     202,     0,   206,     0,     0,     0,     4,     0,   159,   158,
       0,    13,    10,     0,    16,     0,    12,    63,    33,    34,
      35,    37,    38,    41,    40,    46,    45,    44,    43,    48,
      49,    51,    53,    55,    57,    59,     0,    76,   188,   167,
       0,     0,   163,     0,   161,     0,     0,   149,   151,   156,
       0,   172,   120,   123,   183,     0,     0,     0,    23,     0,
       0,    31,    11,     0,     9,     0,   168,   162,   164,   169,
       0,   165,     0,   173,   175,     0,     0,     0,   195,   197,
     198,    17,    61,   170,   166,     0,   200,     0,     0,   199,
     201,   196
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -210,  -210,  -210,  -210,  -210,   -57,  -210,   -89,    14,    16,
      43,    51,    64,    65,    66,    67,    63,  -210,   -56,   -23,
    -210,   -78,   -64,     7,     0,  -210,   221,  -210,    35,  -210,
    -210,   218,   -21,   -66,  -210,    46,  -210,   236,   148,   178,
      -9,   -33,   -11,  -210,   -54,  -210,    61,  -210,   123,  -123,
    -209,  -137,  -210,   -84,  -210,    19,    -3,   174,  -169,  -210,
    -210,  -210,  -210,   273,  -210
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   108,   109,   110,   273,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     207,   126,   150,    54,    55,    45,    46,    26,    27,    28,
      29,    77,    78,    79,   165,   166,    30,    65,    66,    31,
      32,    33,    34,    43,   300,   143,   144,   145,   189,   301,
     239,   158,   249,   127,   128,   129,    57,   131,   132,   133,
     134,   135,    35,    36,    37
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    60,   148,   149,   142,   174,   259,    24,    38,    50,
     161,     1,    42,    40,   168,   179,    47,    63,   238,   248,
     242,   187,   171,   208,   243,   226,    48,    49,   304,   148,
     149,    52,    69,   188,     1,    25,     1,   181,   153,     1,
     185,   186,    24,    64,    74,     1,   136,   233,     1,   157,
     130,    56,   153,     5,   154,   148,   163,   227,   141,   304,
      70,   136,   310,   228,   137,   269,    73,   228,   245,    58,
     167,    59,    67,   252,    71,   170,   138,   229,   311,   325,
     228,   137,   324,    21,   228,   255,    76,   253,   246,   257,
     316,   152,   209,   159,   262,   148,   149,   210,   211,   261,
     251,   234,   187,   235,   264,   265,   187,   148,   149,   266,
      76,    76,    76,   228,   188,    76,   275,    75,    39,    51,
     278,   279,   280,   317,    22,   172,    22,   228,   169,    22,
     237,    23,   236,   157,    76,    22,    23,   137,   234,   163,
     235,    23,    23,    44,   319,    23,   164,   233,   228,   296,
     212,   213,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     274,   303,   314,   334,   214,   215,   320,   268,   148,   149,
     228,   321,   173,   305,   277,   306,   190,   191,   192,   267,
     313,   235,   267,   175,   235,    76,    23,   148,   149,   322,
     176,    41,   177,   323,    60,   297,   193,   182,   194,   183,
     195,   222,   345,   148,   347,    76,   228,   223,   228,   220,
     221,    68,   225,   237,   240,    40,   281,   282,    72,    80,
     283,   284,   224,   338,   141,   339,   340,   335,   337,   241,
     244,   141,   332,   167,   216,   217,   218,   219,   254,   148,
     149,   330,   346,    80,    80,    80,   268,   256,    80,   285,
     286,   287,   288,   350,   351,   258,   260,   141,   148,   342,
     270,   289,   290,   271,   276,   309,   315,    80,   318,   326,
     327,   348,   343,   328,   349,   344,   291,   157,   292,   295,
     293,   155,   294,   160,   146,    82,    83,    84,   312,   151,
     341,   247,   308,   263,   231,   141,     0,     0,    62,     0,
       0,    81,    82,    83,    84,     2,     3,    85,    86,     4,
       5,    87,    88,    89,     6,    94,     0,     7,     8,     9,
      90,    91,    92,     0,    10,    11,     0,    12,    80,    93,
      13,    14,    94,    15,    16,    95,    17,    18,    19,    20,
      21,    96,     0,     0,     0,     0,     0,     0,    80,     0,
       0,     0,     0,     0,    97,    98,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,     0,     0,     0,     0,
       0,    97,    98,     0,    99,     0,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,     0,     0,     0,     0,
       0,    99,     0,     0,   156,   333,     0,   100,   101,   102,
     103,   104,   105,     0,     0,     0,   206,     0,     0,     0,
     106,    53,   107,    81,    82,    83,    84,     2,     3,    85,
      86,     4,     5,    87,    88,    89,     6,     0,     0,     7,
       8,     9,    90,    91,    92,     0,    10,    11,     0,    12,
       0,    93,    13,    14,    94,    15,    16,    95,    17,    18,
      19,    20,    21,    96,     0,     0,     0,    81,    82,    83,
      84,     0,     0,    85,    86,     0,     0,    87,    88,    89,
       0,     0,     0,     0,     0,     0,    90,    91,    92,     0,
       0,     0,     0,    97,    98,    93,     0,     0,    94,     0,
       0,    95,     0,     0,     0,     0,     0,    96,     0,     0,
       0,     0,     0,    99,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,     0,     0,     0,     0,     0,
       0,     0,   106,    53,   230,     0,     0,    97,    98,     0,
       0,    81,    82,    83,    84,     0,     0,    85,    86,     0,
       0,    87,    88,    89,     0,     0,     0,    99,     0,     0,
      90,    91,    92,   100,   101,   102,   103,   104,   105,    93,
       0,     0,    94,     0,     0,    95,   106,    53,   232,     0,
       0,    96,     0,     0,     0,    81,    82,    83,    84,     0,
       0,    85,    86,     0,     0,    87,    88,    89,     0,     0,
       0,     0,     0,     0,    90,    91,    92,     0,     0,     0,
       0,    97,    98,    93,     0,     0,    94,     0,     0,    95,
       0,     0,     0,     0,     0,    96,   146,    82,    83,    84,
       0,    99,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,   146,    82,    83,    84,     0,     0,     0,
     106,    53,   298,     0,     0,    97,    98,    94,   146,    82,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    99,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,     0,     0,    94,
       0,     0,     0,     0,   106,    53,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    98,     0,    99,     0,     0,     0,
       0,     0,   100,   101,   102,   103,   104,   105,    97,    98,
       0,     0,     0,    99,     0,     0,   156,     0,     0,   100,
     101,   102,   103,   104,   105,     0,     0,     0,    99,     0,
       0,     0,   178,     0,   100,   101,   102,   103,   104,   105,
       2,     0,     0,     0,     4,     5,     0,   106,     0,     6,
       0,     0,     7,     0,     9,     0,     0,     0,     0,    10,
      11,     0,     0,     0,     0,    13,    14,     0,     0,    16,
       0,     0,    18,    19,    20,    21,     2,     0,     0,     0,
       4,     5,     0,     0,     0,     6,     0,     0,     7,     0,
       9,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    13,    14,     0,     0,    16,     0,     0,    18,    19,
      20,    21,     0,     0,     0,     0,     0,     2,     3,     0,
       0,     4,     5,     0,     0,     0,     6,     0,     0,     7,
       8,     9,     0,     0,     0,     0,    10,    11,     0,    12,
       0,     0,    13,    14,     0,    15,    16,   162,    17,    18,
      19,    20,    21,     2,     3,     0,     0,     4,     5,     0,
       0,     0,     6,     0,     0,     7,     8,     9,     0,     0,
       0,     0,    10,    11,     0,    12,     0,     0,    13,    14,
       0,    15,    16,   250,    17,    18,    19,    20,    21,     0,
       0,     0,     0,     0,     0,   146,    82,    83,    84,     2,
       0,     0,     0,     4,     5,     0,     0,     0,     6,     0,
       0,     7,     0,     9,     0,     0,     0,     0,    10,    11,
       0,    72,     0,    53,    13,    14,    94,     0,    16,     0,
       0,    18,    19,    20,    21,     0,   146,    82,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,   146,    82,
      83,    84,     0,     0,     0,     0,     0,     0,     0,    53,
       0,     0,     0,     0,     0,    97,    98,    94,     0,     0,
     146,    82,    83,    84,     0,     0,     0,     0,     0,    94,
       0,     0,     0,     0,     0,    99,   146,    82,    83,    84,
       0,   100,   101,   102,   103,   104,   105,     0,     0,     0,
       0,    94,     0,     0,     0,     0,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    97,    98,
     146,    82,    83,    84,     0,     0,    99,     0,     0,   147,
       0,     0,   100,   101,   102,   103,   104,   105,    99,   272,
      97,    98,     0,     0,   100,   101,   102,   103,   104,   105,
       0,    94,     0,     0,     0,     0,    97,    98,     0,     0,
      99,     0,     0,   302,     0,     0,   100,   101,   102,   103,
     104,   105,   146,    82,    83,    84,    99,     0,     0,   331,
       0,     0,   100,   101,   102,   103,   104,   105,     0,     0,
      97,    98,     0,   146,    82,    83,    84,     0,     0,     0,
       0,     0,     0,    94,     0,   146,    82,    83,    84,     0,
      99,   336,     0,     0,     0,     0,   100,   101,   102,   103,
     104,   105,   139,     0,    94,     0,     2,     3,     0,     0,
       4,     5,     0,     0,     0,     6,    94,     0,     7,     8,
       9,     0,    97,    98,     0,    10,    11,     0,    12,     0,
       0,    13,    14,     0,    15,    16,     0,    17,    18,    19,
      20,    21,    99,    97,    98,     0,     0,     0,   100,   101,
     102,   103,   104,   105,     0,    97,    98,     0,     0,     0,
       0,     0,     0,   180,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,   184,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,    61,     0,     0,
       1,     0,     0,   140,     2,     3,     0,     0,     4,     5,
       0,     0,     0,     6,     0,     0,     7,     8,     9,     0,
       0,     0,     0,    10,    11,     0,    12,     0,     0,    13,
      14,     0,    15,    16,     0,    17,    18,    19,    20,    21,
       1,     0,     0,     0,     2,     3,     0,     0,     4,     5,
       0,     0,     0,     6,     0,     0,     7,     8,     9,     0,
       0,     0,     0,    10,    11,     0,    12,     0,     0,    13,
      14,     0,    15,    16,     0,    17,    18,    19,    20,    21,
       0,     0,     0,     1,     0,     0,     0,     2,     3,     0,
      22,     4,     5,     0,     0,     0,     6,    23,     0,     7,
       8,     9,     0,     0,     0,     0,    10,    11,     0,    12,
       0,     0,    13,    14,     0,    15,    16,     0,    17,    18,
      19,    20,    21,     0,     0,     0,     0,     0,     0,     0,
     234,   299,   235,     0,     2,     3,     0,    23,     4,     5,
       0,     0,     0,     6,     0,     0,     7,     8,     9,     0,
       0,     0,     0,    10,    11,     0,    12,     0,     0,    13,
      14,     0,    15,    16,     0,    17,    18,    19,    20,    21,
       2,     3,     0,    22,     4,     5,     0,     0,     0,     6,
      23,     0,     7,     8,     9,     0,     0,     0,     0,    10,
      11,     0,    12,     0,     0,    13,    14,     0,    15,    16,
       0,    17,    18,    19,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     267,   299,   235,     0,     0,     0,     0,    23,     0,     0,
       2,     3,     0,     0,     4,     5,     0,     0,     0,     6,
       0,     0,     7,     8,     9,     0,     0,     0,     0,    10,
      11,     0,    12,     0,     0,    13,    14,   329,    15,    16,
       0,    17,    18,    19,    20,    21,     0,     2,     3,     0,
     307,     4,     5,     0,     0,     0,     6,     0,     0,     7,
       8,     9,     0,     0,     0,     0,    10,    11,     0,    12,
       0,     0,    13,    14,     0,    15,    16,     0,    17,    18,
      19,    20,    21,     2,     0,     0,     0,     4,     5,     0,
       0,     0,     6,     0,     0,     7,     0,     9,     0,     0,
       0,     0,    10,    11,     0,     0,     0,     0,    13,    14,
       0,     0,    16,     0,     0,    18,    19,    20,    21
};

static const yytype_int16 yycheck[] =
{
       0,    34,    59,    59,    58,    89,   175,     0,     3,     3,
      76,     3,    23,    22,    80,    93,    25,   113,   141,   156,
      94,    99,    86,   112,    98,    77,    26,    27,   237,    86,
      86,    31,    43,    99,     3,    35,     3,    94,    98,     3,
      97,    98,    35,     3,    47,     3,    55,   131,     3,    72,
      53,    32,    98,    12,   114,   112,    77,   109,    58,   268,
      98,    70,    98,    98,    57,   188,    47,    98,   114,    93,
      79,    95,    94,    98,   112,   112,    57,   112,   114,   110,
      98,    74,    96,    42,    98,   169,    51,   112,   152,   173,
     259,   111,   100,    74,   112,   152,   152,   105,   106,   177,
     164,    93,   180,    95,   182,   183,   184,   164,   164,    94,
      75,    76,    77,    98,   180,    80,   194,   113,   113,   113,
     209,   210,   211,    94,    93,   112,    93,    98,   110,    93,
     141,   100,   141,   156,    99,    93,   100,   130,    93,   160,
      95,   100,   100,   112,    94,   100,   110,   231,    98,   227,
     101,   102,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     193,   235,   256,   310,    71,    72,    94,   188,   235,   235,
      98,   270,   110,    93,   207,    95,    73,    74,    75,    93,
     254,    95,    93,    93,    95,   160,   100,   254,   254,    94,
       3,    23,    93,    98,   237,   228,    93,    93,    95,    93,
      97,    99,    94,   270,    94,   180,    98,   107,    98,    82,
      83,    43,    76,   234,    94,   234,   212,   213,   111,    51,
     214,   215,   108,   317,   234,   319,   320,   315,   316,    98,
      96,   241,   306,   252,    78,    79,    80,    81,   110,   306,
     306,   305,   336,    75,    76,    77,   267,   110,    80,   216,
     217,   218,   219,   347,   348,    43,   112,   267,   325,   325,
      94,   220,   221,     3,     3,     3,    93,    99,    94,    94,
      94,    18,    94,    96,   112,    96,   222,   310,   223,   226,
     224,    70,   225,    75,     3,     4,     5,     6,   252,    63,
     323,   153,   241,   180,   130,   305,    -1,    -1,    35,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    34,    -1,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,    -1,    29,   160,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,   180,    -1,
      -1,    -1,    -1,    -1,    73,    74,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    73,    74,    -1,    93,    -1,    -1,    -1,    -1,    -1,
      99,   100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,
      -1,    93,    -1,    -1,   113,   114,    -1,    99,   100,   101,
     102,   103,   104,    -1,    -1,    -1,   111,    -1,    -1,    -1,
     112,   113,   114,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    -1,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,    -1,     9,    10,    -1,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,
      -1,    -1,    -1,    73,    74,    31,    -1,    -1,    34,    -1,
      -1,    37,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,    99,
     100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   113,   114,    -1,    -1,    73,    74,    -1,
      -1,     3,     4,     5,     6,    -1,    -1,     9,    10,    -1,
      -1,    13,    14,    15,    -1,    -1,    -1,    93,    -1,    -1,
      22,    23,    24,    99,   100,   101,   102,   103,   104,    31,
      -1,    -1,    34,    -1,    -1,    37,   112,   113,   114,    -1,
      -1,    43,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
      -1,     9,    10,    -1,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    -1,    -1,    -1,
      -1,    73,    74,    31,    -1,    -1,    34,    -1,    -1,    37,
      -1,    -1,    -1,    -1,    -1,    43,     3,     4,     5,     6,
      -1,    93,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,   104,     3,     4,     5,     6,    -1,    -1,    -1,
     112,   113,   114,    -1,    -1,    73,    74,    34,     3,     4,
       5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    93,    -1,    -1,    -1,    -1,
      -1,    99,   100,   101,   102,   103,   104,    -1,    -1,    34,
      -1,    -1,    -1,    -1,   112,   113,    73,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    -1,    93,    -1,    -1,    -1,
      -1,    -1,    99,   100,   101,   102,   103,   104,    73,    74,
      -1,    -1,    -1,    93,    -1,    -1,   113,    -1,    -1,    99,
     100,   101,   102,   103,   104,    -1,    -1,    -1,    93,    -1,
      -1,    -1,   112,    -1,    99,   100,   101,   102,   103,   104,
       7,    -1,    -1,    -1,    11,    12,    -1,   112,    -1,    16,
      -1,    -1,    19,    -1,    21,    -1,    -1,    -1,    -1,    26,
      27,    -1,    -1,    -1,    -1,    32,    33,    -1,    -1,    36,
      -1,    -1,    39,    40,    41,    42,     7,    -1,    -1,    -1,
      11,    12,    -1,    -1,    -1,    16,    -1,    -1,    19,    -1,
      21,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,    -1,
      -1,    32,    33,    -1,    -1,    36,    -1,    -1,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,     7,     8,    -1,
      -1,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    19,
      20,    21,    -1,    -1,    -1,    -1,    26,    27,    -1,    29,
      -1,    -1,    32,    33,    -1,    35,    36,   114,    38,    39,
      40,    41,    42,     7,     8,    -1,    -1,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    19,    20,    21,    -1,    -1,
      -1,    -1,    26,    27,    -1,    29,    -1,    -1,    32,    33,
      -1,    35,    36,   114,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,    -1,
      -1,    19,    -1,    21,    -1,    -1,    -1,    -1,    26,    27,
      -1,   111,    -1,   113,    32,    33,    34,    -1,    36,    -1,
      -1,    39,    40,    41,    42,    -1,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    73,    74,    34,    -1,    -1,
       3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    93,     3,     4,     5,     6,
      -1,    99,   100,   101,   102,   103,   104,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    73,    74,
       3,     4,     5,     6,    -1,    -1,    93,    -1,    -1,    96,
      -1,    -1,    99,   100,   101,   102,   103,   104,    93,    94,
      73,    74,    -1,    -1,    99,   100,   101,   102,   103,   104,
      -1,    34,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,
      93,    -1,    -1,    96,    -1,    -1,    99,   100,   101,   102,
     103,   104,     3,     4,     5,     6,    93,    -1,    -1,    96,
      -1,    -1,    99,   100,   101,   102,   103,   104,    -1,    -1,
      73,    74,    -1,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    -1,     3,     4,     5,     6,    -1,
      93,    94,    -1,    -1,    -1,    -1,    99,   100,   101,   102,
     103,   104,     3,    -1,    34,    -1,     7,     8,    -1,    -1,
      11,    12,    -1,    -1,    -1,    16,    34,    -1,    19,    20,
      21,    -1,    73,    74,    -1,    26,    27,    -1,    29,    -1,
      -1,    32,    33,    -1,    35,    36,    -1,    38,    39,    40,
      41,    42,    93,    73,    74,    -1,    -1,    -1,    99,   100,
     101,   102,   103,   104,    -1,    73,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,    99,
     100,   101,   102,   103,   104,    93,    -1,    -1,    -1,    -1,
      -1,    99,   100,   101,   102,   103,   104,     0,    -1,    -1,
       3,    -1,    -1,    94,     7,     8,    -1,    -1,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    19,    20,    21,    -1,
      -1,    -1,    -1,    26,    27,    -1,    29,    -1,    -1,    32,
      33,    -1,    35,    36,    -1,    38,    39,    40,    41,    42,
       3,    -1,    -1,    -1,     7,     8,    -1,    -1,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    19,    20,    21,    -1,
      -1,    -1,    -1,    26,    27,    -1,    29,    -1,    -1,    32,
      33,    -1,    35,    36,    -1,    38,    39,    40,    41,    42,
      -1,    -1,    -1,     3,    -1,    -1,    -1,     7,     8,    -1,
      93,    11,    12,    -1,    -1,    -1,    16,   100,    -1,    19,
      20,    21,    -1,    -1,    -1,    -1,    26,    27,    -1,    29,
      -1,    -1,    32,    33,    -1,    35,    36,    -1,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    95,    -1,     7,     8,    -1,   100,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    19,    20,    21,    -1,
      -1,    -1,    -1,    26,    27,    -1,    29,    -1,    -1,    32,
      33,    -1,    35,    36,    -1,    38,    39,    40,    41,    42,
       7,     8,    -1,    93,    11,    12,    -1,    -1,    -1,    16,
     100,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,    26,
      27,    -1,    29,    -1,    -1,    32,    33,    -1,    35,    36,
      -1,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    95,    -1,    -1,    -1,    -1,   100,    -1,    -1,
       7,     8,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,
      -1,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,    26,
      27,    -1,    29,    -1,    -1,    32,    33,    94,    35,    36,
      -1,    38,    39,    40,    41,    42,    -1,     7,     8,    -1,
      47,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    19,
      20,    21,    -1,    -1,    -1,    -1,    26,    27,    -1,    29,
      -1,    -1,    32,    33,    -1,    35,    36,    -1,    38,    39,
      40,    41,    42,     7,    -1,    -1,    -1,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    19,    -1,    21,    -1,    -1,
      -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    32,    33,
      -1,    -1,    36,    -1,    -1,    39,    40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     7,     8,    11,    12,    16,    19,    20,    21,
      26,    27,    29,    32,    33,    35,    36,    38,    39,    40,
      41,    42,    93,   100,   138,   139,   142,   143,   144,   145,
     151,   154,   155,   156,   157,   177,   178,   179,     3,   113,
     155,   154,   157,   158,   112,   140,   141,   155,   139,   139,
       3,   113,   139,   113,   138,   139,   170,   171,    93,    95,
     156,     0,   178,   113,     3,   152,   153,    94,   154,   157,
      98,   112,   111,   170,   171,   113,   143,   146,   147,   148,
     154,     3,     4,     5,     6,     9,    10,    13,    14,    15,
      22,    23,    24,    31,    34,    37,    43,    73,    74,    93,
      99,   100,   101,   102,   103,   104,   112,   114,   116,   117,
     118,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   136,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   155,   138,   170,     3,
      94,   139,   159,   160,   161,   162,     3,    96,   120,   133,
     137,   152,   111,    98,   114,   141,   113,   134,   166,   170,
     146,   148,   114,   147,   110,   149,   150,   155,   148,   110,
     112,   137,   112,   110,   168,    93,     3,    93,   112,   136,
      93,   120,    93,    93,    93,   120,   120,   136,   148,   163,
      73,    74,    75,    93,    95,    97,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,   111,   135,   122,   100,
     105,   106,   101,   102,    71,    72,    78,    79,    80,    81,
      82,    83,    99,   107,   108,    76,    77,   109,    98,   112,
     114,   172,   114,   168,    93,    95,   155,   157,   164,   165,
      94,    98,    94,    98,    96,   114,   137,   153,   166,   167,
     114,   137,    98,   112,   110,   168,   110,   168,    43,   173,
     112,   136,   112,   163,   136,   136,    94,    93,   157,   164,
      94,     3,    94,   119,   134,   136,     3,   134,   122,   122,
     122,   123,   123,   124,   124,   125,   125,   125,   125,   126,
     126,   127,   128,   129,   130,   131,   136,   134,   114,    94,
     159,   164,    96,   137,   165,    93,    95,    47,   161,     3,
      98,   114,   150,   137,   168,    93,   173,    94,    94,    94,
      94,   122,    94,    98,    96,   110,    94,    94,    96,    94,
     159,    96,   137,   114,   166,   136,    94,   136,   168,   168,
     168,   134,   133,    94,    96,    94,   168,    94,    18,   112,
     168,   168
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   115,   116,   116,   116,   117,   117,   117,   118,   118,
     118,   118,   118,   118,   118,   118,   119,   119,   120,   120,
     120,   120,   120,   120,   121,   121,   121,   121,   121,   121,
     122,   122,   123,   123,   123,   123,   124,   124,   124,   125,
     125,   125,   126,   126,   126,   126,   126,   127,   127,   127,
     128,   128,   129,   129,   130,   130,   131,   131,   132,   132,
     133,   133,   134,   134,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   136,   136,   137,   138,   138,
     139,   139,   139,   139,   139,   139,   140,   140,   141,   141,
     142,   142,   142,   142,   142,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   144,   144,   144,
     145,   145,   146,   146,   147,   148,   148,   148,   148,   149,
     149,   150,   150,   150,   151,   151,   151,   152,   152,   153,
     153,   154,   154,   155,   155,   156,   156,   156,   156,   156,
     156,   156,   157,   157,   157,   157,   158,   158,   159,   159,
     160,   160,   161,   161,   161,   162,   162,   163,   163,   164,
     164,   164,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   166,   166,   166,   167,   167,   168,   168,   168,   168,
     168,   168,   169,   169,   169,   170,   170,   170,   170,   171,
     171,   172,   172,   173,   173,   174,   174,   174,   175,   175,
     175,   175,   176,   176,   176,   176,   176,   177,   177,   178,
     178,   179,   179,   179,   179
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     3,     1,     1,     1,     1,     4,
       3,     4,     3,     3,     2,     2,     1,     3,     1,     2,
       2,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     3,
       1,     2,     1,     2,     1,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     4,     2,
       1,     1,     1,     2,     3,     2,     1,     2,     1,     1,
       3,     1,     2,     3,     4,     5,     2,     1,     3,     1,
       3,     1,     1,     2,     1,     1,     3,     4,     3,     4,
       4,     3,     1,     2,     2,     3,     1,     2,     1,     3,
       1,     3,     2,     2,     1,     1,     3,     1,     2,     1,
       1,     2,     3,     2,     3,     3,     4,     2,     3,     3,
       4,     1,     3,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     3,     4,     3,     2,     3,     3,     4,     1,
       2,     1,     2,     1,     2,     5,     7,     5,     5,     7,
       6,     7,     3,     2,     2,     2,     3,     1,     2,     1,
       1,     4,     3,     3,     2
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

#line 1759 "cansi.tab.c"

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

#line 501 "cansi.y"

#include <stdio.h>

extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}
