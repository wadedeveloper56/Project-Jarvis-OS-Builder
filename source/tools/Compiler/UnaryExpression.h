#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"

using namespace std;

namespace WadeSpace
{
	class TypeName;
	class CastExpression;
	class PostfixExpression;

	typedef struct _UnaryExpressionNode
	{
		optional<int> str;
	} UnaryExpressionNode, * UnaryExpressionNodePtr;

	class UnaryExpression
	{
	public:
		UnaryExpression(PostfixExpression* postfixExpression);
		void add(const int& op);
		UnaryExpression(const int& op, CastExpression* castExpression);
		UnaryExpression(const int& op, TypeName* typeName);
		UnaryExpression();
		virtual ~UnaryExpression();
		PostfixExpression* getPostfixExpression() const;
		TypeName* getTypeName() const;
		vector<UnaryExpressionNode*>* getVectorUnaryExpressionNode() const;
		CastExpression* getCastExpression() const;
		optional<int> getOp() const;

	private:
		PostfixExpression* postfixExpression;
		TypeName* typeName;
		CastExpression* castExpression;
		optional<int> op;
		vector<UnaryExpressionNode*>* vectorUnaryExpressionNode;
	};
}
