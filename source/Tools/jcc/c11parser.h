/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_C11PARSER_H_INCLUDED
# define YY_YY_C11PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    END = 0,                       /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* "identifier"  */
    I_CONSTANT = 259,              /* "i_const"  */
    F_CONSTANT = 260,              /* "f_const"  */
    STRING_LITERAL = 261,          /* "sting_literal"  */
    Y_EXCLAMATION = 262,           /* Y_EXCLAMATION  */
    Y_NE = 263,                    /* Y_NE  */
    Y_POUND = 264,                 /* Y_POUND  */
    Y_POUND_POUND = 265,           /* Y_POUND_POUND  */
    Y_AND = 266,                   /* Y_AND  */
    Y_AND_AND = 267,               /* Y_AND_AND  */
    Y_AND_EQUAL = 268,             /* Y_AND_EQUAL  */
    Y_LEFT_PAREN = 269,            /* Y_LEFT_PAREN  */
    Y_RIGHT_PAREN = 270,           /* Y_RIGHT_PAREN  */
    Y_TIMES = 271,                 /* Y_TIMES  */
    Y_TIMES_EQUAL = 272,           /* Y_TIMES_EQUAL  */
    Y_PLUS = 273,                  /* Y_PLUS  */
    Y_PLUS_PLUS = 274,             /* Y_PLUS_PLUS  */
    Y_PLUS_EQUAL = 275,            /* Y_PLUS_EQUAL  */
    Y_COMMA = 276,                 /* Y_COMMA  */
    Y_MINUS = 277,                 /* Y_MINUS  */
    Y_MINUS_MINUS = 278,           /* Y_MINUS_MINUS  */
    Y_MINUS_EQUAL = 279,           /* Y_MINUS_EQUAL  */
    Y_ARROW = 280,                 /* Y_ARROW  */
    Y_DOT = 281,                   /* Y_DOT  */
    Y_DOT_DOT_DOT = 282,           /* Y_DOT_DOT_DOT  */
    Y_DIVIDE = 283,                /* Y_DIVIDE  */
    Y_DIVIDE_EQUAL = 284,          /* Y_DIVIDE_EQUAL  */
    Y_COLON = 285,                 /* Y_COLON  */
    Y_SEG_OP = 286,                /* Y_SEG_OP  */
    Y_SEMICOLON = 287,             /* Y_SEMICOLON  */
    Y_LT = 288,                    /* Y_LT  */
    Y_LSHIFT = 289,                /* Y_LSHIFT  */
    Y_LSHIFT_EQUAL = 290,          /* Y_LSHIFT_EQUAL  */
    Y_LE = 291,                    /* Y_LE  */
    Y_EQUAL = 292,                 /* Y_EQUAL  */
    Y_EQ = 293,                    /* Y_EQ  */
    Y_GT = 294,                    /* Y_GT  */
    Y_GE = 295,                    /* Y_GE  */
    Y_RSHIFT = 296,                /* Y_RSHIFT  */
    Y_RSHIFT_EQUAL = 297,          /* Y_RSHIFT_EQUAL  */
    Y_QUESTION = 298,              /* Y_QUESTION  */
    Y_LEFT_BRACKET = 299,          /* Y_LEFT_BRACKET  */
    Y_RIGHT_BRACKET = 300,         /* Y_RIGHT_BRACKET  */
    Y_XOR = 301,                   /* Y_XOR  */
    Y_XOR_EQUAL = 302,             /* Y_XOR_EQUAL  */
    Y___BASED = 303,               /* Y___BASED  */
    Y___CDECL = 304,               /* Y___CDECL  */
    Y___EXPORT = 305,              /* Y___EXPORT  */
    Y___FAR = 306,                 /* Y___FAR  */
    Y___FAR16 = 307,               /* Y___FAR16  */
    Y___FORTRAN = 308,             /* Y___FORTRAN  */
    Y___HUGE = 309,                /* Y___HUGE  */
    Y___INTERRUPT = 310,           /* Y___INTERRUPT  */
    Y___LOADDS = 311,              /* Y___LOADDS  */
    Y___NEAR = 312,                /* Y___NEAR  */
    Y___PASCAL = 313,              /* Y___PASCAL  */
    Y___PRAGMA = 314,              /* Y___PRAGMA  */
    Y___SAVEREGS = 315,            /* Y___SAVEREGS  */
    Y___SEGMENT = 316,             /* Y___SEGMENT  */
    Y___SEGNAME = 317,             /* Y___SEGNAME  */
    Y___SELF = 318,                /* Y___SELF  */
    Y___STDCALL = 319,             /* Y___STDCALL  */
    Y__PACKED = 320,               /* Y__PACKED  */
    Y__SEG16 = 321,                /* Y__SEG16  */
    Y__SYSCALL = 322,              /* Y__SYSCALL  */
    Y_THREAD_LOCAL = 323,          /* Y_THREAD_LOCAL  */
    Y_AUTO = 324,                  /* Y_AUTO  */
    Y_CHAR = 325,                  /* Y_CHAR  */
    Y_CONST = 326,                 /* Y_CONST  */
    Y_DOUBLE = 327,                /* Y_DOUBLE  */
    Y_ELSE = 328,                  /* Y_ELSE  */
    Y_ENUM = 329,                  /* Y_ENUM  */
    Y_EXTERN = 330,                /* Y_EXTERN  */
    Y_FLOAT = 331,                 /* Y_FLOAT  */
    Y_INT = 332,                   /* Y_INT  */
    Y_LONG = 333,                  /* Y_LONG  */
    Y_REGISTER = 334,              /* Y_REGISTER  */
    Y_SHORT = 335,                 /* Y_SHORT  */
    Y_SIGNED = 336,                /* Y_SIGNED  */
    Y_SIZEOF = 337,                /* Y_SIZEOF  */
    Y_STATIC = 338,                /* Y_STATIC  */
    Y_STRUCT = 339,                /* Y_STRUCT  */
    Y_TYPEDEF = 340,               /* Y_TYPEDEF  */
    Y_UNION = 341,                 /* Y_UNION  */
    Y_UNSIGNED = 342,              /* Y_UNSIGNED  */
    Y_VOID = 343,                  /* Y_VOID  */
    Y_VOLATILE = 344,              /* Y_VOLATILE  */
    Y_LEFT_BRACE = 345,            /* Y_LEFT_BRACE  */
    Y_OR = 346,                    /* Y_OR  */
    Y_OR_EQUAL = 347,              /* Y_OR_EQUAL  */
    Y_OR_OR = 348,                 /* Y_OR_OR  */
    Y_RIGHT_BRACE = 349,           /* Y_RIGHT_BRACE  */
    Y_TILDE = 350,                 /* Y_TILDE  */
    Y_IF = 351,                    /* Y_IF  */
    Y_STRING = 352,                /* Y_STRING  */
    Y_INCLUDE_FILE_NAME = 353,     /* Y_INCLUDE_FILE_NAME  */
    Y_TYPEDEF_NAME = 354,          /* Y_TYPEDEF_NAME  */
    Y_NUMBER = 355,                /* Y_NUMBER  */
    Y_PERCENT = 356,               /* Y_PERCENT  */
    Y_PERCENT_EQUAL = 357,         /* Y_PERCENT_EQUAL  */
    Y_DEFINED = 358,               /* Y_DEFINED  */
    Y_ENUMERATION_CONSTANT = 359,  /* Y_ENUMERATION_CONSTANT  */
    Y_FUNC_NAME = 360,             /* Y_FUNC_NAME  */
    Y_GENERIC = 361,               /* Y_GENERIC  */
    Y_DEFAULT = 362,               /* Y_DEFAULT  */
    Y_CASE = 363,                  /* Y_CASE  */
    Y_ALIGNOF = 364,               /* Y_ALIGNOF  */
    Y_IMAGINARY = 365,             /* Y_IMAGINARY  */
    Y_COMPLEX = 366,               /* Y_COMPLEX  */
    Y_LONG_DOUBLE = 367,           /* Y_LONG_DOUBLE  */
    Y_BOOL = 368,                  /* Y_BOOL  */
    Y_ATOMIC = 369,                /* Y_ATOMIC  */
    Y_RESTRICT = 370,              /* Y_RESTRICT  */
    Y_INLINE = 371,                /* Y_INLINE  */
    Y_NORETURN = 372,              /* Y_NORETURN  */
    Y_ALIGNAS = 373,               /* Y_ALIGNAS  */
    Y_STATIC_ASSERT = 374,         /* Y_STATIC_ASSERT  */
    Y_SWITCH = 375,                /* Y_SWITCH  */
    Y_WHILE = 376,                 /* Y_WHILE  */
    Y_DO = 377,                    /* Y_DO  */
    Y_FOR = 378,                   /* Y_FOR  */
    Y_GOTO = 379,                  /* Y_GOTO  */
    Y_CONTINUE = 380,              /* Y_CONTINUE  */
    Y_BREAK = 381,                 /* Y_BREAK  */
    Y_RETURN = 382,                /* Y_RETURN  */
    Y_LONG_LONG = 383              /* Y_LONG_LONG  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef  union ParseUnion  YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif




int yyparse (void);


#endif /* !YY_YY_C11PARSER_H_INCLUDED  */
