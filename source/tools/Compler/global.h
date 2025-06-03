/*******************************************************************************
 * compiler: Declares the main interfaces of the library
 *
 * Copyright (C) 2025 Christopher D. Wade
 * <wade4615@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of STEWART HEITMANN nor the  names of its contributors
 *       may be used to endorse or promote products derived from this software
 *       without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL STEWART HEITMANN BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/
#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <io.h>

#define YY_NO_UNISTD_H
#define fileno _fileno
#define isatty _isatty

#define TRUE 1
#define FALSE 0
#define Boolean unsigned char

typedef enum _VariableSignType{
    TYPE_SIGNED = 0,
    TYPE_UNSIGNED = 1
} VariableSignType;

typedef enum _VariableType{
    TYPE_NULL = 0,
    TYPE_VOID = 1,
    TYPE_CHARACTER = 2,
    TYPE_SHORT = 3,
	TYPE_INTEGER = 4,
	TYPE_LONG = 5,
	TYPE_LONG64 = 6,
	TYPE_FLOAT = 7,
	TYPE_DOUBLE = 8,
	TYPE_STRING = 9,
	TYPE_STRUCT = 10,
	TYPE_BOOLEAN = 11,
	TYPE_COMPLEX = 12,
	TYPE_IMAGINARY = 13
} VariableType;

typedef enum _StorageType {
	STORAGE_NONE = 0,
	STORAGE_TYPEDEF = 1,
	STORAGE_EXTERN = 2,
	STORAGE_STATIC = 3,
	STORAGE_AUTO = 4,
	STORAGE_REGISTER = 5
} StorageType; 

typedef enum _DeclarationType {
    DECLARATION_NONE = 0,
	DECLARATION_VARIABLE = 1,
	DECLARATION_FUNCTION = 2
} DeclarationType; 

typedef enum _FunctionalType {
	RESERVED = 1,
	OPERATOR = 2,
	VARIABLE = 3,
    FUNCTION = 4, 
} FunctionalType; 

typedef struct _ExpressionNode {
  char *string;
  VariableType type;
  Boolean constant;
} ExpressionNode; 

typedef struct _Expression {
   ExpressionNode node;
   struct _Expression *left;
   struct _Expression *right;
} Expression,*ExpressionPtr; 

typedef struct _ExpressionList {
   Expression expression;
   struct _ExpressionList *next;
} ExpressionList,*ExpressionListPtr; 

typedef struct _Declaration {
   char *identifier;     
   VariableType type;
   VariableSignType sign;
   StorageType storage;
   DeclarationType declarationType;
} Declaration,*DeclarationPtr; 

typedef struct _DeclarationList {
   DeclarationPtr var;
   struct _DeclarationList *next;
} DeclarationList,*DeclarationListPtr; 

int yylex();
int yyparse();
int yywrap();
void comment();
void count();
int check_type();
void yyerror(const char* s);
int handleIndentifier();

void addToSymbolTable(char *identifier, VariableType type, VariableSignType sign, StorageType storage, DeclarationType declarationType, Boolean constant); 

extern DeclarationListPtr symbolTable;
extern FILE * fileLexLog;
extern int num_errors;
extern int yylineno;
extern int column;
extern int num_errors;
extern FILE* yyin;
extern FILE* yyout;

#endif