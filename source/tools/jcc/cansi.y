%{
#include <stdlib.h>
#include <stdio.h>
#include "wic.h"

int yyerror(const char *s);
int yylex();
%}

%union {
    int integer;
    char* string;
    long long longlong;
    long double longdouble;
}

%token END 0 "end of file"
%token<string>     IDENTIFIER "identifier"
%token<longlong>   I_CONSTANT "i_const"
%token<longdouble> F_CONSTANT "f_const"
%token<string>     STRING_LITERAL  "sting_literal"

%token <integer>  Y_EXCLAMATION
%token <integer>  Y_NE         
%token <integer>  Y_POUND                 
%token <integer>  Y_POUND_POUND           
%token <integer>  Y_AND                   
%token <integer>  Y_AND_AND               
%token <integer>  Y_AND_EQUAL             
%token <integer>  Y_LEFT_PAREN            
%token <integer>  Y_RIGHT_PAREN           
%token <integer>  Y_TIMES                 
%token <integer>  Y_TIMES_EQUAL           
%token <integer>  Y_PLUS                  
%token <integer>  Y_PLUS_PLUS             
%token <integer>  Y_PLUS_EQUAL            
%token <integer>  Y_COMMA                 
%token <integer>  Y_MINUS                 
%token <integer>  Y_MINUS_MINUS           
%token <integer>  Y_MINUS_EQUAL           
%token <integer>  Y_ARROW                 
%token <integer>  Y_DOT                   
%token <integer>  Y_DOT_DOT_DOT           
%token <integer>  Y_DIVIDE                
%token <integer>  Y_DIVIDE_EQUAL          
%token <integer>  Y_COLON                 
%token <integer>  Y_SEG_OP                
%token <integer>  Y_SEMICOLON             
%token <integer>  Y_LT                    
%token <integer>  Y_LSHIFT                
%token <integer>  Y_LSHIFT_EQUAL          
%token <integer>  Y_LE                    
%token <integer>  Y_EQUAL                 
%token <integer>  Y_EQ                    
%token <integer>  Y_GT                    
%token <integer>  Y_GE                    
%token <integer>  Y_RSHIFT                
%token <integer>  Y_RSHIFT_EQUAL          
%token <integer>  Y_QUESTION              
%token <integer>  Y_LEFT_BRACKET          
%token <integer>  Y_RIGHT_BRACKET         
%token <integer>  Y_XOR                   
%token <integer>  Y_XOR_EQUAL             
%token <integer>  Y___BASED               
%token <integer>  Y___CDECL               
%token <integer>  Y___EXPORT              
%token <integer>  Y___FAR                 
%token <integer>  Y___FAR16               
%token <integer>  Y___FORTRAN             
%token <integer>  Y___HUGE                
%token <integer>  Y___INTERRUPT           
%token <integer>  Y___LOADDS              
%token <integer>  Y___NEAR                
%token <integer>  Y___PASCAL              
%token <integer>  Y___PRAGMA              
%token <integer>  Y___SAVEREGS            
%token <integer>  Y___SEGMENT             
%token <integer>  Y___SEGNAME             
%token <integer>  Y___SELF                
%token <integer>  Y___STDCALL             
%token <integer>  Y__PACKED               
%token <integer>  Y__SEG16                
%token <integer>  Y__SYSCALL
%token <integer>  Y_THREAD_LOCAL
%token <integer>  Y_AUTO                  
%token <integer>  Y_CHAR                  
%token <integer>  Y_CONST                 
%token <integer>  Y_DOUBLE                
%token <integer>  Y_ELSE                  
%token <integer>  Y_ENUM                  
%token <integer>  Y_EXTERN                
%token <integer>  Y_FLOAT                 
%token <integer>  Y_INT                   
%token <integer>  Y_LONG                  
%token <integer>  Y_REGISTER              
%token <integer>  Y_SHORT                 
%token <integer>  Y_SIGNED                
%token <integer>  Y_SIZEOF                
%token <integer>  Y_STATIC                
%token <integer>  Y_STRUCT                
%token <integer>  Y_TYPEDEF               
%token <integer>  Y_UNION                 
%token <integer>  Y_UNSIGNED              
%token <integer>  Y_VOID                  
%token <integer>  Y_VOLATILE              
%token <integer>  Y_LEFT_BRACE            
%token <integer>  Y_OR                    
%token <integer>  Y_OR_EQUAL              
%token <integer>  Y_OR_OR                 
%token <integer>  Y_RIGHT_BRACE           
%token <integer>  Y_TILDE                 
%token <integer>  Y_IF
%token <integer>  Y_STRING                
%token <integer>  Y_INCLUDE_FILE_NAME     
%token <integer>  Y_TYPEDEF_NAME          
%token <integer>  Y_NUMBER                
%token <integer>  Y_PERCENT               
%token <integer>  Y_PERCENT_EQUAL         
%token <integer>  Y_DEFINED               
%token <integer>  Y_ENUMERATION_CONSTANT
%token <integer>  Y_FUNC_NAME
%token <integer>  Y_GENERIC
%token <integer>  Y_DEFAULT
%token <integer>  Y_CASE
%token <integer>  Y_ALIGNOF
%token <integer>  Y_IMAGINARY
%token <integer>  Y_COMPLEX
%token <integer>  Y_LONG_DOUBLE
%token <integer>  Y_BOOL
%token <integer>  Y_ATOMIC
%token <integer>  Y_RESTRICT
%token <integer>  Y_INLINE
%token <integer>  Y_NORETURN
%token <integer>  Y_ALIGNAS
%token <integer>  Y_STATIC_ASSERT
%token <integer>  Y_SWITCH
%token <integer>  Y_WHILE
%token <integer>  Y_DO
%token <integer>  Y_FOR
%token <integer>  Y_GOTO
%token <integer>  Y_CONTINUE
%token <integer>  Y_BREAK
%token <integer>  Y_RETURN
%token <integer>  Y_LONG_LONG

