%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.0"
%defines
%define  api.parser.class { Parser }

%define api.token.constructor
%define api.value.type variant
%define parse.assert
%define api.namespace { WadeSpace }
%code requires
{
    #include <iostream>
    #include <string>
    #include <vector>
    #include <stdint.h>
    #include <stdlib.h>
    #include "Constant.h"
    #include "AssignmentOperator.h"
    #include "StorageClassSpecifier.h"
    #include "TypeSpecifier.h"
    #include "Enumerator.h"
    #include "EnumSpecifier.h"
    #include "Expression.h"

    using namespace std;

    namespace WadeSpace {
        class Scanner;
        class Interpreter;
    }
}

// Bison calls yylex() function that must be provided by us to suck tokens
// from the scanner. This block will be placed at the beginning of IMPLEMENTATION file (cpp).
// We define this function here (function! not method).
// This function is called only inside Bison, so we make it static to limit symbol visibility for the linker
// to avoid potential linking conflicts.
%code top
{
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
}

%lex-param { WadeSpace::Scanner &scanner }
%lex-param { WadeSpace::Interpreter &driver }
%parse-param { WadeSpace::Scanner &scanner }
%parse-param { WadeSpace::Interpreter &driver }
%locations
%define parse.trace
%define parse.error verbose

%define api.token.prefix {TOKEN_}

%token END 0 "end of file"
%token <std::string> IDENTIFIER  "identifier"
%token <uint64_t> I_CONST "i_const"
%token <long double> F_CONST "f_const"
%token <std::string> STRING_LITERAL  "sting_literal"
%token <std::string> TYPE_NAME "type name"
%token <std::string> AUTO "auto"
%token <std::string> BREAK "break"
%token <std::string> CASE "case"
%token <std::string> CHAR "char"
%token <std::string> CONST "const"
%token <std::string> CONTINUE "continue"
%token <std::string> DEFAULT "default"
%token <std::string> DO "do"
%token <std::string> DOUBLE "double"
%token <std::string> LONG_DOUBLE "long double"
%token <std::string> ELSE "else"
%token <std::string> ENUM "enum"
%token <std::string> EXTERN "extern"
%token <std::string> FLOAT "float"
%token <std::string> FOR "for"
%token <std::string> GOTO "goto"
%token <std::string> IF "if"
%token <std::string> INLINE "inline"
%token <std::string> INT "int"
%token <std::string> LONG "long"
%token <std::string> LONG_LONG "long long"
%token <std::string> REGISTER "register"
%token <std::string> RESTRICT "restrict"
%token <std::string> RETURN "return"
%token <std::string> SHORT "short"
%token <std::string> SIGNED "signed"
%token <std::string> SIZEOF "sizeof"
%token <std::string> STATIC "static"
%token <std::string> STRUCT "struct"
%token <std::string> SWITCH "switch"
%token <std::string> TYPEDEF "typedef"
%token <std::string> UNION "union"
%token <std::string> UNSIGNED "unsigned"
%token <std::string> VOID "void"
%token <std::string> VOLATILE "volatile"
%token <std::string> WHILE "while"
%token <std::string> BOOL "bool"
%token <std::string> COMPLEX "complex"
%token <std::string> IMAGINARY "imaginary"
%token <std::string> ELLIPSIS "ellipsis"
%token <std::string> QUESTION "question"
%token <std::string> SEMICOLON ";"
%token <std::string> OCURLY "{"
%token <std::string> CCURLY "}"
%token <std::string> COMMA ","
%token <std::string> COLON ":"
%token <std::string> OPAREN "("
%token <std::string> CPAREN ")"
%token <std::string> OBRACE "["
%token <std::string> CBRACE "]"
%token <std::string> PERIOD "."
%token <std::string> TILDE "~"
%token <std::string> EQUAL_OP "="
%token <std::string> RIGHT_ASSIGN ">>="
%token <std::string> LEFT_ASSIGN "<<="
%token <std::string> ADD_ASSIGN "+="
%token <std::string> SUB_ASSIGN "-="
%token <std::string> MUL_ASSIGN "*="
%token <std::string> DIV_ASSIGN "/="
%token <std::string> MOD_ASSIGN "%="
%token <std::string> AND_ASSIGN "&="
%token <std::string> XOR_ASSIGN "^="
%token <std::string> OR_ASSIGN "|="
%token <std::string> RIGHT_OP ">>"
%token <std::string> LEFT_OP "<<"
%token <std::string> INC_OP "++"
%token <std::string> DEC_OP "--"
%token <std::string> PTR_OP "->"
%token <std::string> AND_OP "&&"
%token <std::string> OR_OP "||"
%token <std::string> GREATER_EQUAL_OP ">="
%token <std::string> LESS_EQUAL_OP "<="
%token <std::string> GREATER_OP ">"
%token <std::string> LESS_OP "<"
%token <std::string> EQUAL_EQUAL_OP "=="
%token <std::string> NOT_EQUAL_OP "!="
%token <std::string> NOT_OP "!"
%token <std::string> XOR_OP "^"
%token <std::string> BIT_AND "&"
%token <std::string> BIT_OR "|"
%token <std::string> MINUS_OP "-"
%token <std::string> PLUS_OP "+"
%token <std::string> TIMES_OP "*"
%token <std::string> DIV_OP "/"
%token <std::string> MOD_OP "%"

