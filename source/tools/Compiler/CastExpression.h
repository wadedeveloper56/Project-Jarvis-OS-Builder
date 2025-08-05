#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "UnaryExpression.h"

using namespace std;

namespace WadeSpace
{
	class TypeName;

	typedef struct _CastExpressionNode
	{
		TypeName* type;
	} CastExpressionNode, * CastExpressionNodePtr;

	class CastExpression
	{
	public:
		CastExpression(UnaryExpression* ue);
		void add(TypeName* type);
		CastExpression();
		virtual ~CastExpression();
		UnaryExpression* getUnaryExpression() const;
		vector<CastExpressionNode*>* getVectorCastExpressionNode() const;

	private:
		UnaryExpression* unaryExpression;
		vector<CastExpressionNode*>* vectorCastExpressionNode;
	};
}
