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
		optional<string> str;
	} UnaryExpressionNode, * UnaryExpressionNodePtr;

	class UnaryExpression
	{
	public:
		UnaryExpression(PostfixExpression* postfixExpression);
		void add(const string& op);
		UnaryExpression(const string& op, CastExpression* castExpression);
		UnaryExpression(const string& op, TypeName* typeName);
		UnaryExpression();
		virtual ~UnaryExpression();
		PostfixExpression* getPostfixExpression() const;
		TypeName* getTypeName() const;
		vector<UnaryExpressionNode*>* getVectorUnaryExpressionNode() const;
		CastExpression* getCastExpression() const;
		optional<string> getOp() const;

	private:
		PostfixExpression* postfixExpression;
		TypeName* typeName;
		//UnaryExpression* unaryExpression;
		CastExpression* castExpression;
		optional<string> op;
		vector<UnaryExpressionNode*>* vectorUnaryExpressionNode;
	};
}
