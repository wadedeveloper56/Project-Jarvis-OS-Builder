#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "ConstantExpression.h"

using namespace std;

namespace WadeSpace {
	class Enumerator
	{
	public:
		Enumerator(string value, ConstantExpression* type);
		Enumerator(string value);
		Enumerator();
		~Enumerator();
	private:
		string operatorStr;
		ConstantExpression* expression;
	};
}
