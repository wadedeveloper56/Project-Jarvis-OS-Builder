/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2014 Krzysztof Narkiewicz <krzysztof.narkiewicz@WadeSpace.com>
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 * 
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
    #include <iostream>
    #include <cstdlib>
    #include <stdlib.h>
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
    /*
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
*/

%}

%option nodefault
%option noyywrap
%option c++
%option yyclass="Scanner"
%option prefix="WadeSpace_"

%%


"auto"         { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_AUTO(yytext, WadeSpace::location()); 
               }               
"break"        { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_BREAK(yytext, WadeSpace::location()); 
               }
"case"         { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_CASE(yytext, WadeSpace::location()); 
               }
"char"         { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_CHAR(yytext, WadeSpace::location()); 
               }
"const"        { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_CONST(yytext, WadeSpace::location()); 
               }
"continue"     { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_CONTINUE(yytext, WadeSpace::location()); 
               }
"default"      { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_DEFAULT(yytext, WadeSpace::location()); 
               }
"do"           { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_DO(yytext, WadeSpace::location()); 
               }
"double"       { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_DOUBLE(yytext, WadeSpace::location()); 
               }
"long double"  { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_LONG_DOUBLE(yytext, WadeSpace::location()); 
               }
"else"         { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_ELSE(yytext, WadeSpace::location()); 
               }
"enum"         { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_ENUM(yytext, WadeSpace::location()); 
               }
"extern"       { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_EXTERN(yytext, WadeSpace::location()); 
               }
"float"        { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_FLOAT(yytext, WadeSpace::location()); 
               }
"for"          { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_FOR(yytext, WadeSpace::location()); 
               }
"goto"         { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_GOTO(yytext, WadeSpace::location()); 
               }
"if"           { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_IF(yytext, WadeSpace::location()); 
               }
"inline"       { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_INLINE(yytext, WadeSpace::location()); 
               }
"int"          { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_INT(yytext, WadeSpace::location()); 
               }
"long"         { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_LONG(yytext, WadeSpace::location()); 
               }
"long long"    { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_LONG_LONG(yytext, WadeSpace::location()); 
               }
"register"     { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_REGISTER(yytext, WadeSpace::location()); 
               }
"restrict"     { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_RESTRICT(yytext, WadeSpace::location()); 
               }
"return"       { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_RETURN(yytext, WadeSpace::location()); 
               }
"short"        { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_SHORT(yytext, WadeSpace::location()); 
               }
"signed"       { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_SIGNED(yytext, WadeSpace::location()); 
               }
"sizeof"       { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_SIZEOF(yytext, WadeSpace::location()); 
               }
"static"       { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_STATIC(yytext, WadeSpace::location()); 
               }
"struct"       { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_STRUCT(yytext, WadeSpace::location()); 
               }
"switch"       { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_SWITCH(yytext, WadeSpace::location()); 
               }
"typedef"      { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_TYPEDEF(yytext, WadeSpace::location()); 
               }
"union"        { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_UNION(yytext, WadeSpace::location()); 
               }
"unsigned"     { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_UNSIGNED(yytext, WadeSpace::location()); 
               }
"void"         { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_VOID(yytext, WadeSpace::location()); 
               }
"volatile"     { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_VOLATILE(yytext, WadeSpace::location()); 
               }
"while"        { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_WHILE(yytext, WadeSpace::location()); 
               }
"bool"         { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_BOOL(yytext, WadeSpace::location()); 
               }
"complex"      { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_COMPLEX(yytext, WadeSpace::location()); 
               }
"imaginary"    { 
                cout << "Scanner: token [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_IMAGINARY(yytext, WadeSpace::location()); 
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

\(          {
                cout << "Scanner: '('" << endl;
                return WadeSpace::Parser::make_LEFTPAR(WadeSpace::location());
            }
            
\)          { 
                cout << "Scanner: ')'" << endl;
                return WadeSpace::Parser::make_RIGHTPAR(WadeSpace::location());
            }

;           {
                cout << "Scanner: ';'" << endl;
                return WadeSpace::Parser::make_SEMICOLON(";",WadeSpace::location());
            }

.           { 
                cout << "Scanner: unknown character [" << yytext << "]" << endl; 
            }
            
<<EOF>>     { return yyterminate(); }

%%