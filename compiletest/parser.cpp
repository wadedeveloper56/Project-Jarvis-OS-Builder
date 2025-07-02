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
#line 34 "parser.y"

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

      case symbol_kind::S_primary_expression: // primary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_cast_expression: // cast_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_shift_expression: // shift_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_and_expression: // and_expression
      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_conditional_expression: // conditional_expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_constant_expression: // constant_expression
        value.YY_MOVE_OR_COPY< Expression > (YY_MOVE (that.value));
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
      case symbol_kind::S_SEMICOLON: // ";"
      case symbol_kind::S_OCURLY: // "{"
      case symbol_kind::S_CCURLY: // "}"
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_COLON: // ":"
      case symbol_kind::S_OPAREN: // "("
      case symbol_kind::S_CPAREN: // ")"
      case symbol_kind::S_OBRACE: // "["
      case symbol_kind::S_CBRACE: // "]"
      case symbol_kind::S_PERIOD: // "."
      case symbol_kind::S_TILDE: // "~"
      case symbol_kind::S_EQUAL_OP: // "="
      case symbol_kind::S_RIGHT_ASSIGN: // ">>="
      case symbol_kind::S_LEFT_ASSIGN: // "<<="
      case symbol_kind::S_ADD_ASSIGN: // "+="
      case symbol_kind::S_SUB_ASSIGN: // "-="
      case symbol_kind::S_MUL_ASSIGN: // "*="
      case symbol_kind::S_DIV_ASSIGN: // "/="
      case symbol_kind::S_MOD_ASSIGN: // "%="
      case symbol_kind::S_AND_ASSIGN: // "&="
      case symbol_kind::S_XOR_ASSIGN: // "^="
      case symbol_kind::S_OR_ASSIGN: // "|="
      case symbol_kind::S_RIGHT_OP: // ">>"
      case symbol_kind::S_LEFT_OP: // "<<"
      case symbol_kind::S_INC_OP: // "++"
      case symbol_kind::S_DEC_OP: // "--"
      case symbol_kind::S_PTR_OP: // "->"
      case symbol_kind::S_AND_OP: // "&&"
      case symbol_kind::S_OR_OP: // "||"
      case symbol_kind::S_GREATER_EQUAL_OP: // ">="
      case symbol_kind::S_LESS_EQUAL_OP: // "<="
      case symbol_kind::S_GREATER_OP: // ">"
      case symbol_kind::S_LESS_OP: // "<"
      case symbol_kind::S_EQUAL_EQUAL_OP: // "=="
      case symbol_kind::S_NOT_EQUAL_OP: // "!="
      case symbol_kind::S_NOT_OP: // "!"
      case symbol_kind::S_XOR_OP: // "^"
      case symbol_kind::S_BIT_AND: // "&"
      case symbol_kind::S_BIT_OR: // "|"
      case symbol_kind::S_MINUS_OP: // "-"
      case symbol_kind::S_PLUS_OP: // "+"
      case symbol_kind::S_TIMES_OP: // "*"
      case symbol_kind::S_DIV_OP: // "/"
      case symbol_kind::S_MOD_OP: // "%"
      case symbol_kind::S_unary_operator: // unary_operator
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.YY_MOVE_OR_COPY< std::vector<Expression> > (YY_MOVE (that.value));
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

      case symbol_kind::S_primary_expression: // primary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_cast_expression: // cast_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_shift_expression: // shift_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_and_expression: // and_expression
      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_conditional_expression: // conditional_expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_constant_expression: // constant_expression
        value.move< Expression > (YY_MOVE (that.value));
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
      case symbol_kind::S_SEMICOLON: // ";"
      case symbol_kind::S_OCURLY: // "{"
      case symbol_kind::S_CCURLY: // "}"
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_COLON: // ":"
      case symbol_kind::S_OPAREN: // "("
      case symbol_kind::S_CPAREN: // ")"
      case symbol_kind::S_OBRACE: // "["
      case symbol_kind::S_CBRACE: // "]"
      case symbol_kind::S_PERIOD: // "."
      case symbol_kind::S_TILDE: // "~"
      case symbol_kind::S_EQUAL_OP: // "="
      case symbol_kind::S_RIGHT_ASSIGN: // ">>="
      case symbol_kind::S_LEFT_ASSIGN: // "<<="
      case symbol_kind::S_ADD_ASSIGN: // "+="
      case symbol_kind::S_SUB_ASSIGN: // "-="
      case symbol_kind::S_MUL_ASSIGN: // "*="
      case symbol_kind::S_DIV_ASSIGN: // "/="
      case symbol_kind::S_MOD_ASSIGN: // "%="
      case symbol_kind::S_AND_ASSIGN: // "&="
      case symbol_kind::S_XOR_ASSIGN: // "^="
      case symbol_kind::S_OR_ASSIGN: // "|="
      case symbol_kind::S_RIGHT_OP: // ">>"
      case symbol_kind::S_LEFT_OP: // "<<"
      case symbol_kind::S_INC_OP: // "++"
      case symbol_kind::S_DEC_OP: // "--"
      case symbol_kind::S_PTR_OP: // "->"
      case symbol_kind::S_AND_OP: // "&&"
      case symbol_kind::S_OR_OP: // "||"
      case symbol_kind::S_GREATER_EQUAL_OP: // ">="
      case symbol_kind::S_LESS_EQUAL_OP: // "<="
      case symbol_kind::S_GREATER_OP: // ">"
      case symbol_kind::S_LESS_OP: // "<"
      case symbol_kind::S_EQUAL_EQUAL_OP: // "=="
      case symbol_kind::S_NOT_EQUAL_OP: // "!="
      case symbol_kind::S_NOT_OP: // "!"
      case symbol_kind::S_XOR_OP: // "^"
      case symbol_kind::S_BIT_AND: // "&"
      case symbol_kind::S_BIT_OR: // "|"
      case symbol_kind::S_MINUS_OP: // "-"
      case symbol_kind::S_PLUS_OP: // "+"
      case symbol_kind::S_TIMES_OP: // "*"
      case symbol_kind::S_DIV_OP: // "/"
      case symbol_kind::S_MOD_OP: // "%"
      case symbol_kind::S_unary_operator: // unary_operator
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.move< std::vector<Expression> > (YY_MOVE (that.value));
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

      case symbol_kind::S_primary_expression: // primary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_cast_expression: // cast_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_shift_expression: // shift_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_and_expression: // and_expression
      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_conditional_expression: // conditional_expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_constant_expression: // constant_expression
        value.copy< Expression > (that.value);
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
      case symbol_kind::S_SEMICOLON: // ";"
      case symbol_kind::S_OCURLY: // "{"
      case symbol_kind::S_CCURLY: // "}"
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_COLON: // ":"
      case symbol_kind::S_OPAREN: // "("
      case symbol_kind::S_CPAREN: // ")"
      case symbol_kind::S_OBRACE: // "["
      case symbol_kind::S_CBRACE: // "]"
      case symbol_kind::S_PERIOD: // "."
      case symbol_kind::S_TILDE: // "~"
      case symbol_kind::S_EQUAL_OP: // "="
      case symbol_kind::S_RIGHT_ASSIGN: // ">>="
      case symbol_kind::S_LEFT_ASSIGN: // "<<="
      case symbol_kind::S_ADD_ASSIGN: // "+="
      case symbol_kind::S_SUB_ASSIGN: // "-="
      case symbol_kind::S_MUL_ASSIGN: // "*="
      case symbol_kind::S_DIV_ASSIGN: // "/="
      case symbol_kind::S_MOD_ASSIGN: // "%="
      case symbol_kind::S_AND_ASSIGN: // "&="
      case symbol_kind::S_XOR_ASSIGN: // "^="
      case symbol_kind::S_OR_ASSIGN: // "|="
      case symbol_kind::S_RIGHT_OP: // ">>"
      case symbol_kind::S_LEFT_OP: // "<<"
      case symbol_kind::S_INC_OP: // "++"
      case symbol_kind::S_DEC_OP: // "--"
      case symbol_kind::S_PTR_OP: // "->"
      case symbol_kind::S_AND_OP: // "&&"
      case symbol_kind::S_OR_OP: // "||"
      case symbol_kind::S_GREATER_EQUAL_OP: // ">="
      case symbol_kind::S_LESS_EQUAL_OP: // "<="
      case symbol_kind::S_GREATER_OP: // ">"
      case symbol_kind::S_LESS_OP: // "<"
      case symbol_kind::S_EQUAL_EQUAL_OP: // "=="
      case symbol_kind::S_NOT_EQUAL_OP: // "!="
      case symbol_kind::S_NOT_OP: // "!"
      case symbol_kind::S_XOR_OP: // "^"
      case symbol_kind::S_BIT_AND: // "&"
      case symbol_kind::S_BIT_OR: // "|"
      case symbol_kind::S_MINUS_OP: // "-"
      case symbol_kind::S_PLUS_OP: // "+"
      case symbol_kind::S_TIMES_OP: // "*"
      case symbol_kind::S_DIV_OP: // "/"
      case symbol_kind::S_MOD_OP: // "%"
      case symbol_kind::S_unary_operator: // unary_operator
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.copy< std::vector<Expression> > (that.value);
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

      case symbol_kind::S_primary_expression: // primary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_cast_expression: // cast_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_shift_expression: // shift_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_and_expression: // and_expression
      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_conditional_expression: // conditional_expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_constant_expression: // constant_expression
        value.move< Expression > (that.value);
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
      case symbol_kind::S_SEMICOLON: // ";"
      case symbol_kind::S_OCURLY: // "{"
      case symbol_kind::S_CCURLY: // "}"
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_COLON: // ":"
      case symbol_kind::S_OPAREN: // "("
      case symbol_kind::S_CPAREN: // ")"
      case symbol_kind::S_OBRACE: // "["
      case symbol_kind::S_CBRACE: // "]"
      case symbol_kind::S_PERIOD: // "."
      case symbol_kind::S_TILDE: // "~"
      case symbol_kind::S_EQUAL_OP: // "="
      case symbol_kind::S_RIGHT_ASSIGN: // ">>="
      case symbol_kind::S_LEFT_ASSIGN: // "<<="
      case symbol_kind::S_ADD_ASSIGN: // "+="
      case symbol_kind::S_SUB_ASSIGN: // "-="
      case symbol_kind::S_MUL_ASSIGN: // "*="
      case symbol_kind::S_DIV_ASSIGN: // "/="
      case symbol_kind::S_MOD_ASSIGN: // "%="
      case symbol_kind::S_AND_ASSIGN: // "&="
      case symbol_kind::S_XOR_ASSIGN: // "^="
      case symbol_kind::S_OR_ASSIGN: // "|="
      case symbol_kind::S_RIGHT_OP: // ">>"
      case symbol_kind::S_LEFT_OP: // "<<"
      case symbol_kind::S_INC_OP: // "++"
      case symbol_kind::S_DEC_OP: // "--"
      case symbol_kind::S_PTR_OP: // "->"
      case symbol_kind::S_AND_OP: // "&&"
      case symbol_kind::S_OR_OP: // "||"
      case symbol_kind::S_GREATER_EQUAL_OP: // ">="
      case symbol_kind::S_LESS_EQUAL_OP: // "<="
      case symbol_kind::S_GREATER_OP: // ">"
      case symbol_kind::S_LESS_OP: // "<"
      case symbol_kind::S_EQUAL_EQUAL_OP: // "=="
      case symbol_kind::S_NOT_EQUAL_OP: // "!="
      case symbol_kind::S_NOT_OP: // "!"
      case symbol_kind::S_XOR_OP: // "^"
      case symbol_kind::S_BIT_AND: // "&"
      case symbol_kind::S_BIT_OR: // "|"
      case symbol_kind::S_MINUS_OP: // "-"
      case symbol_kind::S_PLUS_OP: // "+"
      case symbol_kind::S_TIMES_OP: // "*"
      case symbol_kind::S_DIV_OP: // "/"
      case symbol_kind::S_MOD_OP: // "%"
      case symbol_kind::S_unary_operator: // unary_operator
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.move< std::vector<Expression> > (that.value);
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

      case symbol_kind::S_primary_expression: // primary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_cast_expression: // cast_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_shift_expression: // shift_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_and_expression: // and_expression
      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_conditional_expression: // conditional_expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_constant_expression: // constant_expression
        yylhs.value.emplace< Expression > ();
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
      case symbol_kind::S_SEMICOLON: // ";"
      case symbol_kind::S_OCURLY: // "{"
      case symbol_kind::S_CCURLY: // "}"
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_COLON: // ":"
      case symbol_kind::S_OPAREN: // "("
      case symbol_kind::S_CPAREN: // ")"
      case symbol_kind::S_OBRACE: // "["
      case symbol_kind::S_CBRACE: // "]"
      case symbol_kind::S_PERIOD: // "."
      case symbol_kind::S_TILDE: // "~"
      case symbol_kind::S_EQUAL_OP: // "="
      case symbol_kind::S_RIGHT_ASSIGN: // ">>="
      case symbol_kind::S_LEFT_ASSIGN: // "<<="
      case symbol_kind::S_ADD_ASSIGN: // "+="
      case symbol_kind::S_SUB_ASSIGN: // "-="
      case symbol_kind::S_MUL_ASSIGN: // "*="
      case symbol_kind::S_DIV_ASSIGN: // "/="
      case symbol_kind::S_MOD_ASSIGN: // "%="
      case symbol_kind::S_AND_ASSIGN: // "&="
      case symbol_kind::S_XOR_ASSIGN: // "^="
      case symbol_kind::S_OR_ASSIGN: // "|="
      case symbol_kind::S_RIGHT_OP: // ">>"
      case symbol_kind::S_LEFT_OP: // "<<"
      case symbol_kind::S_INC_OP: // "++"
      case symbol_kind::S_DEC_OP: // "--"
      case symbol_kind::S_PTR_OP: // "->"
      case symbol_kind::S_AND_OP: // "&&"
      case symbol_kind::S_OR_OP: // "||"
      case symbol_kind::S_GREATER_EQUAL_OP: // ">="
      case symbol_kind::S_LESS_EQUAL_OP: // "<="
      case symbol_kind::S_GREATER_OP: // ">"
      case symbol_kind::S_LESS_OP: // "<"
      case symbol_kind::S_EQUAL_EQUAL_OP: // "=="
      case symbol_kind::S_NOT_EQUAL_OP: // "!="
      case symbol_kind::S_NOT_OP: // "!"
      case symbol_kind::S_XOR_OP: // "^"
      case symbol_kind::S_BIT_AND: // "&"
      case symbol_kind::S_BIT_OR: // "|"
      case symbol_kind::S_MINUS_OP: // "-"
      case symbol_kind::S_PLUS_OP: // "+"
      case symbol_kind::S_TIMES_OP: // "*"
      case symbol_kind::S_DIV_OP: // "/"
      case symbol_kind::S_MOD_OP: // "%"
      case symbol_kind::S_unary_operator: // unary_operator
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        yylhs.value.emplace< std::vector<Expression> > ();
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
#line 184 "parser.y"
                 { yylhs.value.as< Expression > () = Expression(yystack_[0].value.as < std::string > ()); cout << "<EXP> IDENTIFIER REDUCE to primary_expression" << endl; }
