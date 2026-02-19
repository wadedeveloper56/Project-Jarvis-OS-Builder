#pragma once

#include <string>
#include <vector>
#include <optional>

#include "Token.h"

using namespace std;

namespace WadeSpace
{
	class Expression;

	class Enumerator
	{
	public:
		Enumerator(TokenPtr identifier, Expression* constantExpression);
		Enumerator();
		virtual ~Enumerator();
		TokenPtr getIdentifier() const;
		Expression* getConstantExpression() const;

	private:
		TokenPtr identifier;
		Expression* constantExpression;
	};
}
