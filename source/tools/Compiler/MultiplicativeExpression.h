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
	class MultiplicativeExpression
	{
	public:
		MultiplicativeExpression(CastExpression* castExpression);
		MultiplicativeExpression(MultiplicativeExpression* multiplicativeExpression, const int& op, CastExpression* castExpression);
		MultiplicativeExpression();
		virtual ~MultiplicativeExpression();
		MultiplicativeExpression* getMultiplicativeExpression() const;
		optional<int> getOp() const;
		CastExpression* getCastExpression() const;

	private:
		MultiplicativeExpression* multiplicativeExpression;
		optional<int> op;
		CastExpression* castExpression;
	};
}
