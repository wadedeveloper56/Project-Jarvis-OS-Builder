%{
#include "global.h"
%}

%union { 	   
    struct _CompilerInfo CompilerInfo;
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
											 $<CompilerInfo>$.data.identifier = (char *) malloc(strlen($<CompilerInfo>1.data.identifier)+1);
                                             strcpy($<CompilerInfo>$.data.identifier, $<CompilerInfo>1.data.identifier);
                                             $<CompilerInfo>$.data.type = TYPE_NULL;
                                             $<CompilerInfo>$.data.constant = FALSE;
	                                         fprintf(fileLexLog,"<EXP> IDENTIFIER REDUCE to primary_expression\n");
											}
	| CONSTANT                              {
											 $<CompilerInfo>$.data.identifier = (char *) malloc(strlen($<CompilerInfo>1.data.identifier)+1);
                                             strcpy($<CompilerInfo>$.data.identifier, $<CompilerInfo>1.data.identifier);
                                             $<CompilerInfo>$.data.type = TYPE_NULL;
                                             $<CompilerInfo>$.data.constant = TRUE;
	                                         fprintf(fileLexLog,"<EXP> '%s' CONSTANT REDUCE to primary_expression\n",$<CompilerInfo>$.data.identifier);
											}
	| STRING_LITERAL                        {
											 $<CompilerInfo>$.data.identifier = (char *) malloc(strlen($<CompilerInfo>1.data.identifier)+1);
                                             strcpy($<CompilerInfo>$.data.identifier, $<CompilerInfo>1.data.identifier);
                                             $<CompilerInfo>$.data.type = TYPE_NULL;
                                             $<CompilerInfo>$.data.constant = TRUE;
	                                         fprintf(fileLexLog,"<EXP> '%s' STRING_LITERAL REDUCE to primary_expression\n",$<CompilerInfo>$.data.identifier);
											}
	| OPENPAREN_OP expression CLOSEPAREN_OP {
                                             $<CompilerInfo>$ = $<CompilerInfo>2;
	                                         fprintf(fileLexLog,"<EXP> OPENPAREN_OP expression CLOSEPAREN_OP REDUCE to primary_expression\n");
											}
	;

postfix_expression
	: primary_expression                                                                 {
                                                                                          $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                                                      fprintf(fileLexLog,"<EXP> primary_expression REDUCE to postfix_expression\n");
																						 }
	| postfix_expression OPENBRACE_OP expression CLOSEBRACE_OP                           {fprintf(fileLexLog,"postfix_expression OPENBRACE_OP expression CLOSEBRACE_OP REDUCE to postfix_expression\n");}
	| postfix_expression OPENPAREN_OP CLOSEPAREN_OP                                      {fprintf(fileLexLog,"postfix_expression OPENPAREN_OP CLOSEPAREN_OP REDUCE to postfix_expression\n");}
	| postfix_expression OPENPAREN_OP argument_expression_list CLOSEPAREN_OP             {fprintf(fileLexLog,"postfix_expression OPENPAREN_OP argument_expression_list CLOSEPAREN_OP REDUCE to postfix_expression\n");}
	| postfix_expression PERIOD_OP IDENTIFIER                                            {fprintf(fileLexLog,"postfix_expression PERIOD_OP IDENTIFIER REDUCE to postfix_expression\n");}
	| postfix_expression PTR_OP IDENTIFIER                                               {fprintf(fileLexLog,"postfix_expression PTR_OP IDENTIFIER REDUCE to postfix_expression\n");}
	| postfix_expression INC_OP                                                          {fprintf(fileLexLog,"postfix_expression INC_OP REDUCE to postfix_expression\n");}
	| postfix_expression DEC_OP                                                          {fprintf(fileLexLog,"postfix_expression DEC_OP REDUCE to postfix_expression\n");}
	| OPENPAREN_OP type_name CLOSEPAREN_OP OCURLY_OP initializer_list CCURLY_OP          {fprintf(fileLexLog,"OPENPAREN_OP type_name CLOSEPAREN_OP OCURLY_OP initializer_list CCURLY_OP REDUCE to postfix_expression\n");}
	| OPENPAREN_OP type_name CLOSEPAREN_OP OCURLY_OP initializer_list COMMA_OP CCURLY_OP {fprintf(fileLexLog,"OPENPAREN_OP type_name CLOSEPAREN_OP OCURLY_OP initializer_list COMMA_OP CCURLY_OP REDUCE to postfix_expression\n");}
	;

argument_expression_list
	: assignment_expression                                    {fprintf(fileLexLog,"assignment_expression REDUCE to argument_expression_list\n");}
	| argument_expression_list COMMA_OP assignment_expression  {fprintf(fileLexLog,"argument_expression_list COMMA_OP assignment_expression REDUCE to argument_expression_list\n");}
	;

unary_expression
	: postfix_expression                            {
                                                     $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                 fprintf(fileLexLog,"<EXP> postfix_expression REDUCE to unary_expression\n");
													}
	| INC_OP unary_expression                       {fprintf(fileLexLog,"INC_OP unary_expression REDUCE to unary_expression\n");}
	| DEC_OP unary_expression                       {fprintf(fileLexLog,"DEC_OP unary_expression REDUCE to unary_expression\n");}
	| unary_operator cast_expression                {fprintf(fileLexLog,"unary_operator cast_expression REDUCE to unary_expression\n");}
	| SIZEOF unary_expression                       {fprintf(fileLexLog,"SIZEOF unary_expression REDUCE to unary_expression\n");}
	| SIZEOF OPENPAREN_OP type_name CLOSEPAREN_OP   {fprintf(fileLexLog,"SIZEOF OPENPAREN_OP type_name CLOSEPAREN_OP REDUCE to unary_expression\n");}
	;

unary_operator
	: BIT_AND   {fprintf(fileLexLog,"BIT_AND REDUCE to unary_operator\n");}
	| TIMES_OP  {fprintf(fileLexLog,"TIMES_OP REDUCE to unary_operator\n");}
	| PLUS_OP   {fprintf(fileLexLog,"PLUS_OP REDUCE to unary_operator\n");}
	| MINUS_OP  {fprintf(fileLexLog,"MINUS_OP REDUCE to unary_operator\n");}
	| TILDE_OP  {fprintf(fileLexLog,"TILDE_OP REDUCE to unary_operator\n");}
	| NOT_OP    {fprintf(fileLexLog,"NOT_OP REDUCE to unary_operator\n");}
	;

cast_expression
	: unary_expression                                      {
                                                             $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                         fprintf(fileLexLog,"<EXP> unary_expression REDUCE to cast_expression\n");
															}
	| OPENPAREN_OP type_name CLOSEPAREN_OP cast_expression  {fprintf(fileLexLog,"OPENPAREN_OP type_name CLOSEPAREN_OP cast_expression REDUCE to cast_expression\n");}
	;

