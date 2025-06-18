%{
#include "global.h"
%}

%union { 	   
    struct _CompilerInfo CompilerInfo;
	struct _ParameterListNode *ParameterList;
}

%token<CompilerInfo> IDENTIFIER CONSTANT STRING_LITERAL
%token<noDefinition> PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token<noDefinition> SEMI_OP OCURLY_OP CCURLY_OP COMMA_OP COLON_OP EQUAL_OP
%token<noDefinition> OPENPAREN_OP CLOSEPAREN_OP OPENBRACE_OP CLOSEBRACE_OP
%token<noDefinition> PERIOD_OP NOT_OP LESS_OP GREATER_OP TILDE_OP XOR_OP QUESTION_OP
%token<noDefinition> AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token<noDefinition> SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token<noDefinition> XOR_ASSIGN OR_ASSIGN TYPE_NAME
%token<noDefinition> PLUS_OP MINUS_OP TIMES_OP DIV_OP MOD_OP BIT_OR BIT_AND
%token<noDefinition> TYPEDEF EXTERN STATIC AUTO REGISTER INLINE RESTRICT
%token<noDefinition> CHAR SHORT INT LONG LONGLONG SIGNED UNSIGNED FLOAT DOUBLE LONGDOUBLE CONST VOLATILE VOID
%token<noDefinition> SIZEOF BOOL COMPLEX IMAGINARY
%token<noDefinition> STRUCT UNION ENUM ELLIPSIS INCLUDE
%token<noDefinition> CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%type <noDefinition> type_name struct_or_union specifier_qualifier_list jump_statement declaration_list
%type <noDefinition> expression_statement iteration_statement labeled_statement    
%type <noDefinition> unary_operator external_declaration translation_unit

%type<CompilerInfo> primary_expression postfix_expression argument_expression_list unary_expression
%type<CompilerInfo> cast_expression multiplicative_expression additive_expression shift_expression relational_expression
%type<CompilerInfo> equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression
%type<CompilerInfo> logical_or_expression conditional_expression assignment_expression assignment_operator expression
%type<CompilerInfo> constant_expression 

%type<CompilerInfo> declaration declaration_specifiers init_declarator_list init_declarator
%type<CompilerInfo> storage_class_specifier type_specifier struct_or_union_specifier struct_declaration_list
%type<CompilerInfo> struct_declaration struct_declarator_list struct_declarator enum_specifier
%type<CompilerInfo> enumerator_list enumerator type_qualifier function_specifier declarator direct_declarator pointer
%type<CompilerInfo> type_qualifier_list parameter_type_list identifier_list
%type<ParameterList> parameter_list parameter_declaration 
%type<CompilerInfo> abstract_declarator direct_abstract_declarator initializer initializer_list designation designator_list
%type<CompilerInfo> designator statement compound_statement block_item_list block_item 
%type<CompilerInfo> selection_statement
%type<CompilerInfo> function_definition

%error-verbose
%locations

%start translation_unit
%%
primary_expression
	: IDENTIFIER                            {
                                             strcpy($<CompilerInfo>$.data.identifier, $<CompilerInfo>1.data.identifier);
                                             $<CompilerInfo>$.data.type = TYPE_NULL;
                                             $<CompilerInfo>$.data.constant = FALSE;
	                                         printCompilerInfoNode("<EXP> IDENTIFIER REDUCE to primary_expression",NULL);
											}
	| CONSTANT                              {
                                             strcpy($<CompilerInfo>$.data.identifier, $<CompilerInfo>1.data.identifier);
                                             $<CompilerInfo>$.data.type = TYPE_NULL;
                                             $<CompilerInfo>$.data.constant = TRUE;
	                                         printCompilerInfoNode("<EXP> CONSTANT REDUCE to primary_expression",&$<CompilerInfo>$);
											}
	| STRING_LITERAL                        {
                                             strcpy($<CompilerInfo>$.data.identifier, $<CompilerInfo>1.data.identifier);
                                             $<CompilerInfo>$.data.type = TYPE_NULL;
                                             $<CompilerInfo>$.data.constant = TRUE;
	                                         printCompilerInfoNode("STRING_LITERAL REDUCE to primary_expression",&$<CompilerInfo>$);
											}
	| OPENPAREN_OP expression CLOSEPAREN_OP {
                                             $<CompilerInfo>$ = $<CompilerInfo>2;
	                                         printCompilerInfoNode("<EXP> OPENPAREN_OP expression CLOSEPAREN_OP REDUCE to primary_expression",NULL);
											}
	;

postfix_expression
	: primary_expression                                                                 {
                                                                                          $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                                                      printCompilerInfoNode("<EXP> primary_expression REDUCE to postfix_expression",NULL);
																						 }
	| postfix_expression OPENBRACE_OP expression CLOSEBRACE_OP                           {printCompilerInfoNode("postfix_expression OPENBRACE_OP expression CLOSEBRACE_OP REDUCE to postfix_expression",NULL);}
	| postfix_expression OPENPAREN_OP CLOSEPAREN_OP                                      {printCompilerInfoNode("postfix_expression OPENPAREN_OP CLOSEPAREN_OP REDUCE to postfix_expression",NULL);}
	| postfix_expression OPENPAREN_OP argument_expression_list CLOSEPAREN_OP             {printCompilerInfoNode("postfix_expression OPENPAREN_OP argument_expression_list CLOSEPAREN_OP REDUCE to postfix_expression",NULL);}
	| postfix_expression PERIOD_OP IDENTIFIER                                            {printCompilerInfoNode("postfix_expression PERIOD_OP IDENTIFIER REDUCE to postfix_expression",NULL);}
	| postfix_expression PTR_OP IDENTIFIER                                               {printCompilerInfoNode("postfix_expression PTR_OP IDENTIFIER REDUCE to postfix_expression",NULL);}
	| postfix_expression INC_OP                                                          {printCompilerInfoNode("postfix_expression INC_OP REDUCE to postfix_expression",NULL);}
	| postfix_expression DEC_OP                                                          {printCompilerInfoNode("postfix_expression DEC_OP REDUCE to postfix_expression",NULL);}
	| OPENPAREN_OP type_name CLOSEPAREN_OP OCURLY_OP initializer_list CCURLY_OP          {printCompilerInfoNode("OPENPAREN_OP type_name CLOSEPAREN_OP OCURLY_OP initializer_list CCURLY_OP REDUCE to postfix_expression",NULL);}
	| OPENPAREN_OP type_name CLOSEPAREN_OP OCURLY_OP initializer_list COMMA_OP CCURLY_OP {printCompilerInfoNode("OPENPAREN_OP type_name CLOSEPAREN_OP OCURLY_OP initializer_list COMMA_OP CCURLY_OP REDUCE to postfix_expression",NULL);}
	;

