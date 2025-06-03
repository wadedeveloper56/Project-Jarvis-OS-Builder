%{
#include "global.h"
%}

%union { 	   
    struct CompilerInfo {   
       char *identifier;     
       VariableType type;
	   VariableSignType sign;
	   StorageType storage;
	   DeclarationType declarationType;
	   Boolean constant; 

       void *noDefinition;	
    } CompilerInfo;
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
%token<noDefinition> CHAR SHORT INT LONG LONGLONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
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
%type<CompilerInfo> type_qualifier_list parameter_type_list parameter_list parameter_declaration identifier_list
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
											 $<CompilerInfo>$.identifier = (char *) malloc(strlen($<CompilerInfo>1.identifier)+1);
                                             strcpy($<CompilerInfo>$.identifier, $<CompilerInfo>1.identifier);
                                             $<CompilerInfo>$.type = TYPE_NULL;
                                             $<CompilerInfo>$.constant = FALSE;
	                                         fprintf(yyout,"IDENTIFIER REDUCE to primary_expression\n");
											}
	| CONSTANT                              {
											 $<CompilerInfo>$.identifier = (char *) malloc(strlen($<CompilerInfo>1.identifier)+1);
                                             strcpy($<CompilerInfo>$.identifier, $<CompilerInfo>1.identifier);
                                             $<CompilerInfo>$.type = TYPE_NULL;
                                             $<CompilerInfo>$.constant = TRUE;
	                                         fprintf(yyout,"'%s' CONSTANT REDUCE to primary_expression\n",$<CompilerInfo>$.identifier);
											}
	| STRING_LITERAL                        {
											 $<CompilerInfo>$.identifier = (char *) malloc(strlen($<CompilerInfo>1.identifier)+1);
                                             strcpy($<CompilerInfo>$.identifier, $<CompilerInfo>1.identifier);
                                             $<CompilerInfo>$.type = TYPE_NULL;
                                             $<CompilerInfo>$.constant = TRUE;
	                                         fprintf(yyout,"'%s' STRING_LITERAL REDUCE to primary_expression\n",$<CompilerInfo>$.identifier);
											}
	| OPENPAREN_OP expression CLOSEPAREN_OP {
                                             $<CompilerInfo>$ = $<CompilerInfo>2;
	                                         fprintf(yyout,"OPENPAREN_OP expression CLOSEPAREN_OP REDUCE to primary_expression\n");
											}
	;

postfix_expression
	: primary_expression                                                                 {
                                                                                          $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                                                      fprintf(yyout,"<EXP> primary_expression REDUCE to postfix_expression\n");
																						 }
	| postfix_expression OPENBRACE_OP expression CLOSEBRACE_OP                           {fprintf(yyout,"postfix_expression OPENBRACE_OP expression CLOSEBRACE_OP REDUCE to postfix_expression\n");}
	| postfix_expression OPENPAREN_OP CLOSEPAREN_OP                                      {fprintf(yyout,"postfix_expression OPENPAREN_OP CLOSEPAREN_OP REDUCE to postfix_expression\n");}
	| postfix_expression OPENPAREN_OP argument_expression_list CLOSEPAREN_OP             {fprintf(yyout,"postfix_expression OPENPAREN_OP argument_expression_list CLOSEPAREN_OP REDUCE to postfix_expression\n");}
	| postfix_expression PERIOD_OP IDENTIFIER                                            {fprintf(yyout,"postfix_expression PERIOD_OP IDENTIFIER REDUCE to postfix_expression\n");}
	| postfix_expression PTR_OP IDENTIFIER                                               {fprintf(yyout,"postfix_expression PTR_OP IDENTIFIER REDUCE to postfix_expression\n");}
	| postfix_expression INC_OP                                                          {fprintf(yyout,"postfix_expression INC_OP REDUCE to postfix_expression\n");}
	| postfix_expression DEC_OP                                                          {fprintf(yyout,"postfix_expression DEC_OP REDUCE to postfix_expression\n");}
	| OPENPAREN_OP type_name CLOSEPAREN_OP OCURLY_OP initializer_list CCURLY_OP          {fprintf(yyout,"OPENPAREN_OP type_name CLOSEPAREN_OP OCURLY_OP initializer_list CCURLY_OP REDUCE to postfix_expression\n");}
	| OPENPAREN_OP type_name CLOSEPAREN_OP OCURLY_OP initializer_list COMMA_OP CCURLY_OP {fprintf(yyout,"OPENPAREN_OP type_name CLOSEPAREN_OP OCURLY_OP initializer_list COMMA_OP CCURLY_OP REDUCE to postfix_expression\n");}
	;

argument_expression_list
	: assignment_expression                                    {fprintf(yyout,"assignment_expression REDUCE to argument_expression_list\n");}
	| argument_expression_list COMMA_OP assignment_expression  {fprintf(yyout,"argument_expression_list COMMA_OP assignment_expression REDUCE to argument_expression_list\n");}
	;

unary_expression
	: postfix_expression                            {
                                                     $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                 fprintf(yyout,"<EXP> postfix_expression REDUCE to unary_expression\n");
													}
	| INC_OP unary_expression                       {fprintf(yyout,"INC_OP unary_expression REDUCE to unary_expression\n");}
	| DEC_OP unary_expression                       {fprintf(yyout,"DEC_OP unary_expression REDUCE to unary_expression\n");}
	| unary_operator cast_expression                {fprintf(yyout,"unary_operator cast_expression REDUCE to unary_expression\n");}
	| SIZEOF unary_expression                       {fprintf(yyout,"SIZEOF unary_expression REDUCE to unary_expression\n");}
	| SIZEOF OPENPAREN_OP type_name CLOSEPAREN_OP   {fprintf(yyout,"SIZEOF OPENPAREN_OP type_name CLOSEPAREN_OP REDUCE to unary_expression\n");}
	;