#line 1199 "parser.cpp"
    break;

  case 3: // primary_expression: constant
#line 185 "parser.y"
               { yylhs.value.as< Expression > () = Expression(&yystack_[0].value.as < Constant > ()); cout << "<EXP> constant REDUCE to primary_expression" << endl; }
#line 1205 "parser.cpp"
    break;

  case 4: // primary_expression: "(" expression ")"
#line 186 "parser.y"
                                { yylhs.value.as< Expression > () = yystack_[1].value.as < Expression > (); cout << "<EXP> (expression) REDUCE to primary_expression" << endl; }
#line 1211 "parser.cpp"
    break;

  case 5: // constant: "f_const"
#line 190 "parser.y"
              {
                 long double &id = yystack_[0].value.as < long double > ();
                 cout << "<EXP> F_CONST REDUCE to constant " << id << endl;
                 yylhs.value.as< Constant > () = Constant(id);
              }
#line 1221 "parser.cpp"
    break;

  case 6: // constant: "i_const"
#line 195 "parser.y"
              {
                 std::uint64_t &id = yystack_[0].value.as < uint64_t > ();
                 cout << "<EXP> I_CONST REDUCE to constant " << id << endl;
                 yylhs.value.as< Constant > () = Constant(id);
              }
#line 1231 "parser.cpp"
    break;

  case 7: // constant: "sting_literal"
