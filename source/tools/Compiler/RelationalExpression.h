#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "ShiftExpression.h"

using namespace std;

namespace WadeSpace
{
	class RelationalExpression
	{
	public:
		RelationalExpression(ShiftExpression* shiftExpression);
		RelationalExpression(RelationalExpression* relationalExpression, const int& op, ShiftExpression* shiftExpression);
		RelationalExpression();
		virtual ~RelationalExpression();
		RelationalExpression* getRelationalExpression() const;
		optional<int> getOp() const;
		ShiftExpression* getShiftExpression() const;

	private:
		RelationalExpression* relationalExpression;
		optional<int> op;
		ShiftExpression* shiftExpression;
	};
}
