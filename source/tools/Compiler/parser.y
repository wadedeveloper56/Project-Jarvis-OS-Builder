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
%token <std::string> EQUAL "="
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
%token <std::string> GREATER_EQUAL ">="
%token <std::string> LESS_EQUAL "<="
%token <std::string> GREATER ">"
%token <std::string> LESS "<"
%token <std::string> EQUAL_EQUAL "=="
%token <std::string> NOT_EQUAL "!="
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
%type<PrimaryExpression> primary_expression
%type<Expression> expression
%type<PostfixExpression> postfix_expression
%type<UnaryExpression> unary_expression
%type<CastExpression> cast_expression
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
%type<TypeQualifier> type_qualifier
%type<std::vector<TypeQualifier>> type_qualifier_list
%type<Pointer> pointer 
%type<DeclarationSpecifiers> declaration_specifiers
%type<DirectDeclarator> direct_declarator
%type<Declarator> declarator
%type<DirectAbstractDeclarator> direct_abstract_declarator
%type<AbstractDeclarator> abstract_declarator
%type<TypeName> type_name
%type<SpecifierQualifierList> specifier_qualifier_list
%type<std::vector<std::string>> identifier_list
%type<StructDeclarator> struct_declarator
%type<std::vector<StructDeclarator>> struct_declarator_list
%type<StructDeclaration> struct_declaration
%type<std::vector<StructDeclaration>> struct_declaration_list
%type<StructOrUnion> struct_or_union
%type<StructOrUnionSpecifier> struct_or_union_specifier
%type<Initializer> initializer
%type<std::vector<Initializer>> initializer_list
%type<InitDeclarator> init_declarator
%type<std::vector<InitDeclarator>> init_declarator_list
%type<Declaration> declaration
%type<ParameterDeclaration> parameter_declaration
%type<ParameterTypeList> parameter_type_list
%type<std::vector<ParameterDeclaration>> parameter_list

%start translation_unit

%%

primary_expression
    : IDENTIFIER                { $<PrimaryExpression>$ = PrimaryExpression(); cout << "IDENTIFIER REDUCE to primary_expression" << endl; }
    | constant                  { $<PrimaryExpression>$ = PrimaryExpression(); cout << "constant REDUCE to primary_expression" << endl; }
    | OPAREN expression CPAREN  { $<PrimaryExpression>$ = PrimaryExpression(); cout << "OPAREN expression CPAREN REDUCE to primary_expression" << endl; }
    ;

constant
    : F_CONST         {
                        long double &id = $1;
                        $<Constant>$ = Constant(id);
                        cout << "F_CONST REDUCE to constant " << id << endl;
                      }
    | I_CONST         {
                        std::uint64_t &id = $1;
                        $<Constant>$ = Constant(id);
                        cout << "I_CONST REDUCE to constant " << id << endl;
                      }
    | STRING_LITERAL  {
                        std::string &id = $1;
                        $<Constant>$ = Constant(id);
                        cout << "STRING_LITERAL REDUCE to constant  " << id << endl;
                      }

postfix_expression
    : primary_expression                                           { $<PostfixExpression>$ = PostfixExpression(); cout << "primary_expression REDUCE to postfix_expression" << endl; }
    | postfix_expression OBRACE expression CBRACE                  { $<PostfixExpression>$ = PostfixExpression(); cout << "postfix_expression OBRACE expression CBRACE REDUCE to postfix_expression" << endl; }
    | postfix_expression OPAREN CPAREN                             { $<PostfixExpression>$ = PostfixExpression(); cout << "postfix_expression OPAREN CPAREN REDUCE to postfix_expression" << endl; }
    | postfix_expression OPAREN argument_expression_list CPAREN    { $<PostfixExpression>$ = PostfixExpression(); cout << "postfix_expression OPAREN argument_expression_list CPAREN REDUCE to postfix_expression" << endl; }
    | postfix_expression PERIOD IDENTIFIER                         { $<PostfixExpression>$ = PostfixExpression(); cout << "postfix_expression PERIOD_OP IDENTIFIER REDUCE to postfix_expression" << endl; }
    | postfix_expression PTR_OP IDENTIFIER                         { $<PostfixExpression>$ = PostfixExpression(); cout << "postfix_expression PTR_OP IDENTIFIER REDUCE to postfix_expression" << endl; }
    | postfix_expression INC_OP                                    { $<PostfixExpression>$ = PostfixExpression(); cout << "postfix_expression INC_OP REDUCE to postfix_expression" << endl; }
    | postfix_expression DEC_OP                                    { $<PostfixExpression>$ = PostfixExpression(); cout << "postfix_expression DEC_OP REDUCE to postfix_expression" << endl; }
    | OPAREN type_name CPAREN OCURLY initializer_list CCURLY       { $<PostfixExpression>$ = PostfixExpression(); cout << "OPAREN type_name CPAREN_OP OCURLY_OP initializer_list CCURLY REDUCE to postfix_expression" << endl; }
    | OPAREN type_name CPAREN OCURLY initializer_list COMMA CCURLY { $<PostfixExpression>$ = PostfixExpression(); cout << "OPAREN type_name CPAREN_OP OCURLY_OP initializer_list COMMA CCURLY REDUCE to postfix_expression" << endl; }


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
    : postfix_expression             { $<UnaryExpression>$ = UnaryExpression(); cout << "postfix_expression REDUCE unary_expression" << endl;}
    | INC_OP unary_expression        { $<UnaryExpression>$ = UnaryExpression(); cout << "INC_OP unary_expression REDUCE unary_expression" << endl;}
    | DEC_OP unary_expression        { $<UnaryExpression>$ = UnaryExpression(); cout << "DEC_OP unary_expression REDUCE unary_expression" << endl;}
    | unary_operator cast_expression { $<UnaryExpression>$ = UnaryExpression(); cout << "unary_operator cast_expression REDUCE unary_expression" << endl;}
    | SIZEOF unary_expression        { $<UnaryExpression>$ = UnaryExpression(); cout << "SIZEOF unary_expression REDUCE unary_expression" << endl;}
    | SIZEOF OPAREN type_name CPAREN { $<UnaryExpression>$ = UnaryExpression(); cout << "SIZEOF OPAREN type_name CPAREN REDUCE unary_expression" << endl;}
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
    : unary_expression                         { $<CastExpression>$ = CastExpression();  cout << "unary_expression REDUCE to cast_expression" << endl;}
    | OPAREN type_name CPAREN cast_expression  { $<CastExpression>$ = CastExpression();  cout << "unary_expression REDUCE to cast_expression" << endl;}
    ;

