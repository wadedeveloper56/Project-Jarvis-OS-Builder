%{
#include <stdlib.h>
#include <stdio.h>
#include "jcc.h"

int yyerror(const char *s);
int yylex();
%}
%define api.pure
%define api.value.type { union ParseUnion }

%token END      0          "end of file"
%token <token>  IDENTIFIER "identifier"
%token <token>  I_CONSTANT "i_const"
%token <token>  F_CONSTANT "f_const"
%token <token>  STRING_LITERAL  "sting_literal"
%token <token>  Y_EXCLAMATION
%token <token>  Y_NE         
%token <token>  Y_POUND                 
%token <token>  Y_POUND_POUND           
%token <token>  Y_AND                   
%token <token>  Y_AND_AND               
%token <token>  Y_AND_EQUAL             
%token <token>  Y_LEFT_PAREN            
%token <token>  Y_RIGHT_PAREN           
%token <token>  Y_TIMES                 
%token <token>  Y_TIMES_EQUAL           
%token <token>  Y_PLUS                  
%token <token>  Y_PLUS_PLUS             
%token <token>  Y_PLUS_EQUAL            
%token <token>  Y_COMMA                 
%token <token>  Y_MINUS                 
%token <token>  Y_MINUS_MINUS           
%token <token>  Y_MINUS_EQUAL           
%token <token>  Y_ARROW                 
%token <token>  Y_DOT                   
%token <token>  Y_DOT_DOT_DOT           
%token <token>  Y_DIVIDE                
%token <token>  Y_DIVIDE_EQUAL          
%token <token>  Y_COLON                 
%token <token>  Y_SEG_OP                
%token <token>  Y_SEMICOLON             
%token <token>  Y_LT                    
%token <token>  Y_LSHIFT                
%token <token>  Y_LSHIFT_EQUAL          
%token <token>  Y_LE                    
%token <token>  Y_EQUAL                 
%token <token>  Y_EQ                    
%token <token>  Y_GT                    
%token <token>  Y_GE                    
%token <token>  Y_RSHIFT                
%token <token>  Y_RSHIFT_EQUAL          
%token <token>  Y_QUESTION              
%token <token>  Y_LEFT_BRACKET          
%token <token>  Y_RIGHT_BRACKET         
%token <token>  Y_XOR                   
%token <token>  Y_XOR_EQUAL             
%token <token>  Y___BASED               
%token <token>  Y___CDECL               
%token <token>  Y___EXPORT              
%token <token>  Y___FAR                 
%token <token>  Y___FAR16               
%token <token>  Y___FORTRAN             
%token <token>  Y___HUGE                
%token <token>  Y___INTERRUPT           
%token <token>  Y___LOADDS              
%token <token>  Y___NEAR                
%token <token>  Y___PASCAL              
%token <token>  Y___PRAGMA              
%token <token>  Y___SAVEREGS            
%token <token>  Y___SEGMENT             
%token <token>  Y___SEGNAME             
%token <token>  Y___SELF                
%token <token>  Y___STDCALL             
%token <token>  Y__PACKED               
%token <token>  Y__SEG16                
%token <token>  Y__SYSCALL
%token <token>  Y_THREAD_LOCAL
%token <token>  Y_AUTO                  
%token <token>  Y_CHAR                  
%token <token>  Y_CONST                 
%token <token>  Y_DOUBLE                
%token <token>  Y_ELSE                  
%token <token>  Y_ENUM                  
%token <token>  Y_EXTERN                
%token <token>  Y_FLOAT                 
%token <token>  Y_INT                   
%token <token>  Y_LONG                  
%token <token>  Y_REGISTER              
%token <token>  Y_SHORT                 
%token <token>  Y_SIGNED                
%token <token>  Y_SIZEOF                
%token <token>  Y_STATIC                
%token <token>  Y_STRUCT                
%token <token>  Y_TYPEDEF               
%token <token>  Y_UNION                 
%token <token>  Y_UNSIGNED              
%token <token>  Y_VOID                  
%token <token>  Y_VOLATILE              
%token <token>  Y_LEFT_BRACE            
%token <token>  Y_OR                    
%token <token>  Y_OR_EQUAL              
%token <token>  Y_OR_OR                 
%token <token>  Y_RIGHT_BRACE           
%token <token>  Y_TILDE                 
%token <token>  Y_IF
%token <token>  Y_STRING                
%token <token>  Y_INCLUDE_FILE_NAME     
%token <token>  Y_TYPEDEF_NAME          
%token <token>  Y_NUMBER                
%token <token>  Y_PERCENT               
%token <token>  Y_PERCENT_EQUAL         
%token <token>  Y_DEFINED               
%token <token>  Y_ENUMERATION_CONSTANT
%token <token>  Y_FUNC_NAME
%token <token>  Y_GENERIC
%token <token>  Y_DEFAULT
%token <token>  Y_CASE
%token <token>  Y_ALIGNOF
%token <token>  Y_IMAGINARY
%token <token>  Y_COMPLEX
%token <token>  Y_LONG_DOUBLE
%token <token>  Y_BOOL
%token <token>  Y_ATOMIC
%token <token>  Y_RESTRICT
%token <token>  Y_INLINE
%token <token>  Y_NORETURN
%token <token>  Y_ALIGNAS
%token <token>  Y_STATIC_ASSERT
%token <token>  Y_SWITCH
%token <token>  Y_WHILE
%token <token>  Y_DO
%token <token>  Y_FOR
%token <token>  Y_GOTO
%token <token>  Y_CONTINUE
%token <token>  Y_BREAK
%token <token>  Y_RETURN
%token <token>  Y_LONG_LONG

