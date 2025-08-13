#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>

using namespace std;

namespace WadeSpace
{
	class ExpressionNode;

	class Enumerator
	{
	public:
		Enumerator(string&  operatorStr, ExpressionNode* constantExpression);
		Enumerator(string&  operatorStr);
		Enumerator();
		virtual ~Enumerator();
		optional<string> getOperatorStr() const;
		ExpressionNode* getConstantExpression() const;

	private:
		optional<string> operatorStr;
		ExpressionNode* constantExpression;
	};
}
