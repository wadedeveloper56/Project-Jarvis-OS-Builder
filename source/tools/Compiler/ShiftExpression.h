#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "AdditiveExpression.h"

using namespace std;

namespace WadeSpace {
	class ShiftExpression
	{
	public:
		ShiftExpression(AdditiveExpression& ae);
		ShiftExpression(ShiftExpression& se, string op, AdditiveExpression& ae);
		ShiftExpression();
		~ShiftExpression();
	private:
		optional < reference_wrapper < AdditiveExpression>> ae;
		string op;
		optional < reference_wrapper < ShiftExpression>> se;
	};
}
