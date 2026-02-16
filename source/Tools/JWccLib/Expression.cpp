#include "pch.h"
#include "Expression.h"

using namespace std;
using namespace WadeSpace;

NodeData::NodeData() : type(NT_NONE), token1(nullptr), token2(nullptr), exp1(nullptr), exp2(nullptr), argumentList(nullptr)
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

Expression::Expression(const NodeDataPtr data, Expression* const left, const TokenPtr op, Expression* const right)
	: data(data),
	  left(left),
	  op(op),
	  right(right)
{
}