%type<Constant> constant
%type<std::vector<Expression>> argument_expression_list
%type<Expression> primary_expression
%type<Expression> expression
%type<Expression> postfix_expression
%type<Expression> unary_expression
%type<Expression> cast_expression
%type<Expression> multiplicative_expression
%type<Expression> additive_expression
%type<Expression> shift_expression
%type<Expression> relational_expression
%type<Expression> equality_expression
%type<Expression> and_expression
%type<Expression> exclusive_or_expression
%type<Expression> inclusive_or_expression
%type<Expression> logical_and_expression
%type<Expression> logical_or_expression
%type<Expression> conditional_expression
%type<Expression> assignment_expression
%type<Expression> constant_expression
%type<std::string> unary_operator
%type<AssignmentOperator> assignment_operator
%type<StorageClassSpecifier> storage_class_specifier
%type<TypeSpecifier> type_specifier
%type<Enumerator> enumerator
%type<std::vector<Enumerator>> enumerator_list
%type<EnumSpecifier> enum_specifier

%start translation_unit

%%

primary_expression
    : IDENTIFIER { $<Expression>$ = Expression($1); cout << "IDENTIFIER REDUCE to primary_expression" << endl; }
    | constant { $<Expression>$ = Expression(&$1); cout << "constant REDUCE to primary_expression" << endl; }
    | OPAREN expression CPAREN  { $<Expression>$ = $2; cout << "(expression) REDUCE to primary_expression" << endl; }
    ;

constant
    : F_CONST {
                 long double &id = $1;
                 cout << "F_CONST REDUCE to constant " << id << endl;
                 $<Constant>$ = Constant(id);
              }
    | I_CONST {
                 std::uint64_t &id = $1;
                 cout << "I_CONST REDUCE to constant " << id << endl;
                 $<Constant>$ = Constant(id);
              }
    | STRING_LITERAL  {
                 std::string &id = $1;
                 cout << "STRING_LITERAL REDUCE to constant  " << id << endl;
                 $<Constant>$ = Constant(id);
              }

