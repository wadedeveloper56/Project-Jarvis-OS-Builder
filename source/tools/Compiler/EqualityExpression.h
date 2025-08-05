#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "RelationalExpression.h"

using namespace std;

namespace WadeSpace
{
	class EqualityExpression
	{
	public:
		EqualityExpression(RelationalExpression* relationalExpression);
		EqualityExpression(EqualityExpression* equalityExpression, int& op, RelationalExpression* relationalExpression);
		EqualityExpression();
		virtual ~EqualityExpression();
		RelationalExpression* getRelationalExpression() const;
		optional<int> getOp() const;
		EqualityExpression* getEqualityExpression() const;

	private:
		RelationalExpression* relationalExpression;
		optional<int> op;
		EqualityExpression* equalityExpression;
	};
}