multiplicative_expression
    : cast_expression                                    { $<Expression>$ = Expression();  cout << "cast_expression REDUCE to multiplicative_expression" << endl;}
    | multiplicative_expression TIMES_OP cast_expression { $<Expression>$ = Expression(); cout << "multiplicative_expression TIMES_OP cast_expression REDUCE to multiplicative_expression" << endl;}
    | multiplicative_expression DIV_OP cast_expression   { $<Expression>$ = Expression(); cout << "multiplicative_expression DIV_OP cast_expression REDUCE to multiplicative_expression" << endl;}
    | multiplicative_expression MOD_OP cast_expression   { $<Expression>$ = Expression(); cout << "multiplicative_expression MOD_OP cast_expression REDUCE to multiplicative_expression" << endl;}
    ;

additive_expression
    : multiplicative_expression                               { $<Expression>$ = $1;  cout << "multiplicative_expression REDUCE to additive_expression" << endl;}
    | additive_expression PLUS_OP multiplicative_expression   { $<Expression>$ = Expression(); cout << "additive_expression REDUCE to multiplicative_expression" << endl;}
    | additive_expression MINUS_OP multiplicative_expression  { $<Expression>$ = Expression(); cout << "additive_expression REDUCE to multiplicative_expression" << endl;}
    ;

shift_expression
    : additive_expression                           { $<Expression>$ = $1;  cout << "additive_expression REDUCE to shift_expression" << endl;}
    | shift_expression LEFT_OP additive_expression  { $<Expression>$ = Expression(); cout << "shift_expression LEFT_OP additive_expression REDUCE to shift_expression" << endl;}
    | shift_expression RIGHT_OP additive_expression { $<Expression>$ = Expression(); cout << "shift_expression RIGHT_OP additive_expression REDUCE to shift_expression" << endl;}
    ;

relational_expression
    : shift_expression                                       { $<Expression>$ = $1;  cout << "shift_expression REDUCE to relational_expression" << endl;}
    | relational_expression LESS shift_expression            { $<Expression>$ = Expression(); cout << "relational_expression LESS shift_expression REDUCE to shift_expression" << endl;}
    | relational_expression GREATER shift_expression         { $<Expression>$ = Expression(); cout << "relational_expression GREATER shift_expression REDUCE to shift_expression" << endl;}
    | relational_expression LESS_EQUAL shift_expression      { $<Expression>$ = Expression(); cout << "relational_expression LESS_EQUAL shift_expression REDUCE to shift_expression" << endl;}
    | relational_expression GREATER_EQUAL shift_expression   { $<Expression>$ = Expression(); cout << "relational_expression GREATER_EQUAL shift_expression REDUCE to shift_expression" << endl;}
    ;

equality_expression
    : relational_expression                                  { $<Expression>$ = $1;  cout << "relational_expression REDUCE to equality_expression" << endl;}
    | equality_expression EQUAL_EQUAL relational_expression  { $<Expression>$ = Expression(); cout << "equality_expression EQUAL_EQUAL relational_expression REDUCE to equality_expression" << endl;}
    | equality_expression NOT_EQUAL relational_expression    { $<Expression>$ = Expression(); cout << "equality_expression NOT_EQUAL relational_expression REDUCE to equality_expression" << endl;}
    ;

