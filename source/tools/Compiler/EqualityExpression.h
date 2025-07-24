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
		EqualityExpression(EqualityExpression* equalityExpression, string& op, RelationalExpression* relationalExpression);
		EqualityExpression();
		virtual ~EqualityExpression();
		RelationalExpression* getRelationalExpression() const;
		bool hasOp() const;
		string getOp() const;
		EqualityExpression* getEqualityExpression() const;

	private:
		RelationalExpression* relationalExpression;
		string op;
		EqualityExpression* equalityExpression;
	};
}