multiplicative_expression
	: cast_expression                                     {
                                                           $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                       fprintf(fileLexLog,"<EXP> cast_expression REDUCE to multiplicative_expression\n");
														  }
	| multiplicative_expression TIMES_OP cast_expression  {fprintf(fileLexLog,"multiplicative_expression TIMES_OP cast_expression REDUCE to multiplicative_expression\n");}
	| multiplicative_expression DIV_OP cast_expression    {fprintf(fileLexLog,"multiplicative_expression DIV_OP cast_expression REDUCE to multiplicative_expression\n");}
	| multiplicative_expression MOD_OP cast_expression    {fprintf(fileLexLog,"multiplicative_expression MOD_OP cast_expression REDUCE to multiplicative_expression\n");}
	;

additive_expression
	: multiplicative_expression                               {
                                                               $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                           fprintf(fileLexLog,"<EXP> multiplicative_expression REDUCE to additive_expression\n");
															  }
	| additive_expression PLUS_OP multiplicative_expression   {fprintf(fileLexLog,"additive_expression PLUS_OP multiplicative_expression REDUCE to additive_expression\n");}
	| additive_expression MINUS_OP multiplicative_expression  {fprintf(fileLexLog,"additive_expression MINUS_OP multiplicative_expression REDUCE to additive_expression\n");}
	;

shift_expression
	: additive_expression                           {
                                                     $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                 fprintf(fileLexLog,"<EXP> additive_expression REDUCE to shift_expression\n");
													}
	| shift_expression LEFT_OP additive_expression  {fprintf(fileLexLog,"shift_expression LEFT_OP additive_expression REDUCE to shift_expression\n");}
	| shift_expression RIGHT_OP additive_expression {fprintf(fileLexLog,"shift_expression RIGHT_OP additive_expression REDUCE to shift_expression\n");}
	;

relational_expression
	: shift_expression                                  {
                                                         $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                     fprintf(fileLexLog,"<EXP> shift_expression REDUCE to relational_expression\n");
														}
	| relational_expression LESS_OP shift_expression    {fprintf(fileLexLog,"relational_expression LESS_OP shift_expression REDUCE to relational_expression\n");}
	| relational_expression GREATER_OP shift_expression {fprintf(fileLexLog,"relational_expression GREATER_OP shift_expression REDUCE to relational_expression\n");}
	| relational_expression LE_OP shift_expression      {fprintf(fileLexLog,"relational_expression LE_OP shift_expression REDUCE to relational_expression\n");}
	| relational_expression GE_OP shift_expression      {fprintf(fileLexLog,"relational_expression GE_OP shift_expression REDUCE to relational_expression\n");}
	;

equality_expression
	: relational_expression                             {
                                                         $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                     fprintf(fileLexLog,"<EXP> relational_expression REDUCE to equality_expression\n");
														}
	| equality_expression EQ_OP relational_expression   {fprintf(fileLexLog,"equality_expression EQ_OP relational_expression REDUCE to equality_expression\n");}
	| equality_expression NE_OP relational_expression   {fprintf(fileLexLog,"equality_expression NE_OP relational_expression REDUCE to equality_expression\n");}
	;

and_expression
	: equality_expression                          {
                                                    $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                fprintf(fileLexLog,"<EXP> equality_expression REDUCE to and_expression\n");
												   }
	| and_expression BIT_AND equality_expression   {fprintf(fileLexLog,"and_expression BIT_AND equality_expression REDUCE to and_expression\n");}
	;

exclusive_or_expression
	: and_expression                                  {
                                                       $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                   fprintf(fileLexLog,"<EXP> and_expression REDUCE to exclusive_or_expression\n");
													  }
	| exclusive_or_expression XOR_OP and_expression   {fprintf(fileLexLog,"exclusive_or_expression XOR_OP and_expression REDUCE to exclusive_or_expression\n");}
	;

inclusive_or_expression
	: exclusive_or_expression                                  {
                                                                $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                            fprintf(fileLexLog,"<EXP> exclusive_or_expression REDUCE to inclusive_or_expression\n");
															   }
	| inclusive_or_expression BIT_OR exclusive_or_expression   {fprintf(fileLexLog,"inclusive_or_expression BIT_OR exclusive_or_expression REDUCE to inclusive_or_expression\n");}
	;

logical_and_expression
	: inclusive_or_expression                               {
                                                             $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                         fprintf(fileLexLog,"<EXP> inclusive_or_expression REDUCE to logical_and_expression\n");
															}
	| logical_and_expression AND_OP inclusive_or_expression {fprintf(fileLexLog,"logical_and_expression AND_OP inclusive_or_expression REDUCE to logical_and_expression\n");}
	;

logical_or_expression
	: logical_and_expression                             {
                                                          $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                      fprintf(fileLexLog,"<EXP> logical_and_expression REDUCE to logical_or_expression\n");
														 }
	| logical_or_expression OR_OP logical_and_expression {fprintf(fileLexLog,"logical_or_expression OR_OP logical_and_expression REDUCE to logical_or_expression\n");}
	;

conditional_expression
	: logical_or_expression                                                        {
                                                                                    $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                                                fprintf(fileLexLog,"<EXP> logical_or_expression REDUCE to conditional_expression\n");
																				   }
	| logical_or_expression QUESTION_OP expression COLON_OP conditional_expression {fprintf(fileLexLog,"logical_or_expression QUESTION_OP expression COLON_OP conditional_expression REDUCE to conditional_expression\n");}
	;

assignment_expression
	: conditional_expression                                     {
                                                                  $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                              fprintf(fileLexLog,"<EXP> conditional_expression REDUCE to assignment_expression\n");
																 }
	| unary_expression assignment_operator assignment_expression {
	                                                              $<CompilerInfo>$ = $<CompilerInfo>3;
	                                                              fprintf(fileLexLog,"<EXP> unary_expression assignment_operator assignment_expression REDUCE to assignment_expression\n");
	                                                             }
	;