%start translation_unit
%%

primary_expression
	: IDENTIFIER
	| constant
	| string
	| Y_LEFT_PAREN expression Y_RIGHT_PAREN
	| generic_selection
	;

constant
	: I_CONSTANT		/* includes character_constant */
	| F_CONSTANT
	| Y_ENUMERATION_CONSTANT	/* after it has been defined as such */
	;

enumeration_constant		/* before it has been defined as such */
	: IDENTIFIER
	;

string
	: STRING_LITERAL
	| Y_FUNC_NAME
	;

generic_selection
	: Y_GENERIC Y_LEFT_PAREN assignment_expression Y_COMMA generic_assoc_list Y_RIGHT_PAREN
	;

generic_assoc_list
	: generic_association
	| generic_assoc_list Y_COMMA generic_association
	;

generic_association
	: type_name Y_COLON assignment_expression
	| Y_DEFAULT Y_COLON assignment_expression
	;

postfix_expression
	: primary_expression
	| postfix_expression Y_LEFT_BRACKET expression Y_RIGHT_BRACKET
	| postfix_expression Y_LEFT_PAREN Y_RIGHT_PAREN
	| postfix_expression Y_LEFT_PAREN argument_expression_list Y_RIGHT_PAREN
	| postfix_expression Y_DOT IDENTIFIER
	| postfix_expression Y_ARROW IDENTIFIER
	| postfix_expression Y_PLUS_PLUS
	| postfix_expression Y_MINUS_MINUS
	| Y_LEFT_PAREN type_name Y_RIGHT_PAREN  Y_LEFT_BRACE initializer_list Y_RIGHT_BRACE
	| Y_LEFT_PAREN type_name Y_RIGHT_PAREN  Y_LEFT_BRACE initializer_list Y_COMMA Y_RIGHT_BRACE
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list Y_COMMA assignment_expression
	;

unary_expression
	: postfix_expression
	| Y_PLUS_PLUS unary_expression
	| Y_MINUS_MINUS unary_expression
	| unary_operator cast_expression
	| Y_SIZEOF unary_expression
	| Y_SIZEOF Y_LEFT_PAREN type_name Y_RIGHT_PAREN
	| Y_ALIGNOF Y_LEFT_PAREN type_name Y_RIGHT_PAREN
	;

unary_operator
	: Y_AND
	| Y_TIMES
	| Y_PLUS
	| Y_MINUS
	| Y_TILDE
	| Y_EXCLAMATION
	;