%type<token> constant
%type<token> enumeration_constant
%type<token> string
%type<token> type_name
%type<expression> primary_expression	
%type<expression> expression	
%type<expression> postfix_expression
%type<expression> assignment_expression
%type<expression> unary_expression
%type<label> unary_operator
%type<label> assignment_operator
%type<expression> cast_expression
%type<expression> constant_expression
%type<expression> argument_expression_list
%type<expression> initializer_list
%type<expression> initializer
%type<expression> multiplicative_expression
%type<expression> additive_expression
%type<expression> shift_expression
%type<expression> relational_expression
%type<expression> equality_expression
%type<expression> and_expression
%type<expression> exclusive_or_expression
%type<expression> inclusive_or_expression
%type<expression> logical_and_expression
%type<expression> logical_or_expression
%type<expression> conditional_expression

%type<declaration> declaration
%type<declSpecifiers> declaration_specifiers
%type<initDeclaratorList> init_declarator_list
%type<staticAssertDecl> static_assert_declaration

%type<token> storage_class_specifier
%type<token> type_qualifier
%type<typeSpecifier> type_specifier
%type<token> function_specifier
%type<token> alignment_specifier
%type<atomicTypeSpecifier> atomic_type_specifier

%type<token> struct_or_union
%type<list> struct_declaration_list
%type<structDeclaration> struct_declaration
%type<list> specifier_qualifier_list
%type<list> struct_declarator_list
%type<structDeclarator> struct_declarator
%type<declarator> declarator
%type<directDeclarator> direct_declarator
%type<structOrUnionSpecifier> struct_or_union_specifier

%type<list> enumerator_list
%type<enumerator> enumerator
$type<enumSpecifier> enum_specifier

%start translation_unit
%%

primary_expression
	: IDENTIFIER                            { $$ = createCTreeRoot(createTokenLabel($1)); }
	| constant                              { $$ = createCTreeRoot(createTokenLabel($1)); }
	| string                                { $$ = createCTreeRoot(createTokenLabel($1)); }
	| Y_LEFT_PAREN expression Y_RIGHT_PAREN { $$ = createCTree1(createConstr2Label(LABCT_PAREN_EXPR, $1, $3), $2); }
	| generic_selection                     { $$ = NULL; }
	;

