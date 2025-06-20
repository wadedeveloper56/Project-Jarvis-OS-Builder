/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "c.y"

#include "global.h"

/* Line 371 of yacc.c  */
#line 72 "c.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "c.tab.h".  */
#ifndef YY_YY_C_TAB_H_INCLUDED
# define YY_YY_C_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     CONSTANT = 259,
     STRING_LITERAL = 260,
     PTR_OP = 261,
     INC_OP = 262,
     DEC_OP = 263,
     LEFT_OP = 264,
     RIGHT_OP = 265,
     LE_OP = 266,
     GE_OP = 267,
     EQ_OP = 268,
     NE_OP = 269,
     SEMI_OP = 270,
     OCURLY_OP = 271,
     CCURLY_OP = 272,
     COMMA_OP = 273,
     COLON_OP = 274,
     EQUAL_OP = 275,
     OPENPAREN_OP = 276,
     CLOSEPAREN_OP = 277,
     OPENBRACE_OP = 278,
     CLOSEBRACE_OP = 279,
     PERIOD_OP = 280,
     NOT_OP = 281,
     LESS_OP = 282,
     GREATER_OP = 283,
     TILDE_OP = 284,
     XOR_OP = 285,
     QUESTION_OP = 286,
     AND_OP = 287,
     OR_OP = 288,
     MUL_ASSIGN = 289,
     DIV_ASSIGN = 290,
     MOD_ASSIGN = 291,
     ADD_ASSIGN = 292,
     SUB_ASSIGN = 293,
     LEFT_ASSIGN = 294,
     RIGHT_ASSIGN = 295,
     AND_ASSIGN = 296,
     XOR_ASSIGN = 297,
     OR_ASSIGN = 298,
     TYPE_NAME = 299,
     PLUS_OP = 300,
     MINUS_OP = 301,
     TIMES_OP = 302,
     DIV_OP = 303,
     MOD_OP = 304,
     BIT_OR = 305,
     BIT_AND = 306,
     TYPEDEF = 307,
     EXTERN = 308,
     STATIC = 309,
     AUTO = 310,
     REGISTER = 311,
     INLINE = 312,
     RESTRICT = 313,
     CHAR = 314,
     SHORT = 315,
     INT = 316,
     LONG = 317,
     LONGLONG = 318,
     SIGNED = 319,
     UNSIGNED = 320,
     FLOAT = 321,
     DOUBLE = 322,
     LONGDOUBLE = 323,
     CONST = 324,
     VOLATILE = 325,
     VOID = 326,
     SIZEOF = 327,
     BOOL = 328,
     COMPLEX = 329,
     IMAGINARY = 330,
     STRUCT = 331,
     UNION = 332,
     ENUM = 333,
     ELLIPSIS = 334,
     INCLUDE = 335,
     CASE = 336,
     DEFAULT = 337,
     IF = 338,
     ELSE = 339,
     SWITCH = 340,
     WHILE = 341,
     DO = 342,
     FOR = 343,
     GOTO = 344,
     CONTINUE = 345,
     BREAK = 346,
     RETURN = 347
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 5 "c.y"
       
    struct _CompilerInfo CompilerInfo;
    struct _ParameterListNode *ParameterList;