cast_expression
	: unary_expression
	| Y_LEFT_PAREN type_name Y_RIGHT_PAREN cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression Y_TIMES cast_expression
	| multiplicative_expression Y_DIVIDE cast_expression
	| multiplicative_expression Y_PERCENT cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression Y_PLUS multiplicative_expression
	| additive_expression Y_MINUS multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression Y_RSHIFT additive_expression
	| shift_expression Y_LSHIFT additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression Y_LT shift_expression
	| relational_expression Y_GT shift_expression
	| relational_expression Y_LE shift_expression
	| relational_expression Y_GE shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression Y_EQ relational_expression
	| equality_expression Y_NE relational_expression
	;

and_expression
	: equality_expression
	| and_expression Y_AND equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression Y_XOR and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression Y_OR exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression Y_AND_AND inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression Y_OR_OR logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression Y_QUESTION expression Y_COLON conditional_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: Y_EQUAL
	| Y_TIMES_EQUAL
	| Y_DIVIDE_EQUAL
	| Y_PERCENT_EQUAL
	| Y_PLUS_EQUAL
	| Y_MINUS_EQUAL
	| Y_LSHIFT_EQUAL
	| Y_RSHIFT_EQUAL
	| Y_AND_EQUAL
	| Y_XOR_EQUAL
	| Y_OR_EQUAL
	;

expression
	: assignment_expression
	| expression Y_COMMA assignment_expression
	;

constant_expression
	: conditional_expression	/* with constraints */
	;

declaration
	: declaration_specifiers Y_SEMICOLON
	| declaration_specifiers init_declarator_list Y_SEMICOLON
	| static_assert_declaration
	;

declaration_specifiers
	: storage_class_specifier declaration_specifiers
	| storage_class_specifier
	| type_specifier declaration_specifiers
	| type_specifier
	| type_qualifier declaration_specifiers
	| type_qualifier
	| function_specifier declaration_specifiers
	| function_specifier
	| alignment_specifier declaration_specifiers
	| alignment_specifier
	;

init_declarator_list
	: init_declarator
	| init_declarator_list Y_COMMA init_declarator
	;

init_declarator
	: declarator Y_EQUAL initializer
	| declarator
	;

storage_class_specifier
	: Y_TYPEDEF	/* identifiers must be flagged as TYPEDEF_NAME */
	| Y_EXTERN
	| Y_STATIC
	| Y_THREAD_LOCAL
	| Y_AUTO
	| Y_REGISTER
	;

type_specifier
	: Y_VOID
	| Y_CHAR
	| Y_SHORT
	| Y_INT
	| Y_LONG
	| Y_LONG_LONG
	| Y_FLOAT
	| Y_DOUBLE
	| Y_LONG_DOUBLE
	| Y_SIGNED
	| Y_UNSIGNED
	| Y_BOOL
	| Y_COMPLEX
	| Y_IMAGINARY	  	/* non-mandated extension */
	| atomic_type_specifier
	| struct_or_union_specifier
	| enum_specifier
	| Y_TYPEDEF_NAME		/* after it has been defined as such */
	;

struct_or_union_specifier
	: struct_or_union Y_LEFT_BRACE struct_declaration_list Y_RIGHT_BRACE
	| struct_or_union IDENTIFIER Y_LEFT_BRACE struct_declaration_list Y_RIGHT_BRACE
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: Y_STRUCT
	| Y_UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list Y_SEMICOLON	/* for anonymous struct/union */
	| specifier_qualifier_list struct_declarator_list Y_SEMICOLON
	| static_assert_declaration
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list Y_COMMA struct_declarator
	;

struct_declarator
	: Y_COLON constant_expression
	| declarator Y_COLON constant_expression
	| declarator
	;

enum_specifier
	: Y_ENUM Y_LEFT_BRACE enumerator_list Y_RIGHT_BRACE
	| Y_ENUM Y_LEFT_BRACE enumerator_list Y_COMMA Y_RIGHT_BRACE
	| Y_ENUM IDENTIFIER Y_LEFT_BRACE enumerator_list Y_RIGHT_BRACE
	| Y_ENUM IDENTIFIER Y_LEFT_BRACE enumerator_list Y_COMMA Y_RIGHT_BRACE
	| Y_ENUM IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list Y_COMMA enumerator
	;