#line 200 "parser.y"
                      {
                 std::string &id = yystack_[0].value.as < std::string > ();
                 cout << "<EXP> STRING_LITERAL REDUCE to constant  " << id << endl;
                 yylhs.value.as< Constant > () = Constant(id);
              }
#line 1241 "parser.cpp"
    break;

  case 8: // postfix_expression: primary_expression
#line 207 "parser.y"
                                                                   { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > (); cout << "primary_expression REDUCE to postfix_expression" << endl; }
#line 1247 "parser.cpp"
    break;

  case 9: // postfix_expression: postfix_expression "[" expression "]"
#line 208 "parser.y"
                                                                   { cout << "postfix_expression OBRACE expression CBRACE REDUCE to postfix_expression" << endl; }
#line 1253 "parser.cpp"
    break;

  case 10: // postfix_expression: postfix_expression "(" ")"
#line 209 "parser.y"
                                                                   { cout << "postfix_expression OPAREN CPAREN REDUCE to postfix_expression" << endl; }
#line 1259 "parser.cpp"
    break;

  case 11: // postfix_expression: postfix_expression "(" argument_expression_list ")"
#line 210 "parser.y"
                                                                   { cout << "postfix_expression OPAREN argument_expression_list CPAREN REDUCE to postfix_expression" << endl; }
#line 1265 "parser.cpp"
    break;

  case 12: // postfix_expression: postfix_expression "." "identifier"
#line 211 "parser.y"
                                                                   { cout << "postfix_expression PERIOD_OP IDENTIFIER REDUCE to postfix_expression" << endl; }
#line 1271 "parser.cpp"
    break;

  case 13: // postfix_expression: postfix_expression "->" "identifier"
#line 212 "parser.y"
                                                                   { cout << "postfix_expression PTR_OP IDENTIFIER REDUCE to postfix_expression" << endl; }
#line 1277 "parser.cpp"
    break;

  case 14: // postfix_expression: postfix_expression "++"
#line 213 "parser.y"
                                                                   { cout << "postfix_expression INC_OP REDUCE to postfix_expression" << endl; }
#line 1283 "parser.cpp"
    break;

  case 15: // postfix_expression: postfix_expression "--"
#line 214 "parser.y"
                                                                   { cout << "postfix_expression DEC_OP REDUCE to postfix_expression" << endl; }
#line 1289 "parser.cpp"
    break;

  case 16: // postfix_expression: "(" type_name ")" "{" initializer_list "}"
#line 215 "parser.y"
                                                                   { cout << "OPAREN type_name CPAREN_OP OCURLY_OP initializer_list CCURLY REDUCE to postfix_expression" << endl; }
#line 1295 "parser.cpp"
    break;

  case 17: // postfix_expression: "(" type_name ")" "{" initializer_list "," "}"
#line 216 "parser.y"
                                                                   { cout << "OPAREN type_name CPAREN_OP OCURLY_OP initializer_list COMMA CCURLY REDUCE to postfix_expression" << endl; }
#line 1301 "parser.cpp"
    break;

  case 18: // argument_expression_list: assignment_expression
#line 220 "parser.y"
                            {
                             Expression exp = yystack_[0].value.as < Expression > ();
                             yylhs.value.as < std::vector<Expression> > () = std::vector<Expression>();
                             yylhs.value.as < std::vector<Expression> > ().push_back(exp);
                             cout << "<EXP> assignment_expression REDUCE argument_expression_list" << endl;
                            }
#line 1312 "parser.cpp"
    break;

  case 19: // argument_expression_list: argument_expression_list "," assignment_expression
#line 226 "parser.y"
                                                           {
            Expression value1 = yystack_[0].value.as < Expression > ();
            std::vector<Expression> &value2 = yystack_[2].value.as < std::vector<Expression> > ();
            value2.push_back(value1);
            yylhs.value.as < std::vector<Expression> > () = value2;
            cout << "<EXP> argument_expression_list COMMA assignment_expression REDUCE argument_expression_list" << endl;
        }
#line 1324 "parser.cpp"
    break;

  case 20: // unary_expression: postfix_expression
#line 236 "parser.y"
                         { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > (); cout << "postfix_expression REDUCE unary_expression" << endl;}
#line 1330 "parser.cpp"
    break;

  case 21: // unary_expression: "++" unary_expression
#line 237 "parser.y"
                              { yylhs.value.as< Expression > () = Expression(yystack_[1].value.as < std::string > (),&yystack_[0].value.as < Expression > ()); cout << "INC_OP unary_expression REDUCE unary_expression" << endl;}
#line 1336 "parser.cpp"
    break;

  case 22: // unary_expression: "--" unary_expression
#line 238 "parser.y"
                              { yylhs.value.as< Expression > () = Expression(yystack_[1].value.as < std::string > (),&yystack_[0].value.as < Expression > ()); cout << "DEC_OP unary_expression REDUCE unary_expression" << endl;}
#line 1342 "parser.cpp"
    break;

  case 23: // unary_expression: unary_operator cast_expression
#line 239 "parser.y"
                                     { yylhs.value.as< Expression > () = Expression(yystack_[1].value.as < std::string > (),&yystack_[0].value.as < Expression > ()); cout << "unary_operator cast_expression REDUCE unary_expression" << endl;}
#line 1348 "parser.cpp"
    break;

  case 24: // unary_expression: "sizeof" unary_expression
#line 240 "parser.y"
                              { yylhs.value.as< Expression > () = Expression(); cout << "SIZEOF unary_expression REDUCE unary_expression" << endl;}
#line 1354 "parser.cpp"
    break;

  case 25: // unary_expression: "sizeof" "(" type_name ")"
#line 241 "parser.y"
                                     { yylhs.value.as< Expression > () = Expression(); cout << "SIZEOF OPAREN type_name CPAREN REDUCE unary_expression" << endl;}
#line 1360 "parser.cpp"
    break;

  case 26: // unary_operator: "&"
#line 245 "parser.y"
                {yylhs.value.as< std::string > () = yystack_[0].value.as < std::string > (); cout << "BIT_AND REDUCE to unary_operator" << endl;}
#line 1366 "parser.cpp"
    break;

  case 27: // unary_operator: "*"
#line 246 "parser.y"
                {yylhs.value.as< std::string > () = yystack_[0].value.as < std::string > (); cout << "TIMES_OP REDUCE to unary_operator" << endl;}
#line 1372 "parser.cpp"
    break;

  case 28: // unary_operator: "+"
#line 247 "parser.y"
                {yylhs.value.as< std::string > () = yystack_[0].value.as < std::string > (); cout << "PLUS_OP REDUCE to unary_operator" << endl;}
#line 1378 "parser.cpp"
    break;

  case 29: // unary_operator: "-"
#line 248 "parser.y"
                {yylhs.value.as< std::string > () = yystack_[0].value.as < std::string > (); cout << "MINUS_OP REDUCE to unary_operator" << endl;}
#line 1384 "parser.cpp"
    break;

  case 30: // unary_operator: "~"
#line 249 "parser.y"
                {yylhs.value.as< std::string > () = yystack_[0].value.as < std::string > (); cout << "TILDE REDUCE to unary_operator" << endl;}
#line 1390 "parser.cpp"
    break;

  case 31: // unary_operator: "!"
#line 250 "parser.y"
                {yylhs.value.as< std::string > () = yystack_[0].value.as < std::string > (); cout << "NOT_OP REDUCE to unary_operator" << endl;}
#line 1396 "parser.cpp"
    break;

  case 32: // cast_expression: unary_expression
