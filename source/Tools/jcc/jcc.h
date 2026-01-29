#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "c11ansi.tab.h"
#include "ArgumentTable.h"
#include "Memory.h"

#define CALL_INTERNAL_zap(name)   { \
    _zap##name(elem); \
}

typedef enum _LabelType
{
	LABT_LIST,
	LABT_TOKEN,
	LABT_CONSTRUCT_ROOT,
	LABT_DECL_INFO,
	LABT_DECL_LIST
} LabelType;

typedef enum _LabelConstrType
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
	LABCT_INIT,
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

typedef enum _RadixType
{
	RADT_DECIMAL,
	RADT_HEX,
	RADT_OCTAL,
	RADT_MAX
} RadixType;

typedef enum _ConstType
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

typedef enum _TokenCode
{
	YC_KEYWORD,
	YC_SYMBOL,
	YC_NUMERIC,
	YC_STRING
} TokenCode;

typedef struct _TokData
{
	TokenCode code;
	union _Representation
	{
		struct _Keyword
		{
			int keyword;
			int strLen;
			char* string;
		} keyword;
		struct _Symbol
		{
			char* string;
			int strLen;
		} symbol;
		struct _NumericConstant
		{
			ConstType type : 6;
			RadixType radix : 2;
			union _ConstRepr
			{
				unsigned long long lIntConst;
				long double lDoubleConst;
			} repr;
		} numericConstant;
		struct _StringConstant
		{
			char* s;
			int strLen;
		} stringConstant;
	} repr;
} TokData, * TokDataPtr;

typedef struct _Token
{
	TokDataPtr data;
}Token, * TokenPtr, ** TokenPtrPtr;

typedef struct _LinkedListNode
{
	struct _LinkedListNode* next;
	void* userData;
} LinkedListNode, * LinkedListNodePtr, ** LinkedListNodePtrPtr;

typedef struct _LinkedList
{
	LinkedListNodePtr list; 
} LinkedList, * LinkedListPtr, ** LinkedListPtrPtr;

