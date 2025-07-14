#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "ConditionalExpression.h"

namespace WadeSpace {
	class ConstantExpression
	{
	public:
		ConstantExpression(ConditionalExpression& ce);
		ConstantExpression();
		~ConstantExpression();
	private:
		std::optional < std::reference_wrapper < ConditionalExpression>> ce;
	};
}