postfix_expression
    : primary_expression                                           { $<Expression>$ = $1; cout << "primary_expression REDUCE to postfix_expression" << endl; }
    | postfix_expression OBRACE expression CBRACE                  { cout << "postfix_expression OBRACE expression CBRACE REDUCE to postfix_expression" << endl; }
    | postfix_expression OPAREN CPAREN                             { cout << "postfix_expression OPAREN CPAREN REDUCE to postfix_expression" << endl; }
    | postfix_expression OPAREN argument_expression_list CPAREN    { cout << "postfix_expression OPAREN argument_expression_list CPAREN REDUCE to postfix_expression" << endl; }
    | postfix_expression PERIOD IDENTIFIER                         { cout << "postfix_expression PERIOD_OP IDENTIFIER REDUCE to postfix_expression" << endl; }
    | postfix_expression PTR_OP IDENTIFIER                         { cout << "postfix_expression PTR_OP IDENTIFIER REDUCE to postfix_expression" << endl; }
    | postfix_expression INC_OP                                    { cout << "postfix_expression INC_OP REDUCE to postfix_expression" << endl; }
    | postfix_expression DEC_OP                                    { cout << "postfix_expression DEC_OP REDUCE to postfix_expression" << endl; }
    | OPAREN type_name CPAREN OCURLY initializer_list CCURLY       { cout << "OPAREN type_name CPAREN_OP OCURLY_OP initializer_list CCURLY REDUCE to postfix_expression" << endl; }
    | OPAREN type_name CPAREN OCURLY initializer_list COMMA CCURLY { cout << "OPAREN type_name CPAREN_OP OCURLY_OP initializer_list COMMA CCURLY REDUCE to postfix_expression" << endl; }


argument_expression_list
    : assignment_expression {
                             Expression exp = $1;
                             $$ = std::vector<Expression>();
                             $$.push_back(exp);
                             cout << "assignment_expression REDUCE argument_expression_list" << endl;
                            }
    | argument_expression_list COMMA assignment_expression {
            Expression value1 = $3;
            std::vector<Expression> &value2 = $1;
            value2.push_back(value1);
            $$ = value2;
            cout << "argument_expression_list COMMA assignment_expression REDUCE argument_expression_list" << endl;
        }
    ;

unary_expression
    : postfix_expression { $<Expression>$ = $1; cout << "postfix_expression REDUCE unary_expression" << endl;}
    | INC_OP unary_expression { $<Expression>$ = Expression($1,&$2); cout << "INC_OP unary_expression REDUCE unary_expression" << endl;}
    | DEC_OP unary_expression { $<Expression>$ = Expression($1,&$2); cout << "DEC_OP unary_expression REDUCE unary_expression" << endl;}
    | unary_operator cast_expression { $<Expression>$ = Expression($1,&$2); cout << "unary_operator cast_expression REDUCE unary_expression" << endl;}
    | SIZEOF unary_expression { $<Expression>$ = Expression(); cout << "SIZEOF unary_expression REDUCE unary_expression" << endl;}
    | SIZEOF OPAREN type_name CPAREN { $<Expression>$ = Expression(); cout << "SIZEOF OPAREN type_name CPAREN REDUCE unary_expression" << endl;}
    ;

unary_operator
    : BIT_AND   {$<std::string>$ = $1; cout << "BIT_AND REDUCE to unary_operator" << endl;}
    | TIMES_OP  {$<std::string>$ = $1; cout << "TIMES_OP REDUCE to unary_operator" << endl;}
    | PLUS_OP   {$<std::string>$ = $1; cout << "PLUS_OP REDUCE to unary_operator" << endl;}
    | MINUS_OP  {$<std::string>$ = $1; cout << "MINUS_OP REDUCE to unary_operator" << endl;}
    | TILDE     {$<std::string>$ = $1; cout << "TILDE REDUCE to unary_operator" << endl;}
    | NOT_OP    {$<std::string>$ = $1; cout << "NOT_OP REDUCE to unary_operator" << endl;}
    ;

cast_expression
    : unary_expression  { $<Expression>$ = $1;  cout << "unary_expression REDUCE to cast_expression" << endl;}
    | OPAREN type_name CPAREN cast_expression  { $<Expression>$ = $4;  cout << "unary_expression REDUCE to cast_expression" << endl;}
    ;