constant
	: I_CONSTANT             {$$ = $1; zapToken($1); }
	| F_CONSTANT             {$$ = $1; zapToken($1); }
	| Y_ENUMERATION_CONSTANT {$$ = $1; zapToken($1); }
	;

enumeration_constant
	: IDENTIFIER {$$ = $1; zapToken($1); }
	;

string
	: STRING_LITERAL {$$ = $1; zapToken($1); }
	| Y_FUNC_NAME    {$$ = $1; zapToken($1); }
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
	: primary_expression                                                       { $$ = $1; }
	| postfix_expression Y_LEFT_BRACKET expression Y_RIGHT_BRACKET             { $$ = createCTree2(createConstr2Label(LABCT_INDEX, $2, $4), $1,  $3); }
	| postfix_expression Y_LEFT_PAREN Y_RIGHT_PAREN                            { $$ = createCTree1(createConstr2Label(LABCT_CALL, $2, $3), $1); }
	| postfix_expression Y_LEFT_PAREN argument_expression_list Y_RIGHT_PAREN   { $$ = createCTree2(createConstr2Label(LABCT_CALL, $2, $4), $1, $3); }
	| postfix_expression Y_DOT IDENTIFIER                                      { $$ = createCTree2(createConstr1Label(LABCT_DOT, $2), $1, createCTreeRoot(createTokenLabel($3))); }
	| postfix_expression Y_ARROW IDENTIFIER                                    { $$ = createCTree2(createConstr1Label(LABCT_ARROW, $2), $1, createCTreeRoot(createTokenLabel($3))); }
	| postfix_expression Y_PLUS_PLUS                                           { $$ = createCTree1(createConstr1Label(LABCT_PLUS_PLUS, $2), $1); }
	| postfix_expression Y_MINUS_MINUS                                         { $$ = createCTree1(createConstr1Label(LABCT_MINUS_MINUS, $2), $1); }
	| Y_LEFT_PAREN type_name Y_RIGHT_PAREN  Y_LEFT_BRACE initializer_list Y_RIGHT_BRACE  { $$ = createCTree1(createConstr5Label(LABCT_INIT, $1,$2,$3,$4,$6), $5); }
	| Y_LEFT_PAREN type_name Y_RIGHT_PAREN  Y_LEFT_BRACE initializer_list Y_COMMA Y_RIGHT_BRACE { $$ = createCTree1(createConstr5Label(LABCT_INIT, $1,$2,$3,$4,$6), $5); }
	;
	
argument_expression_list
	: assignment_expression                                  { $$ = $1; }
	| argument_expression_list Y_COMMA assignment_expression { $$ = createCTree2(createConstr1Label(LABCT_EXPR_SEPARATOR, $2), $1, $3); }
	;

unary_expression
	: postfix_expression                              { $$ = $1; }
	| Y_PLUS_PLUS unary_expression                    { $$ = createCTree1(createConstr1Label(LABCT_PLUS_PLUS, $1), $2); }
	| Y_MINUS_MINUS unary_expression                  { $$ = createCTree1(createConstr1Label(LABCT_MINUS_MINUS, $1), $2); }
	| unary_operator cast_expression                  { $$ = createCTree1($1, $2); }
	| Y_SIZEOF unary_expression                       { $$ = createCTree1(createConstr1Label(LABCT_SIZEOF_EXPR, $1), $2); }
	| Y_SIZEOF Y_LEFT_PAREN type_name Y_RIGHT_PAREN   { $$ = createCTreeRoot(createConstr3Label(LABCT_SIZEOF_TYPE, $1, $2, $4)); }
	| Y_ALIGNOF Y_LEFT_PAREN type_name Y_RIGHT_PAREN  { $$ = createCTreeRoot(createConstr3Label(LABCT_ALIGNOF_TYPE, $1, $2, $4)); }
	;

