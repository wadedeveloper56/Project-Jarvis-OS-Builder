#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
//#include "PostfixExpression.h"
//#include "CastExpression.h"

using namespace std;

namespace WadeSpace
{
	class TypeName;
	class CastExpression;
	class PostfixExpression;

	class UnaryExpression
	{
	public:
		UnaryExpression(PostfixExpression* pe);
		UnaryExpression(const string&  op, UnaryExpression* ue);
		UnaryExpression(const string&  op, CastExpression* ce);
		UnaryExpression(const string&  op, TypeName* tn);
		UnaryExpression();
		virtual ~UnaryExpression();

	private:
		PostfixExpression* pe;
		TypeName* tn;
		UnaryExpression* ue;
		CastExpression* ce;
		string op;
	};
}