enumerator	/* identifiers must be flagged as ENUMERATION_CONSTANT */
	: enumeration_constant Y_EQUAL constant_expression
	| enumeration_constant
	;

atomic_type_specifier
	: Y_ATOMIC Y_LEFT_PAREN type_name Y_RIGHT_PAREN
	;

type_qualifier
	: Y_CONST
	| Y_RESTRICT
	| Y_VOLATILE
	| Y_ATOMIC
	;

function_specifier
	: Y_INLINE
	| Y_NORETURN
	;

alignment_specifier
	: Y_ALIGNAS Y_LEFT_PAREN type_name Y_RIGHT_PAREN
	| Y_ALIGNAS Y_LEFT_PAREN constant_expression Y_RIGHT_PAREN
	;

declarator
	: pointer direct_declarator
	| direct_declarator
	;

direct_declarator
	: IDENTIFIER
	| Y_LEFT_PAREN declarator Y_RIGHT_PAREN
	| direct_declarator Y_LEFT_BRACKET Y_RIGHT_BRACKET
	| direct_declarator Y_LEFT_BRACKET Y_TIMES Y_RIGHT_BRACKET
	| direct_declarator Y_LEFT_BRACKET Y_STATIC type_qualifier_list assignment_expression Y_RIGHT_BRACKET
	| direct_declarator Y_LEFT_BRACKET Y_STATIC assignment_expression Y_RIGHT_BRACKET
	| direct_declarator Y_LEFT_BRACKET type_qualifier_list Y_TIMES Y_RIGHT_BRACKET
	| direct_declarator Y_LEFT_BRACKET type_qualifier_list Y_STATIC assignment_expression Y_RIGHT_BRACKET
	| direct_declarator Y_LEFT_BRACKET type_qualifier_list assignment_expression Y_RIGHT_BRACKET
	| direct_declarator Y_LEFT_BRACKET type_qualifier_list Y_RIGHT_BRACKET
	| direct_declarator Y_LEFT_BRACKET assignment_expression Y_RIGHT_BRACKET
	| direct_declarator Y_LEFT_PAREN parameter_type_list Y_RIGHT_PAREN
	| direct_declarator Y_LEFT_PAREN Y_RIGHT_PAREN
	| direct_declarator Y_LEFT_PAREN identifier_list Y_RIGHT_PAREN
	;

pointer
	: Y_TIMES type_qualifier_list pointer
	| Y_TIMES type_qualifier_list
	| Y_TIMES pointer
	| Y_TIMES
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list Y_COMMA Y_DOT_DOT_DOT
	| parameter_list
	;

parameter_list
	: parameter_declaration
	| parameter_list Y_COMMA parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: IDENTIFIER
	| identifier_list Y_COMMA IDENTIFIER
	;

type_name
	: specifier_qualifier_list abstract_declarator
	| specifier_qualifier_list
	;

abstract_declarator
	: pointer direct_abstract_declarator
	| pointer
	| direct_abstract_declarator
	;

direct_abstract_declarator
	: Y_LEFT_PAREN abstract_declarator Y_RIGHT_PAREN
	| Y_LEFT_BRACKET Y_RIGHT_BRACKET
	| Y_LEFT_BRACKET '*' Y_RIGHT_BRACKET
	| Y_LEFT_BRACKET Y_STATIC type_qualifier_list assignment_expression Y_RIGHT_BRACKET
	| Y_LEFT_BRACKET Y_STATIC assignment_expression Y_RIGHT_BRACKET
	| Y_LEFT_BRACKET type_qualifier_list Y_STATIC assignment_expression Y_RIGHT_BRACKET
	| Y_LEFT_BRACKET type_qualifier_list assignment_expression Y_RIGHT_BRACKET
	| Y_LEFT_BRACKET type_qualifier_list Y_RIGHT_BRACKET
	| Y_LEFT_BRACKET assignment_expression Y_RIGHT_BRACKET
	| direct_abstract_declarator Y_LEFT_BRACKET Y_RIGHT_BRACKET
	| direct_abstract_declarator Y_LEFT_BRACKET '*' Y_RIGHT_BRACKET
	| direct_abstract_declarator Y_LEFT_BRACKET Y_STATIC type_qualifier_list assignment_expression Y_RIGHT_BRACKET
	| direct_abstract_declarator Y_LEFT_BRACKET Y_STATIC assignment_expression Y_RIGHT_BRACKET
	| direct_abstract_declarator Y_LEFT_BRACKET type_qualifier_list assignment_expression Y_RIGHT_BRACKET
	| direct_abstract_declarator Y_LEFT_BRACKET type_qualifier_list Y_STATIC assignment_expression Y_RIGHT_BRACKET
	| direct_abstract_declarator Y_LEFT_BRACKET type_qualifier_list Y_RIGHT_BRACKET
	| direct_abstract_declarator Y_LEFT_BRACKET assignment_expression Y_RIGHT_BRACKET
	| Y_LEFT_PAREN Y_RIGHT_PAREN
	| Y_LEFT_PAREN parameter_type_list Y_RIGHT_PAREN
	| direct_abstract_declarator Y_LEFT_PAREN Y_RIGHT_PAREN
	| direct_abstract_declarator Y_LEFT_PAREN parameter_type_list Y_RIGHT_PAREN
	;