unary_operator
	: BIT_AND   {fprintf(yyout,"BIT_AND REDUCE to unary_operator\n");}
	| TIMES_OP  {fprintf(yyout,"TIMES_OP REDUCE to unary_operator\n");}
	| PLUS_OP   {fprintf(yyout,"PLUS_OP REDUCE to unary_operator\n");}
	| MINUS_OP  {fprintf(yyout,"MINUS_OP REDUCE to unary_operator\n");}
	| TILDE_OP  {fprintf(yyout,"TILDE_OP REDUCE to unary_operator\n");}
	| NOT_OP    {fprintf(yyout,"NOT_OP REDUCE to unary_operator\n");}
	;

cast_expression
	: unary_expression                                      {
                                                             $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                         fprintf(yyout,"<EXP> unary_expression REDUCE to cast_expression\n");
															}
	| OPENPAREN_OP type_name CLOSEPAREN_OP cast_expression  {fprintf(yyout,"OPENPAREN_OP type_name CLOSEPAREN_OP cast_expression REDUCE to cast_expression\n");}
	;

multiplicative_expression
	: cast_expression                                     {
                                                           $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                       fprintf(yyout,"<EXP> cast_expression REDUCE to multiplicative_expression\n");
														  }
	| multiplicative_expression TIMES_OP cast_expression  {fprintf(yyout,"multiplicative_expression TIMES_OP cast_expression REDUCE to multiplicative_expression\n");}
	| multiplicative_expression DIV_OP cast_expression    {fprintf(yyout,"multiplicative_expression DIV_OP cast_expression REDUCE to multiplicative_expression\n");}
	| multiplicative_expression MOD_OP cast_expression    {fprintf(yyout,"multiplicative_expression MOD_OP cast_expression REDUCE to multiplicative_expression\n");}
	;

additive_expression
	: multiplicative_expression                               {
                                                               $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                           fprintf(yyout,"<EXP> multiplicative_expression REDUCE to additive_expression\n");
															  }
	| additive_expression PLUS_OP multiplicative_expression   {fprintf(yyout,"additive_expression PLUS_OP multiplicative_expression REDUCE to additive_expression\n");}
	| additive_expression MINUS_OP multiplicative_expression  {fprintf(yyout,"additive_expression MINUS_OP multiplicative_expression REDUCE to additive_expression\n");}
	;

shift_expression
	: additive_expression                           {
                                                     $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                 fprintf(yyout,"<EXP> additive_expression REDUCE to shift_expression\n");
													}
	| shift_expression LEFT_OP additive_expression  {fprintf(yyout,"shift_expression LEFT_OP additive_expression REDUCE to shift_expression\n");}
	| shift_expression RIGHT_OP additive_expression {fprintf(yyout,"shift_expression RIGHT_OP additive_expression REDUCE to shift_expression\n");}
	;

relational_expression
	: shift_expression                                  {
                                                         $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                     fprintf(yyout,"<EXP> shift_expression REDUCE to relational_expression\n");
														}
	| relational_expression LESS_OP shift_expression    {fprintf(yyout,"relational_expression LESS_OP shift_expression REDUCE to relational_expression\n");}
	| relational_expression GREATER_OP shift_expression {fprintf(yyout,"relational_expression GREATER_OP shift_expression REDUCE to relational_expression\n");}
	| relational_expression LE_OP shift_expression      {fprintf(yyout,"relational_expression LE_OP shift_expression REDUCE to relational_expression\n");}
	| relational_expression GE_OP shift_expression      {fprintf(yyout,"relational_expression GE_OP shift_expression REDUCE to relational_expression\n");}
	;

equality_expression
	: relational_expression                             {
                                                         $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                     fprintf(yyout,"<EXP> relational_expression REDUCE to equality_expression\n");
														}
	| equality_expression EQ_OP relational_expression   {fprintf(yyout,"equality_expression EQ_OP relational_expression REDUCE to equality_expression\n");}
	| equality_expression NE_OP relational_expression   {fprintf(yyout,"equality_expression NE_OP relational_expression REDUCE to equality_expression\n");}
	;

and_expression
	: equality_expression                          {
                                                    $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                fprintf(yyout,"<EXP> equality_expression REDUCE to and_expression\n");
												   }
	| and_expression BIT_AND equality_expression   {fprintf(yyout,"and_expression BIT_AND equality_expression REDUCE to and_expression\n");}
	;

exclusive_or_expression
	: and_expression                                  {
                                                       $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                   fprintf(yyout,"<EXP> and_expression REDUCE to exclusive_or_expression\n");
													  }
	| exclusive_or_expression XOR_OP and_expression   {fprintf(yyout,"exclusive_or_expression XOR_OP and_expression REDUCE to exclusive_or_expression\n");}
	;

inclusive_or_expression
	: exclusive_or_expression                                  {
                                                                $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                            fprintf(yyout,"<EXP> exclusive_or_expression REDUCE to inclusive_or_expression\n");
															   }
	| inclusive_or_expression BIT_OR exclusive_or_expression   {fprintf(yyout,"inclusive_or_expression BIT_OR exclusive_or_expression REDUCE to inclusive_or_expression\n");}
	;

logical_and_expression
	: inclusive_or_expression                               {
                                                             $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                         fprintf(yyout,"<EXP> inclusive_or_expression REDUCE to logical_and_expression\n");
															}
	| logical_and_expression AND_OP inclusive_or_expression {fprintf(yyout,"logical_and_expression AND_OP inclusive_or_expression REDUCE to logical_and_expression\n");}
	;

logical_or_expression
	: logical_and_expression                             {
                                                          $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                      fprintf(yyout,"<EXP> logical_and_expression REDUCE to logical_or_expression\n");
														 }
	| logical_or_expression OR_OP logical_and_expression {fprintf(yyout,"logical_or_expression OR_OP logical_and_expression REDUCE to logical_or_expression\n");}
	;

