#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "RelationalExpression.h"

using namespace std;

namespace WadeSpace {
	class EqualityExpression
	{
	public:
		EqualityExpression(RelationalExpression& re);
		EqualityExpression(EqualityExpression& eq,string op,RelationalExpression& re);
		EqualityExpression();
		~EqualityExpression();
	private:
		optional < reference_wrapper < RelationalExpression>> re;
		string op;
		optional < reference_wrapper < EqualityExpression>> ee;
	};
}