unary_operator
	: Y_AND         { $$ = createConstr1Label(LABCT_ADDR_OF_VALUE, $1); }
	| Y_TIMES       { $$ = createConstr1Label(LABCT_VALUE_AT_ADDR, $1); }
	| Y_PLUS        { $$ = createConstr1Label(LABCT_UNARY_PLUS, $1); }
	| Y_MINUS       { $$ = createConstr1Label(LABCT_UNARY_MINUS, $1); }
	| Y_TILDE       { $$ = createConstr1Label(LABCT_TILDE, $1); }
	| Y_EXCLAMATION { $$ = createConstr1Label(LABCT_EXCLAMATION, $1); }
	;

cast_expression
	: unary_expression                                     { $$ = $1; }
	| Y_LEFT_PAREN type_name Y_RIGHT_PAREN cast_expression { $$ = NULL; }
	;

multiplicative_expression
	: cast_expression { $$ = $1; }
	| multiplicative_expression Y_TIMES cast_expression   { $$ = createCTree2(createConstr1Label(LABCT_TIMES, $2), $1, $3); }
	| multiplicative_expression Y_DIVIDE cast_expression  { $$ = createCTree2(createConstr1Label(LABCT_DIVIDE, $2), $1, $3); }
	| multiplicative_expression Y_PERCENT cast_expression { $$ = createCTree2(createConstr1Label(LABCT_PERCENT, $2), $1, $3); }
	;

additive_expression
	: multiplicative_expression                             { $$ = $1; }
	| additive_expression Y_PLUS multiplicative_expression  { $$ = createCTree2(createConstr1Label(LABCT_PLUS, $2), $1, $3); }
	| additive_expression Y_MINUS multiplicative_expression { $$ = createCTree2(createConstr1Label(LABCT_MINUS, $2), $1, $3); }
	;

shift_expression
	: additive_expression                            { $$ = $1; }
	| shift_expression Y_RSHIFT additive_expression  { $$ = createCTree2(createConstr1Label(LABCT_TIMES, $2), $1, $3); }
	| shift_expression Y_LSHIFT additive_expression  { $$ = createCTree2(createConstr1Label(LABCT_TIMES, $2), $1, $3); }
	;

relational_expression
	: shift_expression                            { $$ = $1; }
	| relational_expression Y_LT shift_expression { $$ = createCTree2(createConstr1Label(LABCT_LT, $2), $1, $3); }
	| relational_expression Y_GT shift_expression { $$ = createCTree2(createConstr1Label(LABCT_GT, $2), $1, $3); }
	| relational_expression Y_LE shift_expression { $$ = createCTree2(createConstr1Label(LABCT_LE, $2), $1, $3); }
	| relational_expression Y_GE shift_expression { $$ = createCTree2(createConstr1Label(LABCT_GE, $2), $1, $3); }
	;

equality_expression
	: relational_expression                          { $$ = $1; }
	| equality_expression Y_EQ relational_expression { $$ = createCTree2(createConstr1Label(LABCT_EQ, $2), $1, $3); }
	| equality_expression Y_NE relational_expression { $$ = createCTree2(createConstr1Label(LABCT_NE, $2), $1, $3); }
	;

and_expression
	: equality_expression                      { $$ = $1; }
	| and_expression Y_AND equality_expression { $$ = createCTree2(createConstr1Label(LABCT_AND, $2), $1, $3); }
	;

exclusive_or_expression
	: and_expression                               { $$ = $1; }
	| exclusive_or_expression Y_XOR and_expression { $$ = createCTree2(createConstr1Label(LABCT_XOR, $2), $1, $3); }
	;

inclusive_or_expression
	: exclusive_or_expression                              { $$ = $1; }
	| inclusive_or_expression Y_OR exclusive_or_expression { $$ = createCTree2(createConstr1Label(LABCT_OR, $2), $1, $3); }
	;

