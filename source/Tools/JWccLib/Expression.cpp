#include "pch.h"
#include "Expression.h"
#include "TypeName.h"
#include "Initializer.h"

using namespace std;
using namespace WadeSpace;

NodeData::NodeData() : type(NT_NONE), token1(nullptr), token2(nullptr), exp1(nullptr), exp2(nullptr), argumentList(nullptr), identifier(nullptr), initializerList(nullptr), typeName(nullptr), token3(nullptr), lexp(nullptr), constant(nullptr)
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
	TokenPtr token3, 
	Constant* constant
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
	token3(token3), constant(constant)
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
	delete constant;
}

NodeType NodeData::getType() const
{
	return type;
}

TokenPtr NodeData::getToken1() const
{
	return token1;
}

TokenPtr NodeData::getToken2() const
{
	return token2;
}

Expression* NodeData::getLexp() const
{
	return lexp;
}

Expression* NodeData::getExp1() const
{
	return exp1;
}

Expression* NodeData::getExp2() const
{
	return exp2;
}

vector<Expression*>* NodeData::getArgumentList() const
{
	return argumentList;
}

TokenPtr NodeData::getIdentifier() const
{
	return identifier;
}

vector<Initializer*>* NodeData::getInitializerList() const
{
	return initializerList;
}

TypeName* NodeData::getTypeName() const
{
	return typeName;
}

TokenPtr NodeData::getToken3() const
{
	return token3;
}

Constant* NodeData::getConstant() const
{
	return constant;
}

NodeData::NodeData(const NodeData& other)
	: type(other.type),
	token1(new Token(*other.token1)),
	token2(new Token(*other.token2)),
	lexp(new Expression(*other.lexp)),
	exp1(new Expression(*other.exp1)),
	exp2(new Expression(*other.exp2)),
	argumentList(new vector<Expression*>(*other.argumentList)),
	identifier(new Token(*other.identifier)),
	initializerList(new vector<Initializer*>(*other.initializerList)),
	typeName(new TypeName(*other.typeName)),
	token3(new Token(*other.token3)),
	constant(new Constant(*other.constant))
{
}

NodeData::NodeData(NodeData&& other) noexcept
	: type(other.type),
	token1(new Token(*other.token1)),
	token2(new Token(*other.token2)),
	lexp(new Expression(*other.lexp)),
	exp1(new Expression(*other.exp1)),
	exp2(new Expression(*other.exp2)),
	argumentList(new vector<Expression*>(*other.argumentList)),
	identifier(new Token(*other.identifier)),
	initializerList(new vector<Initializer*>(*other.initializerList)),
	typeName(new TypeName(*other.typeName)),
	token3(new Token(*other.token3)),
	constant(new Constant(*other.constant))
{
}

NodeData& NodeData::operator=(const NodeData& other)
{
	if (this == &other)
		return *this;
	type = other.type;
	token1 = new Token(*other.token1);
	token2 = new Token(*other.token2);
	lexp = new Expression(*other.lexp);
	exp1 = new Expression(*other.exp1);
	exp2 = new Expression(*other.exp2);
	argumentList = new vector<Expression*>(*other.argumentList);
	identifier = new Token(*other.identifier);
	initializerList = new vector<Initializer*>(*other.initializerList);
	typeName = new TypeName(*other.typeName);
	token3 = new Token(*other.token3);
	constant = new Constant(*other.constant);
	return *this;
}

NodeData& NodeData::operator=(NodeData&& other) noexcept
{
	if (this == &other)
		return *this;
	type = other.type;
	token1 = new Token(*other.token1);
	token2 = new Token(*other.token2);
	lexp = new Expression(*other.lexp);
	exp1 = new Expression(*other.exp1);
	exp2 = new Expression(*other.exp2);
	argumentList = new vector<Expression*>(*other.argumentList);
	identifier = new Token(*other.identifier);
	initializerList = new vector<Initializer*>(*other.initializerList);
	typeName = new TypeName(*other.typeName);
	token3 = new Token(*other.token3);
	constant = new Constant(*other.constant);
	return *this;
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

NodeDataPtr Expression::getData() const
{
	return data;
}

Expression* Expression::getLeft() const
{
	return left;
}

TokenPtr Expression::getOp() const
{
	return op;
}

Expression* Expression::getRight() const
{
	return right;
}


Expression::Expression(const Expression& other)
	: data(new NodeData(*other.data)),
	left(new Expression(*other.left)),
	op(new Token(*other.op)),
	right(new Expression(*other.right))
{
}

Expression::Expression(Expression&& other) noexcept
	: data(new NodeData(*other.data)),
	left(new Expression(*other.left)),
	op(new Token(*other.op)),
	right(new Expression(*other.right))
{
}

Expression& Expression::operator=(const Expression& other)
{
	if (this == &other)
		return *this;
	data = new NodeData(*other.data);
	left = new Expression(*other.left);
	op = new Token(*other.op);
	right = new Expression(*other.right);
	return *this;
}

Expression& Expression::operator=(Expression&& other) noexcept
{
	if (this == &other)
		return *this;
	data = new NodeData(*other.data);
	left = new Expression(*other.left);
	op = new Token(*other.op);
	right = new Expression(*other.right);
	return *this;
}

