#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "UnaryExpression.h"

using namespace std;

namespace WadeSpace {
	class TypeName;

	class CastExpression
	{
	public:
		CastExpression(UnaryExpression& ue);
		CastExpression(TypeName& type, CastExpression& ce);
		CastExpression();
		~CastExpression();
	private:
		optional < reference_wrapper < UnaryExpression>> ue;
		optional < reference_wrapper < TypeName>> type;
		optional < reference_wrapper < CastExpression>> ce;
	};
}
