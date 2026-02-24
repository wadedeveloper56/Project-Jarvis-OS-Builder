#pragma once

#include <string>
#include <vector>
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
		ParameterDeclaration(const ParameterDeclaration& other);
		ParameterDeclaration(ParameterDeclaration&& other) noexcept;
		ParameterDeclaration& operator=(const ParameterDeclaration& other);
		ParameterDeclaration& operator=(ParameterDeclaration&& other) noexcept;
		DeclarationSpecifiers* getDeclarationSpecifiers() const;
		Declarator* getDeclarator() const;
		AbstractDeclarator* getAbstractDeclarator() const;

	private:
		DeclarationSpecifiers* declarationSpecifiers;
		Declarator* declarator;
		AbstractDeclarator* abstractDeclarator;
	};
}
