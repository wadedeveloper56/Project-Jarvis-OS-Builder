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
#line 39 "parser.y"

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
      case symbol_kind::S_assignment_operator: // assignment_operator
        value.YY_MOVE_OR_COPY< AssignmentOperator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_constant: // constant
        value.YY_MOVE_OR_COPY< Constant > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enum_specifier: // enum_specifier
        value.YY_MOVE_OR_COPY< EnumSpecifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.YY_MOVE_OR_COPY< Enumerator > (YY_MOVE (that.value));
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

      case symbol_kind::S_storage_class_specifier: // storage_class_specifier
        value.YY_MOVE_OR_COPY< StorageClassSpecifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.YY_MOVE_OR_COPY< TypeSpecifier > (YY_MOVE (that.value));
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

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.YY_MOVE_OR_COPY< std::vector<Enumerator> > (YY_MOVE (that.value));
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
      case symbol_kind::S_assignment_operator: // assignment_operator
        value.move< AssignmentOperator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_constant: // constant
        value.move< Constant > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enum_specifier: // enum_specifier
        value.move< EnumSpecifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.move< Enumerator > (YY_MOVE (that.value));
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

      case symbol_kind::S_storage_class_specifier: // storage_class_specifier
        value.move< StorageClassSpecifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.move< TypeSpecifier > (YY_MOVE (that.value));
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

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.move< std::vector<Enumerator> > (YY_MOVE (that.value));
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
      case symbol_kind::S_assignment_operator: // assignment_operator
        value.copy< AssignmentOperator > (that.value);
        break;

      case symbol_kind::S_constant: // constant
        value.copy< Constant > (that.value);
        break;

      case symbol_kind::S_enum_specifier: // enum_specifier
        value.copy< EnumSpecifier > (that.value);
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.copy< Enumerator > (that.value);
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

      case symbol_kind::S_storage_class_specifier: // storage_class_specifier
        value.copy< StorageClassSpecifier > (that.value);
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.copy< TypeSpecifier > (that.value);
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

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.copy< std::vector<Enumerator> > (that.value);
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
      case symbol_kind::S_assignment_operator: // assignment_operator
        value.move< AssignmentOperator > (that.value);
        break;

      case symbol_kind::S_constant: // constant
        value.move< Constant > (that.value);
        break;

      case symbol_kind::S_enum_specifier: // enum_specifier
        value.move< EnumSpecifier > (that.value);
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.move< Enumerator > (that.value);
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

      case symbol_kind::S_storage_class_specifier: // storage_class_specifier
        value.move< StorageClassSpecifier > (that.value);
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.move< TypeSpecifier > (that.value);
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

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.move< std::vector<Enumerator> > (that.value);
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
      case symbol_kind::S_assignment_operator: // assignment_operator
        yylhs.value.emplace< AssignmentOperator > ();
        break;

      case symbol_kind::S_constant: // constant
        yylhs.value.emplace< Constant > ();
        break;

      case symbol_kind::S_enum_specifier: // enum_specifier
        yylhs.value.emplace< EnumSpecifier > ();
        break;

      case symbol_kind::S_enumerator: // enumerator
        yylhs.value.emplace< Enumerator > ();
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

      case symbol_kind::S_storage_class_specifier: // storage_class_specifier
        yylhs.value.emplace< StorageClassSpecifier > ();
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        yylhs.value.emplace< TypeSpecifier > ();
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

      case symbol_kind::S_enumerator_list: // enumerator_list
        yylhs.value.emplace< std::vector<Enumerator> > ();
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
#line 194 "parser.y"
                 { yylhs.value.as< Expression > () = Expression(yystack_[0].value.as < std::string > ()); cout << "IDENTIFIER REDUCE to primary_expression" << endl; }
#line 1319 "parser.cpp"
    break;

  case 3: // primary_expression: constant
#line 195 "parser.y"
               { yylhs.value.as< Expression > () = Expression(&yystack_[0].value.as < Constant > ()); cout << "constant REDUCE to primary_expression" << endl; }
#line 1325 "parser.cpp"
    break;

  case 4: // primary_expression: "(" expression ")"
#line 196 "parser.y"
                                { yylhs.value.as< Expression > () = yystack_[1].value.as < Expression > (); cout << "(expression) REDUCE to primary_expression" << endl; }
#line 1331 "parser.cpp"
    break;

  case 5: // constant: "f_const"
#line 200 "parser.y"
              {
                 long double &id = yystack_[0].value.as < long double > ();
                 cout << "F_CONST REDUCE to constant " << id << endl;
                 yylhs.value.as< Constant > () = Constant(id);
              }
#line 1341 "parser.cpp"
    break;

  case 6: // constant: "i_const"
#line 205 "parser.y"
              {
                 std::uint64_t &id = yystack_[0].value.as < uint64_t > ();
                 cout << "I_CONST REDUCE to constant " << id << endl;
                 yylhs.value.as< Constant > () = Constant(id);
              }
#line 1351 "parser.cpp"
    break;

  case 7: // constant: "sting_literal"
#line 210 "parser.y"
                      {
                 std::string &id = yystack_[0].value.as < std::string > ();
                 cout << "STRING_LITERAL REDUCE to constant  " << id << endl;
                 yylhs.value.as< Constant > () = Constant(id);
              }
#line 1361 "parser.cpp"
    break;

  case 8: // postfix_expression: primary_expression
#line 217 "parser.y"
                                                                   { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > (); cout << "primary_expression REDUCE to postfix_expression" << endl; }
#line 1367 "parser.cpp"
    break;

  case 9: // postfix_expression: postfix_expression "[" expression "]"
#line 218 "parser.y"
                                                                   { cout << "postfix_expression OBRACE expression CBRACE REDUCE to postfix_expression" << endl; }
#line 1373 "parser.cpp"
    break;

  case 10: // postfix_expression: postfix_expression "(" ")"
#line 219 "parser.y"
                                                                   { cout << "postfix_expression OPAREN CPAREN REDUCE to postfix_expression" << endl; }
#line 1379 "parser.cpp"
    break;

  case 11: // postfix_expression: postfix_expression "(" argument_expression_list ")"
#line 220 "parser.y"
                                                                   { cout << "postfix_expression OPAREN argument_expression_list CPAREN REDUCE to postfix_expression" << endl; }
#line 1385 "parser.cpp"
    break;

  case 12: // postfix_expression: postfix_expression "." "identifier"
#line 221 "parser.y"
                                                                   { cout << "postfix_expression PERIOD_OP IDENTIFIER REDUCE to postfix_expression" << endl; }
#line 1391 "parser.cpp"
    break;

  case 13: // postfix_expression: postfix_expression "->" "identifier"
#line 222 "parser.y"
                                                                   { cout << "postfix_expression PTR_OP IDENTIFIER REDUCE to postfix_expression" << endl; }
#line 1397 "parser.cpp"
    break;

  case 14: // postfix_expression: postfix_expression "++"
#line 223 "parser.y"
                                                                   { cout << "postfix_expression INC_OP REDUCE to postfix_expression" << endl; }
#line 1403 "parser.cpp"
    break;

  case 15: // postfix_expression: postfix_expression "--"
#line 224 "parser.y"
                                                                   { cout << "postfix_expression DEC_OP REDUCE to postfix_expression" << endl; }
#line 1409 "parser.cpp"
    break;

  case 16: // postfix_expression: "(" type_name ")" "{" initializer_list "}"