conditional_expression
	: logical_or_expression                                                        {
                                                                                    $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                                                fprintf(yyout,"<EXP> logical_or_expression REDUCE to conditional_expression\n");
																				   }
	| logical_or_expression QUESTION_OP expression COLON_OP conditional_expression {fprintf(yyout,"logical_or_expression QUESTION_OP expression COLON_OP conditional_expression REDUCE to conditional_expression\n");}
	;

assignment_expression
	: conditional_expression                                     {
                                                                  $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                              fprintf(yyout,"<EXP> conditional_expression REDUCE to assignment_expression\n");
																 }
	| unary_expression assignment_operator assignment_expression {fprintf(yyout,"unary_expression assignment_operator assignment_expression REDUCE to assignment_expression\n");}
	;

assignment_operator
	: EQUAL_OP     {fprintf(yyout,"EQUAL_OP REDUCE to assignment_operator\n");}
	| MUL_ASSIGN   {fprintf(yyout,"MUL_ASSIGN REDUCE to assignment_operator\n");}
	| DIV_ASSIGN   {fprintf(yyout,"DIV_ASSIGN REDUCE to assignment_operator\n");}
	| MOD_ASSIGN   {fprintf(yyout,"MOD_ASSIGN REDUCE to assignment_operator\n");}
	| ADD_ASSIGN   {fprintf(yyout,"ADD_ASSIGN REDUCE to assignment_operator\n");}
	| SUB_ASSIGN   {fprintf(yyout,"SUB_ASSIGN REDUCE to assignment_operator\n");}
	| LEFT_ASSIGN  {fprintf(yyout,"LEFT_ASSIGN REDUCE to assignment_operator\n");}
	| RIGHT_ASSIGN {fprintf(yyout,"RIGHT_ASSIGN REDUCE to assignment_operator\n");}
	| AND_ASSIGN   {fprintf(yyout,"AND_ASSIGN REDUCE to assignment_operator\n");}
	| XOR_ASSIGN   {fprintf(yyout,"XOR_ASSIGN REDUCE to assignment_operator\n");}
	| OR_ASSIGN    {fprintf(yyout,"OR_ASSIGN REDUCE to assignment_operator\n");}
	;

expression
	: assignment_expression                     {
		                                         $<CompilerInfo>$ = $<CompilerInfo>1;
		                                         fprintf(yyout,"<EXP> assignment_expression REDUCE to expression\n");
											    }
	| expression COMMA_OP assignment_expression {fprintf(yyout," expression COMMA_OP assignment_expression REDUCE to expression\n");}
	;

constant_expression
	: conditional_expression   {fprintf(yyout,"conditional_expression REDUCE to constant_expression\n");}
	;

declaration
	: declaration_specifiers SEMI_OP                        {fprintf(yyout,"declaration_specifiers SEMI_OP REDUCE to declaration\n");}
	| declaration_specifiers init_declarator_list SEMI_OP   {
                                                             $<CompilerInfo>$.sign = $<CompilerInfo>1.sign;
	                                                         $<CompilerInfo>$.type = $<CompilerInfo>1.type;
	                                                         $<CompilerInfo>$.storage = $<CompilerInfo>1.storage;
	                                                         $<CompilerInfo>$.identifier = $<CompilerInfo>2.identifier;
															 fprintf(yyout,"'%d %d %d %s' => declaration_specifiers init_declarator_list SEMI_OP REDUCE to declaration\n",$<CompilerInfo>$.storage,$<CompilerInfo>$.sign,$<CompilerInfo>$.type,$<CompilerInfo>$.identifier);
															}
	;

declaration_specifiers
	: storage_class_specifier                        {fprintf(yyout,"storage_class_specifier REDUCE to declaration_specifiers\n");}
	| storage_class_specifier declaration_specifiers {
	                                                  $<CompilerInfo>$.sign = $<CompilerInfo>2.sign;
	                                                  $<CompilerInfo>$.type = $<CompilerInfo>2.type;
	                                                  $<CompilerInfo>$.storage = $<CompilerInfo>1.storage;
	                                                  fprintf(yyout,"%d %d %d => storage_class_specifier declaration_specifiers REDUCE to declaration_specifiers\n",$<CompilerInfo>$.storage,$<CompilerInfo>$.sign,$<CompilerInfo>$.type);
													 }
	| type_specifier                                 {
	                                                   $<CompilerInfo>$ = $<CompilerInfo>1;
													   fprintf(yyout,"%d %d type_specifier REDUCE to declaration_specifiers\n",$<CompilerInfo>$.sign,$<CompilerInfo>$.type);
													 }
	| type_specifier declaration_specifiers          {
	                                                   $<CompilerInfo>$.sign = $<CompilerInfo>1.sign;
	                                                   $<CompilerInfo>$.type = $<CompilerInfo>2.type;
													   fprintf(yyout,"%d %d => type_specifier declaration_specifiers REDUCE to declaration_specifiers\n",$<CompilerInfo>$.sign,$<CompilerInfo>$.type);
													 }
	| type_qualifier                                 {fprintf(yyout,"type_qualifier REDUCE to declaration_specifiers\n");}
	| type_qualifier declaration_specifiers          {fprintf(yyout,"type_qualifier declaration_specifiers SEMI_OP REDUCE to declaration_specifiers\n");}
	| function_specifier                             {fprintf(yyout,"function_specifier REDUCE to declaration_specifiers\n");}
	| function_specifier declaration_specifiers      {fprintf(yyout,"function_specifier declaration_specifiers REDUCE to declaration_specifiers\n");}
	;

init_declarator_list
	: init_declarator                               {
                                                     $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                 fprintf(yyout,"'%s' => init_declarator REDUCE to init_declarator_list\n",$<CompilerInfo>$.identifier);
													}
	| init_declarator_list COMMA_OP init_declarator {fprintf(yyout,"init_declarator_list COMMA_OP init_declarator REDUCE to init_declarator_list\n");}
	;

