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
#line 50 "parser.y"

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
      case symbol_kind::S_abstract_declarator: // abstract_declarator
        value.YY_MOVE_OR_COPY< AbstractDeclarator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
        value.YY_MOVE_OR_COPY< AssignmentOperator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_constant: // constant
        value.YY_MOVE_OR_COPY< Constant > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
        value.YY_MOVE_OR_COPY< DeclarationSpecifiers > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declarator: // declarator
        value.YY_MOVE_OR_COPY< Declarator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_direct_abstract_declarator: // direct_abstract_declarator
        value.YY_MOVE_OR_COPY< DirectAbstractDeclarator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_direct_declarator: // direct_declarator
        value.YY_MOVE_OR_COPY< DirectDeclarator > (YY_MOVE (that.value));
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

      case symbol_kind::S_pointer: // pointer
        value.YY_MOVE_OR_COPY< Pointer > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
        value.YY_MOVE_OR_COPY< SpecifierQualifierList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_storage_class_specifier: // storage_class_specifier
        value.YY_MOVE_OR_COPY< StorageClassSpecifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_declarator: // struct_declarator
        value.YY_MOVE_OR_COPY< StructDeclarator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_name: // type_name
        value.YY_MOVE_OR_COPY< TypeName > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_qualifier: // type_qualifier
        value.YY_MOVE_OR_COPY< TypeQualifier > (YY_MOVE (that.value));
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
      case symbol_kind::S_EQUAL: // "="
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
      case symbol_kind::S_GREATER_EQUAL: // ">="
      case symbol_kind::S_LESS_EQUAL: // "<="
      case symbol_kind::S_GREATER: // ">"
      case symbol_kind::S_LESS: // "<"
      case symbol_kind::S_EQUAL_EQUAL: // "=="
      case symbol_kind::S_NOT_EQUAL: // "!="
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

      case symbol_kind::S_struct_declarator_list: // struct_declarator_list
        value.YY_MOVE_OR_COPY< std::vector<StructDeclarator> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_qualifier_list: // type_qualifier_list
        value.YY_MOVE_OR_COPY< std::vector<TypeQualifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identifier_list: // identifier_list
        value.YY_MOVE_OR_COPY< std::vector<std::string> > (YY_MOVE (that.value));
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
      case symbol_kind::S_abstract_declarator: // abstract_declarator
        value.move< AbstractDeclarator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
        value.move< AssignmentOperator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_constant: // constant
        value.move< Constant > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
        value.move< DeclarationSpecifiers > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declarator: // declarator
        value.move< Declarator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_direct_abstract_declarator: // direct_abstract_declarator
        value.move< DirectAbstractDeclarator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_direct_declarator: // direct_declarator
        value.move< DirectDeclarator > (YY_MOVE (that.value));
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

      case symbol_kind::S_pointer: // pointer
        value.move< Pointer > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
        value.move< SpecifierQualifierList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_storage_class_specifier: // storage_class_specifier
        value.move< StorageClassSpecifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_declarator: // struct_declarator
        value.move< StructDeclarator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_name: // type_name
        value.move< TypeName > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_qualifier: // type_qualifier
        value.move< TypeQualifier > (YY_MOVE (that.value));
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
      case symbol_kind::S_EQUAL: // "="
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
      case symbol_kind::S_GREATER_EQUAL: // ">="
      case symbol_kind::S_LESS_EQUAL: // "<="
      case symbol_kind::S_GREATER: // ">"
      case symbol_kind::S_LESS: // "<"
      case symbol_kind::S_EQUAL_EQUAL: // "=="
      case symbol_kind::S_NOT_EQUAL: // "!="
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

      case symbol_kind::S_struct_declarator_list: // struct_declarator_list
        value.move< std::vector<StructDeclarator> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_qualifier_list: // type_qualifier_list
        value.move< std::vector<TypeQualifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identifier_list: // identifier_list
        value.move< std::vector<std::string> > (YY_MOVE (that.value));
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
      case symbol_kind::S_abstract_declarator: // abstract_declarator
        value.copy< AbstractDeclarator > (that.value);
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
        value.copy< AssignmentOperator > (that.value);
        break;

      case symbol_kind::S_constant: // constant
        value.copy< Constant > (that.value);
        break;

      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
        value.copy< DeclarationSpecifiers > (that.value);
        break;

      case symbol_kind::S_declarator: // declarator
        value.copy< Declarator > (that.value);
        break;

      case symbol_kind::S_direct_abstract_declarator: // direct_abstract_declarator
        value.copy< DirectAbstractDeclarator > (that.value);
        break;

      case symbol_kind::S_direct_declarator: // direct_declarator
        value.copy< DirectDeclarator > (that.value);
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

      case symbol_kind::S_pointer: // pointer
        value.copy< Pointer > (that.value);
        break;

      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
        value.copy< SpecifierQualifierList > (that.value);
        break;

      case symbol_kind::S_storage_class_specifier: // storage_class_specifier
        value.copy< StorageClassSpecifier > (that.value);
        break;

      case symbol_kind::S_struct_declarator: // struct_declarator
        value.copy< StructDeclarator > (that.value);
        break;

      case symbol_kind::S_type_name: // type_name
        value.copy< TypeName > (that.value);
        break;

      case symbol_kind::S_type_qualifier: // type_qualifier
        value.copy< TypeQualifier > (that.value);
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
      case symbol_kind::S_EQUAL: // "="
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
      case symbol_kind::S_GREATER_EQUAL: // ">="
      case symbol_kind::S_LESS_EQUAL: // "<="
      case symbol_kind::S_GREATER: // ">"
      case symbol_kind::S_LESS: // "<"
      case symbol_kind::S_EQUAL_EQUAL: // "=="
      case symbol_kind::S_NOT_EQUAL: // "!="
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

      case symbol_kind::S_struct_declarator_list: // struct_declarator_list
        value.copy< std::vector<StructDeclarator> > (that.value);
        break;

      case symbol_kind::S_type_qualifier_list: // type_qualifier_list
        value.copy< std::vector<TypeQualifier> > (that.value);
        break;

      case symbol_kind::S_identifier_list: // identifier_list
        value.copy< std::vector<std::string> > (that.value);
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
      case symbol_kind::S_abstract_declarator: // abstract_declarator
        value.move< AbstractDeclarator > (that.value);
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
        value.move< AssignmentOperator > (that.value);
        break;

      case symbol_kind::S_constant: // constant
        value.move< Constant > (that.value);
        break;

      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
        value.move< DeclarationSpecifiers > (that.value);
        break;

      case symbol_kind::S_declarator: // declarator
        value.move< Declarator > (that.value);
        break;

      case symbol_kind::S_direct_abstract_declarator: // direct_abstract_declarator
        value.move< DirectAbstractDeclarator > (that.value);
        break;

      case symbol_kind::S_direct_declarator: // direct_declarator
        value.move< DirectDeclarator > (that.value);
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

      case symbol_kind::S_pointer: // pointer
        value.move< Pointer > (that.value);
        break;

      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
        value.move< SpecifierQualifierList > (that.value);
        break;

      case symbol_kind::S_storage_class_specifier: // storage_class_specifier
        value.move< StorageClassSpecifier > (that.value);
        break;

      case symbol_kind::S_struct_declarator: // struct_declarator
        value.move< StructDeclarator > (that.value);
        break;

      case symbol_kind::S_type_name: // type_name
        value.move< TypeName > (that.value);
        break;

      case symbol_kind::S_type_qualifier: // type_qualifier
        value.move< TypeQualifier > (that.value);
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
      case symbol_kind::S_EQUAL: // "="
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
      case symbol_kind::S_GREATER_EQUAL: // ">="
      case symbol_kind::S_LESS_EQUAL: // "<="
      case symbol_kind::S_GREATER: // ">"
      case symbol_kind::S_LESS: // "<"
      case symbol_kind::S_EQUAL_EQUAL: // "=="
      case symbol_kind::S_NOT_EQUAL: // "!="
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

      case symbol_kind::S_struct_declarator_list: // struct_declarator_list
        value.move< std::vector<StructDeclarator> > (that.value);
        break;

      case symbol_kind::S_type_qualifier_list: // type_qualifier_list
        value.move< std::vector<TypeQualifier> > (that.value);
        break;

      case symbol_kind::S_identifier_list: // identifier_list
        value.move< std::vector<std::string> > (that.value);
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
      case symbol_kind::S_abstract_declarator: // abstract_declarator
        yylhs.value.emplace< AbstractDeclarator > ();
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
        yylhs.value.emplace< AssignmentOperator > ();
        break;

      case symbol_kind::S_constant: // constant
        yylhs.value.emplace< Constant > ();
        break;

      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
        yylhs.value.emplace< DeclarationSpecifiers > ();
        break;

      case symbol_kind::S_declarator: // declarator
        yylhs.value.emplace< Declarator > ();
        break;

      case symbol_kind::S_direct_abstract_declarator: // direct_abstract_declarator
        yylhs.value.emplace< DirectAbstractDeclarator > ();
        break;

      case symbol_kind::S_direct_declarator: // direct_declarator
        yylhs.value.emplace< DirectDeclarator > ();
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

      case symbol_kind::S_pointer: // pointer
        yylhs.value.emplace< Pointer > ();
        break;

      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
        yylhs.value.emplace< SpecifierQualifierList > ();
        break;

      case symbol_kind::S_storage_class_specifier: // storage_class_specifier
        yylhs.value.emplace< StorageClassSpecifier > ();
        break;

      case symbol_kind::S_struct_declarator: // struct_declarator
        yylhs.value.emplace< StructDeclarator > ();
        break;

      case symbol_kind::S_type_name: // type_name
        yylhs.value.emplace< TypeName > ();
        break;

      case symbol_kind::S_type_qualifier: // type_qualifier
        yylhs.value.emplace< TypeQualifier > ();
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
      case symbol_kind::S_EQUAL: // "="
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
      case symbol_kind::S_GREATER_EQUAL: // ">="
      case symbol_kind::S_LESS_EQUAL: // "<="
      case symbol_kind::S_GREATER: // ">"
      case symbol_kind::S_LESS: // "<"
      case symbol_kind::S_EQUAL_EQUAL: // "=="
      case symbol_kind::S_NOT_EQUAL: // "!="
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

      case symbol_kind::S_struct_declarator_list: // struct_declarator_list
        yylhs.value.emplace< std::vector<StructDeclarator> > ();
        break;

      case symbol_kind::S_type_qualifier_list: // type_qualifier_list
        yylhs.value.emplace< std::vector<TypeQualifier> > ();
        break;

      case symbol_kind::S_identifier_list: // identifier_list
        yylhs.value.emplace< std::vector<std::string> > ();
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
#line 218 "parser.y"
                 { yylhs.value.as< Expression > () = Expression(yystack_[0].value.as < std::string > ()); cout << "IDENTIFIER REDUCE to primary_expression" << endl; }
#line 1579 "parser.cpp"
    break;

  case 3: // primary_expression: constant
#line 219 "parser.y"
               { yylhs.value.as< Expression > () = Expression(&yystack_[0].value.as < Constant > ()); cout << "constant REDUCE to primary_expression" << endl; }
#line 1585 "parser.cpp"
    break;

  case 4: // primary_expression: "(" expression ")"
#line 220 "parser.y"
                                { yylhs.value.as< Expression > () = yystack_[1].value.as < Expression > (); cout << "(expression) REDUCE to primary_expression" << endl; }
#line 1591 "parser.cpp"
    break;

  case 5: // constant: "f_const"
#line 224 "parser.y"
              {
                 long double &id = yystack_[0].value.as < long double > ();
                 cout << "F_CONST REDUCE to constant " << id << endl;
                 yylhs.value.as< Constant > () = Constant(id);
              }
#line 1601 "parser.cpp"
    break;

  case 6: // constant: "i_const"
#line 229 "parser.y"
              {
                 std::uint64_t &id = yystack_[0].value.as < uint64_t > ();
                 cout << "I_CONST REDUCE to constant " << id << endl;
                 yylhs.value.as< Constant > () = Constant(id);
              }
#line 1611 "parser.cpp"
    break;

  case 7: // constant: "sting_literal"
#line 234 "parser.y"
                      {
                 std::string &id = yystack_[0].value.as < std::string > ();
                 cout << "STRING_LITERAL REDUCE to constant  " << id << endl;
                 yylhs.value.as< Constant > () = Constant(id);
              }