multiplicative_expression
    : cast_expression  { $<Expression>$ = $1;  cout << "cast_expression REDUCE to multiplicative_expression" << endl;}
    | multiplicative_expression TIMES_OP cast_expression { cout << "multiplicative_expression TIMES_OP cast_expression REDUCE to multiplicative_expression" << endl;}
    | multiplicative_expression DIV_OP cast_expression{ cout << "multiplicative_expression DIV_OP cast_expression REDUCE to multiplicative_expression" << endl;}
    | multiplicative_expression MOD_OP cast_expression{ cout << "multiplicative_expression MOD_OP cast_expression REDUCE to multiplicative_expression" << endl;}
    ;

additive_expression
    : multiplicative_expression  { $<Expression>$ = $1;  cout << "multiplicative_expression REDUCE to additive_expression" << endl;}
    | additive_expression PLUS_OP multiplicative_expression  { cout << "additive_expression REDUCE to multiplicative_expression" << endl;}
    | additive_expression MINUS_OP multiplicative_expression  { cout << "additive_expression REDUCE to multiplicative_expression" << endl;}
    ;

shift_expression
    : additive_expression  { $<Expression>$ = $1;  cout << "additive_expression REDUCE to shift_expression" << endl;}
    | shift_expression LEFT_OP additive_expression{ cout << "shift_expression LEFT_OP additive_expression REDUCE to shift_expression" << endl;}
    | shift_expression RIGHT_OP additive_expression{ cout << "shift_expression RIGHT_OP additive_expression REDUCE to shift_expression" << endl;}
    ;

relational_expression
    : shift_expression  { $<Expression>$ = $1;  cout << "shift_expression REDUCE to relational_expression" << endl;}
    | relational_expression LESS_OP shift_expression   { cout << "relational_expression LESS_OP shift_expression REDUCE to shift_expression" << endl;}
    | relational_expression GREATER_OP shift_expression    { cout << "relational_expression GREATER_OP shift_expression REDUCE to shift_expression" << endl;}
    | relational_expression LESS_EQUAL_OP shift_expression   { cout << "relational_expression LESS_EQUAL_OP shift_expression REDUCE to shift_expression" << endl;}
    | relational_expression GREATER_EQUAL_OP shift_expression   { cout << "relational_expression GREATER_EQUAL_OP shift_expression REDUCE to shift_expression" << endl;}
    ;

equality_expression
    : relational_expression  { $<Expression>$ = $1;  cout << "relational_expression REDUCE to equality_expression" << endl;}
    | equality_expression EQUAL_EQUAL_OP relational_expression  { cout << "equality_expression EQUAL_EQUAL_OP relational_expression REDUCE to equality_expression" << endl;}
    | equality_expression NOT_EQUAL_OP relational_expression  { cout << "equality_expression NOT_EQUAL_OP relational_expression REDUCE to equality_expression" << endl;}
    ;

and_expression
    : equality_expression  { $<Expression>$ = $1;  cout << "equality_expression REDUCE to and_expression" << endl;}
    | and_expression BIT_AND equality_expression  { cout << "and_expression BIT_AND equality_expression REDUCE to and_expression" << endl;}
    ;

exclusive_or_expression
    : and_expression  { $<Expression>$ = $1;  cout << "and_expression REDUCE to exclusive_or_expression" << endl;}
    | exclusive_or_expression XOR_OP and_expression  { cout << "exclusive_or_expression XOR_OP and_expression REDUCE to exclusive_or_expression" << endl;}
    ;

inclusive_or_expression
    : exclusive_or_expression  { $<Expression>$ = $1;  cout << "exclusive_or_expression REDUCE to inclusive_or_expression" << endl;}
    | inclusive_or_expression BIT_OR exclusive_or_expression { cout << "inclusive_or_expression BIT_OR exclusive_or_expression REDUCE to inclusive_or_expression" << endl;}
    ;

logical_and_expression
    : inclusive_or_expression  { $<Expression>$ = $1;  cout << "inclusive_or_expression REDUCE to logical_and_expression" << endl;}
    | logical_and_expression AND_OP inclusive_or_expression  { cout << "inclusive_or_expression REDUCE to logical_and_expression" << endl;}
    ;

