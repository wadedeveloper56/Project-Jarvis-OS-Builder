#include "jcc.h"

CTreePtr createCTreeRoot(LabelPtr label) 
{
    CTreePtr newTree = AllocateMemory(sizeof(CTree));
    newTree->label = label;
    newTree->child1 = NULL;
    newTree->child2 = NULL;
    return newTree;
}

CTreePtr createCTree1(LabelPtr label, CTreePtr child) 
{
    CTreePtr newTree = createCTreeRoot(label);
    newTree->child1 = child;
    return newTree;
}

static LabelPtr _createLabel(LabelType type, void* data)
{
    LabelPtr newLabel = AllocateMemory(sizeof(Label));
    newLabel->type = type;
    newLabel->repr.data = data;
    return newLabel;
}

LabelPtr createConstr2Label(LabelConstrType type, TokenPtr t0, TokenPtr t1) 
{
    LabelPtr newLabel = _createLabel(LABT_CONSTRUCT_ROOT, NULL);
    newLabel->repr.constr.type = type;
    newLabel->repr.constr.numTokens = 2;
    newLabel->repr.constr.tokens = AllocateMemory(sizeof(TokenPtr) * 2);
    newLabel->repr.constr.tokens[0] = t0;
    newLabel->repr.constr.tokens[1] = t1;
    return newLabel;
}

LabelPtr createTokenLabelStr(char* token) 
{
    return _createLabel(LABT_TOKEN, token);
}

TokenPtr createToken(TokDataPtr data, TokPosPtr pos) 
{
    TokenPtr tok = AllocateMemory(sizeof(Token));
    tok->data = data;
    tok->pos = pos;
    return tok;
}

TokPosPtr createTokPos(void) 
{
    TokPosPtr newPos = AllocateMemory(sizeof(TokPos));
    memset(newPos, 0, sizeof(TokPos));
    return newPos;
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
    TokenPtr tok = createToken(createTokData(), NULL);
    tok->data->code = YC_INT_CONST;
    tok->data->repr.numericConstant.type = CONSTT_UINT_CONST;
    tok->data->repr.numericConstant.radix = RADT_DECIMAL;
    tok->data->repr.numericConstant.repr.lIntConst = num;
    return tok;
}

TokenPtr createConstantLDToken(long double num)
{
    TokenPtr tok = createToken(createTokData(), NULL);
    tok->data->code = YC_FLOAT_CONST;
    tok->data->repr.numericConstant.type = CONSTT_LDOUBLE_CONST;
    tok->data->repr.numericConstant.radix = RADT_DECIMAL;
    tok->data->repr.numericConstant.repr.lDoubleConst = num;
    return tok;
}

TokenPtr createStringConstantToken(char *str)
{
    TokenPtr tok = createToken(createTokData(), NULL);
    tok->data->code = YC_STRING_CONST;
    tok->data->repr.stringConstant.s = _strdup(str);
	tok->data->repr.stringConstant.strLen = (int)strlen(str);
    return tok;
}

TokenPtr createStringIDToken(char* str)
{
    TokenPtr tok = createToken(createTokData(), NULL);
    tok->data->code = YC_ID;
    tok->data->repr.symbol.string = _strdup(str);
    tok->data->repr.symbol.strLen = (int)strlen(str);
    return tok;
}

TokenPtr createKeywordToken(char* str,int keyword)
{
    TokenPtr tok = createToken(createTokData(), NULL);
    tok->data->code = YC_KEYWORD;
    tok->data->repr.keyword.string = _strdup(str);
	tok->data->repr.keyword.keyword = keyword;
    tok->data->repr.keyword.strLen = (int)strlen(str);
    return tok;
}