logical_and_expression
	: inclusive_or_expression                                   { $$ = $1; }
	| logical_and_expression Y_AND_AND inclusive_or_expression  { $$ = createCTree2(createConstr1Label(LABCT_AND_AND, $2), $1, $3); }
	;

logical_or_expression
	: logical_and_expression                                { $$ = $1; }
	| logical_or_expression Y_OR_OR logical_and_expression  { $$ = createCTree2(createConstr1Label(LABCT_OR_OR, $2), $1, $3); }
	;

conditional_expression
	: logical_or_expression { $$ = $1; }
	| logical_or_expression Y_QUESTION expression Y_COLON conditional_expression { $$ = createCTree2(createConstr1Label(LABCT_QUESTION, $2), $1, createCTree2(createConstr1Label(LABCT_COLON, $4), $3, $5)); }
	;

assignment_expression
	: conditional_expression                                      { $$ = $1; }
	| unary_expression assignment_operator assignment_expression  { $$ = createCTree2($2, $1, $3); }
	;

assignment_operator
	: Y_EQUAL          { $$ = createConstr1Label(LABCT_EQ, $1); }
	| Y_TIMES_EQUAL    { $$ = createConstr1Label(LABCT_TIMES_EQUAL, $1); }
	| Y_DIVIDE_EQUAL   { $$ = createConstr1Label(LABCT_DIVIDE_EQUAL, $1); }
	| Y_PERCENT_EQUAL  { $$ = createConstr1Label(LABCT_PERCENT_EQUAL, $1); }
	| Y_PLUS_EQUAL     { $$ = createConstr1Label(LABCT_PLUS_EQUAL, $1); }
	| Y_MINUS_EQUAL    { $$ = createConstr1Label(LABCT_MINUS_EQUAL, $1); }
	| Y_LSHIFT_EQUAL   { $$ = createConstr1Label(LABCT_LSHIFT_EQUAL, $1); }
	| Y_RSHIFT_EQUAL   { $$ = createConstr1Label(LABCT_RSHIFT_EQUAL, $1); }
	| Y_AND_EQUAL      { $$ = createConstr1Label(LABCT_AND_EQUAL, $1); }
	| Y_XOR_EQUAL      { $$ = createConstr1Label(LABCT_XOR_EQUAL, $1); }
	| Y_OR_EQUAL       { $$ = createConstr1Label(LABCT_OR_EQUAL, $1); }
	;

expression
	: assignment_expression                    { $$ = $1; }
	| expression Y_COMMA assignment_expression { $$ = createCTree2(createConstr1Label(LABCT_EXPR_SEPARATOR, $2), $1, $3); }
	;

constant_expression
	: conditional_expression  { $$ = $1; }
	;

declaration
	: declaration_specifiers Y_SEMICOLON                      { $$ = createDeclaration($1,NULL,NULL); }
	| declaration_specifiers init_declarator_list Y_SEMICOLON { $$ = createDeclaration($1,$2,NULL); }
	| static_assert_declaration                               { $$ = createDeclaration(NULL,NULL,$1); }
	;

declaration_specifiers
	: storage_class_specifier declaration_specifiers { $$ = createDeclarationSpecifiers1($1,$2); }
	| storage_class_specifier                        { $$ = createDeclarationSpecifiers1($1,NULL); }
	| type_specifier declaration_specifiers          { $$ = createDeclarationSpecifiers2($1,$2); }
	| type_specifier                                 { $$ = createDeclarationSpecifiers2($1,NULL); }
	| type_qualifier declaration_specifiers          { $$ = createDeclarationSpecifiers1($1,$2); }
	| type_qualifier                                 { $$ = createDeclarationSpecifiers1($1,NULL); }
	| function_specifier declaration_specifiers      { $$ = createDeclarationSpecifiers1($1,$2); }
	| function_specifier                             { $$ = createDeclarationSpecifiers1($1,NULL); }
	| alignment_specifier declaration_specifiers     { $$ = createDeclarationSpecifiers1($1,$2); }
	| alignment_specifier                            { $$ = createDeclarationSpecifiers1($1,NULL); }
	;