assignment_operator
	: EQUAL_OP     {fprintf(fileLexLog,"EQUAL_OP REDUCE to assignment_operator\n");}
	| MUL_ASSIGN   {fprintf(fileLexLog,"MUL_ASSIGN REDUCE to assignment_operator\n");}
	| DIV_ASSIGN   {fprintf(fileLexLog,"DIV_ASSIGN REDUCE to assignment_operator\n");}
	| MOD_ASSIGN   {fprintf(fileLexLog,"MOD_ASSIGN REDUCE to assignment_operator\n");}
	| ADD_ASSIGN   {fprintf(fileLexLog,"ADD_ASSIGN REDUCE to assignment_operator\n");}
	| SUB_ASSIGN   {fprintf(fileLexLog,"SUB_ASSIGN REDUCE to assignment_operator\n");}
	| LEFT_ASSIGN  {fprintf(fileLexLog,"LEFT_ASSIGN REDUCE to assignment_operator\n");}
	| RIGHT_ASSIGN {fprintf(fileLexLog,"RIGHT_ASSIGN REDUCE to assignment_operator\n");}
	| AND_ASSIGN   {fprintf(fileLexLog,"AND_ASSIGN REDUCE to assignment_operator\n");}
	| XOR_ASSIGN   {fprintf(fileLexLog,"XOR_ASSIGN REDUCE to assignment_operator\n");}
	| OR_ASSIGN    {fprintf(fileLexLog,"OR_ASSIGN REDUCE to assignment_operator\n");}
	;

expression
	: assignment_expression                     {
		                                         $<CompilerInfo>$ = $<CompilerInfo>1;
		                                         fprintf(fileLexLog,"<EXP> assignment_expression REDUCE to expression\n");
											    }
	| expression COMMA_OP assignment_expression {fprintf(fileLexLog," expression COMMA_OP assignment_expression REDUCE to expression\n");}
	;

constant_expression
	: conditional_expression   {fprintf(fileLexLog,"conditional_expression REDUCE to constant_expression\n");}
	;

declaration
	: declaration_specifiers SEMI_OP                        {fprintf(fileLexLog,"declaration_specifiers SEMI_OP REDUCE to declaration\n");}
	| declaration_specifiers init_declarator_list SEMI_OP   {
                                                             $<CompilerInfo>$.data.sign = $<CompilerInfo>1.data.sign;
	                                                         $<CompilerInfo>$.data.type = $<CompilerInfo>1.data.type;
	                                                         $<CompilerInfo>$.data.storage = $<CompilerInfo>1.data.storage;
	                                                         $<CompilerInfo>$.data.identifier = $<CompilerInfo>2.data.identifier;
															 if ($<CompilerInfo>2.arrayExpression == NULL){
															  fprintf(fileLexLog,"'%d %d %d %s' => declaration_specifiers init_declarator_list SEMI_OP REDUCE to declaration\n",$<CompilerInfo>$.data.storage,$<CompilerInfo>$.data.sign,$<CompilerInfo>$.data.type,$<CompilerInfo>$.data.identifier);
															 } else {
															  fprintf(fileLexLog,"'%d %d %d %s[]' => declaration_specifiers init_declarator_list SEMI_OP REDUCE to declaration\n",$<CompilerInfo>$.data.storage,$<CompilerInfo>$.data.sign,$<CompilerInfo>$.data.type,$<CompilerInfo>$.data.identifier);
															 }
															}
	;

declaration_specifiers
	: storage_class_specifier                        {fprintf(fileLexLog,"storage_class_specifier REDUCE to declaration_specifiers\n");}
	| storage_class_specifier declaration_specifiers {
	                                                  $<CompilerInfo>$.data.sign = $<CompilerInfo>2.data.sign;
	                                                  $<CompilerInfo>$.data.type = $<CompilerInfo>2.data.type;
	                                                  $<CompilerInfo>$.data.storage = $<CompilerInfo>1.data.storage;
	                                                  fprintf(fileLexLog,"%d %s %d => storage_class_specifier declaration_specifiers REDUCE to declaration_specifiers\n",$<CompilerInfo>$.data.storage,VariableSignName[$<CompilerInfo>$.data.sign],$<CompilerInfo>$.data.type);
													 }
	| type_specifier                                 {
	                                                   $<CompilerInfo>$ = $<CompilerInfo>1;
													   fprintf(fileLexLog,"'%s %s' type_specifier REDUCE to declaration_specifiers\n",VariableSignName[$<CompilerInfo>$.data.sign],VariableTypeName[$<CompilerInfo>$.data.type]);
													 }
	| type_specifier declaration_specifiers          {
	                                                   $<CompilerInfo>$.data.sign = $<CompilerInfo>1.data.sign;
	                                                   $<CompilerInfo>$.data.type = $<CompilerInfo>2.data.type;
													   fprintf(fileLexLog,"%s %d => type_specifier declaration_specifiers REDUCE to declaration_specifiers\n",VariableSignName[$<CompilerInfo>$.data.sign],$<CompilerInfo>$.data.type);
													 }
	| type_qualifier                                 {fprintf(fileLexLog,"type_qualifier REDUCE to declaration_specifiers\n");}
	| type_qualifier declaration_specifiers          {fprintf(fileLexLog,"type_qualifier declaration_specifiers SEMI_OP REDUCE to declaration_specifiers\n");}
	| function_specifier                             {fprintf(fileLexLog,"function_specifier REDUCE to declaration_specifiers\n");}
	| function_specifier declaration_specifiers      {fprintf(fileLexLog,"function_specifier declaration_specifiers REDUCE to declaration_specifiers\n");}
	;

init_declarator_list
	: init_declarator                               {
                                                     $<CompilerInfo>$ = $<CompilerInfo>1;
													 if ($<CompilerInfo>1.arrayExpression ==NULL){
	                                                  fprintf(fileLexLog,"'%s' => init_declarator REDUCE to init_declarator_list\n",$<CompilerInfo>$.data.identifier);
													 } else {
													  fprintf(fileLexLog,"'%s[]' => init_declarator REDUCE to init_declarator_list\n",$<CompilerInfo>$.data.identifier);
													 }
													}
	| init_declarator_list COMMA_OP init_declarator {
	                                                 $<CompilerInfo>$ = $<CompilerInfo>3;
	                                                 fprintf(fileLexLog,"'%s' => init_declarator_list COMMA_OP init_declarator REDUCE to init_declarator_list\n",$<CompilerInfo>$.data.identifier);
													 //addToSymbolTable($<CompilerInfo>3.identifier, $<CompilerInfo>3.type, $<CompilerInfo>3.sign, $<CompilerInfo>3.storage, $<CompilerInfo>3.declarationType, $<CompilerInfo>3.constant, $<CompilerInfo>3.arrayExpression);
	                                                }
	;

init_declarator
	: declarator                      {
                                       $<CompilerInfo>$ = $<CompilerInfo>1;
									   if ($<CompilerInfo>1.arrayExpression ==NULL){
	                                    fprintf(fileLexLog,"'%s' => declarator REDUCE to init_declarator\n",$<CompilerInfo>$.data.identifier);
									   } else {
									    fprintf(fileLexLog,"'%s[]' => declarator REDUCE to init_declarator\n",$<CompilerInfo>$.data.identifier);
									   }
									  }
	| declarator EQUAL_OP initializer {fprintf(fileLexLog,"declarator EQUAL_OP initializer REDUCE to init_declarator\n");}
	;

