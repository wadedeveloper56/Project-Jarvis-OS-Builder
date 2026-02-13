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
    #include "pch.h"
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
    #include "Expression.h"
    #include "debug.h"
    #include "Token.h"

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
    #include "pch.h"
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
%token <TokenPtr> AUTO "auto"
%token <TokenPtr> BREAK "break"
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
%token <TokenPtr> EXTERN "extern"
%token <int> FLOAT "float"
%token <int> FOR "for"
%token <int> GOTO "goto"
%token <int> IF "if"
%token <int> INLINE "inline"
%token <int> INT
%token <int> LONG "long"
%token <int> LONG_LONG "long long"
%token <TokenPtr> REGISTER "register"
%token <int> RESTRICT "restrict"
%token <int> RETURN "return"
%token <int> SHORT "short"
%token <int> SIGNED "signed"
%token <int> SIZEOF "sizeof"
%token <TokenPtr> STATIC "static"
%token <int> STRUCT "struct"
%token <int> SWITCH "switch"
%token <TokenPtr> TYPEDEF "typedef"
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
%token <TokenPtr> COMMA ","
%token <int> COLON ":"
%token <int> OPAREN "("
%token <int> CPAREN ")"
%token <int> OBRACE "["
%token <int> CBRACE "]"
%token <int> PERIOD "."
%token <TokenPtr> TILDE "~"
%token <TokenPtr> EQUAL "="
%token <TokenPtr> RIGHT_ASSIGN ">>="
%token <TokenPtr> LEFT_ASSIGN "<<="
%token <TokenPtr> ADD_ASSIGN "+="
%token <TokenPtr> SUB_ASSIGN "-="
%token <TokenPtr> MUL_ASSIGN "*="
%token <TokenPtr> DIV_ASSIGN "/="
%token <TokenPtr> MOD_ASSIGN "%="
%token <TokenPtr> AND_ASSIGN "&="
%token <TokenPtr> XOR_ASSIGN "^="
%token <TokenPtr> OR_ASSIGN "|="
%token <TokenPtr> RIGHT_OP ">>"
%token <TokenPtr> LEFT_OP "<<"
%token <TokenPtr> INC_OP "++"
%token <TokenPtr> DEC_OP "--"
%token <TokenPtr> PTR_OP "->"
%token <TokenPtr> AND_OP "&&"
%token <TokenPtr> OR_OP "||"
%token <TokenPtr> GREATER_EQUAL ">="
%token <TokenPtr> LESS_EQUAL "<="
%token <TokenPtr> GREATER ">"
%token <TokenPtr> LESS "<"
%token <TokenPtr> EQUAL_EQUAL "=="
%token <TokenPtr> NOT_EQUAL "!="
%token <TokenPtr> NOT_OP "!"
%token <TokenPtr> XOR_OP "^"
%token <TokenPtr> BIT_AND "&"
%token <TokenPtr> BIT_OR "|"
%token <TokenPtr> MINUS_OP "-"
%token <TokenPtr> PLUS_OP "+"
%token <TokenPtr> TIMES_OP "*"
%token <TokenPtr> DIV_OP "/"
%token <TokenPtr> MOD_OP "%"

%type<Constant *> constant
%type<vector<Expression *> *> argument_expression_list
%type<Expression *> primary_expression
%type<Expression *> expression
%type<Expression *> postfix_expression
%type<Expression *> unary_expression
%type<Expression *> cast_expression
%type<Expression *> multiplicative_expression
%type<Expression *> additive_expression
%type<Expression *> shift_expression
%type<Expression *> relational_expression
%type<Expression *> equality_expression
%type<Expression *> and_expression
%type<Expression *> exclusive_or_expression
%type<Expression *> inclusive_or_expression
%type<Expression *> logical_and_expression
%type<Expression *> logical_or_expression
%type<Expression *> conditional_expression
%type<Expression *> assignment_expression
%type<Expression *> constant_expression
%type<TokenPtr> unary_operator
%type<TokenPtr> assignment_operator
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

%nonassoc "then"
%nonassoc ELSE

%start translation_unit

%%