init_declarator_list
	: init_declarator                               { $$ = NULL; }
	| init_declarator_list Y_COMMA init_declarator  { $$ = NULL;  zapToken($2); }
	;

init_declarator
	: declarator Y_EQUAL initializer
	| declarator 				    
	;

storage_class_specifier
	: Y_TYPEDEF	      { $$ = $1;  zapToken($1); }
	| Y_EXTERN        { $$ = $1;  zapToken($1); }
	| Y_STATIC        { $$ = $1;  zapToken($1); }
	| Y_THREAD_LOCAL  { $$ = $1;  zapToken($1); }
	| Y_AUTO          { $$ = $1;  zapToken($1); }
	| Y_REGISTER      { $$ = $1;  zapToken($1); }
	;

type_specifier
	: Y_VOID                    { $$ = createTypeSpecifier($1); }
	| Y_CHAR                    { $$ = createTypeSpecifier($1); }
	| Y_SHORT                   { $$ = createTypeSpecifier($1); }
	| Y_INT                     { $$ = createTypeSpecifier($1); }
	| Y_LONG                    { $$ = createTypeSpecifier($1); }
	| Y_LONG_LONG               { $$ = createTypeSpecifier($1); }
	| Y_FLOAT                   { $$ = createTypeSpecifier($1); }
	| Y_DOUBLE                  { $$ = createTypeSpecifier($1); }
	| Y_LONG_DOUBLE             { $$ = createTypeSpecifier($1); }
	| Y_SIGNED                  { $$ = createTypeSpecifier($1); }
	| Y_UNSIGNED                { $$ = createTypeSpecifier($1); }
	| Y_BOOL                    { $$ = createTypeSpecifier($1); }
	| Y_COMPLEX                 { $$ = createTypeSpecifier($1); }
	| Y_IMAGINARY               { $$ = createTypeSpecifier($1); }
	| atomic_type_specifier     { $$ = createTypeSpecifier2($1); }
	| struct_or_union_specifier { $$ = createTypeSpecifier3($1); }
	| enum_specifier            { $$ = NULL; }
	| Y_TYPEDEF_NAME            { $$ = createTypeSpecifier($1); } 
	;

struct_or_union_specifier
	: struct_or_union Y_LEFT_BRACE struct_declaration_list Y_RIGHT_BRACE            { $$ = createStructOrUnionSpecifier($1,NULL,$3); }
	| struct_or_union IDENTIFIER Y_LEFT_BRACE struct_declaration_list Y_RIGHT_BRACE { $$ = createStructOrUnionSpecifier($1,$2,$4); }
	| struct_or_union IDENTIFIER                                                    { $$ = createStructOrUnionSpecifier($1,$2,NULL); }
	;

struct_or_union
	: Y_STRUCT  { $$ = $1; zapToken($1); }
	| Y_UNION   { $$ = $1; zapToken($1); }
	;

struct_declaration_list
	: struct_declaration                         { $$ = createStructDeclarationList($1,NULL); }
	| struct_declaration_list struct_declaration { $$ = createStructDeclarationList($2,$1); } 
	;

struct_declaration
	: specifier_qualifier_list Y_SEMICOLON                         { $$ = createStructDeclaration($1,NULL,NULL); }
	| specifier_qualifier_list struct_declarator_list Y_SEMICOLON  { $$ = createStructDeclaration($1,$2,NULL); }
	| static_assert_declaration                                    { $$ = createStructDeclaration(NULL,NULL,$1); }
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list  { $$ = createSecifierQualifierList($1,NULL,$2); }
	| type_specifier                           { $$ = createSecifierQualifierList($1,NULL,NULL); }
	| type_qualifier specifier_qualifier_list  { $$ = createSecifierQualifierList(NULL,$1,$2); }
	| type_qualifier                           { $$ = createSecifierQualifierList(NULL,$1,NULL); }
	;

