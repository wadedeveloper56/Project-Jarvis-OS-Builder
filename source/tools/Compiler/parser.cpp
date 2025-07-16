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
#line 88 "parser.y"

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

      case symbol_kind::S_additive_expression: // additive_expression
        value.YY_MOVE_OR_COPY< AdditiveExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_and_expression: // and_expression
        value.YY_MOVE_OR_COPY< AndExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assignment_expression: // assignment_expression
        value.YY_MOVE_OR_COPY< AssignmentExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
        value.YY_MOVE_OR_COPY< AssignmentOperator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_selection_statement: // selection_statement
      case symbol_kind::S_iteration_statement: // iteration_statement
      case symbol_kind::S_jump_statement: // jump_statement
        value.YY_MOVE_OR_COPY< BaseStatement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cast_expression: // cast_expression
        value.YY_MOVE_OR_COPY< CastExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_compound_statement: // compound_statement
        value.YY_MOVE_OR_COPY< CompoundStatement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_conditional_expression: // conditional_expression
        value.YY_MOVE_OR_COPY< ConditionalExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_constant: // constant
        value.YY_MOVE_OR_COPY< Constant > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_constant_expression: // constant_expression
        value.YY_MOVE_OR_COPY< ConstantExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.YY_MOVE_OR_COPY< Declaration > (YY_MOVE (that.value));
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

      case symbol_kind::S_equality_expression: // equality_expression
        value.YY_MOVE_OR_COPY< EqualityExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
        value.YY_MOVE_OR_COPY< ExclusiveOrExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
        value.YY_MOVE_OR_COPY< Expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_external_declaration: // external_declaration
        value.YY_MOVE_OR_COPY< ExternalDeclaration > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_definition: // function_definition
        value.YY_MOVE_OR_COPY< FunctionDefinition > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
        value.YY_MOVE_OR_COPY< InclusiveOrExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_init_declarator: // init_declarator
        value.YY_MOVE_OR_COPY< InitDeclarator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_initializer: // initializer
        value.YY_MOVE_OR_COPY< Initializer > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_labeled_statement: // labeled_statement
        value.YY_MOVE_OR_COPY< LabeledStatement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_logical_and_expression: // logical_and_expression
        value.YY_MOVE_OR_COPY< LogicalAndExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_logical_or_expression: // logical_or_expression
        value.YY_MOVE_OR_COPY< LogicalOrExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
        value.YY_MOVE_OR_COPY< MultiplicativeExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.YY_MOVE_OR_COPY< ParameterDeclaration > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
        value.YY_MOVE_OR_COPY< ParameterTypeList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pointer: // pointer
        value.YY_MOVE_OR_COPY< Pointer > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_postfix_expression: // postfix_expression
        value.YY_MOVE_OR_COPY< PostfixExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_primary_expression: // primary_expression
        value.YY_MOVE_OR_COPY< PrimaryExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_relational_expression: // relational_expression
        value.YY_MOVE_OR_COPY< RelationalExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_shift_expression: // shift_expression
        value.YY_MOVE_OR_COPY< ShiftExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
        value.YY_MOVE_OR_COPY< SpecifierQualifierList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_storage_class_specifier: // storage_class_specifier
        value.YY_MOVE_OR_COPY< StorageClassSpecifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_declaration: // struct_declaration
        value.YY_MOVE_OR_COPY< StructDeclaration > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_declarator: // struct_declarator
        value.YY_MOVE_OR_COPY< StructDeclarator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_or_union: // struct_or_union
        value.YY_MOVE_OR_COPY< StructOrUnion > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_or_union_specifier: // struct_or_union_specifier
        value.YY_MOVE_OR_COPY< StructOrUnionSpecifier > (YY_MOVE (that.value));
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

      case symbol_kind::S_unary_expression: // unary_expression
        value.YY_MOVE_OR_COPY< UnaryExpression > (YY_MOVE (that.value));
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

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.YY_MOVE_OR_COPY< std::vector<AssignmentExpression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_list: // statement_list
        value.YY_MOVE_OR_COPY< std::vector<BaseStatement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        value.YY_MOVE_OR_COPY< std::vector<Declaration> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.YY_MOVE_OR_COPY< std::vector<Enumerator> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_init_declarator_list: // init_declarator_list
        value.YY_MOVE_OR_COPY< std::vector<InitDeclarator> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_initializer_list: // initializer_list
        value.YY_MOVE_OR_COPY< std::vector<Initializer> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.YY_MOVE_OR_COPY< std::vector<ParameterDeclaration> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_declaration_list: // struct_declaration_list
        value.YY_MOVE_OR_COPY< std::vector<StructDeclaration> > (YY_MOVE (that.value));
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

      case symbol_kind::S_additive_expression: // additive_expression
        value.move< AdditiveExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_and_expression: // and_expression
        value.move< AndExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assignment_expression: // assignment_expression
        value.move< AssignmentExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
        value.move< AssignmentOperator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_selection_statement: // selection_statement
      case symbol_kind::S_iteration_statement: // iteration_statement
      case symbol_kind::S_jump_statement: // jump_statement
        value.move< BaseStatement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cast_expression: // cast_expression
        value.move< CastExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_compound_statement: // compound_statement
        value.move< CompoundStatement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_conditional_expression: // conditional_expression
        value.move< ConditionalExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_constant: // constant
        value.move< Constant > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_constant_expression: // constant_expression
        value.move< ConstantExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.move< Declaration > (YY_MOVE (that.value));
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

      case symbol_kind::S_equality_expression: // equality_expression
        value.move< EqualityExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
        value.move< ExclusiveOrExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
        value.move< Expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_external_declaration: // external_declaration
        value.move< ExternalDeclaration > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_definition: // function_definition
        value.move< FunctionDefinition > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
        value.move< InclusiveOrExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_init_declarator: // init_declarator
        value.move< InitDeclarator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_initializer: // initializer
        value.move< Initializer > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_labeled_statement: // labeled_statement
        value.move< LabeledStatement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_logical_and_expression: // logical_and_expression
        value.move< LogicalAndExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_logical_or_expression: // logical_or_expression
        value.move< LogicalOrExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
        value.move< MultiplicativeExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.move< ParameterDeclaration > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
        value.move< ParameterTypeList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pointer: // pointer
        value.move< Pointer > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_postfix_expression: // postfix_expression
        value.move< PostfixExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_primary_expression: // primary_expression
        value.move< PrimaryExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_relational_expression: // relational_expression
        value.move< RelationalExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_shift_expression: // shift_expression
        value.move< ShiftExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
        value.move< SpecifierQualifierList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_storage_class_specifier: // storage_class_specifier
        value.move< StorageClassSpecifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_declaration: // struct_declaration
        value.move< StructDeclaration > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_declarator: // struct_declarator
        value.move< StructDeclarator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_or_union: // struct_or_union
        value.move< StructOrUnion > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_or_union_specifier: // struct_or_union_specifier
        value.move< StructOrUnionSpecifier > (YY_MOVE (that.value));
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

      case symbol_kind::S_unary_expression: // unary_expression
        value.move< UnaryExpression > (YY_MOVE (that.value));
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

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.move< std::vector<AssignmentExpression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_list: // statement_list
        value.move< std::vector<BaseStatement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        value.move< std::vector<Declaration> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.move< std::vector<Enumerator> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_init_declarator_list: // init_declarator_list
        value.move< std::vector<InitDeclarator> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_initializer_list: // initializer_list
        value.move< std::vector<Initializer> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.move< std::vector<ParameterDeclaration> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_declaration_list: // struct_declaration_list
        value.move< std::vector<StructDeclaration> > (YY_MOVE (that.value));
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

      case symbol_kind::S_additive_expression: // additive_expression
        value.copy< AdditiveExpression > (that.value);
        break;

      case symbol_kind::S_and_expression: // and_expression
        value.copy< AndExpression > (that.value);
        break;

      case symbol_kind::S_assignment_expression: // assignment_expression
        value.copy< AssignmentExpression > (that.value);
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
        value.copy< AssignmentOperator > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_selection_statement: // selection_statement
      case symbol_kind::S_iteration_statement: // iteration_statement
      case symbol_kind::S_jump_statement: // jump_statement
        value.copy< BaseStatement > (that.value);
        break;

      case symbol_kind::S_cast_expression: // cast_expression
        value.copy< CastExpression > (that.value);
        break;

      case symbol_kind::S_compound_statement: // compound_statement
        value.copy< CompoundStatement > (that.value);
        break;

      case symbol_kind::S_conditional_expression: // conditional_expression
        value.copy< ConditionalExpression > (that.value);
        break;

      case symbol_kind::S_constant: // constant
        value.copy< Constant > (that.value);
        break;

      case symbol_kind::S_constant_expression: // constant_expression
        value.copy< ConstantExpression > (that.value);
        break;

      case symbol_kind::S_declaration: // declaration
        value.copy< Declaration > (that.value);
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

      case symbol_kind::S_equality_expression: // equality_expression
        value.copy< EqualityExpression > (that.value);
        break;

      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
        value.copy< ExclusiveOrExpression > (that.value);
        break;

      case symbol_kind::S_expression: // expression
        value.copy< Expression > (that.value);
        break;

      case symbol_kind::S_external_declaration: // external_declaration
        value.copy< ExternalDeclaration > (that.value);
        break;

      case symbol_kind::S_function_definition: // function_definition
        value.copy< FunctionDefinition > (that.value);
        break;

      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
        value.copy< InclusiveOrExpression > (that.value);
        break;

      case symbol_kind::S_init_declarator: // init_declarator
        value.copy< InitDeclarator > (that.value);
        break;

      case symbol_kind::S_initializer: // initializer
        value.copy< Initializer > (that.value);
        break;

      case symbol_kind::S_labeled_statement: // labeled_statement
        value.copy< LabeledStatement > (that.value);
        break;

      case symbol_kind::S_logical_and_expression: // logical_and_expression
        value.copy< LogicalAndExpression > (that.value);
        break;

      case symbol_kind::S_logical_or_expression: // logical_or_expression
        value.copy< LogicalOrExpression > (that.value);
        break;

      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
        value.copy< MultiplicativeExpression > (that.value);
        break;

      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.copy< ParameterDeclaration > (that.value);
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
        value.copy< ParameterTypeList > (that.value);
        break;

      case symbol_kind::S_pointer: // pointer
        value.copy< Pointer > (that.value);
        break;

      case symbol_kind::S_postfix_expression: // postfix_expression
        value.copy< PostfixExpression > (that.value);
        break;

      case symbol_kind::S_primary_expression: // primary_expression
        value.copy< PrimaryExpression > (that.value);
        break;

      case symbol_kind::S_relational_expression: // relational_expression
        value.copy< RelationalExpression > (that.value);
        break;

      case symbol_kind::S_shift_expression: // shift_expression
        value.copy< ShiftExpression > (that.value);
        break;

      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
        value.copy< SpecifierQualifierList > (that.value);
        break;

      case symbol_kind::S_storage_class_specifier: // storage_class_specifier
        value.copy< StorageClassSpecifier > (that.value);
        break;

      case symbol_kind::S_struct_declaration: // struct_declaration
        value.copy< StructDeclaration > (that.value);
        break;

      case symbol_kind::S_struct_declarator: // struct_declarator
        value.copy< StructDeclarator > (that.value);
        break;

      case symbol_kind::S_struct_or_union: // struct_or_union
        value.copy< StructOrUnion > (that.value);
        break;

      case symbol_kind::S_struct_or_union_specifier: // struct_or_union_specifier
        value.copy< StructOrUnionSpecifier > (that.value);
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

      case symbol_kind::S_unary_expression: // unary_expression
        value.copy< UnaryExpression > (that.value);
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

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.copy< std::vector<AssignmentExpression> > (that.value);
        break;

      case symbol_kind::S_statement_list: // statement_list
        value.copy< std::vector<BaseStatement> > (that.value);
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        value.copy< std::vector<Declaration> > (that.value);
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.copy< std::vector<Enumerator> > (that.value);
        break;

      case symbol_kind::S_init_declarator_list: // init_declarator_list
        value.copy< std::vector<InitDeclarator> > (that.value);
        break;

      case symbol_kind::S_initializer_list: // initializer_list
        value.copy< std::vector<Initializer> > (that.value);
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.copy< std::vector<ParameterDeclaration> > (that.value);
        break;

      case symbol_kind::S_struct_declaration_list: // struct_declaration_list
        value.copy< std::vector<StructDeclaration> > (that.value);
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

      case symbol_kind::S_additive_expression: // additive_expression
        value.move< AdditiveExpression > (that.value);
        break;

      case symbol_kind::S_and_expression: // and_expression
        value.move< AndExpression > (that.value);
        break;

      case symbol_kind::S_assignment_expression: // assignment_expression
        value.move< AssignmentExpression > (that.value);
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
        value.move< AssignmentOperator > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_selection_statement: // selection_statement
      case symbol_kind::S_iteration_statement: // iteration_statement
      case symbol_kind::S_jump_statement: // jump_statement
        value.move< BaseStatement > (that.value);
        break;

      case symbol_kind::S_cast_expression: // cast_expression
        value.move< CastExpression > (that.value);
        break;

      case symbol_kind::S_compound_statement: // compound_statement
        value.move< CompoundStatement > (that.value);
        break;

      case symbol_kind::S_conditional_expression: // conditional_expression
        value.move< ConditionalExpression > (that.value);
        break;

      case symbol_kind::S_constant: // constant
        value.move< Constant > (that.value);
        break;

      case symbol_kind::S_constant_expression: // constant_expression
        value.move< ConstantExpression > (that.value);
        break;

      case symbol_kind::S_declaration: // declaration
        value.move< Declaration > (that.value);
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

      case symbol_kind::S_equality_expression: // equality_expression
        value.move< EqualityExpression > (that.value);
        break;

      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
        value.move< ExclusiveOrExpression > (that.value);
        break;

      case symbol_kind::S_expression: // expression
        value.move< Expression > (that.value);
        break;

      case symbol_kind::S_external_declaration: // external_declaration
        value.move< ExternalDeclaration > (that.value);
        break;

      case symbol_kind::S_function_definition: // function_definition
        value.move< FunctionDefinition > (that.value);
        break;

      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
        value.move< InclusiveOrExpression > (that.value);
        break;

      case symbol_kind::S_init_declarator: // init_declarator
        value.move< InitDeclarator > (that.value);
        break;

      case symbol_kind::S_initializer: // initializer
        value.move< Initializer > (that.value);
        break;

      case symbol_kind::S_labeled_statement: // labeled_statement
        value.move< LabeledStatement > (that.value);
        break;

      case symbol_kind::S_logical_and_expression: // logical_and_expression
        value.move< LogicalAndExpression > (that.value);
        break;

      case symbol_kind::S_logical_or_expression: // logical_or_expression
        value.move< LogicalOrExpression > (that.value);
        break;

      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
        value.move< MultiplicativeExpression > (that.value);
        break;

      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.move< ParameterDeclaration > (that.value);
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
        value.move< ParameterTypeList > (that.value);
        break;

      case symbol_kind::S_pointer: // pointer
        value.move< Pointer > (that.value);
        break;

      case symbol_kind::S_postfix_expression: // postfix_expression
        value.move< PostfixExpression > (that.value);
        break;

      case symbol_kind::S_primary_expression: // primary_expression
        value.move< PrimaryExpression > (that.value);
        break;

      case symbol_kind::S_relational_expression: // relational_expression
        value.move< RelationalExpression > (that.value);
        break;

      case symbol_kind::S_shift_expression: // shift_expression
        value.move< ShiftExpression > (that.value);
        break;

      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
        value.move< SpecifierQualifierList > (that.value);
        break;

      case symbol_kind::S_storage_class_specifier: // storage_class_specifier
        value.move< StorageClassSpecifier > (that.value);
        break;

      case symbol_kind::S_struct_declaration: // struct_declaration
        value.move< StructDeclaration > (that.value);
        break;

      case symbol_kind::S_struct_declarator: // struct_declarator
        value.move< StructDeclarator > (that.value);
        break;

      case symbol_kind::S_struct_or_union: // struct_or_union
        value.move< StructOrUnion > (that.value);
        break;

      case symbol_kind::S_struct_or_union_specifier: // struct_or_union_specifier
        value.move< StructOrUnionSpecifier > (that.value);
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

      case symbol_kind::S_unary_expression: // unary_expression
        value.move< UnaryExpression > (that.value);
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

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.move< std::vector<AssignmentExpression> > (that.value);
        break;

      case symbol_kind::S_statement_list: // statement_list
        value.move< std::vector<BaseStatement> > (that.value);
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        value.move< std::vector<Declaration> > (that.value);
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.move< std::vector<Enumerator> > (that.value);
        break;

      case symbol_kind::S_init_declarator_list: // init_declarator_list
        value.move< std::vector<InitDeclarator> > (that.value);
        break;

      case symbol_kind::S_initializer_list: // initializer_list
        value.move< std::vector<Initializer> > (that.value);
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.move< std::vector<ParameterDeclaration> > (that.value);
        break;

      case symbol_kind::S_struct_declaration_list: // struct_declaration_list
        value.move< std::vector<StructDeclaration> > (that.value);
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

      case symbol_kind::S_additive_expression: // additive_expression
        yylhs.value.emplace< AdditiveExpression > ();
        break;

      case symbol_kind::S_and_expression: // and_expression
        yylhs.value.emplace< AndExpression > ();
        break;

      case symbol_kind::S_assignment_expression: // assignment_expression
        yylhs.value.emplace< AssignmentExpression > ();
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
        yylhs.value.emplace< AssignmentOperator > ();
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_selection_statement: // selection_statement
      case symbol_kind::S_iteration_statement: // iteration_statement
      case symbol_kind::S_jump_statement: // jump_statement
        yylhs.value.emplace< BaseStatement > ();
        break;

      case symbol_kind::S_cast_expression: // cast_expression
        yylhs.value.emplace< CastExpression > ();
        break;

      case symbol_kind::S_compound_statement: // compound_statement
        yylhs.value.emplace< CompoundStatement > ();
        break;

      case symbol_kind::S_conditional_expression: // conditional_expression
        yylhs.value.emplace< ConditionalExpression > ();
        break;

      case symbol_kind::S_constant: // constant
        yylhs.value.emplace< Constant > ();
        break;

      case symbol_kind::S_constant_expression: // constant_expression
        yylhs.value.emplace< ConstantExpression > ();
        break;

      case symbol_kind::S_declaration: // declaration
        yylhs.value.emplace< Declaration > ();
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

      case symbol_kind::S_equality_expression: // equality_expression
        yylhs.value.emplace< EqualityExpression > ();
        break;

      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
        yylhs.value.emplace< ExclusiveOrExpression > ();
        break;

      case symbol_kind::S_expression: // expression
        yylhs.value.emplace< Expression > ();
        break;

      case symbol_kind::S_external_declaration: // external_declaration
        yylhs.value.emplace< ExternalDeclaration > ();
        break;

      case symbol_kind::S_function_definition: // function_definition
        yylhs.value.emplace< FunctionDefinition > ();
        break;

      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
        yylhs.value.emplace< InclusiveOrExpression > ();
        break;

      case symbol_kind::S_init_declarator: // init_declarator
        yylhs.value.emplace< InitDeclarator > ();
        break;

      case symbol_kind::S_initializer: // initializer
        yylhs.value.emplace< Initializer > ();
        break;

      case symbol_kind::S_labeled_statement: // labeled_statement
        yylhs.value.emplace< LabeledStatement > ();
        break;

      case symbol_kind::S_logical_and_expression: // logical_and_expression
        yylhs.value.emplace< LogicalAndExpression > ();
        break;

      case symbol_kind::S_logical_or_expression: // logical_or_expression
        yylhs.value.emplace< LogicalOrExpression > ();
        break;

      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
        yylhs.value.emplace< MultiplicativeExpression > ();
        break;

      case symbol_kind::S_parameter_declaration: // parameter_declaration
        yylhs.value.emplace< ParameterDeclaration > ();
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
        yylhs.value.emplace< ParameterTypeList > ();
        break;

      case symbol_kind::S_pointer: // pointer
        yylhs.value.emplace< Pointer > ();
        break;

      case symbol_kind::S_postfix_expression: // postfix_expression
        yylhs.value.emplace< PostfixExpression > ();
        break;

      case symbol_kind::S_primary_expression: // primary_expression
        yylhs.value.emplace< PrimaryExpression > ();
        break;

      case symbol_kind::S_relational_expression: // relational_expression
        yylhs.value.emplace< RelationalExpression > ();
        break;

      case symbol_kind::S_shift_expression: // shift_expression
        yylhs.value.emplace< ShiftExpression > ();
        break;

      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
        yylhs.value.emplace< SpecifierQualifierList > ();
        break;

      case symbol_kind::S_storage_class_specifier: // storage_class_specifier
        yylhs.value.emplace< StorageClassSpecifier > ();
        break;

      case symbol_kind::S_struct_declaration: // struct_declaration
        yylhs.value.emplace< StructDeclaration > ();
        break;

      case symbol_kind::S_struct_declarator: // struct_declarator
        yylhs.value.emplace< StructDeclarator > ();
        break;

      case symbol_kind::S_struct_or_union: // struct_or_union
        yylhs.value.emplace< StructOrUnion > ();
        break;

      case symbol_kind::S_struct_or_union_specifier: // struct_or_union_specifier
        yylhs.value.emplace< StructOrUnionSpecifier > ();
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

      case symbol_kind::S_unary_expression: // unary_expression
        yylhs.value.emplace< UnaryExpression > ();
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

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        yylhs.value.emplace< std::vector<AssignmentExpression> > ();
        break;

      case symbol_kind::S_statement_list: // statement_list
        yylhs.value.emplace< std::vector<BaseStatement> > ();
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        yylhs.value.emplace< std::vector<Declaration> > ();
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        yylhs.value.emplace< std::vector<Enumerator> > ();
        break;

      case symbol_kind::S_init_declarator_list: // init_declarator_list
        yylhs.value.emplace< std::vector<InitDeclarator> > ();
        break;

      case symbol_kind::S_initializer_list: // initializer_list
        yylhs.value.emplace< std::vector<Initializer> > ();
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        yylhs.value.emplace< std::vector<ParameterDeclaration> > ();
        break;

      case symbol_kind::S_struct_declaration_list: // struct_declaration_list
        yylhs.value.emplace< std::vector<StructDeclaration> > ();
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
#line 279 "parser.y"
                                { yylhs.value.as< PrimaryExpression > () = PrimaryExpression(yystack_[0].value.as < std::string > ()); cout << "IDENTIFIER REDUCE to primary_expression" << endl; }
