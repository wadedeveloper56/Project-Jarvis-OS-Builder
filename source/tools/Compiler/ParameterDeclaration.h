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
		ParameterDeclaration(DeclarationSpecifiers* declarationSpecifiers);
		ParameterDeclaration(DeclarationSpecifiers* declarationSpecifiers, AbstractDeclarator* abstractDeclarator);
		ParameterDeclaration(DeclarationSpecifiers* declarationSpecifiers, Declarator* declarator);
		ParameterDeclaration();
		virtual ~ParameterDeclaration();
		DeclarationSpecifiers* getDeclarationSpecifiers() const;
		Declarator* getDeclarator() const;
		AbstractDeclarator* getAbstractDeclarator() const;

	private:
		DeclarationSpecifiers* declarationSpecifiers;
		Declarator* declarator;
		AbstractDeclarator* abstractDeclarator;
	};
}