struct_declarator_list
	: struct_declarator                                { $$ = createStructDeclaratorList($1,NULL); }
	| struct_declarator_list Y_COMMA struct_declarator { $$ = createStructDeclaratorList($3,$1); } 
	;

struct_declarator
	: Y_COLON constant_expression            { $$ = createStructDeclarator(NULL,$2); }
	| declarator Y_COLON constant_expression { $$ = createStructDeclarator($1,$3); }
	| declarator                             { $$ = createStructDeclarator($1,NULL); }
	;

enum_specifier
	: Y_ENUM Y_LEFT_BRACE enumerator_list Y_RIGHT_BRACE                     { $$ = createEnumSpecifier(NULL,$4); }
	| Y_ENUM Y_LEFT_BRACE enumerator_list Y_COMMA Y_RIGHT_BRACE             { $$ = createEnumSpecifier(NUMM,$4); }
	| Y_ENUM IDENTIFIER Y_LEFT_BRACE enumerator_list Y_RIGHT_BRACE          { $$ = createEnumSpecifier($2,$4); }
	| Y_ENUM IDENTIFIER Y_LEFT_BRACE enumerator_list Y_COMMA Y_RIGHT_BRACE  { $$ = createEnumSpecifier($2,$4); } 
	| Y_ENUM IDENTIFIER                                                     { $$ = createEnumSpecifier($2,NULL); }
	;
	 
enumerator_list
	: enumerator                          { $$ = createEnumeratorList($1, NULL); }
	| enumerator_list Y_COMMA enumerator  { $$ = createEnumeratorList($3, $1); }
	;

enumerator	/* identifiers must be flagged as ENUMERATION_CONSTANT */
	: enumeration_constant Y_EQUAL constant_expression { $$ = createEnumerator($1, $3); }
	| enumeration_constant                             { $$ = createEnumerator($1, NULL); }
	;

atomic_type_specifier
	: Y_ATOMIC Y_LEFT_PAREN type_name Y_RIGHT_PAREN { $$ = createAtomicTypeSpecifier($1,$3); }
	;

type_qualifier
	: Y_CONST      { $$ = $1; }
	| Y_RESTRICT   { $$ = $1; }
	| Y_VOLATILE   { $$ = $1; }
	| Y_ATOMIC     { $$ = $1; }
	;

function_specifier
	: Y_INLINE    { $$ = $1;  }
	| Y_NORETURN  { $$ = $1; }
	;

alignment_specifier
	: Y_ALIGNAS Y_LEFT_PAREN type_name Y_RIGHT_PAREN            { $$ = $1; }
	| Y_ALIGNAS Y_LEFT_PAREN constant_expression Y_RIGHT_PAREN  { $$ = $1; }
	;

declarator
	: pointer direct_declarator { $$ = NULL; }
	| direct_declarator         { $$ = NULL; }
	;

