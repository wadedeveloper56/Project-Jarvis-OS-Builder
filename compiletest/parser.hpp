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
    #include "command.h"

    using namespace std;

    namespace WadeSpace {
        class Scanner;
        class Interpreter;
    }

#line 65 "parser.hpp"

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
#line 206 "parser.hpp"




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
      // "f_const"
      char dummy1[sizeof (long double)];

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
      // "semicolon"
      // "ocurly"
      // "ccurly"
      // "comma"
      // "colon"
      // "oparen"
      // "cparen"
      // "obrace"
      // "cbrace"
      // "period"
      // "tilde"
      // "equal op"
      // "right assign"
      // "left assign"
      // "add assign"
      // "sub assign"
      // "mul assign"
      // "div assign"
      // "mod assign"
      // "and assign"
      // "xor assign"
      // "or assign"
      // "right op"
      // "left op"
      // "inc op"
      // "dec op"
      // "ptr op"
      // "and op"
      // "or op"
      // "ge op"
      // "le op"
      // "greater op"
      // "less op"
      // "eq op"
      // "ne op"
      // "not op"
      // "xor op"
      // "bit and"
      // "bit or"
      // "minus op"
      // "plus op"
      // "times op"
      // "div op"
      // "mod op"
      char dummy2[sizeof (std::string)];

      // "i_const"
      char dummy3[sizeof (uint64_t)];
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
    TOKEN_SEMICOLON = 304,         // "semicolon"
    TOKEN_OCURLY = 305,            // "ocurly"
    TOKEN_CCURLY = 306,            // "ccurly"
    TOKEN_COMMA = 307,             // "comma"
    TOKEN_COLON = 308,             // "colon"
    TOKEN_OPAREN = 309,            // "oparen"
    TOKEN_CPAREN = 310,            // "cparen"
    TOKEN_OBRACE = 311,            // "obrace"
    TOKEN_CBRACE = 312,            // "cbrace"
    TOKEN_PERIOD = 313,            // "period"
    TOKEN_TILDE = 314,             // "tilde"
    TOKEN_EQUAL_OP = 315,          // "equal op"
    TOKEN_RIGHT_ASSIGN = 316,      // "right assign"
    TOKEN_LEFT_ASSIGN = 317,       // "left assign"
    TOKEN_ADD_ASSIGN = 318,        // "add assign"
    TOKEN_SUB_ASSIGN = 319,        // "sub assign"
    TOKEN_MUL_ASSIGN = 320,        // "mul assign"
    TOKEN_DIV_ASSIGN = 321,        // "div assign"
    TOKEN_MOD_ASSIGN = 322,        // "mod assign"
    TOKEN_AND_ASSIGN = 323,        // "and assign"
    TOKEN_XOR_ASSIGN = 324,        // "xor assign"
    TOKEN_OR_ASSIGN = 325,         // "or assign"
    TOKEN_RIGHT_OP = 326,          // "right op"
    TOKEN_LEFT_OP = 327,           // "left op"
    TOKEN_INC_OP = 328,            // "inc op"
    TOKEN_DEC_OP = 329,            // "dec op"
    TOKEN_PTR_OP = 330,            // "ptr op"
    TOKEN_AND_OP = 331,            // "and op"
    TOKEN_OR_OP = 332,             // "or op"
    TOKEN_GE_OP = 333,             // "ge op"
    TOKEN_LE_OP = 334,             // "le op"
    TOKEN_GREATER_OP = 335,        // "greater op"
    TOKEN_LESS_OP = 336,           // "less op"
    TOKEN_EQ_OP = 337,             // "eq op"
    TOKEN_NE_OP = 338,             // "ne op"
    TOKEN_NOT_OP = 339,            // "not op"
    TOKEN_XOR_OP = 340,            // "xor op"
    TOKEN_BIT_AND = 341,           // "bit and"
    TOKEN_BIT_OR = 342,            // "bit or"
    TOKEN_MINUS_OP = 343,          // "minus op"
    TOKEN_PLUS_OP = 344,           // "plus op"
    TOKEN_TIMES_OP = 345,          // "times op"
    TOKEN_DIV_OP = 346,            // "div op"
    TOKEN_MOD_OP = 347             // "mod op"
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
        YYNTOKENS = 117, ///< Number of tokens.
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
        S_SEMICOLON = 49,                        // "semicolon"
        S_OCURLY = 50,                           // "ocurly"
        S_CCURLY = 51,                           // "ccurly"
        S_COMMA = 52,                            // "comma"
        S_COLON = 53,                            // "colon"
        S_OPAREN = 54,                           // "oparen"
        S_CPAREN = 55,                           // "cparen"
        S_OBRACE = 56,                           // "obrace"
        S_CBRACE = 57,                           // "cbrace"
        S_PERIOD = 58,                           // "period"
        S_TILDE = 59,                            // "tilde"
        S_EQUAL_OP = 60,                         // "equal op"
        S_RIGHT_ASSIGN = 61,                     // "right assign"
        S_LEFT_ASSIGN = 62,                      // "left assign"
        S_ADD_ASSIGN = 63,                       // "add assign"
        S_SUB_ASSIGN = 64,                       // "sub assign"
        S_MUL_ASSIGN = 65,                       // "mul assign"
        S_DIV_ASSIGN = 66,                       // "div assign"
        S_MOD_ASSIGN = 67,                       // "mod assign"
        S_AND_ASSIGN = 68,                       // "and assign"
        S_XOR_ASSIGN = 69,                       // "xor assign"
        S_OR_ASSIGN = 70,                        // "or assign"
        S_RIGHT_OP = 71,                         // "right op"
        S_LEFT_OP = 72,                          // "left op"
        S_INC_OP = 73,                           // "inc op"
        S_DEC_OP = 74,                           // "dec op"
        S_PTR_OP = 75,                           // "ptr op"
        S_AND_OP = 76,                           // "and op"
        S_OR_OP = 77,                            // "or op"
        S_GE_OP = 78,                            // "ge op"
        S_LE_OP = 79,                            // "le op"
        S_GREATER_OP = 80,                       // "greater op"
        S_LESS_OP = 81,                          // "less op"
        S_EQ_OP = 82,                            // "eq op"
        S_NE_OP = 83,                            // "ne op"
        S_NOT_OP = 84,                           // "not op"
        S_XOR_OP = 85,                           // "xor op"
        S_BIT_AND = 86,                          // "bit and"
        S_BIT_OR = 87,                           // "bit or"
        S_MINUS_OP = 88,                         // "minus op"
        S_PLUS_OP = 89,                          // "plus op"
        S_TIMES_OP = 90,                         // "times op"
        S_DIV_OP = 91,                           // "div op"
        S_MOD_OP = 92,                           // "mod op"
        S_93_ = 93,                              // '['
        S_94_ = 94,                              // ']'
        S_95_ = 95,                              // '('
        S_96_ = 96,                              // ')'
        S_97_ = 97,                              // '.'
        S_98_ = 98,                              // ','
        S_99_ = 99,                              // '&'
        S_100_ = 100,                            // '*'
        S_101_ = 101,                            // '+'
        S_102_ = 102,                            // '-'
        S_103_ = 103,                            // '~'
        S_104_ = 104,                            // '!'
        S_105_ = 105,                            // '/'
        S_106_ = 106,                            // '%'
        S_107_ = 107,                            // '<'
        S_108_ = 108,                            // '>'
        S_109_ = 109,                            // '^'
        S_110_ = 110,                            // '|'
        S_111_ = 111,                            // '?'
        S_112_ = 112,                            // ':'
        S_113_ = 113,                            // '='
        S_114_ = 114,                            // ';'
        S_115_ = 115,                            // '{'
        S_116_ = 116,                            // '}'
        S_YYACCEPT = 117,                        // $accept
        S_primary_expression = 118,              // primary_expression
        S_constant = 119,                        // constant
        S_postfix_expression = 120,              // postfix_expression
        S_argument_expression_list = 121,        // argument_expression_list
        S_unary_expression = 122,                // unary_expression
        S_unary_operator = 123,                  // unary_operator
        S_cast_expression = 124,                 // cast_expression
        S_multiplicative_expression = 125,       // multiplicative_expression
        S_additive_expression = 126,             // additive_expression
        S_shift_expression = 127,                // shift_expression
        S_relational_expression = 128,           // relational_expression
        S_equality_expression = 129,             // equality_expression
        S_and_expression = 130,                  // and_expression
        S_exclusive_or_expression = 131,         // exclusive_or_expression
        S_inclusive_or_expression = 132,         // inclusive_or_expression
        S_logical_and_expression = 133,          // logical_and_expression
        S_logical_or_expression = 134,           // logical_or_expression
        S_conditional_expression = 135,          // conditional_expression
        S_assignment_expression = 136,           // assignment_expression
        S_assignment_operator = 137,             // assignment_operator
        S_expression = 138,                      // expression
        S_constant_expression = 139,             // constant_expression
        S_declaration = 140,                     // declaration
        S_declaration_specifiers = 141,          // declaration_specifiers
        S_init_declarator_list = 142,            // init_declarator_list
        S_init_declarator = 143,                 // init_declarator
        S_storage_class_specifier = 144,         // storage_class_specifier
        S_type_specifier = 145,                  // type_specifier
        S_struct_or_union_specifier = 146,       // struct_or_union_specifier
        S_struct_or_union = 147,                 // struct_or_union
        S_struct_declaration_list = 148,         // struct_declaration_list
        S_struct_declaration = 149,              // struct_declaration
        S_specifier_qualifier_list = 150,        // specifier_qualifier_list
        S_struct_declarator_list = 151,          // struct_declarator_list
        S_struct_declarator = 152,               // struct_declarator
        S_enum_specifier = 153,                  // enum_specifier
        S_enumerator_list = 154,                 // enumerator_list
        S_enumerator = 155,                      // enumerator
        S_type_qualifier = 156,                  // type_qualifier
        S_declarator = 157,                      // declarator
        S_direct_declarator = 158,               // direct_declarator
        S_pointer = 159,                         // pointer
        S_type_qualifier_list = 160,             // type_qualifier_list
        S_parameter_type_list = 161,             // parameter_type_list
        S_parameter_list = 162,                  // parameter_list
        S_parameter_declaration = 163,           // parameter_declaration
        S_identifier_list = 164,                 // identifier_list
        S_type_name = 165,                       // type_name
        S_abstract_declarator = 166,             // abstract_declarator
        S_direct_abstract_declarator = 167,      // direct_abstract_declarator
        S_initializer = 168,                     // initializer
        S_initializer_list = 169,                // initializer_list
        S_statement = 170,                       // statement
        S_labeled_statement = 171,               // labeled_statement
        S_compound_statement = 172,              // compound_statement
        S_declaration_list = 173,                // declaration_list
        S_statement_list = 174,                  // statement_list
        S_expression_statement = 175,            // expression_statement
        S_selection_statement = 176,             // selection_statement
        S_iteration_statement = 177,             // iteration_statement
        S_jump_statement = 178,                  // jump_statement
        S_translation_unit = 179,                // translation_unit
        S_external_declaration = 180,            // external_declaration
        S_function_definition = 181              // function_definition
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
        value.move< std::string > (std::move (that.value));
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
        value.template destroy< std::string > ();
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
                   || (token::TOKEN_YYerror <= tok && tok <= token::TOKEN_YYUNDEF)
                   || tok == 91
                   || tok == 93
                   || (40 <= tok && tok <= 41)
                   || tok == 46
                   || tok == 44
                   || tok == 38
                   || (42 <= tok && tok <= 43)
                   || tok == 45
                   || tok == 126
                   || tok == 33
                   || tok == 47
                   || tok == 37
                   || tok == 60
                   || tok == 62
                   || tok == 94
                   || tok == 124
                   || tok == 63
                   || tok == 58
                   || tok == 61
                   || tok == 59
                   || tok == 123
                   || tok == 125);
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
      make_EQUAL_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_EQUAL_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EQUAL_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_EQUAL_OP, v, l);
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
      make_GE_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_GE_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_GE_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_GE_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LE_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_LE_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LE_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_LE_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GREATER_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_GREATER_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_GREATER_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_GREATER_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESS_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_LESS_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LESS_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_LESS_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQ_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_EQ_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EQ_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_EQ_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NE_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_NE_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NE_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_NE_OP, v, l);
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
      yylast_ = 1505,     ///< Last index in yytable_.
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
       2,     2,     2,   104,     2,     2,     2,   106,    99,     2,
      95,    96,   100,   101,    98,   102,    97,   105,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   112,   114,
     107,   113,   108,   111,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    93,     2,    94,   109,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   115,   110,   116,   103,     2,     2,     2,
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
        value.copy< std::string > (YY_MOVE (that.value));
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
        value.move< std::string > (YY_MOVE (s.value));
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
#line 3492 "parser.hpp"




#endif // !YY_YY_PARSER_HPP_INCLUDED
