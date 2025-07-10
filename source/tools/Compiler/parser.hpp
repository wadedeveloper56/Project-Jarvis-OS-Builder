// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file parser.hpp
 ** Define the  WadeSpace ::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
// "%code requires" blocks.
#line 11 "parser.y"

    #include <iostream>
    #include <string>
    #include <vector>
    #include <stdint.h>
    #include <stdlib.h>
    #include <optional>
    #include "Constant.h"
    #include "AssignmentOperator.h"
    #include "StorageClassSpecifier.h"
    #include "DeclarationSpecifiers.h"
    #include "TypeSpecifier.h"
    #include "TypeQualifier.h"
    #include "Enumerator.h"
    #include "EnumSpecifier.h"
    #include "Expression.h"
    #include "PrimaryExpression.h"
    #include "Pointer.h"
    #include "DirectDeclarator.h"
    #include "Declarator.h"
    #include "DirectAbstractDeclarator.h"
    #include "AbstractDeclarator.h"
    #include "TypeName.h"
    #include "SpecifierQualifierList.h"
    #include "StructDeclarator.h"
    #include "StructDeclaration.h"
    #include "StructOrUnion.h"
    #include "StructOrUnionSpecifier.h"
    #include "Initializer.h"
    #include "InitDeclarator.h"
    #include "Declaration.h"
    #include "ParameterDeclaration.h"
    #include "ParameterTypeList.h"
    #include "PostfixExpression.h"
    #include "UnaryExpression.h"
    #include "CastExpression.h"    

    using namespace std;

    namespace WadeSpace {
        class Scanner;
        class Interpreter;
    }

#line 94 "parser.hpp"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
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

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 9 "parser.y"
namespace  WadeSpace  {
#line 235 "parser.hpp"




  /// A Bison parser.
  class  Parser 
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // abstract_declarator
      char dummy1[sizeof (AbstractDeclarator)];

      // assignment_operator
      char dummy2[sizeof (AssignmentOperator)];

      // cast_expression
      char dummy3[sizeof (CastExpression)];

      // constant
      char dummy4[sizeof (Constant)];

      // declaration
      char dummy5[sizeof (Declaration)];

      // declaration_specifiers
      char dummy6[sizeof (DeclarationSpecifiers)];

      // declarator
      char dummy7[sizeof (Declarator)];

      // direct_abstract_declarator
      char dummy8[sizeof (DirectAbstractDeclarator)];

      // direct_declarator
      char dummy9[sizeof (DirectDeclarator)];

      // enum_specifier
      char dummy10[sizeof (EnumSpecifier)];

      // enumerator
      char dummy11[sizeof (Enumerator)];

      // multiplicative_expression
      // additive_expression
      // shift_expression
      // relational_expression
      // equality_expression
      // and_expression
      // exclusive_or_expression
      // inclusive_or_expression
      // logical_and_expression
      // logical_or_expression
      // conditional_expression
      // assignment_expression
      // expression
      // constant_expression
      char dummy12[sizeof (Expression)];

      // init_declarator
      char dummy13[sizeof (InitDeclarator)];

      // initializer
      char dummy14[sizeof (Initializer)];

      // parameter_declaration
      char dummy15[sizeof (ParameterDeclaration)];

      // parameter_type_list
      char dummy16[sizeof (ParameterTypeList)];

      // pointer
      char dummy17[sizeof (Pointer)];

      // postfix_expression
      char dummy18[sizeof (PostfixExpression)];

      // primary_expression
      char dummy19[sizeof (PrimaryExpression)];

      // specifier_qualifier_list
      char dummy20[sizeof (SpecifierQualifierList)];

      // storage_class_specifier
      char dummy21[sizeof (StorageClassSpecifier)];

      // struct_declaration
      char dummy22[sizeof (StructDeclaration)];

      // struct_declarator
      char dummy23[sizeof (StructDeclarator)];

      // struct_or_union
      char dummy24[sizeof (StructOrUnion)];

      // struct_or_union_specifier
      char dummy25[sizeof (StructOrUnionSpecifier)];

      // type_name
      char dummy26[sizeof (TypeName)];

      // type_qualifier
      char dummy27[sizeof (TypeQualifier)];

      // type_specifier
      char dummy28[sizeof (TypeSpecifier)];

      // unary_expression
      char dummy29[sizeof (UnaryExpression)];

      // "f_const"
      char dummy30[sizeof (long double)];

      // "identifier"
      // "sting_literal"
      // "type name"
      // "auto"
      // "break"
      // "case"
      // "char"
      // "const"
      // "continue"
      // "default"
      // "do"
      // "double"
      // "long double"
      // "else"
      // "enum"
      // "extern"
      // "float"
      // "for"
      // "goto"
      // "if"
      // "inline"
      // "int"
      // "long"
      // "long long"
      // "register"
      // "restrict"
      // "return"
      // "short"
      // "signed"
      // "sizeof"
      // "static"
      // "struct"
      // "switch"
      // "typedef"
      // "union"
      // "unsigned"
      // "void"
      // "volatile"
      // "while"
      // "bool"
      // "complex"
      // "imaginary"
      // "ellipsis"
      // "question"
      // ";"
      // "{"
      // "}"
      // ","
      // ":"
      // "("
      // ")"
      // "["
      // "]"
      // "."
      // "~"
      // "="
      // ">>="
      // "<<="
      // "+="
      // "-="
      // "*="
      // "/="
      // "%="
      // "&="
      // "^="
      // "|="
      // ">>"
      // "<<"
      // "++"
      // "--"
      // "->"
      // "&&"
      // "||"
      // ">="
      // "<="
      // ">"
      // "<"
      // "=="
      // "!="
      // "!"
      // "^"
      // "&"
      // "|"
      // "-"
      // "+"
      // "*"
      // "/"
      // "%"
      // unary_operator
      char dummy31[sizeof (std::string)];

