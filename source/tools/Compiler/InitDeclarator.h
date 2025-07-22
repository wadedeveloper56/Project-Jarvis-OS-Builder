#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "Declarator.h"
#include "Initializer.h"

namespace WadeSpace {
	class InitDeclarator
	{
	public:
		InitDeclarator(Declarator* dec);
		InitDeclarator(Declarator* dec, Initializer* init);
		InitDeclarator();
		virtual ~InitDeclarator();
		bool hasDeclarator() const;
		bool hasInitializer() const;
		Declarator* getDeclarator() const;
		Initializer* getInitializer() const;
		string getVariableName();
	private:
		Declarator* dec;
		Initializer* init;
	};
}