storage_class_specifier
	: TYPEDEF  {$<CompilerInfo>$.data.storage = STORAGE_NONE;     fprintf(fileLexLog,"TYPEDEF REDUCE to storage_class_specifier\n");}
	| EXTERN   {$<CompilerInfo>$.data.storage = STORAGE_EXTERN;   fprintf(fileLexLog,"EXTERN REDUCE to storage_class_specifier\n");}
	| STATIC   {$<CompilerInfo>$.data.storage = STORAGE_STATIC;   fprintf(fileLexLog,"STATIC REDUCE to storage_class_specifier\n");}
	| AUTO     {$<CompilerInfo>$.data.storage = STORAGE_AUTO;     fprintf(fileLexLog,"AUTO REDUCE to storage_class_specifier\n");}
	| REGISTER {$<CompilerInfo>$.data.storage = STORAGE_REGISTER; fprintf(fileLexLog,"REGISTER REDUCE to storage_class_specifier\n");}
	;

type_specifier
	: VOID                      {$<CompilerInfo>$.data.type = TYPE_VOID;      fprintf(fileLexLog,"'%s' REDUCE to type_specifier\n",VariableTypeName[$<CompilerInfo>$.data.type]); }
	| CHAR                      {$<CompilerInfo>$.data.type = TYPE_CHARACTER; fprintf(fileLexLog,"'%s' REDUCE to type_specifier\n",VariableTypeName[$<CompilerInfo>$.data.type]); }
	| SHORT                     {$<CompilerInfo>$.data.type = TYPE_SHORT;     fprintf(fileLexLog,"'%s' REDUCE to type_specifier\n",VariableTypeName[$<CompilerInfo>$.data.type]); }
	| INT                       {$<CompilerInfo>$.data.type = TYPE_INTEGER;   fprintf(fileLexLog,"'%s' REDUCE to type_specifier\n",VariableTypeName[$<CompilerInfo>$.data.type]); }
	| LONG                      {$<CompilerInfo>$.data.type = TYPE_LONG;      fprintf(fileLexLog,"'%s' REDUCE to type_specifier\n",VariableTypeName[$<CompilerInfo>$.data.type]); }
	| LONGLONG                  {$<CompilerInfo>$.data.type = TYPE_LONG64;    fprintf(fileLexLog,"'%s' REDUCE to type_specifier\n",VariableTypeName[$<CompilerInfo>$.data.type]); }
	| FLOAT                     {$<CompilerInfo>$.data.type = TYPE_FLOAT;     fprintf(fileLexLog,"'%s' REDUCE to type_specifier\n",VariableTypeName[$<CompilerInfo>$.data.type]); }
	| DOUBLE                    {$<CompilerInfo>$.data.type = TYPE_DOUBLE;    fprintf(fileLexLog,"'%s' REDUCE to type_specifier\n",VariableTypeName[$<CompilerInfo>$.data.type]); }
	| SIGNED                    {$<CompilerInfo>$.data.sign = TYPE_SIGNED;    fprintf(fileLexLog,"'%s' REDUCE to type_specifier\n",VariableTypeName[$<CompilerInfo>$.data.sign]); }
	| UNSIGNED                  {$<CompilerInfo>$.data.sign = TYPE_UNSIGNED;  fprintf(fileLexLog,"'%s' REDUCE to type_specifier\n",VariableTypeName[$<CompilerInfo>$.data.sign]); }
	| BOOL                      {$<CompilerInfo>$.data.type = TYPE_INTEGER;   fprintf(fileLexLog,"'%s' REDUCE to type_specifier\n",VariableTypeName[$<CompilerInfo>$.data.type]); }
	| COMPLEX                   {$<CompilerInfo>$.data.type = TYPE_COMPLEX;   fprintf(fileLexLog,"'%s' REDUCE to type_specifier\n",VariableTypeName[$<CompilerInfo>$.data.type]); }
	| IMAGINARY                 {$<CompilerInfo>$.data.type = TYPE_IMAGINARY; fprintf(fileLexLog,"'%s' REDUCE to type_specifier\n",VariableTypeName[$<CompilerInfo>$.data.type]); }
	| struct_or_union_specifier {fprintf(fileLexLog,"struct_or_union_specifier REDUCE to type_specifier\n");}
	| enum_specifier            {fprintf(fileLexLog,"enum_specifier REDUCE to type_specifier\n");}
	| TYPE_NAME                 {fprintf(fileLexLog,"type_specifier TYPE_NAME REDUCE to type_specifier\n");}
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER OCURLY_OP struct_declaration_list CCURLY_OP  {fprintf(fileLexLog,"struct_or_union IDENTIFIER OCURLY_OP struct_declaration_list CCURLY_OP REDUCE to struct_or_union_specifier\n");}
	| struct_or_union OCURLY_OP struct_declaration_list CCURLY_OP             {fprintf(fileLexLog,"struct_or_union OCURLY_OP struct_declaration_list CCURLY_OP REDUCE to struct_or_union_specifier\n");}
	| struct_or_union IDENTIFIER                                              {fprintf(fileLexLog,"struct_or_union IDENTIFIER REDUCE to struct_or_union_specifier\n");}
	;

struct_or_union
	: STRUCT   {fprintf(fileLexLog,"STRUCT REDUCE to struct_or_union\n");}
	| UNION    {fprintf(fileLexLog,"UNION REDUCE to struct_or_union\n");}
	;

struct_declaration_list
	: struct_declaration                         {fprintf(fileLexLog,"struct_declaration REDUCE to struct_declaration_list\n");}
	| struct_declaration_list struct_declaration {fprintf(fileLexLog,"struct_declaration_list struct_declaration REDUCE to struct_declaration_list\n");}
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list SEMI_OP  {fprintf(fileLexLog,"specifier_qualifier_list struct_declarator_list SEMI_OP REDUCE to struct_declaration\n");}
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list {fprintf(fileLexLog,"type_specifier specifier_qualifier_list REDUCE to specifier_qualifier_list\n");}
	| type_specifier                          {fprintf(fileLexLog,"type_specifier REDUCE to specifier_qualifier_list\n");}
	| type_qualifier specifier_qualifier_list {fprintf(fileLexLog,"type_qualifier specifier_qualifier_list REDUCE to specifier_qualifier_list\n");}
	| type_qualifier                          {fprintf(fileLexLog,"type_qualifier REDUCE to specifier_qualifier_list\n");}
	;