      // enumerator_list
      char dummy32[sizeof (std::vector<Enumerator>)];

      // argument_expression_list
      char dummy33[sizeof (std::vector<Expression>)];

      // init_declarator_list
      char dummy34[sizeof (std::vector<InitDeclarator>)];

      // initializer_list
      char dummy35[sizeof (std::vector<Initializer>)];

      // parameter_list
      char dummy36[sizeof (std::vector<ParameterDeclaration>)];

      // struct_declaration_list
      char dummy37[sizeof (std::vector<StructDeclaration>)];

      // struct_declarator_list
      char dummy38[sizeof (std::vector<StructDeclarator>)];

      // type_qualifier_list
      char dummy39[sizeof (std::vector<TypeQualifier>)];

      // identifier_list
      char dummy40[sizeof (std::vector<std::string>)];

      // "i_const"
      char dummy41[sizeof (uint64_t)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        TOKEN_YYEMPTY = -2,
    TOKEN_END = 0,                 // "end of file"
    TOKEN_YYerror = 256,           // error
    TOKEN_YYUNDEF = 257,           // "invalid token"
    TOKEN_IDENTIFIER = 258,        // "identifier"
    TOKEN_I_CONST = 259,           // "i_const"
    TOKEN_F_CONST = 260,           // "f_const"
    TOKEN_STRING_LITERAL = 261,    // "sting_literal"
    TOKEN_TYPE_NAME = 262,         // "type name"
    TOKEN_AUTO = 263,              // "auto"
    TOKEN_BREAK = 264,             // "break"
    TOKEN_CASE = 265,              // "case"
    TOKEN_CHAR = 266,              // "char"
    TOKEN_CONST = 267,             // "const"
    TOKEN_CONTINUE = 268,          // "continue"
    TOKEN_DEFAULT = 269,           // "default"
    TOKEN_DO = 270,                // "do"
    TOKEN_DOUBLE = 271,            // "double"
    TOKEN_LONG_DOUBLE = 272,       // "long double"
    TOKEN_ELSE = 273,              // "else"
    TOKEN_ENUM = 274,              // "enum"
    TOKEN_EXTERN = 275,            // "extern"
    TOKEN_FLOAT = 276,             // "float"
    TOKEN_FOR = 277,               // "for"
    TOKEN_GOTO = 278,              // "goto"
    TOKEN_IF = 279,                // "if"
    TOKEN_INLINE = 280,            // "inline"
    TOKEN_INT = 281,               // "int"
    TOKEN_LONG = 282,              // "long"
    TOKEN_LONG_LONG = 283,         // "long long"
    TOKEN_REGISTER = 284,          // "register"
    TOKEN_RESTRICT = 285,          // "restrict"
    TOKEN_RETURN = 286,            // "return"
    TOKEN_SHORT = 287,             // "short"
    TOKEN_SIGNED = 288,            // "signed"
    TOKEN_SIZEOF = 289,            // "sizeof"
    TOKEN_STATIC = 290,            // "static"
    TOKEN_STRUCT = 291,            // "struct"
    TOKEN_SWITCH = 292,            // "switch"
    TOKEN_TYPEDEF = 293,           // "typedef"
    TOKEN_UNION = 294,             // "union"
    TOKEN_UNSIGNED = 295,          // "unsigned"
    TOKEN_VOID = 296,              // "void"
    TOKEN_VOLATILE = 297,          // "volatile"
    TOKEN_WHILE = 298,             // "while"
    TOKEN_BOOL = 299,              // "bool"
    TOKEN_COMPLEX = 300,           // "complex"
    TOKEN_IMAGINARY = 301,         // "imaginary"
    TOKEN_ELLIPSIS = 302,          // "ellipsis"
    TOKEN_QUESTION = 303,          // "question"
    TOKEN_SEMICOLON = 304,         // ";"
    TOKEN_OCURLY = 305,            // "{"
    TOKEN_CCURLY = 306,            // "}"
    TOKEN_COMMA = 307,             // ","
    TOKEN_COLON = 308,             // ":"
    TOKEN_OPAREN = 309,            // "("
    TOKEN_CPAREN = 310,            // ")"
    TOKEN_OBRACE = 311,            // "["
    TOKEN_CBRACE = 312,            // "]"
    TOKEN_PERIOD = 313,            // "."
    TOKEN_TILDE = 314,             // "~"
    TOKEN_EQUAL = 315,             // "="
    TOKEN_RIGHT_ASSIGN = 316,      // ">>="
    TOKEN_LEFT_ASSIGN = 317,       // "<<="
    TOKEN_ADD_ASSIGN = 318,        // "+="
    TOKEN_SUB_ASSIGN = 319,        // "-="
    TOKEN_MUL_ASSIGN = 320,        // "*="
    TOKEN_DIV_ASSIGN = 321,        // "/="
    TOKEN_MOD_ASSIGN = 322,        // "%="
    TOKEN_AND_ASSIGN = 323,        // "&="
    TOKEN_XOR_ASSIGN = 324,        // "^="
    TOKEN_OR_ASSIGN = 325,         // "|="
    TOKEN_RIGHT_OP = 326,          // ">>"
    TOKEN_LEFT_OP = 327,           // "<<"
    TOKEN_INC_OP = 328,            // "++"
    TOKEN_DEC_OP = 329,            // "--"
    TOKEN_PTR_OP = 330,            // "->"
    TOKEN_AND_OP = 331,            // "&&"
    TOKEN_OR_OP = 332,             // "||"
    TOKEN_GREATER_EQUAL = 333,     // ">="
    TOKEN_LESS_EQUAL = 334,        // "<="
    TOKEN_GREATER = 335,           // ">"
    TOKEN_LESS = 336,              // "<"
    TOKEN_EQUAL_EQUAL = 337,       // "=="
    TOKEN_NOT_EQUAL = 338,         // "!="
    TOKEN_NOT_OP = 339,            // "!"
    TOKEN_XOR_OP = 340,            // "^"
    TOKEN_BIT_AND = 341,           // "&"
    TOKEN_BIT_OR = 342,            // "|"
    TOKEN_MINUS_OP = 343,          // "-"
    TOKEN_PLUS_OP = 344,           // "+"
    TOKEN_TIMES_OP = 345,          // "*"
    TOKEN_DIV_OP = 346,            // "/"
    TOKEN_MOD_OP = 347             // "%"
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 93, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_IDENTIFIER = 3,                        // "identifier"
        S_I_CONST = 4,                           // "i_const"
        S_F_CONST = 5,                           // "f_const"
        S_STRING_LITERAL = 6,                    // "sting_literal"
        S_TYPE_NAME = 7,                         // "type name"
        S_AUTO = 8,                              // "auto"
        S_BREAK = 9,                             // "break"
        S_CASE = 10,                             // "case"
        S_CHAR = 11,                             // "char"
        S_CONST = 12,                            // "const"
        S_CONTINUE = 13,                         // "continue"
        S_DEFAULT = 14,                          // "default"
        S_DO = 15,                               // "do"
        S_DOUBLE = 16,                           // "double"
        S_LONG_DOUBLE = 17,                      // "long double"
        S_ELSE = 18,                             // "else"
        S_ENUM = 19,                             // "enum"
        S_EXTERN = 20,                           // "extern"
        S_FLOAT = 21,                            // "float"
        S_FOR = 22,                              // "for"
        S_GOTO = 23,                             // "goto"
        S_IF = 24,                               // "if"
        S_INLINE = 25,                           // "inline"
        S_INT = 26,                              // "int"
        S_LONG = 27,                             // "long"
        S_LONG_LONG = 28,                        // "long long"
        S_REGISTER = 29,                         // "register"
        S_RESTRICT = 30,                         // "restrict"
        S_RETURN = 31,                           // "return"
        S_SHORT = 32,                            // "short"
        S_SIGNED = 33,                           // "signed"
        S_SIZEOF = 34,                           // "sizeof"
        S_STATIC = 35,                           // "static"
        S_STRUCT = 36,                           // "struct"
        S_SWITCH = 37,                           // "switch"
        S_TYPEDEF = 38,                          // "typedef"
        S_UNION = 39,                            // "union"
        S_UNSIGNED = 40,                         // "unsigned"
        S_VOID = 41,                             // "void"
        S_VOLATILE = 42,                         // "volatile"
        S_WHILE = 43,                            // "while"
        S_BOOL = 44,                             // "bool"
        S_COMPLEX = 45,                          // "complex"
        S_IMAGINARY = 46,                        // "imaginary"
        S_ELLIPSIS = 47,                         // "ellipsis"
        S_QUESTION = 48,                         // "question"
        S_SEMICOLON = 49,                        // ";"
        S_OCURLY = 50,                           // "{"
        S_CCURLY = 51,                           // "}"
        S_COMMA = 52,                            // ","
        S_COLON = 53,                            // ":"
        S_OPAREN = 54,                           // "("
        S_CPAREN = 55,                           // ")"
        S_OBRACE = 56,                           // "["
        S_CBRACE = 57,                           // "]"
        S_PERIOD = 58,                           // "."
        S_TILDE = 59,                            // "~"
        S_EQUAL = 60,                            // "="
        S_RIGHT_ASSIGN = 61,                     // ">>="
        S_LEFT_ASSIGN = 62,                      // "<<="
        S_ADD_ASSIGN = 63,                       // "+="
        S_SUB_ASSIGN = 64,                       // "-="
        S_MUL_ASSIGN = 65,                       // "*="
        S_DIV_ASSIGN = 66,                       // "/="
        S_MOD_ASSIGN = 67,                       // "%="
        S_AND_ASSIGN = 68,                       // "&="
        S_XOR_ASSIGN = 69,                       // "^="
        S_OR_ASSIGN = 70,                        // "|="
        S_RIGHT_OP = 71,                         // ">>"
        S_LEFT_OP = 72,                          // "<<"
        S_INC_OP = 73,                           // "++"
        S_DEC_OP = 74,                           // "--"
        S_PTR_OP = 75,                           // "->"
        S_AND_OP = 76,                           // "&&"
        S_OR_OP = 77,                            // "||"
        S_GREATER_EQUAL = 78,                    // ">="
        S_LESS_EQUAL = 79,                       // "<="
        S_GREATER = 80,                          // ">"
        S_LESS = 81,                             // "<"
        S_EQUAL_EQUAL = 82,                      // "=="
        S_NOT_EQUAL = 83,                        // "!="
        S_NOT_OP = 84,                           // "!"
        S_XOR_OP = 85,                           // "^"
        S_BIT_AND = 86,                          // "&"
        S_BIT_OR = 87,                           // "|"
        S_MINUS_OP = 88,                         // "-"
        S_PLUS_OP = 89,                          // "+"
        S_TIMES_OP = 90,                         // "*"
        S_DIV_OP = 91,                           // "/"
        S_MOD_OP = 92,                           // "%"
        S_YYACCEPT = 93,                         // $accept
        S_primary_expression = 94,               // primary_expression
        S_constant = 95,                         // constant
        S_postfix_expression = 96,               // postfix_expression
        S_argument_expression_list = 97,         // argument_expression_list
        S_unary_expression = 98,                 // unary_expression
        S_unary_operator = 99,                   // unary_operator
        S_cast_expression = 100,                 // cast_expression
        S_multiplicative_expression = 101,       // multiplicative_expression
        S_additive_expression = 102,             // additive_expression
        S_shift_expression = 103,                // shift_expression
        S_relational_expression = 104,           // relational_expression
        S_equality_expression = 105,             // equality_expression
        S_and_expression = 106,                  // and_expression
        S_exclusive_or_expression = 107,         // exclusive_or_expression
        S_inclusive_or_expression = 108,         // inclusive_or_expression
        S_logical_and_expression = 109,          // logical_and_expression
        S_logical_or_expression = 110,           // logical_or_expression
        S_conditional_expression = 111,          // conditional_expression
        S_assignment_expression = 112,           // assignment_expression
        S_assignment_operator = 113,             // assignment_operator
        S_expression = 114,                      // expression
        S_constant_expression = 115,             // constant_expression
        S_declaration = 116,                     // declaration
        S_declaration_specifiers = 117,          // declaration_specifiers
        S_init_declarator_list = 118,            // init_declarator_list
        S_init_declarator = 119,                 // init_declarator
        S_storage_class_specifier = 120,         // storage_class_specifier
        S_type_specifier = 121,                  // type_specifier
        S_struct_or_union_specifier = 122,       // struct_or_union_specifier
        S_struct_or_union = 123,                 // struct_or_union
        S_struct_declaration_list = 124,         // struct_declaration_list
        S_struct_declaration = 125,              // struct_declaration
        S_specifier_qualifier_list = 126,        // specifier_qualifier_list
        S_struct_declarator_list = 127,          // struct_declarator_list
        S_struct_declarator = 128,               // struct_declarator
        S_enum_specifier = 129,                  // enum_specifier
        S_enumerator_list = 130,                 // enumerator_list
        S_enumerator = 131,                      // enumerator
        S_type_qualifier = 132,                  // type_qualifier
        S_declarator = 133,                      // declarator
        S_direct_declarator = 134,               // direct_declarator
        S_pointer = 135,                         // pointer
        S_type_qualifier_list = 136,             // type_qualifier_list
        S_parameter_type_list = 137,             // parameter_type_list
        S_parameter_list = 138,                  // parameter_list
        S_parameter_declaration = 139,           // parameter_declaration
        S_identifier_list = 140,                 // identifier_list
        S_type_name = 141,                       // type_name
        S_abstract_declarator = 142,             // abstract_declarator
        S_direct_abstract_declarator = 143,      // direct_abstract_declarator
        S_initializer = 144,                     // initializer
        S_initializer_list = 145,                // initializer_list
        S_statement = 146,                       // statement
        S_labeled_statement = 147,               // labeled_statement
        S_compound_statement = 148,              // compound_statement
        S_declaration_list = 149,                // declaration_list
        S_statement_list = 150,                  // statement_list
        S_expression_statement = 151,            // expression_statement
        S_selection_statement = 152,             // selection_statement
        S_iteration_statement = 153,             // iteration_statement
        S_jump_statement = 154,                  // jump_statement
        S_translation_unit = 155,                // translation_unit
        S_external_declaration = 156,            // external_declaration
        S_function_definition = 157              // function_definition
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_abstract_declarator: // abstract_declarator
        value.move< AbstractDeclarator > (std::move (that.value));
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
        value.move< AssignmentOperator > (std::move (that.value));
        break;

      case symbol_kind::S_cast_expression: // cast_expression
        value.move< CastExpression > (std::move (that.value));
        break;

      case symbol_kind::S_constant: // constant
        value.move< Constant > (std::move (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.move< Declaration > (std::move (that.value));
        break;

      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
        value.move< DeclarationSpecifiers > (std::move (that.value));
        break;

      case symbol_kind::S_declarator: // declarator
        value.move< Declarator > (std::move (that.value));
        break;

      case symbol_kind::S_direct_abstract_declarator: // direct_abstract_declarator
        value.move< DirectAbstractDeclarator > (std::move (that.value));
        break;

      case symbol_kind::S_direct_declarator: // direct_declarator
        value.move< DirectDeclarator > (std::move (that.value));
        break;

      case symbol_kind::S_enum_specifier: // enum_specifier
        value.move< EnumSpecifier > (std::move (that.value));
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.move< Enumerator > (std::move (that.value));
        break;

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
        value.move< Expression > (std::move (that.value));
        break;

      case symbol_kind::S_init_declarator: // init_declarator
        value.move< InitDeclarator > (std::move (that.value));
        break;

      case symbol_kind::S_initializer: // initializer
        value.move< Initializer > (std::move (that.value));
        break;

      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.move< ParameterDeclaration > (std::move (that.value));
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
        value.move< ParameterTypeList > (std::move (that.value));
        break;

      case symbol_kind::S_pointer: // pointer
        value.move< Pointer > (std::move (that.value));
        break;

      case symbol_kind::S_postfix_expression: // postfix_expression
        value.move< PostfixExpression > (std::move (that.value));
        break;

      case symbol_kind::S_primary_expression: // primary_expression
        value.move< PrimaryExpression > (std::move (that.value));
        break;

      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
        value.move< SpecifierQualifierList > (std::move (that.value));
        break;

      case symbol_kind::S_storage_class_specifier: // storage_class_specifier
        value.move< StorageClassSpecifier > (std::move (that.value));
        break;

      case symbol_kind::S_struct_declaration: // struct_declaration
        value.move< StructDeclaration > (std::move (that.value));
        break;

      case symbol_kind::S_struct_declarator: // struct_declarator
        value.move< StructDeclarator > (std::move (that.value));
        break;

      case symbol_kind::S_struct_or_union: // struct_or_union
        value.move< StructOrUnion > (std::move (that.value));
        break;

      case symbol_kind::S_struct_or_union_specifier: // struct_or_union_specifier
        value.move< StructOrUnionSpecifier > (std::move (that.value));
        break;

      case symbol_kind::S_type_name: // type_name
        value.move< TypeName > (std::move (that.value));
        break;

      case symbol_kind::S_type_qualifier: // type_qualifier
        value.move< TypeQualifier > (std::move (that.value));
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.move< TypeSpecifier > (std::move (that.value));
        break;

      case symbol_kind::S_unary_expression: // unary_expression
        value.move< UnaryExpression > (std::move (that.value));
        break;

      case symbol_kind::S_F_CONST: // "f_const"
        value.move< long double > (std::move (that.value));
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
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.move< std::vector<Enumerator> > (std::move (that.value));
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.move< std::vector<Expression> > (std::move (that.value));
        break;

      case symbol_kind::S_init_declarator_list: // init_declarator_list
        value.move< std::vector<InitDeclarator> > (std::move (that.value));
        break;

      case symbol_kind::S_initializer_list: // initializer_list
        value.move< std::vector<Initializer> > (std::move (that.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.move< std::vector<ParameterDeclaration> > (std::move (that.value));
        break;

      case symbol_kind::S_struct_declaration_list: // struct_declaration_list
        value.move< std::vector<StructDeclaration> > (std::move (that.value));
        break;

      case symbol_kind::S_struct_declarator_list: // struct_declarator_list
        value.move< std::vector<StructDeclarator> > (std::move (that.value));
        break;

      case symbol_kind::S_type_qualifier_list: // type_qualifier_list
        value.move< std::vector<TypeQualifier> > (std::move (that.value));
        break;

      case symbol_kind::S_identifier_list: // identifier_list
        value.move< std::vector<std::string> > (std::move (that.value));
        break;

      case symbol_kind::S_I_CONST: // "i_const"
        value.move< uint64_t > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AbstractDeclarator&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AbstractDeclarator& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AssignmentOperator&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AssignmentOperator& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, CastExpression&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const CastExpression& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Constant&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Constant& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Declaration&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Declaration& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, DeclarationSpecifiers&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const DeclarationSpecifiers& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Declarator&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Declarator& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, DirectAbstractDeclarator&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const DirectAbstractDeclarator& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, DirectDeclarator&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const DirectDeclarator& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, EnumSpecifier&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const EnumSpecifier& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Enumerator&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Enumerator& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Expression&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Expression& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, InitDeclarator&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const InitDeclarator& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Initializer&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Initializer& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ParameterDeclaration&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ParameterDeclaration& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ParameterTypeList&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ParameterTypeList& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Pointer&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Pointer& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, PostfixExpression&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const PostfixExpression& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, PrimaryExpression&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const PrimaryExpression& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, SpecifierQualifierList&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const SpecifierQualifierList& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, StorageClassSpecifier&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const StorageClassSpecifier& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, StructDeclaration&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const StructDeclaration& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, StructDeclarator&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const StructDeclarator& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, StructOrUnion&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const StructOrUnion& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, StructOrUnionSpecifier&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const StructOrUnionSpecifier& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, TypeName&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const TypeName& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, TypeQualifier&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const TypeQualifier& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, TypeSpecifier&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const TypeSpecifier& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, UnaryExpression&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const UnaryExpression& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, long double&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const long double& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<Enumerator>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<Enumerator>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<Expression>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<Expression>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<InitDeclarator>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<InitDeclarator>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<Initializer>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<Initializer>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<ParameterDeclaration>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<ParameterDeclaration>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<StructDeclaration>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<StructDeclaration>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<StructDeclarator>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<StructDeclarator>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<TypeQualifier>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<TypeQualifier>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<std::string>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<std::string>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, uint64_t&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const uint64_t& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_abstract_declarator: // abstract_declarator
        value.template destroy< AbstractDeclarator > ();
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
        value.template destroy< AssignmentOperator > ();
        break;

      case symbol_kind::S_cast_expression: // cast_expression
        value.template destroy< CastExpression > ();
        break;

      case symbol_kind::S_constant: // constant
        value.template destroy< Constant > ();
        break;

      case symbol_kind::S_declaration: // declaration
        value.template destroy< Declaration > ();
        break;

      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
        value.template destroy< DeclarationSpecifiers > ();
        break;

      case symbol_kind::S_declarator: // declarator
        value.template destroy< Declarator > ();
        break;

      case symbol_kind::S_direct_abstract_declarator: // direct_abstract_declarator
        value.template destroy< DirectAbstractDeclarator > ();
        break;

      case symbol_kind::S_direct_declarator: // direct_declarator
        value.template destroy< DirectDeclarator > ();
        break;

      case symbol_kind::S_enum_specifier: // enum_specifier
        value.template destroy< EnumSpecifier > ();
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.template destroy< Enumerator > ();
        break;

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
        value.template destroy< Expression > ();
        break;

      case symbol_kind::S_init_declarator: // init_declarator
        value.template destroy< InitDeclarator > ();
        break;

      case symbol_kind::S_initializer: // initializer
        value.template destroy< Initializer > ();
        break;

      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.template destroy< ParameterDeclaration > ();
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
        value.template destroy< ParameterTypeList > ();
        break;

      case symbol_kind::S_pointer: // pointer
        value.template destroy< Pointer > ();
        break;

      case symbol_kind::S_postfix_expression: // postfix_expression
        value.template destroy< PostfixExpression > ();
        break;

      case symbol_kind::S_primary_expression: // primary_expression
        value.template destroy< PrimaryExpression > ();
        break;

      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
        value.template destroy< SpecifierQualifierList > ();
        break;

      case symbol_kind::S_storage_class_specifier: // storage_class_specifier
        value.template destroy< StorageClassSpecifier > ();
        break;

      case symbol_kind::S_struct_declaration: // struct_declaration
        value.template destroy< StructDeclaration > ();
        break;

      case symbol_kind::S_struct_declarator: // struct_declarator
        value.template destroy< StructDeclarator > ();
        break;

      case symbol_kind::S_struct_or_union: // struct_or_union
        value.template destroy< StructOrUnion > ();
        break;

      case symbol_kind::S_struct_or_union_specifier: // struct_or_union_specifier
        value.template destroy< StructOrUnionSpecifier > ();
        break;

      case symbol_kind::S_type_name: // type_name
        value.template destroy< TypeName > ();
        break;

      case symbol_kind::S_type_qualifier: // type_qualifier
        value.template destroy< TypeQualifier > ();
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.template destroy< TypeSpecifier > ();
        break;

      case symbol_kind::S_unary_expression: // unary_expression
        value.template destroy< UnaryExpression > ();
        break;

      case symbol_kind::S_F_CONST: // "f_const"
        value.template destroy< long double > ();
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
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.template destroy< std::vector<Enumerator> > ();
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.template destroy< std::vector<Expression> > ();
        break;

      case symbol_kind::S_init_declarator_list: // init_declarator_list
        value.template destroy< std::vector<InitDeclarator> > ();
        break;

      case symbol_kind::S_initializer_list: // initializer_list
        value.template destroy< std::vector<Initializer> > ();
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.template destroy< std::vector<ParameterDeclaration> > ();
        break;

      case symbol_kind::S_struct_declaration_list: // struct_declaration_list
        value.template destroy< std::vector<StructDeclaration> > ();
        break;

      case symbol_kind::S_struct_declarator_list: // struct_declarator_list
        value.template destroy< std::vector<StructDeclarator> > ();
        break;

      case symbol_kind::S_type_qualifier_list: // type_qualifier_list
        value.template destroy< std::vector<TypeQualifier> > ();
        break;

      case symbol_kind::S_identifier_list: // identifier_list
        value.template destroy< std::vector<std::string> > ();
        break;

      case symbol_kind::S_I_CONST: // "i_const"
        value.template destroy< uint64_t > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return  Parser ::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_kind_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_kind_type (tok), l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::TOKEN_END
                   || (token::TOKEN_YYerror <= tok && tok <= token::TOKEN_YYUNDEF));
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, long double v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const long double& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::TOKEN_F_CONST);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::TOKEN_IDENTIFIER
                   || (token::TOKEN_STRING_LITERAL <= tok && tok <= token::TOKEN_MOD_OP));
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, uint64_t v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const uint64_t& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::TOKEN_I_CONST);
#endif
      }
    };

    /// Build a parser object.
     Parser  (WadeSpace::Scanner &scanner_yyarg, WadeSpace::Interpreter &driver_yyarg);
    virtual ~ Parser  ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
     Parser  (const  Parser &) = delete;
    /// Non copyable.
     Parser & operator= (const  Parser &) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::TOKEN_END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::TOKEN_END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::TOKEN_YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::TOKEN_YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::TOKEN_YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::TOKEN_YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFIER (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_IDENTIFIER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IDENTIFIER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_IDENTIFIER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_I_CONST (uint64_t v, location_type l)
      {
        return symbol_type (token::TOKEN_I_CONST, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_I_CONST (const uint64_t& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_I_CONST, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_F_CONST (long double v, location_type l)
      {
        return symbol_type (token::TOKEN_F_CONST, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_F_CONST (const long double& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_F_CONST, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING_LITERAL (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_STRING_LITERAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING_LITERAL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_STRING_LITERAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE_NAME (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_TYPE_NAME, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TYPE_NAME (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_TYPE_NAME, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AUTO (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_AUTO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_AUTO (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_AUTO, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BREAK (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_BREAK, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BREAK (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_BREAK, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CASE (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_CASE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CASE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_CASE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHAR (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_CHAR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CHAR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_CHAR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONST (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_CONST, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CONST (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_CONST, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONTINUE (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_CONTINUE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CONTINUE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_CONTINUE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEFAULT (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_DEFAULT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DEFAULT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_DEFAULT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DO (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_DO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DO (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_DO, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOUBLE (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_DOUBLE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DOUBLE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_DOUBLE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LONG_DOUBLE (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_LONG_DOUBLE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LONG_DOUBLE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_LONG_DOUBLE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_ELSE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_ELSE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENUM (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_ENUM, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ENUM (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_ENUM, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXTERN (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_EXTERN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EXTERN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_EXTERN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOAT (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_FLOAT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FLOAT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_FLOAT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOR (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_FOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FOR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_FOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GOTO (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_GOTO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_GOTO (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_GOTO, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_IF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_IF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INLINE (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_INLINE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INLINE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_INLINE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_INT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_INT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LONG (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_LONG, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LONG (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_LONG, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LONG_LONG (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_LONG_LONG, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LONG_LONG (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_LONG_LONG, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REGISTER (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_REGISTER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_REGISTER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_REGISTER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RESTRICT (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_RESTRICT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RESTRICT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_RESTRICT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETURN (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_RETURN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RETURN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_RETURN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SHORT (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_SHORT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SHORT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_SHORT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIGNED (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_SIGNED, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SIGNED (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_SIGNED, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIZEOF (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_SIZEOF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SIZEOF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_SIZEOF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STATIC (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_STATIC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STATIC (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_STATIC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRUCT (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_STRUCT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRUCT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_STRUCT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SWITCH (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_SWITCH, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SWITCH (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_SWITCH, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPEDEF (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_TYPEDEF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TYPEDEF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_TYPEDEF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNION (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_UNION, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_UNION (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_UNION, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNSIGNED (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_UNSIGNED, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_UNSIGNED (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_UNSIGNED, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_VOID, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_VOID (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_VOID, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOLATILE (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_VOLATILE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_VOLATILE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_VOLATILE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_WHILE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_WHILE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_WHILE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOL (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_BOOL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BOOL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_BOOL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMPLEX (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_COMPLEX, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COMPLEX (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_COMPLEX, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IMAGINARY (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_IMAGINARY, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IMAGINARY (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_IMAGINARY, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELLIPSIS (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_ELLIPSIS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ELLIPSIS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_ELLIPSIS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_QUESTION (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_QUESTION, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_QUESTION (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_QUESTION, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_SEMICOLON, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SEMICOLON (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_SEMICOLON, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OCURLY (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_OCURLY, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OCURLY (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_OCURLY, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CCURLY (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_CCURLY, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CCURLY (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_CCURLY, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_COMMA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_COMMA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_COLON, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COLON (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_COLON, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPAREN (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_OPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OPAREN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_OPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CPAREN (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_CPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CPAREN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_CPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OBRACE (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_OBRACE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OBRACE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_OBRACE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CBRACE (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_CBRACE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CBRACE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_CBRACE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PERIOD (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_PERIOD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PERIOD (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_PERIOD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TILDE (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_TILDE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TILDE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_TILDE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUAL (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_EQUAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EQUAL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_EQUAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_RIGHT_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RIGHT_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_RIGHT_ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_LEFT_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LEFT_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_LEFT_ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADD_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_ADD_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ADD_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_ADD_ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_SUB_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SUB_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_SUB_ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MUL_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_MUL_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MUL_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_MUL_ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_DIV_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DIV_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_DIV_ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_MOD_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MOD_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_MOD_ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_AND_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_AND_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_AND_ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XOR_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_XOR_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_XOR_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_XOR_ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_OR_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OR_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_OR_ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_RIGHT_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RIGHT_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_RIGHT_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_LEFT_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LEFT_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_LEFT_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INC_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_INC_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INC_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_INC_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEC_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_DEC_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DEC_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_DEC_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PTR_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_PTR_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PTR_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_PTR_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_AND_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_AND_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_AND_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_OR_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OR_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_OR_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GREATER_EQUAL (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_GREATER_EQUAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_GREATER_EQUAL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_GREATER_EQUAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESS_EQUAL (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_LESS_EQUAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LESS_EQUAL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_LESS_EQUAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GREATER (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_GREATER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_GREATER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_GREATER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESS (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_LESS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LESS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_LESS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUAL_EQUAL (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_EQUAL_EQUAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EQUAL_EQUAL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_EQUAL_EQUAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT_EQUAL (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_NOT_EQUAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NOT_EQUAL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_NOT_EQUAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_NOT_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NOT_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_NOT_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XOR_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_XOR_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_XOR_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_XOR_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BIT_AND (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_BIT_AND, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BIT_AND (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_BIT_AND, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BIT_OR (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_BIT_OR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BIT_OR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_BIT_OR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_MINUS_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_MINUS_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_PLUS_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_PLUS_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TIMES_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_TIMES_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TIMES_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_TIMES_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_DIV_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DIV_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_DIV_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_MOD_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MOD_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_MOD_OP, v, l);
      }
#endif


    class context
    {
    public:
      context (const  Parser & yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const  Parser & yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
     Parser  (const  Parser &);
    /// Non copyable.
     Parser & operator= (const  Parser &);
#endif


    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const short yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const unsigned char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const unsigned char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const unsigned char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 1667,     ///< Last index in yytable_.
      yynnts_ = 65,  ///< Number of nonterminal symbols.
      yyfinal_ = 61 ///< Termination state number.
    };


    // User arguments.
    WadeSpace::Scanner &scanner;
    WadeSpace::Interpreter &driver;

  };

  inline
   Parser ::symbol_kind_type
   Parser ::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
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
    // Last valid token kind.
    const int code_max = 347;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_abstract_declarator: // abstract_declarator
        value.copy< AbstractDeclarator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
        value.copy< AssignmentOperator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cast_expression: // cast_expression
        value.copy< CastExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_constant: // constant
        value.copy< Constant > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.copy< Declaration > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
        value.copy< DeclarationSpecifiers > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declarator: // declarator
        value.copy< Declarator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_direct_abstract_declarator: // direct_abstract_declarator
        value.copy< DirectAbstractDeclarator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_direct_declarator: // direct_declarator
        value.copy< DirectDeclarator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enum_specifier: // enum_specifier
        value.copy< EnumSpecifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.copy< Enumerator > (YY_MOVE (that.value));
        break;

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
        value.copy< Expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_init_declarator: // init_declarator
        value.copy< InitDeclarator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_initializer: // initializer
        value.copy< Initializer > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.copy< ParameterDeclaration > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
        value.copy< ParameterTypeList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pointer: // pointer
        value.copy< Pointer > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_postfix_expression: // postfix_expression
        value.copy< PostfixExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_primary_expression: // primary_expression
        value.copy< PrimaryExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
        value.copy< SpecifierQualifierList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_storage_class_specifier: // storage_class_specifier
        value.copy< StorageClassSpecifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_declaration: // struct_declaration
        value.copy< StructDeclaration > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_declarator: // struct_declarator
        value.copy< StructDeclarator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_or_union: // struct_or_union
        value.copy< StructOrUnion > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_or_union_specifier: // struct_or_union_specifier
        value.copy< StructOrUnionSpecifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_name: // type_name
        value.copy< TypeName > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_qualifier: // type_qualifier
        value.copy< TypeQualifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.copy< TypeSpecifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_unary_expression: // unary_expression
        value.copy< UnaryExpression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_F_CONST: // "f_const"
        value.copy< long double > (YY_MOVE (that.value));
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
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.copy< std::vector<Enumerator> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.copy< std::vector<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_init_declarator_list: // init_declarator_list
        value.copy< std::vector<InitDeclarator> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_initializer_list: // initializer_list
        value.copy< std::vector<Initializer> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.copy< std::vector<ParameterDeclaration> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_declaration_list: // struct_declaration_list
        value.copy< std::vector<StructDeclaration> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_declarator_list: // struct_declarator_list
        value.copy< std::vector<StructDeclarator> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_qualifier_list: // type_qualifier_list
        value.copy< std::vector<TypeQualifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identifier_list: // identifier_list
        value.copy< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_I_CONST: // "i_const"
        value.copy< uint64_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
   Parser ::symbol_kind_type
   Parser ::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
   Parser ::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
   Parser ::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_abstract_declarator: // abstract_declarator
        value.move< AbstractDeclarator > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
        value.move< AssignmentOperator > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_cast_expression: // cast_expression
        value.move< CastExpression > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_constant: // constant
        value.move< Constant > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.move< Declaration > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
        value.move< DeclarationSpecifiers > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_declarator: // declarator
        value.move< Declarator > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_direct_abstract_declarator: // direct_abstract_declarator
        value.move< DirectAbstractDeclarator > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_direct_declarator: // direct_declarator
        value.move< DirectDeclarator > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_enum_specifier: // enum_specifier
        value.move< EnumSpecifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.move< Enumerator > (YY_MOVE (s.value));
        break;

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
        value.move< Expression > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_init_declarator: // init_declarator
        value.move< InitDeclarator > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_initializer: // initializer
        value.move< Initializer > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.move< ParameterDeclaration > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
        value.move< ParameterTypeList > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_pointer: // pointer
        value.move< Pointer > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_postfix_expression: // postfix_expression
        value.move< PostfixExpression > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_primary_expression: // primary_expression
        value.move< PrimaryExpression > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
        value.move< SpecifierQualifierList > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_storage_class_specifier: // storage_class_specifier
        value.move< StorageClassSpecifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_struct_declaration: // struct_declaration
        value.move< StructDeclaration > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_struct_declarator: // struct_declarator
        value.move< StructDeclarator > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_struct_or_union: // struct_or_union
        value.move< StructOrUnion > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_struct_or_union_specifier: // struct_or_union_specifier
        value.move< StructOrUnionSpecifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_type_name: // type_name
        value.move< TypeName > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_type_qualifier: // type_qualifier
        value.move< TypeQualifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.move< TypeSpecifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_unary_expression: // unary_expression
        value.move< UnaryExpression > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_F_CONST: // "f_const"
        value.move< long double > (YY_MOVE (s.value));
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
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.move< std::vector<Enumerator> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.move< std::vector<Expression> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_init_declarator_list: // init_declarator_list
        value.move< std::vector<InitDeclarator> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_initializer_list: // initializer_list
        value.move< std::vector<Initializer> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.move< std::vector<ParameterDeclaration> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_struct_declaration_list: // struct_declaration_list
        value.move< std::vector<StructDeclaration> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_struct_declarator_list: // struct_declarator_list
        value.move< std::vector<StructDeclarator> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_type_qualifier_list: // type_qualifier_list
        value.move< std::vector<TypeQualifier> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_identifier_list: // identifier_list
        value.move< std::vector<std::string> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_I_CONST: // "i_const"
        value.move< uint64_t > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
   Parser ::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
   Parser ::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
   Parser ::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
   Parser ::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  inline
  void
   Parser ::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
   Parser ::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
   Parser ::symbol_kind_type
   Parser ::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  inline
   Parser ::symbol_kind_type
   Parser ::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


#line 9 "parser.y"
} //  WadeSpace 
#line 4799 "parser.hpp"




#endif // !YY_YY_PARSER_HPP_INCLUDED