and_expression
    : equality_expression                         { $<Expression>$ = $1;  cout << "equality_expression REDUCE to and_expression" << endl;}
    | and_expression BIT_AND equality_expression  { $<Expression>$ = Expression(); cout << "and_expression BIT_AND equality_expression REDUCE to and_expression" << endl;}
    ;

exclusive_or_expression
    : and_expression                                 { $<Expression>$ = $1;  cout << "and_expression REDUCE to exclusive_or_expression" << endl;}
    | exclusive_or_expression XOR_OP and_expression  { $<Expression>$ = Expression(); cout << "exclusive_or_expression XOR_OP and_expression REDUCE to exclusive_or_expression" << endl;}
    ;

inclusive_or_expression
    : exclusive_or_expression                                { $<Expression>$ = $1;  cout << "exclusive_or_expression REDUCE to inclusive_or_expression" << endl;}
    | inclusive_or_expression BIT_OR exclusive_or_expression { $<Expression>$ = Expression(); cout << "inclusive_or_expression BIT_OR exclusive_or_expression REDUCE to inclusive_or_expression" << endl;}
    ;

logical_and_expression
    : inclusive_or_expression                                { $<Expression>$ = $1;  cout << "inclusive_or_expression REDUCE to logical_and_expression" << endl;}
    | logical_and_expression AND_OP inclusive_or_expression  { $<Expression>$ = Expression(); cout << "inclusive_or_expression REDUCE to logical_and_expression" << endl;}
    ;

logical_or_expression
    : logical_and_expression                              { $<Expression>$ = $1;  cout << "inclusive_and_expression REDUCE to logical_or_expression" << endl;}
    | logical_or_expression OR_OP logical_and_expression  { $<Expression>$ = Expression(); cout << "logical_or_expression OR_OP logical_and_expression REDUCE to logical_or_expression" << endl;}
    ;

conditional_expression
    : logical_or_expression                                                   { $<Expression>$ = $1;  cout << "logical_or_expression REDUCE to conditional_expression" << endl;}
    | logical_or_expression QUESTION expression COLON conditional_expression  { $<Expression>$ = Expression(); cout << "logical_or_expression QUESTION expression COLON conditional_expression REDUCE to conditional_expression" << endl;}
    ;

assignment_expression
    : conditional_expression                                      { $<Expression>$ = Expression();  cout << "conditional_expression REDUCE to assignment_expression" << endl;}
    | unary_expression assignment_operator assignment_expression  { $<Expression>$ = Expression(); cout << "unary_expression assignment_operator assignment_expression REDUCE to assignment_expression" << endl;}
    ;

assignment_operator
    : EQUAL          { $<AssignmentOperator>$ = AssignmentOperator($1,EQUAL);  cout << "EQUAL_OP REDUCE to assignment_operator" << endl;}
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
    : assignment_expression                   { $<Expression>$ = $1;  cout << "asignment_expression REDUCE to expression" << endl;}
    | expression COMMA assignment_expression  { $<Expression>$ = Expression(); cout << "expression COMMA assignment_expression COMMA  REDUCE to expression" << endl;}
    ;

constant_expression
    : conditional_expression  { $<Expression>$ = $1;  cout << "conditional_expression REDUCE to constant_expression" << endl;}
    ;

declaration
    : declaration_specifiers SEMICOLON                       { $<Declaration>$ = Declaration($1); cout << "declaration_specifiers SEMICOLON REDUCE to declaration" << endl;}
    | declaration_specifiers init_declarator_list SEMICOLON  { $<Declaration>$ = Declaration($1,$2); cout << "declaration_specifiers init_declarator_list SEMICOLON REDUCE to declaration" << endl;}
    ;

declaration_specifiers
    : storage_class_specifier                         { $<DeclarationSpecifiers>$ = DeclarationSpecifiers($1); cout << "storage_class_specifier REDUCE to declaration_specifiers" << endl;}
    | storage_class_specifier declaration_specifiers  { $<DeclarationSpecifiers>$ = DeclarationSpecifiers($1,$2); cout << "storage_class_specifier declaration_specifiers REDUCE to declaration_specifiers" << endl;}
    | type_specifier                                  { $<DeclarationSpecifiers>$ = DeclarationSpecifiers($1); cout << "type_specifier REDUCE to declaration_specifiers" << endl;}
    | type_specifier declaration_specifiers           { $<DeclarationSpecifiers>$ = DeclarationSpecifiers($1,$2); cout << "type_specifier declaration_specifiers REDUCE to declaration_specifiers" << endl;}
    | type_qualifier                                  { $<DeclarationSpecifiers>$ = DeclarationSpecifiers($1); cout << "type_qualifier REDUCE to declaration_specifiers" << endl;}
    | type_qualifier declaration_specifiers           { $<DeclarationSpecifiers>$ = DeclarationSpecifiers($1,$2); cout << "type_qualifier declaration_specifiers REDUCE to declaration_specifiers" << endl;}
    ;

