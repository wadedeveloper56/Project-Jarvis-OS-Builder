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
%}

%option nodefault
%option noyywrap
%option c++
%option yyclass="Scanner"
%option prefix="WadeSpace_"

%%


{L}{A}*        { 
                cout << "Scanner: identifier [" << yytext << "]" << endl;
                return WadeSpace::Parser::make_IDENTIFIER(yytext, WadeSpace::location( /* put location data here if you want */ )); 
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
                return WadeSpace::Parser::make_STRING_LITERAL(yytext, WadeSpace::location( /* put location data here if you want */ )); 
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
                return WadeSpace::Parser::make_SEMICOLON(WadeSpace::location());
            }
            
,           {
                cout << "Scanner: ','" << endl;
                return WadeSpace::Parser::make_COMMA(WadeSpace::location());
            }
            
[\n\t ]     {
                //cout << "Scanner: whitechar (ignored)" << endl;
            }

.           { 
                cout << "Scanner: unknown character [" << yytext << "]" << endl; 
            }
            
<<EOF>>     { return yyterminate(); }


%%
