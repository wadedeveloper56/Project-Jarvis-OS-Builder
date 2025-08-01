#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "ConstantExpression.h"

using namespace std;

namespace WadeSpace
{
	class Enumerator
	{
	public:
		Enumerator(string&  operatorStr, ConstantExpression* constantExpression);
		Enumerator(string&  operatorStr);
		Enumerator();
		virtual ~Enumerator();
		optional<string> getOperatorStr() const;
		ConstantExpression* getConstantExpression() const;

	private:
		optional<string> operatorStr;
		ConstantExpression* constantExpression;
	};
}
