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
    #include <iostream>
    #include <cstdlib>
    #include <stdlib.h>
    #include "TokenType.h"
    #define YY_NO_UNISTD_H
    #include "scanner.h"
    #include "interpreter.h"
    #include "parser.hpp"
    #include "location.hh"

    using namespace std;

    // Original yyterminate() macro returns int. Since we're using Bison 3 variants
    // as tokens, we must redefine it to change type from `int` to `Parser::semantic_type`
    #define yyterminate() WadeSpace::Parser::make_END(WadeSpace::location());

    // This will track current scanner location.
    // Action is called when length of the token is known.
    #define YY_USER_ACTION m_driver.increaseLocation(yyleng);
    
    // !!!WARNING!!!
    // Location API is used, but the location is not initialized, 'cause I'm lazy. When making
    // a token with make_{something} method you can pass detailed token location. Current location
    // is accessible with m_driver.location() method. All puzzle elements are there - just
    // pass location value in every action code block below. I'm going to waste more time writing
    // this excuse than putting this boilerplate below...
    //
    // Location class can be found in location.hh and posistion.hh files. It's just a bit too much
    // boilerplate for this small example. Bummer.
%}

%option nodefault
%option noyywrap
%option c++
%option yyclass="Scanner"
%option prefix="WadeSpace_"

%%

"auto"         { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_AUTO(AUTO, WadeSpace::location()); 
               }               
"break"        { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_BREAK(BREAK, WadeSpace::location()); 
               }
"case"         { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_CASE(CASE, WadeSpace::location()); 
               }
"char"         { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_CHAR(CHAR, WadeSpace::location()); 
               }
"const"        { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_CONST(CONST, WadeSpace::location()); 
               }
"continue"     { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_CONTINUE(CONTINUE, WadeSpace::location()); 
               }
"default"      { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_DEFAULT(DEFAULT, WadeSpace::location()); 
               }
"do"           { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_DO(DO, WadeSpace::location()); 
               }
"double"       { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_DOUBLE(DOUBLE, WadeSpace::location()); 
               }
"long double"  { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_LONG_DOUBLE(LONG_DOUBLE, WadeSpace::location()); 
               }
"else"         { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_ELSE(ELSE, WadeSpace::location()); 
               }
"enum"         { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_ENUM(ENUM, WadeSpace::location()); 
               }
"extern"       { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_EXTERN(EXTERN, WadeSpace::location()); 
               }
"float"        { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_FLOAT(FLOAT, WadeSpace::location()); 
               }
"for"          { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_FOR(FOR, WadeSpace::location()); 
               }
"goto"         { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_GOTO(GOTO, WadeSpace::location()); 
               }
"if"           { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_IF(IF, WadeSpace::location()); 
               }
"inline"       { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_INLINE(INLINE, WadeSpace::location()); 
               }
"int"          { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_INT(INT, WadeSpace::location()); 
               }
"long"         { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_LONG(LONG, WadeSpace::location()); 
               }
"long long"    { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_LONG_LONG(LONG_LONG, WadeSpace::location()); 
               }
"register"     { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_REGISTER(REGISTER, WadeSpace::location()); 
               }
"restrict"     { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_RESTRICT(RESTRICT, WadeSpace::location()); 
               }
"return"       { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_RETURN(RETURN, WadeSpace::location()); 
               }
"short"        { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_SHORT(SHORT, WadeSpace::location()); 
               }
"signed"       { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_SIGNED(SIGNED, WadeSpace::location()); 
               }
"sizeof"       { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_SIZEOF(SIZEOF, WadeSpace::location()); 
               }
"static"       { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_STATIC(STATIC, WadeSpace::location()); 
               }
"struct"       { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_STRUCT(STRUCT, WadeSpace::location()); 
               }
"switch"       { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_SWITCH(SWITCH, WadeSpace::location()); 
               }
"typedef"      { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_TYPEDEF(TYPEDEF, WadeSpace::location()); 
               }
"union"        { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_UNION(UNION, WadeSpace::location()); 
               }
