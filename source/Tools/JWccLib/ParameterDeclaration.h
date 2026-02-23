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

		ParameterDeclaration(const ParameterDeclaration& other)
			: declarationSpecifiers(new DeclarationSpecifiers(*other.declarationSpecifiers)),
			  declarator(new Declarator(*other.declarator)),
			  abstractDeclarator(new AbstractDeclarator(*other.abstractDeclarator))
		{
		}

		ParameterDeclaration(ParameterDeclaration&& other) noexcept
			: declarationSpecifiers(new DeclarationSpecifiers(*other.declarationSpecifiers)),
			declarator(new Declarator(*other.declarator)),
			abstractDeclarator(new AbstractDeclarator(*other.abstractDeclarator))
		{
		}

		ParameterDeclaration& operator=(const ParameterDeclaration& other)
		{
			if (this == &other)
				return *this;
			delete declarationSpecifiers;
			delete declarator;
			delete abstractDeclarator;
			declarationSpecifiers = new DeclarationSpecifiers(*other.declarationSpecifiers);
			declarator = new Declarator(*other.declarator);
			abstractDeclarator = new AbstractDeclarator(*other.abstractDeclarator);
			return *this;
		}

		ParameterDeclaration& operator=(ParameterDeclaration&& other) noexcept
		{
			if (this == &other)
				return *this;
			delete declarationSpecifiers;
			delete declarator;
			delete abstractDeclarator;
			declarationSpecifiers = new DeclarationSpecifiers(*other.declarationSpecifiers);
			declarator = new Declarator(*other.declarator);
			abstractDeclarator = new AbstractDeclarator(*other.abstractDeclarator);
			return *this;
		}

		DeclarationSpecifiers* getDeclarationSpecifiers() const;
		Declarator* getDeclarator() const;
		AbstractDeclarator* getAbstractDeclarator() const;

	private:
		DeclarationSpecifiers* declarationSpecifiers;
		Declarator* declarator;
		AbstractDeclarator* abstractDeclarator;
	};
}