logical_or_expression
    : logical_and_expression  { $<Expression>$ = $1;  cout << "inclusive_and_expression REDUCE to logical_or_expression" << endl;}
    | logical_or_expression OR_OP logical_and_expression  { cout << "logical_or_expression OR_OP logical_and_expression REDUCE to logical_or_expression" << endl;}
    ;

conditional_expression
    : logical_or_expression  { $<Expression>$ = $1;  cout << "logical_or_expression REDUCE to conditional_expression" << endl;}
    | logical_or_expression QUESTION expression COLON conditional_expression  { cout << "logical_or_expression QUESTION expression COLON conditional_expression REDUCE to conditional_expression" << endl;}
    ;

assignment_expression
    : conditional_expression  { $<Expression>$ = $1;  cout << "conditional_expression REDUCE to assignment_expression" << endl;}
    | unary_expression assignment_operator assignment_expression  { cout << "unary_expression assignment_operator assignment_expression REDUCE to assignment_expression" << endl;}
    ;

assignment_operator
    : EQUAL_OP       { $<AssignmentOperator>$ = AssignmentOperator($1,EQUAL_OP);  cout << "EQUAL_OP REDUCE to assignment_operator" << endl;}
    | MUL_ASSIGN     { $<AssignmentOperator>$ = AssignmentOperator($1,MUL_ASSIGN);  cout << "MUL_ASSIGN REDUCE to assignment_operator" << endl;}
    | DIV_ASSIGN     { $<AssignmentOperator>$ = AssignmentOperator($1,DIV_ASSIGN);  cout << "DIV_ASSIGN REDUCE to assignment_operator" << endl;}
    | MOD_ASSIGN     { $<AssignmentOperator>$ = AssignmentOperator($1,MOD_ASSIGN);  cout << "MOG_ASSIGN REDUCE to assignment_operator" << endl;}
    | ADD_ASSIGN     { $<AssignmentOperator>$ = AssignmentOperator($1,ADD_ASSIGN);  cout << "ADD_ASSIGN REDUCE to assignment_operator" << endl;}
    | SUB_ASSIGN     { $<AssignmentOperator>$ = AssignmentOperator($1,SUB_ASSIGN);  cout << "SUB_ASSIGN REDUCE to assignment_operator" << endl;}
    | LEFT_ASSIGN    { $<AssignmentOperator>$ = AssignmentOperator($1,LEFT_ASSIGN);  cout << "LEFT_ASSIGN REDUCE to assignment_operator" << endl;}
    | RIGHT_ASSIGN   { $<AssignmentOperator>$ = AssignmentOperator($1,RIGHT_ASSIGN);  cout << "RIGHT_ASSIGN REDUCE to assignment_operator" << endl;}
    | AND_ASSIGN     { $<AssignmentOperator>$ = AssignmentOperator($1,AND_ASSIGN);  cout << "AND_ASSIGN REDUCE to assignment_operator" << endl;}
    | XOR_ASSIGN     { $<AssignmentOperator>$ = AssignmentOperator($1,XOR_ASSIGN);  cout << "XOR_ASSIGN REDUCE to assignment_operator" << endl;}
    | OR_ASSIGN      { $<AssignmentOperator>$ = AssignmentOperator($1,OR_ASSIGN);  cout << "OR_ASSIGN REDUCE to assignment_operator" << endl;}
    ;

expression
    : assignment_expression  { $<Expression>$ = $1;  cout << "asignment_expression REDUCE to expression" << endl;}
    | expression COMMA assignment_expression  { cout << "expression COMMA assignment_expression COMMA  REDUCE to expression" << endl;}
    ;

constant_expression
    : conditional_expression  { $<Expression>$ = $1;  cout << "conditional_expression REDUCE to constant_expression" << endl;}
    ;