struct_declarator_list
	: struct_declarator                                 {fprintf(fileLexLog,"struct_declarator REDUCE to struct_declarator_list\n");}
	| struct_declarator_list COMMA_OP struct_declarator {fprintf(fileLexLog,"struct_declarator_list COMMA_OP struct_declarator REDUCE to struct_declarator_list\n");}
	;

struct_declarator
	: declarator                                 {fprintf(fileLexLog,"declarator REDUCE to struct_declarator\n");}
	| COLON_OP constant_expression               {fprintf(fileLexLog,"COLON_OP constant_expression REDUCE to struct_declarator\n");}
	| declarator COLON_OP constant_expression    {fprintf(fileLexLog,"declarator COLON_OP constant_expression REDUCE to struct_declarator\n");}
	;

enum_specifier
	: ENUM OCURLY_OP enumerator_list CCURLY_OP                     {fprintf(fileLexLog,"ENUM OCURLY_OP enumerator_list CCURLY_OP REDUCE to enum_specifier\n");}
	| ENUM IDENTIFIER OCURLY_OP enumerator_list CCURLY_OP          {fprintf(fileLexLog,"ENUM IDENTIFIER OCURLY_OP enumerator_list CCURLY_OP REDUCE to enum_specifier\n");}
	| ENUM OCURLY_OP enumerator_list COMMA_OP CCURLY_OP            {fprintf(fileLexLog,"ENUM OCURLY_OP enumerator_list COMMA_OP CCURLY_OP REDUCE to enum_specifier\n");}
	| ENUM IDENTIFIER OCURLY_OP enumerator_list COMMA_OP CCURLY_OP {fprintf(fileLexLog,"ENUM IDENTIFIER OCURLY_OP enumerator_list COMMA_OP CCURLY_OP REDUCE to enum_specifier\n");}
	| ENUM IDENTIFIER                                              {fprintf(fileLexLog,"ENUM IDENTIFIER REDUCE to enum_specifier\n");}
	;

enumerator_list
	: enumerator                           {fprintf(fileLexLog,"enumerator REDUCE to enumerator_list\n");}
	| enumerator_list COMMA_OP enumerator  {fprintf(fileLexLog,"enumerator_list COMMA_OP enumerator REDUCE to enumerator_list\n");}
	;

enumerator
	: IDENTIFIER                              {fprintf(fileLexLog,"IDENTIFIER REDUCE to enumerator\n");}
	| IDENTIFIER EQUAL_OP constant_expression {fprintf(fileLexLog,"IDENTIFIER EQUAL_OP constant_expression REDUCE to enumerator\n");}
	;

type_qualifier
	: CONST    {fprintf(fileLexLog,"CONST REDUCE to type_qualifier\n");}
	| RESTRICT {fprintf(fileLexLog,"RESTRICT REDUCE to type_qualifier\n");}
	| VOLATILE {fprintf(fileLexLog,"VOLATILE REDUCE to type_qualifier\n");}
	;

function_specifier
	: INLINE  {fprintf(fileLexLog,"INLINE REDUCE to function_specifier\n");}
	;

declarator
	: pointer direct_declarator  {fprintf(fileLexLog,"pointer direct_declarator REDUCE to declarator\n");}
	| direct_declarator          {
                                  $<CompilerInfo>$ = $<CompilerInfo>1;
								  if ($<CompilerInfo>1.arrayExpression == NULL) {
	                                  fprintf(fileLexLog,"'%s' => direct_declarator REDUCE to declarator\n",$<CompilerInfo>$.data.identifier);
								  } else {
	                                  fprintf(fileLexLog,"'%s[]'  => direct_declarator REDUCE to declarator\n",$<CompilerInfo>$.data.identifier);
								  }
								 }
	;


direct_declarator
	: IDENTIFIER                                                                                      {
	                                                                                                   $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                                                                   fprintf(fileLexLog,"'%s' => IDENTIFIER REDUCE to direct_declarator\n",$<CompilerInfo>$.data.identifier);
																									  }
	| OPENPAREN_OP declarator CLOSEPAREN_OP                                                           {fprintf(fileLexLog,"OPENPAREN_OP declarator CLOSEPAREN_OP REDUCE to direct_declarator\n");}
	| direct_declarator OPENBRACE_OP type_qualifier_list assignment_expression CLOSEBRACE_OP          {fprintf(fileLexLog,"direct_declarator OPENBRACE_OP type_qualifier_list assignment_expression CLOSEBRACE_OP REDUCE to direct_declarator\n");}
	| direct_declarator OPENBRACE_OP type_qualifier_list CLOSEBRACE_OP                                {fprintf(fileLexLog,"direct_declarator OPENBRACE_OP type_qualifier_list CLOSEBRACE_OP REDUCE to direct_declarator\n");}
	| direct_declarator OPENBRACE_OP assignment_expression CLOSEBRACE_OP                              {
	                                                                                                   $<CompilerInfo>$ = $<CompilerInfo>1;
																									   addToExpression(&$<CompilerInfo>$.arrayExpression,$<CompilerInfo>1.data.identifier,$<CompilerInfo>1.data.type,$<CompilerInfo>1.data.sign,FALSE);
	                                                                                                   fprintf(fileLexLog,"<EXP> direct_declarator OPENBRACE_OP assignment_expression CLOSEBRACE_OP REDUCE to direct_declarator\n");
																									  }
	| direct_declarator OPENBRACE_OP STATIC type_qualifier_list assignment_expression CLOSEBRACE_OP   {fprintf(fileLexLog,"direct_declarator OPENBRACE_OP STATIC type_qualifier_list assignment_expression CLOSEBRACE_OP REDUCE to direct_declarator\n");}
	| direct_declarator OPENBRACE_OP type_qualifier_list STATIC assignment_expression CLOSEBRACE_OP   {fprintf(fileLexLog,"direct_declarator OPENBRACE_OP type_qualifier_list STATIC assignment_expression CLOSEBRACE_OP REDUCE to direct_declarator\n");}
	| direct_declarator OPENBRACE_OP type_qualifier_list TIMES_OP CLOSEBRACE_OP                       {fprintf(fileLexLog,"direct_declarator OPENBRACE_OP type_qualifier_list TIMES_OP CLOSEBRACE_OP REDUCE to direct_declarator\n");}
	| direct_declarator OPENBRACE_OP TIMES_OP CLOSEBRACE_OP                                           {fprintf(fileLexLog,"direct_declarator OPENBRACE_OP TIMES_OP CLOSEBRACE_OP REDUCE to direct_declarator\n");}
	| direct_declarator OPENBRACE_OP CLOSEBRACE_OP                                                    {fprintf(fileLexLog,"direct_declarator OPENBRACE_OP CLOSEBRACE_OP REDUCE to direct_declarator\n");}
	| direct_declarator OPENPAREN_OP parameter_type_list CLOSEPAREN_OP                                {fprintf(fileLexLog,"direct_declarator OPENPAREN_OP parameter_type_list CLOSEPAREN_OP REDUCE to direct_declarator\n");}
	| direct_declarator OPENPAREN_OP identifier_list CLOSEPAREN_OP                                    {fprintf(fileLexLog,"direct_declarator OPENPAREN_OP identifier_list CLOSEPAREN_OP REDUCE to direct_declarator\n");}
	| direct_declarator OPENPAREN_OP CLOSEPAREN_OP                                                    {
		                                                                                               $<CompilerInfo>$ = $<CompilerInfo>1;
		                                                                                               fprintf(fileLexLog,"'%s' => direct_declarator OPENPAREN_OP CLOSEPAREN_OP REDUCE to direct_declarator\n",$<CompilerInfo>$.data.identifier);
																									  }
	;

