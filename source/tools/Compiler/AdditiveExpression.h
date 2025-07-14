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
		AdditiveExpression(MultiplicativeExpression& me);
		AdditiveExpression(AdditiveExpression& ae, string op, MultiplicativeExpression& me);
		AdditiveExpression();
		~AdditiveExpression();
	private:
		optional < reference_wrapper < MultiplicativeExpression>> me;
		string op;
		optional < reference_wrapper < AdditiveExpression>> ae;
	};
}