#line 2234 "parser.cpp"
    break;

  case 3: // primary_expression: constant
#line 280 "parser.y"
                                { yylhs.value.as< PrimaryExpression > () = PrimaryExpression(yystack_[0].value.as < Constant > ()); cout << "constant REDUCE to primary_expression" << endl; }
#line 2240 "parser.cpp"
    break;

  case 4: // primary_expression: "(" expression ")"
#line 281 "parser.y"
                                { yylhs.value.as< PrimaryExpression > () = PrimaryExpression(yystack_[1].value.as < Expression > ()); cout << "OPAREN expression CPAREN REDUCE to primary_expression" << endl; }
#line 2246 "parser.cpp"
    break;

  case 5: // constant: "f_const"
#line 285 "parser.y"
                      {
                        long double &id = yystack_[0].value.as < long double > ();
                        yylhs.value.as< Constant > () = Constant(id);
                        cout << "F_CONST REDUCE to constant " << id << endl;
                      }
#line 2256 "parser.cpp"
    break;

  case 6: // constant: "i_const"
#line 290 "parser.y"
                      {
                        std::uint64_t &id = yystack_[0].value.as < uint64_t > ();
                        yylhs.value.as< Constant > () = Constant(id);
                        cout << "I_CONST REDUCE to constant " << id << endl;
                      }
#line 2266 "parser.cpp"
    break;

  case 7: // constant: "sting_literal"
#line 295 "parser.y"
                      {
                        std::string &id = yystack_[0].value.as < std::string > ();
                        yylhs.value.as< Constant > () = Constant(id);
                        cout << "STRING_LITERAL REDUCE to constant  " << id << endl;
                      }
#line 2276 "parser.cpp"
    break;

  case 8: // postfix_expression: primary_expression
#line 302 "parser.y"
                                                                   { yylhs.value.as< PostfixExpression > () = PostfixExpression(yystack_[0].value.as < PrimaryExpression > ()); cout << "primary_expression REDUCE to postfix_expression" << endl; }
#line 2282 "parser.cpp"
    break;

  case 9: // postfix_expression: postfix_expression "[" expression "]"
#line 303 "parser.y"
                                                                   { yylhs.value.as< PostfixExpression > () = PostfixExpression(yystack_[3].value.as < PostfixExpression > (),yystack_[1].value.as < Expression > ()); cout << "postfix_expression OBRACE expression CBRACE REDUCE to postfix_expression" << endl; }
#line 2288 "parser.cpp"
    break;

  case 10: // postfix_expression: postfix_expression "(" ")"
#line 304 "parser.y"
                                                                   { yylhs.value.as< PostfixExpression > () = PostfixExpression(yystack_[2].value.as < PostfixExpression > (),yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::string > ()); cout << "postfix_expression OPAREN CPAREN REDUCE to postfix_expression" << endl; }
#line 2294 "parser.cpp"
    break;

  case 11: // postfix_expression: postfix_expression "(" argument_expression_list ")"
#line 305 "parser.y"
                                                                   { yylhs.value.as< PostfixExpression > () = PostfixExpression(yystack_[3].value.as < PostfixExpression > (),yystack_[1].value.as < std::vector<AssignmentExpression> > ()); cout << "postfix_expression OPAREN argument_expression_list CPAREN REDUCE to postfix_expression" << endl; }
#line 2300 "parser.cpp"
    break;

  case 12: // postfix_expression: postfix_expression "." "identifier"
#line 306 "parser.y"
                                                                   { yylhs.value.as< PostfixExpression > () = PostfixExpression(yystack_[2].value.as < PostfixExpression > (),yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::string > ()); cout << "postfix_expression PERIOD_OP IDENTIFIER REDUCE to postfix_expression" << endl; }
#line 2306 "parser.cpp"
    break;

  case 13: // postfix_expression: postfix_expression "->" "identifier"
#line 307 "parser.y"
                                                                   { yylhs.value.as< PostfixExpression > () = PostfixExpression(yystack_[2].value.as < PostfixExpression > (),yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::string > ()); cout << "postfix_expression PTR_OP IDENTIFIER REDUCE to postfix_expression" << endl; }
#line 2312 "parser.cpp"
    break;

  case 14: // postfix_expression: postfix_expression "++"
#line 308 "parser.y"
                                                                   { yylhs.value.as< PostfixExpression > () = PostfixExpression(yystack_[1].value.as < PostfixExpression > (),yystack_[0].value.as < std::string > (),""); cout << "postfix_expression INC_OP REDUCE to postfix_expression" << endl; }
#line 2318 "parser.cpp"
    break;

  case 15: // postfix_expression: postfix_expression "--"
#line 309 "parser.y"
                                                                   { yylhs.value.as< PostfixExpression > () = PostfixExpression(yystack_[1].value.as < PostfixExpression > (),yystack_[0].value.as < std::string > (),""); cout << "postfix_expression DEC_OP REDUCE to postfix_expression" << endl; }
#line 2324 "parser.cpp"
    break;

  case 16: // postfix_expression: "(" type_name ")" "{" initializer_list "}"
#line 310 "parser.y"
                                                                   { yylhs.value.as< PostfixExpression > () = PostfixExpression(yystack_[4].value.as < TypeName > (),yystack_[1].value.as < std::vector<Initializer> > ()); cout << "OPAREN type_name CPAREN_OP OCURLY_OP initializer_list CCURLY REDUCE to postfix_expression" << endl; }
#line 2330 "parser.cpp"
    break;

  case 17: // postfix_expression: "(" type_name ")" "{" initializer_list "," "}"
#line 311 "parser.y"
                                                                   { yylhs.value.as< PostfixExpression > () = PostfixExpression(yystack_[5].value.as < TypeName > (),yystack_[2].value.as < std::vector<Initializer> > ()); cout << "OPAREN type_name CPAREN_OP OCURLY_OP initializer_list COMMA CCURLY REDUCE to postfix_expression" << endl; }
#line 2336 "parser.cpp"
    break;

  case 18: // argument_expression_list: assignment_expression
#line 315 "parser.y"
                            {
                             AssignmentExpression exp = yystack_[0].value.as < AssignmentExpression > ();
                             yylhs.value.as < std::vector<AssignmentExpression> > () = std::vector<AssignmentExpression>();
                             yylhs.value.as < std::vector<AssignmentExpression> > ().push_back(exp);
                             cout << "assignment_expression REDUCE argument_expression_list" << endl;
                            }
#line 2347 "parser.cpp"
    break;

  case 19: // argument_expression_list: argument_expression_list "," assignment_expression
#line 321 "parser.y"
                                                           {
            AssignmentExpression value1 = yystack_[0].value.as < AssignmentExpression > ();
            std::vector<AssignmentExpression> &value2 = yystack_[2].value.as < std::vector<AssignmentExpression> > ();
            value2.push_back(value1);
            yylhs.value.as < std::vector<AssignmentExpression> > () = value2;
            cout << "argument_expression_list COMMA assignment_expression REDUCE argument_expression_list" << endl;
        }
#line 2359 "parser.cpp"
    break;

  case 20: // unary_expression: postfix_expression
#line 331 "parser.y"
                                     { yylhs.value.as< UnaryExpression > () = UnaryExpression(yystack_[0].value.as < PostfixExpression > ()); cout << "postfix_expression REDUCE unary_expression" << endl;}
#line 2365 "parser.cpp"
    break;

  case 21: // unary_expression: "++" unary_expression
#line 332 "parser.y"
                                     { yylhs.value.as< UnaryExpression > () = UnaryExpression(yystack_[1].value.as < std::string > (),yystack_[0].value.as < UnaryExpression > ()); cout << "INC_OP unary_expression REDUCE unary_expression" << endl;}
#line 2371 "parser.cpp"
    break;

  case 22: // unary_expression: "--" unary_expression
#line 333 "parser.y"
                                     { yylhs.value.as< UnaryExpression > () = UnaryExpression(yystack_[1].value.as < std::string > (),yystack_[0].value.as < UnaryExpression > ()); cout << "DEC_OP unary_expression REDUCE unary_expression" << endl;}
#line 2377 "parser.cpp"
    break;

  case 23: // unary_expression: unary_operator cast_expression
#line 334 "parser.y"
                                     { yylhs.value.as< UnaryExpression > () = UnaryExpression(yystack_[1].value.as < std::string > (),yystack_[0].value.as < CastExpression > ()); cout << "unary_operator cast_expression REDUCE unary_expression" << endl;}
#line 2383 "parser.cpp"
    break;

  case 24: // unary_expression: "sizeof" unary_expression
#line 335 "parser.y"
                                     { yylhs.value.as< UnaryExpression > () = UnaryExpression(yystack_[1].value.as < std::string > (),yystack_[0].value.as < UnaryExpression > ()); cout << "SIZEOF unary_expression REDUCE unary_expression" << endl;}
#line 2389 "parser.cpp"
    break;

  case 25: // unary_expression: "sizeof" "(" type_name ")"
#line 336 "parser.y"
                                     { yylhs.value.as< UnaryExpression > () = UnaryExpression(yystack_[3].value.as < std::string > (),yystack_[1].value.as < TypeName > ()); cout << "SIZEOF OPAREN type_name CPAREN REDUCE unary_expression" << endl;}
#line 2395 "parser.cpp"
    break;

  case 26: // unary_operator: "&"
#line 340 "parser.y"
                {yylhs.value.as< std::string > () = yystack_[0].value.as < std::string > (); cout << "BIT_AND REDUCE to unary_operator" << endl;}
#line 2401 "parser.cpp"
    break;

  case 27: // unary_operator: "*"
#line 341 "parser.y"
                {yylhs.value.as< std::string > () = yystack_[0].value.as < std::string > (); cout << "TIMES_OP REDUCE to unary_operator" << endl;}
#line 2407 "parser.cpp"
    break;

  case 28: // unary_operator: "+"
#line 342 "parser.y"
                {yylhs.value.as< std::string > () = yystack_[0].value.as < std::string > (); cout << "PLUS_OP REDUCE to unary_operator" << endl;}
#line 2413 "parser.cpp"
    break;

  case 29: // unary_operator: "-"
#line 343 "parser.y"
                {yylhs.value.as< std::string > () = yystack_[0].value.as < std::string > (); cout << "MINUS_OP REDUCE to unary_operator" << endl;}
#line 2419 "parser.cpp"
    break;

  case 30: // unary_operator: "~"
#line 344 "parser.y"
                {yylhs.value.as< std::string > () = yystack_[0].value.as < std::string > (); cout << "TILDE REDUCE to unary_operator" << endl;}
#line 2425 "parser.cpp"
    break;

  case 31: // unary_operator: "!"
#line 345 "parser.y"
                {yylhs.value.as< std::string > () = yystack_[0].value.as < std::string > (); cout << "NOT_OP REDUCE to unary_operator" << endl;}
#line 2431 "parser.cpp"
    break;

  case 32: // cast_expression: unary_expression
#line 349 "parser.y"
                                               { yylhs.value.as< CastExpression > () = CastExpression(yystack_[0].value.as < UnaryExpression > ());  cout << "unary_expression REDUCE to cast_expression" << endl;}
#line 2437 "parser.cpp"
    break;

  case 33: // cast_expression: "(" type_name ")" cast_expression
#line 350 "parser.y"
                                               { yylhs.value.as< CastExpression > () = CastExpression(yystack_[2].value.as < TypeName > (),yystack_[0].value.as < CastExpression > ());  cout << "unary_expression REDUCE to cast_expression" << endl;}
#line 2443 "parser.cpp"
    break;

  case 34: // multiplicative_expression: cast_expression
#line 354 "parser.y"
                                                         { yylhs.value.as< MultiplicativeExpression > () = MultiplicativeExpression(yystack_[0].value.as < CastExpression > ());  cout << "cast_expression REDUCE to multiplicative_expression" << endl;}
#line 2449 "parser.cpp"
    break;

  case 35: // multiplicative_expression: multiplicative_expression "*" cast_expression
