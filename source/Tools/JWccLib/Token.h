#pragma once

typedef enum _TokenCode
{
	YC_KEYWORD,
	YC_SYMBOL,
	YC_NUMERIC,
	YC_STRING
} TokenCode;

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

TokenPtr createToken(TokDataPtr data);
TokDataPtr createTokData(void);
TokenPtr createConstantULLToken(unsigned long long num);
TokenPtr createConstantLDToken(long double num);
TokenPtr createStringConstantToken(char* str);
TokenPtr createStringIDToken(char* str);
TokenPtr createKeywordToken(char* str, int keyword);
