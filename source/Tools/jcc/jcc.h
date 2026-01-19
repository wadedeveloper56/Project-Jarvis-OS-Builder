#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "c11parser.h"
#include "ArgumentTable.h"
#include "Memory.h"

typedef enum {
	LABT_LIST,
	LABT_TOKEN,
	LABT_CONSTRUCT_ROOT,
	LABT_DECL_INFO,
	LABT_DECL_LIST
} LabelType;

typedef enum {
	LABCT_ADDR_OF_VALUE,
	LABCT_AND,
	LABCT_AND_AND,
	LABCT_ARROW,
	LABCT_CALL,
	LABCT_CAST_EXPR,
	LABCT_COLON,
	LABCT_DEFINED,
	LABCT_DIVIDE,
	LABCT_DOT,
	LABCT_EQ,
	LABCT_EXCLAMATION,
	LABCT_EXPR_LIST,
	LABCT_EXPR_SEPARATOR,
	LABCT_GE,
	LABCT_GT,
	LABCT_INDEX,
	LABCT_LE,
	LABCT_LSHIFT,
	LABCT_LT,
	LABCT_MINUS,
	LABCT_NE,
	LABCT_OR,
	LABCT_OR_OR,
	LABCT_PAREN_EXPR,
	LABCT_PERCENT,
	LABCT_PLUS,
	LABCT_PRE_DEFINE_MACRO,
	LABCT_PRE_ELIF,
	LABCT_PRE_ELSE,
	LABCT_PRE_ENDIF,
	LABCT_PRE_IF,
	LABCT_PRE_IFDEF,
	LABCT_PRE_IFNDEF,
	LABCT_PRE_INCLUDE,
	LABCT_PRE_DIR_LIST,
	LABCT_QUESTION,
	LABCT_RSHIFT,
	LABCT_SIZEOF_EXPR,
	LABCT_SIZEOF_TYPE,
	LABCT_STRINGS,
	LABCT_CONSTANT,
	LABCT_TILDE,
	LABCT_TIMES,
	LABCT_UNARY_MINUS,
	LABCT_UNARY_PLUS,
	LABCT_VALUE_AT_ADDR,
	LABCT_XOR,

	LABCT_MAX
} LabelConstrType;

typedef struct {
	char* fileName;
	int8_t fileLevel;
	int16_t lineNum;
	int16_t  colNum;
	uint8_t  linesBefore;
	uint8_t  spacesBefore;
	long orderLineNum;
} TokPos, * TokPosPtr;

typedef enum {
	RADT_DECIMAL,
	RADT_HEX,
	RADT_OCTAL,
	RADT_MAX
} RadixType;

typedef enum {
	CONSTT_CHAR_CONST,
	CONSTT_INT_CONST,
	CONSTT_UINT_CONST,
	CONSTT_LONG_CONST,
	CONSTT_ULONG_CONST,
	CONSTT_FLOAT_CONST,
	CONSTT_DOUBLE_CONST,
	CONSTT_LDOUBLE_CONST,   /* Long double const */
	CONSTT_STRING_CONST,
	CONSTT_MAX
} ConstType;

typedef enum {
	TT_PREPROCESSOR,
	TT_OTHER
} token_type;

typedef struct {
	uint16_t code;
	union {
		struct {
			int keyword;
			int strLen;
			char* string;
		} keyword;
		struct {
			char* string;
			int strLen;
			//pDeclInfo pTypeDecl;
		} symbol;
		struct {
			ConstType type : 6;
			RadixType radix : 2;
			union {
				unsigned long long lIntConst;
				long double lDoubleConst;
			} repr;
		} numericConstant;
		struct {
			char* s;
			int strLen;
		} stringConstant;
	} repr;
} TokData, *TokDataPtr;

typedef struct {
	TokDataPtr data;
	TokPosPtr pos;
}Token, *TokenPtr, ** TokenPtrPtr;

typedef struct {
	LabelType type;
	union {
		struct { /* Construct in case type=LABT_CONSTRUCT_ROOT*/
			LabelConstrType type : 8;
			int8_t numTokens;
			TokenPtrPtr tokens;
		} constr;
		//pSLList list; // List of tokens
		TokenPtr token;
		//pDeclInfo dinfo;
		//pDeclList declList;
		void* data;
	} repr;
} Label, * LabelPtr, ** LabelPtrPtr;

typedef struct _CTree {
	LabelPtr label;
	struct _CTree* child1; /* Left child */
	struct _CTree* child2;  /* Right child */
} CTree, * CTreePtr, ** CTreePtrPtr;

union ParseUnion {
	CTreePtr tree;
	TokenPtr token;
};

void printHeader(void);
void doConversion(void** name);
void initiate(int argc, char* argv[]);
void terminate(int exitCode);
//********************************************
CTreePtr createCTreeRoot(LabelPtr label);
CTreePtr createCTree1(LabelPtr label, CTreePtr child);
LabelPtr createTokenLabelStr(char* token);
LabelPtr createConstr2Label(LabelConstrType type, TokenPtr t0, TokenPtr t1);
TokenPtr createToken(TokDataPtr data, TokPosPtr pos);
TokPosPtr createTokPos(void);
TokDataPtr createTokData(void);
TokenPtr createConstantULLToken(unsigned long long num);
TokenPtr createConstantLDToken(long double num);
TokenPtr createStringConstantToken(char* str);
TokenPtr createStringIDToken(char* str);
TokenPtr createKeywordToken(char* str, int keyword);