init_declarator
	: declarator                      {
                                       $<CompilerInfo>$ = $<CompilerInfo>1;
	                                   fprintf(yyout,"'%s' => declarator REDUCE to init_declarator\n",$<CompilerInfo>$.identifier);
									  }
	| declarator EQUAL_OP initializer {fprintf(yyout,"declarator EQUAL_OP initializer REDUCE to init_declarator\n");}
	;

storage_class_specifier
	: TYPEDEF  {$<CompilerInfo>$.storage = STORAGE_NONE;     fprintf(yyout,"TYPEDEF REDUCE to storage_class_specifier\n");}
	| EXTERN   {$<CompilerInfo>$.storage = STORAGE_EXTERN;   fprintf(yyout,"EXTERN REDUCE to storage_class_specifier\n");}
	| STATIC   {$<CompilerInfo>$.storage = STORAGE_STATIC;   fprintf(yyout,"STATIC REDUCE to storage_class_specifier\n");}
	| AUTO     {$<CompilerInfo>$.storage = STORAGE_AUTO;     fprintf(yyout,"AUTO REDUCE to storage_class_specifier\n");}
	| REGISTER {$<CompilerInfo>$.storage = STORAGE_REGISTER; fprintf(yyout,"REGISTER REDUCE to storage_class_specifier\n");}
	;

type_specifier
	: VOID                      {$<CompilerInfo>$.type = TYPE_VOID;      fprintf(yyout,"%d REDUCE to type_specifier\n",$<CompilerInfo>$.type); }
	| CHAR                      {$<CompilerInfo>$.type = TYPE_CHARACTER; fprintf(yyout,"%d REDUCE to type_specifier\n",$<CompilerInfo>$.type); }
	| SHORT                     {$<CompilerInfo>$.type = TYPE_SHORT;     fprintf(yyout,"%d REDUCE to type_specifier\n",$<CompilerInfo>$.type); }
	| INT                       {$<CompilerInfo>$.type = TYPE_INTEGER;   fprintf(yyout,"%d REDUCE to type_specifier\n",$<CompilerInfo>$.type); }
	| LONG                      {$<CompilerInfo>$.type = TYPE_LONG;      fprintf(yyout,"%d REDUCE to type_specifier\n",$<CompilerInfo>$.type); }
	| LONGLONG                  {$<CompilerInfo>$.type = TYPE_LONG64;    fprintf(yyout,"%d REDUCE to type_specifier\n",$<CompilerInfo>$.type); }
	| FLOAT                     {$<CompilerInfo>$.type = TYPE_FLOAT;     fprintf(yyout,"%d REDUCE to type_specifier\n",$<CompilerInfo>$.type); }
	| DOUBLE                    {$<CompilerInfo>$.type = TYPE_DOUBLE;    fprintf(yyout,"%d REDUCE to type_specifier\n",$<CompilerInfo>$.type); }
	| SIGNED                    {$<CompilerInfo>$.sign = TYPE_SIGNED;    fprintf(yyout,"%d REDUCE to type_specifier\n",$<CompilerInfo>$.sign); }
	| UNSIGNED                  {$<CompilerInfo>$.sign = TYPE_UNSIGNED;  fprintf(yyout,"%d REDUCE to type_specifier\n",$<CompilerInfo>$.sign); }
	| BOOL                      {$<CompilerInfo>$.type = TYPE_INTEGER;   fprintf(yyout,"%d REDUCE to type_specifier\n",$<CompilerInfo>$.type); }
	| COMPLEX                   {$<CompilerInfo>$.type = TYPE_COMPLEX;   fprintf(yyout,"%d REDUCE to type_specifier\n",$<CompilerInfo>$.type); }
	| IMAGINARY                 {$<CompilerInfo>$.type = TYPE_IMAGINARY; fprintf(yyout,"%d REDUCE to type_specifier\n",$<CompilerInfo>$.type); }
	| struct_or_union_specifier {fprintf(yyout,"struct_or_union_specifier REDUCE to type_specifier\n");}
	| enum_specifier            {fprintf(yyout,"enum_specifier REDUCE to type_specifier\n");}
	| TYPE_NAME                 {fprintf(yyout,"type_specifier TYPE_NAME REDUCE to type_specifier\n");}
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER OCURLY_OP struct_declaration_list CCURLY_OP  {fprintf(yyout,"struct_or_union IDENTIFIER OCURLY_OP struct_declaration_list CCURLY_OP REDUCE to struct_or_union_specifier\n");}
	| struct_or_union OCURLY_OP struct_declaration_list CCURLY_OP             {fprintf(yyout,"struct_or_union OCURLY_OP struct_declaration_list CCURLY_OP REDUCE to struct_or_union_specifier\n");}
	| struct_or_union IDENTIFIER                                              {fprintf(yyout,"struct_or_union IDENTIFIER REDUCE to struct_or_union_specifier\n");}
	;

struct_or_union
	: STRUCT   {fprintf(yyout,"STRUCT REDUCE to struct_or_union\n");}
	| UNION    {fprintf(yyout,"UNION REDUCE to struct_or_union\n");}
	;

struct_declaration_list
	: struct_declaration                         {fprintf(yyout,"struct_declaration REDUCE to struct_declaration_list\n");}
	| struct_declaration_list struct_declaration {fprintf(yyout,"struct_declaration_list struct_declaration REDUCE to struct_declaration_list\n");}
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list SEMI_OP  {fprintf(yyout,"specifier_qualifier_list struct_declarator_list SEMI_OP REDUCE to struct_declaration\n");}
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list {fprintf(yyout,"type_specifier specifier_qualifier_list REDUCE to specifier_qualifier_list\n");}
	| type_specifier                          {fprintf(yyout,"type_specifier REDUCE to specifier_qualifier_list\n");}
	| type_qualifier specifier_qualifier_list {fprintf(yyout,"type_qualifier specifier_qualifier_list REDUCE to specifier_qualifier_list\n");}
	| type_qualifier                          {fprintf(yyout,"type_qualifier REDUCE to specifier_qualifier_list\n");}
	;