"unsigned"     { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_UNSIGNED(UNSIGNED, WadeSpace::location()); 
               }
"void"         { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_VOID(VOID, WadeSpace::location()); 
               }
"volatile"     { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_VOLATILE(VOLATILE, WadeSpace::location()); 
               }
"while"        { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_WHILE(WHILE, WadeSpace::location()); 
               }
"bool"         { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_BOOL(BOOL, WadeSpace::location()); 
               }
"complex"      { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_COMPLEX(COMPLEX, WadeSpace::location()); 
               }
"imaginary"    { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_IMAGINARY(IMAGINARY, WadeSpace::location()); 
               }

{L}{A}*        { 
                cout << "Scanner: identifier [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_IDENTIFIER(yytext, WadeSpace::location()); 
               }
{HP}{H}+{IS}?  {
                cout << "Scanner: decimal number: " << yytext << endl;
                uint64_t number = strtoull(yytext, 0, 10);
                return WadeSpace::Parser::make_I_CONST(number, WadeSpace::location());
               }
{NZ}{D}*{IS}?  {
                cout << "Scanner: decimal number: " << yytext << endl;
                uint64_t number = strtoull(yytext, 0, 10);
                return WadeSpace::Parser::make_I_CONST(number, WadeSpace::location());
               }
"0"{O}*{IS}?   {
                cout << "Scanner: decimal number: " << yytext << endl;
                uint64_t number = strtoull(yytext, 0, 10);
                return WadeSpace::Parser::make_I_CONST(number, WadeSpace::location());
               }
{CP}?"'"([^'\\\n]|{ES})+"'"  {
                cout << "Scanner: decimal number: " << yytext << endl;
                uint64_t number = strtoull(yytext, 0, 10);
                return WadeSpace::Parser::make_I_CONST(number, WadeSpace::location());
               }
{D}+{E}{FS}?  {              
                cout << "Scanner: decimal number: " << yytext << endl;
                long double number = strtold(yytext, NULL);
                return WadeSpace::Parser::make_F_CONST(number, WadeSpace::location());
               }
{D}*"."{D}+{E}?{FS}? {              
                cout << "Scanner: decimal number: " << yytext << endl;
                long double number = strtold(yytext, NULL);
                return WadeSpace::Parser::make_F_CONST(number, WadeSpace::location());
               }
{D}+"."{E}?{FS}? {              
                cout << "Scanner: decimal number: " << yytext << endl;
                long double number = strtold(yytext, NULL);
                return WadeSpace::Parser::make_F_CONST(number, WadeSpace::location());
               }
{HP}{H}+{P}{FS}? {              
                cout << "Scanner: decimal number: " << yytext << endl;
                long double number = strtold(yytext, NULL);
                return WadeSpace::Parser::make_F_CONST(number, WadeSpace::location());
               }
{HP}{H}*"."{H}+{P}{FS}? {              
                cout << "Scanner: decimal number: " << yytext << endl;
                long double number = strtold(yytext, NULL);
                return WadeSpace::Parser::make_F_CONST(number, WadeSpace::location());
               }
{HP}{H}+"."{P}{FS}? {              
                cout << "Scanner: decimal number: " << yytext << endl;
                long double number = strtold(yytext, NULL);
                return WadeSpace::Parser::make_F_CONST(number, WadeSpace::location());
               }

({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+   { 
                cout << "Scanner: string literal [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_STRING_LITERAL(yytext, WadeSpace::location()); 
               }               

"..."          {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_ELLIPSIS(ELLIPSIS,WadeSpace::location());
               }
"?"            {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_QUESTION(QUESTION,WadeSpace::location());
               }
";"            {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_SEMICOLON(SEMICOLON,WadeSpace::location());
               }
"{"            {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_OCURLY(OCURLY,WadeSpace::location());
               }
"}"            {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_CCURLY(CCURLY,WadeSpace::location());
               }
","            {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_COMMA(COMMA,WadeSpace::location());
               }
":"            {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_COLON(COLON,WadeSpace::location());
               }
"("            {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_OPAREN(OPAREN,WadeSpace::location());
               }
")"            {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_CPAREN(CPAREN,WadeSpace::location());
               }
"["            {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_OBRACE(OBRACE,WadeSpace::location());
               }
"]"            {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_CBRACE(CBRACE,WadeSpace::location());
               }
"."            {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_PERIOD(PERIOD,WadeSpace::location());
               }
"~"            {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_TILDE(TILDE,WadeSpace::location());
               }
"="            {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_EQUAL(EQUAL,WadeSpace::location());
               }
">>="          {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_RIGHT_ASSIGN(RIGHT_ASSIGN,WadeSpace::location());
               }
"<<="          {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_LEFT_ASSIGN(LEFT_ASSIGN,WadeSpace::location());
               }
"+="           {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_ADD_ASSIGN(ADD_ASSIGN,WadeSpace::location());
               }
"-="           {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_SUB_ASSIGN(SUB_ASSIGN,WadeSpace::location());
               }
"*="           {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_MUL_ASSIGN(MUL_ASSIGN,WadeSpace::location());
               }
"/="           {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_DIV_ASSIGN(DIV_ASSIGN,WadeSpace::location());
               }
"%="           {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_MOD_ASSIGN(MOD_ASSIGN,WadeSpace::location());
               }
"&="           {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_AND_ASSIGN(AND_ASSIGN,WadeSpace::location());
               }
"^="           {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_XOR_ASSIGN(XOR_ASSIGN,WadeSpace::location());
               }
"|="           {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_OR_ASSIGN(OR_ASSIGN,WadeSpace::location());
               }
">>"           {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_RIGHT_OP(RIGHT_OP,WadeSpace::location());
               }
"<<"           {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_LEFT_OP(LEFT_OP,WadeSpace::location());
               }
"++"           {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_INC_OP(INC_OP,WadeSpace::location());
               }
"--"           {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_DEC_OP(DEC_OP,WadeSpace::location());
               }
"->"           { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_PTR_OP(PTR_OP,WadeSpace::location());
               }
"&&"           {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_AND_OP(AND_OP,WadeSpace::location());
               }
"||"           {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_OR_OP(OR_OP,WadeSpace::location());
               }
"<"            {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_LESS(LESS,WadeSpace::location());
               }
">"            {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_GREATER(GREATER,WadeSpace::location());
               }
"<="           {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_LESS_EQUAL(LESS_EQUAL,WadeSpace::location());
               }
">="           {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_GREATER_EQUAL(GREATER_EQUAL,WadeSpace::location());
               }
"=="           {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_EQUAL_EQUAL(EQUAL_EQUAL,WadeSpace::location());
               }
"!="           {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_NOT_EQUAL(NOT_EQUAL,WadeSpace::location());
               }
"!"            {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_NOT_OP(NOT_OP,WadeSpace::location());
               }
"^"            {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_XOR_OP(XOR_OP,WadeSpace::location());
               }
"&"            {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_BIT_AND(BIT_AND,WadeSpace::location());
               }
"|"            {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_BIT_OR(BIT_OR,WadeSpace::location());
               }
"-"            {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_MINUS_OP(MINUS_OP,WadeSpace::location());
               }
"+"            {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_PLUS_OP(PLUS_OP,WadeSpace::location());
               }
"*"            {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_TIMES_OP(TIMES_OP,WadeSpace::location());
               }
"/"            {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_DIV_OP(DIV_OP,WadeSpace::location());
               }
"%"            {
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_MOD_OP(MOD_OP,WadeSpace::location());
               }
\"[^"]*\"      { cout << "Scanner: multiline comment [" << yytext << "]" << endl;  }
"//".*         { cout << "Scanner: single line comment [" << yytext << "]" << endl;  }
[ \t\v\n\f]    { }
.              { 
                cout << "Scanner: unknown character [" << yytext << "]" << endl; 
               }           
<<EOF>>     { return yyterminate(); }

%%