declaration
    : declaration_specifiers SEMICOLON  { cout << "declaration_specifiers SEMICOLON REDUCE to declaration" << endl;}
    | declaration_specifiers init_declarator_list SEMICOLON  { cout << "declaration_specifiers init_declarator_list SEMICOLON REDUCE to declaration" << endl;}
    ;

declaration_specifiers
    : storage_class_specifier                         { cout << "storage_class_specifier REDUCE to declaration_specifiers" << endl;}
    | storage_class_specifier declaration_specifiers  { cout << "storage_class_specifier declaration_specifiers REDUCE to declaration_specifiers" << endl;}
    | type_specifier                                  { cout << "type_specifier REDUCE to declaration_specifiers" << endl;}
    | type_specifier declaration_specifiers           { cout << "type_specifier declaration_specifiers REDUCE to declaration_specifiers" << endl;}
    | type_qualifier                                  { cout << "type_qualifier REDUCE to declaration_specifiers" << endl;}
    | type_qualifier declaration_specifiers           { cout << "type_qualifier declaration_specifiers REDUCE to declaration_specifiers" << endl;}
    ;

init_declarator_list
    : init_declarator                            { cout << "init_declarator REDUCE to init_declarator_list" << endl;}
    | init_declarator_list COMMA init_declarator { cout << "init_declarator_list COMMA init_declarator REDUCE to init_declarator_list" << endl;}
    ;

init_declarator
    : declarator                       { cout << "declarator REDUCE to init_declarator" << endl;}
    | declarator EQUAL_OP initializer  { cout << "declarator EQUAL_OP initializer REDUCE to init_declarator" << endl;}
    ;

storage_class_specifier
    : TYPEDEF   { $<StorageClassSpecifier>$ = StorageClassSpecifier($1,TYPEDEF); cout << "TYPEDEF REDUCE to storage_class_specifier" << endl;}
    | EXTERN    { $<StorageClassSpecifier>$ = StorageClassSpecifier($1,EXTERN); cout << "EXTERN REDUCE to storage_class_specifier" << endl;}
    | STATIC    { $<StorageClassSpecifier>$ = StorageClassSpecifier($1,STATIC); cout << "STATIC REDUCE to storage_class_specifier" << endl;}
    | AUTO      { $<StorageClassSpecifier>$ = StorageClassSpecifier($1,AUTO); cout << "AUTO REDUCE to storage_class_specifier" << endl;}
    | REGISTER  { $<StorageClassSpecifier>$ = StorageClassSpecifier($1,REGISTER); cout << "REGISTER REDUCE to storage_class_specifier" << endl;}
    ;

type_specifier
    : VOID                      { $<TypeSpecifier>$ = TypeSpecifier($1,VOID); cout << "VOID REDUCE to type_specifier" << endl;}
    | CHAR                      { $<TypeSpecifier>$ = TypeSpecifier($1,CHAR); cout << "CHAR REDUCE to type_specifier" << endl;}
    | SHORT                     { $<TypeSpecifier>$ = TypeSpecifier($1,SHORT); cout << "SHORT REDUCE to type_specifier" << endl;}
    | INT                       { $<TypeSpecifier>$ = TypeSpecifier($1,INT); cout << "INT REDUCE to type_specifier" << endl;}
    | LONG                      { $<TypeSpecifier>$ = TypeSpecifier($1,LONG); cout << "LONG REDUCE to type_specifier" << endl;}
    | FLOAT                     { $<TypeSpecifier>$ = TypeSpecifier($1,FLOAT); cout << "FLOAT REDUCE to type_specifier" << endl;}
    | DOUBLE                    { $<TypeSpecifier>$ = TypeSpecifier($1,DOUBLE); cout << "DOUBLE REDUCE to type_specifier" << endl;}
    | SIGNED                    { $<TypeSpecifier>$ = TypeSpecifier($1,SIGNED); cout << "SIGNED REDUCE to type_specifier" << endl;}
    | UNSIGNED                  { $<TypeSpecifier>$ = TypeSpecifier($1,UNSIGNED); cout << "UNIGNED REDUCE to type_specifier" << endl;}
    | struct_or_union_specifier { $<TypeSpecifier>$ = TypeSpecifier(); cout << "struct_or_union_specifier REDUCE to type_specifier" << endl;}
    | enum_specifier            { $<TypeSpecifier>$ = TypeSpecifier();/*"enum_specifier",&$1);*/ cout << "enum_specifier REDUCE to type_specifier" << endl;}
    | TYPE_NAME                 { $<TypeSpecifier>$ = TypeSpecifier($1,TYPE_NAME); cout << "TYPE_NAME REDUCE to type_specifier" << endl;}
    ;