init_declarator_list
    : init_declarator                            {
                                                  InitDeclarator exp = $1;
                                                  $$ = std::vector<InitDeclarator>();
                                                  $$.push_back(exp);
                                                  cout << "init_declarator REDUCE to init_declarator_list" << endl;
                                                 }
    | init_declarator_list COMMA init_declarator {
                                                  InitDeclarator value1 = $3;
                                                  std::vector<InitDeclarator> &value2 = $1;
                                                  value2.push_back(value1);
                                                  $$ = value2;
                                                  cout << "init_declarator_list COMMA init_declarator REDUCE to init_declarator_list" << endl;
                                                 }
    ;

init_declarator
    : declarator                    { $<InitDeclarator>$ = InitDeclarator($1); cout << "declarator REDUCE to init_declarator" << endl;}
    | declarator EQUAL initializer  { $<InitDeclarator>$ = InitDeclarator($1,$3); cout << "declarator EQUAL initializer REDUCE to init_declarator" << endl;}
    ;

storage_class_specifier
    : TYPEDEF   { $<StorageClassSpecifier>$ = StorageClassSpecifier($1,TYPEDEF); cout << "TYPEDEF REDUCE to storage_class_specifier" << endl;}
    | EXTERN    { $<StorageClassSpecifier>$ = StorageClassSpecifier($1,EXTERN); cout << "EXTERN REDUCE to storage_class_specifier" << endl;}
    | STATIC    { $<StorageClassSpecifier>$ = StorageClassSpecifier($1,STATIC); cout << "STATIC REDUCE to storage_class_specifier" << endl;}
    | AUTO      { $<StorageClassSpecifier>$ = StorageClassSpecifier($1,AUTO); cout << "AUTO REDUCE to storage_class_specifier" << endl;}
    | REGISTER  { $<StorageClassSpecifier>$ = StorageClassSpecifier($1,REGISTER); cout << "REGISTER REDUCE to storage_class_specifier" << endl;}
    ;

type_specifier
    : VOID                      { $<TypeSpecifier>$ = TypeSpecifier(VOID); cout << "VOID REDUCE to type_specifier" << endl;}
    | CHAR                      { $<TypeSpecifier>$ = TypeSpecifier(CHAR); cout << "CHAR REDUCE to type_specifier" << endl;}
    | SHORT                     { $<TypeSpecifier>$ = TypeSpecifier(SHORT); cout << "SHORT REDUCE to type_specifier" << endl;}
    | INT                       { $<TypeSpecifier>$ = TypeSpecifier(INT); cout << "INT REDUCE to type_specifier" << endl;}
    | LONG                      { $<TypeSpecifier>$ = TypeSpecifier(LONG); cout << "LONG REDUCE to type_specifier" << endl;}
    | FLOAT                     { $<TypeSpecifier>$ = TypeSpecifier(FLOAT); cout << "FLOAT REDUCE to type_specifier" << endl;}
    | DOUBLE                    { $<TypeSpecifier>$ = TypeSpecifier(DOUBLE); cout << "DOUBLE REDUCE to type_specifier" << endl;}
    | SIGNED                    { $<TypeSpecifier>$ = TypeSpecifier(SIGNED); cout << "SIGNED REDUCE to type_specifier" << endl;}
    | UNSIGNED                  { $<TypeSpecifier>$ = TypeSpecifier(UNSIGNED); cout << "UNIGNED REDUCE to type_specifier" << endl;}
    | struct_or_union_specifier { $<TypeSpecifier>$ = TypeSpecifier($1); cout << "struct_or_union_specifier REDUCE to type_specifier" << endl;}
    | enum_specifier            { $<TypeSpecifier>$ = TypeSpecifier($1); cout << "enum_specifier REDUCE to type_specifier" << endl;}
    | TYPE_NAME                 { $<TypeSpecifier>$ = TypeSpecifier(TYPE_NAME); cout << "TYPE_NAME REDUCE to type_specifier" << endl;}
    ;

struct_or_union_specifier
    : struct_or_union IDENTIFIER OCURLY struct_declaration_list CCURLY   { $<StructOrUnionSpecifier>$ = StructOrUnionSpecifier($1,$2,$4); cout << "struct_or_union IDENTIFIER OCURLY struct_declaration_list CCURLY REDUCE to struct_or_union_specifier" << endl;}
    | struct_or_union OCURLY struct_declaration_list CCURLY              { $<StructOrUnionSpecifier>$ = StructOrUnionSpecifier($1,$3); cout << "struct_or_union OCURLY struct_declaration_list CCURLY REDUCE to struct_or_union_specifier" << endl;}
    | struct_or_union IDENTIFIER                                         { $<StructOrUnionSpecifier>$ = StructOrUnionSpecifier($1,$2); cout << "struct_or_union IDENTIFIER REDUCE to struct_or_union_specifier" << endl;}
    ;

