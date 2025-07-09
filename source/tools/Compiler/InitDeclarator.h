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
		InitDeclarator(Declarator& dec);
		InitDeclarator(Declarator& dec,Initializer& init);
		InitDeclarator();
		~InitDeclarator();
	private:
		std::optional < std::reference_wrapper < Declarator>> dec;
		std::optional < std::reference_wrapper < Initializer>> init;
	};
}