#line 1621 "parser.cpp"
    break;

  case 8: // postfix_expression: primary_expression
#line 241 "parser.y"
                                                                   { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > (); cout << "primary_expression REDUCE to postfix_expression" << endl; }
#line 1627 "parser.cpp"
    break;

  case 9: // postfix_expression: postfix_expression "[" expression "]"
#line 242 "parser.y"
                                                                   { cout << "postfix_expression OBRACE expression CBRACE REDUCE to postfix_expression" << endl; }
#line 1633 "parser.cpp"
    break;

  case 10: // postfix_expression: postfix_expression "(" ")"
#line 243 "parser.y"
                                                                   { cout << "postfix_expression OPAREN CPAREN REDUCE to postfix_expression" << endl; }
#line 1639 "parser.cpp"
    break;

  case 11: // postfix_expression: postfix_expression "(" argument_expression_list ")"
#line 244 "parser.y"
                                                                   { cout << "postfix_expression OPAREN argument_expression_list CPAREN REDUCE to postfix_expression" << endl; }
#line 1645 "parser.cpp"
    break;

  case 12: // postfix_expression: postfix_expression "." "identifier"
#line 245 "parser.y"
                                                                   { cout << "postfix_expression PERIOD_OP IDENTIFIER REDUCE to postfix_expression" << endl; }
#line 1651 "parser.cpp"
    break;

  case 13: // postfix_expression: postfix_expression "->" "identifier"
#line 246 "parser.y"
                                                                   { cout << "postfix_expression PTR_OP IDENTIFIER REDUCE to postfix_expression" << endl; }
#line 1657 "parser.cpp"
    break;

  case 14: // postfix_expression: postfix_expression "++"
#line 247 "parser.y"
                                                                   { cout << "postfix_expression INC_OP REDUCE to postfix_expression" << endl; }
#line 1663 "parser.cpp"
    break;

  case 15: // postfix_expression: postfix_expression "--"
#line 248 "parser.y"
                                                                   { cout << "postfix_expression DEC_OP REDUCE to postfix_expression" << endl; }
#line 1669 "parser.cpp"
    break;

  case 16: // postfix_expression: "(" type_name ")" "{" initializer_list "}"
#line 249 "parser.y"
                                                                   { cout << "OPAREN type_name CPAREN_OP OCURLY_OP initializer_list CCURLY REDUCE to postfix_expression" << endl; }
#line 1675 "parser.cpp"
    break;

  case 17: // postfix_expression: "(" type_name ")" "{" initializer_list "," "}"
#line 250 "parser.y"
                                                                   { cout << "OPAREN type_name CPAREN_OP OCURLY_OP initializer_list COMMA CCURLY REDUCE to postfix_expression" << endl; }
#line 1681 "parser.cpp"
    break;

  case 18: // argument_expression_list: assignment_expression
#line 254 "parser.y"
                            {
                             Expression exp = yystack_[0].value.as < Expression > ();
                             yylhs.value.as < std::vector<Expression> > () = std::vector<Expression>();
                             yylhs.value.as < std::vector<Expression> > ().push_back(exp);
                             cout << "assignment_expression REDUCE argument_expression_list" << endl;
                            }
#line 1692 "parser.cpp"
    break;

  case 19: // argument_expression_list: argument_expression_list "," assignment_expression
#line 260 "parser.y"
                                                           {
            Expression value1 = yystack_[0].value.as < Expression > ();
            std::vector<Expression> &value2 = yystack_[2].value.as < std::vector<Expression> > ();
            value2.push_back(value1);
            yylhs.value.as < std::vector<Expression> > () = value2;
            cout << "argument_expression_list COMMA assignment_expression REDUCE argument_expression_list" << endl;
        }
#line 1704 "parser.cpp"
    break;

  case 20: // unary_expression: postfix_expression
#line 270 "parser.y"
                         { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > (); cout << "postfix_expression REDUCE unary_expression" << endl;}
#line 1710 "parser.cpp"
    break;

  case 21: // unary_expression: "++" unary_expression
#line 271 "parser.y"
                              { yylhs.value.as< Expression > () = Expression(yystack_[1].value.as < std::string > (),&yystack_[0].value.as < Expression > ()); cout << "INC_OP unary_expression REDUCE unary_expression" << endl;}
#line 1716 "parser.cpp"
    break;

  case 22: // unary_expression: "--" unary_expression
#line 272 "parser.y"
                              { yylhs.value.as< Expression > () = Expression(yystack_[1].value.as < std::string > (),&yystack_[0].value.as < Expression > ()); cout << "DEC_OP unary_expression REDUCE unary_expression" << endl;}
#line 1722 "parser.cpp"
    break;

  case 23: // unary_expression: unary_operator cast_expression
#line 273 "parser.y"
                                     { yylhs.value.as< Expression > () = Expression(yystack_[1].value.as < std::string > (),&yystack_[0].value.as < Expression > ()); cout << "unary_operator cast_expression REDUCE unary_expression" << endl;}
#line 1728 "parser.cpp"
    break;

  case 24: // unary_expression: "sizeof" unary_expression
#line 274 "parser.y"
                              { yylhs.value.as< Expression > () = Expression(); cout << "SIZEOF unary_expression REDUCE unary_expression" << endl;}
#line 1734 "parser.cpp"
    break;

  case 25: // unary_expression: "sizeof" "(" type_name ")"
#line 275 "parser.y"
                                     { yylhs.value.as< Expression > () = Expression(); cout << "SIZEOF OPAREN type_name CPAREN REDUCE unary_expression" << endl;}
#line 1740 "parser.cpp"
    break;

  case 26: // unary_operator: "&"
#line 279 "parser.y"
                {yylhs.value.as< std::string > () = yystack_[0].value.as < std::string > (); cout << "BIT_AND REDUCE to unary_operator" << endl;}
#line 1746 "parser.cpp"
    break;

  case 27: // unary_operator: "*"
#line 280 "parser.y"
                {yylhs.value.as< std::string > () = yystack_[0].value.as < std::string > (); cout << "TIMES_OP REDUCE to unary_operator" << endl;}
#line 1752 "parser.cpp"
    break;

  case 28: // unary_operator: "+"
#line 281 "parser.y"
                {yylhs.value.as< std::string > () = yystack_[0].value.as < std::string > (); cout << "PLUS_OP REDUCE to unary_operator" << endl;}
#line 1758 "parser.cpp"
    break;

  case 29: // unary_operator: "-"
#line 282 "parser.y"
                {yylhs.value.as< std::string > () = yystack_[0].value.as < std::string > (); cout << "MINUS_OP REDUCE to unary_operator" << endl;}
#line 1764 "parser.cpp"
    break;

  case 30: // unary_operator: "~"
#line 283 "parser.y"
                {yylhs.value.as< std::string > () = yystack_[0].value.as < std::string > (); cout << "TILDE REDUCE to unary_operator" << endl;}
#line 1770 "parser.cpp"
    break;

  case 31: // unary_operator: "!"
#line 284 "parser.y"
                {yylhs.value.as< std::string > () = yystack_[0].value.as < std::string > (); cout << "NOT_OP REDUCE to unary_operator" << endl;}
#line 1776 "parser.cpp"
    break;

  case 32: // cast_expression: unary_expression
#line 288 "parser.y"
                        { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "unary_expression REDUCE to cast_expression" << endl;}
#line 1782 "parser.cpp"
    break;

  case 33: // cast_expression: "(" type_name ")" cast_expression
#line 289 "parser.y"
                                               { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "unary_expression REDUCE to cast_expression" << endl;}
#line 1788 "parser.cpp"
    break;

  case 34: // multiplicative_expression: cast_expression
#line 293 "parser.y"
                       { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "cast_expression REDUCE to multiplicative_expression" << endl;}
#line 1794 "parser.cpp"
    break;

  case 35: // multiplicative_expression: multiplicative_expression "*" cast_expression
#line 294 "parser.y"
                                                         { cout << "multiplicative_expression TIMES_OP cast_expression REDUCE to multiplicative_expression" << endl;}
#line 1800 "parser.cpp"
    break;

  case 36: // multiplicative_expression: multiplicative_expression "/" cast_expression
#line 295 "parser.y"
                                                      { cout << "multiplicative_expression DIV_OP cast_expression REDUCE to multiplicative_expression" << endl;}
#line 1806 "parser.cpp"
    break;

  case 37: // multiplicative_expression: multiplicative_expression "%" cast_expression
#line 296 "parser.y"
                                                      { cout << "multiplicative_expression MOD_OP cast_expression REDUCE to multiplicative_expression" << endl;}
#line 1812 "parser.cpp"
    break;

  case 38: // additive_expression: multiplicative_expression
#line 300 "parser.y"
                                 { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "multiplicative_expression REDUCE to additive_expression" << endl;}
#line 1818 "parser.cpp"
    break;

  case 39: // additive_expression: additive_expression "+" multiplicative_expression
#line 301 "parser.y"
                                                             { cout << "additive_expression REDUCE to multiplicative_expression" << endl;}
#line 1824 "parser.cpp"
    break;

  case 40: // additive_expression: additive_expression "-" multiplicative_expression
#line 302 "parser.y"
                                                              { cout << "additive_expression REDUCE to multiplicative_expression" << endl;}
#line 1830 "parser.cpp"
    break;

  case 41: // shift_expression: additive_expression
#line 306 "parser.y"
                           { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "additive_expression REDUCE to shift_expression" << endl;}
#line 1836 "parser.cpp"
    break;

  case 42: // shift_expression: shift_expression "<<" additive_expression
#line 307 "parser.y"
                                                   { cout << "shift_expression LEFT_OP additive_expression REDUCE to shift_expression" << endl;}
#line 1842 "parser.cpp"
    break;

  case 43: // shift_expression: shift_expression ">>" additive_expression
#line 308 "parser.y"
                                                    { cout << "shift_expression RIGHT_OP additive_expression REDUCE to shift_expression" << endl;}
#line 1848 "parser.cpp"
    break;

  case 44: // relational_expression: shift_expression
#line 312 "parser.y"
                        { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "shift_expression REDUCE to relational_expression" << endl;}
#line 1854 "parser.cpp"
    break;

  case 45: // relational_expression: relational_expression "<" shift_expression
#line 313 "parser.y"
                                                    { cout << "relational_expression LESS shift_expression REDUCE to shift_expression" << endl;}
#line 1860 "parser.cpp"
    break;

  case 46: // relational_expression: relational_expression ">" shift_expression
#line 314 "parser.y"
                                                        { cout << "relational_expression GREATER shift_expression REDUCE to shift_expression" << endl;}
#line 1866 "parser.cpp"
    break;

  case 47: // relational_expression: relational_expression "<=" shift_expression
#line 315 "parser.y"
                                                          { cout << "relational_expression LESS_EQUAL shift_expression REDUCE to shift_expression" << endl;}
#line 1872 "parser.cpp"
    break;

  case 48: // relational_expression: relational_expression ">=" shift_expression
#line 316 "parser.y"
                                                             { cout << "relational_expression GREATER_EQUAL shift_expression REDUCE to shift_expression" << endl;}
#line 1878 "parser.cpp"
    break;

  case 49: // equality_expression: relational_expression
#line 320 "parser.y"
                             { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "relational_expression REDUCE to equality_expression" << endl;}
#line 1884 "parser.cpp"
    break;

  case 50: // equality_expression: equality_expression "==" relational_expression
#line 321 "parser.y"
                                                             { cout << "equality_expression EQUAL_EQUAL relational_expression REDUCE to equality_expression" << endl;}
#line 1890 "parser.cpp"
    break;

  case 51: // equality_expression: equality_expression "!=" relational_expression
#line 322 "parser.y"
                                                           { cout << "equality_expression NOT_EQUAL relational_expression REDUCE to equality_expression" << endl;}
#line 1896 "parser.cpp"
    break;

  case 52: // and_expression: equality_expression
#line 326 "parser.y"
                           { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "equality_expression REDUCE to and_expression" << endl;}
#line 1902 "parser.cpp"
    break;

  case 53: // and_expression: and_expression "&" equality_expression
#line 327 "parser.y"
                                                  { cout << "and_expression BIT_AND equality_expression REDUCE to and_expression" << endl;}