struct_or_union
    : STRUCT   { $<StructOrUnion>$ = StructOrUnion(STRUCT); cout << "STRUCT REDUCE to struct_or_union" << endl;}
    | UNION    { $<StructOrUnion>$ = StructOrUnion(UNION); cout << "UNION REDUCE to struct_or_union" << endl;}
    ;

struct_declaration_list
    : struct_declaration    {
                             StructDeclaration exp = $1;
                             $$ = std::vector<StructDeclaration>();
                             $$.push_back(exp);
                             cout << "struct_declaration REDUCE to struct_declaration_list" << endl;
                            }
    | struct_declaration_list struct_declaration     {
                                                       StructDeclaration value1 = $2;
                                                       std::vector<StructDeclaration> &value2 = $1;
                                                       value2.push_back(value1);
                                                       $$ = value2;
                                                       cout << "struct_declaration_list struct_declaration REDUCE to struct_declaration_list" << endl;
                                                     }
    ;

struct_declaration
    : specifier_qualifier_list struct_declarator_list SEMICOLON { $<StructDeclaration>$ = StructDeclaration($1,$2); cout << "specifier_qualifier_list struct_declarator_list SEMICOLON REDUCE to struct_declaration" << endl;}
    ;

specifier_qualifier_list
    : type_specifier specifier_qualifier_list { $<SpecifierQualifierList>$ = SpecifierQualifierList($2,$1); cout << "type_specifier specifier_qualifier_list REDUCE to specifier_qualifier_list" << endl;}
    | type_specifier                          { $<SpecifierQualifierList>$ = SpecifierQualifierList($1); cout << "type_specifier REDUCE to specifier_qualifier_list" << endl;}
    | type_qualifier specifier_qualifier_list { $<SpecifierQualifierList>$ = SpecifierQualifierList($2,$1); cout << "type_qualifier specifier_qualifier_list REDUCE to specifier_qualifier_list" << endl;}
    | type_qualifier                          { $<SpecifierQualifierList>$ = SpecifierQualifierList($1); cout << "type_qualifier REDUCE to specifier_qualifier_list" << endl;}
    ;

struct_declarator_list
    : struct_declarator                              {
                                                       StructDeclarator exp = $1;
                                                       $$ = std::vector<StructDeclarator>();
                                                       $$.push_back(exp);
                                                       cout << "struct_declarator REDUCE to struct_declarator_list" << endl;
                                                     }
    | struct_declarator_list COMMA struct_declarator {
                                                       StructDeclarator value1 = $3;
                                                       std::vector<StructDeclarator> &value2 = $1;
                                                       value2.push_back(value1);
                                                       $$ = value2;
                                                       cout << "struct_declarator_list COMMA struct_declarator REDUCE to struct_declarator_list" << endl;
                                                     }
    ;

struct_declarator
    : declarator                           { $<StructDeclarator>$ = StructDeclarator($1); cout << "declarator REDUCE to struct_declarator" << endl;}
    | COLON constant_expression            { $<StructDeclarator>$ = StructDeclarator($2); cout << "COLON constant_expression REDUCE to struct_declarator" << endl;}
    | declarator COLON constant_expression { $<StructDeclarator>$ = StructDeclarator($1,$3); cout << "declarator COLON constant_expression REDUCE to struct_declarator" << endl;}
    ;

enum_specifier
    : ENUM OCURLY enumerator_list CCURLY             { $<EnumSpecifier>$ = EnumSpecifier($3); cout << "ENUM OCURLY enumerator_list CCURLY REDUCE to enum_specifier" << endl;}
    | ENUM IDENTIFIER OCURLY enumerator_list CCURLY  { $<EnumSpecifier>$ = EnumSpecifier($2,$4); cout << "ENUM IDENTIFIER OCURLY enumerator_list CCURLY REDUCE to enum_specifier" << endl;}
    | ENUM IDENTIFIER                                { $<EnumSpecifier>$ = EnumSpecifier($2); cout << "ENUM IDENTIFIER REDUCE to enum_specifier" << endl;}
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
    : IDENTIFIER                           { $<Enumerator>$ = Enumerator($1); cout << "IDENTIFIER REDUCE to ENUMERATOR" << endl;}
    | IDENTIFIER EQUAL constant_expression { $<Enumerator>$ = Enumerator($1,$3); cout << "IDENTIFIER EQUAL constant_expression REDUCE to ENUMERATOR" << endl;}
    ;

type_qualifier
    : CONST    { $<TypeQualifier>$ = TypeQualifier($1,CONST); cout << "CONST REDUCE to type_qualifier" << endl;}
    | VOLATILE { $<TypeQualifier>$ = TypeQualifier($1,VOLATILE); cout << "VOLATILE REDUCE to type_qualifier" << endl;}
    ;

declarator
    : pointer direct_declarator { $<Declarator>$ = Declarator($1,$2); cout << "pointer direct_declarator REDUCE to declarator" << endl;}
    | direct_declarator         { $<Declarator>$ = Declarator($1); cout << "direct_declarator REDUCE to declarator" << endl;}
    ;

