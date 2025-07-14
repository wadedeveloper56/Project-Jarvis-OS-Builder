#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "AndExpression.h"

using namespace std;

namespace WadeSpace {
	class ExclusiveOrExpression
	{
	public:
		ExclusiveOrExpression(AndExpression& ae);
		ExclusiveOrExpression(ExclusiveOrExpression& eoe,AndExpression& ae);
		ExclusiveOrExpression();
		~ExclusiveOrExpression();
	private:
		optional < reference_wrapper < AndExpression>> ae;
		optional < reference_wrapper < ExclusiveOrExpression>> eoe;
	};
}