#line 1908 "parser.cpp"
    break;

  case 54: // exclusive_or_expression: and_expression
#line 331 "parser.y"
                      { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "and_expression REDUCE to exclusive_or_expression" << endl;}
#line 1914 "parser.cpp"
    break;

  case 55: // exclusive_or_expression: exclusive_or_expression "^" and_expression
#line 332 "parser.y"
                                                     { cout << "exclusive_or_expression XOR_OP and_expression REDUCE to exclusive_or_expression" << endl;}
#line 1920 "parser.cpp"
    break;

  case 56: // inclusive_or_expression: exclusive_or_expression
#line 336 "parser.y"
                               { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "exclusive_or_expression REDUCE to inclusive_or_expression" << endl;}
#line 1926 "parser.cpp"
    break;

  case 57: // inclusive_or_expression: inclusive_or_expression "|" exclusive_or_expression
#line 337 "parser.y"
                                                             { cout << "inclusive_or_expression BIT_OR exclusive_or_expression REDUCE to inclusive_or_expression" << endl;}
#line 1932 "parser.cpp"
    break;

  case 58: // logical_and_expression: inclusive_or_expression
#line 341 "parser.y"
                               { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "inclusive_or_expression REDUCE to logical_and_expression" << endl;}
#line 1938 "parser.cpp"
    break;

  case 59: // logical_and_expression: logical_and_expression "&&" inclusive_or_expression
#line 342 "parser.y"
                                                             { cout << "inclusive_or_expression REDUCE to logical_and_expression" << endl;}
#line 1944 "parser.cpp"
    break;

  case 60: // logical_or_expression: logical_and_expression
#line 346 "parser.y"
                              { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "inclusive_and_expression REDUCE to logical_or_expression" << endl;}
#line 1950 "parser.cpp"
    break;

  case 61: // logical_or_expression: logical_or_expression "||" logical_and_expression
#line 347 "parser.y"
                                                          { cout << "logical_or_expression OR_OP logical_and_expression REDUCE to logical_or_expression" << endl;}
#line 1956 "parser.cpp"
    break;

  case 62: // conditional_expression: logical_or_expression
#line 351 "parser.y"
                             { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "logical_or_expression REDUCE to conditional_expression" << endl;}
#line 1962 "parser.cpp"
    break;

  case 63: // conditional_expression: logical_or_expression "question" expression ":" conditional_expression
#line 352 "parser.y"
                                                                              { cout << "logical_or_expression QUESTION expression COLON conditional_expression REDUCE to conditional_expression" << endl;}
#line 1968 "parser.cpp"
    break;

  case 64: // assignment_expression: conditional_expression
#line 356 "parser.y"
                              { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "conditional_expression REDUCE to assignment_expression" << endl;}
#line 1974 "parser.cpp"
    break;

  case 65: // assignment_expression: unary_expression assignment_operator assignment_expression
#line 357 "parser.y"
                                                                  { cout << "unary_expression assignment_operator assignment_expression REDUCE to assignment_expression" << endl;}
#line 1980 "parser.cpp"
    break;

  case 66: // assignment_operator: "="
#line 361 "parser.y"
                  { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(yystack_[0].value.as < std::string > (),EQUAL_OP);  cout << "EQUAL_OP REDUCE to assignment_operator" << endl;}
#line 1986 "parser.cpp"
    break;

  case 67: // assignment_operator: "*="
#line 362 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(yystack_[0].value.as < std::string > (),MUL_ASSIGN);  cout << "MUL_ASSIGN REDUCE to assignment_operator" << endl;}
#line 1992 "parser.cpp"
    break;

  case 68: // assignment_operator: "/="
#line 363 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(yystack_[0].value.as < std::string > (),DIV_ASSIGN);  cout << "DIV_ASSIGN REDUCE to assignment_operator" << endl;}
#line 1998 "parser.cpp"
    break;

  case 69: // assignment_operator: "%="
#line 364 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(yystack_[0].value.as < std::string > (),MOD_ASSIGN);  cout << "MOG_ASSIGN REDUCE to assignment_operator" << endl;}
#line 2004 "parser.cpp"
    break;

  case 70: // assignment_operator: "+="
#line 365 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(yystack_[0].value.as < std::string > (),ADD_ASSIGN);  cout << "ADD_ASSIGN REDUCE to assignment_operator" << endl;}
#line 2010 "parser.cpp"
    break;

  case 71: // assignment_operator: "-="
#line 366 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(yystack_[0].value.as < std::string > (),SUB_ASSIGN);  cout << "SUB_ASSIGN REDUCE to assignment_operator" << endl;}
#line 2016 "parser.cpp"
    break;

  case 72: // assignment_operator: "<<="
#line 367 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(yystack_[0].value.as < std::string > (),LEFT_ASSIGN);  cout << "LEFT_ASSIGN REDUCE to assignment_operator" << endl;}
#line 2022 "parser.cpp"
    break;

  case 73: // assignment_operator: ">>="
#line 368 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(yystack_[0].value.as < std::string > (),RIGHT_ASSIGN);  cout << "RIGHT_ASSIGN REDUCE to assignment_operator" << endl;}
#line 2028 "parser.cpp"
    break;

  case 74: // assignment_operator: "&="
#line 369 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(yystack_[0].value.as < std::string > (),AND_ASSIGN);  cout << "AND_ASSIGN REDUCE to assignment_operator" << endl;}
#line 2034 "parser.cpp"
    break;

  case 75: // assignment_operator: "^="
#line 370 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(yystack_[0].value.as < std::string > (),XOR_ASSIGN);  cout << "XOR_ASSIGN REDUCE to assignment_operator" << endl;}
#line 2040 "parser.cpp"
    break;

  case 76: // assignment_operator: "|="
#line 371 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(yystack_[0].value.as < std::string > (),OR_ASSIGN);  cout << "OR_ASSIGN REDUCE to assignment_operator" << endl;}
#line 2046 "parser.cpp"
    break;

  case 77: // expression: assignment_expression
#line 375 "parser.y"
                             { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "asignment_expression REDUCE to expression" << endl;}
#line 2052 "parser.cpp"
    break;

  case 78: // expression: expression "," assignment_expression
#line 376 "parser.y"
                                              { cout << "expression COMMA assignment_expression COMMA  REDUCE to expression" << endl;}
#line 2058 "parser.cpp"
    break;

  case 79: // constant_expression: conditional_expression
#line 380 "parser.y"
                              { yylhs.value.as< Expression > () = yystack_[0].value.as < Expression > ();  cout << "conditional_expression REDUCE to constant_expression" << endl;}
#line 2064 "parser.cpp"
    break;

  case 80: // declaration: declaration_specifiers ";"
#line 384 "parser.y"
                                        { cout << "declaration_specifiers SEMICOLON REDUCE to declaration" << endl;}
#line 2070 "parser.cpp"
    break;

  case 81: // declaration: declaration_specifiers init_declarator_list ";"
#line 385 "parser.y"
                                                             { cout << "declaration_specifiers init_declarator_list SEMICOLON REDUCE to declaration" << endl;}
#line 2076 "parser.cpp"
    break;

  case 82: // declaration_specifiers: storage_class_specifier
#line 389 "parser.y"
                                                      { yylhs.value.as< DeclarationSpecifiers > () = DeclarationSpecifiers(yystack_[0].value.as < StorageClassSpecifier > ()); cout << "storage_class_specifier REDUCE to declaration_specifiers" << endl;}
#line 2082 "parser.cpp"
    break;

  case 83: // declaration_specifiers: storage_class_specifier declaration_specifiers
#line 390 "parser.y"
                                                      { yylhs.value.as< DeclarationSpecifiers > () = DeclarationSpecifiers(yystack_[1].value.as < StorageClassSpecifier > (),yystack_[0].value.as < DeclarationSpecifiers > ()); cout << "storage_class_specifier declaration_specifiers REDUCE to declaration_specifiers" << endl;}
#line 2088 "parser.cpp"
    break;

  case 84: // declaration_specifiers: type_specifier
#line 391 "parser.y"
                                                      { yylhs.value.as< DeclarationSpecifiers > () = DeclarationSpecifiers(yystack_[0].value.as < TypeSpecifier > ()); cout << "type_specifier REDUCE to declaration_specifiers" << endl;}
#line 2094 "parser.cpp"
    break;

  case 85: // declaration_specifiers: type_specifier declaration_specifiers
#line 392 "parser.y"
                                                      { yylhs.value.as< DeclarationSpecifiers > () = DeclarationSpecifiers(yystack_[1].value.as < TypeSpecifier > (),yystack_[0].value.as < DeclarationSpecifiers > ()); cout << "type_specifier declaration_specifiers REDUCE to declaration_specifiers" << endl;}
#line 2100 "parser.cpp"
    break;

  case 86: // declaration_specifiers: type_qualifier
#line 393 "parser.y"
                                                      { yylhs.value.as< DeclarationSpecifiers > () = DeclarationSpecifiers(yystack_[0].value.as < TypeQualifier > ()); cout << "type_qualifier REDUCE to declaration_specifiers" << endl;}
#line 2106 "parser.cpp"
    break;

  case 87: // declaration_specifiers: type_qualifier declaration_specifiers
#line 394 "parser.y"
                                                      { yylhs.value.as< DeclarationSpecifiers > () = DeclarationSpecifiers(yystack_[1].value.as < TypeQualifier > (),yystack_[0].value.as < DeclarationSpecifiers > ()); cout << "type_qualifier declaration_specifiers REDUCE to declaration_specifiers" << endl;}
#line 2112 "parser.cpp"
    break;

  case 88: // init_declarator_list: init_declarator
#line 398 "parser.y"
                                                 { cout << "init_declarator REDUCE to init_declarator_list" << endl;}
#line 2118 "parser.cpp"
    break;

  case 89: // init_declarator_list: init_declarator_list "," init_declarator
#line 399 "parser.y"
                                                 { cout << "init_declarator_list COMMA init_declarator REDUCE to init_declarator_list" << endl;}
#line 2124 "parser.cpp"
    break;

  case 90: // init_declarator: declarator
#line 403 "parser.y"
                                       { cout << "declarator REDUCE to init_declarator" << endl;}
#line 2130 "parser.cpp"
    break;

  case 91: // init_declarator: declarator "=" initializer
#line 404 "parser.y"
                                    { cout << "declarator EQUAL initializer REDUCE to init_declarator" << endl;}
#line 2136 "parser.cpp"
    break;

  case 92: // storage_class_specifier: "typedef"
#line 408 "parser.y"
                { yylhs.value.as< StorageClassSpecifier > () = StorageClassSpecifier(yystack_[0].value.as < std::string > (),TYPEDEF); cout << "TYPEDEF REDUCE to storage_class_specifier" << endl;}
#line 2142 "parser.cpp"
    break;

  case 93: // storage_class_specifier: "extern"
#line 409 "parser.y"
                { yylhs.value.as< StorageClassSpecifier > () = StorageClassSpecifier(yystack_[0].value.as < std::string > (),EXTERN); cout << "EXTERN REDUCE to storage_class_specifier" << endl;}
#line 2148 "parser.cpp"
    break;

  case 94: // storage_class_specifier: "static"
#line 410 "parser.y"
                { yylhs.value.as< StorageClassSpecifier > () = StorageClassSpecifier(yystack_[0].value.as < std::string > (),STATIC); cout << "STATIC REDUCE to storage_class_specifier" << endl;}
#line 2154 "parser.cpp"
    break;

  case 95: // storage_class_specifier: "auto"
#line 411 "parser.y"
                { yylhs.value.as< StorageClassSpecifier > () = StorageClassSpecifier(yystack_[0].value.as < std::string > (),AUTO); cout << "AUTO REDUCE to storage_class_specifier" << endl;}
#line 2160 "parser.cpp"
    break;

  case 96: // storage_class_specifier: "register"
#line 412 "parser.y"
                { yylhs.value.as< StorageClassSpecifier > () = StorageClassSpecifier(yystack_[0].value.as < std::string > (),REGISTER); cout << "REGISTER REDUCE to storage_class_specifier" << endl;}
#line 2166 "parser.cpp"
    break;

  case 97: // type_specifier: "void"
#line 416 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(yystack_[0].value.as < std::string > (),VOID); cout << "VOID REDUCE to type_specifier" << endl;}
#line 2172 "parser.cpp"
    break;

  case 98: // type_specifier: "char"
