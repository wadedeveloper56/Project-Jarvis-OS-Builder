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
		MultiplicativeExpression(CastExpression* ce);
		MultiplicativeExpression(MultiplicativeExpression* me, const string& op, CastExpression* ce);
		MultiplicativeExpression();
		virtual ~MultiplicativeExpression();

	private:
		MultiplicativeExpression* me;
		string op;
		CastExpression* ce;
	};
}
