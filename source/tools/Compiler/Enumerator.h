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
		Enumerator(const string&  value, ConstantExpression* type);
		Enumerator(const string&  value);
		Enumerator();
		virtual ~Enumerator();

	private:
		string operatorStr;
		ConstantExpression* expression;
	};
}
