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
#include <errno.h>
#include <io.h>

#define YY_NO_UNISTD_H
#define fileno _fileno
#define isatty _isatty

#define TRUE 1
#define FALSE 0
#define Boolean unsigned char

typedef enum _VariableSignType {
	TYPE_SIGNED = 0,
	TYPE_UNSIGNED = 1
} VariableSignType;
extern char* VariableSignName[];

typedef enum _VariableType {
	TYPE_NULL = 0,
	TYPE_VOID = 1,
	TYPE_CHARACTER = 2,
	TYPE_SHORT = 3,
	TYPE_INTEGER = 4,
	TYPE_LONG = 5,
	TYPE_LONG64 = 6,
	TYPE_FLOAT = 7,
	TYPE_DOUBLE = 8,
	TYPE_LONGDOUBLE = 9,
	TYPE_STRING = 10,
	TYPE_STRUCT = 11,
	TYPE_BOOLEAN = 12,
	TYPE_COMPLEX = 13,
	TYPE_IMAGINARY = 14
} VariableType;
extern char* VariableTypeName[];

typedef enum _StorageType {
	STORAGE_NONE = 0,
	STORAGE_TYPEDEF = 1,
	STORAGE_EXTERN = 2,
	STORAGE_STATIC = 3,
	STORAGE_AUTO = 4,
	STORAGE_REGISTER = 5
} StorageType;
extern char* VariableStorageName[];

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

typedef struct _IdentifierData {
	char identifier[256];
	VariableType type;
	VariableSignType sign;
	StorageType storage;
	DeclarationType declarationType;
	Boolean constant;
	int pointerLevel;
}IdentifierData, * IdentifierDataPtr, ** IdentifierDataPtrPtr;

typedef struct _ExpressionNode {
	IdentifierData data;
} ExpressionNode, * ExpressionBodePtr, ** ExprressionNodePtrPtr;

typedef struct _Expression {
	ExpressionNode node;
	struct _Expression* next;
} Expression, * ExpressionPtr, ** ExprressionPtrPtr;

typedef struct _ExpressionList {
	Expression expression;
	struct _ExpressionList* next;
} ExpressionList, * ExpressionListPtr, ** ExpressionListPtrPtr;

typedef struct _ParameterListNode {
	IdentifierData data;
	ExpressionListPtr arrayExpression;
	struct _ParameterListNode* next;
}ParameterListNode, * ParameterListNodePtr, ** ParameterListNodePtrPtr;

typedef struct _Declaration {
	IdentifierData data;
	ExpressionListPtr arrayExpression;
	struct _ParameterListNode* parameterList;
} Declaration, * DeclarationPtr;

typedef struct _DeclarationList {
	Declaration declaration;
	struct _DeclarationList* next;
} DeclarationList, * DeclarationListPtr;

typedef struct _CompilerInfo {
	IdentifierData data;
	ExpressionListPtr arrayExpression;
	ParameterListNodePtr parameterList;
	void* noDefinition;
} CompilerInfo, * CompilerInfoPtr, ** CompilerInfoPtrPtr;

int yylex();
int yyparse();
int yywrap();
void comment();
void count();
int check_type();
void yyerror(const char* s);
int handleIndentifier(int result);

ExpressionListPtr createExpression(char* identifier, VariableType type, VariableSignType sign, Boolean constant);
DeclarationPtr createDeclaration(int pointerLevel, char* identifier, VariableType type, VariableSignType sign, StorageType storage, DeclarationType declarationType, ExpressionListPtr arrayExpression, ParameterListNodePtr parameterList);
void addDeclaration(DeclarationPtr declaration);
void addFunction(DeclarationPtr declaration);
void addToSymbolTable(int pointerLevel, char* identifier, VariableType type, VariableSignType sign, StorageType storage, DeclarationType declarationType, Boolean constant, ExpressionListPtr arrayExpression);
void addToFunctionTable(char* identifier, VariableType type, VariableSignType sign, StorageType storage, DeclarationType declarationType, Boolean constant, ExpressionListPtr arrayExpression, ParameterListNodePtr parameterList);
int printSize(ParameterListNodePtr list);
void addToExpression(ExpressionListPtrPtr expression, char* identifier, VariableType type, VariableSignType sign, Boolean constant);
ParameterListNodePtr createParameterListNode(CompilerInfoPtr node);
void addToParameterList(ParameterListNodePtrPtr list, ParameterListNodePtr node);
void addToParameterList2(ParameterListNodePtrPtr list, CompilerInfoPtr node);
void printDeclaration(DeclarationPtr declaration);
void printFunction(DeclarationPtr declaration);
void printParameterListNode(char* message, ParameterListNodePtr list);
void printCompilerInfoNode(char* message, CompilerInfoPtr list);

extern DeclarationListPtr symbolTable;
extern DeclarationListPtr functionTable;
extern FILE* fileLexLog;
extern int num_errors;
extern int yylineno;
extern int column;
extern int num_errors;
extern FILE* yyin;
extern FILE* yyout;
extern Boolean bit16;
extern Boolean bit32;
extern Boolean bit64;
extern char logFileName[_MAX_PATH];
extern char drive[_MAX_DRIVE];
extern char dir[_MAX_DIR];
extern char fname[_MAX_FNAME];
extern char ext[_MAX_EXT];

#endif