argument_expression_list
	: assignment_expression                                    {printCompilerInfoNode("assignment_expression REDUCE to argument_expression_list",NULL);}
	| argument_expression_list COMMA_OP assignment_expression  {printCompilerInfoNode("argument_expression_list COMMA_OP assignment_expression REDUCE to argument_expression_list",NULL);}
	;

unary_expression
	: postfix_expression                            {
                                                     $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                 printCompilerInfoNode("<EXP> postfix_expression REDUCE to unary_expression",NULL);
													}
	| INC_OP unary_expression                       {printCompilerInfoNode("INC_OP unary_expression REDUCE to unary_expression",NULL);}
	| DEC_OP unary_expression                       {printCompilerInfoNode("DEC_OP unary_expression REDUCE to unary_expression",NULL);}
	| unary_operator cast_expression                {printCompilerInfoNode("unary_operator cast_expression REDUCE to unary_expression",NULL);}
	| SIZEOF unary_expression                       {printCompilerInfoNode("SIZEOF unary_expression REDUCE to unary_expression",NULL);}
	| SIZEOF OPENPAREN_OP type_name CLOSEPAREN_OP   {printCompilerInfoNode("SIZEOF OPENPAREN_OP type_name CLOSEPAREN_OP REDUCE to unary_expression",NULL);}
	;

unary_operator
	: BIT_AND   {printCompilerInfoNode("BIT_AND REDUCE to unary_operator",NULL);}
	| TIMES_OP  {printCompilerInfoNode("TIMES_OP REDUCE to unary_operator",NULL);}
	| PLUS_OP   {printCompilerInfoNode("PLUS_OP REDUCE to unary_operator",NULL);}
	| MINUS_OP  {printCompilerInfoNode("MINUS_OP REDUCE to unary_operator",NULL);}
	| TILDE_OP  {printCompilerInfoNode("TILDE_OP REDUCE to unary_operator",NULL);}
	| NOT_OP    {printCompilerInfoNode("NOT_OP REDUCE to unary_operator",NULL);}
	;

cast_expression
	: unary_expression                                      {
                                                             $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                         printCompilerInfoNode("<EXP> unary_expression REDUCE to cast_expression",NULL);
															}
	| OPENPAREN_OP type_name CLOSEPAREN_OP cast_expression  {printCompilerInfoNode("OPENPAREN_OP type_name CLOSEPAREN_OP cast_expression REDUCE to cast_expression",NULL);}
	;

multiplicative_expression
	: cast_expression                                     {
                                                           $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                       printCompilerInfoNode("<EXP> cast_expression REDUCE to multiplicative_expression",NULL);
														  }
	| multiplicative_expression TIMES_OP cast_expression  {printCompilerInfoNode("multiplicative_expression TIMES_OP cast_expression REDUCE to multiplicative_expression",NULL);}
	| multiplicative_expression DIV_OP cast_expression    {printCompilerInfoNode("multiplicative_expression DIV_OP cast_expression REDUCE to multiplicative_expression",NULL);}
	| multiplicative_expression MOD_OP cast_expression    {printCompilerInfoNode("multiplicative_expression MOD_OP cast_expression REDUCE to multiplicative_expression",NULL);}
	;

additive_expression
	: multiplicative_expression                               {
                                                               $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                           printCompilerInfoNode("<EXP> multiplicative_expression REDUCE to additive_expression",NULL);
															  }
	| additive_expression PLUS_OP multiplicative_expression   {printCompilerInfoNode("additive_expression PLUS_OP multiplicative_expression REDUCE to additive_expression",NULL);}
	| additive_expression MINUS_OP multiplicative_expression  {printCompilerInfoNode("additive_expression MINUS_OP multiplicative_expression REDUCE to additive_expression",NULL);}
	;

shift_expression
	: additive_expression                           {
                                                     $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                 printCompilerInfoNode("<EXP> additive_expression REDUCE to shift_expression",NULL);
													}
	| shift_expression LEFT_OP additive_expression  {printCompilerInfoNode("shift_expression LEFT_OP additive_expression REDUCE to shift_expression",NULL);}
	| shift_expression RIGHT_OP additive_expression {printCompilerInfoNode("shift_expression RIGHT_OP additive_expression REDUCE to shift_expression",NULL);}
	;

relational_expression
	: shift_expression                                  {
                                                         $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                     printCompilerInfoNode("<EXP> shift_expression REDUCE to relational_expression",NULL);
														}
	| relational_expression LESS_OP shift_expression    {printCompilerInfoNode("relational_expression LESS_OP shift_expression REDUCE to relational_expression",NULL);}
	| relational_expression GREATER_OP shift_expression {printCompilerInfoNode("relational_expression GREATER_OP shift_expression REDUCE to relational_expression",NULL);}
	| relational_expression LE_OP shift_expression      {printCompilerInfoNode("relational_expression LE_OP shift_expression REDUCE to relational_expression",NULL);}
	| relational_expression GE_OP shift_expression      {printCompilerInfoNode("relational_expression GE_OP shift_expression REDUCE to relational_expression",NULL);}
	;

equality_expression
	: relational_expression                             {
                                                         $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                     printCompilerInfoNode("<EXP> relational_expression REDUCE to equality_expression",NULL);
														}
	| equality_expression EQ_OP relational_expression   {printCompilerInfoNode("equality_expression EQ_OP relational_expression REDUCE to equality_expression",NULL);}
	| equality_expression NE_OP relational_expression   {printCompilerInfoNode("equality_expression NE_OP relational_expression REDUCE to equality_expression",NULL);}
	;

and_expression
	: equality_expression                          {
                                                    $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                printCompilerInfoNode("<EXP> equality_expression REDUCE to and_expression",NULL);
												   }
	| and_expression BIT_AND equality_expression   {printCompilerInfoNode("and_expression BIT_AND equality_expression REDUCE to and_expression",NULL);}
	;

exclusive_or_expression
	: and_expression                                  {
                                                       $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                   printCompilerInfoNode("<EXP> and_expression REDUCE to exclusive_or_expression",NULL);
													  }
	| exclusive_or_expression XOR_OP and_expression   {printCompilerInfoNode("exclusive_or_expression XOR_OP and_expression REDUCE to exclusive_or_expression",NULL);}
	;

inclusive_or_expression
	: exclusive_or_expression                                  {
                                                                $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                            printCompilerInfoNode("<EXP> exclusive_or_expression REDUCE to inclusive_or_expression",NULL);
															   }
	| inclusive_or_expression BIT_OR exclusive_or_expression   {printCompilerInfoNode("inclusive_or_expression BIT_OR exclusive_or_expression REDUCE to inclusive_or_expression",NULL);}
	;

logical_and_expression
	: inclusive_or_expression                               {
                                                             $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                         printCompilerInfoNode("<EXP> inclusive_or_expression REDUCE to logical_and_expression",NULL);
															}
	| logical_and_expression AND_OP inclusive_or_expression {printCompilerInfoNode("logical_and_expression AND_OP inclusive_or_expression REDUCE to logical_and_expression",NULL);}
	;

