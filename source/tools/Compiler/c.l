%option yylineno
%e  1019
%p  2807
%n  371
%k  284
%a  1213
%o  1117

D   [0-9]
L   [a-zA-Z_]
H   [a-fA-F0-9]
E   ([Ee][+-]?{D}+)
P   ([Pp][+-]?{D}+)
FS  (f|F|l|L)
IS  ((u|U)|(u|U)?(l|L|ll|LL)|(l|L|ll|LL)(u|U))

%{
#include "global.h"
#include "c.tab.h"

int column = 0;
FILE * fileLexLog;
int num_errors;
%}

%%
^"#"[ \t]*include[ \t]*[\"<]{L}({L}|{D})*[^ \t\n\">] { count(); return(INCLUDE);}
"/*"             { comment(); }
"//".*           { /* consume //-comment */ }
"auto"           { count(); return(AUTO); }
"break"          { count(); return(BREAK); }
"case"           { count(); return(CASE); }
"char"           { count(); return(CHAR); }
"const"          { count(); return(CONST); }
"continue"       { count(); return(CONTINUE); }
"default"        { count(); return(DEFAULT); }
"do"             { count(); return(DO); }
"double"         { count(); return(DOUBLE); }
"long double"    { count(); return(LONGDOUBLE); }
"else"           { count(); return(ELSE); }
"enum"           { count(); return(ENUM); }
"extern"         { count(); return(EXTERN); }
"float"          { count(); return(FLOAT); }
"for"            { count(); return(FOR); }
"goto"           { count(); return(GOTO); }
"if"             { count(); return(IF); }
"inline"         { count(); return(INLINE); }
"int"            { count(); return(INT); }
"long"           { count(); return(LONG); }
"long long"      { count(); return(LONGLONG); }
"register"       { count(); return(REGISTER); }
"restrict"       { count(); return(RESTRICT); }
"return"         { count(); return(RETURN); }
"short"          { count(); return(SHORT); }
"signed"         { count(); return(SIGNED); }
"sizeof"         { count(); return(SIZEOF); }
"static"         { count(); return(STATIC); }
"struct"         { count(); return(STRUCT); }
"switch"         { count(); return(SWITCH); }
"typedef"        { count(); return(TYPEDEF); }
"union"          { count(); return(UNION); }
"unsigned"       { count(); return(UNSIGNED); }
"void"           { count(); return(VOID); }
"volatile"       { count(); return(VOLATILE); }
"while"          { count(); return(WHILE); }
"bool"           { count(); return BOOL; }
"complex"        { count(); return COMPLEX; }
"imaginary"      { count(); return IMAGINARY; }

{L}({L}|{D})*             { count(); return(handleIndentifier(IDENTIFIER)); }
0[xX]{H}+{IS}?            { count(); return(handleIndentifier(CONSTANT)); }
0[0-7]*{IS}?              { count(); return(handleIndentifier(CONSTANT)); }
[1-9]{D}*{IS}?            { count(); return(handleIndentifier(CONSTANT)); }
L?'(\\.|[^\\'\n])+'       { count(); return(handleIndentifier(CONSTANT)); }
{D}+{E}{FS}?              { count(); return(handleIndentifier(CONSTANT)); }
{D}*"."{D}+{E}?{FS}?      { count(); return(handleIndentifier(CONSTANT)); }
{D}+"."{D}*{E}?{FS}?      { count(); return(handleIndentifier(CONSTANT)); }
0[xX]{H}+{P}{FS}?         { count(); return(handleIndentifier(CONSTANT)); }
0[xX]{H}*"."{H}+{P}?{FS}? { count(); return(handleIndentifier(CONSTANT)); }
0[xX]{H}+"."{H}*{P}?{FS}? { count(); return(handleIndentifier(CONSTANT)); }
L?\"(\\.|[^\\"\n])*\"     { count(); return(handleIndentifier(STRING_LITERAL)); }
"..."                     { count(); return(ELLIPSIS); }
"?"                       { count(); return(QUESTION_OP); }
";"                       { count(); return(SEMI_OP); }
("{"|"<%")                { count(); return(OCURLY_OP); }
("}"|"%>")                { count(); return(CCURLY_OP); }
","                       { count(); return(COMMA_OP); }
":"                       { count(); return(COLON_OP); }
"("                       { count(); return(OPENPAREN_OP); }
")"                       { count(); return(CLOSEPAREN_OP); }
("["|"<:")                { count(); return(OPENBRACE_OP); }
("]"|":>")                { count(); return(CLOSEBRACE_OP); }
"."                       { count(); return(PERIOD_OP); }
"~"             { count(); return(TILDE_OP); }

"="             { count(); return(EQUAL_OP); }
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
"<"             { count(); return(LESS_OP); }
">"             { count(); return(GE_OP); }
"<="            { count(); return(LE_OP); }
">="            { count(); return(GE_OP); }
"=="            { count(); return(EQ_OP); }
"!="            { count(); return(NE_OP); }
"!"             { count(); return(NOT_OP); }
"^"             { count(); return(XOR_OP); }
"&"             { count(); return(BIT_AND); }
"|"             { count(); return(BIT_OR); }

"-"             { count(); return(MINUS_OP); }
"+"             { count(); return(PLUS_OP); }
"*"             { count(); return(TIMES_OP); }
"/"             { count(); return(DIV_OP); }
"%"             { count(); return(MOD_OP); }

[ \t\v\n\f]     { }
.               { /* Add code to complain about unmatched characters */ }

%%

int yywrap(void)
{
    return 1;
}


void comment(void)
{
    char c, prev = 0;
  
    while ((c = input()) != 0)      /* (EOF maps to 0) */
    {
        if (c == '/' && prev == '*')
            return;
        prev = c;
    }
    yyerror("unterminated comment");
}

int handleIndentifier(int result) {
 memset(yylval.CompilerInfo.data.identifier,sizeof(yylval.CompilerInfo.data.identifier),0);
 strcpy(yylval.CompilerInfo.data.identifier, yytext);
 yylval.CompilerInfo.data.constant = (result==IDENTIFIER) ? (FALSE) : (TRUE);
 yylval.CompilerInfo.data.type = TYPE_NULL;
 return result;
}

void count(void)
{
    int i;

    for (i = 0; yytext[i] != '\0'; i++) 
        if (yytext[i] == '\n')
            column = 0;
        else if (yytext[i] == '\t')
            column += 8 - (column % 8);
        else
            column++;

    //ECHO;
}


int check_type(void)
{
    return IDENTIFIER;
}