struct_declarator_list
	: struct_declarator                                 {fprintf(yyout,"struct_declarator REDUCE to struct_declarator_list\n");}
	| struct_declarator_list COMMA_OP struct_declarator {fprintf(yyout,"struct_declarator_list COMMA_OP struct_declarator REDUCE to struct_declarator_list\n");}
	;

struct_declarator
	: declarator                                 {fprintf(yyout,"declarator REDUCE to struct_declarator\n");}
	| COLON_OP constant_expression               {fprintf(yyout,"COLON_OP constant_expression REDUCE to struct_declarator\n");}
	| declarator COLON_OP constant_expression    {fprintf(yyout,"declarator COLON_OP constant_expression REDUCE to struct_declarator\n");}
	;

enum_specifier
	: ENUM OCURLY_OP enumerator_list CCURLY_OP                     {fprintf(yyout,"ENUM OCURLY_OP enumerator_list CCURLY_OP REDUCE to enum_specifier\n");}
	| ENUM IDENTIFIER OCURLY_OP enumerator_list CCURLY_OP          {fprintf(yyout,"ENUM IDENTIFIER OCURLY_OP enumerator_list CCURLY_OP REDUCE to enum_specifier\n");}
	| ENUM OCURLY_OP enumerator_list COMMA_OP CCURLY_OP            {fprintf(yyout,"ENUM OCURLY_OP enumerator_list COMMA_OP CCURLY_OP REDUCE to enum_specifier\n");}
	| ENUM IDENTIFIER OCURLY_OP enumerator_list COMMA_OP CCURLY_OP {fprintf(yyout,"ENUM IDENTIFIER OCURLY_OP enumerator_list COMMA_OP CCURLY_OP REDUCE to enum_specifier\n");}
	| ENUM IDENTIFIER                                              {fprintf(yyout,"ENUM IDENTIFIER REDUCE to enum_specifier\n");}
	;

enumerator_list
	: enumerator                           {fprintf(yyout,"enumerator REDUCE to enumerator_list\n");}
	| enumerator_list COMMA_OP enumerator  {fprintf(yyout,"enumerator_list COMMA_OP enumerator REDUCE to enumerator_list\n");}
	;

enumerator
	: IDENTIFIER                              {fprintf(yyout,"IDENTIFIER REDUCE to enumerator\n");}
	| IDENTIFIER EQUAL_OP constant_expression {fprintf(yyout,"IDENTIFIER EQUAL_OP constant_expression REDUCE to enumerator\n");}
	;

type_qualifier
	: CONST    {fprintf(yyout,"CONST REDUCE to type_qualifier\n");}
	| RESTRICT {fprintf(yyout,"RESTRICT REDUCE to type_qualifier\n");}
	| VOLATILE {fprintf(yyout,"VOLATILE REDUCE to type_qualifier\n");}
	;

function_specifier
	: INLINE  {fprintf(yyout,"INLINE REDUCE to function_specifier\n");}
	;

declarator
	: pointer direct_declarator  {fprintf(yyout,"pointer direct_declarator REDUCE to declarator\n");}
	| direct_declarator          {
                                  $<CompilerInfo>$ = $<CompilerInfo>1;
	                              fprintf(yyout,"'%s' => direct_declarator REDUCE to declarator\n",$<CompilerInfo>$.identifier);
								 }
	;


direct_declarator
	: IDENTIFIER                                                                                      {
	                                                                                                   $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                                                                   fprintf(yyout,"'%s' => IDENTIFIER REDUCE to direct_declarator\n",$<CompilerInfo>$.identifier);
																									  }
	| OPENPAREN_OP declarator CLOSEPAREN_OP                                                           {fprintf(yyout,"OPENPAREN_OP declarator CLOSEPAREN_OP REDUCE to direct_declarator\n");}
	| direct_declarator OPENBRACE_OP type_qualifier_list assignment_expression CLOSEBRACE_OP          {fprintf(yyout,"direct_declarator OPENBRACE_OP type_qualifier_list assignment_expression CLOSEBRACE_OP REDUCE to direct_declarator\n");}
	| direct_declarator OPENBRACE_OP type_qualifier_list CLOSEBRACE_OP                                {fprintf(yyout,"direct_declarator OPENBRACE_OP type_qualifier_list CLOSEBRACE_OP REDUCE to direct_declarator\n");}
	| direct_declarator OPENBRACE_OP assignment_expression CLOSEBRACE_OP                              {
	                                                                                                   $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                                                                   fprintf(yyout,"direct_declarator OPENBRACE_OP assignment_expression CLOSEBRACE_OP REDUCE to direct_declarator\n");
																									  }
	| direct_declarator OPENBRACE_OP STATIC type_qualifier_list assignment_expression CLOSEBRACE_OP   {fprintf(yyout,"direct_declarator OPENBRACE_OP STATIC type_qualifier_list assignment_expression CLOSEBRACE_OP REDUCE to direct_declarator\n");}
	| direct_declarator OPENBRACE_OP type_qualifier_list STATIC assignment_expression CLOSEBRACE_OP   {fprintf(yyout,"direct_declarator OPENBRACE_OP type_qualifier_list STATIC assignment_expression CLOSEBRACE_OP REDUCE to direct_declarator\n");}
	| direct_declarator OPENBRACE_OP type_qualifier_list TIMES_OP CLOSEBRACE_OP                       {fprintf(yyout,"direct_declarator OPENBRACE_OP type_qualifier_list TIMES_OP CLOSEBRACE_OP REDUCE to direct_declarator\n");}
	| direct_declarator OPENBRACE_OP TIMES_OP CLOSEBRACE_OP                                           {fprintf(yyout,"direct_declarator OPENBRACE_OP TIMES_OP CLOSEBRACE_OP REDUCE to direct_declarator\n");}
	| direct_declarator OPENBRACE_OP CLOSEBRACE_OP                                                    {fprintf(yyout,"direct_declarator OPENBRACE_OP CLOSEBRACE_OP REDUCE to direct_declarator\n");}
	| direct_declarator OPENPAREN_OP parameter_type_list CLOSEPAREN_OP                                {fprintf(yyout,"direct_declarator OPENPAREN_OP parameter_type_list CLOSEPAREN_OP REDUCE to direct_declarator\n");}
	| direct_declarator OPENPAREN_OP identifier_list CLOSEPAREN_OP                                    {fprintf(yyout,"direct_declarator OPENPAREN_OP identifier_list CLOSEPAREN_OP REDUCE to direct_declarator\n");}
	| direct_declarator OPENPAREN_OP CLOSEPAREN_OP                                                    {
		                                                                                               $<CompilerInfo>$ = $<CompilerInfo>1;
		                                                                                               fprintf(yyout,"'%s' => direct_declarator OPENPAREN_OP CLOSEPAREN_OP REDUCE to direct_declarator\n",$<CompilerInfo>$.identifier);
																									  }
	;