#line 225 "parser.y"
                                                                   { cout << "OPAREN type_name CPAREN_OP OCURLY_OP initializer_list CCURLY REDUCE to postfix_expression" << endl; }
#line 1415 "parser.cpp"
    break;

  case 17: // postfix_expression: "(" type_name ")" "{" initializer_list "," "}"
#line 226 "parser.y"
                                                                   { cout << "OPAREN type_name CPAREN_OP OCURLY_OP initializer_list COMMA CCURLY REDUCE to postfix_expression" << endl; }
#line 1421 "parser.cpp"
    break;

  case 18: // argument_expression_list: assignment_expression
#line 230 "parser.y"
                            {
                             Expression exp = yystack_[0].value.as < Expression > ();
                             yylhs.value.as < std::vector<Expression> > () = std::vector<Expression>();
                             yylhs.value.as < std::vector<Expression> > ().push_back(exp);
                             cout << "assignment_expression REDUCE argument_expression_list" << endl;
                            }
#line 1432 "parser.cpp"
    break;

  case 19: // argument_expression_list: argument_expression_list "," assignment_expression
#line 236 "parser.y"
                                                           {
            Expression value1 = yystack_[0].value.as < Expression > ();
            std::vector<Expression> &value2 = yystack_[2].value.as < std::vector<Expression> > ();
            value2.push_back(value1);
            yylhs.value.as < std::vector<Expression> > () = value2;
            cout << "argument_expression_list COMMA assignment_expression REDUCE argument_expression_list" << endl;
        }
#line 1444 "parser.cpp"
    break;

  case 20: // unary_expression: postfix_expression
#line 246 "parser.y"
                         { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > (); cout << "postfix_expression REDUCE unary_expression" << endl;}
#line 1450 "parser.cpp"
    break;

  case 21: // unary_expression: "++" unary_expression
#line 247 "parser.y"
                              { yylhs.value.as< Expression > () = Expression(yystack_[1].value.as < std::string > (),&yystack_[0].value.as < Expression > ()); cout << "INC_OP unary_expression REDUCE unary_expression" << endl;}
#line 1456 "parser.cpp"
    break;

  case 22: // unary_expression: "--" unary_expression
#line 248 "parser.y"
                              { yylhs.value.as< Expression > () = Expression(yystack_[1].value.as < std::string > (),&yystack_[0].value.as < Expression > ()); cout << "DEC_OP unary_expression REDUCE unary_expression" << endl;}
#line 1462 "parser.cpp"
    break;

  case 23: // unary_expression: unary_operator cast_expression
#line 249 "parser.y"
                                     { yylhs.value.as< Expression > () = Expression(yystack_[1].value.as < std::string > (),&yystack_[0].value.as < Expression > ()); cout << "unary_operator cast_expression REDUCE unary_expression" << endl;}
#line 1468 "parser.cpp"
    break;

  case 24: // unary_expression: "sizeof" unary_expression
#line 250 "parser.y"
                              { yylhs.value.as< Expression > () = Expression(); cout << "SIZEOF unary_expression REDUCE unary_expression" << endl;}
#line 1474 "parser.cpp"
    break;

  case 25: // unary_expression: "sizeof" "(" type_name ")"
#line 251 "parser.y"
                                     { yylhs.value.as< Expression > () = Expression(); cout << "SIZEOF OPAREN type_name CPAREN REDUCE unary_expression" << endl;}
#line 1480 "parser.cpp"
    break;

  case 26: // unary_operator: "&"
#line 255 "parser.y"
                {yylhs.value.as< std::string > () = yystack_[0].value.as < std::string > (); cout << "BIT_AND REDUCE to unary_operator" << endl;}
#line 1486 "parser.cpp"
    break;

  case 27: // unary_operator: "*"
#line 256 "parser.y"
                {yylhs.value.as< std::string > () = yystack_[0].value.as < std::string > (); cout << "TIMES_OP REDUCE to unary_operator" << endl;}
#line 1492 "parser.cpp"
    break;

  case 28: // unary_operator: "+"
#line 257 "parser.y"
                {yylhs.value.as< std::string > () = yystack_[0].value.as < std::string > (); cout << "PLUS_OP REDUCE to unary_operator" << endl;}
#line 1498 "parser.cpp"
    break;

  case 29: // unary_operator: "-"
#line 258 "parser.y"
                {yylhs.value.as< std::string > () = yystack_[0].value.as < std::string > (); cout << "MINUS_OP REDUCE to unary_operator" << endl;}
#line 1504 "parser.cpp"
    break;

  case 30: // unary_operator: "~"
#line 259 "parser.y"
                {yylhs.value.as< std::string > () = yystack_[0].value.as < std::string > (); cout << "TILDE REDUCE to unary_operator" << endl;}
#line 1510 "parser.cpp"
    break;

  case 31: // unary_operator: "!"
#line 260 "parser.y"
                {yylhs.value.as< std::string > () = yystack_[0].value.as < std::string > (); cout << "NOT_OP REDUCE to unary_operator" << endl;}
#line 1516 "parser.cpp"
    break;

  case 32: // cast_expression: unary_expression
#line 264 "parser.y"
                        { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "unary_expression REDUCE to cast_expression" << endl;}
#line 1522 "parser.cpp"
    break;

  case 33: // cast_expression: "(" type_name ")" cast_expression
#line 265 "parser.y"
                                               { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "unary_expression REDUCE to cast_expression" << endl;}
#line 1528 "parser.cpp"
    break;

  case 34: // multiplicative_expression: cast_expression
#line 269 "parser.y"
                       { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "cast_expression REDUCE to multiplicative_expression" << endl;}
#line 1534 "parser.cpp"
    break;

  case 35: // multiplicative_expression: multiplicative_expression "*" cast_expression
#line 270 "parser.y"
                                                         { cout << "multiplicative_expression TIMES_OP cast_expression REDUCE to multiplicative_expression" << endl;}
#line 1540 "parser.cpp"
    break;

  case 36: // multiplicative_expression: multiplicative_expression "/" cast_expression
#line 271 "parser.y"
                                                      { cout << "multiplicative_expression DIV_OP cast_expression REDUCE to multiplicative_expression" << endl;}
#line 1546 "parser.cpp"
    break;

  case 37: // multiplicative_expression: multiplicative_expression "%" cast_expression
#line 272 "parser.y"
                                                      { cout << "multiplicative_expression MOD_OP cast_expression REDUCE to multiplicative_expression" << endl;}
#line 1552 "parser.cpp"
    break;

  case 38: // additive_expression: multiplicative_expression
#line 276 "parser.y"
                                 { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "multiplicative_expression REDUCE to additive_expression" << endl;}
#line 1558 "parser.cpp"
    break;

  case 39: // additive_expression: additive_expression "+" multiplicative_expression
#line 277 "parser.y"
                                                             { cout << "additive_expression REDUCE to multiplicative_expression" << endl;}
#line 1564 "parser.cpp"
    break;

  case 40: // additive_expression: additive_expression "-" multiplicative_expression
#line 278 "parser.y"
                                                              { cout << "additive_expression REDUCE to multiplicative_expression" << endl;}
#line 1570 "parser.cpp"
    break;

  case 41: // shift_expression: additive_expression
#line 282 "parser.y"
                           { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "additive_expression REDUCE to shift_expression" << endl;}
