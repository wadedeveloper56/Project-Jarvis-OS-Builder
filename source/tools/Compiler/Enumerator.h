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
		bool hasOperatorStr() const;
		string getOperatorStr() const;
		ConstantExpression* getConstantExpression() const;

	private:
		optional<reference_wrapper<string>> operatorStr;
		ConstantExpression* constantExpression;
	};
}
