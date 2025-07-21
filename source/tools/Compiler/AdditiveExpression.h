#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "MultiplicativeExpression.h"

using namespace std;

namespace WadeSpace {
	class AdditiveExpression
	{
	public:
		AdditiveExpression(MultiplicativeExpression* me);
		AdditiveExpression(AdditiveExpression* ae, string op, MultiplicativeExpression* me);
		AdditiveExpression();
		virtual ~AdditiveExpression();
		bool hasMultiplicativeExpression() const;
		bool hasAdditiveExpression() const;
		MultiplicativeExpression* getMultiplicativeExpression() const;
		AdditiveExpression* getAdditiveExpression() const;
		string getOperation() const;
	private:
		MultiplicativeExpression* me;
		string op;
		AdditiveExpression* ae;
	};
}