#line 1576 "parser.cpp"
    break;

  case 42: // shift_expression: shift_expression "<<" additive_expression
#line 283 "parser.y"
                                                  { cout << "shift_expression LEFT_OP additive_expression REDUCE to shift_expression" << endl;}
#line 1582 "parser.cpp"
    break;

  case 43: // shift_expression: shift_expression ">>" additive_expression
#line 284 "parser.y"
                                                   { cout << "shift_expression RIGHT_OP additive_expression REDUCE to shift_expression" << endl;}
#line 1588 "parser.cpp"
    break;

  case 44: // relational_expression: shift_expression
#line 288 "parser.y"
                        { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "shift_expression REDUCE to relational_expression" << endl;}
#line 1594 "parser.cpp"
    break;

  case 45: // relational_expression: relational_expression "<" shift_expression
#line 289 "parser.y"
                                                       { cout << "relational_expression LESS_OP shift_expression REDUCE to shift_expression" << endl;}
#line 1600 "parser.cpp"
    break;

  case 46: // relational_expression: relational_expression ">" shift_expression
#line 290 "parser.y"
                                                           { cout << "relational_expression GREATER_OP shift_expression REDUCE to shift_expression" << endl;}
#line 1606 "parser.cpp"
    break;

  case 47: // relational_expression: relational_expression "<=" shift_expression
#line 291 "parser.y"
                                                             { cout << "relational_expression LESS_EQUAL_OP shift_expression REDUCE to shift_expression" << endl;}
#line 1612 "parser.cpp"
    break;

  case 48: // relational_expression: relational_expression ">=" shift_expression
#line 292 "parser.y"
                                                                { cout << "relational_expression GREATER_EQUAL_OP shift_expression REDUCE to shift_expression" << endl;}
#line 1618 "parser.cpp"
    break;

  case 49: // equality_expression: relational_expression
#line 296 "parser.y"
                             { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "relational_expression REDUCE to equality_expression" << endl;}
#line 1624 "parser.cpp"
    break;

  case 50: // equality_expression: equality_expression "==" relational_expression
#line 297 "parser.y"
                                                                { cout << "equality_expression EQUAL_EQUAL_OP relational_expression REDUCE to equality_expression" << endl;}
#line 1630 "parser.cpp"
    break;

  case 51: // equality_expression: equality_expression "!=" relational_expression
#line 298 "parser.y"
                                                              { cout << "equality_expression NOT_EQUAL_OP relational_expression REDUCE to equality_expression" << endl;}
#line 1636 "parser.cpp"
    break;

  case 52: // and_expression: equality_expression
#line 302 "parser.y"
                           { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "equality_expression REDUCE to and_expression" << endl;}
#line 1642 "parser.cpp"
    break;

  case 53: // and_expression: and_expression "&" equality_expression
#line 303 "parser.y"
                                                  { cout << "and_expression BIT_AND equality_expression REDUCE to and_expression" << endl;}
#line 1648 "parser.cpp"
    break;

  case 54: // exclusive_or_expression: and_expression
#line 307 "parser.y"
                      { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "and_expression REDUCE to exclusive_or_expression" << endl;}
#line 1654 "parser.cpp"
    break;

  case 55: // exclusive_or_expression: exclusive_or_expression "^" and_expression
#line 308 "parser.y"
                                                     { cout << "exclusive_or_expression XOR_OP and_expression REDUCE to exclusive_or_expression" << endl;}
#line 1660 "parser.cpp"
    break;

  case 56: // inclusive_or_expression: exclusive_or_expression
#line 312 "parser.y"
                               { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "exclusive_or_expression REDUCE to inclusive_or_expression" << endl;}
#line 1666 "parser.cpp"
    break;

  case 57: // inclusive_or_expression: inclusive_or_expression "|" exclusive_or_expression
#line 313 "parser.y"
                                                             { cout << "inclusive_or_expression BIT_OR exclusive_or_expression REDUCE to inclusive_or_expression" << endl;}
#line 1672 "parser.cpp"
    break;

  case 58: // logical_and_expression: inclusive_or_expression
#line 317 "parser.y"
                               { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "inclusive_or_expression REDUCE to logical_and_expression" << endl;}
#line 1678 "parser.cpp"
    break;

  case 59: // logical_and_expression: logical_and_expression "&&" inclusive_or_expression
#line 318 "parser.y"
                                                             { cout << "inclusive_or_expression REDUCE to logical_and_expression" << endl;}
#line 1684 "parser.cpp"
    break;

  case 60: // logical_or_expression: logical_and_expression
#line 322 "parser.y"
                              { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "inclusive_and_expression REDUCE to logical_or_expression" << endl;}
#line 1690 "parser.cpp"
    break;

  case 61: // logical_or_expression: logical_or_expression "||" logical_and_expression
#line 323 "parser.y"
                                                          { cout << "logical_or_expression OR_OP logical_and_expression REDUCE to logical_or_expression" << endl;}
#line 1696 "parser.cpp"
    break;

  case 62: // conditional_expression: logical_or_expression
#line 327 "parser.y"
                             { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "logical_or_expression REDUCE to conditional_expression" << endl;}
#line 1702 "parser.cpp"
    break;

  case 63: // conditional_expression: logical_or_expression "question" expression ":" conditional_expression
#line 328 "parser.y"
                                                                              { cout << "logical_or_expression QUESTION expression COLON conditional_expression REDUCE to conditional_expression" << endl;}
#line 1708 "parser.cpp"
    break;

  case 64: // assignment_expression: conditional_expression
#line 332 "parser.y"
                              { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "conditional_expression REDUCE to assignment_expression" << endl;}
#line 1714 "parser.cpp"
    break;

  case 65: // assignment_expression: unary_expression assignment_operator assignment_expression
#line 333 "parser.y"
                                                                  { cout << "unary_expression assignment_operator assignment_expression REDUCE to assignment_expression" << endl;}
#line 1720 "parser.cpp"
    break;

  case 66: // assignment_operator: "="
#line 337 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(yystack_[0].value.as < std::string > (),EQUAL_OP);  cout << "EQUAL_OP REDUCE to assignment_operator" << endl;}
#line 1726 "parser.cpp"
    break;

  case 67: // assignment_operator: "*="
#line 338 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(yystack_[0].value.as < std::string > (),MUL_ASSIGN);  cout << "MUL_ASSIGN REDUCE to assignment_operator" << endl;}
#line 1732 "parser.cpp"
    break;

  case 68: // assignment_operator: "/="
#line 339 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(yystack_[0].value.as < std::string > (),DIV_ASSIGN);  cout << "DIV_ASSIGN REDUCE to assignment_operator" << endl;}
#line 1738 "parser.cpp"
    break;

  case 69: // assignment_operator: "%="
#line 340 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(yystack_[0].value.as < std::string > (),MOD_ASSIGN);  cout << "MOG_ASSIGN REDUCE to assignment_operator" << endl;}
#line 1744 "parser.cpp"
    break;

  case 70: // assignment_operator: "+="
#line 341 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(yystack_[0].value.as < std::string > (),ADD_ASSIGN);  cout << "ADD_ASSIGN REDUCE to assignment_operator" << endl;}
#line 1750 "parser.cpp"
    break;

  case 71: // assignment_operator: "-="
#line 342 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(yystack_[0].value.as < std::string > (),SUB_ASSIGN);  cout << "SUB_ASSIGN REDUCE to assignment_operator" << endl;}
#line 1756 "parser.cpp"
    break;

  case 72: // assignment_operator: "<<="
