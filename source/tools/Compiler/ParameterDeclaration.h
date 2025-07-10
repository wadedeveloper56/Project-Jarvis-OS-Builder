#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "DeclarationSpecifiers.h"
#include "Declarator.h"
#include "AbstractDeclarator.h"

namespace WadeSpace {
	class ParameterDeclaration
	{
	public:
		ParameterDeclaration(DeclarationSpecifiers& pdl);
		ParameterDeclaration(DeclarationSpecifiers& pdl, AbstractDeclarator& ad);
		ParameterDeclaration(DeclarationSpecifiers& pdl, Declarator& dec);
		ParameterDeclaration();
		~ParameterDeclaration();
	private:
		std::optional < std::reference_wrapper < DeclarationSpecifiers>> pdl;
		std::optional < std::reference_wrapper < Declarator>> dec;
		std::optional < std::reference_wrapper < AbstractDeclarator>> ad;
	};
}