#line 417 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(yystack_[0].value.as < std::string > (),CHAR); cout << "CHAR REDUCE to type_specifier" << endl;}
#line 2178 "parser.cpp"
    break;

  case 99: // type_specifier: "short"
#line 418 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(yystack_[0].value.as < std::string > (),SHORT); cout << "SHORT REDUCE to type_specifier" << endl;}
#line 2184 "parser.cpp"
    break;

  case 100: // type_specifier: "int"
#line 419 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(yystack_[0].value.as < std::string > (),INT); cout << "INT REDUCE to type_specifier" << endl;}
#line 2190 "parser.cpp"
    break;

  case 101: // type_specifier: "long"
#line 420 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(yystack_[0].value.as < std::string > (),LONG); cout << "LONG REDUCE to type_specifier" << endl;}
#line 2196 "parser.cpp"
    break;

  case 102: // type_specifier: "float"
#line 421 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(yystack_[0].value.as < std::string > (),FLOAT); cout << "FLOAT REDUCE to type_specifier" << endl;}
#line 2202 "parser.cpp"
    break;

  case 103: // type_specifier: "double"
#line 422 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(yystack_[0].value.as < std::string > (),DOUBLE); cout << "DOUBLE REDUCE to type_specifier" << endl;}
#line 2208 "parser.cpp"
    break;

  case 104: // type_specifier: "signed"
#line 423 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(yystack_[0].value.as < std::string > (),SIGNED); cout << "SIGNED REDUCE to type_specifier" << endl;}
#line 2214 "parser.cpp"
    break;

  case 105: // type_specifier: "unsigned"
#line 424 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(yystack_[0].value.as < std::string > (),UNSIGNED); cout << "UNIGNED REDUCE to type_specifier" << endl;}
#line 2220 "parser.cpp"
    break;

  case 106: // type_specifier: struct_or_union_specifier
#line 425 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier("struct_or_union_specifier",struct_or_union_specifier); cout << "struct_or_union_specifier REDUCE to type_specifier" << endl;}
#line 2226 "parser.cpp"
    break;

  case 107: // type_specifier: enum_specifier
#line 426 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier("enum_specifier",&yystack_[0].value.as < EnumSpecifier > ()); cout << "enum_specifier REDUCE to type_specifier" << endl;}
#line 2232 "parser.cpp"
    break;

  case 108: // type_specifier: "type name"
#line 427 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(yystack_[0].value.as < std::string > (),TYPE_NAME); cout << "TYPE_NAME REDUCE to type_specifier" << endl;}
#line 2238 "parser.cpp"
    break;

  case 109: // struct_or_union_specifier: struct_or_union "identifier" "{" struct_declaration_list "}"
#line 431 "parser.y"
                                                                         { cout << "struct_or_union IDENTIFIER OCURLY struct_declaration_list CCURLY REDUCE to struct_or_union_specifier" << endl;}
#line 2244 "parser.cpp"
    break;

  case 110: // struct_or_union_specifier: struct_or_union "{" struct_declaration_list "}"
#line 432 "parser.y"
                                                                         { cout << "struct_or_union OCURLY struct_declaration_list CCURLY REDUCE to struct_or_union_specifier" << endl;}
#line 2250 "parser.cpp"
    break;

  case 111: // struct_or_union_specifier: struct_or_union "identifier"
#line 433 "parser.y"
                                                                         { cout << "struct_or_union IDENTIFIER REDUCE to struct_or_union_specifier" << endl;}
#line 2256 "parser.cpp"
    break;

  case 112: // struct_or_union: "struct"
#line 437 "parser.y"
               { cout << "STRUCT REDUCE to struct_or_union" << endl;}
#line 2262 "parser.cpp"
    break;

  case 113: // struct_or_union: "union"
#line 438 "parser.y"
               { cout << "UNION REDUCE to struct_or_union" << endl;}
#line 2268 "parser.cpp"
    break;

  case 114: // struct_declaration_list: struct_declaration
#line 442 "parser.y"
                                                 { cout << "struct_declaration REDUCE to struct_declaration_list" << endl;}
#line 2274 "parser.cpp"
    break;

  case 115: // struct_declaration_list: struct_declaration_list struct_declaration
#line 443 "parser.y"
                                                 { cout << "struct_declaration_list struct_declaration REDUCE to struct_declaration_list" << endl;}
#line 2280 "parser.cpp"
    break;

  case 116: // struct_declaration: specifier_qualifier_list struct_declarator_list ";"
#line 447 "parser.y"
                                                                { cout << "specifier_qualifier_list struct_declarator_list SEMICOLON REDUCE to struct_declaration" << endl;}
#line 2286 "parser.cpp"
    break;

  case 117: // specifier_qualifier_list: type_specifier specifier_qualifier_list
#line 451 "parser.y"
                                              { yylhs.value.as< SpecifierQualifierList > () = SpecifierQualifierList(yystack_[0].value.as < SpecifierQualifierList > (),yystack_[1].value.as < TypeSpecifier > ()); cout << "type_specifier specifier_qualifier_list REDUCE to specifier_qualifier_list" << endl;}
#line 2292 "parser.cpp"
    break;

  case 118: // specifier_qualifier_list: type_specifier
#line 452 "parser.y"
                                              { yylhs.value.as< SpecifierQualifierList > () = SpecifierQualifierList(yystack_[0].value.as < TypeSpecifier > ()); cout << "type_specifier REDUCE to specifier_qualifier_list" << endl;}
#line 2298 "parser.cpp"
    break;

  case 119: // specifier_qualifier_list: type_qualifier specifier_qualifier_list
#line 453 "parser.y"
                                              { yylhs.value.as< SpecifierQualifierList > () = SpecifierQualifierList(yystack_[0].value.as < SpecifierQualifierList > (),yystack_[1].value.as < TypeQualifier > ()); cout << "type_qualifier specifier_qualifier_list REDUCE to specifier_qualifier_list" << endl;}
#line 2304 "parser.cpp"
    break;

  case 120: // specifier_qualifier_list: type_qualifier
#line 454 "parser.y"
                                              { yylhs.value.as< SpecifierQualifierList > () = SpecifierQualifierList(yystack_[0].value.as < TypeQualifier > ()); cout << "type_qualifier REDUCE to specifier_qualifier_list" << endl;}
#line 2310 "parser.cpp"
    break;

  case 121: // struct_declarator_list: struct_declarator
#line 458 "parser.y"
                                                     {
                                                       StructDeclarator exp = yystack_[0].value.as < StructDeclarator > ();
                                                       yylhs.value.as < std::vector<StructDeclarator> > () = std::vector<StructDeclarator>();
                                                       yylhs.value.as < std::vector<StructDeclarator> > ().push_back(exp);
                                                       cout << "struct_declarator REDUCE to struct_declarator_list" << endl;
                                                     }
#line 2321 "parser.cpp"
    break;

  case 122: // struct_declarator_list: struct_declarator_list "," struct_declarator
#line 464 "parser.y"
                                                     {
                                                       StructDeclarator value1 = yystack_[0].value.as < StructDeclarator > ();
                                                       std::vector<StructDeclarator> &value2 = yystack_[2].value.as < std::vector<StructDeclarator> > ();
                                                       value2.push_back(value1);
                                                       yylhs.value.as < std::vector<StructDeclarator> > () = value2;
                                                       cout << "struct_declarator_list COMMA struct_declarator REDUCE to struct_declarator_list" << endl;
                                                     }
#line 2333 "parser.cpp"
    break;

  case 123: // struct_declarator: declarator
#line 474 "parser.y"
                                           { yylhs.value.as< StructDeclarator > () = StructDeclarator(yystack_[0].value.as < Declarator > ()); cout << "declarator REDUCE to struct_declarator" << endl;}
#line 2339 "parser.cpp"
    break;

  case 124: // struct_declarator: ":" constant_expression
#line 475 "parser.y"
                                           { yylhs.value.as< StructDeclarator > () = StructDeclarator(yystack_[0].value.as < Expression > ()); cout << "COLON constant_expression REDUCE to struct_declarator" << endl;}
#line 2345 "parser.cpp"
    break;

  case 125: // struct_declarator: declarator ":" constant_expression
#line 476 "parser.y"
                                           { yylhs.value.as< StructDeclarator > () = StructDeclarator(yystack_[2].value.as < Declarator > (),yystack_[0].value.as < Expression > ()); cout << "declarator COLON constant_expression REDUCE to struct_declarator" << endl;}
#line 2351 "parser.cpp"
    break;

  case 126: // enum_specifier: "enum" "{" enumerator_list "}"
#line 480 "parser.y"
                                                     { yylhs.value.as< EnumSpecifier > () = EnumSpecifier(yystack_[1].value.as < std::vector<Enumerator> > ()); cout << "ENUM OCURLY enumerator_list CCURLY REDUCE to enum_specifier" << endl;}
#line 2357 "parser.cpp"
    break;

  case 127: // enum_specifier: "enum" "identifier" "{" enumerator_list "}"
#line 481 "parser.y"
                                                     { yylhs.value.as< EnumSpecifier > () = EnumSpecifier(yystack_[3].value.as < std::string > (),yystack_[1].value.as < std::vector<Enumerator> > ()); cout << "ENUM IDENTIFIER OCURLY enumerator_list CCURLY REDUCE to enum_specifier" << endl;}
#line 2363 "parser.cpp"
    break;

  case 128: // enum_specifier: "enum" "identifier"
#line 482 "parser.y"
                                                     { yylhs.value.as< EnumSpecifier > () = EnumSpecifier(yystack_[0].value.as < std::string > ()); cout << "ENUM IDENTIFIER REDUCE to enum_specifier" << endl;}
#line 2369 "parser.cpp"
    break;

  case 129: // enumerator_list: enumerator
#line 486 "parser.y"
                                        {
                                          Enumerator exp = yystack_[0].value.as < Enumerator > ();
                                          yylhs.value.as < std::vector<Enumerator> > () = std::vector<Enumerator>();
                                          yylhs.value.as < std::vector<Enumerator> > ().push_back(exp);
                                          cout << "enumerator REDUCE enumerator_list" << endl;
                                        }
#line 2380 "parser.cpp"
    break;

  case 130: // enumerator_list: enumerator_list "," enumerator
#line 492 "parser.y"
                                        {
                                          Enumerator value1 = yystack_[0].value.as < Enumerator > ();
                                          std::vector<Enumerator> &value2 = yystack_[2].value.as < std::vector<Enumerator> > ();
                                          value2.push_back(value1);
                                          yylhs.value.as < std::vector<Enumerator> > () = value2;
                                          cout << "enumerator_list COMMA enumerator REDUCE enumerator_list" << endl;
                                        }
#line 2392 "parser.cpp"
    break;

  case 131: // enumerator: "identifier"
#line 502 "parser.y"
                                           { yylhs.value.as< Enumerator > () = Enumerator(yystack_[0].value.as < std::string > ()); cout << "IDENTIFIER REDUCE to ENUMERATOR" << endl;}
#line 2398 "parser.cpp"
    break;

  case 132: // enumerator: "identifier" "=" constant_expression
#line 503 "parser.y"
                                           { yylhs.value.as< Enumerator > () = Enumerator(yystack_[2].value.as < std::string > (),yystack_[0].value.as < Expression > ()); cout << "IDENTIFIER EQUAL constant_expression REDUCE to ENUMERATOR" << endl;}
#line 2404 "parser.cpp"
    break;

  case 133: // type_qualifier: "const"
#line 507 "parser.y"
               { yylhs.value.as< TypeQualifier > () = TypeQualifier(yystack_[0].value.as < std::string > (),CONST); cout << "CONST REDUCE to type_qualifier" << endl;}
#line 2410 "parser.cpp"
    break;

  case 134: // type_qualifier: "volatile"
#line 508 "parser.y"
               { yylhs.value.as< TypeQualifier > () = TypeQualifier(yystack_[0].value.as < std::string > (),VOLATILE); cout << "VOLATILE REDUCE to type_qualifier" << endl;}
#line 2416 "parser.cpp"
    break;

  case 135: // declarator: pointer direct_declarator
#line 512 "parser.y"
                                { yylhs.value.as< Declarator > () = Declarator(yystack_[1].value.as < Pointer > (),yystack_[0].value.as < DirectDeclarator > ()); cout << "pointer direct_declarator REDUCE to declarator" << endl;}
