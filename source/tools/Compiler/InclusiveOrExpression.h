#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "ExclusiveOrExpression.h"

using namespace std;

namespace WadeSpace {
	class InclusiveOrExpression
	{
	public:
		InclusiveOrExpression(ExclusiveOrExpression* eoe);
		InclusiveOrExpression(InclusiveOrExpression* ioe, ExclusiveOrExpression* eoe);
		InclusiveOrExpression();
		~InclusiveOrExpression();
	private:
		InclusiveOrExpression* ioe;
		ExclusiveOrExpression* eoe;
	};
}