direct_declarator
    : IDENTIFIER                                            { $<DirectDeclarator>$ = DirectDeclarator($1); cout << "IDENTIFIER REDUCE to direct_declarator" << endl;}
    | OPAREN declarator CPAREN                              { $<DirectDeclarator>$ = DirectDeclarator(); cout << "OPAREN declarator CPAREN REDUCE to direct_declarator" << endl;}
    | direct_declarator OBRACE constant_expression CBRACE   { $<DirectDeclarator>$ = DirectDeclarator(); cout << "direct_declarator OBRACE constant_expression CBRACE REDUCE to direct_declarator" << endl;}
    | direct_declarator OBRACE CBRACE                       { $<DirectDeclarator>$ = DirectDeclarator(); cout << "direct_declarator OBRACE CBRACE REDUCE to direct_declarator" << endl;}
    | direct_declarator OPAREN parameter_type_list CPAREN   { $<DirectDeclarator>$ = DirectDeclarator(); cout << "direct_declarator OPAREN parameter_type_list CPAREN to direct_declarator" << endl;}
    | direct_declarator OPAREN identifier_list CPAREN       { $<DirectDeclarator>$ = DirectDeclarator(); cout << "direct_declarator OPAREN identifier_list CPAREN REDUCE to direct_declarator" << endl;}
    | direct_declarator OPAREN CPAREN                       { $<DirectDeclarator>$ = DirectDeclarator(); cout << "direct_declarator OPAREN CPAREN REDUCE to direct_declarator" << endl;}
    ;

pointer
    : TIMES_OP                              {$<Pointer>$ = Pointer($1); cout << "TIMES_OP REDUCE to POINTER" << endl;}
    | TIMES_OP type_qualifier_list          {$<Pointer>$ = Pointer($1,$2); cout << "TIMES_OP type_qualifier_list REDUCE to POINTER" << endl;}
    | TIMES_OP pointer                      {$<Pointer>$ = Pointer($1,$2); $<Pointer>$.inc(); cout << "TIMES_OP pointer REDUCE to POINTER" << endl;}
    | TIMES_OP type_qualifier_list pointer  {$<Pointer>$ = Pointer($1,$2,$3); $<Pointer>$.inc(); cout << "TIMES_OP type_qualifier_list pointer REDUCE to POINTER" << endl;}
    ;

type_qualifier_list
    : type_qualifier        {
                             TypeQualifier exp = $1;
                             $$ = std::vector<TypeQualifier>();
                             $$.push_back(exp);
                             cout << "type_qualifier REDUCE type_qualifier_list" << endl;
                            }
    | type_qualifier_list type_qualifier {
                                          TypeQualifier value1 = $2;
                                          std::vector<TypeQualifier> &value2 = $1;
                                          value2.push_back(value1);
                                          $$ = value2;
                                          cout << "type_qualifier_list type_qualifier REDUCE type_qualifier_list" << endl;
                                        }
    ;


parameter_type_list
    : parameter_list                  { $<ParameterTypeList>$ = ParameterTypeList($1,""); cout << "parameter_list REDUCE to parameter_type_list" << endl; }
    | parameter_list COMMA ELLIPSIS   { $<ParameterTypeList>$ = ParameterTypeList($1,$2); cout << "parameter_list COMMA ELLIPSIS REDUCE to parameter_type_list" << endl; }
    ;

parameter_list
    : parameter_declaration                       {
                                                    ParameterDeclaration exp = $1;
                                                    $$ = std::vector<ParameterDeclaration>();
                                                    $$.push_back(exp);
                                                    cout << "parameter_declaration REDUCE to parameter_list" << endl;
                                                  }
    | parameter_list COMMA parameter_declaration  {
                                                    ParameterDeclaration value1 = $3;
                                                    std::vector<ParameterDeclaration> &value2 = $1;
                                                    value2.push_back(value1);
                                                    $$ = value2;
                                                    cout << "parameter_list COMMA parameter_declaration REDUCE to parameter_list" << endl;
                                                  }
    ;

parameter_declaration
    : declaration_specifiers declarator           { $<ParameterDeclaration>$ = ParameterDeclaration($1,$2); cout << "declaration_specifiers declarator REDUCE to parameter_declaration" << endl; }
    | declaration_specifiers abstract_declarator  { $<ParameterDeclaration>$ = ParameterDeclaration($1,$2); cout << "declaration_specifiers abstract_declarator REDUCE to parameter_declaration" << endl; }
    | declaration_specifiers                      { $<ParameterDeclaration>$ = ParameterDeclaration($1); cout << "declaration_specifiers REDUCE to parameter_declaration" << endl; }
    ;

