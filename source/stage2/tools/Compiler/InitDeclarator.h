#pragma once

#include <string>
#include <vector>
#include <stdint.h>
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
		string getVariableName();

	private:
		Declarator* declarator;
		Initializer* initializer;
	};
}