#line 355 "parser.y"
                                                         { yylhs.value.as< MultiplicativeExpression > () = MultiplicativeExpression(yystack_[2].value.as < MultiplicativeExpression > (),yystack_[1].value.as < std::string > (),yystack_[0].value.as < CastExpression > ()); cout << "multiplicative_expression TIMES_OP cast_expression REDUCE to multiplicative_expression" << endl;}
#line 2455 "parser.cpp"
    break;

  case 36: // multiplicative_expression: multiplicative_expression "/" cast_expression
#line 356 "parser.y"
                                                         { yylhs.value.as< MultiplicativeExpression > () = MultiplicativeExpression(yystack_[2].value.as < MultiplicativeExpression > (),yystack_[1].value.as < std::string > (),yystack_[0].value.as < CastExpression > ()); cout << "multiplicative_expression DIV_OP cast_expression REDUCE to multiplicative_expression" << endl;}
#line 2461 "parser.cpp"
    break;

  case 37: // multiplicative_expression: multiplicative_expression "%" cast_expression
#line 357 "parser.y"
                                                         { yylhs.value.as< MultiplicativeExpression > () = MultiplicativeExpression(yystack_[2].value.as < MultiplicativeExpression > (),yystack_[1].value.as < std::string > (),yystack_[0].value.as < CastExpression > ()); cout << "multiplicative_expression MOD_OP cast_expression REDUCE to multiplicative_expression" << endl;}
#line 2467 "parser.cpp"
    break;

  case 38: // additive_expression: multiplicative_expression
#line 361 "parser.y"
                                                              { yylhs.value.as< AdditiveExpression > () = AdditiveExpression(yystack_[0].value.as < MultiplicativeExpression > ());  cout << "multiplicative_expression REDUCE to additive_expression" << endl;}
#line 2473 "parser.cpp"
    break;

  case 39: // additive_expression: additive_expression "+" multiplicative_expression
#line 362 "parser.y"
                                                              { yylhs.value.as< AdditiveExpression > () = AdditiveExpression(yystack_[2].value.as < AdditiveExpression > (),yystack_[1].value.as < std::string > (),yystack_[0].value.as < MultiplicativeExpression > ()); cout << "additive_expression REDUCE to multiplicative_expression" << endl;}
#line 2479 "parser.cpp"
    break;

  case 40: // additive_expression: additive_expression "-" multiplicative_expression
#line 363 "parser.y"
                                                              { yylhs.value.as< AdditiveExpression > () = AdditiveExpression(yystack_[2].value.as < AdditiveExpression > (),yystack_[1].value.as < std::string > (),yystack_[0].value.as < MultiplicativeExpression > ()); cout << "additive_expression REDUCE to multiplicative_expression" << endl;}
#line 2485 "parser.cpp"
    break;

  case 41: // shift_expression: additive_expression
#line 367 "parser.y"
                                                    { yylhs.value.as< ShiftExpression > () = ShiftExpression(yystack_[0].value.as < AdditiveExpression > ());  cout << "additive_expression REDUCE to shift_expression" << endl;}
#line 2491 "parser.cpp"
    break;

  case 42: // shift_expression: shift_expression "<<" additive_expression
#line 368 "parser.y"
                                                    { yylhs.value.as< ShiftExpression > () = ShiftExpression(yystack_[2].value.as < ShiftExpression > (),yystack_[1].value.as < std::string > (),yystack_[0].value.as < AdditiveExpression > ()); cout << "shift_expression LEFT_OP additive_expression REDUCE to shift_expression" << endl;}
#line 2497 "parser.cpp"
    break;

  case 43: // shift_expression: shift_expression ">>" additive_expression
#line 369 "parser.y"
                                                    { yylhs.value.as< ShiftExpression > () = ShiftExpression(yystack_[2].value.as < ShiftExpression > (),yystack_[1].value.as < std::string > (),yystack_[0].value.as < AdditiveExpression > ()); cout << "shift_expression RIGHT_OP additive_expression REDUCE to shift_expression" << endl;}
#line 2503 "parser.cpp"
    break;

  case 44: // relational_expression: shift_expression
#line 373 "parser.y"
                                                             { yylhs.value.as< RelationalExpression > () = RelationalExpression(yystack_[0].value.as < ShiftExpression > ());  cout << "shift_expression REDUCE to relational_expression" << endl;}
#line 2509 "parser.cpp"
    break;

  case 45: // relational_expression: relational_expression "<" shift_expression
#line 374 "parser.y"
                                                             { yylhs.value.as< RelationalExpression > () = RelationalExpression(yystack_[2].value.as < RelationalExpression > (),yystack_[1].value.as < std::string > (),yystack_[0].value.as < ShiftExpression > ()); cout << "relational_expression LESS shift_expression REDUCE to shift_expression" << endl;}
#line 2515 "parser.cpp"
    break;

  case 46: // relational_expression: relational_expression ">" shift_expression
#line 375 "parser.y"
                                                             { yylhs.value.as< RelationalExpression > () = RelationalExpression(yystack_[2].value.as < RelationalExpression > (),yystack_[1].value.as < std::string > (),yystack_[0].value.as < ShiftExpression > ()); cout << "relational_expression GREATER shift_expression REDUCE to shift_expression" << endl;}
#line 2521 "parser.cpp"
    break;

  case 47: // relational_expression: relational_expression "<=" shift_expression
#line 376 "parser.y"
                                                             { yylhs.value.as< RelationalExpression > () = RelationalExpression(yystack_[2].value.as < RelationalExpression > (),yystack_[1].value.as < std::string > (),yystack_[0].value.as < ShiftExpression > ()); cout << "relational_expression LESS_EQUAL shift_expression REDUCE to shift_expression" << endl;}
#line 2527 "parser.cpp"
    break;

  case 48: // relational_expression: relational_expression ">=" shift_expression
#line 377 "parser.y"
                                                             { yylhs.value.as< RelationalExpression > () = RelationalExpression(yystack_[2].value.as < RelationalExpression > (),yystack_[1].value.as < std::string > (),yystack_[0].value.as < ShiftExpression > ()); cout << "relational_expression GREATER_EQUAL shift_expression REDUCE to shift_expression" << endl;}
#line 2533 "parser.cpp"
    break;

  case 49: // equality_expression: relational_expression
#line 381 "parser.y"
                                                             { yylhs.value.as< EqualityExpression > () = EqualityExpression(yystack_[0].value.as < RelationalExpression > ());  cout << "relational_expression REDUCE to equality_expression" << endl;}
#line 2539 "parser.cpp"
    break;

  case 50: // equality_expression: equality_expression "==" relational_expression
#line 382 "parser.y"
                                                             { yylhs.value.as< EqualityExpression > () = EqualityExpression(yystack_[2].value.as < EqualityExpression > (),yystack_[1].value.as < std::string > (),yystack_[0].value.as < RelationalExpression > ()); cout << "equality_expression EQUAL_EQUAL relational_expression REDUCE to equality_expression" << endl;}
#line 2545 "parser.cpp"
    break;

  case 51: // equality_expression: equality_expression "!=" relational_expression
#line 383 "parser.y"
                                                             { yylhs.value.as< EqualityExpression > () = EqualityExpression(yystack_[2].value.as < EqualityExpression > (),yystack_[1].value.as < std::string > (),yystack_[0].value.as < RelationalExpression > ()); cout << "equality_expression NOT_EQUAL relational_expression REDUCE to equality_expression" << endl;}
#line 2551 "parser.cpp"
    break;

  case 52: // and_expression: equality_expression
#line 387 "parser.y"
                                                  { yylhs.value.as< AndExpression > () = AndExpression(yystack_[0].value.as < EqualityExpression > ());  cout << "equality_expression REDUCE to and_expression" << endl;}
#line 2557 "parser.cpp"
    break;

  case 53: // and_expression: and_expression "&" equality_expression
#line 388 "parser.y"
                                                  { yylhs.value.as< AndExpression > () = AndExpression(yystack_[2].value.as < AndExpression > (),yystack_[0].value.as < EqualityExpression > ()); cout << "and_expression BIT_AND equality_expression REDUCE to and_expression" << endl;}
#line 2563 "parser.cpp"
    break;

  case 54: // exclusive_or_expression: and_expression
#line 392 "parser.y"
                                                     { yylhs.value.as< ExclusiveOrExpression > () = ExclusiveOrExpression(yystack_[0].value.as < AndExpression > ());  cout << "and_expression REDUCE to exclusive_or_expression" << endl;}
#line 2569 "parser.cpp"
    break;

  case 55: // exclusive_or_expression: exclusive_or_expression "^" and_expression
#line 393 "parser.y"
                                                     { yylhs.value.as< ExclusiveOrExpression > () = ExclusiveOrExpression(yystack_[2].value.as < ExclusiveOrExpression > (),yystack_[0].value.as < AndExpression > ()); cout << "exclusive_or_expression XOR_OP and_expression REDUCE to exclusive_or_expression" << endl;}
#line 2575 "parser.cpp"
    break;

  case 56: // inclusive_or_expression: exclusive_or_expression
#line 397 "parser.y"
                                                             { yylhs.value.as< InclusiveOrExpression > () = InclusiveOrExpression(yystack_[0].value.as < ExclusiveOrExpression > ());  cout << "exclusive_or_expression REDUCE to inclusive_or_expression" << endl;}
#line 2581 "parser.cpp"
    break;

  case 57: // inclusive_or_expression: inclusive_or_expression "|" exclusive_or_expression
#line 398 "parser.y"
                                                             { yylhs.value.as< InclusiveOrExpression > () = InclusiveOrExpression(yystack_[2].value.as < InclusiveOrExpression > (),yystack_[0].value.as < ExclusiveOrExpression > ()); cout << "inclusive_or_expression BIT_OR exclusive_or_expression REDUCE to inclusive_or_expression" << endl;}
#line 2587 "parser.cpp"
    break;

  case 58: // logical_and_expression: inclusive_or_expression
#line 402 "parser.y"
                                                             { yylhs.value.as< LogicalAndExpression > () = LogicalAndExpression(yystack_[0].value.as < InclusiveOrExpression > ());  cout << "inclusive_or_expression REDUCE to logical_and_expression" << endl;}
#line 2593 "parser.cpp"
    break;

  case 59: // logical_and_expression: logical_and_expression "&&" inclusive_or_expression
#line 403 "parser.y"
                                                             { yylhs.value.as< LogicalAndExpression > () = LogicalAndExpression(yystack_[2].value.as < LogicalAndExpression > (),yystack_[0].value.as < InclusiveOrExpression > ()); cout << "inclusive_or_expression REDUCE to logical_and_expression" << endl;}
#line 2599 "parser.cpp"
    break;

  case 60: // logical_or_expression: logical_and_expression
#line 407 "parser.y"
                                                          { yylhs.value.as< LogicalOrExpression > () = LogicalOrExpression(yystack_[0].value.as < LogicalAndExpression > ());  cout << "inclusive_and_expression REDUCE to logical_or_expression" << endl;}
#line 2605 "parser.cpp"
    break;

  case 61: // logical_or_expression: logical_or_expression "||" logical_and_expression
#line 408 "parser.y"
                                                          { yylhs.value.as< LogicalOrExpression > () = LogicalOrExpression(yystack_[2].value.as < LogicalOrExpression > (),yystack_[0].value.as < LogicalAndExpression > ()); cout << "logical_or_expression OR_OP logical_and_expression REDUCE to logical_or_expression" << endl;}
#line 2611 "parser.cpp"
    break;

  case 62: // conditional_expression: logical_or_expression
#line 412 "parser.y"
                                                                              { yylhs.value.as< ConditionalExpression > () = ConditionalExpression(yystack_[0].value.as < LogicalOrExpression > ());  cout << "logical_or_expression REDUCE to conditional_expression" << endl;}
#line 2617 "parser.cpp"
    break;

  case 63: // conditional_expression: logical_or_expression "question" expression ":" conditional_expression
#line 413 "parser.y"
                                                                              { yylhs.value.as< ConditionalExpression > () = ConditionalExpression(yystack_[4].value.as < LogicalOrExpression > (),yystack_[2].value.as < Expression > (),yystack_[0].value.as < ConditionalExpression > ()); cout << "logical_or_expression QUESTION expression COLON conditional_expression REDUCE to conditional_expression" << endl;}
#line 2623 "parser.cpp"
    break;

  case 64: // assignment_expression: conditional_expression
#line 417 "parser.y"
                                                                  { yylhs.value.as< AssignmentExpression > () = AssignmentExpression(yystack_[0].value.as < ConditionalExpression > ());  cout << "conditional_expression REDUCE to assignment_expression" << endl;}
#line 2629 "parser.cpp"
    break;

  case 65: // assignment_expression: unary_expression assignment_operator assignment_expression
#line 418 "parser.y"
                                                                  { yylhs.value.as< AssignmentExpression > () = AssignmentExpression(yystack_[2].value.as < UnaryExpression > (),yystack_[1].value.as < AssignmentOperator > (),yystack_[0].value.as < AssignmentExpression > ()); cout << "unary_expression assignment_operator assignment_expression REDUCE to assignment_expression" << endl;}
#line 2635 "parser.cpp"
    break;

  case 66: // assignment_operator: "="
#line 422 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(EQUAL);  cout << "EQUAL_OP REDUCE to assignment_operator" << endl;}
#line 2641 "parser.cpp"
    break;

  case 67: // assignment_operator: "*="
#line 423 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(MUL_ASSIGN);  cout << "MUL_ASSIGN REDUCE to assignment_operator" << endl;}
#line 2647 "parser.cpp"
    break;

  case 68: // assignment_operator: "/="
#line 424 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(DIV_ASSIGN);  cout << "DIV_ASSIGN REDUCE to assignment_operator" << endl;}
#line 2653 "parser.cpp"
    break;

  case 69: // assignment_operator: "%="
#line 425 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(MOD_ASSIGN);  cout << "MOG_ASSIGN REDUCE to assignment_operator" << endl;}
#line 2659 "parser.cpp"
    break;

  case 70: // assignment_operator: "+="
#line 426 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(ADD_ASSIGN);  cout << "ADD_ASSIGN REDUCE to assignment_operator" << endl;}
#line 2665 "parser.cpp"
    break;

  case 71: // assignment_operator: "-="
#line 427 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(SUB_ASSIGN);  cout << "SUB_ASSIGN REDUCE to assignment_operator" << endl;}
#line 2671 "parser.cpp"
    break;

  case 72: // assignment_operator: "<<="
#line 428 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(LEFT_ASSIGN);  cout << "LEFT_ASSIGN REDUCE to assignment_operator" << endl;}
#line 2677 "parser.cpp"
    break;

  case 73: // assignment_operator: ">>="
#line 429 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(RIGHT_ASSIGN);  cout << "RIGHT_ASSIGN REDUCE to assignment_operator" << endl;}
#line 2683 "parser.cpp"
    break;

  case 74: // assignment_operator: "&="
#line 430 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(AND_ASSIGN);  cout << "AND_ASSIGN REDUCE to assignment_operator" << endl;}
#line 2689 "parser.cpp"
    break;

  case 75: // assignment_operator: "^="
#line 431 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(XOR_ASSIGN);  cout << "XOR_ASSIGN REDUCE to assignment_operator" << endl;}
#line 2695 "parser.cpp"
    break;

  case 76: // assignment_operator: "|="
#line 432 "parser.y"
                     { yylhs.value.as< AssignmentOperator > () = AssignmentOperator(OR_ASSIGN);  cout << "OR_ASSIGN REDUCE to assignment_operator" << endl;}
#line 2701 "parser.cpp"
    break;

  case 77: // expression: assignment_expression
#line 436 "parser.y"
                                              { yylhs.value.as< Expression > () = Expression(yystack_[0].value.as < AssignmentExpression > ());  cout << "asignment_expression REDUCE to expression" << endl;}
#line 2707 "parser.cpp"
    break;

  case 78: // expression: expression "," assignment_expression
#line 437 "parser.y"
                                              { yylhs.value.as< Expression > () = Expression(yystack_[2].value.as < Expression > (),yystack_[1].value.as < std::string > (),yystack_[0].value.as < AssignmentExpression > ()); cout << "expression COMMA assignment_expression COMMA  REDUCE to expression" << endl;}
#line 2713 "parser.cpp"
    break;

  case 79: // constant_expression: conditional_expression
#line 441 "parser.y"
                              { yylhs.value.as< ConstantExpression > () = ConstantExpression(yystack_[0].value.as < ConditionalExpression > ());  cout << "conditional_expression REDUCE to constant_expression" << endl;}
#line 2719 "parser.cpp"
    break;

  case 80: // declaration: declaration_specifiers ";"
#line 445 "parser.y"
                                                             { yylhs.value.as< Declaration > () = Declaration(yystack_[1].value.as < DeclarationSpecifiers > ()); cout << "declaration_specifiers SEMICOLON REDUCE to declaration" << endl;}
#line 2725 "parser.cpp"
    break;

  case 81: // declaration: declaration_specifiers init_declarator_list ";"
#line 446 "parser.y"
                                                             { yylhs.value.as< Declaration > () = Declaration(yystack_[2].value.as < DeclarationSpecifiers > (),yystack_[1].value.as < std::vector<InitDeclarator> > ()); cout << "declaration_specifiers init_declarator_list SEMICOLON REDUCE to declaration" << endl;}