primary_expression
    : IDENTIFIER                { $$ = createPrimaryExpression($1,NULL);      cout << "IDENTIFIER REDUCE to primary_expression" << endl; }
    | constant                  { $$ = createPrimaryExpression(nullopt,$1);   cout << "constant REDUCE to primary_expression" << endl; }
    | OPAREN expression CPAREN  { $$ = $2;                                    cout << "OPAREN expression CPAREN REDUCE to primary_expression" << endl; }
    ;

constant
    : F_CONST         { $$ = createConstant(nullopt,$1,nullopt,FLOAT_CONSTANT);   cout << "F_CONST REDUCE to constant " << endl; }
    | I_CONST         { $$ = createConstant($1,nullopt,nullopt,INTEGER_CONSTANT); cout << "I_CONST REDUCE to constant " << endl; }
    | STRING_LITERAL  { $$ = createConstant(nullopt,nullopt,$1,STRING_CONSTANT);  cout << "STRING_LITERAL REDUCE to constant  " << endl; }

postfix_expression
    : primary_expression                                           { $$ = $1;  cout << "primary_expression REDUCE to postfix_expression" << endl; }
    | postfix_expression OBRACE expression CBRACE                  { $$ = createExpression(NT_ARRAY,$2,$4,$3,nullptr,nullptr,nullptr,nullopt,nullptr,nullptr,nullptr,  $1,nullptr,nullptr); cout << "postfix_expression OBRACE expression CBRACE REDUCE to postfix_expression" << endl; }
    | postfix_expression OPAREN CPAREN                             { $$ = createExpression(NT_FUNCTION_CALL,$2,$3,nullptr,nullptr,nullptr,nullptr,nullopt,nullptr,nullptr,nullptr, $1,nullptr,nullptr); cout << "postfix_expression OPAREN CPAREN REDUCE to postfix_expression" << endl; }
    | postfix_expression OPAREN argument_expression_list CPAREN    { $$ = createExpression(NT_FUNCTION_CALL,$2,$4,nullptr,nullptr,nullptr,$3,nullopt,nullptr,nullptr,nullptr, $1,nullptr,nullptr); cout << "postfix_expression OPAREN argument_expression_list CPAREN REDUCE to postfix_expression" << endl; }
    | postfix_expression PERIOD IDENTIFIER                         { $$ = createExpression(NT_VAR_ACCESS,$2,nullopt,nullptr,nullptr,nullptr,nullptr,$3,nullptr,nullptr,nullptr, $1,nullptr,nullptr); cout << "postfix_expression PERIOD_OP IDENTIFIER REDUCE to postfix_expression" << endl; }
    | postfix_expression PTR_OP IDENTIFIER                         { $$ = createExpression(NT_VAR_ACCESS,nullopt,nullopt,nullptr,nullptr,nullptr,nullptr,$3,nullptr,nullptr,$2, $1,nullptr,nullptr); cout << "postfix_expression PTR_OP IDENTIFIER REDUCE to postfix_expression" << endl; }
    | postfix_expression INC_OP                                    { $$ = createExpression(NT_INC,nullopt,nullopt,nullptr,$1,nullptr,nullptr,nullopt,nullptr,nullptr,$2, nullptr,nullptr,nullptr); cout << "postfix_expression INC_OP REDUCE to postfix_expression" << endl; }
    | postfix_expression DEC_OP                                    { $$ = createExpression(NT_DEC,nullopt,nullopt,nullptr,$1,nullptr,nullptr,nullopt,nullptr,nullptr,$2, nullptr,nullptr,nullptr); cout << "postfix_expression DEC_OP REDUCE to postfix_expression" << endl; }
    | OPAREN type_name CPAREN OCURLY initializer_list CCURLY       { $$ = createExpression(NT_TYPECAST,nullopt,nullopt,nullptr,nullptr,nullptr,nullptr,nullopt,$5,$2,nullptr, nullptr,nullptr,nullptr); cout << "OPAREN type_name CPAREN_OP OCURLY_OP initializer_list CCURLY REDUCE to postfix_expression" << endl; }
    | OPAREN type_name CPAREN OCURLY initializer_list COMMA CCURLY { $$ = createExpression(NT_TYPECAST,nullopt,nullopt,nullptr,nullptr,nullptr,nullptr,nullopt,$5,$2,nullptr, nullptr,nullptr,nullptr); cout << "OPAREN type_name CPAREN_OP OCURLY_OP initializer_list COMMA CCURLY REDUCE to postfix_expression" << endl; }


