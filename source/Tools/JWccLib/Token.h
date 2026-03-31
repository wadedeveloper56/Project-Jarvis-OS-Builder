#pragma once

using namespace std;

enum TokenCode
{
	YC_NONE,
	YC_KEYWORD,
	YC_SYMBOL,
	YC_NUMERIC,
	YC_STRING
};

enum RadixType
{
	RADT_NONE,
	RADT_DECIMAL,
	RADT_HEX,
	RADT_OCTAL,
	RADT_MAX
};

enum ConstType
{
	CONSTT_NONE,
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
};

struct Keyword
{
	int keyword;
	int strLen;
	char* string;
};

struct Symbol
{
	char* string;
	int strLen;
};

struct NumericConstant
{
	ConstType type : 6;
	RadixType radix : 2;
	union ConstRepr
	{
		unsigned long long lIntConst;
		long double lDoubleConst;
	} repr;
};

struct StringConstant
{
	char* s;
	int strLen;
};

typedef struct CTokData
{
	TokenCode code;
	union Representation
	{
		Keyword keyword;
		Symbol symbol;
		NumericConstant numericConstant;
		StringConstant stringConstant;
	} repr;

	CTokData() = default;
	~CTokData() = default;
	CTokData(const CTokData& other) = default;
	CTokData(CTokData&& other) noexcept = default;
	CTokData& operator=(const CTokData& other) = default;
	CTokData& operator=(CTokData&& other) noexcept = default;
} * CTokDataPtr;

typedef struct CToken
{
	CTokDataPtr data;
	CToken() = default;
	~CToken()= default;
	CToken(const CToken& other)= default;
	CToken(CToken&& other) noexcept = default;
	CToken& operator=(const CToken& other) = default;
	CToken& operator=(CToken&& other) noexcept = default;
	string getSymbolName() const;
	string getKeywordName() const;
	unsigned long long getIntegerConst() const;
	long double getDoubleConst() const;
}* CTokenPtr, ** CTokenPtrPtr;

CTokenPtr createToken(CTokDataPtr data);
CTokDataPtr createTokData(void);
CTokenPtr createConstantULLToken(unsigned long long num);
CTokenPtr createConstantLDToken(long double num);
CTokenPtr createStringConstantToken(char* str);
CTokenPtr createStringIDToken(char* str);
CTokenPtr createKeywordToken(char* str, int keyword);