pointer
	: TIMES_OP                             {fprintf(fileLexLog,"TIMES_OP REDUCE to pointer\n");}
	| TIMES_OP type_qualifier_list         {fprintf(fileLexLog,"TIMES_OP type_qualifier_list REDUCE to pointer\n");}
	| TIMES_OP pointer                     {fprintf(fileLexLog,"TIMES_OP pointer REDUCE to pointer\n");}
	| TIMES_OP type_qualifier_list pointer {fprintf(fileLexLog,"TIMES_OP type_qualifier_list pointer REDUCE to pointer\n");}
	;

type_qualifier_list
	: type_qualifier                     {fprintf(fileLexLog,"type_qualifier REDUCE to type_qualifier_list\n");}
	| type_qualifier_list type_qualifier {fprintf(fileLexLog,"type_qualifier_list type_qualifier REDUCE to type_qualifier_list\n");}
	;


parameter_type_list
	: parameter_list                   {fprintf(fileLexLog,"parameter_list REDUCE to parameter_type_list\n");}
	| parameter_list COMMA_OP ELLIPSIS {fprintf(fileLexLog,"parameter_list COMMA_OP ELLIPSIS REDUCE to parameter_type_list\n");}
	;

parameter_list
	: parameter_declaration                         {
	                                                 $<CompilerInfo>$ = $<CompilerInfo>1;
	                                                 fprintf(fileLexLog,"parameter_declaration REDUCE to parameter_list\n");
													}
	| parameter_list COMMA_OP parameter_declaration {
	                                                 fprintf(fileLexLog,"parameter_list COMMA_OP parameter_declaration REDUCE to parameter_list\n");
													}
	;

parameter_declaration
	: declaration_specifiers declarator          {
                                                  $<CompilerInfo>$ = $<CompilerInfo>1;
												  if ($<CompilerInfo>$.arrayExpression == NULL) {
	                                               fprintf(fileLexLog,"'%s' => declaration_specifiers declarator REDUCE to parameter_declaration\n",$<CompilerInfo>$.data.identifier);
								                  } else {
	                                               fprintf(fileLexLog,"'%s[]'  => declaration_specifiers declarator REDUCE to parameter_declaration\n",$<CompilerInfo>$.data.identifier);
								                  }
												 }
	| declaration_specifiers abstract_declarator {fprintf(fileLexLog,"declaration_specifiers abstract_declarator REDUCE to parameter_declaration\n");}
	| declaration_specifiers                     {fprintf(fileLexLog,"declaration_specifiers REDUCE to parameter_declaration\n");}
	;

identifier_list
	: IDENTIFIER                          {fprintf(fileLexLog,"IDENTIFIER REDUCE to identifier_list\n");}
	| identifier_list COMMA_OP IDENTIFIER {fprintf(fileLexLog,"identifier_list COMMA_OP IDENTIFIER REDUCE to identifier_list\n");}
	;

type_name
	: specifier_qualifier_list                     {fprintf(fileLexLog,"specifier_qualifier_list REDUCE to type_name\n");}
	| specifier_qualifier_list abstract_declarator {fprintf(fileLexLog,"specifier_qualifier_list abstract_declarator REDUCE to type_name\n");}
	;

abstract_declarator
	: pointer                            {fprintf(fileLexLog,"pointer REDUCE to abstract_declarator\n");}
	| direct_abstract_declarator         {fprintf(fileLexLog,"direct_abstract_declarator REDUCE to abstract_declarator\n");}
	| pointer direct_abstract_declarator {fprintf(fileLexLog,"pointer direct_abstract_declarator REDUCE to abstract_declarator\n");}
	;

direct_abstract_declarator
	: OPENPAREN_OP abstract_declarator CLOSEPAREN_OP                               {fprintf(fileLexLog,"OPENPAREN_OP abstract_declarator CLOSEPAREN_OP REDUCE to direct_abstract_declarator\n");}
	| OPENBRACE_OP CLOSEBRACE_OP                                                   {fprintf(fileLexLog,"OPENBRACE_OP CLOSEBRACE_OP REDUCE to direct_abstract_declarator\n");}
	| OPENBRACE_OP assignment_expression CLOSEBRACE_OP                             {fprintf(fileLexLog,"OPENBRACE_OP assignment_expression CLOSEBRACE_OP REDUCE to direct_abstract_declarator\n");}
	| direct_abstract_declarator OPENBRACE_OP CLOSEBRACE_OP                        {fprintf(fileLexLog,"direct_abstract_declarator OPENBRACE_OP CLOSEBRACE_OP REDUCE to direct_abstract_declarator\n");}
	| direct_abstract_declarator OPENBRACE_OP assignment_expression CLOSEBRACE_OP  {fprintf(fileLexLog,"direct_abstract_declarator OPENBRACE_OP assignment_expression CLOSEBRACE_OP REDUCE to direct_abstract_declarator\n");}
	| OPENBRACE_OP TIMES_OP CLOSEBRACE_OP                                          {fprintf(fileLexLog,"OPENBRACE_OP TIMES_OP CLOSEBRACE_OP REDUCE to direct_abstract_declarator\n");}
	| direct_abstract_declarator OPENBRACE_OP TIMES_OP CLOSEBRACE_OP               {fprintf(fileLexLog,"direct_abstract_declarator OPENBRACE_OP TIMES_OP CLOSEBRACE_OP REDUCE to direct_abstract_declarator\n");}
	| OPENPAREN_OP CLOSEPAREN_OP                                                   {fprintf(fileLexLog,"OPENPAREN_OP CLOSEPAREN_OP REDUCE to direct_abstract_declarator\n");}
	| OPENPAREN_OP parameter_type_list CLOSEPAREN_OP                               {fprintf(fileLexLog,"OPENPAREN_OP parameter_type_list CLOSEPAREN_OP REDUCE to direct_abstract_declarator\n");}
	| direct_abstract_declarator OPENPAREN_OP CLOSEPAREN_OP                        {fprintf(fileLexLog,"direct_abstract_declarator OPENPAREN_OP CLOSEPAREN_OP REDUCE to direct_abstract_declarator\n");}
	| direct_abstract_declarator OPENPAREN_OP parameter_type_list CLOSEPAREN_OP    {fprintf(fileLexLog,"direct_abstract_declarator OPENPAREN_OP parameter_type_list CLOSEPAREN_OP REDUCE to direct_abstract_declarator\n");}
	;