logical_or_expression
	: logical_and_expression                             {
                                                          $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                      printCompilerInfoNode("<EXP> logical_and_expression REDUCE to logical_or_expression",NULL);
														 }
	| logical_or_expression OR_OP logical_and_expression {printCompilerInfoNode("logical_or_expression OR_OP logical_and_expression REDUCE to logical_or_expression",NULL);}
	;

conditional_expression
	: logical_or_expression                                                        {
                                                                                    $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                                                printCompilerInfoNode("<EXP> logical_or_expression REDUCE to conditional_expression",NULL);
																				   }
	| logical_or_expression QUESTION_OP expression COLON_OP conditional_expression {printCompilerInfoNode("logical_or_expression QUESTION_OP expression COLON_OP conditional_expression REDUCE to conditional_expression",NULL);}
	;

assignment_expression
	: conditional_expression                                     {
                                                                  $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                              printCompilerInfoNode("<EXP> conditional_expression REDUCE to assignment_expression",NULL);
																 }
	| unary_expression assignment_operator assignment_expression {
	                                                              $<CompilerInfo>$ = $<CompilerInfo>3;
	                                                              printCompilerInfoNode("<EXP> unary_expression assignment_operator assignment_expression REDUCE to assignment_expression",NULL);
	                                                             }
	;

assignment_operator
	: EQUAL_OP     {printCompilerInfoNode("EQUAL_OP REDUCE to assignment_operator",NULL);}
	| MUL_ASSIGN   {printCompilerInfoNode("MUL_ASSIGN REDUCE to assignment_operator",NULL);}
	| DIV_ASSIGN   {printCompilerInfoNode("DIV_ASSIGN REDUCE to assignment_operator",NULL);}
	| MOD_ASSIGN   {printCompilerInfoNode("MOD_ASSIGN REDUCE to assignment_operator",NULL);}
	| ADD_ASSIGN   {printCompilerInfoNode("ADD_ASSIGN REDUCE to assignment_operator",NULL);}
	| SUB_ASSIGN   {printCompilerInfoNode("SUB_ASSIGN REDUCE to assignment_operator",NULL);}
	| LEFT_ASSIGN  {printCompilerInfoNode("LEFT_ASSIGN REDUCE to assignment_operator",NULL);}
	| RIGHT_ASSIGN {printCompilerInfoNode("RIGHT_ASSIGN REDUCE to assignment_operator",NULL);}
	| AND_ASSIGN   {printCompilerInfoNode("AND_ASSIGN REDUCE to assignment_operator",NULL);}
	| XOR_ASSIGN   {printCompilerInfoNode("XOR_ASSIGN REDUCE to assignment_operator",NULL);}
	| OR_ASSIGN    {printCompilerInfoNode("OR_ASSIGN REDUCE to assignment_operator",NULL);}
	;

expression
	: assignment_expression                     {
		                                         $<CompilerInfo>$ = $<CompilerInfo>1;
		                                         printCompilerInfoNode("<EXP> assignment_expression REDUCE to expression",NULL);
											    }
	| expression COMMA_OP assignment_expression {printCompilerInfoNode(" expression COMMA_OP assignment_expression REDUCE to expression",NULL);}
	;

constant_expression
	: conditional_expression   {printCompilerInfoNode("conditional_expression REDUCE to constant_expression",NULL);}
	;

declaration
	: declaration_specifiers SEMI_OP                        {printCompilerInfoNode("declaration_specifiers SEMI_OP REDUCE to declaration",NULL);}
	| declaration_specifiers init_declarator_list SEMI_OP   {
                                                             $<CompilerInfo>$.data.sign = $<CompilerInfo>1.data.sign;
	                                                         $<CompilerInfo>$.data.type = $<CompilerInfo>1.data.type;
	                                                         $<CompilerInfo>$.data.storage = $<CompilerInfo>1.data.storage;
 	                                                         $<CompilerInfo>$.data.pointerLevel = $<CompilerInfo>2.data.pointerLevel;
															 memset($<CompilerInfo>$.data.identifier,sizeof($<CompilerInfo>$.data.identifier),0);
	                                                         strcpy($<CompilerInfo>$.data.identifier, $<CompilerInfo>2.data.identifier);
														     printCompilerInfoNode("declaration_specifiers init_declarator_list SEMI_OP REDUCE to declaration",&$<CompilerInfo>$);
															}
	;

declaration_specifiers
	: storage_class_specifier                        {printCompilerInfoNode("storage_class_specifier REDUCE to declaration_specifiers",NULL);}
	| storage_class_specifier declaration_specifiers {
	                                                  $<CompilerInfo>$.data.sign = $<CompilerInfo>2.data.sign;
	                                                  $<CompilerInfo>$.data.type = $<CompilerInfo>2.data.type;
	                                                  $<CompilerInfo>$.data.storage = $<CompilerInfo>1.data.storage;
                                                      $<CompilerInfo>$.data.pointerLevel = $<CompilerInfo>2.data.pointerLevel;
	                                                  printCompilerInfoNode("storage_class_specifier declaration_specifiers REDUCE to declaration_specifiers",&$<CompilerInfo>$);
													 }
	| type_specifier                                 {
	                                                   $<CompilerInfo>$ = $<CompilerInfo>1;
													   printCompilerInfoNode("type_specifier REDUCE to declaration_specifiers",&$<CompilerInfo>$);
													 }
	| type_specifier declaration_specifiers          {
	                                                   $<CompilerInfo>$.data.sign = $<CompilerInfo>1.data.sign;
	                                                   $<CompilerInfo>$.data.type = $<CompilerInfo>2.data.type;
													   printCompilerInfoNode("type_specifier declaration_specifiers REDUCE to declaration_specifiers",&$<CompilerInfo>$);
													 }
	| type_qualifier                                 {printCompilerInfoNode("type_qualifier REDUCE to declaration_specifiers",NULL);}
	| type_qualifier declaration_specifiers          {printCompilerInfoNode("type_qualifier declaration_specifiers SEMI_OP REDUCE to declaration_specifiers",NULL);}
	| function_specifier                             {printCompilerInfoNode("function_specifier REDUCE to declaration_specifiers",NULL);}
	| function_specifier declaration_specifiers      {printCompilerInfoNode("function_specifier declaration_specifiers REDUCE to declaration_specifiers",NULL);}
	;

init_declarator_list
	: init_declarator                               {
                                                     $<CompilerInfo>$ = $<CompilerInfo>1;
                                                     printCompilerInfoNode("init_declarator REDUCE to init_declarator_list",&$<CompilerInfo>$);
													}
	| init_declarator_list COMMA_OP init_declarator {
	                                                 $<CompilerInfo>$ = $<CompilerInfo>3;
	                                                 printCompilerInfoNode("init_declarator_list COMMA_OP init_declarator REDUCE to init_declarator_list",&$<CompilerInfo>$);
													 //addToSymbolTable($<CompilerInfo>3.identifier, $<CompilerInfo>3.type, $<CompilerInfo>3.sign, $<CompilerInfo>3.storage, $<CompilerInfo>3.declarationType, $<CompilerInfo>3.constant, $<CompilerInfo>3.arrayExpression);
	                                                }
	;

