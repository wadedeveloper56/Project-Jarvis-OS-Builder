O   [0-7]
D   [0-9]
NZ  [1-9]
L   [a-zA-Z_]
A   [a-zA-Z_0-9]
H   [a-fA-F0-9]
HP  (0[xX])
E   ([Ee][+-]?{D}+)
P   ([Pp][+-]?{D}+)
FS  (f|F|l|L)
IS  (((u|U)(l|L|ll|LL)?)|((l|L|ll|LL)(u|U)?))
CP  (u|U|L)
SP  (u8|u|U|L)
ES  (\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
WS  [ \t\v\n\f]


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
                return(IDENTIFIER); 
               }
{HP}{H}+{IS}?  {
                count();
                return(I_CONST);
               }
{NZ}{D}*{IS}?  {
                count();
                return(I_CONST);
               }
"0"{O}*{IS}?   {
                count();
                return(I_CONST);
               }
{CP}?"'"([^'\\\n]|{ES})+"'"  {
                count();
                return(I_CONST);
               }
{D}+{E}{FS}?  {              
                count();
                return(F_CONST);
               }
{D}*"."{D}+{E}?{FS}? {              
                count();
                return(F_CONST);
               }
{D}+"."{E}?{FS}? {              
                count();
                return(F_CONST);
               }
{HP}{H}+{P}{FS}? {              
                count();
                return(F_CONST);
               }
{HP}{H}*"."{H}+{P}{FS}? {              
                count();
                return(F_CONST);
               }
{HP}{H}+"."{P}{FS}? {              
                count();
                return(F_CONST);
               }

({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+   { 
                count();
                return(STRING_LITERAL); 
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