#line 2422 "parser.cpp"
    break;

  case 136: // declarator: direct_declarator
#line 513 "parser.y"
                                { yylhs.value.as< Declarator > () = Declarator(yystack_[0].value.as < DirectDeclarator > ()); cout << "direct_declarator REDUCE to declarator" << endl;}
#line 2428 "parser.cpp"
    break;

  case 137: // direct_declarator: "identifier"
#line 517 "parser.y"
                                                            { yylhs.value.as< DirectDeclarator > () = DirectDeclarator(yystack_[0].value.as < std::string > ()); cout << "IDENTIFIER REDUCE to direct_declarator" << endl;}
#line 2434 "parser.cpp"
    break;

  case 138: // direct_declarator: "(" declarator ")"
#line 518 "parser.y"
                                                            { yylhs.value.as< DirectDeclarator > () = DirectDeclarator(); cout << "OPAREN declarator CPAREN REDUCE to direct_declarator" << endl;}
#line 2440 "parser.cpp"
    break;

  case 139: // direct_declarator: direct_declarator "[" constant_expression "]"
#line 519 "parser.y"
                                                            { yylhs.value.as< DirectDeclarator > () = DirectDeclarator(); cout << "direct_declarator OBRACE constant_expression CBRACE REDUCE to direct_declarator" << endl;}
#line 2446 "parser.cpp"
    break;

  case 140: // direct_declarator: direct_declarator "[" "]"
#line 520 "parser.y"
                                                            { yylhs.value.as< DirectDeclarator > () = DirectDeclarator(); cout << "direct_declarator OBRACE CBRACE REDUCE to direct_declarator" << endl;}
#line 2452 "parser.cpp"
    break;

  case 141: // direct_declarator: direct_declarator "(" parameter_type_list ")"
#line 521 "parser.y"
                                                            { yylhs.value.as< DirectDeclarator > () = DirectDeclarator(); cout << "direct_declarator OPAREN parameter_type_list CPAREN to direct_declarator" << endl;}
#line 2458 "parser.cpp"
    break;

  case 142: // direct_declarator: direct_declarator "(" identifier_list ")"
#line 522 "parser.y"
                                                            { yylhs.value.as< DirectDeclarator > () = DirectDeclarator(); cout << "direct_declarator OPAREN identifier_list CPAREN REDUCE to direct_declarator" << endl;}
#line 2464 "parser.cpp"
    break;

  case 143: // direct_declarator: direct_declarator "(" ")"
#line 523 "parser.y"
                                                            { yylhs.value.as< DirectDeclarator > () = DirectDeclarator(); cout << "direct_declarator OPAREN CPAREN REDUCE to direct_declarator" << endl;}
#line 2470 "parser.cpp"
    break;

  case 144: // pointer: "*"
#line 527 "parser.y"
                                            {yylhs.value.as< Pointer > () = Pointer(yystack_[0].value.as < std::string > ()); cout << "TIMES_OP REDUCE to POINTER" << endl;}
#line 2476 "parser.cpp"
    break;

  case 145: // pointer: "*" type_qualifier_list
#line 528 "parser.y"
                                            {yylhs.value.as< Pointer > () = Pointer(yystack_[1].value.as < std::string > (),&yystack_[0].value.as < std::vector<TypeQualifier> > ()); cout << "TIMES_OP type_qualifier_list REDUCE to POINTER" << endl;}
#line 2482 "parser.cpp"
    break;

  case 146: // pointer: "*" pointer
#line 529 "parser.y"
                                            {yylhs.value.as< Pointer > () = Pointer(yystack_[1].value.as < std::string > (),&yystack_[0].value.as < Pointer > ()); yylhs.value.as< Pointer > ().inc(); cout << "TIMES_OP pointer REDUCE to POINTER" << endl;}
#line 2488 "parser.cpp"
    break;

  case 147: // pointer: "*" type_qualifier_list pointer
#line 530 "parser.y"
                                            {yylhs.value.as< Pointer > () = Pointer(yystack_[2].value.as < std::string > (),&yystack_[1].value.as < std::vector<TypeQualifier> > (),&yystack_[0].value.as < Pointer > ()); yylhs.value.as< Pointer > ().inc(); cout << "TIMES_OP type_qualifier_list pointer REDUCE to POINTER" << endl;}
#line 2494 "parser.cpp"
    break;

  case 148: // type_qualifier_list: type_qualifier
#line 534 "parser.y"
                            {
                             TypeQualifier exp = yystack_[0].value.as < TypeQualifier > ();
                             yylhs.value.as < std::vector<TypeQualifier> > () = std::vector<TypeQualifier>();
                             yylhs.value.as < std::vector<TypeQualifier> > ().push_back(exp);
                             cout << "type_qualifier REDUCE type_qualifier_list" << endl;
                            }
#line 2505 "parser.cpp"
    break;

  case 149: // type_qualifier_list: type_qualifier_list type_qualifier
#line 540 "parser.y"
                                         {
                                          TypeQualifier value1 = yystack_[0].value.as < TypeQualifier > ();
                                          std::vector<TypeQualifier> &value2 = yystack_[1].value.as < std::vector<TypeQualifier> > ();
                                          value2.push_back(value1);
                                          yylhs.value.as < std::vector<TypeQualifier> > () = value2;
                                          cout << "type_qualifier_list type_qualifier REDUCE type_qualifier_list" << endl;
                                        }
#line 2517 "parser.cpp"
    break;

  case 150: // parameter_type_list: parameter_list
#line 551 "parser.y"
                                      { cout << "parameter_list REDUCE to parameter_type_list" << endl; }
#line 2523 "parser.cpp"
    break;

  case 151: // parameter_type_list: parameter_list "," "ellipsis"
#line 552 "parser.y"
                                      { cout << "parameter_list COMMA ELLIPSIS REDUCE to parameter_type_list" << endl; }
#line 2529 "parser.cpp"
    break;

  case 152: // parameter_list: parameter_declaration
#line 556 "parser.y"
                                                  { cout << "parameter_declaration REDUCE to parameter_list" << endl; }
#line 2535 "parser.cpp"
    break;

  case 153: // parameter_list: parameter_list "," parameter_declaration
#line 557 "parser.y"
                                                  { cout << "parameter_list COMMA parameter_declaration REDUCE to parameter_list" << endl; }
#line 2541 "parser.cpp"
    break;

  case 154: // parameter_declaration: declaration_specifiers declarator
#line 561 "parser.y"
                                                  { cout << "declaration_specifiers declarator REDUCE to parameter_declaration" << endl; }
#line 2547 "parser.cpp"
    break;

  case 155: // parameter_declaration: declaration_specifiers abstract_declarator
#line 562 "parser.y"
                                                  { cout << "declaration_specifiers abstract_declarator REDUCE to parameter_declaration" << endl; }
#line 2553 "parser.cpp"
    break;

  case 156: // parameter_declaration: declaration_specifiers
#line 563 "parser.y"
                                                  { cout << "declaration_specifiers REDUCE to parameter_declaration" << endl; }
#line 2559 "parser.cpp"
    break;

  case 157: // identifier_list: "identifier"
#line 567 "parser.y"
                   {
                             std::string exp = yystack_[0].value.as < std::string > ();
                             yylhs.value.as < std::vector<std::string> > () = std::vector<std::string>();
                             yylhs.value.as < std::vector<std::string> > ().push_back(exp);
                             cout << "specifier_qualifier_list REDUCE to identifier_list" << endl;
                            }
#line 2570 "parser.cpp"
    break;

  case 158: // identifier_list: identifier_list "," "identifier"
#line 573 "parser.y"
                                       {
                                          std::string value1 = yystack_[0].value.as < std::string > ();
                                          std::vector<std::string> &value2 = yystack_[2].value.as < std::vector<std::string> > ();
                                          value2.push_back(value1);
                                          yylhs.value.as < std::vector<std::string> > () = value2;
                                          cout << "identifier_list COMMA IDENTIFIER REDUCE to identifier_list" << endl; 
                                        }
#line 2582 "parser.cpp"
    break;

  case 159: // type_name: specifier_qualifier_list
#line 583 "parser.y"
                                                   { yylhs.value.as< TypeName > () = TypeName(yystack_[0].value.as < SpecifierQualifierList > ()); cout << "specifier_qualifier_list REDUCE to type_name" << endl; }
#line 2588 "parser.cpp"
    break;

  case 160: // type_name: specifier_qualifier_list abstract_declarator
#line 584 "parser.y"
                                                   { yylhs.value.as< TypeName > () = TypeName(yystack_[1].value.as < SpecifierQualifierList > (),yystack_[0].value.as < AbstractDeclarator > ()); cout << "specifier_qualifier_list abstract_declarator REDUCE to type_name" << endl; }
#line 2594 "parser.cpp"
    break;

  case 161: // abstract_declarator: pointer
#line 588 "parser.y"
                                          { yylhs.value.as< AbstractDeclarator > () = AbstractDeclarator(yystack_[0].value.as < Pointer > ()); cout << "pointer REDUCE to abstract_declarator" << endl; }
#line 2600 "parser.cpp"
    break;

  case 162: // abstract_declarator: direct_abstract_declarator
#line 589 "parser.y"
                                          { yylhs.value.as< AbstractDeclarator > () = AbstractDeclarator(yystack_[0].value.as < DirectAbstractDeclarator > ()); cout << "direct_abstract_declarator REDUCE to abstract_declarator" << endl; }
#line 2606 "parser.cpp"
    break;

  case 163: // abstract_declarator: pointer direct_abstract_declarator
#line 590 "parser.y"
                                          { yylhs.value.as< AbstractDeclarator > () = AbstractDeclarator(yystack_[1].value.as < Pointer > (),yystack_[0].value.as < DirectAbstractDeclarator > ()); cout << "pointer direct_abstract_declarator REDUCE to abstract_declarator" << endl; }
#line 2612 "parser.cpp"
    break;

  case 164: // direct_abstract_declarator: "(" abstract_declarator ")"
#line 594 "parser.y"
                                                                   { yylhs.value.as< DirectAbstractDeclarator > () = DirectAbstractDeclarator(yystack_[1].value.as < AbstractDeclarator > ()); cout << "OPAREN abstract_declarator CPAREN REDUCE to direct_abstract_declarator" << endl; }
#line 2618 "parser.cpp"
    break;

  case 165: // direct_abstract_declarator: "[" "]"
#line 595 "parser.y"
                                                                   { yylhs.value.as< DirectAbstractDeclarator > () = DirectAbstractDeclarator(); cout << "OBRACE CBRACE REDUCE to direct_abstract_declarator" << endl; }
#line 2624 "parser.cpp"
    break;

  case 166: // direct_abstract_declarator: "[" constant_expression "]"
#line 596 "parser.y"
                                                                   { yylhs.value.as< DirectAbstractDeclarator > () = DirectAbstractDeclarator(); cout << "OBRACE constant_expression CBRACE REDUCE to direct_abstract_declarator" << endl; }
#line 2630 "parser.cpp"
    break;

  case 167: // direct_abstract_declarator: direct_abstract_declarator "[" "]"
#line 597 "parser.y"
                                                                   { yylhs.value.as< DirectAbstractDeclarator > () = DirectAbstractDeclarator(); cout << "direct_abstract_declarator OBRACE CBRACE REDUCE to direct_abstract_declarator" << endl; }
#line 2636 "parser.cpp"
    break;

  case 168: // direct_abstract_declarator: direct_abstract_declarator "[" constant_expression "]"
#line 598 "parser.y"
                                                                   { yylhs.value.as< DirectAbstractDeclarator > () = DirectAbstractDeclarator(); cout << "direct_abstract_declarator OBRACE constant_expression CBRACE REDUCE to direct_abstract_declarator" << endl; }
#line 2642 "parser.cpp"
    break;

  case 169: // direct_abstract_declarator: "(" ")"
#line 599 "parser.y"
                                                                   { yylhs.value.as< DirectAbstractDeclarator > () = DirectAbstractDeclarator(); cout << "OPAREN CPAREN REDUCE to direct_abstract_declarator" << endl; }
#line 2648 "parser.cpp"
    break;

  case 170: // direct_abstract_declarator: "(" parameter_type_list ")"