initializer
	: Y_LEFT_BRACE initializer_list Y_RIGHT_BRACE
	| Y_LEFT_BRACE initializer_list Y_COMMA Y_RIGHT_BRACE
	| assignment_expression
	;

initializer_list
	: designation initializer
	| initializer
	| initializer_list Y_COMMA designation initializer
	| initializer_list Y_COMMA initializer
	;

designation
	: designator_list Y_EQUAL
	;

designator_list
	: designator
	| designator_list designator
	;

designator
	: Y_LEFT_BRACKET constant_expression Y_RIGHT_BRACKET
	| Y_DOT IDENTIFIER
	;

static_assert_declaration
	: Y_STATIC_ASSERT Y_LEFT_PAREN constant_expression Y_COMMA STRING_LITERAL Y_RIGHT_PAREN Y_SEMICOLON
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
	: IDENTIFIER Y_COLON statement
	| Y_CASE constant_expression Y_COLON statement
	| Y_DEFAULT Y_COLON statement
	;

compound_statement
	: Y_LEFT_BRACE Y_RIGHT_BRACE
	| Y_LEFT_BRACE  block_item_list Y_RIGHT_BRACE
	;

block_item_list
	: block_item
	| block_item_list block_item
	;

block_item
	: declaration
	| statement
	;

expression_statement
	: Y_SEMICOLON
	| expression Y_SEMICOLON
	;

selection_statement
	: Y_IF Y_LEFT_PAREN expression Y_RIGHT_PAREN statement Y_ELSE statement
	| Y_IF Y_LEFT_PAREN expression Y_RIGHT_PAREN statement
	| Y_SWITCH Y_LEFT_PAREN expression Y_RIGHT_PAREN statement
	;

iteration_statement
	: Y_WHILE Y_LEFT_PAREN expression Y_RIGHT_PAREN statement
	| Y_DO statement Y_WHILE Y_LEFT_PAREN expression Y_RIGHT_PAREN Y_SEMICOLON
	| Y_FOR Y_LEFT_PAREN expression_statement expression_statement Y_RIGHT_PAREN statement
	| Y_FOR Y_LEFT_PAREN expression_statement expression_statement expression Y_RIGHT_PAREN statement
	| Y_FOR Y_LEFT_PAREN declaration expression_statement Y_RIGHT_PAREN statement
	| Y_FOR Y_LEFT_PAREN declaration expression_statement expression Y_RIGHT_PAREN statement
	;

jump_statement
	: Y_GOTO IDENTIFIER Y_SEMICOLON
	| Y_CONTINUE Y_SEMICOLON
	| Y_BREAK Y_SEMICOLON
	| Y_RETURN Y_SEMICOLON
	| Y_RETURN expression Y_SEMICOLON
	;

translation_unit
	: external_declaration                   { printf("translation_unit -> external_declaration\n\n"); }
	| translation_unit external_declaration  { printf("translation_unit -> translation_unit external_declaration\n\n"); }
	;

external_declaration
	: function_definition   { printf("external_declaration -> function_definition\n"); }
	| declaration           { printf("external_declaration -> declaration\n"); }
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	;

declaration_list
	: declaration
	| declaration_list declaration
	;


%%
#include <stdio.h>

extern char * yytext;

int yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** %s %s\n", s, yytext);
	return 0;
}