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

#ifndef YY_YY_CANSI_TAB_H_INCLUDED
# define YY_YY_CANSI_TAB_H_INCLUDED
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
    I_CONST = 259,                 /* "i_const"  */
    F_CONST = 260,                 /* "f_const"  */
    STRING_LITERAL = 261,          /* "sting_literal"  */
    TYPE_NAME = 262,               /* "type name"  */
    AUTO = 263,                    /* "auto"  */
    BREAK = 264,                   /* "break"  */
    CASE = 265,                    /* "case"  */
    CHAR = 266,                    /* "char"  */
    CONST = 267,                   /* "const"  */
    CONTINUE = 268,                /* "continue"  */
    DEFAULT = 269,                 /* "default"  */
    DO = 270,                      /* "do"  */
    DOUBLE = 271,                  /* "double"  */
    LONG_DOUBLE = 272,             /* "long double"  */
    ELSE = 273,                    /* "else"  */
    ENUM = 274,                    /* "enum"  */
    EXTERN = 275,                  /* "extern"  */
    FLOAT = 276,                   /* "float"  */
    FOR = 277,                     /* "for"  */
    GOTO = 278,                    /* "goto"  */
    IF = 279,                      /* "if"  */
    INLINE = 280,                  /* "inline"  */
    INT = 281,                     /* INT  */
    LONG = 282,                    /* "long"  */
    LONG_LONG = 283,               /* "long long"  */
    REGISTER = 284,                /* "register"  */
    RESTRICT = 285,                /* "restrict"  */
    RETURN = 286,                  /* "return"  */
    SHORT = 287,                   /* "short"  */
    SIGNED = 288,                  /* "signed"  */
    SIZEOF = 289,                  /* "sizeof"  */
    STATIC = 290,                  /* "static"  */
    STRUCT = 291,                  /* "struct"  */
    SWITCH = 292,                  /* "switch"  */
    TYPEDEF = 293,                 /* "typedef"  */
    UNION = 294,                   /* "union"  */
    UNSIGNED = 295,                /* "unsigned"  */
    VOID = 296,                    /* "void"  */
    VOLATILE = 297,                /* "volatile"  */
    WHILE = 298,                   /* "while"  */
    BOOL = 299,                    /* "bool"  */
    COMPLEX = 300,                 /* "complex"  */
    IMAGINARY = 301,               /* "imaginary"  */
    ELLIPSIS = 302,                /* "ellipsis"  */
    QUESTION = 303,                /* "question"  */
    SEMICOLON = 304,               /* ";"  */
    OCURLY = 305,                  /* "{"  */
    CCURLY = 306,                  /* "}"  */
    COMMA = 307,                   /* ","  */
    COLON = 308,                   /* ":"  */
    OPAREN = 309,                  /* "("  */
    CPAREN = 310,                  /* ")"  */
    OBRACE = 311,                  /* "["  */
    CBRACE = 312,                  /* "]"  */
    PERIOD = 313,                  /* "."  */
    TILDE = 314,                   /* "~"  */
    EQUAL = 315,                   /* "="  */
    RIGHT_ASSIGN = 316,            /* ">>="  */
    LEFT_ASSIGN = 317,             /* "<<="  */
    ADD_ASSIGN = 318,              /* "+="  */
    SUB_ASSIGN = 319,              /* "-="  */
    MUL_ASSIGN = 320,              /* "*="  */
    DIV_ASSIGN = 321,              /* "/="  */
    MOD_ASSIGN = 322,              /* "%="  */
    AND_ASSIGN = 323,              /* "&="  */
    XOR_ASSIGN = 324,              /* "^="  */
    OR_ASSIGN = 325,               /* "|="  */
    RIGHT_OP = 326,                /* ">>"  */
    LEFT_OP = 327,                 /* "<<"  */
    INC_OP = 328,                  /* "++"  */
    DEC_OP = 329,                  /* "--"  */
    PTR_OP = 330,                  /* "->"  */
    AND_OP = 331,                  /* "&&"  */
    OR_OP = 332,                   /* "||"  */
    GREATER_EQUAL = 333,           /* ">="  */
    LESS_EQUAL = 334,              /* "<="  */
    GREATER = 335,                 /* ">"  */
    LESS = 336,                    /* "<"  */
    EQUAL_EQUAL = 337,             /* "=="  */
    NOT_EQUAL = 338,               /* "!="  */
    NOT_OP = 339,                  /* "!"  */
    XOR_OP = 340,                  /* "^"  */
    BIT_AND = 341,                 /* "&"  */
    BIT_OR = 342,                  /* "|"  */
    MINUS_OP = 343,                /* "-"  */
    PLUS_OP = 344,                 /* "+"  */
    TIMES_OP = 345,                /* "*"  */
    DIV_OP = 346,                  /* "/"  */
    MOD_OP = 347                   /* "%"  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CANSI_TAB_H_INCLUDED  */
