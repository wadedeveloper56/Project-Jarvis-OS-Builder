#pragma once

#include <string>
#include "Constant.h"
#include "Token.h"

using namespace std;

namespace WadeSpace
{

	typedef enum _NodeType { NT_NONE, NT_ARRAY, NT_FUNCTION_CALL,NT_VAR_ACCESS,NT_INC,NT_DEC,NT_TYPECAST,NT_SIZEOF,NT_UNARY,NT_OP,NT_QUESTION} NodeType;

	class Expression;
	class AssignmentExpression;
	class Initializer;
	class TypeName;

	typedef struct NodeData
	{
		NodeType type;
		TokenPtr token1;
		TokenPtr token2;
		Expression* lexp;
		Expression* exp1;
		Expression* exp2;
		vector<Expression*>* argumentList;
		TokenPtr identifier;
		vector<Initializer*>* initializerList;
		TypeName* typeName;
		TokenPtr token3;
		NodeData();
		NodeData(
			const NodeType type,
			const TokenPtr token1,
			const TokenPtr token2,
			Expression* const lexp,
			Expression* const exp1,
			Expression* const exp2,
			vector<Expression*>* argumentList,
			TokenPtr identifier,
			vector<Initializer*>* initializerList,
			TypeName* typeName,
			TokenPtr token3
			);
		~NodeData() = default;
	} * NodeDataPtr;

	class Expression
	{
	public:
		Expression() = default;
		Expression(const NodeDataPtr data, Expression* const left, const TokenPtr op, Expression* const right);
	private:
		NodeDataPtr data;
		Expression* left;
		TokenPtr op;
		Expression* right;
	};
}
