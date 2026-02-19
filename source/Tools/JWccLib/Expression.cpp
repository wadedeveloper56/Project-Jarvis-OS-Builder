#include "pch.h"
#include "Expression.h"
#include "TypeName.h"
#include "Initializer.h"

using namespace std;
using namespace WadeSpace;

NodeData::NodeData() : type(NT_NONE), token1(nullptr), token2(nullptr), exp1(nullptr), exp2(nullptr), argumentList(nullptr), identifier(nullptr), initializerList(nullptr), typeName(nullptr), token3(nullptr), lexp(nullptr)
{
}

NodeData::NodeData(
	const NodeType type,
	TokenPtr token1,
	TokenPtr token2,
	Expression* const lexp,
	Expression* const exp1,
	Expression* const exp2,
	vector<Expression*>* argumentList,
	TokenPtr identifier,
	vector<Initializer*>* initializerList,
	TypeName* typeName,
	TokenPtr token3
)
	: type(type),
	token1(token1),
	token2(token2),
	lexp(lexp),
	exp1(exp1),
	exp2(exp2),
	argumentList(argumentList),
	identifier(identifier),
	initializerList(initializerList),
	typeName(typeName),
	token3(token3)
{
}

NodeData::~NodeData()
{
	delete token1;
	delete token2;
	delete lexp;
	delete exp1;
	delete exp2;
	if (argumentList != nullptr)
	{
		for (auto ptr : *argumentList)
		{
			delete ptr;
		}
		delete argumentList;
	}
	delete identifier;
	if (initializerList != nullptr)
	{
		for (auto ptr : *initializerList)
		{
			delete ptr;
		}
		delete initializerList;
	}
	delete typeName;
	delete token3;
	delete lexp;
}

Expression::Expression() : data(nullptr), left(nullptr), op(nullptr), right(nullptr)
{
}

Expression::Expression(const NodeDataPtr data, Expression* const left, const TokenPtr op, Expression* const right)
	: data(data),
	  left(left),
	  op(op),
	  right(right)
{
}

Expression::~Expression()
{
	delete data;
	delete left;
	delete op;
	delete right;
}
