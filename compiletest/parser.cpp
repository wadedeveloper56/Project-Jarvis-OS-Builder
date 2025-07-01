// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

// "%code top" blocks.
#line 33 "parser.y"

    #include <iostream>
    #include <stdlib.h>
    #include "scanner.h"
    #include "parser.hpp"
    #include "interpreter.h"
    #include "location.hh"
    
    // yylex() arguments are defined in parser.y
    static WadeSpace::Parser::symbol_type yylex(WadeSpace::Scanner &scanner, WadeSpace::Interpreter &driver) {
        return scanner.get_next_token();
    }
    
    // you can accomplish the same thing by inlining the code using preprocessor
    // x and y are same as in above static function
    // #define yylex(x, y) scanner.get_next_token()
    
    using namespace WadeSpace;

#line 59 "parser.cpp"




#include "parser.hpp"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 9 "parser.y"
namespace  WadeSpace  {
#line 159 "parser.cpp"

  /// Build a parser object.
   Parser :: Parser  (WadeSpace::Scanner &scanner_yyarg, WadeSpace::Interpreter &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

   Parser ::~ Parser  ()
  {}

   Parser ::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
   Parser ::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

   Parser ::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
   Parser ::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
   Parser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

   Parser ::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

   Parser ::symbol_kind_type
   Parser ::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

   Parser ::stack_symbol_type::stack_symbol_type ()
  {}

   Parser ::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_F_CONST: // "f_const"
        value.YY_MOVE_OR_COPY< long double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRING_LITERAL: // "sting_literal"
      case symbol_kind::S_TYPE_NAME: // "type name"
      case symbol_kind::S_AUTO: // "auto"
      case symbol_kind::S_BREAK: // "break"
      case symbol_kind::S_CASE: // "case"
      case symbol_kind::S_CHAR: // "char"
      case symbol_kind::S_CONST: // "const"
      case symbol_kind::S_CONTINUE: // "continue"
      case symbol_kind::S_DEFAULT: // "default"
      case symbol_kind::S_DO: // "do"
      case symbol_kind::S_DOUBLE: // "double"
      case symbol_kind::S_LONG_DOUBLE: // "long double"
      case symbol_kind::S_ELSE: // "else"
      case symbol_kind::S_ENUM: // "enum"
      case symbol_kind::S_EXTERN: // "extern"
      case symbol_kind::S_FLOAT: // "float"
      case symbol_kind::S_FOR: // "for"
      case symbol_kind::S_GOTO: // "goto"
      case symbol_kind::S_IF: // "if"
      case symbol_kind::S_INLINE: // "inline"
      case symbol_kind::S_INT: // "int"
      case symbol_kind::S_LONG: // "long"
      case symbol_kind::S_LONG_LONG: // "long long"
      case symbol_kind::S_REGISTER: // "register"
      case symbol_kind::S_RESTRICT: // "restrict"
      case symbol_kind::S_RETURN: // "return"
      case symbol_kind::S_SHORT: // "short"
      case symbol_kind::S_SIGNED: // "signed"
      case symbol_kind::S_SIZEOF: // "sizeof"
      case symbol_kind::S_STATIC: // "static"
      case symbol_kind::S_STRUCT: // "struct"
      case symbol_kind::S_SWITCH: // "switch"
      case symbol_kind::S_TYPEDEF: // "typedef"
      case symbol_kind::S_UNION: // "union"
      case symbol_kind::S_UNSIGNED: // "unsigned"
      case symbol_kind::S_VOID: // "void"
      case symbol_kind::S_VOLATILE: // "volatile"
      case symbol_kind::S_WHILE: // "while"
      case symbol_kind::S_BOOL: // "bool"
      case symbol_kind::S_COMPLEX: // "complex"
      case symbol_kind::S_IMAGINARY: // "imaginary"
      case symbol_kind::S_ELLIPSIS: // "ellipsis"
      case symbol_kind::S_QUESTION: // "question"
      case symbol_kind::S_SEMICOLON: // "semicolon"
      case symbol_kind::S_OCURLY: // "ocurly"
      case symbol_kind::S_CCURLY: // "ccurly"
      case symbol_kind::S_COMMA: // "comma"
      case symbol_kind::S_COLON: // "colon"
      case symbol_kind::S_OPAREN: // "oparen"
      case symbol_kind::S_CPAREN: // "cparen"
      case symbol_kind::S_OBRACE: // "obrace"
      case symbol_kind::S_CBRACE: // "cbrace"
      case symbol_kind::S_PERIOD: // "period"
      case symbol_kind::S_TILDE: // "tilde"
      case symbol_kind::S_EQUAL_OP: // "equal op"
      case symbol_kind::S_RIGHT_ASSIGN: // "right assign"
      case symbol_kind::S_LEFT_ASSIGN: // "left assign"
      case symbol_kind::S_ADD_ASSIGN: // "add assign"
      case symbol_kind::S_SUB_ASSIGN: // "sub assign"
      case symbol_kind::S_MUL_ASSIGN: // "mul assign"
      case symbol_kind::S_DIV_ASSIGN: // "div assign"
      case symbol_kind::S_MOD_ASSIGN: // "mod assign"
      case symbol_kind::S_AND_ASSIGN: // "and assign"
      case symbol_kind::S_XOR_ASSIGN: // "xor assign"
      case symbol_kind::S_OR_ASSIGN: // "or assign"
      case symbol_kind::S_RIGHT_OP: // "right op"
      case symbol_kind::S_LEFT_OP: // "left op"
      case symbol_kind::S_INC_OP: // "inc op"
      case symbol_kind::S_DEC_OP: // "dec op"
      case symbol_kind::S_PTR_OP: // "ptr op"
      case symbol_kind::S_AND_OP: // "and op"
      case symbol_kind::S_OR_OP: // "or op"
      case symbol_kind::S_GE_OP: // "ge op"
      case symbol_kind::S_LE_OP: // "le op"
      case symbol_kind::S_GREATER_OP: // "greater op"
      case symbol_kind::S_LESS_OP: // "less op"
      case symbol_kind::S_EQ_OP: // "eq op"
      case symbol_kind::S_NE_OP: // "ne op"
      case symbol_kind::S_NOT_OP: // "not op"
      case symbol_kind::S_XOR_OP: // "xor op"
      case symbol_kind::S_BIT_AND: // "bit and"
      case symbol_kind::S_BIT_OR: // "bit or"
      case symbol_kind::S_MINUS_OP: // "minus op"
      case symbol_kind::S_PLUS_OP: // "plus op"
      case symbol_kind::S_TIMES_OP: // "times op"
      case symbol_kind::S_DIV_OP: // "div op"
      case symbol_kind::S_MOD_OP: // "mod op"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_I_CONST: // "i_const"
        value.YY_MOVE_OR_COPY< uint64_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

   Parser ::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_F_CONST: // "f_const"
        value.move< long double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRING_LITERAL: // "sting_literal"
      case symbol_kind::S_TYPE_NAME: // "type name"
      case symbol_kind::S_AUTO: // "auto"
      case symbol_kind::S_BREAK: // "break"
      case symbol_kind::S_CASE: // "case"
      case symbol_kind::S_CHAR: // "char"
      case symbol_kind::S_CONST: // "const"
      case symbol_kind::S_CONTINUE: // "continue"
      case symbol_kind::S_DEFAULT: // "default"
      case symbol_kind::S_DO: // "do"
      case symbol_kind::S_DOUBLE: // "double"
      case symbol_kind::S_LONG_DOUBLE: // "long double"
      case symbol_kind::S_ELSE: // "else"
      case symbol_kind::S_ENUM: // "enum"
      case symbol_kind::S_EXTERN: // "extern"
      case symbol_kind::S_FLOAT: // "float"
      case symbol_kind::S_FOR: // "for"
      case symbol_kind::S_GOTO: // "goto"
      case symbol_kind::S_IF: // "if"
      case symbol_kind::S_INLINE: // "inline"
      case symbol_kind::S_INT: // "int"
      case symbol_kind::S_LONG: // "long"
      case symbol_kind::S_LONG_LONG: // "long long"
      case symbol_kind::S_REGISTER: // "register"
      case symbol_kind::S_RESTRICT: // "restrict"
      case symbol_kind::S_RETURN: // "return"
      case symbol_kind::S_SHORT: // "short"
      case symbol_kind::S_SIGNED: // "signed"
      case symbol_kind::S_SIZEOF: // "sizeof"
      case symbol_kind::S_STATIC: // "static"
      case symbol_kind::S_STRUCT: // "struct"
      case symbol_kind::S_SWITCH: // "switch"
      case symbol_kind::S_TYPEDEF: // "typedef"
      case symbol_kind::S_UNION: // "union"
      case symbol_kind::S_UNSIGNED: // "unsigned"
      case symbol_kind::S_VOID: // "void"
      case symbol_kind::S_VOLATILE: // "volatile"
      case symbol_kind::S_WHILE: // "while"
      case symbol_kind::S_BOOL: // "bool"
      case symbol_kind::S_COMPLEX: // "complex"
      case symbol_kind::S_IMAGINARY: // "imaginary"
      case symbol_kind::S_ELLIPSIS: // "ellipsis"
      case symbol_kind::S_QUESTION: // "question"
      case symbol_kind::S_SEMICOLON: // "semicolon"
      case symbol_kind::S_OCURLY: // "ocurly"
      case symbol_kind::S_CCURLY: // "ccurly"
      case symbol_kind::S_COMMA: // "comma"
      case symbol_kind::S_COLON: // "colon"
      case symbol_kind::S_OPAREN: // "oparen"
      case symbol_kind::S_CPAREN: // "cparen"
      case symbol_kind::S_OBRACE: // "obrace"
      case symbol_kind::S_CBRACE: // "cbrace"
      case symbol_kind::S_PERIOD: // "period"
      case symbol_kind::S_TILDE: // "tilde"
      case symbol_kind::S_EQUAL_OP: // "equal op"
      case symbol_kind::S_RIGHT_ASSIGN: // "right assign"
      case symbol_kind::S_LEFT_ASSIGN: // "left assign"
      case symbol_kind::S_ADD_ASSIGN: // "add assign"
      case symbol_kind::S_SUB_ASSIGN: // "sub assign"
      case symbol_kind::S_MUL_ASSIGN: // "mul assign"
      case symbol_kind::S_DIV_ASSIGN: // "div assign"
      case symbol_kind::S_MOD_ASSIGN: // "mod assign"
      case symbol_kind::S_AND_ASSIGN: // "and assign"
      case symbol_kind::S_XOR_ASSIGN: // "xor assign"
      case symbol_kind::S_OR_ASSIGN: // "or assign"
      case symbol_kind::S_RIGHT_OP: // "right op"
      case symbol_kind::S_LEFT_OP: // "left op"
      case symbol_kind::S_INC_OP: // "inc op"
      case symbol_kind::S_DEC_OP: // "dec op"
      case symbol_kind::S_PTR_OP: // "ptr op"
      case symbol_kind::S_AND_OP: // "and op"
      case symbol_kind::S_OR_OP: // "or op"
      case symbol_kind::S_GE_OP: // "ge op"
      case symbol_kind::S_LE_OP: // "le op"
      case symbol_kind::S_GREATER_OP: // "greater op"
      case symbol_kind::S_LESS_OP: // "less op"
      case symbol_kind::S_EQ_OP: // "eq op"
      case symbol_kind::S_NE_OP: // "ne op"
      case symbol_kind::S_NOT_OP: // "not op"
      case symbol_kind::S_XOR_OP: // "xor op"
      case symbol_kind::S_BIT_AND: // "bit and"
      case symbol_kind::S_BIT_OR: // "bit or"
      case symbol_kind::S_MINUS_OP: // "minus op"
      case symbol_kind::S_PLUS_OP: // "plus op"
      case symbol_kind::S_TIMES_OP: // "times op"
      case symbol_kind::S_DIV_OP: // "div op"
      case symbol_kind::S_MOD_OP: // "mod op"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_I_CONST: // "i_const"
        value.move< uint64_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_F_CONST: // "f_const"
        value.copy< long double > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRING_LITERAL: // "sting_literal"
      case symbol_kind::S_TYPE_NAME: // "type name"
      case symbol_kind::S_AUTO: // "auto"
      case symbol_kind::S_BREAK: // "break"
      case symbol_kind::S_CASE: // "case"
      case symbol_kind::S_CHAR: // "char"
      case symbol_kind::S_CONST: // "const"
      case symbol_kind::S_CONTINUE: // "continue"
      case symbol_kind::S_DEFAULT: // "default"
      case symbol_kind::S_DO: // "do"
      case symbol_kind::S_DOUBLE: // "double"
      case symbol_kind::S_LONG_DOUBLE: // "long double"
      case symbol_kind::S_ELSE: // "else"
      case symbol_kind::S_ENUM: // "enum"
      case symbol_kind::S_EXTERN: // "extern"
      case symbol_kind::S_FLOAT: // "float"
      case symbol_kind::S_FOR: // "for"
      case symbol_kind::S_GOTO: // "goto"
      case symbol_kind::S_IF: // "if"
      case symbol_kind::S_INLINE: // "inline"
      case symbol_kind::S_INT: // "int"
      case symbol_kind::S_LONG: // "long"
      case symbol_kind::S_LONG_LONG: // "long long"
      case symbol_kind::S_REGISTER: // "register"
      case symbol_kind::S_RESTRICT: // "restrict"
      case symbol_kind::S_RETURN: // "return"
      case symbol_kind::S_SHORT: // "short"
      case symbol_kind::S_SIGNED: // "signed"
      case symbol_kind::S_SIZEOF: // "sizeof"
      case symbol_kind::S_STATIC: // "static"
      case symbol_kind::S_STRUCT: // "struct"
      case symbol_kind::S_SWITCH: // "switch"
      case symbol_kind::S_TYPEDEF: // "typedef"
      case symbol_kind::S_UNION: // "union"
      case symbol_kind::S_UNSIGNED: // "unsigned"
      case symbol_kind::S_VOID: // "void"
      case symbol_kind::S_VOLATILE: // "volatile"
      case symbol_kind::S_WHILE: // "while"
      case symbol_kind::S_BOOL: // "bool"
      case symbol_kind::S_COMPLEX: // "complex"
      case symbol_kind::S_IMAGINARY: // "imaginary"
      case symbol_kind::S_ELLIPSIS: // "ellipsis"
      case symbol_kind::S_QUESTION: // "question"
      case symbol_kind::S_SEMICOLON: // "semicolon"
      case symbol_kind::S_OCURLY: // "ocurly"
      case symbol_kind::S_CCURLY: // "ccurly"
      case symbol_kind::S_COMMA: // "comma"
      case symbol_kind::S_COLON: // "colon"
      case symbol_kind::S_OPAREN: // "oparen"
      case symbol_kind::S_CPAREN: // "cparen"
      case symbol_kind::S_OBRACE: // "obrace"
      case symbol_kind::S_CBRACE: // "cbrace"
      case symbol_kind::S_PERIOD: // "period"
      case symbol_kind::S_TILDE: // "tilde"
      case symbol_kind::S_EQUAL_OP: // "equal op"
      case symbol_kind::S_RIGHT_ASSIGN: // "right assign"
      case symbol_kind::S_LEFT_ASSIGN: // "left assign"
      case symbol_kind::S_ADD_ASSIGN: // "add assign"
      case symbol_kind::S_SUB_ASSIGN: // "sub assign"
      case symbol_kind::S_MUL_ASSIGN: // "mul assign"
      case symbol_kind::S_DIV_ASSIGN: // "div assign"
      case symbol_kind::S_MOD_ASSIGN: // "mod assign"
      case symbol_kind::S_AND_ASSIGN: // "and assign"
      case symbol_kind::S_XOR_ASSIGN: // "xor assign"
      case symbol_kind::S_OR_ASSIGN: // "or assign"
      case symbol_kind::S_RIGHT_OP: // "right op"
      case symbol_kind::S_LEFT_OP: // "left op"
      case symbol_kind::S_INC_OP: // "inc op"
      case symbol_kind::S_DEC_OP: // "dec op"
      case symbol_kind::S_PTR_OP: // "ptr op"
      case symbol_kind::S_AND_OP: // "and op"
      case symbol_kind::S_OR_OP: // "or op"
      case symbol_kind::S_GE_OP: // "ge op"
      case symbol_kind::S_LE_OP: // "le op"
      case symbol_kind::S_GREATER_OP: // "greater op"
      case symbol_kind::S_LESS_OP: // "less op"
      case symbol_kind::S_EQ_OP: // "eq op"
      case symbol_kind::S_NE_OP: // "ne op"
      case symbol_kind::S_NOT_OP: // "not op"
      case symbol_kind::S_XOR_OP: // "xor op"
      case symbol_kind::S_BIT_AND: // "bit and"
      case symbol_kind::S_BIT_OR: // "bit or"
      case symbol_kind::S_MINUS_OP: // "minus op"
      case symbol_kind::S_PLUS_OP: // "plus op"
      case symbol_kind::S_TIMES_OP: // "times op"
      case symbol_kind::S_DIV_OP: // "div op"
      case symbol_kind::S_MOD_OP: // "mod op"
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_I_CONST: // "i_const"
        value.copy< uint64_t > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_F_CONST: // "f_const"
        value.move< long double > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRING_LITERAL: // "sting_literal"
      case symbol_kind::S_TYPE_NAME: // "type name"
      case symbol_kind::S_AUTO: // "auto"
      case symbol_kind::S_BREAK: // "break"
      case symbol_kind::S_CASE: // "case"
      case symbol_kind::S_CHAR: // "char"
      case symbol_kind::S_CONST: // "const"
      case symbol_kind::S_CONTINUE: // "continue"
      case symbol_kind::S_DEFAULT: // "default"
      case symbol_kind::S_DO: // "do"
      case symbol_kind::S_DOUBLE: // "double"
      case symbol_kind::S_LONG_DOUBLE: // "long double"
      case symbol_kind::S_ELSE: // "else"
      case symbol_kind::S_ENUM: // "enum"
      case symbol_kind::S_EXTERN: // "extern"
      case symbol_kind::S_FLOAT: // "float"
      case symbol_kind::S_FOR: // "for"
      case symbol_kind::S_GOTO: // "goto"
      case symbol_kind::S_IF: // "if"
      case symbol_kind::S_INLINE: // "inline"
      case symbol_kind::S_INT: // "int"
      case symbol_kind::S_LONG: // "long"
      case symbol_kind::S_LONG_LONG: // "long long"
      case symbol_kind::S_REGISTER: // "register"
      case symbol_kind::S_RESTRICT: // "restrict"
      case symbol_kind::S_RETURN: // "return"
      case symbol_kind::S_SHORT: // "short"
      case symbol_kind::S_SIGNED: // "signed"
      case symbol_kind::S_SIZEOF: // "sizeof"
      case symbol_kind::S_STATIC: // "static"
      case symbol_kind::S_STRUCT: // "struct"
      case symbol_kind::S_SWITCH: // "switch"
      case symbol_kind::S_TYPEDEF: // "typedef"
      case symbol_kind::S_UNION: // "union"
      case symbol_kind::S_UNSIGNED: // "unsigned"
      case symbol_kind::S_VOID: // "void"
      case symbol_kind::S_VOLATILE: // "volatile"
      case symbol_kind::S_WHILE: // "while"
      case symbol_kind::S_BOOL: // "bool"
      case symbol_kind::S_COMPLEX: // "complex"
      case symbol_kind::S_IMAGINARY: // "imaginary"
      case symbol_kind::S_ELLIPSIS: // "ellipsis"
      case symbol_kind::S_QUESTION: // "question"
      case symbol_kind::S_SEMICOLON: // "semicolon"
      case symbol_kind::S_OCURLY: // "ocurly"
      case symbol_kind::S_CCURLY: // "ccurly"
      case symbol_kind::S_COMMA: // "comma"
      case symbol_kind::S_COLON: // "colon"
      case symbol_kind::S_OPAREN: // "oparen"
      case symbol_kind::S_CPAREN: // "cparen"
      case symbol_kind::S_OBRACE: // "obrace"
      case symbol_kind::S_CBRACE: // "cbrace"
      case symbol_kind::S_PERIOD: // "period"
      case symbol_kind::S_TILDE: // "tilde"
      case symbol_kind::S_EQUAL_OP: // "equal op"
      case symbol_kind::S_RIGHT_ASSIGN: // "right assign"
      case symbol_kind::S_LEFT_ASSIGN: // "left assign"
      case symbol_kind::S_ADD_ASSIGN: // "add assign"
      case symbol_kind::S_SUB_ASSIGN: // "sub assign"
      case symbol_kind::S_MUL_ASSIGN: // "mul assign"
      case symbol_kind::S_DIV_ASSIGN: // "div assign"
      case symbol_kind::S_MOD_ASSIGN: // "mod assign"
      case symbol_kind::S_AND_ASSIGN: // "and assign"
      case symbol_kind::S_XOR_ASSIGN: // "xor assign"
      case symbol_kind::S_OR_ASSIGN: // "or assign"
      case symbol_kind::S_RIGHT_OP: // "right op"
      case symbol_kind::S_LEFT_OP: // "left op"
      case symbol_kind::S_INC_OP: // "inc op"
      case symbol_kind::S_DEC_OP: // "dec op"
      case symbol_kind::S_PTR_OP: // "ptr op"
      case symbol_kind::S_AND_OP: // "and op"
      case symbol_kind::S_OR_OP: // "or op"
      case symbol_kind::S_GE_OP: // "ge op"
      case symbol_kind::S_LE_OP: // "le op"
      case symbol_kind::S_GREATER_OP: // "greater op"
      case symbol_kind::S_LESS_OP: // "less op"
      case symbol_kind::S_EQ_OP: // "eq op"
      case symbol_kind::S_NE_OP: // "ne op"
      case symbol_kind::S_NOT_OP: // "not op"
      case symbol_kind::S_XOR_OP: // "xor op"
      case symbol_kind::S_BIT_AND: // "bit and"
      case symbol_kind::S_BIT_OR: // "bit or"
      case symbol_kind::S_MINUS_OP: // "minus op"
      case symbol_kind::S_PLUS_OP: // "plus op"
      case symbol_kind::S_TIMES_OP: // "times op"
      case symbol_kind::S_DIV_OP: // "div op"
      case symbol_kind::S_MOD_OP: // "mod op"
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_I_CONST: // "i_const"
        value.move< uint64_t > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
   Parser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   Parser ::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
   Parser ::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
   Parser ::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
   Parser ::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   Parser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   Parser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   Parser ::debug_level_type
   Parser ::debug_level () const
  {
    return yydebug_;
  }

  void
   Parser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

   Parser ::state_type
   Parser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
   Parser ::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
   Parser ::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
   Parser ::operator() ()
  {
    return parse ();
  }

  int
   Parser ::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (scanner, driver));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_F_CONST: // "f_const"
        yylhs.value.emplace< long double > ();
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRING_LITERAL: // "sting_literal"
      case symbol_kind::S_TYPE_NAME: // "type name"
      case symbol_kind::S_AUTO: // "auto"
      case symbol_kind::S_BREAK: // "break"
      case symbol_kind::S_CASE: // "case"
      case symbol_kind::S_CHAR: // "char"
      case symbol_kind::S_CONST: // "const"
      case symbol_kind::S_CONTINUE: // "continue"
      case symbol_kind::S_DEFAULT: // "default"
      case symbol_kind::S_DO: // "do"
      case symbol_kind::S_DOUBLE: // "double"
      case symbol_kind::S_LONG_DOUBLE: // "long double"
      case symbol_kind::S_ELSE: // "else"
      case symbol_kind::S_ENUM: // "enum"
      case symbol_kind::S_EXTERN: // "extern"
      case symbol_kind::S_FLOAT: // "float"
      case symbol_kind::S_FOR: // "for"
      case symbol_kind::S_GOTO: // "goto"
      case symbol_kind::S_IF: // "if"
      case symbol_kind::S_INLINE: // "inline"
      case symbol_kind::S_INT: // "int"
      case symbol_kind::S_LONG: // "long"
      case symbol_kind::S_LONG_LONG: // "long long"
      case symbol_kind::S_REGISTER: // "register"
      case symbol_kind::S_RESTRICT: // "restrict"
      case symbol_kind::S_RETURN: // "return"
      case symbol_kind::S_SHORT: // "short"
      case symbol_kind::S_SIGNED: // "signed"
      case symbol_kind::S_SIZEOF: // "sizeof"
      case symbol_kind::S_STATIC: // "static"
      case symbol_kind::S_STRUCT: // "struct"
      case symbol_kind::S_SWITCH: // "switch"
      case symbol_kind::S_TYPEDEF: // "typedef"
      case symbol_kind::S_UNION: // "union"
      case symbol_kind::S_UNSIGNED: // "unsigned"
      case symbol_kind::S_VOID: // "void"
      case symbol_kind::S_VOLATILE: // "volatile"
      case symbol_kind::S_WHILE: // "while"
      case symbol_kind::S_BOOL: // "bool"
      case symbol_kind::S_COMPLEX: // "complex"
      case symbol_kind::S_IMAGINARY: // "imaginary"
      case symbol_kind::S_ELLIPSIS: // "ellipsis"
      case symbol_kind::S_QUESTION: // "question"
      case symbol_kind::S_SEMICOLON: // "semicolon"
      case symbol_kind::S_OCURLY: // "ocurly"
      case symbol_kind::S_CCURLY: // "ccurly"
      case symbol_kind::S_COMMA: // "comma"
      case symbol_kind::S_COLON: // "colon"
      case symbol_kind::S_OPAREN: // "oparen"
      case symbol_kind::S_CPAREN: // "cparen"
      case symbol_kind::S_OBRACE: // "obrace"
      case symbol_kind::S_CBRACE: // "cbrace"
      case symbol_kind::S_PERIOD: // "period"
      case symbol_kind::S_TILDE: // "tilde"
      case symbol_kind::S_EQUAL_OP: // "equal op"
      case symbol_kind::S_RIGHT_ASSIGN: // "right assign"
      case symbol_kind::S_LEFT_ASSIGN: // "left assign"
      case symbol_kind::S_ADD_ASSIGN: // "add assign"
      case symbol_kind::S_SUB_ASSIGN: // "sub assign"
      case symbol_kind::S_MUL_ASSIGN: // "mul assign"
      case symbol_kind::S_DIV_ASSIGN: // "div assign"
      case symbol_kind::S_MOD_ASSIGN: // "mod assign"
      case symbol_kind::S_AND_ASSIGN: // "and assign"
      case symbol_kind::S_XOR_ASSIGN: // "xor assign"
      case symbol_kind::S_OR_ASSIGN: // "or assign"
      case symbol_kind::S_RIGHT_OP: // "right op"
      case symbol_kind::S_LEFT_OP: // "left op"
      case symbol_kind::S_INC_OP: // "inc op"
      case symbol_kind::S_DEC_OP: // "dec op"
      case symbol_kind::S_PTR_OP: // "ptr op"
      case symbol_kind::S_AND_OP: // "and op"
      case symbol_kind::S_OR_OP: // "or op"
      case symbol_kind::S_GE_OP: // "ge op"
      case symbol_kind::S_LE_OP: // "le op"
      case symbol_kind::S_GREATER_OP: // "greater op"
      case symbol_kind::S_LESS_OP: // "less op"
      case symbol_kind::S_EQ_OP: // "eq op"
      case symbol_kind::S_NE_OP: // "ne op"
      case symbol_kind::S_NOT_OP: // "not op"
      case symbol_kind::S_XOR_OP: // "xor op"
      case symbol_kind::S_BIT_AND: // "bit and"
      case symbol_kind::S_BIT_OR: // "bit or"
      case symbol_kind::S_MINUS_OP: // "minus op"
      case symbol_kind::S_PLUS_OP: // "plus op"
      case symbol_kind::S_TIMES_OP: // "times op"
      case symbol_kind::S_DIV_OP: // "div op"
      case symbol_kind::S_MOD_OP: // "mod op"
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_I_CONST: // "i_const"
        yylhs.value.emplace< uint64_t > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {

#line 1047 "parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
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


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
   Parser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
   Parser ::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
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
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
   Parser ::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  //  Parser ::context.
   Parser ::context::context (const  Parser & yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
   Parser ::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
   Parser ::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
   Parser ::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short  Parser ::yypact_ninf_ = -218;

  const signed char  Parser ::yytable_ninf_ = -1;

  const short
   Parser ::yypact_[] =
  {
    1295,  -218,  -218,  -218,  -218,  -218,  -218,     8,  -218,  -218,
    -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,
    -218,  -218,     3,    38,  -218,    36,  1445,  1445,  -218,    11,
    -218,  1445,   930,    53,     4,  1213,  -218,  -218,   -92,    35,
     -44,  -218,  -218,    38,  -218,   -20,  -218,   894,  -218,  -218,
     -24,   272,  -218,   314,  -218,    36,  -218,   930,   949,  1372,
      53,  -218,  -218,    35,   -58,   -34,  -218,  -218,  -218,  -218,
       3,  -218,   716,  -218,   930,   272,   272,   358,  -218,    21,
     272,   -10,  -218,  -218,  -218,    10,  1066,    33,    39,   673,
      82,   187,   100,   657,  1098,   134,   163,  1066,  1108,  1108,
     272,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,
    -218,   107,     7,  1066,  -218,   -52,    12,   136,   -45,   164,
     126,   151,   162,   197,   -32,  -218,  -218,    13,  -218,  -218,
    -218,   428,   481,  -218,  -218,  -218,  -218,   165,  -218,  -218,
    -218,  -218,  -218,  -218,   180,  -218,  -218,    44,   179,   178,
    -218,    89,    -9,  1066,    35,  -218,  -218,   716,  -218,  -218,
    -218,   858,  -218,  -218,  -218,  1066,    74,  -218,   168,  -218,
     673,  -218,   169,  -218,   673,   234,   759,   171,  1066,  -218,
      85,   272,  -218,  1066,  1066,   -37,  -218,  -218,   127,   186,
    -218,  -218,   283,  1066,   981,   286,  -218,  -218,  -218,  -218,
    -218,  -218,  -218,  -218,  -218,  -218,  -218,  1066,  -218,  1066,
    1066,  1066,  1066,  1066,  1066,  1066,  1066,  1066,  1066,  1066,
    1066,  1066,  1066,  1066,  1066,  1066,  1066,  1066,  1066,  -218,
    -218,   555,  -218,  -218,  -218,   992,  1253,  -218,    17,  -218,
     101,  -218,   605,  -218,   287,  -218,  -218,  -218,  -218,    27,
    -218,  -218,    21,  -218,  1066,  -218,   673,  -218,   199,   759,
    -218,   118,  -218,   196,   121,   130,  -218,  1331,   137,  -218,
    1066,  -218,    -8,  -218,   143,  -218,  -218,  -218,  -218,  -218,
    -218,   -52,   -52,    12,    12,   136,   136,   136,   136,   -45,
     -45,   164,   126,   151,   162,   197,    94,  -218,  -218,  -218,
     201,  -218,   204,   206,   101,  1024,  1409,  -218,  -218,  -218,
     599,  -218,  -218,  -218,  -218,  1066,  1034,   673,  -218,   673,
     673,  -218,  -218,  -218,  1066,  1066,  -218,  -218,  -218,  -218,
     203,  -218,   207,  -218,  -218,   147,   673,   161,   289,  -218,
    -218,  -218,  -218,  -218,  -218,   195,  -218,   673,   673,  -218,
    -218,  -218
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
       0,   135,   106,    93,    96,   131,   101,     0,    91,   100,
      98,    99,    94,    97,   102,    92,   110,    90,   111,   103,
      95,   132,     0,   142,   210,     0,    80,    82,   104,     0,
     105,    84,     0,   134,     0,     0,   207,   209,   126,     0,
       0,   146,   144,   143,    78,     0,    86,    88,    81,    83,
     109,     0,    85,     0,   189,     0,   214,     0,     0,     0,
     133,     1,   208,     0,   129,     0,   127,   136,   147,   145,
       0,    79,     0,   212,     0,     0,   116,     0,   112,     0,
     118,     2,     7,     6,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    24,    25,    26,    27,    28,    29,   193,   185,     8,
       3,    18,    30,     0,    32,    36,    39,    42,    47,    50,
      52,    54,    56,    58,    60,    62,    75,     0,   191,   176,
     177,     0,     0,   178,   179,   180,   181,    88,   190,   213,
       2,   138,    30,    77,     0,   155,   141,   154,     0,   148,
     150,     0,     0,     0,     0,   124,    87,     0,   171,    89,
     211,     0,   115,   108,   113,     0,     0,   119,   121,   117,
       0,   204,     0,   203,     0,     0,     0,     0,     0,   205,
       0,     0,    22,     0,     0,     0,    19,    20,   157,     0,
      14,    15,     0,     0,     0,     0,    71,    70,    68,    69,
      65,    66,    67,    72,    73,    74,    64,     0,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   194,
     187,     0,   186,   192,   137,     0,     0,   152,   159,   153,
     160,   139,     0,   140,     0,   125,   130,   128,   174,     0,
     107,   122,     0,   114,     0,   182,     0,   184,     0,     0,
     202,     0,   206,     0,     0,     0,     5,     0,   159,   158,
       0,    13,     0,    10,     0,    16,    12,    63,    33,    34,
      35,    37,    38,    41,    40,    46,    45,    43,    44,    48,
      49,    51,    53,    55,    57,    59,     0,    76,   188,   163,
       0,   167,     0,     0,   161,     0,     0,   149,   151,   156,
       0,   172,   120,   123,   183,     0,     0,     0,    23,     0,
       0,    31,     9,    11,     0,     0,   164,   168,   162,   165,
       0,   169,     0,   173,   175,     0,     0,     0,   195,   197,
     198,    17,    61,   166,   170,     0,   200,     0,     0,   199,
     201,   196
  };

  const short
   Parser ::yypgoto_[] =
  {
    -218,  -218,  -218,  -218,  -218,   -57,  -218,   -81,    51,    56,
      37,    45,    88,    92,   108,   106,   113,  -218,   -56,   -23,
    -218,   -78,   -61,     9,     0,  -218,   274,  -218,   135,  -218,
    -218,   267,   -60,   -40,  -218,   109,  -218,   295,   205,    42,
     -12,   -29,   -15,  -218,   -55,  -218,   120,  -218,   182,  -131,
    -217,  -135,  -218,   -86,  -218,   144,    34,   229,  -164,  -218,
    -218,  -218,  -218,   329,  -218
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,   109,   110,   111,   274,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     207,   127,   144,    54,    55,    45,    46,    26,    27,    28,
      29,    77,    78,    79,   166,   167,    30,    65,    66,    31,
      32,    33,    34,    43,   302,   149,   150,   151,   189,   303,
     240,   159,   249,   128,   129,   130,    57,   132,   133,   134,
     135,   136,    35,    36,    37
  };

  const short
   Parser ::yytable_[] =
  {
      25,   142,   143,   175,   148,    60,     1,     1,    42,    24,
      40,    38,   259,    47,    50,   180,   239,   164,   266,   185,
       1,   304,   248,    63,     1,   172,    48,    49,    69,   142,
     143,    52,   208,   216,   217,    25,   162,   182,    64,     1,
     169,   186,   187,   137,    24,   226,   233,     1,   209,   158,
       5,   304,    67,   210,   211,   153,   142,   269,   137,   147,
     188,   228,   218,   219,   154,    41,   138,   168,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    70,   227,
      21,    74,   155,   138,   255,    68,   322,   131,   257,   154,
     228,    75,   246,    80,    71,   316,   142,   143,    22,    22,
     261,   164,   170,    23,   251,   264,   265,   245,   142,   143,
     235,   228,   236,   212,   213,   272,    22,    80,    80,    80,
     206,    23,    80,    39,   171,   310,    51,   229,   278,   279,
     280,    22,   238,   165,   158,   237,    23,   235,    23,   236,
     138,   188,    80,   311,    23,   233,    58,   173,    59,   296,
      44,   174,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     314,   275,   252,   268,   300,   334,    56,   176,   142,   143,
     190,   191,   192,   228,   277,   243,    76,   244,   253,   321,
     177,    73,   228,   313,   305,   178,   306,   142,   143,   262,
     193,   139,   194,    80,   195,   297,   325,   214,   215,    60,
      76,    76,    76,   142,   317,    76,   228,   319,   160,   228,
     235,   238,   267,    80,    40,   222,   320,    23,   228,   183,
     235,   338,   267,   339,   340,    76,   147,   335,   337,   323,
     168,   324,   147,   345,   330,   228,   220,   221,   142,   143,
     346,   332,   268,   285,   286,   287,   288,   347,   184,   228,
     223,   350,   351,   281,   282,   289,   290,   147,   142,   342,
     283,   284,   224,   225,   234,   241,   242,   258,    72,     2,
     254,   256,   270,     4,     5,   260,   271,   158,     6,   276,
     309,     7,   318,     9,   315,   326,    76,   343,    10,    11,
     327,   341,   328,   344,    13,    14,   147,   348,    16,   349,
     291,    18,    19,    20,    21,   292,    76,    81,    82,    83,
      84,     2,     3,    85,    86,     4,     5,    87,    88,    89,
       6,   294,   293,     7,     8,     9,    90,    91,    92,   295,
      10,    11,   161,    12,   156,    93,    13,    14,    94,    15,
      16,    95,    17,    18,    19,    20,    21,    96,   152,   247,
     231,   312,   308,   263,    62,     2,     0,     0,    97,     4,
       5,     0,     0,     0,     6,     0,     0,     7,     0,     9,
       0,     0,     0,     0,    10,    11,     0,    98,    99,     0,
      13,    14,     0,     0,    16,     0,     0,    18,    19,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,   100,
       0,     0,     0,   101,   102,   103,   104,   105,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,    53,
     108,    81,    82,    83,    84,     2,     3,    85,    86,     4,
       5,    87,    88,    89,     6,     0,     0,     7,     8,     9,
      90,    91,    92,     0,    10,    11,     0,    12,     0,    93,
      13,    14,    94,    15,    16,    95,    17,    18,    19,    20,
      21,    96,     0,     0,   163,     0,     0,     0,     0,     0,
       0,     0,    97,     0,    81,    82,    83,    84,     0,     0,
      85,    86,     0,     0,    87,    88,    89,     0,     0,     0,
       0,    98,    99,    90,    91,    92,     0,     0,     0,     0,
       0,     0,    93,     0,     0,    94,     0,     0,    95,     0,
       0,     0,     0,   100,    96,     0,     0,   101,   102,   103,
     104,   105,   106,     0,     0,    97,     0,     0,     0,     0,
       0,     0,   107,    53,   230,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    98,    99,     0,     0,    81,    82,
      83,    84,     0,     0,    85,    86,     0,     0,    87,    88,
      89,     0,     0,     0,     0,     0,   100,    90,    91,    92,
     101,   102,   103,   104,   105,   106,    93,     0,     0,    94,
       0,     0,    95,     0,     0,   107,    53,   232,    96,     0,
       0,     0,   140,    82,    83,    84,     0,     0,     0,    97,
       0,     0,     2,     3,     0,     0,     4,     5,     0,     0,
       0,     6,     0,     0,     7,     8,     9,     0,    98,    99,
       0,    10,    11,    94,    12,     0,     0,    13,    14,     0,
      15,    16,     0,    17,    18,    19,    20,    21,     0,     0,
     100,     0,   307,    97,   101,   102,   103,   104,   105,   106,
     140,    82,    83,    84,     0,     0,     0,     0,     0,   107,
      53,   298,    98,    99,     0,     0,    81,    82,    83,    84,
       0,     0,    85,    86,     0,     0,    87,    88,    89,     0,
       0,    94,     0,     0,   100,    90,    91,    92,   101,   102,
     103,   104,   105,   106,    93,     0,     0,    94,     0,     0,
      95,    97,     0,     0,   157,   333,    96,     0,     0,   140,
      82,    83,    84,     0,     0,     0,     0,    97,     0,     0,
      98,    99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    98,    99,     0,     0,
      94,     0,   100,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   140,    82,    83,    84,     0,     0,   100,     0,
      97,   179,   101,   102,   103,   104,   105,   106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   107,    53,    98,
      99,     0,     0,    94,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,     0,    97,     0,   101,   102,   103,   104,   105,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   157,    98,    99,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,     0,     0,     0,   101,   102,
     103,   104,   105,   106,     0,     2,     0,     0,     0,     4,
       5,     0,     0,   107,     6,     0,     0,     7,     0,     9,
       0,     0,     0,     0,    10,    11,     0,     0,     0,     0,
      13,    14,     0,     0,    16,     0,     0,    18,    19,    20,
      21,     2,     3,     0,     0,     4,     5,     0,     0,     0,
       6,     0,     0,     7,     8,     9,     0,     0,     0,     0,
      10,    11,     0,    12,     0,     0,    13,    14,     0,    15,
      16,     0,    17,    18,    19,    20,    21,     2,     3,     0,
       0,     4,     5,     0,     0,     0,     6,     0,     0,     7,
       8,     9,   140,    82,    83,    84,    10,    11,     0,    12,
       0,     0,    13,    14,     0,    15,    16,     0,    17,    18,
      19,    20,    21,     0,   250,     0,     0,     0,     0,     0,
       0,     0,     0,    94,   140,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,   140,    82,    83,    84,     0,
       0,     0,     0,    97,     0,     0,     0,    72,     0,    53,
       0,     0,     0,     0,     0,    94,     0,     0,     0,     0,
       0,     0,    98,    99,     0,     0,    94,   140,    82,    83,
      84,     0,     0,     0,     0,    97,     0,   140,    82,    83,
      84,     0,     0,   141,   100,    53,    97,     0,   101,   102,
     103,   104,   105,   106,    98,    99,     0,     0,    94,     0,
       0,     0,     0,     0,     0,    98,    99,     0,    94,   140,
      82,    83,    84,     0,     0,     0,   100,   273,    97,     0,
     101,   102,   103,   104,   105,   106,   299,   100,    97,     0,
       0,   101,   102,   103,   104,   105,   106,    98,    99,     0,
      94,   140,    82,    83,    84,     0,     0,    98,    99,     0,
       0,   140,    82,    83,    84,     0,     0,     0,   329,   100,
      97,     0,     0,   101,   102,   103,   104,   105,   106,   100,
     336,     0,    94,   101,   102,   103,   104,   105,   106,    98,
      99,     0,    94,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,     0,     0,     0,     0,     0,     0,     0,
       0,   100,    97,     0,     0,   101,   102,   103,   104,   105,
     106,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   181,     0,     0,     0,   101,   102,   103,
     104,   105,   106,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,    61,     0,     0,     1,     0,     0,     0,
       2,     3,     0,     0,     4,     5,     0,     0,     0,     6,
       0,     0,     7,     8,     9,     0,     0,     0,     0,    10,
      11,     0,    12,     0,     0,    13,    14,     0,    15,    16,
       0,    17,    18,    19,    20,    21,     1,     0,     0,     0,
       2,     3,     0,     0,     4,     5,     0,     0,     0,     6,
       0,     0,     7,     8,     9,     0,     0,     0,     0,    10,
      11,     0,    12,     0,     0,    13,    14,     0,    15,    16,
       0,    17,    18,    19,    20,    21,     0,     0,     1,     0,
       0,     0,     2,     3,     0,     0,     4,     5,    22,     0,
       0,     6,     0,    23,     7,     8,     9,     0,     0,     0,
       0,    10,    11,     0,    12,     0,     0,    13,    14,     0,
      15,    16,     0,    17,    18,    19,    20,    21,     2,     3,
       0,     0,     4,     5,     0,     0,   235,     6,   236,   301,
       7,     8,     9,    23,     0,     0,     0,    10,    11,     0,
      12,     0,     0,    13,    14,     0,    15,    16,     0,    17,
      18,    19,    20,    21,     0,   145,     0,     0,     0,     2,
       3,     0,     0,     4,     5,     0,     0,     0,     6,     0,
      22,     7,     8,     9,     0,    23,     0,     0,    10,    11,
       0,    12,     0,     0,    13,    14,     0,    15,    16,     0,
      17,    18,    19,    20,    21,     0,     2,     3,     0,     0,
       4,     5,     0,     0,   235,     6,   267,   301,     7,     8,
       9,    23,     0,     0,     0,    10,    11,     0,    12,     0,
       0,    13,    14,     0,    15,    16,     0,    17,    18,    19,
      20,    21,     2,     3,     0,     0,     4,     5,     0,     0,
       0,     6,     0,     0,     7,     8,     9,     0,   146,     0,
       0,    10,    11,     0,    12,     0,     0,    13,    14,     0,
      15,    16,     0,    17,    18,    19,    20,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   331
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    58,    58,    89,    59,    34,     3,     3,    23,     0,
      22,     3,   176,    25,     3,    93,   147,    77,    55,    97,
       3,   238,   157,   115,     3,    86,    26,    27,    43,    86,
      86,    31,   113,    78,    79,    35,    76,    94,     3,     3,
      80,    98,    99,    55,    35,    77,   132,     3,   100,    72,
      12,   268,    96,   105,   106,   113,   113,   188,    70,    59,
     100,    98,   107,   108,    98,    23,    57,    79,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    98,   111,
      42,    47,   116,    74,   170,    43,    94,    53,   174,    98,
      98,   115,   153,    51,   114,   259,   153,   153,    95,    95,
     178,   161,   112,   100,   165,   183,   184,   116,   165,   165,
      93,    98,    95,   101,   102,   193,    95,    75,    76,    77,
     113,   100,    80,   115,   114,    98,   115,   114,   209,   210,
     211,    95,   147,   112,   157,   147,   100,    93,   100,    95,
     131,   181,   100,   116,   100,   231,    93,   114,    95,   227,
     114,   112,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     256,   194,    98,   188,   235,   310,    32,    95,   235,   235,
      73,    74,    75,    98,   207,    96,    51,    98,   114,   270,
       3,    47,    98,   254,    93,    95,    95,   254,   254,   114,
      93,    57,    95,   161,    97,   228,   112,    71,    72,   238,
      75,    76,    77,   270,    96,    80,    98,    96,    74,    98,
      93,   236,    95,   181,   236,    99,    96,   100,    98,    95,
      93,   317,    95,   319,   320,   100,   236,   315,   316,    96,
     252,    98,   242,    96,   305,    98,    82,    83,   305,   305,
     336,   306,   267,   216,   217,   218,   219,    96,    95,    98,
     109,   347,   348,   212,   213,   220,   221,   267,   325,   325,
     214,   215,   110,    76,    94,    96,    98,    43,   113,     7,
     112,   112,    96,    11,    12,   114,     3,   310,    16,     3,
       3,    19,    96,    21,    95,    94,   161,    94,    26,    27,
      96,   324,    96,    96,    32,    33,   306,    18,    36,   114,
     222,    39,    40,    41,    42,   223,   181,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,   225,   224,    19,    20,    21,    22,    23,    24,   226,
      26,    27,    75,    29,    70,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    63,   154,
     131,   252,   242,   181,    35,     7,    -1,    -1,    54,    11,
      12,    -1,    -1,    -1,    16,    -1,    -1,    19,    -1,    21,
      -1,    -1,    -1,    -1,    26,    27,    -1,    73,    74,    -1,
      32,    33,    -1,    -1,    36,    -1,    -1,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      -1,    -1,    -1,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,
     116,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,    -1,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,     3,     4,     5,     6,    -1,    -1,
       9,    10,    -1,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    73,    74,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    34,    -1,    -1,    37,    -1,
      -1,    -1,    -1,    95,    43,    -1,    -1,    99,   100,   101,
     102,   103,   104,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      -1,    -1,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    -1,    -1,     3,     4,
       5,     6,    -1,    -1,     9,    10,    -1,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    95,    22,    23,    24,
      99,   100,   101,   102,   103,   104,    31,    -1,    -1,    34,
      -1,    -1,    37,    -1,    -1,   114,   115,   116,    43,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,    54,
      -1,    -1,     7,     8,    -1,    -1,    11,    12,    -1,    -1,
      -1,    16,    -1,    -1,    19,    20,    21,    -1,    73,    74,
      -1,    26,    27,    34,    29,    -1,    -1,    32,    33,    -1,
      35,    36,    -1,    38,    39,    40,    41,    42,    -1,    -1,
      95,    -1,    47,    54,    99,   100,   101,   102,   103,   104,
       3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,   114,
     115,   116,    73,    74,    -1,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    10,    -1,    -1,    13,    14,    15,    -1,
      -1,    34,    -1,    -1,    95,    22,    23,    24,    99,   100,
     101,   102,   103,   104,    31,    -1,    -1,    34,    -1,    -1,
      37,    54,    -1,    -1,   115,   116,    43,    -1,    -1,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,
      34,    -1,    95,    -1,    -1,    -1,    99,   100,   101,   102,
     103,   104,     3,     4,     5,     6,    -1,    -1,    95,    -1,
      54,   114,    99,   100,   101,   102,   103,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,    73,
      74,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    -1,    54,    -1,    99,   100,   101,   102,   103,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   115,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    99,   100,
     101,   102,   103,   104,    -1,     7,    -1,    -1,    -1,    11,
      12,    -1,    -1,   114,    16,    -1,    -1,    19,    -1,    21,
      -1,    -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,
      32,    33,    -1,    -1,    36,    -1,    -1,    39,    40,    41,
      42,     7,     8,    -1,    -1,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,
      26,    27,    -1,    29,    -1,    -1,    32,    33,    -1,    35,
      36,    -1,    38,    39,    40,    41,    42,     7,     8,    -1,
      -1,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    19,
      20,    21,     3,     4,     5,     6,    26,    27,    -1,    29,
      -1,    -1,    32,    33,    -1,    35,    36,    -1,    38,    39,
      40,    41,    42,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,   113,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    -1,    -1,    34,     3,     4,     5,
       6,    -1,    -1,    -1,    -1,    54,    -1,     3,     4,     5,
       6,    -1,    -1,    94,    95,   115,    54,    -1,    99,   100,
     101,   102,   103,   104,    73,    74,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    34,     3,
       4,     5,     6,    -1,    -1,    -1,    95,    96,    54,    -1,
      99,   100,   101,   102,   103,   104,    94,    95,    54,    -1,
      -1,    99,   100,   101,   102,   103,   104,    73,    74,    -1,
      34,     3,     4,     5,     6,    -1,    -1,    73,    74,    -1,
      -1,     3,     4,     5,     6,    -1,    -1,    -1,    94,    95,
      54,    -1,    -1,    99,   100,   101,   102,   103,   104,    95,
      96,    -1,    34,    99,   100,   101,   102,   103,   104,    73,
      74,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    54,    -1,    -1,    99,   100,   101,   102,   103,
     104,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    -1,    -1,    -1,    99,   100,   101,
     102,   103,   104,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,   104,     0,    -1,    -1,     3,    -1,    -1,    -1,
       7,     8,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,
      -1,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,    26,
      27,    -1,    29,    -1,    -1,    32,    33,    -1,    35,    36,
      -1,    38,    39,    40,    41,    42,     3,    -1,    -1,    -1,
       7,     8,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,
      -1,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,    26,
      27,    -1,    29,    -1,    -1,    32,    33,    -1,    35,    36,
      -1,    38,    39,    40,    41,    42,    -1,    -1,     3,    -1,
      -1,    -1,     7,     8,    -1,    -1,    11,    12,    95,    -1,
      -1,    16,    -1,   100,    19,    20,    21,    -1,    -1,    -1,
      -1,    26,    27,    -1,    29,    -1,    -1,    32,    33,    -1,
      35,    36,    -1,    38,    39,    40,    41,    42,     7,     8,
      -1,    -1,    11,    12,    -1,    -1,    93,    16,    95,    96,
      19,    20,    21,   100,    -1,    -1,    -1,    26,    27,    -1,
      29,    -1,    -1,    32,    33,    -1,    35,    36,    -1,    38,
      39,    40,    41,    42,    -1,     3,    -1,    -1,    -1,     7,
       8,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,    -1,
      95,    19,    20,    21,    -1,   100,    -1,    -1,    26,    27,
      -1,    29,    -1,    -1,    32,    33,    -1,    35,    36,    -1,
      38,    39,    40,    41,    42,    -1,     7,     8,    -1,    -1,
      11,    12,    -1,    -1,    93,    16,    95,    96,    19,    20,
      21,   100,    -1,    -1,    -1,    26,    27,    -1,    29,    -1,
      -1,    32,    33,    -1,    35,    36,    -1,    38,    39,    40,
      41,    42,     7,     8,    -1,    -1,    11,    12,    -1,    -1,
      -1,    16,    -1,    -1,    19,    20,    21,    -1,    96,    -1,
      -1,    26,    27,    -1,    29,    -1,    -1,    32,    33,    -1,
      35,    36,    -1,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     7,     8,    11,    12,    16,    19,    20,    21,
      26,    27,    29,    32,    33,    35,    36,    38,    39,    40,
      41,    42,    95,   100,   140,   141,   144,   145,   146,   147,
     153,   156,   157,   158,   159,   179,   180,   181,     3,   115,
     157,   156,   159,   160,   114,   142,   143,   157,   141,   141,
       3,   115,   141,   115,   140,   141,   172,   173,    93,    95,
     158,     0,   180,   115,     3,   154,   155,    96,   156,   159,
      98,   114,   113,   172,   173,   115,   145,   148,   149,   150,
     156,     3,     4,     5,     6,     9,    10,    13,    14,    15,
      22,    23,    24,    31,    34,    37,    43,    54,    73,    74,
      95,    99,   100,   101,   102,   103,   104,   114,   116,   118,
     119,   120,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   138,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   157,   140,   172,
       3,    94,   122,   135,   139,     3,    96,   141,   161,   162,
     163,   164,   154,   113,    98,   116,   143,   115,   136,   168,
     172,   148,   150,   116,   149,   112,   151,   152,   157,   150,
     112,   114,   139,   114,   112,   170,    95,     3,    95,   114,
     138,    95,   122,    95,    95,   138,   122,   122,   150,   165,
      73,    74,    75,    93,    95,    97,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,   113,   137,   124,   100,
     105,   106,   101,   102,    71,    72,    78,    79,   107,   108,
      82,    83,    99,   109,   110,    76,    77,   111,    98,   114,
     116,   174,   116,   170,    94,    93,    95,   157,   159,   166,
     167,    96,    98,    96,    98,   116,   139,   155,   168,   169,
     116,   139,    98,   114,   112,   170,   112,   170,    43,   175,
     114,   138,   114,   165,   138,   138,    55,    95,   159,   166,
      96,     3,   138,    96,   121,   136,     3,   136,   124,   124,
     124,   125,   125,   126,   126,   127,   127,   127,   127,   128,
     128,   129,   130,   131,   132,   133,   138,   136,   116,    94,
     139,    96,   161,   166,   167,    93,    95,    47,   163,     3,
      98,   116,   152,   139,   170,    95,   175,    96,    96,    96,
      96,   124,    94,    96,    98,   112,    94,    96,    96,    94,
     139,    96,   161,   116,   168,   138,    96,   138,   170,   170,
     170,   136,   135,    94,    96,    96,   170,    96,    18,   114,
     170,   170
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,   117,   118,   118,   118,   118,   119,   119,   120,   120,
     120,   120,   120,   120,   120,   120,   121,   121,   122,   122,
     122,   122,   122,   122,   123,   123,   123,   123,   123,   123,
     124,   124,   125,   125,   125,   125,   126,   126,   126,   127,
     127,   127,   128,   128,   128,   128,   128,   129,   129,   129,
     130,   130,   131,   131,   132,   132,   133,   133,   134,   134,
     135,   135,   136,   136,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   138,   138,   139,   140,   140,
     141,   141,   141,   141,   141,   141,   142,   142,   143,   143,
     144,   144,   144,   144,   144,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   146,   146,   146,
     147,   147,   148,   148,   149,   150,   150,   150,   150,   151,
     151,   152,   152,   152,   153,   153,   153,   154,   154,   155,
     155,   156,   156,   157,   157,   158,   158,   158,   158,   158,
     158,   158,   159,   159,   159,   159,   160,   160,   161,   161,
     162,   162,   163,   163,   163,   164,   164,   165,   165,   166,
     166,   166,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   168,   168,   168,   169,   169,   170,   170,   170,   170,
     170,   170,   171,   171,   171,   172,   172,   172,   172,   173,
     173,   174,   174,   175,   175,   176,   176,   176,   177,   177,
     177,   177,   178,   178,   178,   178,   178,   179,   179,   180,
     180,   181,   181,   181,   181
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     1,     1,     1,     3,     1,     1,     1,     4,
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


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\"identifier\"",
  "\"i_const\"", "\"f_const\"", "\"sting_literal\"", "\"type name\"",
  "\"auto\"", "\"break\"", "\"case\"", "\"char\"", "\"const\"",
  "\"continue\"", "\"default\"", "\"do\"", "\"double\"", "\"long double\"",
  "\"else\"", "\"enum\"", "\"extern\"", "\"float\"", "\"for\"", "\"goto\"",
  "\"if\"", "\"inline\"", "\"int\"", "\"long\"", "\"long long\"",
  "\"register\"", "\"restrict\"", "\"return\"", "\"short\"", "\"signed\"",
  "\"sizeof\"", "\"static\"", "\"struct\"", "\"switch\"", "\"typedef\"",
  "\"union\"", "\"unsigned\"", "\"void\"", "\"volatile\"", "\"while\"",
  "\"bool\"", "\"complex\"", "\"imaginary\"", "\"ellipsis\"",
  "\"question\"", "\"semicolon\"", "\"ocurly\"", "\"ccurly\"", "\"comma\"",
  "\"colon\"", "\"oparen\"", "\"cparen\"", "\"obrace\"", "\"cbrace\"",
  "\"period\"", "\"tilde\"", "\"equal op\"", "\"right assign\"",
  "\"left assign\"", "\"add assign\"", "\"sub assign\"", "\"mul assign\"",
  "\"div assign\"", "\"mod assign\"", "\"and assign\"", "\"xor assign\"",
  "\"or assign\"", "\"right op\"", "\"left op\"", "\"inc op\"",
  "\"dec op\"", "\"ptr op\"", "\"and op\"", "\"or op\"", "\"ge op\"",
  "\"le op\"", "\"greater op\"", "\"less op\"", "\"eq op\"", "\"ne op\"",
  "\"not op\"", "\"xor op\"", "\"bit and\"", "\"bit or\"", "\"minus op\"",
  "\"plus op\"", "\"times op\"", "\"div op\"", "\"mod op\"", "'['", "']'",
  "'('", "')'", "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'",
  "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'",
  "'{'", "'}'", "$accept", "primary_expression", "constant",
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
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   160,   160,   161,   162,   163,   167,   168,   171,   172,
     173,   174,   175,   176,   177,   178,   182,   183,   187,   188,
     189,   190,   191,   192,   196,   197,   198,   199,   200,   201,
     205,   206,   210,   211,   212,   213,   217,   218,   219,   223,
     224,   225,   229,   230,   231,   232,   233,   237,   238,   239,
     243,   244,   248,   249,   253,   254,   258,   259,   263,   264,
     268,   269,   273,   274,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   292,   293,   297,   301,   302,
     306,   307,   308,   309,   310,   311,   315,   316,   320,   321,
     325,   326,   327,   328,   329,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   348,   349,   350,
     354,   355,   359,   360,   364,   368,   369,   370,   371,   375,
     376,   380,   381,   382,   386,   387,   388,   392,   393,   397,
     398,   402,   403,   407,   408,   412,   413,   414,   415,   416,
     417,   418,   422,   423,   424,   425,   429,   430,   435,   436,
     440,   441,   445,   446,   447,   451,   452,   456,   457,   461,
     462,   463,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   479,   480,   481,   485,   486,   490,   491,   492,   493,
     494,   495,   499,   500,   501,   505,   506,   507,   508,   512,
     513,   517,   518,   522,   523,   527,   528,   529,   533,   534,
     535,   536,   540,   541,   542,   543,   544,   548,   549,   553,
     554,   558,   559,   560,   561
  };

  void
   Parser ::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
   Parser ::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 9 "parser.y"
} //  WadeSpace 
#line 2030 "parser.cpp"

#line 564 "parser.y"


// Bison expects us to provide implementation - otherwise linker complains
void WadeSpace::Parser::error(const location &loc , const std::string &message) {
        
        // Location should be initialized inside scanner action, but is not in this example.
        // Let's grab location directly from driver class.
    // cout << "Error: " << message << endl << "Location: " << loc << endl;
    
        cout << "Error: " << message << endl << "Error location: " << driver.location() << endl;
}
