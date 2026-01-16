%e  1019
%p  2807
%n  371
%k  284
%a  1213
%o  1117

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
#include <io.h>
#include <fcntl.h>
#include "jcc.h"
#include "cansi.tab.h"

#define fileno _fileno
#define isatty _isatty

extern void yyerror(const char *);  /* prints grammar violation message */
static void comment(void);
static int check_type(void);
%}

%option bison-bridge

%%
"/*"                    { comment(); }
"//".*                  { /* consume //-comment */ }
"auto"					{ return(Y_AUTO); }
"break"					{ return(Y_BREAK); }
"case"					{ return(Y_CASE); }
"char"					{ return(Y_CHAR); }
"const"					{ return(Y_CONST); }
"continue"				{ return(Y_CONTINUE); }
"default"				{ return(Y_DEFAULT); }
"do"					{ return(Y_DO); }
"double"				{ return(Y_DOUBLE); }
"long double"			{ return(Y_LONG_DOUBLE); }
"else"					{ return(Y_ELSE); }
"enum"					{ return(Y_ENUM); }
"extern"				{ return(Y_EXTERN); }
"float"					{ return(Y_FLOAT); }
"for"					{ return(Y_FOR); }
"goto"					{ return(Y_GOTO); }
"if"					{ return(Y_IF); }
"inline"				{ return(Y_INLINE); }
"int"					{ return(Y_INT); }
"long"					{ return(Y_LONG); }
"long long"				{ return(Y_LONG_LONG); }
"register"				{ return(Y_REGISTER); }
"restrict"				{ return(Y_RESTRICT); }
"return"				{ return(Y_RETURN); }
"short"					{ return(Y_SHORT); }
"signed"				{ return(Y_SIGNED); }
"sizeof"				{ return(Y_SIZEOF); }
"static"				{ return(Y_STATIC); }
"struct"				{ return(Y_STRUCT); }
"switch"				{ return(Y_SWITCH); }
"typedef"				{ return(Y_TYPEDEF); }
"union"					{ return(Y_UNION); }
"unsigned"				{ return(Y_UNSIGNED); }
"void"					{ return(Y_VOID); }
"volatile"				{ return(Y_VOLATILE); }
"while"					{ return(Y_WHILE); }
"_Alignas"              { return Y_ALIGNAS; }
"_Alignof"              { return Y_ALIGNOF; }
"_Atomic"               { return Y_ATOMIC; }
"bool"                 { return Y_BOOL; }
"complex"              { return Y_COMPLEX; }
"_Generic"              { return Y_GENERIC; }
"imaginary"            { return Y_IMAGINARY; }
"_Noreturn"             { return Y_NORETURN; }
"_Static_assert"        { return Y_STATIC_ASSERT; }
"_Thread_local"         	        { return Y_THREAD_LOCAL; }
"__func__"              	        { return Y_FUNC_NAME; }
{L}{A}*						        { yylval->string = _strdup(yytext); return IDENTIFIER; }
{HP}{H}+{IS}?				        { yylval->longlong = strtoull(yytext, 0, 10); return I_CONSTANT; }
{NZ}{D}*{IS}?				        { yylval->longlong = strtoull(yytext, 0, 10); return I_CONSTANT; }
"0"{O}*{IS}?				        { yylval->longlong = strtoull(yytext, 0, 10); return I_CONSTANT; }
{CP}?"'"([^'\\\n]|{ES})+"'"		    { yylval->longlong = strtoull(yytext, 0, 10); return I_CONSTANT; }
{D}+{E}{FS}?				        { yylval->longdouble = strtold(yytext, NULL); return F_CONSTANT; }
{D}*"."{D}+{E}?{FS}?			    { yylval->longdouble = strtold(yytext, NULL); return F_CONSTANT; }
{D}+"."{E}?{FS}?			        { yylval->longdouble = strtold(yytext, NULL); return F_CONSTANT; }
{HP}{H}+{P}{FS}?			        { yylval->longdouble = strtold(yytext, NULL); return F_CONSTANT; }
{HP}{H}*"."{H}+{P}{FS}?			    { yylval->longdouble = strtold(yytext, NULL); return F_CONSTANT; }
{HP}{H}+"."{P}{FS}?    			    { yylval->longdouble = strtold(yytext, NULL); return F_CONSTANT; }
({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+	{ yylval->string = _strdup(yytext); return STRING_LITERAL; }
"..."					{ return Y_DOT_DOT_DOT; }
">>="					{ return Y_RSHIFT_EQUAL; }
"<<="					{ return Y_LSHIFT_EQUAL; }
"+="					{ return Y_PLUS_EQUAL; }
"-="					{ return Y_MINUS_EQUAL; }
"*="					{ return Y_TIMES_EQUAL; }
"/="					{ return Y_DIVIDE_EQUAL; }
"%="					{ return Y_PERCENT_EQUAL; }
"&="					{ return Y_AND_EQUAL; }
"^="					{ return Y_XOR_EQUAL; }
"|="					{ return Y_OR_EQUAL; }
">>"					{ return Y_RSHIFT; }
"<<"					{ return Y_LSHIFT; }
"++"					{ return Y_PLUS_PLUS; }
"--"					{ return Y_MINUS_MINUS; }
"->"					{ return Y_ARROW; }
"&&"					{ return Y_AND_AND; }
"||"					{ return Y_OR_OR; }
"<="					{ return Y_LE; }
">="					{ return Y_GE; }
"=="					{ return Y_EQ; }
"!="					{ return Y_NE; }
";"					{ return Y_SEMICOLON; }
"{" 				{ return  Y_LEFT_BRACE; }
"}" 				{ return  Y_RIGHT_BRACE; }
","					{ return  Y_COMMA; }
":"					{ return Y_COLON; }
"="					{ return Y_EQUAL; }
"("					{ return Y_LEFT_PAREN; }
")"					{ return Y_RIGHT_PAREN; }
"[" 				{ return Y_LEFT_BRACKET; }
"]" 				{ return Y_RIGHT_BRACKET; }
"."					{ return Y_DOT; }
"&"					{ return Y_AND; }
"!"					{ return Y_EXCLAMATION; }
"~"					{ return Y_TILDE; }
"-"					{ return Y_MINUS; }
"+"					{ return Y_PLUS; }
"*"					{ return Y_TIMES; }
"/"					{ return Y_DIVIDE; }
"%"					{ return Y_PERCENT; }
"<"					{ return Y_LT; }
">"					{ return Y_GT; }
"^"					{ return Y_XOR; }
"|"					{ return Y_OR; }
"?"					{ return Y_QUESTION; }

{WS}+					{ /* whitespace separates tokens */ }
.					{ /* discard bad characters */ }

%%

int yywrap(void)        /* called at end of input */
{
    return 1;           /* terminate now */
}

static void comment(void)
{
    int c;

    while ((c = input()) != 0)
        if (c == '*')
        {
            while ((c = input()) == '*')
                ;

            if (c == '/')
                return;

            if (c == 0)
                break;
        }
    yyerror("unterminated comment");
}

static int check_type(void)
{
        return IDENTIFIER;
}