init_declarator
	: declarator                      {
                                       $<CompilerInfo>$ = $<CompilerInfo>1;
	                                   printCompilerInfoNode("declarator REDUCE to init_declarator",&$<CompilerInfo>$);
									  }
	| declarator EQUAL_OP initializer {printCompilerInfoNode("declarator EQUAL_OP initializer REDUCE to init_declarator",NULL);}
	;

storage_class_specifier
	: TYPEDEF  {$<CompilerInfo>$.data.storage = STORAGE_NONE;     printCompilerInfoNode("TYPEDEF REDUCE to storage_class_specifier",NULL);}
	| EXTERN   {$<CompilerInfo>$.data.storage = STORAGE_EXTERN;   printCompilerInfoNode("EXTERN REDUCE to storage_class_specifier",NULL);}
	| STATIC   {$<CompilerInfo>$.data.storage = STORAGE_STATIC;   printCompilerInfoNode("STATIC REDUCE to storage_class_specifier",NULL);}
	| AUTO     {$<CompilerInfo>$.data.storage = STORAGE_AUTO;     printCompilerInfoNode("AUTO REDUCE to storage_class_specifier",NULL);}
	| REGISTER {$<CompilerInfo>$.data.storage = STORAGE_REGISTER; printCompilerInfoNode("REGISTER REDUCE to storage_class_specifier",NULL);}
	;

type_specifier
	: VOID                      {$<CompilerInfo>$.data.type = TYPE_VOID;      printCompilerInfoNode("TYPE_VOID REDUCE to type_specifier",NULL); }
	| CHAR                      {$<CompilerInfo>$.data.type = TYPE_CHARACTER; printCompilerInfoNode("TYPE_CHARACTER REDUCE to type_specifier",NULL); }
	| SHORT                     {$<CompilerInfo>$.data.type = TYPE_SHORT;     printCompilerInfoNode("TYPE_SHORT REDUCE to type_specifier",NULL); }
	| INT                       {$<CompilerInfo>$.data.type = TYPE_INTEGER;   printCompilerInfoNode("TYPE_INTEGER REDUCE to type_specifier",NULL); }
	| LONG                      {$<CompilerInfo>$.data.type = TYPE_LONG;      printCompilerInfoNode("TYPE_LONG REDUCE to type_specifier",NULL); }
	| LONGLONG                  {$<CompilerInfo>$.data.type = TYPE_LONG64;    printCompilerInfoNode("TYPE_LONG64 REDUCE to type_specifier",NULL); }
	| FLOAT                     {$<CompilerInfo>$.data.type = TYPE_FLOAT;     printCompilerInfoNode("TYPE_FLOAT REDUCE to type_specifier",NULL); }
	| DOUBLE                    {$<CompilerInfo>$.data.type = TYPE_DOUBLE;    printCompilerInfoNode("TYPE_DOUBLE REDUCE to type_specifier",NULL); }
	| LONGDOUBLE                {$<CompilerInfo>$.data.type = TYPE_LONGDOUBLE;printCompilerInfoNode("TYPE_LONGDOUBLE REDUCE to type_specifier",NULL); }
	| SIGNED                    {$<CompilerInfo>$.data.sign = TYPE_SIGNED;    printCompilerInfoNode("TYPE_SIGNED REDUCE to type_specifier",NULL); }
	| UNSIGNED                  {$<CompilerInfo>$.data.sign = TYPE_UNSIGNED;  printCompilerInfoNode("TYPE_UNSIGNED REDUCE to type_specifier",NULL); }
	| BOOL                      {$<CompilerInfo>$.data.type = TYPE_BOOLEAN;   printCompilerInfoNode("TYPE_BOOLEAN REDUCE to type_specifier",NULL); }
	| COMPLEX                   {$<CompilerInfo>$.data.type = TYPE_COMPLEX;   printCompilerInfoNode("TYPE_COMPLEX REDUCE to type_specifier",NULL); }
	| IMAGINARY                 {$<CompilerInfo>$.data.type = TYPE_IMAGINARY; printCompilerInfoNode("TYPE_IMAGINARY REDUCE to type_specifier",NULL); }
	| struct_or_union_specifier {printCompilerInfoNode("struct_or_union_specifier REDUCE to type_specifier",NULL);}
	| enum_specifier            {printCompilerInfoNode("enum_specifier REDUCE to type_specifier",NULL);}
	| TYPE_NAME                 {printCompilerInfoNode("type_specifier TYPE_NAME REDUCE to type_specifier",NULL);}
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER OCURLY_OP struct_declaration_list CCURLY_OP  {printCompilerInfoNode("struct_or_union IDENTIFIER OCURLY_OP struct_declaration_list CCURLY_OP REDUCE to struct_or_union_specifier",NULL);}
	| struct_or_union OCURLY_OP struct_declaration_list CCURLY_OP             {printCompilerInfoNode("struct_or_union OCURLY_OP struct_declaration_list CCURLY_OP REDUCE to struct_or_union_specifier",NULL);}
	| struct_or_union IDENTIFIER                                              {printCompilerInfoNode("struct_or_union IDENTIFIER REDUCE to struct_or_union_specifier",NULL);}
	;

struct_or_union
	: STRUCT   {printCompilerInfoNode("STRUCT REDUCE to struct_or_union",NULL);}
	| UNION    {printCompilerInfoNode("UNION REDUCE to struct_or_union",NULL);}
	;

struct_declaration_list
	: struct_declaration                         {printCompilerInfoNode("struct_declaration REDUCE to struct_declaration_list",NULL);}
	| struct_declaration_list struct_declaration {printCompilerInfoNode("struct_declaration_list struct_declaration REDUCE to struct_declaration_list",NULL);}
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list SEMI_OP  {printCompilerInfoNode("specifier_qualifier_list struct_declarator_list SEMI_OP REDUCE to struct_declaration",NULL);}
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list {printCompilerInfoNode("type_specifier specifier_qualifier_list REDUCE to specifier_qualifier_list",NULL);}
	| type_specifier                          {printCompilerInfoNode("type_specifier REDUCE to specifier_qualifier_list",NULL);}
	| type_qualifier specifier_qualifier_list {printCompilerInfoNode("type_qualifier specifier_qualifier_list REDUCE to specifier_qualifier_list",NULL);}
	| type_qualifier                          {printCompilerInfoNode("type_qualifier REDUCE to specifier_qualifier_list",NULL);}
	;

struct_declarator_list
	: struct_declarator                                 {printCompilerInfoNode("struct_declarator REDUCE to struct_declarator_list",NULL);}
	| struct_declarator_list COMMA_OP struct_declarator {printCompilerInfoNode("struct_declarator_list COMMA_OP struct_declarator REDUCE to struct_declarator_list",NULL);}
	;

