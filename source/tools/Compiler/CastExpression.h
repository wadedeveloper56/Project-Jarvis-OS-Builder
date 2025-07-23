#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "UnaryExpression.h"

using namespace std;

namespace WadeSpace
{
	class TypeName;

	class CastExpression
	{
	public:
		CastExpression(UnaryExpression* ue);
		CastExpression(TypeName* type, CastExpression* ce);
		CastExpression();
		virtual ~CastExpression();
		UnaryExpression* getUnaryExpression() const;
		TypeName* getType() const;
		CastExpression* getCastExpression() const;

	private:
		UnaryExpression* unaryExpression;
		TypeName* type;
		CastExpression* castExpression;
	};
}
