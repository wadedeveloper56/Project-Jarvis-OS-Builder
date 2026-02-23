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

typedef struct TokData
{
	TokenCode code;
	union Representation
	{
		Keyword keyword;
		Symbol symbol;
		NumericConstant numericConstant;
		StringConstant stringConstant;
	} repr;

	TokData() = default;
	~TokData() = default;
	TokData(const TokData& other) = default;
	TokData(TokData&& other) noexcept = default;
	TokData& operator=(const TokData& other) = default;
	TokData& operator=(TokData&& other) noexcept = default;
} * TokDataPtr;

typedef struct Token
{
	TokDataPtr data;
	Token();
	~Token();

	Token(const Token& other)
	{
		delete data;
		data = new TokData(*other.data);
	}

	Token(Token&& other) noexcept
	{
		delete data;
		data = new TokData(*other.data);
	}

	Token& operator=(const Token& other)
	{
		if (this == &other)
			return *this;
		delete data;
		data = new TokData(*other.data);
		return *this;
	}

	Token& operator=(Token&& other) noexcept
	{
		if (this == &other)
			return *this;
		delete data;
		data = new TokData(*other.data);
		return *this;
	}

	string getSymbolName() const;
	string getKeywordName() const;
}* TokenPtr, ** TokenPtrPtr;

TokenPtr createToken(TokDataPtr data);
TokDataPtr createTokData(void);
TokenPtr createConstantULLToken(unsigned long long num);
TokenPtr createConstantLDToken(long double num);
TokenPtr createStringConstantToken(char* str);
TokenPtr createStringIDToken(char* str);
TokenPtr createKeywordToken(char* str, int keyword);