struct_declarator
	: declarator                                 {printCompilerInfoNode("declarator REDUCE to struct_declarator",NULL);}
	| COLON_OP constant_expression               {printCompilerInfoNode("COLON_OP constant_expression REDUCE to struct_declarator",NULL);}
	| declarator COLON_OP constant_expression    {printCompilerInfoNode("declarator COLON_OP constant_expression REDUCE to struct_declarator",NULL);}
	;

enum_specifier
	: ENUM OCURLY_OP enumerator_list CCURLY_OP                     {printCompilerInfoNode("ENUM OCURLY_OP enumerator_list CCURLY_OP REDUCE to enum_specifier",NULL);}
	| ENUM IDENTIFIER OCURLY_OP enumerator_list CCURLY_OP          {printCompilerInfoNode("ENUM IDENTIFIER OCURLY_OP enumerator_list CCURLY_OP REDUCE to enum_specifier",NULL);}
	| ENUM OCURLY_OP enumerator_list COMMA_OP CCURLY_OP            {printCompilerInfoNode("ENUM OCURLY_OP enumerator_list COMMA_OP CCURLY_OP REDUCE to enum_specifier",NULL);}
	| ENUM IDENTIFIER OCURLY_OP enumerator_list COMMA_OP CCURLY_OP {printCompilerInfoNode("ENUM IDENTIFIER OCURLY_OP enumerator_list COMMA_OP CCURLY_OP REDUCE to enum_specifier",NULL);}
	| ENUM IDENTIFIER                                              {printCompilerInfoNode("ENUM IDENTIFIER REDUCE to enum_specifier",NULL);}
	;

enumerator_list
	: enumerator                           {printCompilerInfoNode("enumerator REDUCE to enumerator_list",NULL);}
	| enumerator_list COMMA_OP enumerator  {printCompilerInfoNode("enumerator_list COMMA_OP enumerator REDUCE to enumerator_list",NULL);}
	;

enumerator
	: IDENTIFIER                              {printCompilerInfoNode("IDENTIFIER REDUCE to enumerator",NULL);}
	| IDENTIFIER EQUAL_OP constant_expression {printCompilerInfoNode("IDENTIFIER EQUAL_OP constant_expression REDUCE to enumerator",NULL);}
	;

type_qualifier
	: CONST    {printCompilerInfoNode("CONST REDUCE to type_qualifier",NULL);}
	| RESTRICT {printCompilerInfoNode("RESTRICT REDUCE to type_qualifier",NULL);}
	| VOLATILE {printCompilerInfoNode("VOLATILE REDUCE to type_qualifier",NULL);}
	;

function_specifier
	: INLINE  {printCompilerInfoNode("INLINE REDUCE to function_specifier",NULL);}
	;

declarator
	: pointer direct_declarator  {
	                              $<CompilerInfo>$ = $<CompilerInfo>2;
								  $<CompilerInfo>$.data.pointerLevel = $<CompilerInfo>1.data.pointerLevel;
	                              printCompilerInfoNode("pointer direct_declarator REDUCE to declarator",&$<CompilerInfo>$);
								 }
	| direct_declarator          {
                                  $<CompilerInfo>$ = $<CompilerInfo>1;
                                  printCompilerInfoNode("direct_declarator REDUCE to declarator",&$<CompilerInfo>$);									  
								 }
	;


direct_declarator
	: IDENTIFIER                                                                                      {
	                                                                                                   $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                                                                   printCompilerInfoNode("IDENTIFIER REDUCE to direct_declarator",&$<CompilerInfo>$);
																									  }
	| OPENPAREN_OP declarator CLOSEPAREN_OP                                                           {printCompilerInfoNode("OPENPAREN_OP declarator CLOSEPAREN_OP REDUCE to direct_declarator",NULL);}
	| direct_declarator OPENBRACE_OP type_qualifier_list assignment_expression CLOSEBRACE_OP          {printCompilerInfoNode("direct_declarator OPENBRACE_OP type_qualifier_list assignment_expression CLOSEBRACE_OP REDUCE to direct_declarator",NULL);}
	| direct_declarator OPENBRACE_OP type_qualifier_list CLOSEBRACE_OP                                {printCompilerInfoNode("direct_declarator OPENBRACE_OP type_qualifier_list CLOSEBRACE_OP REDUCE to direct_declarator",NULL);}
	| direct_declarator OPENBRACE_OP assignment_expression CLOSEBRACE_OP                              {
	                                                                                                   $<CompilerInfo>$ = $<CompilerInfo>1;
																									   addToExpression(&$<CompilerInfo>$.arrayExpression,$<CompilerInfo>1.data.identifier,$<CompilerInfo>1.data.type,$<CompilerInfo>1.data.sign,FALSE);
	                                                                                                   printCompilerInfoNode("<EXP> direct_declarator OPENBRACE_OP assignment_expression CLOSEBRACE_OP REDUCE to direct_declarator",NULL);
																									  }
	| direct_declarator OPENBRACE_OP STATIC type_qualifier_list assignment_expression CLOSEBRACE_OP   {printCompilerInfoNode("direct_declarator OPENBRACE_OP STATIC type_qualifier_list assignment_expression CLOSEBRACE_OP REDUCE to direct_declarator",NULL);}
	| direct_declarator OPENBRACE_OP type_qualifier_list STATIC assignment_expression CLOSEBRACE_OP   {printCompilerInfoNode("direct_declarator OPENBRACE_OP type_qualifier_list STATIC assignment_expression CLOSEBRACE_OP REDUCE to direct_declarator",NULL);}
	| direct_declarator OPENBRACE_OP type_qualifier_list TIMES_OP CLOSEBRACE_OP                       {printCompilerInfoNode("direct_declarator OPENBRACE_OP type_qualifier_list TIMES_OP CLOSEBRACE_OP REDUCE to direct_declarator",NULL);}
	| direct_declarator OPENBRACE_OP TIMES_OP CLOSEBRACE_OP                                           {printCompilerInfoNode("direct_declarator OPENBRACE_OP TIMES_OP CLOSEBRACE_OP REDUCE to direct_declarator",NULL);}
	| direct_declarator OPENBRACE_OP CLOSEBRACE_OP                                                    {printCompilerInfoNode("direct_declarator OPENBRACE_OP CLOSEBRACE_OP REDUCE to direct_declarator",NULL);}
	| direct_declarator OPENPAREN_OP parameter_type_list CLOSEPAREN_OP                                {
	                                                                                                   $<CompilerInfo>$ = $<CompilerInfo>1;
																									   $<CompilerInfo>$.parameterList = $<ParameterList>3;																									   
	                                                                                                   printCompilerInfoNode("direct_declarator OPENPAREN_OP parameter_type_list CLOSEPAREN_OP REDUCE to direct_declarator", &$<CompilerInfo>$);
																									  }
	| direct_declarator OPENPAREN_OP identifier_list CLOSEPAREN_OP                                    {printCompilerInfoNode("direct_declarator OPENPAREN_OP identifier_list CLOSEPAREN_OP REDUCE to direct_declarator",NULL);}
	| direct_declarator OPENPAREN_OP CLOSEPAREN_OP                                                    {
		                                                                                               $<CompilerInfo>$ = $<CompilerInfo>1;
		                                                                                               printCompilerInfoNode("direct_declarator OPENPAREN_OP CLOSEPAREN_OP REDUCE to direct_declarator",&$<CompilerInfo>$);
																									  }
	;