identifier_list
    : IDENTIFIER                       {
                                          std::string exp = $1;
                                          $$ = std::vector<std::string>();
                                          $$.push_back(exp);
                                          cout << "IDENTIFIER REDUCE to identifier_list" << endl;
                                       }
    | identifier_list COMMA IDENTIFIER {
                                          std::string value1 = $3;
                                          std::vector<std::string> &value2 = $1;
                                          value2.push_back(value1);
                                          $$ = value2;
                                          cout << "identifier_list COMMA IDENTIFIER REDUCE to identifier_list" << endl; 
                                        }
    ;

type_name
    : specifier_qualifier_list                     { $<TypeName>$ = TypeName($1); cout << "specifier_qualifier_list REDUCE to type_name" << endl; }
    | specifier_qualifier_list abstract_declarator { $<TypeName>$ = TypeName($1,$2); cout << "specifier_qualifier_list abstract_declarator REDUCE to type_name" << endl; }
    ;

abstract_declarator
    : pointer                             { $<AbstractDeclarator>$ = AbstractDeclarator($1); cout << "pointer REDUCE to abstract_declarator" << endl; }
    | direct_abstract_declarator          { $<AbstractDeclarator>$ = AbstractDeclarator($1); cout << "direct_abstract_declarator REDUCE to abstract_declarator" << endl; }
    | pointer direct_abstract_declarator  { $<AbstractDeclarator>$ = AbstractDeclarator($1,$2); cout << "pointer direct_abstract_declarator REDUCE to abstract_declarator" << endl; }
    ;

direct_abstract_declarator
    : OPAREN abstract_declarator CPAREN                            { $<DirectAbstractDeclarator>$ = DirectAbstractDeclarator($2); cout << "OPAREN abstract_declarator CPAREN REDUCE to direct_abstract_declarator" << endl; }
    | OBRACE CBRACE                                                { $<DirectAbstractDeclarator>$ = DirectAbstractDeclarator(); cout << "OBRACE CBRACE REDUCE to direct_abstract_declarator" << endl; }
    | OBRACE constant_expression CBRACE                            { $<DirectAbstractDeclarator>$ = DirectAbstractDeclarator(); cout << "OBRACE constant_expression CBRACE REDUCE to direct_abstract_declarator" << endl; }
    | direct_abstract_declarator OBRACE CBRACE                     { $<DirectAbstractDeclarator>$ = DirectAbstractDeclarator(); cout << "direct_abstract_declarator OBRACE CBRACE REDUCE to direct_abstract_declarator" << endl; }
    | direct_abstract_declarator OBRACE constant_expression CBRACE { $<DirectAbstractDeclarator>$ = DirectAbstractDeclarator(); cout << "direct_abstract_declarator OBRACE constant_expression CBRACE REDUCE to direct_abstract_declarator" << endl; }
    | OPAREN CPAREN                                                { $<DirectAbstractDeclarator>$ = DirectAbstractDeclarator(); cout << "OPAREN CPAREN REDUCE to direct_abstract_declarator" << endl; }
    | OPAREN parameter_type_list CPAREN                            { $<DirectAbstractDeclarator>$ = DirectAbstractDeclarator(); cout << "OPAREN parameter_type_list CPAREN REDUCE to direct_abstract_declarator" << endl; }
    | direct_abstract_declarator OPAREN CPAREN                     { $<DirectAbstractDeclarator>$ = DirectAbstractDeclarator(); cout << "direct_abstract_declarator OPAREN CPAREN REDUCE to direct_abstract_declarator" << endl; }
    | direct_abstract_declarator OPAREN parameter_type_list CPAREN { $<DirectAbstractDeclarator>$ = DirectAbstractDeclarator(); cout << "direct_abstract_declarator OPAREN parameter_type_list CPAREN REDUCE to direct_abstract_declarator" << endl; }
    ;

initializer
    : assignment_expression                { $<Initializer>$ = Initializer($1); cout << "assignment_expression REDUCE to initializer" << endl; }
    | OCURLY initializer_list CCURLY       { $<Initializer>$ = Initializer($2); cout << "OCURLY initializer_list CCURLY REDUCE to initializer" << endl; }
    | OCURLY initializer_list COMMA CCURLY { $<Initializer>$ = Initializer($2); cout << "OCURLY initializer_list COMMA CCURLY REDUCE to initializer" << endl; }
    ;

initializer_list
    : initializer                         {
                                           Initializer exp = $1;
                                           $$ = std::vector<Initializer>();
                                           $$.push_back(exp);
                                           cout << "initializer REDUCE to initializer_list" << endl;
                                          }
    | initializer_list COMMA initializer  {
                                           Initializer value1 = $3;
                                           std::vector<Initializer> &value2 = $1;
                                           value2.push_back(value1);
                                           $$ = value2;
                                           cout << "initializer_list COMMA initializer REDUCE to initializer_list" << endl;
                                         }
    ;