argument_expression_list
    : assignment_expression                                { $$ = createArgumentExpressionList($1,nullptr); cout << "assignment_expression REDUCE argument_expression_list" << endl; }
    | argument_expression_list COMMA assignment_expression { $$ = createArgumentExpressionList($3,$1); cout << "argument_expression_list COMMA assignment_expression REDUCE argument_expression_list" << endl; }
    ;

unary_expression
    : postfix_expression             { $$ = $1; cout << "postfix_expression REDUCE unary_expression" << endl;}
    | INC_OP unary_expression        { $$ = createExpression(NT_INC,nullopt,nullopt,nullptr,$2,nullptr,nullptr,nullopt,nullptr,nullptr,$1, nullptr,nullptr,nullptr); cout << "INC_OP unary_expression REDUCE unary_expression" << endl;}
    | DEC_OP unary_expression        { $$ = createExpression(NT_DEC,nullopt,nullopt,nullptr,$2,nullptr,nullptr,nullopt,nullptr,nullptr,$1, nullptr,nullptr,nullptr); cout << "DEC_OP unary_expression REDUCE unary_expression" << endl;}
    | unary_operator cast_expression { $$ = createExpression(NT_UNARY,nullopt,nullopt,nullptr,$2,nullptr,nullptr,nullopt,nullptr,nullptr,nullptr, nullptr,nullptr,nullptr); cout << "unary_operator cast_expression REDUCE unary_expression" << endl;}
    | SIZEOF unary_expression        { $$ = createExpression(NT_SIZEOF,$1,nullopt,nullptr,$2,nullptr,nullptr,nullopt,nullptr,nullptr,nullptr, nullptr,nullptr,nullptr); cout << "SIZEOF unary_expression REDUCE unary_expression" << endl;}
    | SIZEOF OPAREN type_name CPAREN { $$ = createExpression(NT_SIZEOF,$1,nullopt,nullptr,nullptr,nullptr,nullptr,nullopt,nullptr,$3,nullptr, nullptr,nullptr,nullptr); cout << "SIZEOF OPAREN type_name CPAREN REDUCE unary_expression" << endl;}
    ;

unary_operator
    : BIT_AND   { $$ = $1; cout << "BIT_AND REDUCE to unary_operator" << endl;}
    | TIMES_OP  { $$ = $1; cout << "TIMES_OP REDUCE to unary_operator" << endl;}
    | PLUS_OP   { $$ = $1; cout << "PLUS_OP REDUCE to unary_operator" << endl;}
    | MINUS_OP  { $$ = $1; cout << "MINUS_OP REDUCE to unary_operator" << endl;}
    | TILDE     { $$ = $1; cout << "TILDE REDUCE to unary_operator" << endl;}
    | NOT_OP    { $$ = $1; cout << "NOT_OP REDUCE to unary_operator" << endl;}
    ;

cast_expression
    : unary_expression                         { $$ = $1;  cout << "unary_expression REDUCE to cast_expression" << endl;}
    | OPAREN type_name CPAREN cast_expression  { $$ = createExpression(NT_TYPECAST,nullopt,nullopt,nullptr,$4,nullptr,nullptr,nullopt,nullptr,$2,nullptr, nullptr,nullptr,nullptr);  cout << "unary_expression REDUCE to cast_expression" << endl;}
    ;

