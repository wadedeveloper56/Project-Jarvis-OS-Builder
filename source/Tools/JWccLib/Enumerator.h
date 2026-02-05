#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>

using namespace std;

namespace WadeSpace
{
	class Expression;

	class Enumerator
	{
	public:
		Enumerator(string&  operatorStr, Expression* constantExpression);
		Enumerator(string&  operatorStr);
		Enumerator();
		virtual ~Enumerator();
		optional<string> getOperatorStr() const;
		Expression* getConstantExpression() const;

	private:
		optional<string> operatorStr;
		Expression* constantExpression;
	};
}
