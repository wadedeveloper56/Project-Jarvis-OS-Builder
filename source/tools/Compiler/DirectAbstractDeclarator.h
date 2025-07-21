#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"

namespace WadeSpace {
	class AbstractDeclarator;
	class ConstantExpression;
	class ParameterTypeList;

	class DirectAbstractDeclarator
	{
	public:
		DirectAbstractDeclarator(DirectAbstractDeclarator* dad, ParameterTypeList* ce, TokenType type);
		DirectAbstractDeclarator(ParameterTypeList* ce, TokenType type);
		DirectAbstractDeclarator(DirectAbstractDeclarator* dad, ConstantExpression* ce, TokenType type);
		DirectAbstractDeclarator(DirectAbstractDeclarator* dad, TokenType type);
		DirectAbstractDeclarator(AbstractDeclarator* ad);
		DirectAbstractDeclarator(ConstantExpression* ce);
		DirectAbstractDeclarator(TokenType type);
		DirectAbstractDeclarator();
		virtual ~DirectAbstractDeclarator();
	private:
		ParameterTypeList* ptl;
		DirectAbstractDeclarator* dad;
		AbstractDeclarator* ad;
		ConstantExpression* ce;
		TokenType type;
	};
}
