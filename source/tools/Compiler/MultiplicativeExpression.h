#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "CastExpression.h"

using namespace std;

namespace WadeSpace {
	class MultiplicativeExpression
	{
	public:
		MultiplicativeExpression(CastExpression& ce);
		MultiplicativeExpression(MultiplicativeExpression& me, string op, CastExpression& ce);
		MultiplicativeExpression();
		~MultiplicativeExpression();
	private:
		optional < reference_wrapper < MultiplicativeExpression>> me;
		string op;
		optional < reference_wrapper < CastExpression>> ce;
	};
}