initializer
	: assignment_expression                         {fprintf(fileLexLog,"assignment_expression REDUCE to initializer\n");}
	| OCURLY_OP initializer_list CCURLY_OP          {fprintf(fileLexLog,"OCURLY_OP initializer_list CCURLY_OP REDUCE to initializer\n");}
	| OCURLY_OP initializer_list COMMA_OP CCURLY_OP {fprintf(fileLexLog,"OCURLY_OP initializer_list COMMA_OP CCURLY_OP REDUCE to initializer\n");}
	;

initializer_list
	: initializer                                       {fprintf(fileLexLog,"initializer REDUCE to initializer_list\n");}
	| designation initializer                           {fprintf(fileLexLog,"designation initializer REDUCE to initializer_list\n");}
	| initializer_list COMMA_OP initializer             {fprintf(fileLexLog,"initializer_list COMMA_OP initializer REDUCE to initializer_list\n");}
	| initializer_list COMMA_OP designation initializer {fprintf(fileLexLog,"initializer_list COMMA_OP designation initializer REDUCE to initializer_list\n");}
	;

designation
	: designator_list EQUAL_OP {fprintf(fileLexLog,"designator_list EQUAL_OP REDUCE to designation\n");}
	;

designator_list
	: designator                 {fprintf(fileLexLog,"designator REDUCE to designator_list\n");}
	| designator_list designator {fprintf(fileLexLog,"designator_list designator EQUAL_OP REDUCE to designator_list\n");}
	;

designator
	: OPENBRACE_OP constant_expression CLOSEBRACE_OP    {fprintf(fileLexLog,"labeled_statement REDUCE to statement\n");}
	| PERIOD_OP IDENTIFIER                              {fprintf(fileLexLog,"labeled_statement REDUCE to statement\n");}
	;

statement
	: labeled_statement     {fprintf(fileLexLog,"labeled_statement REDUCE to statement\n");}
	| compound_statement    {fprintf(fileLexLog,"compound_statement REDUCE to statement\n");}
	| expression_statement  {fprintf(fileLexLog,"expression_statement REDUCE to statement\n");}
	| selection_statement   {fprintf(fileLexLog,"selection_statement REDUCE to statement\n");}
	| iteration_statement   {fprintf(fileLexLog,"iteration_statement REDUCE to statement\n");}
	| jump_statement        {
		                     $<CompilerInfo>$ = $<CompilerInfo>1;
		                     fprintf(fileLexLog,"<EXP> jump_statement REDUCE to statement\n");
							}
	;

labeled_statement
	: IDENTIFIER COLON_OP statement               {fprintf(fileLexLog,"IDENTIFIER COLON_OP statement REDUCE to labeled_statement\n");}
	| CASE constant_expression COLON_OP statement {fprintf(fileLexLog,"CASE constant_expression COLON_OP statement REDUCE to labeled_statement\n");}
	| DEFAULT COLON_OP statement                  {fprintf(fileLexLog,"DEFAULT COLON_OP statement REDUCE to labeled_statement\n");}
	;

compound_statement
	: OCURLY_OP CCURLY_OP                 {fprintf(fileLexLog,"OCURLY_OP CCURLY_OP REDUCE to compound_statement\n");}
	| OCURLY_OP block_item_list CCURLY_OP {
		                                   $<CompilerInfo>$ = $<CompilerInfo>2;
		                                   fprintf(fileLexLog,"<EXP> OCURLY_OP block_item_list CCURLY_OP REDUCE to compound_statement\n");
										  }
	;

block_item_list
	: block_item                 {
		                          $<CompilerInfo>$ = $<CompilerInfo>1;
		                          fprintf(fileLexLog,"<EXP> block_item REDUCE to block_item_list\n");
								 }
	| block_item_list block_item {fprintf(fileLexLog,"block_item_list block_item REDUCE to block_item_list\n");}
	;

block_item
	: declaration  {fprintf(fileLexLog,"declaration REDUCE to block_item\n");}
	| statement    {
		            $<CompilerInfo>$ = $<CompilerInfo>1;
		            fprintf(fileLexLog,"<EXP> statement REDUCE to block_item\n");
				   }
	;

expression_statement
	: SEMI_OP            {fprintf(fileLexLog,"SEMI_OP REDUCE to expression_statement\n");}
	| expression SEMI_OP {fprintf(fileLexLog,"expression SEMI_OP REDUCE to expression_statement\n");}
	;

selection_statement
	: IF OPENPAREN_OP expression CLOSEPAREN_OP statement                {fprintf(fileLexLog,"IF OPENPAREN_OP expression CLOSEPAREN_OP statement REDUCE to selection_statement\n");}
	| IF OPENPAREN_OP expression CLOSEPAREN_OP statement ELSE statement {fprintf(fileLexLog,"IF OPENPAREN_OP expression CLOSEPAREN_OP statement ELSE statement REDUCE to selection_statement\n");}
	| SWITCH OPENPAREN_OP expression CLOSEPAREN_OP statement            {fprintf(fileLexLog,"SWITCH OPENPAREN_OP expression CLOSEPAREN_OP statement REDUCE to selection_statement\n");}
	;

