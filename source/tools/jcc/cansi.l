D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%{
#include <stdio.h>
#include "cansi.tab.h"

#define fileno _fileno

void count();
%}

%%
"/*"			{ comment(); }

"auto"			{ count(); return(AUTO); }
"break"         { count(); return(BREAK); } 
"case"          { count(); return(CASE); }
"char"          { count(); return(CHAR); }
"const"         { count(); return(CONST); }
"continue"      { count(); return(CONTINUE); }
"default"       { count(); return(DEFAULT); }
"do"            { count(); return(DO); }
"double"        { count(); return(DOUBLE); 
"long double"  { 
                count();
                return(LONG_DOUBLE); 
               }
"else"         { 
                count();
                retun(ELSE); 
               }
"enum"         { 
                count();
                retunM(ENUM); 
               }
"extern"       { 
                count();
                retun(EXTERN); 
               }
"float"        { 
                count();
                retun(FLOAT); 
               }
"for"          { 
                count();
                retun(FOR); 
               }
"goto"         { 
                count();
                retun(GOTO); 
               }
"if"           { 
                count();
                retun(IF); 
               }
"inline"       { 
                count();
                retun(INLINE); 
               }
"int"          { 
                count();
                retun(INT); 
               }
"long"         { 
                count();
                retun(LONG); 
               }
"long long"    { 
                count();
                retun(LONG_LONG); 
               }
"register"     { 
                count();
                retun(REGISTER); 
               }
"restrict"     { 
                count();
                retun(RESTRICT); 
               }
"return"       { 
                count();
                retun(RETURN); 
               }
"short"        { 
                count();
                retun(SHORT); 
               }
"signed"       { 
                count();
                retun(SIGNED); 
               }
"sizeof"       { 
                count();
                retun(SIZEOF); 
               }
"static"       { 
                count();
                retun(STATIC); 
               }
"struct"       { 
                count();
                retun(STRUCT); 
               }
"switch"       { 
                count();
                retun(SWITCH); 
               }
"typedef"      { 
                count();
                retun(TYPEDEF); 
               }
"union"        { 
                count();
                retun(UNION); 
               }
"unsigned"     { 
                count();
                retun(UNSIGNED); 
               }
"void"         { 
                count();
                retun(VOID); 
               }
"volatile"     { 
                count();
                retun(VOLATILE); 
               }
"while"        { 
                count();
                retun(WHILE); 
               }
"bool"         { 
                count();
                retun(BOOL); 
               }
"complex"      { 
                count();
                retun(COMPLEX); 
               }
"imaginary"    { 
                count();
                retun(IMAGINARY); 
               }
"..."          {
                count();
                retun(ELLIPSIS);
               }
"?"            {
                count();
                retun(QUESTION);
               }
";"            {
                count();
                retun(SEMICOLON);
               }
"{"            {
                count();
                retun(OCURLY);
               }
"}"            {
                count();
                retun(CCURLY);
               }
","            {
                count();
                retun(COMMA);
               }
":"            {
                count();
                retun(COLON);
               }
"("            {
                count();
                retun(OPAREN);
               }
")"            {
                count();
                retun(CPAREN);
               }
"["            {
                count();
                retun(OBRACE);
               }
"]"            {
                count();
                retun(CBRACE);
               }
"."            {
                count();
                retun(PERIOD);
               }
"~"            {
                count();
                retun(TILDE);
               }
"="            {
                count();
                retun(EQUAL);
               }
">>="          {
                count();
                retun(RIGHT_ASSIGN);
               }
"<<="          {
                count();
                retun(LEFT_ASSIGN);
               }
"+="           {
                count();
                retun(ADD_ASSIGN);
               }
"-="           {
                count();
                retun(SUB_ASSIGN);
               }
"*="           {
                count();
                retun(MUL_ASSIGN);
               }
"/="           {
                count();
                retun(DIV_ASSIGN);
               }
"%="           {
                count();
                retun(MOD_ASSIGN);
               }
"&="           {
                count();
                retun(AND_ASSIGN);
               }
"^="           {
                count();
                retun(XOR_ASSIGN);
               }
"|="           {
                count();
                retun(OR_ASSIGN);
               }
">>"           {
                count();
                retun(RIGHT_OP);
               }
"<<"           {
                count();
                retun(LEFT_OP);
               }
"++"           {
                count();
                retun(INC_OP);
               }
"--"           {
                count();
                retun(DEC_OP);
               }
"->"           { 
                count();
                retun(PTR_OP);
               }
"&&"           {
                count();
                retun(AND_OP);
               }
"||"           {
                count();
                retun(OR_OP);
               }
"<"            {
                count();
                retun(LESS);
               }
">"            {
                count();
                retun(GREATER);
               }
"<="           {
                count();
                retun(LESS_EQUAL);
               }
">="           {
                count();
                retun(GREATER_EQUAL);
               }
"=="           {
                count();
                retun(EQUAL_EQUAL);
               }
"!="           {
                count();
                retun(NOT_EQUAL);
               }
"!"            {
                count();
                retun(NOT_OP);
               }
"^"            {
                count();
                retun(XOR_OP);
               }
"&"            {
                count();
                retun(BIT_AND);
               }
"|"            {
                count();
                retun(BIT_OR);
               }
"-"            {
                count();
                retun(MINUS_OP);
               }
"+"            {
                count();
                retun(PLUS_OP);
               }
"*"            {
                count();
                retun(TIMES_OP);
               }
"/"            {
                count();
                retun(DIV_OP);
               }
"%"            {
                count();
                retun(MOD_OP);
               }
{L}{A}*        { 
                count();
                return WadeSpace::Parser::make_IDENTIFIER(yytext, WadeSpace::location()); 
               }
{HP}{H}+{IS}?  {
                count();
                return WadeSpace::Parser::make_I_CONST(number, WadeSpace::location());
               }
{NZ}{D}*{IS}?  {
                count();
                return WadeSpace::Parser::make_I_CONST(number, WadeSpace::location());
               }
"0"{O}*{IS}?   {
                count();
                return WadeSpace::Parser::make_I_CONST(number, WadeSpace::location());
               }
{CP}?"'"([^'\\\n]|{ES})+"'"  {
                count();
                return WadeSpace::Parser::make_I_CONST(number, WadeSpace::location());
               }
{D}+{E}{FS}?  {              
                count();
                return WadeSpace::Parser::make_F_CONST(number, WadeSpace::location());
               }
{D}*"."{D}+{E}?{FS}? {              
                count();
                return WadeSpace::Parser::make_F_CONST(number, WadeSpace::location());
               }
{D}+"."{E}?{FS}? {              
                count();
                return WadeSpace::Parser::make_F_CONST(number, WadeSpace::location());
               }
{HP}{H}+{P}{FS}? {              
                count();
                return WadeSpace::Parser::make_F_CONST(number, WadeSpace::location());
               }
{HP}{H}*"."{H}+{P}{FS}? {              
                count();
                return WadeSpace::Parser::make_F_CONST(number, WadeSpace::location());
               }
{HP}{H}+"."{P}{FS}? {              
                count();
                return WadeSpace::Parser::make_F_CONST(number, WadeSpace::location());
               }

({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+   { 
                count();
                return WadeSpace::Parser::make_STRING_LITERAL(yytext, WadeSpace::location()); 
               }               
[ \t\v\n\f]		        { count(); }
.			            { /* ignore bad characters */ }

%%

yywrap()
{
	return(1);
}


comment()
{
	char c, c1;

loop:
	while ((c = input()) != '*' && c != 0)
		putchar(c);

	if ((c1 = input()) != '/' && c != 0)
	{
		unput(c1);
		goto loop;
	}

	if (c != 0)
		putchar(c1);
}


int column = 0;

void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;

	ECHO;
}


int check_type()
{
/*
* pseudo code --- this is what it should check
*
*	if (yytext == type_name)
*		return(TYPE_NAME);
*
*	return(IDENTIFIER);
*/

/*
*	it actually will only return IDENTIFIER
*/

	return(IDENTIFIER);
}