pointer
	: TIMES_OP                             {fprintf(yyout,"TIMES_OP REDUCE to pointer\n");}
	| TIMES_OP type_qualifier_list         {fprintf(yyout,"TIMES_OP type_qualifier_list REDUCE to pointer\n");}
	| TIMES_OP pointer                     {fprintf(yyout,"TIMES_OP pointer REDUCE to pointer\n");}
	| TIMES_OP type_qualifier_list pointer {fprintf(yyout,"TIMES_OP type_qualifier_list pointer REDUCE to pointer\n");}
	;

type_qualifier_list
	: type_qualifier                     {fprintf(yyout,"type_qualifier REDUCE to type_qualifier_list\n");}
	| type_qualifier_list type_qualifier {fprintf(yyout,"type_qualifier_list type_qualifier REDUCE to type_qualifier_list\n");}
	;


parameter_type_list
	: parameter_list                   {fprintf(yyout,"parameter_list REDUCE to parameter_type_list\n");}
	| parameter_list COMMA_OP ELLIPSIS {fprintf(yyout,"parameter_list COMMA_OP ELLIPSIS REDUCE to parameter_type_list\n");}
	;

parameter_list
	: parameter_declaration                         {fprintf(yyout,"parameter_declaration REDUCE to parameter_list\n");}
	| parameter_list COMMA_OP parameter_declaration {fprintf(yyout,"parameter_list COMMA_OP parameter_declaration REDUCE to parameter_list\n");}
	;

parameter_declaration
	: declaration_specifiers declarator          {fprintf(yyout,"declaration_specifiers declarator REDUCE to parameter_declaration\n");}
	| declaration_specifiers abstract_declarator {fprintf(yyout,"declaration_specifiers abstract_declarator REDUCE to parameter_declaration\n");}
	| declaration_specifiers                     {fprintf(yyout,"declaration_specifiers REDUCE to parameter_declaration\n");}
	;

identifier_list
	: IDENTIFIER                          {fprintf(yyout,"IDENTIFIER REDUCE to identifier_list\n");}
	| identifier_list COMMA_OP IDENTIFIER {fprintf(yyout,"identifier_list COMMA_OP IDENTIFIER REDUCE to identifier_list\n");}
	;

type_name
	: specifier_qualifier_list                     {fprintf(yyout,"specifier_qualifier_list REDUCE to type_name\n");}
	| specifier_qualifier_list abstract_declarator {fprintf(yyout,"specifier_qualifier_list abstract_declarator REDUCE to type_name\n");}
	;

abstract_declarator
	: pointer                            {fprintf(yyout,"pointer REDUCE to abstract_declarator\n");}
	| direct_abstract_declarator         {fprintf(yyout,"direct_abstract_declarator REDUCE to abstract_declarator\n");}
	| pointer direct_abstract_declarator {fprintf(yyout,"pointer direct_abstract_declarator REDUCE to abstract_declarator\n");}
	;

direct_abstract_declarator
	: OPENPAREN_OP abstract_declarator CLOSEPAREN_OP                               {fprintf(yyout,"OPENPAREN_OP abstract_declarator CLOSEPAREN_OP REDUCE to direct_abstract_declarator\n");}
	| OPENBRACE_OP CLOSEBRACE_OP                                                   {fprintf(yyout,"OPENBRACE_OP CLOSEBRACE_OP REDUCE to direct_abstract_declarator\n");}
	| OPENBRACE_OP assignment_expression CLOSEBRACE_OP                             {fprintf(yyout,"OPENBRACE_OP assignment_expression CLOSEBRACE_OP REDUCE to direct_abstract_declarator\n");}
	| direct_abstract_declarator OPENBRACE_OP CLOSEBRACE_OP                        {fprintf(yyout,"direct_abstract_declarator OPENBRACE_OP CLOSEBRACE_OP REDUCE to direct_abstract_declarator\n");}
	| direct_abstract_declarator OPENBRACE_OP assignment_expression CLOSEBRACE_OP  {fprintf(yyout,"direct_abstract_declarator OPENBRACE_OP assignment_expression CLOSEBRACE_OP REDUCE to direct_abstract_declarator\n");}
	| OPENBRACE_OP TIMES_OP CLOSEBRACE_OP                                          {fprintf(yyout,"OPENBRACE_OP TIMES_OP CLOSEBRACE_OP REDUCE to direct_abstract_declarator\n");}
	| direct_abstract_declarator OPENBRACE_OP TIMES_OP CLOSEBRACE_OP               {fprintf(yyout,"direct_abstract_declarator OPENBRACE_OP TIMES_OP CLOSEBRACE_OP REDUCE to direct_abstract_declarator\n");}
	| OPENPAREN_OP CLOSEPAREN_OP                                                   {fprintf(yyout,"OPENPAREN_OP CLOSEPAREN_OP REDUCE to direct_abstract_declarator\n");}
	| OPENPAREN_OP parameter_type_list CLOSEPAREN_OP                               {fprintf(yyout,"OPENPAREN_OP parameter_type_list CLOSEPAREN_OP REDUCE to direct_abstract_declarator\n");}
	| direct_abstract_declarator OPENPAREN_OP CLOSEPAREN_OP                        {fprintf(yyout,"direct_abstract_declarator OPENPAREN_OP CLOSEPAREN_OP REDUCE to direct_abstract_declarator\n");}
	| direct_abstract_declarator OPENPAREN_OP parameter_type_list CLOSEPAREN_OP    {fprintf(yyout,"direct_abstract_declarator OPENPAREN_OP parameter_type_list CLOSEPAREN_OP REDUCE to direct_abstract_declarator\n");}
	;