/* Line 387 of yacc.c  */
#line 213 "c.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_C_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 254 "c.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  57
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1715

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  240
/* YYNRULES -- Number of states.  */
#define YYNSTATES  402

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   347

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      85,    86,    87,    88,    89,    90,    91,    92
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    15,    20,    24,
      29,    33,    37,    40,    43,    50,    58,    60,    64,    66,
      69,    72,    75,    78,    83,    85,    87,    89,    91,    93,
      95,    97,   102,   104,   108,   112,   116,   118,   122,   126,
     128,   132,   136,   138,   142,   146,   150,   154,   156,   160,
     164,   166,   170,   172,   176,   178,   182,   184,   188,   190,
     194,   196,   202,   204,   208,   210,   212,   214,   216,   218,
     220,   222,   224,   226,   228,   230,   232,   236,   238,   241,
     245,   247,   250,   252,   255,   257,   260,   262,   265,   267,
     271,   273,   277,   279,   281,   283,   285,   287,   289,   291,
     293,   295,   297,   299,   301,   303,   305,   307,   309,   311,
     313,   315,   317,   319,   321,   327,   332,   335,   337,   339,
     341,   344,   348,   351,   353,   356,   358,   360,   364,   366,
     369,   373,   378,   384,   390,   397,   400,   402,   406,   408,
     412,   414,   416,   418,   420,   423,   425,   427,   431,   437,
     442,   447,   454,   461,   467,   472,   476,   481,   486,   490,
     492,   495,   498,   502,   504,   507,   509,   513,   515,   519,
     522,   525,   527,   529,   533,   535,   538,   540,   542,   545,
     549,   552,   556,   560,   565,   569,   574,   577,   581,   585,
     590,   592,   596,   601,   603,   606,   610,   615,   618,   620,
     623,   627,   630,   632,   634,   636,   638,   640,   642,   646,
     651,   655,   658,   662,   664,   667,   669,   671,   673,   676,
     682,   690,   696,   702,   710,   717,   725,   732,   740,   744,
     747,   750,   753,   757,   759,   762,   764,   766,   771,   775,
     777
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     158,     0,    -1,     3,    -1,     4,    -1,     5,    -1,    21,
     113,    22,    -1,    94,    -1,    95,    23,   113,    24,    -1,
      95,    21,    22,    -1,    95,    21,    96,    22,    -1,    95,
      25,     3,    -1,    95,     6,     3,    -1,    95,     7,    -1,
      95,     8,    -1,    21,   141,    22,    16,   145,    17,    -1,
      21,   141,    22,    16,   145,    18,    17,    -1,   111,    -1,
      96,    18,   111,    -1,    95,    -1,     7,    97,    -1,     8,
      97,    -1,    98,    99,    -1,    72,    97,    -1,    72,    21,
     141,    22,    -1,    51,    -1,    47,    -1,    45,    -1,    46,
      -1,    29,    -1,    26,    -1,    97,    -1,    21,   141,    22,
      99,    -1,    99,    -1,   100,    47,    99,    -1,   100,    48,
      99,    -1,   100,    49,    99,    -1,   100,    -1,   101,    45,
     100,    -1,   101,    46,   100,    -1,   101,    -1,   102,     9,
     101,    -1,   102,    10,   101,    -1,   102,    -1,   103,    27,
     102,    -1,   103,    28,   102,    -1,   103,    11,   102,    -1,
     103,    12,   102,    -1,   103,    -1,   104,    13,   103,    -1,
     104,    14,   103,    -1,   104,    -1,   105,    51,   104,    -1,
     105,    -1,   106,    30,   105,    -1,   106,    -1,   107,    50,
     106,    -1,   107,    -1,   108,    32,   107,    -1,   108,    -1,
     109,    33,   108,    -1,   109,    -1,   109,    31,   113,    19,
     110,    -1,   110,    -1,    97,   112,   111,    -1,    20,    -1,
      34,    -1,    35,    -1,    36,    -1,    37,    -1,    38,    -1,
      39,    -1,    40,    -1,    41,    -1,    42,    -1,    43,    -1,
     111,    -1,   113,    18,   111,    -1,   110,    -1,   116,    15,
      -1,   116,   117,    15,    -1,   119,    -1,   119,   116,    -1,
     120,    -1,   120,   116,    -1,   131,    -1,   131,   116,    -1,
     132,    -1,   132,   116,    -1,   118,    -1,   117,    18,   118,
      -1,   133,    -1,   133,    20,   144,    -1,    52,    -1,    53,
      -1,    54,    -1,    55,    -1,    56,    -1,    71,    -1,    59,
      -1,    60,    -1,    61,    -1,    62,    -1,    63,    -1,    66,
      -1,    67,    -1,    68,    -1,    64,    -1,    65,    -1,    73,
      -1,    74,    -1,    75,    -1,   121,    -1,   128,    -1,    44,
      -1,   122,     3,    16,   123,    17,    -1,   122,    16,   123,
      17,    -1,   122,     3,    -1,    76,    -1,    77,    -1,   124,
      -1,   123,   124,    -1,   125,   126,    15,    -1,   120,   125,
      -1,   120,    -1,   131,   125,    -1,   131,    -1,   127,    -1,
     126,    18,   127,    -1,   133,    -1,    19,   114,    -1,   133,
      19,   114,    -1,    78,    16,   129,    17,    -1,    78,     3,
      16,   129,    17,    -1,    78,    16,   129,    18,    17,    -1,
      78,     3,    16,   129,    18,    17,    -1,    78,     3,    -1,
     130,    -1,   129,    18,   130,    -1,     3,    -1,     3,    20,
     114,    -1,    69,    -1,    58,    -1,    70,    -1,    57,    -1,
     135,   134,    -1,   134,    -1,     3,    -1,    21,   133,    22,
      -1,   134,    23,   136,   111,    24,    -1,   134,    23,   136,
      24,    -1,   134,    23,   111,    24,    -1,   134,    23,    54,
     136,   111,    24,    -1,   134,    23,   136,    54,   111,    24,
      -1,   134,    23,   136,    47,    24,    -1,   134,    23,    47,
      24,    -1,   134,    23,    24,    -1,   134,    21,   137,    22,
      -1,   134,    21,   140,    22,    -1,   134,    21,    22,    -1,
      47,    -1,    47,   136,    -1,    47,   135,    -1,    47,   136,
     135,    -1,   131,    -1,   136,   131,    -1,   138,    -1,   138,
      18,    79,    -1,   139,    -1,   138,    18,   139,    -1,   116,
     133,    -1,   116,   142,    -1,   116,    -1,     3,    -1,   140,
      18,     3,    -1,   125,    -1,   125,   142,    -1,   135,    -1,
     143,    -1,   135,   143,    -1,    21,   142,    22,    -1,    23,
      24,    -1,    23,   111,    24,    -1,   143,    23,    24,    -1,
     143,    23,   111,    24,    -1,    23,    47,    24,    -1,   143,
      23,    47,    24,    -1,    21,    22,    -1,    21,   137,    22,
      -1,   143,    21,    22,    -1,   143,    21,   137,    22,    -1,
     111,    -1,    16,   145,    17,    -1,    16,   145,    18,    17,
      -1,   144,    -1,   146,   144,    -1,   145,    18,   144,    -1,
     145,    18,   146,   144,    -1,   147,    20,    -1,   148,    -1,
     147,   148,    -1,    23,   114,    24,    -1,    25,     3,    -1,
     150,    -1,   151,    -1,   154,    -1,   155,    -1,   156,    -1,
     157,    -1,     3,    19,   149,    -1,    81,   114,    19,   149,
      -1,    82,    19,   149,    -1,    16,    17,    -1,    16,   152,
      17,    -1,   153,    -1,   152,   153,    -1,   115,    -1,   149,
      -1,    15,    -1,   113,    15,    -1,    83,    21,   113,    22,
     149,    -1,    83,    21,   113,    22,   149,    84,   149,    -1,
      85,    21,   113,    22,   149,    -1,    86,    21,   113,    22,
     149,    -1,    87,   149,    86,    21,   113,    22,    15,    -1,
      88,    21,   154,   154,    22,   149,    -1,    88,    21,   154,
     154,   113,    22,   149,    -1,    88,    21,   115,   154,    22,
     149,    -1,    88,    21,   115,   154,   113,    22,   149,    -1,
      89,     3,    15,    -1,    90,    15,    -1,    91,    15,    -1,
      92,    15,    -1,    92,   113,    15,    -1,   159,    -1,   158,
     159,    -1,   160,    -1,   115,    -1,   116,   133,   161,   151,
      -1,   116,   133,   151,    -1,   115,    -1,   161,   115,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    52,    52,    58,    64,    70,    77,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    93,    94,    98,   102,
     103,   104,   105,   106,   110,   111,   112,   113,   114,   115,
     119,   123,   127,   131,   132,   133,   137,   141,   142,   146,
     150,   151,   155,   159,   160,   161,   162,   166,   170,   171,
     175,   179,   183,   187,   191,   195,   199,   203,   207,   211,
     215,   219,   223,   227,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   248,   252,   256,   260,   261,
     274,   275,   283,   292,   297,   298,   299,   300,   304,   308,
     316,   320,   324,   325,   326,   327,   328,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   352,   353,   354,   358,   359,   363,
     364,   368,   372,   373,   374,   375,   379,   380,   384,   385,
     386,   390,   391,   392,   393,   394,   398,   399,   403,   404,
     408,   409,   410,   414,   418,   423,   431,   435,   436,   437,
     438,   443,   444,   445,   446,   447,   453,   458,   459,   466,
     467,   468,   473,   477,   478,   483,   487,   494,   498,   506,
     514,   515,   519,   520,   524,   525,   529,   530,   531,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     549,   550,   551,   555,   556,   557,   558,   562,   566,   567,
     571,   572,   576,   577,   578,   579,   580,   581,   588,   589,
     590,   594,   595,   602,   606,   610,   611,   618,   619,   623,
     624,   625,   629,   630,   631,   632,   633,   634,   638,   639,
     640,   641,   642,   649,   655,   664,   674,   689,   690,   701,
     702
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP",
  "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "SEMI_OP", "OCURLY_OP", "CCURLY_OP",
  "COMMA_OP", "COLON_OP", "EQUAL_OP", "OPENPAREN_OP", "CLOSEPAREN_OP",
  "OPENBRACE_OP", "CLOSEBRACE_OP", "PERIOD_OP", "NOT_OP", "LESS_OP",
  "GREATER_OP", "TILDE_OP", "XOR_OP", "QUESTION_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "PLUS_OP", "MINUS_OP", "TIMES_OP", "DIV_OP", "MOD_OP",
  "BIT_OR", "BIT_AND", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER",
  "INLINE", "RESTRICT", "CHAR", "SHORT", "INT", "LONG", "LONGLONG",
  "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "LONGDOUBLE", "CONST",
  "VOLATILE", "VOID", "SIZEOF", "BOOL", "COMPLEX", "IMAGINARY", "STRUCT",
  "UNION", "ENUM", "ELLIPSIS", "INCLUDE", "CASE", "DEFAULT", "IF", "ELSE",
  "SWITCH", "WHILE", "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN",
  "$accept", "primary_expression", "postfix_expression",
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
  "type_qualifier", "function_specifier", "declarator",
  "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "designation", "designator_list", "designator", "statement",
  "labeled_statement", "compound_statement", "block_item_list",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "declaration_list", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    93,    94,    94,    94,    94,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    96,    96,    97,    97,
      97,    97,    97,    97,    98,    98,    98,    98,    98,    98,
      99,    99,   100,   100,   100,   100,   101,   101,   101,   102,
     102,   102,   103,   103,   103,   103,   103,   104,   104,   104,
     105,   105,   106,   106,   107,   107,   108,   108,   109,   109,
     110,   110,   111,   111,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   113,   113,   114,   115,   115,
     116,   116,   116,   116,   116,   116,   116,   116,   117,   117,
     118,   118,   119,   119,   119,   119,   119,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   121,   121,   121,   122,   122,   123,
     123,   124,   125,   125,   125,   125,   126,   126,   127,   127,
     127,   128,   128,   128,   128,   128,   129,   129,   130,   130,
     131,   131,   131,   132,   133,   133,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   135,
     135,   135,   135,   136,   136,   137,   137,   138,   138,   139,
     139,   139,   140,   140,   141,   141,   142,   142,   142,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     144,   144,   144,   145,   145,   145,   145,   146,   147,   147,
     148,   148,   149,   149,   149,   149,   149,   149,   150,   150,
     150,   151,   151,   152,   152,   153,   153,   154,   154,   155,
     155,   155,   156,   156,   156,   156,   156,   156,   157,   157,
     157,   157,   157,   158,   158,   159,   159,   160,   160,   161,
     161
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     6,     7,     1,     3,     1,     2,
       2,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     3,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     4,     2,     1,     1,     1,
       2,     3,     2,     1,     2,     1,     1,     3,     1,     2,
       3,     4,     5,     5,     6,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     2,     1,     1,     3,     5,     4,
       4,     6,     6,     5,     4,     3,     4,     4,     3,     1,
       2,     2,     3,     1,     2,     1,     3,     1,     3,     2,
       2,     1,     1,     3,     1,     2,     1,     1,     2,     3,
       2,     3,     3,     4,     3,     4,     2,     3,     3,     4,
       1,     3,     4,     1,     2,     3,     4,     2,     1,     2,
       3,     2,     1,     1,     1,     1,     1,     1,     3,     4,
       3,     2,     3,     1,     2,     1,     1,     1,     2,     5,
       7,     5,     5,     7,     6,     7,     6,     7,     3,     2,
       2,     2,     3,     1,     2,     1,     1,     4,     3,     1,
       2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   113,    92,    93,    94,    95,    96,   143,   141,    98,
      99,   100,   101,   102,   106,   107,   103,   104,   105,   140,
     142,    97,   108,   109,   110,   117,   118,     0,   236,     0,
      80,    82,   111,     0,   112,    84,    86,     0,   233,   235,
     135,     0,   146,    78,     0,   159,     0,    88,    90,   145,
       0,    81,    83,   116,     0,    85,    87,     1,   234,     0,
     138,     0,   136,     0,   163,   161,   160,    79,     0,     0,
       0,   239,     0,   238,     0,     0,     0,   144,     0,   123,
       0,   119,     0,   125,     0,     0,   131,     0,   147,   164,
     162,    89,    90,     2,     3,     4,     0,     0,   217,   211,
       0,    29,    28,    26,    27,    25,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     6,
      18,    30,     0,    32,    36,    39,    42,    47,    50,    52,
      54,    56,    58,    60,    62,    75,     0,   215,   216,   202,
     203,     0,   213,   204,   205,   206,   207,     2,     0,   190,
      91,   240,   237,   172,   158,   171,     0,   165,   167,     0,
     155,    25,     0,     0,     0,     0,   122,   115,   120,     0,
       0,   126,   128,   124,   132,     0,    30,    77,   139,   133,
     137,     0,     0,    19,    20,     0,   174,     0,     0,    22,
       0,     0,     0,     0,     0,     0,     0,     0,   229,   230,
     231,     0,     0,    12,    13,     0,     0,     0,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,     0,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     218,     0,   212,   214,     0,     0,   193,     0,     0,     0,
     198,     0,     0,   169,   176,   170,   177,   156,     0,     0,
     157,   154,     0,   150,   149,    25,     0,     0,   114,   129,
     121,     0,     0,   134,   208,     0,     5,     0,   176,   175,
       0,     0,     0,   210,     0,     0,     0,     0,     0,     0,
     228,   232,    11,     8,     0,    16,     0,    10,    63,    33,
      34,    35,    37,    38,    40,    41,    45,    46,    43,    44,
      48,    49,    51,    53,    55,    57,     0,    59,    76,     0,
     201,   191,     0,   194,   197,   199,   186,     0,     0,   180,
      25,     0,   178,     0,     0,   166,   168,   173,     0,   153,
       0,   148,   127,   130,     0,     0,    31,    23,   209,     0,
       0,     0,     0,     0,     0,     0,     9,     7,     0,   200,
     192,   195,     0,   187,   179,   184,   181,   188,     0,   182,
      25,     0,   151,   152,     0,   219,   221,   222,     0,     0,
       0,     0,     0,    17,    61,   196,   189,   185,   183,    14,
       0,     0,     0,   226,     0,   224,     0,    15,   220,   223,
     227,   225
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   119,   120,   294,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   219,
     136,   178,    28,    72,    46,    47,    30,    31,    32,    33,
      80,    81,    82,   170,   171,    34,    61,    62,    35,    36,
      63,    49,    50,    66,   327,   157,   158,   159,   187,   328,
     256,   246,   247,   248,   249,   250,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    37,    38,    39,    74
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -308
static const yytype_int16 yypact[] =
{
    1609,  -308,  -308,  -308,  -308,  -308,  -308,  -308,  -308,  -308,
    -308,  -308,  -308,  -308,  -308,  -308,  -308,  -308,  -308,  -308,
    -308,  -308,  -308,  -308,  -308,  -308,  -308,    53,  -308,    23,
    1609,  1609,  -308,   116,  -308,  1609,  1609,   284,  -308,  -308,
     113,   138,  -308,  -308,    56,    18,     9,  -308,  1348,    70,
      50,  -308,  -308,   132,  1637,  -308,  -308,  -308,  -308,   138,
     149,    83,  -308,   208,  -308,  -308,    18,  -308,    56,   366,
    1048,  -308,    23,  -308,  1404,   775,   851,    70,  1637,  1637,
    1432,  -308,    31,  1637,   159,  1282,  -308,    77,  -308,  -308,
    -308,  -308,   218,   224,  -308,  -308,  1291,  1291,  -308,  -308,
     671,  -308,  -308,  -308,  -308,  -308,  -308,  1327,  1282,   233,
     243,   248,   254,   546,   258,   219,   266,   268,  1093,  -308,
     110,   120,  1282,  -308,   147,   200,   238,   154,   242,   246,
     269,   250,   271,   203,  -308,  -308,   202,  -308,  -308,  -308,
    -308,   456,  -308,  -308,  -308,  -308,  -308,  -308,   987,  -308,
    -308,  -308,  -308,  -308,  -308,    45,   276,   283,  -308,    -2,
    -308,   286,    68,   287,   861,  1467,  -308,  -308,  -308,  1282,
     213,  -308,   288,  -308,  -308,    87,  -308,  -308,  -308,  -308,
    -308,   546,   671,  -308,  -308,   121,    34,   290,   671,  -308,
     289,   546,  1282,  1282,  1282,   227,   595,   299,  -308,  -308,
    -308,   214,   312,  -308,  -308,  1102,  1282,   313,  -308,  -308,
    -308,  -308,  -308,  -308,  -308,  -308,  -308,  -308,  -308,  1282,
    -308,  1282,  1282,  1282,  1282,  1282,  1282,  1282,  1282,  1282,
    1282,  1282,  1282,  1282,  1282,  1282,  1282,  1282,  1282,  1282,
    -308,  1282,  -308,  -308,  1282,   314,  -308,   245,  1048,   124,
    -308,   747,  1138,  -308,   102,  -308,   212,  -308,  1581,   315,
    -308,  -308,  1015,  -308,  -308,   295,  1282,   296,  -308,  -308,
    -308,    31,  1282,  -308,  -308,   301,  -308,  1525,   216,  -308,
    1147,   302,   546,  -308,   153,   156,   166,   304,  1192,  1192,
    -308,  -308,  -308,  -308,   167,  -308,    40,  -308,  -308,  -308,
    -308,  -308,   147,   147,   200,   200,   238,   238,   238,   238,
     154,   154,   242,   246,   269,   250,   241,   271,  -308,   303,
    -308,  -308,   921,  -308,  -308,  -308,  -308,   307,   308,  -308,
     310,   332,   212,  1553,  1201,  -308,  -308,  -308,   339,  -308,
     340,  -308,  -308,  -308,   316,   987,  -308,   316,  -308,   546,
     546,   546,  1282,  1237,  1246,  1282,  -308,  -308,  1282,  -308,
    -308,  -308,  1048,  -308,  -308,  -308,  -308,  -308,   309,  -308,
     341,   342,  -308,  -308,   256,   291,  -308,  -308,   168,   546,
     169,   546,   201,  -308,  -308,  -308,  -308,  -308,  -308,  -308,
     953,   546,   352,  -308,   546,  -308,   546,  -308,  -308,  -308,
    -308,  -308
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -308,  -308,  -308,  -308,   -23,  -308,  -112,    64,    69,    -4,
      58,   134,   137,   140,   141,   145,  -308,   -80,   -69,  -308,
     -86,  -102,   -29,     0,  -308,   311,  -308,   -37,  -308,  -308,
     318,   -67,   -61,  -308,   106,  -308,   321,   -78,   226,  -308,
     -21,   -39,   -33,   -47,   -72,  -308,   127,  -308,   -58,  -132,
    -229,   -68,    41,  -307,  -308,   144,  -109,  -308,    12,  -308,
     253,  -175,  -308,  -308,  -308,  -308,   360,  -308,  -308
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      29,   149,   150,   156,   195,   177,   190,   163,    48,   180,
     220,    77,    65,   168,   185,   362,   259,    79,   166,    71,
     260,   289,   173,   255,    67,   332,    42,    68,   177,   164,
      51,    52,   201,    90,    42,    55,    56,    29,    43,   186,
     137,    79,    79,    79,    44,   151,    79,    92,    42,   332,
     169,    92,    44,    42,   279,   277,    40,   252,   241,    42,
      73,   172,   176,    79,   357,    45,   251,   269,   252,    41,
      45,    44,   274,   183,   184,   155,     8,    44,    45,   149,
      60,    45,   283,   362,   189,   176,   152,    19,    20,   177,
      60,    75,    45,    76,   179,   267,   185,   180,   168,   176,
      86,    87,   185,    45,   273,    42,   284,   285,   286,   299,
     300,   301,   137,   353,   354,   262,   202,   203,   204,    53,
     296,   186,   254,   251,   275,   252,     8,   186,    79,    59,
     281,   205,    54,   206,   253,   207,   295,    19,    20,   241,
     208,    60,   319,   276,   324,    79,   176,   244,    78,   245,
     298,    79,   316,   278,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   177,   228,   229,   288,   346,    85,
     343,   241,   318,   348,   241,   349,   174,   175,   350,   149,
     323,   230,   231,   331,   241,   355,   241,   241,   351,   356,
     392,   394,   177,   338,   221,   222,   223,   340,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,    77,   176,   240,   254,   241,
     241,   176,   197,   396,   306,   307,   308,   309,   270,   291,
      88,   271,   241,   333,   238,   334,   239,   277,    70,   252,
     375,   376,   377,   181,   278,   224,   225,   226,   227,   176,
     172,   155,   191,   149,   361,   232,   233,   176,   155,   241,
     358,   368,   321,   322,   192,   371,   378,   380,   382,   193,
     393,    64,   395,   389,   390,   194,   149,   155,   384,   196,
      83,   198,   398,   199,    57,   400,   383,   401,   302,   303,
     310,   311,    89,   149,   385,   304,   305,   234,   257,   235,
     236,   258,    64,   237,    83,    83,    83,   272,   282,    83,
     261,   263,   280,   287,   290,   292,   297,   320,   337,   339,
     341,   149,   361,   344,   347,   352,    83,   359,     1,   363,
     364,   386,   345,   155,   365,   176,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,   366,    22,    23,    24,
      25,    26,    27,   372,   373,   387,   388,   399,   312,    93,
      94,    95,   313,    96,    97,   391,   314,   342,   315,    91,
      84,    98,    69,    99,   317,   336,   374,   100,    64,     0,
      89,    83,   101,   325,   243,   102,   165,    58,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,     0,
       1,   103,   104,   105,    83,     0,     0,   106,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,   107,    22,
      23,    24,    25,    26,    27,     0,     0,   108,   109,   110,
       0,   111,   112,   113,   114,   115,   116,   117,   118,    93,
      94,    95,     0,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    69,   242,     0,     0,     0,   100,     0,     0,
       0,     0,   101,     0,     0,   102,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,   103,   104,   105,     0,     0,     0,   106,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,   107,    22,
      23,    24,    25,    26,    27,     0,     0,   108,   109,   110,
       0,   111,   112,   113,   114,   115,   116,   117,   118,    93,
      94,    95,     0,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    69,     0,     0,     0,     0,   100,     0,     0,
       0,     0,   101,     0,     0,   102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,   105,     0,     0,     0,   106,   147,    94,
      95,     0,    96,    97,     0,     0,     0,     0,     0,     0,
      98,     0,     0,     0,     0,     0,   100,     0,   107,     0,
       0,   101,     0,     0,   102,     0,     0,   108,   109,   110,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     1,
     103,   104,   105,     0,     0,     0,   106,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   107,    22,    23,
      24,    25,    26,    27,   147,    94,    95,     0,    96,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,     0,     0,     0,     0,   101,     0,     0,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,   103,   104,   105,     0,
       0,     0,   106,     0,     0,     0,     0,     0,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   107,    22,    23,    24,    25,    26,    27,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   251,   326,
     252,     0,     0,     0,     0,     0,     0,     0,   153,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,    45,     0,     0,   154,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     1,
      22,    23,    24,    25,    26,    27,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,    22,    23,
      24,    25,    26,    27,   147,    94,    95,     0,    96,    97,
       0,     0,     0,     0,   147,    94,    95,     0,    96,    97,
       0,     0,   100,     0,     0,   160,     0,   101,     0,     0,
     102,     0,   100,     0,     0,   264,     0,   101,     0,     0,
     102,     0,     0,     0,     0,     0,   103,   104,   161,     0,
       0,     0,   106,     0,     0,   162,   103,   104,   265,     8,
       0,     0,   106,     0,     0,   266,     0,     0,     0,     8,
      19,    20,     0,   107,   147,    94,    95,     0,    96,    97,
      19,    20,     0,   107,     0,     0,     0,   148,   360,     0,
       0,     0,   100,     0,   244,     0,   245,   101,     0,     0,
     102,     0,     0,     0,     0,     0,   147,    94,    95,     0,
      96,    97,     0,     0,     0,     0,   103,   104,   105,   148,
     397,     0,   106,     0,   100,     0,   244,     0,   245,   101,
       0,     0,   102,     0,     0,     0,     0,     0,     0,     0,
     147,    94,    95,   107,    96,    97,     0,     0,   103,   104,
     105,     0,     0,   148,   106,     0,     0,     0,   100,     0,
     244,     0,   245,   101,     0,     0,   102,     0,   147,    94,
      95,     0,    96,    97,     0,   107,     0,     0,     0,     0,
       0,     0,   103,   104,   105,     0,   100,     0,   106,     0,
       0,   101,     0,     0,   102,     0,     0,     0,     0,     0,
       0,   147,    94,    95,     0,    96,    97,     0,     0,   107,
     103,   104,   105,     0,   148,     0,   106,     0,     0,   100,
       0,     0,     0,     8,   101,     0,     0,   102,     0,     0,
       0,     0,     0,     0,    19,    20,     0,   107,     0,     0,
       0,     0,     0,   103,   104,   105,   147,    94,    95,   106,
      96,    97,     0,     0,     0,   147,    94,    95,   200,    96,
      97,     0,     0,     0,   100,     0,     0,     0,     0,   101,
     107,     0,   102,   100,   293,     0,     0,     0,   101,     0,
       0,   102,     0,     0,     0,     0,     0,     0,   103,   104,
     105,   147,    94,    95,   106,    96,    97,   103,   104,   105,
     147,    94,    95,   106,    96,    97,     0,     0,     0,   100,
       0,     0,   329,   345,   101,   107,     0,   102,   100,     0,
       0,     0,     0,   101,   107,     0,   102,     0,     0,     0,
       0,     0,     0,   103,   104,   330,     0,     0,     0,   106,
       0,     0,   103,   104,   105,   147,    94,    95,   106,    96,
      97,     0,     0,     0,   147,    94,    95,    98,    96,    97,
     107,     0,     0,   100,     0,     0,     0,     0,   101,   107,
       0,   102,   100,     0,     0,   369,     0,   101,     0,     0,
     102,     0,     0,     0,     0,     0,     0,   103,   104,   105,
     147,    94,    95,   106,    96,    97,   103,   104,   370,   147,
      94,    95,   106,    96,    97,     0,     0,     0,   100,   379,
       0,     0,     0,   101,   107,     0,   102,   100,   381,     0,
       0,     0,   101,   107,     0,   102,     0,     0,     0,     0,
       0,     0,   103,   104,   105,   147,    94,    95,   106,    96,
      97,   103,   104,   105,   147,    94,    95,   106,    96,    97,
       0,     0,     0,   100,     0,     0,     0,     0,   101,   107,
       0,   102,   182,     0,     0,     0,     0,   101,   107,     0,
     102,     0,     0,     0,     0,     0,     0,   103,   104,   105,
     147,    94,    95,   106,    96,    97,   103,   104,   105,     0,
       0,     0,   106,     0,     0,     0,     0,     0,   188,     0,
       0,     0,     0,   101,   107,     0,   102,     0,     0,     0,
       0,     0,     0,   107,    69,     0,     0,     0,    70,     0,
       0,     0,   103,   104,   105,     0,     0,     0,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,   107,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      69,    22,    23,    24,    25,    26,    27,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,   167,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     1,    22,    23,    24,
      25,    26,    27,     0,   268,     0,     0,     0,     0,     0,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,    22,    23,    24,    25,    26,
      27,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
      22,    23,    24,    25,    26,    27,   277,   326,   252,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     0,    45,     0,     0,   367,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     1,    22,    23,
      24,    25,    26,    27,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     1,    22,    23,    24,    25,
      26,    27,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     1,    22,    23,    24,    25,    26,    27,
     335,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     1,    22,    23,    24,    25,    26,    27,     0,     0,
       0,     0,     0,     0,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
      22,    23,    24,    25,    26,    27
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-308)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    70,    70,    75,   113,    85,   108,    76,    29,    87,
     122,    50,    45,    80,   100,   322,    18,    54,    79,    48,
      22,   196,    83,   155,    15,   254,     3,    18,   108,    76,
      30,    31,   118,    66,     3,    35,    36,    37,    15,   100,
      69,    78,    79,    80,    21,    74,    83,    68,     3,   278,
      19,    72,    21,     3,   186,    21,     3,    23,    18,     3,
      48,    82,    85,   100,    24,    47,    21,   169,    23,    16,
      47,    21,   181,    96,    97,    75,    58,    21,    47,   148,
       3,    47,   191,   390,   107,   108,    74,    69,    70,   169,
       3,    21,    47,    23,    17,   164,   182,   175,   165,   122,
      17,    18,   188,    47,    17,     3,   192,   193,   194,   221,
     222,   223,   141,   288,   289,   162,     6,     7,     8,     3,
     206,   182,   155,    21,   182,    23,    58,   188,   165,    16,
     188,    21,    16,    23,   155,    25,   205,    69,    70,    18,
      20,     3,   244,    22,    20,   182,   169,    23,    16,    25,
     219,   188,   238,   186,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,   244,    11,    12,   196,   280,    20,
     272,    18,   241,   282,    18,    22,    17,    18,    22,   248,
     248,    27,    28,   252,    18,    18,    18,    18,    22,    22,
      22,    22,   272,   262,    47,    48,    49,   266,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   254,   239,    15,   251,    18,
      18,   244,     3,    22,   228,   229,   230,   231,    15,    15,
      22,    18,    18,    21,    31,    23,    33,    21,    20,    23,
     349,   350,   351,    19,   277,    45,    46,     9,    10,   272,
     271,   251,    19,   322,   322,    13,    14,   280,   258,    18,
      19,   333,    17,    18,    21,   334,   352,   353,   354,    21,
     379,    45,   381,    17,    18,    21,   345,   277,   358,    21,
      54,    15,   391,    15,     0,   394,   355,   396,   224,   225,
     232,   233,    66,   362,   362,   226,   227,    51,    22,    30,
      50,    18,    76,    32,    78,    79,    80,    19,    19,    83,
      24,    24,    22,    86,    15,     3,     3,     3,     3,    24,
      24,   390,   390,    22,    22,    21,   100,    24,    44,    22,
      22,    22,    16,   333,    24,   358,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    24,    73,    74,    75,
      76,    77,    78,    24,    24,    24,    24,    15,   234,     3,
       4,     5,   235,     7,     8,    84,   236,   271,   237,    68,
      59,    15,    16,    17,   239,   258,   345,    21,   162,    -1,
     164,   165,    26,   249,   141,    29,    78,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,    -1,
      44,    45,    46,    47,   188,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    -1,    -1,    81,    82,    83,
      -1,    85,    86,    87,    88,    89,    90,    91,    92,     3,
       4,     5,    -1,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    26,    -1,    -1,    29,    -1,    -1,   262,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    -1,    -1,    81,    82,    83,
      -1,    85,    86,    87,    88,    89,    90,    91,    92,     3,
       4,     5,    -1,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    -1,    -1,    51,     3,     4,
       5,    -1,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    21,    -1,    72,    -1,
      -1,    26,    -1,    -1,    29,    -1,    -1,    81,    82,    83,
      -1,    85,    86,    87,    88,    89,    90,    91,    92,    44,
      45,    46,    47,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,     3,     4,     5,    -1,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    47,    -1,    -1,    22,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    44,
      73,    74,    75,    76,    77,    78,    -1,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    -1,    73,    74,
      75,    76,    77,    78,     3,     4,     5,    -1,     7,     8,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,     8,
      -1,    -1,    21,    -1,    -1,    24,    -1,    26,    -1,    -1,
      29,    -1,    21,    -1,    -1,    24,    -1,    26,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      -1,    -1,    51,    -1,    -1,    54,    45,    46,    47,    58,
      -1,    -1,    51,    -1,    -1,    54,    -1,    -1,    -1,    58,
      69,    70,    -1,    72,     3,     4,     5,    -1,     7,     8,
      69,    70,    -1,    72,    -1,    -1,    -1,    16,    17,    -1,
      -1,    -1,    21,    -1,    23,    -1,    25,    26,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
       7,     8,    -1,    -1,    -1,    -1,    45,    46,    47,    16,
      17,    -1,    51,    -1,    21,    -1,    23,    -1,    25,    26,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    72,     7,     8,    -1,    -1,    45,    46,
      47,    -1,    -1,    16,    51,    -1,    -1,    -1,    21,    -1,
      23,    -1,    25,    26,    -1,    -1,    29,    -1,     3,     4,
       5,    -1,     7,     8,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    21,    -1,    51,    -1,
      -1,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,     7,     8,    -1,    -1,    72,
      45,    46,    47,    -1,    16,    -1,    51,    -1,    -1,    21,
      -1,    -1,    -1,    58,    26,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,     3,     4,     5,    51,
       7,     8,    -1,    -1,    -1,     3,     4,     5,    15,     7,
       8,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    26,
      72,    -1,    29,    21,    22,    -1,    -1,    -1,    26,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,     3,     4,     5,    51,     7,     8,    45,    46,    47,
       3,     4,     5,    51,     7,     8,    -1,    -1,    -1,    21,
      -1,    -1,    24,    16,    26,    72,    -1,    29,    21,    -1,
      -1,    -1,    -1,    26,    72,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,    51,
      -1,    -1,    45,    46,    47,     3,     4,     5,    51,     7,
       8,    -1,    -1,    -1,     3,     4,     5,    15,     7,     8,
      72,    -1,    -1,    21,    -1,    -1,    -1,    -1,    26,    72,
      -1,    29,    21,    -1,    -1,    24,    -1,    26,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
       3,     4,     5,    51,     7,     8,    45,    46,    47,     3,
       4,     5,    51,     7,     8,    -1,    -1,    -1,    21,    22,
      -1,    -1,    -1,    26,    72,    -1,    29,    21,    22,    -1,
      -1,    -1,    26,    72,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,     3,     4,     5,    51,     7,
       8,    45,    46,    47,     3,     4,     5,    51,     7,     8,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    26,    72,
      -1,    29,    21,    -1,    -1,    -1,    -1,    26,    72,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
       3,     4,     5,    51,     7,     8,    45,    46,    47,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    26,    72,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    16,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    45,    46,    47,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      16,    73,    74,    75,    76,    77,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    44,    73,    74,    75,
      76,    77,    78,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    -1,    73,    74,    75,    76,    77,
      78,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    -1,
      73,    74,    75,    76,    77,    78,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    47,    -1,    -1,    22,    -1,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    44,    73,    74,
      75,    76,    77,    78,    -1,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    44,    73,    74,    75,    76,
      77,    78,    -1,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    44,    73,    74,    75,    76,    77,    78,
      79,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    44,    73,    74,    75,    76,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    -1,
      73,    74,    75,    76,    77,    78
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    44,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    73,    74,    75,    76,    77,    78,   115,   116,
     119,   120,   121,   122,   128,   131,   132,   158,   159,   160,
       3,    16,     3,    15,    21,    47,   117,   118,   133,   134,
     135,   116,   116,     3,    16,   116,   116,     0,   159,    16,
       3,   129,   130,   133,   131,   135,   136,    15,    18,    16,
      20,   115,   116,   151,   161,    21,    23,   134,    16,   120,
     123,   124,   125,   131,   129,    20,    17,    18,    22,   131,
     135,   118,   133,     3,     4,     5,     7,     8,    15,    17,
      21,    26,    29,    45,    46,    47,    51,    72,    81,    82,
      83,    85,    86,    87,    88,    89,    90,    91,    92,    94,
      95,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   113,   115,   149,   150,
     151,   152,   153,   154,   155,   156,   157,     3,    16,   111,
     144,   115,   151,     3,    22,   116,   137,   138,   139,   140,
      24,    47,    54,   111,   136,   123,   125,    17,   124,    19,
     126,   127,   133,   125,    17,    18,    97,   110,   114,    17,
     130,    19,    21,    97,    97,   113,   125,   141,    21,    97,
     114,    19,    21,    21,    21,   149,    21,     3,    15,    15,
      15,   113,     6,     7,     8,    21,    23,    25,    20,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,   112,
      99,    47,    48,    49,    45,    46,     9,    10,    11,    12,
      27,    28,    13,    14,    51,    30,    50,    32,    31,    33,
      15,    18,    17,   153,    23,    25,   144,   145,   146,   147,
     148,    21,    23,   133,   135,   142,   143,    22,    18,    18,
      22,    24,   136,    24,    24,    47,    54,   111,    17,   114,
      15,    18,    19,    17,   149,   141,    22,    21,   135,   142,
      22,   141,    19,   149,   113,   113,   113,    86,   115,   154,
      15,    15,     3,    22,    96,   111,   113,     3,   111,    99,
      99,    99,   100,   100,   101,   101,   102,   102,   102,   102,
     103,   103,   104,   105,   106,   107,   113,   108,   111,   114,
       3,    17,    18,   144,    20,   148,    22,   137,   142,    24,
      47,   111,   143,    21,    23,    79,   139,     3,   111,    24,
     111,    24,   127,   114,    22,    16,    99,    22,   149,    22,
      22,    22,    21,   154,   154,    18,    22,    24,    19,    24,
      17,   144,   146,    22,    22,    24,    24,    22,   137,    24,
      47,   111,    24,    24,   145,   149,   149,   149,   113,    22,
     113,    22,   113,   111,   110,   144,    22,    24,    24,    17,
      18,    84,    22,   149,    22,   149,    22,    17,   149,    15,
     149,   149
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 52 "c.y"
    {
                                             strcpy((yyval.CompilerInfo).data.identifier, (yyvsp[(1) - (1)].CompilerInfo).data.identifier);
                                             (yyval.CompilerInfo).data.type = TYPE_NULL;
                                             (yyval.CompilerInfo).data.constant = FALSE;
                                             printCompilerInfoNode("<EXP> IDENTIFIER REDUCE to primary_expression",NULL);
                                            }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 58 "c.y"
    {
                                             strcpy((yyval.CompilerInfo).data.identifier, (yyvsp[(1) - (1)].CompilerInfo).data.identifier);
                                             (yyval.CompilerInfo).data.type = TYPE_NULL;
                                             (yyval.CompilerInfo).data.constant = TRUE;
                                             printCompilerInfoNode("<EXP> CONSTANT REDUCE to primary_expression",&(yyval.CompilerInfo));
                                            }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 64 "c.y"
    {
                                             strcpy((yyval.CompilerInfo).data.identifier, (yyvsp[(1) - (1)].CompilerInfo).data.identifier);
                                             (yyval.CompilerInfo).data.type = TYPE_NULL;
                                             (yyval.CompilerInfo).data.constant = TRUE;
                                             printCompilerInfoNode("STRING_LITERAL REDUCE to primary_expression",&(yyval.CompilerInfo));
                                            }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 70 "c.y"
    {
                                             (yyval.CompilerInfo) = (yyvsp[(2) - (3)].CompilerInfo);
                                             printCompilerInfoNode("<EXP> OPENPAREN_OP expression CLOSEPAREN_OP REDUCE to primary_expression",NULL);
                                            }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 77 "c.y"
    {
                                                                                          (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                                                                                          printCompilerInfoNode("<EXP> primary_expression REDUCE to postfix_expression",NULL);
                                                                                         }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 81 "c.y"
    {printCompilerInfoNode("postfix_expression OPENBRACE_OP expression CLOSEBRACE_OP REDUCE to postfix_expression",NULL);}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 82 "c.y"
    {printCompilerInfoNode("postfix_expression OPENPAREN_OP CLOSEPAREN_OP REDUCE to postfix_expression",NULL);}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 83 "c.y"
    {printCompilerInfoNode("postfix_expression OPENPAREN_OP argument_expression_list CLOSEPAREN_OP REDUCE to postfix_expression",NULL);}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 84 "c.y"
    {printCompilerInfoNode("postfix_expression PERIOD_OP IDENTIFIER REDUCE to postfix_expression",NULL);}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 85 "c.y"
    {printCompilerInfoNode("postfix_expression PTR_OP IDENTIFIER REDUCE to postfix_expression",NULL);}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 86 "c.y"
    {printCompilerInfoNode("postfix_expression INC_OP REDUCE to postfix_expression",NULL);}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 87 "c.y"
    {printCompilerInfoNode("postfix_expression DEC_OP REDUCE to postfix_expression",NULL);}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 88 "c.y"
    {printCompilerInfoNode("OPENPAREN_OP type_name CLOSEPAREN_OP OCURLY_OP initializer_list CCURLY_OP REDUCE to postfix_expression",NULL);}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 89 "c.y"
    {printCompilerInfoNode("OPENPAREN_OP type_name CLOSEPAREN_OP OCURLY_OP initializer_list COMMA_OP CCURLY_OP REDUCE to postfix_expression",NULL);}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 93 "c.y"
    {printCompilerInfoNode("assignment_expression REDUCE to argument_expression_list",NULL);}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 94 "c.y"
    {printCompilerInfoNode("argument_expression_list COMMA_OP assignment_expression REDUCE to argument_expression_list",NULL);}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 98 "c.y"
    {
                                                     (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                                                     printCompilerInfoNode("<EXP> postfix_expression REDUCE to unary_expression",NULL);
                                                    }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 102 "c.y"
    {printCompilerInfoNode("INC_OP unary_expression REDUCE to unary_expression",NULL);}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 103 "c.y"
    {printCompilerInfoNode("DEC_OP unary_expression REDUCE to unary_expression",NULL);}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 104 "c.y"
    {printCompilerInfoNode("unary_operator cast_expression REDUCE to unary_expression",NULL);}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 105 "c.y"
    {printCompilerInfoNode("SIZEOF unary_expression REDUCE to unary_expression",NULL);}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 106 "c.y"
    {printCompilerInfoNode("SIZEOF OPENPAREN_OP type_name CLOSEPAREN_OP REDUCE to unary_expression",NULL);}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 110 "c.y"
    {printCompilerInfoNode("BIT_AND REDUCE to unary_operator",NULL);}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 111 "c.y"
    {printCompilerInfoNode("TIMES_OP REDUCE to unary_operator",NULL);}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 112 "c.y"
    {printCompilerInfoNode("PLUS_OP REDUCE to unary_operator",NULL);}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 113 "c.y"
    {printCompilerInfoNode("MINUS_OP REDUCE to unary_operator",NULL);}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 114 "c.y"
    {printCompilerInfoNode("TILDE_OP REDUCE to unary_operator",NULL);}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 115 "c.y"
    {printCompilerInfoNode("NOT_OP REDUCE to unary_operator",NULL);}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 119 "c.y"
    {
                                                             (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                                                             printCompilerInfoNode("<EXP> unary_expression REDUCE to cast_expression",NULL);
                                                            }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 123 "c.y"
    {printCompilerInfoNode("OPENPAREN_OP type_name CLOSEPAREN_OP cast_expression REDUCE to cast_expression",NULL);}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 127 "c.y"
    {
                                                           (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                                                           printCompilerInfoNode("<EXP> cast_expression REDUCE to multiplicative_expression",NULL);
                                                          }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 131 "c.y"
    {printCompilerInfoNode("multiplicative_expression TIMES_OP cast_expression REDUCE to multiplicative_expression",NULL);}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 132 "c.y"
    {printCompilerInfoNode("multiplicative_expression DIV_OP cast_expression REDUCE to multiplicative_expression",NULL);}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 133 "c.y"
    {printCompilerInfoNode("multiplicative_expression MOD_OP cast_expression REDUCE to multiplicative_expression",NULL);}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 137 "c.y"
    {
                                                               (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                                                               printCompilerInfoNode("<EXP> multiplicative_expression REDUCE to additive_expression",NULL);
                                                              }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 141 "c.y"
    {printCompilerInfoNode("additive_expression PLUS_OP multiplicative_expression REDUCE to additive_expression",NULL);}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 142 "c.y"
    {printCompilerInfoNode("additive_expression MINUS_OP multiplicative_expression REDUCE to additive_expression",NULL);}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 146 "c.y"
    {
                                                     (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                                                     printCompilerInfoNode("<EXP> additive_expression REDUCE to shift_expression",NULL);
                                                    }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 150 "c.y"
    {printCompilerInfoNode("shift_expression LEFT_OP additive_expression REDUCE to shift_expression",NULL);}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 151 "c.y"
    {printCompilerInfoNode("shift_expression RIGHT_OP additive_expression REDUCE to shift_expression",NULL);}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 155 "c.y"
    {
                                                         (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                                                         printCompilerInfoNode("<EXP> shift_expression REDUCE to relational_expression",NULL);
                                                        }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 159 "c.y"
    {printCompilerInfoNode("relational_expression LESS_OP shift_expression REDUCE to relational_expression",NULL);}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 160 "c.y"
    {printCompilerInfoNode("relational_expression GREATER_OP shift_expression REDUCE to relational_expression",NULL);}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 161 "c.y"
    {printCompilerInfoNode("relational_expression LE_OP shift_expression REDUCE to relational_expression",NULL);}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 162 "c.y"
    {printCompilerInfoNode("relational_expression GE_OP shift_expression REDUCE to relational_expression",NULL);}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 166 "c.y"
    {
                                                         (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                                                         printCompilerInfoNode("<EXP> relational_expression REDUCE to equality_expression",NULL);
                                                        }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 170 "c.y"
    {printCompilerInfoNode("equality_expression EQ_OP relational_expression REDUCE to equality_expression",NULL);}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 171 "c.y"
    {printCompilerInfoNode("equality_expression NE_OP relational_expression REDUCE to equality_expression",NULL);}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 175 "c.y"
    {
                                                    (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                                                    printCompilerInfoNode("<EXP> equality_expression REDUCE to and_expression",NULL);
                                                   }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 179 "c.y"
    {printCompilerInfoNode("and_expression BIT_AND equality_expression REDUCE to and_expression",NULL);}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 183 "c.y"
    {
                                                       (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                                                       printCompilerInfoNode("<EXP> and_expression REDUCE to exclusive_or_expression",NULL);
                                                      }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 187 "c.y"
    {printCompilerInfoNode("exclusive_or_expression XOR_OP and_expression REDUCE to exclusive_or_expression",NULL);}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 191 "c.y"
    {
                                                                (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                                                                printCompilerInfoNode("<EXP> exclusive_or_expression REDUCE to inclusive_or_expression",NULL);
                                                               }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 195 "c.y"
    {printCompilerInfoNode("inclusive_or_expression BIT_OR exclusive_or_expression REDUCE to inclusive_or_expression",NULL);}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 199 "c.y"
    {
                                                             (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                                                             printCompilerInfoNode("<EXP> inclusive_or_expression REDUCE to logical_and_expression",NULL);
                                                            }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 203 "c.y"
    {printCompilerInfoNode("logical_and_expression AND_OP inclusive_or_expression REDUCE to logical_and_expression",NULL);}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 207 "c.y"
    {
                                                          (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                                                          printCompilerInfoNode("<EXP> logical_and_expression REDUCE to logical_or_expression",NULL);
                                                         }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 211 "c.y"
    {printCompilerInfoNode("logical_or_expression OR_OP logical_and_expression REDUCE to logical_or_expression",NULL);}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 215 "c.y"
    {
                                                                                    (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                                                                                    printCompilerInfoNode("<EXP> logical_or_expression REDUCE to conditional_expression",NULL);
                                                                                   }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 219 "c.y"
    {printCompilerInfoNode("logical_or_expression QUESTION_OP expression COLON_OP conditional_expression REDUCE to conditional_expression",NULL);}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 223 "c.y"
    {
                                                                  (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                                                                  printCompilerInfoNode("<EXP> conditional_expression REDUCE to assignment_expression",NULL);
                                                                 }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 227 "c.y"
    {
                                                                  (yyval.CompilerInfo) = (yyvsp[(3) - (3)].CompilerInfo);
                                                                  printCompilerInfoNode("<EXP> unary_expression assignment_operator assignment_expression REDUCE to assignment_expression",NULL);
                                                                 }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 234 "c.y"
    {printCompilerInfoNode("EQUAL_OP REDUCE to assignment_operator",NULL);}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 235 "c.y"
    {printCompilerInfoNode("MUL_ASSIGN REDUCE to assignment_operator",NULL);}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 236 "c.y"
    {printCompilerInfoNode("DIV_ASSIGN REDUCE to assignment_operator",NULL);}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 237 "c.y"
    {printCompilerInfoNode("MOD_ASSIGN REDUCE to assignment_operator",NULL);}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 238 "c.y"
    {printCompilerInfoNode("ADD_ASSIGN REDUCE to assignment_operator",NULL);}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 239 "c.y"
    {printCompilerInfoNode("SUB_ASSIGN REDUCE to assignment_operator",NULL);}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 240 "c.y"
    {printCompilerInfoNode("LEFT_ASSIGN REDUCE to assignment_operator",NULL);}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 241 "c.y"
    {printCompilerInfoNode("RIGHT_ASSIGN REDUCE to assignment_operator",NULL);}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 242 "c.y"
    {printCompilerInfoNode("AND_ASSIGN REDUCE to assignment_operator",NULL);}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 243 "c.y"
    {printCompilerInfoNode("XOR_ASSIGN REDUCE to assignment_operator",NULL);}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 244 "c.y"
    {printCompilerInfoNode("OR_ASSIGN REDUCE to assignment_operator",NULL);}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 248 "c.y"
    {
                                                 (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                                                 printCompilerInfoNode("<EXP> assignment_expression REDUCE to expression",NULL);
                                                }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 252 "c.y"
    {printCompilerInfoNode(" expression COMMA_OP assignment_expression REDUCE to expression",NULL);}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 256 "c.y"
    {printCompilerInfoNode("conditional_expression REDUCE to constant_expression",NULL);}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 260 "c.y"
    {printCompilerInfoNode("declaration_specifiers SEMI_OP REDUCE to declaration",NULL);}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 261 "c.y"
    {
                                                             (yyval.CompilerInfo).data.sign = (yyvsp[(1) - (3)].CompilerInfo).data.sign;
                                                             (yyval.CompilerInfo).data.type = (yyvsp[(1) - (3)].CompilerInfo).data.type;
                                                             (yyval.CompilerInfo).data.storage = (yyvsp[(1) - (3)].CompilerInfo).data.storage;
                                                             (yyval.CompilerInfo).data.pointerLevel = (yyvsp[(2) - (3)].CompilerInfo).data.pointerLevel;
                                                             (yyval.CompilerInfo).data.emptyArray = (yyvsp[(2) - (3)].CompilerInfo).data.emptyArray;                                                            (yyval.CompilerInfo).data.emptyArray = (yyvsp[(2) - (3)].CompilerInfo).data.pointerLevel;
                                                             memset((yyval.CompilerInfo).data.identifier,sizeof((yyval.CompilerInfo).data.identifier),0);
                                                             strcpy((yyval.CompilerInfo).data.identifier, (yyvsp[(2) - (3)].CompilerInfo).data.identifier);
                                                             printCompilerInfoNode("declaration_specifiers init_declarator_list SEMI_OP REDUCE to declaration",&(yyval.CompilerInfo));
                                                            }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 274 "c.y"
    {printCompilerInfoNode("storage_class_specifier REDUCE to declaration_specifiers",NULL);}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 275 "c.y"
    {
                                                      (yyval.CompilerInfo).data.sign = (yyvsp[(2) - (2)].CompilerInfo).data.sign;
                                                      (yyval.CompilerInfo).data.type = (yyvsp[(2) - (2)].CompilerInfo).data.type;
                                                      (yyval.CompilerInfo).data.storage = (yyvsp[(1) - (2)].CompilerInfo).data.storage;
                                                      (yyval.CompilerInfo).data.pointerLevel = (yyvsp[(2) - (2)].CompilerInfo).data.pointerLevel;
                                                      (yyval.CompilerInfo).data.emptyArray = (yyvsp[(2) - (2)].CompilerInfo).data.emptyArray;
                                                      printCompilerInfoNode("storage_class_specifier declaration_specifiers REDUCE to declaration_specifiers",&(yyval.CompilerInfo));
                                                     }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 283 "c.y"
    {
                                                       (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                                                       (yyval.CompilerInfo).data.sign = (yyvsp[(1) - (1)].CompilerInfo).data.sign;
                                                       (yyval.CompilerInfo).data.type = (yyvsp[(1) - (1)].CompilerInfo).data.type;
                                                       (yyval.CompilerInfo).data.storage = (yyvsp[(1) - (1)].CompilerInfo).data.storage;
                                                       (yyval.CompilerInfo).data.pointerLevel = (yyvsp[(1) - (1)].CompilerInfo).data.pointerLevel;
                                                       (yyval.CompilerInfo).data.emptyArray = (yyvsp[(1) - (1)].CompilerInfo).data.emptyArray;
                                                       printCompilerInfoNode("type_specifier REDUCE to declaration_specifiers",&(yyval.CompilerInfo));
                                                     }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 292 "c.y"
    {
                                                       (yyval.CompilerInfo).data.sign = (yyvsp[(1) - (2)].CompilerInfo).data.sign;
                                                       (yyval.CompilerInfo).data.type = (yyvsp[(2) - (2)].CompilerInfo).data.type;
                                                       printCompilerInfoNode("type_specifier declaration_specifiers REDUCE to declaration_specifiers",&(yyval.CompilerInfo));
                                                     }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 297 "c.y"
    {printCompilerInfoNode("type_qualifier REDUCE to declaration_specifiers",NULL);}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 298 "c.y"
    {printCompilerInfoNode("type_qualifier declaration_specifiers SEMI_OP REDUCE to declaration_specifiers",NULL);}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 299 "c.y"
    {printCompilerInfoNode("function_specifier REDUCE to declaration_specifiers",NULL);}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 300 "c.y"
    {printCompilerInfoNode("function_specifier declaration_specifiers REDUCE to declaration_specifiers",NULL);}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 304 "c.y"
    {
                                                     (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                                                     printCompilerInfoNode("init_declarator REDUCE to init_declarator_list",&(yyval.CompilerInfo));
                                                    }
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 308 "c.y"
    {
                                                     (yyval.CompilerInfo) = (yyvsp[(3) - (3)].CompilerInfo);
                                                     printCompilerInfoNode("init_declarator_list COMMA_OP init_declarator REDUCE to init_declarator_list",&(yyval.CompilerInfo));
                                                     //addToSymbolTable($<CompilerInfo>3.identifier, $<CompilerInfo>3.type, $<CompilerInfo>3.sign, $<CompilerInfo>3.storage, $<CompilerInfo>3.declarationType, $<CompilerInfo>3.constant, $<CompilerInfo>3.arrayExpression);
                                                    }
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 316 "c.y"
    {
                                       (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                                       printCompilerInfoNode("declarator REDUCE to init_declarator",&(yyval.CompilerInfo));
                                      }
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 320 "c.y"
    {printCompilerInfoNode("declarator EQUAL_OP initializer REDUCE to init_declarator",NULL);}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 324 "c.y"
    {(yyval.CompilerInfo).data.storage = STORAGE_NONE;     printCompilerInfoNode("TYPEDEF REDUCE to storage_class_specifier",NULL);}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 325 "c.y"
    {(yyval.CompilerInfo).data.storage = STORAGE_EXTERN;   printCompilerInfoNode("EXTERN REDUCE to storage_class_specifier",NULL);}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 326 "c.y"
    {(yyval.CompilerInfo).data.storage = STORAGE_STATIC;   printCompilerInfoNode("STATIC REDUCE to storage_class_specifier",NULL);}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 327 "c.y"
    {(yyval.CompilerInfo).data.storage = STORAGE_AUTO;     printCompilerInfoNode("AUTO REDUCE to storage_class_specifier",NULL);}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 328 "c.y"
    {(yyval.CompilerInfo).data.storage = STORAGE_REGISTER; printCompilerInfoNode("REGISTER REDUCE to storage_class_specifier",NULL);}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 332 "c.y"
    {(yyval.CompilerInfo).data.type = TYPE_VOID;      printCompilerInfoNode("TYPE_VOID REDUCE to type_specifier",NULL); }
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 333 "c.y"
    {(yyval.CompilerInfo).data.type = TYPE_CHARACTER; printCompilerInfoNode("TYPE_CHARACTER REDUCE to type_specifier",NULL); }
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 334 "c.y"
    {(yyval.CompilerInfo).data.type = TYPE_SHORT;     printCompilerInfoNode("TYPE_SHORT REDUCE to type_specifier",NULL); }
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 335 "c.y"
    {(yyval.CompilerInfo).data.type = TYPE_INTEGER;   printCompilerInfoNode("TYPE_INTEGER REDUCE to type_specifier",NULL); }
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 336 "c.y"
    {(yyval.CompilerInfo).data.type = TYPE_LONG;      printCompilerInfoNode("TYPE_LONG REDUCE to type_specifier",NULL); }
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 337 "c.y"
    {(yyval.CompilerInfo).data.type = TYPE_LONG64;    printCompilerInfoNode("TYPE_LONG64 REDUCE to type_specifier",NULL); }
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 338 "c.y"
    {(yyval.CompilerInfo).data.type = TYPE_FLOAT;     printCompilerInfoNode("TYPE_FLOAT REDUCE to type_specifier",NULL); }
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 339 "c.y"
    {(yyval.CompilerInfo).data.type = TYPE_DOUBLE;    printCompilerInfoNode("TYPE_DOUBLE REDUCE to type_specifier",NULL); }
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 340 "c.y"
    {(yyval.CompilerInfo).data.type = TYPE_LONGDOUBLE;printCompilerInfoNode("TYPE_LONGDOUBLE REDUCE to type_specifier",NULL); }
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 341 "c.y"
    {(yyval.CompilerInfo).data.sign = TYPE_SIGNED;    printCompilerInfoNode("TYPE_SIGNED REDUCE to type_specifier",NULL); }
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 342 "c.y"
    {(yyval.CompilerInfo).data.sign = TYPE_UNSIGNED;  printCompilerInfoNode("TYPE_UNSIGNED REDUCE to type_specifier",NULL); }
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 343 "c.y"
    {(yyval.CompilerInfo).data.type = TYPE_BOOLEAN;   printCompilerInfoNode("TYPE_BOOLEAN REDUCE to type_specifier",NULL); }
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 344 "c.y"
    {(yyval.CompilerInfo).data.type = TYPE_COMPLEX;   printCompilerInfoNode("TYPE_COMPLEX REDUCE to type_specifier",NULL); }
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 345 "c.y"
    {(yyval.CompilerInfo).data.type = TYPE_IMAGINARY; printCompilerInfoNode("TYPE_IMAGINARY REDUCE to type_specifier",NULL); }
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 346 "c.y"
    {printCompilerInfoNode("struct_or_union_specifier REDUCE to type_specifier",NULL);}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 347 "c.y"
    {printCompilerInfoNode("enum_specifier REDUCE to type_specifier",NULL);}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 348 "c.y"
    {printCompilerInfoNode("type_specifier TYPE_NAME REDUCE to type_specifier",NULL);}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 352 "c.y"
    {printCompilerInfoNode("struct_or_union IDENTIFIER OCURLY_OP struct_declaration_list CCURLY_OP REDUCE to struct_or_union_specifier",NULL);}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 353 "c.y"
    {printCompilerInfoNode("struct_or_union OCURLY_OP struct_declaration_list CCURLY_OP REDUCE to struct_or_union_specifier",NULL);}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 354 "c.y"
    {printCompilerInfoNode("struct_or_union IDENTIFIER REDUCE to struct_or_union_specifier",NULL);}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 358 "c.y"
    {printCompilerInfoNode("STRUCT REDUCE to struct_or_union",NULL);}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 359 "c.y"
    {printCompilerInfoNode("UNION REDUCE to struct_or_union",NULL);}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 363 "c.y"
    {printCompilerInfoNode("struct_declaration REDUCE to struct_declaration_list",NULL);}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 364 "c.y"
    {printCompilerInfoNode("struct_declaration_list struct_declaration REDUCE to struct_declaration_list",NULL);}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 368 "c.y"
    {printCompilerInfoNode("specifier_qualifier_list struct_declarator_list SEMI_OP REDUCE to struct_declaration",NULL);}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 372 "c.y"
    {printCompilerInfoNode("type_specifier specifier_qualifier_list REDUCE to specifier_qualifier_list",NULL);}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 373 "c.y"
    {printCompilerInfoNode("type_specifier REDUCE to specifier_qualifier_list",NULL);}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 374 "c.y"
    {printCompilerInfoNode("type_qualifier specifier_qualifier_list REDUCE to specifier_qualifier_list",NULL);}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 375 "c.y"
    {printCompilerInfoNode("type_qualifier REDUCE to specifier_qualifier_list",NULL);}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 379 "c.y"
    {printCompilerInfoNode("struct_declarator REDUCE to struct_declarator_list",NULL);}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 380 "c.y"
    {printCompilerInfoNode("struct_declarator_list COMMA_OP struct_declarator REDUCE to struct_declarator_list",NULL);}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 384 "c.y"
    {printCompilerInfoNode("declarator REDUCE to struct_declarator",NULL);}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 385 "c.y"
    {printCompilerInfoNode("COLON_OP constant_expression REDUCE to struct_declarator",NULL);}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 386 "c.y"
    {printCompilerInfoNode("declarator COLON_OP constant_expression REDUCE to struct_declarator",NULL);}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 390 "c.y"
    {printCompilerInfoNode("ENUM OCURLY_OP enumerator_list CCURLY_OP REDUCE to enum_specifier",NULL);}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 391 "c.y"
    {printCompilerInfoNode("ENUM IDENTIFIER OCURLY_OP enumerator_list CCURLY_OP REDUCE to enum_specifier",NULL);}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 392 "c.y"
    {printCompilerInfoNode("ENUM OCURLY_OP enumerator_list COMMA_OP CCURLY_OP REDUCE to enum_specifier",NULL);}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 393 "c.y"
    {printCompilerInfoNode("ENUM IDENTIFIER OCURLY_OP enumerator_list COMMA_OP CCURLY_OP REDUCE to enum_specifier",NULL);}
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 394 "c.y"
    {printCompilerInfoNode("ENUM IDENTIFIER REDUCE to enum_specifier",NULL);}
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 398 "c.y"
    {printCompilerInfoNode("enumerator REDUCE to enumerator_list",NULL);}
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 399 "c.y"
    {printCompilerInfoNode("enumerator_list COMMA_OP enumerator REDUCE to enumerator_list",NULL);}
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 403 "c.y"
    {printCompilerInfoNode("IDENTIFIER REDUCE to enumerator",NULL);}
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 404 "c.y"
    {printCompilerInfoNode("IDENTIFIER EQUAL_OP constant_expression REDUCE to enumerator",NULL);}
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 408 "c.y"
    {printCompilerInfoNode("CONST REDUCE to type_qualifier",NULL);}
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 409 "c.y"
    {printCompilerInfoNode("RESTRICT REDUCE to type_qualifier",NULL);}
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 410 "c.y"
    {printCompilerInfoNode("VOLATILE REDUCE to type_qualifier",NULL);}
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 414 "c.y"
    {printCompilerInfoNode("INLINE REDUCE to function_specifier",NULL);}
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 418 "c.y"
    {
                                  (yyval.CompilerInfo) = (yyvsp[(2) - (2)].CompilerInfo);
                                  (yyval.CompilerInfo).data.pointerLevel = (yyvsp[(1) - (2)].CompilerInfo).data.pointerLevel;
                                  printCompilerInfoNode("pointer direct_declarator REDUCE to declarator",&(yyval.CompilerInfo));
                                 }
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 423 "c.y"
    {
                                  (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                                  printCompilerInfoNode("direct_declarator REDUCE to declarator",&(yyval.CompilerInfo));                                      
                                 }
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 431 "c.y"
    {
                                                                                                       (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                                                                                                       printCompilerInfoNode("IDENTIFIER REDUCE to direct_declarator",&(yyval.CompilerInfo));
                                                                                                      }
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 435 "c.y"
    {printCompilerInfoNode("OPENPAREN_OP declarator CLOSEPAREN_OP REDUCE to direct_declarator",NULL);}
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 436 "c.y"
    {printCompilerInfoNode("direct_declarator OPENBRACE_OP type_qualifier_list assignment_expression CLOSEBRACE_OP REDUCE to direct_declarator",NULL);}
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 437 "c.y"
    {printCompilerInfoNode("direct_declarator OPENBRACE_OP type_qualifier_list CLOSEBRACE_OP REDUCE to direct_declarator",NULL);}
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 438 "c.y"
    {
                                                                                                       (yyval.CompilerInfo) = (yyvsp[(1) - (4)].CompilerInfo);
                                                                                                       addToExpression(&(yyval.CompilerInfo).arrayExpression,(yyvsp[(1) - (4)].CompilerInfo).data.identifier,(yyvsp[(1) - (4)].CompilerInfo).data.type,(yyvsp[(1) - (4)].CompilerInfo).data.sign,FALSE);
                                                                                                       printCompilerInfoNode("<EXP> direct_declarator OPENBRACE_OP assignment_expression CLOSEBRACE_OP REDUCE to direct_declarator",NULL);
                                                                                                      }
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 443 "c.y"
    {printCompilerInfoNode("direct_declarator OPENBRACE_OP STATIC type_qualifier_list assignment_expression CLOSEBRACE_OP REDUCE to direct_declarator",NULL);}
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 444 "c.y"
    {printCompilerInfoNode("direct_declarator OPENBRACE_OP type_qualifier_list STATIC assignment_expression CLOSEBRACE_OP REDUCE to direct_declarator",NULL);}
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 445 "c.y"
    {printCompilerInfoNode("direct_declarator OPENBRACE_OP type_qualifier_list TIMES_OP CLOSEBRACE_OP REDUCE to direct_declarator",NULL);}
    break;

  case 154:
/* Line 1792 of yacc.c  */
#line 446 "c.y"
    {printCompilerInfoNode("direct_declarator OPENBRACE_OP TIMES_OP CLOSEBRACE_OP REDUCE to direct_declarator",NULL);}
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 447 "c.y"
    {
                                                                                                       (yyval.CompilerInfo) = (yyvsp[(1) - (3)].CompilerInfo);
                                                                                                       (yyval.CompilerInfo).data.emptyArray = TRUE;
                                                                                                       //addToExpression2(&$<CompilerInfo>$.arrayExpression,"",0,0,FALSE);
                                                                                                       printCompilerInfoNode("direct_declarator OPENBRACE_OP CLOSEBRACE_OP REDUCE to direct_declarator",&(yyval.CompilerInfo));
                                                                                                      }
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 453 "c.y"
    {
                                                                                                       (yyval.CompilerInfo) = (yyvsp[(1) - (4)].CompilerInfo);
                                                                                                       (yyval.CompilerInfo).parameterList = (yyvsp[(3) - (4)].ParameterList);                                                                                                     
                                                                                                       printCompilerInfoNode("direct_declarator OPENPAREN_OP parameter_type_list CLOSEPAREN_OP REDUCE to direct_declarator", &(yyval.CompilerInfo));
                                                                                                      }
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 458 "c.y"
    {printCompilerInfoNode("direct_declarator OPENPAREN_OP identifier_list CLOSEPAREN_OP REDUCE to direct_declarator",NULL);}
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 459 "c.y"
    {
                                                                                                       (yyval.CompilerInfo) = (yyvsp[(1) - (3)].CompilerInfo);
                                                                                                       printCompilerInfoNode("direct_declarator OPENPAREN_OP CLOSEPAREN_OP REDUCE to direct_declarator",&(yyval.CompilerInfo));
                                                                                                      }
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 466 "c.y"
    {(yyval.CompilerInfo).data.pointerLevel++; printCompilerInfoNode("TIMES_OP REDUCE to pointer",&(yyval.CompilerInfo));}
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 467 "c.y"
    {printCompilerInfoNode("TIMES_OP type_qualifier_list REDUCE to pointer",NULL);}
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 468 "c.y"
    {
                                            (yyval.CompilerInfo).data.pointerLevel = (yyvsp[(2) - (2)].CompilerInfo).data.pointerLevel; 
                                            (yyval.CompilerInfo).data.pointerLevel++; 
                                            printCompilerInfoNode("TIMES_OP pointer REDUCE to pointer",&(yyval.CompilerInfo));
                                           }
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 473 "c.y"
    {printCompilerInfoNode("TIMES_OP type_qualifier_list pointer REDUCE to pointer",NULL);}
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 477 "c.y"
    {printCompilerInfoNode("type_qualifier REDUCE to type_qualifier_list",NULL);}
    break;

  case 164:
/* Line 1792 of yacc.c  */
#line 478 "c.y"
    {printCompilerInfoNode("type_qualifier_list type_qualifier REDUCE to type_qualifier_list",NULL);}
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 483 "c.y"
    {
                                        (yyval.CompilerInfo).parameterList = (yyvsp[(1) - (1)].ParameterList);
                                        printCompilerInfoNode("<EXP> parameter_list REDUCE to parameter_type_list",&(yyval.CompilerInfo));
                                       }
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 487 "c.y"
    {
                                        (yyval.CompilerInfo).parameterList = (yyvsp[(1) - (3)].ParameterList);
                                        printCompilerInfoNode("<EXP> parameter_list COMMA_OP ELLIPSIS REDUCE to parameter_type_list",&(yyval.CompilerInfo));
                                       }
    break;

  case 167:
/* Line 1792 of yacc.c  */
#line 494 "c.y"
    {
                                                     (yyval.ParameterList) = createParameterListNode(&(yyvsp[(1) - (1)].CompilerInfo));
                                                     printParameterListNode("parameter_declaration REDUCE to parameter_list",(yyval.ParameterList));
                                                    }
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 498 "c.y"
    {
                                                     addToParameterList2(&(yyvsp[(1) - (3)].ParameterList), &(yyvsp[(3) - (3)].CompilerInfo));
                                                     (yyval.ParameterList) = (yyvsp[(1) - (3)].ParameterList);
                                                     printParameterListNode("parameter_list COMMA_OP parameter_declaration REDUCE to parameter_list",(yyval.ParameterList));
                                                    }
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 506 "c.y"
    {
                                                  (yyval.CompilerInfo) = (yyvsp[(2) - (2)].CompilerInfo);
                                                  (yyval.CompilerInfo).data.sign = (yyvsp[(1) - (2)].CompilerInfo).data.sign;
                                                  (yyval.CompilerInfo).data.type = (yyvsp[(1) - (2)].CompilerInfo).data.type;
                                                  (yyval.CompilerInfo).data.storage = (yyvsp[(1) - (2)].CompilerInfo).data.storage;
                                                  (yyval.CompilerInfo).parameterList = (yyvsp[(1) - (2)].CompilerInfo).parameterList;
                                                  printCompilerInfoNode("declaration_specifiers declarator REDUCE to parameter_declaration",&(yyval.CompilerInfo));
                                                 }
    break;

  case 170:
/* Line 1792 of yacc.c  */
#line 514 "c.y"
    {printCompilerInfoNode("declaration_specifiers abstract_declarator REDUCE to parameter_declaration",NULL);}
    break;

  case 171:
/* Line 1792 of yacc.c  */
#line 515 "c.y"
    {printCompilerInfoNode("declaration_specifiers REDUCE to parameter_declaration",NULL);}
    break;

  case 172:
/* Line 1792 of yacc.c  */
#line 519 "c.y"
    {printCompilerInfoNode("IDENTIFIER REDUCE to identifier_list",NULL);}
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 520 "c.y"
    {printCompilerInfoNode("identifier_list COMMA_OP IDENTIFIER REDUCE to identifier_list",NULL);}
    break;

  case 174:
/* Line 1792 of yacc.c  */
#line 524 "c.y"
    {printCompilerInfoNode("specifier_qualifier_list REDUCE to type_name",NULL);}
    break;

  case 175:
/* Line 1792 of yacc.c  */
#line 525 "c.y"
    {printCompilerInfoNode("specifier_qualifier_list abstract_declarator REDUCE to type_name",NULL);}
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 529 "c.y"
    {printCompilerInfoNode("pointer REDUCE to abstract_declarator",NULL);}
    break;

  case 177:
/* Line 1792 of yacc.c  */
#line 530 "c.y"
    {printCompilerInfoNode("direct_abstract_declarator REDUCE to abstract_declarator",NULL);}
    break;

  case 178:
/* Line 1792 of yacc.c  */
#line 531 "c.y"
    {printCompilerInfoNode("pointer direct_abstract_declarator REDUCE to abstract_declarator",NULL);}
    break;

  case 179:
/* Line 1792 of yacc.c  */
#line 535 "c.y"
    {printCompilerInfoNode("OPENPAREN_OP abstract_declarator CLOSEPAREN_OP REDUCE to direct_abstract_declarator",NULL);}
    break;

  case 180:
/* Line 1792 of yacc.c  */
#line 536 "c.y"
    {printCompilerInfoNode("OPENBRACE_OP CLOSEBRACE_OP REDUCE to direct_abstract_declarator",NULL);}
    break;

  case 181:
/* Line 1792 of yacc.c  */
#line 537 "c.y"
    {printCompilerInfoNode("OPENBRACE_OP assignment_expression CLOSEBRACE_OP REDUCE to direct_abstract_declarator",NULL);}
    break;

  case 182:
/* Line 1792 of yacc.c  */
#line 538 "c.y"
    {printCompilerInfoNode("direct_abstract_declarator OPENBRACE_OP CLOSEBRACE_OP REDUCE to direct_abstract_declarator",NULL);}
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 539 "c.y"
    {printCompilerInfoNode("direct_abstract_declarator OPENBRACE_OP assignment_expression CLOSEBRACE_OP REDUCE to direct_abstract_declarator",NULL);}
    break;

  case 184:
/* Line 1792 of yacc.c  */
#line 540 "c.y"
    {printCompilerInfoNode("OPENBRACE_OP TIMES_OP CLOSEBRACE_OP REDUCE to direct_abstract_declarator",NULL);}
    break;

  case 185:
/* Line 1792 of yacc.c  */
#line 541 "c.y"
    {printCompilerInfoNode("direct_abstract_declarator OPENBRACE_OP TIMES_OP CLOSEBRACE_OP REDUCE to direct_abstract_declarator",NULL);}
    break;

  case 186:
/* Line 1792 of yacc.c  */
#line 542 "c.y"
    {printCompilerInfoNode("OPENPAREN_OP CLOSEPAREN_OP REDUCE to direct_abstract_declarator",NULL);}
    break;

  case 187:
/* Line 1792 of yacc.c  */
#line 543 "c.y"
    {printCompilerInfoNode("OPENPAREN_OP parameter_type_list CLOSEPAREN_OP REDUCE to direct_abstract_declarator",NULL);}
    break;

  case 188:
/* Line 1792 of yacc.c  */
#line 544 "c.y"
    {printCompilerInfoNode("direct_abstract_declarator OPENPAREN_OP CLOSEPAREN_OP REDUCE to direct_abstract_declarator",NULL);}
    break;

  case 189:
/* Line 1792 of yacc.c  */
#line 545 "c.y"
    {printCompilerInfoNode("direct_abstract_declarator OPENPAREN_OP parameter_type_list CLOSEPAREN_OP REDUCE to direct_abstract_declarator",NULL);}
    break;

  case 190:
/* Line 1792 of yacc.c  */
#line 549 "c.y"
    {printCompilerInfoNode("assignment_expression REDUCE to initializer",NULL);}
    break;

  case 191:
/* Line 1792 of yacc.c  */
#line 550 "c.y"
    {printCompilerInfoNode("OCURLY_OP initializer_list CCURLY_OP REDUCE to initializer",NULL);}
    break;

  case 192:
/* Line 1792 of yacc.c  */
#line 551 "c.y"
    {printCompilerInfoNode("OCURLY_OP initializer_list COMMA_OP CCURLY_OP REDUCE to initializer",NULL);}
    break;

  case 193:
/* Line 1792 of yacc.c  */
#line 555 "c.y"
    {printCompilerInfoNode("initializer REDUCE to initializer_list",NULL);}
    break;

  case 194:
/* Line 1792 of yacc.c  */
#line 556 "c.y"
    {printCompilerInfoNode("designation initializer REDUCE to initializer_list",NULL);}
    break;

  case 195:
/* Line 1792 of yacc.c  */
#line 557 "c.y"
    {printCompilerInfoNode("initializer_list COMMA_OP initializer REDUCE to initializer_list",NULL);}
    break;

  case 196:
/* Line 1792 of yacc.c  */
#line 558 "c.y"
    {printCompilerInfoNode("initializer_list COMMA_OP designation initializer REDUCE to initializer_list",NULL);}
    break;

  case 197:
/* Line 1792 of yacc.c  */
#line 562 "c.y"
    {printCompilerInfoNode("designator_list EQUAL_OP REDUCE to designation",NULL);}
    break;

  case 198:
/* Line 1792 of yacc.c  */
#line 566 "c.y"
    {printCompilerInfoNode("designator REDUCE to designator_list",NULL);}
    break;

  case 199:
/* Line 1792 of yacc.c  */
#line 567 "c.y"
    {printCompilerInfoNode("designator_list designator EQUAL_OP REDUCE to designator_list",NULL);}
    break;

  case 200:
/* Line 1792 of yacc.c  */
#line 571 "c.y"
    {printCompilerInfoNode("labeled_statement REDUCE to statement",NULL);}
    break;

  case 201:
/* Line 1792 of yacc.c  */
#line 572 "c.y"
    {printCompilerInfoNode("labeled_statement REDUCE to statement",NULL);}
    break;

  case 202:
/* Line 1792 of yacc.c  */
#line 576 "c.y"
    {printCompilerInfoNode("labeled_statement REDUCE to statement",NULL);}
    break;

  case 203:
/* Line 1792 of yacc.c  */
#line 577 "c.y"
    {printCompilerInfoNode("compound_statement REDUCE to statement",NULL);}
    break;

  case 204:
/* Line 1792 of yacc.c  */
#line 578 "c.y"
    {printCompilerInfoNode("expression_statement REDUCE to statement",NULL);}
    break;

  case 205:
/* Line 1792 of yacc.c  */
#line 579 "c.y"
    {printCompilerInfoNode("selection_statement REDUCE to statement",NULL);}
    break;

  case 206:
/* Line 1792 of yacc.c  */
#line 580 "c.y"
    {printCompilerInfoNode("iteration_statement REDUCE to statement",NULL);}
    break;

  case 207:
/* Line 1792 of yacc.c  */
#line 581 "c.y"
    {
                             (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                             printCompilerInfoNode("<EXP> jump_statement REDUCE to statement",NULL);
                            }
    break;

  case 208:
/* Line 1792 of yacc.c  */
#line 588 "c.y"
    {printCompilerInfoNode("IDENTIFIER COLON_OP statement REDUCE to labeled_statement",NULL);}
    break;

  case 209:
/* Line 1792 of yacc.c  */
#line 589 "c.y"
    {printCompilerInfoNode("CASE constant_expression COLON_OP statement REDUCE to labeled_statement",NULL);}
    break;

  case 210:
/* Line 1792 of yacc.c  */
#line 590 "c.y"
    {printCompilerInfoNode("DEFAULT COLON_OP statement REDUCE to labeled_statement",NULL);}
    break;

  case 211:
/* Line 1792 of yacc.c  */
#line 594 "c.y"
    {printCompilerInfoNode("OCURLY_OP CCURLY_OP REDUCE to compound_statement",NULL);}
    break;

  case 212:
/* Line 1792 of yacc.c  */
#line 595 "c.y"
    {
                                           (yyval.CompilerInfo) = (yyvsp[(2) - (3)].CompilerInfo);
                                           printCompilerInfoNode("<EXP> OCURLY_OP block_item_list CCURLY_OP REDUCE to compound_statement",NULL);
                                          }
    break;

  case 213:
/* Line 1792 of yacc.c  */
#line 602 "c.y"
    {
                                  (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                                  printCompilerInfoNode("<EXP> block_item REDUCE to block_item_list",NULL);
                                 }
    break;

  case 214:
/* Line 1792 of yacc.c  */
#line 606 "c.y"
    {printCompilerInfoNode("block_item_list block_item REDUCE to block_item_list",NULL);}
    break;

  case 215:
/* Line 1792 of yacc.c  */
#line 610 "c.y"
    {printCompilerInfoNode("declaration REDUCE to block_item",NULL);}
    break;

  case 216:
/* Line 1792 of yacc.c  */
#line 611 "c.y"
    {
                    (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                    printCompilerInfoNode("<EXP> statement REDUCE to block_item",NULL);
                   }
    break;

  case 217:
/* Line 1792 of yacc.c  */
#line 618 "c.y"
    {printCompilerInfoNode("SEMI_OP REDUCE to expression_statement",NULL);}
    break;

  case 218:
/* Line 1792 of yacc.c  */
#line 619 "c.y"
    {printCompilerInfoNode("expression SEMI_OP REDUCE to expression_statement",NULL);}
    break;

  case 219:
/* Line 1792 of yacc.c  */
#line 623 "c.y"
    {printCompilerInfoNode("IF OPENPAREN_OP expression CLOSEPAREN_OP statement REDUCE to selection_statement",NULL);}
    break;

  case 220:
/* Line 1792 of yacc.c  */
#line 624 "c.y"
    {printCompilerInfoNode("IF OPENPAREN_OP expression CLOSEPAREN_OP statement ELSE statement REDUCE to selection_statement",NULL);}
    break;

  case 221:
/* Line 1792 of yacc.c  */
#line 625 "c.y"
    {printCompilerInfoNode("SWITCH OPENPAREN_OP expression CLOSEPAREN_OP statement REDUCE to selection_statement",NULL);}
    break;

  case 222:
/* Line 1792 of yacc.c  */
#line 629 "c.y"
    {printCompilerInfoNode("WHILE OPENPAREN_OP expression CLOSEPAREN_OP statement REDUCE to iteration_statement",NULL);}
    break;

  case 223:
/* Line 1792 of yacc.c  */
#line 630 "c.y"
    {printCompilerInfoNode("DO statement WHILE OPENPAREN_OP expression CLOSEPAREN_OP SEMI_OP REDUCE to iteration_statement",NULL);}
    break;

  case 224:
/* Line 1792 of yacc.c  */
#line 631 "c.y"
    {printCompilerInfoNode("FOR OPENPAREN_OP expression_statement expression_statement CLOSEPAREN_OP statement REDUCE to iteration_statement",NULL);}
    break;

  case 225:
/* Line 1792 of yacc.c  */
#line 632 "c.y"
    {printCompilerInfoNode("FOR OPENPAREN_OP expression_statement expression_statement expression CLOSEPAREN_OP statement REDUCE to iteration_statement",NULL);}
    break;

  case 226:
/* Line 1792 of yacc.c  */
#line 633 "c.y"
    {printCompilerInfoNode("FOR OPENPAREN_OP declaration expression_statement CLOSEPAREN_OP statement REDUCE to iteration_statement",NULL);}
    break;

  case 227:
/* Line 1792 of yacc.c  */
#line 634 "c.y"
    {printCompilerInfoNode("FOR OPENPAREN_OP declaration expression_statement expression CLOSEPAREN_OP statement REDUCE to iteration_statement",NULL);}
    break;

  case 228:
/* Line 1792 of yacc.c  */
#line 638 "c.y"
    {printCompilerInfoNode("GOTO IDENTIFIER SEMI_OP REDUCE to jump_statement",NULL);}
    break;

  case 229:
/* Line 1792 of yacc.c  */
#line 639 "c.y"
    {printCompilerInfoNode("CONTINUE SEMI_OP REDUCE to jump_statement",NULL);}
    break;

  case 230:
/* Line 1792 of yacc.c  */
#line 640 "c.y"
    {printCompilerInfoNode("BREAK SEMI_OP REDUCE to jump_statement",NULL);}
    break;

  case 231:
/* Line 1792 of yacc.c  */
#line 641 "c.y"
    {printCompilerInfoNode("RETURN SEMI_OP REDUCE to jump_statement",NULL);}
    break;

  case 232:
/* Line 1792 of yacc.c  */
#line 642 "c.y"
    {
                                 (yyval.CompilerInfo) = (yyvsp[(2) - (3)].CompilerInfo);
                                 printCompilerInfoNode("<EXP> RETURN expression SEMI_OP REDUCE to jump_statement",NULL);
                                }
    break;

  case 233:
/* Line 1792 of yacc.c  */
#line 649 "c.y"
    {
                                             (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                                             addToSymbolTable((yyvsp[(1) - (1)].CompilerInfo).data.pointerLevel,(yyvsp[(1) - (1)].CompilerInfo).data.identifier, (yyvsp[(1) - (1)].CompilerInfo).data.type, (yyvsp[(1) - (1)].CompilerInfo).data.sign, (yyvsp[(1) - (1)].CompilerInfo).data.storage, (yyvsp[(1) - (1)].CompilerInfo).data.declarationType, (yyvsp[(1) - (1)].CompilerInfo).data.constant, (yyvsp[(1) - (1)].CompilerInfo).data.emptyArray, (yyvsp[(1) - (1)].CompilerInfo).arrayExpression);
                                             addToFunctionTable((yyvsp[(1) - (1)].CompilerInfo).data.identifier, (yyvsp[(1) - (1)].CompilerInfo).data.type, (yyvsp[(1) - (1)].CompilerInfo).data.sign, (yyvsp[(1) - (1)].CompilerInfo).data.storage, (yyvsp[(1) - (1)].CompilerInfo).data.declarationType, (yyvsp[(1) - (1)].CompilerInfo).data.constant, (yyvsp[(1) - (1)].CompilerInfo).arrayExpression,(yyvsp[(1) - (1)].CompilerInfo).parameterList);
                                             printCompilerInfoNode("external_declaration REDUCE to translation_unit",&(yyval.CompilerInfo));
                                            }
    break;

  case 234:
/* Line 1792 of yacc.c  */
#line 655 "c.y"
    {
                                             (yyval.CompilerInfo) = (yyvsp[(2) - (2)].CompilerInfo);
                                             addToSymbolTable((yyvsp[(2) - (2)].CompilerInfo).data.pointerLevel,(yyvsp[(2) - (2)].CompilerInfo).data.identifier, (yyvsp[(2) - (2)].CompilerInfo).data.type, (yyvsp[(2) - (2)].CompilerInfo).data.sign, (yyvsp[(2) - (2)].CompilerInfo).data.storage, (yyvsp[(2) - (2)].CompilerInfo).data.declarationType, (yyvsp[(2) - (2)].CompilerInfo).data.constant, (yyvsp[(2) - (2)].CompilerInfo).data.emptyArray, (yyvsp[(2) - (2)].CompilerInfo).arrayExpression);
                                             addToFunctionTable((yyvsp[(2) - (2)].CompilerInfo).data.identifier, (yyvsp[(2) - (2)].CompilerInfo).data.type, (yyvsp[(2) - (2)].CompilerInfo).data.sign, (yyvsp[(2) - (2)].CompilerInfo).data.storage, (yyvsp[(2) - (2)].CompilerInfo).data.declarationType, (yyvsp[(1) - (2)].CompilerInfo).data.constant, (yyvsp[(1) - (2)].CompilerInfo).arrayExpression,(yyvsp[(2) - (2)].CompilerInfo).parameterList);
                                             printCompilerInfoNode("translation_unit external_declaration REDUCE to translation_unit",&(yyval.CompilerInfo));
                                            }
    break;

  case 235:
/* Line 1792 of yacc.c  */
#line 664 "c.y"
    {
                           (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                           (yyval.CompilerInfo).data.declarationType = DECLARATION_FUNCTION;
                           (yyval.CompilerInfo).data.sign = (yyvsp[(1) - (1)].CompilerInfo).data.sign;
                           (yyval.CompilerInfo).data.type = (yyvsp[(1) - (1)].CompilerInfo).data.type;
                           (yyval.CompilerInfo).data.storage = (yyvsp[(1) - (1)].CompilerInfo).data.storage;
                           (yyval.CompilerInfo).parameterList = (yyvsp[(1) - (1)].CompilerInfo).parameterList;
                           //addToFunctionTable($<CompilerInfo>$.data.identifier, $<CompilerInfo>$.data.type, $<CompilerInfo>$.data.sign, $<CompilerInfo>$.data.storage, $<CompilerInfo>$.data.declarationType, $<CompilerInfo>$.data.constant, $<CompilerInfo>$.arrayExpression,$<CompilerInfo>$.parameterList);
                           printCompilerInfoNode("function_definition REDUCE to external_declaration",&(yyval.CompilerInfo));
                          }
    break;

  case 236:
/* Line 1792 of yacc.c  */
#line 674 "c.y"
    {
                           (yyval.CompilerInfo) = (yyvsp[(1) - (1)].CompilerInfo);
                           (yyval.CompilerInfo).data.declarationType = DECLARATION_VARIABLE;
                           (yyval.CompilerInfo).data.sign = (yyvsp[(1) - (1)].CompilerInfo).data.sign;
                           (yyval.CompilerInfo).data.type = (yyvsp[(1) - (1)].CompilerInfo).data.type;
                           (yyval.CompilerInfo).data.storage = (yyvsp[(1) - (1)].CompilerInfo).data.storage;
                           (yyval.CompilerInfo).data.pointerLevel = (yyvsp[(1) - (1)].CompilerInfo).data.pointerLevel;
                           memset((yyval.CompilerInfo).data.identifier,sizeof((yyval.CompilerInfo).data.identifier),0);
                           strcpy((yyval.CompilerInfo).data.identifier,(yyvsp[(1) - (1)].CompilerInfo).data.identifier);
                           //addToSymbolTable($<CompilerInfo>$.data.identifier, $<CompilerInfo>$.data.type, $<CompilerInfo>$.data.sign, $<CompilerInfo>$.data.storage, $<CompilerInfo>$.data.declarationType, $<CompilerInfo>$.data.constant, $<CompilerInfo>$.arrayExpression,$<CompilerInfo>$.parameterList);
                           printCompilerInfoNode("declaration REDUCE to external_declaration",&(yyval.CompilerInfo));
                          }
    break;

  case 237:
/* Line 1792 of yacc.c  */
#line 689 "c.y"
    {printCompilerInfoNode("declaration_specifiers declarator declaration_list compound_statement REDUCE to function_definition",NULL);}
    break;

  case 238:
/* Line 1792 of yacc.c  */
#line 690 "c.y"
    { 
                                                                             
                                                                             (yyval.CompilerInfo)=(yyvsp[(2) - (3)].CompilerInfo);
                                                                             (yyval.CompilerInfo).data.sign = (yyvsp[(1) - (3)].CompilerInfo).data.sign;
                                                                             (yyval.CompilerInfo).data.type = (yyvsp[(1) - (3)].CompilerInfo).data.type;
                                                                             (yyval.CompilerInfo).data.storage = (yyvsp[(1) - (3)].CompilerInfo).data.storage;
                                                                             printCompilerInfoNode("declaration_specifiers declarator compound_statement REDUCE to function_definition", &(yyval.CompilerInfo));
                                                                            }
    break;

  case 239:
/* Line 1792 of yacc.c  */
#line 701 "c.y"
    {printCompilerInfoNode("declaration REDUCE to declaration_list",NULL);}
    break;

  case 240:
/* Line 1792 of yacc.c  */
#line 702 "c.y"
    {printCompilerInfoNode("declaration_list declaration REDUCE to declaration_list",NULL);}
    break;


/* Line 1792 of yacc.c  */
#line 3890 "c.tab.c"
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 705 "c.y"


void yyerror(const char* s) {
    fprintf(stderr, "Parse error on line %d column %d : %s", yylineno, column, s);
    num_errors++;
}