#line 343 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(yystack_[0].value.as < std::string > (),LEFT_ASSIGN);  cout << "LEFT_ASSIGN REDUCE to assignment_operator" << endl;}
#line 1762 "parser.cpp"
    break;

  case 73: // assignment_operator: ">>="
#line 344 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(yystack_[0].value.as < std::string > (),RIGHT_ASSIGN);  cout << "RIGHT_ASSIGN REDUCE to assignment_operator" << endl;}
#line 1768 "parser.cpp"
    break;

  case 74: // assignment_operator: "&="
#line 345 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(yystack_[0].value.as < std::string > (),AND_ASSIGN);  cout << "AND_ASSIGN REDUCE to assignment_operator" << endl;}
#line 1774 "parser.cpp"
    break;

  case 75: // assignment_operator: "^="
#line 346 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(yystack_[0].value.as < std::string > (),XOR_ASSIGN);  cout << "XOR_ASSIGN REDUCE to assignment_operator" << endl;}
#line 1780 "parser.cpp"
    break;

  case 76: // assignment_operator: "|="
#line 347 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(yystack_[0].value.as < std::string > (),OR_ASSIGN);  cout << "OR_ASSIGN REDUCE to assignment_operator" << endl;}
#line 1786 "parser.cpp"
    break;

  case 77: // expression: assignment_expression
#line 351 "parser.y"
                             { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "asignment_expression REDUCE to expression" << endl;}
#line 1792 "parser.cpp"
    break;

  case 78: // expression: expression "," assignment_expression
#line 352 "parser.y"
                                              { cout << "expression COMMA assignment_expression COMMA  REDUCE to expression" << endl;}
#line 1798 "parser.cpp"
    break;

  case 79: // constant_expression: conditional_expression
#line 356 "parser.y"
                              { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "conditional_expression REDUCE to constant_expression" << endl;}
#line 1804 "parser.cpp"
    break;

  case 80: // declaration: declaration_specifiers ";"
#line 360 "parser.y"
                                        { cout << "declaration_specifiers SEMICOLON REDUCE to declaration" << endl;}
#line 1810 "parser.cpp"
    break;

  case 81: // declaration: declaration_specifiers init_declarator_list ";"
#line 361 "parser.y"
                                                             { cout << "declaration_specifiers init_declarator_list SEMICOLON REDUCE to declaration" << endl;}
#line 1816 "parser.cpp"
    break;

  case 82: // declaration_specifiers: storage_class_specifier
#line 365 "parser.y"
                                                      { cout << "storage_class_specifier REDUCE to declaration_specifiers" << endl;}
#line 1822 "parser.cpp"
    break;

  case 83: // declaration_specifiers: storage_class_specifier declaration_specifiers
#line 366 "parser.y"
                                                      { cout << "storage_class_specifier declaration_specifiers REDUCE to declaration_specifiers" << endl;}
#line 1828 "parser.cpp"
    break;

  case 84: // declaration_specifiers: type_specifier
#line 367 "parser.y"
                                                      { cout << "type_specifier REDUCE to declaration_specifiers" << endl;}
#line 1834 "parser.cpp"
    break;

  case 85: // declaration_specifiers: type_specifier declaration_specifiers
#line 368 "parser.y"
                                                      { cout << "type_specifier declaration_specifiers REDUCE to declaration_specifiers" << endl;}
#line 1840 "parser.cpp"
    break;

  case 86: // declaration_specifiers: type_qualifier
#line 369 "parser.y"
                                                      { cout << "type_qualifier REDUCE to declaration_specifiers" << endl;}
#line 1846 "parser.cpp"
    break;

  case 87: // declaration_specifiers: type_qualifier declaration_specifiers
#line 370 "parser.y"
                                                      { cout << "type_qualifier declaration_specifiers REDUCE to declaration_specifiers" << endl;}
#line 1852 "parser.cpp"
    break;

  case 88: // init_declarator_list: init_declarator
#line 374 "parser.y"
                                                 { cout << "init_declarator REDUCE to init_declarator_list" << endl;}
#line 1858 "parser.cpp"
    break;

  case 89: // init_declarator_list: init_declarator_list "," init_declarator
#line 375 "parser.y"
                                                 { cout << "init_declarator_list COMMA init_declarator REDUCE to init_declarator_list" << endl;}
#line 1864 "parser.cpp"
    break;

  case 90: // init_declarator: declarator
#line 379 "parser.y"
                                       { cout << "declarator REDUCE to init_declarator" << endl;}
#line 1870 "parser.cpp"
    break;

  case 91: // init_declarator: declarator "=" initializer
#line 380 "parser.y"
                                       { cout << "declarator EQUAL_OP initializer REDUCE to init_declarator" << endl;}
#line 1876 "parser.cpp"
    break;

  case 92: // storage_class_specifier: "typedef"
#line 384 "parser.y"
                { yylhs.value.as< StorageClassSpecifier > () = StorageClassSpecifier(yystack_[0].value.as < std::string > (),TYPEDEF); cout << "TYPEDEF REDUCE to storage_class_specifier" << endl;}
#line 1882 "parser.cpp"
    break;

  case 93: // storage_class_specifier: "extern"
#line 385 "parser.y"
                { yylhs.value.as< StorageClassSpecifier > () = StorageClassSpecifier(yystack_[0].value.as < std::string > (),EXTERN); cout << "EXTERN REDUCE to storage_class_specifier" << endl;}
#line 1888 "parser.cpp"
    break;

  case 94: // storage_class_specifier: "static"
#line 386 "parser.y"
                { yylhs.value.as< StorageClassSpecifier > () = StorageClassSpecifier(yystack_[0].value.as < std::string > (),STATIC); cout << "STATIC REDUCE to storage_class_specifier" << endl;}
#line 1894 "parser.cpp"
    break;

  case 95: // storage_class_specifier: "auto"
#line 387 "parser.y"
                { yylhs.value.as< StorageClassSpecifier > () = StorageClassSpecifier(yystack_[0].value.as < std::string > (),AUTO); cout << "AUTO REDUCE to storage_class_specifier" << endl;}
#line 1900 "parser.cpp"
    break;

  case 96: // storage_class_specifier: "register"
#line 388 "parser.y"
                { yylhs.value.as< StorageClassSpecifier > () = StorageClassSpecifier(yystack_[0].value.as < std::string > (),REGISTER); cout << "REGISTER REDUCE to storage_class_specifier" << endl;}
#line 1906 "parser.cpp"
    break;

  case 97: // type_specifier: "void"
#line 392 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(yystack_[0].value.as < std::string > (),VOID); cout << "VOID REDUCE to type_specifier" << endl;}
#line 1912 "parser.cpp"
    break;

  case 98: // type_specifier: "char"
#line 393 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(yystack_[0].value.as < std::string > (),CHAR); cout << "CHAR REDUCE to type_specifier" << endl;}
#line 1918 "parser.cpp"
    break;

  case 99: // type_specifier: "short"
#line 394 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(yystack_[0].value.as < std::string > (),SHORT); cout << "SHORT REDUCE to type_specifier" << endl;}
#line 1924 "parser.cpp"
    break;

  case 100: // type_specifier: "int"
