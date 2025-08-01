#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "AdditiveExpression.h"

using namespace std;

namespace WadeSpace
{
	class ShiftExpression
	{
	public:
		ShiftExpression(AdditiveExpression* additiveExpression);
		ShiftExpression(ShiftExpression* shiftExpression, const string& op, AdditiveExpression* additiveExpression);
		ShiftExpression();
		virtual ~ShiftExpression();

	private:
		AdditiveExpression* additiveExpression;
		optional<string> op;
		ShiftExpression* shiftExpression;
	};
}
