#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
//#include "PostfixExpression.h"
//#include "CastExpression.h"

using namespace std;

namespace WadeSpace {
	class TypeName;
	class CastExpression;
	class PostfixExpression;

	class UnaryExpression
	{
	public:
		UnaryExpression(PostfixExpression* pe);
		UnaryExpression(string op, UnaryExpression* ue);
		UnaryExpression(string op, CastExpression* ce);
		UnaryExpression(string op, TypeName* tn);
		UnaryExpression();
		~UnaryExpression();
	private:
		PostfixExpression* pe;
		TypeName* tn;
		UnaryExpression* ue;
		CastExpression* ce;
		string op;
	};
}
