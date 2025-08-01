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
		MultiplicativeExpression(MultiplicativeExpression* multiplicativeExpression, const string& op, CastExpression* castExpression);
		MultiplicativeExpression();
		virtual ~MultiplicativeExpression();
		MultiplicativeExpression* getMultiplicativeExpression() const;
		optional<string> getOp() const;
		CastExpression* getCastExpression() const;

	private:
		MultiplicativeExpression* multiplicativeExpression;
		optional<string> op;
		CastExpression* castExpression;
	};
}
