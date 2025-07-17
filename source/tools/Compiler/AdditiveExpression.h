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
		~AdditiveExpression();
	private:
		MultiplicativeExpression* me;
		string op;
		AdditiveExpression* ae;
	};
}