#line 2731 "parser.cpp"
    break;

  case 82: // declaration_specifiers: storage_class_specifier
#line 450 "parser.y"
                                                      { yylhs.value.as< DeclarationSpecifiers > () = DeclarationSpecifiers(yystack_[0].value.as < StorageClassSpecifier > ()); cout << "storage_class_specifier REDUCE to declaration_specifiers" << endl;}
#line 2737 "parser.cpp"
    break;

  case 83: // declaration_specifiers: storage_class_specifier declaration_specifiers
#line 451 "parser.y"
                                                      { yylhs.value.as< DeclarationSpecifiers > () = DeclarationSpecifiers(yystack_[1].value.as < StorageClassSpecifier > (),yystack_[0].value.as < DeclarationSpecifiers > ()); cout << "storage_class_specifier declaration_specifiers REDUCE to declaration_specifiers" << endl;}
#line 2743 "parser.cpp"
    break;

  case 84: // declaration_specifiers: type_specifier
#line 452 "parser.y"
                                                      { yylhs.value.as< DeclarationSpecifiers > () = DeclarationSpecifiers(yystack_[0].value.as < TypeSpecifier > ()); cout << "type_specifier REDUCE to declaration_specifiers" << endl;}
#line 2749 "parser.cpp"
    break;

  case 85: // declaration_specifiers: type_specifier declaration_specifiers
#line 453 "parser.y"
                                                      { yylhs.value.as< DeclarationSpecifiers > () = DeclarationSpecifiers(yystack_[1].value.as < TypeSpecifier > (),yystack_[0].value.as < DeclarationSpecifiers > ()); cout << "type_specifier declaration_specifiers REDUCE to declaration_specifiers" << endl;}
#line 2755 "parser.cpp"
    break;

  case 86: // declaration_specifiers: type_qualifier
#line 454 "parser.y"
                                                      { yylhs.value.as< DeclarationSpecifiers > () = DeclarationSpecifiers(yystack_[0].value.as < TypeQualifier > ()); cout << "type_qualifier REDUCE to declaration_specifiers" << endl;}
#line 2761 "parser.cpp"
    break;

  case 87: // declaration_specifiers: type_qualifier declaration_specifiers
#line 455 "parser.y"
                                                      { yylhs.value.as< DeclarationSpecifiers > () = DeclarationSpecifiers(yystack_[1].value.as < TypeQualifier > (),yystack_[0].value.as < DeclarationSpecifiers > ()); cout << "type_qualifier declaration_specifiers REDUCE to declaration_specifiers" << endl;}
#line 2767 "parser.cpp"
    break;

  case 88: // init_declarator_list: init_declarator
#line 459 "parser.y"
                                                 {
                                                  InitDeclarator exp = yystack_[0].value.as < InitDeclarator > ();
                                                  yylhs.value.as < std::vector<InitDeclarator> > () = std::vector<InitDeclarator>();
                                                  yylhs.value.as < std::vector<InitDeclarator> > ().push_back(exp);
                                                  cout << "init_declarator REDUCE to init_declarator_list" << endl;
                                                 }
#line 2778 "parser.cpp"
    break;

  case 89: // init_declarator_list: init_declarator_list "," init_declarator
#line 465 "parser.y"
                                                 {
                                                  InitDeclarator value1 = yystack_[0].value.as < InitDeclarator > ();
                                                  std::vector<InitDeclarator> &value2 = yystack_[2].value.as < std::vector<InitDeclarator> > ();
                                                  value2.push_back(value1);
                                                  yylhs.value.as < std::vector<InitDeclarator> > () = value2;
                                                  cout << "init_declarator_list COMMA init_declarator REDUCE to init_declarator_list" << endl;
                                                 }
#line 2790 "parser.cpp"
    break;

  case 90: // init_declarator: declarator
#line 475 "parser.y"
                                    { yylhs.value.as< InitDeclarator > () = InitDeclarator(yystack_[0].value.as < Declarator > ()); cout << "declarator REDUCE to init_declarator" << endl;}
#line 2796 "parser.cpp"
    break;

  case 91: // init_declarator: declarator "=" initializer
#line 476 "parser.y"
                                    { yylhs.value.as< InitDeclarator > () = InitDeclarator(yystack_[2].value.as < Declarator > (),yystack_[0].value.as < Initializer > ()); cout << "declarator EQUAL initializer REDUCE to init_declarator" << endl;}
#line 2802 "parser.cpp"
    break;

  case 92: // storage_class_specifier: "typedef"
#line 480 "parser.y"
                { yylhs.value.as< StorageClassSpecifier > () = StorageClassSpecifier(yystack_[0].value.as < std::string > (),TYPEDEF); cout << "TYPEDEF REDUCE to storage_class_specifier" << endl;}
#line 2808 "parser.cpp"
    break;

  case 93: // storage_class_specifier: "extern"
#line 481 "parser.y"
                { yylhs.value.as< StorageClassSpecifier > () = StorageClassSpecifier(yystack_[0].value.as < std::string > (),EXTERN); cout << "EXTERN REDUCE to storage_class_specifier" << endl;}
#line 2814 "parser.cpp"
    break;

  case 94: // storage_class_specifier: "static"
#line 482 "parser.y"
                { yylhs.value.as< StorageClassSpecifier > () = StorageClassSpecifier(yystack_[0].value.as < std::string > (),STATIC); cout << "STATIC REDUCE to storage_class_specifier" << endl;}
#line 2820 "parser.cpp"
    break;

  case 95: // storage_class_specifier: "auto"
#line 483 "parser.y"
                { yylhs.value.as< StorageClassSpecifier > () = StorageClassSpecifier(yystack_[0].value.as < std::string > (),AUTO); cout << "AUTO REDUCE to storage_class_specifier" << endl;}
#line 2826 "parser.cpp"
    break;

  case 96: // storage_class_specifier: "register"
#line 484 "parser.y"
                { yylhs.value.as< StorageClassSpecifier > () = StorageClassSpecifier(yystack_[0].value.as < std::string > (),REGISTER); cout << "REGISTER REDUCE to storage_class_specifier" << endl;}
#line 2832 "parser.cpp"
    break;

  case 97: // type_specifier: "void"
#line 488 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(VOID); cout << "VOID REDUCE to type_specifier" << endl;}
#line 2838 "parser.cpp"
    break;

  case 98: // type_specifier: "char"
#line 489 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(CHAR); cout << "CHAR REDUCE to type_specifier" << endl;}
#line 2844 "parser.cpp"
    break;

  case 99: // type_specifier: "short"
#line 490 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(SHORT); cout << "SHORT REDUCE to type_specifier" << endl;}
#line 2850 "parser.cpp"
    break;

  case 100: // type_specifier: "int"
#line 491 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(INT); cout << "INT REDUCE to type_specifier" << endl;}
#line 2856 "parser.cpp"
    break;

  case 101: // type_specifier: "long"
#line 492 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(LONG); cout << "LONG REDUCE to type_specifier" << endl;}
#line 2862 "parser.cpp"
    break;

  case 102: // type_specifier: "long long"
#line 493 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(LONG_LONG); cout << "LONG_LONG REDUCE to type_specifier" << endl;}
#line 2868 "parser.cpp"
    break;

  case 103: // type_specifier: "float"
#line 494 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(FLOAT); cout << "FLOAT REDUCE to type_specifier" << endl;}
#line 2874 "parser.cpp"
    break;

  case 104: // type_specifier: "double"
#line 495 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(DOUBLE); cout << "DOUBLE REDUCE to type_specifier" << endl;}
#line 2880 "parser.cpp"
    break;

  case 105: // type_specifier: "long double"
#line 496 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(LONG_DOUBLE); cout << "LONG_DOUBLE REDUCE to type_specifier" << endl;}
#line 2886 "parser.cpp"
    break;

  case 106: // type_specifier: "bool"
#line 497 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(BOOL); cout << "BOOL REDUCE to type_specifier" << endl;}
#line 2892 "parser.cpp"
    break;

  case 107: // type_specifier: "imaginary"
#line 498 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(IMAGINARY); cout << "IMAGINARY REDUCE to type_specifier" << endl;}
#line 2898 "parser.cpp"
    break;

  case 108: // type_specifier: "complex"
#line 499 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(COMPLEX); cout << "COMPLEX REDUCE to type_specifier" << endl;}
#line 2904 "parser.cpp"
    break;

  case 109: // type_specifier: "signed"
#line 500 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(SIGNED); cout << "SIGNED REDUCE to type_specifier" << endl;}
#line 2910 "parser.cpp"
    break;

  case 110: // type_specifier: "unsigned"
#line 501 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(UNSIGNED); cout << "UNIGNED REDUCE to type_specifier" << endl;}
#line 2916 "parser.cpp"
    break;

  case 111: // type_specifier: struct_or_union_specifier
#line 502 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(yystack_[0].value.as < StructOrUnionSpecifier > ()); cout << "struct_or_union_specifier REDUCE to type_specifier" << endl;}
#line 2922 "parser.cpp"
    break;

  case 112: // type_specifier: enum_specifier
#line 503 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(yystack_[0].value.as < EnumSpecifier > ()); cout << "enum_specifier REDUCE to type_specifier" << endl;}
#line 2928 "parser.cpp"
    break;

  case 113: // type_specifier: "type name"
#line 504 "parser.y"
                                { yylhs.value.as< TypeSpecifier > () = TypeSpecifier(TYPE_NAME); cout << "TYPE_NAME REDUCE to type_specifier" << endl;}
#line 2934 "parser.cpp"
    break;

  case 114: // struct_or_union_specifier: struct_or_union "identifier" "{" struct_declaration_list "}"
#line 508 "parser.y"
                                                                         { yylhs.value.as< StructOrUnionSpecifier > () = StructOrUnionSpecifier(yystack_[4].value.as < StructOrUnion > (),yystack_[3].value.as < std::string > (),yystack_[1].value.as < std::vector<StructDeclaration> > ()); cout << "struct_or_union IDENTIFIER OCURLY struct_declaration_list CCURLY REDUCE to struct_or_union_specifier" << endl;}
#line 2940 "parser.cpp"
    break;

  case 115: // struct_or_union_specifier: struct_or_union "{" struct_declaration_list "}"
#line 509 "parser.y"
                                                                         { yylhs.value.as< StructOrUnionSpecifier > () = StructOrUnionSpecifier(yystack_[3].value.as < StructOrUnion > (),yystack_[1].value.as < std::vector<StructDeclaration> > ()); cout << "struct_or_union OCURLY struct_declaration_list CCURLY REDUCE to struct_or_union_specifier" << endl;}
#line 2946 "parser.cpp"
    break;

  case 116: // struct_or_union_specifier: struct_or_union "identifier"
#line 510 "parser.y"
                                                                         { yylhs.value.as< StructOrUnionSpecifier > () = StructOrUnionSpecifier(yystack_[1].value.as < StructOrUnion > (),yystack_[0].value.as < std::string > ()); cout << "struct_or_union IDENTIFIER REDUCE to struct_or_union_specifier" << endl;}
#line 2952 "parser.cpp"
    break;

  case 117: // struct_or_union: "struct"
#line 514 "parser.y"
               { yylhs.value.as< StructOrUnion > () = StructOrUnion(STRUCT); cout << "STRUCT REDUCE to struct_or_union" << endl;}
#line 2958 "parser.cpp"
    break;

  case 118: // struct_or_union: "union"
#line 515 "parser.y"
               { yylhs.value.as< StructOrUnion > () = StructOrUnion(UNION); cout << "UNION REDUCE to struct_or_union" << endl;}
#line 2964 "parser.cpp"
    break;

  case 119: // struct_declaration_list: struct_declaration
#line 519 "parser.y"
                            {
                             StructDeclaration exp = yystack_[0].value.as < StructDeclaration > ();
                             yylhs.value.as < std::vector<StructDeclaration> > () = std::vector<StructDeclaration>();
                             yylhs.value.as < std::vector<StructDeclaration> > ().push_back(exp);
                             cout << "struct_declaration REDUCE to struct_declaration_list" << endl;
                            }
#line 2975 "parser.cpp"
    break;

  case 120: // struct_declaration_list: struct_declaration_list struct_declaration
#line 525 "parser.y"
                                                     {
                                                       StructDeclaration value1 = yystack_[0].value.as < StructDeclaration > ();
                                                       std::vector<StructDeclaration> &value2 = yystack_[1].value.as < std::vector<StructDeclaration> > ();
                                                       value2.push_back(value1);
                                                       yylhs.value.as < std::vector<StructDeclaration> > () = value2;
                                                       cout << "struct_declaration_list struct_declaration REDUCE to struct_declaration_list" << endl;
                                                     }
#line 2987 "parser.cpp"
    break;

  case 121: // struct_declaration: specifier_qualifier_list struct_declarator_list ";"
#line 535 "parser.y"
                                                                { yylhs.value.as< StructDeclaration > () = StructDeclaration(yystack_[2].value.as < SpecifierQualifierList > (),yystack_[1].value.as < std::vector<StructDeclarator> > ()); cout << "specifier_qualifier_list struct_declarator_list SEMICOLON REDUCE to struct_declaration" << endl;}
#line 2993 "parser.cpp"
    break;

  case 122: // specifier_qualifier_list: type_specifier specifier_qualifier_list
#line 539 "parser.y"
                                              { yylhs.value.as< SpecifierQualifierList > () = SpecifierQualifierList(yystack_[0].value.as < SpecifierQualifierList > (),yystack_[1].value.as < TypeSpecifier > ()); cout << "type_specifier specifier_qualifier_list REDUCE to specifier_qualifier_list" << endl;}
#line 2999 "parser.cpp"
    break;

  case 123: // specifier_qualifier_list: type_specifier
#line 540 "parser.y"
                                              { yylhs.value.as< SpecifierQualifierList > () = SpecifierQualifierList(yystack_[0].value.as < TypeSpecifier > ()); cout << "type_specifier REDUCE to specifier_qualifier_list" << endl;}
#line 3005 "parser.cpp"
    break;

  case 124: // specifier_qualifier_list: type_qualifier specifier_qualifier_list
#line 541 "parser.y"
                                              { yylhs.value.as< SpecifierQualifierList > () = SpecifierQualifierList(yystack_[0].value.as < SpecifierQualifierList > (),yystack_[1].value.as < TypeQualifier > ()); cout << "type_qualifier specifier_qualifier_list REDUCE to specifier_qualifier_list" << endl;}
#line 3011 "parser.cpp"
    break;

  case 125: // specifier_qualifier_list: type_qualifier
#line 542 "parser.y"
                                              { yylhs.value.as< SpecifierQualifierList > () = SpecifierQualifierList(yystack_[0].value.as < TypeQualifier > ()); cout << "type_qualifier REDUCE to specifier_qualifier_list" << endl;}
#line 3017 "parser.cpp"
    break;

  case 126: // struct_declarator_list: struct_declarator
#line 546 "parser.y"
                                                     {
                                                       StructDeclarator exp = yystack_[0].value.as < StructDeclarator > ();
                                                       yylhs.value.as < std::vector<StructDeclarator> > () = std::vector<StructDeclarator>();
                                                       yylhs.value.as < std::vector<StructDeclarator> > ().push_back(exp);
                                                       cout << "struct_declarator REDUCE to struct_declarator_list" << endl;
                                                     }
#line 3028 "parser.cpp"
    break;

  case 127: // struct_declarator_list: struct_declarator_list "," struct_declarator
#line 552 "parser.y"
                                                     {
                                                       StructDeclarator value1 = yystack_[0].value.as < StructDeclarator > ();
                                                       std::vector<StructDeclarator> &value2 = yystack_[2].value.as < std::vector<StructDeclarator> > ();
                                                       value2.push_back(value1);
                                                       yylhs.value.as < std::vector<StructDeclarator> > () = value2;
                                                       cout << "struct_declarator_list COMMA struct_declarator REDUCE to struct_declarator_list" << endl;
                                                     }
#line 3040 "parser.cpp"
    break;

  case 128: // struct_declarator: declarator
#line 562 "parser.y"
                                           { yylhs.value.as< StructDeclarator > () = StructDeclarator(yystack_[0].value.as < Declarator > ()); cout << "declarator REDUCE to struct_declarator" << endl;}
#line 3046 "parser.cpp"
    break;

  case 129: // struct_declarator: ":" constant_expression
#line 563 "parser.y"
                                           { yylhs.value.as< StructDeclarator > () = StructDeclarator(yystack_[0].value.as < ConstantExpression > ()); cout << "COLON constant_expression REDUCE to struct_declarator" << endl;}
#line 3052 "parser.cpp"
    break;

  case 130: // struct_declarator: declarator ":" constant_expression
#line 564 "parser.y"
                                           { yylhs.value.as< StructDeclarator > () = StructDeclarator(yystack_[2].value.as < Declarator > (),yystack_[0].value.as < ConstantExpression > ()); cout << "declarator COLON constant_expression REDUCE to struct_declarator" << endl;}
#line 3058 "parser.cpp"
    break;

  case 131: // enum_specifier: "enum" "{" enumerator_list "}"
#line 568 "parser.y"
                                                     { yylhs.value.as< EnumSpecifier > () = EnumSpecifier(yystack_[1].value.as < std::vector<Enumerator> > ()); cout << "ENUM OCURLY enumerator_list CCURLY REDUCE to enum_specifier" << endl;}
