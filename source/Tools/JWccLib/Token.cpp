#include "pch.h"
#include "Token.h"
 
using namespace std;

void zapTokData(TokDataPtr elem) 
{
	if (elem == nullptr)
	{
		return;
	}
	if (elem->code == YC_NUMERIC)
	{
		// Nothing to free
	}
	else if (elem->code == YC_STRING)
	{
		delete[] elem->repr.stringConstant.s;
	}
	else
	{
		delete[] elem->repr.symbol.string;
	}
	delete elem;
}

Token::Token()
{
	data = nullptr;
}

Token::~Token()
{
	zapTokData(data);
}

string Token::getSymbolName() const
{
	if (data->code == YC_SYMBOL)
	{
		return string(data->repr.symbol.string, data->repr.symbol.strLen);
	}
	else
	{
		throw logic_error("Token is not an identifier");
	}
}

string Token::getKeywordName() const
{
	if (data->code == YC_KEYWORD)
	{
		return string(data->repr.keyword.string, data->repr.keyword.strLen);
	}
	else
	{
		throw logic_error("Token is not a keyword");
	}
}