#line 600 "parser.y"
                                                                   { yylhs.value.as< DirectAbstractDeclarator > () = DirectAbstractDeclarator(); cout << "OPAREN parameter_type_list CPAREN REDUCE to direct_abstract_declarator" << endl; }
#line 2654 "parser.cpp"
    break;

  case 171: // direct_abstract_declarator: direct_abstract_declarator "(" ")"
#line 601 "parser.y"
                                                                   { yylhs.value.as< DirectAbstractDeclarator > () = DirectAbstractDeclarator(); cout << "direct_abstract_declarator OPAREN CPAREN REDUCE to direct_abstract_declarator" << endl; }
#line 2660 "parser.cpp"
    break;

  case 172: // direct_abstract_declarator: direct_abstract_declarator "(" parameter_type_list ")"
#line 602 "parser.y"
                                                                   { yylhs.value.as< DirectAbstractDeclarator > () = DirectAbstractDeclarator(); cout << "direct_abstract_declarator OPAREN parameter_type_list CPAREN REDUCE to direct_abstract_declarator" << endl; }
#line 2666 "parser.cpp"
    break;

  case 173: // initializer: assignment_expression
#line 606 "parser.y"
                                           { cout << "assignment_expression REDUCE to initializer" << endl; }
#line 2672 "parser.cpp"
    break;

  case 174: // initializer: "{" initializer_list "}"
#line 607 "parser.y"
                                           { cout << "OCURLY initializer_list CCURLY REDUCE to initializer" << endl; }
#line 2678 "parser.cpp"
    break;

  case 175: // initializer: "{" initializer_list "," "}"
#line 608 "parser.y"
                                           { cout << "OCURLY initializer_list COMMA CCURLY REDUCE to initializer" << endl; }
#line 2684 "parser.cpp"
    break;

  case 176: // initializer_list: initializer
#line 612 "parser.y"
                                         { cout << "initializer REDUCE to initializer_list" << endl; }
#line 2690 "parser.cpp"
    break;

  case 177: // initializer_list: initializer_list "," initializer
#line 613 "parser.y"
                                         { cout << "initializer_list COMMA initializer REDUCE to initializer_list" << endl; }
#line 2696 "parser.cpp"
    break;

  case 178: // statement: labeled_statement
#line 617 "parser.y"
                           { cout << "labeled_statement REDUCE to statement" << endl; }
#line 2702 "parser.cpp"
    break;

  case 179: // statement: compound_statement
#line 618 "parser.y"
                           { cout << "compound_statement REDUCE to statement" << endl; }
#line 2708 "parser.cpp"
    break;

  case 180: // statement: expression_statement
#line 619 "parser.y"
                           { cout << "expression_statement REDUCE to statement" << endl; }
#line 2714 "parser.cpp"
    break;

  case 181: // statement: selection_statement
#line 620 "parser.y"
                           { cout << "selection_statement REDUCE to statement" << endl; }
#line 2720 "parser.cpp"
    break;

  case 182: // statement: iteration_statement
#line 621 "parser.y"
                           { cout << "iteration_statement REDUCE to statement" << endl; }
#line 2726 "parser.cpp"
    break;

  case 183: // statement: jump_statement
#line 622 "parser.y"
                           { cout << "jump_statement REDUCE to statement" << endl; }
#line 2732 "parser.cpp"
    break;

  case 184: // labeled_statement: "identifier" ":" statement
#line 626 "parser.y"
                                               { cout << "IDENTIFIER COLON statement REDUCE to label_statement" << endl; }
#line 2738 "parser.cpp"
    break;

  case 185: // labeled_statement: "case" constant_expression ":" statement
#line 627 "parser.y"
                                               { cout << "CASE constant_expression COLON statement REDUCE to label_statement" << endl; }
#line 2744 "parser.cpp"
    break;

  case 186: // labeled_statement: "default" ":" statement
#line 628 "parser.y"
                                               { cout << "DEFAULT COLON statement REDUCE to label_statement" << endl; }
#line 2750 "parser.cpp"
    break;

  case 187: // compound_statement: "{" "}"
#line 632 "parser.y"
                                                    { cout << "OCURLY CCURLY REDUCE to compound_statement" << endl; }
#line 2756 "parser.cpp"
    break;

  case 188: // compound_statement: "{" statement_list "}"
#line 633 "parser.y"
                                                    { cout << "OCURLY statement_list CCURLY REDUCE to compound_statement" << endl; }
#line 2762 "parser.cpp"
    break;

  case 189: // compound_statement: "{" declaration_list "}"
#line 634 "parser.y"
                                                    { cout << "OCURLY declaration_list CCURLY REDUCE to compound_statement" << endl; }
#line 2768 "parser.cpp"
    break;

  case 190: // compound_statement: "{" declaration_list statement_list "}"
#line 635 "parser.y"
                                                    { cout << "OCURLY declaration_list statement_list CCURLY REDUCE to compound_statement" << endl; }
#line 2774 "parser.cpp"
    break;

  case 191: // declaration_list: declaration
#line 639 "parser.y"
                                    { cout << "declaration REDUCE to declaration_list" << endl; }
#line 2780 "parser.cpp"
    break;

  case 192: // declaration_list: declaration_list declaration
#line 640 "parser.y"
                                    { cout << "declaration_list declaration REDUCE to declaration_list" << endl; }
#line 2786 "parser.cpp"
    break;

  case 193: // statement_list: statement
#line 644 "parser.y"
                               { cout << "statement REDUCE to statement_list" << endl; }
#line 2792 "parser.cpp"
    break;

  case 194: // statement_list: statement_list statement
#line 645 "parser.y"
                               { cout << "statement_list statement REDUCE to statement_list" << endl; }
#line 2798 "parser.cpp"
    break;

  case 195: // expression_statement: ";"
#line 649 "parser.y"
                            { cout << "SEMICOLON REDUCE to expression_statement" << endl; }
#line 2804 "parser.cpp"
    break;

  case 196: // expression_statement: expression ";"
#line 650 "parser.y"
                            { cout << "expression SEMICOLON REDUCE to expression_statement" << endl; }
#line 2810 "parser.cpp"
    break;

  case 197: // selection_statement: "if" "(" expression ")" statement
#line 654 "parser.y"
                                                           { cout << "IF OPAREN expression CPAREN statement REDUCE to selection_statement" << endl; }
#line 2816 "parser.cpp"
    break;

  case 198: // selection_statement: "if" "(" expression ")" statement "else" statement
#line 655 "parser.y"
                                                           { cout << "IF OPAREN expression CPAREN statement ELSE statement REDUCE to selection_statement" << endl; }
#line 2822 "parser.cpp"
    break;

  case 199: // selection_statement: "switch" "(" expression ")" statement
#line 656 "parser.y"
                                                           { cout << "SWITCH OPAREN expression CPAREN statement REDUCE to selection_statement" << endl; }
#line 2828 "parser.cpp"
    break;

  case 200: // iteration_statement: "while" "(" expression ")" statement
#line 660 "parser.y"
                                                                                       { cout << "WHILE OPAREN expression CPAREN statement REDUCE to iteration_statement" << endl; }
#line 2834 "parser.cpp"
    break;

  case 201: // iteration_statement: "do" statement "while" "(" expression ")" ";"
#line 661 "parser.y"
                                                                                       { cout << "DO statement WHILE OPAREN expression CPAREN SEMICOLON REDUCE to iteration_statement" << endl; }
#line 2840 "parser.cpp"
    break;

  case 202: // iteration_statement: "for" "(" expression_statement expression_statement ")" statement
#line 662 "parser.y"
                                                                                       { cout << "FOR OPAREN expression_statement expression_statement CPAREN statement REDUCE to iteration_statement" << endl; }
#line 2846 "parser.cpp"
    break;

  case 203: // iteration_statement: "for" "(" expression_statement expression_statement expression ")" statement
#line 663 "parser.y"
                                                                                       { cout << "FOR OPAREN expression_statement expression_statement expression CPAREN statement REDUCE to iteration_statement" << endl; }
#line 2852 "parser.cpp"
    break;

  case 204: // jump_statement: "goto" "identifier" ";"
#line 667 "parser.y"
                                  { cout << "GOTO IDENTIFIER SEMICOLON REDUCE to jump_statement" << endl; }
#line 2858 "parser.cpp"
    break;

  case 205: // jump_statement: "continue" ";"
#line 668 "parser.y"
                                  { cout << "CONTINUE SEMICOLON REDUCE to jump_statement" << endl; }
#line 2864 "parser.cpp"
    break;

  case 206: // jump_statement: "break" ";"
#line 669 "parser.y"
                                  { cout << "BREAK SEMICOLON REDUCE to jump_statement" << endl; }
#line 2870 "parser.cpp"
    break;

  case 207: // jump_statement: "return" ";"
#line 670 "parser.y"
                                  { cout << "RETURN SEMICOLON REDUCE to jump_statement" << endl; }
#line 2876 "parser.cpp"
    break;

  case 208: // jump_statement: "return" expression ";"
#line 671 "parser.y"
                                  { cout << "RETURN expression SEMICOLON REDUCE to jump_statement" << endl; }
#line 2882 "parser.cpp"
    break;

  case 209: // translation_unit: external_declaration
#line 675 "parser.y"
                                            { cout << "external_declaration REDUCE to translation_unit" << endl; }
#line 2888 "parser.cpp"
    break;

  case 210: // translation_unit: translation_unit external_declaration
#line 676 "parser.y"
                                            { cout << "translation_unit external_declaration REDUCE to translation_unit" << endl; }
#line 2894 "parser.cpp"
    break;

  case 211: // external_declaration: function_definition
#line 680 "parser.y"
                           { cout << "function_definition REDUCE to external_declaration" << endl; }
#line 2900 "parser.cpp"
    break;

  case 212: // external_declaration: declaration
#line 681 "parser.y"
                           { cout << "declaration REDUCE to external_declaration" << endl; }
#line 2906 "parser.cpp"
    break;

  case 213: // function_definition: declaration_specifiers declarator declaration_list compound_statement
#line 685 "parser.y"
                                                                            { cout << "declaration_specifiers declarator declaration_list compound_statement REDUCE to function_definition" << endl; }
#line 2912 "parser.cpp"
    break;

  case 214: // function_definition: declaration_specifiers declarator compound_statement
#line 686 "parser.y"
                                                                            { cout << "declaration_specifiers declarator compound_statement REDUCE to function_definition" << endl; }
#line 2918 "parser.cpp"
    break;

  case 215: // function_definition: declarator declaration_list compound_statement
#line 687 "parser.y"
                                                                            { cout << "declarator declaration_list compound_statement REDUCE to function_definition" << endl; }
#line 2924 "parser.cpp"
    break;

  case 216: // function_definition: declarator compound_statement
#line 688 "parser.y"
                                                                            { cout << "declarator compound_statement REDUCE to function_definition" << endl; }
#line 2930 "parser.cpp"
    break;


