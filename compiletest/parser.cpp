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
      case symbol_kind::S_constant: // constant
        value.YY_MOVE_OR_COPY< Constant > (YY_MOVE (that.value));
        break;

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
      case symbol_kind::S_constant: // constant
        value.move< Constant > (YY_MOVE (that.value));
        break;

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
      case symbol_kind::S_constant: // constant
        value.copy< Constant > (that.value);
        break;

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
      case symbol_kind::S_constant: // constant
        value.move< Constant > (that.value);
        break;

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
      case symbol_kind::S_constant: // constant
        yylhs.value.emplace< Constant > ();
        break;

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
  case 2: // primary_expression: "identifier"
#line 162 "parser.y"
                 { cout << "IDENTIFIER REDUCE to primary_expression" << endl; }
#line 1069 "parser.cpp"
    break;

  case 3: // primary_expression: constant
#line 163 "parser.y"
               { cout << "constant REDUCE to primary_expression" << endl; }
#line 1075 "parser.cpp"
    break;

  case 4: // primary_expression: "oparen" expression "cparen"
#line 164 "parser.y"
                                { cout << "(expression) REDUCE to primary_expression" << endl; }
#line 1081 "parser.cpp"
    break;

  case 5: // constant: "f_const"
#line 168 "parser.y"
              {
                 long double &id = yystack_[0].value.as < long double > ();
                 cout << "<EXP> F_CONST REDUCE to constant " << id << endl;
                 yylhs.value.as< Constant > () = Constant(id);
              }
#line 1091 "parser.cpp"
    break;

  case 6: // constant: "i_const"
#line 173 "parser.y"
              {
                 std::uint64_t &id = yystack_[0].value.as < uint64_t > ();
                 cout << "<EXP> I_CONST REDUCE to constant " << id << endl;
                 yylhs.value.as< Constant > () = Constant(id);
              }
#line 1101 "parser.cpp"
    break;

  case 7: // constant: "sting_literal"
#line 178 "parser.y"
                      {
                 std::string &id = yystack_[0].value.as < std::string > ();
                 cout << "<EXP> STRING_LITERAL REDUCE to constant  " << id << endl;
                 yylhs.value.as< Constant > () = Constant(id);
              }
#line 1111 "parser.cpp"
    break;

  case 8: // postfix_expression: primary_expression
#line 185 "parser.y"
                                                                   { cout << "primary_expression REDUCE to postfix_expression" << endl; }
#line 1117 "parser.cpp"
    break;

  case 9: // postfix_expression: postfix_expression "obrace" expression "cbrace"
#line 186 "parser.y"
                                                                   { cout << "postfix_expression OBRACE expression CBRACE REDUCE to postfix_expression" << endl; }
#line 1123 "parser.cpp"
    break;

  case 10: // postfix_expression: postfix_expression "oparen" "cparen"
#line 187 "parser.y"
                                                                   { cout << "postfix_expression OPAREN CPAREN REDUCE to postfix_expression" << endl; }
#line 1129 "parser.cpp"
    break;

  case 11: // postfix_expression: postfix_expression "oparen" argument_expression_list "cparen"
#line 188 "parser.y"
                                                                   { cout << "postfix_expression OPAREN argument_expression_list CPAREN REDUCE to postfix_expression" << endl; }
#line 1135 "parser.cpp"
    break;

  case 12: // postfix_expression: postfix_expression "period" "identifier"
#line 189 "parser.y"
                                                                   { cout << "postfix_expression PERIOD_OP IDENTIFIER REDUCE to postfix_expression" << endl; }
#line 1141 "parser.cpp"
    break;

  case 13: // postfix_expression: postfix_expression "ptr op" "identifier"
#line 190 "parser.y"
                                                                   { cout << "postfix_expression PTR_OP IDENTIFIER REDUCE to postfix_expression" << endl; }
#line 1147 "parser.cpp"
    break;

  case 14: // postfix_expression: postfix_expression "inc op"
#line 191 "parser.y"
                                                                   { cout << "postfix_expression INC_OP REDUCE to postfix_expression" << endl; }
#line 1153 "parser.cpp"
    break;

  case 15: // postfix_expression: postfix_expression "dec op"
#line 192 "parser.y"
                                                                   { cout << "postfix_expression DEC_OP REDUCE to postfix_expression" << endl; }
#line 1159 "parser.cpp"
    break;

  case 16: // postfix_expression: "oparen" type_name "cparen" "ocurly" initializer_list "ccurly"
#line 193 "parser.y"
                                                                   { cout << "OPAREN type_name CPAREN_OP OCURLY_OP initializer_list CCURLY REDUCE to postfix_expression" << endl; }
#line 1165 "parser.cpp"
    break;

  case 17: // postfix_expression: "oparen" type_name "cparen" "ocurly" initializer_list "comma" "ccurly"