multiplicative_expression
    : cast_expression                                    { $$ = $1;  cout << "cast_expression REDUCE to multiplicative_expression" << endl;}
    | multiplicative_expression TIMES_OP cast_expression { $$ = createExpression(NT_OP,nullopt,nullopt,nullptr,nullptr,nullptr,nullptr,nullopt,nullptr,nullptr,nullptr, $1,$2,$3); cout << "multiplicative_expression TIMES_OP cast_expression REDUCE to multiplicative_expression" << endl;}
    | multiplicative_expression DIV_OP cast_expression   { $$ = createExpression(NT_OP,nullopt,nullopt,nullptr,nullptr,nullptr,nullptr,nullopt,nullptr,nullptr,nullptr, $1,$2,$3); cout << "multiplicative_expression DIV_OP cast_expression REDUCE to multiplicative_expression" << endl;}
    | multiplicative_expression MOD_OP cast_expression   { $$ = createExpression(NT_OP,nullopt,nullopt,nullptr,nullptr,nullptr,nullptr,nullopt,nullptr,nullptr,nullptr, $1,$2,$3); cout << "multiplicative_expression MOD_OP cast_expression REDUCE to multiplicative_expression" << endl;}
    ;

additive_expression
    : multiplicative_expression                               { $$ = $1;  cout << "multiplicative_expression REDUCE to additive_expression" << endl;}
    | additive_expression PLUS_OP multiplicative_expression   { $$ = createExpression(NT_OP,nullopt,nullopt,nullptr,nullptr,nullptr,nullptr,nullopt,nullptr,nullptr,nullptr, $1,$2,$3); cout << "additive_expression REDUCE to multiplicative_expression" << endl;}
    | additive_expression MINUS_OP multiplicative_expression  { $$ = createExpression(NT_OP,nullopt,nullopt,nullptr,nullptr,nullptr,nullptr,nullopt,nullptr,nullptr,nullptr, $1,$2,$3); cout << "additive_expression REDUCE to multiplicative_expression" << endl;}
    ;

shift_expression
    : additive_expression                           { $$ = $1;  cout << "additive_expression REDUCE to shift_expression" << endl;}
    | shift_expression LEFT_OP additive_expression  { $$ = createExpression(NT_OP,nullopt,nullopt,nullptr,nullptr,nullptr,nullptr,nullopt,nullptr,nullptr,nullptr, $1,$2,$3);; cout << "shift_expression LEFT_OP additive_expression REDUCE to shift_expression" << endl;}
    | shift_expression RIGHT_OP additive_expression { $$ = createExpression(NT_OP,nullopt,nullopt,nullptr,nullptr,nullptr,nullptr,nullopt,nullptr,nullptr,nullptr, $1,$2,$3);; cout << "shift_expression RIGHT_OP additive_expression REDUCE to shift_expression" << endl;}
    ;

relational_expression
    : shift_expression                                       { $$ = $1;  cout << "shift_expression REDUCE to relational_expression" << endl;}
    | relational_expression LESS shift_expression            { $$ = createExpression(NT_OP,nullopt,nullopt,nullptr,nullptr,nullptr,nullptr,nullopt,nullptr,nullptr,nullptr, $1,$2,$3); cout << "relational_expression LESS shift_expression REDUCE to shift_expression" << endl;}
    | relational_expression GREATER shift_expression         { $$ = createExpression(NT_OP,nullopt,nullopt,nullptr,nullptr,nullptr,nullptr,nullopt,nullptr,nullptr,nullptr, $1,$2,$3); cout << "relational_expression GREATER shift_expression REDUCE to shift_expression" << endl;}
    | relational_expression LESS_EQUAL shift_expression      { $$ = createExpression(NT_OP,nullopt,nullopt,nullptr,nullptr,nullptr,nullptr,nullopt,nullptr,nullptr,nullptr, $1,$2,$3); cout << "relational_expression LESS_EQUAL shift_expression REDUCE to shift_expression" << endl;}
    | relational_expression GREATER_EQUAL shift_expression   { $$ = createExpression(NT_OP,nullopt,nullopt,nullptr,nullptr,nullptr,nullptr,nullopt,nullptr,nullptr,nullptr, $1,$2,$3); cout << "relational_expression GREATER_EQUAL shift_expression REDUCE to shift_expression" << endl;}
    ;

