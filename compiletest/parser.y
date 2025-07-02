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


%start translation_unit

%%

primary_expression
    : IDENTIFIER { $<Expression>$ = Expression($1); cout << "<EXP> IDENTIFIER REDUCE to primary_expression" << endl; }
    | constant { $<Expression>$ = Expression(&$1); cout << "<EXP> constant REDUCE to primary_expression" << endl; }
    | OPAREN expression CPAREN  { $<Expression>$ = $2; cout << "<EXP> (expression) REDUCE to primary_expression" << endl; }
    ;

constant
    : F_CONST {
                 long double &id = $1;
                 cout << "<EXP> F_CONST REDUCE to constant " << id << endl;
                 $<Constant>$ = Constant(id);
              }
    | I_CONST {
                 std::uint64_t &id = $1;
                 cout << "<EXP> I_CONST REDUCE to constant " << id << endl;
                 $<Constant>$ = Constant(id);
              }
    | STRING_LITERAL  {
                 std::string &id = $1;
                 cout << "<EXP> STRING_LITERAL REDUCE to constant  " << id << endl;
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
                             cout << "<EXP> assignment_expression REDUCE argument_expression_list" << endl;
                            }
    | argument_expression_list COMMA assignment_expression {
            Expression value1 = $3;
            std::vector<Expression> &value2 = $1;
            value2.push_back(value1);
            $$ = value2;
            cout << "<EXP> argument_expression_list COMMA assignment_expression REDUCE argument_expression_list" << endl;
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
    : unary_expression  { $<Expression>$ = $1; }
    | OPAREN type_name CPAREN cast_expression  { $<Expression>$ = Expression(); }
    ;

multiplicative_expression
    : cast_expression  { $<Expression>$ = $1; }
    | multiplicative_expression TIMES_OP cast_expression
    | multiplicative_expression DIV_OP cast_expression
    | multiplicative_expression MOD_OP cast_expression
    ;

additive_expression
    : multiplicative_expression
    | additive_expression '+' multiplicative_expression
    | additive_expression '-' multiplicative_expression
    ;

shift_expression
    : additive_expression
    | shift_expression LEFT_OP additive_expression
    | shift_expression RIGHT_OP additive_expression
    ;

relational_expression
    : shift_expression
    | relational_expression LESS_OP shift_expression
    | relational_expression GREATER_OP shift_expression
    | relational_expression LESS_EQUAL_OP shift_expression
    | relational_expression GREATER_EQUAL_OP shift_expression
    ;

equality_expression
    : relational_expression
    | equality_expression EQUAL_EQUAL_OP relational_expression
    | equality_expression NOT_EQUAL_OP relational_expression
    ;

and_expression
    : equality_expression
    | and_expression '&' equality_expression
    ;

exclusive_or_expression
    : and_expression
    | exclusive_or_expression '^' and_expression
    ;

inclusive_or_expression
    : exclusive_or_expression
    | inclusive_or_expression '|' exclusive_or_expression
    ;

logical_and_expression
    : inclusive_or_expression
    | logical_and_expression AND_OP inclusive_or_expression
    ;

logical_or_expression
    : logical_and_expression
    | logical_or_expression OR_OP logical_and_expression
    ;

conditional_expression
    : logical_or_expression
    | logical_or_expression '?' expression ':' conditional_expression
    ;

assignment_expression
    : conditional_expression
    | unary_expression assignment_operator assignment_expression
    ;

assignment_operator
    : '='
    | MUL_ASSIGN
    | DIV_ASSIGN
    | MOD_ASSIGN
    | ADD_ASSIGN
    | SUB_ASSIGN
    | LEFT_ASSIGN
    | RIGHT_ASSIGN
    | AND_ASSIGN
    | XOR_ASSIGN
    | OR_ASSIGN
    ;

expression
    : assignment_expression
    | expression COMMA assignment_expression
    ;

constant_expression
    : conditional_expression
    ;

declaration
    : declaration_specifiers SEMICOLON
    | declaration_specifiers init_declarator_list SEMICOLON
    ;

declaration_specifiers
    : storage_class_specifier
    | storage_class_specifier declaration_specifiers
    | type_specifier
    | type_specifier declaration_specifiers
    | type_qualifier
    | type_qualifier declaration_specifiers
    ;

init_declarator_list
    : init_declarator
    | init_declarator_list COMMA init_declarator
    ;

init_declarator
    : declarator
    | declarator '=' initializer
    ;

storage_class_specifier
    : TYPEDEF
    | EXTERN
    | STATIC
    | AUTO
    | REGISTER
    ;

type_specifier
    : VOID
    | CHAR
    | SHORT
    | INT
    | LONG
    | FLOAT
    | DOUBLE
    | SIGNED
    | UNSIGNED
    | struct_or_union_specifier
    | enum_specifier
    | TYPE_NAME
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
    | ':' constant_expression
    | declarator ':' constant_expression
    ;

enum_specifier
    : ENUM OCURLY enumerator_list CCURLY
    | ENUM IDENTIFIER OCURLY enumerator_list CCURLY
    | ENUM IDENTIFIER
    ;

enumerator_list
    : enumerator
    | enumerator_list COMMA enumerator
    ;

enumerator
    : IDENTIFIER
    | IDENTIFIER '=' constant_expression
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
    : IDENTIFIER ':' statement
    | CASE constant_expression ':' statement
    | DEFAULT ':' statement
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
