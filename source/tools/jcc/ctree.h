#pragma once

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
	LABCT_TILDE,
	LABCT_TIMES,
	LABCT_UNARY_MINUS,
	LABCT_UNARY_PLUS,
	LABCT_VALUE_AT_ADDR,
	LABCT_XOR,

	LABCT_MAX
} LabelConstrType;

typedef struct {
	LabelType type;
	union {
		struct { /* Construct in case type=LABT_CONSTRUCT_ROOT*/
			LabelConstrType type : 8;
			int8 numTokens;
			pToken* tokens;
		} constr;
		pSLList list; // List of tokens
		pToken token;
		pDeclInfo dinfo;
		pDeclList declList;
		void* data;
	} repr;
} Label, * pLabel;

typedef struct _CTree {
	pLabel label;
	struct _CTree* child1; /* Left child */
	struct _CTree* child2;  /* Right child */
} CTree, * pCTree;

typedef union {
	pOUnit oUnit;
	pToken token;
	pCTree tree;
	pLabel label;
	pSLList tokenList;
	pDeclInfo dinfo;
	pDeclTree declList;
	pDeclTreeElem declTreeElem;
	pDeclStructInfo dsinfo;
	pDeclStructBody dsbody;
	pEnumList enumList;
	pEnumElem enumElem;
	pDeclEnum declEnum;
	pDclr dclr;
	pDclrList dclrList;
	pDclrPtr dclrPtr;
	pArrElem arrElem;
	int flag;
	void* data;
} ParseUnion;

/* types used for collecting decl-specifiers */

/* only one of these may be specified */
typedef enum {
	STG_NULL = 0,
	STG_TYPEDEF,
	STG_REGISTER,
	STG_AUTO,
	STG_EXTERN,
	STG_STATIC,
	STG_MAX
} StgClass;

/* any one of these may be specified */
typedef enum {
	STY_CONST = 0x01,
	STY_VOLATILE = 0x02,
	STY_NULL = 0x00
} TypeQualifier;

/* only certain combinations may be specified */
typedef enum {
	STM_NULL = 0x0000,
	STM_CHAR = 0x0001,
	STM_INT = 0x0002,
	STM_LONG = 0x0004,
	STM_FLOAT = 0x0008,
	STM_DOUBLE = 0x0010,
	STM_SIGNED = 0x0020,
	STM_UNSIGNED = 0x0040,
	STM_SHORT = 0x0080,
	STM_VOID = 0x0100,
	STM_DOT_DOT_DOT = 0x0200      // Used exclusively for function args
} YScalarType;

typedef enum {
	DIT_NULL = 0,
	DIT_SCALAR,                 // Things like int, uint and alike
	DIT_STRUCT_OR_UNION,
	DIT_ENUM
} DeclInfoType;

// Scalar types
typedef enum {
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

typedef enum {
	MT_NULL = 0,
	MT_NEAR,
	MT_FAR,
	MT_FAR16,
	MT_HUGE,
	MT_MAX
} MemType;

struct DeclInfo {
	pToken begPunct;  // Punctuation mark at the beginning of a declarator
	StgClass storage;
	TypeQualifier qualifier;
	pTokPos prefixPos;
	DeclInfoType type : 8;
	union {
		struct {        // DIT_SCALAR
			YScalarType scalarCombo;
			ScalarType scalar;
			pTokPos scalarPos;
		} scalar;
		pDeclEnum e;                    // DIT_ENUM
		pDeclStructInfo s;              // DIT_STRUCT_OR_UNION
	} repr;
	pDclrList dclrList;  // List of declarators (optional)
	pDclr dclr;  // Declarator that may come from defined type
};

typedef enum {
	DSIT_STRUCT,
	DSIT_UNION
} DeclStructInfoType;

struct DeclStructInfo {
	DeclStructInfoType type;
	pTokPos typePos;
	pToken name;                // Name (optional) of the structure
	pDeclStructBody body;       // Body (optional) of the structure
};

struct DeclStructBody {
	pDeclList declList;
	pTokPos endPos;
};

struct ArrElem {
	pToken lBracket;
	pCTree constExpr;
	pToken rBracket;
};

struct Dclr {
	MemType memType;
	pTokPos memPos;

	pToken pragmaMod;

	pDclrPtr ptr;

	pToken id;

	pArrList arrList;

	pToken argBegin;  // '('
	pDeclList args;
	pToken argEnd;  // ')'

	pToken equalTok;
	pCTree initializer;
};

struct DclrPtr {
	MemType memType;
	TypeQualifier qualifiers;
	pTokPos pos;
};

struct DeclEnum {
	pTokPos enumPos;            // enum
	//    pToken name;              // optional
	pEnumList list;             // optional
};

struct EnumElem {
	char   begPunctExists;  // comma exists before this element
	pToken name;
	pToken equal;
	pCTree expression;
};