equality_expression
    : relational_expression                                  { $$ = $1;  cout << "relational_expression REDUCE to equality_expression" << endl;}
    | equality_expression EQUAL_EQUAL relational_expression  { $$ = createExpression(NT_OP,nullopt,nullopt,nullptr,nullptr,nullptr,nullptr,nullopt,nullptr,nullptr,nullptr, $1,$2,$3); cout << "equality_expression EQUAL_EQUAL relational_expression REDUCE to equality_expression" << endl;}
    | equality_expression NOT_EQUAL relational_expression    { $$ = createExpression(NT_OP,nullopt,nullopt,nullptr,nullptr,nullptr,nullptr,nullopt,nullptr,nullptr,nullptr, $1,$2,$3); cout << "equality_expression NOT_EQUAL relational_expression REDUCE to equality_expression" << endl;}
    ;

and_expression     
    : equality_expression                         { $$ = $1;  cout << "equality_expression REDUCE to and_expression" << endl;}
    | and_expression BIT_AND equality_expression  { $$ = createExpression(NT_OP,nullopt,nullopt,nullptr,nullptr,nullptr,nullptr,nullopt,nullptr,nullptr,nullptr, $1,$2,$3); cout << "and_expression BIT_AND equality_expression REDUCE to and_expression" << endl;}
    ;

exclusive_or_expression
    : and_expression                                 { $$ = $1;  cout << "and_expression REDUCE to exclusive_or_expression" << endl;}
    | exclusive_or_expression XOR_OP and_expression  { $$ = createExpression(NT_OP,nullopt,nullopt,nullptr,nullptr,nullptr,nullptr,nullopt,nullptr,nullptr,nullptr, $1,$2,$3); cout << "exclusive_or_expression XOR_OP and_expression REDUCE to exclusive_or_expression" << endl;}
    ;

inclusive_or_expression
    : exclusive_or_expression                                { $$ = $1;  cout << "exclusive_or_expression REDUCE to inclusive_or_expression" << endl;}
    | inclusive_or_expression BIT_OR exclusive_or_expression { $$ = createExpression(NT_OP,nullopt,nullopt,nullptr,nullptr,nullptr,nullptr,nullopt,nullptr,nullptr,nullptr, $1,$2,$3); cout << "inclusive_or_expression BIT_OR exclusive_or_expression REDUCE to inclusive_or_expression" << endl;}
    ;

logical_and_expression
    : inclusive_or_expression                                { $$ = $1;  cout << "inclusive_or_expression REDUCE to logical_and_expression" << endl;}
    | logical_and_expression AND_OP inclusive_or_expression  { $$ = createExpression(NT_OP,nullopt,nullopt,nullptr,nullptr,nullptr,nullptr,nullopt,nullptr,nullptr,nullptr, $1,$2,$3); cout << "inclusive_or_expression REDUCE to logical_and_expression" << endl;}
    ;

logical_or_expression
    : logical_and_expression                              { $$ = $1;  cout << "inclusive_and_expression REDUCE to logical_or_expression" << endl;}
    | logical_or_expression OR_OP logical_and_expression  { $$ = createExpression(NT_OP,nullopt,nullopt,nullptr,nullptr,nullptr,nullptr,nullopt,nullptr,nullptr,nullptr, $1,$2,$3); cout << "logical_or_expression OR_OP logical_and_expression REDUCE to logical_or_expression" << endl;}
    ;

conditional_expression
    : logical_or_expression                                                   { $$ = $1;  cout << "logical_or_expression REDUCE to conditional_expression" << endl;}
    | logical_or_expression QUESTION expression COLON conditional_expression  { $$ = createExpression(NT_QUESTION,nullopt,nullopt,$1,$3,$5,nullptr,nullopt,nullptr,nullptr,nullptr,  nullptr,nullptr,nullptr); cout << "logical_or_expression QUESTION expression COLON conditional_expression REDUCE to conditional_expression" << endl;}
    ;

assignment_expression
    : conditional_expression                                      { $$ = $1;  cout << "conditional_expression REDUCE to assignment_expression" << endl;}
    | unary_expression assignment_operator assignment_expression  { $$ = createExpression(NT_OP,nullopt,nullopt,nullptr,nullptr,nullptr,nullptr,nullopt,nullptr,nullptr,nullptr, $1,$2,$3); cout << "unary_expression assignment_operator assignment_expression REDUCE to assignment_expression" << endl;}
    ;