pointer
	: TIMES_OP                             {$<CompilerInfo>$.data.pointerLevel++; printCompilerInfoNode("TIMES_OP REDUCE to pointer",&$<CompilerInfo>$);}
	| TIMES_OP type_qualifier_list         {printCompilerInfoNode("TIMES_OP type_qualifier_list REDUCE to pointer",NULL);}
	| TIMES_OP pointer                     {
		                                    $<CompilerInfo>$.data.pointerLevel = $<CompilerInfo>2.data.pointerLevel; 
		                                    $<CompilerInfo>$.data.pointerLevel++; 
											printCompilerInfoNode("TIMES_OP pointer REDUCE to pointer",&$<CompilerInfo>$);
										   }
	| TIMES_OP type_qualifier_list pointer {printCompilerInfoNode("TIMES_OP type_qualifier_list pointer REDUCE to pointer",NULL);}
	;

type_qualifier_list
	: type_qualifier                     {printCompilerInfoNode("type_qualifier REDUCE to type_qualifier_list",NULL);}
	| type_qualifier_list type_qualifier {printCompilerInfoNode("type_qualifier_list type_qualifier REDUCE to type_qualifier_list",NULL);}
	;


parameter_type_list
	: parameter_list                   {
	                                    $<CompilerInfo>$.parameterList = $<ParameterList>1;
                                        printCompilerInfoNode("<EXP> parameter_list REDUCE to parameter_type_list",&$<CompilerInfo>$);
									   }
	| parameter_list COMMA_OP ELLIPSIS {
	                                    $<CompilerInfo>$.parameterList = $<ParameterList>1;
	                                    printCompilerInfoNode("<EXP> parameter_list COMMA_OP ELLIPSIS REDUCE to parameter_type_list",&$<CompilerInfo>$);
									   }
	;

parameter_list
	: parameter_declaration                         {
	                                                 $<ParameterList>$ = createParameterListNode(&$<CompilerInfo>1);
	                                                 printParameterListNode("parameter_declaration REDUCE to parameter_list",$<ParameterList>$);
													}
	| parameter_list COMMA_OP parameter_declaration {
	                                                 addToParameterList2(&$<ParameterList>1, &$<CompilerInfo>1);
													 $<ParameterList>$ = $<ParameterList>1;
	                                                 printParameterListNode("parameter_list COMMA_OP parameter_declaration REDUCE to parameter_list",$<ParameterList>$);
													}
	;

parameter_declaration
	: declaration_specifiers declarator          {
                                                  $<CompilerInfo>$ = $<CompilerInfo>2;
					  						      $<CompilerInfo>$.data.sign = $<CompilerInfo>1.data.sign;
                                                  $<CompilerInfo>$.data.type = $<CompilerInfo>1.data.type;
                                                  $<CompilerInfo>$.data.storage = $<CompilerInfo>1.data.storage;
						                          $<CompilerInfo>$.parameterList = $<CompilerInfo>1.parameterList;
					  						      printCompilerInfoNode("declaration_specifiers declarator REDUCE to parameter_declaration",&$<CompilerInfo>$);
												 }
	| declaration_specifiers abstract_declarator {printCompilerInfoNode("declaration_specifiers abstract_declarator REDUCE to parameter_declaration",NULL);}
	| declaration_specifiers                     {printCompilerInfoNode("declaration_specifiers REDUCE to parameter_declaration",NULL);}
	;

identifier_list
	: IDENTIFIER                          {printCompilerInfoNode("IDENTIFIER REDUCE to identifier_list",NULL);}
	| identifier_list COMMA_OP IDENTIFIER {printCompilerInfoNode("identifier_list COMMA_OP IDENTIFIER REDUCE to identifier_list",NULL);}
	;

type_name
	: specifier_qualifier_list                     {printCompilerInfoNode("specifier_qualifier_list REDUCE to type_name",NULL);}
	| specifier_qualifier_list abstract_declarator {printCompilerInfoNode("specifier_qualifier_list abstract_declarator REDUCE to type_name",NULL);}
	;

abstract_declarator
	: pointer                            {printCompilerInfoNode("pointer REDUCE to abstract_declarator",NULL);}
	| direct_abstract_declarator         {printCompilerInfoNode("direct_abstract_declarator REDUCE to abstract_declarator",NULL);}
	| pointer direct_abstract_declarator {printCompilerInfoNode("pointer direct_abstract_declarator REDUCE to abstract_declarator",NULL);}
	;

direct_abstract_declarator
	: OPENPAREN_OP abstract_declarator CLOSEPAREN_OP                               {printCompilerInfoNode("OPENPAREN_OP abstract_declarator CLOSEPAREN_OP REDUCE to direct_abstract_declarator",NULL);}
	| OPENBRACE_OP CLOSEBRACE_OP                                                   {printCompilerInfoNode("OPENBRACE_OP CLOSEBRACE_OP REDUCE to direct_abstract_declarator",NULL);}
	| OPENBRACE_OP assignment_expression CLOSEBRACE_OP                             {printCompilerInfoNode("OPENBRACE_OP assignment_expression CLOSEBRACE_OP REDUCE to direct_abstract_declarator",NULL);}
	| direct_abstract_declarator OPENBRACE_OP CLOSEBRACE_OP                        {printCompilerInfoNode("direct_abstract_declarator OPENBRACE_OP CLOSEBRACE_OP REDUCE to direct_abstract_declarator",NULL);}
	| direct_abstract_declarator OPENBRACE_OP assignment_expression CLOSEBRACE_OP  {printCompilerInfoNode("direct_abstract_declarator OPENBRACE_OP assignment_expression CLOSEBRACE_OP REDUCE to direct_abstract_declarator",NULL);}
	| OPENBRACE_OP TIMES_OP CLOSEBRACE_OP                                          {printCompilerInfoNode("OPENBRACE_OP TIMES_OP CLOSEBRACE_OP REDUCE to direct_abstract_declarator",NULL);}
	| direct_abstract_declarator OPENBRACE_OP TIMES_OP CLOSEBRACE_OP               {printCompilerInfoNode("direct_abstract_declarator OPENBRACE_OP TIMES_OP CLOSEBRACE_OP REDUCE to direct_abstract_declarator",NULL);}
	| OPENPAREN_OP CLOSEPAREN_OP                                                   {printCompilerInfoNode("OPENPAREN_OP CLOSEPAREN_OP REDUCE to direct_abstract_declarator",NULL);}
	| OPENPAREN_OP parameter_type_list CLOSEPAREN_OP                               {printCompilerInfoNode("OPENPAREN_OP parameter_type_list CLOSEPAREN_OP REDUCE to direct_abstract_declarator",NULL);}
	| direct_abstract_declarator OPENPAREN_OP CLOSEPAREN_OP                        {printCompilerInfoNode("direct_abstract_declarator OPENPAREN_OP CLOSEPAREN_OP REDUCE to direct_abstract_declarator",NULL);}
	| direct_abstract_declarator OPENPAREN_OP parameter_type_list CLOSEPAREN_OP    {printCompilerInfoNode("direct_abstract_declarator OPENPAREN_OP parameter_type_list CLOSEPAREN_OP REDUCE to direct_abstract_declarator",NULL);}
	;