#line 194 "parser.y"
                                                                   { cout << "OPAREN type_name CPAREN_OP OCURLY_OP initializer_list COMMA CCURLY REDUCE to postfix_expression" << endl; }
#line 1171 "parser.cpp"
    break;


#line 1175 "parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -214;

  const signed char  Parser ::yytable_ninf_ = -1;

  const short
   Parser ::yypact_[] =
  {
    1466,  -214,  -214,  -214,  -214,  -214,  -214,     9,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,    38,     8,  -214,    29,  1625,  1625,  -214,    12,
    -214,  1625,  1116,   -39,    18,  1426,  -214,  -214,   -60,    62,
     -14,  -214,  -214,     8,  -214,   -24,  -214,  1072,  -214,  -214,
      -8,  1661,  -214,   497,  -214,    29,  -214,  1116,  1506,   269,
     -39,  -214,  -214,    62,   -22,   -34,  -214,  -214,  -214,  -214,
      38,  -214,   830,  -214,  1116,  1661,  1661,   546,  -214,    36,
    1661,    41,  -214,  -214,  -214,    45,  1272,    48,    88,   865,
     115,   201,   119,   906,  1283,   146,   151,  1159,  1324,  1324,
    1661,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,    16,   270,  1272,  -214,   -20,   -56,   118,    50,   110,
     124,   144,   147,   183,   -44,  -214,  -214,    90,  -214,  -214,
    -214,   608,   719,  -214,  -214,  -214,  -214,   150,  -214,  -214,
    -214,  -214,    25,   166,   170,  -214,    53,  -214,  -214,  -214,
    -214,   152,   -13,  1272,    62,  -214,  -214,   830,  -214,  -214,
    -214,   763,  -214,  -214,  -214,  1272,   101,  -214,   157,  -214,
     865,  -214,   160,  -214,   865,   227,   940,   168,  1272,  -214,
     106,  1661,  -214,  1272,  1272,   -32,   -21,   225,  -214,  -214,
     186,  1211,  1272,   279,  -214,  -214,   280,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  1272,  -214,
    1272,  1272,  1272,  1272,  1272,  1272,  1272,  1272,  1272,  1272,
    1272,  1272,  1272,  1272,  1272,  1272,  1272,  1272,  1272,  1272,
    -214,  -214,   754,  -214,  -214,   455,   323,  -214,    13,  -214,
      93,  -214,  1583,   282,  -214,  -214,  -214,  -214,  -214,  -214,
      95,  -214,  -214,    36,  -214,  1272,  -214,   865,  -214,   193,
     940,  -214,    56,  -214,   197,   107,   121,  -214,  1036,    97,
    -214,   238,  1272,  -214,   -15,  -214,   -33,  -214,  -214,  -214,
    -214,  -214,  -214,   -20,   -20,   -56,   -56,   118,   118,   118,
     118,    50,    50,   110,   124,   144,   147,   183,   -63,  -214,
    -214,  -214,   198,   200,  -214,   181,    93,  1545,   355,  -214,
    -214,  -214,   599,  -214,  -214,  -214,  -214,  1272,  1200,   865,
    -214,   865,   865,   830,  -214,  -214,  1272,  -214,  1272,  -214,
    -214,  -214,  -214,   202,  -214,   184,  -214,  -214,   126,   865,
     135,   283,  -214,  -214,    92,  -214,  -214,  -214,  -214,   187,
    -214,   865,   865,  -214,   249,   830,  -214,  -214,  -214,  -214
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
       0,   137,   108,    95,    98,   133,   103,     0,    93,   102,
     100,   101,    96,    99,   104,    94,   112,    92,   113,   105,
      97,   134,     0,   144,   212,     0,    82,    84,   106,     0,
     107,    86,     0,   136,     0,     0,   209,   211,   128,     0,
       0,   148,   146,   145,    80,     0,    88,    90,    83,    85,
     111,     0,    87,     0,   191,     0,   216,     0,     0,     0,
     135,     1,   210,     0,   131,     0,   129,   138,   149,   147,
       0,    81,     0,   214,     0,     0,   118,     0,   114,     0,
     120,     2,     6,     5,     7,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,    27,    28,    29,    30,    31,   195,   187,     8,
       3,    20,    32,     0,    34,    38,    41,    44,    49,    52,
      54,    56,    58,    60,    62,    64,    77,     0,   193,   178,
     179,     0,     0,   180,   181,   182,   183,    90,   192,   215,
     157,   143,   156,     0,   150,   152,     0,     2,   140,    32,
      79,     0,     0,     0,     0,   126,    89,     0,   173,    91,
     213,     0,   117,   110,   115,     0,     0,   121,   123,   119,
       0,   206,     0,   205,     0,     0,     0,     0,     0,   207,
       0,     0,    24,     0,     0,     0,   159,     0,    21,    22,
       0,     0,     0,     0,    14,    15,     0,    73,    72,    70,
      71,    67,    68,    69,    74,    75,    76,    66,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     196,   189,     0,   188,   194,     0,     0,   154,   161,   155,
     162,   141,     0,     0,   142,   139,   127,   132,   130,   176,
       0,   109,   124,     0,   116,     0,   184,     0,   186,     0,
       0,   204,     0,   208,     0,     0,     0,     4,     0,   161,
     160,     0,     0,    10,     0,    18,     0,    12,    13,    65,
      35,    36,    37,    39,    40,    43,    42,    48,    47,    45,
      46,    50,    51,    53,    55,    57,    59,    61,     0,    78,
     190,   169,     0,     0,   165,     0,   163,     0,     0,   151,
     153,   158,     0,   174,   122,   125,   185,     0,     0,     0,
      25,     0,     0,     0,    33,    11,     0,     9,     0,   170,
     164,   166,   171,     0,   167,     0,   175,   177,     0,     0,
       0,   197,   199,   200,     0,    19,    63,   172,   168,     0,
     202,     0,     0,    16,     0,     0,   201,   203,   198,    17
  };

  const short
   Parser ::yypgoto_[] =
  {
    -214,  -214,  -214,  -214,  -214,   -50,  -214,   -94,    20,    23,
       7,    27,    79,    80,    81,    82,    78,  -214,   -57,   -71,
    -214,   -86,   -52,    10,     0,  -214,   239,  -214,    34,  -214,
    -214,   235,   -59,   -29,  -214,    59,  -214,   250,   161,   214,
     -17,   -28,    -6,  -214,   -54,  -214,    74,  -214,   -87,  -120,
    -213,   -69,    -5,   -75,  -214,   149,   100,   188,  -122,  -214,
    -214,  -214,  -214,   285,  -214
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,   109,   110,   111,   274,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     208,   127,   151,    54,    55,    45,    46,    26,    27,    28,
      29,    77,    78,    79,   166,   167,    30,    65,    66,    31,
      32,    33,    34,    43,   302,   144,   145,   146,   187,   303,
     240,   249,   250,   128,   129,   130,    57,   132,   133,   134,
     135,   136,    35,    36,    37
  };

  const short
   Parser ::yytable_[] =
  {
      25,   158,   150,   159,   143,    40,    60,   180,    47,   149,
      24,   185,    38,   190,   175,    50,     1,    42,   164,   209,
       5,     1,   239,   267,   327,   306,    48,    49,     1,   150,
     229,    52,     1,   227,   172,    25,   149,    69,   137,     1,
     325,     1,   213,   214,   182,    24,   328,   162,   188,   189,
      21,   169,    63,   137,   260,    58,   306,   234,   142,   154,
     229,   229,   168,   149,   228,    64,   270,   138,   186,    70,
     191,   186,   192,   268,   193,    59,    23,   210,   326,   155,
     154,    67,   211,   212,   138,    76,   158,    71,   153,   194,
     195,   196,   262,   236,   264,   256,   150,   265,   266,   258,
     246,   247,   164,   149,    75,    23,   276,   235,   150,    76,
      76,    76,    22,   252,    76,   149,   280,   281,   282,   235,
     275,    39,    23,    22,    51,   237,    23,   236,   217,   218,
      22,    76,    22,    23,    76,    23,   238,   279,   318,   236,
      44,   138,   298,   353,   354,   165,   243,    74,   244,   229,
     170,   319,   186,   131,   219,   220,   171,   234,   299,   173,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   324,   150,
     269,    56,   316,   229,   305,   355,   149,   307,   312,   215,
     216,   268,   221,   222,   253,    76,    73,   174,   150,   229,
     229,   230,   321,   315,   177,   149,   139,   308,   313,   176,
      60,   236,   254,   178,   229,    76,   322,   263,    40,   229,
     223,   349,   149,   160,   287,   288,   289,   290,   229,   238,
     351,   338,   340,   283,   284,   142,   168,    41,   285,   286,
     183,   158,   142,   337,   341,   184,   342,   343,   291,   292,
     224,   150,   158,   333,   225,   345,   335,    68,   149,   226,
      72,   241,   269,   242,   350,    80,   255,   245,   142,   257,
     259,   346,   147,    82,    83,    84,   357,   358,   149,   261,
     271,   272,   277,   278,   158,   311,   337,   317,   323,    80,
      80,    80,   320,   329,    80,   330,   331,   347,   356,   348,
     359,   352,   293,    94,   294,   297,   295,   142,   296,   156,
     161,    80,   314,   152,    80,   248,   310,     0,   344,   232,
      62,     0,     0,    97,     0,     0,   147,    82,    83,    84,
       0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,     0,    98,    99,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,   147,    82,
      83,    84,     0,   100,     0,   101,   102,   103,   104,   105,
     106,     0,     0,     0,     0,    80,     0,    97,     0,     0,
     207,     0,     0,     0,   148,     0,     0,     0,     0,    94,
       0,     0,     0,     0,     0,    80,    98,    99,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
       0,     0,     0,     0,     0,     0,     0,   100,     0,   101,
     102,   103,   104,   105,   106,     0,     0,     0,    98,    99,
       0,     0,     0,     0,     0,     0,     0,     0,   304,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
       0,   101,   102,   103,   104,   105,   106,     0,     1,     0,
       0,     0,     2,     3,     0,     0,     4,     5,     0,     0,
     334,     6,     0,     0,     7,     8,     9,     0,     0,     0,
       0,    10,    11,     0,    12,     0,     0,    13,    14,     0,
      15,    16,     0,    17,    18,    19,    20,    21,     0,     0,
      81,    82,    83,    84,     2,     3,    85,    86,     4,     5,
      87,    88,    89,     6,     0,     0,     7,     8,     9,    90,
      91,    92,     0,    10,    11,     0,    12,     0,    93,    13,
      14,    94,    15,    16,    95,    17,    18,    19,    20,    21,
      96,     0,     0,     0,     0,     0,     0,     0,     0,   235,
     301,    97,    23,     2,     0,     0,     0,     4,     5,     0,
       0,     0,     6,     0,     0,     7,     0,     9,     0,   236,
      98,    99,    10,    11,     0,     0,     0,     0,    13,    14,
       0,     0,    16,     0,     0,    18,    19,    20,    21,     0,
       0,   100,     0,   101,   102,   103,   104,   105,   106,     0,
       0,     0,   147,    82,    83,    84,     0,     0,   107,    53,
     108,    81,    82,    83,    84,     2,     3,    85,    86,     4,
       5,    87,    88,    89,     6,     0,     0,     7,     8,     9,
      90,    91,    92,    94,    10,    11,     0,    12,     0,    93,
      13,    14,    94,    15,    16,    95,    17,    18,    19,    20,
      21,    96,     0,    97,     0,     0,     0,     0,     0,   163,
       0,     0,    97,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,    99,     0,     0,     0,     0,     0,     0,
       0,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,     0,   101,   102,   103,   104,   105,
     106,     0,   100,     0,   101,   102,   103,   104,   105,   106,
       0,   157,   336,     0,     0,     0,     0,     0,     0,   107,
      53,   231,    81,    82,    83,    84,     0,     0,    85,    86,
       0,     0,    87,    88,    89,     0,     0,     0,     0,     0,
       0,    90,    91,    92,     0,     0,     0,     0,     0,     0,
      93,     0,     0,    94,     0,     0,    95,    81,    82,    83,
      84,     0,    96,    85,    86,     0,     0,    87,    88,    89,
       2,     0,     0,    97,     4,     5,    90,    91,    92,     6,
       0,     0,     7,     0,     9,    93,     0,     0,    94,    10,
      11,    95,    98,    99,     0,    13,    14,    96,     0,    16,
       0,     0,    18,    19,    20,    21,     0,     0,    97,     0,
       0,     0,     0,   100,     0,   101,   102,   103,   104,   105,
     106,     0,     0,     0,     0,     0,     0,    98,    99,     0,
     107,    53,   233,   147,    82,    83,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   100,     0,
     101,   102,   103,   104,   105,   106,     0,     0,     0,     0,
       0,     0,     0,     0,    94,   107,    53,   300,    81,    82,
      83,    84,     0,     0,    85,    86,   251,     0,    87,    88,
      89,     0,     0,     0,    97,     0,     0,    90,    91,    92,
       0,     0,     0,     0,     0,     0,    93,     0,     0,    94,
       0,     0,    95,    98,    99,     0,     0,     0,    96,   147,
      82,    83,    84,     0,     0,     0,     0,     0,     0,    97,
       0,     0,     0,     0,   100,     0,   101,   102,   103,   104,
     105,   106,     0,     0,     0,     0,     0,     0,    98,    99,
      94,     0,   157,   147,    82,    83,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
      97,   101,   102,   103,   104,   105,   106,     0,     0,     0,
       0,     0,     0,     0,    94,     0,   107,    53,     0,    98,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,     0,     0,     0,     0,     0,
     100,     0,   101,   102,   103,   104,   105,   106,     0,     0,
       0,     0,     0,    98,    99,     0,     0,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,     0,   101,   102,   103,   104,
     105,   106,     0,     2,     3,     0,     0,     4,     5,     0,
       0,   107,     6,     0,     0,     7,     8,     9,     0,     0,
       0,     0,    10,    11,     0,    12,     0,     0,    13,    14,
       0,    15,    16,     0,    17,    18,    19,    20,    21,     2,
       3,     0,     0,     4,     5,     0,     0,     0,     6,     0,
       0,     7,     8,     9,     0,     0,     0,     0,    10,    11,
       0,    12,     0,     0,    13,    14,     0,    15,    16,     0,
      17,    18,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     0,     4,     5,     0,
     268,   301,     6,    23,     0,     7,     8,     9,     0,     0,
       0,     0,    10,    11,     0,    12,     0,     0,    13,    14,
     236,    15,    16,     0,    17,    18,    19,    20,    21,     0,
       0,     0,   147,    82,    83,    84,     2,     0,     0,     0,
       4,     5,     0,     0,     0,     6,     0,     0,     7,     0,
       9,     0,    72,     0,    53,    10,    11,     0,     0,     0,
       0,    13,    14,    94,     0,    16,     0,     0,    18,    19,
      20,    21,     0,   147,    82,    83,    84,     0,     0,     0,
       0,     0,     0,    97,   147,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,     0,
       0,     0,    98,    99,    94,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,     0,     0,     0,     0,
       0,     0,     0,   100,    97,   101,   102,   103,   104,   105,
     106,     0,     0,     0,     0,    97,   273,     0,     0,     0,
       0,     0,     0,    98,    99,   147,    82,    83,    84,     0,
       0,     0,     0,     0,    98,    99,   147,    82,    83,    84,
       0,     0,     0,     0,   100,   339,   101,   102,   103,   104,
     105,   106,     0,     0,     0,   100,    94,   101,   102,   103,
     104,   105,   106,     0,     0,     0,     0,    94,     0,     0,
       0,     0,     0,     0,     0,     0,    97,   147,    82,    83,
      84,     0,     0,     0,     0,     0,     0,    97,     0,     0,
       0,     0,     0,     0,     0,    98,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    98,    99,    94,     0,
       0,     0,     0,     0,     0,     0,   100,     0,   101,   102,
     103,   104,   105,   106,     0,     0,     0,   181,    97,   101,
     102,   103,   104,   105,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,    61,     0,     0,     1,
       0,     0,     0,     2,     3,     0,     0,     4,     5,     0,
       0,     0,     6,     0,     0,     7,     8,     9,     0,     0,
       0,     0,    10,    11,     0,    12,     0,     0,    13,    14,
       0,    15,    16,     0,    17,    18,    19,    20,    21,     1,
       0,     0,     0,     2,     3,     0,     0,     4,     5,     0,
       0,     0,     6,     0,     0,     7,     8,     9,     0,     0,
       0,     0,    10,    11,     0,    12,     0,     0,    13,    14,
       0,    15,    16,     0,    17,    18,    19,    20,    21,   140,
       0,     0,     0,     2,     3,     0,     0,     4,     5,     0,
      22,     0,     6,    23,     0,     7,     8,     9,     0,     0,
       0,     0,    10,    11,     0,    12,     0,     0,    13,    14,
       0,    15,    16,     0,    17,    18,    19,    20,    21,     0,
       0,     0,     2,     3,     0,     0,     4,     5,     0,     0,
      22,     6,     0,    23,     7,     8,     9,     0,     0,     0,
       0,    10,    11,     0,    12,     0,     0,    13,    14,     0,
      15,    16,     0,    17,    18,    19,    20,    21,     0,     0,
       2,     3,     0,     0,     4,     5,     0,     0,     0,     6,
       0,   141,     7,     8,     9,     0,     0,     0,     0,    10,
      11,     0,    12,     0,     0,    13,    14,     0,    15,    16,
       0,    17,    18,    19,    20,    21,     0,     0,     0,     0,
     309,     0,     2,     3,     0,     0,     4,     5,     0,     0,
     332,     6,     0,     0,     7,     8,     9,     0,     0,     0,
       0,    10,    11,     0,    12,     0,     0,    13,    14,     0,
      15,    16,     0,    17,    18,    19,    20,    21,     2,     0,
       0,     0,     4,     5,     0,     0,     0,     6,     0,     0,
       7,     0,     9,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    13,    14,     0,     0,    16,     0,     0,
      18,    19,    20,    21
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    72,    59,    72,    58,    22,    34,    93,    25,    59,
       0,    97,     3,   100,    89,     3,     3,    23,    77,   113,
      12,     3,   142,    55,    57,   238,    26,    27,     3,    86,
      93,    31,     3,    77,    86,    35,    86,    43,    55,     3,
      55,     3,    98,    99,    94,    35,   109,    76,    98,    99,
      42,    80,   112,    70,   176,    94,   269,   132,    58,    93,
      93,    93,    79,   113,   108,     3,   186,    57,    97,    93,
      54,   100,    56,    94,    58,   114,    97,    97,    93,   113,
      93,    95,   102,   103,    74,    51,   157,   111,   110,    73,
      74,    75,   178,   114,   181,   170,   153,   183,   184,   174,
     113,   153,   161,   153,   112,    97,   192,    94,   165,    75,
      76,    77,    94,   165,    80,   165,   210,   211,   212,    94,
     191,   112,    97,    94,   112,   142,    97,   114,    78,    79,
      94,    97,    94,    97,   100,    97,   142,   208,   260,   114,
     111,   131,   228,    51,    52,   109,    93,    47,    95,    93,
     109,    95,   181,    53,   104,   105,   111,   232,   229,   111,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   272,   236,
     186,    32,   257,    93,   236,    93,   236,    94,    93,    71,
      72,    94,    82,    83,    93,   161,    47,   109,   255,    93,
      93,   111,    95,   255,     3,   255,    57,   114,   113,    94,
     238,   114,   111,    94,    93,   181,    95,   111,   235,    93,
      96,    95,   272,    74,   217,   218,   219,   220,    93,   235,
      95,   317,   318,   213,   214,   235,   253,    23,   215,   216,
      94,   312,   242,   312,   319,    94,   321,   322,   221,   222,
     106,   308,   323,   307,   107,   326,   308,    43,   308,    76,
     110,    95,   268,    93,   339,    51,   109,   115,   268,   109,
      43,   328,     3,     4,     5,     6,   351,   352,   328,   111,
      55,    95,     3,     3,   355,     3,   355,    94,    50,    75,
      76,    77,    95,    95,    80,    95,   115,    95,   111,   115,
      51,    18,   223,    34,   224,   227,   225,   307,   226,    70,
      75,    97,   253,    63,   100,   154,   242,    -1,   323,   131,
      35,    -1,    -1,    54,    -1,    -1,     3,     4,     5,     6,
      -1,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    -1,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,     3,     4,
       5,     6,    -1,    94,    -1,    96,    97,    98,    99,   100,
     101,    -1,    -1,    -1,    -1,   161,    -1,    54,    -1,    -1,
     110,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    -1,   181,    73,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    96,
      97,    98,    99,   100,   101,    -1,    -1,    -1,    73,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      -1,    96,    97,    98,    99,   100,   101,    -1,     3,    -1,
      -1,    -1,     7,     8,    -1,    -1,    11,    12,    -1,    -1,
     115,    16,    -1,    -1,    19,    20,    21,    -1,    -1,    -1,
      -1,    26,    27,    -1,    29,    -1,    -1,    32,    33,    -1,
      35,    36,    -1,    38,    39,    40,    41,    42,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    -1,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    54,    97,     7,    -1,    -1,    -1,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    19,    -1,    21,    -1,   114,
      73,    74,    26,    27,    -1,    -1,    -1,    -1,    32,    33,
      -1,    -1,    36,    -1,    -1,    39,    40,    41,    42,    -1,
      -1,    94,    -1,    96,    97,    98,    99,   100,   101,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,    -1,   111,   112,
     113,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    19,    20,    21,
      22,    23,    24,    34,    26,    27,    -1,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    54,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    96,    97,    98,    99,   100,
     101,    -1,    94,    -1,    96,    97,    98,    99,   100,   101,
      -1,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,     3,     4,     5,     6,    -1,    -1,     9,    10,
      -1,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    34,    -1,    -1,    37,     3,     4,     5,
       6,    -1,    43,     9,    10,    -1,    -1,    13,    14,    15,
       7,    -1,    -1,    54,    11,    12,    22,    23,    24,    16,
      -1,    -1,    19,    -1,    21,    31,    -1,    -1,    34,    26,
      27,    37,    73,    74,    -1,    32,    33,    43,    -1,    36,
      -1,    -1,    39,    40,    41,    42,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    94,    -1,    96,    97,    98,    99,   100,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,
     111,   112,   113,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,
      96,    97,    98,    99,   100,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,   111,   112,   113,     3,     4,
       5,     6,    -1,    -1,     9,    10,   113,    -1,    13,    14,
      15,    -1,    -1,    -1,    54,    -1,    -1,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,
      -1,    -1,    37,    73,    74,    -1,    -1,    -1,    43,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    94,    -1,    96,    97,    98,    99,
     100,   101,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,
      34,    -1,   112,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      54,    96,    97,    98,    99,   100,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,   111,   112,    -1,    73,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      94,    -1,    96,    97,    98,    99,   100,   101,    -1,    -1,
      -1,    -1,    -1,    73,    74,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    -1,    96,    97,    98,    99,
     100,   101,    -1,     7,     8,    -1,    -1,    11,    12,    -1,
      -1,   111,    16,    -1,    -1,    19,    20,    21,    -1,    -1,
      -1,    -1,    26,    27,    -1,    29,    -1,    -1,    32,    33,
      -1,    35,    36,    -1,    38,    39,    40,    41,    42,     7,
       8,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,    -1,
      -1,    19,    20,    21,    -1,    -1,    -1,    -1,    26,    27,
      -1,    29,    -1,    -1,    32,    33,    -1,    35,    36,    -1,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,     8,    -1,    -1,    11,    12,    -1,
      94,    95,    16,    97,    -1,    19,    20,    21,    -1,    -1,
      -1,    -1,    26,    27,    -1,    29,    -1,    -1,    32,    33,
     114,    35,    36,    -1,    38,    39,    40,    41,    42,    -1,
      -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      11,    12,    -1,    -1,    -1,    16,    -1,    -1,    19,    -1,
      21,    -1,   110,    -1,   112,    26,    27,    -1,    -1,    -1,
      -1,    32,    33,    34,    -1,    36,    -1,    -1,    39,    40,
      41,    42,    -1,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    54,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,
      -1,    -1,    73,    74,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    54,    96,    97,    98,    99,   100,
     101,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,     3,     4,     5,     6,    -1,
      -1,    -1,    -1,    -1,    73,    74,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,    -1,    -1,    94,    34,    96,    97,    98,
      99,   100,   101,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,     3,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    96,    97,
      98,    99,   100,   101,    -1,    -1,    -1,    94,    54,    96,
      97,    98,    99,   100,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    97,    98,    99,   100,   101,     0,    -1,    -1,     3,
      -1,    -1,    -1,     7,     8,    -1,    -1,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    19,    20,    21,    -1,    -1,
      -1,    -1,    26,    27,    -1,    29,    -1,    -1,    32,    33,
      -1,    35,    36,    -1,    38,    39,    40,    41,    42,     3,
      -1,    -1,    -1,     7,     8,    -1,    -1,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    19,    20,    21,    -1,    -1,
      -1,    -1,    26,    27,    -1,    29,    -1,    -1,    32,    33,
      -1,    35,    36,    -1,    38,    39,    40,    41,    42,     3,
      -1,    -1,    -1,     7,     8,    -1,    -1,    11,    12,    -1,
      94,    -1,    16,    97,    -1,    19,    20,    21,    -1,    -1,
      -1,    -1,    26,    27,    -1,    29,    -1,    -1,    32,    33,
      -1,    35,    36,    -1,    38,    39,    40,    41,    42,    -1,
      -1,    -1,     7,     8,    -1,    -1,    11,    12,    -1,    -1,
      94,    16,    -1,    97,    19,    20,    21,    -1,    -1,    -1,
      -1,    26,    27,    -1,    29,    -1,    -1,    32,    33,    -1,
      35,    36,    -1,    38,    39,    40,    41,    42,    -1,    -1,
       7,     8,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,
      -1,    95,    19,    20,    21,    -1,    -1,    -1,    -1,    26,
      27,    -1,    29,    -1,    -1,    32,    33,    -1,    35,    36,
      -1,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      47,    -1,     7,     8,    -1,    -1,    11,    12,    -1,    -1,
      95,    16,    -1,    -1,    19,    20,    21,    -1,    -1,    -1,
      -1,    26,    27,    -1,    29,    -1,    -1,    32,    33,    -1,
      35,    36,    -1,    38,    39,    40,    41,    42,     7,    -1,
      -1,    -1,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
      19,    -1,    21,    -1,    -1,    -1,    -1,    26,    27,    -1,
      -1,    -1,    -1,    32,    33,    -1,    -1,    36,    -1,    -1,
      39,    40,    41,    42
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     7,     8,    11,    12,    16,    19,    20,    21,
      26,    27,    29,    32,    33,    35,    36,    38,    39,    40,
      41,    42,    94,    97,   139,   140,   143,   144,   145,   146,
     152,   155,   156,   157,   158,   178,   179,   180,     3,   112,
     156,   155,   158,   159,   111,   141,   142,   156,   140,   140,
       3,   112,   140,   112,   139,   140,   171,   172,    94,   114,
     157,     0,   179,   112,     3,   153,   154,    95,   155,   158,
      93,   111,   110,   171,   172,   112,   144,   147,   148,   149,
     155,     3,     4,     5,     6,     9,    10,    13,    14,    15,
      22,    23,    24,    31,    34,    37,    43,    54,    73,    74,
      94,    96,    97,    98,    99,   100,   101,   111,   113,   117,
     118,   119,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   137,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   156,   139,   171,
       3,    95,   140,   160,   161,   162,   163,     3,   115,   121,
     134,   138,   153,   110,    93,   113,   142,   112,   135,   167,
     171,   147,   149,   113,   148,   109,   150,   151,   156,   149,
     109,   111,   138,   111,   109,   169,    94,     3,    94,   111,
     137,    94,   121,    94,    94,   137,   149,   164,   121,   121,
     164,    54,    56,    58,    73,    74,    75,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,   110,   136,   123,
      97,   102,   103,    98,    99,    71,    72,    78,    79,   104,
     105,    82,    83,    96,   106,   107,    76,    77,   108,    93,
     111,   113,   173,   113,   169,    94,   114,   156,   158,   165,
     166,    95,    93,    93,    95,   115,   113,   138,   154,   167,
     168,   113,   138,    93,   111,   109,   169,   109,   169,    43,
     174,   111,   137,   111,   164,   137,   137,    55,    94,   158,
     165,    55,    95,    55,   120,   135,   137,     3,     3,   135,
     123,   123,   123,   124,   124,   125,   125,   126,   126,   126,
     126,   127,   127,   128,   129,   130,   131,   132,   137,   135,
     113,    95,   160,   165,   115,   138,   166,    94,   114,    47,
     162,     3,    93,   113,   151,   138,   169,    94,   174,    95,
      95,    95,    95,    50,   123,    55,    93,    57,   109,    95,
      95,   115,    95,   160,   115,   138,   113,   167,   137,    95,
     137,   169,   169,   169,   168,   135,   134,    95,   115,    95,
     169,    95,    18,    51,    52,    93,   111,   169,   169,    51
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,   116,   117,   117,   117,   118,   118,   118,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   120,   120,
     121,   121,   121,   121,   121,   121,   122,   122,   122,   122,
     122,   122,   123,   123,   124,   124,   124,   124,   125,   125,
     125,   126,   126,   126,   127,   127,   127,   127,   127,   128,
     128,   128,   129,   129,   130,   130,   131,   131,   132,   132,
     133,   133,   134,   134,   135,   135,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   137,   137,   138,
     139,   139,   140,   140,   140,   140,   140,   140,   141,   141,
     142,   142,   143,   143,   143,   143,   143,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   145,
     145,   145,   146,   146,   147,   147,   148,   149,   149,   149,
     149,   150,   150,   151,   151,   151,   152,   152,   152,   153,
     153,   154,   154,   155,   155,   156,   156,   157,   157,   157,
     157,   157,   157,   157,   158,   158,   158,   158,   159,   159,
     160,   160,   161,   161,   162,   162,   162,   163,   163,   164,
     164,   165,   165,   165,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   167,   167,   167,   168,   168,   169,   169,
     169,   169,   169,   169,   170,   170,   170,   171,   171,   171,
     171,   172,   172,   173,   173,   174,   174,   175,   175,   175,
     176,   176,   176,   176,   177,   177,   177,   177,   177,   178,
     178,   179,   179,   180,   180,   180,   180
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     1,     1,     3,     1,     1,     1,     1,     4,
       3,     4,     3,     3,     2,     2,     6,     7,     1,     3,
       1,     2,     2,     2,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     5,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       2,     3,     1,     2,     1,     2,     1,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       4,     2,     1,     1,     1,     2,     3,     2,     1,     2,
       1,     1,     3,     1,     2,     3,     4,     5,     2,     1,
       3,     1,     3,     1,     1,     2,     1,     1,     3,     4,
       3,     4,     4,     3,     1,     2,     2,     3,     1,     2,
       1,     3,     1,     3,     2,     2,     1,     1,     3,     1,
       2,     1,     1,     2,     3,     2,     3,     3,     4,     2,
       3,     3,     4,     1,     3,     4,     1,     3,     1,     1,
       1,     1,     1,     1,     3,     4,     3,     2,     3,     3,
       4,     1,     2,     1,     2,     1,     2,     5,     7,     5,
       5,     7,     6,     7,     3,     2,     2,     2,     3,     1,
       2,     1,     1,     4,     3,     3,     2
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
  "\"plus op\"", "\"times op\"", "\"div op\"", "\"mod op\"", "','", "'('",
  "')'", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'",
  "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'", "'}'", "'['",
  "']'", "$accept", "primary_expression", "constant", "postfix_expression",
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
       0,   162,   162,   163,   164,   168,   173,   178,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   198,   199,
     203,   204,   205,   206,   207,   208,   212,   213,   214,   215,
     216,   217,   221,   222,   226,   227,   228,   229,   233,   234,
     235,   239,   240,   241,   245,   246,   247,   248,   249,   253,
     254,   255,   259,   260,   264,   265,   269,   270,   274,   275,
     279,   280,   284,   285,   289,   290,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   308,   309,   313,
     317,   318,   322,   323,   324,   325,   326,   327,   331,   332,
     336,   337,   341,   342,   343,   344,   345,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   364,
     365,   366,   370,   371,   375,   376,   380,   384,   385,   386,
     387,   391,   392,   396,   397,   398,   402,   403,   404,   408,
     409,   413,   414,   418,   419,   423,   424,   428,   429,   430,
     431,   432,   433,   434,   438,   439,   440,   441,   445,   446,
     451,   452,   456,   457,   461,   462,   463,   467,   468,   472,
     473,   477,   478,   479,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   495,   496,   497,   501,   502,   506,   507,
     508,   509,   510,   511,   515,   516,   517,   521,   522,   523,
     524,   528,   529,   533,   534,   538,   539,   543,   544,   545,
     549,   550,   551,   552,   556,   557,   558,   559,   560,   564,
     565,   569,   570,   574,   575,   576,   577
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
#line 2197 "parser.cpp"

#line 580 "parser.y"


// Bison expects us to provide implementation - otherwise linker complains
void WadeSpace::Parser::error(const location &loc , const std::string &message) {
        
        // Location should be initialized inside scanner action, but is not in this example.
        // Let's grab location directly from driver class.
    // cout << "Error: " << message << endl << "Location: " << loc << endl;
    
        cout << "Error: " << message << endl << "Error location: " << driver.location() << endl;
}