initializer
	: assignment_expression                         {fprintf(yyout,"assignment_expression REDUCE to initializer\n");}
	| OCURLY_OP initializer_list CCURLY_OP          {fprintf(yyout,"OCURLY_OP initializer_list CCURLY_OP REDUCE to initializer\n");}
	| OCURLY_OP initializer_list COMMA_OP CCURLY_OP {fprintf(yyout,"OCURLY_OP initializer_list COMMA_OP CCURLY_OP REDUCE to initializer\n");}
	;

initializer_list
	: initializer                                       {fprintf(yyout,"initializer REDUCE to initializer_list\n");}
	| designation initializer                           {fprintf(yyout,"designation initializer REDUCE to initializer_list\n");}
	| initializer_list COMMA_OP initializer             {fprintf(yyout,"initializer_list COMMA_OP initializer REDUCE to initializer_list\n");}
	| initializer_list COMMA_OP designation initializer {fprintf(yyout,"initializer_list COMMA_OP designation initializer REDUCE to initializer_list\n");}
	;

designation
	: designator_list EQUAL_OP {fprintf(yyout,"designator_list EQUAL_OP REDUCE to designation\n");}
	;

designator_list
	: designator                 {fprintf(yyout,"designator REDUCE to designator_list\n");}
	| designator_list designator {fprintf(yyout,"designator_list designator EQUAL_OP REDUCE to designator_list\n");}
	;

designator
	: OPENBRACE_OP constant_expression CLOSEBRACE_OP    {fprintf(yyout,"labeled_statement REDUCE to statement\n");}
	| PERIOD_OP IDENTIFIER                              {fprintf(yyout,"labeled_statement REDUCE to statement\n");}
	;

statement
	: labeled_statement     {fprintf(yyout,"labeled_statement REDUCE to statement\n");}
	| compound_statement    {fprintf(yyout,"compound_statement REDUCE to statement\n");}
	| expression_statement  {fprintf(yyout,"expression_statement REDUCE to statement\n");}
	| selection_statement   {fprintf(yyout,"selection_statement REDUCE to statement\n");}
	| iteration_statement   {fprintf(yyout,"iteration_statement REDUCE to statement\n");}
	| jump_statement        {
		                     $<CompilerInfo>$ = $<CompilerInfo>1;
		                     fprintf(yyout,"<EXP> jump_statement REDUCE to statement\n");
							}
	;

labeled_statement
	: IDENTIFIER COLON_OP statement               {fprintf(yyout,"IDENTIFIER COLON_OP statement REDUCE to labeled_statement\n");}
	| CASE constant_expression COLON_OP statement {fprintf(yyout,"CASE constant_expression COLON_OP statement REDUCE to labeled_statement\n");}
	| DEFAULT COLON_OP statement                  {fprintf(yyout,"DEFAULT COLON_OP statement REDUCE to labeled_statement\n");}
	;

compound_statement
	: OCURLY_OP CCURLY_OP                 {fprintf(yyout,"OCURLY_OP CCURLY_OP REDUCE to compound_statement\n");}
	| OCURLY_OP block_item_list CCURLY_OP {
		                                   $<CompilerInfo>$ = $<CompilerInfo>2;
		                                   fprintf(yyout,"<EXP> OCURLY_OP block_item_list CCURLY_OP REDUCE to compound_statement\n");
										  }
	;

block_item_list
	: block_item                 {
		                          $<CompilerInfo>$ = $<CompilerInfo>1;
		                          fprintf(yyout,"<EXP> block_item REDUCE to block_item_list\n");
								 }
	| block_item_list block_item {fprintf(yyout,"block_item_list block_item REDUCE to block_item_list\n");}
	;

block_item
	: declaration  {fprintf(yyout,"declaration REDUCE to block_item\n");}
	| statement    {
		            $<CompilerInfo>$ = $<CompilerInfo>1;
		            fprintf(yyout,"<EXP> statement REDUCE to block_item\n");
				   }
	;

expression_statement
	: SEMI_OP            {fprintf(yyout,"SEMI_OP REDUCE to expression_statement\n");}
	| expression SEMI_OP {fprintf(yyout,"expression SEMI_OP REDUCE to expression_statement\n");}
	;

selection_statement
	: IF OPENPAREN_OP expression CLOSEPAREN_OP statement                {fprintf(yyout,"IF OPENPAREN_OP expression CLOSEPAREN_OP statement REDUCE to selection_statement\n");}
	| IF OPENPAREN_OP expression CLOSEPAREN_OP statement ELSE statement {fprintf(yyout,"IF OPENPAREN_OP expression CLOSEPAREN_OP statement ELSE statement REDUCE to selection_statement\n");}
	| SWITCH OPENPAREN_OP expression CLOSEPAREN_OP statement            {fprintf(yyout,"SWITCH OPENPAREN_OP expression CLOSEPAREN_OP statement REDUCE to selection_statement\n");}
	;

