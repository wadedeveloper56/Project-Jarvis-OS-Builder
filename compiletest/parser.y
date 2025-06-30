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

%token <std::string> SEMICOLON "semicolon";
%token <std::string> AUTO "auto";
%token <std::string> BREAK "break";
%token <std::string> CASE "case";
%token <std::string> CHAR "char";
%token <std::string> CONST "const"
%token <std::string> CONTINUE "continue"
%token <std::string> DEFAULT "default"
%token <std::string> DO "do"
%token <std::string> DOUBLE "double"
%token <std::string> LONG_DOUBLE "long double"
%token <std::string> ELSE "else"
%token <std::string> ENUM "enum"
%token <std::string> EXTERN "extern"
/*
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
%start translation_unit

%%

translation_unit 
        :   {}
        |   translation_unit command {}
        |   translation_unit SEMICOLON {}
        ;

command 
        : IDENTIFIER LEFTPAR RIGHTPAR {}
        ;
    
%%

// Bison expects us to provide implementation - otherwise linker complains
void WadeSpace::Parser::error(const location &loc , const std::string &message) {
        
        // Location should be initialized inside scanner action, but is not in this example.
        // Let's grab location directly from driver class.
    // cout << "Error: " << message << endl << "Location: " << loc << endl;
    
        cout << "Error: " << message << endl << "Error location: " << driver.location() << endl;
}