initializer
	: assignment_expression                         {printCompilerInfoNode("assignment_expression REDUCE to initializer",NULL);}
	| OCURLY_OP initializer_list CCURLY_OP          {printCompilerInfoNode("OCURLY_OP initializer_list CCURLY_OP REDUCE to initializer",NULL);}
	| OCURLY_OP initializer_list COMMA_OP CCURLY_OP {printCompilerInfoNode("OCURLY_OP initializer_list COMMA_OP CCURLY_OP REDUCE to initializer",NULL);}
	;

initializer_list
	: initializer                                       {printCompilerInfoNode("initializer REDUCE to initializer_list",NULL);}
	| designation initializer                           {printCompilerInfoNode("designation initializer REDUCE to initializer_list",NULL);}
	| initializer_list COMMA_OP initializer             {printCompilerInfoNode("initializer_list COMMA_OP initializer REDUCE to initializer_list",NULL);}
	| initializer_list COMMA_OP designation initializer {printCompilerInfoNode("initializer_list COMMA_OP designation initializer REDUCE to initializer_list",NULL);}
	;

designation
	: designator_list EQUAL_OP {printCompilerInfoNode("designator_list EQUAL_OP REDUCE to designation",NULL);}
	;

designator_list
	: designator                 {printCompilerInfoNode("designator REDUCE to designator_list",NULL);}
	| designator_list designator {printCompilerInfoNode("designator_list designator EQUAL_OP REDUCE to designator_list",NULL);}
	;

designator
	: OPENBRACE_OP constant_expression CLOSEBRACE_OP    {printCompilerInfoNode("labeled_statement REDUCE to statement",NULL);}
	| PERIOD_OP IDENTIFIER                              {printCompilerInfoNode("labeled_statement REDUCE to statement",NULL);}
	;

statement
	: labeled_statement     {printCompilerInfoNode("labeled_statement REDUCE to statement",NULL);}
	| compound_statement    {printCompilerInfoNode("compound_statement REDUCE to statement",NULL);}
	| expression_statement  {printCompilerInfoNode("expression_statement REDUCE to statement",NULL);}
	| selection_statement   {printCompilerInfoNode("selection_statement REDUCE to statement",NULL);}
	| iteration_statement   {printCompilerInfoNode("iteration_statement REDUCE to statement",NULL);}
	| jump_statement        {
		                     $<CompilerInfo>$ = $<CompilerInfo>1;
		                     printCompilerInfoNode("<EXP> jump_statement REDUCE to statement",NULL);
							}
	;

labeled_statement
	: IDENTIFIER COLON_OP statement               {printCompilerInfoNode("IDENTIFIER COLON_OP statement REDUCE to labeled_statement",NULL);}
	| CASE constant_expression COLON_OP statement {printCompilerInfoNode("CASE constant_expression COLON_OP statement REDUCE to labeled_statement",NULL);}
	| DEFAULT COLON_OP statement                  {printCompilerInfoNode("DEFAULT COLON_OP statement REDUCE to labeled_statement",NULL);}
	;

compound_statement
	: OCURLY_OP CCURLY_OP                 {printCompilerInfoNode("OCURLY_OP CCURLY_OP REDUCE to compound_statement",NULL);}
	| OCURLY_OP block_item_list CCURLY_OP {
		                                   $<CompilerInfo>$ = $<CompilerInfo>2;
		                                   printCompilerInfoNode("<EXP> OCURLY_OP block_item_list CCURLY_OP REDUCE to compound_statement",NULL);
										  }
	;

block_item_list
	: block_item                 {
		                          $<CompilerInfo>$ = $<CompilerInfo>1;
		                          printCompilerInfoNode("<EXP> block_item REDUCE to block_item_list",NULL);
								 }
	| block_item_list block_item {printCompilerInfoNode("block_item_list block_item REDUCE to block_item_list",NULL);}
	;

block_item
	: declaration  {printCompilerInfoNode("declaration REDUCE to block_item",NULL);}
	| statement    {
		            $<CompilerInfo>$ = $<CompilerInfo>1;
		            printCompilerInfoNode("<EXP> statement REDUCE to block_item",NULL);
				   }
	;

expression_statement
	: SEMI_OP            {printCompilerInfoNode("SEMI_OP REDUCE to expression_statement",NULL);}
	| expression SEMI_OP {printCompilerInfoNode("expression SEMI_OP REDUCE to expression_statement",NULL);}
	;

selection_statement
	: IF OPENPAREN_OP expression CLOSEPAREN_OP statement                {printCompilerInfoNode("IF OPENPAREN_OP expression CLOSEPAREN_OP statement REDUCE to selection_statement",NULL);}
	| IF OPENPAREN_OP expression CLOSEPAREN_OP statement ELSE statement {printCompilerInfoNode("IF OPENPAREN_OP expression CLOSEPAREN_OP statement ELSE statement REDUCE to selection_statement",NULL);}
	| SWITCH OPENPAREN_OP expression CLOSEPAREN_OP statement            {printCompilerInfoNode("SWITCH OPENPAREN_OP expression CLOSEPAREN_OP statement REDUCE to selection_statement",NULL);}
	;

iteration_statement
	: WHILE OPENPAREN_OP expression CLOSEPAREN_OP statement                                         {printCompilerInfoNode("WHILE OPENPAREN_OP expression CLOSEPAREN_OP statement REDUCE to iteration_statement",NULL);}
	| DO statement WHILE OPENPAREN_OP expression CLOSEPAREN_OP SEMI_OP                              {printCompilerInfoNode("DO statement WHILE OPENPAREN_OP expression CLOSEPAREN_OP SEMI_OP REDUCE to iteration_statement",NULL);}
	| FOR OPENPAREN_OP expression_statement expression_statement CLOSEPAREN_OP statement            {printCompilerInfoNode("FOR OPENPAREN_OP expression_statement expression_statement CLOSEPAREN_OP statement REDUCE to iteration_statement",NULL);}
	| FOR OPENPAREN_OP expression_statement expression_statement expression CLOSEPAREN_OP statement {printCompilerInfoNode("FOR OPENPAREN_OP expression_statement expression_statement expression CLOSEPAREN_OP statement REDUCE to iteration_statement",NULL);}
	| FOR OPENPAREN_OP declaration expression_statement CLOSEPAREN_OP statement                     {printCompilerInfoNode("FOR OPENPAREN_OP declaration expression_statement CLOSEPAREN_OP statement REDUCE to iteration_statement",NULL);}
	| FOR OPENPAREN_OP declaration expression_statement expression CLOSEPAREN_OP statement          {printCompilerInfoNode("FOR OPENPAREN_OP declaration expression_statement expression CLOSEPAREN_OP statement REDUCE to iteration_statement",NULL);}
	;