iteration_statement
	: WHILE OPENPAREN_OP expression CLOSEPAREN_OP statement                                         {fprintf(fileLexLog,"WHILE OPENPAREN_OP expression CLOSEPAREN_OP statement REDUCE to iteration_statement\n");}
	| DO statement WHILE OPENPAREN_OP expression CLOSEPAREN_OP SEMI_OP                              {fprintf(fileLexLog,"DO statement WHILE OPENPAREN_OP expression CLOSEPAREN_OP SEMI_OP REDUCE to iteration_statement\n");}
	| FOR OPENPAREN_OP expression_statement expression_statement CLOSEPAREN_OP statement            {fprintf(fileLexLog,"FOR OPENPAREN_OP expression_statement expression_statement CLOSEPAREN_OP statement REDUCE to iteration_statement\n");}
	| FOR OPENPAREN_OP expression_statement expression_statement expression CLOSEPAREN_OP statement {fprintf(fileLexLog,"FOR OPENPAREN_OP expression_statement expression_statement expression CLOSEPAREN_OP statement REDUCE to iteration_statement\n");}
	| FOR OPENPAREN_OP declaration expression_statement CLOSEPAREN_OP statement                     {fprintf(fileLexLog,"FOR OPENPAREN_OP declaration expression_statement CLOSEPAREN_OP statement REDUCE to iteration_statement\n");}
	| FOR OPENPAREN_OP declaration expression_statement expression CLOSEPAREN_OP statement          {fprintf(fileLexLog,"FOR OPENPAREN_OP declaration expression_statement expression CLOSEPAREN_OP statement REDUCE to iteration_statement\n");}
	;

jump_statement
	: GOTO IDENTIFIER SEMI_OP   {fprintf(fileLexLog,"GOTO IDENTIFIER SEMI_OP REDUCE to jump_statement\n");}
	| CONTINUE SEMI_OP          {fprintf(fileLexLog,"CONTINUE SEMI_OP REDUCE to jump_statement\n");}
	| BREAK SEMI_OP             {fprintf(fileLexLog,"BREAK SEMI_OP REDUCE to jump_statement\n");}
	| RETURN SEMI_OP            {fprintf(fileLexLog,"RETURN SEMI_OP REDUCE to jump_statement\n");}
	| RETURN expression SEMI_OP {
		                         $<CompilerInfo>$ = $<CompilerInfo>2;
		                         fprintf(fileLexLog,"<EXP> RETURN expression SEMI_OP REDUCE to jump_statement\n");
								}
	;

translation_unit
	: external_declaration                  {
                                             $<CompilerInfo>$ = $<CompilerInfo>1;
											 //addToSymbolTable($<CompilerInfo>1.data.identifier, $<CompilerInfo>1.data.type, $<CompilerInfo>1.data.sign, $<CompilerInfo>1.data.storage, $<CompilerInfo>1.data.declarationType, $<CompilerInfo>1.data.constant, $<CompilerInfo>1.arrayExpression);
	                                         fprintf(fileLexLog,"<EXP> external_declaration REDUCE to translation_unit\n");
											}
	| translation_unit external_declaration {
											 //addToSymbolTable($<CompilerInfo>2.data.identifier, $<CompilerInfo>2.data.type, $<CompilerInfo>2.data.sign, $<CompilerInfo>2.data.storage, $<CompilerInfo>2.data.declarationType, $<CompilerInfo>2.data.constant, $<CompilerInfo>1.arrayExpression);
		                                     fprintf(fileLexLog,"<EXP> translation_unit external_declaration REDUCE to translation_unit\n");
											}
	;

external_declaration
	: function_definition {
                           $<CompilerInfo>$ = $<CompilerInfo>1;
						   $<CompilerInfo>$.data.declarationType = DECLARATION_FUNCTION;
                           addToFunctionTable($<CompilerInfo>$.data.identifier, $<CompilerInfo>$.data.type, $<CompilerInfo>$.data.sign, $<CompilerInfo>$.data.storage, $<CompilerInfo>$.data.declarationType, $<CompilerInfo>$.data.constant, $<CompilerInfo>$.arrayExpression);
						   fprintf(fileLexLog,"'%d %d %s %s' => function_definition REDUCE to external_declaration\n",$<CompilerInfo>$.data.storage,$<CompilerInfo>$.data.sign,VariableTypeName[$<CompilerInfo>$.data.type],$<CompilerInfo>$.data.identifier);
						  }
	| declaration         {
                           $<CompilerInfo>$ = $<CompilerInfo>1;
						   $<CompilerInfo>$.data.declarationType = DECLARATION_VARIABLE;
                           $<CompilerInfo>$.data.sign = $<CompilerInfo>1.data.sign;
                           $<CompilerInfo>$.data.type = $<CompilerInfo>1.data.type;
                           $<CompilerInfo>$.data.storage = $<CompilerInfo>1.data.storage;
                           $<CompilerInfo>$.data.identifier = $<CompilerInfo>1.data.identifier;
                           if ($<CompilerInfo>$.arrayExpression==NULL){
	                        fprintf(fileLexLog,"'%d %d %d %s' => declaration REDUCE to external_declaration\n",$<CompilerInfo>$.data.storage,$<CompilerInfo>$.data.sign,$<CompilerInfo>$.data.type,$<CompilerInfo>$.data.identifier);
						   } else {
						    fprintf(fileLexLog,"'%d %d %d %s[]' => declaration REDUCE to external_declaration\n",$<CompilerInfo>$.data.storage,$<CompilerInfo>$.data.sign,$<CompilerInfo>$.data.type,$<CompilerInfo>$.data.identifier);
						   }
                           addToSymbolTable($<CompilerInfo>$.data.identifier, $<CompilerInfo>$.data.type, $<CompilerInfo>$.data.sign, $<CompilerInfo>$.data.storage, $<CompilerInfo>$.data.declarationType, $<CompilerInfo>$.data.constant, $<CompilerInfo>$.arrayExpression);
						   fprintf(fileLexLog,"'%d %d %s %s' => function_definition REDUCE to external_declaration\n",$<CompilerInfo>$.data.storage,$<CompilerInfo>$.data.sign,VariableTypeName[$<CompilerInfo>$.data.type],$<CompilerInfo>$.data.identifier);
						  }
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement {fprintf(fileLexLog,"declaration_specifiers declarator declaration_list compound_statement REDUCE to function_definition\n");}
	| declaration_specifiers declarator compound_statement                  { 
		                                                                     
		                                                                     $<CompilerInfo>$.data.sign = $<CompilerInfo>1.data.sign;
                                                                             $<CompilerInfo>$.data.type = $<CompilerInfo>1.data.type;
																			 $<CompilerInfo>$.data.storage = $<CompilerInfo>1.data.storage;
																			 $<CompilerInfo>$.data.identifier = $<CompilerInfo>2.data.identifier;	
		                                                                     fprintf(fileLexLog,"<EXP> declaration_specifiers declarator compound_statement REDUCE to function_definition\n");
																			}
	;

declaration_list
	: declaration                   {fprintf(fileLexLog,"declaration REDUCE to declaration_list\n");}
	| declaration_list declaration  {fprintf(fileLexLog,"declaration_list declaration REDUCE to declaration_list\n");}
	;

%%

void yyerror(const char* s) {
	fprintf(stderr, "Parse error on line %d column %d : %s\n", yylineno, column, s);
	num_errors++;
}