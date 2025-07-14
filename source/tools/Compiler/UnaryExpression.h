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
		UnaryExpression(PostfixExpression& pe);
		UnaryExpression(string op, UnaryExpression& ue);
		UnaryExpression(string op, CastExpression& ce);
		UnaryExpression(string op, TypeName& tn);
		UnaryExpression();
		~UnaryExpression();
	private:
		optional < reference_wrapper < PostfixExpression>> pe;
		optional < reference_wrapper < TypeName>> tn;
		optional < reference_wrapper < UnaryExpression>> ue;
		optional < reference_wrapper < CastExpression>> ce;
		string op;
	};
}
