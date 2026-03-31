#include "pch.h"
#include "Token.h"

CTokenPtr createToken(const CTokDataPtr data)
{
	const auto tok = new CToken;
	tok->data = data;
	return tok;
}

CTokDataPtr createTokData(void)
{
	const auto data = new CTokData;
	memset(data, 0, sizeof(CTokData));
	data->repr.symbol.string = nullptr;
	return data;
}

CTokenPtr createConstantULLToken(const unsigned long long num)
{
	const auto tok = createToken(createTokData());
	tok->data->code = YC_NUMERIC;
	tok->data->repr.numericConstant.type = CONSTT_UINT_CONST;
	tok->data->repr.numericConstant.radix = RADT_DECIMAL;
	tok->data->repr.numericConstant.repr.lIntConst = num;
	return tok;
}

CTokenPtr createConstantLDToken(const long double num)
{
	const auto tok = createToken(createTokData());
	tok->data->code = YC_NUMERIC;
	tok->data->repr.numericConstant.type = CONSTT_LDOUBLE_CONST;
	tok->data->repr.numericConstant.radix = RADT_DECIMAL;
	tok->data->repr.numericConstant.repr.lDoubleConst = num;
	return tok;
}

CTokenPtr createStringConstantToken(char* str)
{
	const CTokenPtr tok = createToken(createTokData());
	tok->data->code = YC_STRING;
	tok->data->repr.stringConstant.s = new char[strlen(str) + 1];
	strcpy(tok->data->repr.stringConstant.s, str);
	tok->data->repr.stringConstant.strLen = (int)strlen(str);
	return tok;
}

CTokenPtr createStringIDToken(char* str)
{
	const CTokenPtr tok = createToken(createTokData());
	tok->data->code = YC_SYMBOL;
	tok->data->repr.symbol.string = new char[strlen(str) + 1];
	strcpy(tok->data->repr.symbol.string, str);
	tok->data->repr.symbol.strLen = (int)strlen(str);
	return tok;
}

CTokenPtr createKeywordToken(char* str, int keyword)
{
	CTokenPtr tok = createToken(createTokData());
	tok->data->code = YC_KEYWORD;
	tok->data->repr.keyword.string = new char[strlen(str) + 1];
	strcpy(tok->data->repr.keyword.string, str);
	tok->data->repr.keyword.keyword = keyword;
	tok->data->repr.keyword.strLen = (int)strlen(str);
	return tok;
}