#line 254 "parser.y"
                        { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > (); }
#line 1402 "parser.cpp"
    break;

  case 33: // cast_expression: "(" type_name ")" cast_expression
#line 255 "parser.y"
                                               { yylhs.value.as< Expression > () = Expression(); }
#line 1408 "parser.cpp"
    break;

  case 34: // multiplicative_expression: cast_expression
#line 259 "parser.y"
                       { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > (); }
#line 1414 "parser.cpp"
    break;

  case 35: // multiplicative_expression: multiplicative_expression "*" cast_expression
#line 260 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[2].value.as < Expression > (); }
#line 1420 "parser.cpp"
    break;

  case 36: // multiplicative_expression: multiplicative_expression "/" cast_expression
#line 261 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[2].value.as < Expression > (); }
#line 1426 "parser.cpp"
    break;

  case 37: // multiplicative_expression: multiplicative_expression "%" cast_expression
#line 262 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[2].value.as < Expression > (); }
#line 1432 "parser.cpp"
    break;

  case 38: // additive_expression: multiplicative_expression
#line 266 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > (); }
#line 1438 "parser.cpp"
    break;

  case 39: // additive_expression: additive_expression '+' multiplicative_expression
#line 267 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[2].value.as < Expression > (); }
#line 1444 "parser.cpp"
    break;

  case 40: // additive_expression: additive_expression '-' multiplicative_expression
#line 268 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[2].value.as < Expression > (); }
#line 1450 "parser.cpp"
    break;

  case 41: // shift_expression: additive_expression
#line 272 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > (); }
#line 1456 "parser.cpp"
    break;

  case 42: // shift_expression: shift_expression "<<" additive_expression
#line 273 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[2].value.as < Expression > (); }
#line 1462 "parser.cpp"
    break;

  case 43: // shift_expression: shift_expression ">>" additive_expression
#line 274 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[2].value.as < Expression > (); }
#line 1468 "parser.cpp"
    break;

  case 44: // relational_expression: shift_expression
#line 278 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > (); }
#line 1474 "parser.cpp"
    break;

  case 45: // relational_expression: relational_expression "<" shift_expression
#line 279 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[2].value.as < Expression > (); }
#line 1480 "parser.cpp"
    break;

  case 46: // relational_expression: relational_expression ">" shift_expression
#line 280 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[2].value.as < Expression > (); }
#line 1486 "parser.cpp"
    break;

  case 47: // relational_expression: relational_expression "<=" shift_expression
#line 281 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[2].value.as < Expression > (); }
#line 1492 "parser.cpp"
    break;

  case 48: // relational_expression: relational_expression ">=" shift_expression
#line 282 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[2].value.as < Expression > (); }
#line 1498 "parser.cpp"
    break;

  case 49: // equality_expression: relational_expression
#line 286 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > (); }
#line 1504 "parser.cpp"
    break;

  case 50: // equality_expression: equality_expression "==" relational_expression
#line 287 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[2].value.as < Expression > (); }
#line 1510 "parser.cpp"
    break;

  case 51: // equality_expression: equality_expression "!=" relational_expression
#line 288 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[2].value.as < Expression > (); }
#line 1516 "parser.cpp"
    break;

  case 52: // and_expression: equality_expression
#line 292 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > (); }
#line 1522 "parser.cpp"
    break;

  case 53: // and_expression: and_expression '&' equality_expression
#line 293 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[2].value.as < Expression > (); }
#line 1528 "parser.cpp"
    break;

  case 54: // exclusive_or_expression: and_expression
#line 297 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > (); }
#line 1534 "parser.cpp"
    break;

  case 55: // exclusive_or_expression: exclusive_or_expression '^' and_expression
#line 298 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[2].value.as < Expression > (); }
#line 1540 "parser.cpp"
    break;

  case 56: // inclusive_or_expression: exclusive_or_expression
#line 302 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > (); }
#line 1546 "parser.cpp"
    break;

  case 57: // inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression
#line 303 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[2].value.as < Expression > (); }
#line 1552 "parser.cpp"
    break;

  case 58: // logical_and_expression: inclusive_or_expression
#line 307 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > (); }
#line 1558 "parser.cpp"
    break;

  case 59: // logical_and_expression: logical_and_expression "&&" inclusive_or_expression
#line 308 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[2].value.as < Expression > (); }
#line 1564 "parser.cpp"
    break;

  case 60: // logical_or_expression: logical_and_expression
#line 312 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > (); }
#line 1570 "parser.cpp"
    break;

  case 61: // logical_or_expression: logical_or_expression "||" logical_and_expression
#line 313 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[2].value.as < Expression > (); }
#line 1576 "parser.cpp"
    break;

  case 62: // conditional_expression: logical_or_expression
#line 317 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > (); }
#line 1582 "parser.cpp"
    break;

  case 63: // conditional_expression: logical_or_expression '?' expression ':' conditional_expression
#line 318 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[4].value.as < Expression > (); }
#line 1588 "parser.cpp"
    break;

  case 64: // assignment_expression: conditional_expression
#line 322 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > (); }
#line 1594 "parser.cpp"
    break;

  case 65: // assignment_expression: unary_expression assignment_operator assignment_expression
#line 323 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[2].value.as < Expression > (); }
#line 1600 "parser.cpp"
    break;

  case 77: // expression: assignment_expression
#line 341 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > (); }
#line 1606 "parser.cpp"
    break;

  case 78: // expression: expression "," assignment_expression
#line 342 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[2].value.as < Expression > (); }
#line 1612 "parser.cpp"
    break;

  case 79: // constant_expression: conditional_expression
#line 346 "parser.y"
      { yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > (); }
#line 1618 "parser.cpp"
    break;

  case 209: // translation_unit: external_declaration
#line 597 "parser.y"
                                            { cout << "external_declaration REDUCE to translation_unit" << endl; }
#line 1624 "parser.cpp"
    break;

  case 210: // translation_unit: translation_unit external_declaration
#line 598 "parser.y"
                                            { cout << "translation_unit external_declaration REDUCE to translation_unit" << endl; }
#line 1630 "parser.cpp"
    break;

  case 211: // external_declaration: function_definition
#line 602 "parser.y"
                           { cout << "function_definition REDUCE to external_declaration" << endl; }
#line 1636 "parser.cpp"
    break;

  case 212: // external_declaration: declaration
#line 603 "parser.y"
                           { cout << "declaration REDUCE to external_declaration" << endl; }
#line 1642 "parser.cpp"
    break;


