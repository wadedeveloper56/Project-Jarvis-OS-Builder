#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "c11ansi.tab.h"
#include "ArgumentTable.h"
#include "Memory.h"

typedef enum
{
	LABT_LIST,
	LABT_TOKEN,
	LABT_CONSTRUCT_ROOT,
	LABT_DECL_INFO,
	LABT_DECL_LIST
} LabelType;

typedef enum
{
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
	LABCT_MINUS_MINUS,
	LABCT_NE,
	LABCT_OR,
	LABCT_OR_OR,
	LABCT_PAREN_EXPR,
	LABCT_PERCENT,
	LABCT_PLUS,
	LABCT_PLUS_PLUS,
	LABCT_QUESTION,
	LABCT_RSHIFT,
	LABCT_SIZEOF_EXPR,
	LABCT_SIZEOF_TYPE,
	LABCT_ALIGNOF_TYPE,
	LABCT_STRINGS,
	LABCT_CONSTANT,
	LABCT_TILDE,
	LABCT_TIMES,
	LABCT_UNARY_MINUS,
	LABCT_UNARY_PLUS,
	LABCT_VALUE_AT_ADDR,
	LABCT_XOR,
	LABCT_TIMES_EQUAL,
	LABCT_DIVIDE_EQUAL,
	LABCT_PERCENT_EQUAL,
	LABCT_PLUS_EQUAL,
	LABCT_MINUS_EQUAL,
	LABCT_LSHIFT_EQUAL,
	LABCT_RSHIFT_EQUAL,
	LABCT_AND_EQUAL,
	LABCT_XOR_EQUAL,
	LABCT_OR_EQUAL,

	LABCT_MAX
} LabelConstrType;

//typedef struct {
//	char* fileName;
//	int8_t fileLevel;
//	int16_t lineNum;
//	int16_t  colNum;
//	uint8_t  linesBefore;
//	uint8_t  spacesBefore;
//	long orderLineNum;
//} TokPos, * TokPosPtr;
//
typedef enum
{
	RADT_DECIMAL,
	RADT_HEX,
	RADT_OCTAL,
	RADT_MAX
} RadixType;