#line 3064 "parser.cpp"
    break;

  case 132: // enum_specifier: "enum" "identifier" "{" enumerator_list "}"
#line 569 "parser.y"
                                                     { yylhs.value.as< EnumSpecifier > () = EnumSpecifier(yystack_[3].value.as < std::string > (),yystack_[1].value.as < std::vector<Enumerator> > ()); cout << "ENUM IDENTIFIER OCURLY enumerator_list CCURLY REDUCE to enum_specifier" << endl;}
#line 3070 "parser.cpp"
    break;

  case 133: // enum_specifier: "enum" "identifier"
#line 570 "parser.y"
                                                     { yylhs.value.as< EnumSpecifier > () = EnumSpecifier(yystack_[0].value.as < std::string > ()); cout << "ENUM IDENTIFIER REDUCE to enum_specifier" << endl;}
#line 3076 "parser.cpp"
    break;

  case 134: // enumerator_list: enumerator
#line 574 "parser.y"
                                        {
                                          Enumerator exp = yystack_[0].value.as < Enumerator > ();
                                          yylhs.value.as < std::vector<Enumerator> > () = std::vector<Enumerator>();
                                          yylhs.value.as < std::vector<Enumerator> > ().push_back(exp);
                                          cout << "enumerator REDUCE enumerator_list" << endl;
                                        }
#line 3087 "parser.cpp"
    break;

  case 135: // enumerator_list: enumerator_list "," enumerator
#line 580 "parser.y"
                                        {
                                          Enumerator value1 = yystack_[0].value.as < Enumerator > ();
                                          std::vector<Enumerator> &value2 = yystack_[2].value.as < std::vector<Enumerator> > ();
                                          value2.push_back(value1);
                                          yylhs.value.as < std::vector<Enumerator> > () = value2;
                                          cout << "enumerator_list COMMA enumerator REDUCE enumerator_list" << endl;
                                        }
#line 3099 "parser.cpp"
    break;

  case 136: // enumerator: "identifier"
#line 590 "parser.y"
                                           { yylhs.value.as< Enumerator > () = Enumerator(yystack_[0].value.as < std::string > ()); cout << "IDENTIFIER REDUCE to ENUMERATOR" << endl;}
#line 3105 "parser.cpp"
    break;

  case 137: // enumerator: "identifier" "=" constant_expression
#line 591 "parser.y"
                                           { yylhs.value.as< Enumerator > () = Enumerator(yystack_[2].value.as < std::string > (),yystack_[0].value.as < ConstantExpression > ()); cout << "IDENTIFIER EQUAL constant_expression REDUCE to ENUMERATOR" << endl;}
#line 3111 "parser.cpp"
    break;

  case 138: // type_qualifier: "const"
#line 595 "parser.y"
               { yylhs.value.as< TypeQualifier > () = TypeQualifier(yystack_[0].value.as < std::string > (),CONST); cout << "CONST REDUCE to type_qualifier" << endl;}
#line 3117 "parser.cpp"
    break;

  case 139: // type_qualifier: "volatile"
#line 596 "parser.y"
               { yylhs.value.as< TypeQualifier > () = TypeQualifier(yystack_[0].value.as < std::string > (),VOLATILE); cout << "VOLATILE REDUCE to type_qualifier" << endl;}
#line 3123 "parser.cpp"
    break;

  case 140: // declarator: pointer direct_declarator
#line 600 "parser.y"
                                { yylhs.value.as< Declarator > () = Declarator(yystack_[1].value.as < Pointer > (),yystack_[0].value.as < DirectDeclarator > ()); cout << "pointer direct_declarator REDUCE to declarator" << endl;}
#line 3129 "parser.cpp"
    break;

  case 141: // declarator: direct_declarator
#line 601 "parser.y"
                                { yylhs.value.as< Declarator > () = Declarator(yystack_[0].value.as < DirectDeclarator > ()); cout << "direct_declarator REDUCE to declarator" << endl;}
#line 3135 "parser.cpp"
    break;

  case 142: // direct_declarator: "identifier"
#line 605 "parser.y"
                                                            { yylhs.value.as< DirectDeclarator > () = DirectDeclarator(yystack_[0].value.as < std::string > ()); cout << "IDENTIFIER REDUCE to direct_declarator" << endl;}
#line 3141 "parser.cpp"
    break;

  case 143: // direct_declarator: "(" declarator ")"
#line 606 "parser.y"
                                                            { yylhs.value.as< DirectDeclarator > () = DirectDeclarator(); cout << "OPAREN declarator CPAREN REDUCE to direct_declarator" << endl;}
#line 3147 "parser.cpp"
    break;

  case 144: // direct_declarator: direct_declarator "[" constant_expression "]"
#line 607 "parser.y"
                                                            { yylhs.value.as< DirectDeclarator > () = DirectDeclarator(); cout << "direct_declarator OBRACE constant_expression CBRACE REDUCE to direct_declarator" << endl;}
#line 3153 "parser.cpp"
    break;

  case 145: // direct_declarator: direct_declarator "[" "]"
#line 608 "parser.y"
                                                            { yylhs.value.as< DirectDeclarator > () = DirectDeclarator(); cout << "direct_declarator OBRACE CBRACE REDUCE to direct_declarator" << endl;}
#line 3159 "parser.cpp"
    break;

  case 146: // direct_declarator: direct_declarator "(" parameter_type_list ")"
#line 609 "parser.y"
                                                            { yylhs.value.as< DirectDeclarator > () = DirectDeclarator(); cout << "direct_declarator OPAREN parameter_type_list CPAREN to direct_declarator" << endl;}
#line 3165 "parser.cpp"
    break;

  case 147: // direct_declarator: direct_declarator "(" identifier_list ")"
#line 610 "parser.y"
                                                            { yylhs.value.as< DirectDeclarator > () = DirectDeclarator(); cout << "direct_declarator OPAREN identifier_list CPAREN REDUCE to direct_declarator" << endl;}
#line 3171 "parser.cpp"
    break;

  case 148: // direct_declarator: direct_declarator "(" ")"
#line 611 "parser.y"
                                                            { yylhs.value.as< DirectDeclarator > () = DirectDeclarator(); cout << "direct_declarator OPAREN CPAREN REDUCE to direct_declarator" << endl;}
#line 3177 "parser.cpp"
    break;

  case 149: // pointer: "*"
#line 615 "parser.y"
                                            {yylhs.value.as< Pointer > () = Pointer(yystack_[0].value.as < std::string > ()); cout << "TIMES_OP REDUCE to POINTER" << endl;}
#line 3183 "parser.cpp"
    break;

  case 150: // pointer: "*" type_qualifier_list
#line 616 "parser.y"
                                            {yylhs.value.as< Pointer > () = Pointer(yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::vector<TypeQualifier> > ()); cout << "TIMES_OP type_qualifier_list REDUCE to POINTER" << endl;}
#line 3189 "parser.cpp"
    break;

  case 151: // pointer: "*" pointer
#line 617 "parser.y"
                                            {yylhs.value.as< Pointer > () = Pointer(yystack_[1].value.as < std::string > (),yystack_[0].value.as < Pointer > ()); yylhs.value.as< Pointer > ().inc(); cout << "TIMES_OP pointer REDUCE to POINTER" << endl;}
#line 3195 "parser.cpp"
    break;

  case 152: // pointer: "*" type_qualifier_list pointer
#line 618 "parser.y"
                                            {yylhs.value.as< Pointer > () = Pointer(yystack_[2].value.as < std::string > (),yystack_[1].value.as < std::vector<TypeQualifier> > (),yystack_[0].value.as < Pointer > ()); yylhs.value.as< Pointer > ().inc(); cout << "TIMES_OP type_qualifier_list pointer REDUCE to POINTER" << endl;}
#line 3201 "parser.cpp"
    break;

  case 153: // type_qualifier_list: type_qualifier
#line 622 "parser.y"
                            {
                             TypeQualifier exp = yystack_[0].value.as < TypeQualifier > ();
                             yylhs.value.as < std::vector<TypeQualifier> > () = std::vector<TypeQualifier>();
                             yylhs.value.as < std::vector<TypeQualifier> > ().push_back(exp);
                             cout << "type_qualifier REDUCE type_qualifier_list" << endl;
                            }
#line 3212 "parser.cpp"
    break;

  case 154: // type_qualifier_list: type_qualifier_list type_qualifier
#line 628 "parser.y"
                                         {
                                          TypeQualifier value1 = yystack_[0].value.as < TypeQualifier > ();
                                          std::vector<TypeQualifier> &value2 = yystack_[1].value.as < std::vector<TypeQualifier> > ();
                                          value2.push_back(value1);
                                          yylhs.value.as < std::vector<TypeQualifier> > () = value2;
                                          cout << "type_qualifier_list type_qualifier REDUCE type_qualifier_list" << endl;
                                        }
#line 3224 "parser.cpp"
    break;

  case 155: // parameter_type_list: parameter_list
#line 639 "parser.y"
                                      { yylhs.value.as< ParameterTypeList > () = ParameterTypeList(yystack_[0].value.as < std::vector<ParameterDeclaration> > (),""); cout << "parameter_list REDUCE to parameter_type_list" << endl; }
#line 3230 "parser.cpp"
    break;

  case 156: // parameter_type_list: parameter_list "," "ellipsis"
#line 640 "parser.y"
                                      { yylhs.value.as< ParameterTypeList > () = ParameterTypeList(yystack_[2].value.as < std::vector<ParameterDeclaration> > (),yystack_[1].value.as < std::string > ()); cout << "parameter_list COMMA ELLIPSIS REDUCE to parameter_type_list" << endl; }
#line 3236 "parser.cpp"
    break;

  case 157: // parameter_list: parameter_declaration
#line 644 "parser.y"
                                                  {
                                                    ParameterDeclaration exp = yystack_[0].value.as < ParameterDeclaration > ();
                                                    yylhs.value.as < std::vector<ParameterDeclaration> > () = std::vector<ParameterDeclaration>();
                                                    yylhs.value.as < std::vector<ParameterDeclaration> > ().push_back(exp);
                                                    cout << "parameter_declaration REDUCE to parameter_list" << endl;
                                                  }
#line 3247 "parser.cpp"
    break;

  case 158: // parameter_list: parameter_list "," parameter_declaration
#line 650 "parser.y"
                                                  {
                                                    ParameterDeclaration value1 = yystack_[0].value.as < ParameterDeclaration > ();
                                                    std::vector<ParameterDeclaration> &value2 = yystack_[2].value.as < std::vector<ParameterDeclaration> > ();
                                                    value2.push_back(value1);
                                                    yylhs.value.as < std::vector<ParameterDeclaration> > () = value2;
                                                    cout << "parameter_list COMMA parameter_declaration REDUCE to parameter_list" << endl;
                                                  }
#line 3259 "parser.cpp"
    break;

  case 159: // parameter_declaration: declaration_specifiers declarator
#line 660 "parser.y"
                                                  { yylhs.value.as< ParameterDeclaration > () = ParameterDeclaration(yystack_[1].value.as < DeclarationSpecifiers > (),yystack_[0].value.as < Declarator > ()); cout << "declaration_specifiers declarator REDUCE to parameter_declaration" << endl; }
#line 3265 "parser.cpp"
    break;

  case 160: // parameter_declaration: declaration_specifiers abstract_declarator
#line 661 "parser.y"
                                                  { yylhs.value.as< ParameterDeclaration > () = ParameterDeclaration(yystack_[1].value.as < DeclarationSpecifiers > (),yystack_[0].value.as < AbstractDeclarator > ()); cout << "declaration_specifiers abstract_declarator REDUCE to parameter_declaration" << endl; }
#line 3271 "parser.cpp"
    break;

  case 161: // parameter_declaration: declaration_specifiers
#line 662 "parser.y"
                                                  { yylhs.value.as< ParameterDeclaration > () = ParameterDeclaration(yystack_[0].value.as < DeclarationSpecifiers > ()); cout << "declaration_specifiers REDUCE to parameter_declaration" << endl; }
#line 3277 "parser.cpp"
    break;

  case 162: // identifier_list: "identifier"
#line 666 "parser.y"
                                       {
                                          std::string exp = yystack_[0].value.as < std::string > ();
                                          yylhs.value.as < std::vector<std::string> > () = std::vector<std::string>();
                                          yylhs.value.as < std::vector<std::string> > ().push_back(exp);
                                          cout << "IDENTIFIER REDUCE to identifier_list" << endl;
                                       }
#line 3288 "parser.cpp"
    break;

  case 163: // identifier_list: identifier_list "," "identifier"
#line 672 "parser.y"
                                       {
                                          std::string value1 = yystack_[0].value.as < std::string > ();
                                          std::vector<std::string> &value2 = yystack_[2].value.as < std::vector<std::string> > ();
                                          value2.push_back(value1);
                                          yylhs.value.as < std::vector<std::string> > () = value2;
                                          cout << "identifier_list COMMA IDENTIFIER REDUCE to identifier_list" << endl; 
                                        }
#line 3300 "parser.cpp"
    break;

  case 164: // type_name: specifier_qualifier_list
#line 682 "parser.y"
                                                   { yylhs.value.as< TypeName > () = TypeName(yystack_[0].value.as < SpecifierQualifierList > ()); cout << "specifier_qualifier_list REDUCE to type_name" << endl; }
#line 3306 "parser.cpp"
    break;

  case 165: // type_name: specifier_qualifier_list abstract_declarator
#line 683 "parser.y"
                                                   { yylhs.value.as< TypeName > () = TypeName(yystack_[1].value.as < SpecifierQualifierList > (),yystack_[0].value.as < AbstractDeclarator > ()); cout << "specifier_qualifier_list abstract_declarator REDUCE to type_name" << endl; }
#line 3312 "parser.cpp"
    break;

  case 166: // abstract_declarator: pointer
#line 687 "parser.y"
                                          { yylhs.value.as< AbstractDeclarator > () = AbstractDeclarator(yystack_[0].value.as < Pointer > ()); cout << "pointer REDUCE to abstract_declarator" << endl; }
#line 3318 "parser.cpp"
    break;

  case 167: // abstract_declarator: direct_abstract_declarator
#line 688 "parser.y"
                                          { yylhs.value.as< AbstractDeclarator > () = AbstractDeclarator(yystack_[0].value.as < DirectAbstractDeclarator > ()); cout << "direct_abstract_declarator REDUCE to abstract_declarator" << endl; }
#line 3324 "parser.cpp"
    break;

  case 168: // abstract_declarator: pointer direct_abstract_declarator
#line 689 "parser.y"
                                          { yylhs.value.as< AbstractDeclarator > () = AbstractDeclarator(yystack_[1].value.as < Pointer > (),yystack_[0].value.as < DirectAbstractDeclarator > ()); cout << "pointer direct_abstract_declarator REDUCE to abstract_declarator" << endl; }
#line 3330 "parser.cpp"
    break;

  case 169: // direct_abstract_declarator: "(" abstract_declarator ")"
#line 693 "parser.y"
                                                                   { yylhs.value.as< DirectAbstractDeclarator > () = DirectAbstractDeclarator(yystack_[1].value.as < AbstractDeclarator > ()); cout << "OPAREN abstract_declarator CPAREN REDUCE to direct_abstract_declarator" << endl; }
#line 3336 "parser.cpp"
    break;

  case 170: // direct_abstract_declarator: "[" "]"
#line 694 "parser.y"
                                                                   { yylhs.value.as< DirectAbstractDeclarator > () = DirectAbstractDeclarator(); cout << "OBRACE CBRACE REDUCE to direct_abstract_declarator" << endl; }
#line 3342 "parser.cpp"
    break;

  case 171: // direct_abstract_declarator: "[" constant_expression "]"
#line 695 "parser.y"
                                                                   { yylhs.value.as< DirectAbstractDeclarator > () = DirectAbstractDeclarator(); cout << "OBRACE constant_expression CBRACE REDUCE to direct_abstract_declarator" << endl; }
#line 3348 "parser.cpp"
    break;

  case 172: // direct_abstract_declarator: direct_abstract_declarator "[" "]"
#line 696 "parser.y"
                                                                   { yylhs.value.as< DirectAbstractDeclarator > () = DirectAbstractDeclarator(); cout << "direct_abstract_declarator OBRACE CBRACE REDUCE to direct_abstract_declarator" << endl; }
#line 3354 "parser.cpp"
    break;

  case 173: // direct_abstract_declarator: direct_abstract_declarator "[" constant_expression "]"
#line 697 "parser.y"
                                                                   { yylhs.value.as< DirectAbstractDeclarator > () = DirectAbstractDeclarator(); cout << "direct_abstract_declarator OBRACE constant_expression CBRACE REDUCE to direct_abstract_declarator" << endl; }
#line 3360 "parser.cpp"
    break;

  case 174: // direct_abstract_declarator: "(" ")"
#line 698 "parser.y"
                                                                   { yylhs.value.as< DirectAbstractDeclarator > () = DirectAbstractDeclarator(); cout << "OPAREN CPAREN REDUCE to direct_abstract_declarator" << endl; }
#line 3366 "parser.cpp"
    break;

  case 175: // direct_abstract_declarator: "(" parameter_type_list ")"
