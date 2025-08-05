#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "CastExpression.h"

using namespace std;

namespace WadeSpace
{
	typedef struct _MultiplicativeExpressionNode
	{
		CastExpression* expression;
		optional<int> op;
	} MultiplicativeExpressionNode, * MultiplicativeExpressionNodePtr;


	class MultiplicativeExpression
	{
	public:
		MultiplicativeExpression(CastExpression* castExpression);
		void add(const int& op, CastExpression* castExpression);
		MultiplicativeExpression();
		virtual ~MultiplicativeExpression();
		optional<int> getOp() const;
		CastExpression* getCastExpression() const;

	private:
		vector<MultiplicativeExpressionNode*> * vectorMultiplicativeExpressionNode;
		CastExpression* castExpression;
	};
}
