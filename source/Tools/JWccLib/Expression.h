#pragma once

#include <string>
#include "Constant.h"
#include "Token.h"

using namespace std;

namespace WadeSpace
{

	typedef enum NodeType { NT_NONE, NT_ARRAY, NT_FUNCTION_CALL,NT_VAR_ACCESS,NT_INC,NT_DEC,NT_TYPECAST,NT_SIZEOF,NT_UNARY,NT_OP};

	class Expression;
	class AssignmentExpression;
	class Initializer;
	class TypeName;

	typedef struct NodeData
	{
		NodeType type;
		optional<int> token1;
		optional<int> token2;
		Expression* exp1;
		Expression* exp2;
		vector<Expression*>* argumentList;
		optional<string> identifier;
		vector<Initializer*>* initializerList;
		TypeName* typeName;
		TokenPtr token3;
		NodeData();
		NodeData(
			const NodeType type,
			const optional<int> token1,
			const optional<int> token2,
			Expression* const exp1,
			Expression* const exp2,
			vector<Expression*>* argumentList,
			optional<string> identifier,
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