#line 1646 "parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -215;

  const signed char  Parser ::yytable_ninf_ = -1;

  const short
   Parser ::yypact_[] =
  {
     363,  -215,  -215,  -215,  -215,  -215,  -215,    37,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
    -215,  -215,    16,    -3,  -215,    15,  1604,  1604,  -215,    38,
    -215,  1604,  1531,   -12,    19,   283,  -215,  -215,    21,    65,
      23,  -215,  -215,    -3,  -215,   -38,  -215,   557,  -215,  -215,
      34,  1640,  -215,   627,  -215,    15,  -215,  1531,  1385,   403,
     -12,  -215,  -215,    65,   -24,    88,  -215,  -215,  -215,  -215,
    -215,    16,  1167,  -215,  1531,  1640,  1640,  1459,  -215,    18,
    1640,     3,  -215,  -215,  -215,    43,  1259,   107,    59,  1067,
      71,   191,   148,   779,  1292,   150,   157,  -215,  -215,   803,
    -215,  1301,  1301,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
     141,    85,  1259,  -215,   178,   -45,   108,    64,   174,   131,
     143,   153,   186,   -17,  -215,  -215,    81,  -215,  -215,  -215,
     715,   891,  -215,  -215,  -215,  -215,   173,  -215,  -215,  -215,
    -215,    26,   227,   237,  -215,   146,  -215,  -215,  -215,  -215,
     190,   172,  1259,  -215,    65,  -215,  1167,  -215,  -215,  -215,
    1495,  -215,  -215,  -215,  1259,   144,  -215,   201,  -215,  1067,
    -215,   202,  -215,  1067,   255,  1185,   256,  1259,  -215,   168,
     803,  -215,  1259,  1259,   170,   -42,   252,   803,  -215,  -215,
     953,  1259,   305,  -215,  -215,   308,  -215,  -215,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,  1259,  -215,  1259,
    1259,  1259,  1259,  1259,  1259,  1259,  1259,  1259,  1259,  1259,
    1259,  1259,  1259,  1259,  1259,  1259,  1259,  1259,  -215,  1259,
    -215,   979,  -215,  -215,   323,   410,  -215,    31,  -215,    -8,
    -215,  1567,   311,  -215,  -215,  -215,  -215,  -215,  -215,   220,
    -215,  -215,  -215,    18,  1259,  -215,  1067,  -215,   263,  1185,
    -215,   181,  -215,   272,   183,   185,  -215,   520,    13,  -215,
    1226,   273,  -215,   199,  -215,    54,  -215,  -215,  -215,  -215,
    -215,  -215,   178,   178,   -45,   -45,   108,   108,   108,   108,
      64,    64,   174,   131,   143,   153,   186,    27,  -215,  -215,
    -215,   274,   277,  -215,   231,    -8,  1422,   436,  -215,  -215,
    -215,  -215,  1108,  -215,  -215,  -215,  1259,  1283,  1067,   286,
    1067,  1067,  1167,  -215,   286,  1259,  -215,  -215,  1259,  -215,
    -215,  -215,  -215,   285,  -215,   236,  -215,  -215,   209,  1067,
     211,   327,  -215,  -215,   224,  -215,  -215,  -215,  -215,   292,
    -215,  1067,  1067,  -215,  1126,  -215,  -215,  -215,  -215
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
      81,     0,     0,   214,     0,     0,   118,     0,   114,     0,
     120,     2,     6,     5,     7,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   195,   187,     0,
      30,     0,     0,    31,    26,    29,    28,    27,     8,     3,
      20,    32,     0,    34,    38,    41,    44,    49,    52,    54,
      56,    58,    60,    62,    64,    77,     0,   193,   178,   179,
       0,     0,   180,   181,   182,   183,    90,   192,   215,   157,
     143,   156,     0,   150,   152,     0,     2,   140,    32,    79,
       0,     0,     0,   126,     0,    89,     0,   173,    91,   213,
       0,   117,   110,   115,     0,     0,   121,   123,   119,     0,
     206,     0,   205,     0,     0,     0,     0,     0,   207,     0,
       0,    24,     0,     0,     0,   159,     0,     0,    21,    22,
       0,     0,     0,    14,    15,     0,    73,    72,    70,    71,
      67,    68,    69,    74,    75,    76,    66,     0,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   196,     0,
     189,     0,   188,   194,     0,     0,   154,   161,   155,   162,
     141,     0,     0,   142,   139,   127,   132,   130,   176,     0,
     109,   124,   116,     0,     0,   184,     0,   186,     0,     0,
     204,     0,   208,     0,     0,     0,     4,     0,   161,   160,
       0,     0,    10,     0,    18,     0,    12,    13,    65,    35,
      36,    37,    39,    40,    43,    42,    48,    47,    46,    45,
      50,    51,    53,    55,    57,    59,    61,     0,    78,   190,
     169,     0,     0,   165,     0,   163,     0,     0,   151,   153,
     158,   174,     0,   122,   125,   185,     0,     0,     0,    25,
       0,     0,     0,    33,     0,     0,    11,     9,     0,   170,
     164,   166,   171,     0,   167,     0,   175,   177,     0,     0,
       0,   197,   199,   200,     0,    19,    63,   172,   168,     0,
     202,     0,     0,    16,     0,   201,   203,   198,    17
  };

  const short
   Parser ::yypgoto_[] =
  {
    -215,  -215,  -215,  -215,  -215,   -49,  -215,   -87,    68,    73,
     -28,    76,   124,   125,   123,   126,   127,  -215,   -54,   -70,
    -215,   -86,   -48,     8,     0,  -215,   289,  -215,   133,  -215,
    -215,   279,   -47,   -52,  -215,   104,  -215,   304,   214,    32,
      -5,   -30,    -7,  -215,   -57,  -215,   128,  -215,  -136,  -108,
    -214,   -69,    50,   -74,  -215,   171,     9,   243,  -169,  -215,
    -215,  -215,  -215,   341,  -215
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,   108,   109,   110,   273,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     207,   126,   150,    54,    55,    45,    46,    26,    27,    28,
      29,    77,    78,    79,   165,   166,    30,    65,    66,    31,
      32,    33,    34,    43,   301,   143,   144,   145,   186,   302,
     239,   248,   249,   127,   128,   129,    57,   131,   132,   133,
     134,   135,    35,    36,    37
  };

  const short
   Parser ::yytable_[] =
  {
      25,   142,   157,   158,    60,   149,   259,   179,    24,     5,
     148,    70,   267,   184,    71,   174,    42,    40,     1,     1,
      47,     1,     1,   305,   161,   208,    48,    49,   168,     1,
     163,    52,   149,   238,     1,    25,    69,   148,   171,    21,
      38,    50,    58,    24,   263,   181,   306,   185,   212,   213,
     136,   271,   188,   189,   305,    41,    74,   233,   141,   235,
     226,    23,   130,   148,    44,   137,   136,   267,    64,    22,
      22,    63,    22,    22,   167,    68,   152,   269,    67,   229,
     234,   227,   137,    80,    75,   234,   157,    39,    51,    59,
     317,   261,   170,   307,   184,   255,   264,   265,   149,   257,
      23,   184,   169,   148,   246,   275,   229,    80,    80,    80,
     149,   327,    80,   163,   235,   148,   251,   164,    23,    23,
     274,    23,   279,   280,   281,   175,   328,   235,   185,    23,
     228,    80,   235,   229,   237,   185,   236,   278,   137,   153,
     154,   297,   216,   217,   218,   219,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   172,   233,   173,   298,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   268,   214,
     215,   149,   315,   323,    76,   206,   148,   304,   286,   287,
     288,   289,    80,   252,   176,   190,   253,   191,   242,   192,
     149,   243,   177,    56,   182,   148,   314,    60,    76,    76,
      76,   183,    80,    76,   193,   194,   195,   262,    73,    80,
     229,   148,   229,   245,   154,   266,   222,   237,   138,    40,
     338,   340,    76,   229,   141,   229,   318,   229,   320,   223,
     321,   141,   157,   337,   341,   159,   342,   343,   167,   333,
     224,   325,   157,   149,   326,   345,   220,   221,   148,   335,
     268,   229,   225,   229,   349,   350,   351,   141,   209,   210,
     211,   311,   312,    72,   346,   353,   354,   356,   357,   148,
     282,   283,   240,    61,   157,   337,     1,   284,   285,   241,
       2,     3,   244,    76,     4,     5,   290,   291,   258,     6,
     254,   256,     7,     8,     9,   260,   141,   270,   276,    10,
      11,   277,    12,    76,   310,    13,    14,   316,    15,    16,
      76,    17,    18,    19,    20,    21,     1,   319,   324,   329,
       2,     3,   330,   331,     4,     5,   322,    22,   348,     6,
     347,   355,     7,     8,     9,   352,   292,   294,   293,    10,
      11,   295,    12,   296,   160,    13,    14,   313,    15,    16,
     155,    17,    18,    19,    20,    21,     1,   151,   247,   309,
       2,     3,   344,   231,     4,     5,    62,   234,   300,     6,
       0,     0,     7,     8,     9,     0,    23,     0,     0,    10,
      11,     0,    12,     0,     0,    13,    14,     0,    15,    16,
       0,    17,    18,    19,    20,    21,   146,    82,    83,    84,
       0,     0,     0,   146,    82,    83,    84,    22,     0,     0,
       0,     0,     0,     0,   235,     0,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,     0,   146,
      82,    83,    84,     0,    94,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    99,     0,     0,
       0,     0,   100,     0,    99,     0,    23,     0,     0,   100,
      94,     0,     0,     0,     0,     0,   101,   102,     0,     0,
       0,     0,     0,   101,   102,     0,     0,   103,     0,   104,
      99,   105,   106,   107,   103,   100,   104,     0,   105,   106,
     107,     0,     0,     0,     0,   147,     0,     0,     0,   101,
     102,     0,   303,     0,     0,     0,     0,     0,     0,     0,
     103,     0,   104,     0,   105,   106,   107,     2,     3,     0,
       0,     4,     5,     0,     0,     0,     6,     0,   334,     7,
       8,     9,     0,     0,     0,     0,    10,    11,     0,    12,
       0,     0,    13,    14,     0,    15,    16,     0,    17,    18,
      19,    20,    21,     0,     2,     3,     0,     0,     4,     5,
       0,     0,     0,     6,   267,   300,     7,     8,     9,     0,
       0,     0,     0,    10,    11,     0,    12,     0,     0,    13,
      14,     0,    15,    16,     0,    17,    18,    19,    20,    21,
       0,     0,     0,     0,     0,     0,     0,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   235,     0,    23,     0,     0,     0,     0,     0,     0,
      81,    82,    83,    84,     2,     3,    85,    86,     4,     5,
      87,    88,    89,     6,     0,     0,     7,     8,     9,    90,
      91,    92,     0,    10,    11,     0,    12,    72,    93,    13,
      14,    94,    15,    16,    95,    17,    18,    19,    20,    21,
      96,     0,     0,     0,     0,     0,    97,    53,    98,     0,
       0,    99,     0,     0,     0,     0,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     101,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,     0,   104,     0,   105,   106,   107,    81,    82,
      83,    84,     2,     3,    85,    86,     4,     5,    87,    88,
      89,     6,     0,     0,     7,     8,     9,    90,    91,    92,
       0,    10,    11,     0,    12,     0,    93,    13,    14,    94,
      15,    16,    95,    17,    18,    19,    20,    21,    96,     0,
       0,     0,     0,     0,    97,    53,   230,     0,     0,    99,
       0,     0,     0,     0,   100,     0,     0,     0,     0,     0,
       0,     0,   146,    82,    83,    84,     0,     0,   101,   102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
       0,   104,     0,   105,   106,   107,   146,    82,    83,    84,
       2,     0,     0,    94,     4,     5,     0,     0,     0,     6,
       0,     0,     7,     0,     9,     0,     0,     0,   178,    10,
      11,     0,     0,    99,     0,    13,    14,    94,   100,    16,
       0,     0,    18,    19,    20,    21,     0,     0,     0,     0,
       0,     0,   101,   102,     0,     0,     0,    99,     0,     0,
       0,     0,   100,   103,     0,   104,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,     0,   104,
       0,   105,   106,   107,    81,    82,    83,    84,     0,     0,
      85,    86,     0,     0,    87,    88,    89,     0,     0,     0,
       0,     0,     0,    90,    91,    92,     0,     0,     0,     0,
       0,     0,    93,     0,     0,    94,     0,     0,    95,     0,
       0,     0,     0,     0,    96,     0,     0,     0,     0,     0,
      97,    53,   232,     0,     0,    99,     0,     0,     0,     0,
     100,     0,     0,     0,     0,     0,   146,    82,    83,    84,
       0,     0,     0,     0,   101,   102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,     0,   104,     0,   105,
     106,   107,    81,    82,    83,    84,     0,    94,    85,    86,
       0,     0,    87,    88,    89,     0,     0,     0,     0,     0,
       0,    90,    91,    92,     0,     0,     0,    99,   272,     0,
      93,     0,   100,    94,     0,     0,    95,     0,     0,     0,
       0,     0,    96,     0,     0,     0,   101,   102,    97,    53,
     299,     0,     0,    99,     0,     0,     0,   103,   100,   104,
       0,   105,   106,   107,     0,     0,     0,     0,     0,     0,
       0,     0,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,     0,   104,     0,   105,   106,   107,
      81,    82,    83,    84,     0,     0,    85,    86,     0,     0,
      87,    88,    89,     0,     0,     0,     0,     0,     0,    90,
      91,    92,     0,     0,     0,     0,     0,     0,    93,     0,
       0,    94,     0,     0,    95,     0,     0,     0,     0,     0,
      96,   146,    82,    83,    84,     0,    97,    53,     0,     0,
       0,    99,     0,     0,     0,     0,   100,     0,     0,   146,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
     101,   102,    94,     0,     0,     0,     0,     0,     0,     0,
       0,   103,     0,   104,     0,   105,   106,   107,   156,   336,
      94,     0,    99,     0,     0,     0,     0,   100,     0,     0,
     146,    82,    83,    84,     0,     0,   156,   358,     0,     0,
      99,   101,   102,     0,     0,   100,     0,     0,   146,    82,
      83,    84,   103,     0,   104,     0,   105,   106,   107,   101,
     102,    94,     0,     0,     0,     0,     0,     0,     0,     0,
     103,     0,   104,     0,   105,   106,   107,   156,     0,    94,
       0,    99,     0,     0,     0,     0,   100,     0,     0,   146,
      82,    83,    84,     0,    97,     0,     0,     0,     0,    99,
     101,   102,     0,     0,   100,     0,     0,     0,     0,     0,
       0,   103,     0,   104,     0,   105,   106,   107,   101,   102,
      94,     0,   146,    82,    83,    84,     0,     0,     0,   103,
       0,   104,     0,   105,   106,   107,   322,     0,     0,     0,
      99,     0,     0,     0,     0,   100,   146,    82,    83,    84,
       0,     0,     0,    94,     0,   146,    82,    83,    84,   101,
     102,     0,     0,     0,   146,    82,    83,    84,     0,     0,
     103,     0,   104,    99,   105,   106,   107,    94,   100,     0,
       0,     0,     0,     0,     0,     0,    94,     0,     0,     0,
       0,     0,   101,   102,     0,    94,     0,    99,   339,     0,
       0,     0,   100,   103,     0,   104,   180,   105,   106,   107,
       0,   100,     0,     0,     0,   187,   101,   102,     0,     0,
     100,     0,     0,     0,     0,   101,   102,   103,     0,   104,
       0,   105,   106,   107,   101,   102,   103,     0,   104,     0,
     105,   106,   107,     0,     0,   103,     0,   104,   139,   105,
     106,   107,     2,     3,     0,     0,     4,     5,     0,     0,
       0,     6,     0,     0,     7,     8,     9,     0,     0,     0,
       0,    10,    11,     0,    12,     0,     0,    13,    14,     0,
      15,    16,     0,    17,    18,    19,    20,    21,     0,     2,
       3,     0,     0,     4,     5,     0,     0,     0,     6,     0,
     140,     7,     8,     9,     0,     0,     0,     0,    10,    11,
       0,    12,     0,     0,    13,    14,     0,    15,    16,     0,
      17,    18,    19,    20,    21,     0,     2,     0,     0,     0,
       4,     5,     0,     0,     0,     6,     0,   332,     7,     0,
       9,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    13,    14,     0,     0,    16,     0,     0,    18,    19,
      20,    21,     2,     0,     0,     0,     4,     5,     0,     0,
     162,     6,     0,     0,     7,     0,     9,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    13,    14,     0,
       0,    16,     0,     0,    18,    19,    20,    21,     2,     3,
       0,     0,     4,     5,     0,     0,   250,     6,     0,     0,
       7,     8,     9,     0,     0,     0,     0,    10,    11,     0,
      12,     0,     0,    13,    14,     0,    15,    16,     0,    17,
      18,    19,    20,    21,     2,     3,     0,     0,     4,     5,
       0,    53,     0,     6,     0,     0,     7,     8,     9,     0,
       0,     0,     0,    10,    11,     0,    12,     0,     0,    13,
      14,     0,    15,    16,     0,    17,    18,    19,    20,    21,
       0,     2,     3,     0,   308,     4,     5,     0,     0,     0,
       6,     0,     0,     7,     8,     9,     0,     0,     0,     0,
      10,    11,     0,    12,     0,     0,    13,    14,     0,    15,
      16,     0,    17,    18,    19,    20,    21,     2,     0,     0,
       0,     4,     5,     0,     0,     0,     6,     0,     0,     7,
       0,     9,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    13,    14,     0,     0,    16,     0,     0,    18,
      19,    20,    21
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    58,    72,    72,    34,    59,   175,    93,     0,    12,
      59,    49,    54,    99,    52,    89,    23,    22,     3,     3,
      25,     3,     3,   237,    76,   112,    26,    27,    80,     3,
      77,    31,    86,   141,     3,    35,    43,    86,    86,    42,
       3,     3,    54,    35,   180,    94,    54,    99,    93,    94,
      55,   187,   101,   102,   268,    23,    47,   131,    58,   101,
      77,   103,    53,   112,    49,    57,    71,    54,     3,    54,
      54,    50,    54,    54,    79,    43,   100,   185,    55,    52,
      54,    98,    74,    51,    50,    54,   156,    50,    50,   101,
     259,   177,    49,   101,   180,   169,   182,   183,   152,   173,
     103,   187,    99,   152,   152,   191,    52,    75,    76,    77,
     164,    57,    80,   160,   101,   164,   164,    99,   103,   103,
     190,   103,   209,   210,   211,    54,    99,   101,   180,   103,
      49,    99,   101,    52,   141,   187,   141,   207,   130,    51,
      52,   227,    78,    79,    80,    81,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    49,   231,    99,   229,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   185,    71,
      72,   235,   256,   270,    51,   100,   235,   235,   216,   217,
     218,   219,   160,    49,     3,    54,    52,    56,    52,    58,
     254,    55,    54,    32,    54,   254,   254,   237,    75,    76,
      77,    54,   180,    80,    73,    74,    75,    49,    47,   187,
      52,   270,    52,    51,    52,    55,    95,   234,    57,   234,
     316,   317,    99,    52,   234,    52,    55,    52,    55,    96,
      55,   241,   312,   312,   318,    74,   320,   321,   253,   306,
      97,    52,   322,   307,    55,   325,    82,    83,   307,   307,
     267,    52,    76,    52,    55,   339,    55,   267,    90,    91,
      92,    51,    52,   100,   328,    51,    52,   351,   352,   328,
     212,   213,    55,     0,   354,   354,     3,   214,   215,    52,
       7,     8,   102,   160,    11,    12,   220,   221,    43,    16,
      99,    99,    19,    20,    21,    49,   306,    55,     3,    26,
      27,     3,    29,   180,     3,    32,    33,    54,    35,    36,
     187,    38,    39,    40,    41,    42,     3,    55,    55,    55,
       7,     8,    55,   102,    11,    12,    50,    54,   102,    16,
      55,    49,    19,    20,    21,    18,   222,   224,   223,    26,
      27,   225,    29,   226,    75,    32,    33,   253,    35,    36,
      71,    38,    39,    40,    41,    42,     3,    63,   154,   241,
       7,     8,   322,   130,    11,    12,    35,    54,    55,    16,
      -1,    -1,    19,    20,    21,    -1,   103,    -1,    -1,    26,
      27,    -1,    29,    -1,    -1,    32,    33,    -1,    35,    36,
      -1,    38,    39,    40,    41,    42,     3,     4,     5,     6,
      -1,    -1,    -1,     3,     4,     5,     6,    54,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    -1,   103,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,     3,
       4,     5,     6,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    59,    -1,    54,    -1,   103,    -1,    -1,    59,
      34,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,
      -1,    -1,    -1,    73,    74,    -1,    -1,    84,    -1,    86,
      54,    88,    89,    90,    84,    59,    86,    -1,    88,    89,
      90,    -1,    -1,    -1,    -1,   102,    -1,    -1,    -1,    73,
      74,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    -1,    86,    -1,    88,    89,    90,     7,     8,    -1,
      -1,    11,    12,    -1,    -1,    -1,    16,    -1,   102,    19,
      20,    21,    -1,    -1,    -1,    -1,    26,    27,    -1,    29,
      -1,    -1,    32,    33,    -1,    35,    36,    -1,    38,    39,
      40,    41,    42,    -1,     7,     8,    -1,    -1,    11,    12,
      -1,    -1,    -1,    16,    54,    55,    19,    20,    21,    -1,
      -1,    -1,    -1,    26,    27,    -1,    29,    -1,    -1,    32,
      33,    -1,    35,    36,    -1,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   101,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    -1,    29,   100,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    -1,    86,    -1,    88,    89,    90,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    19,    20,    21,    22,    23,    24,
      -1,    26,    27,    -1,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,    -1,    73,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    86,    -1,    88,    89,    90,     3,     4,     5,     6,
       7,    -1,    -1,    34,    11,    12,    -1,    -1,    -1,    16,
      -1,    -1,    19,    -1,    21,    -1,    -1,    -1,    49,    26,
      27,    -1,    -1,    54,    -1,    32,    33,    34,    59,    36,
      -1,    -1,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    59,    84,    -1,    86,    -1,    88,    89,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    86,
      -1,    88,    89,    90,     3,     4,     5,     6,    -1,    -1,
       9,    10,    -1,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    34,    -1,    -1,    37,    -1,
      -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    73,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    86,    -1,    88,
      89,    90,     3,     4,     5,     6,    -1,    34,     9,    10,
      -1,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    -1,    -1,    -1,    54,    55,    -1,
      31,    -1,    59,    34,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    73,    74,    49,    50,
      51,    -1,    -1,    54,    -1,    -1,    -1,    84,    59,    86,
      -1,    88,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    -1,    86,    -1,    88,    89,    90,
       3,     4,     5,     6,    -1,    -1,     9,    10,    -1,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    34,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      43,     3,     4,     5,     6,    -1,    49,    50,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    59,    -1,    -1,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    -1,    86,    -1,    88,    89,    90,    50,    51,
      34,    -1,    54,    -1,    -1,    -1,    -1,    59,    -1,    -1,
       3,     4,     5,     6,    -1,    -1,    50,    51,    -1,    -1,
      54,    73,    74,    -1,    -1,    59,    -1,    -1,     3,     4,
       5,     6,    84,    -1,    86,    -1,    88,    89,    90,    73,
      74,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    -1,    86,    -1,    88,    89,    90,    50,    -1,    34,
      -1,    54,    -1,    -1,    -1,    -1,    59,    -1,    -1,     3,
       4,     5,     6,    -1,    49,    -1,    -1,    -1,    -1,    54,
      73,    74,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    -1,    86,    -1,    88,    89,    90,    73,    74,
      34,    -1,     3,     4,     5,     6,    -1,    -1,    -1,    84,
      -1,    86,    -1,    88,    89,    90,    50,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    59,     3,     4,     5,     6,
      -1,    -1,    -1,    34,    -1,     3,     4,     5,     6,    73,
      74,    -1,    -1,    -1,     3,     4,     5,     6,    -1,    -1,
      84,    -1,    86,    54,    88,    89,    90,    34,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    73,    74,    -1,    34,    -1,    54,    55,    -1,
      -1,    -1,    59,    84,    -1,    86,    54,    88,    89,    90,
      -1,    59,    -1,    -1,    -1,    54,    73,    74,    -1,    -1,
      59,    -1,    -1,    -1,    -1,    73,    74,    84,    -1,    86,
      -1,    88,    89,    90,    73,    74,    84,    -1,    86,    -1,
      88,    89,    90,    -1,    -1,    84,    -1,    86,     3,    88,
      89,    90,     7,     8,    -1,    -1,    11,    12,    -1,    -1,
      -1,    16,    -1,    -1,    19,    20,    21,    -1,    -1,    -1,
      -1,    26,    27,    -1,    29,    -1,    -1,    32,    33,    -1,
      35,    36,    -1,    38,    39,    40,    41,    42,    -1,     7,
       8,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,    -1,
      55,    19,    20,    21,    -1,    -1,    -1,    -1,    26,    27,
      -1,    29,    -1,    -1,    32,    33,    -1,    35,    36,    -1,
      38,    39,    40,    41,    42,    -1,     7,    -1,    -1,    -1,
      11,    12,    -1,    -1,    -1,    16,    -1,    55,    19,    -1,
      21,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,    -1,
      -1,    32,    33,    -1,    -1,    36,    -1,    -1,    39,    40,
      41,    42,     7,    -1,    -1,    -1,    11,    12,    -1,    -1,
      51,    16,    -1,    -1,    19,    -1,    21,    -1,    -1,    -1,
      -1,    26,    27,    -1,    -1,    -1,    -1,    32,    33,    -1,
      -1,    36,    -1,    -1,    39,    40,    41,    42,     7,     8,
      -1,    -1,    11,    12,    -1,    -1,    51,    16,    -1,    -1,
      19,    20,    21,    -1,    -1,    -1,    -1,    26,    27,    -1,
      29,    -1,    -1,    32,    33,    -1,    35,    36,    -1,    38,
      39,    40,    41,    42,     7,     8,    -1,    -1,    11,    12,
      -1,    50,    -1,    16,    -1,    -1,    19,    20,    21,    -1,
      -1,    -1,    -1,    26,    27,    -1,    29,    -1,    -1,    32,
      33,    -1,    35,    36,    -1,    38,    39,    40,    41,    42,
      -1,     7,     8,    -1,    47,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,
      26,    27,    -1,    29,    -1,    -1,    32,    33,    -1,    35,
      36,    -1,    38,    39,    40,    41,    42,     7,    -1,    -1,
      -1,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    19,
      -1,    21,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,
      -1,    -1,    32,    33,    -1,    -1,    36,    -1,    -1,    39,
      40,    41,    42
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     7,     8,    11,    12,    16,    19,    20,    21,
      26,    27,    29,    32,    33,    35,    36,    38,    39,    40,
      41,    42,    54,   103,   127,   128,   131,   132,   133,   134,
     140,   143,   144,   145,   146,   166,   167,   168,     3,    50,
     144,   143,   146,   147,    49,   129,   130,   144,   128,   128,
       3,    50,   128,    50,   127,   128,   159,   160,    54,   101,
     145,     0,   167,    50,     3,   141,   142,    55,   143,   146,
      49,    52,   100,   159,   160,    50,   132,   135,   136,   137,
     143,     3,     4,     5,     6,     9,    10,    13,    14,    15,
      22,    23,    24,    31,    34,    37,    43,    49,    51,    54,
      59,    73,    74,    84,    86,    88,    89,    90,   105,   106,
     107,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   125,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   144,   127,   159,     3,
      55,   128,   148,   149,   150,   151,     3,   102,   109,   122,
     126,   141,   100,    51,    52,   130,    50,   123,   155,   159,
     135,   137,    51,   136,    99,   138,   139,   144,   137,    99,
      49,   126,    49,    99,   157,    54,     3,    54,    49,   125,
      54,   109,    54,    54,   125,   137,   152,    54,   109,   109,
      54,    56,    58,    73,    74,    75,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,   100,   124,   111,    90,
      91,    92,    93,    94,    71,    72,    78,    79,    80,    81,
      82,    83,    95,    96,    97,    76,    77,    98,    49,    52,
      51,   161,    51,   157,    54,   101,   144,   146,   153,   154,
      55,    52,    52,    55,   102,    51,   126,   142,   155,   156,
      51,   126,    49,    52,    99,   157,    99,   157,    43,   162,
      49,   125,    49,   152,   125,   125,    55,    54,   146,   153,
      55,   152,    55,   108,   123,   125,     3,     3,   123,   111,
     111,   111,   112,   112,   113,   113,   114,   114,   114,   114,
     115,   115,   116,   117,   118,   119,   120,   125,   123,    51,
      55,   148,   153,   102,   126,   154,    54,   101,    47,   150,
       3,    51,    52,   139,   126,   157,    54,   162,    55,    55,
      55,    55,    50,   111,    55,    52,    55,    57,    99,    55,
      55,   102,    55,   148,   102,   126,    51,   155,   125,    55,
     125,   157,   157,   157,   156,   123,   122,    55,   102,    55,
     157,    55,    18,    51,    52,    49,   157,   157,    51
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,   104,   105,   105,   105,   106,   106,   106,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   108,   108,
     109,   109,   109,   109,   109,   109,   110,   110,   110,   110,
     110,   110,   111,   111,   112,   112,   112,   112,   113,   113,
     113,   114,   114,   114,   115,   115,   115,   115,   115,   116,
     116,   116,   117,   117,   118,   118,   119,   119,   120,   120,
     121,   121,   122,   122,   123,   123,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   125,   125,   126,
     127,   127,   128,   128,   128,   128,   128,   128,   129,   129,
     130,   130,   131,   131,   131,   131,   131,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   133,
     133,   133,   134,   134,   135,   135,   136,   137,   137,   137,
     137,   138,   138,   139,   139,   139,   140,   140,   140,   141,
     141,   142,   142,   143,   143,   144,   144,   145,   145,   145,
     145,   145,   145,   145,   146,   146,   146,   146,   147,   147,
     148,   148,   149,   149,   150,   150,   150,   151,   151,   152,
     152,   153,   153,   153,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   155,   155,   155,   156,   156,   157,   157,
     157,   157,   157,   157,   158,   158,   158,   159,   159,   159,
     159,   160,   160,   161,   161,   162,   162,   163,   163,   163,
     164,   164,   164,   164,   165,   165,   165,   165,   165,   166,
     166,   167,   167,   168,   168,   168,   168
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
  "\"question\"", "\";\"", "\"{\"", "\"}\"", "\",\"", "\":\"", "\"(\"",
  "\")\"", "\"[\"", "\"]\"", "\".\"", "\"~\"", "\"=\"", "\">>=\"",
  "\"<<=\"", "\"+=\"", "\"-=\"", "\"*=\"", "\"/=\"", "\"%=\"", "\"&=\"",
  "\"^=\"", "\"|=\"", "\">>\"", "\"<<\"", "\"++\"", "\"--\"", "\"->\"",
  "\"&&\"", "\"||\"", "\">=\"", "\"<=\"", "\">\"", "\"<\"", "\"==\"",
  "\"!=\"", "\"!\"", "\"^\"", "\"&\"", "\"|\"", "\"-\"", "\"+\"", "\"*\"",
  "\"/\"", "\"%\"", "'+'", "'-'", "'&'", "'^'", "'|'", "'?'", "':'", "'='",
  "'['", "']'", "'*'", "$accept", "primary_expression", "constant",
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
       0,   184,   184,   185,   186,   190,   195,   200,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   220,   226,
     236,   237,   238,   239,   240,   241,   245,   246,   247,   248,
     249,   250,   254,   255,   259,   260,   261,   262,   266,   267,
     268,   272,   273,   274,   278,   279,   280,   281,   282,   286,
     287,   288,   292,   293,   297,   298,   302,   303,   307,   308,
     312,   313,   317,   318,   322,   323,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   341,   342,   346,
     350,   351,   355,   356,   357,   358,   359,   360,   364,   365,
     369,   370,   374,   375,   376,   377,   378,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   397,
     398,   399,   403,   404,   408,   409,   413,   417,   418,   419,
     420,   424,   425,   429,   430,   431,   435,   436,   437,   441,
     442,   446,   447,   451,   452,   456,   457,   461,   462,   463,
     464,   465,   466,   467,   471,   472,   473,   474,   478,   479,
     484,   485,   489,   490,   494,   495,   496,   500,   501,   505,
     506,   510,   511,   512,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   528,   529,   530,   534,   535,   539,   540,
     541,   542,   543,   544,   548,   549,   550,   554,   555,   556,
     557,   561,   562,   566,   567,   571,   572,   576,   577,   578,
     582,   583,   584,   585,   589,   590,   591,   592,   593,   597,
     598,   602,   603,   607,   608,   609,   610
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
#line 2660 "parser.cpp"

#line 613 "parser.y"


// Bison expects us to provide implementation - otherwise linker complains
void WadeSpace::Parser::error(const location &loc , const std::string &message) {
        
        // Location should be initialized inside scanner action, but is not in this example.
        // Let's grab location directly from driver class.
    // cout << "Error: " << message << endl << "Location: " << loc << endl;
    
        cout << "Error: " << message << endl << "Error location: " << driver.location() << endl;
}
