#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "EqualityExpression.h"

using namespace std;

namespace WadeSpace
{
	class AndExpression
	{
	public:
		AndExpression(EqualityExpression* equalityExpression);
		AndExpression(AndExpression* andExpression, EqualityExpression* equalityExpression);
		AndExpression();
		virtual ~AndExpression();
		AndExpression* getAndExpression() const;
		EqualityExpression* getEqualityExpression() const;

	private:
		AndExpression* andExpression;
		EqualityExpression* equalityExpression;
	};
}
