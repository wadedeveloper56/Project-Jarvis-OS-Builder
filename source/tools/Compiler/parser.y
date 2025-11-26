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
    #include "StorageClassSpecifier.h"
    #include "DeclarationSpecifiers.h"
    #include "TypeSpecifier.h"
    #include "TypeQualifier.h"
    #include "Enumerator.h"
    #include "EnumSpecifier.h"
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
    #include "BaseStatement.h"
    #include "JumpStatement.h"
    #include "IterationStatement.h"
    #include "SelectionStatement.h"
    #include "ExpressionStatement.h"
    #include "CompoundStatement.h"
    #include "LabeledStatement.h"
    #include "Statement.h"
    #include "FunctionDefinition.h"
    #include "ExternalDeclaration.h"
    #include "ProgramData.h"
    #include "ExpressionNode.h"

    using namespace std;

    namespace WadeSpace {
        extern ProgramData *program;

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
%token <int> TYPE_NAME "type name"
%token <int> AUTO "auto"
%token <int> BREAK "break"
%token <int> CASE "case"
%token <int> CHAR "char"
%token <int> CONST "const"
%token <int> CONTINUE "continue"
%token <int> DEFAULT "default"
%token <int> DO "do"
%token <int> DOUBLE "double"
%token <int> LONG_DOUBLE "long double"
%token <int> ELSE "else"
%token <int> ENUM "enum"
%token <int> EXTERN "extern"
%token <int> FLOAT "float"
%token <int> FOR "for"
%token <int> GOTO "goto"
%token <int> IF "if"
%token <int> INLINE "inline"
%token <int> INT
%token <int> LONG "long"
%token <int> LONG_LONG "long long"
%token <int> REGISTER "register"
%token <int> RESTRICT "restrict"
%token <int> RETURN "return"
%token <int> SHORT "short"
%token <int> SIGNED "signed"
%token <int> SIZEOF "sizeof"
%token <int> STATIC "static"
%token <int> STRUCT "struct"
%token <int> SWITCH "switch"
%token <int> TYPEDEF "typedef"
%token <int> UNION "union"
%token <int> UNSIGNED "unsigned"
%token <int> VOID "void"
%token <int> VOLATILE "volatile"
%token <int> WHILE "while"
%token <int> BOOL "bool"
%token <int> COMPLEX "complex"
%token <int> IMAGINARY "imaginary"
%token <int> ELLIPSIS "ellipsis"
%token <int> QUESTION "question"
%token <int> SEMICOLON ";"
%token <int> OCURLY "{"
%token <int> CCURLY "}"
%token <int> COMMA ","
%token <int> COLON ":"
%token <int> OPAREN "("
%token <int> CPAREN ")"
%token <int> OBRACE "["
%token <int> CBRACE "]"
%token <int> PERIOD "."
%token <int> TILDE "~"
%token <int> EQUAL "="
%token <int> RIGHT_ASSIGN ">>="
%token <int> LEFT_ASSIGN "<<="
%token <int> ADD_ASSIGN "+="
%token <int> SUB_ASSIGN "-="
%token <int> MUL_ASSIGN "*="
%token <int> DIV_ASSIGN "/="
%token <int> MOD_ASSIGN "%="
%token <int> AND_ASSIGN "&="
%token <int> XOR_ASSIGN "^="
%token <int> OR_ASSIGN "|="
%token <int> RIGHT_OP ">>"
%token <int> LEFT_OP "<<"
%token <int> INC_OP "++"
%token <int> DEC_OP "--"
%token <int> PTR_OP "->"
%token <int> AND_OP "&&"
%token <int> OR_OP "||"
%token <int> GREATER_EQUAL ">="
%token <int> LESS_EQUAL "<="
%token <int> GREATER ">"
%token <int> LESS "<"
%token <int> EQUAL_EQUAL "=="
%token <int> NOT_EQUAL "!="
%token <int> NOT_OP "!"
%token <int> XOR_OP "^"
%token <int> BIT_AND "&"
%token <int> BIT_OR "|"
%token <int> MINUS_OP "-"
%token <int> PLUS_OP "+"
%token <int> TIMES_OP "*"
%token <int> DIV_OP "/"
%token <int> MOD_OP "%"

%type<Constant *> constant
%type<vector<ExpressionNode *> *> argument_expression_list
%type<ExpressionNode *> primary_expression
%type<ExpressionNode *> expression
%type<ExpressionNode *> postfix_expression
%type<ExpressionNode *> unary_expression
%type<ExpressionNode *> cast_expression
%type<ExpressionNode *> multiplicative_expression
%type<ExpressionNode *> additive_expression
%type<ExpressionNode *> shift_expression
%type<ExpressionNode *> relational_expression
%type<ExpressionNode *> equality_expression
%type<ExpressionNode *> and_expression
%type<ExpressionNode *> exclusive_or_expression
%type<ExpressionNode *> inclusive_or_expression
%type<ExpressionNode *> logical_and_expression
%type<ExpressionNode *> logical_or_expression
%type<ExpressionNode *> conditional_expression
%type<ExpressionNode *> assignment_expression
%type<ExpressionNode *> constant_expression
%type<int> unary_operator
%type<int> assignment_operator
%type<StorageClassSpecifier *> storage_class_specifier
%type<TypeSpecifier *> type_specifier
%type<Enumerator *> enumerator
%type<std::vector<Enumerator *> *> enumerator_list
%type<EnumSpecifier *> enum_specifier
%type<TypeQualifier *> type_qualifier
%type<std::vector<TypeQualifier *> *> type_qualifier_list
%type<Pointer *> pointer 
%type<DeclarationSpecifiers *> declaration_specifiers
%type<DirectDeclarator *> direct_declarator
%type<Declarator *> declarator
%type<DirectAbstractDeclarator *> direct_abstract_declarator
%type<AbstractDeclarator *> abstract_declarator
%type<TypeName *> type_name
%type<SpecifierQualifierList *> specifier_qualifier_list
%type<std::vector<std::string> *> identifier_list
%type<StructDeclarator *> struct_declarator
%type<std::vector<StructDeclarator *> *> struct_declarator_list
%type<StructDeclaration *> struct_declaration
%type<std::vector<StructDeclaration *> *> struct_declaration_list
%type<StructOrUnion *> struct_or_union
%type<StructOrUnionSpecifier *> struct_or_union_specifier
%type<Initializer *> initializer
%type<std::vector<Initializer *> *> initializer_list
%type<InitDeclarator *> init_declarator
%type<std::vector<InitDeclarator *> *> init_declarator_list
%type<Declaration *> declaration
%type<ParameterDeclaration *> parameter_declaration
%type<ParameterTypeList *> parameter_type_list
%type<std::vector<ParameterDeclaration *> *> parameter_list
%type<BaseStatement *> jump_statement
%type<std::vector<BaseStatement *> *> statement_list
%type<BaseStatement *> statement
%type<BaseStatement *> iteration_statement
%type<BaseStatement *> selection_statement
%type<BaseStatement *> expression_statement
%type<std::vector<Declaration *> *> declaration_list
%type<BaseStatement *> compound_statement
%type<LabeledStatement *> labeled_statement
%type<FunctionDefinition *> function_definition
%type<ExternalDeclaration *> external_declaration

%start translation_unit

%%

primary_expression
    : IDENTIFIER                { $<ExpressionNode *>$ = new ExpressionNode($1); cout << "IDENTIFIER REDUCE to primary_expression" << endl; }
    | constant                  { $<ExpressionNode *>$ = new ExpressionNode($1); cout << "constant REDUCE to primary_expression" << endl; }
    | OPAREN expression CPAREN  { $<ExpressionNode *>$ = $2; cout << "OPAREN expression CPAREN REDUCE to primary_expression" << endl; }
    ;

constant
    : F_CONST         {
                        long double id = $1;
                        $<Constant *>$ = new Constant(id);
                        cout << "F_CONST REDUCE to constant " << id << endl;
                      }
    | I_CONST         {
                        uint64_t id = $1;
                        $<Constant *>$ = new Constant(id);
                        cout << "I_CONST REDUCE to constant " << id << endl;
                      }
    | STRING_LITERAL  {
                        string id = $1;
                        $<Constant *>$ = new Constant(id);
                        cout << "STRING_LITERAL REDUCE to constant  " << id << endl;
                      }

postfix_expression
    : primary_expression                                           { $<ExpressionNode *>$ = $1; cout << "primary_expression REDUCE to postfix_expression" << endl; }
    | postfix_expression OBRACE expression CBRACE                  { $<ExpressionNode *>$ = new ExpressionNode($1,$2,nullptr); cout << "postfix_expression OBRACE expression CBRACE REDUCE to postfix_expression" << endl; }
    | postfix_expression OPAREN CPAREN                             { $<ExpressionNode *>$ = new ExpressionNode($1,nullptr,nullptr); cout << "postfix_expression OPAREN CPAREN REDUCE to postfix_expression" << endl; }
    | postfix_expression OPAREN argument_expression_list CPAREN    { $<ExpressionNode *>$ = new ExpressionNode($1,$3); cout << "postfix_expression OPAREN argument_expression_list CPAREN REDUCE to postfix_expression" << endl; }
    | postfix_expression PERIOD IDENTIFIER                         { $<ExpressionNode *>$ = new ExpressionNode($1,$2,$3); cout << "postfix_expression PERIOD_OP IDENTIFIER REDUCE to postfix_expression" << endl; }
    | postfix_expression PTR_OP IDENTIFIER                         { $<ExpressionNode *>$ = new ExpressionNode($1,$2,$3); cout << "postfix_expression PTR_OP IDENTIFIER REDUCE to postfix_expression" << endl; }
    | postfix_expression INC_OP                                    { $<ExpressionNode *>$ = new ExpressionNode($1,$2,""); cout << "postfix_expression INC_OP REDUCE to postfix_expression" << endl; }
    | postfix_expression DEC_OP                                    { $<ExpressionNode *>$ = new ExpressionNode($1,$2,""); cout << "postfix_expression DEC_OP REDUCE to postfix_expression" << endl; }
    | OPAREN type_name CPAREN OCURLY initializer_list CCURLY       { $<ExpressionNode *>$ = new ExpressionNode($2,$5); cout << "OPAREN type_name CPAREN_OP OCURLY_OP initializer_list CCURLY REDUCE to postfix_expression" << endl; }
    | OPAREN type_name CPAREN OCURLY initializer_list COMMA CCURLY { $<ExpressionNode *>$ = new ExpressionNode($2,$5); cout << "OPAREN type_name CPAREN_OP OCURLY_OP initializer_list COMMA CCURLY REDUCE to postfix_expression" << endl; }


argument_expression_list
    : assignment_expression {
                             ExpressionNode *exp = $1;
                             $$ = new std::vector<ExpressionNode *>();
                             $$->push_back(exp);
                             cout << "assignment_expression REDUCE argument_expression_list" << endl;
                            }
    | argument_expression_list COMMA assignment_expression {
            ExpressionNode* value1 = $3;
            vector<ExpressionNode*>* value2 = $1;
            value2->push_back(value1);
            $$ = value2;
            cout << "argument_expression_list COMMA assignment_expression REDUCE argument_expression_list" << endl;
        }
    ;

unary_expression
    : postfix_expression             { $<ExpressionNode *>$ = $1; cout << "postfix_expression REDUCE unary_expression" << endl;}
    | INC_OP unary_expression        { $<ExpressionNode *>$ = new ExpressionNode($2,$1,""); cout << "INC_OP unary_expression REDUCE unary_expression" << endl;}
    | DEC_OP unary_expression        { $<ExpressionNode *>$ = new ExpressionNode($2,$1,""); cout << "DEC_OP unary_expression REDUCE unary_expression" << endl;}
    | unary_operator cast_expression { $<ExpressionNode *>$ = new ExpressionNode($2,$1,""); cout << "unary_operator cast_expression REDUCE unary_expression" << endl;}
    | SIZEOF unary_expression        { $<ExpressionNode *>$ = new ExpressionNode($2,$1,""); cout << "SIZEOF unary_expression REDUCE unary_expression" << endl;}
    | SIZEOF OPAREN type_name CPAREN { $<ExpressionNode *>$ = new ExpressionNode($3,$1); cout << "SIZEOF OPAREN type_name CPAREN REDUCE unary_expression" << endl;}
    ;

unary_operator
    : BIT_AND   {$<int>$ = $1; cout << "BIT_AND REDUCE to unary_operator" << endl;}
    | TIMES_OP  {$<int>$ = $1; cout << "TIMES_OP REDUCE to unary_operator" << endl;}
    | PLUS_OP   {$<int>$ = $1; cout << "PLUS_OP REDUCE to unary_operator" << endl;}
    | MINUS_OP  {$<int>$ = $1; cout << "MINUS_OP REDUCE to unary_operator" << endl;}
    | TILDE     {$<int>$ = $1; cout << "TILDE REDUCE to unary_operator" << endl;}
    | NOT_OP    {$<int>$ = $1; cout << "NOT_OP REDUCE to unary_operator" << endl;}
    ;

cast_expression
    : unary_expression                         { $<ExpressionNode *>$ = $1;  cout << "unary_expression REDUCE to cast_expression" << endl;}
    | OPAREN type_name CPAREN cast_expression  { $<ExpressionNode *>$ = new ExpressionNode($2,$4);  cout << "unary_expression REDUCE to cast_expression" << endl;}
    ;

multiplicative_expression
    : cast_expression                                    { $<ExpressionNode *>$ = $1;  cout << "cast_expression REDUCE to multiplicative_expression" << endl;}
    | multiplicative_expression TIMES_OP cast_expression { $<ExpressionNode *>$ = new ExpressionNode($1,$2,$3); cout << "multiplicative_expression TIMES_OP cast_expression REDUCE to multiplicative_expression" << endl;}
    | multiplicative_expression DIV_OP cast_expression   { $<ExpressionNode *>$ = new ExpressionNode($1,$2,$3);cout << "multiplicative_expression DIV_OP cast_expression REDUCE to multiplicative_expression" << endl;}
    | multiplicative_expression MOD_OP cast_expression   { $<ExpressionNode *>$ = new ExpressionNode($1,$2,$3); cout << "multiplicative_expression MOD_OP cast_expression REDUCE to multiplicative_expression" << endl;}
    ;

additive_expression
    : multiplicative_expression                               { $<ExpressionNode *>$ = $1;  cout << "multiplicative_expression REDUCE to additive_expression" << endl;}
    | additive_expression PLUS_OP multiplicative_expression   { $<ExpressionNode *>$ = new ExpressionNode($1,$2,$3); cout << "additive_expression REDUCE to multiplicative_expression" << endl;}
    | additive_expression MINUS_OP multiplicative_expression  { $<ExpressionNode *>$ = new ExpressionNode($1,$2,$3); cout << "additive_expression REDUCE to multiplicative_expression" << endl;}
    ;

shift_expression
    : additive_expression                           { $<ExpressionNode *>$ = $1;  cout << "additive_expression REDUCE to shift_expression" << endl;}
    | shift_expression LEFT_OP additive_expression  { $<ExpressionNode *>$ = new ExpressionNode($1,$2,$3); cout << "shift_expression LEFT_OP additive_expression REDUCE to shift_expression" << endl;}
    | shift_expression RIGHT_OP additive_expression { $<ExpressionNode *>$ = new ExpressionNode($1,$2,$3); cout << "shift_expression RIGHT_OP additive_expression REDUCE to shift_expression" << endl;}
    ;

relational_expression
    : shift_expression                                       { $<ExpressionNode *>$ = $1;  cout << "shift_expression REDUCE to relational_expression" << endl;}
    | relational_expression LESS shift_expression            { $<ExpressionNode *>$ = new ExpressionNode($1,$2,$3); cout << "relational_expression LESS shift_expression REDUCE to shift_expression" << endl;}
    | relational_expression GREATER shift_expression         { $<ExpressionNode *>$ = new ExpressionNode($1,$2,$3); cout << "relational_expression GREATER shift_expression REDUCE to shift_expression" << endl;}
    | relational_expression LESS_EQUAL shift_expression      { $<ExpressionNode *>$ = new ExpressionNode($1,$2,$3); cout << "relational_expression LESS_EQUAL shift_expression REDUCE to shift_expression" << endl;}
    | relational_expression GREATER_EQUAL shift_expression   { $<ExpressionNode *>$ = new ExpressionNode($1,$2,$3); cout << "relational_expression GREATER_EQUAL shift_expression REDUCE to shift_expression" << endl;}
    ;

equality_expression
    : relational_expression                                  { $<ExpressionNode *>$ = $1;  cout << "relational_expression REDUCE to equality_expression" << endl;}
    | equality_expression EQUAL_EQUAL relational_expression  { $<ExpressionNode *>$ = new ExpressionNode($1,$2,$3); cout << "equality_expression EQUAL_EQUAL relational_expression REDUCE to equality_expression" << endl;}
    | equality_expression NOT_EQUAL relational_expression    { $<ExpressionNode *>$ = new ExpressionNode($1,$2,$3); cout << "equality_expression NOT_EQUAL relational_expression REDUCE to equality_expression" << endl;}
    ;

and_expression
    : equality_expression                         { $<ExpressionNode *>$ = $1;  cout << "equality_expression REDUCE to and_expression" << endl;}
    | and_expression BIT_AND equality_expression  { $<ExpressionNode *>$ = new ExpressionNode($1,$2,$3); cout << "and_expression BIT_AND equality_expression REDUCE to and_expression" << endl;}
    ;

exclusive_or_expression
    : and_expression                                 { $<ExpressionNode *>$ = $1;  cout << "and_expression REDUCE to exclusive_or_expression" << endl;}
    | exclusive_or_expression XOR_OP and_expression  { $<ExpressionNode *>$ = new ExpressionNode($1,$2,$3); cout << "exclusive_or_expression XOR_OP and_expression REDUCE to exclusive_or_expression" << endl;}
    ;

inclusive_or_expression
    : exclusive_or_expression                                { $<ExpressionNode *>$ = $1;  cout << "exclusive_or_expression REDUCE to inclusive_or_expression" << endl;}
    | inclusive_or_expression BIT_OR exclusive_or_expression { $<ExpressionNode *>$ = new ExpressionNode($1,$2,$3); cout << "inclusive_or_expression BIT_OR exclusive_or_expression REDUCE to inclusive_or_expression" << endl;}
    ;

logical_and_expression
    : inclusive_or_expression                                { $<ExpressionNode *>$ = $1;  cout << "inclusive_or_expression REDUCE to logical_and_expression" << endl;}
    | logical_and_expression AND_OP inclusive_or_expression  { $<ExpressionNode *>$ = new ExpressionNode($1,$2,$3); cout << "inclusive_or_expression REDUCE to logical_and_expression" << endl;}
    ;

logical_or_expression
    : logical_and_expression                              { $<ExpressionNode *>$ = $1;  cout << "inclusive_and_expression REDUCE to logical_or_expression" << endl;}
    | logical_or_expression OR_OP logical_and_expression  { $<ExpressionNode *>$ = new ExpressionNode($1,$2,$3); cout << "logical_or_expression OR_OP logical_and_expression REDUCE to logical_or_expression" << endl;}
    ;

conditional_expression
    : logical_or_expression                                                   { $<ExpressionNode *>$ = $1;  cout << "logical_or_expression REDUCE to conditional_expression" << endl;}
    | logical_or_expression QUESTION expression COLON conditional_expression  { $<ExpressionNode *>$ = new ExpressionNode($1,$2,$3); cout << "logical_or_expression QUESTION expression COLON conditional_expression REDUCE to conditional_expression" << endl;}
    ;

assignment_expression
    : conditional_expression                                      { $<ExpressionNode *>$ = $1;  cout << "conditional_expression REDUCE to assignment_expression" << endl;}
    | unary_expression assignment_operator assignment_expression  { $<ExpressionNode *>$ = new ExpressionNode($1,$2,$3); cout << "unary_expression assignment_operator assignment_expression REDUCE to assignment_expression" << endl;}
    ;

assignment_operator
    : EQUAL          { $<int>$ = $1;  cout << "EQUAL_OP REDUCE to assignment_operator" << endl;}
    | MUL_ASSIGN     { $<int>$ = $1;  cout << "MUL_ASSIGN REDUCE to assignment_operator" << endl;}
    | DIV_ASSIGN     { $<int>$ = $1;  cout << "DIV_ASSIGN REDUCE to assignment_operator" << endl;}
    | MOD_ASSIGN     { $<int>$ = $1;  cout << "MOG_ASSIGN REDUCE to assignment_operator" << endl;}
    | ADD_ASSIGN     { $<int>$ = $1;  cout << "ADD_ASSIGN REDUCE to assignment_operator" << endl;}
    | SUB_ASSIGN     { $<int>$ = $1;  cout << "SUB_ASSIGN REDUCE to assignment_operator" << endl;}
    | LEFT_ASSIGN    { $<int>$ = $1;  cout << "LEFT_ASSIGN REDUCE to assignment_operator" << endl;}
    | RIGHT_ASSIGN   { $<int>$ = $1;  cout << "RIGHT_ASSIGN REDUCE to assignment_operator" << endl;}
    | AND_ASSIGN     { $<int>$ = $1;  cout << "AND_ASSIGN REDUCE to assignment_operator" << endl;}
    | XOR_ASSIGN     { $<int>$ = $1;  cout << "XOR_ASSIGN REDUCE to assignment_operator" << endl;}
    | OR_ASSIGN      { $<int>$ = $1;  cout << "OR_ASSIGN REDUCE to assignment_operator" << endl;}
    ;

expression
    : assignment_expression                   { $<ExpressionNode *>$ = $1;  cout << "asignment_expression REDUCE to expression" << endl;}
    | expression COMMA assignment_expression  { $<ExpressionNode *>$ = new ExpressionNode($1,$2,$3); cout << "expression COMMA assignment_expression COMMA  REDUCE to expression" << endl;}
    ;

constant_expression
    : conditional_expression  { $<ExpressionNode *>$ = $1;  cout << "conditional_expression REDUCE to constant_expression" << endl;}
    ;

declaration
    : declaration_specifiers SEMICOLON                       { $<Declaration *>$ = new Declaration($1); cout << "declaration_specifiers SEMICOLON REDUCE to declaration" << endl;}
    | declaration_specifiers init_declarator_list SEMICOLON  { $<Declaration *>$ = new Declaration($1,$2); cout << "declaration_specifiers init_declarator_list SEMICOLON REDUCE to declaration" << endl;}
    ;

declaration_specifiers
    : storage_class_specifier                         { $<DeclarationSpecifiers *>$ = new DeclarationSpecifiers($1); cout << "storage_class_specifier REDUCE to declaration_specifiers" << endl;}
    | storage_class_specifier declaration_specifiers  { $<DeclarationSpecifiers *>$ = new DeclarationSpecifiers($1,$2); cout << "storage_class_specifier declaration_specifiers REDUCE to declaration_specifiers" << endl;}
    | type_specifier                                  { $<DeclarationSpecifiers *>$ = new DeclarationSpecifiers($1); cout << "type_specifier REDUCE to declaration_specifiers" << endl;}
    | type_specifier declaration_specifiers           { $<DeclarationSpecifiers *>$ = new DeclarationSpecifiers($1,$2); cout << "type_specifier declaration_specifiers REDUCE to declaration_specifiers" << endl;}
    | type_qualifier                                  { $<DeclarationSpecifiers *>$ = new DeclarationSpecifiers($1); cout << "type_qualifier REDUCE to declaration_specifiers" << endl;}
    | type_qualifier declaration_specifiers           { $<DeclarationSpecifiers *>$ = new DeclarationSpecifiers($1,$2); cout << "type_qualifier declaration_specifiers REDUCE to declaration_specifiers" << endl;}
    ;

init_declarator_list
    : init_declarator                            {
                                                  InitDeclarator* exp = $1;
                                                  $$ = new std::vector<InitDeclarator*>();
                                                  $$->push_back(exp);
                                                  cout << "init_declarator REDUCE to init_declarator_list" << endl;
                                                 }
    | init_declarator_list COMMA init_declarator {
                                                  InitDeclarator* value1 = $3;
                                                  std::vector<InitDeclarator*>* value2 = $1;
                                                  value2->push_back(value1);
                                                  $$ = value2;
                                                  cout << "init_declarator_list COMMA init_declarator REDUCE to init_declarator_list" << endl;
                                                 }
    ;

init_declarator
    : declarator                    { $<InitDeclarator *>$ = new InitDeclarator($1); cout << "declarator REDUCE to init_declarator" << endl;}
    | declarator EQUAL initializer  { $<InitDeclarator *>$ = new InitDeclarator($1,$3); cout << "declarator EQUAL initializer REDUCE to init_declarator" << endl;}
    ;

storage_class_specifier
    : TYPEDEF   { $<StorageClassSpecifier *>$ = new StorageClassSpecifier($1,TYPEDEF); cout << "TYPEDEF REDUCE to storage_class_specifier" << endl;}
    | EXTERN    { $<StorageClassSpecifier *>$ = new StorageClassSpecifier($1,EXTERN); cout << "EXTERN REDUCE to storage_class_specifier" << endl;}
    | STATIC    { $<StorageClassSpecifier *>$ = new StorageClassSpecifier($1,STATIC); cout << "STATIC REDUCE to storage_class_specifier" << endl;}
    | AUTO      { $<StorageClassSpecifier *>$ = new StorageClassSpecifier($1,AUTO); cout << "AUTO REDUCE to storage_class_specifier" << endl;}
    | REGISTER  { $<StorageClassSpecifier *>$ = new StorageClassSpecifier($1,REGISTER); cout << "REGISTER REDUCE to storage_class_specifier" << endl;}
    ;

type_specifier
    : VOID                      { $<TypeSpecifier *>$ = new TypeSpecifier(VOID); cout << "VOID REDUCE to type_specifier" << endl;}
    | CHAR                      { $<TypeSpecifier *>$ = new TypeSpecifier(CHAR); cout << "CHAR REDUCE to type_specifier" << endl;}
    | SHORT                     { $<TypeSpecifier *>$ = new TypeSpecifier(SHORT); cout << "SHORT REDUCE to type_specifier" << endl;}
    | INT                       { $<TypeSpecifier *>$ = new TypeSpecifier(INT); cout << "INT REDUCE to type_specifier" << endl;}
    | LONG                      { $<TypeSpecifier *>$ = new TypeSpecifier(LONG); cout << "LONG REDUCE to type_specifier" << endl;}
    | LONG_LONG                 { $<TypeSpecifier *>$ = new TypeSpecifier(LONG_LONG); cout << "LONG_LONG REDUCE to type_specifier" << endl;}
    | FLOAT                     { $<TypeSpecifier *>$ = new TypeSpecifier(FLOAT); cout << "FLOAT REDUCE to type_specifier" << endl;}
    | DOUBLE                    { $<TypeSpecifier *>$ = new TypeSpecifier(DOUBLE); cout << "DOUBLE REDUCE to type_specifier" << endl;}
    | LONG_DOUBLE               { $<TypeSpecifier *>$ = new TypeSpecifier(LONG_DOUBLE); cout << "LONG_DOUBLE REDUCE to type_specifier" << endl;}
    | BOOL                      { $<TypeSpecifier *>$ = new TypeSpecifier(BOOL); cout << "BOOL REDUCE to type_specifier" << endl;}
    | IMAGINARY                 { $<TypeSpecifier *>$ = new TypeSpecifier(IMAGINARY); cout << "IMAGINARY REDUCE to type_specifier" << endl;}
    | COMPLEX                   { $<TypeSpecifier *>$ = new TypeSpecifier(COMPLEX); cout << "COMPLEX REDUCE to type_specifier" << endl;}
    | SIGNED                    { $<TypeSpecifier *>$ = new TypeSpecifier(SIGNED); cout << "SIGNED REDUCE to type_specifier" << endl;}
    | UNSIGNED                  { $<TypeSpecifier *>$ = new TypeSpecifier(UNSIGNED); cout << "UNIGNED REDUCE to type_specifier" << endl;}
    | struct_or_union_specifier { $<TypeSpecifier *>$ = new TypeSpecifier($1); cout << "struct_or_union_specifier REDUCE to type_specifier" << endl;}
    | enum_specifier            { $<TypeSpecifier *>$ = new TypeSpecifier($1); cout << "enum_specifier REDUCE to type_specifier" << endl;}
    | TYPE_NAME                 { $<TypeSpecifier *>$ = new TypeSpecifier(TYPE_NAME); cout << "TYPE_NAME REDUCE to type_specifier" << endl;}
    ;

struct_or_union_specifier
    : struct_or_union IDENTIFIER OCURLY struct_declaration_list CCURLY   { $<StructOrUnionSpecifier *>$ = new StructOrUnionSpecifier($1,$2,$4); cout << "struct_or_union IDENTIFIER OCURLY struct_declaration_list CCURLY REDUCE to struct_or_union_specifier" << endl;}
    | struct_or_union OCURLY struct_declaration_list CCURLY              { $<StructOrUnionSpecifier *>$ = new StructOrUnionSpecifier($1,$3); cout << "struct_or_union OCURLY struct_declaration_list CCURLY REDUCE to struct_or_union_specifier" << endl;}
    | struct_or_union IDENTIFIER                                         { $<StructOrUnionSpecifier *>$ = new StructOrUnionSpecifier($1,$2); cout << "struct_or_union IDENTIFIER REDUCE to struct_or_union_specifier" << endl;}
    ;

struct_or_union
    : STRUCT   { $<StructOrUnion *>$ = new StructOrUnion(STRUCT); cout << "STRUCT REDUCE to struct_or_union" << endl;}
    | UNION    { $<StructOrUnion *>$ = new StructOrUnion(UNION); cout << "UNION REDUCE to struct_or_union" << endl;}
    ;

struct_declaration_list
    : struct_declaration    {
                             StructDeclaration* exp = $1;
                             $$ = new std::vector<StructDeclaration *>();
                             $$->push_back(exp);
                             cout << "struct_declaration REDUCE to struct_declaration_list" << endl;
                            }
    | struct_declaration_list struct_declaration     {
                                                       StructDeclaration* value1 = $2;
                                                       std::vector<StructDeclaration *>* value2 = $1;
                                                       value2->push_back(value1);
                                                       $$ = value2;
                                                       cout << "struct_declaration_list struct_declaration REDUCE to struct_declaration_list" << endl;
                                                     }
    ;

struct_declaration
    : specifier_qualifier_list struct_declarator_list SEMICOLON { $<StructDeclaration *>$ = new StructDeclaration($1,$2); cout << "specifier_qualifier_list struct_declarator_list SEMICOLON REDUCE to struct_declaration" << endl;}
    ;

specifier_qualifier_list
    : type_specifier specifier_qualifier_list { $<SpecifierQualifierList *>$ = new SpecifierQualifierList($2,$1); cout << "type_specifier specifier_qualifier_list REDUCE to specifier_qualifier_list" << endl;}
    | type_specifier                          { $<SpecifierQualifierList *>$ = new SpecifierQualifierList($1); cout << "type_specifier REDUCE to specifier_qualifier_list" << endl;}
    | type_qualifier specifier_qualifier_list { $<SpecifierQualifierList *>$ = new SpecifierQualifierList($2,$1); cout << "type_qualifier specifier_qualifier_list REDUCE to specifier_qualifier_list" << endl;}
    | type_qualifier                          { $<SpecifierQualifierList *>$ = new SpecifierQualifierList($1); cout << "type_qualifier REDUCE to specifier_qualifier_list" << endl;}
    ;

struct_declarator_list
    : struct_declarator                              {
                                                       StructDeclarator* exp = $1;
                                                       $$ = new std::vector<StructDeclarator *>();
                                                       $$->push_back(exp);
                                                       cout << "struct_declarator REDUCE to struct_declarator_list" << endl;
                                                     }
    | struct_declarator_list COMMA struct_declarator {
                                                       StructDeclarator* value1 = $3;
                                                       std::vector<StructDeclarator*>* value2 = $1;
                                                       value2->push_back(value1);
                                                       $$ = value2;
                                                       cout << "struct_declarator_list COMMA struct_declarator REDUCE to struct_declarator_list" << endl;
                                                     }
    ;

struct_declarator
    : declarator                           { $<StructDeclarator *>$ = new StructDeclarator($1); cout << "declarator REDUCE to struct_declarator" << endl;}
    | COLON constant_expression            { $<StructDeclarator *>$ = new StructDeclarator($2); cout << "COLON constant_expression REDUCE to struct_declarator" << endl;}
    | declarator COLON constant_expression { $<StructDeclarator *>$ = new StructDeclarator($1,$3); cout << "declarator COLON constant_expression REDUCE to struct_declarator" << endl;}
    ;

enum_specifier
    : ENUM OCURLY enumerator_list CCURLY             { $<EnumSpecifier *>$ = new EnumSpecifier($3); cout << "ENUM OCURLY enumerator_list CCURLY REDUCE to enum_specifier" << endl;}
    | ENUM IDENTIFIER OCURLY enumerator_list CCURLY  { $<EnumSpecifier *>$ = new EnumSpecifier($2,$4); cout << "ENUM IDENTIFIER OCURLY enumerator_list CCURLY REDUCE to enum_specifier" << endl;}
    | ENUM IDENTIFIER                                { $<EnumSpecifier *>$ = new EnumSpecifier($2); cout << "ENUM IDENTIFIER REDUCE to enum_specifier" << endl;}
    ;

enumerator_list
    : enumerator                        {
                                          Enumerator* exp = $1;
                                          $$ = new std::vector<Enumerator *>();
                                          $$->push_back(exp);
                                          cout << "enumerator REDUCE enumerator_list" << endl;
                                        }
    | enumerator_list COMMA enumerator  {
                                          Enumerator* value1 = $3;
                                          std::vector<Enumerator*>* value2 = $1;
                                          value2->push_back(value1);
                                          $$ = value2;
                                          cout << "enumerator_list COMMA enumerator REDUCE enumerator_list" << endl;
                                        }
    ;

enumerator
    : IDENTIFIER                           { $<Enumerator *>$ = new Enumerator($1); cout << "IDENTIFIER REDUCE to ENUMERATOR" << endl;}
    | IDENTIFIER EQUAL constant_expression { $<Enumerator *>$ = new Enumerator($1,$3); cout << "IDENTIFIER EQUAL constant_expression REDUCE to ENUMERATOR" << endl;}
    ;

type_qualifier
    : CONST    { $<TypeQualifier *>$ = new TypeQualifier($1,CONST); cout << "CONST REDUCE to type_qualifier" << endl;}
    | VOLATILE { $<TypeQualifier *>$ = new TypeQualifier($1,VOLATILE); cout << "VOLATILE REDUCE to type_qualifier" << endl;}
    ;

declarator
    : pointer direct_declarator { $<Declarator *>$ = new Declarator($1,$2); cout << "pointer direct_declarator REDUCE to declarator" << endl;}
    | direct_declarator         { $<Declarator *>$ = new Declarator($1); cout << "direct_declarator REDUCE to declarator" << endl;}
    ;

direct_declarator
    : IDENTIFIER                                            { $<DirectDeclarator *>$ = new DirectDeclarator($1); cout << "IDENTIFIER REDUCE to direct_declarator" << endl;}
    | OPAREN declarator CPAREN                              { $<DirectDeclarator *>$ = new DirectDeclarator("",$2); cout << "OPAREN declarator CPAREN REDUCE to direct_declarator" << endl;}
    | direct_declarator OBRACE constant_expression CBRACE   { $<DirectDeclarator *>$ = new DirectDeclarator($1,$3); cout << "direct_declarator OBRACE constant_expression CBRACE REDUCE to direct_declarator" << endl;}
    | direct_declarator OBRACE CBRACE                       { $<DirectDeclarator *>$ = new DirectDeclarator($1,$2,$3); cout << "direct_declarator OBRACE CBRACE REDUCE to direct_declarator" << endl;}
    | direct_declarator OPAREN parameter_type_list CPAREN   { $<DirectDeclarator *>$ = new DirectDeclarator($1,$3); cout << "direct_declarator OPAREN parameter_type_list CPAREN to direct_declarator" << endl;}
    | direct_declarator OPAREN identifier_list CPAREN       { $<DirectDeclarator *>$ = new DirectDeclarator($1,$3); cout << "direct_declarator OPAREN identifier_list CPAREN REDUCE to direct_declarator" << endl;}
    | direct_declarator OPAREN CPAREN                       { $<DirectDeclarator *>$ = new DirectDeclarator($1,$2,$3); cout << "direct_declarator OPAREN CPAREN REDUCE to direct_declarator" << endl;}
    ;

pointer
    : TIMES_OP                              {$<Pointer *>$ = new Pointer($1); cout << "TIMES_OP REDUCE to POINTER" << endl;}
    | TIMES_OP type_qualifier_list          {$<Pointer *>$ = new Pointer($1,$2); cout << "TIMES_OP type_qualifier_list REDUCE to POINTER" << endl;}
    | TIMES_OP pointer                      {$<Pointer *>$ = new Pointer($1,$2); $<Pointer *>$->inc(); cout << "TIMES_OP pointer REDUCE to POINTER" << endl;}
    | TIMES_OP type_qualifier_list pointer  {$<Pointer *>$ = new Pointer($1,$2,$3); $<Pointer *>$->inc(); cout << "TIMES_OP type_qualifier_list pointer REDUCE to POINTER" << endl;}
    ;

type_qualifier_list
    : type_qualifier        {
                             TypeQualifier* exp = $1;
                             $$ = new std::vector<TypeQualifier*>();
                             $$->push_back(exp);
                             cout << "type_qualifier REDUCE type_qualifier_list" << endl;
                            }
    | type_qualifier_list type_qualifier {
                                          TypeQualifier* value1 = $2;
                                          std::vector<TypeQualifier *>* value2 = $1;
                                          value2->push_back(value1);
                                          $$ = value2;
                                          cout << "type_qualifier_list type_qualifier REDUCE type_qualifier_list" << endl;
                                        }
    ;


parameter_type_list
    : parameter_list                  { $<ParameterTypeList *>$ = new ParameterTypeList($1,NONE); cout << "parameter_list REDUCE to parameter_type_list" << endl; }
    | parameter_list COMMA ELLIPSIS   { $<ParameterTypeList *>$ = new ParameterTypeList($1,$2); cout << "parameter_list COMMA ELLIPSIS REDUCE to parameter_type_list" << endl; }
    ;

parameter_list
    : parameter_declaration                       {
                                                    ParameterDeclaration* exp = $1;
                                                    $$ = new std::vector<ParameterDeclaration*>();
                                                    $$->push_back(exp);
                                                    cout << "parameter_declaration REDUCE to parameter_list" << endl;
                                                  }
    | parameter_list COMMA parameter_declaration  {
                                                    ParameterDeclaration* value1 = $3;
                                                    std::vector<ParameterDeclaration*>* value2 = $1;
                                                    value2->push_back(value1);
                                                    $$ = value2;
                                                    cout << "parameter_list COMMA parameter_declaration REDUCE to parameter_list" << endl;
                                                  }
    ;

parameter_declaration
    : declaration_specifiers declarator           { $<ParameterDeclaration *>$ = new ParameterDeclaration($1,$2); cout << "declaration_specifiers declarator REDUCE to parameter_declaration" << endl; }
    | declaration_specifiers abstract_declarator  { $<ParameterDeclaration *>$ = new ParameterDeclaration($1,$2); cout << "declaration_specifiers abstract_declarator REDUCE to parameter_declaration" << endl; }
    | declaration_specifiers                      { $<ParameterDeclaration *>$ = new ParameterDeclaration($1); cout << "declaration_specifiers REDUCE to parameter_declaration" << endl; }
    ;

identifier_list
    : IDENTIFIER                       {
                                          std::string exp = $1;
                                          $$ = new std::vector<std::string>();
                                          $$->push_back(exp);
                                          cout << "IDENTIFIER REDUCE to identifier_list" << endl;
                                       }
    | identifier_list COMMA IDENTIFIER {
                                          std::string value1 = $3;
                                          std::vector<std::string> *value2 = $1;
                                          value2->push_back(value1);
                                          $$ = value2;
                                          cout << "identifier_list COMMA IDENTIFIER REDUCE to identifier_list" << endl; 
                                        }
    ;

type_name
    : specifier_qualifier_list                     { $<TypeName *>$ = new TypeName($1); cout << "specifier_qualifier_list REDUCE to type_name" << endl; }
    | specifier_qualifier_list abstract_declarator { $<TypeName *>$ = new TypeName($1,$2); cout << "specifier_qualifier_list abstract_declarator REDUCE to type_name" << endl; }
    ;

abstract_declarator
    : pointer                             { $<AbstractDeclarator *>$ = new AbstractDeclarator($1); cout << "pointer REDUCE to abstract_declarator" << endl; }
    | direct_abstract_declarator          { $<AbstractDeclarator *>$ = new AbstractDeclarator($1); cout << "direct_abstract_declarator REDUCE to abstract_declarator" << endl; }
    | pointer direct_abstract_declarator  { $<AbstractDeclarator *>$ = new AbstractDeclarator($1,$2); cout << "pointer direct_abstract_declarator REDUCE to abstract_declarator" << endl; }
    ;

direct_abstract_declarator
    : OPAREN abstract_declarator CPAREN                            { $<DirectAbstractDeclarator *>$ = new DirectAbstractDeclarator($2); cout << "OPAREN abstract_declarator CPAREN REDUCE to direct_abstract_declarator" << endl; }
    | OBRACE CBRACE                                                { $<DirectAbstractDeclarator *>$ = new DirectAbstractDeclarator(ARRAY); cout << "OBRACE CBRACE REDUCE to direct_abstract_declarator" << endl; }
    | OBRACE constant_expression CBRACE                            { $<DirectAbstractDeclarator *>$ = new DirectAbstractDeclarator($2); cout << "OBRACE constant_expression CBRACE REDUCE to direct_abstract_declarator" << endl; }
    | direct_abstract_declarator OBRACE CBRACE                     { $<DirectAbstractDeclarator *>$ = new DirectAbstractDeclarator($1,ARRAY); cout << "direct_abstract_declarator OBRACE CBRACE REDUCE to direct_abstract_declarator" << endl; }
    | direct_abstract_declarator OBRACE constant_expression CBRACE { $<DirectAbstractDeclarator *>$ = new DirectAbstractDeclarator($1,$3,ARRAY); cout << "direct_abstract_declarator OBRACE constant_expression CBRACE REDUCE to direct_abstract_declarator" << endl; }
    | OPAREN CPAREN                                                { $<DirectAbstractDeclarator *>$ = new DirectAbstractDeclarator(FUNCTION); cout << "OPAREN CPAREN REDUCE to direct_abstract_declarator" << endl; }
    | OPAREN parameter_type_list CPAREN                            { $<DirectAbstractDeclarator *>$ = new DirectAbstractDeclarator($2,FUNCTION); cout << "OPAREN parameter_type_list CPAREN REDUCE to direct_abstract_declarator" << endl; }
    | direct_abstract_declarator OPAREN CPAREN                     { $<DirectAbstractDeclarator *>$ = new DirectAbstractDeclarator($1,FUNCTION); cout << "direct_abstract_declarator OPAREN CPAREN REDUCE to direct_abstract_declarator" << endl; }
    | direct_abstract_declarator OPAREN parameter_type_list CPAREN { $<DirectAbstractDeclarator *>$ = new DirectAbstractDeclarator($1,$3,FUNCTION); cout << "direct_abstract_declarator OPAREN parameter_type_list CPAREN REDUCE to direct_abstract_declarator" << endl; }
    ;

initializer
    : assignment_expression                { $<Initializer *>$ = new Initializer($1); cout << "assignment_expression REDUCE to initializer" << endl; }
    | OCURLY initializer_list CCURLY       { $<Initializer *>$ = new Initializer($2); cout << "OCURLY initializer_list CCURLY REDUCE to initializer" << endl; }
    | OCURLY initializer_list COMMA CCURLY { $<Initializer *>$ = new Initializer($2); cout << "OCURLY initializer_list COMMA CCURLY REDUCE to initializer" << endl; }
    ;

initializer_list
    : initializer                         {
                                           Initializer* exp = $1;
                                           $$ = new std::vector<Initializer*>();
                                           $$->push_back(exp);
                                           cout << "initializer REDUCE to initializer_list" << endl;
                                          }
    | initializer_list COMMA initializer  {
                                           Initializer* value1 = $3;
                                           std::vector<Initializer*> *value2 = $1;
                                           value2->push_back(value1);
                                           $$ = value2;
                                           cout << "initializer_list COMMA initializer REDUCE to initializer_list" << endl;
                                          }
    ;

statement
    : labeled_statement    { $<BaseStatement *>$ = new Statement(NONE,$1); cout << "labeled_statement REDUCE to statement" << endl; }
    | compound_statement   { $<BaseStatement *>$ = new Statement(NONE,$1); cout << "compound_statement REDUCE to statement" << endl; }
    | expression_statement { $<BaseStatement *>$ = new Statement(NONE,$1); cout << "expression_statement REDUCE to statement" << endl; }
    | selection_statement  { $<BaseStatement *>$ = new Statement(NONE,$1); cout << "selection_statement REDUCE to statement" << endl; }
    | iteration_statement  { $<BaseStatement *>$ = new Statement(NONE,$1); cout << "iteration_statement REDUCE to statement" << endl; }
    | jump_statement       { $<BaseStatement *>$ = new Statement(NONE,$1); cout << "jump_statement REDUCE to statement" << endl; }
    ;

labeled_statement
    : IDENTIFIER COLON statement               { $<BaseStatement *>$ = new LabeledStatement($1,$3); cout << "IDENTIFIER COLON statement REDUCE to label_statement" << endl; }
    | CASE constant_expression COLON statement { $<BaseStatement *>$ = new LabeledStatement(CASE,$2,$4); cout << "CASE constant_expression COLON statement REDUCE to label_statement" << endl; }
    | DEFAULT COLON statement                  { $<BaseStatement *>$ = new LabeledStatement(DEFAULT,$3); cout << "DEFAULT COLON statement REDUCE to label_statement" << endl; }
    ;

compound_statement
    : OCURLY CCURLY                                 { $<BaseStatement *>$ = new CompoundStatement(); cout << "OCURLY CCURLY REDUCE to compound_statement" << endl; }
    | OCURLY statement_list CCURLY                  { $<BaseStatement *>$ = new CompoundStatement($2); cout << "OCURLY statement_list CCURLY REDUCE to compound_statement" << endl; }
    | OCURLY declaration_list CCURLY                { $<BaseStatement *>$ = new CompoundStatement($2); cout << "OCURLY declaration_list CCURLY REDUCE to compound_statement" << endl; }
    | OCURLY declaration_list statement_list CCURLY { $<BaseStatement *>$ = new CompoundStatement($3,$2); cout << "OCURLY declaration_list statement_list CCURLY REDUCE to compound_statement" << endl; }
    ;

declaration_list
    : declaration                   {
                                     Declaration* exp = $1;
                                     $$ = new std::vector<Declaration*>();
                                     $$->push_back(exp);
                                     cout << "declaration REDUCE to declaration_list" << endl;
                                    }
    | declaration_list declaration  {
                                     Declaration* value1 = $2;
                                     std::vector<Declaration*> *value2 = $1;
                                     value2->push_back(value1);
                                     $$ = value2;
                                     cout << "declaration_list declaration REDUCE to declaration_list" << endl;
                                    }
    ;

statement_list
    : statement                   {
                                    BaseStatement* exp = $1;
                                    $$ = new std::vector<BaseStatement*>();
                                    $$->push_back(exp);
                                    cout << "statement REDUCE to statement_list" << endl;
                                  }
    | statement_list statement    {
                                    BaseStatement* value1 = $2;
                                    std::vector<BaseStatement*>* value2 = $1;
                                    value2->push_back(value1);
                                    $$ = value2;
                                    cout << "statement_list statement REDUCE to statement_list" << endl;
                                  }
    ;

expression_statement
    : SEMICOLON             { $<BaseStatement *>$ = new ExpressionStatement(); cout << "SEMICOLON REDUCE to expression_statement" << endl; }
    | expression SEMICOLON  { $<BaseStatement *>$ = new ExpressionStatement($1); cout << "expression SEMICOLON REDUCE to expression_statement" << endl; }
    ;

selection_statement
    : IF OPAREN expression CPAREN statement                { $<BaseStatement *>$ = new SelectionStatement(IF,$3,$5); cout << "IF OPAREN expression CPAREN statement REDUCE to selection_statement" << endl; }
    | IF OPAREN expression CPAREN statement ELSE statement { $<BaseStatement *>$ = new SelectionStatement(IF,$3,$5,$7); cout << "IF OPAREN expression CPAREN statement ELSE statement REDUCE to selection_statement" << endl; }
    | SWITCH OPAREN expression CPAREN statement            { $<BaseStatement *>$ = new SelectionStatement(SWITCH,$3,$5); cout << "SWITCH OPAREN expression CPAREN statement REDUCE to selection_statement" << endl; }
    ;

iteration_statement
    : WHILE OPAREN expression CPAREN statement                                         { $<BaseStatement *>$ = new IterationStatement(WHILE,$3,$5); cout << "WHILE OPAREN expression CPAREN statement REDUCE to iteration_statement" << endl; }
    | DO statement WHILE OPAREN expression CPAREN SEMICOLON                            { $<BaseStatement *>$ = new IterationStatement(DO,$5,$2); cout << "DO statement WHILE OPAREN expression CPAREN SEMICOLON REDUCE to iteration_statement" << endl; }
    | FOR OPAREN expression_statement expression_statement CPAREN statement            { $<BaseStatement *>$ = new IterationStatement(FOR,$3,$4,$6); cout << "FOR OPAREN expression_statement expression_statement CPAREN statement REDUCE to iteration_statement" << endl; }
    | FOR OPAREN expression_statement expression_statement expression CPAREN statement { $<BaseStatement *>$ = new IterationStatement(FOR,$3,$4,$5,$7); cout << "FOR OPAREN expression_statement expression_statement expression CPAREN statement REDUCE to iteration_statement" << endl; }
    ;

jump_statement
    : GOTO IDENTIFIER SEMICOLON   { $<BaseStatement *>$ = new JumpStatement(GOTO,$2); cout << "GOTO IDENTIFIER SEMICOLON REDUCE to jump_statement" << endl; }
    | CONTINUE SEMICOLON          { $<BaseStatement *>$ = new JumpStatement(CONTINUE); cout << "CONTINUE SEMICOLON REDUCE to jump_statement" << endl; }
    | BREAK SEMICOLON             { $<BaseStatement *>$ = new JumpStatement(BREAK); cout << "BREAK SEMICOLON REDUCE to jump_statement" << endl; }
    | RETURN SEMICOLON            { $<BaseStatement *>$ = new JumpStatement(RETURN); cout << "RETURN SEMICOLON REDUCE to jump_statement" << endl; }
    | RETURN expression SEMICOLON { $<BaseStatement *>$ = new JumpStatement(RETURN,$2); cout << "RETURN expression SEMICOLON REDUCE to jump_statement" << endl; }
    ;

translation_unit 
    : external_declaration                  { program = new ProgramData(); program->add($1); cout << "external_declaration REDUCE to translation_unit" << endl; }
    | translation_unit external_declaration { program->add($2); cout << "translation_unit external_declaration REDUCE to translation_unit" << endl; }
    ;

external_declaration
    : function_definition  { $<ExternalDeclaration *>$ = new ExternalDeclaration($1); cout << "function_definition REDUCE to external_declaration" << endl; }
    | declaration          { $<ExternalDeclaration *>$ = new ExternalDeclaration($1); cout << "declaration REDUCE to external_declaration" << endl; }
    ;

function_definition
    : declaration_specifiers declarator declaration_list compound_statement { $<FunctionDefinition *>$ = new FunctionDefinition($1,$2,$3,$4); cout << "declaration_specifiers declarator declaration_list compound_statement REDUCE to function_definition" << endl; }
    | declaration_specifiers declarator compound_statement                  { $<FunctionDefinition *>$ = new FunctionDefinition($1,$2,$3); cout << "declaration_specifiers declarator compound_statement REDUCE to function_definition" << endl; }
    | declarator declaration_list compound_statement                        { $<FunctionDefinition *>$ = new FunctionDefinition($1,$2,$3); cout << "declarator declaration_list compound_statement REDUCE to function_definition" << endl; }
    | declarator compound_statement                                         { $<FunctionDefinition *>$ = new FunctionDefinition($1,$2); cout << "declarator compound_statement REDUCE to function_definition" << endl; }
    ;
    
%%

void WadeSpace::Parser::error(const location &loc , const string &message) {
    // cout << "Error: " << message << endl << "Location: " << loc << endl;  
    cout << "Error: " << message << endl << "Error location: " << driver.location() << endl;
}