assignment_operator
    : EQUAL          { $$ = $1;  cout << "EQUAL_OP REDUCE to assignment_operator" << endl;}
    | MUL_ASSIGN     { $$ = $1;  cout << "MUL_ASSIGN REDUCE to assignment_operator" << endl;}
    | DIV_ASSIGN     { $$ = $1;  cout << "DIV_ASSIGN REDUCE to assignment_operator" << endl;}
    | MOD_ASSIGN     { $$ = $1;  cout << "MOG_ASSIGN REDUCE to assignment_operator" << endl;}
    | ADD_ASSIGN     { $$ = $1;  cout << "ADD_ASSIGN REDUCE to assignment_operator" << endl;}
    | SUB_ASSIGN     { $$ = $1;  cout << "SUB_ASSIGN REDUCE to assignment_operator" << endl;}
    | LEFT_ASSIGN    { $$ = $1;  cout << "LEFT_ASSIGN REDUCE to assignment_operator" << endl;}
    | RIGHT_ASSIGN   { $$ = $1;  cout << "RIGHT_ASSIGN REDUCE to assignment_operator" << endl;}
    | AND_ASSIGN     { $$ = $1;  cout << "AND_ASSIGN REDUCE to assignment_operator" << endl;}
    | XOR_ASSIGN     { $$ = $1;  cout << "XOR_ASSIGN REDUCE to assignment_operator" << endl;}
    | OR_ASSIGN      { $$ = $1;  cout << "OR_ASSIGN REDUCE to assignment_operator" << endl;}
    ;

expression
    : assignment_expression                   { $$ = $1;  cout << "asignment_expression REDUCE to expression" << endl;}
    | expression COMMA assignment_expression  { $$ = createExpression(NT_OP,nullopt,nullopt,nullptr,nullptr,nullptr,nullptr,nullopt,nullptr,nullptr,nullptr, $1,$2,$3); cout << "expression COMMA assignment_expression COMMA  REDUCE to expression" << endl;}
    ;

constant_expression
    : conditional_expression  { $<Expression *>$ = $1;  cout << "conditional_expression REDUCE to constant_expression" << endl;}
    ;

declaration
    : declaration_specifiers SEMICOLON                       { $$ = new Declaration($1); cout << "declaration_specifiers SEMICOLON REDUCE to declaration" << endl;}
    | declaration_specifiers init_declarator_list SEMICOLON  { $$ = new Declaration($1,$2); cout << "declaration_specifiers init_declarator_list SEMICOLON REDUCE to declaration" << endl;}
    ;

declaration_specifiers
    : storage_class_specifier                         { $$ = createDeclarationSpecifiers($1,nullptr,nullptr,nullptr); cout << "storage_class_specifier REDUCE to declaration_specifiers" << endl;}
    | storage_class_specifier declaration_specifiers  { $$ = createDeclarationSpecifiers($1,nullptr,nullptr,$2);      cout << "** storage_class_specifier declaration_specifiers REDUCE to declaration_specifiers" << endl;}
    | type_specifier                                  { $$ = createDeclarationSpecifiers(nullptr,$1,nullptr,nullptr); cout << "** type_specifier REDUCE to declaration_specifiers" << endl;}
    | type_specifier declaration_specifiers           { $$ = createDeclarationSpecifiers(nullptr,$1,nullptr,$2);      cout << "type_specifier declaration_specifiers REDUCE to declaration_specifiers" << endl;}
    | type_qualifier                                  { $$ = createDeclarationSpecifiers(nullptr,nullptr,$1,nullptr); cout << "type_qualifier REDUCE to declaration_specifiers" << endl;}
    | type_qualifier declaration_specifiers           { $$ = createDeclarationSpecifiers(nullptr,nullptr,$1,$2);      cout << "type_qualifier declaration_specifiers REDUCE to declaration_specifiers" << endl;}
    ;

init_declarator_list
    : init_declarator                            { $$ = createInitDeclaratorList($1,nullptr); cout << "init_declarator REDUCE to init_declarator_list" << endl;}
    | init_declarator_list COMMA init_declarator { $$ = createInitDeclaratorList($3,$1); cout << "init_declarator_list COMMA init_declarator REDUCE to init_declarator_list" << endl;}
    ;

