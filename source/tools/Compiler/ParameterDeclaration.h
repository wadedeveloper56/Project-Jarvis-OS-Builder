#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "DeclarationSpecifiers.h"
#include "Declarator.h"
#include "AbstractDeclarator.h"

namespace WadeSpace
{
	class ParameterDeclaration
	{
	public:
		ParameterDeclaration(DeclarationSpecifiers* pdl);
		ParameterDeclaration(DeclarationSpecifiers* pdl, AbstractDeclarator* ad);
		ParameterDeclaration(DeclarationSpecifiers* pdl, Declarator* dec);
		ParameterDeclaration();
		virtual ~ParameterDeclaration();

	private:
		DeclarationSpecifiers* pdl;
		Declarator* dec;
		AbstractDeclarator* ad;
	};
}