#line 2934 "parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -226;

  const signed char  Parser ::yytable_ninf_ = -1;

  const short
   Parser ::yypact_[] =
  {
     908,  -226,  -226,  -226,  -226,  -226,  -226,    38,  -226,  -226,
    -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,
    -226,  -226,    17,    22,  -226,    19,  1589,  1589,  -226,    43,
    -226,  1589,  1516,   -14,     5,   283,  -226,  -226,    15,    14,
      26,  -226,  -226,    22,  -226,   -33,  -226,  1325,  -226,  -226,
      35,  1625,  -226,   343,  -226,    19,  -226,  1516,  1370,   950,
     -14,  -226,  -226,    14,    40,   166,  -226,  -226,  -226,  -226,
    -226,    17,  1025,  -226,  1516,  1625,  1625,  1444,  -226,     8,
    1625,    49,  -226,  -226,  -226,    64,  1159,    79,    85,   783,
     104,   147,   131,   495,  1182,   139,   171,  -226,  -226,   519,
    -226,  1200,  1200,  -226,  -226,  -226,  -226,  -226,  -226,  -226,
      60,   344,  1159,  -226,   132,   -34,   156,    61,   148,   101,
     117,   150,   144,     3,  -226,  -226,    52,  -226,  -226,  -226,
     431,   607,  -226,  -226,  -226,  -226,   190,  -226,  -226,  -226,
    -226,    20,   193,   202,  -226,    72,  -226,  -226,  -226,  -226,
     206,   184,  1159,  -226,    14,  -226,  1025,  -226,  -226,  -226,
    1480,  -226,  -226,  -226,  1159,    95,  -226,   213,  -226,   783,
    -226,   222,  -226,   783,   218,  1043,   227,  1159,  -226,    97,
     519,  -226,  1159,  1159,    96,    -7,   225,   519,  -226,  -226,
     669,  1159,   278,  -226,  -226,   279,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,  -226,  -226,  -226,  1159,  -226,  1159,
    1159,  1159,  1159,  1159,  1159,  1159,  1159,  1159,  1159,  1159,
    1159,  1159,  1159,  1159,  1159,  1159,  1159,  1159,  -226,  1159,
    -226,   695,  -226,  -226,   867,  1066,  -226,    21,  -226,    63,
    -226,  1552,   284,  -226,  -226,  -226,  -226,  -226,  -226,   188,
    -226,  -226,  -226,     8,  1159,  -226,   783,  -226,   234,  1043,
    -226,   136,  -226,   237,   145,   149,  -226,  1284,   127,  -226,
    1084,   241,  -226,   159,  -226,    27,  -226,  -226,  -226,  -226,
    -226,  -226,   132,   132,   -34,   -34,   156,   156,   156,   156,
      61,    61,   148,   101,   117,   150,   204,   144,  -226,  -226,
    -226,   242,   243,  -226,   232,    63,  1407,  1141,  -226,  -226,
    -226,  -226,   927,  -226,  -226,  -226,  1159,   757,   783,   250,
     783,   783,  1025,  -226,   250,  1159,  -226,  -226,  1159,  -226,
    -226,  -226,  -226,   246,  -226,   248,  -226,  -226,   160,   783,
     164,   289,  -226,  -226,   208,  -226,  -226,  -226,  -226,   259,
    -226,   783,   783,  -226,   968,  -226,  -226,  -226,  -226
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
    -226,  -226,  -226,  -226,  -226,   -49,  -226,   -80,    56,    57,
     -63,    53,    89,    91,    93,   102,    99,  -226,   -58,   -70,
    -226,    12,   -56,    13,     0,  -226,   260,  -226,   133,  -226,
    -226,   255,   -68,   -55,  -226,    80,  -226,   269,   180,    46,
      11,   -30,    -5,  -226,   -53,  -226,    94,  -226,  -120,  -135,
    -225,   -69,    16,   -74,  -226,   -18,    25,   209,  -168,  -226,
    -226,  -226,  -226,   301,  -226
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
      25,   149,   157,   158,    60,   142,   238,   259,     1,   163,
     148,     1,   305,    24,    56,   174,    70,    64,    42,    71,
       1,   161,     1,     1,     1,   168,    48,    49,   149,    73,
     171,    52,   208,    40,     5,    25,    47,   148,    69,   138,
      58,    38,    59,   305,   185,   181,    50,   267,    24,   235,
     269,   226,   188,   189,   212,   213,   159,   233,   141,    22,
     263,   164,    22,   148,    21,    63,   136,   271,    44,    41,
     137,    22,    74,    22,   234,   234,   235,   235,   130,   229,
     227,    67,   136,    23,   327,    75,   157,   137,    39,    68,
     167,   317,   163,    51,   149,   255,   246,    80,    23,   257,
     152,   228,   169,   148,   229,   179,   149,    23,   251,    23,
      23,   184,    23,   170,   190,   148,   191,   306,   192,   307,
     274,    80,    80,    80,   242,   185,    80,   243,   172,   279,
     280,   281,   185,   193,   194,   195,   237,   278,   173,   216,
     217,   218,   219,   137,   252,    80,   262,   253,   229,   229,
     176,   266,   236,   286,   287,   288,   289,   233,   175,   298,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   149,   148,   304,
     268,   267,   315,   235,    76,   177,   148,   222,   229,   261,
     323,   318,   184,   182,   264,   265,   149,   229,   314,   184,
     320,   229,   223,   275,   321,   148,    80,    60,    76,    76,
      76,   325,   229,    76,   326,   349,   229,   153,   154,   351,
     225,   148,   209,   210,   211,   183,    80,   214,   215,   237,
     220,   221,    76,    80,   141,   245,   154,   224,   296,   311,
     312,   141,   157,   337,   341,    40,   342,   343,   240,   149,
      72,   335,   157,   333,   241,   345,   229,   328,   148,   353,
     354,   258,   268,   244,   167,   350,   254,   141,   282,   283,
     346,   284,   285,   290,   291,   256,   260,   356,   357,   148,
     270,   276,   277,    61,   157,   337,     1,   310,   316,   331,
       2,     3,   319,    76,     4,     5,   324,   329,   330,     6,
     322,   347,     7,     8,     9,   348,   141,   352,   355,    10,
      11,   292,    12,    76,   293,    13,    14,   294,    15,    16,
      76,    17,    18,    19,    20,    21,   297,   295,   338,   340,
     160,   155,   151,   313,   247,   309,    62,    22,   344,   231,
       0,     0,     0,     0,     0,     0,    81,    82,    83,    84,
       2,     3,    85,    86,     4,     5,    87,    88,    89,     6,
       0,     0,     7,     8,     9,    90,    91,    92,     0,    10,
      11,     0,    12,    23,    93,    13,    14,    94,    15,    16,
      95,    17,    18,    19,    20,    21,    96,     0,     0,     0,
       0,     0,    97,    53,    98,     0,     0,    99,     0,     0,
       0,     0,   100,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,     0,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,     0,   104,
       0,   105,   106,   107,    81,    82,    83,    84,     2,     3,
      85,    86,     4,     5,    87,    88,    89,     6,     0,     0,
       7,     8,     9,    90,    91,    92,     0,    10,    11,     0,
      12,     0,    93,    13,    14,    94,    15,    16,    95,    17,
      18,    19,    20,    21,    96,     0,     0,     0,     0,     0,
      97,    53,   230,     0,     0,    99,     0,     0,     0,     0,
     100,     0,     0,     0,     0,     0,     0,     0,   146,    82,
      83,    84,     0,     0,   101,   102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,     0,   104,     0,   105,
     106,   107,   146,    82,    83,    84,     2,     0,     0,    94,
       4,     5,     0,     0,     0,     6,     0,     0,     7,     0,
       9,     0,     0,     0,   178,    10,    11,     0,     0,    99,
       0,    13,    14,    94,   100,    16,     0,     0,    18,    19,
      20,    21,     0,     0,     0,     0,     0,     0,   101,   102,
       0,     0,     0,    99,     0,     0,     0,     0,   100,   103,
       0,   104,     0,   105,   106,   107,     0,     0,     0,     0,
       0,     0,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,     0,   104,     0,   105,   106,   107,
      81,    82,    83,    84,     0,     0,    85,    86,     0,     0,
      87,    88,    89,     0,     0,     0,     0,     0,     0,    90,
      91,    92,     0,     0,     0,     0,     0,     0,    93,     0,
       0,    94,     0,     0,    95,     0,     0,     0,     0,     0,
      96,     0,     0,     0,     0,     0,    97,    53,   232,     0,
       0,    99,     0,     0,     0,     0,   100,     0,     0,     0,
       0,     0,   146,    82,    83,    84,     0,     0,     0,     0,
     101,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,     0,   104,     0,   105,   106,   107,    81,    82,
      83,    84,     0,    94,    85,    86,     0,     0,    87,    88,
      89,     0,     0,     0,     0,     0,     0,    90,    91,    92,
       0,     0,     0,    99,   272,     0,    93,     0,   100,    94,
       0,     0,    95,     0,     0,     0,     0,     0,    96,     0,
       0,     0,   101,   102,    97,    53,   299,     0,     0,    99,
       0,     0,     0,   103,   100,   104,     0,   105,   106,   107,
     146,    82,    83,    84,     0,     0,     0,     0,   101,   102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
       0,   104,     0,   105,   106,   107,    81,    82,    83,    84,
       0,    94,    85,    86,     0,     0,    87,    88,    89,     0,
       0,     0,     0,     0,     0,    90,    91,    92,     0,     0,
       0,    99,   339,     0,    93,     0,   100,    94,     0,     0,
      95,     0,     0,     0,     0,     0,    96,     0,     0,     0,
     101,   102,    97,    53,     0,     0,     0,    99,     0,     0,
       0,   103,   100,   104,     0,   105,   106,   107,     0,     0,
       0,     0,     0,     0,     0,     0,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,     0,   104,
       1,   105,   106,   107,     2,     3,     0,     0,     4,     5,
       0,     0,     0,     6,     0,     0,     7,     8,     9,     0,
       0,     0,     0,    10,    11,     0,    12,     0,     0,    13,
      14,     0,    15,    16,     0,    17,    18,    19,    20,    21,
       0,     1,     0,     0,     0,     2,     3,     0,     0,     4,
       5,   234,   300,   235,     6,     0,     0,     7,     8,     9,
     146,    82,    83,    84,    10,    11,     0,    12,     0,     0,
      13,    14,     0,    15,    16,     0,    17,    18,    19,    20,
      21,     0,     0,   146,    82,    83,    84,    23,     0,     0,
       0,    94,    22,     0,     0,     0,     0,     0,     0,     0,
       0,   146,    82,    83,    84,     0,     0,   156,   336,     0,
       0,    99,     0,     0,    94,     0,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,     0,
     101,   102,    94,     0,    99,     0,     0,   147,     0,   100,
       0,   103,     0,   104,     0,   105,   106,   107,   156,   358,
       0,     0,    99,   101,   102,     0,     0,   100,   146,    82,
      83,    84,     0,     0,   103,     0,   104,     0,   105,   106,
     107,   101,   102,     0,     0,     0,   146,    82,    83,    84,
       0,     0,   103,     0,   104,     0,   105,   106,   107,    94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   146,
      82,    83,    84,     0,     0,   156,     0,    94,     0,    99,
       0,     0,     0,     0,   100,     0,     0,   146,    82,    83,
      84,     0,    97,     0,     0,     0,     0,    99,   101,   102,
      94,     0,   100,     0,     0,     0,     0,     0,     0,   103,
       0,   104,     0,   105,   106,   107,   101,   102,    94,     0,
      99,     0,     0,   303,     0,   100,     0,   103,     0,   104,
       0,   105,   106,   107,   322,     0,     0,     0,    99,   101,
     102,     0,     0,   100,   146,    82,    83,    84,     0,     0,
     103,     0,   104,     0,   105,   106,   107,   101,   102,     0,
       0,     0,   146,    82,    83,    84,     0,     0,   103,     0,
     104,     0,   105,   106,   107,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   146,    82,    83,    84,     0,
       0,     0,     0,    94,     0,    99,     0,     0,   334,     0,
     100,     0,     0,   146,    82,    83,    84,     0,     0,     0,
       0,     0,     0,    99,   101,   102,    94,     0,   100,     0,
       0,     0,     0,     0,     0,   103,     0,   104,     0,   105,
     106,   107,   101,   102,    94,     0,   180,     0,     0,     0,
       0,   100,     0,   103,     0,   104,     0,   105,   106,   107,
       0,     0,     0,     0,   187,   101,   102,     0,     0,   100,
       0,     0,     0,     0,     0,     0,   103,     0,   104,     0,
     105,   106,   107,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,     0,   104,     0,   105,   106,
     107,     2,     3,     0,     0,     4,     5,     0,     0,     0,
       6,     0,     0,     7,     8,     9,     0,     0,     0,     0,
      10,    11,     0,    12,     0,     0,    13,    14,     0,    15,
      16,     0,    17,    18,    19,    20,    21,     0,     0,     0,
       0,     0,     2,     3,     0,     0,     4,     5,   267,   300,
     235,     6,     0,     0,     7,     8,     9,     0,     0,     0,
       0,    10,    11,     0,    12,     0,     0,    13,    14,     0,
      15,    16,     0,    17,    18,    19,    20,    21,     0,     0,
       0,     0,     0,   139,    23,    53,     0,     2,     3,     0,
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
       0,    59,    72,    72,    34,    58,   141,   175,     3,    77,
      59,     3,   237,     0,    32,    89,    49,     3,    23,    52,
       3,    76,     3,     3,     3,    80,    26,    27,    86,    47,
      86,    31,   112,    22,    12,    35,    25,    86,    43,    57,
      54,     3,    56,   268,    99,    94,     3,    54,    35,    56,
     185,    48,   101,   102,    88,    89,    74,   131,    58,    54,
     180,    53,    54,   112,    42,    50,    55,   187,    49,    23,
      57,    54,    47,    54,    54,    54,    56,    56,    53,    52,
      77,    55,    71,    90,    57,    50,   156,    74,    50,    43,
      79,   259,   160,    50,   152,   169,   152,    51,    90,   173,
      60,    49,    53,   152,    52,    93,   164,    90,   164,    90,
      90,    99,    90,    49,    54,   164,    56,    54,    58,    56,
     190,    75,    76,    77,    52,   180,    80,    55,    49,   209,
     210,   211,   187,    73,    74,    75,   141,   207,    53,    78,
      79,    80,    81,   130,    49,    99,    49,    52,    52,    52,
       3,    55,   141,   216,   217,   218,   219,   231,    54,   229,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   235,   227,   235,
     185,    54,   256,    56,    51,    54,   235,    86,    52,   177,
     270,    55,   180,    54,   182,   183,   254,    52,   254,   187,
      55,    52,    85,   191,    55,   254,   160,   237,    75,    76,
      77,    52,    52,    80,    55,    55,    52,    51,    52,    55,
      76,   270,    90,    91,    92,    54,   180,    71,    72,   234,
      82,    83,    99,   187,   234,    51,    52,    87,   226,    51,
      52,   241,   312,   312,   318,   234,   320,   321,    55,   307,
      60,   307,   322,   306,    52,   325,    52,    53,   307,    51,
      52,    43,   267,    57,   253,   339,    53,   267,   212,   213,
     328,   214,   215,   220,   221,    53,    49,   351,   352,   328,
      55,     3,     3,     0,   354,   354,     3,     3,    54,    57,
       7,     8,    55,   160,    11,    12,    55,    55,    55,    16,
      50,    55,    19,    20,    21,    57,   306,    18,    49,    26,
      27,   222,    29,   180,   223,    32,    33,   224,    35,    36,
     187,    38,    39,    40,    41,    42,   227,   225,   316,   317,
      75,    71,    63,   253,   154,   241,    35,    54,   322,   130,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    -1,    29,    90,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    59,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    -1,    73,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    86,
      -1,    88,    89,    90,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      19,    20,    21,    22,    23,    24,    -1,    26,    27,    -1,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,    -1,    73,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    86,    -1,    88,
      89,    90,     3,     4,     5,     6,     7,    -1,    -1,    34,
      11,    12,    -1,    -1,    -1,    16,    -1,    -1,    19,    -1,
      21,    -1,    -1,    -1,    49,    26,    27,    -1,    -1,    54,
      -1,    32,    33,    34,    59,    36,    -1,    -1,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    59,    84,
      -1,    86,    -1,    88,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    -1,    86,    -1,    88,    89,    90,
       3,     4,     5,     6,    -1,    -1,     9,    10,    -1,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    34,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,    -1,
      73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    -1,    86,    -1,    88,    89,    90,     3,     4,
       5,     6,    -1,    34,     9,    10,    -1,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      -1,    -1,    -1,    54,    55,    -1,    31,    -1,    59,    34,
      -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    73,    74,    49,    50,    51,    -1,    -1,    54,
      -1,    -1,    -1,    84,    59,    86,    -1,    88,    89,    90,
       3,     4,     5,     6,    -1,    -1,    -1,    -1,    73,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    86,    -1,    88,    89,    90,     3,     4,     5,     6,
      -1,    34,     9,    10,    -1,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,    -1,
      -1,    54,    55,    -1,    31,    -1,    59,    34,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      73,    74,    49,    50,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    84,    59,    86,    -1,    88,    89,    90,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    86,
       3,    88,    89,    90,     7,     8,    -1,    -1,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    19,    20,    21,    -1,
      -1,    -1,    -1,    26,    27,    -1,    29,    -1,    -1,    32,
      33,    -1,    35,    36,    -1,    38,    39,    40,    41,    42,
      -1,     3,    -1,    -1,    -1,     7,     8,    -1,    -1,    11,
      12,    54,    55,    56,    16,    -1,    -1,    19,    20,    21,
       3,     4,     5,     6,    26,    27,    -1,    29,    -1,    -1,
      32,    33,    -1,    35,    36,    -1,    38,    39,    40,    41,
      42,    -1,    -1,     3,     4,     5,     6,    90,    -1,    -1,
      -1,    34,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,    -1,    50,    51,    -1,
      -1,    54,    -1,    -1,    34,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,
      73,    74,    34,    -1,    54,    -1,    -1,    57,    -1,    59,
      -1,    84,    -1,    86,    -1,    88,    89,    90,    50,    51,
      -1,    -1,    54,    73,    74,    -1,    -1,    59,     3,     4,
       5,     6,    -1,    -1,    84,    -1,    86,    -1,    88,    89,
      90,    73,    74,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,    -1,    84,    -1,    86,    -1,    88,    89,    90,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,    -1,    50,    -1,    34,    -1,    54,
      -1,    -1,    -1,    -1,    59,    -1,    -1,     3,     4,     5,
       6,    -1,    49,    -1,    -1,    -1,    -1,    54,    73,    74,
      34,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    86,    -1,    88,    89,    90,    73,    74,    34,    -1,
      54,    -1,    -1,    57,    -1,    59,    -1,    84,    -1,    86,
      -1,    88,    89,    90,    50,    -1,    -1,    -1,    54,    73,
      74,    -1,    -1,    59,     3,     4,     5,     6,    -1,    -1,
      84,    -1,    86,    -1,    88,    89,    90,    73,    74,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,    -1,    84,    -1,
      86,    -1,    88,    89,    90,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
      -1,    -1,    -1,    34,    -1,    54,    -1,    -1,    57,    -1,
      59,    -1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    73,    74,    34,    -1,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    86,    -1,    88,
      89,    90,    73,    74,    34,    -1,    54,    -1,    -1,    -1,
      -1,    59,    -1,    84,    -1,    86,    -1,    88,    89,    90,
      -1,    -1,    -1,    -1,    54,    73,    74,    -1,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    86,    -1,
      88,    89,    90,    73,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    -1,    86,    -1,    88,    89,
      90,     7,     8,    -1,    -1,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,
      26,    27,    -1,    29,    -1,    -1,    32,    33,    -1,    35,
      36,    -1,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,     7,     8,    -1,    -1,    11,    12,    54,    55,
      56,    16,    -1,    -1,    19,    20,    21,    -1,    -1,    -1,
      -1,    26,    27,    -1,    29,    -1,    -1,    32,    33,    -1,
      35,    36,    -1,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,     3,    90,    50,    -1,     7,     8,    -1,
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
      41,    42,    54,    90,   116,   117,   120,   121,   122,   123,
     129,   132,   133,   134,   135,   155,   156,   157,     3,    50,
     133,   132,   135,   136,    49,   118,   119,   133,   117,   117,
       3,    50,   117,    50,   116,   117,   148,   149,    54,    56,
     134,     0,   156,    50,     3,   130,   131,    55,   132,   135,
      49,    52,    60,   148,   149,    50,   121,   124,   125,   126,
     132,     3,     4,     5,     6,     9,    10,    13,    14,    15,
      22,    23,    24,    31,    34,    37,    43,    49,    51,    54,
      59,    73,    74,    84,    86,    88,    89,    90,    94,    95,
      96,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   114,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   133,   116,   148,     3,
      55,   117,   137,   138,   139,   140,     3,    57,    98,   111,
     115,   130,    60,    51,    52,   119,    50,   112,   144,   148,
     124,   126,    51,   125,    53,   127,   128,   133,   126,    53,
      49,   115,    49,    53,   146,    54,     3,    54,    49,   114,
      54,    98,    54,    54,   114,   126,   141,    54,    98,    98,
      54,    56,    58,    73,    74,    75,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,   113,   100,    90,
      91,    92,    88,    89,    71,    72,    78,    79,    80,    81,
      82,    83,    86,    85,    87,    76,    48,    77,    49,    52,
      51,   150,    51,   146,    54,    56,   133,   135,   142,   143,
      55,    52,    52,    55,    57,    51,   115,   131,   144,   145,
      51,   115,    49,    52,    53,   146,    53,   146,    43,   151,
      49,   114,    49,   141,   114,   114,    55,    54,   135,   142,
      55,   141,    55,    97,   112,   114,     3,     3,   112,   100,
     100,   100,   101,   101,   102,   102,   103,   103,   103,   103,
     104,   104,   105,   106,   107,   108,   114,   109,   112,    51,
      55,   137,   142,    57,   115,   143,    54,    56,    47,   139,
       3,    51,    52,   128,   115,   146,    54,   151,    55,    55,
      55,    55,    50,   100,    55,    52,    55,    57,    53,    55,
      55,    57,    55,   137,    57,   115,    51,   144,   114,    55,
     114,   146,   146,   146,   145,   112,   111,    55,    57,    55,
     146,    55,    18,    51,    52,    49,   146,   146,    51
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    93,    94,    94,    94,    95,    95,    95,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    97,    97,
      98,    98,    98,    98,    98,    98,    99,    99,    99,    99,
      99,    99,   100,   100,   101,   101,   101,   101,   102,   102,
     102,   103,   103,   103,   104,   104,   104,   104,   104,   105,
     105,   105,   106,   106,   107,   107,   108,   108,   109,   109,
     110,   110,   111,   111,   112,   112,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   114,   114,   115,
     116,   116,   117,   117,   117,   117,   117,   117,   118,   118,
     119,   119,   120,   120,   120,   120,   120,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   122,
     122,   122,   123,   123,   124,   124,   125,   126,   126,   126,
     126,   127,   127,   128,   128,   128,   129,   129,   129,   130,
     130,   131,   131,   132,   132,   133,   133,   134,   134,   134,
     134,   134,   134,   134,   135,   135,   135,   135,   136,   136,
     137,   137,   138,   138,   139,   139,   139,   140,   140,   141,
     141,   142,   142,   142,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   144,   144,   144,   145,   145,   146,   146,
     146,   146,   146,   146,   147,   147,   147,   148,   148,   148,
     148,   149,   149,   150,   150,   151,   151,   152,   152,   152,
     153,   153,   153,   153,   154,   154,   154,   154,   154,   155,
     155,   156,   156,   157,   157,   157,   157
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
  "\"/\"", "\"%\"", "$accept", "primary_expression", "constant",
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
       0,   218,   218,   219,   220,   224,   229,   234,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   254,   260,
     270,   271,   272,   273,   274,   275,   279,   280,   281,   282,
     283,   284,   288,   289,   293,   294,   295,   296,   300,   301,
     302,   306,   307,   308,   312,   313,   314,   315,   316,   320,
     321,   322,   326,   327,   331,   332,   336,   337,   341,   342,
     346,   347,   351,   352,   356,   357,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   375,   376,   380,
     384,   385,   389,   390,   391,   392,   393,   394,   398,   399,
     403,   404,   408,   409,   410,   411,   412,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   431,
     432,   433,   437,   438,   442,   443,   447,   451,   452,   453,
     454,   458,   464,   474,   475,   476,   480,   481,   482,   486,
     492,   502,   503,   507,   508,   512,   513,   517,   518,   519,
     520,   521,   522,   523,   527,   528,   529,   530,   534,   540,
     551,   552,   556,   557,   561,   562,   563,   567,   573,   583,
     584,   588,   589,   590,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   606,   607,   608,   612,   613,   617,   618,
     619,   620,   621,   622,   626,   627,   628,   632,   633,   634,
     635,   639,   640,   644,   645,   649,   650,   654,   655,   656,
     660,   661,   662,   663,   667,   668,   669,   670,   671,   675,
     676,   680,   681,   685,   686,   687,   688
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
#line 3943 "parser.cpp"

#line 691 "parser.y"


// Bison expects us to provide implementation - otherwise linker complains
void WadeSpace::Parser::error(const location &loc , const std::string &message) {
        
        // Location should be initialized inside scanner action, but is not in this example.
        // Let's grab location directly from driver class.
    // cout << "Error: " << message << endl << "Location: " << loc << endl;
    
        cout << "Error: " << message << endl << "Error location: " << driver.location() << endl;
}
