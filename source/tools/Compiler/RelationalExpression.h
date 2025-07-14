#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "ShiftExpression.h"

using namespace std;

namespace WadeSpace {
	class RelationalExpression
	{
	public:
		RelationalExpression(ShiftExpression& se);
		RelationalExpression(RelationalExpression& re, string op, ShiftExpression& se);
		RelationalExpression();
		~RelationalExpression();
	private:
		optional < reference_wrapper < RelationalExpression>> re;
		string op;
		optional < reference_wrapper < ShiftExpression>> se;
	};
}