statement
    : labeled_statement    { cout << "labeled_statement REDUCE to statement" << endl; }
    | compound_statement   { cout << "compound_statement REDUCE to statement" << endl; }
    | expression_statement { cout << "expression_statement REDUCE to statement" << endl; }
    | selection_statement  { cout << "selection_statement REDUCE to statement" << endl; }
    | iteration_statement  { cout << "iteration_statement REDUCE to statement" << endl; }
    | jump_statement       { cout << "jump_statement REDUCE to statement" << endl; }
    ;

labeled_statement
    : IDENTIFIER COLON statement               { cout << "IDENTIFIER COLON statement REDUCE to label_statement" << endl; }
    | CASE constant_expression COLON statement { cout << "CASE constant_expression COLON statement REDUCE to label_statement" << endl; }
    | DEFAULT COLON statement                  { cout << "DEFAULT COLON statement REDUCE to label_statement" << endl; }
    ;

compound_statement
    : OCURLY CCURLY                                 { cout << "OCURLY CCURLY REDUCE to compound_statement" << endl; }
    | OCURLY statement_list CCURLY                  { cout << "OCURLY statement_list CCURLY REDUCE to compound_statement" << endl; }
    | OCURLY declaration_list CCURLY                { cout << "OCURLY declaration_list CCURLY REDUCE to compound_statement" << endl; }
    | OCURLY declaration_list statement_list CCURLY { cout << "OCURLY declaration_list statement_list CCURLY REDUCE to compound_statement" << endl; }
    ;

declaration_list
    : declaration                   { cout << "declaration REDUCE to declaration_list" << endl; }
    | declaration_list declaration  { cout << "declaration_list declaration REDUCE to declaration_list" << endl; }
    ;

statement_list
    : statement                { cout << "statement REDUCE to statement_list" << endl; }
    | statement_list statement { cout << "statement_list statement REDUCE to statement_list" << endl; }
    ;

expression_statement
    : SEMICOLON             { cout << "SEMICOLON REDUCE to expression_statement" << endl; }
    | expression SEMICOLON  { cout << "expression SEMICOLON REDUCE to expression_statement" << endl; }
    ;

selection_statement
    : IF OPAREN expression CPAREN statement                { cout << "IF OPAREN expression CPAREN statement REDUCE to selection_statement" << endl; }
    | IF OPAREN expression CPAREN statement ELSE statement { cout << "IF OPAREN expression CPAREN statement ELSE statement REDUCE to selection_statement" << endl; }
    | SWITCH OPAREN expression CPAREN statement            { cout << "SWITCH OPAREN expression CPAREN statement REDUCE to selection_statement" << endl; }
    ;

iteration_statement
    : WHILE OPAREN expression CPAREN statement                                         { cout << "WHILE OPAREN expression CPAREN statement REDUCE to iteration_statement" << endl; }
    | DO statement WHILE OPAREN expression CPAREN SEMICOLON                            { cout << "DO statement WHILE OPAREN expression CPAREN SEMICOLON REDUCE to iteration_statement" << endl; }
    | FOR OPAREN expression_statement expression_statement CPAREN statement            { cout << "FOR OPAREN expression_statement expression_statement CPAREN statement REDUCE to iteration_statement" << endl; }
    | FOR OPAREN expression_statement expression_statement expression CPAREN statement { cout << "FOR OPAREN expression_statement expression_statement expression CPAREN statement REDUCE to iteration_statement" << endl; }
    ;

jump_statement
    : GOTO IDENTIFIER SEMICOLON   { cout << "GOTO IDENTIFIER SEMICOLON REDUCE to jump_statement" << endl; }
    | CONTINUE SEMICOLON          { cout << "CONTINUE SEMICOLON REDUCE to jump_statement" << endl; }
    | BREAK SEMICOLON             { cout << "BREAK SEMICOLON REDUCE to jump_statement" << endl; }
    | RETURN SEMICOLON            { cout << "RETURN SEMICOLON REDUCE to jump_statement" << endl; }
    | RETURN expression SEMICOLON { cout << "RETURN expression SEMICOLON REDUCE to jump_statement" << endl; }
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
    : declaration_specifiers declarator declaration_list compound_statement { cout << "declaration_specifiers declarator declaration_list compound_statement REDUCE to function_definition" << endl; }
    | declaration_specifiers declarator compound_statement                  { cout << "declaration_specifiers declarator compound_statement REDUCE to function_definition" << endl; }
    | declarator declaration_list compound_statement                        { cout << "declarator declaration_list compound_statement REDUCE to function_definition" << endl; }
    | declarator compound_statement                                         { cout << "declarator compound_statement REDUCE to function_definition" << endl; }
    ;
    
%%

// Bison expects us to provide implementation - otherwise linker complains
void WadeSpace::Parser::error(const location &loc , const std::string &message) {
        
        // Location should be initialized inside scanner action, but is not in this example.
        // Let's grab location directly from driver class.
    // cout << "Error: " << message << endl << "Location: " << loc << endl;
    
        cout << "Error: " << message << endl << "Error location: " << driver.location() << endl;
}