struct_or_union_specifier
    : struct_or_union IDENTIFIER OCURLY struct_declaration_list CCURLY
    | struct_or_union OCURLY struct_declaration_list CCURLY
    | struct_or_union IDENTIFIER
    ;

struct_or_union
    : STRUCT
    | UNION
    ;

struct_declaration_list
    : struct_declaration
    | struct_declaration_list struct_declaration
    ;

struct_declaration
    : specifier_qualifier_list struct_declarator_list SEMICOLON
    ;

specifier_qualifier_list
    : type_specifier specifier_qualifier_list
    | type_specifier
    | type_qualifier specifier_qualifier_list
    | type_qualifier
    ;

struct_declarator_list
    : struct_declarator
    | struct_declarator_list COMMA struct_declarator
    ;

struct_declarator
    : declarator
    | COLON constant_expression
    | declarator COLON constant_expression
    ;

enum_specifier
    : ENUM OCURLY enumerator_list CCURLY             { $<EnumSpecifier>$ = EnumSpecifier("",&$3); cout << "ENUM OCURLY enumerator_list CCURLY REDUCE to enum_specifier" << endl;}
    | ENUM IDENTIFIER OCURLY enumerator_list CCURLY  { $<EnumSpecifier>$ = EnumSpecifier($2,&$4); cout << "ENUM IDENTIFIER OCURLY enumerator_list CCURLY REDUCE to enum_specifier" << endl;}
    | ENUM IDENTIFIER                                { $<EnumSpecifier>$ = EnumSpecifier($2,NULL); cout << "ENUM IDENTIFIER REDUCE to enum_specifier" << endl;}
    ;

enumerator_list
    : enumerator                        {
                                          Enumerator exp = $1;
                                          $$ = std::vector<Enumerator>();
                                          $$.push_back(exp);
                                          cout << "enumerator REDUCE enumerator_list" << endl;
                                        }
    | enumerator_list COMMA enumerator  {
                                          Enumerator value1 = $3;
                                          std::vector<Enumerator> &value2 = $1;
                                          value2.push_back(value1);
                                          $$ = value2;
                                          cout << "enumerator_list COMMA enumerator REDUCE enumerator_list" << endl;
                                        }
    ;

enumerator
    : IDENTIFIER                              { $<Enumerator>$ = Enumerator($1,NULL); cout << "IDENTIFIER REDUCE to ENUMERATOR" << endl;}
    | IDENTIFIER EQUAL_OP constant_expression { $<Enumerator>$ = Enumerator($1,&$3); cout << "IDENTIFIER EQUAL_OP constant_expression REDUCE to ENUMERATOR" << endl;}
    ;

type_qualifier
    : CONST
    | VOLATILE
    ;

declarator
    : pointer direct_declarator
    | direct_declarator
    ;

direct_declarator
    : IDENTIFIER
    | OPAREN declarator CPAREN
    | direct_declarator '[' constant_expression ']'
    | direct_declarator '[' ']'
    | direct_declarator OPAREN parameter_type_list CPAREN
    | direct_declarator OPAREN identifier_list CPAREN
    | direct_declarator OPAREN CPAREN
    ;

pointer
    : '*'
    | '*' type_qualifier_list
    | '*' pointer
    | '*' type_qualifier_list pointer
    ;