#line 395 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(yystack_[0].value.as < std::string > (),INT); cout << "INT REDUCE to type_specifier" << endl;}
#line 1930 "parser.cpp"
    break;

  case 101: // type_specifier: "long"
#line 396 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(yystack_[0].value.as < std::string > (),LONG); cout << "LONG REDUCE to type_specifier" << endl;}
#line 1936 "parser.cpp"
    break;

  case 102: // type_specifier: "float"
#line 397 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(yystack_[0].value.as < std::string > (),FLOAT); cout << "FLOAT REDUCE to type_specifier" << endl;}
#line 1942 "parser.cpp"
    break;

  case 103: // type_specifier: "double"
#line 398 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(yystack_[0].value.as < std::string > (),DOUBLE); cout << "DOUBLE REDUCE to type_specifier" << endl;}
#line 1948 "parser.cpp"
    break;

  case 104: // type_specifier: "signed"
#line 399 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(yystack_[0].value.as < std::string > (),SIGNED); cout << "SIGNED REDUCE to type_specifier" << endl;}
#line 1954 "parser.cpp"
    break;

  case 105: // type_specifier: "unsigned"
#line 400 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(yystack_[0].value.as < std::string > (),UNSIGNED); cout << "UNIGNED REDUCE to type_specifier" << endl;}
#line 1960 "parser.cpp"
    break;

  case 106: // type_specifier: struct_or_union_specifier
#line 401 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(); cout << "struct_or_union_specifier REDUCE to type_specifier" << endl;}
#line 1966 "parser.cpp"
    break;

  case 107: // type_specifier: enum_specifier
#line 402 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier();/*"enum_specifier",&$1);*/ cout << "enum_specifier REDUCE to type_specifier" << endl;}
#line 1972 "parser.cpp"
    break;

  case 108: // type_specifier: "type name"
#line 403 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(yystack_[0].value.as < std::string > (),TYPE_NAME); cout << "TYPE_NAME REDUCE to type_specifier" << endl;}
#line 1978 "parser.cpp"
    break;

  case 126: // enum_specifier: "enum" "{" enumerator_list "}"
#line 445 "parser.y"
                                                     { yylhs.value.as< EnumSpecifier > () = EnumSpecifier("",&yystack_[1].value.as < std::vector<Enumerator> > ()); cout << "ENUM OCURLY enumerator_list CCURLY REDUCE to enum_specifier" << endl;}
#line 1984 "parser.cpp"
    break;

  case 127: // enum_specifier: "enum" "identifier" "{" enumerator_list "}"
#line 446 "parser.y"
                                                     { yylhs.value.as< EnumSpecifier > () = EnumSpecifier(yystack_[3].value.as < std::string > (),&yystack_[1].value.as < std::vector<Enumerator> > ()); cout << "ENUM IDENTIFIER OCURLY enumerator_list CCURLY REDUCE to enum_specifier" << endl;}
#line 1990 "parser.cpp"
    break;

  case 128: // enum_specifier: "enum" "identifier"
#line 447 "parser.y"
                                                     { yylhs.value.as< EnumSpecifier > () = EnumSpecifier(yystack_[0].value.as < std::string > (),NULL); cout << "ENUM IDENTIFIER REDUCE to enum_specifier" << endl;}
#line 1996 "parser.cpp"
    break;

  case 129: // enumerator_list: enumerator
#line 451 "parser.y"
                                        {
                                          Enumerator exp = yystack_[0].value.as < Enumerator > ();
                                          yylhs.value.as < std::vector<Enumerator> > () = std::vector<Enumerator>();
                                          yylhs.value.as < std::vector<Enumerator> > ().push_back(exp);
                                          cout << "enumerator REDUCE enumerator_list" << endl;
                                        }
#line 2007 "parser.cpp"
    break;

  case 130: // enumerator_list: enumerator_list "," enumerator
#line 457 "parser.y"
                                        {
                                          Enumerator value1 = yystack_[0].value.as < Enumerator > ();
                                          std::vector<Enumerator> &value2 = yystack_[2].value.as < std::vector<Enumerator> > ();
                                          value2.push_back(value1);
                                          yylhs.value.as < std::vector<Enumerator> > () = value2;
                                          cout << "enumerator_list COMMA enumerator REDUCE enumerator_list" << endl;
                                        }
#line 2019 "parser.cpp"
    break;

  case 131: // enumerator: "identifier"
#line 467 "parser.y"
                                              { yylhs.value.as< Enumerator > () = Enumerator(yystack_[0].value.as < std::string > (),NULL); cout << "IDENTIFIER REDUCE to ENUMERATOR" << endl;}
#line 2025 "parser.cpp"
    break;

  case 132: // enumerator: "identifier" "=" constant_expression
#line 468 "parser.y"
                                              { yylhs.value.as< Enumerator > () = Enumerator(yystack_[2].value.as < std::string > (),&yystack_[0].value.as < Expression > ()); cout << "IDENTIFIER EQUAL_OP constant_expression REDUCE to ENUMERATOR" << endl;}
#line 2031 "parser.cpp"
    break;

  case 209: // translation_unit: external_declaration
#line 618 "parser.y"
                                            { cout << "external_declaration REDUCE to translation_unit" << endl; }
#line 2037 "parser.cpp"
    break;

  case 210: // translation_unit: translation_unit external_declaration
#line 619 "parser.y"
                                            { cout << "translation_unit external_declaration REDUCE to translation_unit" << endl; }
#line 2043 "parser.cpp"
    break;

  case 211: // external_declaration: function_definition
#line 623 "parser.y"
                           { cout << "function_definition REDUCE to external_declaration" << endl; }
#line 2049 "parser.cpp"
    break;

  case 212: // external_declaration: declaration
#line 624 "parser.y"
                           { cout << "declaration REDUCE to external_declaration" << endl; }
#line 2055 "parser.cpp"
    break;