init_declarator
    : declarator                    { $<InitDeclarator *>$ = new InitDeclarator($1); cout << "declarator REDUCE to init_declarator" << endl;}
    | declarator EQUAL initializer  { $<InitDeclarator *>$ = new InitDeclarator($1,$3); cout << "declarator EQUAL initializer REDUCE to init_declarator" << endl;}
    ;

storage_class_specifier
    : TYPEDEF   { $$ = createStorageClassSpecifier($1); cout << "** TYPEDEF REDUCE to storage_class_specifier" << endl;}
    | EXTERN    { $$ = createStorageClassSpecifier($1); cout << "EXTERN REDUCE to storage_class_specifier" << endl;}
    | STATIC    { $$ = createStorageClassSpecifier($1); cout << "STATIC REDUCE to storage_class_specifier" << endl;}
    | AUTO      { $$ = createStorageClassSpecifier($1); cout << "AUTO REDUCE to storage_class_specifier" << endl;}
    | REGISTER  { $$ = createStorageClassSpecifier($1); cout << "REGISTER REDUCE to storage_class_specifier" << endl;}
    ;

type_specifier
    : VOID                      { $$ = new TypeSpecifier(VOID); cout << "VOID REDUCE to type_specifier" << endl;}
    | CHAR                      { $$ = new TypeSpecifier(CHAR); cout << "CHAR REDUCE to type_specifier" << endl;}
    | SHORT                     { $$ = new TypeSpecifier(SHORT); cout << "SHORT REDUCE to type_specifier" << endl;}
    | INT                       { $$ = new TypeSpecifier(INT); cout << "** INT REDUCE to type_specifier" << endl;}
    | LONG                      { $$ = new TypeSpecifier(LONG); cout << "LONG REDUCE to type_specifier" << endl;}
    | LONG_LONG                 { $$ = new TypeSpecifier(LONG_LONG); cout << "LONG_LONG REDUCE to type_specifier" << endl;}
    | FLOAT                     { $$ = new TypeSpecifier(FLOAT); cout << "FLOAT REDUCE to type_specifier" << endl;}
    | DOUBLE                    { $$ = new TypeSpecifier(DOUBLE); cout << "DOUBLE REDUCE to type_specifier" << endl;}
    | LONG_DOUBLE               { $$ = new TypeSpecifier(LONG_DOUBLE); cout << "LONG_DOUBLE REDUCE to type_specifier" << endl;}
    | BOOL                      { $$ = new TypeSpecifier(BOOL); cout << "BOOL REDUCE to type_specifier" << endl;}
    | IMAGINARY                 { $$ = new TypeSpecifier(IMAGINARY); cout << "IMAGINARY REDUCE to type_specifier" << endl;}
    | COMPLEX                   { $$ = new TypeSpecifier(COMPLEX); cout << "COMPLEX REDUCE to type_specifier" << endl;}
    | SIGNED                    { $$ = new TypeSpecifier(SIGNED); cout << "SIGNED REDUCE to type_specifier" << endl;}
    | UNSIGNED                  { $$ = new TypeSpecifier(UNSIGNED); cout << "UNIGNED REDUCE to type_specifier" << endl;}
    | struct_or_union_specifier { $$ = new TypeSpecifier($1); cout << "struct_or_union_specifier REDUCE to type_specifier" << endl;}
    | enum_specifier            { $$ = new TypeSpecifier($1); cout << "enum_specifier REDUCE to type_specifier" << endl;}
    | TYPE_NAME                 { $$ = new TypeSpecifier(TYPE_NAME); cout << "TYPE_NAME REDUCE to type_specifier" << endl;}
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
    : pointer direct_declarator { $$ = createDeclarator($1,$2); cout << "pointer direct_declarator REDUCE to declarator" << endl;}
    | direct_declarator         { $$ = createDeclarator(nullptr,$1); cout << "direct_declarator REDUCE to declarator" << endl;}
    ;