typedef enum
{
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

//typedef enum {
//	TT_PREPROCESSOR,
//	TT_OTHER
//} token_type;
//
typedef enum
{
	YC_INT_CONST,
	YC_FLOAT_CONST,
	YC_STRING_CONST,
	YC_ID,
	YC_KEYWORD
	// ... other token codes as needed
} TokenCode;

typedef struct
{
	TokenCode code;
	union
	{
		struct
		{
			int keyword;
			int strLen;
			char* string;
		} keyword;
		struct
		{
			char* string;
			int strLen;
		} symbol;
		struct
		{
			ConstType type : 6;
			RadixType radix : 2;
			union
			{
				unsigned long long lIntConst;
				long double lDoubleConst;
			} repr;
		} numericConstant;
		struct
		{
			char* s;
			int strLen;
		} stringConstant;
	} repr;
} TokData, * TokDataPtr;

typedef struct
{
	TokDataPtr data;
}Token, * TokenPtr, ** TokenPtrPtr;

typedef struct _SLListNode
{
	struct _SLListNode* next;
	void* userData;
} SLListNode, * SLListNodePtr, ** SLListNodePtrPtr;

typedef struct _LinkedList
{
	SLListNodePtr head;  /* 1-st element in the list */
	SLListNodePtr tail;  /* Last (most recently added) element in the list */
} LinkedList, * LinkedListPtr, ** LinkedListPtrPtr;

typedef struct
{
	LabelType type;
	union
	{
		struct
		{
			LabelConstrType type : 8;
			int8_t numTokens;
			TokenPtrPtr tokens;
		} constr;
		LinkedListPtr list; // List of tokens
		TokenPtr token;
		void* data;
	} repr;
} Label, * LabelPtr, ** LabelPtrPtr;

typedef struct _CTree
{
	LabelPtr label;
	struct _CTree* child1; /* Left child */
	struct _CTree* child2;  /* Right child */
} CTree, * CTreePtr, ** CTreePtrPtr;

typedef enum
{
	STG_NULL = 0,
	STG_TYPEDEF,
	STG_REGISTER,
	STG_AUTO,
	STG_EXTERN,
	STG_STATIC,
	STG_THREAD_LOCAL,
	STG_MAX
} StgClass;

typedef enum
{
	STY_NULL = 0x00,
	STY_CONST = 0x01,
	STY_VOLATILE = 0x02,
	STY_RESTRICT = 0x03,
	STY_ATOMIC = 0x04,
	STY_INLINE = 0x05,
	STY_NORETURN = 0x06,
	STY_ALIGNAS = 0x07,
} TypeQualifier;

typedef enum
{
	STM_NULL = 0x00000,
	STM_CHAR = 0x00001,
	STM_INT = 0x00002,
	STM_LONG = 0x00004,
	STM_LONG_LONG = 0x00008,
	STM_FLOAT = 0x00010,
	STM_DOUBLE = 0x00020,
	STM_LONG_DOUBLE = 0x00040,
	STM_SIGNED = 0x00080,
	STM_UNSIGNED = 0x00100,
	STM_SHORT = 0x00200,
	STM_VOID = 0x00400,
	STM_BOOL = 0x00800,
	STM_DOT_DOT_DOT = 0x01000,      // Used exclusively for function args
	STM_COMPLEX = 0x002000,
    STM_IMAGINARY = 0x04000,
    STM_ATOMIC = 0x08000,
    STM_STRUCT = 0x10000,
    STM_ENUM = 0x20000,
    STM_TYPEDEF = 0x40000

} YScalarType;

typedef enum
{
	DIT_NULL = 0,
	DIT_SCALAR,                 // Things like int, uint and alike
	DIT_STRUCT_OR_UNION,
	DIT_ENUM
} DeclInfoType;

// Scalar types
typedef enum
{
	SCL_NULL = 0x00,
	SCL_CHAR,
	SCL_SCHAR,
	SCL_UCHAR,
	SCL_WCHAR,            // extension: long char
	SCL_SSHORT,
	SCL_USHORT,
	SCL_SINT,
	SCL_UINT,
	SCL_SLONG,
	SCL_ULONG,
	SCL_FLOAT,
	SCL_DOUBLE,
	SCL_LDOUBLE,        // long double
	SCL_VOID,
	SCL_DOT_DOT_DOT,
	SCL_MAX
} ScalarType;

typedef enum
{
	DSIT_STRUCT,
	DSIT_UNION
} DeclStructInfoType;

typedef struct _DeclStructBody
{
	LinkedListPtr declList;
}DeclStructBody, * DeclStructBodyPtr, ** DeclStructBodyPtrPtr;

typedef struct _DeclStructInfo
{
	DeclStructInfoType type;
	TokenPtr name;                // Name (optional) of the structure
	DeclStructBodyPtr body;       // Body (optional) of the structure
}DeclStructInfo, * DeclStructInfoPtr, ** DeclStructInfoPtrPtr;

typedef struct DeclEnum
{
	LinkedListPtr list;             // optional
}DeclEnum, * DeclEnumPtr, ** DeclEnumPtrPtr;

typedef enum
{
	MT_NULL = 0,
	MT_NEAR,
	MT_FAR,
	MT_FAR16,
	MT_HUGE,
	MT_MAX
} MemType;

typedef struct _DclrPtr
{
	MemType memType;
	TypeQualifier qualifiers;
}_DclrPtr, * pDclrPtr;

typedef struct _Dclr
{
	MemType memType;
	TokenPtr pragmaMod;
	pDclrPtr ptr;
	TokenPtr id;
	LinkedListPtr arrList;
	TokenPtr argBegin;  // '('
	LinkedListPtr args;
	TokenPtr argEnd;  // ')'
	TokenPtr equalTok;
	CTreePtr initializer;
}Dclr, * DclrPtr, ** DclrPtrPtr;

typedef struct _DeclInfo
{
	TokenPtr begPunct;  // Punctuation mark at the beginning of a declarator
	StgClass storage;
	TypeQualifier qualifier;
	DeclInfoType type : 8;
	union
	{
		struct
		{        // DIT_SCALAR
			YScalarType scalarCombo;
			ScalarType scalar;
		} scalar;
		DeclEnumPtr e;                    // DIT_ENUM
		DeclStructInfoPtr s;              // DIT_STRUCT_OR_UNION
	} repr;
	LinkedListPtr dclrList;  // List of declarators (optional)
	DclrPtr dclr;  // Declarator that may come from defined type
}DeclInfo, * DeclInfoPtr, ** DeclInfoPtrPtr;

typedef struct _EnumElem
{
	char   begPunctExists;  // comma exists before this element
	TokenPtr name;
	TokenPtr equal;
	CTreePtr expression;
}EnumElem, * EnumElemPtr, ** EnumElemPtrPtr;

typedef struct _ArrElem
{
	TokenPtr lBracket;
	CTreePtr constExpr;
	TokenPtr rBracket;
}ArrElem, * ArrElemPtr, ** ArrElemPtrPtr;

//typedef enum
//{
//	DECL_INFO,
//	DECL_TREE_ELEM
//} DeclTreeElemType;
//
//typedef struct _DeclTreeElem
//{
//	DeclTreeElemType type;
//	union
//	{
//		DeclInfoPtr decl;
//		LinkedListPtr list;
//	} u;
//}DeclTreeElem, *DeclTreeElemPtr, **DeclTreeElemPtrPtr;

union ParseUnion
{
	CTreePtr expression;
	LabelPtr label;
	TokenPtr token;
	DeclInfoPtr dinfo;
	//DeclStructInfoPtr dsinfo;
	//DeclStructBodyPtr dsbody;
	DeclEnumPtr declEnum;
	DclrPtr dclr;
	//pDclrPtr dclrPtr;
	//LinkedListPtr tokenList;
	LinkedListPtr enumList;
	LinkedListPtr declList;
	LinkedListPtr dclrList;
	EnumElemPtr enumElem;
	//ArrElemPtr arrElem;
	//DeclTreeElemPtr declTreeElem;
	//int flag;
	//void* data;
};

void printHeader(void);
void doConversion(void** name);
void initiate(int argc, char* argv[]);
void terminate(int exitCode);
//********************************************
// structures.c functions
//********************************************
TokenPtr createConstantULLToken(unsigned long long num);
TokenPtr createConstantLDToken(long double num);
TokenPtr createStringConstantToken(char* str);
TokenPtr createStringIDToken(char* str);
TokenPtr createKeywordToken(char* str, int keyword);
//********************************************
// tree.c functions
//********************************************
CTreePtr createCTreeRoot(LabelPtr label);
CTreePtr createNULLCTree(void);
CTreePtr createCTree1(LabelPtr label, CTreePtr child);
CTreePtr createCTree2(LabelPtr label, CTreePtr child1, CTreePtr child2);
LabelPtr createTokenLabel(TokenPtr token);
LabelPtr createConstr0Label(LabelConstrType type);
LabelPtr createConstr1Label(LabelConstrType type, TokenPtr t0);
LabelPtr createConstr2Label(LabelConstrType type, TokenPtr t0, TokenPtr t1);
LabelPtr createConstr3Label(LabelConstrType type, TokenPtr t0, TokenPtr t1, TokenPtr t2);
LabelPtr createConstr4Label(LabelConstrType type, TokenPtr t0, TokenPtr t1, TokenPtr t2, TokenPtr t3);
LabelPtr createConstr5Label(LabelConstrType type, TokenPtr t0, TokenPtr t1, TokenPtr t2, TokenPtr t3, TokenPtr t4);
LinkedListPtr transformDecl(DeclInfoPtr decl);
DeclInfoPtr addDeclInfoDclrList(DeclInfoPtr decl, LinkedListPtr list);
void zapToken(void* elem);
LinkedListPtr createDclrList(DclrPtr elem);
LinkedListPtr createDclrInfoList(DeclInfoPtr elem);
LinkedListPtr addDclrList(LinkedListPtr list, DclrPtr elem);
LinkedListPtr addDclrInfoList(LinkedListPtr list, DeclInfoPtr elem);
DeclInfoPtr createStructDeclaration(DeclInfoPtr info, LinkedListPtr list);
DeclInfoPtr createStgClassDeclInfo(StgClass stgClass, TokenPtr pos);
DclrPtr addDclrInitializer(DclrPtr dclr, TokenPtr equalTok, CTreePtr initializer);
DeclInfoPtr createDeclInfoSCALAR(YScalarType tokCode);
DeclInfoPtr combine2DeclInfo(DeclInfoPtr d1, DeclInfoPtr d2);
DeclInfoPtr createQualifierDeclInfo(TypeQualifier qualifier);
DeclInfoPtr createFunctionSpecifirDeclInfo(TypeQualifier qualifier);
DeclInfoPtr createAlignmentSpecifierDeclInfo(TypeQualifier qualifier, TokenPtr tok1, TokenPtr tok2, CTreePtr tok3, TokenPtr tok4);
DclrPtr createStructDeclarator(DclrPtr decl, CTreePtr expression);
DeclEnumPtr createDeclEnum(TokenPtr enumPos, TokenPtr identifier, LinkedListPtr list);
LinkedListPtr createEnumElemList(EnumElemPtr element);
LinkedListPtr addEnumElemList(LinkedListPtr list, EnumElemPtr element);
EnumElemPtr createEnumElem(TokenPtr name, TokenPtr equal, CTreePtr expression);
