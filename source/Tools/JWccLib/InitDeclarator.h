#pragma once

#include <string>
#include <vector>
#include <optional>
#include "Declarator.h"
#include "Initializer.h"

namespace WadeSpace
{
	class InitDeclarator
	{
	public:
		InitDeclarator(Declarator* declarator);
		InitDeclarator(Declarator* declarator, Initializer* initializer);
		InitDeclarator();
		virtual ~InitDeclarator();
		Declarator* getDeclarator() const;
		Initializer* getInitializer() const;
		string getVariableName() const;

	private:
		Declarator* declarator;
		Initializer* initializer;
	};
}