direct_declarator
    : IDENTIFIER                                            { $$ = createDirectDeclarator($1,nullopt,nullopt,NULL,NULL,NULL,NULL,NULL); cout << "IDENTIFIER REDUCE to direct_declarator" << endl;}
    | OPAREN declarator CPAREN                              { $$ = createDirectDeclarator(nullopt,$1,$3,$2,NULL,NULL,NULL,NULL); cout << "OPAREN declarator CPAREN REDUCE to direct_declarator" << endl;}
    | direct_declarator OBRACE constant_expression CBRACE   { $$ = createDirectDeclarator(nullopt,$2,$4,NULL,$1,$3,NULL,NULL); cout << "direct_declarator OBRACE constant_expression CBRACE REDUCE to direct_declarator" << endl;}
    | direct_declarator OBRACE CBRACE                       { $$ = createDirectDeclarator(nullopt,$2,$3,NULL,$1,NULL,NULL,NULL); cout << "direct_declarator OBRACE CBRACE REDUCE to direct_declarator" << endl;}
    | direct_declarator OPAREN parameter_type_list CPAREN   { $$ = createDirectDeclarator(nullopt,$2,$4,NULL,$1,NULL,$3,NULL); cout << "direct_declarator OPAREN parameter_type_list CPAREN to direct_declarator" << endl;}
    | direct_declarator OPAREN identifier_list CPAREN       { $$ = createDirectDeclarator(nullopt,$2,$4,NULL,$1,NULL,NULL,$3); cout << "direct_declarator OPAREN identifier_list CPAREN REDUCE to direct_declarator" << endl;}
    | direct_declarator OPAREN CPAREN                       { $$ = createDirectDeclarator(nullopt,$2,$3,NULL,$1,NULL,NULL,NULL); cout << "direct_declarator OPAREN CPAREN REDUCE to direct_declarator" << endl;}
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
    | parameter_list COMMA ELLIPSIS   { $<ParameterTypeList *>$ = new ParameterTypeList($1,$3); cout << "parameter_list COMMA ELLIPSIS REDUCE to parameter_type_list" << endl; }
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
    : pointer                             { $$ = new AbstractDeclarator($1,nullptr); cout << "pointer REDUCE to abstract_declarator" << endl; }
    | direct_abstract_declarator          { $$ = new AbstractDeclarator(nullptr,$1); cout << "direct_abstract_declarator REDUCE to abstract_declarator" << endl; }
    | pointer direct_abstract_declarator  { $$ = new AbstractDeclarator($1,$2);      cout << "pointer direct_abstract_declarator REDUCE to abstract_declarator" << endl; }
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
    : labeled_statement    { $<BaseStatement *>$ = new Statement(labeled_statement,$1); cout << "labeled_statement REDUCE to statement" << endl; }
    | compound_statement   { $<BaseStatement *>$ = new Statement(compound_statement,$1); cout << "compound_statement REDUCE to statement" << endl; }
    | expression_statement { $<BaseStatement *>$ = new Statement(expression_statement,$1); cout << "expression_statement REDUCE to statement" << endl; }
    | selection_statement  { $<BaseStatement *>$ = new Statement(selection_statement,$1); cout << "selection_statement REDUCE to statement" << endl; }
    | iteration_statement  { $<BaseStatement *>$ = new Statement(iteration_statement,$1); cout << "iteration_statement REDUCE to statement" << endl; }
    | jump_statement       { $<BaseStatement *>$ = new Statement(jump_statement,$1); cout << "jump_statement REDUCE to statement" << endl; }
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
    : declaration                   { $$ = createDeclarationList($1,nullptr);
                                     //Declaration* exp = $1;
                                     //$$ = new std::vector<Declaration*>();
                                     //$$->push_back(exp);
                                     cout << "declaration REDUCE to declaration_list" << endl;
                                    }
    | declaration_list declaration  {
                                     $$ = createDeclarationList($2,$1);
                                     //Declaration* value1 = $2;
                                     //std::vector<Declaration*> *value2 = $1;
                                     //value2->push_back(value1);
                                     //$$ = value2;
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
    : IF OPAREN expression CPAREN statement  %prec "then"  { $<BaseStatement *>$ = new SelectionStatement(IF,$3,$5); cout << "IF OPAREN expression CPAREN statement REDUCE to selection_statement" << endl; }
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
