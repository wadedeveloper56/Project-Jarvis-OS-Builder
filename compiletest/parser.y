%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.0"
%defines
%define  api.parser.class { Parser }

%define api.token.constructor
%define api.value.type variant
%define parse.assert
%define api.namespace { WadeSpace }
%code requires
{
    #include <iostream>
    #include <string>
    #include <vector>
    #include <stdint.h>
    #include <stdlib.h>
    #include "command.h"

    using namespace std;

    namespace WadeSpace {
        class Scanner;
        class Interpreter;
    }
}

// Bison calls yylex() function that must be provided by us to suck tokens
// from the scanner. This block will be placed at the beginning of IMPLEMENTATION file (cpp).
// We define this function here (function! not method).
// This function is called only inside Bison, so we make it static to limit symbol visibility for the linker
// to avoid potential linking conflicts.
%code top
{
    #include <iostream>
    #include <stdlib.h>
    #include "scanner.h"
    #include "parser.hpp"
    #include "interpreter.h"
    #include "location.hh"
    
    // yylex() arguments are defined in parser.y
    static WadeSpace::Parser::symbol_type yylex(WadeSpace::Scanner &scanner, WadeSpace::Interpreter &driver) {
        return scanner.get_next_token();
    }
    
    // you can accomplish the same thing by inlining the code using preprocessor
    // x and y are same as in above static function
    // #define yylex(x, y) scanner.get_next_token()
    
    using namespace WadeSpace;
}

%lex-param { WadeSpace::Scanner &scanner }
%lex-param { WadeSpace::Interpreter &driver }
%parse-param { WadeSpace::Scanner &scanner }
%parse-param { WadeSpace::Interpreter &driver }
%locations
%define parse.trace
%define parse.error verbose

%define api.token.prefix {TOKEN_}

%token END 0 "end of file"
%token <std::string> IDENTIFIER  "identifier";
%token <uint64_t> I_CONST "i_const";
%token <long double> F_CONST "f_const";
%token <std::string> STRING_LITERAL  "sting_literal";
%token LEFTPAR "leftpar";
%token RIGHTPAR "rightpar";
%token SEMICOLON "semicolon";
%token COMMA "comma";

%type< WadeSpace::Command > command;
%type< std::vector<uint64_t> > arguments;

%start program

%%

program :   {
                cout << "*** RUN ***" << endl;
                cout << "Type function with list of parmeters. Parameter list can be empty" << endl
                     << "or contain positive integers only. Examples: " << endl
                     << " * function()" << endl
                     << " * function(1,2,3)" << endl
                     << "Terminate listing with ; to see parsed AST" << endl
                     << "Terminate parser with Ctrl-D" << endl;
                
                cout << endl << "prompt> ";
                
                driver.clear();
            }
        | program command
            {
                const Command &cmd = $2;
                cout << "command parsed, updating AST" << endl;
                driver.addCommand(cmd);
                cout << endl << "prompt> ";
            }
        | program SEMICOLON
            {
                cout << "*** STOP RUN ***" << endl;
                cout << driver.str() << endl;
            }
        ;


command : IDENTIFIER LEFTPAR RIGHTPAR
        {
            string &id = $1;
            cout << "ID: " << id << endl;
            $$ = Command(id);
        }
    | IDENTIFIER LEFTPAR arguments RIGHTPAR
        {
            string &id = $1;
            const std::vector<uint64_t> &args = $3;
            cout << "function: " << id << ", " << args.size() << endl;
            $$ = Command(id, args);
        }
    ;


arguments : I_CONST
        {
            uint64_t number = $1;
            $$ = std::vector<uint64_t>();
            $$.push_back(number);
            cout << "first argument: " << number << endl;
        }
    | arguments COMMA I_CONST
        {
            uint64_t number = $3;
            std::vector<uint64_t> &args = $1;
            args.push_back(number);
            $$ = args;
            cout << "next argument: " << number << ", arg list size = " << args.size() << endl;
        }
    ;
    
%%

// Bison expects us to provide implementation - otherwise linker complains
void WadeSpace::Parser::error(const location &loc , const std::string &message) {
        
        // Location should be initialized inside scanner action, but is not in this example.
        // Let's grab location directly from driver class.
    // cout << "Error: " << message << endl << "Location: " << loc << endl;
    
        cout << "Error: " << message << endl << "Error location: " << driver.location() << endl;
}