iteration_statement
	: WHILE OPENPAREN_OP expression CLOSEPAREN_OP statement                                         {fprintf(yyout,"WHILE OPENPAREN_OP expression CLOSEPAREN_OP statement REDUCE to iteration_statement\n");}
	| DO statement WHILE OPENPAREN_OP expression CLOSEPAREN_OP SEMI_OP                              {fprintf(yyout,"DO statement WHILE OPENPAREN_OP expression CLOSEPAREN_OP SEMI_OP REDUCE to iteration_statement\n");}
	| FOR OPENPAREN_OP expression_statement expression_statement CLOSEPAREN_OP statement            {fprintf(yyout,"FOR OPENPAREN_OP expression_statement expression_statement CLOSEPAREN_OP statement REDUCE to iteration_statement\n");}
	| FOR OPENPAREN_OP expression_statement expression_statement expression CLOSEPAREN_OP statement {fprintf(yyout,"FOR OPENPAREN_OP expression_statement expression_statement expression CLOSEPAREN_OP statement REDUCE to iteration_statement\n");}
	| FOR OPENPAREN_OP declaration expression_statement CLOSEPAREN_OP statement                     {fprintf(yyout,"FOR OPENPAREN_OP declaration expression_statement CLOSEPAREN_OP statement REDUCE to iteration_statement\n");}
	| FOR OPENPAREN_OP declaration expression_statement expression CLOSEPAREN_OP statement          {fprintf(yyout,"FOR OPENPAREN_OP declaration expression_statement expression CLOSEPAREN_OP statement REDUCE to iteration_statement\n");}
	;

jump_statement
	: GOTO IDENTIFIER SEMI_OP   {fprintf(yyout,"GOTO IDENTIFIER SEMI_OP REDUCE to jump_statement\n");}
	| CONTINUE SEMI_OP          {fprintf(yyout,"CONTINUE SEMI_OP REDUCE to jump_statement\n");}
	| BREAK SEMI_OP             {fprintf(yyout,"BREAK SEMI_OP REDUCE to jump_statement\n");}
	| RETURN SEMI_OP            {fprintf(yyout,"RETURN SEMI_OP REDUCE to jump_statement\n");}
	| RETURN expression SEMI_OP {
		                         $<CompilerInfo>$ = $<CompilerInfo>2;
		                         fprintf(yyout,"<EXP> RETURN expression SEMI_OP REDUCE to jump_statement\n");
								}
	;

translation_unit
	: external_declaration                  {
                                             $<CompilerInfo>$ = $<CompilerInfo>1;
											 addToSymbolTable($<CompilerInfo>1.identifier, $<CompilerInfo>1.type, $<CompilerInfo>1.sign, $<CompilerInfo>1.storage, $<CompilerInfo>1.declarationType, $<CompilerInfo>1.constant);
	                                         fprintf(yyout,"<EXP> external_declaration REDUCE to translation_unit\n");
											}
	| translation_unit external_declaration {
											 addToSymbolTable($<CompilerInfo>2.identifier, $<CompilerInfo>2.type, $<CompilerInfo>2.sign, $<CompilerInfo>2.storage, $<CompilerInfo>2.declarationType, $<CompilerInfo>2.constant);
		                                     fprintf(yyout,"<EXP> translation_unit external_declaration REDUCE to translation_unit\n");
											}
	;

external_declaration
	: function_definition {
                           $<CompilerInfo>$ = $<CompilerInfo>1;
						   $<CompilerInfo>$.declarationType = DECLARATION_FUNCTION;
						   fprintf(yyout,"'%d %d %d %s' => function_definition REDUCE to external_declaration\n",$<CompilerInfo>$.storage,$<CompilerInfo>$.sign,$<CompilerInfo>$.type,$<CompilerInfo>$.identifier);
						  }
	| declaration         {
                           $<CompilerInfo>$ = $<CompilerInfo>1;
						   $<CompilerInfo>$.declarationType = DECLARATION_VARIABLE;
                           $<CompilerInfo>$.sign = $<CompilerInfo>1.sign;
                           $<CompilerInfo>$.type = $<CompilerInfo>1.type;
                           $<CompilerInfo>$.storage = $<CompilerInfo>1.storage;
                           $<CompilerInfo>$.identifier = $<CompilerInfo>1.identifier;															 
	                       fprintf(yyout,"'%d %d %d %s' => declaration REDUCE to external_declaration\n",$<CompilerInfo>$.storage,$<CompilerInfo>$.sign,$<CompilerInfo>$.type,$<CompilerInfo>$.identifier);
						  }
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement {fprintf(yyout,"declaration_specifiers declarator declaration_list compound_statement REDUCE to function_definition\n");}
	| declaration_specifiers declarator compound_statement                  { 
		                                                                     
		                                                                     $<CompilerInfo>$.sign = $<CompilerInfo>1.sign;
                                                                             $<CompilerInfo>$.type = $<CompilerInfo>1.type;
																			 $<CompilerInfo>$.storage = $<CompilerInfo>1.storage;
																			 $<CompilerInfo>$.identifier = $<CompilerInfo>2.identifier;	
		                                                                     fprintf(yyout,"<EXP> declaration_specifiers declarator compound_statement REDUCE to function_definition\n");
																			}
	;

declaration_list
	: declaration                   {fprintf(yyout,"declaration REDUCE to declaration_list\n");}
	| declaration_list declaration  {fprintf(yyout,"declaration_list declaration REDUCE to declaration_list\n");}
	;

%%

void yyerror(const char* s) {
	fprintf(stderr, "Parse error on line %d column %d : %s\n", yylineno, column, s);
	num_errors++;
}