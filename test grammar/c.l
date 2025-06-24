/*
Note: The following %-parameters are the minimum sizes needed for real Lex.
%e  number of parsed tree nodes
%p  number of positions
%n  number of states
%k  number of packed character classes
%a  number of transitions
%o  size of output array
*/
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
#include "y.tab.h"

void count();
%}

%option reentrant bison-bridge

%%
"/*"            { comment(); }

"auto"          { count(); return(AUTO); }
"break"         { count(); return(BREAK); }
"case"          { count(); return(CASE); }
"char"          { count(); return(CHAR); }
"const"         { count(); return(CONST); }
"continue"      { count(); return(CONTINUE); }
"default"       { count(); return(DEFAULT); }
"do"            { count(); return(DO); }
"double"        { count(); return(DOUBLE); }
"else"          { count(); return(ELSE); }
"enum"          { count(); return(ENUM); }
"extern"        { count(); return(EXTERN); }
"float"         { count(); return(FLOAT); }
"for"           { count(); return(FOR); }
"goto"          { count(); return(GOTO); }
"if"            { count(); return(IF); }
"int"           { count(); return(INT); }
"long"          { count(); return(LONG); }
"register"      { count(); return(REGISTER); }
"return"        { count(); return(RETURN); }
"short"         { count(); return(SHORT); }
"signed"        { count(); return(SIGNED); }
"sizeof"        { count(); return(SIZEOF); }
"static"        { count(); return(STATIC); }
"struct"        { count(); return(STRUCT); }
"switch"        { count(); return(SWITCH); }
"typedef"       { count(); return(TYPEDEF); }
"union"         { count(); return(UNION); }
"unsigned"      { count(); return(UNSIGNED); }
"void"          { count(); return(VOID); }
"volatile"      { count(); return(VOLATILE); }
"while"         { count(); return(WHILE); }
{L}{A}*                     { count(); return check_type(); }
{HP}{H}+{IS}?               { count(); return I_CONSTANT; }
{NZ}{D}*{IS}?               { count(); return I_CONSTANT; }
"0"{O}*{IS}?                { count(); return I_CONSTANT; }
{CP}?"'"([^'\\\n]|{ES})+"'" { count(); return I_CONSTANT; }
{D}+{E}{FS}?                { count(); return F_CONSTANT; }
{D}*"."{D}+{E}?{FS}?        { count(); return F_CONSTANT; }
{D}+"."{E}?{FS}?            { count(); return F_CONSTANT; }
{HP}{H}+{P}{FS}?            { count(); return F_CONSTANT; }
{HP}{H}*"."{H}+{P}{FS}?     { count(); return F_CONSTANT; }
{HP}{H}+"."{P}{FS}?         { count(); return F_CONSTANT; }

({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+   { count(); return STRING_LITERAL; }

"..."           { count(); return(ELLIPSIS); }
">>="           { count(); return(RIGHT_ASSIGN); }
"<<="           { count(); return(LEFT_ASSIGN); }
"+="            { count(); return(ADD_ASSIGN); }
"-="            { count(); return(SUB_ASSIGN); }
"*="            { count(); return(MUL_ASSIGN); }
"/="            { count(); return(DIV_ASSIGN); }
"%="            { count(); return(MOD_ASSIGN); }
"&="            { count(); return(AND_ASSIGN); }
"^="            { count(); return(XOR_ASSIGN); }
"|="            { count(); return(OR_ASSIGN); }
">>"            { count(); return(RIGHT_OP); }
"<<"            { count(); return(LEFT_OP); }
"++"            { count(); return(INC_OP); }
"--"            { count(); return(DEC_OP); }
"->"            { count(); return(PTR_OP); }
"&&"            { count(); return(AND_OP); }
"||"            { count(); return(OR_OP); }
"<="            { count(); return(LE_OP); }
">="            { count(); return(GE_OP); }
"=="            { count(); return(EQ_OP); }
"!="            { count(); return(NE_OP); }
";"             { count(); return(';'); }
("{"|"<%")      { count(); return('{'); }
("}"|"%>")      { count(); return('}'); }
","         { count(); return(','); }
":"         { count(); return(':'); }
"="         { count(); return('='); }
"("         { count(); return('('); }
")"         { count(); return(')'); }
("["|"<:")      { count(); return('['); }
("]"|":>")      { count(); return(']'); }
"."         { count(); return('.'); }
"&"         { count(); return('&'); }
"!"         { count(); return('!'); }
"~"         { count(); return('~'); }
"-"         { count(); return('-'); }
"+"         { count(); return('+'); }
"*"         { count(); return('*'); }
"/"         { count(); return('/'); }
"%"         { count(); return('%'); }
"<"         { count(); return('<'); }
">"         { count(); return('>'); }
"^"         { count(); return('^'); }
"|"         { count(); return('|'); }
"?"         { count(); return('?'); }

[ \t\v\n\f]     { count(); }
.           { /* ignore bad characters */ }

%%

// Required for reentrant scanner
int yywrap(yyscan_t scanner) {
    return 1; // Indicate no more input
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
*   if (yytext == type_name)
*       return(TYPE_NAME);
*
*   return(IDENTIFIER);
*/

/*
*   it actually will only return IDENTIFIER
*/

    return(IDENTIFIER);
}