#line 699 "parser.y"
                                                                   { yylhs.value.as< DirectAbstractDeclarator > () = DirectAbstractDeclarator(); cout << "OPAREN parameter_type_list CPAREN REDUCE to direct_abstract_declarator" << endl; }
#line 3372 "parser.cpp"
    break;

  case 176: // direct_abstract_declarator: direct_abstract_declarator "(" ")"
#line 700 "parser.y"
                                                                   { yylhs.value.as< DirectAbstractDeclarator > () = DirectAbstractDeclarator(); cout << "direct_abstract_declarator OPAREN CPAREN REDUCE to direct_abstract_declarator" << endl; }
#line 3378 "parser.cpp"
    break;

  case 177: // direct_abstract_declarator: direct_abstract_declarator "(" parameter_type_list ")"
#line 701 "parser.y"
                                                                   { yylhs.value.as< DirectAbstractDeclarator > () = DirectAbstractDeclarator(); cout << "direct_abstract_declarator OPAREN parameter_type_list CPAREN REDUCE to direct_abstract_declarator" << endl; }
#line 3384 "parser.cpp"
    break;

  case 178: // initializer: assignment_expression
#line 705 "parser.y"
                                           { yylhs.value.as< Initializer > () = Initializer(yystack_[0].value.as < AssignmentExpression > ()); cout << "assignment_expression REDUCE to initializer" << endl; }
#line 3390 "parser.cpp"
    break;

  case 179: // initializer: "{" initializer_list "}"
#line 706 "parser.y"
                                           { yylhs.value.as< Initializer > () = Initializer(yystack_[1].value.as < std::vector<Initializer> > ()); cout << "OCURLY initializer_list CCURLY REDUCE to initializer" << endl; }
#line 3396 "parser.cpp"
    break;

  case 180: // initializer: "{" initializer_list "," "}"
#line 707 "parser.y"
                                           { yylhs.value.as< Initializer > () = Initializer(yystack_[2].value.as < std::vector<Initializer> > ()); cout << "OCURLY initializer_list COMMA CCURLY REDUCE to initializer" << endl; }
#line 3402 "parser.cpp"
    break;

  case 181: // initializer_list: initializer
#line 711 "parser.y"
                                          {
                                           Initializer exp = yystack_[0].value.as < Initializer > ();
                                           yylhs.value.as < std::vector<Initializer> > () = std::vector<Initializer>();
                                           yylhs.value.as < std::vector<Initializer> > ().push_back(exp);
                                           cout << "initializer REDUCE to initializer_list" << endl;
                                          }
#line 3413 "parser.cpp"
    break;

  case 182: // initializer_list: initializer_list "," initializer
#line 717 "parser.y"
                                          {
                                           Initializer value1 = yystack_[0].value.as < Initializer > ();
                                           std::vector<Initializer> &value2 = yystack_[2].value.as < std::vector<Initializer> > ();
                                           value2.push_back(value1);
                                           yylhs.value.as < std::vector<Initializer> > () = value2;
                                           cout << "initializer_list COMMA initializer REDUCE to initializer_list" << endl;
                                          }
#line 3425 "parser.cpp"
    break;

  case 183: // statement: labeled_statement
#line 727 "parser.y"
                           { yylhs.value.as< BaseStatement > () = Statement(NONE,yystack_[0].value.as < LabeledStatement > ()); cout << "labeled_statement REDUCE to statement" << endl; }
#line 3431 "parser.cpp"
    break;

  case 184: // statement: compound_statement
#line 728 "parser.y"
                           { yylhs.value.as< BaseStatement > () = Statement(NONE,yystack_[0].value.as < CompoundStatement > ()); cout << "compound_statement REDUCE to statement" << endl; }
#line 3437 "parser.cpp"
    break;

  case 185: // statement: expression_statement
#line 729 "parser.y"
                           { yylhs.value.as< BaseStatement > () = Statement(NONE,yystack_[0].value.as < BaseStatement > ()); cout << "expression_statement REDUCE to statement" << endl; }
#line 3443 "parser.cpp"
    break;

  case 186: // statement: selection_statement
#line 730 "parser.y"
                           { yylhs.value.as< BaseStatement > () = Statement(NONE,yystack_[0].value.as < BaseStatement > ()); cout << "selection_statement REDUCE to statement" << endl; }
#line 3449 "parser.cpp"
    break;

  case 187: // statement: iteration_statement
#line 731 "parser.y"
                           { yylhs.value.as< BaseStatement > () = Statement(NONE,yystack_[0].value.as < BaseStatement > ()); cout << "iteration_statement REDUCE to statement" << endl; }
#line 3455 "parser.cpp"
    break;

  case 188: // statement: jump_statement
#line 732 "parser.y"
                           { yylhs.value.as< BaseStatement > () = Statement(NONE,yystack_[0].value.as < BaseStatement > ()); cout << "jump_statement REDUCE to statement" << endl; }
#line 3461 "parser.cpp"
    break;

  case 189: // labeled_statement: "identifier" ":" statement
#line 736 "parser.y"
                                               { yylhs.value.as< BaseStatement > () = LabeledStatement(yystack_[2].value.as < std::string > (),yystack_[0].value.as < BaseStatement > ()); cout << "IDENTIFIER COLON statement REDUCE to label_statement" << endl; }
#line 3467 "parser.cpp"
    break;

  case 190: // labeled_statement: "case" constant_expression ":" statement
#line 737 "parser.y"
                                               { yylhs.value.as< BaseStatement > () = LabeledStatement(CASE,yystack_[2].value.as < ConstantExpression > (),yystack_[0].value.as < BaseStatement > ()); cout << "CASE constant_expression COLON statement REDUCE to label_statement" << endl; }
#line 3473 "parser.cpp"
    break;

  case 191: // labeled_statement: "default" ":" statement
#line 738 "parser.y"
                                               { yylhs.value.as< BaseStatement > () = LabeledStatement(DEFAULT,yystack_[0].value.as < BaseStatement > ()); cout << "DEFAULT COLON statement REDUCE to label_statement" << endl; }
#line 3479 "parser.cpp"
    break;

  case 192: // compound_statement: "{" "}"
#line 742 "parser.y"
                                                    { yylhs.value.as< BaseStatement > () = CompoundStatement(); cout << "OCURLY CCURLY REDUCE to compound_statement" << endl; }
#line 3485 "parser.cpp"
    break;

  case 193: // compound_statement: "{" statement_list "}"
#line 743 "parser.y"
                                                    { yylhs.value.as< BaseStatement > () = CompoundStatement(yystack_[1].value.as < std::vector<BaseStatement> > ()); cout << "OCURLY statement_list CCURLY REDUCE to compound_statement" << endl; }
#line 3491 "parser.cpp"
    break;

  case 194: // compound_statement: "{" declaration_list "}"
#line 744 "parser.y"
                                                    { yylhs.value.as< BaseStatement > () = CompoundStatement(yystack_[1].value.as < std::vector<Declaration> > ()); cout << "OCURLY declaration_list CCURLY REDUCE to compound_statement" << endl; }
#line 3497 "parser.cpp"
    break;

  case 195: // compound_statement: "{" declaration_list statement_list "}"
#line 745 "parser.y"
                                                    { yylhs.value.as< BaseStatement > () = CompoundStatement(yystack_[1].value.as < std::vector<BaseStatement> > (),yystack_[2].value.as < std::vector<Declaration> > ()); cout << "OCURLY declaration_list statement_list CCURLY REDUCE to compound_statement" << endl; }
#line 3503 "parser.cpp"
    break;

  case 196: // declaration_list: declaration
#line 749 "parser.y"
                                    {
                                     Declaration exp = yystack_[0].value.as < Declaration > ();
                                     yylhs.value.as < std::vector<Declaration> > () = std::vector<Declaration>();
                                     yylhs.value.as < std::vector<Declaration> > ().push_back(exp);
                                     cout << "declaration REDUCE to declaration_list" << endl;
                                    }
#line 3514 "parser.cpp"
    break;

  case 197: // declaration_list: declaration_list declaration
#line 755 "parser.y"
                                    {
                                     Declaration value1 = yystack_[0].value.as < Declaration > ();
                                     std::vector<Declaration> &value2 = yystack_[1].value.as < std::vector<Declaration> > ();
                                     value2.push_back(value1);
                                     yylhs.value.as < std::vector<Declaration> > () = value2;
                                     cout << "declaration_list declaration REDUCE to declaration_list" << endl;
                                    }
#line 3526 "parser.cpp"
    break;

  case 198: // statement_list: statement
#line 765 "parser.y"
                                  {
                                    BaseStatement exp = yystack_[0].value.as < BaseStatement > ();
                                    yylhs.value.as < std::vector<BaseStatement> > () = std::vector<BaseStatement>();
                                    yylhs.value.as < std::vector<BaseStatement> > ().push_back(exp);
                                    cout << "statement REDUCE to statement_list" << endl;
                                  }
#line 3537 "parser.cpp"
    break;

  case 199: // statement_list: statement_list statement
#line 771 "parser.y"
                                  {
                                    BaseStatement value1 = yystack_[0].value.as < BaseStatement > ();
                                    std::vector<BaseStatement> &value2 = yystack_[1].value.as < std::vector<BaseStatement> > ();
                                    value2.push_back(value1);
                                    yylhs.value.as < std::vector<BaseStatement> > () = value2;
                                    cout << "statement_list statement REDUCE to statement_list" << endl;
                                  }
#line 3549 "parser.cpp"
    break;

  case 200: // expression_statement: ";"
#line 781 "parser.y"
                            { yylhs.value.as< BaseStatement > () = ExpressionStatement(); cout << "SEMICOLON REDUCE to expression_statement" << endl; }
#line 3555 "parser.cpp"
    break;

  case 201: // expression_statement: expression ";"
#line 782 "parser.y"
                            { yylhs.value.as< BaseStatement > () = ExpressionStatement(yystack_[1].value.as < Expression > ()); cout << "expression SEMICOLON REDUCE to expression_statement" << endl; }
#line 3561 "parser.cpp"
    break;

  case 202: // selection_statement: "if" "(" expression ")" statement
#line 786 "parser.y"
                                                           { yylhs.value.as< BaseStatement > () = SelectionStatement(IF,yystack_[2].value.as < Expression > (),yystack_[0].value.as < BaseStatement > ()); cout << "IF OPAREN expression CPAREN statement REDUCE to selection_statement" << endl; }
#line 3567 "parser.cpp"
    break;

  case 203: // selection_statement: "if" "(" expression ")" statement "else" statement
#line 787 "parser.y"
                                                           { yylhs.value.as< BaseStatement > () = SelectionStatement(IF,yystack_[4].value.as < Expression > (),yystack_[2].value.as < BaseStatement > (),yystack_[0].value.as < BaseStatement > ()); cout << "IF OPAREN expression CPAREN statement ELSE statement REDUCE to selection_statement" << endl; }
#line 3573 "parser.cpp"
    break;

  case 204: // selection_statement: "switch" "(" expression ")" statement
#line 788 "parser.y"
                                                           { yylhs.value.as< BaseStatement > () = SelectionStatement(SWITCH,yystack_[2].value.as < Expression > (),yystack_[0].value.as < BaseStatement > ()); cout << "SWITCH OPAREN expression CPAREN statement REDUCE to selection_statement" << endl; }
#line 3579 "parser.cpp"
    break;

  case 205: // iteration_statement: "while" "(" expression ")" statement
#line 792 "parser.y"
                                                                                       { yylhs.value.as< BaseStatement > () = IterationStatement(WHILE,yystack_[2].value.as < Expression > (),yystack_[0].value.as < BaseStatement > ()); cout << "WHILE OPAREN expression CPAREN statement REDUCE to iteration_statement" << endl; }
#line 3585 "parser.cpp"
    break;

  case 206: // iteration_statement: "do" statement "while" "(" expression ")" ";"
#line 793 "parser.y"
                                                                                       { yylhs.value.as< BaseStatement > () = IterationStatement(DO,yystack_[2].value.as < Expression > (),yystack_[5].value.as < BaseStatement > ()); cout << "DO statement WHILE OPAREN expression CPAREN SEMICOLON REDUCE to iteration_statement" << endl; }
#line 3591 "parser.cpp"
    break;

  case 207: // iteration_statement: "for" "(" expression_statement expression_statement ")" statement
#line 794 "parser.y"
                                                                                       { yylhs.value.as< BaseStatement > () = IterationStatement(FOR,yystack_[3].value.as < BaseStatement > (),yystack_[2].value.as < BaseStatement > (),yystack_[0].value.as < BaseStatement > ()); cout << "FOR OPAREN expression_statement expression_statement CPAREN statement REDUCE to iteration_statement" << endl; }
#line 3597 "parser.cpp"
    break;

  case 208: // iteration_statement: "for" "(" expression_statement expression_statement expression ")" statement
#line 795 "parser.y"
                                                                                       { yylhs.value.as< BaseStatement > () = IterationStatement(FOR,yystack_[4].value.as < BaseStatement > (),yystack_[3].value.as < BaseStatement > (),yystack_[2].value.as < Expression > (),yystack_[0].value.as < BaseStatement > ()); cout << "FOR OPAREN expression_statement expression_statement expression CPAREN statement REDUCE to iteration_statement" << endl; }
#line 3603 "parser.cpp"
    break;

  case 209: // jump_statement: "goto" "identifier" ";"
#line 799 "parser.y"
                                  { yylhs.value.as< BaseStatement > () = JumpStatement(GOTO,yystack_[1].value.as < std::string > ()); cout << "GOTO IDENTIFIER SEMICOLON REDUCE to jump_statement" << endl; }
#line 3609 "parser.cpp"
    break;

  case 210: // jump_statement: "continue" ";"
#line 800 "parser.y"
                                  { yylhs.value.as< BaseStatement > () = JumpStatement(CONTINUE); cout << "CONTINUE SEMICOLON REDUCE to jump_statement" << endl; }
#line 3615 "parser.cpp"
    break;

  case 211: // jump_statement: "break" ";"
#line 801 "parser.y"
                                  { yylhs.value.as< BaseStatement > () = JumpStatement(BREAK); cout << "BREAK SEMICOLON REDUCE to jump_statement" << endl; }
#line 3621 "parser.cpp"
    break;

  case 212: // jump_statement: "return" ";"
#line 802 "parser.y"
                                  { yylhs.value.as< BaseStatement > () = JumpStatement(RETURN); cout << "RETURN SEMICOLON REDUCE to jump_statement" << endl; }
#line 3627 "parser.cpp"
    break;

  case 213: // jump_statement: "return" expression ";"
#line 803 "parser.y"
                                  { yylhs.value.as< BaseStatement > () = JumpStatement(RETURN,yystack_[1].value.as < Expression > ()); cout << "RETURN expression SEMICOLON REDUCE to jump_statement" << endl; }
#line 3633 "parser.cpp"
    break;

  case 214: // translation_unit: external_declaration
#line 807 "parser.y"
                                            { globalVars = std::vector<ExternalDeclaration>(); globalVars.push_back(yystack_[0].value.as < ExternalDeclaration > ()); cout << "external_declaration REDUCE to translation_unit" << endl; }
#line 3639 "parser.cpp"
    break;

  case 215: // translation_unit: translation_unit external_declaration
#line 808 "parser.y"
                                            { globalVars.push_back(yystack_[0].value.as < ExternalDeclaration > ()); cout << "translation_unit external_declaration REDUCE to translation_unit" << endl; }
#line 3645 "parser.cpp"
    break;

  case 216: // external_declaration: function_definition
#line 812 "parser.y"
                           { yylhs.value.as< ExternalDeclaration > () = ExternalDeclaration(yystack_[0].value.as < FunctionDefinition > ()); cout << "function_definition REDUCE to external_declaration" << endl; }
#line 3651 "parser.cpp"
    break;

  case 217: // external_declaration: declaration
#line 813 "parser.y"
                           { yylhs.value.as< ExternalDeclaration > () = ExternalDeclaration(yystack_[0].value.as < Declaration > ()); cout << "declaration REDUCE to external_declaration" << endl; }
#line 3657 "parser.cpp"
    break;

  case 218: // function_definition: declaration_specifiers declarator declaration_list compound_statement
#line 817 "parser.y"
                                                                            { yylhs.value.as< FunctionDefinition > () = FunctionDefinition(yystack_[3].value.as < DeclarationSpecifiers > (),yystack_[2].value.as < Declarator > (),yystack_[1].value.as < std::vector<Declaration> > (),yystack_[0].value.as < CompoundStatement > ()); cout << "declaration_specifiers declarator declaration_list compound_statement REDUCE to function_definition" << endl; }
#line 3663 "parser.cpp"
    break;

  case 219: // function_definition: declaration_specifiers declarator compound_statement
#line 818 "parser.y"
                                                                            { yylhs.value.as< FunctionDefinition > () = FunctionDefinition(yystack_[2].value.as < DeclarationSpecifiers > (),yystack_[1].value.as < Declarator > (),yystack_[0].value.as < CompoundStatement > ()); cout << "declaration_specifiers declarator compound_statement REDUCE to function_definition" << endl; }
#line 3669 "parser.cpp"
    break;

  case 220: // function_definition: declarator declaration_list compound_statement
#line 819 "parser.y"
                                                                            { yylhs.value.as< FunctionDefinition > () = FunctionDefinition(yystack_[2].value.as < Declarator > (),yystack_[1].value.as < std::vector<Declaration> > (),yystack_[0].value.as < CompoundStatement > ()); cout << "declarator declaration_list compound_statement REDUCE to function_definition" << endl; }
