#include "jcc.h"

TokenPtr createToken(TokDataPtr data) 
{
    TokenPtr tok = AllocateMemory(sizeof(Token));
    tok->data = data;
    return tok;
}

TokDataPtr createTokData(void)
{
    TokDataPtr newData = AllocateMemory(sizeof(TokData));
    memset(newData, 0, sizeof(TokData));
    newData->repr.symbol.string = NULL;
    return newData;
}

TokenPtr createConstantULLToken(unsigned long long num) 
{
    TokenPtr tok = createToken(createTokData());
    tok->data->code = YC_INT_CONST;
    tok->data->repr.numericConstant.type = CONSTT_UINT_CONST;
    tok->data->repr.numericConstant.radix = RADT_DECIMAL;
    tok->data->repr.numericConstant.repr.lIntConst = num;
    return tok;
}

TokenPtr createConstantLDToken(long double num)
{
    TokenPtr tok = createToken(createTokData());
    tok->data->code = YC_FLOAT_CONST;
    tok->data->repr.numericConstant.type = CONSTT_LDOUBLE_CONST;
    tok->data->repr.numericConstant.radix = RADT_DECIMAL;
    tok->data->repr.numericConstant.repr.lDoubleConst = num;
    return tok;
}

TokenPtr createStringConstantToken(char *str)
{
    TokenPtr tok = createToken(createTokData());
    tok->data->code = YC_STRING_CONST;
    tok->data->repr.stringConstant.s = _strdup(str);
	tok->data->repr.stringConstant.strLen = (int)strlen(str);
    return tok;
}

TokenPtr createStringIDToken(char* str)
{
    TokenPtr tok = createToken(createTokData());
    tok->data->code = YC_ID;
    tok->data->repr.symbol.string = _strdup(str);
    tok->data->repr.symbol.strLen = (int)strlen(str);
    return tok;
}

TokenPtr createKeywordToken(char* str,int keyword)
{
    TokenPtr tok = createToken(createTokData());
    tok->data->code = YC_KEYWORD;
    tok->data->repr.keyword.string = _strdup(str);
	tok->data->repr.keyword.keyword = keyword;
    tok->data->repr.keyword.strLen = (int)strlen(str);
    return tok;
}
