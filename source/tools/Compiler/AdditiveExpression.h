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
		AdditiveExpression(AdditiveExpression* additiveExpression, const string& op, MultiplicativeExpression* multiplicativeExpression);
		AdditiveExpression();
		virtual ~AdditiveExpression();
		MultiplicativeExpression* getMultiplicativeExpression() const;
		AdditiveExpression* getAdditiveExpression() const;
		optional<string> getOperation() const;

	private:
		MultiplicativeExpression* multiplicativeExpression;
		optional<string> oper;
		AdditiveExpression* additiveExpression;
	};
}
