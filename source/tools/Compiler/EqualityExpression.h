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
		EqualityExpression(RelationalExpression* re);
		EqualityExpression(EqualityExpression* eq, const string& op, RelationalExpression* re);
		EqualityExpression();
		virtual ~EqualityExpression();

	private:
		RelationalExpression* re;
		string op;
		EqualityExpression* ee;
	};
}