type_qualifier_list
    : type_qualifier
    | type_qualifier_list type_qualifier
    ;


parameter_type_list
    : parameter_list
    | parameter_list COMMA ELLIPSIS
    ;

parameter_list
    : parameter_declaration
    | parameter_list COMMA parameter_declaration
    ;

parameter_declaration
    : declaration_specifiers declarator
    | declaration_specifiers abstract_declarator
    | declaration_specifiers
    ;

identifier_list
    : IDENTIFIER
    | identifier_list COMMA IDENTIFIER
    ;

type_name
    : specifier_qualifier_list
    | specifier_qualifier_list abstract_declarator
    ;

abstract_declarator
    : pointer
    | direct_abstract_declarator
    | pointer direct_abstract_declarator
    ;

direct_abstract_declarator
    : OPAREN abstract_declarator CPAREN
    | '[' ']'
    | '[' constant_expression ']'
    | direct_abstract_declarator '[' ']'
    | direct_abstract_declarator '[' constant_expression ']'
    | OPAREN CPAREN
    | OPAREN parameter_type_list CPAREN
    | direct_abstract_declarator OPAREN CPAREN
    | direct_abstract_declarator OPAREN parameter_type_list CPAREN
    ;

initializer
    : assignment_expression
    | OCURLY initializer_list CCURLY
    | OCURLY initializer_list COMMA CCURLY
    ;

initializer_list
    : initializer
    | initializer_list COMMA initializer
    ;

statement
    : labeled_statement
    | compound_statement
    | expression_statement
    | selection_statement
    | iteration_statement
    | jump_statement
    ;

labeled_statement
    : IDENTIFIER COLON statement
    | CASE constant_expression COLON statement
    | DEFAULT COLON statement
    ;

compound_statement
    : OCURLY CCURLY
    | OCURLY statement_list CCURLY
    | OCURLY declaration_list CCURLY
    | OCURLY declaration_list statement_list CCURLY
    ;

declaration_list
    : declaration
    | declaration_list declaration
    ;

statement_list
    : statement
    | statement_list statement
    ;

expression_statement
    : SEMICOLON
    | expression SEMICOLON
    ;

selection_statement
    : IF OPAREN expression CPAREN statement
    | IF OPAREN expression CPAREN statement ELSE statement
    | SWITCH OPAREN expression CPAREN statement
    ;

iteration_statement
    : WHILE OPAREN expression CPAREN statement
    | DO statement WHILE OPAREN expression CPAREN SEMICOLON
    | FOR OPAREN expression_statement expression_statement CPAREN statement
    | FOR OPAREN expression_statement expression_statement expression CPAREN statement
    ;

jump_statement
    : GOTO IDENTIFIER SEMICOLON
    | CONTINUE SEMICOLON
    | BREAK SEMICOLON
    | RETURN SEMICOLON
    | RETURN expression SEMICOLON
    ;

translation_unit
    : external_declaration                  { cout << "external_declaration REDUCE to translation_unit" << endl; }
    | translation_unit external_declaration { cout << "translation_unit external_declaration REDUCE to translation_unit" << endl; }
    ;

external_declaration
    : function_definition  { cout << "function_definition REDUCE to external_declaration" << endl; }
    | declaration          { cout << "declaration REDUCE to external_declaration" << endl; }
    ;

function_definition
    : declaration_specifiers declarator declaration_list compound_statement
    | declaration_specifiers declarator compound_statement
    | declarator declaration_list compound_statement
    | declarator compound_statement
    ;
    
%%

// Bison expects us to provide implementation - otherwise linker complains
void WadeSpace::Parser::error(const location &loc , const std::string &message) {
        
        // Location should be initialized inside scanner action, but is not in this example.
        // Let's grab location directly from driver class.
    // cout << "Error: " << message << endl << "Location: " << loc << endl;
    
        cout << "Error: " << message << endl << "Error location: " << driver.location() << endl;
}
