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
		ParameterDeclaration();
		ParameterDeclaration(DeclarationSpecifiers* declarationSpecifiers);
		ParameterDeclaration(DeclarationSpecifiers* declarationSpecifiers, AbstractDeclarator* abstractDeclarator);
		ParameterDeclaration(DeclarationSpecifiers* declarationSpecifiers, Declarator* declarator);
		virtual ~ParameterDeclaration();

		ParameterDeclaration(const ParameterDeclaration& other);
		ParameterDeclaration(ParameterDeclaration&& other) noexcept;
		ParameterDeclaration& operator=(const ParameterDeclaration& other);
		ParameterDeclaration& operator=(ParameterDeclaration&& other) noexcept;

		[[nodiscard]] DeclarationSpecifiers* getDeclarationSpecifiers() const;
		[[nodiscard]] Declarator* getDeclarator() const;
		[[nodiscard]] AbstractDeclarator* getAbstractDeclarator() const;

		[[nodiscard]] bool hasDeclarationSpecifiers() const;
		[[nodiscard]] bool hasDeclarator() const;
		[[nodiscard]] bool hasAbstractDeclarator() const;

	private:
		DeclarationSpecifiers* declarationSpecifiers;
		Declarator* declarator;
		AbstractDeclarator* abstractDeclarator;
	};
}