jump_statement
	: GOTO IDENTIFIER SEMI_OP   {printCompilerInfoNode("GOTO IDENTIFIER SEMI_OP REDUCE to jump_statement",NULL);}
	| CONTINUE SEMI_OP          {printCompilerInfoNode("CONTINUE SEMI_OP REDUCE to jump_statement",NULL);}
	| BREAK SEMI_OP             {printCompilerInfoNode("BREAK SEMI_OP REDUCE to jump_statement",NULL);}
	| RETURN SEMI_OP            {printCompilerInfoNode("RETURN SEMI_OP REDUCE to jump_statement",NULL);}
	| RETURN expression SEMI_OP {
		                         $<CompilerInfo>$ = $<CompilerInfo>2;
		                         printCompilerInfoNode("<EXP> RETURN expression SEMI_OP REDUCE to jump_statement",NULL);
								}
	;

translation_unit
	: external_declaration                  {
                                             $<CompilerInfo>$ = $<CompilerInfo>1;
											 addToSymbolTable($<CompilerInfo>1.data.pointerLevel,$<CompilerInfo>1.data.identifier, $<CompilerInfo>1.data.type, $<CompilerInfo>1.data.sign, $<CompilerInfo>1.data.storage, $<CompilerInfo>1.data.declarationType, $<CompilerInfo>1.data.constant, $<CompilerInfo>1.arrayExpression);
											 addToFunctionTable($<CompilerInfo>1.data.identifier, $<CompilerInfo>1.data.type, $<CompilerInfo>1.data.sign, $<CompilerInfo>1.data.storage, $<CompilerInfo>1.data.declarationType, $<CompilerInfo>1.data.constant, $<CompilerInfo>1.arrayExpression,$<CompilerInfo>1.parameterList);
	                                         printCompilerInfoNode("external_declaration REDUCE to translation_unit",&$<CompilerInfo>$);
											}
	| translation_unit external_declaration {
											 addToSymbolTable($<CompilerInfo>2.data.pointerLevel,$<CompilerInfo>2.data.identifier, $<CompilerInfo>2.data.type, $<CompilerInfo>2.data.sign, $<CompilerInfo>2.data.storage, $<CompilerInfo>2.data.declarationType, $<CompilerInfo>2.data.constant, $<CompilerInfo>1.arrayExpression);
											 addToFunctionTable($<CompilerInfo>2.data.identifier, $<CompilerInfo>2.data.type, $<CompilerInfo>2.data.sign, $<CompilerInfo>2.data.storage, $<CompilerInfo>2.data.declarationType, $<CompilerInfo>1.data.constant, $<CompilerInfo>1.arrayExpression,$<CompilerInfo>2.parameterList);
		                                     printCompilerInfoNode("translation_unit external_declaration REDUCE to translation_unit",&$<CompilerInfo>$);
											}
	;

external_declaration
	: function_definition {
                           $<CompilerInfo>$ = $<CompilerInfo>1;
						   $<CompilerInfo>$.data.declarationType = DECLARATION_FUNCTION;
						   $<CompilerInfo>$.data.sign = $<CompilerInfo>1.data.sign;
                           $<CompilerInfo>$.data.type = $<CompilerInfo>1.data.type;
                           $<CompilerInfo>$.data.storage = $<CompilerInfo>1.data.storage;
						   $<CompilerInfo>$.parameterList = $<CompilerInfo>1.parameterList;
                           //addToFunctionTable($<CompilerInfo>$.data.identifier, $<CompilerInfo>$.data.type, $<CompilerInfo>$.data.sign, $<CompilerInfo>$.data.storage, $<CompilerInfo>$.data.declarationType, $<CompilerInfo>$.data.constant, $<CompilerInfo>$.arrayExpression,$<CompilerInfo>$.parameterList);
						   printCompilerInfoNode("function_definition REDUCE to external_declaration",&$<CompilerInfo>$);
						  }
	| declaration         {
                           $<CompilerInfo>$ = $<CompilerInfo>1;
						   $<CompilerInfo>$.data.declarationType = DECLARATION_VARIABLE;
                           $<CompilerInfo>$.data.sign = $<CompilerInfo>1.data.sign;
                           $<CompilerInfo>$.data.type = $<CompilerInfo>1.data.type;
                           $<CompilerInfo>$.data.storage = $<CompilerInfo>1.data.storage;
                           $<CompilerInfo>$.data.pointerLevel = $<CompilerInfo>1.data.pointerLevel;
						   memset($<CompilerInfo>$.data.identifier,sizeof($<CompilerInfo>$.data.identifier),0);
                           strcpy($<CompilerInfo>$.data.identifier,$<CompilerInfo>1.data.identifier);
                           //addToSymbolTable($<CompilerInfo>$.data.identifier, $<CompilerInfo>$.data.type, $<CompilerInfo>$.data.sign, $<CompilerInfo>$.data.storage, $<CompilerInfo>$.data.declarationType, $<CompilerInfo>$.data.constant, $<CompilerInfo>$.arrayExpression,$<CompilerInfo>$.parameterList);
                           printCompilerInfoNode("declaration REDUCE to external_declaration",&$<CompilerInfo>$);
						  }
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement {printCompilerInfoNode("declaration_specifiers declarator declaration_list compound_statement REDUCE to function_definition",NULL);}
	| declaration_specifiers declarator compound_statement                  { 
		                                                                     
																			 $<CompilerInfo>$=$<CompilerInfo>2;
																			 $<CompilerInfo>$.data.sign = $<CompilerInfo>1.data.sign;
                                                                             $<CompilerInfo>$.data.type = $<CompilerInfo>1.data.type;
                                                                             $<CompilerInfo>$.data.storage = $<CompilerInfo>1.data.storage;
		                                                                     printCompilerInfoNode("declaration_specifiers declarator compound_statement REDUCE to function_definition", &$<CompilerInfo>$);
																			}
	;

declaration_list
	: declaration                   {printCompilerInfoNode("declaration REDUCE to declaration_list",NULL);}
	| declaration_list declaration  {printCompilerInfoNode("declaration_list declaration REDUCE to declaration_list",NULL);}
	;

%%

void yyerror(const char* s) {
	fprintf(stderr, "Parse error on line %d column %d : %s", yylineno, column, s);
	num_errors++;
}