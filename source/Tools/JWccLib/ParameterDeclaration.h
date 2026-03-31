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
		DeclarationSpecifiers* declarationSpecifiers;
		Declarator* declarator;
		AbstractDeclarator* abstractDeclarator;
	public:
		ParameterDeclaration() = default;
		ParameterDeclaration(DeclarationSpecifiers* declarationSpecifiers);
		ParameterDeclaration(DeclarationSpecifiers* declarationSpecifiers, AbstractDeclarator* abstractDeclarator);
		ParameterDeclaration(DeclarationSpecifiers* declarationSpecifiers, Declarator* declarator);
		virtual ~ParameterDeclaration() = default;
		ParameterDeclaration(const ParameterDeclaration& other) = default;
		ParameterDeclaration(ParameterDeclaration&& other) noexcept = default;
		ParameterDeclaration& operator=(const ParameterDeclaration& other) = default;
		ParameterDeclaration& operator=(ParameterDeclaration&& other) noexcept = default;
		[[nodiscard]] DeclarationSpecifiers* getDeclarationSpecifiers() const { return declarationSpecifiers; }
		[[nodiscard]] Declarator* getDeclarator() const { return declarator; }
		[[nodiscard]] AbstractDeclarator* getAbstractDeclarator() const { return abstractDeclarator; }
		void setDeclarationSpecifiers(DeclarationSpecifiers* declarationSpecifiers) { this->declarationSpecifiers = declarationSpecifiers; }
		void setDeclarator(Declarator* declarator) { this->declarator = declarator; }
		void setAbstractDeclarator(AbstractDeclarator* abstractDeclarator) { this->abstractDeclarator = abstractDeclarator; }
		[[nodiscard]] bool hasDeclarationSpecifiers() const { return declarationSpecifiers != nullptr; }
		[[nodiscard]] bool hasDeclarator() const { return declarator != nullptr; }
		[[nodiscard]] bool hasAbstractDeclarator() const { return abstractDeclarator != nullptr; }

	};
}