direct_declarator
	: IDENTIFIER                                                                                          { $$ = NULL; }
	| Y_LEFT_PAREN declarator Y_RIGHT_PAREN                                                               { $$ = NULL; }
	| direct_declarator Y_LEFT_BRACKET Y_RIGHT_BRACKET                                                    { $$ = NULL; }
	| direct_declarator Y_LEFT_BRACKET Y_TIMES Y_RIGHT_BRACKET                                            { $$ = NULL; }
	| direct_declarator Y_LEFT_BRACKET Y_STATIC type_qualifier_list assignment_expression Y_RIGHT_BRACKET { $$ = NULL; }
	| direct_declarator Y_LEFT_BRACKET Y_STATIC assignment_expression Y_RIGHT_BRACKET                     { $$ = NULL; }
	| direct_declarator Y_LEFT_BRACKET type_qualifier_list Y_TIMES Y_RIGHT_BRACKET                        { $$ = NULL; }
	| direct_declarator Y_LEFT_BRACKET type_qualifier_list Y_STATIC assignment_expression Y_RIGHT_BRACKET { $$ = NULL; }
	| direct_declarator Y_LEFT_BRACKET type_qualifier_list assignment_expression Y_RIGHT_BRACKET          { $$ = NULL; }
	| direct_declarator Y_LEFT_BRACKET type_qualifier_list Y_RIGHT_BRACKET                                { $$ = NULL; }
	| direct_declarator Y_LEFT_BRACKET assignment_expression Y_RIGHT_BRACKET                              { $$ = NULL; }
	| direct_declarator Y_LEFT_PAREN parameter_type_list Y_RIGHT_PAREN                                    { $$ = NULL; }
	| direct_declarator Y_LEFT_PAREN Y_RIGHT_PAREN                                                        { $$ = NULL; }
	| direct_declarator Y_LEFT_PAREN identifier_list Y_RIGHT_PAREN                                        { $$ = NULL; }
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
	: specifier_qualifier_list abstract_declarator { $$ = NULL; }
	| specifier_qualifier_list                     { $$ = NULL; }
	;

abstract_declarator
	: pointer direct_abstract_declarator
	| pointer
	| direct_abstract_declarator
	;

direct_abstract_declarator
	: Y_LEFT_PAREN abstract_declarator Y_RIGHT_PAREN
	| Y_LEFT_BRACKET Y_RIGHT_BRACKET
	| Y_LEFT_BRACKET Y_TIMES Y_RIGHT_BRACKET
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
	: Y_LEFT_BRACE initializer_list Y_RIGHT_BRACE         { $$ = createCTree1(createConstr2Label(LABCT_EXPR_LIST, $1, $3), $2); }
	| Y_LEFT_BRACE initializer_list Y_COMMA Y_RIGHT_BRACE { $$ = createCTree1(createConstr3Label(LABCT_EXPR_LIST, $1, $3, $4), $2); }
	| assignment_expression                               { $$ = $1; }
	;

initializer_list
	: designation initializer                           { $$ = NULL; }
	| initializer                                       { $$ = createCTree1(createConstr0Label(LABCT_EXPR_LIST), $1); }
	| initializer_list Y_COMMA designation initializer  { $$ = NULL; }
	| initializer_list Y_COMMA initializer              { $$ = createCTree2(createConstr1Label(LABCT_EXPR_LIST, $2), $1, $3); }
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
	: Y_STATIC_ASSERT Y_LEFT_PAREN constant_expression Y_COMMA STRING_LITERAL Y_RIGHT_PAREN Y_SEMICOLON { $$ = NULL; }
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
	: Y_GOTO IDENTIFIER Y_SEMICOLON    { printf("jump_statement -> Y_GOTO IDENTIFIER Y_SEMICOLON\n"); }
	| Y_CONTINUE Y_SEMICOLON           { printf("jump_statement -> Y_CONTINUE Y_SEMICOLON\n"); }
	| Y_BREAK Y_SEMICOLON              { printf("jump_statement -> Y_BREAK Y_SEMICOLON\n"); }
	| Y_RETURN Y_SEMICOLON             { printf("jump_statement -> Y_RETURN Y_SEMICOLON\n"); }
	| Y_RETURN expression Y_SEMICOLON  { printf("jump_statement -> Y_RETURN expression Y_SEMICOLON\n"); }
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
	: declaration_specifiers declarator declaration_list compound_statement    { printf("function_definition -> declaration_specifiers declarator declaration_list compound_statement\n"); }
	| declaration_specifiers declarator compound_statement                     { printf("function_definition -> declaration_specifiers declarator compound_statement\n"); }
	;

declaration_list
	: declaration
	| declaration_list declaration
	;


%%
#include <stdio.h>

extern char * yytext;
extern int yylineno;

int yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** Line %d %s %s\n", yylineno, s, yytext);
	return 0;
}