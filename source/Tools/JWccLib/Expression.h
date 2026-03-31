#pragma once

#include <string>
#include "Constant.h"
#include "Token.h"

using namespace std;

namespace WadeSpace
{
	typedef enum _NodeType
	{
		NT_NONE, NT_ARRAY, NT_FUNCTION_CALL, NT_VAR_ACCESS, NT_INC, NT_DEC, NT_TYPECAST, NT_SIZEOF, NT_UNARY, NT_OP,
		NT_QUESTION
	} NodeType;

	class Expression;
	class AssignmentExpression;
	class Initializer;
	class TypeName;

	typedef struct NodeData
	{
		NodeType type;
		CTokenPtr token1;
		CTokenPtr token2;
		Expression* lexp;
		Expression* exp1;
		Expression* exp2;
		vector<Expression*>* argumentList;
		CTokenPtr identifier;
		vector<Initializer*>* initializerList;
		TypeName* typeName;
		CTokenPtr token3;
		Constant* constant;
		NodeData();
		NodeData(
			const NodeType type,
			const CTokenPtr token1,
			const CTokenPtr token2,
			Expression* const lexp,
			Expression* const exp1,
			Expression* const exp2,
			vector<Expression*>* argumentList,
			CTokenPtr identifier,
			vector<Initializer*>* initializerList,
			TypeName* typeName,
			CTokenPtr token3,
			Constant* constant
		);
		~NodeData();
		NodeData(const NodeData& other);
		NodeData(NodeData&& other) noexcept;
		NodeData& operator=(const NodeData& other);
		NodeData& operator=(NodeData&& other) noexcept;
		[[nodiscard]] NodeType getType() const;
		[[nodiscard]] CTokenPtr getToken1() const;
		[[nodiscard]] CTokenPtr getToken2() const;
		[[nodiscard]] Expression* getLexp() const;
		[[nodiscard]] Expression* getExp1() const;
		[[nodiscard]] Expression* getExp2() const;
		[[nodiscard]] vector<Expression*>* getArgumentList() const;
		[[nodiscard]] CTokenPtr getIdentifier() const;
		[[nodiscard]] vector<Initializer*>* getInitializerList() const;
		[[nodiscard]] TypeName* getTypeName() const;
		[[nodiscard]] CTokenPtr getToken3() const;
		[[nodiscard]] Constant* getConstant() const;
	}* NodeDataPtr;

	class Expression
	{
	public:
		Expression();
		Expression(const NodeDataPtr data, Expression* const left, const CTokenPtr op, Expression* const right);
		~Expression();

		Expression(const Expression& other);
		Expression(Expression&& other) noexcept;
		Expression& operator=(const Expression& other);
		Expression& operator=(Expression&& other) noexcept;

		[[nodiscard]] NodeDataPtr getData() const;
		[[nodiscard]] Expression* getLeft() const;
		[[nodiscard]] CTokenPtr getOp() const;
		[[nodiscard]] Expression* getRight() const;

		[[nodiscard]] bool hasData() const;
		[[nodiscard]] bool hasLeft() const;
		[[nodiscard]] bool hasOp() const;
		[[nodiscard]] bool hasRight() const;

	private:
		NodeDataPtr data;
		Expression* left;
		CTokenPtr op;
		Expression* right;
	};
}
