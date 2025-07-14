#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "EqualityExpression.h"

using namespace std;

namespace WadeSpace {
	class AndExpression
	{
	public:
		AndExpression(EqualityExpression& ee);
		AndExpression(AndExpression& ae, EqualityExpression& ee);
		AndExpression();
		~AndExpression();
	private:
		optional < reference_wrapper < AndExpression>> ae;
		optional < reference_wrapper < EqualityExpression>> ee;
	};
}
