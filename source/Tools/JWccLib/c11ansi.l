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
#include "pch.h"
#include "jcc.h"

extern void yyerror(const char *);  /* prints grammar violation message */
static void comment(void);
static int check_type(void);
%}

%option bison-bridge

%%
"/*"                                { comment(); }
"//".*                              { /* consume //-comment */ }
"auto"                              { yylval->token = createKeywordToken(yytext,Y_AUTO); return(Y_AUTO); }
"break"                             { yylval->token = createKeywordToken(yytext,Y_BREAK); return(Y_BREAK); }
"case"                              { yylval->token = createKeywordToken(yytext,Y_CASE); return(Y_CASE); }
"char"                              { yylval->token = createKeywordToken(yytext,Y_CHAR); return(Y_CHAR); }
"const"                             { yylval->token = createKeywordToken(yytext,Y_CONST); return(Y_CONST); }
"continue"                          { yylval->token = createKeywordToken(yytext,Y_CONTINUE); return(Y_CONTINUE); }
"default"                           { yylval->token = createKeywordToken(yytext,Y_DEFAULT); return(Y_DEFAULT); }
"do"                                { yylval->token = createKeywordToken(yytext,Y_DO); return(Y_DO); }
"double"                            { yylval->token = createKeywordToken(yytext,Y_DOUBLE); return(Y_DOUBLE); }
"long double"                       { yylval->token = createKeywordToken(yytext,Y_LONG_DOUBLE); return(Y_LONG_DOUBLE); }
"else"                              { yylval->token = createKeywordToken(yytext,Y_ELSE); return(Y_ELSE); }
"enum"                              { yylval->token = createKeywordToken(yytext,Y_ENUM); return(Y_ENUM); }
"extern"                            { yylval->token = createKeywordToken(yytext,Y_EXTERN); return(Y_EXTERN); }
"float"                             { yylval->token = createKeywordToken(yytext,Y_FLOAT); return(Y_FLOAT); }
"for"                               { yylval->token = createKeywordToken(yytext,Y_FOR); return(Y_FOR); }
"goto"                              { yylval->token = createKeywordToken(yytext,Y_GOTO); return(Y_GOTO); }
"if"                                { yylval->token = createKeywordToken(yytext,Y_IF); return(Y_IF); }
"inline"                            { yylval->token = createKeywordToken(yytext,Y_INLINE); return(Y_INLINE); }
"int"                               { yylval->token = createKeywordToken(yytext,Y_INT); return(Y_INT); }
"long"                              { yylval->token = createKeywordToken(yytext,Y_LONG); return(Y_LONG); }
"long long"                         { yylval->token = createKeywordToken(yytext,Y_LONG_LONG); return(Y_LONG_LONG); }
"register"                          { yylval->token = createKeywordToken(yytext,Y_REGISTER); return(Y_REGISTER); }
"restrict"                          { yylval->token = createKeywordToken(yytext,Y_RESTRICT); return(Y_RESTRICT); }
"return"                            { yylval->token = createKeywordToken(yytext,Y_RETURN); return(Y_RETURN); }
"short"                             { yylval->token = createKeywordToken(yytext,Y_SHORT); return(Y_SHORT); }
"signed"                            { yylval->token = createKeywordToken(yytext,Y_SIGNED); return(Y_SIGNED); }
"sizeof"                            { yylval->token = createKeywordToken(yytext,Y_SIZEOF); return(Y_SIZEOF); }
"static"                            { yylval->token = createKeywordToken(yytext,Y_STATIC); return(Y_STATIC); }
"struct"                            { yylval->token = createKeywordToken(yytext,Y_STRUCT); return(Y_STRUCT); }
"switch"                            { yylval->token = createKeywordToken(yytext,Y_SWITCH); return(Y_SWITCH); }
"typedef"                           { yylval->token = createKeywordToken(yytext,Y_TYPEDEF); return(Y_TYPEDEF); }
"union"                             { yylval->token = createKeywordToken(yytext,Y_UNION); return(Y_UNION); }
"unsigned"                          { yylval->token = createKeywordToken(yytext,Y_UNSIGNED); return(Y_UNSIGNED); }
"void"                              { yylval->token = createKeywordToken(yytext,Y_VOID); return(Y_VOID); }
"volatile"                          { yylval->token = createKeywordToken(yytext,Y_VOLATILE); return(Y_VOLATILE); }
"while"                             { yylval->token = createKeywordToken(yytext,Y_WHILE); return(Y_WHILE); }
"_Alignas"                          { yylval->token = createKeywordToken(yytext,Y_ALIGNAS); return Y_ALIGNAS; }
"_Alignof"                          { yylval->token = createKeywordToken(yytext,Y_ALIGNOF); return Y_ALIGNOF; }
"_Atomic"                           { yylval->token = createKeywordToken(yytext,Y_ATOMIC); return Y_ATOMIC; }
"bool"                              { yylval->token = createKeywordToken(yytext,Y_BOOL); return Y_BOOL; }
"complex"                           { yylval->token = createKeywordToken(yytext,Y_COMPLEX); return Y_COMPLEX; }
"_Generic"                          { yylval->token = createKeywordToken(yytext,Y_GENERIC); return Y_GENERIC; }
"imaginary"                         { yylval->token = createKeywordToken(yytext,Y_IMAGINARY); return Y_IMAGINARY; }
"_Noreturn"                         { yylval->token = createKeywordToken(yytext,Y_NORETURN); return Y_NORETURN; }
"_Static_assert"                    { yylval->token = createKeywordToken(yytext,Y_STATIC_ASSERT); return Y_STATIC_ASSERT; }
"_Thread_local"                     { yylval->token = createKeywordToken(yytext,Y_THREAD_LOCAL); return Y_THREAD_LOCAL; }
"__func__"                          { yylval->token = createKeywordToken(yytext,Y_FUNC_NAME); return Y_FUNC_NAME; }
{L}{A}*                             { yylval->token = createStringIDToken(yytext); return IDENTIFIER; }
{HP}{H}+{IS}?                       { yylval->token = createConstantULLToken(strtoull(yytext, 0, 10)); return I_CONSTANT; }
{NZ}{D}*{IS}?                       { yylval->token = createConstantULLToken(strtoull(yytext, 0, 10)); return I_CONSTANT; }
"0"{O}*{IS}?                        { yylval->token = createConstantULLToken(strtoull(yytext, 0, 10)); return I_CONSTANT; }
{CP}?"'"([^'\\\n]|{ES})+"'"         { yylval->token = createConstantULLToken(strtoull(yytext, 0, 10)); return I_CONSTANT; }
{D}+{E}{FS}?                        { yylval->token = createConstantLDToken(strtold(yytext, NULL)); return F_CONSTANT; }
{D}*"."{D}+{E}?{FS}?                { yylval->token = createConstantLDToken(strtold(yytext, NULL)); return F_CONSTANT; }
{D}+"."{E}?{FS}?                    { yylval->token = createConstantLDToken(strtold(yytext, NULL)); return F_CONSTANT; }
{HP}{H}+{P}{FS}?                    { yylval->token = createConstantLDToken(strtold(yytext, NULL)); return F_CONSTANT; }
{HP}{H}*"."{H}+{P}{FS}?             { yylval->token = createConstantLDToken(strtold(yytext, NULL)); return F_CONSTANT; }
{HP}{H}+"."{P}{FS}?                 { yylval->token = createConstantLDToken(strtold(yytext, NULL)); return F_CONSTANT; }
({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+   { yylval->token = createStringConstantToken(yytext); return STRING_LITERAL; }
"..."                               { yylval->token = createKeywordToken(yytext,Y_DOT_DOT_DOT); return Y_DOT_DOT_DOT; }
">>="                               { yylval->token = createKeywordToken(yytext,Y_RSHIFT_EQUAL); return Y_RSHIFT_EQUAL; }
"<<="                               { yylval->token = createKeywordToken(yytext,Y_LSHIFT_EQUAL); return Y_LSHIFT_EQUAL; }
"+="                                { yylval->token = createKeywordToken(yytext,Y_PLUS_EQUAL); return Y_PLUS_EQUAL; }
"-="                                { yylval->token = createKeywordToken(yytext,Y_MINUS_EQUAL); return Y_MINUS_EQUAL; }
"*="                                { yylval->token = createKeywordToken(yytext,Y_TIMES_EQUAL); return Y_TIMES_EQUAL; }
"/="                                { yylval->token = createKeywordToken(yytext,Y_DIVIDE_EQUAL); return Y_DIVIDE_EQUAL; }
"%="                                { yylval->token = createKeywordToken(yytext,Y_PERCENT_EQUAL); return Y_PERCENT_EQUAL; }
"&="                                { yylval->token = createKeywordToken(yytext,Y_AND_EQUAL); return Y_AND_EQUAL; }
"^="                                { yylval->token = createKeywordToken(yytext,Y_XOR_EQUAL); return Y_XOR_EQUAL; }
"|="                                { yylval->token = createKeywordToken(yytext,Y_OR_EQUAL); return Y_OR_EQUAL; }
">>"                                { yylval->token = createKeywordToken(yytext,Y_RSHIFT); return Y_RSHIFT; }
"<<"                                { yylval->token = createKeywordToken(yytext,Y_LSHIFT); return Y_LSHIFT; }
"++"                                { yylval->token = createKeywordToken(yytext,Y_PLUS_PLUS); return Y_PLUS_PLUS; }
"--"                                { yylval->token = createKeywordToken(yytext,Y_MINUS_MINUS); return Y_MINUS_MINUS; }
"->"                                { yylval->token = createKeywordToken(yytext,Y_ARROW); return Y_ARROW; }
"&&"                                { yylval->token = createKeywordToken(yytext,Y_AND_AND); return Y_AND_AND; }
"||"                                { yylval->token = createKeywordToken(yytext,Y_OR_OR); return Y_OR_OR; }
"<="                                { yylval->token = createKeywordToken(yytext,Y_LE); return Y_LE; }
">="                                { yylval->token = createKeywordToken(yytext,Y_GE); return Y_GE; }
"=="                                { yylval->token = createKeywordToken(yytext,Y_EQ); return Y_EQ; }
"!="                                { yylval->token = createKeywordToken(yytext,Y_NE); return Y_NE; }
";"	                                { yylval->token = createKeywordToken(yytext,Y_SEMICOLON); return Y_SEMICOLON; }
"{"                                 { yylval->token = createKeywordToken(yytext,Y_LEFT_BRACE); return Y_LEFT_BRACE; }
"}"                                 { yylval->token = createKeywordToken(yytext,Y_RIGHT_BRACE); return Y_RIGHT_BRACE; }
","	                                { yylval->token = createKeywordToken(yytext,Y_COMMA); return Y_COMMA; }
":"	                                { yylval->token = createKeywordToken(yytext,Y_COLON); return Y_COLON; }
"="	                                { yylval->token = createKeywordToken(yytext,Y_EQUAL); return Y_EQUAL; }
"("	                                { yylval->token = createKeywordToken(yytext,Y_LEFT_PAREN); return Y_LEFT_PAREN; }
")"	                                { yylval->token = createKeywordToken(yytext,Y_RIGHT_PAREN); return Y_RIGHT_PAREN; }
"["                                 { yylval->token = createKeywordToken(yytext,Y_LEFT_BRACKET); return Y_LEFT_BRACKET; }
"]"                                 { yylval->token = createKeywordToken(yytext,Y_RIGHT_BRACKET); return Y_RIGHT_BRACKET; }
"."	                                { yylval->token = createKeywordToken(yytext,Y_DOT); return Y_DOT; }
"&"	                                { yylval->token = createKeywordToken(yytext,Y_AND); return Y_AND; }
"!"	                                { yylval->token = createKeywordToken(yytext,Y_EXCLAMATION); return Y_EXCLAMATION; }
"~"	                                { yylval->token = createKeywordToken(yytext,Y_TILDE); return Y_TILDE; }
"-"	                                { yylval->token = createKeywordToken(yytext,Y_MINUS); return Y_MINUS; }
"+"	                                { yylval->token = createKeywordToken(yytext,Y_PLUS); return Y_PLUS; }
"*"	                                { yylval->token = createKeywordToken(yytext,Y_TIMES); return Y_TIMES; }
"/"	                                { yylval->token = createKeywordToken(yytext,Y_DIVIDE); return Y_DIVIDE; }
"%"	                                { yylval->token = createKeywordToken(yytext,Y_PERCENT); return Y_PERCENT; }
"<"	                                { yylval->token = createKeywordToken(yytext,Y_LT); return Y_LT; }
">"	                                { yylval->token = createKeywordToken(yytext,Y_GT); return Y_GT; }
"^"	                                { yylval->token = createKeywordToken(yytext,Y_XOR); return Y_XOR; }
"|"	                                { yylval->token = createKeywordToken(yytext,Y_OR); return Y_OR; }
"?"	                                { yylval->token = createKeywordToken(yytext,Y_QUESTION); return Y_QUESTION; }

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