typedef struct _Label
{
	LabelType type;
	union _LabelRepr
	{
		struct _LabelConstr
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

typedef enum _StorageClass
{
	SC_AUTO,
	SC_REGISTER,
	SC_STATIC,
	SC_EXTERN,
	SC_TYPEDEF,
	SC_THREAD_LOCAL,
	SC_MAX
} StorageClass;

typedef enum _TypeQualifier
{
	TQ_CONST,
	TQ_RESTRICT,
	TQ_VOLATILE,
	TQ_ATOMIC,
	TQ_MAX
} TypeQualifier;

typedef struct _TypeSpecifier TypeSpecifier, * TypeSpecifierPtr, ** TypeSpecifierPtrPtr;
typedef struct _StructOrUnionSpecifier StructOrUnionSpecifier, * StructOrUnionSpecifierPtr, ** StructOrUnionSpecifierPtrPtr;
typedef struct _EnumSpecifier EnumSpecifier, * EnumSpecifierPtr, ** EnumSpecifierPtrPtr;

typedef struct _AtomicTypeSpecifier
{
	TokenPtr atomicToken;
	TypeSpecifierPtr typeSpecifier;
} AtomicTypeSpecifier, * AtomicTypeSpecifierPtr, ** AtomicTypeSpecifierPtrPtr;

typedef struct _TypeSpecifier
{
	TokenPtr specifierToken;
	AtomicTypeSpecifierPtr atomicTypeSpecifier;
	StructOrUnionSpecifierPtr structOrUnionSpecifier;
	EnumSpecifierPtr enumSpecifier;
} TypeSpecifier, * TypeSpecifierPtr, ** TypeSpecifierPtrPtr;

typedef enum _FunctionSpecifier
{
	FS_INLINE,
	FS_NORETURN,
	FS_MAX
} FunctionSpecifier;

typedef enum _AlignmentSpecifier
{
	AS_ALIGNOF
} AlignmentSpecifier;

typedef struct _DeclarationSpecifiersNode
{
	TokenPtr token;
	TypeSpecifierPtr typeSpecifier;
} DeclarationSpecifiersNode, * DeclarationSpecifiersNodePtr, ** DeclarationSpecifiersNodePtrPtr;

typedef struct _DeclarationSpecifiers
{
	LinkedListPtr tokenList; // list of DeclarationSpecifiersNode
} DeclarationSpecifiers, * DeclarationSpecifiersPtr, ** DeclarationSpecifiersPtrPtr;

typedef struct _StaticAssertDeclaration
{
	CTreePtr constExpr;
	TokenPtr strLiteral;
} StaticAssertDeclaration, * StaticAssertDeclarationPtr, ** StaticAssertDeclarationPtrPtr;

typedef struct _Declaration
{
	DeclarationSpecifiersPtr declSpecifiers;
	LinkedListPtr initDeclaratorList;
	StaticAssertDeclarationPtr staticAssertDecl;
} Declaration, * DeclarationPtr, ** DeclarationPtrPtr;

typedef struct _StructDeclaration
{
	LinkedListPtr specifierQualifierList;
	LinkedListPtr structDeclaratorList;
	StaticAssertDeclarationPtr staticAssertDeclarationPtr;
} StructDeclaration, * StructDeclarationPtr, ** StructDeclarationPtrPtr;

typedef struct _Declarator Declarator, * DeclaratorPtr, ** DeclaratorPtrPtr;
typedef struct _DirectDeclarator DirectDeclarator, * DirectDeclaratorPtr, ** DirectDeclaratorPtrPtr;

typedef struct _StructDeclarator
{
	DeclaratorPtr declarator;
	CTreePtr constantExpr;
} StructDeclarator, * StructDeclaratorPtr, ** StructDeclaratorPtrPtr;

typedef struct _DirectDeclarator
{
	DirectDeclaratorPtr directDeclarator;
	DeclaratorPtr declarator;
	LinkedListPtr identifierList;
	TokenPtr identifier;
	TokenPtr delimStart;
	TokenPtr delimEnd;
} DirectDeclarator, * DirectDeclaratorPtr, ** DirectDeclaratorPtrPtr;

typedef struct _Declarator
{
	DirectDeclaratorPtr directDeclarator;
	LinkedListPtr pointerList; // list of TokenPtr (TypeQualifier)
} Declarator, * DeclaratorPtr, ** DeclaratorPtrPtr;	

typedef struct _SpecifierQualifierListNode
{
	TokenPtr typeQualifier;
	TypeSpecifierPtr typeSpecifier;
} SpecifierQualifierListNode, * SpecifierQualifierListNodePtr, ** SpecifierQualifierListNodePtrPtr;

typedef struct _StructOrUnionSpecifier
{
	TokenPtr structOrUnionToken;
	TokenPtr structOrUnionName;
	LinkedListPtr structDeclarationList; // list of StructDeclarationPtr
} StructOrUnionSpecifier, * StructOrUnionSpecifierPtr, ** StructOrUnionSpecifierPtrPtr;

typedef struct _Enumerator
{
	TokenPtr enumeratorName;
	CTreePtr constExpr;
} Enumerator, * EnumeratorPtr, ** EnumeratorPtrPtr;

typedef struct _EnumSpecifier
{
	TokenPtr enumName;
	LinkedListPtr enumeratorList; // list of EnumeratorPtr
} EnumSpecifier, * EnumSpecifierPtr, ** EnumSpecifierPtrPtr;

union ParseUnion
{
	CTreePtr expression;
	LabelPtr label;
	TokenPtr token;
	LinkedListPtr list;
	DeclarationPtr declaration;	
	DeclarationSpecifiersPtr declSpecifiers;
	LinkedListPtr initDeclaratorList;
	StaticAssertDeclarationPtr staticAssertDecl;
	TypeSpecifierPtr typeSpecifier;
	AtomicTypeSpecifierPtr atomicTypeSpecifier;
	StructDeclarationPtr structDeclaration;
	StructDeclaratorPtr structDeclarator;
	DeclaratorPtr declarator;
	DirectDeclaratorPtr directDeclarator;
	StructOrUnionSpecifierPtr structOrUnionSpecifier;
	EnumeratorPtr enumerator;
	EnumSpecifierPtr enumSpecifier;
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
void zapToken(void* elem);
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
DeclarationPtr createDeclaration(DeclarationSpecifiersPtr declSpecifiers, LinkedListPtr initDeclaratorList, StaticAssertDeclarationPtr staticAssertDecl);
void addListElem(LinkedListPtr pList, void* elem);
LinkedListPtr createList(void);
DeclarationSpecifiersPtr createDeclarationSpecifiers1(TokenPtr token, DeclarationSpecifiersPtr tokenList);
DeclarationSpecifiersPtr createDeclarationSpecifiers2(TypeSpecifierPtr typeSpecifier, DeclarationSpecifiersPtr tokenList);
TypeSpecifierPtr createTypeSpecifier(TokenPtr token);
TypeSpecifierPtr createTypeSpecifier2(AtomicTypeSpecifierPtr token);
TypeSpecifierPtr createTypeSpecifier3(StructOrUnionSpecifierPtr token);
TypeSpecifierPtr createTypeSpecifier4(EnumSpecifierPtr token);
AtomicTypeSpecifierPtr createAtomicTypeSpecifier(TokenPtr atomicToken, TokenPtr typeNameToken);
LinkedListPtr createStructDeclarationList(StructDeclarationPtr node, LinkedListPtr list);
StructDeclarationPtr createStructDeclaration(LinkedListPtr specifierQualifierList, LinkedListPtr structDeclaratorList, StaticAssertDeclarationPtr staticAssertDeclaration);
LinkedListPtr createSecifierQualifierList(TypeSpecifierPtr typeSpecifier, TokenPtr typeQualifier, LinkedListPtr list);
LinkedListPtr createStructDeclaratorList(StructDeclaratorPtr structDeclarator, LinkedListPtr list);
StructDeclaratorPtr createStructDeclarator(DeclaratorPtr declarator, CTreePtr constExpression);
StructOrUnionSpecifierPtr createStructOrUnionSpecifier(TokenPtr structOrUnion, TokenPtr identifier, LinkedListPtr list);
LinkedListPtr createEnumeratorList(EnumeratorPtr enumerator, LinkedListPtr list);
EnumeratorPtr createEnumerator(TokenPtr enumeratorName, CTreePtr constExpr);
EnumSpecifierPtr createEnumSpecifier(TokenPtr enumName, LinkedListPtr enumeratorList);
DirectDeclaratorPtr createDirectDeclarator1(TokenPtr identifier);
DirectDeclaratorPtr createDirectDeclarator2(DirectDeclaratorPtr directDeclarator, DeclaratorPtr declarator);