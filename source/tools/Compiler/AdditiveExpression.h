#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "MultiplicativeExpression.h"

using namespace std;

namespace WadeSpace
{
	class AdditiveExpression
	{
	public:
		AdditiveExpression(MultiplicativeExpression* multiplicativeExpression);
		AdditiveExpression(AdditiveExpression* additiveExpression, const int& op, MultiplicativeExpression* multiplicativeExpression);
		AdditiveExpression();
		virtual ~AdditiveExpression();
		MultiplicativeExpression* getMultiplicativeExpression() const;
		AdditiveExpression* getAdditiveExpression() const;
		optional<int> getOperation() const;

	private:
		MultiplicativeExpression* multiplicativeExpression;
		optional<int> oper;
		AdditiveExpression* additiveExpression;
	};
}