#line 3675 "parser.cpp"
    break;

  case 221: // function_definition: declarator compound_statement
#line 820 "parser.y"
                                                                            { yylhs.value.as< FunctionDefinition > () = FunctionDefinition(yystack_[1].value.as < Declarator > (),yystack_[0].value.as < CompoundStatement > ()); cout << "declarator compound_statement REDUCE to function_definition" << endl; }
#line 3681 "parser.cpp"
    break;


#line 3685 "parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -230;

  const signed char  Parser ::yytable_ninf_ = -1;

  const short
   Parser ::yypact_[] =
  {
     682,  -230,  -230,  -230,  -230,  -230,  -230,  -230,    15,  -230,
    -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,
    -230,  -230,  -230,  -230,  -230,  -230,  -230,    24,    17,  -230,
      21,  1653,  1653,  -230,    30,  -230,  1653,  1572,     4,    13,
     306,  -230,  -230,   -41,    14,   -14,  -230,  -230,    17,  -230,
      71,  -230,  1370,  -230,  -230,     1,  1689,  -230,   366,  -230,
      21,  -230,  1572,  1415,  1004,     4,  -230,  -230,    14,    -5,
      31,  -230,  -230,  -230,  -230,  -230,    24,  1022,  -230,  1572,
    1689,  1689,  1495,  -230,     3,  1689,     9,  -230,  -230,  -230,
      27,  1155,    50,    20,   904,    54,   122,    76,   518,  1227,
     106,   126,  -230,  -230,   542,  -230,  1245,  1245,  -230,  -230,
    -230,  -230,  -230,  -230,  -230,   138,   233,  1155,  -230,   137,
     101,   176,    70,   167,   109,   114,   128,   161,    69,  -230,
    -230,    90,  -230,  -230,  -230,   454,   728,  -230,  -230,  -230,
    -230,   165,  -230,  -230,  -230,  -230,    23,   166,   188,  -230,
      66,  -230,  -230,  -230,  -230,   187,   205,  1155,  -230,    14,
    -230,  1022,  -230,  -230,  -230,  1531,  -230,  -230,  -230,  1155,
      91,  -230,   200,  -230,   904,  -230,   217,  -230,   904,   219,
    1064,   226,  1155,  -230,    95,   542,  -230,  1155,  1155,   130,
      34,   224,   542,  -230,  -230,   790,  1155,   282,  -230,  -230,
     283,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,
    -230,  -230,  1155,  -230,  1155,  1155,  1155,  1155,  1155,  1155,
    1155,  1155,  1155,  1155,  1155,  1155,  1155,  1155,  1155,  1155,
    1155,  1155,  1155,  -230,  1155,  -230,   816,  -230,  -230,   626,
    1111,  -230,    40,  -230,   179,  -230,  1612,   284,  -230,  -230,
    -230,  -230,  -230,  -230,   209,  -230,  -230,  -230,     3,  1155,
    -230,   904,  -230,   234,  1064,  -230,   145,  -230,   235,   149,
     155,  -230,  1329,   180,  -230,  1129,   236,  -230,   162,  -230,
     -32,  -230,  -230,  -230,  -230,  -230,  -230,   137,   137,   101,
     101,   176,   176,   176,   176,    70,    70,   167,   109,   114,
     128,   212,   161,  -230,  -230,  -230,   252,   253,  -230,   232,
     179,  1455,  1137,  -230,  -230,  -230,  -230,   945,  -230,  -230,
    -230,  1155,  1201,   904,   260,   904,   904,  1022,  -230,   260,
    1155,  -230,  -230,  1155,  -230,  -230,  -230,  -230,   257,  -230,
     258,  -230,  -230,   164,   904,   171,   298,  -230,  -230,   215,
    -230,  -230,  -230,  -230,   270,  -230,   904,   904,  -230,   963,
    -230,  -230,  -230,  -230
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
       0,   142,   113,    95,    98,   138,   104,   105,     0,    93,
     103,   100,   101,   102,    96,    99,   109,    94,   117,    92,
     118,   110,    97,   139,   106,   108,   107,     0,   149,   217,
       0,    82,    84,   111,     0,   112,    86,     0,   141,     0,
       0,   214,   216,   133,     0,     0,   153,   151,   150,    80,
       0,    88,    90,    83,    85,   116,     0,    87,     0,   196,
       0,   221,     0,     0,     0,   140,     1,   215,     0,   136,
       0,   134,   143,   154,   152,    81,     0,     0,   219,     0,
       0,   123,     0,   119,     0,   125,     2,     6,     5,     7,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   200,   192,     0,    30,     0,     0,    31,    26,
      29,    28,    27,     8,     3,    20,    32,     0,    34,    38,
      41,    44,    49,    52,    54,    56,    58,    60,    62,    64,
      77,     0,   198,   183,   184,     0,     0,   185,   186,   187,
     188,    90,   197,   220,   162,   148,   161,     0,   155,   157,
       0,     2,   145,    32,    79,     0,     0,     0,   131,     0,
      89,     0,   178,    91,   218,     0,   122,   115,   120,     0,
       0,   126,   128,   124,     0,   211,     0,   210,     0,     0,
       0,     0,     0,   212,     0,     0,    24,     0,     0,     0,
     164,     0,     0,    21,    22,     0,     0,     0,    14,    15,
       0,    66,    73,    72,    70,    71,    67,    68,    69,    74,
      75,    76,     0,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   201,     0,   194,     0,   193,   199,     0,
       0,   159,   166,   160,   167,   146,     0,     0,   147,   144,
     132,   137,   135,   181,     0,   114,   129,   121,     0,     0,
     189,     0,   191,     0,     0,   209,     0,   213,     0,     0,
       0,     4,     0,   166,   165,     0,     0,    10,     0,    18,
       0,    12,    13,    65,    35,    36,    37,    40,    39,    43,
      42,    48,    47,    46,    45,    50,    51,    53,    55,    57,
      59,     0,    61,    78,   195,   174,     0,     0,   170,     0,
     168,     0,     0,   156,   158,   163,   179,     0,   127,   130,
     190,     0,     0,     0,    25,     0,     0,     0,    33,     0,
       0,    11,     9,     0,   175,   169,   171,   176,     0,   172,
       0,   180,   182,     0,     0,     0,   202,   204,   205,     0,
      19,    63,   177,   173,     0,   207,     0,     0,    16,     0,
     206,   208,   203,    17
  };

  const short
   Parser ::yypgoto_[] =
  {
    -230,  -230,  -230,  -230,  -230,   -53,  -230,   -87,    51,    58,
     -68,    56,    93,    96,    92,    98,    97,  -230,   -57,   -76,
    -230,   -90,   -54,    10,     0,  -230,   254,  -230,   -33,  -230,
    -230,   251,   -79,     6,  -230,    78,  -230,   269,   181,    53,
     -15,   -34,    -9,  -230,   -59,  -230,   103,  -230,  -157,  -124,
    -229,   -75,    26,   -52,  -230,   141,    16,   208,  -159,  -230,
    -230,  -230,  -230,   314,  -230
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,   113,   114,   115,   278,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     212,   131,   155,    59,    60,    50,    51,    31,    32,    33,
      34,    82,    83,    84,   170,   171,    35,    70,    71,    36,
      37,    38,    39,    48,   306,   148,   149,   150,   191,   307,
     244,   253,   254,   132,   133,   134,    62,   136,   137,   138,
     139,   140,    40,    41,    42
  };

  const short
   Parser ::yytable_[] =
  {
      30,   162,   163,   168,   147,    65,     1,   154,   184,    68,
      29,   153,    45,   310,   189,    52,     1,    69,    43,    47,
     234,   264,   243,    81,     1,   332,     1,     1,   268,     5,
     213,    53,    54,    55,   154,   276,    57,   176,   153,    74,
      30,    72,   179,     1,   310,   141,   186,    81,    81,    81,
      29,    80,    81,   193,   194,   157,   169,    27,    63,    23,
      64,   141,   174,   146,   153,    44,   274,    27,    79,   172,
      49,    81,   142,   178,   135,    27,   175,   239,    27,   240,
      56,    46,   158,   159,   238,   162,   168,   166,   272,   142,
     240,   173,   266,    28,   239,   189,   240,   269,   270,   177,
     154,    73,   189,   251,   153,   322,   280,    28,   180,    85,
     190,    28,   154,    28,    28,   256,   153,   231,   247,   279,
      75,   248,   260,    76,    28,   181,   262,   284,   285,   286,
     182,   241,    81,    85,    85,    85,   283,   242,    85,   233,
     257,   301,   234,   258,   267,   142,   232,   234,   221,   222,
     223,   224,    81,   291,   292,   293,   294,    85,   303,    81,
     187,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,    61,   153,
     188,   273,   234,   154,   238,   271,   309,   153,   328,   217,
     218,   190,   195,    78,   196,   227,   197,   234,   190,   228,
     323,   234,   154,   143,   325,   319,   153,   234,    65,   320,
     326,   198,   199,   200,   330,   229,   234,   331,    85,   354,
     164,   245,   153,   234,    45,    77,   356,   214,   215,   216,
     242,   343,   345,   311,   272,   312,   240,   230,    85,   146,
     246,   162,   342,   172,   249,    85,   146,   219,   220,   225,
     226,   162,   338,   259,   350,   154,   250,   159,   340,   153,
     316,   317,   263,   273,   234,   333,   358,   359,   287,   288,
     261,   346,   146,   347,   348,   265,   351,   289,   290,   275,
     153,   295,   296,   162,   342,   281,   282,   315,   321,   336,
     324,   329,   355,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   361,   362,    66,   334,   335,     1,
     327,   146,   352,     2,     3,   353,   357,     4,     5,   360,
     297,   299,     6,     7,   298,     8,     9,    10,   300,   302,
     160,   165,    11,    12,    13,    14,   318,   156,    15,    16,
     252,    17,    18,   236,    19,    20,    21,    22,    23,   314,
      24,    25,    26,   349,    67,     0,     0,     0,     0,     0,
      27,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,     2,     3,    90,    91,     4,     5,    92,
      93,    94,     6,     7,     0,     8,     9,    10,    95,    96,
      97,     0,    11,    12,    13,    14,    28,    98,    15,    16,
      99,    17,    18,   100,    19,    20,    21,    22,    23,   101,
      24,    25,    26,     0,     0,   102,    58,   103,     0,     0,
     104,     0,     0,     0,     0,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,     0,   109,     0,   110,   111,   112,    86,    87,    88,
      89,     2,     3,    90,    91,     4,     5,    92,    93,    94,
       6,     7,     0,     8,     9,    10,    95,    96,    97,     0,
      11,    12,    13,    14,     0,    98,    15,    16,    99,    17,
      18,   100,    19,    20,    21,    22,    23,   101,    24,    25,
      26,     0,     0,   102,    58,   235,     0,     0,   104,     0,
       0,     0,     0,   105,     0,     0,     0,     0,     0,     0,
       0,   151,    87,    88,    89,     0,     0,   106,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   108,     0,
     109,     0,   110,   111,   112,   151,    87,    88,    89,     2,
       0,     0,    99,     4,     5,     0,     0,     0,     6,     7,
       0,     8,     0,    10,     0,     0,     0,   183,    11,    12,
      13,     0,   104,     0,    15,    16,    99,   105,    18,     0,
       0,    20,    21,    22,    23,     0,    24,    25,    26,     0,
       0,   106,   107,     0,     0,     0,   104,     0,     0,     0,
       0,   105,   108,     0,   109,     0,   110,   111,   112,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,     0,   109,     1,
     110,   111,   112,     2,     3,     0,     0,     4,     5,     0,
       0,     0,     6,     7,     0,     8,     9,    10,     0,     0,
       0,     0,    11,    12,    13,    14,     0,     0,    15,    16,
       0,    17,    18,     0,    19,    20,    21,    22,    23,     0,
      24,    25,    26,     0,     0,     0,     0,     0,     0,     0,
     239,   305,   240,     0,     0,     1,     0,     0,     0,     2,
       3,     0,     0,     4,     5,     0,     0,     0,     6,     7,
       0,     8,     9,    10,     0,     0,     0,     0,    11,    12,
      13,    14,     0,     0,    15,    16,    28,    17,    18,     0,
      19,    20,    21,    22,    23,     0,    24,    25,    26,     0,
       0,    86,    87,    88,    89,     0,    27,    90,    91,     0,
       0,    92,    93,    94,     0,     0,     0,     0,     0,     0,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
       0,     0,    99,     0,     0,   100,     0,     0,     0,     0,
       0,   101,    28,     0,     0,     0,     0,   102,    58,   237,
       0,     0,   104,     0,     0,     0,     0,   105,     0,     0,
       0,     0,     0,   151,    87,    88,    89,     0,     0,     0,
       0,   106,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   108,     0,   109,     0,   110,   111,   112,    86,
      87,    88,    89,     0,    99,    90,    91,     0,     0,    92,
      93,    94,     0,     0,     0,     0,     0,     0,    95,    96,
      97,     0,     0,     0,   104,   277,     0,    98,     0,   105,
      99,     0,     0,   100,     0,     0,     0,     0,     0,   101,
       0,     0,     0,   106,   107,   102,    58,   304,     0,     0,
     104,     0,     0,     0,   108,   105,   109,     0,   110,   111,
     112,     0,     0,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,     0,   109,     0,   110,   111,   112,    86,    87,    88,
      89,     0,     0,    90,    91,     0,     0,    92,    93,    94,
       0,     0,     0,     0,     0,     0,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,     0,     0,    99,     0,
       0,   100,     0,     0,     0,     0,     0,   101,   151,    87,
      88,    89,     0,   102,    58,     0,     0,     0,   104,     0,
       0,     0,     0,   105,     0,     0,   151,    87,    88,    89,
       0,     0,     0,     0,     0,     0,     0,   106,   107,    99,
       0,     0,     0,     0,     0,     0,     0,     0,   108,     0,
     109,     0,   110,   111,   112,   161,   341,    99,     0,   104,
       0,     0,     0,     0,   105,     0,     0,   151,    87,    88,
      89,     0,     0,   161,   363,     0,     0,   104,   106,   107,
       0,     0,   105,     0,     0,   151,    87,    88,    89,   108,
       0,   109,     0,   110,   111,   112,   106,   107,    99,     0,
       0,     0,     0,     0,     0,     0,     0,   108,     0,   109,
       0,   110,   111,   112,     0,     0,    99,     0,   104,     0,
       0,   152,     0,   105,     0,     0,     0,   151,    87,    88,
      89,     0,   161,     0,     0,     0,   104,   106,   107,     0,
       0,   105,     0,     0,     0,     0,     0,     0,   108,     0,
     109,     0,   110,   111,   112,   106,   107,     0,    99,     0,
       0,     0,     0,     0,     0,     0,   108,     0,   109,     0,
     110,   111,   112,   102,   151,    87,    88,    89,   104,     0,
       0,     0,     0,   105,     0,     0,     0,     0,     0,     0,
       0,     0,   151,    87,    88,    89,     0,   106,   107,     0,
     151,    87,    88,    89,     0,    99,     0,     0,   108,     0,
     109,     0,   110,   111,   112,     0,     0,     0,   151,    87,
      88,    89,     0,    99,     0,   104,     0,     0,   308,     0,
     105,    99,     0,     0,     0,     0,     0,     0,     0,   327,
       0,     0,     0,   104,   106,   107,     0,     0,   105,    99,
       0,   104,     0,     0,   339,   108,   105,   109,     0,   110,
     111,   112,   106,   107,   151,    87,    88,    89,     0,   104,
     106,   107,     0,   108,   105,   109,     0,   110,   111,   112,
       0,   108,     0,   109,     0,   110,   111,   112,   106,   107,
     151,    87,    88,    89,     0,    99,     0,     0,     0,   108,
       0,   109,     0,   110,   111,   112,     0,     0,   151,    87,
      88,    89,     0,     0,     0,   104,   344,     0,     0,     0,
     105,    99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,    99,
       0,   185,     0,     0,     0,   108,   105,   109,     0,   110,
     111,   112,     0,     0,     0,     0,     0,     0,     0,   192,
     106,   107,     0,     0,   105,     0,     0,     0,     0,     0,
       0,   108,     0,   109,     0,   110,   111,   112,   106,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
       0,   109,     0,   110,   111,   112,     2,     3,     0,     0,
       4,     5,     0,     0,     0,     6,     7,     0,     8,     9,
      10,     0,     0,     0,     0,    11,    12,    13,    14,     0,
       0,    15,    16,     0,    17,    18,     0,    19,    20,    21,
      22,    23,     0,    24,    25,    26,     0,     2,     3,     0,
       0,     4,     5,   272,   305,   240,     6,     7,     0,     8,
       9,    10,     0,     0,     0,     0,    11,    12,    13,    14,
       0,     0,    15,    16,     0,    17,    18,     0,    19,    20,
      21,    22,    23,     0,    24,    25,    26,     0,   144,    28,
      58,     0,     2,     3,     0,     0,     4,     5,     0,     0,
      77,     6,     7,     0,     8,     9,    10,     0,     0,     0,
       0,    11,    12,    13,    14,     0,     0,    15,    16,     0,
      17,    18,     0,    19,    20,    21,    22,    23,     0,    24,
      25,    26,     2,     3,     0,     0,     4,     5,     0,     0,
     145,     6,     7,     0,     8,     9,    10,     0,     0,     0,
       0,    11,    12,    13,    14,     0,     0,    15,    16,     0,
      17,    18,     0,    19,    20,    21,    22,    23,     0,    24,
      25,    26,     2,     0,     0,     0,     4,     5,     0,     0,
     337,     6,     7,     0,     8,     0,    10,     0,     0,     0,
       0,    11,    12,    13,     0,     0,     0,    15,    16,     0,
       0,    18,     0,     0,    20,    21,    22,    23,     2,    24,
      25,    26,     4,     5,     0,     0,   167,     6,     7,     0,
       8,     0,    10,     0,     0,     0,     0,    11,    12,    13,
       0,     0,     0,    15,    16,     0,     0,    18,     0,     0,
      20,    21,    22,    23,     0,    24,    25,    26,     0,     2,
       3,     0,   255,     4,     5,     0,     0,     0,     6,     7,
       0,     8,     9,    10,     0,     0,     0,     0,    11,    12,
      13,    14,     0,     0,    15,    16,     0,    17,    18,     0,
      19,    20,    21,    22,    23,     0,    24,    25,    26,     2,
       3,     0,    58,     4,     5,     0,     0,     0,     6,     7,
       0,     8,     9,    10,     0,     0,     0,     0,    11,    12,
      13,    14,     0,     0,    15,    16,     0,    17,    18,     0,
      19,    20,    21,    22,    23,     0,    24,    25,    26,   313,
       2,     3,     0,     0,     4,     5,     0,     0,     0,     6,
       7,     0,     8,     9,    10,     0,     0,     0,     0,    11,
      12,    13,    14,     0,     0,    15,    16,     0,    17,    18,
       0,    19,    20,    21,    22,    23,     2,    24,    25,    26,
       4,     5,     0,     0,     0,     6,     7,     0,     8,     0,
      10,     0,     0,     0,     0,    11,    12,    13,     0,     0,
       0,    15,    16,     0,     0,    18,     0,     0,    20,    21,
      22,    23,     0,    24,    25,    26
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    77,    77,    82,    63,    39,     3,    64,    98,    50,
       0,    64,    27,   242,   104,    30,     3,     3,     3,    28,
      52,   180,   146,    56,     3,    57,     3,     3,   185,    12,
     117,    31,    32,     3,    91,   192,    36,    91,    91,    48,
      40,    55,    94,     3,   273,    60,    99,    80,    81,    82,
      40,    50,    85,   106,   107,    60,    53,    54,    54,    42,
      56,    76,    53,    63,   117,    50,   190,    54,    52,    84,
      49,   104,    62,    53,    58,    54,    49,    54,    54,    56,
      50,    28,    51,    52,   136,   161,   165,    81,    54,    79,
      56,    85,   182,    90,    54,   185,    56,   187,   188,    49,
     157,    48,   192,   157,   157,   264,   196,    90,    54,    56,
     104,    90,   169,    90,    90,   169,   169,    48,    52,   195,
      49,    55,   174,    52,    90,     3,   178,   214,   215,   216,
      54,   146,   165,    80,    81,    82,   212,   146,    85,    49,
      49,   231,    52,    52,    49,   135,    77,    52,    78,    79,
      80,    81,   185,   221,   222,   223,   224,   104,   234,   192,
      54,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,    37,   232,
      54,   190,    52,   240,   236,    55,   240,   240,   275,    88,
      89,   185,    54,    52,    56,    86,    58,    52,   192,    85,
      55,    52,   259,    62,    55,   259,   259,    52,   242,   261,
      55,    73,    74,    75,    52,    87,    52,    55,   165,    55,
      79,    55,   275,    52,   239,    60,    55,    90,    91,    92,
     239,   321,   322,    54,    54,    56,    56,    76,   185,   239,
      52,   317,   317,   258,    57,   192,   246,    71,    72,    82,
      83,   327,   311,    53,   330,   312,    51,    52,   312,   312,
      51,    52,    43,   272,    52,    53,    51,    52,   217,   218,
      53,   323,   272,   325,   326,    49,   333,   219,   220,    55,
     333,   225,   226,   359,   359,     3,     3,     3,    54,    57,
      55,    55,   344,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,   356,   357,     0,    55,    55,     3,
      50,   311,    55,     7,     8,    57,    18,    11,    12,    49,
     227,   229,    16,    17,   228,    19,    20,    21,   230,   232,
      76,    80,    26,    27,    28,    29,   258,    68,    32,    33,
     159,    35,    36,   135,    38,    39,    40,    41,    42,   246,
      44,    45,    46,   327,    40,    -1,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    29,    90,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    49,    50,    51,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    -1,    86,    -1,    88,    89,    90,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    49,    50,    51,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,    -1,    73,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,
      86,    -1,    88,    89,    90,     3,     4,     5,     6,     7,
      -1,    -1,    34,    11,    12,    -1,    -1,    -1,    16,    17,
      -1,    19,    -1,    21,    -1,    -1,    -1,    49,    26,    27,
      28,    -1,    54,    -1,    32,    33,    34,    59,    36,    -1,
      -1,    39,    40,    41,    42,    -1,    44,    45,    46,    -1,
      -1,    73,    74,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    59,    84,    -1,    86,    -1,    88,    89,    90,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    86,     3,
      88,    89,    90,     7,     8,    -1,    -1,    11,    12,    -1,
      -1,    -1,    16,    17,    -1,    19,    20,    21,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    -1,    -1,    32,    33,
      -1,    35,    36,    -1,    38,    39,    40,    41,    42,    -1,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    56,    -1,    -1,     3,    -1,    -1,    -1,     7,
       8,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,    17,
      -1,    19,    20,    21,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    -1,    -1,    32,    33,    90,    35,    36,    -1,
      38,    39,    40,    41,    42,    -1,    44,    45,    46,    -1,
      -1,     3,     4,     5,     6,    -1,    54,     9,    10,    -1,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    34,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    43,    90,    -1,    -1,    -1,    -1,    49,    50,    51,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    59,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    -1,    86,    -1,    88,    89,    90,     3,
       4,     5,     6,    -1,    34,     9,    10,    -1,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    -1,    -1,    -1,    54,    55,    -1,    31,    -1,    59,
      34,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    73,    74,    49,    50,    51,    -1,    -1,
      54,    -1,    -1,    -1,    84,    59,    86,    -1,    88,    89,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    -1,    86,    -1,    88,    89,    90,     3,     4,     5,
       6,    -1,    -1,     9,    10,    -1,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    -1,
      -1,    37,    -1,    -1,    -1,    -1,    -1,    43,     3,     4,
       5,     6,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    59,    -1,    -1,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,
      86,    -1,    88,    89,    90,    50,    51,    34,    -1,    54,
      -1,    -1,    -1,    -1,    59,    -1,    -1,     3,     4,     5,
       6,    -1,    -1,    50,    51,    -1,    -1,    54,    73,    74,
      -1,    -1,    59,    -1,    -1,     3,     4,     5,     6,    84,
      -1,    86,    -1,    88,    89,    90,    73,    74,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    86,
      -1,    88,    89,    90,    -1,    -1,    34,    -1,    54,    -1,
      -1,    57,    -1,    59,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,    50,    -1,    -1,    -1,    54,    73,    74,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,
      86,    -1,    88,    89,    90,    73,    74,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    86,    -1,
      88,    89,    90,    49,     3,     4,     5,     6,    54,    -1,
      -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,    73,    74,    -1,
       3,     4,     5,     6,    -1,    34,    -1,    -1,    84,    -1,
      86,    -1,    88,    89,    90,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,    34,    -1,    54,    -1,    -1,    57,    -1,
      59,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    -1,    54,    73,    74,    -1,    -1,    59,    34,
      -1,    54,    -1,    -1,    57,    84,    59,    86,    -1,    88,
      89,    90,    73,    74,     3,     4,     5,     6,    -1,    54,
      73,    74,    -1,    84,    59,    86,    -1,    88,    89,    90,
      -1,    84,    -1,    86,    -1,    88,    89,    90,    73,    74,
       3,     4,     5,     6,    -1,    34,    -1,    -1,    -1,    84,
      -1,    86,    -1,    88,    89,    90,    -1,    -1,     3,     4,
       5,     6,    -1,    -1,    -1,    54,    55,    -1,    -1,    -1,
      59,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    -1,    -1,    -1,    34,
      -1,    54,    -1,    -1,    -1,    84,    59,    86,    -1,    88,
      89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      73,    74,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    -1,    86,    -1,    88,    89,    90,    73,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    86,    -1,    88,    89,    90,     7,     8,    -1,    -1,
      11,    12,    -1,    -1,    -1,    16,    17,    -1,    19,    20,
      21,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    -1,
      -1,    32,    33,    -1,    35,    36,    -1,    38,    39,    40,
      41,    42,    -1,    44,    45,    46,    -1,     7,     8,    -1,
      -1,    11,    12,    54,    55,    56,    16,    17,    -1,    19,
      20,    21,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      -1,    -1,    32,    33,    -1,    35,    36,    -1,    38,    39,
      40,    41,    42,    -1,    44,    45,    46,    -1,     3,    90,
      50,    -1,     7,     8,    -1,    -1,    11,    12,    -1,    -1,
      60,    16,    17,    -1,    19,    20,    21,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    -1,    -1,    32,    33,    -1,
      35,    36,    -1,    38,    39,    40,    41,    42,    -1,    44,
      45,    46,     7,     8,    -1,    -1,    11,    12,    -1,    -1,
      55,    16,    17,    -1,    19,    20,    21,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    -1,    -1,    32,    33,    -1,
      35,    36,    -1,    38,    39,    40,    41,    42,    -1,    44,
      45,    46,     7,    -1,    -1,    -1,    11,    12,    -1,    -1,
      55,    16,    17,    -1,    19,    -1,    21,    -1,    -1,    -1,
      -1,    26,    27,    28,    -1,    -1,    -1,    32,    33,    -1,
      -1,    36,    -1,    -1,    39,    40,    41,    42,     7,    44,
      45,    46,    11,    12,    -1,    -1,    51,    16,    17,    -1,
      19,    -1,    21,    -1,    -1,    -1,    -1,    26,    27,    28,
      -1,    -1,    -1,    32,    33,    -1,    -1,    36,    -1,    -1,
      39,    40,    41,    42,    -1,    44,    45,    46,    -1,     7,
       8,    -1,    51,    11,    12,    -1,    -1,    -1,    16,    17,
      -1,    19,    20,    21,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    -1,    -1,    32,    33,    -1,    35,    36,    -1,
      38,    39,    40,    41,    42,    -1,    44,    45,    46,     7,
       8,    -1,    50,    11,    12,    -1,    -1,    -1,    16,    17,
      -1,    19,    20,    21,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    -1,    -1,    32,    33,    -1,    35,    36,    -1,
      38,    39,    40,    41,    42,    -1,    44,    45,    46,    47,
       7,     8,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,
      17,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    -1,    -1,    32,    33,    -1,    35,    36,
      -1,    38,    39,    40,    41,    42,     7,    44,    45,    46,
      11,    12,    -1,    -1,    -1,    16,    17,    -1,    19,    -1,
      21,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,    -1,
      -1,    32,    33,    -1,    -1,    36,    -1,    -1,    39,    40,
      41,    42,    -1,    44,    45,    46
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     7,     8,    11,    12,    16,    17,    19,    20,
      21,    26,    27,    28,    29,    32,    33,    35,    36,    38,
      39,    40,    41,    42,    44,    45,    46,    54,    90,   116,
     117,   120,   121,   122,   123,   129,   132,   133,   134,   135,
     155,   156,   157,     3,    50,   133,   132,   135,   136,    49,
     118,   119,   133,   117,   117,     3,    50,   117,    50,   116,
     117,   148,   149,    54,    56,   134,     0,   156,    50,     3,
     130,   131,    55,   132,   135,    49,    52,    60,   148,   149,
      50,   121,   124,   125,   126,   132,     3,     4,     5,     6,
       9,    10,    13,    14,    15,    22,    23,    24,    31,    34,
      37,    43,    49,    51,    54,    59,    73,    74,    84,    86,
      88,    89,    90,    94,    95,    96,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   114,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   133,   116,   148,     3,    55,   117,   137,   138,   139,
     140,     3,    57,    98,   111,   115,   130,    60,    51,    52,
     119,    50,   112,   144,   148,   124,   126,    51,   125,    53,
     127,   128,   133,   126,    53,    49,   115,    49,    53,   146,
      54,     3,    54,    49,   114,    54,    98,    54,    54,   114,
     126,   141,    54,    98,    98,    54,    56,    58,    73,    74,
      75,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,   113,   100,    90,    91,    92,    88,    89,    71,
      72,    78,    79,    80,    81,    82,    83,    86,    85,    87,
      76,    48,    77,    49,    52,    51,   150,    51,   146,    54,
      56,   133,   135,   142,   143,    55,    52,    52,    55,    57,
      51,   115,   131,   144,   145,    51,   115,    49,    52,    53,
     146,    53,   146,    43,   151,    49,   114,    49,   141,   114,
     114,    55,    54,   135,   142,    55,   141,    55,    97,   112,
     114,     3,     3,   112,   100,   100,   100,   101,   101,   102,
     102,   103,   103,   103,   103,   104,   104,   105,   106,   107,
     108,   114,   109,   112,    51,    55,   137,   142,    57,   115,
     143,    54,    56,    47,   139,     3,    51,    52,   128,   115,
     146,    54,   151,    55,    55,    55,    55,    50,   100,    55,
      52,    55,    57,    53,    55,    55,    57,    55,   137,    57,
     115,    51,   144,   114,    55,   114,   146,   146,   146,   145,
     112,   111,    55,    57,    55,   146,    55,    18,    51,    52,
      49,   146,   146,    51
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
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   122,   122,   122,   123,   123,   124,
     124,   125,   126,   126,   126,   126,   127,   127,   128,   128,
     128,   129,   129,   129,   130,   130,   131,   131,   132,   132,
     133,   133,   134,   134,   134,   134,   134,   134,   134,   135,
     135,   135,   135,   136,   136,   137,   137,   138,   138,   139,
     139,   139,   140,   140,   141,   141,   142,   142,   142,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   144,   144,
     144,   145,   145,   146,   146,   146,   146,   146,   146,   147,
     147,   147,   148,   148,   148,   148,   149,   149,   150,   150,
     151,   151,   152,   152,   152,   153,   153,   153,   153,   154,
     154,   154,   154,   154,   155,   155,   156,   156,   157,   157,
     157,   157
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     4,     2,     1,     1,     1,
       2,     3,     2,     1,     2,     1,     1,     3,     1,     2,
       3,     4,     5,     2,     1,     3,     1,     3,     1,     1,
       2,     1,     1,     3,     4,     3,     4,     4,     3,     1,
       2,     2,     3,     1,     2,     1,     3,     1,     3,     2,
       2,     1,     1,     3,     1,     2,     1,     1,     2,     3,
       2,     3,     3,     4,     2,     3,     3,     4,     1,     3,
       4,     1,     3,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     2,     3,     3,     4,     1,     2,     1,     2,
       1,     2,     5,     7,     5,     5,     7,     6,     7,     3,
       2,     2,     2,     3,     1,     2,     1,     1,     4,     3,
       3,     2
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
       0,   279,   279,   280,   281,   285,   290,   295,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   315,   321,
     331,   332,   333,   334,   335,   336,   340,   341,   342,   343,
     344,   345,   349,   350,   354,   355,   356,   357,   361,   362,
     363,   367,   368,   369,   373,   374,   375,   376,   377,   381,
     382,   383,   387,   388,   392,   393,   397,   398,   402,   403,
     407,   408,   412,   413,   417,   418,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   436,   437,   441,
     445,   446,   450,   451,   452,   453,   454,   455,   459,   465,
     475,   476,   480,   481,   482,   483,   484,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   508,   509,   510,   514,   515,   519,
     525,   535,   539,   540,   541,   542,   546,   552,   562,   563,
     564,   568,   569,   570,   574,   580,   590,   591,   595,   596,
     600,   601,   605,   606,   607,   608,   609,   610,   611,   615,
     616,   617,   618,   622,   628,   639,   640,   644,   650,   660,
     661,   662,   666,   672,   682,   683,   687,   688,   689,   693,
     694,   695,   696,   697,   698,   699,   700,   701,   705,   706,
     707,   711,   717,   727,   728,   729,   730,   731,   732,   736,
     737,   738,   742,   743,   744,   745,   749,   755,   765,   771,
     781,   782,   786,   787,   788,   792,   793,   794,   795,   799,
     800,   801,   802,   803,   807,   808,   812,   813,   817,   818,
     819,   820
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
#line 4714 "parser.cpp"

#line 823 "parser.y"


// Bison expects us to provide implementation - otherwise linker complains
void WadeSpace::Parser::error(const location &loc , const std::string &message) {
        
        // Location should be initialized inside scanner action, but is not in this example.
        // Let's grab location directly from driver class.
    // cout << "Error: " << message << endl << "Location: " << loc << endl;
    
        cout << "Error: " << message << endl << "Error location: " << driver.location() << endl;
}