#line 2059 "parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -196;

  const signed char  Parser ::yytable_ninf_ = -1;

  const short
   Parser ::yypact_[] =
  {
     372,  -196,  -196,  -196,  -196,  -196,  -196,    26,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,     6,     7,  -196,     5,  1619,  1619,  -196,    38,
    -196,  1619,  1546,   -42,     8,   283,  -196,  -196,   -26,    43,
       1,  -196,  -196,     7,  -196,    55,  -196,  1355,  -196,  -196,
      22,  1655,  -196,   597,  -196,     5,  -196,  1546,  1400,   391,
     -42,  -196,  -196,    43,    23,    41,  -196,  -196,  -196,  -196,
    -196,     6,  1137,  -196,  1546,  1655,  1655,  1474,  -196,    14,
    1655,    24,  -196,  -196,  -196,    36,  1229,    49,    85,  1037,
      65,   125,   100,   749,  1262,   127,   129,  -196,  -196,   773,
    -196,  1271,  1271,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
      60,   371,  1229,  -196,   145,   -24,   185,    61,   148,    99,
     102,    59,   117,   -34,  -196,  -196,    75,  -196,  -196,  -196,
     685,   861,  -196,  -196,  -196,  -196,   140,  -196,  -196,  -196,
    -196,    17,   147,   173,  -196,    92,  -196,  -196,  -196,  -196,
     123,   208,  1229,  -196,    43,  -196,  1137,  -196,  -196,  -196,
    1510,  -196,  -196,  -196,  1229,   104,  -196,   175,  -196,  1037,
    -196,   187,  -196,  1037,   205,  1155,   201,  1229,  -196,   106,
     773,  -196,  1229,  1229,   136,   -15,   199,   773,  -196,  -196,
     923,  1229,   258,  -196,  -196,   260,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  1229,  -196,  1229,
    1229,  1229,  1229,  1229,  1229,  1229,  1229,  1229,  1229,  1229,
    1229,  1229,  1229,  1229,  1229,  1229,  1229,  1229,  -196,  1229,
    -196,   949,  -196,  -196,   327,   424,  -196,    20,  -196,   -38,
    -196,  1582,   263,  -196,  -196,  -196,  -196,  -196,  -196,   217,
    -196,  -196,  -196,    14,  1229,  -196,  1037,  -196,   228,  1155,
    -196,   149,  -196,   234,   159,   163,  -196,   532,   -32,  -196,
    1196,   237,  -196,   164,  -196,    27,  -196,  -196,  -196,  -196,
    -196,  -196,   145,   145,   -24,   -24,   185,   185,   185,   185,
      61,    61,   148,    99,   102,    59,   219,   117,  -196,  -196,
    -196,   241,   242,  -196,   204,   -38,  1437,   448,  -196,  -196,
    -196,  -196,  1078,  -196,  -196,  -196,  1229,  1253,  1037,   250,
    1037,  1037,  1137,  -196,   250,  1229,  -196,  -196,  1229,  -196,
    -196,  -196,  -196,   246,  -196,   211,  -196,  -196,   168,  1037,
     172,   289,  -196,  -196,   222,  -196,  -196,  -196,  -196,   259,
    -196,  1037,  1037,  -196,  1096,  -196,  -196,  -196,  -196
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
       0,     0,     0,    14,    15,     0,    66,    73,    72,    70,
      71,    67,    68,    69,    74,    75,    76,     0,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   196,     0,
     189,     0,   188,   194,     0,     0,   154,   161,   155,   162,
     141,     0,     0,   142,   139,   127,   132,   130,   176,     0,
     109,   124,   116,     0,     0,   184,     0,   186,     0,     0,
     204,     0,   208,     0,     0,     0,     4,     0,   161,   160,
       0,     0,    10,     0,    18,     0,    12,    13,    65,    35,
      36,    37,    40,    39,    43,    42,    48,    47,    46,    45,
      50,    51,    53,    55,    57,    59,     0,    61,    78,   190,
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
    -196,  -196,  -196,  -196,  -196,   -49,  -196,   -80,    63,    66,
     -68,    67,    89,    91,    93,   101,   105,  -196,   -58,   -70,
    -196,    12,   -56,    13,     0,  -196,   256,  -196,   133,  -196,
    -196,   261,   -43,   -55,  -196,    78,  -196,   270,   186,    46,
      11,   -30,    -5,  -196,   -53,  -196,   103,  -196,  -140,  -135,
    -195,   -69,    19,   -74,  -196,   165,    28,   212,  -168,  -196,
    -196,  -196,  -196,   310,  -196
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
      25,   149,   157,   158,    60,   142,   238,   259,     1,     1,
     148,     1,    58,    24,   226,   174,   306,     1,    42,     5,
       1,   161,   267,     1,    63,   168,    48,    49,   149,    38,
     171,    52,   208,    40,   163,    25,    47,   148,    69,   267,
     263,    50,   305,   227,   185,   181,    64,   271,    24,    21,
     269,    59,   188,   189,    44,   307,    67,   233,   141,    22,
      22,   235,    22,   148,   212,   213,   136,   164,    22,    41,
     137,   234,    75,   305,   234,    74,    39,   169,   235,   229,
      23,   130,   136,   152,   327,   170,   157,   137,    51,    68,
     167,   317,   153,   154,   149,   255,   246,    80,   172,   257,
      23,    23,    23,   148,    70,   179,   149,    71,   251,    23,
     235,   184,    23,   235,   190,   148,   191,   163,   192,   175,
     274,    80,    80,    80,   228,   185,    80,   229,   176,   279,
     280,   281,   185,   193,   194,   195,   237,   278,   173,   216,
     217,   218,   219,   137,   242,    80,   224,   243,   286,   287,
     288,   289,   236,   252,   177,   262,   253,   233,   229,   298,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   149,   148,   304,
     268,   182,   315,   183,    76,   222,   148,   223,   229,   261,
     323,   266,   184,   225,   264,   265,   149,    56,   314,   184,
      72,   229,   240,   275,   318,   148,    80,    60,    76,    76,
      76,   229,    73,    76,   320,   229,   325,   244,   321,   326,
     229,   148,   138,   349,   229,   241,    80,   351,   254,   237,
     220,   221,    76,    80,   141,   209,   210,   211,   296,   159,
     256,   141,   157,   337,   341,    40,   342,   343,   258,   149,
     260,   335,   157,   333,   270,   345,   214,   215,   148,   245,
     154,   276,   268,   277,   167,   350,   310,   141,   311,   312,
     346,   229,   328,   353,   354,   282,   283,   356,   357,   148,
     284,   285,   316,    61,   157,   337,     1,   290,   291,   319,
       2,     3,   324,    76,     4,     5,   329,   330,   331,     6,
     322,   347,     7,     8,     9,   348,   141,   352,   355,    10,
      11,   292,    12,    76,   293,    13,    14,   294,    15,    16,
      76,    17,    18,    19,    20,    21,   295,   155,   338,   340,
       1,   313,   297,   151,     2,     3,   160,    22,     4,     5,
     247,   344,   231,     6,   309,    62,     7,     8,     9,     0,
       0,     0,     0,    10,    11,     0,    12,     0,     0,    13,
      14,     0,    15,    16,     0,    17,    18,    19,    20,    21,
       0,     0,     0,     0,     0,     1,     0,     0,    23,     2,
       3,   234,   300,     4,     5,     0,     0,     0,     6,     0,
       0,     7,     8,     9,   146,    82,    83,    84,    10,    11,
       0,    12,     0,     0,    13,    14,     0,    15,    16,     0,
      17,    18,    19,    20,    21,     0,     0,     0,     0,     0,
     235,     0,    23,     0,     0,    94,    22,   146,    82,    83,
      84,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,     0,     0,     0,    99,     0,     0,     0,     0,
     100,   146,    82,    83,    84,     0,     0,     0,    94,     0,
       0,     0,     0,     0,   101,   102,     0,    23,     0,     0,
       0,     0,     0,     0,     0,   103,     0,   104,    99,   105,
     106,   107,    94,   100,     0,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   101,   102,     0,
       0,     0,    99,     0,     0,     0,     0,   100,   103,     0,
     104,     0,   105,   106,   107,     0,     0,     0,   303,     0,
       0,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   103,     0,   104,     0,   105,   106,   107,     2,
       3,     0,   334,     4,     5,     0,     0,     0,     6,     0,
       0,     7,     8,     9,     0,     0,     0,     0,    10,    11,
       0,    12,     0,     0,    13,    14,     0,    15,    16,     0,
      17,    18,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   267,   300,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,    82,    83,    84,     2,     3,    85,    86,     4,     5,
      87,    88,    89,     6,     0,     0,     7,     8,     9,    90,
      91,    92,     0,    10,    11,   235,    12,    23,    93,    13,
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
     105,   106,   107,     0,     0,   103,     0,   104,     0,   105,
     106,   107,     2,     3,     0,     0,     4,     5,     0,     0,
       0,     6,     0,     0,     7,     8,     9,     0,     0,     0,
       0,    10,    11,     0,    12,     0,     0,    13,    14,     0,
      15,    16,     0,    17,    18,    19,    20,    21,     0,     0,
       0,     0,     0,   139,     0,    53,     0,     2,     3,     0,
       0,     4,     5,     0,     0,    72,     6,     0,     0,     7,
       8,     9,     0,     0,     0,     0,    10,    11,     0,    12,
       0,     0,    13,    14,     0,    15,    16,     0,    17,    18,
      19,    20,    21,     0,     2,     3,     0,     0,     4,     5,
       0,     0,     0,     6,     0,   140,     7,     8,     9,     0,
       0,     0,     0,    10,    11,     0,    12,     0,     0,    13,
      14,     0,    15,    16,     0,    17,    18,    19,    20,    21,
       0,     2,     0,     0,     0,     4,     5,     0,     0,     0,
       6,     0,   332,     7,     0,     9,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    13,    14,     0,     0,
      16,     0,     0,    18,    19,    20,    21,     2,     0,     0,
       0,     4,     5,     0,     0,   162,     6,     0,     0,     7,
       0,     9,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    13,    14,     0,     0,    16,     0,     0,    18,
      19,    20,    21,     2,     3,     0,     0,     4,     5,     0,
       0,   250,     6,     0,     0,     7,     8,     9,     0,     0,
       0,     0,    10,    11,     0,    12,     0,     0,    13,    14,
       0,    15,    16,     0,    17,    18,    19,    20,    21,     2,
       3,     0,     0,     4,     5,     0,    53,     0,     6,     0,
       0,     7,     8,     9,     0,     0,     0,     0,    10,    11,
       0,    12,     0,     0,    13,    14,     0,    15,    16,     0,
      17,    18,    19,    20,    21,     0,     2,     3,     0,   308,
       4,     5,     0,     0,     0,     6,     0,     0,     7,     8,
       9,     0,     0,     0,     0,    10,    11,     0,    12,     0,
       0,    13,    14,     0,    15,    16,     0,    17,    18,    19,
      20,    21,     2,     0,     0,     0,     4,     5,     0,     0,
       0,     6,     0,     0,     7,     0,     9,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    13,    14,     0,
       0,    16,     0,     0,    18,    19,    20,    21
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    59,    72,    72,    34,    58,   141,   175,     3,     3,
      59,     3,    54,     0,    48,    89,    54,     3,    23,    12,
       3,    76,    54,     3,    50,    80,    26,    27,    86,     3,
      86,    31,   112,    22,    77,    35,    25,    86,    43,    54,
     180,     3,   237,    77,    99,    94,     3,   187,    35,    42,
     185,    93,   101,   102,    49,    93,    55,   131,    58,    54,
      54,    93,    54,   112,    88,    89,    55,    53,    54,    23,
      57,    54,    50,   268,    54,    47,    50,    53,    93,    52,
      95,    53,    71,    60,    57,    49,   156,    74,    50,    43,
      79,   259,    51,    52,   152,   169,   152,    51,    49,   173,
      95,    95,    95,   152,    49,    93,   164,    52,   164,    95,
      93,    99,    95,    93,    54,   164,    56,   160,    58,    54,
     190,    75,    76,    77,    49,   180,    80,    52,     3,   209,
     210,   211,   187,    73,    74,    75,   141,   207,    53,    78,
      79,    80,    81,   130,    52,    99,    87,    55,   216,   217,
     218,   219,   141,    49,    54,    49,    52,   231,    52,   229,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   235,   227,   235,
     185,    54,   256,    54,    51,    86,   235,    85,    52,   177,
     270,    55,   180,    76,   182,   183,   254,    32,   254,   187,
      60,    52,    55,   191,    55,   254,   160,   237,    75,    76,
      77,    52,    47,    80,    55,    52,    52,    94,    55,    55,
      52,   270,    57,    55,    52,    52,   180,    55,    53,   234,
      82,    83,    99,   187,   234,    90,    91,    92,   226,    74,
      53,   241,   312,   312,   318,   234,   320,   321,    43,   307,
      49,   307,   322,   306,    55,   325,    71,    72,   307,    51,
      52,     3,   267,     3,   253,   339,     3,   267,    51,    52,
     328,    52,    53,    51,    52,   212,   213,   351,   352,   328,
     214,   215,    54,     0,   354,   354,     3,   220,   221,    55,
       7,     8,    55,   160,    11,    12,    55,    55,    94,    16,
      50,    55,    19,    20,    21,    94,   306,    18,    49,    26,
      27,   222,    29,   180,   223,    32,    33,   224,    35,    36,
     187,    38,    39,    40,    41,    42,   225,    71,   316,   317,
       3,   253,   227,    63,     7,     8,    75,    54,    11,    12,
     154,   322,   130,    16,   241,    35,    19,    20,    21,    -1,
      -1,    -1,    -1,    26,    27,    -1,    29,    -1,    -1,    32,
      33,    -1,    35,    36,    -1,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    95,     7,
       8,    54,    55,    11,    12,    -1,    -1,    -1,    16,    -1,
      -1,    19,    20,    21,     3,     4,     5,     6,    26,    27,
      -1,    29,    -1,    -1,    32,    33,    -1,    35,    36,    -1,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      93,    -1,    95,    -1,    -1,    34,    54,     3,     4,     5,
       6,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      59,     3,     4,     5,     6,    -1,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    73,    74,    -1,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    86,    54,    88,
      89,    90,    34,    59,    -1,    94,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    59,    84,    -1,
      86,    -1,    88,    89,    90,    -1,    -1,    -1,    94,    -1,
      -1,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    -1,    86,    -1,    88,    89,    90,     7,
       8,    -1,    94,    11,    12,    -1,    -1,    -1,    16,    -1,
      -1,    19,    20,    21,    -1,    -1,    -1,    -1,    26,    27,
      -1,    29,    -1,    -1,    32,    33,    -1,    35,    36,    -1,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    93,    29,    95,    31,    32,
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
      88,    89,    90,    -1,    -1,    84,    -1,    86,    -1,    88,
      89,    90,     7,     8,    -1,    -1,    11,    12,    -1,    -1,
      -1,    16,    -1,    -1,    19,    20,    21,    -1,    -1,    -1,
      -1,    26,    27,    -1,    29,    -1,    -1,    32,    33,    -1,
      35,    36,    -1,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    50,    -1,     7,     8,    -1,
      -1,    11,    12,    -1,    -1,    60,    16,    -1,    -1,    19,
      20,    21,    -1,    -1,    -1,    -1,    26,    27,    -1,    29,
      -1,    -1,    32,    33,    -1,    35,    36,    -1,    38,    39,
      40,    41,    42,    -1,     7,     8,    -1,    -1,    11,    12,
      -1,    -1,    -1,    16,    -1,    55,    19,    20,    21,    -1,
      -1,    -1,    -1,    26,    27,    -1,    29,    -1,    -1,    32,
      33,    -1,    35,    36,    -1,    38,    39,    40,    41,    42,
      -1,     7,    -1,    -1,    -1,    11,    12,    -1,    -1,    -1,
      16,    -1,    55,    19,    -1,    21,    -1,    -1,    -1,    -1,
      26,    27,    -1,    -1,    -1,    -1,    32,    33,    -1,    -1,
      36,    -1,    -1,    39,    40,    41,    42,     7,    -1,    -1,
      -1,    11,    12,    -1,    -1,    51,    16,    -1,    -1,    19,
      -1,    21,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,
      -1,    -1,    32,    33,    -1,    -1,    36,    -1,    -1,    39,
      40,    41,    42,     7,     8,    -1,    -1,    11,    12,    -1,
      -1,    51,    16,    -1,    -1,    19,    20,    21,    -1,    -1,
      -1,    -1,    26,    27,    -1,    29,    -1,    -1,    32,    33,
      -1,    35,    36,    -1,    38,    39,    40,    41,    42,     7,
       8,    -1,    -1,    11,    12,    -1,    50,    -1,    16,    -1,
      -1,    19,    20,    21,    -1,    -1,    -1,    -1,    26,    27,
      -1,    29,    -1,    -1,    32,    33,    -1,    35,    36,    -1,
      38,    39,    40,    41,    42,    -1,     7,     8,    -1,    47,
      11,    12,    -1,    -1,    -1,    16,    -1,    -1,    19,    20,
      21,    -1,    -1,    -1,    -1,    26,    27,    -1,    29,    -1,
      -1,    32,    33,    -1,    35,    36,    -1,    38,    39,    40,
      41,    42,     7,    -1,    -1,    -1,    11,    12,    -1,    -1,
      -1,    16,    -1,    -1,    19,    -1,    21,    -1,    -1,    -1,
      -1,    26,    27,    -1,    -1,    -1,    -1,    32,    33,    -1,
      -1,    36,    -1,    -1,    39,    40,    41,    42
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     7,     8,    11,    12,    16,    19,    20,    21,
      26,    27,    29,    32,    33,    35,    36,    38,    39,    40,
      41,    42,    54,    95,   119,   120,   123,   124,   125,   126,
     132,   135,   136,   137,   138,   158,   159,   160,     3,    50,
     136,   135,   138,   139,    49,   121,   122,   136,   120,   120,
       3,    50,   120,    50,   119,   120,   151,   152,    54,    93,
     137,     0,   159,    50,     3,   133,   134,    55,   135,   138,
      49,    52,    60,   151,   152,    50,   124,   127,   128,   129,
     135,     3,     4,     5,     6,     9,    10,    13,    14,    15,
      22,    23,    24,    31,    34,    37,    43,    49,    51,    54,
      59,    73,    74,    84,    86,    88,    89,    90,    97,    98,
      99,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   117,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   136,   119,   151,     3,
      55,   120,   140,   141,   142,   143,     3,    94,   101,   114,
     118,   133,    60,    51,    52,   122,    50,   115,   147,   151,
     127,   129,    51,   128,    53,   130,   131,   136,   129,    53,
      49,   118,    49,    53,   149,    54,     3,    54,    49,   117,
      54,   101,    54,    54,   117,   129,   144,    54,   101,   101,
      54,    56,    58,    73,    74,    75,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,   116,   103,    90,
      91,    92,    88,    89,    71,    72,    78,    79,    80,    81,
      82,    83,    86,    85,    87,    76,    48,    77,    49,    52,
      51,   153,    51,   149,    54,    93,   136,   138,   145,   146,
      55,    52,    52,    55,    94,    51,   118,   134,   147,   148,
      51,   118,    49,    52,    53,   149,    53,   149,    43,   154,
      49,   117,    49,   144,   117,   117,    55,    54,   138,   145,
      55,   144,    55,   100,   115,   117,     3,     3,   115,   103,
     103,   103,   104,   104,   105,   105,   106,   106,   106,   106,
     107,   107,   108,   109,   110,   111,   117,   112,   115,    51,
      55,   140,   145,    94,   118,   146,    54,    93,    47,   142,
       3,    51,    52,   131,   118,   149,    54,   154,    55,    55,
      55,    55,    50,   103,    55,    52,    55,    57,    53,    55,
      55,    94,    55,   140,    94,   118,    51,   147,   117,    55,
     117,   149,   149,   149,   148,   115,   114,    55,    94,    55,
     149,    55,    18,    51,    52,    49,   149,   149,    51
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    96,    97,    97,    97,    98,    98,    98,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,   100,   100,
     101,   101,   101,   101,   101,   101,   102,   102,   102,   102,
     102,   102,   103,   103,   104,   104,   104,   104,   105,   105,
     105,   106,   106,   106,   107,   107,   107,   107,   107,   108,
     108,   108,   109,   109,   110,   110,   111,   111,   112,   112,
     113,   113,   114,   114,   115,   115,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   117,   117,   118,
     119,   119,   120,   120,   120,   120,   120,   120,   121,   121,
     122,   122,   123,   123,   123,   123,   123,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   125,
     125,   125,   126,   126,   127,   127,   128,   129,   129,   129,
     129,   130,   130,   131,   131,   131,   132,   132,   132,   133,
     133,   134,   134,   135,   135,   136,   136,   137,   137,   137,
     137,   137,   137,   137,   138,   138,   138,   138,   139,   139,
     140,   140,   141,   141,   142,   142,   142,   143,   143,   144,
     144,   145,   145,   145,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   147,   147,   147,   148,   148,   149,   149,
     149,   149,   149,   149,   150,   150,   150,   151,   151,   151,
     151,   152,   152,   153,   153,   154,   154,   155,   155,   155,
     156,   156,   156,   156,   157,   157,   157,   157,   157,   158,
     158,   159,   159,   160,   160,   160,   160
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
  "\"/\"", "\"%\"", "'['", "']'", "'*'", "$accept", "primary_expression",
  "constant", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
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
       0,   194,   194,   195,   196,   200,   205,   210,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   230,   236,
     246,   247,   248,   249,   250,   251,   255,   256,   257,   258,
     259,   260,   264,   265,   269,   270,   271,   272,   276,   277,
     278,   282,   283,   284,   288,   289,   290,   291,   292,   296,
     297,   298,   302,   303,   307,   308,   312,   313,   317,   318,
     322,   323,   327,   328,   332,   333,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   351,   352,   356,
     360,   361,   365,   366,   367,   368,   369,   370,   374,   375,
     379,   380,   384,   385,   386,   387,   388,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   407,
     408,   409,   413,   414,   418,   419,   423,   427,   428,   429,
     430,   434,   435,   439,   440,   441,   445,   446,   447,   451,
     457,   467,   468,   472,   473,   477,   478,   482,   483,   484,
     485,   486,   487,   488,   492,   493,   494,   495,   499,   500,
     505,   506,   510,   511,   515,   516,   517,   521,   522,   526,
     527,   531,   532,   533,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   549,   550,   551,   555,   556,   560,   561,
     562,   563,   564,   565,   569,   570,   571,   575,   576,   577,
     578,   582,   583,   587,   588,   592,   593,   597,   598,   599,
     603,   604,   605,   606,   610,   611,   612,   613,   614,   618,
     619,   623,   624,   628,   629,   630,   631
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
#line 3074 "parser.cpp"

#line 634 "parser.y"


// Bison expects us to provide implementation - otherwise linker complains
void WadeSpace::Parser::error(const location &loc , const std::string &message) {
        
        // Location should be initialized inside scanner action, but is not in this example.
        // Let's grab location directly from driver class.
    // cout << "Error: " << message << endl << "Location: " << loc << endl;
    
        cout << "Error: " << message << endl << "Error location: " << driver.location() << endl;
}
